// SPTMProbe2 — iOS 27.2 (24B115) reachability + paddr-surface probe
// Target: iPhone14,7 / T8110, app sandbox.
// Every line is a real API result. Logs survive crashes in Documents/SPTMProbe2.log.

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <IOKit/IOKitLib.h>
#import <mach/mach.h>
#import <mach/mach_time.h>
#import <sys/mman.h>
#import <sys/sysctl.h>
#import <sys/utsname.h>
#import <unistd.h>
#import <errno.h>
#import <string.h>
#import <stdlib.h>
#import <stdint.h>

// private IOSurface SPI
typedef struct __IOSurface *IOSurfaceRef;
typedef uint32_t IOSurfaceID;
extern IOSurfaceRef IOSurfaceCreate(CFDictionaryRef properties);
extern IOSurfaceRef IOSurfaceLookup(IOSurfaceID cid);
extern IOSurfaceID IOSurfaceGetID(IOSurfaceRef buffer);
extern size_t IOSurfaceGetAllocSize(IOSurfaceRef buffer);
extern size_t IOSurfaceGetBytesPerRow(IOSurfaceRef buffer);
extern size_t IOSurfaceGetWidth(IOSurfaceRef buffer);
extern size_t IOSurfaceGetHeight(IOSurfaceRef buffer);
extern void *IOSurfaceGetBaseAddress(IOSurfaceRef buffer);
extern void IOSurfaceSetValue(IOSurfaceRef buffer, CFStringRef key, CFTypeRef value);
extern void IOSurfaceRemoveValue(IOSurfaceRef buffer, CFStringRef key);
extern kern_return_t IOSurfaceLock(IOSurfaceRef buffer, uint32_t options, uint32_t *seed);
extern kern_return_t IOSurfaceUnlock(IOSurfaceRef buffer, uint32_t options, uint32_t *seed);

static NSMutableString *gLog;
static NSLock *gLock;
static FILE *gFile;
static NSString *gLogPath;
static NSString *gLastPath;
static UITextView *gView;
static UILabel *gPathLabel;
static UILabel *gPhaseLabel;
static volatile int gStop;
static volatile int gBusy;

static NSString *docs_dir(void) {
    NSArray *a = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    return a.count ? a[0] : NSTemporaryDirectory();
}

static void log_line(NSString *s) {
    if (!s) return;
    [gLock lock];
    if (gFile) {
        fprintf(gFile, "%s\n", s.UTF8String);
        fflush(gFile);
        fsync(fileno(gFile));
    }
    [gLog appendFormat:@"%@\n", s];
    if (gLog.length > 900000) [gLog deleteCharactersInRange:NSMakeRange(0, 300000)];
    NSString *copy = [gLog copy];
    [gLock unlock];
    dispatch_async(dispatch_get_main_queue(), ^{
        if (gView) {
            gView.text = copy;
            if (copy.length > 2) {
                NSRange r = NSMakeRange(copy.length - 1, 1);
                [gView scrollRangeToVisible:r];
            }
        }
    });
}

#define LOG(fmt, ...) log_line([NSString stringWithFormat:fmt, ##__VA_ARGS__])

static void write_last(NSString *s) {
    if (!gLastPath) return;
    [s writeToFile:gLastPath atomically:YES encoding:NSUTF8StringEncoding error:NULL];
}

static NSString *hexdump(const uint8_t *p, size_t n) {
    if (!p || !n) return @"";
    if (n > 0x100) n = 0x100;
    NSMutableString *s = [NSMutableString string];
    for (size_t i = 0; i < n; i += 16) {
        [s appendFormat:@"%04zx:", i];
        for (size_t j = 0; j < 16 && i + j < n; j++) [s appendFormat:@" %02x", p[i+j]];
        [s appendString:@"\n"];
    }
    return s;
}

static int scan_ptrs(const uint8_t *p, size_t n, NSString *tag, int limit) {
    if (!p || n < 8) return 0;
    int hits = 0;
    NSMutableString *s = [NSMutableString string];
    for (size_t i = 0; i + 8 <= n && hits < limit; i += 4) {
        uint64_t v = 0;
        memcpy(&v, p + i, 8);
        BOOL ktext = (v >= 0xfffffff007004000ULL && v < 0xfffffff00aa78000ULL);
        BOOL krange = (v >= 0xfffffff000000000ULL && v < 0xfffffff800000000ULL);
        BOOL sx32 = (v >= 0xffffffff80000000ULL && v <= 0xffffffffffffffffULL);
        if (ktext || (krange && !sx32) || sx32) {
            [s appendFormat:@"+0x%zx=0x%016llx%@ ", i, (unsigned long long)v,
             ktext ? @"[KTEXT]" : (sx32 ? @"[SX32]" : @"[K]")];
            hits++;
        }
    }
    if (hits) LOG(@"[PTR] %@ hits=%d %@", tag, hits, s);
    return hits;
}

