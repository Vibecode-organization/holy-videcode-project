#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <Foundation/Foundation.h>
#import <string.h>
#import <stdlib.h>
#import <mach/mach.h>
static NSMutableString *gLog; static NSString *gPath;
static void L(NSString *fmt,...){va_list ap;va_start(ap,fmt);NSString*s=[[NSString alloc]initWithFormat:fmt arguments:ap];va_end(ap);[gLog appendString:s];[gLog appendString:@"\n"];[gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];NSLog(@"[sc] %@",s);}
static uint64_t rd64(const void*p){uint64_t v;memcpy(&v,p,8);return v;}
static void scan(const char*tag,const uint8_t*b,size_t n){for(size_t i=0;i+8<=n;i+=8){uint64_t q=rd64(b+i);if((q&0xfffffff000000000ULL)==0xfffffff000000000ULL||(q>=0xffffffe000000000ULL&&q<0xffffffff00000000ULL))L(@"[HIT %s] +0x%zx = 0x%llx",tag,i,(unsigned long long)q);}}
static io_connect_t C;
static void scalar(const char*tag,uint32_t sel,uint64_t*a,int n,uint32_t nout){
 uint64_t out[16]; for(int i=0;i<16;i++)out[i]=0xBBBBBBBBBBBBBBBBULL; uint32_t oc=nout;
 kern_return_t kr=IOConnectCallScalarMethod(C,sel,a,n,out,&oc);
 L(@"[%s sel%u] kr=0x%x oc=%u",tag,sel,kr,oc);
 for(uint32_t i=0;i<oc&&i<8;i++)L(@"[%s sel%u] out[%u]=0x%llx",tag,sel,i,(unsigned long long)out[i]);
}
static void structm(const char*tag,uint32_t sel,const void*in,size_t ins,size_t outsz){
 uint8_t out[0x800]; memset(out,0xAA,sizeof(out)); size_t os=outsz;
 kern_return_t kr=IOConnectCallStructMethod(C,sel,in,ins,out,&os);
 L(@"[%s sel%u] kr=0x%x osz=0x%zx",tag,sel,kr,os);
 if(!kr){int qn=(int)(os<0x100?os:0x100)/8;for(int i=0;i<qn;i++)L(@"[%s sel%u] q%d=0x%llx",tag,sel,i,(unsigned long long)rd64(out+i*8));scan(tag,out,os);}
}
static void run(void){
 io_service_t svc=IOServiceGetMatchingService(kIOMasterPortDefault,IOServiceMatching("AGXAcceleratorG14P"));
 L(@"[svc] 0x%x",svc); if(!svc)return;
 kern_return_t kr=IOServiceOpen(svc,mach_task_self(),1,&C); IOObjectRelease(svc);
 L(@"[open] 0x%x",kr); if(kr)return;
 vm_address_t buf=0; vm_allocate(mach_task_self(),&buf,0x4000,VM_FLAGS_ANYWHERE);
 uint64_t*p=(uint64_t*)buf; for(int i=0;i<0x800;i++)p[i]=0x5152535400000000ULL|i;
 uint8_t in[0x100]; memset(in,0,sizeof(in)); *(uint32_t*)in=0x40; *(uint64_t*)(in+0x38)=buf; *(uint64_t*)(in+0x40)=0x4000; *(uint32_t*)(in+0x50)=0x4000;
 uint8_t out[0x1000]; memset(out,0xAA,sizeof(out)); size_t os=0x1000;
 kr=IOConnectCallStructMethod(C,8,in,0x100,out,&os);
 uint32_t rid=*(uint32_t*)(out+0x24);
 L(@"[res] kr=0x%x rid=%u q0=0x%llx q3=0x%llx q10=0x%llx",kr,rid,(unsigned long long)rd64(out),(unsigned long long)rd64(out+0x18),(unsigned long long)rd64(out+0x50));
 /* scalar getters */
 uint64_t a1[1]={rid}, a2[2]={rid,0}, a2b[2]={0,rid}, a3[3]={rid,0x100,0x200};
 scalar("s19",19,a1,1,3);
 scalar("s23",23,NULL,0,1);
 scalar("s28",28,NULL,0,2);
 scalar("s31e0",31,(uint64_t[]){0},1,2);
 scalar("s31e1",31,(uint64_t[]){1},1,2);
 scalar("s31rid",31,a1,1,2);
 scalar("s34",34,a1,1,1);
 scalar("s36",36,a3,3,1);
 scalar("s40",40,a1,1,2);
 scalar("s54a",54,a2,2,1);
 scalar("s54b",54,a2b,2,1);
 /* struct getters */
 structm("st3",3,NULL,0,8);
 structm("st16",16,NULL,0,8);
 structm("st17",17,NULL,0,4);
 structm("st19",19,(void*)a1,8,24);
 structm("st21",21,NULL,0,48);
 structm("st29",29,(void*)a1,8,0);
 structm("st39",39,(uint8_t[24]){0},24,0x10);
 /* sel2 full 0x218 */
 structm("st2",2,NULL,0,0x218);
 IOServiceClose(C); L(@"=== done ===");
}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{
 self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;
 UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;tv.text=@"IOGPUScalars\n";
 [vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;
 dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0),^{NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];gPath=[docs stringByAppendingPathComponent:@"sc.log"];gLog=[NSMutableString new];run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});
 return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
