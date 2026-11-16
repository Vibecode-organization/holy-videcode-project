// ctprobe2 — UIKit app that probes AMFI user client from a normal profile-signed app.
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <mach/mach.h>
#import <sys/sysctl.h>
#import <unistd.h>
#import <errno.h>

typedef mach_port_t io_object_t;
typedef io_object_t io_service_t;
typedef io_object_t io_connect_t;
extern io_service_t IOServiceGetMatchingService(mach_port_t masterPort, CFDictionaryRef matching);
extern CFMutableDictionaryRef IOServiceMatching(const char *name);
extern kern_return_t IOServiceOpen(io_service_t service, mach_port_t owningTask, uint32_t type, io_connect_t *connect);
extern kern_return_t IOServiceClose(io_connect_t connect);
extern kern_return_t IOObjectRelease(io_object_t object);
extern kern_return_t IOConnectCallScalarMethod(io_connect_t connection, uint32_t selector,
                                               const uint64_t *input, uint32_t inputCnt,
                                               uint64_t *output, uint32_t *outputCnt);
extern kern_return_t IOConnectCallStructMethod(io_connect_t connection, uint32_t selector,
                                               const void *inputStruct, size_t inputStructCnt,
                                               void *outputStruct, size_t *outputStructCnt);

extern int csops(pid_t pid, unsigned int ops, void *useraddr, size_t usersize);
#define CS_OPS_ENTITLEMENTS_BLOB 7

static FILE *gF;
static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    if (gF) { fprintf(gF, "%s\n", s.UTF8String); fflush(gF); }
    NSLog(@"[ctprobe2] %@", s);
}

static void probeAMFI(void) {
    io_service_t svc = IOServiceGetMatchingService(0, IOServiceMatching("AppleMobileFileIntegrity"));
    L(@"AMFI service=0x%x", svc);
    if (!svc) return;
    io_connect_t conn = 0;
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), 0, &conn);
    L(@"IOServiceOpen(AMFI) -> 0x%x conn=0x%x", kr, conn);
    if (kr != KERN_SUCCESS) { IOObjectRelease(svc); return; }
    for (uint32_t sel = 0; sel <= 12; sel++) {
        uint64_t in[8] = {0}; uint64_t out[16] = {0}; uint32_t outCnt = 16;
        kr = IOConnectCallScalarMethod(conn, sel, in, 0, out, &outCnt);
        L(@"AMFI scalar sel=%u -> 0x%x outCnt=%u", sel, kr, outCnt);
    }
    struct { uint32_t version; uint32_t count; } tc = {1, 0};
    uint64_t out[4] = {0}; size_t outCnt = 4;
    kr = IOConnectCallStructMethod(conn, 1, &tc, sizeof(tc), out, &outCnt);
    L(@"AMFI struct sel=1 (tc v1 count0) -> 0x%x outCnt=%zu", kr, outCnt);
    struct { uint32_t version; uint32_t count; uint8_t cdhash[20]; } tc2 = {1, 1, {0}};
    outCnt = 4;
    kr = IOConnectCallStructMethod(conn, 1, &tc2, sizeof(tc2), out, &outCnt);
    L(@"AMFI struct sel=1 (tc v1 count1 zero cdhash) -> 0x%x outCnt=%zu", kr, outCnt);
    IOServiceClose(conn);
    IOObjectRelease(svc);
}

static void probeFS(void) {
    NSError *e = nil;
    NSArray *a = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:@"/var/mobile/Library/Preferences" error:&e];
    L(@"ls /var/mobile/Library/Preferences -> %lu err=%@", (unsigned long)a.count, e.localizedDescription);
    e = nil;
    BOOL ok = [@"x" writeToFile:@"/var/mobile/Library/Preferences/ctprobe2_marker" atomically:YES encoding:NSUTF8StringEncoding error:&e];
    L(@"write prefs -> %d err=%@", ok, e.localizedDescription);
    e = nil;
    a = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:@"/" error:&e];
    L(@"ls / -> %lu err=%@", (unsigned long)a.count, e.localizedDescription);
}

static void dumpEnts(void) {
    unsigned char buf[8192]; memset(buf,0,sizeof(buf));
    int r = csops(getpid(), CS_OPS_ENTITLEMENTS_BLOB, buf, sizeof(buf));
    L(@"csops(ents) -> %d errno=%d", r, errno);
    if (r != 0) return;
    uint32_t len = ntohl(*(uint32_t *)(buf+4));
    if (len > sizeof(buf)-8) len = sizeof(buf)-8;
    NSString *t = [[NSString alloc] initWithBytes:buf+8 length:len encoding:NSUTF8StringEncoding];
    L(@"ents: %@", t ?: @"(non-utf8)");
}

static void runProbe(void) {
    @autoreleasepool {
        NSString *docs = [NSHomeDirectory() stringByAppendingPathComponent:@"Documents"];
        [[NSFileManager defaultManager] createDirectoryAtPath:docs withIntermediateDirectories:YES attributes:nil error:nil];
        gF = fopen([[docs stringByAppendingPathComponent:@"ctprobe2.log"] UTF8String], "a");
        L(@"=== ctprobe2 start uid=%d euid=%d pid=%d home=%@", getuid(), geteuid(), getpid(), NSHomeDirectory());
        dumpEnts();
        probeFS();
        probeAMFI();
        L(@"=== ctprobe2 done ===");
        if (gF) { fclose(gF); gF = NULL; }
    }
}

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (nonatomic, strong) UIWindow *window;
@end
@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)opts {
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    UIViewController *vc = [UIViewController new];
    vc.view.backgroundColor = [UIColor systemBackgroundColor];
    UILabel *l = [[UILabel alloc] initWithFrame:vc.view.bounds];
    l.text = @"ctprobe2"; l.textAlignment = NSTextAlignmentCenter;
    [vc.view addSubview:l];
    self.window.rootViewController = vc;
    [self.window makeKeyAndVisible];
    dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{ runProbe(); });
    return YES;
}
@end
int main(int argc, char **argv) { @autoreleasepool { return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class])); } }
