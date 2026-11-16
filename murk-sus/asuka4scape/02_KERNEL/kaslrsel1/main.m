#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <Foundation/Foundation.h>
#import <string.h>
#import <stdlib.h>
static NSMutableString *gLog; static NSString *gPath;
static void L(NSString *fmt,...){va_list ap;va_start(ap,fmt);NSString*s=[[NSString alloc]initWithFormat:fmt arguments:ap];va_end(ap);[gLog appendString:s];[gLog appendString:@"\n"];[gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];NSLog(@"[k1] %@",s);}
static uint64_t rd64(const void*p){uint64_t v;memcpy(&v,p,8);return v;}
static void run(void){
 const char*names[]={"IOGPUDevice","IOGPU","IOGPUDeviceUserClient","AGXAcceleratorG14P","AGXAccelerator","AGXDevice","IOAccelerator","IOSurfaceRoot"};
 for(int ni=0;ni<8;ni++){
  io_service_t svc=IOServiceGetMatchingService(kIOMasterPortDefault,IOServiceMatching(names[ni]));
  L(@"[svc %s] 0x%x",names[ni],svc); if(!svc)continue;
  for(uint32_t t=0;t<4;t++){
   io_connect_t c=0; kern_return_t kr=IOServiceOpen(svc,mach_task_self(),t,&c);
   if(kr){L(@"[open %s t%u] 0x%x",names[ni],t,kr);continue;}
   L(@"[open %s t%u] conn=0x%x",names[ni],t,c);
   for(int sel=0;sel<2;sel++){
    uint8_t o[0x100]; memset(o,0xAA,sizeof(o)); size_t os=0x40;
    kr=IOConnectCallStructMethod(c,sel,NULL,0,o,&os);
    L(@"[%s t%u sel%d] kr=0x%x osz=0x%zx q0=0x%llx q1=0x%llx q2=0x%llx q3=0x%llx q4=0x%llx q5=0x%llx q6=0x%llx q7=0x%llx",names[ni],t,sel,kr,os,
      (unsigned long long)rd64(o),(unsigned long long)rd64(o+8),(unsigned long long)rd64(o+0x10),(unsigned long long)rd64(o+0x18),(unsigned long long)rd64(o+0x20),(unsigned long long)rd64(o+0x28),(unsigned long long)rd64(o+0x30),(unsigned long long)rd64(o+0x38));
   }
   IOServiceClose(c);
  }
  IOObjectRelease(svc);
 }
 L(@"=== done ===");
}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{
 self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;
 UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;tv.text=@"KaslrSel1\n";
 [vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;
 dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0),^{NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];gPath=[docs stringByAppendingPathComponent:@"k1.log"];gLog=[NSMutableString new];run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});
 return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
