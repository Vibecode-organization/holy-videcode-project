#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <Foundation/Foundation.h>
#import <string.h>
#import <stdlib.h>
static NSMutableString *gLog; static NSString *gPath;
static void L(NSString *fmt,...){va_list ap;va_start(ap,fmt);NSString*s=[[NSString alloc]initWithFormat:fmt arguments:ap];va_end(ap);[gLog appendString:s];[gLog appendString:@"\n"];[gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];NSLog(@"[get] %@",s);}
static uint64_t rd64(const void*p){uint64_t v;memcpy(&v,p,8);return v;}
static void scan(const char*tag,const uint8_t*b,size_t n){for(size_t i=0;i+8<=n;i+=8){uint64_t q=rd64(b+i);if((q&0xfffffff000000000ULL)==0xfffffff000000000ULL||(q>=0xffffffe000000000ULL&&q<0xffffffff00000000ULL))L(@"[HIT %s] +0x%zx = 0x%llx",tag,i,(unsigned long long)q);}}
static void run(void){
 io_service_t svc=IOServiceGetMatchingService(kIOMasterPortDefault,IOServiceMatching("AGXAcceleratorG14P"));
 L(@"[svc] 0x%x",svc); if(!svc)return;
 for(uint32_t t=0;t<=3;t++){
  io_connect_t c=0; kern_return_t kr=IOServiceOpen(svc,mach_task_self(),t,&c);
  L(@"[open t%u] 0x%x conn=0x%x",t,kr,c); if(kr) continue;
  size_t sizes[6]={64,64,536,8,32,16};
  for(int s=0;s<6;s++){
   uint8_t out[0x400]; memset(out,0xAA,sizeof(out)); size_t os=sizes[s];
   kr=IOConnectCallStructMethod(c,s,NULL,0,out,&os);
   L(@"[sel%d t%u] -> 0x%x osz=0x%zx",s,t,kr,os);
   if(kr==0){
    int qn=(int)(os<0x100?os:0x100)/8;
    for(int i=0;i<qn;i++)L(@"[q%d t%u] +0x%x = 0x%llx",s,t,i*8,(unsigned long long)rd64(out+i*8));
    scan("sel",out,os);
   }
  }
  IOServiceClose(c);
 }
 L(@"=== done ===");
}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{
 self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;
 UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;tv.text=@"IOGPUGet\n";
 [vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;
 dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0),^{NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];gPath=[docs stringByAppendingPathComponent:@"get.log"];gLog=[NSMutableString new];run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});
 return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
