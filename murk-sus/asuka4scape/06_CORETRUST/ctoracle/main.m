#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <Security/Security.h>
#import <dlfcn.h>
#import <mach-o/loader.h>
#import <mach-o/fat.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

typedef int (*CTEvaluatePragueFn)(const uint8_t *cmsData, size_t cmsLen,
                                  const uint8_t *detached, size_t detachedLen,
                                  int allowTestHierarchy,
                                  const uint8_t **leafCert, size_t *leafCertLen,
                                  uint64_t *policyFlags,
                                  uint32_t *cmsDigestType,
                                  uint32_t *hashAgilityDigestType,
                                  const uint8_t **digestData, size_t *digestLen);

typedef int (*CTEvaluateAMFIFn)(const uint8_t *cmsData, size_t cmsLen,
                                const uint8_t *detached, size_t detachedLen,
                                int allowTestHierarchy,
                                const uint8_t **leafCert, size_t *leafCertLen,
                                uint64_t *policyFlags,
                                uint32_t *cmsDigestType,
                                uint32_t *hashAgilityDigestType,
                                const uint8_t **digestData, size_t *digestLen);

typedef int (*CTEvaluateSavageFn)(uint64_t policy,
                                  const uint8_t **certs, const size_t *certLens, size_t certCount,
                                  const uint8_t **root, size_t *rootLen,
                                  uint64_t *outPolicy);

static NSMutableString *gLog;
static NSString *gPath;
static UITextView *gTV;

static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    [gLog appendString:s]; [gLog appendString:@"\n"];
    [gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
    dispatch_async(dispatch_get_main_queue(), ^{ if (gTV) gTV.text = gLog; });
}

static NSData *read_file(NSString *p) { return [NSData dataWithContentsOfFile:p]; }

static uint32_t be32(const uint8_t *p) { return (p[0]<<24)|(p[1]<<16)|(p[2]<<8)|p[3]; }

static void dump_blobs(NSData *sig, const char *tag) {
    const uint8_t *s = sig.bytes; size_t n = sig.length;
    if (n < 12) { L(@"[%s] sig too small %zu", tag, n); return; }
    uint32_t magic = be32(s), len = be32(s+4), cnt = be32(s+8);
    L(@"[%s] superblob magic=%08x len=%u count=%u size=%zu", tag, magic, len, cnt, n);
    if (magic != 0xfade0cc0) return;
    for (uint32_t i = 0; i < cnt && 12 + (i+1)*8 <= n; i++) {
        uint32_t type = be32(s + 12 + i*8);
        uint32_t off = be32(s + 16 + i*8);
        if (off + 8 > n) continue;
        uint32_t blen = be32(s + off + 4);
        L(@"[%s] blob[%u] type=%08x off=%u len=%u", tag, i, type, off, blen);
    }
}

static const uint8_t *find_blob(NSData *sig, uint32_t want, size_t *outLen) {
    const uint8_t *s = sig.bytes; size_t n = sig.length;
    if (n < 12 || be32(s) != 0xfade0cc0) return NULL;
    uint32_t cnt = be32(s+8);
    for (uint32_t i = 0; i < cnt && 12 + (i+1)*8 <= n; i++) {
        uint32_t type = be32(s + 12 + i*8);
        uint32_t off = be32(s + 16 + i*8);
        if (type != want || off + 8 > n) continue;
        uint32_t blen = be32(s + off + 4);
        if (off + blen > n) continue;
        *outLen = blen;
        return s + off;
    }
    return NULL;
}

static NSData *signature_blob_for_path(NSString *path) {
    NSString *exe = path;
    NSData *d = read_file(exe);
    if (!d) { L(@"cannot read exe %@", exe); return nil; }
    const uint8_t *b = d.bytes; size_t n = d.length;
    if (n < 32 || *(const uint32_t *)b != MH_MAGIC_64) { L(@"not thin arm64 macho"); return nil; }
    const struct mach_header_64 *mh = (const struct mach_header_64 *)b;
    const uint8_t *p = b + sizeof(*mh);
    for (uint32_t i = 0; i < mh->ncmds; i++) {
        const struct load_command *lc = (const struct load_command *)p;
        if (lc->cmd == LC_CODE_SIGNATURE) {
            const struct linkedit_data_command *ld = (const struct linkedit_data_command *)lc;
            if ((uint64_t)ld->dataoff + ld->datasize > n) { L(@"sig out of file"); return nil; }
            L(@"LC_CODE_SIGNATURE off=%u size=%u", ld->dataoff, ld->datasize);
            return [d subdataWithRange:NSMakeRange(ld->dataoff, ld->datasize)];
        }
        p += lc->cmdsize;
    }
    L(@"no LC_CODE_SIGNATURE");
    return nil;
}

