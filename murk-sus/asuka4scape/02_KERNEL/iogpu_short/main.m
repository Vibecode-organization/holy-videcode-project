// IOGPUShortProbe3 — IOGPU/AGX queue path, sel45 scalar-count variants.
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <IOKit/IOKitLib.h>
#import <mach/mach.h>
#import <sys/utsname.h>
#import <string.h>
#import <unistd.h>

static NSMutableString *gLog;
static NSString *gPath;
static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    [gLog appendString:s]; [gLog appendString:@"\n"];
    [gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
    NSLog(@"[iogpushort3] %@", s);
}

static io_connect_t open_service(const char *name, const char *tag) {
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching(name));
    if (!svc) { L(@"[%s] service %s absent", tag, name); return 0; }
    io_connect_t c = 0;
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), 1, &c);
    L(@"[%s] open %s type1 -> 0x%x conn=0x%x", tag, name, kr, c);
    IOObjectRelease(svc);
    return kr == KERN_SUCCESS ? c : 0;
}

static void probe_queue(io_connect_t c, const char *tag) {
    uint64_t s14[2] = {0x10, 0x10};
    uint8_t o14[0x10]; memset(o14, 0, sizeof(o14));
    size_t o14sz = sizeof(o14);
    kern_return_t kr = IOConnectCallMethod(c, 14, s14, 2, NULL, 0, NULL, NULL, o14, &o14sz);
    L(@"[%s] sel14 -> 0x%x osz=0x%zx id=0x%llx val=0x%llx", tag, kr, o14sz,
      (unsigned long long)*(uint64_t *)o14, (unsigned long long)*(uint64_t *)(o14 + 8));
    uint32_t nid = (uint32_t)*(uint64_t *)(o14 + 8);
    if (kr) return;

    static const uint64_t pairs[][2] = {
        {0, 0}, {0x10, 0x10}, {0x100, 0x10}, {0x1000, 0x1000},
        {0x4000, 0x10}, {0x10, 0x1000}, {0x4000, 0x4000},
    };
    uint32_t qid = 0;
    for (unsigned i = 0; i < sizeof(pairs)/sizeof(pairs[0]); i++) {
        uint64_t s42[2] = {pairs[i][0], pairs[i][1]};
        uint64_t o42[2] = {0}; uint32_t o42cnt = 2;
        kr = IOConnectCallMethod(c, 42, s42, 2, NULL, 0, o42, &o42cnt, NULL, NULL);
        L(@"[%s] sel42 {0x%llx,0x%llx} -> 0x%x id=0x%llx serial=0x%llx", tag,
          (unsigned long long)pairs[i][0], (unsigned long long)pairs[i][1],
          kr, (unsigned long long)o42[0], (unsigned long long)o42[1]);
        if (kr == 0 && o42[0]) { qid = (uint32_t)o42[0]; break; }
    }
    if (!qid) return;
    {
        uint64_t s44[2] = {qid, nid};
        kr = IOConnectCallMethod(c, 44, s44, 2, NULL, 0, NULL, NULL, NULL, NULL);
        L(@"[%s] sel44 {q=0x%x,n=0x%x} -> 0x%x", tag, qid, nid, kr);
    }
    // sel45 layout: scalarInput[0] = queue id; structureInput = {u32 count,
    // then count entries of 0x18 bytes}; structureInputSize = 8 + count*0x18.
    for (int n = 1; n <= 4; n++) {
        uint8_t si[0x400]; memset(si, 0, sizeof(si));
        *(uint32_t *)si = (uint32_t)n;      // command count
        size_t ssz = 8 + 0x18 * n;
        uint64_t s45[1] = { (uint64_t)qid };
        kr = IOConnectCallMethod(c, 45, s45, 1, si, ssz, NULL, NULL, NULL, NULL);
        L(@"[%s] sel45 q=%u count=%d ssz=0x%zx -> 0x%x", tag, qid, n, ssz, kr);
        // also try a variant whose first command word is a small handle
        *(uint32_t *)(si + 8) = 1;
        kr = IOConnectCallMethod(c, 45, s45, 1, si, ssz, NULL, NULL, NULL, NULL);
        L(@"[%s] sel45 q=%u count=%d h=1 -> 0x%x", tag, qid, n, kr);
    }
    // IO command buffer: sel46 creates one, returns {cbId, object field}.
    {
        uint64_t so[2] = {0,0}; uint32_t soc = 2;
        uint64_t s46[1] = { (uint64_t)qid };
        kr = IOConnectCallMethod(c, 46, s46, 1, NULL, 0, so, &soc, NULL, NULL);
        L(@"[%s] sel46 create-cb q=%u -> 0x%x cbId=0x%llx f=0x%llx", tag, qid, kr,
          (unsigned long long)so[0], (unsigned long long)so[1]);
        if (kr == 0 && so[0]) {
            // Is the second output an IOSurface ID for the command shmem?
            IOSurfaceRef cbs = IOSurfaceLookup((uint32_t)so[1]);
            L(@"[%s] IOSurfaceLookup(0x%x) -> %p", tag, (uint32_t)so[1], cbs);
            if (cbs) {
                L(@"[%s] cb surface id=%u alloc=0x%zx base=%p", tag, IOSurfaceGetID(cbs),
                  IOSurfaceGetAllocSize(cbs), IOSurfaceGetBaseAddress(cbs));
                CFRelease(cbs);
            }
            IOSurfaceRef cbs2 = IOSurfaceLookup((uint32_t)(so[1] >> 32));
            L(@"[%s] IOSurfaceLookup(hi 0x%x) -> %p", tag, (uint32_t)(so[1] >> 32), cbs2);
            if (cbs2) CFRelease(cbs2);
            // Is f a user VA (mapped in our task) or a GPU/physical address?
            {
                uint8_t tmp[0x40]; mach_vm_size_t got = 0;
                kern_return_t rr = mach_vm_read_overwrite(mach_task_self(),
                    (mach_vm_address_t)so[1], 0x20, (mach_vm_address_t)tmp, &got);
                L(@"[%s] vm_read f=0x%llx -> 0x%x got=0x%llx", tag,
                  (unsigned long long)so[1], rr, (unsigned long long)got);
                if (rr == KERN_SUCCESS) {
                    L(@"[%s] f data: %08x %08x %08x %08x", tag,
                      ((uint32_t*)tmp)[0],((uint32_t*)tmp)[1],((uint32_t*)tmp)[2],((uint32_t*)tmp)[3]);
                }
                mach_vm_address_t base = (mach_vm_address_t)(so[1] & ~0xfffULL);
                rr = mach_vm_read_overwrite(mach_task_self(), base, 0x20,
                                            (mach_vm_address_t)tmp, &got);
                L(@"[%s] vm_read base=0x%llx -> 0x%x got=0x%llx", tag,
                  (unsigned long long)base, rr, (unsigned long long)got);
                if (rr == KERN_SUCCESS) {
                    L(@"[%s] base data: %08x %08x %08x %08x", tag,
                      ((uint32_t*)tmp)[0],((uint32_t*)tmp)[1],((uint32_t*)tmp)[2],((uint32_t*)tmp)[3]);
                }
            }
            uint8_t *cmd = NULL;
            if (posix_memalign((void **)&cmd, 0x4000, 0x4000) == 0) {
                memset(cmd, 0, 0x4000);
                // entry = {nonzero, cbId, user cmdlist VA, flags}
                for (int pat = 0; pat < 3; pat++) {
                    memset(cmd, 0, 0x4000);
                    if (pat == 1) *(uint32_t *)(cmd + 0) = 1;
                    if (pat == 2) memset(cmd, 0x41, 0x1000);
                    uint8_t si[0x20]; memset(si, 0, sizeof(si));
                    *(uint32_t *)(si + 0x00) = 1;
                    *(uint32_t *)(si + 0x04) = (uint32_t)so[0];
                    *(uint64_t *)(si + 0x08) = (uint64_t)(uintptr_t)cmd;
                    *(uint32_t *)(si + 0x10) = 0;
                    uint64_t s45[1] = { (uint64_t)qid };
                    kr = IOConnectCallMethod(c, 45, s45, 1, si, 0x20, NULL, NULL, NULL, NULL);
                    L(@"[%s] sel45 cb pat=%d cbId=0x%llx cmd=%p -> 0x%x", tag, pat,
                      (unsigned long long)so[0], cmd, kr);
                    L(@"[%s] cmd[0..3]=%08x %08x %08x %08x", tag,
                      ((uint32_t*)cmd)[0], ((uint32_t*)cmd)[1], ((uint32_t*)cmd)[2], ((uint32_t*)cmd)[3]);
                }
            }
        }
    }
}

