// kaslr_probe_v2 — 27.2 / 24B115 KASLR leak probe, crash-safe
//
// Отличия от v1 (02_KERNEL/kaslr_probe/main.m):
//   1. Каждый probe обёрнут в @try/@catch и в собственный autorelease pool.
//   2. Лог пишется на диск ПОСЛЕ КАЖДОЙ строки -> краш не теряет данные.
//   3. IOSurfaceGetBulkAttachments больше не вызывается вслепую (именно на нём падал v1:
//      __bzero c NULL-буфером, адрес 0xffffffffffffffe8).
//   4. Добавлены: vm_region_64, IORegistryEntryCreateCFProperties, IOConnectMapMemory64
//      на AGX/IOGPU, опционально exclaves_ctl.
//
// Сборка (Theos), arm64e, без entitlements:
//   make package
// Установка: подписать своим сертификатом, поставить на iPhone14,7 (24B115).

#import <UIKit/UIKit.h>
#import <mach/mach.h>
#import <mach/mach_host.h>
#import <mach/mach_port.h>
#import <mach/vm_region.h>
#import <mach/vm_map.h>
#import <mach/task_info.h>
#import <sys/sysctl.h>
#import <sys/syscall.h>
#import <dlfcn.h>
#import <IOKit/IOKitLib.h>
#import <IOKit/IOKitKeys.h>

// exclaves_ctl — mach trap 88. ABI не подтверждён: включать только осознанно.
#define TRY_EXCLAVES 0

static NSString *gLogPath;
static NSMutableString *gLog;

static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    [gLog appendString:s];
    [gLog appendString:@"\n"];
    NSLog(@"[kaslr2] %@", s);
    // сбрасываем на диск сразу — иначе краш съест последние строки
    [gLog writeToFile:gLogPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
}

// Ищем только то, что похоже на kernel text/data: 0xfffffff0_00000000 .. 0xffffffff_ffffffff
static void scan(const char *tag, const void *buf, size_t len, size_t maxhits) {
    if (!buf || len < 8) { L(@"--- %s: empty", tag); return; }
    const uint64_t *p = (const uint64_t *)buf;
    size_t hits = 0;
    for (size_t i = 0; i + 8 <= len; i += 8, p++) {
        uint64_t v = *p;
        if (v >= 0xfffffff000000000ULL) {
            L(@"HIT %s off=0x%04zx val=0x%016llx", tag, i, (unsigned long long)v);
            if (++hits >= maxhits) { L(@"HIT %s ... truncated", tag); break; }
        }
    }
    if (!hits) L(@"--- %s: clean (%zu bytes)", tag, len);
}

#define SAFE(name, body)                                                     \
    do {                                                                     \
        @autoreleasepool {                                                   \
            @try { L(@"== %s: start", name); body; L(@"== %s: done", name); } \
            @catch (NSException *e) {                                        \
                L(@"!! %s: exception %@: %@", name, e.name, e.reason);       \
            }                                                                \
        }                                                                    \
    } while (0)

// ---------------------------------------------------------------- vm_region

static void probe_vm_region(void) {
    mach_vm_address_t addr = 0;
    natural_t depth = 0;
    while (1) {
        mach_vm_size_t size = 0;
        vm_region_submap_info_data_64_t info;
        mach_msg_type_number_t cnt = VM_REGION_SUBMAP_INFO_COUNT_64;
        kern_return_t kr = mach_vm_region_recurse(mach_task_self(), &addr, &size,
                                                  &depth, (vm_region_recurse_info_t)&info, &cnt);
        if (kr != KERN_SUCCESS) break;
        if (cnt >= VM_REGION_SUBMAP_INFO_COUNT_64) {
            L(@"vm_region 0x%llx..0x%llx obj=0x%llx off=0x%llx",
              (unsigned long long)addr, (unsigned long long)(addr + size),
              (unsigned long long)info.object_id, (unsigned long long)info.offset);
            scan("vm_region_info", &info, sizeof(info), 8);
        }
        addr += size;
        depth = 0;
        if (addr == 0) break;
    }
}

// ---------------------------------------------------------------- IOSurface

static void probe_iosurface(void) {
    void *h = dlopen("/System/Library/Frameworks/IOSurface.framework/IOSurface", RTLD_NOW);
    if (!h) { L(@"IOSurface dlopen failed"); return; }

    void *(*create)(CFDictionaryRef) = (void *(*)(CFDictionaryRef))dlsym(h, "IOSurfaceCreate");
    uint32_t (*getid)(void *)      = (uint32_t (*)(void *))dlsym(h, "IOSurfaceGetID");
    CFDictionaryRef (*allv)(void *) = (CFDictionaryRef (*)(void *))dlsym(h, "IOSurfaceCopyAllValues");
    if (!create || !getid) { L(@"IOSurface symbols missing"); return; }

    NSDictionary *props = @{ @"IOSurfaceWidth": @64, @"IOSurfaceHeight": @64,
                             @"IOSurfaceBytesPerElement": @4,
                             @"IOSurfacePixelFormat": @0x42475241 };
    void *s = create((__bridge CFDictionaryRef)props);
    L(@"IOSurfaceCreate = %p", s);
    if (!s) return;
    L(@"IOSurfaceGetID = %u", getid(s));

    if (allv) {
        CFDictionaryRef d = allv(s);
        if (d) {
            NSDictionary *ns = (__bridge_transfer NSDictionary *)d;
            for (id k in ns) {
                id v = ns[k];
                if ([v isKindOfClass:[NSNumber class]]) {
                    unsigned long long n = [v unsignedLongLongValue];
                    L(@"prop %@ = 0x%llx", k, n);
                }
            }
        }
    }

    // IOSurfaceGetBulkAttachments НЕ вызываем: v1 умер именно на нём.
    // Если понадобится — сначала запросить count с NULL-буфером, потом аллоцировать.
    CFRelease((CFTypeRef)s);
}

