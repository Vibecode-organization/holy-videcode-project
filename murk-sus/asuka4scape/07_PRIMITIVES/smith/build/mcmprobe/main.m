// MCMProbe — read-only MobileContainerManager class-13 group/part sweep.
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <dlfcn.h>
typedef void *xpc_object_t;
extern xpc_object_t xpc_string_create(const char *);
extern void xpc_release(xpc_object_t);
#import <sys/stat.h>
#import <dirent.h>
#import <errno.h>
#import <fcntl.h>
#import <unistd.h>

typedef void *(*q_create)(void);
typedef void (*q_set_class)(void *, uint64_t);
typedef void (*q_set_group)(void *, xpc_object_t);
typedef void (*q_set_ids)(void *, xpc_object_t);
typedef void (*q_set_flags)(void *, uint64_t);
typedef void (*q_set_part)(void *, uint64_t);
typedef void (*q_set_domain)(void *, const char *);
typedef void *(*q_get_one)(void *);
typedef char *(*copy_path)(void *);
typedef char *(*copy_token)(void *);
typedef void (*q_free)(void *);
typedef int64_t (*sbx_consume)(const char *);

static q_create Qc; static q_set_class Qclass; static q_set_group Qgroup; static q_set_ids Qids;
static q_set_flags Qflags; static q_set_part Qpart; static q_set_domain Qdomain;
static q_get_one Qone; static copy_path Qpath; static copy_token Qtoken; static q_free Qfree;
static sbx_consume Sconsume;
static NSMutableString *L; static NSString *LP;

static void logf_(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt); NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap]; va_end(ap);
    NSLog(@"[mcm] %@", s); [L appendFormat:@"%@\n", s];
    [L writeToFile:LP atomically:YES encoding:NSUTF8StringEncoding error:nil];
    int fd = open(LP.fileSystemRepresentation, O_RDONLY); if (fd>=0){fsync(fd);close(fd);}
}

static void list_dir(NSString *path) {
    DIR *d = opendir(path.fileSystemRepresentation);
    if (!d) { logf_(@"  readdir(%@) fail errno=%d", path, errno); return; }
    int n=0; struct dirent *e;
    while ((e = readdir(d)) && n<20) { logf_(@"  entry: %s", e->d_name); n++; }
    closedir(d);
}

static BOOL one_group(NSString *gid, uint64_t part, uint64_t flags, BOOL use_ids) {
    void *q = Qc(); if (!q) return NO;
    Qclass(q, 13);
    xpc_object_t x = xpc_string_create(gid.UTF8String);
    if (use_ids) Qids(q, x); else Qgroup(q, x);
    Qflags(q, flags);
    Qpart(q, part);
    Qdomain(q, "");
    void *obj = Qone(q);
    if (!obj) { logf_(@"[grp] %@ part=%llu flags=0x%llx ids=%d -> no result", gid, (unsigned long long)part, (unsigned long long)flags, use_ids); xpc_release(x); Qfree(q); return NO; }
    char *p = Qpath ? Qpath(obj) : NULL;
    char *t = Qtoken ? Qtoken(obj) : NULL;
    logf_(@"[grp] %@ part=%llu flags=0x%llx ids=%d -> obj=%p path=%s token=%s",
          gid, (unsigned long long)part, (unsigned long long)flags, use_ids, obj, p?p:"(null)", t?"yes":"(null)");
    if (t && Sconsume) { int64_t h = Sconsume(t); logf_(@"  consume -> %lld", (long long)h); }
    if (p) {
        struct stat st;
        if (stat(p, &st)==0) logf_(@"  stat mode=%o uid=%d gid=%d", st.st_mode & 07777, st.st_uid, st.st_gid);
        else logf_(@"  stat fail errno=%d", errno);
        list_dir([NSString stringWithUTF8String:p]);
        NSString *lp = [[NSString stringWithUTF8String:p] stringByAppendingPathComponent:@"Library"];
        list_dir(lp);
        list_dir([lp stringByAppendingPathComponent:@"Preferences"]);
    }
    if (p) free(p); if (t) free(t);
    xpc_release(x); Qfree(q);
    return YES;
}

