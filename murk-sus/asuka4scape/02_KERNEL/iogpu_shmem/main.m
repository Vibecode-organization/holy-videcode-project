#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <Foundation/Foundation.h>
#import <string.h>
#import <stdlib.h>
#import <mach/mach.h>
#import <mach/vm_region.h>
#import <sys/mman.h>
#import <IOSurface/IOSurfaceRef.h>

static NSMutableString *gLog; static NSString *gPath;
static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    [gLog appendString:s]; [gLog appendString:@"\n"];
    [gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
    NSLog(@"[iogpushmem] %@", s);
}
static kern_return_t call(io_connect_t c, uint32_t sel, const uint64_t *sv, uint32_t sc,
                          void *si, size_t sis, uint64_t *so, uint32_t *soc, void *sout, size_t *sos) {
    return IOConnectCallMethod(c, sel, sv, sc, si, sis, so, soc, sout, sos);
}
static void snap(const char *tag) {
    vm_address_t addr = 0x100000000ULL;
    int n = 0;
    while (addr < 0x120000000ULL && n < 200) {
        vm_size_t size = 0; vm_region_basic_info_data_64_t bi;
        mach_port_t obj = 0; mach_msg_type_number_t cnt = VM_REGION_BASIC_INFO_COUNT_64;
        kern_return_t kr = vm_region_64(mach_task_self(), &addr, &size, VM_REGION_BASIC_INFO_64,
                                        (vm_region_info_t)&bi, &cnt, &obj);
        if (kr != KERN_SUCCESS) break;
        if (size <= 0x400000 && (bi.protection & VM_PROT_WRITE))
            L(@"[vm %s] 0x%llx size=0x%llx prot=%d", tag,
              (unsigned long long)addr, (unsigned long long)size, bi.protection);
        if (obj) mach_port_deallocate(mach_task_self(), obj);
        addr += size;
        n++;
    }
}

