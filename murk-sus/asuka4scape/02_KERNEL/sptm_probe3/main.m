// SPTMProbe3 — focused type sweep: IOMobileFramebuffer / IOGPU / Scaler
// iOS 27.2 (24B115), iPhone14,7. Logs to Documents/SPTMProbe3.log.
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <IOKit/IOKitLib.h>
#import <mach/mach.h>
#import <sys/mman.h>
#import <sys/utsname.h>
#import <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

typedef struct __IOSurface *IOSurfaceRef;
typedef uint32_t IOSurfaceID;
extern IOSurfaceRef IOSurfaceCreate(CFDictionaryRef properties);
extern IOSurfaceID IOSurfaceGetID(IOSurfaceRef buffer);
extern size_t IOSurfaceGetAllocSize(IOSurfaceRef buffer);
extern void *IOSurfaceGetBaseAddress(IOSurfaceRef buffer);

static FILE *gFile;
static NSLock *gLock;
static NSString *gLogPath;
static NSString *gLastPath;
static UITextView *gView;
static NSMutableString *gBuf;
static int gLines;

static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    if (!s) return;
    [gLock lock];
    if (gFile) { fprintf(gFile, "%s\n", s.UTF8String); fflush(gFile); }
    [gBuf appendFormat:@"%@\n", s];
    if (gBuf.length > 400000) [gBuf deleteCharactersInRange:NSMakeRange(0, 150000)];
    BOOL upd = (++gLines % 16) == 0;
    NSString *copy = upd ? [gBuf copy] : nil;
    [gLock unlock];
    if (upd) dispatch_async(dispatch_get_main_queue(), ^{
        if (gView) { gView.text = copy; [gView scrollRangeToVisible:NSMakeRange(copy.length ? copy.length-1 : 0, 1)]; }
    });
}

static void last(NSString *s) {
    if (gLastPath) [s writeToFile:gLastPath atomically:YES encoding:NSUTF8StringEncoding error:NULL];
}

static NSString *dump(const uint8_t *p, size_t n) {
    if (!p || !n) return @"";
    if (n > 0x80) n = 0x80;
    NSMutableString *s = [NSMutableString string];
    for (size_t i = 0; i < n; i += 16) {
        [s appendFormat:@"%04zx:", i];
        for (size_t j = 0; j < 16 && i+j < n; j++) [s appendFormat:@" %02x", p[i+j]];
        [s appendString:@"\n"];
    }
    return s;
}

static int scan(const uint8_t *p, size_t n, const char *tag) {
    if (!p || n < 8) return 0;
    int hits = 0;
    for (size_t i = 0; i + 8 <= n && hits < 8; i += 4) {
        uint64_t v; memcpy(&v, p+i, 8);
        if ((v >= 0xfffffff007004000ULL && v < 0xfffffff00aa78000ULL) ||
            (v >= 0xfffffff000000000ULL && v < 0xfffffff800000000ULL) ||
            (v >= 0xffffffff80000000ULL)) {
            L(@"[PTR] %s +0x%zx = 0x%016llx", tag, i, (unsigned long long)v);
            hits++;
        }
    }
    return hits;
}

static IOSurfaceRef mk_surface(void) {
    CFMutableDictionaryRef d = CFDictionaryCreateMutable(NULL, 0, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
    int32_t v;
    CFNumberRef n;
    v=64; n=CFNumberCreate(NULL,kCFNumberSInt32Type,&v); CFDictionarySetValue(d,CFSTR("IOSurfaceWidth"),n); CFRelease(n);
    v=64; n=CFNumberCreate(NULL,kCFNumberSInt32Type,&v); CFDictionarySetValue(d,CFSTR("IOSurfaceHeight"),n); CFRelease(n);
    v=0x42475241; n=CFNumberCreate(NULL,kCFNumberSInt32Type,&v); CFDictionarySetValue(d,CFSTR("IOSurfacePixelFormat"),n); CFRelease(n);
    v=256; n=CFNumberCreate(NULL,kCFNumberSInt32Type,&v); CFDictionarySetValue(d,CFSTR("IOSurfaceBytesPerRow"),n); CFRelease(n);
    IOSurfaceRef s = IOSurfaceCreate(d); CFRelease(d);
    if (s) L(@"[SURF] id=%u base=%p alloc=0x%zx", IOSurfaceGetID(s), IOSurfaceGetBaseAddress(s), IOSurfaceGetAllocSize(s));
    return s;
}

static void type_sweep(const char *name) {
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching(name));
    if (!svc) { L(@"[SVC] %s absent", name); return; }
    io_name_t cls={0}; IOObjectGetClass(svc, cls);
    L(@"[SVC] %s class=%s", name, cls);
    for (uint32_t t=0; t<=16; t++) {
        io_connect_t c=0;
        kern_return_t kr = IOServiceOpen(svc, mach_task_self(), t, &c);
        L(@"[OPEN] %s t=%u -> 0x%x conn=%u", name, t, kr, c);
        if (kr==KERN_SUCCESS && c) IOServiceClose(c);
    }
    IOObjectRelease(svc);
}