static void test_prague(NSData *sig, uint32_t cdType, const char *tag) {
    size_t cmsLen = 0, cdLen = 0;
    const uint8_t *cms = find_blob(sig, 0x10000, &cmsLen);
    const uint8_t *cd = find_blob(sig, cdType, &cdLen);
    if (!cms) { L(@"[%s] no CMS", tag); return; }
    if (!cd) { L(@"[%s] no CD type %08x", tag, cdType); return; }
    if (cmsLen < 8) { L(@"[%s] cms short", tag); return; }
    const uint8_t *cmsData = cms + 8; size_t cmsDataLen = cmsLen - 8;
    L(@"[%s] cmsData=%zu cd=%zu", tag, cmsDataLen, cdLen);

    void *h = dlopen("/System/Library/PrivateFrameworks/MobileInBoxUpdate.framework/MobileInBoxUpdate", RTLD_NOW);
    if (!h) { L(@"[%s] dlopen failed: %s", tag, dlerror()); return; }
    CTEvaluatePragueFn fn = (CTEvaluatePragueFn)dlsym(h, "CTEvaluatePragueSignatureCMS");
    L(@"[%s] fn=%p", tag, fn);
    if (!fn) return;
    const uint8_t *leaf = NULL; size_t leafLen = 0;
    uint64_t policy = 0; uint32_t cmsDig = 0, agil = 0;
    const uint8_t *dig = NULL; size_t digLen = 0;
    int r = fn(cmsData, cmsDataLen, cd, cdLen, 0, &leaf, &leafLen, &policy, &cmsDig, &agil, &dig, &digLen);
    L(@"[%s] prague -> 0x%x policy=0x%llx cmsDig=%u agil=%u leaf=%zu dig=%zu",
      tag, r, (unsigned long long)policy, cmsDig, agil, leafLen, digLen);
    if (dig && digLen) {
        NSMutableString *hs = [NSMutableString string];
        for (size_t i = 0; i < digLen && i < 64; i++) [hs appendFormat:@"%02x", dig[i]];
        L(@"[%s] digest=%s", tag, hs);
    }
    if (leaf && leafLen) {
        NSData *lc = [NSData dataWithBytes:leaf length:leafLen];
        NSString *lp = [[gPath stringByDeletingLastPathComponent] stringByAppendingPathComponent:[NSString stringWithFormat:@"leaf-%s.der", tag]];
        [lc writeToFile:lp atomically:YES];
    }
}

static void test_libmis(NSData *cmsData, NSData *cdData, const char *tag) {
    void *h = dlopen("/usr/lib/libmis.dylib", RTLD_NOW);
    if (!h) { L(@"[amfi] %s dlopen failed: %s", tag, dlerror()); return; }
    CTEvaluateAMFIFn fn = (CTEvaluateAMFIFn)dlsym(h, "CTEvaluateAMFICodeSignatureCMS");
    if (!fn) { L(@"[amfi] %s no symbol", tag); return; }
    const uint8_t *leaf = NULL; size_t leafLen = 0;
    uint64_t policy = 0; uint32_t cmsDig = 0, agil = 0;
    const uint8_t *dig = NULL; size_t digLen = 0;
    int r = fn(cmsData.bytes, cmsData.length, cdData.bytes, cdData.length, 0,
               &leaf, &leafLen, &policy, &cmsDig, &agil, &dig, &digLen);
    L(@"[amfi] %s r=0x%x policy=0x%llx cmsDig=%u agil=%u leaf=%zu dig=%zu cd=%zu",
      tag, r, (unsigned long long)policy, cmsDig, agil, leafLen, digLen, cdData.length);
    if (dig && digLen) {
        NSMutableString *hs = [NSMutableString string];
        for (size_t i = 0; i < digLen && i < 64; i++) [hs appendFormat:@"%02x", dig[i]];
        L(@"[amfi] %s digest=%s", tag, hs);
    }
}

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (nonatomic, strong) UIWindow *window;
@end

