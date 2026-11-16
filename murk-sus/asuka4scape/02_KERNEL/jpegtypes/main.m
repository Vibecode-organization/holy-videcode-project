#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <Foundation/Foundation.h>
#import <string.h>
#import <stdlib.h>
static NSMutableString *gLog; static NSString *gPath;
static void L(NSString *fmt,...){va_list ap;va_start(ap,fmt);NSString*s=[[NSString alloc]initWithFormat:fmt arguments:ap];va_end(ap);[gLog appendString:s];[gLog appendString:@"\n"];[gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];NSLog(@"[jt] %@",s);}
static uint64_t rd64(const void*p){uint64_t v;memcpy(&v,p,8);return v;}
static void run(void){
 io_service_t svc=IOServiceGetMatchingService(kIOMasterPortDefault,IOServiceMatching("AppleJPEGDriver"));
 L(@"[svc] 0x%x",svc); if(!svc)return;
 for(uint32_t t=0;t<=8;t++){
  io_connect_t c=0; kern_return_t kr=IOServiceOpen(svc,mach_task_self(),t,&c);
  L(@"[open t%u] 0x%x conn=0x%x",t,kr,c);
  if(kr){continue;}
  uint8_t in[0x1000]; memset(in,0,sizeof(in));
  *(uint32_t*)(in+0x00)=0; *(uint32_t*)(in+0x04)=0x100; *(uint32_t*)(in+0x08)=0x4000;
  *(uint32_t*)(in+0x0c)=0x1000; *(uint32_t*)(in+0x14)=16; *(uint32_t*)(in+0x18)=16;
  *(uint32_t*)(in+0x2c)=0; *(uint64_t*)(in+0x30)=0; *(uint32_t*)(in+0x7c)=0;
  uint8_t out[0x1000]; memset(out,0xAA,sizeof(out)); size_t os=0x1000;
  kr=IOConnectCallMethod(c,5,NULL,0,in,0x1000,NULL,NULL,out,&os);
  L(@"[t%u sel5] 0x%x osz=0x%zx out4c=0x%llx q0=0x%llx",t,kr,os,
    (unsigned long long)rd64(out+0x4c),(unsigned long long)rd64(out));
  uint8_t in7[0xda0]; memset(in7,0,sizeof(in7));
  *(uint32_t*)(in7+0x00)=0; *(uint32_t*)(in7+0x04)=0x100; *(uint32_t*)(in7+0x08)=0x4000;
  *(uint32_t*)(in7+0x0c)=0x1000; *(uint32_t*)(in7+0x14)=16; *(uint32_t*)(in7+0x18)=16;
  *(uint32_t*)(in7+0x2c)=0; *(uint64_t*)(in7+0x30)=0; *(uint32_t*)(in7+0x7c)=0;
  uint8_t out7[0xda0]; memset(out7,0xAA,sizeof(out7)); size_t os7=0xda0;
  kr=IOConnectCallMethod(c,7,NULL,0,in7,0xda0,NULL,NULL,out7,&os7);
  L(@"[t%u sel7] 0x%x osz=0x%zx out4c=0x%llx",t,kr,os7,(unsigned long long)rd64(out7+0x4c));
  IOServiceClose(c);
 }
 L(@"=== done ===");
}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{
 self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;
 UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;tv.text=@"JpegTypes\n";
 [vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;
 dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0),^{NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];gPath=[docs stringByAppendingPathComponent:@"jt.log"];gLog=[NSMutableString new];run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});
 return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
