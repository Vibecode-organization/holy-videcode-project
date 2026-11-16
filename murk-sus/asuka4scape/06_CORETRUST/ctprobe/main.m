// ctprobe — CoreTrust / AMFI payload probe.
// Writes every line to Documents/ctprobe.log with fsync so a crash cannot lose it.
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <Security/Security.h>

// Security SPI declarations (not in the public iOS SDK headers).
typedef struct CF_BRIDGED_TYPE(id) __SecCode const *SecStaticCodeRef;
typedef struct CF_BRIDGED_TYPE(id) __SecRequirement const *SecRequirementRef;
typedef CF_OPTIONS(uint32_t, SecCSFlags) { kSecCSDefaultFlags = 0, kSecCSSigningInformation = 1 << 1 };
OSStatus SecCodeCopySigningInformation(SecStaticCodeRef code, SecCSFlags flags, CFDictionaryRef * __nonnull CF_RETURNS_RETAINED information);
CFDataRef SecCertificateCopyData(SecCertificateRef certificate);
extern const CFStringRef kSecCodeInfoCertificates;
OSStatus SecStaticCodeCreateWithPathAndAttributes(CFURLRef path, SecCSFlags flags, CFDictionaryRef attributes, SecStaticCodeRef * __nonnull CF_RETURNS_RETAINED staticCode);
OSStatus SecStaticCodeCheckValidity(SecStaticCodeRef staticCode, SecCSFlags flags, SecRequirementRef requirement);
CFStringRef SecCopyErrorMessageString(OSStatus status, void *reserved);
#include <dlfcn.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/sysctl.h>
#include <arpa/inet.h>
#include <errno.h>
#include <CommonCrypto/CommonDigest.h>

extern int csops(pid_t pid, unsigned int ops, void *useraddr, size_t usersize);
#define CS_OPS_ENTITLEMENTS_BLOB 7

static UITextView *gTV;
static NSMutableString *gLog;
static NSString *gDocs;
static NSString *gLogPath;
static NSString *gStagePath;
static NSString *gDonePath;
static BOOL gRunning = NO;
static NSString *gSkipStage = nil;

static NSString *sysctl_str(const char *name) {
    size_t sz = 0;
    if (sysctlbyname(name, NULL, &sz, NULL, 0) != 0 || sz == 0 || sz > 8192) return @"?";
    char *buf = calloc(1, sz + 1);
    if (!buf) return @"?";
    if (sysctlbyname(name, buf, &sz, NULL, 0) != 0) { free(buf); return @"?"; }
    NSString *s = [NSString stringWithUTF8String:buf] ?: @"?";
    free(buf);
    return s;
}

static void fsync_path(NSString *path) {
    int fd = open(path.fileSystemRepresentation, O_RDONLY);
    if (fd >= 0) { fsync(fd); close(fd); }
}

static void write_log(void) {
    NSData *d = [gLog dataUsingEncoding:NSUTF8StringEncoding];
    [d writeToFile:gLogPath options:NSDataWritingAtomic error:nil];
    fsync_path(gLogPath);
}

static void log_line(NSString *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    time_t now = time(NULL);
    struct tm tmv;
    localtime_r(&now, &tmv);
    char ts[32];
    strftime(ts, sizeof(ts), "%H:%M:%S", &tmv);
    [gLog appendFormat:@"%s %@\n", ts, s];
    write_log();
    dispatch_async(dispatch_get_main_queue(), ^{
        if (gTV) {
            gTV.text = gLog;
            [gTV scrollRangeToVisible:NSMakeRange(gLog.length, 0)];
        }
    });
}

static void write_stage(NSString *stage) {
    [stage writeToFile:gStagePath atomically:YES encoding:NSUTF8StringEncoding error:nil];
    [@"0" writeToFile:gDonePath atomically:YES encoding:NSUTF8StringEncoding error:nil];
    fsync_path(gStagePath);
    fsync_path(gDonePath);
}

static void mark_done(void) {
    [@"1" writeToFile:gDonePath atomically:YES encoding:NSUTF8StringEncoding error:nil];
    fsync_path(gDonePath);
}