static void probe_type(const char *name, uint32_t type, uint32_t maxsel) {
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching(name));
    if (!svc) return;
    io_connect_t c=0;
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), type, &c);
    L(@"[PROBE] %s t=%u open=0x%x conn=%u", name, type, kr, c);
    if (kr==KERN_SUCCESS && c) {
        uint8_t in[0x100]; uint8_t out[0x800]; uint64_t sin[2]; uint64_t sout[4];
        for (uint32_t sel=0; sel<=maxsel; sel++) {
            for (int shape=0; shape<4; shape++) {
                uint32_t sc = (shape==0)?0:1;
                size_t st = (shape<2)?0:0x100;
                memset(in,0,sizeof(in)); memset(out,0,sizeof(out));
                memset(sin,0,sizeof(sin)); memset(sout,0,sizeof(sout));
                if (shape==3) sin[0]=0x100;
                uint32_t scout=4; size_t outsz=sizeof(out);
                last([NSString stringWithFormat:@"%s t%u sel=0x%x sc=%u st=0x%zx", name,type,sel,sc,st]);
                kr = IOConnectCallMethod(c, sel, sc?sin:NULL, sc, st?in:NULL, st,
                                         sout, &scout, out, &outsz);
                L(@"[IO] %s t%u sel=0x%02x sc=%u st=0x%zx -> 0x%x outsz=0x%zx so0=0x%llx",
                  name,type,sel,sc,st,kr,outsz,(unsigned long long)sout[0]);
                if (kr==0 || outsz != sizeof(out)) {
                    L(@"[IO]   out:\n%@", dump(out,outsz));
                    scan(out,outsz,name);
                }
            }
        }
        IOServiceClose(c);
    }
    IOObjectRelease(svc);
}

static void mfb_surface(void) {
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("IOMobileFramebuffer"));
    if (!svc) { L(@"[MFB] absent"); return; }
    IOSurfaceRef s = mk_surface();
    IOSurfaceID sid = s ? IOSurfaceGetID(s) : 0;
    for (uint32_t t=0; t<=8; t++) {
        io_connect_t c=0;
        kern_return_t kr = IOServiceOpen(svc, mach_task_self(), t, &c);
        if (kr != KERN_SUCCESS || !c) continue;
        L(@"[MFB] t=%u opened, sid=%u", t, sid);
        for (uint32_t sel=0; sel<=0x20; sel++) {
            for (int shape=0; shape<3; shape++) {
                uint8_t in[0x100]; memset(in,0,sizeof(in));
                uint64_t sin[2]={sid,0};
                uint64_t sout[4]={0}; uint32_t scout=4;
                uint8_t out[0x800]; memset(out,0,sizeof(out)); size_t outsz=sizeof(out);
                uint32_t sc = (shape==2)?0:1;
                size_t st = (shape==0)?0:0x100;
                last([NSString stringWithFormat:@"MFB t%u sel=0x%x shape=%d sid=%u",t,sel,shape,sid]);
                kr = IOConnectCallMethod(c, sel, sc?sin:NULL, sc, st?in:NULL, st,
                                         sout, &scout, out, &outsz);
                L(@"[MFB] t%u sel=0x%02x sh=%d -> 0x%x outsz=0x%zx so0=0x%llx",
                  t,sel,shape,kr,outsz,(unsigned long long)sout[0]);
                if (kr==0) { L(@"[MFB]   out:\n%@", dump(out,outsz)); scan(out,outsz,"MFB"); }
            }
        }
        IOServiceClose(c);
    }
    if (s) CFRelease(s);
    IOObjectRelease(svc);
}

