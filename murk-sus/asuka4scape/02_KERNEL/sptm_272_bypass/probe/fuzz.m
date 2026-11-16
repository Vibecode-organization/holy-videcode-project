#import "fuzz.h"
#import "logger.h"
#import <IOKit/IOKitLib.h>
#import <string.h>
#import <stdlib.h>
#import <sys/mman.h>

static NSString *g_lastPath = nil;

NSString *fuzz_last_config_path(void) { return g_lastPath; }

static uint64_t rng_state = 0x9e3779b97f4a7c15ULL;
static uint64_t rnd64(void)
{
    rng_state ^= rng_state << 13;
    rng_state ^= rng_state >> 7;
    rng_state ^= rng_state << 17;
    return rng_state;
}

static void ensure_last_path(void)
{
    if (g_lastPath) return;
    NSArray *dirs = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,
                                                        NSUserDomainMask, YES);
    NSString *docs = dirs.count ? dirs[0] : NSTemporaryDirectory();
    NSString *folder = [docs stringByAppendingPathComponent:@"SPTM272Logs"];
    [[NSFileManager defaultManager] createDirectoryAtPath:folder
                              withIntermediateDirectories:YES
                                               attributes:nil
                                                    error:NULL];
    g_lastPath = [folder stringByAppendingPathComponent:@"last_config.bin"];
}

// Writes the full call descriptor + struct bytes and fsyncs before the call.
static void dump_last(NSString *tag, uint32_t sel, const uint64_t *scalars,
                      uint32_t scalarCount, const uint8_t *buf, size_t len)
{
    ensure_last_path();
    NSMutableData *d = [NSMutableData data];
    NSString *head = [NSString stringWithFormat:
        @"tag=%@ sel=0x%x scalars=%u struct=%zu time=%@\n", tag, sel,
        scalarCount, len, [NSDate date]];
    [d appendData:[head dataUsingEncoding:NSUTF8StringEncoding]];
    for (uint32_t i = 0; i < scalarCount; i++) {
        NSString *s = [NSString stringWithFormat:@"scalar[%u]=0x%llx\n", i,
                       (unsigned long long)scalars[i]];
        [d appendData:[s dataUsingEncoding:NSUTF8StringEncoding]];
    }
    [d appendData:[@"struct:\n" dataUsingEncoding:NSUTF8StringEncoding]];
    if (buf && len) [d appendBytes:buf length:len];
    [d appendData:[@"\n" dataUsingEncoding:NSUTF8StringEncoding]];
    [d writeToFile:g_lastPath atomically:YES];
    log_flush();
}

// structIn sizes for IOSurfaceRoot table A (0xffffffff = any, -1 = none).
static const int64_t kSurfaceIn[60] = {
    0xffffffff, 0, 0xc, 0xc, 0, 0, 0x20, 0, 0, -1,
    0xffffffff, 0xffffffff, 0, 0, 0, 0, 0, 0x18, 0x18, 0xffffffff,
    0, 0, 0, 0, 0xffffffff, 0, 0xffffffff, 0xa0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0xffffffff, 0xffffffff, 0xffffffff, 0,
    0xffffffff, 0, 0, 0, 0xffffffff, 0, 0, 0, 0, 0,
};
static const int32_t kSurfaceScalarsIn[60] = {
    1, 1, 0, 0, 1, 2, 0, 2, 1, 0,
    0, 0, 3, 0, 2, 2, 1, 0, 0, 0,
    2, 4, 2, 1, 0, 1, 0, 0, 1, 2,
    1, 3, 0, 3, 1, 2, 1, 2, 1, 5,
    0, 1, 4, 4, 4, 3, 0, 1, 1, 1,
    2, 2, 1, 1, 0, 1, 2, 4, 5, 1,
};

static size_t pick_any_size(uint64_t r)
{
    static const size_t sizes[] = {0, 4, 0xc, 0x10, 0x20, 0x40, 0x100, 0x400, 0x1000};
    return sizes[r % (sizeof(sizes) / sizeof(sizes[0]))];
}