static void check_static_code(NSString *path) {
    CFURLRef url = (__bridge CFURLRef)[NSURL fileURLWithPath:path];
    SecStaticCodeRef code = NULL;
    OSStatus st = SecStaticCodeCreateWithPathAndAttributes(url, kSecCSDefaultFlags, NULL, &code);
    log_line(@"SecStaticCodeCreateWithPath(%@) -> %d", path.lastPathComponent, (int)st);
    if (st == errSecSuccess && code) {
        st = SecStaticCodeCheckValidity(code, kSecCSDefaultFlags, NULL);
        log_line(@"SecStaticCodeCheckValidity(%@) -> %d", path.lastPathComponent, (int)st);
        CFStringRef msg = SecCopyErrorMessageString(st, NULL);
        if (msg) {
            log_line(@"  %@", (__bridge NSString *)msg);
            CFRelease(msg);
        }
        CFRelease(code);
    }
}

static void copy_profile_and_certs(void) {
    NSFileManager *fm = [NSFileManager defaultManager];
    NSString *prof = [[NSBundle mainBundle] pathForResource:@"embedded" ofType:@"mobileprovision"];
    if (prof) {
        NSData *d = [NSData dataWithContentsOfFile:prof];
        [d writeToFile:[gDocs stringByAppendingPathComponent:@"embedded.mobileprovision"] atomically:YES];
        log_line(@"profile copied: %lu bytes", (unsigned long)d.length);
    } else {
        log_line(@"no embedded.mobileprovision in bundle");
    }
    NSString *cr = [[[NSBundle mainBundle] bundlePath] stringByAppendingPathComponent:@"_CodeSignature/CodeResources"];
    if ([fm fileExistsAtPath:cr]) {
        NSData *d = [NSData dataWithContentsOfFile:cr];
        [d writeToFile:[gDocs stringByAppendingPathComponent:@"CodeResources"] atomically:YES];
        log_line(@"CodeResources copied: %lu bytes", (unsigned long)d.length);
    }
    CFURLRef url = (__bridge CFURLRef)[NSURL fileURLWithPath:[[NSBundle mainBundle] bundlePath]];
    SecStaticCodeRef code = NULL;
    OSStatus st = SecStaticCodeCreateWithPathAndAttributes(url, kSecCSDefaultFlags, NULL, &code);
    if (st == errSecSuccess && code) {
        CFDictionaryRef info = NULL;
        st = SecCodeCopySigningInformation(code, kSecCSSigningInformation, &info);
        if (st == errSecSuccess && info) {
            CFArrayRef certs = CFDictionaryGetValue(info, CFSTR("certificates"));
            if (certs) {
                CFIndex n = CFArrayGetCount(certs);
                log_line(@"own signing certs: %ld", (long)n);
                for (CFIndex i = 0; i < n; i++) {
                    SecCertificateRef c = (SecCertificateRef)CFArrayGetValueAtIndex(certs, i);
                    CFDataRef der = SecCertificateCopyData(c);
                    NSString *name = [NSString stringWithFormat:@"cert%ld.der", (long)i];
                    [(__bridge NSData *)der writeToFile:[gDocs stringByAppendingPathComponent:name] atomically:YES];
                    CFRelease(der);
                }
            }
            CFRelease(info);
        }
        CFRelease(code);
    }
}

static void copy_own_bundle(void) {
    NSFileManager *fm = [NSFileManager defaultManager];
    NSString *own = [gDocs stringByAppendingPathComponent:@"own"];
    [fm createDirectoryAtPath:own withIntermediateDirectories:YES attributes:nil error:nil];
    NSString *bp = [[NSBundle mainBundle] bundlePath];
    NSString *exe = [[NSBundle mainBundle] executablePath];
    if (exe) [fm copyItemAtPath:exe toPath:[own stringByAppendingPathComponent:exe.lastPathComponent] error:nil];
    for (NSString *rel in @[@"Info.plist", @"_CodeSignature/CodeResources", @"embedded.mobileprovision"]) {
        NSString *src = [bp stringByAppendingPathComponent:rel];
        if ([fm fileExistsAtPath:src]) {
            NSString *dst = [own stringByAppendingPathComponent:[rel lastPathComponent]];
            [fm copyItemAtPath:src toPath:dst error:nil];
        }
    }
    for (NSString *n in [fm contentsOfDirectoryAtPath:bp error:nil]) {
        if ([n hasSuffix:@".b64"]) {
            [fm copyItemAtPath:[bp stringByAppendingPathComponent:n] toPath:[own stringByAppendingPathComponent:n] error:nil];
        }
    }
    log_line(@"own bundle copied to %@", own);
}