static const char *krstr(kern_return_t kr) {
    static char b[32];
    snprintf(b, sizeof(b), "0x%x", kr);
    return b;
}

static void last_call(const char *svc, uint32_t type, uint32_t sel, uint32_t sc, size_t st) {
    write_last([NSString stringWithFormat:
        @"service=%s type=%u sel=0x%x scalarIn=%u structIn=0x%zx\n",
        svc, type, sel, sc, st]);
}

// ---------- generic service / selector probing ----------

static void probe_selectors(io_connect_t conn, const char *svc, uint32_t type, uint32_t maxsel) {
    uint8_t in[0x400];
    uint8_t out[0x1000];
    uint64_t sin[4];
    uint64_t sout[8];
    static const uint32_t scs[] = {0, 1, 2, 4};
    static const size_t sts[] = {0, 0x10, 0x58, 0x100, 0x400};

    for (uint32_t sel = 0; sel <= maxsel && !gStop; sel++) {
        int live = 0;
        for (int si = 0; si < (int)(sizeof(scs)/sizeof(scs[0])) && !gStop; si++) {
            for (int ti = 0; ti < (int)(sizeof(sts)/sizeof(sts[0])) && !gStop; ti++) {
                uint32_t sc = scs[si];
                size_t st = sts[ti];
                // only the widest shape for high selectors, to bound call count
                if (sel > 0x20 && !(sc == 1 && st == 0x100)) continue;
                memset(in, 0, sizeof(in));
                memset(sin, 0, sizeof(sin));
                memset(sout, 0, sizeof(sout));
                memset(out, 0, sizeof(out));
                uint32_t scout = 8;
                size_t outsz = sizeof(out);
                last_call(svc, type, sel, sc, st);
                kern_return_t kr = IOConnectCallMethod(conn, sel,
                    sc ? sin : NULL, sc, st ? in : NULL, st,
                    sout, &scout, out, &outsz);
                if (kr != 0xe00002c2 && kr != 0xe00002bc && kr != 0xe00002c7)
                    live = 1;
                LOG(@"[IO] %s t%u sel=0x%02x sc=%u st=0x%zx -> %s scout=%u outsz=0x%zx so0=0x%llx",
                    svc, type, sel, sc, st, krstr(kr), scout, outsz,
                    (unsigned long long)sout[0]);
                if (kr == 0 || outsz != sizeof(out) || scout != 8) {
                    if (scout) LOG(@"[IO]   scalars: %llx %llx %llx %llx",
                        (unsigned long long)sout[0], (unsigned long long)sout[1],
                        (unsigned long long)sout[2], (unsigned long long)sout[3]);
                    if (outsz && outsz <= sizeof(out)) {
                        LOG(@"[IO]   out[0..0x40]:\n%@", hexdump(out, outsz > 0x40 ? 0x40 : outsz));
                        scan_ptrs(out, outsz, [NSString stringWithFormat:@"%s/t%u/sel%x", svc, type, sel], 12);
                    }
                }
                if (gStop) break;
            }
        }
        if (!live && sel > 8) {
            // no method in the first probe shapes; keep going, some selectors
            // only accept a different shape
        }
    }
}

static void probe_service(const char *name, uint32_t maxsel) {
    if (gStop) return;
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching(name));
    if (!svc) {
        LOG(@"[SVC] %s: absent", name);
        return;
    }
    io_name_t cls = {0};
    IOObjectGetClass(svc, cls);
    LOG(@"[SVC] %s: present class=%s", name, cls);
    for (uint32_t type = 0; type <= 8 && !gStop; type++) {
        io_connect_t conn = 0;
        last_call(name, type, 0xffffffff, 0, 0);
        kern_return_t kr = IOServiceOpen(svc, mach_task_self(), type, &conn);
        LOG(@"[OPEN] %s type=%u -> %s conn=%u", name, type, krstr(kr), conn);
        if (kr == KERN_SUCCESS && conn) {
            probe_selectors(conn, name, type, maxsel);
            IOServiceClose(conn);
        }
    }
    IOObjectRelease(svc);
}

