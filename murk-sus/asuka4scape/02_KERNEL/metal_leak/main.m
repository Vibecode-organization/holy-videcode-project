#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <Foundation/Foundation.h>
#import <Metal/Metal.h>
#import <string.h>
#import <stdlib.h>
static NSMutableString *gLog; static NSString *gPath;
static void L(NSString *fmt,...){va_list ap;va_start(ap,fmt);NSString*s=[[NSString alloc]initWithFormat:fmt arguments:ap];va_end(ap);[gLog appendString:s];[gLog appendString:@"\n"];[gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];NSLog(@"[ml] %@",s);}
static uint64_t rd64(const void*p){uint64_t v;memcpy(&v,p,8);return v;}
static void dump0(io_connect_t c,const char*tag){uint8_t o[0x40];memset(o,0xCC,sizeof(o));size_t os=0x40;uint64_t so[2]={0,0};uint32_t soc=0;
 kern_return_t kr=IOConnectCallMethod(c,0,so,0,NULL,0,NULL,NULL,o,&os);L(@"[sel0 %s] 0x%x osz=0x%zx",tag,kr,os);
 for(int i=0;i<8;i++)L(@"[sel0 %s] q%d=0x%llx",tag,i,(unsigned long long)rd64(o+i*8));}
static void dump1(io_connect_t c,const char*tag){uint8_t o[0x40];memset(o,0xCC,sizeof(o));size_t os=0x40;
 kern_return_t kr=IOConnectCallMethod(c,1,NULL,0,NULL,0,NULL,NULL,o,&os);L(@"[sel1 %s] 0x%x osz=0x%zx",tag,kr,os);
 for(int i=0;i<8;i++)L(@"[sel1 %s] q%d=0x%llx",tag,i,(unsigned long long)rd64(o+i*8));}
static void run(void){
 @autoreleasepool{
  id<MTLDevice> md=MTLCreateSystemDefaultDevice(); L(@"[metal] device=%p name=%@",md,md?[md name]:@"nil");
  id<MTLCommandQueue> mq=md?[md newCommandQueue]:nil; L(@"[metal] queue=%p",mq);
  id<MTLBuffer> mb=md?[md newBufferWithLength:0x4000 options:MTLResourceStorageModeShared]:nil; L(@"[metal] buf=%p gpu=%llx",mb,mb?(unsigned long long)[mb gpuAddress]:0);
  if(mq){id<MTLCommandBuffer> cb=[mq commandBuffer];[cb commit];[cb waitUntilCompleted];L(@"[metal] cb done status=%ld",(long)[cb status]);}
  io_service_t svc=IOServiceGetMatchingService(kIOMasterPortDefault,IOServiceMatching("AGXAcceleratorG14P"));L(@"[svc] 0x%x",svc);
  if(svc){io_connect_t c=0;kern_return_t kr=IOServiceOpen(svc,mach_task_self(),1,&c);IOObjectRelease(svc);L(@"[open] 0x%x conn=0x%x",kr,c);
   if(!kr){dump0(c,"after_metal");dump1(c,"after_metal");IOServiceClose(c);}}
 }
 L(@"=== done ===");
}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{
 self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;
 UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;tv.text=@"MetalLeak\n";
 [vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;
 dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0),^{NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];gPath=[docs stringByAppendingPathComponent:@"ml.log"];gLog=[NSMutableString new];run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});
 return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