static void log_self_entitlements(void) {
    unsigned char buf[16384];
    memset(buf, 0, sizeof(buf));
    int r = csops(getpid(), CS_OPS_ENTITLEMENTS_BLOB, buf, sizeof(buf));
    log_line(@"csops(ents) -> %d errno=%d", r, errno);
    if (r != 0) return;
    uint32_t magic = ntohl(*(uint32_t *)buf);
    uint32_t len = ntohl(*(uint32_t *)(buf + 4));
    log_line(@"ents magic=0x%08x len=%u", magic, len);
    if (len > sizeof(buf) - 8) len = sizeof(buf) - 8;
    NSString *xml = [[NSString alloc] initWithBytes:buf + 8 length:len encoding:NSUTF8StringEncoding];
    if (xml) log_line(@"ents xml:\n%@", xml);
    else log_line(@"ents: non-UTF8 blob");
}

static void log_readme(void) {
    NSString *readme =
        @"CTProbe — CoreTrust / AMFI payload probe\n"
        @"\n"
        @"Files in this Documents folder:\n"
        @"  ctprobe.log          full run log, flushed and fsynced after every line\n"
        @"  last_stage.txt       payload that was running when the app last stopped\n"
        @"  last_stage_done.txt  1 = that payload finished, 0 = app died during it\n"
        @"  payloads/*.dylib     decoded test payloads\n"
        @"  payloads/*.marker    written by a payload constructor only if AMFI accepted it\n"
        @"\n"
        @"If the app crashed, open Settings > Privacy & Security > Analytics & Improvements\n"
        @"> Analytics Data and search for 'ctprobe' (newest .ips file).\n"
        @"The log is already on disk before each dlopen, so the crashing payload is named\n"
        @"in last_stage.txt even if the process was killed by AMFI/dyld.\n";
    [readme writeToFile:[gDocs stringByAppendingPathComponent:@"README.txt"] atomically:YES encoding:NSUTF8StringEncoding error:nil];
}

static NSArray *payloads(void) {
    return @[
        @{@"name": @"system", @"desc": @"Apple-signed system dylib (dlopen control)"},
        @{@"name": @"adhoc", @"desc": @"ad-hoc signed dylib (expected reject)"},
        @{@"name": @"adhoc_ent", @"desc": @"ad-hoc + entitlements (expected reject)"},
        @{@"name": @"control", @"desc": @"valid CMS, self-signed Test Root (unpinned root)"},
        @{@"name": @"apple_iphone", @"desc": @"self-signed Apple iPhone CA + Apple extension OID"},
        @{@"name": @"apple_iphone_noext", @"desc": @"self-signed Apple iPhone CA, no extension"},
        @{@"name": @"apple_cs", @"desc": @"self-signed Apple Code Signing CA"},
        @{@"name": @"apple_dev", @"desc": @"self-signed Apple WWDR CA"},
        @{@"name": @"trollstore", @"desc": @"CVE-2023-41991 style: App Store signer + TrollStore signer (Apple first)"},
        @{@"name": @"trollstore_rev", @"desc": @"same CMS with TrollStore signer first (order diagnostic)"},
        @{@"name": @"modcd_reuse", @"desc": @"modified App Store CD (SHA1 code slots) + real CD; CMS Apple first, md=template"},
        @{@"name": @"modcd_app", @"desc": @"same, our signer md=sha256(modified App Store CD)"},
        @{@"name": @"modcd_real", @"desc": @"same, our signer md=sha256(real CD)"},
        @{@"name": @"modcd_ours", @"desc": @"same, our signer first"},
        @{@"name": @"swap_reuse", @"desc": @"real CD main, App Store CD alternate; md=template"},
        @{@"name": @"swap_app", @"desc": @"real CD main, App Store CD alternate; md=sha256(App Store CD)"},
        @{@"name": @"swap_real", @"desc": @"real CD main, App Store CD alternate; md=sha256(real CD)"},
        @{@"name": @"modcd_ours_app", @"desc": @"modified App Store CD; our signer first, md=sha256(modified App Store CD)"},
        @{@"name": @"modcd_ours_real", @"desc": @"modified App Store CD; our signer first, md=sha256(real CD)"},
        @{@"name": @"swap_ours_app", @"desc": @"real CD main, App Store CD alternate; our signer first, md=sha256(App Store CD)"},
    ];
}

