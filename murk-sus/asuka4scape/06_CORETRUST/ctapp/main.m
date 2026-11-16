// ctapp — dlopen probe + self-signature dump.
#import <UIKit/UIKit.h>
#include <dlfcn.h>
#include <unistd.h>
#include <sys/sysctl.h>
#include <mach-o/loader.h>
#include <mach-o/fat.h>
#include <CommonCrypto/CommonDigest.h>

extern int csops(pid_t pid, unsigned int ops, void *useraddr, size_t usersize);
#define CS_OPS_STATUS 0
#define CS_OPS_ENTITLEMENTS_BLOB 7

static UITextView *gTV;
static NSMutableString *gLog;
static NSString *gLogPath;
static NSString *gDocs;

static void flushLog(void) {
    if (gLogPath) [gLog writeToFile:gLogPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
    if (gTV) gTV.text = gLog;
}

static NSString *sysctl_str(const char *name) {
    size_t sz = 0;
    if (sysctlbyname(name, NULL, &sz, NULL, 0) != 0 || sz == 0 || sz > 4096) return @"?";
    char *buf = calloc(1, sz + 1);
    if (sysctlbyname(name, buf, &sz, NULL, 0) != 0) { free(buf); return @"?"; }
    NSString *s = [NSString stringWithUTF8String:buf] ?: @"?";
    free(buf);
    return s;
}

// Walk our own LC_CODE_SIGNATURE superblob and summarise it.
static void dump_self_signature(NSMutableString *out) {
    NSString *exe = [[NSBundle mainBundle] executablePath];
    NSData *d = [NSData dataWithContentsOfFile:exe];
    if (!d) { [out appendString:@"selfsig: cannot read executable\n"]; return; }
    const unsigned char *b = d.bytes;
    if (d.length < 32) { [out appendString:@"selfsig: too small\n"]; return; }
    uint32_t magic = *(const uint32_t *)b;
    [out appendFormat:@"selfsig: exe=%@ size=%lu magic=%08x\n", exe.lastPathComponent, (unsigned long)d.length, magic];
    if (magic != MH_MAGIC_64) { [out appendString:@"selfsig: not thin 64-bit macho\n"]; return; }
    const struct mach_header_64 *mh = (const struct mach_header_64 *)b;
    const unsigned char *p = b + sizeof(*mh);
    uint32_t sigoff = 0, sigsize = 0, found = 0;
    for (uint32_t i = 0; i < mh->ncmds; i++) {
        const struct load_command *lc = (const struct load_command *)p;
        if (lc->cmd == LC_CODE_SIGNATURE) {
            const struct linkedit_data_command *ld = (const struct linkedit_data_command *)lc;
            sigoff = ld->dataoff; sigsize = ld->datasize; found = 1;
            break;
        }
        p += lc->cmdsize;
    }
    if (!found) { [out appendString:@"selfsig: no LC_CODE_SIGNATURE\n"]; return; }
    [out appendFormat:@"selfsig: blob off=%u size=%u\n", sigoff, sigsize];
    if ((uint64_t)sigoff + sigsize > d.length) { [out appendString:@"selfsig: blob out of file\n"]; return; }
    NSData *blob = [d subdataWithRange:NSMakeRange(sigoff, sigsize)];
    [[blob copy] writeToFile:[gDocs stringByAppendingPathComponent:@"selfsig.blob"] atomically:YES];
    const unsigned char *s = blob.bytes;
    if (sigsize < 12) return;
    uint32_t sb_magic = ntohl(*(const uint32_t *)s);
    uint32_t sb_len = ntohl(*(const uint32_t *)(s + 4));
    uint32_t sb_cnt = ntohl(*(const uint32_t *)(s + 8));
    [out appendFormat:@"superblob magic=%08x len=%u count=%u\n", sb_magic, sb_len, sb_cnt];
    if (sb_magic != 0xfade0cc0u) return;
    for (uint32_t i = 0; i < sb_cnt && 12 + (i + 1) * 8 <= sigsize; i++) {
        uint32_t type = ntohl(*(const uint32_t *)(s + 12 + i * 8));
        uint32_t off = ntohl(*(const uint32_t *)(s + 16 + i * 8));
        if (off + 8 > sigsize) continue;
        uint32_t blen = ntohl(*(const uint32_t *)(s + off + 4));
        [out appendFormat:@" blob type=%08x off=%u len=%u\n", type, off, blen];
        if ((type == 0 || type == 0x1000) && off + 0x2c <= sigsize) {
            const unsigned char *cd = s + off;
            uint32_t version = ntohl(*(const uint32_t *)(cd + 8));
            uint32_t flags = ntohl(*(const uint32_t *)(cd + 12));
            uint32_t identOff = ntohl(*(const uint32_t *)(cd + 20));
            uint32_t nSpec = ntohl(*(const uint32_t *)(cd + 24));
            uint32_t nCode = ntohl(*(const uint32_t *)(cd + 28));
            uint32_t codeLimit = ntohl(*(const uint32_t *)(cd + 32));
            uint8_t hashSize = cd[36], hashType = cd[37], platform = cd[38], pageSize = cd[39];
            [out appendFormat:@"  CD ver=%08x flags=%08x hashType=%u hashSize=%u nSpec=%u nCode=%u codeLimit=%u platform=%u page=%u\n",
             version, flags, hashType, hashSize, nSpec, nCode, codeLimit, platform, pageSize];
            if (identOff < blen) {
                char ident[256] = {0};
                size_t n = blen - identOff < sizeof(ident) - 1 ? blen - identOff : sizeof(ident) - 1;
                memcpy(ident, cd + identOff, n);
                [out appendFormat:@"  ident=%s\n", ident];
            }
            uint32_t special = (identOff + (uint32_t)strlen((const char *)cd + identOff) + 1 + 3) & ~3u;
            for (uint32_t k = 0; k < nSpec && k < 7 && special + (k + 1) * hashSize <= blen; k++) {
                [out appendFormat:@"  slot%u=", k];
                for (uint32_t j = 0; j < hashSize && j < 32; j++) [out appendFormat:@"%02x", cd[special + k * hashSize + j]];
                [out appendString:@"\n"];
            }
        }
    }
}

static void dump_self_entitlements(NSMutableString *out) {
    unsigned char buf[8192];
    memset(buf, 0, sizeof(buf));
    int r = csops(getpid(), CS_OPS_ENTITLEMENTS_BLOB, buf, sizeof(buf));
    [out appendFormat:@"csops(ents) -> %d errno=%d\n", r, errno];
    if (r != 0) return;
    uint32_t magic = ntohl(*(uint32_t *)buf);
    uint32_t length = ntohl(*(uint32_t *)(buf + 4));
    [out appendFormat:@"ents magic=%08x length=%u\n", magic, length];
    if (length > sizeof(buf) - 8) length = sizeof(buf) - 8;
    NSData *raw = [NSData dataWithBytes:buf + 8 length:length];
    [raw writeToFile:[gDocs stringByAppendingPathComponent:@"selfents.bin"] atomically:YES];
    NSString *txt = [[NSString alloc] initWithBytes:raw.bytes length:raw.length encoding:NSUTF8StringEncoding];
    if (txt) [out appendFormat:@"ents xml:\n%@\n", txt];
    else [out appendString:@"ents: not UTF-8 (DER?)\n"];
}

static void dump_profile(NSMutableString *out) {
    NSString *p = [[NSBundle mainBundle] pathForResource:@"embedded" ofType:@"mobileprovision"];
    [out appendFormat:@"profile path=%@\n", p ?: @"(none)"];
    if (!p) return;
    NSData *d = [NSData dataWithContentsOfFile:p];
    [out appendFormat:@"profile size=%lu\n", (unsigned long)d.length];
    if (d) [d writeToFile:[gDocs stringByAppendingPathComponent:@"profile.mobileprovision"] atomically:YES];
}

static void probe(NSString *tag) {
    NSMutableString *o = [NSMutableString string];
    [o appendFormat:@"\n===== probe %@ =====\n", tag];
    [o appendFormat:@"kern.osversion=%@\n", sysctl_str("kern.osversion")];
    [o appendFormat:@"hw.model=%@\n", sysctl_str("hw.model")];
    [o appendFormat:@"kern.version=%@\n", sysctl_str("kern.version")];
    [o appendFormat:@"bundle=%@\n", [[NSBundle mainBundle] bundlePath]];
    NSArray *files = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:[[NSBundle mainBundle] bundlePath] error:nil];
    [o appendFormat:@"bundle files=%@\n", [files componentsJoinedByString:@", "]];
    dump_profile(o);
    dump_self_entitlements(o);
    dump_self_signature(o);
    [o appendFormat:@"===== end probe =====\n"];
    [gLog appendString:o];
    flushLog();
}

