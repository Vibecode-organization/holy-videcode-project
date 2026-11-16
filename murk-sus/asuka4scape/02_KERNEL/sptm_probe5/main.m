// SPTMProbe5 — properties + IOConnectMapMemory64 + exact Scaler ABI
// iOS 27.2 (24B115), iPhone14,7. Logs to Documents/SPTMProbe5.log.
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
extern kern_return_t IOConnectMapMemory64(io_connect_t connect, uint32_t memoryType,
    task_port_t intoTask, uint64_t *atAddress, uint64_t *ofSize, IOOptionBits options);
extern kern_return_t vm_deallocate(vm_map_t target_task, vm_address_t address, vm_size_t size);
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

static void last(NSString *s) {
    if (gLastPath) [s writeToFile:gLastPath atomically:YES encoding:NSUTF8StringEncoding error:NULL];
}

static NSString *dump(const uint8_t *p, size_t n) {
    if (!p || !n) return @"";
    if (n > 0x80) n = 0x80;
    NSMutableString *s = [NSMutableString string];
    for (size_t i=0;i<n;i+=16) {
        [s appendFormat:@"%04zx:",i];
        for (size_t j=0;j<16 && i+j<n;j++) [s appendFormat:@" %02x",p[i+j]];
        [s appendString:@"\n"];
    }
    return s;
}

static int scan(const uint8_t *p, size_t n, const char *tag) {
    if (!p || n < 8) return 0;
    int hits=0;
    for (size_t i=0;i+8<=n && hits<10;i+=4) {
        uint64_t v; memcpy(&v,p+i,8);
        if ((v>=0xfffffff007004000ULL && v<0xfffffff00aa78000ULL) ||
            (v>=0xfffffff000000000ULL && v<0xfffffff800000000ULL) ||
            (v>=0xffffffff80000000ULL) ||
            ((v & 0xfffffffff000ULL) == v && (v & 0x3) == 0x3)) {
            L(@"[PTR] %s +0x%zx = 0x%016llx", tag, i, (unsigned long long)v);
            hits++;
        }
    }
    return hits;
}

static IOSurfaceRef mk_surface(void) {
    CFMutableDictionaryRef d = CFDictionaryCreateMutable(NULL,0,&kCFTypeDictionaryKeyCallBacks,&kCFTypeDictionaryValueCallBacks);
    CFNumberRef n; int32_t v;
    v=64; n=CFNumberCreate(NULL,kCFNumberSInt32Type,&v); CFDictionarySetValue(d,CFSTR("IOSurfaceWidth"),n); CFRelease(n);
    v=64; n=CFNumberCreate(NULL,kCFNumberSInt32Type,&v); CFDictionarySetValue(d,CFSTR("IOSurfaceHeight"),n); CFRelease(n);
    v=0x42475241; n=CFNumberCreate(NULL,kCFNumberSInt32Type,&v); CFDictionarySetValue(d,CFSTR("IOSurfacePixelFormat"),n); CFRelease(n);
    v=256; n=CFNumberCreate(NULL,kCFNumberSInt32Type,&v); CFDictionarySetValue(d,CFSTR("IOSurfaceBytesPerRow"),n); CFRelease(n);
    IOSurfaceRef s=IOSurfaceCreate(d); CFRelease(d);
    if (s) L(@"[SURF] id=%u base=%p alloc=0x%zx",IOSurfaceGetID(s),IOSurfaceGetBaseAddress(s),IOSurfaceGetAllocSize(s));
    return s;
}

static NSString *cfstr(CFTypeRef v, NSUInteger cap) {
    if (!v) return @"(null)";
    CFStringRef s = CFStringCreateWithFormat(NULL,NULL,CFSTR("%@"),v);
    if (!s) return @"(unprintable)";
    NSString *out = (__bridge_transfer NSString *)s;
    if (out.length > cap) out = [out substringToIndex:cap];
    return out;
}

static void props(const char *name) {
    io_registry_entry_t e = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching(name));
    if (!e) { L(@"[PROP] %s absent",name); return; }
    io_name_t cls={0}; IOObjectGetClass(e,cls);
    CFMutableDictionaryRef d=NULL;
    kern_return_t kr = IORegistryEntryCreateCFProperties(e,&d,kCFAllocatorDefault,0);
    L(@"[PROP] %s class=%s kr=0x%x",name,cls,kr);
    if (kr==KERN_SUCCESS && d) { L(@"[PROP] %s = %@",name,cfstr((CFTypeRef)d,12000)); CFRelease(d); }
    IOObjectRelease(e);
}