@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)opts {
    gLog = [NSMutableString new];
    NSString *docs = [NSHomeDirectory() stringByAppendingPathComponent:@"Documents"];
    gPath = [docs stringByAppendingPathComponent:@"ctoracle.log"];
    [gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];

    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    UIViewController *vc = [UIViewController new];
    gTV = [[UITextView alloc] initWithFrame:vc.view.bounds];
    gTV.editable = NO; gTV.font = [UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];
    [vc.view addSubview:gTV];
    self.window.rootViewController = vc;
    [self.window makeKeyAndVisible];

    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{
            @autoreleasepool {
                L(@"=== ctoracle start %@ ===", [[UIDevice currentDevice] systemVersion]);
                NSData *sig = signature_blob_for_path([[NSBundle mainBundle] executablePath]);
                if (sig) {
                    dump_blobs(sig, "self");
                    test_prague(sig, 0, "sha1cd");
                    test_prague(sig, 0x1000, "sha256cd");

                    NSString *docs = [NSHomeDirectory() stringByAppendingPathComponent:@"Documents"];
                    NSArray *files = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:docs error:nil];
                    for (NSString *fn in files) {
                        if ([fn hasSuffix:@".cms"]) {
                            NSString *base = [fn stringByDeletingPathExtension];
                            NSString *cdp = [docs stringByAppendingPathComponent:[base stringByAppendingPathExtension:@"cd"]];
                            NSData *cms = read_file([docs stringByAppendingPathComponent:fn]);
                            NSData *cd = read_file(cdp);
                            if (cms && cd) test_libmis(cms, cd, fn.UTF8String);
                            else L(@"[amfi] %@ missing cms/cd", fn);
                            continue;
                        }
                        if (![fn hasSuffix:@".dylib"] && ![fn hasSuffix:@".bin"] && ![fn hasSuffix:@".case"]) continue;
                        NSString *fp = [docs stringByAppendingPathComponent:fn];
                        NSDictionary *attrs = [[NSFileManager defaultManager] attributesOfItemAtPath:fp error:nil];
                        if (attrs.fileSize > 4*1024*1024) continue;
                        L(@"--- case %@ ---", fn);
                        NSData *cs = signature_blob_for_path(fp);
                        if (!cs) { L(@"[case] no signature"); continue; }
                        dump_blobs(cs, fn.UTF8String);
                        test_prague(cs, 0, [fn UTF8String]);
                        test_prague(cs, 0x1000, [fn UTF8String]);
                        dlerror();
                        void *dh = dlopen(fp.fileSystemRepresentation, RTLD_NOW | RTLD_LOCAL);
                        const char *de = dlerror();
                        L(@"[dlopen] %@ -> %p err=%s", fn, dh, de ? de : "none");
                        if (dh) dlclose(dh);
                    }

                    NSString *fw = [[[NSBundle mainBundle] bundlePath] stringByAppendingPathComponent:@"Frameworks"];
                    NSArray *fwFiles = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:fw error:nil];
                    for (NSString *fn in fwFiles) {
                        if (![fn hasSuffix:@".dylib"]) continue;
                        NSString *fp = [fw stringByAppendingPathComponent:fn];
                        L(@"--- bundle case %@ ---", fn);
                        NSData *cs = signature_blob_for_path(fp);
                        if (!cs) { L(@"[bundle case] no signature"); continue; }
                        dump_blobs(cs, fn.UTF8String);
                        test_prague(cs, 0, [fn UTF8String]);
                        test_prague(cs, 0x1000, [fn UTF8String]);
                        dlerror();
                        void *dh = dlopen(fp.fileSystemRepresentation, RTLD_NOW | RTLD_LOCAL);
                        const char *de = dlerror();
                        L(@"[bundle dlopen] %@ -> %p err=%s", fn, dh, de ? de : "none");
                        if (dh) dlclose(dh);
                    }
                }
                L(@"=== ctoracle done ===");
            }
        });
    });
    return YES;
}
@end

int main(int argc, char **argv) { @autoreleasepool { return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class])); } }
