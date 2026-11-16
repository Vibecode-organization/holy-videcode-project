#import <UIKit/UIKit.h>
#import <IOKit/IOKitLib.h>
#import <IOSurface/IOSurfaceRef.h>
#import <Foundation/Foundation.h>
#import <sys/utsname.h>
#import <string.h>
#import <stdlib.h>

static NSMutableString *gLog;
static NSString *gPath;
static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    [gLog appendString:s]; [gLog appendString:@"\n"];
    [gLog writeToFile:gPath atomically:YES encoding:NSUTF8StringEncoding error:nil];
    NSLog(@"[shmemprobe] %@", s);
}

static io_connect_t open_svc(const char *name, uint32_t type) {
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching(name));
    if (!svc) { L(@"[SVC] %s absent", name); return 0; }
    io_connect_t c = 0;
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), type, &c);
    L(@"[SVC] %s type=%u -> 0x%x conn=0x%x", name, type, kr, c);
    IOObjectRelease(svc);
    return kr == KERN_SUCCESS ? c : 0;
}

typedef struct { mach_vm_address_t start, end; vm_prot_t prot; } VReg;
static VReg gSnap[512]; static int gSnapN;

static void snap_regions(void) {
    gSnapN = 0;
    mach_vm_address_t addr = 0;
    while (gSnapN < 512) {
        mach_vm_size_t size = 0;
        vm_region_basic_info_data_64_t info;
        mach_msg_type_number_t cnt = VM_REGION_BASIC_INFO_COUNT_64;
        mach_port_t obj = 0;
        kern_return_t kr = mach_vm_region(mach_task_self(), &addr, &size,
                                          VM_REGION_BASIC_INFO_64,
                                          (vm_region_info_t)&info, &cnt, &obj);
        if (kr != KERN_SUCCESS || size == 0) break;
        if (info.protection != 0) {
            gSnap[gSnapN].start = addr; gSnap[gSnapN].end = addr + size;
            gSnap[gSnapN].prot = info.protection; gSnapN++;
        }
        addr += size;
    }
}

static void diff_regions(const char *tag) {
    VReg cur[512]; int cn = 0;
    mach_vm_address_t addr = 0;
    while (cn < 512) {
        mach_vm_size_t size = 0;
        vm_region_basic_info_data_64_t info;
        mach_msg_type_number_t cnt = VM_REGION_BASIC_INFO_COUNT_64;
        mach_port_t obj = 0;
        kern_return_t kr = mach_vm_region(mach_task_self(), &addr, &size,
                                          VM_REGION_BASIC_INFO_64,
                                          (vm_region_info_t)&info, &cnt, &obj);
        if (kr != KERN_SUCCESS || size == 0) break;
        if (info.protection != 0) {
            cur[cn].start = addr; cur[cn].end = addr + size;
            cur[cn].prot = info.protection; cn++;
        }
        addr += size;
    }
    int added = 0;
    for (int i = 0; i < cn; i++) {
        int found = 0;
        for (int j = 0; j < gSnapN; j++)
            if (gSnap[j].start == cur[i].start && gSnap[j].end == cur[i].end) { found = 1; break; }
        if (!found) {
            L(@"[VM] %s NEW region 0x%llx-0x%llx prot=0x%x", tag,
              (unsigned long long)cur[i].start, (unsigned long long)cur[i].end, cur[i].prot);
            added++;
            if (added > 16) break;
        }
    }
    L(@"[VM] %s regions %d -> %d, new=%d", tag, gSnapN, cn, added);
    memcpy(gSnap, cur, sizeof(VReg) * cn); gSnapN = cn;
}

static void check_addr(uint64_t a, const char *tag) {
    for (int i = 0; i < gSnapN; i++) {
        if (gSnap[i].start <= a && a < gSnap[i].end) {
            L(@"[VM] %s addr=0x%llx in region 0x%llx-0x%llx prot=0x%x", tag,
              (unsigned long long)a, (unsigned long long)gSnap[i].start,
              (unsigned long long)gSnap[i].end, gSnap[i].prot);
            return;
        }
    }
    L(@"[VM] %s addr=0x%llx NOT in any mapped region", tag, (unsigned long long)a);
}

