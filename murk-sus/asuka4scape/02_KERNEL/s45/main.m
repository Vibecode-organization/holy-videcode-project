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
    io_service_t svc=IOServiceGetMatchingService(kIOMasterPortDefault,IOServiceMatching("AGXAcceleratorG14P"));
    L(@"[svc] 0x%x",svc); if(!svc)return;
    io_connect_t c=0; kern_return_t kr=IOServiceOpen(svc,mach_task_self(),1,&c); L(@"[open] 0x%x conn=0x%x",kr,c); IOObjectRelease(svc); if(kr)return;
    uint64_t nq_addr=0; uint32_t nq_id=0;
    { uint64_t sv[2]={0x100,0x10}; uint8_t so[0x10]={0}; size_t sos=0x10; kr=call(c,14,sv,2,NULL,0,NULL,NULL,so,&sos); nq_addr=*(uint64_t*)so; nq_id=*(uint32_t*)(so+8); L(@"[sel14] 0x%x addr=0x%llx id=%u",kr,(unsigned long long)nq_addr,nq_id); }
    if(!nq_id){L(@"[no nq]");IOServiceClose(c);return;}
    uint64_t shm_addr=0; uint32_t shm_id=0;
    { uint64_t sv[2]={0x4000,0}; uint8_t so[0x10]={0}; size_t sos=0x10; kr=call(c,12,sv,2,NULL,0,NULL,NULL,so,&sos); shm_addr=*(uint64_t*)so; shm_id=*(uint32_t*)(so+0xc); L(@"[sel12] 0x%x addr=0x%llx len=0x%x id=%u",kr,(unsigned long long)shm_addr,*(uint32_t*)(so+8),shm_id); }
    if(!shm_addr||!shm_id){L(@"[no shm]");IOServiceClose(c);return;}
    volatile uint32_t *sp=(volatile uint32_t*)(uintptr_t)shm_addr; sp[0]=8; sp[1]=8; for(int i=2;i<16;i++)sp[i]=0;
    uint64_t qid=0;
    { uint64_t sv[2]={0,0}; uint64_t so[2]={0}; uint32_t oc=2; kr=call(c,42,sv,2,NULL,0,so,&oc,NULL,NULL); L(@"[sel42] 0x%x qid=%llu q1=0x%llx",kr,(unsigned long long)so[0],(unsigned long long)so[1]); if(!kr)qid=so[0]; }
    if(!qid){L(@"[no qid]");IOServiceClose(c);return;}
    kr=call(c,44,(uint64_t[]){qid,nq_id},2,NULL,0,NULL,NULL,NULL,NULL); L(@"[sel44] 0x%x",kr);
    uint64_t cbid=0;
    { uint64_t sv[1]={qid}; uint64_t so[2]={0}; uint32_t oc=2; kr=call(c,46,sv,1,NULL,0,so,&oc,NULL,NULL); L(@"[sel46] 0x%x cbid=%llu serial=0x%llx",kr,(unsigned long long)so[0],(unsigned long long)so[1]); if(!kr)cbid=so[0]; }
    if(!cbid){L(@"[no cb]");IOServiceClose(c);return;}
    for(int st=0;st<4;st++){
      uint32_t stride=(uint32_t[]){0x18,0x20,0x30,0x40}[st];
      uint8_t *e=calloc(1,stride); *(uint32_t*)e=1; *(uint32_t*)(e+4)=0;
      if(stride>=0x18){*(uint32_t*)(e+8)=shm_id;*(uint32_t*)(e+12)=(uint32_t)cbid;*(uint64_t*)(e+16)=shm_addr;*(uint32_t*)(e+24)=0;}
      else { memcpy(e+8,&shm_id,4); memcpy(e+12,&cbid,4); }
      uint64_t sv[4]={qid,0,1,stride};
      kr=call(c,45,sv,4,e,stride,NULL,NULL,NULL,NULL);
      L(@"[sel45 stride=0x%x] 0x%x",stride,kr);
      uint64_t s1=0,s2=0; uint32_t oc1=0,oc2=0; kern_return_t k49=call(c,49,&qid,1,NULL,0,&s1,&oc1,NULL,NULL); kern_return_t k50=call(c,50,&qid,1,NULL,0,&s2,&oc2,NULL,NULL);
      L(@"[sel49] 0x%x out=%llu [sel50] 0x%x out=%llu",k49,(unsigned long long)s1,k50,(unsigned long long)s2);
      L(@"[shm] header=%08x %08x %08x %08x data=%016llx %016llx",sp[0],sp[1],sp[2],sp[3],*(volatile uint64_t*)(sp+4),*(volatile uint64_t*)(sp+6));
      free(e);
    }
    IOServiceClose(c); L(@"=== done ===");
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
