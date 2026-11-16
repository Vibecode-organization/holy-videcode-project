#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <Foundation/Foundation.h>
#import <string.h>
#import <stdlib.h>
static NSMutableString *gLog; static NSString *gPath;
static void L(NSString *fmt,...){va_list ap;va_start(ap,fmt);NSString*s=[[NSString alloc]initWithFormat:fmt arguments:ap];va_end(ap);[gLog appendString:s];[gLog appendString:@"\n"];[gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];NSLog(@"[dt] %@",s);}
static void scanstr(NSString*tag,NSString*s){if(!s)return;for(NSString*line in [s componentsSeparatedByString:@"\n"]){if([line containsString:@"fffffff"]||[line containsString:@"0x4d"])L(@"[%s] %@",tag.UTF8String,line);}}
static void dump(const char*path){
 io_registry_entry_t e=IORegistryEntryFromPath(kIOMasterPortDefault,path);L(@"[path %s] 0x%x",path,e);if(!e)return;
 CFMutableDictionaryRef props=NULL;kern_return_t kr=IORegistryEntryCreateCFProperties(e,&props,kCFAllocatorDefault,0);L(@"[props %s] kr=0x%x",path,kr);
 if(props){NSString*s=[NSString stringWithFormat:@"%@",(__bridge NSDictionary*)props];L(@"[dict %s] len=%zu",path,s.length);scanstr([NSString stringWithFormat:@"%s",path],s);CFRelease(props);}
 IOObjectRelease(e);
}
static void run(void){
 const char*paths[]={"IODeviceTree:/chosen","IODeviceTree:/memory","IODeviceTree:/arm-io/sgx","IODeviceTree:/arm-io/sgx/sgx","IODeviceTree:/arm-io/sgx/sgx,reg","IODeviceTree:/"};
 for(int i=0;i<6;i++)dump(paths[i]);
 L(@"=== done ===");
}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{
 self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;
 UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;tv.text=@"DTProbe\n";
 [vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;
 dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0),^{NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];gPath=[docs stringByAppendingPathComponent:@"dt.log"];gLog=[NSMutableString new];run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});
 return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
