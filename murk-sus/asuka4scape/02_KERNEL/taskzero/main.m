#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <Foundation/Foundation.h>
#import <IOSurface/IOSurfaceRef.h>
#import <string.h>
#import <stdlib.h>
#import <mach/mach.h>
static NSMutableString *gLog; static NSString *gPath;
static void L(NSString *fmt,...){va_list ap;va_start(ap,fmt);NSString*s=[[NSString alloc]initWithFormat:fmt arguments:ap];va_end(ap);[gLog appendString:s];[gLog appendString:@"\n"];[gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];NSLog(@"[tz] %@",s);}
static uint64_t rd64(const void*p){uint64_t v;memcpy(&v,p,8);return v;}
static void run(void){
 const char*names[]={"IOSurfaceRoot","AppleM2ScalerCSCDriver","AGXAcceleratorG14P","AppleJPEGDriver","IOMobileFramebuffer"};
 for(int ni=0;ni<5;ni++){
  io_service_t svc=IOServiceGetMatchingService(kIOMasterPortDefault,IOServiceMatching(names[ni]));
  L(@"[svc %s] 0x%x",names[ni],svc); if(!svc) continue;
  for(uint32_t t=0;t<3;t++){
   for(int mode=0;mode<2;mode++){
    mach_port_t task=mode?mach_task_self():MACH_PORT_NULL;
    io_connect_t c=0; kern_return_t kr=IOServiceOpen(svc,task,t,&c);
    L(@"[open %s t%u task=%s] 0x%x conn=0x%x",names[ni],t,mode?"self":"NULL",kr,c);
    if(kr==0&&c){
     if(ni==0){
      uint64_t sc[2]={0x04D00000ULL,0x4000}; uint8_t out[0xc68]; memset(out,0xAA,sizeof(out)); size_t os=sizeof(out);
      kr=IOConnectCallMethod(c,7,sc,2,NULL,0,NULL,NULL,out,&os);
      L(@"[surf t%u task=%s sel7 paddr] -> 0x%x osz=0x%zx q0=0x%llx q3=0x%llx",t,mode?"self":"NULL",kr,os,(unsigned long long)rd64(out),(unsigned long long)rd64(out+0x18));
      if(kr==0){uint32_t sid=*(uint32_t*)(out+0x18);IOSurfaceRef sf=IOSurfaceLookup(sid);L(@"[surf] id=%u lookup=%p",sid,sf);if(sf){void*b=IOSurfaceGetBaseAddress(sf);L(@"[surf] base=%p alloc=0x%zx",b,IOSurfaceGetAllocSize(sf));if(b&&(uintptr_t)b<0x800000000000ULL){L(@"[surf] base0=0x%llx",(unsigned long long)rd64(b));}CFRelease(sf);}}
     } else if(ni==1){
      uint8_t out[0x400]; memset(out,0xAA,sizeof(out)); size_t os=0x298; kr=IOConnectCallMethod(c,11,NULL,0,NULL,0,NULL,NULL,out,&os);
      L(@"[scaler t%u task=%s sel11] -> 0x%x osz=0x%zx q0=0x%llx",t,mode?"self":"NULL",kr,os,(unsigned long long)rd64(out));
     } else if(ni==2){
      uint8_t out[0x40]; memset(out,0xAA,sizeof(out)); size_t os=0x40; kr=IOConnectCallMethod(c,0,NULL,0,NULL,0,NULL,NULL,out,&os);
      L(@"[agx t%u task=%s sel0] -> 0x%x osz=0x%zx q0=0x%llx",t,mode?"self":"NULL",kr,os,(unsigned long long)rd64(out));
     }
     IOServiceClose(c);
    }
   }
  }
  IOObjectRelease(svc);
 }
 L(@"=== done ===");
}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{
 self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;
 UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;tv.text=@"TaskZero\n";
 [vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;
 dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0),^{NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];gPath=[docs stringByAppendingPathComponent:@"tz.log"];gLog=[NSMutableString new];run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});
 return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