static void scan_page(uint64_t va, size_t len, const char *tag) {
    if (!va) return;
    uint8_t *tmp = malloc(len);
    if (!tmp) return;
    mach_vm_size_t got = 0;
    kern_return_t kr = mach_vm_read_overwrite(mach_task_self(), (mach_vm_address_t)va, len,
                                              (mach_vm_address_t)tmp, &got);
    L(@"[SCAN] %s va=0x%llx len=0x%zx -> 0x%x got=0x%llx", tag,
      (unsigned long long)va, len, kr, (unsigned long long)got);
    if (kr == KERN_SUCCESS) {
        int hits = 0;
        for (size_t i = 0; i + 8 <= got; i += 8) {
            uint64_t v = *(uint64_t *)(tmp + i);
            if ((v >> 40) == 0xffffff || (v >> 32) == 0xfffffff0) {
                L(@"[SCAN] %s +0x%zx = 0x%016llx", tag, i, (unsigned long long)v);
                if (++hits >= 24) break;
            }
        }
        L(@"[SCAN] %s kernel-like=%d", tag, hits);
    }
    free(tmp);
}

// Prepare an IO command buffer and return its shmem address (field +0x38).
static uint64_t make_cb(io_connect_t c, uint32_t *qid_out, uint32_t *cb_out) {
    uint64_t s14[2] = {0x10, 0x10};
    uint8_t o14[0x10] = {0}; size_t o14sz = sizeof(o14);
    kern_return_t kr = IOConnectCallMethod(c, 14, s14, 2, NULL, 0, NULL, NULL, o14, &o14sz);
    L(@"[CB] sel14 -> 0x%x id=0x%llx", kr, (unsigned long long)*(uint64_t *)o14);
    if (kr) return 0;
    scan_page(*(uint64_t *)o14, 0x4000, "sel14");

    uint64_t s42[2] = {0,0}, o42[2] = {0}; uint32_t o42c = 2;
    kr = IOConnectCallMethod(c, 42, s42, 2, NULL, 0, o42, &o42c, NULL, NULL);
    L(@"[CB] sel42 -> 0x%x qid=0x%llx", kr, (unsigned long long)o42[0]);
    if (kr || !o42[0]) return 0;
    uint32_t qid = (uint32_t)o42[0];

    uint32_t nid = (uint32_t)*(uint64_t *)(o14 + 8);
    uint64_t s44[2] = {qid, nid};
    kr = IOConnectCallMethod(c, 44, s44, 2, NULL, 0, NULL, NULL, NULL, NULL);
    L(@"[CB] sel44 q=%u n=%u -> 0x%x", qid, nid, kr);

    uint64_t s46[1] = {qid}, so46[2] = {0}; uint32_t soc46 = 2;
    kr = IOConnectCallMethod(c, 46, s46, 1, NULL, 0, so46, &soc46, NULL, NULL);
    L(@"[CB] sel46 -> 0x%x cbId=0x%llx f=0x%llx", kr,
      (unsigned long long)so46[0], (unsigned long long)so46[1]);
    if (qid_out) *qid_out = qid;
    if (cb_out) *cb_out = (uint32_t)so46[0];
    return so46[1];
}

