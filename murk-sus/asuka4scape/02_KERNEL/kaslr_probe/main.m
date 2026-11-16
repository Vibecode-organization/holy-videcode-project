// kaslr_probe — 27.2 KASLR leak probe (Theos app, arm64e)
// Builds a list of userspace-reachable kernel interfaces and scans their
// outputs for kernel-looking pointers (0xffff000000000000+).
//
// Run on iPhone14,7 27.2, then read the on-screen log / Console output.

#import <UIKit/UIKit.h>
#import <mach/mach.h>
#import <mach/mach_host.h>
#import <mach/mach_port.h>
#import <mach/task_info.h>
#import <mach/thread_info.h>
#import <sys/sysctl.h>
#import <dlfcn.h>
#import <IOKit/IOKitLib.h>

static NSMutableString *gLog;
static UITextView *gTV;
static NSString *gLogPath;

static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    [gLog appendString:s]; [gLog appendString:@"\n"];
    NSLog(@"[kaslr] %@", s);
    if (gLogPath) [gLog writeToFile:gLogPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
    if (gTV) gTV.text = gLog;
}

static void scan(const char *tag, const void *buf, size_t len) {
    const uint64_t *p = (const uint64_t *)buf;
    int hits = 0;
    for (size_t i = 0; i + 8 <= len; i += 8, p++) {
        uint64_t v = *p;
        if (v >= 0xffff000000000000ULL) {
            L(@"HIT %s off=0x%03lx val=0x%016llx", tag, (unsigned long)i, (unsigned long long)v);
            if (++hits >= 24) { L(@"HIT %s ... truncated", tag); break; }
        }
    }
    if (!hits) L(@"--- %s no kernel-looking values (%lu bytes)", tag, (unsigned long)len);
}

static void probe_kobject(void) {
    mach_port_t host = mach_host_self();
    mach_port_t task = mach_task_self();
    natural_t type = 0; mach_vm_address_t kobj = 0;
    kern_return_t kr = mach_port_kobject(mach_task_self(), host, &type, &kobj);
    L(@"mach_port_kobject(host): kr=%d kobj=0x%llx type=%u", kr, (unsigned long long)kobj, type);
    kobj = 0; type = 0;
    kr = mach_port_kobject(mach_task_self(), task, &type, &kobj);
    L(@"mach_port_kobject(task): kr=%d kobj=0x%llx type=%u", kr, (unsigned long long)kobj, type);
}

static void probe_space_info(void) {
    ipc_info_space_t info = {0};
    ipc_info_name_array_t table = NULL;
    mach_msg_type_number_t tcount = 0;
    ipc_info_tree_name_array_t tree = NULL;
    mach_msg_type_number_t tcount2 = 0;
    kern_return_t kr = mach_port_space_info(mach_task_self(), &info, &table, &tcount, &tree, &tcount2);
    L(@"mach_port_space_info: kr=%d tcount=%u treecount=%u", kr, tcount, tcount2);
    scan("space_info", &info, sizeof(info));
    if (table && tcount) scan("space_table", table, tcount * sizeof(ipc_info_name_t));
    if (tree && tcount2) scan("space_tree", tree, tcount2 * sizeof(ipc_info_tree_name_t));
    if (table) vm_deallocate(mach_task_self(), (vm_address_t)table, tcount * sizeof(ipc_info_name_t));
    if (tree) vm_deallocate(mach_task_self(), (vm_address_t)tree, tcount2 * sizeof(ipc_info_tree_name_t));
}

static void probe_task_info(void) {
    for (int f = 0; f <= 32; f++) {
        uint8_t buf[4096]; memset(buf, 0, sizeof(buf));
        mach_msg_type_number_t cnt = sizeof(buf)/sizeof(natural_t);
        kern_return_t kr = task_info(mach_task_self(), f, (task_info_t)buf, &cnt);
        if (kr == KERN_SUCCESS) {
            char tag[64]; snprintf(tag, sizeof(tag), "task_info.flavor%d", f);
            scan(tag, buf, (size_t)cnt * sizeof(natural_t));
        }
    }
}

