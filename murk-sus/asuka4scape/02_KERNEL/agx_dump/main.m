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
    NSLog(@"[agxdump] %@", s);
}
static void dump(const char *tag, const uint8_t *b, size_t n) {
    for (size_t i = 0; i < n; i += 16) {
        NSMutableString *s = [NSMutableString stringWithFormat:@"[%s] %04zx: ", tag, i];
        for (size_t j = 0; j < 16 && i + j < n; j++) [s appendFormat:@"%02x ", b[i+j]];
        [s appendString:@" | "];
        for (size_t j = 0; j < 16 && i + j < n; j += 8) {
            uint64_t q = 0; memcpy(&q, b+i+j, 8);
            [s appendFormat:@"%016llx ", (unsigned long long)q];
        }
        L(@"%@", s);
    }
}
static kern_return_t call(io_connect_t c, uint32_t sel, const uint64_t *sv, uint32_t sc,
                          void *si, size_t sis, void *so, size_t *sos) {
    return IOConnectCallMethod(c, sel, sv, sc, si, sis, NULL, NULL, so, sos);
}
static void run(void) {
    struct utsname u; uname(&u);
    L(@"=== AGXDump %s ===", u.version);
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("AGXAcceleratorG14P"));
    L(@"[svc] 0x%x", svc);
    if (!svc) return;
    io_connect_t c = 0;
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), 1, &c);
    L(@"[open] type1 -> 0x%x conn=0x%x", kr, c);
    IOObjectRelease(svc);
    if (kr) return;
    uint8_t out[0x1000];

    memset(out, 0xCC, sizeof(out)); size_t os = 0x40;
    kr = call(c, 0, NULL, 0, NULL, 0, out, &os);
    L(@"[sel0] -> 0x%x osz=0x%zx", kr, os); if (!kr) dump("sel0", out, os);
    memset(out, 0xCC, sizeof(out)); os = 0x40;
    kr = call(c, 1, NULL, 0, NULL, 0, out, &os);
    L(@"[sel1] -> 0x%x osz=0x%zx", kr, os); if (!kr) dump("sel1", out, os);
    memset(out, 0xCC, sizeof(out)); os = 0x218;
    kr = call(c, 2, NULL, 0, NULL, 0, out, &os);
    L(@"[sel2] -> 0x%x osz=0x%zx", kr, os); if (!kr) dump("sel2", out, 0x80);
    if (!kr) {
        uint64_t base = *(uint64_t *)out;
        L(@"[sel2page] base=0x%llx", (unsigned long long)base);
        if (base > 0x100000000ULL) {
            for (int i = 0; i < 0x4000; i += 4) {
                uint32_t v = *(volatile uint32_t *)(base + i);
                if (v == 0x04D00000 || v == 0x4D00000 || (v >= 0x80000000 && v < 0x100000000)) {
                    L(@"[sel2hit] +0x%x u32=0x%08x", i, v);
                }
            }
            for (int i = 0; i < 0x4000; i += 8) {
                uint64_t q = *(volatile uint64_t *)(base + i);
                if ((q & 0xfffffff000000000ULL) == 0xfffffff000000000ULL || (q >= 0x800000000ULL && q < 0x1000000000ULL)) {
                    L(@"[sel2hit64] +0x%x q=0x%llx", i, (unsigned long long)q);
                }
            }
        }
    }
    memset(out, 0xCC, sizeof(out)); os = 8;
    kr = call(c, 3, NULL, 0, NULL, 0, out, &os);
    L(@"[sel3] -> 0x%x osz=0x%zx", kr, os); if (!kr) dump("sel3", out, os);
    memset(out, 0xCC, sizeof(out)); os = 0x20;
    kr = call(c, 4, NULL, 0, NULL, 0, out, &os);
    L(@"[sel4] -> 0x%x osz=0x%zx", kr, os); if (!kr) dump("sel4", out, os);
    // scan sel4 pages for PA/PTE/TTBAT
    {
        uint64_t p1 = *(uint64_t *)(out + 8), p2 = *(uint64_t *)(out + 0x10);
        uint64_t sz = *(uint64_t *)(out + 0x18);
        L(@"[sel4scan] p1=0x%llx p2=0x%llx sz=0x%llx", (unsigned long long)p1,
          (unsigned long long)p2, (unsigned long long)sz);
        uint64_t pages[2] = {p1, p2};
        for (int pi = 0; pi < 2; pi++) {
            uint64_t base = pages[pi];
            if (base < 0x100000000ULL) continue;
            for (int i = 0; i < 0x4000; i += 8) {
                uint64_t q = *(volatile uint64_t *)(base + i);
                if ((q & 0xfffffff000000000ULL) == 0xfffffff000000000ULL ||
                    (q >= 0x800000000ULL && q < 0x1000000000ULL) ||
                    q == 0x04D00000 || q == 0x4D00000) {
                    L(@"[sel4hit%d] +0x%x q=0x%llx", pi, i, (unsigned long long)q);
                }
            }
        }
    }
    memset(out, 0xCC, sizeof(out)); os = 0x10;
    kr = call(c, 5, NULL, 0, NULL, 0, out, &os);
    L(@"[sel5] -> 0x%x osz=0x%zx", kr, os); if (!kr) dump("sel5", out, os);

    // sel6 probing with various sizes
    uint8_t sin[0x1000]; memset(sin, 0, sizeof(sin));
    for (size_t sz = 0x400; sz <= 0x420; sz += 8) {
        memset(out, 0xCC, sizeof(out)); os = 0x10;
        kr = call(c, 6, NULL, 0, sin, sz, out, &os);
        L(@"[sel6] si=0x%zx -> 0x%x osz=0x%zx out0=%016llx out8=%016llx", sz, kr, os,
          (unsigned long long)*(uint64_t*)out, (unsigned long long)*(uint64_t*)(out+8));
    }
    IOServiceClose(c);
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
    tv.editable = NO; tv.text = @"AGXDump\n";
    [vc.view addSubview:tv]; self.window.rootViewController = vc; [self.window makeKeyAndVisible];
    [UIApplication sharedApplication].idleTimerDisabled = YES;
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0), ^{
        NSString *docs = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject];
        gPath = [docs stringByAppendingPathComponent:@"agx.log"];
        gLog = [NSMutableString new]; run();
        dispatch_async(dispatch_get_main_queue(), ^{ tv.text = gLog; });
    });
    return YES;
}
@end
int main(int argc, char **argv) { @autoreleasepool { return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class])); } }