// Create a resType=0x80 sysmemory resource over our own buffer, detach it,
// then exercise replace_backing_bytes/ranges with a user VA and a kernel VA.
static void sysmem_test(io_connect_t c, const char *tag) {
    void *ub = NULL;
    if (posix_memalign(&ub, 0x4000, 0x4000) != 0 || !ub) { L(@"[SYSM] %s alloc failed", tag); return; }
    memset(ub, 0x5A, 0x4000);
    uint64_t start = (uint64_t)(uintptr_t)ub;
    uint64_t size = 0x4000;
    uint64_t end = start + size;

    uint8_t in[0x100]; memset(in, 0, sizeof(in));
    *(uint32_t *)(in + 0x00) = 0x80;      // resType: sysmemory
    *(uint64_t *)(in + 0x38) = end;       // extent end
    *(uint64_t *)(in + 0x40) = start;     // extent start
    *(uint64_t *)(in + 0x48) = size;      // size
    uint8_t out[0x1000]; memset(out, 0, sizeof(out)); size_t osz = sizeof(out);
    kern_return_t kr = IOConnectCallStructMethod(c, 8, in, sizeof(in), out, &osz);
    uint32_t rid = *(uint32_t *)(out + 0x24);
    L(@"[SYSM] %s create type80 -> 0x%x osz=0x%zx rid=%u q0=0x%llx q3=0x%llx",
      tag, kr, osz, rid, (unsigned long long)*(uint64_t *)out,
      (unsigned long long)*(uint64_t *)(out + 0x30));
    if (kr != 0 || rid == 0) return;

    uint64_t s37[1] = {rid};
    kr = IOConnectCallScalarMethod(c, 37, s37, 1, NULL, NULL);
    L(@"[SYSM] %s detach rid=%u -> 0x%x", tag, rid, kr);

    struct __attribute__((packed)) RB { uint32_t rid; uint32_t flags; uint64_t addr; uint64_t len; };
    struct __attribute__((packed)) RR { uint64_t addr; uint64_t len; };

    struct RB rb = { rid, 0, start, size };
    kr = IOConnectCallStructMethod(c, 38, &rb, sizeof(rb), NULL, NULL);
    L(@"[SYSM] %s replace-bytes own -> 0x%x", tag, kr);

    rb.addr = 0xfffffff007004000ULL;
    kr = IOConnectCallStructMethod(c, 38, &rb, sizeof(rb), NULL, NULL);
    L(@"[SYSM] %s replace-bytes kva -> 0x%x", tag, kr);

    struct RR rng = { start, size };
    struct RB rr = { rid, 2, (uint64_t)(uintptr_t)&rng, 1 };
    uint64_t so = 0; uint32_t soc = 1;
    kr = IOConnectCallMethod(c, 39, NULL, 0, &rr, sizeof(rr), &so, &soc, NULL, NULL);
    L(@"[SYSM] %s replace-ranges own -> 0x%x out=0x%llx", tag, kr, (unsigned long long)so);

    struct RR krng = { 0xfffffff007004000ULL, 0x4000 };
    struct RB krr = { rid, 2, (uint64_t)(uintptr_t)&krng, 1 };
    so = 0; soc = 1;
    kr = IOConnectCallMethod(c, 39, NULL, 0, &krr, sizeof(krr), &so, &soc, NULL, NULL);
    L(@"[SYSM] %s replace-ranges kva -> 0x%x out=0x%llx", tag, kr, (unsigned long long)so);

    // Read back the first bytes of our buffer to see if anything changed.
    uint8_t *p = (uint8_t *)ub;
    L(@"[SYSM] %s ub[0..7]=%02x %02x %02x %02x %02x %02x %02x %02x",
      tag, p[0],p[1],p[2],p[3],p[4],p[5],p[6],p[7]);
}

// IOSurface created from a client address: user VA control and kernel VA test.
static void surface_addr_test(uint64_t addr, const char *tag) {
    NSDictionary *d = @{
        @"IOSurfaceWidth": @1024,
        @"IOSurfaceHeight": @64,
        @"IOSurfaceBytesPerElement": @4,
        @"IOSurfaceBytesPerRow": @4096,
        @"IOSurfaceAllocSize": @0x40000,
        @"IOSurfacePixelFormat": @0x42475241,
        @"IOSurfaceAddress": @(addr)
    };
    IOSurfaceRef s = IOSurfaceCreate((__bridge CFDictionaryRef)d);
    if (!s) { L(@"[SADDR] %s addr=0x%llx -> create failed", tag, (unsigned long long)addr); return; }
    void *ba = IOSurfaceGetBaseAddress(s);
    size_t as = IOSurfaceGetAllocSize(s);
    L(@"[SADDR] %s addr=0x%llx -> id=%u base=%p alloc=0x%zx", tag,
      (unsigned long long)addr, IOSurfaceGetID(s), ba, as);
    if (ba) {
        mach_vm_size_t got = 0; uint8_t tmp[8];
        kern_return_t rr = mach_vm_read_overwrite(mach_task_self(),
            (mach_vm_address_t)ba, 8, (mach_vm_address_t)tmp, &got);
        L(@"[SADDR] %s vm_read(base) -> 0x%x got=0x%llx", tag, rr, (unsigned long long)got);
    }
    CFRelease(s);
}

