// ctprobe2 — UIKit app that probes AMFI user client from a normal profile-signed app.
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <mach/mach.h>
#import <sys/sysctl.h>
#import <unistd.h>
#import <errno.h>
#import <dlfcn.h>

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
    for (uint32_t type = 0; type <= 10; type++) {
        io_connect_t conn = 0;
        kern_return_t kr = IOServiceOpen(svc, mach_task_self(), type, &conn);
        L(@"AMFI open type=%u -> 0x%x conn=0x%x", type, kr, conn);
        if (kr == KERN_SUCCESS) IOServiceClose(conn);
    }
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

static void probeSymbols(void) {
    const char *paths[] = {
        "/System/Library/PrivateFrameworks/MobileInBoxUpdate.framework/MobileInBoxUpdate",
        "/System/Library/Frameworks/Security.framework/Security",
        "/usr/lib/libmis.dylib",
        NULL
    };
    const char *syms[] = {
        "CTEvaluateAMFICodeSignatureCMS",
        "CTEvaluateSavageCerts",
        "CTEvaluateCertsForPolicy",
        "CTEvaluatePragueSignatureCMS",
        NULL
    };
    for (int i = 0; paths[i]; i++) {
        void *h = dlopen(paths[i], RTLD_NOW);
        L(@"dlopen %s -> %p err=%s", paths[i], h, h ? "-" : dlerror());
        for (int j = 0; syms[j]; j++) {
            L(@"  dlsym %s -> %p", syms[j], h ? dlsym(h, syms[j]) : NULL);
        }
    }
    for (int j = 0; syms[j]; j++) {
        L(@"RTLD_DEFAULT %s -> %p", syms[j], dlsym(RTLD_DEFAULT, syms[j]));
    }
}

typedef int (*ct_amfi_fn)(const uint8_t *cms, size_t cmsLen, const uint8_t *det, size_t detLen,
                          bool allowTest, const uint8_t **leaf, size_t *leafLen,
                          uint64_t *policy, uint32_t *cmsDig, uint32_t *agil,
                          const uint8_t **dig, size_t *digLen);
typedef int (*ct_prague_fn)(const uint8_t *cms, size_t cmsLen, const uint8_t *det, size_t detLen,
                            bool allowTest, const uint8_t **leaf, size_t *leafLen);

static void probeCoreTrust(void) {
    void *h = dlopen("/usr/lib/libmis.dylib", RTLD_NOW);
    ct_amfi_fn amfi = (ct_amfi_fn)dlsym(h, "CTEvaluateAMFICodeSignatureCMS");
    ct_prague_fn prague = (ct_prague_fn)dlsym(h, "CTEvaluatePragueSignatureCMS");
    L(@"libmis=%p amfi=%p prague=%p", h, amfi, prague);
    struct { const char *name; const char *det; } tests[] = {
        {"test_template", "template"},
        {"test_dist_appstorefirst", "fake"},
        {"test_ca_appstorefirst", "fake"},
        {"test_multisigner", "multi"},
        {"test_multisigner_time", "multi_time"},
        {"test_template_unsigned", "template"},
        {"test_dupattrs", "template"},
        {"test_siddup_real_first", "template"},
        {"test_siddup_fake_first", "template"},
        {NULL, NULL}
    };
    for (int i = 0; tests[i].name; i++) {
        NSString *p = [[NSBundle mainBundle] pathForResource:[NSString stringWithUTF8String:tests[i].name] ofType:@"cms"];
        NSData *d = p ? [NSData dataWithContentsOfFile:p] : nil;
        NSString *dp = [[NSBundle mainBundle] pathForResource:[NSString stringWithUTF8String:tests[i].det] ofType:@"cd"];
        NSData *dd = dp ? [NSData dataWithContentsOfFile:dp] : nil;
        if (!d) { L(@"oracle %s: no resource", tests[i].name); continue; }
        const uint8_t *leaf = NULL; size_t leafLen = 0; uint64_t policy = 0;
        uint32_t cd = 0, ag = 0; const uint8_t *dig = NULL; size_t digLen = 0;
        int r = amfi ? amfi(d.bytes, d.length, dd.bytes, dd.length, false, &leaf, &leafLen, &policy, &cd, &ag, &dig, &digLen) : -1;
        NSMutableString *hs = [NSMutableString string];
        for (size_t k = 0; dig && k < digLen && k < 8; k++) [hs appendFormat:@"%02x", dig[k]];
        L(@"AMFI %s r=0x%x policy=0x%llx cmsDig=%u agil=%u leaf=%zu dig=%zu dig0=%@ det=%zu",
          tests[i].name, r, (unsigned long long)policy, cd, ag, leafLen, digLen, hs, dd.length);
        leaf = NULL; leafLen = 0;
        int r2 = prague ? prague(d.bytes, d.length, dd.bytes, dd.length, false, &leaf, &leafLen) : -1;
        L(@"Prague %s r=0x%x leaf=%zu", tests[i].name, r2, leafLen);
    }
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
        probeSymbols();
        probeCoreTrust();
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