// ---------- IOSurface ----------

static IOSurfaceRef make_surface(const char *tag, uint64_t address, int use_addr,
                                 const char *region, int global, int compress) {
    int w = 64, h = 64;
    size_t bpr = 256;
    CFMutableDictionaryRef d = CFDictionaryCreateMutable(kCFAllocatorDefault, 0,
        &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
    CFNumberRef n;
    int32_t v32;
    v32 = w; n = CFNumberCreate(NULL, kCFNumberSInt32Type, &v32); CFDictionarySetValue(d, CFSTR("IOSurfaceWidth"), n); CFRelease(n);
    v32 = h; n = CFNumberCreate(NULL, kCFNumberSInt32Type, &v32); CFDictionarySetValue(d, CFSTR("IOSurfaceHeight"), n); CFRelease(n);
    v32 = (int32_t)0x42475241; n = CFNumberCreate(NULL, kCFNumberSInt32Type, &v32); CFDictionarySetValue(d, CFSTR("IOSurfacePixelFormat"), n); CFRelease(n);
    v32 = (int32_t)bpr; n = CFNumberCreate(NULL, kCFNumberSInt32Type, &v32); CFDictionarySetValue(d, CFSTR("IOSurfaceBytesPerRow"), n); CFRelease(n);
    if (use_addr) {
        n = CFNumberCreate(NULL, kCFNumberSInt64Type, &address);
        CFDictionarySetValue(d, CFSTR("IOSurfaceAddress"), n); CFRelease(n);
    }
    if (region && region[0]) {
        CFStringRef s = CFStringCreateWithCString(NULL, region, kCFStringEncodingUTF8);
        CFDictionarySetValue(d, CFSTR("IOSurfaceMemoryRegion"), s); CFRelease(s);
    }
    if (global) {
        CFDictionarySetValue(d, CFSTR("IOSurfaceIsGlobal"), kCFBooleanTrue);
    }
    if (compress) {
        v32 = 1; n = CFNumberCreate(NULL, kCFNumberSInt32Type, &v32);
        CFDictionarySetValue(d, CFSTR("IOSurfaceCompressionType"), n); CFRelease(n);
    }
    IOSurfaceRef surf = IOSurfaceCreate(d);
    CFRelease(d);
    if (!surf) {
        LOG(@"[SURF] %s: CREATE FAILED", tag);
        return NULL;
    }
    IOSurfaceID sid = IOSurfaceGetID(surf);
    void *base = IOSurfaceGetBaseAddress(surf);
    LOG(@"[SURF] %s: id=%u base=%p alloc=0x%zx bpr=0x%zx w=%zu h=%zu",
        tag, sid, base, IOSurfaceGetAllocSize(surf), IOSurfaceGetBytesPerRow(surf),
        IOSurfaceGetWidth(surf), IOSurfaceGetHeight(surf));
    if (base) {
        uint8_t b[32]; memset(b, 0, sizeof(b));
        memcpy(b, base, 16);
        b[0] = 0x5a; b[1] = 0x5b;
        LOG(@"[SURF] %s: first16=%s", tag, hexdump(b, 16).UTF8String);
    }
    return surf;
}

static void surface_tests(void) {
    LOG(@"[TEST] surfaces");
    // baseline
    IOSurfaceRef a = make_surface("baseline", 0, 0, NULL, 0, 0);
    if (a) CFRelease(a);

    // IOSurfaceAddress = user VA
    void *buf = mmap(NULL, 0x4000, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANON, -1, 0);
    if (buf != MAP_FAILED) {
        memset(buf, 0xaa, 0x4000);
        IOSurfaceRef s = make_surface("address-user", (uint64_t)(uintptr_t)buf, 1, NULL, 0, 0);
        if (s) {
            void *base = IOSurfaceGetBaseAddress(s);
            LOG(@"[SURF] address-user: requested=%p returned=%p equal=%d",
                buf, base, base == buf);
            IOSurfaceSetValue(s, CFSTR("IOSurfaceAddress"),
                (__bridge CFTypeRef)@((uint64_t)(uintptr_t)buf));
            LOG(@"[SURF] address-user: after set base=%p", IOSurfaceGetBaseAddress(s));
            CFRelease(s);
        }
        munmap(buf, 0x4000);
    } else {
        LOG(@"[SURF] mmap failed errno=%d", errno);
    }

    // memory-region names
    const char *regions[] = {"PurpleGfxMem", "gpu-region", "GFX", "GPU", "IOSurface", NULL};
    for (int i = 0; regions[i]; i++) {
        char tag[64]; snprintf(tag, sizeof(tag), "region-%s", regions[i]);
        IOSurfaceRef s = make_surface(tag, 0, 0, regions[i], 0, 0);
        if (s) CFRelease(s);
    }

    // global
    IOSurfaceRef g = make_surface("global", 0, 0, NULL, 1, 0);
    if (g) {
        IOSurfaceID gid = IOSurfaceGetID(g);
        IOSurfaceRef g2 = IOSurfaceLookup(gid);
        LOG(@"[SURF] global: id=%u lookup=%p same=%d", gid, g2, g2 == g);
        if (g2) CFRelease(g2);
        CFRelease(g);
    }

    // compressed
    IOSurfaceRef c = make_surface("compress", 0, 0, NULL, 0, 1);
    if (c) CFRelease(c);
}

static void global_surface_sweep(void) {
    LOG(@"[TEST] global IOSurface sweep");
    int found = 0;
    for (uint32_t sid = 1; sid <= 0x8000 && !gStop; sid++) {
        IOSurfaceRef s = IOSurfaceLookup(sid);
        if (!s) continue;
        found++;
        void *base = IOSurfaceGetBaseAddress(s);
        LOG(@"[GLOBAL] id=%u base=%p alloc=0x%zx bpr=0x%zx w=%zu h=%zu",
            sid, base, IOSurfaceGetAllocSize(s), IOSurfaceGetBytesPerRow(s),
            IOSurfaceGetWidth(s), IOSurfaceGetHeight(s));
        if (base) {
            uint8_t b[16]; memset(b, 0, sizeof(b));
            memcpy(b, base, 16);
            LOG(@"[GLOBAL] id=%u first16=%s", sid, hexdump(b, 16).UTF8String);
        }
        CFRelease(s);
        if (found >= 32) break;
        if ((sid & 0x3ff) == 0) LOG(@"[GLOBAL] progress %u found=%d", sid, found);
    }
    LOG(@"[GLOBAL] done found=%d", found);
}

// ---------- dedicated AGX / IOGPU ----------

static void agx_resource_tests(void) {
    LOG(@"[TEST] AGX/IOGPU resources");
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault,
                                                   IOServiceMatching("AGXAcceleratorG14P"));
    if (!svc) { LOG(@"[AGX] absent"); return; }
    io_connect_t conn = 0;
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), 1, &conn);
    LOG(@"[AGX] open type1 -> %s conn=%u", krstr(kr), conn);
    if (kr != KERN_SUCCESS || !conn) { IOObjectRelease(svc); return; }

    uint8_t in[0x800]; uint8_t out[0x1000];
    uint64_t sout[8]; uint32_t scout; size_t outsz;

    // sel 6: new command queue, exact 0x408
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out)); memset(sout, 0, sizeof(sout));
    scout = 8; outsz = sizeof(out);
    last_call("AGX", 1, 6, 0, 0x408);
    kr = IOConnectCallMethod(conn, 6, NULL, 0, in, 0x408, sout, &scout, out, &outsz);
    LOG(@"[AGX] sel6 0x408 -> %s scout=%u outsz=0x%zx id=%llx", krstr(kr), scout, outsz,
        (unsigned long long)sout[0]);
    if (kr == 0) {
        uint64_t qid = sout[0];
        // sel 7: delete queue (cleanup after logging)
        uint64_t sin[1] = {qid};
        kr = IOConnectCallMethod(conn, 7, sin, 1, NULL, 0, NULL, NULL, NULL, NULL);
        LOG(@"[AGX] sel7 delete qid=%llu -> %s", (unsigned long long)qid, krstr(kr));
    }

    // sel 8 resource: type 0x82 from a surface
    IOSurfaceRef surf = make_surface("agx-src", 0, 0, NULL, 0, 0);
    if (surf) {
        IOSurfaceID sid = IOSurfaceGetID(surf);
        memset(in, 0, sizeof(in));
        *(uint32_t *)(in + 0x00) = 0x82;
        *(uint32_t *)(in + 0x38) = sid;
        *(uint32_t *)(in + 0x3c) = 0;
        memset(out, 0, sizeof(out)); memset(sout, 0, sizeof(sout));
        scout = 8; outsz = sizeof(out);
        last_call("AGX", 1, 8, 0, 0x58);
        kr = IOConnectCallMethod(conn, 8, NULL, 0, in, 0x58, sout, &scout, out, &outsz);
        LOG(@"[AGX] sel8 type0x82 sid=%u -> %s scout=%u outsz=0x%zx out0=%llx",
            sid, krstr(kr), scout, outsz, (unsigned long long)sout[0]);
        if (kr == 0) LOG(@"[AGX] sel8 out:\n%@", hexdump(out, outsz > 0x80 ? 0x80 : outsz));
        CFRelease(surf);
    }

    // sel 8 resource: type 0 from user memory
    void *ub = mmap(NULL, 0x4000, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANON, -1, 0);
    if (ub != MAP_FAILED) {
        memset(ub, 0xcc, 0x4000);
        memset(in, 0, sizeof(in));
        *(uint32_t *)(in + 0x00) = 0;
        *(uint64_t *)(in + 0x18) = 0x4000;          // size / length
        *(uint64_t *)(in + 0x50) = (uint64_t)(uintptr_t)ub; // client VA
        memset(out, 0, sizeof(out)); memset(sout, 0, sizeof(sout));
        scout = 8; outsz = sizeof(out);
        last_call("AGX", 1, 8, 0, 0x58);
        kr = IOConnectCallMethod(conn, 8, NULL, 0, in, 0x58, sout, &scout, out, &outsz);
        LOG(@"[AGX] sel8 type0 userVA=%p -> %s scout=%u outsz=0x%zx out0=%llx",
            ub, krstr(kr), scout, outsz, (unsigned long long)sout[0]);
        if (kr == 0) LOG(@"[AGX] sel8 t0 out:\n%@", hexdump(out, outsz > 0x80 ? 0x80 : outsz));
        munmap(ub, 0x4000);
    }

    IOServiceClose(conn);
    IOObjectRelease(svc);
}