static void attempt(NSString *name, NSString *path) {
    [gLog appendFormat:@"\n=== attempt %@ ===\npath: %@\n", name, path ?: @"(nil)"];
    flushLog();
    if (!path) { [gLog appendString:@"no path\n"]; flushLog(); return; }
    NSString *dir = [gLogPath stringByDeletingLastPathComponent];
    setenv("CT_MARKER", [[dir stringByAppendingPathComponent:[name stringByAppendingString:@".ran"]] UTF8String], 1);
    NSData *d = [NSData dataWithContentsOfFile:path];
    if (d) {
        unsigned char md[CC_SHA256_DIGEST_LENGTH];
        CC_SHA256(d.bytes, (CC_LONG)d.length, md);
        NSMutableString *h = [NSMutableString string];
        for (int i = 0; i < CC_SHA256_DIGEST_LENGTH; i++) [h appendFormat:@"%02x", md[i]];
        [gLog appendFormat:@"sha256=%s size=%lu\n", h.UTF8String, (unsigned long)d.length];
    }
    dlerror();
    void *h = dlopen(path.UTF8String, RTLD_NOW | RTLD_LOCAL);
    const char *err = dlerror();
    if (h) [gLog appendFormat:@"dlopen OK handle=%p\n", h];
    else [gLog appendFormat:@"dlopen FAIL: %s\n", err ?: "?"];
    NSString *marker = [dir stringByAppendingPathComponent:[name stringByAppendingString:@".ran"]];
    NSString *m = [NSString stringWithContentsOfFile:marker encoding:NSUTF8StringEncoding error:nil];
    if (m.length) [gLog appendFormat:@"marker: %@\n", [m stringByTrimmingCharactersInSet:[NSCharacterSet newlineCharacterSet]]];
    flushLog();
}

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (nonatomic, strong) UIWindow *window;
@property (nonatomic, strong) UIViewController *vc;
@end