static void run(void) {
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("AGXAcceleratorG14P"));
    if (!svc) { L(@"no AGX svc"); return; }
    io_connect_t c=0; kern_return_t kr=IOServiceOpen(svc, mach_task_self(), 1, &c);
    L(@"[open] 0x%x conn=0x%x", kr, c); IOObjectRelease(svc);
    if (kr) return;

    uint64_t nq_addr=0; uint32_t nq_id=0;
    {
        uint64_t sv[2]={0x100,0x10}; uint8_t so[0x10]; memset(so,0,sizeof(so)); size_t sos=sizeof(so);
        kr=call(c,14,sv,2,NULL,0,NULL,NULL,so,&sos);
        nq_addr=*(uint64_t*)so; nq_id=*(uint32_t*)(so+8);
        L(@"[sel14] -> 0x%x addr=0x%llx id=%u",kr,(unsigned long long)nq_addr,nq_id);
    }
    if(!nq_id){ L(@"no nq"); IOServiceClose(c); return; }

    uint64_t shm_addr=0; uint32_t shm_id=0;
    for (int ty=0; ty<4; ty++) {
        uint32_t types[4] = {0,2,3,0x100};
        uint64_t sv[2] = {0x4000, types[ty]};
        uint8_t so[0x10]; memset(so,0,sizeof(so)); size_t sos=sizeof(so);
        kr=call(c,12,sv,2,NULL,0,NULL,NULL,so,&sos);
        L(@"[sel12] size=0x4000 type=0x%x -> 0x%x osz=0x%zx addr=0x%llx len=0x%x id=%u",
          types[ty],kr,sos,(unsigned long long)*(uint64_t*)so,
          *(uint32_t*)(so+8),*(uint32_t*)(so+0xc));
        if (ty==0 && !kr && *(uint64_t*)so) { shm_addr=*(uint64_t*)so; shm_id=*(uint32_t*)(so+0xc); }
    }
    L(@"[shm] addr=0x%llx id=%u",(unsigned long long)shm_addr,shm_id);


    snap("after_sel14");
    // --- notification queue event tests ---
    {
        volatile uint64_t *q=(volatile uint64_t*)(uintptr_t)nq_addr;
        q[0]=0;
        q[1]=0xdeadbeefcafebabeULL;
        for (uint32_t id=0; id<=4; id++) {
            uint64_t sv[1]={id}; uint64_t so[2]={0x11111111,0x22222222}; uint32_t oc=2;
            kr=call(c,31,sv,1,NULL,0,so,&oc,NULL,NULL);
            L(@"[sel31] id=%u -> 0x%x oc=%u o0=0x%llx o1=0x%llx",id,kr,oc,
              (unsigned long long)so[0],(unsigned long long)so[1]);
        }
        for (uint32_t id=0; id<=4; id++) {
            uint64_t sv[2]={id,0xfeedfacecafebeefULL};
            kr=call(c,30,sv,2,NULL,0,NULL,NULL,NULL,NULL);
            L(@"[sel30] id=%u -> 0x%x",id,kr);
        }
        for (uint32_t id=0; id<=4; id++) {
            uint64_t sv[1]={id}; uint64_t so[2]={0,0}; uint32_t oc=2;
            kr=call(c,31,sv,1,NULL,0,so,&oc,NULL,NULL);
            L(@"[sel31b] id=%u -> 0x%x o0=0x%llx o1=0x%llx",id,kr,
              (unsigned long long)so[0],(unsigned long long)so[1]);
        }
        L(@"[nq2] %016llx %016llx %016llx %016llx",
          (unsigned long long)q[0],(unsigned long long)q[1],
          (unsigned long long)q[2],(unsigned long long)q[3]);
    }

    void *buf=mmap(NULL,0x4000,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANON,-1,0);
    memset(buf,0,0x4000);
    // valid empty command list: start=8 end=8
    *(uint32_t*)buf=8; *(uint32_t*)((char*)buf+4)=8;

    uint64_t qid=0;
    {
        uint64_t sv[2]={0,0}; uint64_t so[2]={0,0}; uint32_t oc=2;
        kr=call(c,42,sv,2,NULL,0,so,&oc,NULL,NULL);
        if(!kr) qid=so[0];
        L(@"[sel42] type0 -> 0x%x qid=%llu q1=0x%llx",kr,(unsigned long long)qid,(unsigned long long)so[1]);
    }
    if(!qid){ L(@"no qid"); IOServiceClose(c); return; }
    uint64_t sv44[2]={qid,nq_id};
    kr=call(c,44,sv44,2,NULL,0,NULL,NULL,NULL,NULL);
    L(@"[sel44] q=%llu nq=%u -> 0x%x",(unsigned long long)qid,nq_id,kr);

    uint64_t cbid=0;
    {
        uint64_t sv[1]={qid}; uint64_t so[2]={0,0}; uint32_t oc=2;
        kr=call(c,46,sv,1,NULL,0,so,&oc,NULL,NULL);
        L(@"[sel46] -> 0x%x q0=0x%llx q1=0x%llx",kr,
          (unsigned long long)so[0],(unsigned long long)so[1]);
        if(!kr) cbid=so[0];
    }
    if(!cbid){ L(@"no cb"); IOServiceClose(c); return; }

    snap("after_sel46");
    // First submit with valid empty header
    if (shm_addr) {
        volatile uint32_t *sp=(volatile uint32_t*)shm_addr;
        NSDictionary *props = @{(__bridge NSString*)kIOSurfaceWidth:@1024,
                                (__bridge NSString*)kIOSurfaceHeight:@1,
                                (__bridge NSString*)kIOSurfaceBytesPerElement:@4,
                                (__bridge NSString*)kIOSurfaceBytesPerRow:@4096,
                                (__bridge NSString*)kIOSurfaceAllocSize:@0x1000};
        IOSurfaceRef surf = IOSurfaceCreate((__bridge CFDictionaryRef)props);
        uint64_t gpuVA=0;
        if (surf) {
            uint32_t sid=IOSurfaceGetID(surf);
            uint8_t *sin=calloc(1,0x100); uint8_t *sout=calloc(1,0x1000); size_t sos=0x1000;
            *(uint32_t*)(sin)=0x82; *(uint32_t*)(sin+0x38)=sid;
            kern_return_t k8=call(c,8,NULL,0,sin,0x100,NULL,NULL,sout,&sos);
            gpuVA=*(uint64_t*)sout;
            L(@"[surf] id=%u sel8=0x%x gpuVA=0x%llx span=0x%llx",sid,k8,
              (unsigned long long)gpuVA,(unsigned long long)*(uint64_t*)(sout+0x28));
            free(sin); free(sout);
        }
        if (surf && gpuVA) {
            IOSurfaceLock(surf,0,NULL); uint8_t *base=(uint8_t*)IOSurfaceGetBaseAddress(surf); memset(base,0,0x1000); IOSurfaceUnlock(surf,0,NULL);
            sp[0]=8; sp[1]=0x20; sp[2]=1; sp[3]=0x18;
            *(volatile uint64_t*)(sp+4)=gpuVA; sp[6]=1; sp[7]=0;
            uint64_t sv[1]={qid};
            uint8_t *e=calloc(1,8+0x18); *(uint32_t*)e=1;
            *(uint32_t*)(e+8)=shm_id; *(uint32_t*)(e+12)=(uint32_t)cbid;
            kern_return_t k45=call(c,45,sv,1,e,8+0x18,NULL,NULL,NULL,NULL);
            kern_return_t k49=call(c,49,sv,1,NULL,0,NULL,NULL,NULL,NULL);
            kern_return_t k50=call(c,50,sv,1,NULL,0,NULL,NULL,NULL,NULL);
            IOSurfaceLock(surf,0,NULL); base=(uint8_t*)IOSurfaceGetBaseAddress(surf);
            uint64_t v0=*(uint64_t*)base, v1=*(uint64_t*)(base+8);
            IOSurfaceUnlock(surf,0,NULL);
            L(@"[bar-gpu] submit=0x%x io=0x%x comp=0x%x buf=%016llx %016llx",k45,k49,k50,
              (unsigned long long)v0,(unsigned long long)v1);
            free(e);
        }
        if (surf) CFRelease(surf);
    }
    // dump nq and our buffer
    NSMutableString *h=[NSMutableString string];
    for(int i=0;i<0x20;i+=8) [h appendFormat:@"%016llx ",(unsigned long long)*(volatile uint64_t*)(nq_addr+i)];
    L(@"[nq] %@",h);
    L(@"[buf] %08x %08x",*(uint32_t*)buf,*(uint32_t*)((char*)buf+4));

    IOServiceClose(c);
    L(@"=== done ===");
}
@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (strong, nonatomic) UIWindow *window;
@end
@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)opts {
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    UIViewController *vc = [UIViewController new]; vc.view.backgroundColor = UIColor.blackColor;
    UITextView *tv = [[UITextView alloc] initWithFrame:vc.view.bounds];
    tv.backgroundColor = UIColor.blackColor; tv.textColor = UIColor.greenColor;
    tv.font = [UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];
    tv.editable = NO; tv.text = @"IOGPUShmem\n";
    [vc.view addSubview:tv]; self.window.rootViewController = vc; [self.window makeKeyAndVisible];
    [UIApplication sharedApplication].idleTimerDisabled = YES;
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0), ^{
        NSString *docs = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject];
        gPath = [docs stringByAppendingPathComponent:@"iogpushmem.log"];
        gLog = [NSMutableString new]; run();
        dispatch_async(dispatch_get_main_queue(), ^{ tv.text = gLog; });
    });
    return YES;
}
@end
int main(int argc, char **argv) { @autoreleasepool { return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class])); } }
