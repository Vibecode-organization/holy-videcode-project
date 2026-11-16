// ctlab — entitlement / AMFI user client probe.
// build: arm64, iOS 14.0 target, runs on 27.2.
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <Security/Security.h>
#import <mach/mach.h>
#import <sys/sysctl.h>
#import <unistd.h>
#import <errno.h>
#import <dlfcn.h>

// IOKit is not in the stripped SDK headers; declare the small surface we use.
typedef mach_port_t io_object_t;
typedef io_object_t io_service_t;
typedef io_object_t io_connect_t;
extern io_service_t IOServiceGetMatchingService(mach_port_t masterPort, CFDictionaryRef matching);
extern CFMutableDictionaryRef IOServiceMatching(const char *name);
extern kern_return_t IOServiceOpen(io_service_t service, task_port_t owningTask, uint32_t type, io_connect_t *connect);
extern kern_return_t IOServiceClose(io_connect_t connect);
extern kern_return_t IOObjectRelease(io_object_t object);
extern kern_return_t IOConnectCallScalarMethod(io_connect_t connection, uint32_t selector,
                                               const uint64_t *input, uint32_t inputCnt,
                                               uint64_t *output, uint32_t *outputCnt);
extern kern_return_t IOConnectCallStructMethod(io_connect_t connection, uint32_t selector,
                                               const void *inputStruct, size_t inputStructCnt,
                                               void *outputStruct, size_t *outputStructCnt);

extern int csops(pid_t pid, unsigned int ops, void *useraddr, size_t usersize);
#define CS_OPS_STATUS 0
#define CS_OPS_ENTITLEMENTS_BLOB 7

static FILE *gF;
static void L(NSString *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    NSString *s = [[NSString alloc] initWithFormat:fmt arguments:ap];
    va_end(ap);
    fprintf(gF, "%s\n", s.UTF8String);
    fflush(gF);
}

static NSString *homeDir(void) { return NSHomeDirectory(); }

static void dumpEntitlements(void) {
    unsigned char buf[16384];
    memset(buf, 0, sizeof(buf));
    int r = csops(getpid(), CS_OPS_ENTITLEMENTS_BLOB, buf, sizeof(buf));
    L(@"csops(ents) -> %d errno=%d", r, errno);
    if (r != 0) return;
    uint32_t magic = ntohl(*(uint32_t *)buf);
    uint32_t len = ntohl(*(uint32_t *)(buf + 4));
    L(@"ents magic=%08x len=%u", magic, len);
    if (len > sizeof(buf) - 8) len = sizeof(buf) - 8;
    NSData *d = [NSData dataWithBytes:buf + 8 length:len];
    NSString *txt = [[NSString alloc] initWithData:d encoding:NSUTF8StringEncoding];
    if (txt) L(@"ents-xml:\n%@", txt);
    else L(@"ents-hex: %@", [d description]);
}

static void probeAMFI(void) {
    io_service_t svc = IOServiceGetMatchingService(0, IOServiceMatching("AppleMobileFileIntegrity"));
    L(@"AMFI service=0x%x", svc);
    if (!svc) return;
    io_connect_t conn = 0;
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), 0, &conn);
    L(@"IOServiceOpen(AMFI) -> 0x%x conn=0x%x", kr, conn);
    if (kr != KERN_SUCCESS) { IOObjectRelease(svc); return; }

    // Probe selectors 0..12 with zero input; log return codes.
    for (uint32_t sel = 0; sel <= 12; sel++) {
        uint64_t in[8] = {0};
        uint64_t out[16] = {0};
        uint32_t outCnt = 16;
        kr = IOConnectCallScalarMethod(conn, sel, in, 0, out, &outCnt);
        L(@"AMFI scalar sel=%u -> 0x%x outCnt=%u", sel, kr, outCnt);
    }
    // Try loadTrustCache with a minimal v1 blob: magic/version 1, count 0.
    struct { uint32_t version; uint32_t count; } tc = {1, 0};
    uint64_t out[4] = {0}; size_t outCnt = 4;
    kr = IOConnectCallStructMethod(conn, 1, &tc, sizeof(tc), out, &outCnt);
    L(@"AMFI struct sel=1 (tc v1 count0) -> 0x%x outCnt=%zu", kr, outCnt);

    IOServiceClose(conn);
    IOObjectRelease(svc);
}

static void probeFilesystem(void) {
    NSFileManager *fm = [NSFileManager defaultManager];
    NSError *e = nil;
    NSArray *a = [fm contentsOfDirectoryAtPath:@"/var/mobile/Library/Preferences" error:&e];
    L(@"ls /var/mobile/Library/Preferences -> %lu err=%@", (unsigned long)a.count, e.localizedDescription);
    NSString *marker = @"/var/mobile/Library/Preferences/ctlab_marker";
    BOOL ok = [@"ctlab" writeToFile:marker atomically:YES encoding:NSUTF8StringEncoding error:&e];
    L(@"write %@ -> %d err=%@", marker, ok, e.localizedDescription);
    e = nil;
    ok = [@"ctlab" writeToFile:@"/tmp/ctlab_marker" atomically:YES encoding:NSUTF8StringEncoding error:&e];
    L(@"write /tmp/ctlab_marker -> %d err=%@", ok, e.localizedDescription);
    e = nil;
    a = [fm contentsOfDirectoryAtPath:@"/" error:&e];
    L(@"ls / -> %lu err=%@", (unsigned long)a.count, e.localizedDescription);
}

static NSString *sysctlStr(const char *n) {
    size_t sz = 0; if (sysctlbyname(n, NULL, &sz, NULL, 0) != 0 || sz == 0 || sz > 4096) return @"?";
    char *b = calloc(1, sz + 1);
    if (sysctlbyname(n, b, &sz, NULL, 0) != 0) { free(b); return @"?"; }
    NSString *s = [NSString stringWithUTF8String:b] ?: @"?"; free(b); return s;
}

int main(int argc, char **argv) {
    @autoreleasepool {
        NSString *docs = [homeDir() stringByAppendingPathComponent:@"Documents"];
        [[NSFileManager defaultManager] createDirectoryAtPath:docs withIntermediateDirectories:YES attributes:nil error:nil];
        gF = fopen([[docs stringByAppendingPathComponent:@"ctlab.log"] UTF8String], "a");
        if (!gF) gF = stderr;
        L(@"=== ctlab start ===");
        L(@"os=%@ build=%@ model=%@", [[UIDevice currentDevice] systemVersion], sysctlStr("kern.osversion"), sysctlStr("hw.model"));
        L(@"uid=%d euid=%d pid=%d home=%@", getuid(), geteuid(), getpid(), homeDir());
        dumpEntitlements();
        probeFilesystem();
        probeAMFI();
        L(@"=== ctlab done ===");
        if (gF != stderr) fclose(gF);
    }
    return 0;
}