@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)opts {
    gDocs = [NSHomeDirectory() stringByAppendingPathComponent:@"Documents"];
    [[NSFileManager defaultManager] createDirectoryAtPath:gDocs withIntermediateDirectories:YES attributes:nil error:nil];
    gLogPath = [gDocs stringByAppendingPathComponent:@"dylib.log"];
    gLog = [NSMutableString stringWithString:@"=== dylib test UI ===\n"];

    static NSString *names_arr[9];
    NSArray *names = @[@"probe", @"frameworks", @"dylib_adhoc_v2", @"dylib_adhoc_ent",
                       @"dylib_control", @"dylib_apple", @"dylib_apple_cs", @"dylib_apple_ext", @"system"];
    (void)names_arr;

    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    self.vc = [UIViewController new];
    CGFloat y = 50, h = 36;
    for (NSString *n in names) {
        UIButton *b = [UIButton buttonWithType:UIButtonTypeSystem];
        b.frame = CGRectMake(20, y, self.vc.view.bounds.size.width - 40, h);
        [b setTitle:n forState:UIControlStateNormal];
        [b addTarget:self action:@selector(tap:) forControlEvents:UIControlEventTouchUpInside];
        b.tag = [names indexOfObject:n];
        [self.vc.view addSubview:b];
        y += h + 4;
    }
    gTV = [[UITextView alloc] initWithFrame:CGRectMake(10, y, self.vc.view.bounds.size.width - 20, 260)];
    gTV.editable = NO; gTV.font = [UIFont fontWithName:@"Menlo" size:8];
    [self.vc.view addSubview:gTV];
    self.window.rootViewController = self.vc;
    [self.window makeKeyAndVisible];
    gTV.text = gLog;
    probe(@"launch");
    return YES;
}
- (void)tap:(UIButton *)b {
    NSArray *names = @[@"probe", @"frameworks", @"dylib_adhoc_v2", @"dylib_adhoc_ent",
                       @"dylib_control", @"dylib_apple", @"dylib_apple_cs", @"dylib_apple_ext", @"system"];
    NSString *n = names[b.tag];
    if ([n isEqualToString:@"probe"]) { probe(@"manual"); return; }
    if ([n isEqualToString:@"system"]) { attempt(n, @"/usr/lib/libSystem.B.dylib"); return; }
    if ([n isEqualToString:@"frameworks"]) {
        NSString *fw = [[[NSBundle mainBundle] bundlePath] stringByAppendingPathComponent:@"Frameworks/test.dylib"];
        attempt(n, fw);
        return;
    }
    attempt(n, [[NSBundle mainBundle] pathForResource:n ofType:nil]);
}
@end

int main(int argc, char **argv) {
    @autoreleasepool { return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class])); }
}