static void service_sweep(void) {
    const char *names[] = {
        "AppleAVE2Driver", "AppleH11ANEInterface", "AppleJPEGDriver",
        "IOMobileFramebuffer", "IOMobileFramebufferShim",
        "AppleMobileDispH14P-DCP", "IOMobileGraphicsFamily",
        "AppleSMC", "AppleSEPManager", "AppleDisplay",
        "AppleM2ScalerCSCDriver", "IOGPU", "AGXAcceleratorG14P"
    };
    for (unsigned i = 0; i < sizeof(names)/sizeof(names[0]); i++) {
        io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault,
                                                       IOServiceMatching(names[i]));
        if (!svc) { L(@"[GATE] %s absent", names[i]); continue; }
        for (uint32_t t = 0; t < 4; t++) {
            io_connect_t c = 0;
            kern_return_t kr = IOServiceOpen(svc, mach_task_self(), t, &c);
            L(@"[GATE] %s type=%u -> 0x%x conn=0x%x", names[i], t, kr, c);
            if (kr == KERN_SUCCESS && c) IOServiceClose(c);
        }
        IOObjectRelease(svc);
    }
}

static void selector_sweep(io_connect_t c, const char *tag, int maxsel) {
    for (int sel = 0; sel < maxsel; sel++) {
        uint64_t s[2] = {0, 0};
        uint64_t o[2] = {0, 0}; uint32_t oc = 2;
        kern_return_t kr = IOConnectCallScalarMethod(c, sel, s, 1, o, &oc);
        if (kr != 0xe00002c7 && kr != 0xe00000f9 && kr != 0xe00002c2)
            L(@"[SEL] %s sel=%d 1s -> 0x%x oc=%u out=%llx,%llx", tag, sel, kr, oc,
              (unsigned long long)o[0], (unsigned long long)o[1]);
        uint8_t sin[0x100]; memset(sin, 0, sizeof(sin));
        uint8_t sout[0x200]; memset(sout, 0, sizeof(sout)); size_t osz = sizeof(sout);
        kr = IOConnectCallMethod(c, sel, s, 1, sin, 0x20, NULL, NULL, sout, &osz);
        if (kr != 0xe00002c7 && kr != 0xe00000f9 && kr != 0xe00002c2 && kr != 0xe00002bc)
            L(@"[SEL] %s sel=%d 1s+0x20 -> 0x%x osz=0x%zx", tag, sel, kr, osz);
    }
}

static void selector_sweep2(io_connect_t c, const char *tag, int maxsel) {
    static const uint32_t scs[] = {0, 1, 2, 3, 4};
    static const size_t sis[] = {0, 0x8, 0x10, 0x18, 0x20, 0x28, 0x30, 0x40, 0x100};
    int hits = 0;
    for (int sel = 0; sel < maxsel; sel++) {
        for (unsigned a = 0; a < sizeof(scs)/sizeof(scs[0]); a++) {
            for (unsigned b = 0; b < sizeof(sis)/sizeof(sis[0]); b++) {
                uint64_t sv[4] = {0x4000, 0x40, 1, 0};
                uint8_t sin[0x100]; memset(sin, 0, sizeof(sin));
                uint8_t sout[0x1000]; memset(sout, 0, sizeof(sout));
                size_t osz = sizeof(sout);
                kern_return_t kr = IOConnectCallMethod(c, sel, sv, scs[a],
                    sis[b] ? sin : NULL, sis[b], NULL, NULL, sout, &osz);
                if (kr == 0) {
                    L(@"[SEL2] %s sel=%d sc=%u si=0x%zx OK osz=0x%zx out=%02x%02x%02x%02x",
                      tag, sel, scs[a], sis[b], osz, sout[0],sout[1],sout[2],sout[3]);
                    if (++hits > 120) return;
                } else if (kr != 0xe00002c2 && kr != 0xe00002c7 && kr != 0xe00000f9 &&
                           kr != 0xe00002bc && kr != 0xe00002e2) {
                    L(@"[SEL2] %s sel=%d sc=%u si=0x%zx -> 0x%x", tag, sel, scs[a], sis[b], kr);
                }
            }
        }
    }
    L(@"[SEL2] %s done hits=%d", tag, hits);
}

static void map_probe(io_connect_t c, const char *tag) {
    for (uint32_t t = 0; t < 10; t++) {
        mach_vm_address_t addr = 0;
        mach_vm_size_t size = 0x4000;
        kern_return_t kr = IOConnectMapMemory64(c, t, mach_task_self(), &addr, &size, kIOMapAnywhere);
        L(@"[MAP] %s type=%u -> 0x%x addr=0x%llx size=0x%llx", tag, t, kr,
          (unsigned long long)addr, (unsigned long long)size);
        if (kr == KERN_SUCCESS && addr) {
            scan_page(addr, size < 0x4000 ? size : 0x4000, tag);
            IOConnectUnmapMemory64(c, t, mach_task_self(), addr);
        }
    }
}

