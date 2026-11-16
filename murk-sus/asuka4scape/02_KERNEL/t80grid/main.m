#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <Foundation/Foundation.h>
#import <IOSurface/IOSurfaceRef.h>
#import <mach/mach.h>
#import <string.h>
#import <stdlib.h>
static NSMutableString *gLog; static NSString *gPath; static io_service_t g_svc; static io_connect_t g_c;
static void L(NSString *fmt,...){va_list ap;va_start(ap,fmt);NSString*s=[[NSString alloc]initWithFormat:fmt arguments:ap];va_end(ap);[gLog appendString:s];[gLog appendString:@"\n"];[gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];NSLog(@"[g] %@",s);}
static uint64_t rd64(const void*p){uint64_t v;memcpy(&v,p,8);return v;}
static kern_return_t call8(uint32_t type,uint32_t p14,uint32_t p15,uint32_t p16,uint64_t a30,uint64_t a38,uint64_t a40,uint64_t a48,uint32_t a50,uint8_t*out){
 uint8_t in[0x100]; memset(in,0,sizeof(in)); *(uint32_t*)in=type; *(uint32_t*)(in+0x14)=p14; *(uint32_t*)(in+0x15)=p15; *(uint32_t*)(in+0x16)=p16;
 *(uint64_t*)(in+0x18)=0; *(uint64_t*)(in+0x30)=a30; *(uint64_t*)(in+0x38)=a38; *(uint64_t*)(in+0x40)=a40; *(uint64_t*)(in+0x48)=a48; *(uint32_t*)(in+0x50)=a50;
 memset(out,0xAA,0x1000); size_t os=0x1000; return IOConnectCallStructMethod(g_c,8,in,0x100,out,&os);
}
static void reopen(void){ if(g_c){IOServiceClose(g_c);g_c=0;} kern_return_t kr=IOServiceOpen(g_svc,mach_task_self(),1,&g_c); if(kr)L(@"[reopen] 0x%x",kr); }
static void run(void){
 g_svc=IOServiceGetMatchingService(kIOMasterPortDefault,IOServiceMatching("AGXAcceleratorG14P")); L(@"[svc] 0x%x",g_svc); if(!g_svc)return; reopen();
 NSDictionary*d=@{@"IOSurfaceAllocSize":@0x10000,@"IOSurfaceMemoryRegion":@"PurpleGfxMem"};
 IOSurfaceRef s=IOSurfaceCreate((__bridge CFDictionaryRef)d); if(!s){L(@"[no purple]");return;}
 uint64_t base=(uint64_t)(uintptr_t)IOSurfaceGetBaseAddress(s); L(@"[base] 0x%llx",(unsigned long long)base); memset((void*)base,0x5A,0x10000);
 uint64_t A[]={0,base,0x4000};
 uint64_t B[]={0,base,base+0x4000,0x4000};
 uint64_t C[]={0,base,base+0x4000,0x4000};
 uint64_t D[]={0x4000,0x1000};
 uint32_t E[]={0x4000,0x1000,0};
 int cnt=0,ok=0;
 for(int bits=0;bits<2;bits++){
  uint32_t p16=(bits&1)?0x20:0;
  for(int ia=0;ia<3;ia++)for(int ib=0;ib<4;ib++)for(int ic=0;ic<4;ic++)for(int id=0;id<2;id++)for(int ie=0;ie<3;ie++){
   uint8_t o[0x1000]; kern_return_t kr=call8(0x80,0,0,p16,A[ia],B[ib],C[ic],D[id],E[ie],o); cnt++;
   if(kr==0){ ok++; L(@"[OK] p16=0x%x a30=0x%llx a38=0x%llx a40=0x%llx a48=0x%llx a50=0x%x q0=0x%llx q1=0x%llx q2=0x%llx q5=0x%llx q10=0x%llx",p16,(unsigned long long)A[ia],(unsigned long long)B[ib],(unsigned long long)C[ic],(unsigned long long)D[id],E[ie],(unsigned long long)rd64(o),(unsigned long long)rd64(o+8),(unsigned long long)rd64(o+0x10),(unsigned long long)rd64(o+0x28),(unsigned long long)rd64(o+0x50)); }
   if((cnt%40)==0) reopen();
  }
 }
 L(@"[done] tried=%d ok=%d",cnt,ok);
 CFRelease(s); if(g_c)IOServiceClose(g_c); IOObjectRelease(g_svc); L(@"=== done ===");
}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{
 self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;
 UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;tv.text=@"T80Grid\n";
 [vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;
 dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0),^{NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];gPath=[docs stringByAppendingPathComponent:@"grid.log"];gLog=[NSMutableString new];run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});
 return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
