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
    NSLog(@"[agxsubmit] %@",s);
}
static kern_return_t call(io_connect_t c,uint32_t sel,const uint64_t *sv,uint32_t sc,
                          void *si,size_t sis,uint64_t *so,uint32_t *soc,void *sout,size_t *sos){
    return IOConnectCallMethod(c,sel,sv,sc,si,sis,so,soc,sout,sos);
}
static void run(void){
    io_service_t svc=IOServiceGetMatchingService(kIOMasterPortDefault,IOServiceMatching("AGXAcceleratorG14P"));
    if(!svc){L(@"no svc");return;}
    io_connect_t c=0; kern_return_t kr=IOServiceOpen(svc,mach_task_self(),1,&c); IOObjectRelease(svc);
    L(@"[open] 0x%x",kr); if(kr)return;

    uint8_t qin[0x410]; memset(qin,0,sizeof(qin));
    *(uint32_t*)(qin+0x404)=1;
    uint8_t qout[0x10]; memset(qout,0,sizeof(qout)); size_t qos=sizeof(qout);
    kr=call(c,6,NULL,0,qin,0x410,NULL,NULL,qout,&qos);
    L(@"[sel6] si=0x410 -> 0x%x osz=0x%zx q0=0x%llx q1=0x%llx",kr,qos,
      (unsigned long long)*(uint64_t*)qout,(unsigned long long)*(uint64_t*)(qout+8));
    if(kr){ memset(qin,0,sizeof(qin)); qos=sizeof(qout); kr=call(c,6,NULL,0,qin,0x408,NULL,NULL,qout,&qos);
        L(@"[sel6] si=0x408 -> 0x%x osz=0x%zx q0=0x%llx q1=0x%llx",kr,qos,
          (unsigned long long)*(uint64_t*)qout,(unsigned long long)*(uint64_t*)(qout+8)); }
    uint32_t qid=*(uint32_t*)qout;
    if(!qid){L(@"no qid");IOServiceClose(c);return;}

    NSDictionary *props=@{(__bridge NSString*)kIOSurfaceWidth:@1024,(__bridge NSString*)kIOSurfaceHeight:@4,
        (__bridge NSString*)kIOSurfaceBytesPerElement:@4,(__bridge NSString*)kIOSurfaceBytesPerRow:@4096,
        (__bridge NSString*)kIOSurfaceAllocSize:@0x4000};
    IOSurfaceRef surf=IOSurfaceCreate((__bridge CFDictionaryRef)props);
    if(!surf){L(@"no surf");IOServiceClose(c);return;}
    uint32_t sid=IOSurfaceGetID(surf);
    uint8_t *sin=calloc(1,0x100),*sout=calloc(1,0x1000); size_t sos=0x1000;
    *(uint32_t*)(sin)=0x82; *(uint32_t*)(sin+0x38)=sid;
    kr=call(c,8,NULL,0,sin,0x100,NULL,NULL,sout,&sos);
    uint64_t gpuVA=*(uint64_t*)sout, rid=*(uint64_t*)(sout+0x30), span=*(uint64_t*)(sout+0x28);
    L(@"[sel8] 0x%x gpuVA=0x%llx rid=0x%llx span=0x%llx",kr,
      (unsigned long long)gpuVA,(unsigned long long)rid,(unsigned long long)span);
    for(int i=0;i<16;i++) L(@"[sel8q] q%d=0x%llx",i,(unsigned long long)*(uint64_t*)(sout+i*8));
    if(!gpuVA){CFRelease(surf);IOServiceClose(c);return;}

    IOSurfaceLock(surf,0,NULL); memset(IOSurfaceGetBaseAddress(surf),0xAA,0x4000); IOSurfaceUnlock(surf,0,NULL);

    // create type 0x80 sysmemory resource with a command-list buffer
    uint64_t sm_gpuva=0;
    void *cbuf=mmap(NULL,0x4000,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANON,-1,0);
    memset(cbuf,0,0x4000);
    uint32_t smid=0;
    {
        uint8_t sin2[0x100]; memset(sin2,0,sizeof(sin2));
        *(uint32_t*)(sin2+0x00)=0x80;
        *(uint64_t*)(sin2+0x38)=(uint64_t)(uintptr_t)cbuf+0x4000;
        *(uint64_t*)(sin2+0x40)=(uint64_t)(uintptr_t)cbuf;
        *(uint64_t*)(sin2+0x48)=0x4000;
        uint8_t sout2[0x1000]; memset(sout2,0,sizeof(sout2)); size_t sos2=sizeof(sout2);
        kern_return_t k8b=call(c,8,NULL,0,sin2,0x100,NULL,NULL,sout2,&sos2);
        smid=*(uint32_t*)(sout2+0x24);
        sm_gpuva=*(uint64_t*)sout2;
        L(@"[sel8 type80] 0x%x osz=0x%zx smid=%u q0=0x%llx q4=0x%llx",k8b,sos2,smid,
          (unsigned long long)sm_gpuva,(unsigned long long)*(uint64_t*)(sout2+0x20));
    }
    // sel12 AGXDebugBufferShmem (type 2) -> id in dev+0x78
    uint64_t dbg_addr=0; uint32_t dbg_id=0;
    {
        uint64_t sv[2]={0x4000,2}; uint8_t o[0x10]; memset(o,0,sizeof(o)); size_t os=0x10;
        kern_return_t k12=call(c,12,sv,2,NULL,0,NULL,NULL,o,&os);
        dbg_addr=*(uint64_t*)o; dbg_id=*(uint32_t*)(o+0xc);
        L(@"[sel12 type2] 0x%x addr=0x%llx len=0x%x id=%u",k12,
          (unsigned long long)dbg_addr,*(uint32_t*)(o+8),dbg_id);
    }
    uint32_t rid2=*(uint32_t*)(sout+0x24);
    L(@"[id24] rid2=%u",rid2);
    for(int t=0;t<5;t++){
        uint8_t rec[0x40]; memset(rec,0,sizeof(rec));
        if(t==0){ *(uint64_t*)(rec+0x18)=sm_gpuva; *(uint32_t*)(rec+0x20)=0; }
        if(t==1){ *(uint64_t*)(rec+0x18)=gpuVA; *(uint32_t*)(rec+0x20)=0; }
        if(t==2){ *(uint64_t*)(rec+0x18)=sm_gpuva; *(uint32_t*)(rec+0x20)=dbg_id; }
        if(t==3){ *(uint64_t*)(rec+0x18)=gpuVA+0x1000; *(uint32_t*)(rec+0x20)=0; }
        if(t==4){ *(uint64_t*)(rec+0x18)=sm_gpuva; *(uint32_t*)(rec+0x20)=smid; }
        *(uint32_t*)(rec+0x30)=0x41424344;
        *(uint64_t*)(rec+0x38)=0;
        uint64_t s25[4]={qid,0,1,0x40}; uint64_t out=0; uint32_t oc=1;
        kr=call(c,25,s25,4,rec,0x40,&out,&oc,NULL,NULL);
        L(@"[sel25 t%d] rec18=0x%llx id=%u -> 0x%x out=0x%llx",t,
          (unsigned long long)*(uint64_t*)(rec+0x18),*(uint32_t*)(rec+0x20),kr,
          (unsigned long long)out);
    }
    free(sin); free(sout);
    CFRelease(surf); IOServiceClose(c); L(@"=== done ===");
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
    tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular]; tv.editable=NO; tv.text=@"AGXSubmit\n";
    [vc.view addSubview:tv]; self.window.rootViewController=vc; [self.window makeKeyAndVisible];
    [UIApplication sharedApplication].idleTimerDisabled=YES;
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0),^{
        NSString *docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];
        gPath=[docs stringByAppendingPathComponent:@"agxsubmit.log"]; gLog=[NSMutableString new]; run();
        dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});
    });
    return YES;
}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