// ---------- MFB ----------

static void mfb_tests(void) {
    LOG(@"[TEST] IOMobileFramebuffer");
    const char *names[] = {"IOMobileFramebuffer", "IOMobileFramebufferService",
                           "IOMobileFramebufferUserClient", "IOMobileGraphicsFamily", NULL};
    for (int i = 0; names[i]; i++) probe_service(names[i], 0x40);

    // dedicated probe: open and feed an IOSurface id in scalar0
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault,
                                                   IOServiceMatching("IOMobileFramebuffer"));
    if (svc) {
        for (uint32_t type = 0; type <= 4; type++) {
            io_connect_t conn = 0;
            kern_return_t kr = IOServiceOpen(svc, mach_task_self(), type, &conn);
            LOG(@"[MFB] open type%u -> %s conn=%u", type, krstr(kr), conn);
            if (kr == KERN_SUCCESS && conn) {
                IOSurfaceRef s = make_surface("mfb-src", 0, 0, NULL, 0, 0);
                IOSurfaceID sid = s ? IOSurfaceGetID(s) : 0;
                for (uint32_t sel = 0; sel <= 0x10; sel++) {
                    uint64_t sin[2] = {sid, 0};
                    uint64_t sout[4] = {0};
                    uint32_t scout = 4;
                    uint8_t out[0x200]; size_t outsz = sizeof(out);
                    memset(out, 0, sizeof(out));
                    last_call("MFB", type, sel, 1, 0);
                    kr = IOConnectCallMethod(conn, sel, sin, 1, NULL, 0,
                                             sout, &scout, out, &outsz);
                    LOG(@"[MFB] t%u sel=0x%02x sid=%u -> %s outsz=0x%zx so0=0x%llx",
                        type, sel, sid, krstr(kr), outsz, (unsigned long long)sout[0]);
                    if (outsz && outsz <= sizeof(out)) scan_ptrs(out, outsz, @"MFB", 8);
                }
                if (s) CFRelease(s);
                IOServiceClose(conn);
            }
        }
        IOObjectRelease(svc);
    }
}