NSString *fuzz_iosurface(int iterations)
{
    NSMutableArray<NSString *> *lines = [NSMutableArray array];
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault,
                                                   IOServiceMatching("IOSurfaceRoot"));
    if (svc == IO_OBJECT_NULL) {
        return @"fuzz: IOSurfaceRoot absent";
    }
    io_connect_t conn = IO_OBJECT_NULL;
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), 0, &conn);
    IOObjectRelease(svc);
    if (kr != KERN_SUCCESS) {
        return [NSString stringWithFormat:@"fuzz: IOSurfaceRoot open kr=0x%x", kr];
    }
    log_write(@"fuzz: IOSurfaceRoot conn=%u iterations=%d", conn, iterations);

    uint8_t *buf = calloc(1, 0x1000);
    uint8_t *out = calloc(1, 0x1000);
    uint64_t scalars[8];

    for (uint32_t sel = 0; sel < 60; sel++) {
        int64_t declared = kSurfaceIn[sel];
        int32_t scalarCount = kSurfaceScalarsIn[sel];
        if (scalarCount < 0) scalarCount = 0;
        if (scalarCount > 8) scalarCount = 8;

        size_t sizes[9];
        int sizeCount = 0;
        if (declared == -1 || declared == 0) {
            sizes[sizeCount++] = 0;
        }
        else if (declared == 0xffffffff) {
            for (int i = 0; i < 9; i++) sizes[sizeCount++] = i == 0 ? 0 : pick_any_size((uint64_t)i * 7);
        }
        else {
            sizes[sizeCount++] = (size_t)declared;
        }

        for (int it = 0; it < iterations; it++) {
            for (int s = 0; s < sizeCount; s++) {
                size_t len = sizes[s];
                if (len > 0x1000) len = 0x1000;
                memset(buf, 0, 0x1000);
                for (size_t i = 0; i < len; i++) buf[i] = (uint8_t)rnd64();
                for (int i = 0; i < 8; i++) scalars[i] = rnd64();

                dump_last(@"IOSurfaceRoot", sel, scalars, (uint32_t)scalarCount, buf, len);
                memset(out, 0, 0x1000);
                uint32_t outCnt = 0x1000;
                size_t outSize = 0;
                kern_return_t r = IOConnectCallMethod(conn, sel, scalars, scalarCount,
                                                      buf, len, NULL, &outCnt,
                                                      out, &outSize);
                if (r != (kern_return_t)0xe00002bc && r != (kern_return_t)0xe00002c7) {
                    NSString *line = [NSString stringWithFormat:
                        @"fuzz: IOSurface sel=0x%x len=0x%zx kr=0x%x out=%zu",
                        sel, len, r, outSize];
                    [lines addObject:line];
                    log_write(@"%@", line);
                }
            }
        }
        usleep(2000);
    }
    free(buf);
    free(out);
    IOServiceClose(conn);
    log_write(@"fuzz: IOSurface done");
    return [lines componentsJoinedByString:@"\n"];
}


