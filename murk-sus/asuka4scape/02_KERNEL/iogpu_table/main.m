#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <Foundation/Foundation.h>
#import <IOSurface/IOSurfaceRef.h>
#import <string.h>
#import <stdlib.h>
#import <sys/mman.h>

static NSMutableString *gLog; static NSString *gPath;
static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt); NSString *s=[[NSString alloc] initWithFormat:fmt arguments:ap]; va_end(ap);
    [gLog appendString:s]; [gLog appendString:@"\n"];
    [gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
    NSLog(@"[iogputbl] %@",s);
}
static kern_return_t call(io_connect_t c, uint32_t sel, const uint64_t *sv, uint32_t sc,
                          void *si, size_t sis, uint64_t *so, uint32_t *soc, void *sout, size_t *sos) {
    return IOConnectCallMethod(c,sel,sv,sc,si,sis,so,soc,sout,sos);
}
static void dump(const char *tag, uint64_t va, int n) {
    L(@"[tbl %s] va=0x%llx",tag,(unsigned long long)va);
    for (int i=0;i<n;i+=3) {
        NSMutableString *s=[NSMutableString string];
        for (int j=0;j<3 && i+j<n;j++)
            [s appendFormat:@"[%02d]=%016llx ",i+j,(unsigned long long)*(volatile uint64_t*)(va+(i+j)*8)];
        L(@"[tbl %s] %@",tag,s);
    }
}
static void run(void) {
    io_service_t svc=IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("AGXAcceleratorG14P"));
    if(!svc){L(@"no svc");return;}
    io_connect_t c=0; kern_return_t kr=IOServiceOpen(svc,mach_task_self(),1,&c); IOObjectRelease(svc);
    L(@"[open] 0x%x",kr); if(kr)return;

    NSDictionary *props=@{(__bridge NSString*)kIOSurfaceWidth:@1024,(__bridge NSString*)kIOSurfaceHeight:@1,
        (__bridge NSString*)kIOSurfaceBytesPerElement:@4,(__bridge NSString*)kIOSurfaceBytesPerRow:@4096,
        (__bridge NSString*)kIOSurfaceAllocSize:@0x1000};
    IOSurfaceRef surf=IOSurfaceCreate((__bridge CFDictionaryRef)props);
    uint64_t entry=0, gpuVA=0, rid=0;
    if(surf){
        uint32_t sid=IOSurfaceGetID(surf);
        uint8_t *sin=calloc(1,0x100),*sout=calloc(1,0x1000); size_t sos=0x1000;
        *(uint32_t*)(sin)=0x82; *(uint32_t*)(sin+0x38)=sid;
        kr=call(c,8,NULL,0,sin,0x100,NULL,NULL,sout,&sos);
        gpuVA=*(uint64_t*)sout; entry=*(uint64_t*)(sout+0x10); rid=*(uint64_t*)(sout+0x30);
        L(@"[sel8] -> 0x%x gpuVA=0x%llx entry=0x%llx rid=0x%llx span=0x%llx",kr,
          (unsigned long long)gpuVA,(unsigned long long)entry,(unsigned long long)rid,
          (unsigned long long)*(uint64_t*)(sout+0x28));
        free(sin); free(sout);
    }
    if(entry) dump("before",entry,24);

    uint64_t nq_addr=0; uint32_t nq_id=0, shm_id=0;
    { uint64_t sv[2]={0x100,0x10}; uint8_t o[0x10]; size_t os=0x10;
      kr=call(c,14,sv,2,NULL,0,NULL,NULL,o,&os); nq_addr=*(uint64_t*)o; nq_id=*(uint32_t*)(o+8);
      L(@"[sel14] 0x%x addr=0x%llx id=%u",kr,(unsigned long long)nq_addr,nq_id); }
    { uint64_t sv[2]={0x4000,0}; uint8_t o[0x10]; size_t os=0x10;
      kr=call(c,12,sv,2,NULL,0,NULL,NULL,o,&os); shm_id=*(uint32_t*)(o+0xc);
      L(@"[sel12] 0x%x addr=0x%llx len=0x%x id=%u",kr,(unsigned long long)*(uint64_t*)o,
        *(uint32_t*)(o+8),shm_id); }
    uint64_t qid=0;
    { uint64_t sv[2]={0,0}; uint64_t so[2]={0,0}; uint32_t oc=2;
      kr=call(c,42,sv,2,NULL,0,so,&oc,NULL,NULL); qid=so[0];
      L(@"[sel42] 0x%x qid=%llu q1=0x%llx",kr,(unsigned long long)qid,(unsigned long long)so[1]); }
    if(qid){ uint64_t sv[2]={qid,nq_id}; kr=call(c,44,sv,2,NULL,0,NULL,NULL,NULL,NULL);
      L(@"[sel44] 0x%x",kr); }
    uint64_t cbid=0;
    if(qid){ uint64_t sv[1]={qid}; uint64_t so[2]={0,0}; uint32_t oc=2;
      kr=call(c,46,sv,1,NULL,0,so,&oc,NULL,NULL); cbid=so[0];
      L(@"[sel46] 0x%x cb=%llu q1=0x%llx",kr,(unsigned long long)cbid,(unsigned long long)so[1]); }

    if(entry) dump("after",entry,24);
    // scan around table for new small values
    if(entry){
        uint64_t base=entry & ~0x3fffULL;
        for(int i=0;i<0x40;i++){
            uint64_t a=base+i*0x100;
            uint64_t v0=*(volatile uint64_t*)(a);
            if(v0==0x1500000000ULL || (v0>0x1000 && v0<0x100000000ULL))
                L(@"[scan] 0x%llx = 0x%llx",(unsigned long long)a,(unsigned long long)v0);
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
    tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular]; tv.editable=NO; tv.text=@"IOGPUTbl\n";
    [vc.view addSubview:tv]; self.window.rootViewController=vc; [self.window makeKeyAndVisible];
    [UIApplication sharedApplication].idleTimerDisabled=YES;
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0),^{
        NSString *docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];
        gPath=[docs stringByAppendingPathComponent:@"iogputbl.log"]; gLog=[NSMutableString new]; run();
        dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});
    });
    return YES;
}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