static void new_surface_probe(const char *name) {
    for (uint32_t t = 0; t < 4; t++) {
        io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching(name));
        if (!svc) { L(@"[NS] %s absent", name); return; }
        io_connect_t c = 0;
        kern_return_t kr = IOServiceOpen(svc, mach_task_self(), t, &c);
        IOObjectRelease(svc);
        if (kr != KERN_SUCCESS || !c) { L(@"[NS] %s t=%u open -> 0x%x", name, t, kr); continue; }
        L(@"[NS] %s t=%u conn=0x%x", name, t, c);
        selector_sweep2(c, name, 64);
        map_probe(c, name);
        IOServiceClose(c);
        return;
    }
}

static void run(void) {
    struct utsname u; uname(&u);
    service_sweep();
    L(@"=== ShmemProbe2 start %s %s ===", u.machine, u.version);

    io_connect_t iogpu = open_svc("IOGPU", 1);
    io_connect_t agx = open_svc("AGXAcceleratorG14P", 1);
    if (iogpu) {
        snap_regions();
        uint32_t qid = 0, cb = 0;
        uint64_t f = make_cb(iogpu, &qid, &cb);
        L(@"[IOGPU] cmd shmem f=0x%llx qid=%u cb=%u", (unsigned long long)f, qid, cb);
        diff_regions("after-cb");
        check_addr(f, "f");
        check_addr(f & ~0xfffULL, "f-page");
        // Trigger command processing, then check whether the shmem became mapped.
        if (qid && cb) {
            uint8_t si[0x40]; memset(si, 0, sizeof(si));
            *(uint32_t *)si = 0;
            uint64_t s45[1] = { (uint64_t)qid };
            kern_return_t k45 = IOConnectCallMethod(iogpu, 45, s45, 1, si, 0x20, NULL, NULL, NULL, NULL);
            L(@"[IOGPU] sel45 empty cb=%u -> 0x%x", cb, k45);
            diff_regions("after-sel45");
            check_addr(f, "f-after45");
        }
        sysmem_test(iogpu, "IOGPU");
    }
    if (agx) {
        uint32_t qid = 0, cb = 0;
        uint64_t f = make_cb(agx, &qid, &cb);
        L(@"[AGX] cmd shmem f=0x%llx qid=%u cb=%u", (unsigned long long)f, qid, cb);
        sysmem_test(agx, "AGX");
    }

    // Control: user address in our own task.
    void *ub = NULL;
    if (posix_memalign(&ub, 0x4000, 0x40000) == 0) {
        memset(ub, 0x33, 0x40000);
        surface_addr_test((uint64_t)(uintptr_t)ub, "user");
    }
    // Kernel text / kernel data addresses.
    surface_addr_test(0xfffffff007004000ULL, "ktext");
    surface_addr_test(0xfffffff00af48000ULL, "kdata");

    new_surface_probe("IOMobileFramebuffer");
    new_surface_probe("AppleJPEGDriver");

    L(@"=== done ===");
    if (iogpu) IOServiceClose(iogpu);
    if (agx) IOServiceClose(agx);
}

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (strong, nonatomic) UIWindow *window;
@end
@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)opts {
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    UIViewController *vc = [UIViewController new];
    vc.view.backgroundColor = UIColor.blackColor;
    UITextView *tv = [[UITextView alloc] initWithFrame:vc.view.bounds];
    tv.backgroundColor = UIColor.blackColor; tv.textColor = UIColor.greenColor;
    tv.font = [UIFont monospacedSystemFontOfSize:9 weight:UIFontWeightRegular];
    tv.editable = NO; tv.text = @"ShmemProbe2\n";
    [vc.view addSubview:tv]; self.window.rootViewController = vc;
    [self.window makeKeyAndVisible];
    [UIApplication sharedApplication].idleTimerDisabled = YES;
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0), ^{
        NSString *docs = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject];
        gPath = [docs stringByAppendingPathComponent:@"shmem.log"];
        gLog = [NSMutableString new];
        run();
        dispatch_async(dispatch_get_main_queue(), ^{ tv.text = gLog; });
    });
    return YES;
}
@end
int main(int argc, char **argv) { @autoreleasepool { return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class])); } }