static void probe_thread_info(void) {
    thread_t th = mach_thread_self();
    for (int f = 0; f <= 20; f++) {
        uint8_t buf[2048]; memset(buf, 0, sizeof(buf));
        mach_msg_type_number_t cnt = sizeof(buf)/sizeof(natural_t);
        kern_return_t kr = thread_info(th, f, (thread_info_t)buf, &cnt);
        if (kr == KERN_SUCCESS) {
            char tag[64]; snprintf(tag, sizeof(tag), "thread_info.flavor%d", f);
            scan(tag, buf, (size_t)cnt * sizeof(natural_t));
        }
    }
}

static void probe_kinfo(void) {
    int pids[2] = { 0, getpid() };
    for (int i = 0; i < 2; i++) {
        int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, pids[i] };
        uint8_t buf[2048] = {0}; size_t len = sizeof(buf);
        if (sysctl(mib, 4, buf, &len, NULL, 0) == 0) {
            char tag[64]; snprintf(tag, sizeof(tag), "kinfo_proc.%d", pids[i]);
            scan(tag, buf, len);
        } else {
            L(@"sysctl kinfo_proc.%d failed", pids[i]);
        }
    }
}

static void probe_iosurface_root(uint32_t sid) {
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("IOSurfaceRoot"));
    if (!svc) { L(@"IOSurfaceRoot: service not found"); return; }
    io_connect_t conn = 0;
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), 0, &conn);
    L(@"IOSurfaceRoot open: kr=%d conn=%u sid=%u", kr, conn, sid);
    IOObjectRelease(svc);
    if (kr != KERN_SUCCESS) return;
    static const struct { uint32_t sel, sin, szout, sout; } tbl[] = {
        {4,1,3176,0},{7,2,3176,0},{13,0,40,0},{28,1,160,0},{30,1,0xffffffff,0},
        {34,1,3176,0},{49,1,0xffffffff,0},{51,2,0xffffffff,2},{64,1,3176,0},
        {67,2,3176,0},{73,0,40,0},{88,1,160,0},{90,1,0xffffffff,0},
        {94,1,3176,0},{109,1,0xffffffff,0},{111,2,0xffffffff,2},
    };
    for (unsigned i = 0; i < sizeof(tbl)/sizeof(tbl[0]); i++) {
        uint64_t in[4] = { sid, 0, 0, 0 };
        uint64_t out[8] = {0}; uint32_t outCnt = 8;
        size_t osz = (tbl[i].szout == 0xffffffff) ? 0xc68 : tbl[i].szout;
        if (osz > 0xc68) osz = 0xc68;
        uint8_t obuf[0xc68]; memset(obuf, 0, sizeof(obuf));
        kr = IOConnectCallMethod(conn, tbl[i].sel, in, tbl[i].sin, NULL, 0,
                                 out, &outCnt, obuf, &osz);
        char tag[64]; snprintf(tag, sizeof(tag), "IOSurfaceRoot.sel%u", tbl[i].sel);
        L(@"%s: kr=%d outsz=%zu outCnt=%u", tag, kr, osz, outCnt);
        if (kr == KERN_SUCCESS && osz > 0) scan(tag, obuf, osz);
        if (kr == KERN_SUCCESS) scan("IOSurfaceRoot.scalarOut", out, (size_t)outCnt * 8);
    }
    IOServiceClose(conn);
}