static void scaler_test(void) {
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("AppleM2ScalerCSCDriver"));
    if (!svc) { L(@"[SCL] absent"); return; }
    io_connect_t c=0;
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), 0, &c);
    L(@"[SCL] open t0 -> 0x%x conn=%u", kr, c);
    if (kr==KERN_SUCCESS && c) {
        uint8_t out[0x400]; uint64_t sout[4]; uint64_t sin[2];
        for (uint32_t s=0; s<=0x40; s++) {
            memset(out,0,sizeof(out)); memset(sout,0,sizeof(sout)); sin[0]=s; sin[1]=0;
            uint32_t scout=4; size_t outsz=sizeof(out);
            last([NSString stringWithFormat:@"SCL sel0b s=%u",s]);
            kr = IOConnectCallMethod(c, 0x0b, sin, 1, NULL, 0, sout, &scout, out, &outsz);
            L(@"[SCL] sel0b s=%u -> 0x%x outsz=0x%zx\n%@", s, kr, outsz, dump(out,outsz));
            scan(out,outsz,"SCL0b");
        }
        // sel 0x0a: set slot table (u32 slot <4, 16 bytes at +0x170)
        for (uint32_t slot=0; slot<4; slot++) {
            uint8_t in[0x18]; memset(in,0,sizeof(in));
            *(uint32_t*)(in+0)=slot;
            *(uint64_t*)(in+8)=0;
            *(uint64_t*)(in+16)=0;
            last([NSString stringWithFormat:@"SCL sel0a slot=%u",slot]);
            kr = IOConnectCallMethod(c, 0x0a, NULL, 0, in, 0x18, NULL, NULL, NULL, NULL);
            L(@"[SCL] sel0a slot=%u -> 0x%x", slot, kr);
            uint64_t s0=0; uint32_t sc0=4; size_t os0=sizeof(out);
            memset(out,0,sizeof(out)); memset(sout,0,sizeof(sout));
            kr = IOConnectCallMethod(c, 0x0b, &s0, 1, NULL, 0, sout, &sc0, out, &os0);
            L(@"[SCL] after0a sel0b -> 0x%x outsz=0x%zx\n%@", kr, os0, dump(out,os0));
        }
        IOServiceClose(c);
    }
    IOObjectRelease(svc);
}

static void run(void) {
    struct utsname u; uname(&u);
    L(@"[RUN] SPTMProbe3 start %@ machine=%s rel=%s uid=%u", [NSDate date], u.machine, u.release, getuid());
    const char *svcs[] = {
        "IOMobileFramebuffer","IOMobileFramebufferService","AppleCLCD2",
        "IOGPU","AGXAcceleratorG14P","IOGPUDevice","AGXDevice",
        "AppleJPEGDriver","AppleM2ScalerCSCDriver","AppleT8110DART",
        "AppleH11ANEInterface","H11ANEInDirectPathClient","AppleAVE2Driver",
        "IOSurfaceRoot",NULL };
    for (int i=0; svcs[i]; i++) type_sweep(svcs[i]);
    for (uint32_t t=3; t<=8; t++) probe_type("IOMobileFramebuffer", t, 0x20);
    probe_type("IOGPU", 1, 0x10);
    probe_type("AGXAcceleratorG14P", 1, 0x10);
    probe_type("AppleJPEGDriver", 0, 0x08);
    probe_type("AppleM2ScalerCSCDriver", 0, 0x08);
    scaler_test();
    mfb_surface();
    L(@"[RUN] done %@", [NSDate date]);
}

@interface D : UIResponder <UIApplicationDelegate>
@property (nonatomic) UIWindow *w;
@end
@implementation D
- (BOOL)application:(UIApplication*)a didFinishLaunchingWithOptions:(NSDictionary*)o {
    gLock=[NSLock new]; gBuf=[NSMutableString new]; gLines=0;
    NSString *docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];
    gLogPath=[docs stringByAppendingPathComponent:@"SPTMProbe3.log"];
    gLastPath=[docs stringByAppendingPathComponent:@"SPTMProbe3-last.txt"];
    gFile=fopen(gLogPath.fileSystemRepresentation,"a");
    if(!gFile){ gLogPath=[NSTemporaryDirectory() stringByAppendingPathComponent:@"SPTMProbe3.log"]; gFile=fopen(gLogPath.fileSystemRepresentation,"a"); }
    UIViewController *vc=[UIViewController new]; vc.view.backgroundColor=[UIColor blackColor];
    gView=[[UITextView alloc] initWithFrame:vc.view.bounds]; gView.backgroundColor=[UIColor blackColor]; gView.textColor=[UIColor greenColor]; gView.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular]; gView.editable=NO; gView.text=gLogPath; [vc.view addSubview:gView];
    self.w=[[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds]; self.w.rootViewController=vc; [self.w makeKeyAndVisible];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW,(int64_t)(1.0*NSEC_PER_SEC)),dispatch_get_global_queue(QOS_CLASS_USER_INITIATED,0),^{ run(); });
    return YES;
}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,@"D");}}
