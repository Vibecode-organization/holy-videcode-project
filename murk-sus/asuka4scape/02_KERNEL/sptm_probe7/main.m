// SPTMProbe7 — AGX/IOGPU info-query exact-shape leak probe
// iOS 27.2 (24B115), iPhone14,7. Logs to Documents/SPTMProbe7.log.
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <IOKit/IOKitLib.h>
#import <mach/mach.h>
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
            }
            free(out);
        }
        IOServiceClose(c);
    }
    IOObjectRelease(svc);
}

static void run(void) {
    struct utsname u; uname(&u);
    L(@"[RUN] SPTMProbe7 start %@ machine=%s rel=%s",[NSDate date],u.machine,u.release);
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
    gLogPath=[docs stringByAppendingPathComponent:@"SPTMProbe7.log"];
    gFile=fopen(gLogPath.fileSystemRepresentation,"a");
    if(!gFile){gLogPath=[NSTemporaryDirectory() stringByAppendingPathComponent:@"SPTMProbe7.log"];gFile=fopen(gLogPath.fileSystemRepresentation,"a");}
    UIViewController *vc=[UIViewController new]; vc.view.backgroundColor=[UIColor blackColor];
    gView=[[UITextView alloc] initWithFrame:vc.view.bounds]; gView.backgroundColor=[UIColor blackColor]; gView.textColor=[UIColor greenColor]; gView.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular]; gView.editable=NO; gView.text=gLogPath; [vc.view addSubview:gView];
    self.w=[[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds]; self.w.rootViewController=vc; [self.w makeKeyAndVisible];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW,(int64_t)(1.0*NSEC_PER_SEC)),dispatch_get_global_queue(QOS_CLASS_USER_INITIATED,0),^{run();});
    return YES;
}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,@"D");}}