static void parents(const char *name) {
    io_registry_entry_t e = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching(name));
    if (!e) return;
    for (int i=0;i<6;i++) {
        io_name_t nm={0}; IOObjectGetClass(e,nm);
        CFMutableDictionaryRef d=NULL;
        kern_return_t kr=IORegistryEntryCreateCFProperties(e,&d,kCFAllocatorDefault,0);
        L(@"[PARENT] %s depth=%d class=%s kr=0x%x %@",name,i,nm,kr,cfstr((CFTypeRef)d,3000));
        if (d) CFRelease(d);
        io_registry_entry_t p=0;
        if (IORegistryEntryGetParentEntry(e,kIOServicePlane,&p)!=KERN_SUCCESS || !p) {
            if (IORegistryEntryGetParentEntry(e,kIODeviceTreePlane,&p)!=KERN_SUCCESS || !p) break;
        }
        IOObjectRelease(e); e=p;
    }
    IOObjectRelease(e);
}


static void dt_props(const char *name) {
    io_registry_entry_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching(name));
    if (!svc) { L(@"[DT] %s absent",name); return; }
    io_registry_entry_t p = 0;
    if (IORegistryEntryGetParentEntry(svc, kIOServicePlane, &p) != KERN_SUCCESS || !p) {
        L(@"[DT] %s no service parent",name); IOObjectRelease(svc); return;
    }
    io_name_t cls = {0}; IOObjectGetClass(p, cls);
    io_string_t path; memset(path,0,sizeof(path));
    kern_return_t pr = IORegistryEntryGetPath(p, kIODeviceTreePlane, path);
    L(@"[DT] %s parent=%s dtpath_kr=0x%x path='%s'",name,cls,pr,path);
    const char *keys[] = {
        "gpu-region-base","gpu-region-size","ttbat-phys-addr-base","gptbat-ready",
        "gfx-shared-region-base","gfx-shared-region-size","gfx-shared-l2-region-base",
        "gfx-shared-l2-region-size","gfx-handoff-base","gfx-handoff-size",
        "agx-address-space-mgmt-mode","uat-enforce-gpu-carveout","uat-vaddr-size",
        "uat-segment-limit","uat-mapping-limit","gpu-iouat","iommu-present",NULL
    };
    for (int i=0; keys[i]; i++) {
        CFStringRef k = CFStringCreateWithCString(NULL, keys[i], kCFStringEncodingUTF8);
        CFTypeRef v = IORegistryEntryCreateCFProperty(p, k, kCFAllocatorDefault, 0);
        if (k) CFRelease(k);
        L(@"[DT] %s parent key=%s v=%s",name,keys[i],cfstr(v,512));
        if (v) CFRelease(v);
    }
    io_registry_entry_t dt = 0;
    if (IORegistryEntryGetParentEntry(p, kIODeviceTreePlane, &dt) == KERN_SUCCESS && dt) {
        io_name_t dcls = {0}; IOObjectGetClass(dt, dcls);
        io_string_t dpath; memset(dpath,0,sizeof(dpath));
        kern_return_t dpr = IORegistryEntryGetPath(dt, kIODeviceTreePlane, dpath);
        L(@"[DT] %s dtparent=%s dtpath_kr=0x%x path='%s'",name,dcls,dpr,dpath);
        for (int i=0; keys[i]; i++) {
            CFStringRef k = CFStringCreateWithCString(NULL, keys[i], kCFStringEncodingUTF8);
            CFTypeRef v = IORegistryEntryCreateCFProperty(dt, k, kCFAllocatorDefault, 0);
            if (k) CFRelease(k);
            L(@"[DT] %s dt key=%s v=%s",name,keys[i],cfstr(v,512));
            if (v) CFRelease(v);
        }
        CFMutableDictionaryRef d=NULL;
        kern_return_t dkr = IORegistryEntryCreateCFProperties(dt,&d,kCFAllocatorDefault,0);
        L(@"[DT] %s dt props kr=0x%x %@",name,dkr,cfstr((CFTypeRef)d,8000));
        if (d) CFRelease(d);
        IOObjectRelease(dt);
    } else {
        L(@"[DT] %s no DT parent (kr=0x%x)",name,dt);
    }
    IOObjectRelease(p); IOObjectRelease(svc);
}