static void probe_iokit_surface(void) {
    void *h = dlopen("/System/Library/Frameworks/IOSurface.framework/IOSurface", RTLD_NOW);
    if (!h) { L(@"IOSurface dlopen failed"); return; }
    void *(*create)(CFDictionaryRef) = (void *(*)(CFDictionaryRef))dlsym(h, "IOSurfaceCreate");
    if (!create) { L(@"no IOSurfaceCreate"); return; }
    NSDictionary *props = @{ @"IOSurfaceWidth": @64, @"IOSurfaceHeight": @64,
                             @"IOSurfaceBytesPerElement": @4, @"IOSurfacePixelFormat": @0x42475241 };
    void *s = create((__bridge CFDictionaryRef)props);
    L(@"IOSurfaceCreate: %p", s);
    if (!s) return;
    uint32_t (*getid)(void *) = (uint32_t (*)(void *))dlsym(h, "IOSurfaceGetID");
    uint32_t sid = getid ? getid(s) : 0;
    L(@"IOSurfaceGetID = %u", sid);
    probe_iosurface_root(sid);

    // 1) IOSurfaceCopyAllValues: dump every property, flag kernel-looking numbers
    CFDictionaryRef (*allv)(void *) = (CFDictionaryRef (*)(void *))dlsym(h, "IOSurfaceCopyAllValues");
    if (allv) {
        CFDictionaryRef d = allv(s);
        if (d) {
            NSDictionary *ns = (__bridge_transfer NSDictionary *)d;
            for (id key in ns) {
                id v = ns[key];
                if ([v isKindOfClass:[NSNumber class]]) {
                    unsigned long long n = [v unsignedLongLongValue];
                    L(@"prop %@ = 0x%llx", key, n);
                    if (n >= 0xffff000000000000ULL) L(@"HIT prop %@ = 0x%llx", key, n);
                } else {
                    L(@"prop %@ = %@", key, v);
                }
            }
        } else L(@"IOSurfaceCopyAllValues: null");
    } else L(@"no IOSurfaceCopyAllValues symbol");

    // 2) private IOSurfaceGetAddress
    void *(*getaddr)(void *) = (void *(*)(void *))dlsym(h, "IOSurfaceGetAddress");
    if (getaddr) {
        void *a = getaddr(s);
        L(@"IOSurfaceGetAddress = %p", a);
        if ((uintptr_t)a >= 0xffff000000000000ULL) L(@"HIT IOSurfaceGetAddress = %p", a);
    } else L(@"no IOSurfaceGetAddress symbol");

    // 3) IOSurfaceCopyValue for address-ish keys
    CFTypeRef (*copyv)(void *, CFStringRef) = (CFTypeRef (*)(void *, CFStringRef))dlsym(h, "IOSurfaceCopyValue");
    if (copyv) {
        const char *keys[] = { "IOSurfaceAddress", "IOSurfaceBase", "IOSurfacePlaneBase",
                               "IOSurfaceMemoryRegion", "IOSurfaceAddressOffset" };
        for (int i = 0; i < 5; i++) {
            CFStringRef k = CFStringCreateWithCString(NULL, keys[i], kCFStringEncodingUTF8);
            CFTypeRef v = copyv(s, k);
            if (v) {
                if (CFGetTypeID(v) == CFNumberGetTypeID()) {
                    long long n = 0; CFNumberGetValue((CFNumberRef)v, kCFNumberSInt64Type, &n);
                    L(@"CopyValue[%s] = 0x%llx", keys[i], (unsigned long long)n);
                    if ((unsigned long long)n >= 0xffff000000000000ULL) L(@"HIT CopyValue[%s] = 0x%llx", keys[i], (unsigned long long)n);
                } else if (CFGetTypeID(v) == CFStringGetTypeID()) {
                    L(@"CopyValue[%s] = %@", keys[i], (__bridge NSString *)v);
                } else L(@"CopyValue[%s] = CFType %lu", keys[i], (unsigned long)CFGetTypeID(v));
                CFRelease(v);
            } else L(@"CopyValue[%s] = null", keys[i]);
            CFRelease(k);
        }
    } else L(@"no IOSurfaceCopyValue symbol");

    CFRelease((CFTypeRef)s);
}

static void run_all(void) {
    L(@"=== kaslr_probe 27.2 start ===");
    probe_kobject();
    probe_space_info();
    probe_task_info();
    probe_thread_info();
    probe_kinfo();
    probe_iokit_surface();
    L(@"=== done ===");
}

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (nonatomic, strong) UIWindow *window;
@end

@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)opts {
    gLog = [NSMutableString new];
    NSString *docs = [NSHomeDirectory() stringByAppendingPathComponent:@"Documents"];
    [[NSFileManager defaultManager] createDirectoryAtPath:docs withIntermediateDirectories:YES attributes:nil error:nil];
    gLogPath = [docs stringByAppendingPathComponent:@"kaslr.log"];
    [gLog writeToFile:gLogPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    UIViewController *vc = [UIViewController new];
    gTV = [[UITextView alloc] initWithFrame:vc.view.bounds];
    gTV.editable = NO; gTV.font = [UIFont fontWithName:@"Menlo" size:10];
    [vc.view addSubview:gTV];
    self.window.rootViewController = vc;
    [self.window makeKeyAndVisible];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.6 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        run_all();
    });
    return YES;
}
@end

int main(int argc, char **argv) {
    @autoreleasepool { return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class])); }
}