// ---------- the rest ----------

static void run_all(void) {
    if (gBusy) { LOG(@"[RUN] already running"); return; }
    gBusy = 1; gStop = 0;

    struct utsname u; uname(&u);
    LOG(@"[RUN] SPTMProbe2 start %@", [NSDate date]);
    LOG(@"[RUN] machine=%s release=%s uid=%u euid=%u pid=%d",
        u.machine, u.release, getuid(), geteuid(), getpid());
    LOG(@"[RUN] log=%@", gLogPath);

    surface_tests();
    global_surface_sweep();
    probe_service("IOSurfaceRoot", 0x0); // just open/type scan
    probe_service("AppleJPEGDriver", 0x10);
    probe_service("AppleM2ScalerCSCDriver", 0x10);
    probe_service("AppleT8110DART", 0x10);
    probe_service("AppleH11ANEInterface", 0x10);
    probe_service("AppleAVE2Driver", 0x10);
    probe_service("IOGPU", 0x40);
    probe_service("IOGPUDevice", 0x40);
    probe_service("AGXDevice", 0x40);
    probe_service("IOAccelerator", 0x20);

    agx_resource_tests();
    mfb_tests();

    LOG(@"[RUN] done %@", [NSDate date]);
    gBusy = 0;
}

// ---------- UI ----------

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (nonatomic) UIWindow *window;
@end