static void map_types(const char *name, uint32_t type, uint32_t maxType) {
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching(name));
    if (!svc) return;
    io_connect_t c=0;
    kern_return_t kr=IOServiceOpen(svc,mach_task_self(),type,&c);
    L(@"[MAP] %s t=%u open=0x%x conn=%u",name,type,kr,c);
    if (kr==KERN_SUCCESS && c) {
        for (uint32_t mt=0; mt<=maxType; mt++) {
            for (int opt=0; opt<2; opt++) {
                uint64_t addr=0; uint64_t size=0;
                IOOptionBits o = opt ? kIOMapAnywhere : 0;
                last([NSString stringWithFormat:@"MAP %s t%u mt=0x%x opt=%d",name,type,mt,o]);
                kr = IOConnectMapMemory64(c, mt, mach_task_self(), &addr, &size, o);
                L(@"[MAP] %s t%u mt=0x%x opt=0x%x -> 0x%x addr=%#llx size=%#llx",
                  name,type,mt,o,kr,(unsigned long long)addr,(unsigned long long)size);
                if (kr != KERN_SUCCESS) {
                    mach_vm_address_t a32=0; mach_vm_size_t s32=0;
                    kern_return_t kr32 = IOConnectMapMemory(c, mt, mach_task_self(), &a32, &s32, o);
                    L(@"[MAP32] %s t%u mt=0x%x opt=0x%x -> 0x%x addr=%#lx size=%#lx",
                      name,type,mt,o,kr32,(unsigned long long)a32,(unsigned long long)s32);
                    if (kr32==KERN_SUCCESS) { addr=a32; size=s32; kr=kr32; }
                }
                if (kr==KERN_SUCCESS && addr && addr < 0x800000000000ULL && size) {
                    size_t rd = size > 0x1000 ? 0x1000 : (size_t)size;
                    uint8_t buf[0x1000];
                    memcpy(buf,(void *)(uintptr_t)addr,rd);
                    L(@"[MAP]   bytes:\n%@",dump(buf,rd<0x80?rd:0x80));
                    scan(buf,rd,name);
                    vm_deallocate(mach_task_self(),(vm_address_t)addr,(vm_size_t)size);
                }
            }
        }
        IOServiceClose(c);
    }
    IOObjectRelease(svc);
}

static void probe_type_ex(const char *name, uint32_t type, uint32_t maxsel, IOSurfaceID sid) {
    io_service_t svc=IOServiceGetMatchingService(kIOMasterPortDefault,IOServiceMatching(name));
    if (!svc) return;
    io_connect_t c=0;
    kern_return_t kr=IOServiceOpen(svc,mach_task_self(),type,&c);
    L(@"[PROBE] %s t=%u open=0x%x conn=%u",name,type,kr,c);
    if (kr==KERN_SUCCESS && c) {
        uint8_t in[0x200]; uint8_t out[0x800]; uint64_t sin[2]; uint64_t sout[4];
        for (uint32_t sel=0; sel<=maxsel; sel++) {
            for (int sh=0; sh<5; sh++) {
                uint32_t sc; size_t st;
                memset(in,0,sizeof(in)); memset(out,0,sizeof(out)); memset(sin,0,sizeof(sin)); memset(sout,0,sizeof(sout));
                if (sh==0) { sc=0; st=0; }
                else if (sh==1) { sc=1; sin[0]=sid; st=0; }
                else if (sh==2) { sc=1; sin[0]=sid; st=0x100; }
                else if (sh==3) { sc=2; sin[0]=sid; st=0x100; }
                else { sc=0; st=0x100; }
                uint32_t scout=4; size_t outsz=sizeof(out);
                last([NSString stringWithFormat:@"%s t%u sel=0x%x sh=%d",name,type,sel,sh]);
                kr=IOConnectCallMethod(c,sel,sc?sin:NULL,sc,st?in:NULL,st,sout,&scout,out,&outsz);
                L(@"[IO] %s t%u sel=0x%02x sh=%d -> 0x%x outsz=0x%zx so0=0x%llx",
                  name,type,sel,sh,kr,outsz,(unsigned long long)sout[0]);
                if (kr==0 || outsz!=sizeof(out)) { L(@"[IO]   out:\n%@",dump(out,outsz)); scan(out,outsz,name); }
            }
        }
        IOServiceClose(c);
    }
    IOObjectRelease(svc);
}

