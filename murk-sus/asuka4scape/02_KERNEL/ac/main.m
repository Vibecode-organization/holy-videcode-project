#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <sys/stat.h>
#import <spawn.h>
#import <sys/wait.h>
#import <errno.h>
extern char **environ;
static NSMutableString*gLog;static NSString*gPath;
static void L(NSString*fmt,...){va_list ap;va_start(ap,fmt);NSString*s=[[NSString alloc]initWithFormat:fmt arguments:ap];va_end(ap);[gLog appendString:s];[gLog appendString:@"\n"];[gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];NSLog(@"[ac] %@",s);}
static void trylaunch(NSString*bin,NSString*target){char*argv[]={(char*)bin.fileSystemRepresentation,(char*)"load",(char*)target.fileSystemRepresentation,NULL};pid_t pid=0;errno=0;int r=posix_spawn(&pid,bin.fileSystemRepresentation,NULL,NULL,argv,environ);L(@"[spawn %@] r=%d pid=%d errno=%d",bin,r,pid,errno);if(r==0){int st=0;waitpid(pid,&st,0);L(@"[spawn %@] status=0x%x",bin,st);}}
static void run(void){NSString*target=@"/var/mobile/Library/LaunchAgents/com.mcmx.agent.plist";struct stat st;errno=0;int r=stat(target.fileSystemRepresentation,&st);L(@"[stat target] r=%d errno=%d mode=%o size=%lld",r,errno,r?0:st.st_mode,r?0:(long long)st.st_size);NSData*d=[NSData dataWithContentsOfFile:target];L(@"[read target] %p len=%zu",d,d.length);if(d){L(@"[read target] first=%.*s",(int)(d.length>200?200:d.length),(const char*)d.bytes);}
 NSString*g=[[NSFileManager defaultManager] containerURLForSecurityApplicationGroupIdentifier:@"group.8e0bc870a21520b9.1"].path;NSString*marker=[g stringByAppendingPathComponent:@"agent_ran"];L(@"[marker] %@ exists=%d",marker,[[NSFileManager defaultManager] fileExistsAtPath:marker]);NSData*m=[NSData dataWithContentsOfFile:marker];if(m)L(@"[marker] data=%.*s",(int)m.length,(const char*)m.bytes);
 for(NSString*b in @[@"/bin/launchctl",@"/usr/bin/launchctl",@"/sbin/launchctl",@"/usr/libexec/launchctl",@"/usr/libexec/launchd"]){trylaunch(b,target);}sleep(3);L(@"[marker2] exists=%d",[[NSFileManager defaultManager] fileExistsAtPath:marker]);L(@"=== done ===");}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;[vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES)firstObject];gPath=[[docs stringByAppendingPathComponent:@"ac.log"]copy];gLog=[NSMutableString new];dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED,0),^{run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
