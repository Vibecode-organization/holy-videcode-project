#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <Foundation/Foundation.h>
#import <string.h>
#import <stdlib.h>
#import <sys/mman.h>

static NSMutableString *gLog; static NSString *gPath;
static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt); NSString *s=[[NSString alloc] initWithFormat:fmt arguments:ap]; va_end(ap);
    [gLog appendString:s]; [gLog appendString:@"\n"];
    [gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
    NSLog(@"[iogpulk] %@",s);
}
static kern_return_t call(io_connect_t c, uint32_t sel, const uint64_t *sv, uint32_t sc,
                          void *si, size_t sis, uint64_t *so, uint32_t *soc, void *sout, size_t *sos) {
    return IOConnectCallMethod(c,sel,sv,sc,si,sis,so,soc,sout,sos);
}
static void run(void) {
    io_service_t svc=IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("AGXAcceleratorG14P"));
    if(!svc){L(@"no svc");return;}
    io_connect_t c=0; kern_return_t kr=IOServiceOpen(svc,mach_task_self(),1,&c); IOObjectRelease(svc);
    L(@"[open] 0x%x conn=0x%x",kr,c); if(kr)return;
    void *buf=mmap(NULL,0x4000,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANON,-1,0); memset(buf,0x41,0x4000);
    uint64_t keys[]={0,1,2,3,4,(uint64_t)(uintptr_t)buf,0x1500000000ULL};
    for(unsigned i=0;i<sizeof(keys)/sizeof(keys[0]);i++){
        uint64_t sv[1]={keys[i]}; uint8_t out[0x40]; memset(out,0xCC,sizeof(out)); size_t os=0x18;
        kr=call(c,19,sv,1,NULL,0,NULL,NULL,out,&os);
        L(@"[sel19] key=0x%llx -> 0x%x osz=0x%zx q0=0x%llx q1=0x%llx q2=0x%llx",
          (unsigned long long)keys[i],kr,os,(unsigned long long)*(uint64_t*)out,
          (unsigned long long)*(uint64_t*)(out+8),(unsigned long long)*(uint64_t*)(out+16));
    }
    {
        uint8_t out[0x40]; memset(out,0xCC,sizeof(out)); size_t os=0x30;
        kr=call(c,21,NULL,0,NULL,0,NULL,NULL,out,&os);
        L(@"[sel21] -> 0x%x osz=0x%zx %016llx %016llx %016llx %016llx %016llx %016llx",kr,os,
          (unsigned long long)*(uint64_t*)out,(unsigned long long)*(uint64_t*)(out+8),
          (unsigned long long)*(uint64_t*)(out+16),(unsigned long long)*(uint64_t*)(out+24),
          (unsigned long long)*(uint64_t*)(out+32),(unsigned long long)*(uint64_t*)(out+40));
    }
    uint64_t k2[][2]={{0,0},{1,0},{2,0},{(uint64_t)(uintptr_t)buf,0},{0,(uint64_t)(uintptr_t)buf},{0x1500000000ULL,0}};
    for(unsigned i=0;i<sizeof(k2)/sizeof(k2[0]);i++){
        uint64_t sv[2]={k2[i][0],k2[i][1]}; uint64_t so[2]={0,0}; uint32_t oc=2;
        kr=call(c,54,sv,2,NULL,0,so,&oc,NULL,NULL);
        L(@"[sel54] a=0x%llx b=0x%llx -> 0x%x q0=0x%llx q1=0x%llx",
          (unsigned long long)sv[0],(unsigned long long)sv[1],kr,
          (unsigned long long)so[0],(unsigned long long)so[1]);
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
    tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular]; tv.editable=NO; tv.text=@"IOGPULk\n";
    [vc.view addSubview:tv]; self.window.rootViewController=vc; [self.window makeKeyAndVisible];
    [UIApplication sharedApplication].idleTimerDisabled=YES;
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0),^{
        NSString *docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];
        gPath=[docs stringByAppendingPathComponent:@"iogpulk.log"]; gLog=[NSMutableString new]; run();
        dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});
    });
    return YES;
}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