static void scaler_exact(void) {
    io_service_t svc=IOServiceGetMatchingService(kIOMasterPortDefault,IOServiceMatching("AppleM2ScalerCSCDriver"));
    if (!svc) { L(@"[SCL] absent"); return; }
    io_connect_t c=0; kern_return_t kr=IOServiceOpen(svc,mach_task_self(),0,&c);
    L(@"[SCL] open=0x%x conn=%u",kr,c);
    if (kr!=KERN_SUCCESS || !c) { IOObjectRelease(svc); return; }
    uint8_t in[0x1000]; uint8_t out[0x1000]; uint64_t sout[4];
    struct { uint32_t sel; size_t st; uint32_t sc; } cases[] = {
        {0x01,0x1b0,0},{0x04,0x20,0},{0x06,0xfa8,0},
        {0x07,0x08,0},{0x08,0x08,0},{0x09,0x10,0},
        {0x0a,0x18,0},{0x0b,0x00,0},
    };
    for (unsigned i=0;i<sizeof(cases)/sizeof(cases[0]);i++) {
        memset(in,0,sizeof(in)); memset(out,0,sizeof(out)); memset(sout,0,sizeof(sout));
        // for 7/8/9 put a valid user buffer address in the struct
        void *ub = mmap(NULL,0x4000,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANON,-1,0);
        if (ub!=MAP_FAILED) memset(ub,0x5a,0x4000);
        if (cases[i].sel==0x07 || cases[i].sel==0x08) *(uint64_t*)(in+0)=(uint64_t)(uintptr_t)ub;
        if (cases[i].sel==0x09) { *(uint64_t*)(in+0)=(uint64_t)(uintptr_t)ub; *(uint64_t*)(in+8)=(uint64_t)(uintptr_t)ub; }
        if (cases[i].sel==0x0a) { *(uint32_t*)(in+0)=0; }
        uint32_t scout=4; size_t outsz=sizeof(out);
        last([NSString stringWithFormat:@"SCL sel=0x%x st=0x%zx",cases[i].sel,cases[i].st]);
        kr=IOConnectCallMethod(c,cases[i].sel,NULL,cases[i].sc,cases[i].st?in:NULL,cases[i].st,sout,&scout,out,&outsz);
        L(@"[SCL] sel=0x%02x st=0x%zx -> 0x%x outsz=0x%zx so0=0x%llx",cases[i].sel,cases[i].st,kr,outsz,(unsigned long long)sout[0]);
        if (kr==0 || outsz!=sizeof(out)) { L(@"[SCL]   out:\n%@",dump(out,outsz)); scan(out,outsz,"SCL"); }
        if (ub!=MAP_FAILED) munmap(ub,0x4000);
    }
    IOServiceClose(c); IOObjectRelease(svc);
}

static void run(void) {
    struct utsname u; uname(&u);
    L(@"[RUN] SPTMProbe5 start %@ machine=%s rel=%s",[NSDate date],u.machine,u.release);
    props("AGXAcceleratorG14P");
    props("IOMobileFramebuffer");
    props("AppleCLCD2");
    props("AppleM2ScalerCSCDriver");
    props("IOSurfaceRoot");
    parents("AGXAcceleratorG14P");
    dt_props("AGXAcceleratorG14P");
    dt_props("IOMobileFramebuffer");
    map_types("AGXAcceleratorG14P",1,0x100);
    for (uint32_t t=0;t<=16;t++) map_types("IOMobileFramebuffer",t,0x40);
    for (uint32_t t=0;t<=16;t++) map_types("AppleCLCD2",t,0x40);
    for (uint32_t t=0;t<=16;t++) map_types("AppleM2ScalerCSCDriver",t,0x40);
    for (uint32_t t=0;t<=8;t++) map_types("AppleJPEGDriver",t,0x40);
    IOSurfaceRef s=mk_surface(); IOSurfaceID sid=s?IOSurfaceGetID(s):0;
    for (uint32_t t=0;t<=8;t++) probe_type_ex("AppleCLCD2",t,0x20,sid);
    for (uint32_t t=0;t<=8;t++) probe_type_ex("IOMobileFramebufferService",t,0x20,sid);
    for (uint32_t t=9;t<=16;t++) probe_type_ex("IOMobileFramebuffer",t,0x20,sid);
    probe_type_ex("IOGPU",1,0x02,sid);
    scaler_exact();
    if (s) CFRelease(s);
    L(@"[RUN] done %@",[NSDate date]);
}

@interface D : UIResponder <UIApplicationDelegate>
@property (nonatomic) UIWindow *w;
@end
@implementation D
- (BOOL)application:(UIApplication*)a didFinishLaunchingWithOptions:(NSDictionary*)o {
    gLock=[NSLock new]; gBuf=[NSMutableString new]; gLines=0;
    NSString *docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];
    gLogPath=[docs stringByAppendingPathComponent:@"SPTMProbe5.log"];
    gLastPath=[docs stringByAppendingPathComponent:@"SPTMProbe5-last.txt"];
    gFile=fopen(gLogPath.fileSystemRepresentation,"a");
    if(!gFile){gLogPath=[NSTemporaryDirectory() stringByAppendingPathComponent:@"SPTMProbe5.log"];gFile=fopen(gLogPath.fileSystemRepresentation,"a");}
    UIViewController *vc=[UIViewController new]; vc.view.backgroundColor=[UIColor blackColor];
    gView=[[UITextView alloc] initWithFrame:vc.view.bounds]; gView.backgroundColor=[UIColor blackColor]; gView.textColor=[UIColor greenColor]; gView.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular]; gView.editable=NO; gView.text=gLogPath; [vc.view addSubview:gView];
    self.w=[[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds]; self.w.rootViewController=vc; [self.w makeKeyAndVisible];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW,(int64_t)(1.0*NSEC_PER_SEC)),dispatch_get_global_queue(QOS_CLASS_USER_INITIATED,0),^{run();});
    return YES;
}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,@"D");}}
