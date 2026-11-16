#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <Foundation/Foundation.h>
#import <sys/utsname.h>
#import <string.h>
#import <stdlib.h>

static NSMutableString *gLog; static NSString *gPath;
static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    [gLog appendString:s]; [gLog appendString:@"\n"];
    [gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
    NSLog(@"[iomfbprobe] %@", s);
}
static io_connect_t open_svc(const char *name, uint32_t type) {
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching(name));
    if (!svc) return 0;
    io_connect_t c = 0;
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), type, &c);
    IOObjectRelease(svc);
    return kr == KERN_SUCCESS ? c : 0;
}
static void sweep(io_connect_t c, const char *tag, int maxsel) {
    static const uint32_t scs[] = {0,1,2,3,4};
    static const size_t sis[] = {0, 8, 0x10, 0x20, 0x40, 0x100};
    int hits = 0;
    for (int sel = 0; sel < maxsel; sel++) {
        int selhit = 0;
        for (unsigned a = 0; a < sizeof(scs)/sizeof(scs[0]); a++) {
            for (unsigned b = 0; b < sizeof(sis)/sizeof(sis[0]); b++) {
                uint64_t sv[4] = {0x40, 0x10, 1, 0};
                uint8_t sin[0x100]; memset(sin, 0, sizeof(sin));
                if (sis[b] >= 4) *(uint32_t *)sin = 0x40;
                uint8_t sout[0x1000]; memset(sout, 0, sizeof(sout));
                size_t osz = sizeof(sout);
                kern_return_t kr = IOConnectCallMethod(c, sel, sv, scs[a],
                    sis[b] ? sin : NULL, sis[b], NULL, NULL, sout, &osz);
                if (kr == 0) {
                    L(@"[SEL] %s sel=%d sc=%u si=0x%zx OK osz=0x%zx out=%02x%02x%02x%02x",
                      tag, sel, scs[a], sis[b], osz, sout[0],sout[1],sout[2],sout[3]);
                    selhit = 1; hits++;
                } else if (kr != 0xe00002c2 && kr != 0xe00002c7 && kr != 0xe00000f9 &&
                           kr != 0xe00002bc && kr != 0xe00002e2) {
                    L(@"[SEL] %s sel=%d sc=%u si=0x%zx -> 0x%x", tag, sel, scs[a], sis[b], kr);
                }
            }
        }
        if (selhit && hits > 200) { L(@"[SEL] %s stop hits=%d", tag, hits); return; }
    }
    L(@"[SEL] %s done hits=%d", tag, hits);
}
static void map_probe(io_connect_t c, const char *tag) {
    for (uint32_t t = 0; t < 12; t++) {
        mach_vm_address_t addr = 0; mach_vm_size_t size = 0x4000;
        kern_return_t kr = IOConnectMapMemory64(c, t, mach_task_self(), &addr, &size, kIOMapAnywhere);
        if (kr == 0) L(@"[MAP] %s type=%u OK addr=0x%llx size=0x%llx", tag, t,
                      (unsigned long long)addr, (unsigned long long)size);
        else if (kr != 0xe00002c2) L(@"[MAP] %s type=%u -> 0x%x", tag, t, kr);
        if (kr == 0) IOConnectUnmapMemory64(c, t, mach_task_self(), addr);
    }
}
static void scan_services(void) {
    io_iterator_t iter = 0;
    kern_return_t kr = IOServiceGetMatchingServices(kIOMasterPortDefault,
                                                    IOServiceMatching("IOService"), &iter);
    L(@"[SCAN] iterator -> 0x%x", kr);
    if (kr != KERN_SUCCESS) return;
    io_service_t svc; int total = 0, opened = 0;
    while ((svc = IOIteratorNext(iter))) {
        total++;
        io_name_t cls; memset(cls, 0, sizeof(cls));
        IOObjectGetClass(svc, cls);
        for (uint32_t t = 0; t < 3; t++) {
            io_connect_t c = 0;
            kern_return_t okr = IOServiceOpen(svc, mach_task_self(), t, &c);
            if (okr == KERN_SUCCESS && c) {
                L(@"[OPEN] %s t=%u conn=0x%x", cls, t, c);
                IOServiceClose(c);
                opened++;
                break;
            }
        }
        IOObjectRelease(svc);
    }
    IOObjectRelease(iter);
    L(@"[SCAN] total=%d opened=%d", total, opened);
}

