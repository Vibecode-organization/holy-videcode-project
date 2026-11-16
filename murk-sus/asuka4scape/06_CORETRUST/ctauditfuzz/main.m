// ctoracle — on-device CoreTrust oracle.
// Calls the userspace CoreTrust implementation (libmis / MobileInBoxUpdate)
// with arbitrary CMS + CodeDirectory pairs and logs the verdict + policy flags.
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#include <dlfcn.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
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
        @autoreleasepool {
            memcpy(buf, seed, n);
            int flips = 1 + rand() % 12;
            for (int k = 0; k < flips; k++) {
                size_t off = 1 + (rand() % (n - 1));
                buf[off] = (uint8_t)rand();
            }
            [[NSData dataWithBytes:buf length:n] writeToFile:[docs stringByAppendingPathComponent:@"last.cms"] atomically:YES];
            const uint8_t *leaf = NULL; CT_size_t ll = 0; CoreTrustPolicyFlags pol = 0;
            uint32_t cdg = 0, ag = 0; const uint8_t *dig = NULL; CT_size_t dl = 0;
            fn(buf, n, cdData.bytes, cdData.length, false, &leaf, &ll, &pol, &cdg, &ag, &dig, &dl);
            if ((i % 5000) == 0) flog([NSString stringWithFormat:@"fuzz %lu ok", i]);
        }
    }
    flog(@"fuzz done");
}

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (nonatomic, strong) UIWindow *window;
@end

@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)opts {
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    UIViewController *vc = [UIViewController new];
    self.window.rootViewController = vc;
    [self.window makeKeyAndVisible];

    flog(@"start");
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
    NSString *fz = [[NSHomeDirectory() stringByAppendingPathComponent:@"Documents"] stringByAppendingPathComponent:@"fuzz.on"];
    if ([[NSFileManager defaultManager] fileExistsAtPath:fz]) {
        [UIApplication sharedApplication].idleTimerDisabled = YES;
        flog(@"fuzz launch");
        dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{
            fuzz_loop(fn);
        });
        return YES;
    }

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