static void probe_sel52(io_connect_t c, const char *tag) {
    uint64_t s52[2] = {1, 0};
    uint8_t si[0x40]; memset(si, 0, sizeof(si));
    *(uint32_t *)(si + 0x00) = 1;
    *(uint32_t *)(si + 0x08) = 0x10;
    *(uint64_t *)(si + 0x10) = 4;
    *(uint64_t *)(si + 0x18) = 0x10;
    kern_return_t kr = IOConnectCallMethod(c, 52, s52, 2, si, 4,
                                           NULL, NULL, NULL, NULL);
    L(@"[%s] sel52 4-byte -> 0x%x", tag, kr);
    kr = IOConnectCallMethod(c, 52, s52, 2, si, 0x40,
                             NULL, NULL, NULL, NULL);
    L(@"[%s] sel52 0x40 -> 0x%x", tag, kr);
    uint64_t s53[2] = {1, 0};
    kr = IOConnectCallMethod(c, 53, s53, 2, si, 0x40,
                             NULL, NULL, NULL, NULL);
    L(@"[%s] sel53 0x40 -> 0x%x", tag, kr);
}

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (strong, nonatomic) UIWindow *window;
@end

@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)opts {
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    UIViewController *vc = [UIViewController new];
    vc.view.backgroundColor = UIColor.blackColor;
    UITextView *tv = [[UITextView alloc] initWithFrame:vc.view.bounds];
    tv.backgroundColor = UIColor.blackColor; tv.textColor = UIColor.greenColor;
    tv.font = [UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];
    tv.editable = NO; tv.text = @"IOGPUShortProbe3 running...\n";
    [vc.view addSubview:tv]; self.window.rootViewController = vc;
    [self.window makeKeyAndVisible];
    [UIApplication sharedApplication].idleTimerDisabled = YES;
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0), ^{
        NSString *docs = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject];
        gPath = [docs stringByAppendingPathComponent:@"iogpu_short3.log"];
        gLog = [NSMutableString new];
        struct utsname u = {0}; uname(&u);
        L(@"=== IOGPUShortProbe3 start %s %s ===", u.machine, u.version);
        io_connect_t a = open_service("IOGPU", "IOGPU");
        if (a) { probe_queue(a, "IOGPU"); probe_sel52(a, "IOGPU"); IOServiceClose(a); }
        io_connect_t b = open_service("AGXAcceleratorG14P", "AGX");
        if (b) { probe_queue(b, "AGX"); probe_sel52(b, "AGX"); IOServiceClose(b); }
        L(@"=== done ===");
        dispatch_async(dispatch_get_main_queue(), ^{ tv.text = gLog; });
    });
    return YES;
}
@end

int main(int argc, char **argv) {
    @autoreleasepool { return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class])); }
}