NSString *scaler_targeted_probe(void)
{
    NSMutableArray<NSString *> *lines = [NSMutableArray array];
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault,
                                                   IOServiceMatching("AppleM2ScalerCSCDriver"));
    if (svc == IO_OBJECT_NULL) return @"targeted: Scaler absent";
    io_connect_t conn = IO_OBJECT_NULL;
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), 0, &conn);
    IOObjectRelease(svc);
    if (kr != KERN_SUCCESS) return [NSString stringWithFormat:@"targeted: open kr=0x%x", kr];

    // sel 11: provider dump
    uint8_t out[0x400] = {0};
    uint32_t outCnt = (uint32_t)sizeof(out);
    size_t outSize = 0;
    uint64_t scalar[4] = {0x298, 0, 0, 0};
    uint8_t in[0x20] = {0};
    memset(in, 0x41, sizeof(in));
    dump_last(@"Scaler", 11, scalar, 1, in, sizeof(in));
    kr = IOConnectCallMethod(conn, 11, scalar, 1, in, sizeof(in), NULL, &outCnt, out, &outSize);
    NSMutableString *hex = [NSMutableString string];
    for (size_t i = 0; i < outSize && i < 0x60; i++) [hex appendFormat:@"%02x", out[i]];
    [lines addObject:[NSString stringWithFormat:@"sel11 kr=0x%x size=%zu head=%@", kr, outSize, hex]];
    log_write(@"targeted: sel11 kr=0x%x size=%zu head=%@", kr, outSize, hex);

    // sel 7 with a valid user buffer
    void *b7 = mmap(NULL, 0x4000, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANON, -1, 0);
    if (b7 != MAP_FAILED) {
        memset(b7, 0xAA, 0x4000);
        uint64_t u = (uint64_t)b7;
        dump_last(@"Scaler", 7, &u, 0, (uint8_t *)&u, 8);
        kr = IOConnectCallMethod(conn, 7, NULL, 0, &u, 8, NULL, NULL, NULL, NULL);
        uint8_t first = *(uint8_t *)b7;
        [lines addObject:[NSString stringWithFormat:@"sel7 kr=0x%x first=0x%02x", kr, first]];
        log_write(@"targeted: sel7 kr=0x%x first=0x%02x", kr, first);
        munmap(b7, 0x4000);
    }

    // sel 9 with two valid user buffers
    void *b9a = mmap(NULL, 0x4000, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANON, -1, 0);
    void *b9b = mmap(NULL, 0x4000, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANON, -1, 0);
    if (b9a != MAP_FAILED && b9b != MAP_FAILED) {
        memset(b9a, 0xBB, 0x4000);
        memset(b9b, 0xCC, 0x4000);
        uint64_t pair[2] = {(uint64_t)b9a, (uint64_t)b9b};
        dump_last(@"Scaler", 9, NULL, 0, (uint8_t *)pair, sizeof(pair));
        kr = IOConnectCallMethod(conn, 9, NULL, 0, pair, sizeof(pair), NULL, NULL, NULL, NULL);
        [lines addObject:[NSString stringWithFormat:@"sel9 kr=0x%x a=0x%02x b=0x%02x",
                          kr, *(uint8_t *)b9a, *(uint8_t *)b9b]];
        log_write(@"targeted: sel9 kr=0x%x a=0x%02x b=0x%02x", kr,
                  *(uint8_t *)b9a, *(uint8_t *)b9b);
        munmap(b9a, 0x4000);
        munmap(b9b, 0x4000);
    }

    IOServiceClose(conn);
    log_write(@"targeted: done");
    return [lines componentsJoinedByString:@"\n"];
}

NSString *fuzz_scaler(int iterations)
{
    NSMutableArray<NSString *> *lines = [NSMutableArray array];
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault,
                                                   IOServiceMatching("AppleM2ScalerCSCDriver"));
    if (svc == IO_OBJECT_NULL) {
        return @"fuzz: Scaler absent";
    }
    io_connect_t conn = IO_OBJECT_NULL;
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), 0, &conn);
    IOObjectRelease(svc);
    if (kr != KERN_SUCCESS) {
        return [NSString stringWithFormat:@"fuzz: Scaler open kr=0x%x", kr];
    }
    log_write(@"fuzz: Scaler conn=%u iterations=%d", conn, iterations);

    static const size_t kSizes[] = {0, 8, 0x10, 0x18, 0x20, 0x1b0, 0xfa8};
    uint8_t *buf = calloc(1, 0x1000);
    uint64_t scalars[8];

    for (uint32_t sel = 0; sel < 12; sel++) {
        for (int it = 0; it < iterations; it++) {
            for (size_t si = 0; si < sizeof(kSizes) / sizeof(kSizes[0]); si++) {
                size_t len = kSizes[si];
                if (len > 0x1000) len = 0x1000;
                memset(buf, 0, 0x1000);
                for (size_t i = 0; i < len; i++) buf[i] = (uint8_t)rnd64();
                for (int i = 0; i < 8; i++) scalars[i] = rnd64();
                int sc = (sel == 9 || sel == 7 || sel == 8) ? 1 : (int)(rnd64() % 4);

                dump_last(@"Scaler", sel, scalars, (uint32_t)sc, buf, len);
                uint32_t outCnt = 0;
                size_t outSize = 0;
                kern_return_t r = IOConnectCallMethod(conn, sel, scalars, (uint32_t)sc,
                                                      buf, len, NULL, &outCnt,
                                                      NULL, &outSize);
                if (r != (kern_return_t)0xe00002bc && r != (kern_return_t)0xe00002c7 &&
                    r != (kern_return_t)0xe00002c2) {
                    NSString *line = [NSString stringWithFormat:
                        @"fuzz: Scaler sel=0x%x len=0x%zx kr=0x%x",
                        sel, len, r];
                    [lines addObject:line];
                    log_write(@"%@", line);
                }
            }
        }
        usleep(2000);
    }
    free(buf);
    IOServiceClose(conn);
    log_write(@"fuzz: Scaler done");
    return [lines componentsJoinedByString:@"\n"];
}
