// ctaudit — CoreTrust oracle, separate bundle id, production + test hierarchy.
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
    bool allow_test_hierarchy,
    const uint8_t **leafCert, CT_size_t *leafCertLen,
    CoreTrustPolicyFlags *policyFlags,
    uint32_t *cmsDigestType, uint32_t *hashAgilityDigestType,
    const uint8_t **digestData, CT_size_t *digestLen);

static void flog(NSString *s) {
    NSString *p = [NSHomeDirectory() stringByAppendingPathComponent:@"Documents/ctaudit.log"];
    NSFileHandle *fh = [NSFileHandle fileHandleForWritingAtPath:p];
    if (!fh) {
        [[NSFileManager defaultManager] createFileAtPath:p contents:nil attributes:nil];
        fh = [NSFileHandle fileHandleForWritingAtPath:p];
    }
    [fh seekToEndOfFile];
    [fh writeData:[[s stringByAppendingString:@"\n"] dataUsingEncoding:NSUTF8StringEncoding]];
    [fh closeFile];
}

static void run_one(NSString *tag, NSData *cms, NSData *cd,
                    CTEvaluateAMFICodeSignatureCMS_t fn, bool testHierarchy) {
    const uint8_t *leaf = NULL; CT_size_t leafLen = 0;
    CoreTrustPolicyFlags pol = 0;
    uint32_t cmsDig = 0, agilDig = 0;
    const uint8_t *dig = NULL; CT_size_t digLen = 0;
    CT_int r = fn((const uint8_t *)cms.bytes, cms.length,
                  (const uint8_t *)cd.bytes, cd.length,
                  testHierarchy, &leaf, &leafLen, &pol, &cmsDig, &agilDig, &dig, &digLen);
    flog([NSString stringWithFormat:@"%@ [%@]: ret=0x%x leaf=%llu cmsDig=%u agility=%u digLen=%llu policy=0x%llx",
          tag, testHierarchy ? @"test" : @"prod", (unsigned)r,
          (unsigned long long)leafLen, cmsDig, agilDig,
          (unsigned long long)digLen, (unsigned long long)pol]);
    if (dig && digLen) {
        NSMutableString *h = [NSMutableString string];
        for (CT_size_t i = 0; i < digLen && i < 32; i++) [h appendFormat:@"%02x", dig[i]];
        flog([NSString stringWithFormat:@"  digest=%@", h]);
    }
}

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (nonatomic, strong) UIWindow *window;
@end

@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)opts {
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    UIViewController *vc = [UIViewController new];
    vc.view.backgroundColor = UIColor.blackColor;
    UITextView *tv = [[UITextView alloc] initWithFrame:vc.view.bounds];
    tv.backgroundColor = UIColor.blackColor;
    tv.textColor = UIColor.greenColor;
    tv.font = [UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];
    tv.editable = NO;
    [vc.view addSubview:tv];
    self.window.rootViewController = vc;
    [self.window makeKeyAndVisible];

    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0), ^{
        flog(@"=== ctaudit start ===");
        void *h = dlopen("/usr/lib/libmis.dylib", RTLD_NOW | RTLD_LOCAL);
        CTEvaluateAMFICodeSignatureCMS_t fn = NULL;
        if (h) {
            void *sym = dlsym(h, "CTEvaluateAMFICodeSignatureCMS");
            if (!sym) sym = dlsym(h, "_CTEvaluateAMFICodeSignatureCMS");
            if (sym) fn = (CTEvaluateAMFICodeSignatureCMS_t)sym;
        }
        flog([NSString stringWithFormat:@"libmis=%p fn=%p", h, fn]);
        if (!fn) return;

        NSString *docs = [NSHomeDirectory() stringByAppendingPathComponent:@"Documents"];
        NSArray *files = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:docs error:nil];
        for (NSString *f in [files sortedArrayUsingSelector:@selector(compare:)]) {
            if (![f hasSuffix:@".cms"]) continue;
            NSString *base = [f stringByDeletingPathExtension];
            NSString *cdp = [docs stringByAppendingPathComponent:[base stringByAppendingString:@".cd"]];
            NSData *cms = [NSData dataWithContentsOfFile:[docs stringByAppendingPathComponent:f]];
            NSData *cd = [NSData dataWithContentsOfFile:cdp];
            if (!cms || !cd) { flog([NSString stringWithFormat:@"%@: missing cms/cd", base]); continue; }
            run_one(base, cms, cd, fn, false);
            run_one(base, cms, cd, fn, true);
        }
        flog(@"=== ctaudit done ===");
    });
    return YES;
}
@end

int main(int argc, char **argv) {
    @autoreleasepool { return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class])); }
}
