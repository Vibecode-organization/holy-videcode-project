#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <Foundation/Foundation.h>
#import <IOSurface/IOSurfaceRef.h>
#import <CoreVideo/CoreVideo.h>
#import <VideoToolbox/VideoToolbox.h>
typedef struct OpaqueVTPixelTransferSession *VTPixelTransferSessionRef;
extern OSStatus VTPixelTransferSessionCreate(CFAllocatorRef, VTPixelTransferSessionRef *);
extern OSStatus VTPixelTransferSessionTransferImage(VTPixelTransferSessionRef, CVPixelBufferRef, CVPixelBufferRef);
#import <string.h>
#import <stdlib.h>
static NSMutableString *gLog; static NSString *gPath;
static void L(NSString *fmt,...){va_list ap;va_start(ap,fmt);NSString*s=[[NSString alloc]initWithFormat:fmt arguments:ap];va_end(ap);[gLog appendString:s];[gLog appendString:@"\n"];[gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];NSLog(@"[sx] %@",s);}
static uint64_t rd64(const void*p){uint64_t v;memcpy(&v,p,8);return v;}
static void scan(const char*tag,const uint8_t*b,size_t n){for(size_t i=0;i+8<=n;i+=8){uint64_t q=rd64(b+i);if((q&0xfffffff000000000ULL)==0xfffffff000000000ULL||(q>=0xffffffe000000000ULL&&q<0xffffffff00000000ULL))L(@"[HIT %s] +0x%zx = 0x%llx",tag,i,(unsigned long long)q);}}
static CVPixelBufferRef pb(int w,int h){NSDictionary*a=@{(id)kCVPixelBufferIOSurfacePropertiesKey:@{} };CVPixelBufferRef p=NULL;CVReturn r=CVPixelBufferCreate(kCFAllocatorDefault,w,h,kCVPixelFormatType_32BGRA,(__bridge CFDictionaryRef)a,&p);L(@"[pb] %dx%d -> %d %p",w,h,r,p);return p;}
static void runctx(void){
 CVPixelBufferRef a=pb(1920,1080),b=pb(640,360); if(!a||!b)return;
 VTPixelTransferSessionRef ts=NULL; OSStatus st=VTPixelTransferSessionCreate(kCFAllocatorDefault,&ts); L(@"[vt] create=%d ts=%p",(int)st,ts);
 if(ts){st=VTPixelTransferSessionTransferImage(ts,a,b);L(@"[vt] transfer=%d",(int)st);CFRelease(ts);}
 if(a)CFRelease(a); if(b)CFRelease(b);
}
static void run(void){
 runctx();
 io_service_t svc=IOServiceGetMatchingService(kIOMasterPortDefault,IOServiceMatching("AppleM2ScalerCSCDriver"));L(@"[svc] 0x%x",svc);if(!svc)return;
 for(uint32_t t=0;t<3;t++){
  io_connect_t c=0;kern_return_t kr=IOServiceOpen(svc,mach_task_self(),t,&c);L(@"[open t%u] 0x%x conn=0x%x",t,kr,c);if(kr)continue;
  uint8_t o[0x400];memset(o,0xAA,sizeof(o));size_t os=0x298;kr=IOConnectCallMethod(c,11,NULL,0,NULL,0,NULL,NULL,o,&os);L(@"[t%u sel11] kr=0x%x osz=0x%zx",t,kr,os);if(!kr){for(int i=0;i<0x298&&i<0x100;i+=8)L(@"[t%u s11] +0x%x=0x%llx",t,i,(unsigned long long)rd64(o+i));scan("s11",o,0x298);}
  uint8_t in1[0x1b0];memset(in1,0,sizeof(in1));memset(o,0xAA,sizeof(o));os=0x40;kr=IOConnectCallMethod(c,1,NULL,0,in1,0x1b0,NULL,NULL,o,&os);L(@"[t%u sel1] kr=0x%x osz=0x%zx q0=0x%llx q1=0x%llx",t,kr,os,(unsigned long long)rd64(o),(unsigned long long)rd64(o+8));
  uint8_t in4[0x20];memset(in4,0,sizeof(in4));memset(o,0xAA,sizeof(o));os=0x20;kr=IOConnectCallMethod(c,4,NULL,0,in4,0x20,NULL,NULL,o,&os);L(@"[t%u sel4] kr=0x%x osz=0x%zx q0=0x%llx q1=0x%llx q2=0x%llx q3=0x%llx",t,kr,os,(unsigned long long)rd64(o),(unsigned long long)rd64(o+8),(unsigned long long)rd64(o+0x10),(unsigned long long)rd64(o+0x18));scan("s4",o,0x20);
  IOServiceClose(c);
 }
 IOObjectRelease(svc);L(@"=== done ===");
}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{
 self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;
 UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;tv.text=@"ScalerCtx\n";
 [vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;
 dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0),^{NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];gPath=[docs stringByAppendingPathComponent:@"sx.log"];gLog=[NSMutableString new];run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});
 return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
