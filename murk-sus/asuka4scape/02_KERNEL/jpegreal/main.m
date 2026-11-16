#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <Foundation/Foundation.h>
#import <ImageIO/ImageIO.h>
#import <string.h>
#import <stdlib.h>
static NSMutableString *gLog; static NSString *gPath;
static void L(NSString *fmt,...){va_list ap;va_start(ap,fmt);NSString*s=[[NSString alloc]initWithFormat:fmt arguments:ap];va_end(ap);[gLog appendString:s];[gLog appendString:@"\n"];[gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];NSLog(@"[jr] %@",s);}
static uint64_t rd64(const void*p){uint64_t v;memcpy(&v,p,8);return v;}
static void scan(const char*tag,const uint8_t*b,size_t n){for(size_t i=0;i+8<=n;i+=8){uint64_t q=rd64(b+i);if((q&0xfffffff000000000ULL)==0xfffffff000000000ULL)L(@"[HIT %s] +0x%zx=0x%llx",tag,i,(unsigned long long)q);}}
static NSData* makejpeg(void){UIGraphicsBeginImageContext(CGSizeMake(64,64));[[UIColor redColor] setFill];UIRectFill(CGRectMake(0,0,64,64));UIImage*img=UIGraphicsGetImageFromCurrentImageContext();UIGraphicsEndImageContext();NSData*d=UIImageJPEGRepresentation(img,0.8);L(@"[jpeg] data=%p len=%zu",d,d.length);return d;}
static void run(void){
 NSData*j=makejpeg();if(j){CGImageSourceRef src=CGImageSourceCreateWithData((__bridge CFDataRef)j,NULL);L(@"[imgsrc] %p",src);if(src){CGImageRef im=CGImageSourceCreateImageAtIndex(src,0,NULL);L(@"[img] %p %zux%zu",im,CGImageGetWidth(im),CGImageGetHeight(im));if(im)CGImageRelease(im);CFRelease(src);}}
 io_service_t svc=IOServiceGetMatchingService(kIOMasterPortDefault,IOServiceMatching("AppleJPEGDriver"));L(@"[svc] 0x%x",svc);if(!svc)return;
 for(uint32_t t=0;t<9;t++){
  io_connect_t c=0;kern_return_t kr=IOServiceOpen(svc,mach_task_self(),t,&c);if(kr)continue;L(@"[open t%u] conn=0x%x",t,c);
  uint8_t in[0x1000];memset(in,0,sizeof(in));*(uint32_t*)(in+0x00)=0;*(uint32_t*)(in+0x04)=0x100;*(uint32_t*)(in+0x08)=0x4000;*(uint32_t*)(in+0x0c)=0x1000;*(uint32_t*)(in+0x14)=64;*(uint32_t*)(in+0x18)=64;*(uint32_t*)(in+0x2c)=0;*(uint32_t*)(in+0x7c)=0;
  uint8_t out[0x1000];memset(out,0xAA,sizeof(out));size_t os=0x1000;
  kr=IOConnectCallStructMethod(c,5,in,0x1000,out,&os);
  L(@"[t%u sel5] kr=0x%x osz=0x%zx out4c=0x%llx out10=0x%llx",t,kr,os,(unsigned long long)rd64(out+0x4c),(unsigned long long)rd64(out+0x10));scan("jpeg",out,0x1000);
  IOServiceClose(c);
 }
 IOObjectRelease(svc);L(@"=== done ===");
}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{
 self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;
 UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;tv.text=@"JpegReal\n";
 [vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;
 dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0),^{NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];gPath=[docs stringByAppendingPathComponent:@"jr.log"];gLog=[NSMutableString new];run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});
 return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