static void run_payload(NSDictionary *p) {
    NSString *name = p[@"name"];
    NSString *desc = p[@"desc"];
    write_stage(name);
    log_line(@"=== BEGIN %@ — %@ ===", name, desc);

    if ([name isEqualToString:@"system"]) {
        dlerror();
        void *h = dlopen("/usr/lib/libsqlite3.dylib", RTLD_NOW | RTLD_LOCAL);
        const char *err = dlerror();
        log_line(@"system dlopen -> %p %s", h, h ? "OK" : (err ? err : "(null)"));
        log_line(@"=== END %@ ===", name);
        mark_done();
        return;
    }

    NSString *resName = [@"p_" stringByAppendingString:name];
    NSString *resPath = [[NSBundle mainBundle] pathForResource:resName ofType:@"b64"];
    if (!resPath) {
        log_line(@"MISSING resource %@.b64", resName);
        log_line(@"=== END %@ ===", name);
        mark_done();
        return;
    }
    NSString *b64 = [NSString stringWithContentsOfFile:resPath encoding:NSUTF8StringEncoding error:nil];
    NSData *bin = b64 ? [[NSData alloc] initWithBase64EncodedString:b64 options:NSDataBase64DecodingIgnoreUnknownCharacters] : nil;
    if (!bin.length) {
        log_line(@"base64 decode failed for %@", resName);
        log_line(@"=== END %@ ===", name);
        mark_done();
        return;
    }

    NSString *dir = [gDocs stringByAppendingPathComponent:@"payloads"];
    [[NSFileManager defaultManager] createDirectoryAtPath:dir withIntermediateDirectories:YES attributes:nil error:nil];
    NSString *path = [dir stringByAppendingPathComponent:[name stringByAppendingString:@".dylib"]];
    [bin writeToFile:path atomically:YES];
    chmod(path.fileSystemRepresentation, 0755);

    unsigned char md[CC_SHA256_DIGEST_LENGTH];
    CC_SHA256(bin.bytes, (CC_LONG)bin.length, md);
    NSMutableString *hex = [NSMutableString string];
    for (int i = 0; i < CC_SHA256_DIGEST_LENGTH; i++) [hex appendFormat:@"%02x", md[i]];
    log_line(@"payload %@ size=%lu sha256=%@", path, (unsigned long)bin.length, hex);

    NSString *marker = [dir stringByAppendingPathComponent:[name stringByAppendingString:@".marker"]];
    [[NSFileManager defaultManager] removeItemAtPath:marker error:nil];
    setenv("CT_MARKER", marker.fileSystemRepresentation, 1);

    check_static_code(path);
    dlerror();
    log_line(@"dlopen(%@) ...", path);
    void *h = dlopen(path.fileSystemRepresentation, RTLD_NOW | RTLD_LOCAL);
    const char *err = dlerror();
    if (h) log_line(@"dlopen OK handle=%p", h);
    else log_line(@"dlopen FAIL: %s", err ? err : "(null)");

    NSString *m = [NSString stringWithContentsOfFile:marker encoding:NSUTF8StringEncoding error:nil];
    if (m.length) {
        log_line(@"marker: %@", [m stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]]);
    } else {
        log_line(@"marker: (none)");
    }
    log_line(@"=== END %@ ===", name);
    mark_done();
}

