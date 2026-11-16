#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <Foundation/Foundation.h>
#import <string.h>
#import <stdlib.h>
#import <sys/mman.h>
#import <IOSurface/IOSurfaceRef.h>

static NSMutableString *gLog; static NSString *gPath;
static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt); NSString *s=[[NSString alloc] initWithFormat:fmt arguments:ap]; va_end(ap);
    [gLog appendString:s]; [gLog appendString:@"\n"];
    [gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
    NSLog(@"[iogpufuzz] %@",s);
}
static kern_return_t call(io_connect_t c,uint32_t sel,const uint64_t *sv,uint32_t sc,
                          void *si,size_t sis,uint64_t *so,uint32_t *soc,void *sout,size_t *sos){
    return IOConnectCallMethod(c,sel,sv,sc,si,sis,so,soc,sout,sos);
}
struct T { uint32_t id; uint64_t a,b,c,d; const char *name; };
static struct T cases[1]; // filled at runtime
static void run(void){
    io_service_t svc=IOServiceGetMatchingService(kIOMasterPortDefault,IOServiceMatching("AGXAcceleratorG14P"));
    if(!svc){L(@"no svc");return;}
    io_connect_t c=0; kern_return_t kr=IOServiceOpen(svc,mach_task_self(),1,&c); IOObjectRelease(svc);
    L(@"[open] 0x%x",kr); if(kr)return;
    uint64_t nq=0; uint32_t nqid=0;
    { uint64_t sv[2]={0x100,0x10}; uint8_t o[0x10]; size_t os=0x10;
      kr=call(c,14,sv,2,NULL,0,NULL,NULL,o,&os); nq=*(uint64_t*)o; nqid=*(uint32_t*)(o+8);
      L(@"[sel14] 0x%x id=%u",kr,nqid); }
    uint64_t shm=0; uint32_t shmid=0;
    { uint64_t sv[2]={0x4000,0}; uint8_t o[0x10]; size_t os=0x10;
      kr=call(c,12,sv,2,NULL,0,NULL,NULL,o,&os); shm=*(uint64_t*)o; shmid=*(uint32_t*)(o+0xc);
      L(@"[sel12] 0x%x addr=0x%llx id=%u",kr,(unsigned long long)shm,shmid); }
    uint64_t q=0;
    { uint64_t sv[2]={0,0}; uint64_t so[2]={0,0}; uint32_t oc=2;
      kr=call(c,42,sv,2,NULL,0,so,&oc,NULL,NULL); q=so[0];
      L(@"[sel42] 0x%x qid=%llu",kr,(unsigned long long)q); }
    if(!q||!shm){L(@"no q/shm");IOServiceClose(c);return;}
    { uint64_t sv[2]={q,nqid}; kr=call(c,44,sv,2,NULL,0,NULL,NULL,NULL,NULL); L(@"[sel44] 0x%x",kr); }

    NSDictionary *props=@{(__bridge NSString*)kIOSurfaceWidth:@1024,(__bridge NSString*)kIOSurfaceHeight:@1,
        (__bridge NSString*)kIOSurfaceBytesPerElement:@4,(__bridge NSString*)kIOSurfaceBytesPerRow:@4096,
        (__bridge NSString*)kIOSurfaceAllocSize:@0x1000};
    IOSurfaceRef surf=IOSurfaceCreate((__bridge CFDictionaryRef)props);
    uint64_t rid=0,gpuVA=0,span=0;
    if(surf){
        uint32_t sid=IOSurfaceGetID(surf);
        uint8_t *sin=calloc(1,0x100),*sout=calloc(1,0x1000); size_t sos=0x1000;
        *(uint32_t*)(sin)=0x82; *(uint32_t*)(sin+0x38)=sid;
        kern_return_t k8=call(c,8,NULL,0,sin,0x100,NULL,NULL,sout,&sos);
        gpuVA=*(uint64_t*)sout; rid=*(uint64_t*)(sout+0x30); span=*(uint64_t*)(sout+0x28);
        L(@"[sel8] 0x%x rid=0x%llx gpuVA=0x%llx span=0x%llx",k8,
          (unsigned long long)rid,(unsigned long long)gpuVA,(unsigned long long)span);
        free(sin); free(sout);
    }
    cases[0].id=(uint32_t)rid; cases[0].a=gpuVA; cases[0].b=span; cases[0].c=0; cases[0].d=0;
    cases[0].name="valid_res";

    for(unsigned t=0;t<sizeof(cases)/sizeof(cases[0]);t++){
        uint64_t cb=0;
        { uint64_t sv[1]={q}; uint64_t so[2]={0,0}; uint32_t oc=2;
          kr=call(c,46,sv,1,NULL,0,so,&oc,NULL,NULL); cb=so[0]; }
        if(!cb){L(@"[%s] no cb",cases[t].name);continue;}
        volatile uint32_t *sp=(volatile uint32_t*)shm;
        sp[0]=8; sp[1]=8+0x38;
        sp[2]=0; sp[3]=0x38;
        sp[4]=cases[t].id;
        *(volatile uint64_t*)(sp+6)=cases[t].a;
        *(volatile uint64_t*)(sp+8)=cases[t].b;
        *(volatile uint64_t*)(sp+10)=cases[t].c;
        *(volatile uint64_t*)(sp+12)=cases[t].d;
        uint8_t *e=calloc(1,8+0x18); *(uint32_t*)e=1;
        *(uint32_t*)(e+8)=shmid; *(uint32_t*)(e+12)=(uint32_t)cb;
        L(@"[case %s] cb=%llu id=0x%x a=0x%llx b=0x%llx c=0x%llx d=0x%llx",
          cases[t].name,(unsigned long long)cb,cases[t].id,
          (unsigned long long)cases[t].a,(unsigned long long)cases[t].b,
          (unsigned long long)cases[t].c,(unsigned long long)cases[t].d);
        if(surf){IOSurfaceLock(surf,0,NULL);uint8_t*b=(uint8_t*)IOSurfaceGetBaseAddress(surf);memset(b,0xAA,0x1000);IOSurfaceUnlock(surf,0,NULL);}
        uint64_t sv[1]={q};
        kern_return_t k45=call(c,45,sv,1,e,8+0x18,NULL,NULL,NULL,NULL);
        kern_return_t k49=call(c,49,sv,1,NULL,0,NULL,NULL,NULL,NULL);
        kern_return_t k50=call(c,50,sv,1,NULL,0,NULL,NULL,NULL,NULL);
        uint64_t v0=0,v1=0;
        if(surf){IOSurfaceLock(surf,0,NULL);uint8_t*b=(uint8_t*)IOSurfaceGetBaseAddress(surf);v0=*(uint64_t*)b;v1=*(uint64_t*)(b+8);IOSurfaceUnlock(surf,0,NULL);}
        L(@"[case %s] submit=0x%x io=0x%x comp=0x%x buf=%016llx %016llx",cases[t].name,k45,k49,k50,
          (unsigned long long)v0,(unsigned long long)v1);
        free(e);
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
    tv.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular]; tv.editable=NO; tv.text=@"IOGPUFuzz\n";
    [vc.view addSubview:tv]; self.window.rootViewController=vc; [self.window makeKeyAndVisible];
    [UIApplication sharedApplication].idleTimerDisabled=YES;
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH,0),^{
        NSString *docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];
        gPath=[docs stringByAppendingPathComponent:@"iogpufuzz.log"]; gLog=[NSMutableString new]; run();
        dispatch_async(dispatch_get_main_queue(),^{tv.text=gLog;});
    });
    return YES;
}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]));}}
