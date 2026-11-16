#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <Foundation/Foundation.h>
#import <string.h>
#import <stdlib.h>
static NSMutableString *gLog; static NSString *gPath;
static void L(NSString *fmt,...){va_list ap;va_start(ap,fmt);NSString*s=[[NSString alloc]initWithFormat:fmt arguments:ap];va_end(ap);[gLog appendString:s];[gLog appendString:@"\n"];[gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];NSLog(@"[sw] %@",s);}
static io_service_t g_svc;
static io_connect_t op(void){io_connect_t c=0;kern_return_t kr=IOServiceOpen(g_svc,mach_task_self(),1,&c);L(@"[open] 0x%x conn=0x%x",kr,c);return kr?0:c;}
static uint64_t rd64(const void*p){uint64_t v;memcpy(&v,p,8);return v;}
static void run(void){
 g_svc=IOServiceGetMatchingService(kIOMasterPortDefault,IOServiceMatching("AGXAcceleratorG14P"));L(@"[svc] 0x%x",g_svc);if(!g_svc)return;
 uint32_t strides[]={0x100,0x200,0x400,0x800,0x1000,0x2000,0x4000,0x30,0x40,0x18};
 for(int s=0;s<10;s++){
  uint32_t stride=strides[s]; io_connect_t c=op(); if(!c)continue;
  uint64_t nq_addr=0;uint32_t nq_id=0; 
  {uint64_t sv[2]={0x100,0x10};uint8_t so[0x10]={0};size_t sos=0x10;kern_return_t kr=IOConnectCallMethod(c,14,sv,2,NULL,0,NULL,NULL,so,&sos);nq_addr=rd64(so);nq_id=*(uint32_t*)(so+8);L(@"[%x sel14] 0x%x addr=0x%llx id=%u",stride,kr,(unsigned long long)nq_addr,nq_id);}
  uint64_t shm_addr=0;uint32_t shm_id=0;
  {uint64_t sv[2]={0x4000,0};uint8_t so[0x10]={0};size_t sos=0x10;kern_return_t kr=IOConnectCallMethod(c,12,sv,2,NULL,0,NULL,NULL,so,&sos);shm_addr=rd64(so);shm_id=*(uint32_t*)(so+0xc);L(@"[%x sel12] 0x%x addr=0x%llx id=%u",stride,kr,(unsigned long long)shm_addr,shm_id);}
  if(!shm_addr||!nq_id){IOServiceClose(c);continue;}
  volatile uint32_t*sp=(volatile uint32_t*)(uintptr_t)shm_addr;sp[0]=8;sp[1]=8;for(int i=2;i<16;i++)sp[i]=0;
  uint64_t qid=0;{uint64_t sv[2]={0,0},so[2]={0};uint32_t oc=2;kern_return_t kr=IOConnectCallMethod(c,42,sv,2,NULL,0,so,&oc,NULL,NULL);qid=so[0];L(@"[%x sel42] 0x%x qid=%llu",stride,kr,(unsigned long long)qid);}
  if(!qid){IOServiceClose(c);continue;}
  kern_return_t kr=IOConnectCallMethod(c,44,(uint64_t[]){qid,nq_id},2,NULL,0,NULL,NULL,NULL,NULL);L(@"[%x sel44] 0x%x",stride,kr);
  uint64_t cbid=0;{uint64_t sv[1]={qid},so[2]={0};uint32_t oc=2;kr=IOConnectCallMethod(c,46,sv,1,NULL,0,so,&oc,NULL,NULL);cbid=so[0];L(@"[%x sel46] 0x%x cbid=%llu",stride,kr,(unsigned long long)cbid);}
  if(!cbid){IOServiceClose(c);continue;}
  uint8_t*e=calloc(1,stride);if(stride>=0x18){*(uint32_t*)(e+0)=shm_id;*(uint32_t*)(e+4)=(uint32_t)cbid;*(uint64_t*)(e+8)=shm_addr;*(uint32_t*)(e+0x10)=0;}
  uint64_t sv[4]={qid,0,1,stride};kr=IOConnectCallMethod(c,45,sv,4,e,stride,NULL,NULL,NULL,NULL);
  L(@"[%x sel45] 0x%x",stride,kr);free(e);
  IOServiceClose(c);
 }
 IOObjectRelease(g_svc);L(@"=== done ===");
}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{
 self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;
 UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;tv.text=@"S45Sweep\n";
 [vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;
 dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0),^{NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];gPath=[docs stringByAppendingPathComponent:@"sw.log"];gLog=[NSMutableString new];run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});
 return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