@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)opts {
    gLock = [NSLock new];
    gLog = [NSMutableString new];

    NSString *docs = docs_dir();
    gLogPath = [docs stringByAppendingPathComponent:@"SPTMProbe2.log"];
    gLastPath = [docs stringByAppendingPathComponent:@"SPTMProbe2-last.txt"];
    gFile = fopen(gLogPath.fileSystemRepresentation, "a");
    if (!gFile) {
        gLogPath = [NSTemporaryDirectory() stringByAppendingPathComponent:@"SPTMProbe2.log"];
        gFile = fopen(gLogPath.fileSystemRepresentation, "a");
    }

    UIViewController *vc = [UIViewController new];
    vc.view.backgroundColor = [UIColor blackColor];
    CGRect b = vc.view.bounds;

    gPathLabel = [[UILabel alloc] initWithFrame:CGRectMake(8, 40, b.size.width - 16, 44)];
    gPathLabel.textColor = [UIColor greenColor];
    gPathLabel.font = [UIFont monospacedSystemFontOfSize:11 weight:UIFontWeightRegular];
    gPathLabel.numberOfLines = 2;
    gPathLabel.text = gLogPath;
    [vc.view addSubview:gPathLabel];

    gPhaseLabel = [[UILabel alloc] initWithFrame:CGRectMake(8, 84, b.size.width - 16, 20)];
    gPhaseLabel.textColor = [UIColor yellowColor];
    gPhaseLabel.font = [UIFont monospacedSystemFontOfSize:11 weight:UIFontWeightBold];
    gPhaseLabel.text = @"idle";
    [vc.view addSubview:gPhaseLabel];

    gView = [[UITextView alloc] initWithFrame:CGRectMake(8, 108, b.size.width - 16, b.size.height - 160)];
    gView.textColor = [UIColor greenColor];
    gView.backgroundColor = [UIColor blackColor];
    gView.font = [UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];
    gView.editable = NO;
    gView.text = @"starting...";
    [vc.view addSubview:gView];

    UIButton *run = [UIButton buttonWithType:UIButtonTypeSystem];
    run.frame = CGRectMake(8, b.size.height - 44, 100, 34);
    [run setTitle:@"RUN" forState:UIControlStateNormal];
    [run addTarget:self action:@selector(onRun) forControlEvents:UIControlEventTouchUpInside];
    [vc.view addSubview:run];

    UIButton *stop = [UIButton buttonWithType:UIButtonTypeSystem];
    stop.frame = CGRectMake(116, b.size.height - 44, 100, 34);
    [stop setTitle:@"STOP" forState:UIControlStateNormal];
    [stop addTarget:self action:@selector(onStop) forControlEvents:UIControlEventTouchUpInside];
    [vc.view addSubview:stop];

    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    self.window.rootViewController = vc;
    [self.window makeKeyAndVisible];

    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1.0 * NSEC_PER_SEC)),
                   dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{
        run_all();
    });
    return YES;
}

- (void)onRun {
    dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{ run_all(); });
}
- (void)onStop { gStop = 1; LOG(@"[RUN] stop requested"); }
@end

int main(int argc, char **argv) {
    @autoreleasepool { return UIApplicationMain(argc, argv, nil, @"AppDelegate"); }
}