static void run(void) {
    void *h = dlopen("/usr/lib/system/libsystem_containermanager.dylib", RTLD_NOW|RTLD_LOCAL);
    logf_(@"dlopen mcm -> %p", h);
    if (!h) return;
    Qc=dlsym(h,"container_query_create"); Qclass=dlsym(h,"container_query_set_class");
    Qgroup=dlsym(h,"container_query_set_group_identifiers"); Qids=dlsym(h,"container_query_set_identifiers");
    Qflags=dlsym(h,"container_query_operation_set_flags");
    if (!Qflags) Qflags=dlsym(h,"container_query_set_flags");
    Qpart=dlsym(h,"container_query_operation_set_part"); Qdomain=dlsym(h,"container_query_operation_set_part_domain");
    Qone=dlsym(h,"container_query_get_single_result"); Qpath=dlsym(h,"container_copy_path");
    Qtoken=dlsym(h,"container_copy_sandbox_token"); Qfree=dlsym(h,"container_query_free");
    Sconsume=dlsym(RTLD_DEFAULT,"sandbox_extension_consume");
    logf_(@"sym Qc=%p Qclass=%p Qgroup=%p Qids=%p Qflags=%p Qpart=%p Qdomain=%p Qone=%p Qpath=%p Qtoken=%p Qfree=%p Sconsume=%p",
          Qc,Qclass,Qgroup,Qids,Qflags,Qpart,Qdomain,Qone,Qpath,Qtoken,Qfree,Sconsume);
    if (!Qc||!Qclass||!Qgroup||!Qflags||!Qpart||!Qdomain||!Qone||!Qfree) return;

    // control: own data container, part 3
    NSString *own = [[NSBundle mainBundle] bundleIdentifier];
    logf_(@"own bundle id=%@", own);
    one_group(own, 3, 0x8000000000ULL, YES);   // class 13 with ids is wrong; control via class 2 below
    // proper class 2 control
    {
        void *q=Qc(); Qclass(q,2); xpc_object_t x=xpc_string_create(own.UTF8String); Qids(q,x);
        Qflags(q,0x8000000000ULL); Qpart(q,3); Qdomain(q,"");
        void *o=Qone(q);
        if(o){char*p=Qpath?Qpath(o):NULL;char*t=Qtoken?Qtoken(o):NULL;logf_(@"[own] path=%s token=%s",p?p:"(null)",t?"yes":"(null)");
            if(t&&Sconsume)logf_(@"  consume=%lld",(long long)Sconsume(t)); if(p){list_dir([NSString stringWithUTF8String:p]);free(p);} if(t)free(t);}
        else logf_(@"[own] no result");
        xpc_release(x);Qfree(q);
    }

    NSArray *groups = @[
      @"systemgroup.com.apple.mobilegestaltcache",
      @"systemgroup.com.apple.installcoordinationd",
      @"systemgroup.com.apple.configurationprofiles",
      @"systemgroup.com.apple.pisco.suinfo",
      @"systemgroup.com.apple.osanalytics",
      @"systemgroup.com.apple.codecoveragedata",
      @"systemgroup.com.apple.nsurlstoragedresources",
      @"systemgroup.com.apple.ondemandresources",
      @"systemgroup.com.apple.lsd.iconscache",
    ];
    for (NSString *g in groups) {
        for (uint64_t part=0; part<=6; part++) {
            one_group(g, part, 0x8100000000ULL, NO);
            one_group(g, part, 0x8000000000ULL, NO);
        }
    }
    logf_(@"=== done ===");
}

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property(nonatomic,strong) UIWindow *window; @property(nonatomic,strong) UITextView *tv;
@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts {
    NSString *docs=[NSHomeDirectory() stringByAppendingPathComponent:@"Documents"];
    [[NSFileManager defaultManager] createDirectoryAtPath:docs withIntermediateDirectories:YES attributes:nil error:nil];
    LP=[docs stringByAppendingPathComponent:@"mcmprobe.log"]; L=[NSMutableString stringWithString:@"\n=== MCMProbe ===\n"];
    self.window=[[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    UIViewController *vc=[UIViewController new]; self.tv=[[UITextView alloc] initWithFrame:vc.view.bounds];
    self.tv.editable=NO; self.tv.font=[UIFont fontWithName:@"Menlo" size:9]; [vc.view addSubview:self.tv];
    self.window.rootViewController=vc; [self.window makeKeyAndVisible];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW,(int64_t)(1.0*NSEC_PER_SEC)),dispatch_get_main_queue(),^{
        dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED,0),^{ run(); dispatch_async(dispatch_get_main_queue(),^{self.tv.text=L;}); });
    });
    return YES;
}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