// ---------------------------------------------------------------- IOKit shmem

static void scan_service_shmem(const char *cls) {
    io_iterator_t it = 0;
    CFMutableDictionaryRef m = IOServiceMatching(cls);
    if (!m) { L(@"%s: no matching dict", cls); return; }
    if (IOServiceGetMatchingServices(kIOMasterPortDefault, m, &it) != KERN_SUCCESS) {
        L(@"%s: no services", cls);
        return;
    }
    io_service_t svc;
    int n = 0;
    while ((svc = IOIteratorNext(it)) && n < 4) {
        io_connect_t conn = 0;
        kern_return_t kr = IOServiceOpen(svc, mach_task_self(), 0, &conn);
        if (kr == KERN_SUCCESS) {
            for (uint32_t type = 0; type < 4; type++) {
                mach_vm_address_t addr = 0;
                mach_vm_size_t size = 0;
                kern_return_t mk = IOConnectMapMemory64(conn, type, mach_task_self(),
                                                        &addr, &size, kIOMapAnywhere);
                if (mk == KERN_SUCCESS && addr && size) {
                    L(@"%s shmem type=%u addr=0x%llx size=0x%llx",
                      cls, type, (unsigned long long)addr, (unsigned long long)size);
                    scan(cls, (const void *)(uintptr_t)addr,
                         size > 0x1000 ? 0x1000 : (size_t)size, 16);
                    IOConnectUnmapMemory64(conn, type, mach_task_self(), addr);
                }
            }
            IOServiceClose(conn);
        } else {
            L(@"%s: open kr=0x%x", cls, kr);
        }
        IOObjectRelease(svc);
        n++;
    }
    IOObjectRelease(it);
}

static void probe_iokit(void) {
    const char *classes[] = { "AGXAccelerator", "IOGPUDevice", "IOAccelerator",
                              "IOSurfaceRoot", "AppleCLCD2", "AppleH11ANEInterface" };
    for (size_t i = 0; i < sizeof(classes) / sizeof(classes[0]); i++)
        scan_service_shmem(classes[i]);
}

// ---------------------------------------------------------------- IORegistry

static void probe_ioregistry(void) {
    io_iterator_t it = 0;
    if (IORegistryCreateIterator(kIOMasterPortDefault, kIOServicePlane,
                                 kIORegistryIterateRecursively, &it) != KERN_SUCCESS)
        { L(@"registry: iterator failed"); return; }
    io_registry_entry_t e;
    int n = 0;
    while ((e = IOIteratorNext(it)) && n < 200) {
        CFMutableDictionaryRef props = NULL;
        if (IORegistryEntryCreateCFProperties(e, &props, kCFAllocatorDefault, 0) == KERN_SUCCESS && props) {
            CFDataRef data = CFPropertyListCreateData(kCFAllocatorDefault, props,
                                                      kCFPropertyListBinaryFormat_v1_0, 0, NULL);
            if (data) {
                scan("ioreg_props", CFDataGetBytePtr(data), CFDataGetLength(data), 4);
                CFRelease(data);
            }
            CFRelease(props);
        }
        IOObjectRelease(e);
        n++;
    }
    IOObjectRelease(it);
    L(@"registry: scanned %d entries", n);
}

// ---------------------------------------------------------------- exclaves

#if TRY_EXCLAVES
static void probe_exclaves(void) {
    // mach traps вызываются с отрицательным номером: mov x16, #-88; svc #0x80.
    // ABI аргументов НЕ подтверждён — вызов может уронить процесс.
    uint64_t buf[64] = {0};
    long r = syscall(-88, (uint32_t)1 /*operation_and_flags*/, (uint64_t)0,
                     (uint64_t)buf, (uint64_t)sizeof(buf),
                     (uint64_t)sizeof(buf), (uint64_t)0, (uint64_t)0);
    L(@"exclaves_ctl -> %ld", r);
    scan("exclaves_buf", buf, sizeof(buf), 8);
}
#endif

// ---------------------------------------------------------------- main

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (nonatomic, strong) UIWindow *window;
@end

@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)opts {
    gLog = [NSMutableString new];
    NSString *docs = [NSHomeDirectory() stringByAppendingPathComponent:@"Documents"];
    [[NSFileManager defaultManager] createDirectoryAtPath:docs
                              withIntermediateDirectories:YES attributes:nil error:nil];
    gLogPath = [docs stringByAppendingPathComponent:@"kaslr2.log"];
    [gLog writeToFile:gLogPath atomically:YES encoding:NSUTF8StringEncoding error:nil];

    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    UIViewController *vc = [UIViewController new];
    UITextView *tv = [[UITextView alloc] initWithFrame:vc.view.bounds];
    tv.editable = NO;
    [vc.view addSubview:tv];
    self.window.rootViewController = vc;
    [self.window makeKeyAndVisible];

    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.6 * NSEC_PER_SEC)),
                   dispatch_get_main_queue(), ^{
        L(@"=== kaslr_probe_v2 start ===");
        L(@"log: %@", gLogPath);

        SAFE("vm_region",    probe_vm_region());
        SAFE("iosurface",    probe_iosurface());
        SAFE("iokit_shmem",  probe_iokit());
        SAFE("ioregistry",   probe_ioregistry());
#if TRY_EXCLAVES
        SAFE("exclaves",     probe_exclaves());
#endif

        L(@"=== done ===");
        tv.text = gLog;
    });
    return YES;
}
@end

int main(int argc, char **argv) {
    @autoreleasepool { return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class])); }
}