static void keystore_probe(void) {
    io_connect_t c = open_svc("AppleKeyStore", 0);
    if (!c) { L(@"[KS] no conn"); return; }
    static const size_t sis[] = {0, 0x10, 0x20, 0x100, 0x1000};
    for (int sel = 0; sel < 24; sel++) {
        for (int sc = 0; sc <= 3; sc++) {
            for (unsigned b = 0; b < sizeof(sis)/sizeof(sis[0]); b++) {
                uint64_t sv[3] = {0, 0, 0};
                uint8_t sin[0x1000]; memset(sin, 0, sizeof(sin));
                uint8_t sout[0x1000]; memset(sout, 0, sizeof(sout)); size_t osz = sizeof(sout);
                uint64_t so[4] = {0,0,0,0}; uint32_t soc = 4;
                kern_return_t kr = IOConnectCallMethod(c, sel, sv, sc,
                    sis[b] ? sin : NULL, sis[b], so, &soc, sout, &osz);
                if (kr == 0)
                    L(@"[KS] sel=%d sc=%d si=0x%zx -> 0 osz=0x%zx so=%llx,%llx,%llx,%llx first=%02x%02x%02x%02x",
                      sel, sc, sis[b], osz, (unsigned long long)so[0], (unsigned long long)so[1],
                      (unsigned long long)so[2], (unsigned long long)so[3], sout[0],sout[1],sout[2],sout[3]);
                else if (kr != 0xe00002c2 && kr != 0xe00002c7 && kr != 0xe00002bc && kr != 0xe00000f9)
                    L(@"[KS] sel=%d sc=%d si=0x%zx -> 0x%x", sel, sc, sis[b], kr);
            }
        }
    }
    IOServiceClose(c);
}

static void run(void) {
    struct utsname u; uname(&u);
    L(@"=== IOMFBProbe start %s ===", u.version);
    keystore_probe();
    scan_services();
    const char *names[] = {};
    for (unsigned n = 0; n < sizeof(names)/sizeof(names[0]); n++) {
        io_connect_t c = 0;
        for (uint32_t t = 0; t < 4 && !c; t++) {
            c = open_svc(names[n], t);
            L(@"[OPEN] %s type=%u conn=0x%x", names[n], t, c);
        }
        if (!c) continue;
        sweep(c, names[n], 110);
        map_probe(c, names[n]);
        IOServiceClose(c);
    }
    L(@"=== done ===");
}
@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (strong, nonatomic) UIWindow *window;
@end
@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)opts {
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    UIViewController *vc = [UIViewController new]; vc.view.backgroundColor = UIColor.blackColor;
    UITextView *tv = [[UITextView alloc] initWithFrame:vc.view.bounds];
    tv.backgroundColor = UIColor.blackColor; tv.textColor = UIColor.greenColor;
    tv.font = [UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];
    tv.editable = NO; tv.text = @"IOMFBProbe\n";
    [vc.view addSubview:tv]; self.window.rootViewController = vc; [self.window makeKeyAndVisible];
    [UIApplication sharedApplication].idleTimerDisabled = YES;
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0), ^{
        NSString *docs = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject];
        gPath = [docs stringByAppendingPathComponent:@"iomfb.log"];
        gLog = [NSMutableString new]; run();
        dispatch_async(dispatch_get_main_queue(), ^{ tv.text = gLog; });
    });
    return YES;
}
@end
int main(int argc, char **argv) { @autoreleasepool { return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class])); } }