static void run_all(BOOL reset_guard) {
    if (gRunning) return;
    if (reset_guard) gSkipStage = nil;
    gRunning = YES;
    dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{
        log_line(@"RUN ALL start (guard=%@)", gSkipStage ?: @"none");
        BOOL skipped = NO;
        for (NSDictionary *p in payloads()) {
            @autoreleasepool {
                if (!skipped && gSkipStage && [p[@"name"] isEqualToString:gSkipStage]) {
                    log_line(@"CRASH GUARD: skipping %@ (previous run died here)", p[@"name"]);
                    skipped = YES;
                    continue;
                }
                run_payload(p);
            }
        }
        log_line(@"RUN ALL done");
        gRunning = NO;
    });
}

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (nonatomic, strong) UIWindow *window;
@property (nonatomic, strong) UITextView *tv;
@end

@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)opts {
    gDocs = [NSHomeDirectory() stringByAppendingPathComponent:@"Documents"];
    [[NSFileManager defaultManager] createDirectoryAtPath:gDocs withIntermediateDirectories:YES attributes:nil error:nil];
    gLogPath = [gDocs stringByAppendingPathComponent:@"ctprobe.log"];
    gStagePath = [gDocs stringByAppendingPathComponent:@"last_stage.txt"];
    gDonePath = [gDocs stringByAppendingPathComponent:@"last_stage_done.txt"];

    NSString *old = [NSString stringWithContentsOfFile:gLogPath encoding:NSUTF8StringEncoding error:nil];
    gLog = [NSMutableString string];
    if (old.length) [gLog appendString:@"\n\n===== NEW RUN =====\n"];
    else [gLog appendString:@"===== CTProbe =====\n"];

    log_line(@"kern.osversion=%@", sysctl_str("kern.osversion"));
    log_line(@"kern.version=%@", sysctl_str("kern.version"));
    log_line(@"hw.model=%@", sysctl_str("hw.model"));
    log_line(@"bundle=%@", [[NSBundle mainBundle] bundlePath]);
    log_line(@"home=%@", NSHomeDirectory());
    log_line(@"log=%@", gLogPath);
    log_self_entitlements();
    log_readme();
    copy_profile_and_certs();
    copy_own_bundle();

    NSString *prevStage = [NSString stringWithContentsOfFile:gStagePath encoding:NSUTF8StringEncoding error:nil];
    NSString *prevDone = [NSString stringWithContentsOfFile:gDonePath encoding:NSUTF8StringEncoding error:nil];
    prevStage = [prevStage stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
    prevDone = [prevDone stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
    if (prevStage.length && ![prevDone isEqualToString:@"1"]) {
        gSkipStage = prevStage;
        log_line(@"CRASH GUARD: previous run stopped at %@", prevStage);
    }

    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    UIViewController *vc = [UIViewController new];
    CGFloat w = vc.view.bounds.size.width;
    UIButton *run = [UIButton buttonWithType:UIButtonTypeSystem];
    run.frame = CGRectMake(20, 60, w - 40, 44);
    [run setTitle:@"RUN ALL (reset guard)" forState:UIControlStateNormal];
    [run addTarget:self action:@selector(runTapped:) forControlEvents:UIControlEventTouchUpInside];
    [vc.view addSubview:run];

    UIButton *clear = [UIButton buttonWithType:UIButtonTypeSystem];
    clear.frame = CGRectMake(20, 106, w - 40, 36);
    [clear setTitle:@"CLEAR LOG" forState:UIControlStateNormal];
    [clear addTarget:self action:@selector(clearTapped:) forControlEvents:UIControlEventTouchUpInside];
    [vc.view addSubview:clear];

    self.tv = [[UITextView alloc] initWithFrame:CGRectMake(10, 150, w - 20, vc.view.bounds.size.height - 160)];
    self.tv.editable = NO;
    self.tv.font = [UIFont fontWithName:@"Menlo" size:9];
    self.tv.text = gLog;
    [vc.view addSubview:self.tv];
    gTV = self.tv;

    self.window.rootViewController = vc;
    [self.window makeKeyAndVisible];

    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1.5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        run_all(NO);
    });
    return YES;
}

- (void)runTapped:(id)sender { run_all(YES); }

- (void)clearTapped:(id)sender {
    [gLog setString:@"===== CTProbe (log cleared) =====\n"];
    write_log();
    if (gTV) gTV.text = gLog;
}
@end

int main(int argc, char **argv) {
    @autoreleasepool {
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
    }
}
