#import "probes.h"
#import "logger.h"
#import <IOSurface/IOSurfaceRef.h>
#import <IOSurface/IOSurfaceObjC.h>
#import <IOKit/IOKitLib.h>
#import <mach/mach.h>
#import <sys/mman.h>
#import <string.h>

static NSString *hx(uint64_t v)
{
    return [NSString stringWithFormat:@"0x%llx", (unsigned long long)v];
}

static NSNumber *n64(uint64_t v)
{
    return [NSNumber numberWithUnsignedLongLong:v];
}

#pragma mark - IOSurface compressed-geometry probes (24B115, K1/K2)

static NSMutableDictionary *compressed_plane(uint64_t bytes_per_tile,
                                             uint64_t bytes_per_tile_row,
                                             uint64_t plane_size,
                                             uint64_t slice_count,
                                             uint64_t data_slice,
                                             uint64_t header_slice)
{
    uint64_t data_total = bytes_per_tile_row;
    uint64_t header_offset = data_total * slice_count;
    return [@{
        @"IOSurfacePlaneWidth": @3,
        @"IOSurfacePlaneHeight": @1,
        @"IOSurfacePlaneBytesPerElement": @1,
        @"IOSurfacePlaneElementWidth": @1,
        @"IOSurfacePlaneElementHeight": @1,
        @"IOSurfaceAddressFormat": @0,
        @"IOSurfacePlaneBytesPerRow": @3,
        @"IOSurfacePlaneSize": n64(plane_size),
        @"IOSurfacePlaneOffset": @0,
        @"IOSurfacePlaneCompressionType": @3,
        @"IOSurfacePlaneCompressionFootprint": @0,
        @"IOSurfacePlaneCompressedTileWidth": @1,
        @"IOSurfacePlaneCompressedTileHeight": @1,
        @"IOSurfacePlaneBytesPerCompressedTileHeader": @32,
        @"IOSurfacePlaneHorizontalPixelOffsetWithinCompressedTileArray": @0,
        @"IOSurfacePlaneVerticalPixelOffsetWithinCompressedTileArray": @0,
        @"IOSurfacePlaneBytesPerTileData": n64(bytes_per_tile),
        @"IOSurfacePlaneWidthInCompressedTiles": @3,
        @"IOSurfacePlaneHeightInCompressedTiles": @1,
        @"IOSurfacePlaneBytesPerRowOfTileData": n64(bytes_per_tile_row),
        @"IOSurfacePlaneBytesPerRowOfCompressedTileHeaderGroups": @0,
        @"IOSurfacePlaneCompressedTileHeaderRegionOffset": n64(header_offset),
        @"IOSurfacePlaneCompressedTileDataRegionOffset": @0,
        @"IOSurfacePlaneDataRegionBytesPerSlice": n64(data_slice),
        @"IOSurfacePlaneHeaderRegionBytesPerSlice": n64(header_slice),
    } mutableCopy];
}

static NSString *surface_one(NSString *name, NSDictionary *properties)
{
    IOSurfaceRef surface = IOSurfaceCreate((__bridge CFDictionaryRef)properties);
    NSString *result;
    if (surface == NULL) {
        result = [NSString stringWithFormat:@"%@: CREATE_FAILED", name];
    }
    else {
        result = [NSString stringWithFormat:@"%@: OK id=%u alloc=0x%zx width=%zu height=%zu",
                  name, IOSurfaceGetID(surface), IOSurfaceGetAllocSize(surface),
                  IOSurfaceGetWidth(surface), IOSurfaceGetHeight(surface)];
        CFRelease(surface);
    }
    NSLog(@"[SPTM272] %@", result);
    return result;
}

static NSMutableDictionary *with_base(NSDictionary *plane, uint64_t alloc, uint64_t slices)
{
    NSMutableDictionary *d = [@{
        @"IOSurfaceWidth": @3,
        @"IOSurfaceHeight": @1,
        @"IOSurfaceBytesPerRow": @3,
        @"IOSurfacePixelFormat": @0,
        @"IOSurfaceAllocSize": n64(alloc),
        @"IOSurfacePlaneInfo": @[plane],
        @"IOSurfaceSliceCount": n64(slices),
    } mutableCopy];
    return d;
}

NSString *run_surface_probes(void)
{
    NSMutableArray<NSString *> *lines = [NSMutableArray array];

    NSDictionary *baseline = with_base(compressed_plane(1, 3, 3, 1, 3, 0), 0x4000, 1);
    [lines addObject:surface_one(@"baseline compressed type 3", baseline)];

    // 3 * 0xAAAAAAAB == 0x200000001 -> 1 after 32-bit truncation (K2).
    NSDictionary *wrap_row = with_base(compressed_plane(0xAAAAAAAB, 1, 1, 1, 1, 0), 0x4000, 1);
    [lines addObject:surface_one(@"K2 wrapped tile row", wrap_row)];

    // 0x10000 * 0x10000 == 0 mod 2^32 (K1).
    NSDictionary *wrap_slices = with_base(compressed_plane(0xAAAAAAAB, 1, 0x10000, 0x10000, 0x10000, 0), 0x4000, 0x10000);
    [lines addObject:surface_one(@"K1 wrapped slice total", wrap_slices)];
    return [lines componentsJoinedByString:@"\n"];
}

#pragma mark - IOSurfaceAddress semantics

NSString *run_address_probe(void)
{
    NSMutableArray<NSString *> *lines = [NSMutableArray array];

    void *buf = mmap(NULL, 0x4000, PROT_READ | PROT_WRITE,
                     MAP_PRIVATE | MAP_ANON, -1, 0);
    if (buf == MAP_FAILED) {
        return @"address probe: mmap failed";
    }
    memset(buf, 0xAA, 0x4000);
    uint64_t addr = (uint64_t)buf;

    NSDictionary *base = @{
        @"IOSurfaceWidth": @64,
        @"IOSurfaceHeight": @64,
        @"IOSurfaceBytesPerRow": @256,
        @"IOSurfacePixelFormat": @(0x42475241), // 'BGRA'
        @"IOSurfaceAllocSize": @0x4000,
    };

    // Control surface: no address property.
    IOSurfaceRef control = IOSurfaceCreate((__bridge CFDictionaryRef)base);
    if (control) {
        void *ba = IOSurfaceGetBaseAddress(control);
        [lines addObject:[NSString stringWithFormat:@"control: OK alloc=0x%zx base=%p",
                          IOSurfaceGetAllocSize(control), ba]];
        CFRelease(control);
    }
    else {
        [lines addObject:@"control: CREATE_FAILED"];
    }

    // Test surface: IOSurfaceAddress = owned VA, 0xAA pattern.
    NSMutableDictionary *props = [base mutableCopy];
    props[@"IOSurfaceAddress"] = n64(addr);
    IOSurfaceRef s = IOSurfaceCreate((__bridge CFDictionaryRef)props);
    if (s == NULL) {
        [lines addObject:@"address: CREATE_FAILED (property rejected or invalid geometry)"];
    }
    else {
        void *ba = IOSurfaceGetBaseAddress(s);
        [lines addObject:[NSString stringWithFormat:
            @"address: OK alloc=0x%zx base=%p requested=0x%llx",
            IOSurfaceGetAllocSize(s), ba, (unsigned long long)addr]];
        if ((uint64_t)ba == addr) {
            uint8_t first = *(volatile uint8_t *)ba;
            [lines addObject:[NSString stringWithFormat:
                @"address: base == requested -> virtual64 in our task, first byte 0x%02x (expected 0xaa)",
                first]];
        }
        else if (ba != NULL) {
            [lines addObject:@"address: base != requested -> not aliased to our buffer"];
        }
        else {
            [lines addObject:@"address: base == NULL -> mapping failed (physical or blocked)"];
        }
        CFRelease(s);
    }

    // Zero address: cheap rejection test, no dereference.
    NSMutableDictionary *zero = [base mutableCopy];
    zero[@"IOSurfaceAddress"] = @0;
    IOSurfaceRef z = IOSurfaceCreate((__bridge CFDictionaryRef)zero);
    [lines addObject:z ? @"address=0: CREATE_OK" : @"address=0: CREATE_FAILED"];
    if (z) CFRelease(z);

    munmap(buf, 0x4000);
    NSLog(@"[SPTM272] %@", [lines componentsJoinedByString:@"\n"]);
    return [lines componentsJoinedByString:@"\n"];
}

#pragma mark - Device tree: /arm-io/sgx

static uint64_t cf_u64(CFTypeRef v)
{
    if (v == NULL) return 0;
    CFTypeID t = CFGetTypeID(v);
    if (t == CFDataGetTypeID()) {
        CFDataRef d = (CFDataRef)v;
        if (CFDataGetLength(d) >= 8) {
            uint64_t x = 0;
            memcpy(&x, CFDataGetBytePtr(d), 8);
            return x;
        }
        if (CFDataGetLength(d) >= 4) {
            uint32_t x = 0;
            memcpy(&x, CFDataGetBytePtr(d), 4);
            return x;
        }
    }
    if (t == CFNumberGetTypeID()) {
        int64_t x = 0;
        CFNumberGetValue((CFNumberRef)v, kCFNumberSInt64Type, &x);
        return (uint64_t)x;
    }
    return 0;
}

static io_registry_entry_t child_named(io_registry_entry_t parent, const char *name)
{
    io_iterator_t it = IO_OBJECT_NULL;
    if (IORegistryEntryGetChildIterator(parent, kIODeviceTreePlane, &it) != KERN_SUCCESS) {
        if (IORegistryEntryGetChildIterator(parent, kIOServicePlane, &it) != KERN_SUCCESS) {
            return IO_OBJECT_NULL;
        }
    }
    io_registry_entry_t child = IO_OBJECT_NULL;
    io_registry_entry_t found = IO_OBJECT_NULL;
    while ((child = IOIteratorNext(it)) != IO_OBJECT_NULL) {
        io_name_t n = {0};
        IORegistryEntryGetName(child, n);
        if (strcmp(n, name) == 0) {
            found = child;
            break;
        }
        IOObjectRelease(child);
    }
    IOObjectRelease(it);
    return found;
}

NSString *run_devicetree_probe(void)
{
    NSMutableArray<NSString *> *lines = [NSMutableArray array];

    io_registry_entry_t sgx = IORegistryEntryFromPath(kIOMasterPortDefault,
                                                       "IODeviceTree:/arm-io/sgx");
    if (sgx == IO_OBJECT_NULL) {
        io_registry_entry_t root = IORegistryEntryFromPath(kIOMasterPortDefault, "IODeviceTree:/");
        if (root != IO_OBJECT_NULL) {
            io_registry_entry_t armio = child_named(root, "arm-io");
            if (armio != IO_OBJECT_NULL) {
                sgx = child_named(armio, "sgx");
                if (sgx == IO_OBJECT_NULL) {
                    IOObjectRelease(armio);
                }
            }
            IOObjectRelease(root);
        }
    }

    if (sgx == IO_OBJECT_NULL) {
        [lines addObject:@"dt: /arm-io/sgx not reachable from sandbox"];
        io_registry_entry_t root2 = IORegistryEntryFromPath(kIOMasterPortDefault, "IODeviceTree:/");
        if (root2 != IO_OBJECT_NULL) {
            io_registry_entry_t armio2 = child_named(root2, "arm-io");
            if (armio2 != IO_OBJECT_NULL) {
                io_iterator_t it = IO_OBJECT_NULL;
                if (IORegistryEntryGetChildIterator(armio2, kIODeviceTreePlane, &it) == KERN_SUCCESS) {
                    io_registry_entry_t c = IO_OBJECT_NULL;
                    int n = 0;
                    while ((c = IOIteratorNext(it)) != IO_OBJECT_NULL && n < 24) {
                        io_name_t cn = {0};
                        IORegistryEntryGetName(c, cn);
                        [lines addObject:[NSString stringWithFormat:@"dt: /arm-io/%s", cn]];
                        IOObjectRelease(c);
                        n++;
                    }
                    IOObjectRelease(it);
                }
                IOObjectRelease(armio2);
            }
            IOObjectRelease(root2);
        }
    }
    else {
        const char *keys[] = {
            "gpu-region-base", "gpu-region-size",
            "gfx-shared-region-base", "gfx-shared-region-size",
            "gfx-shared-l2-region-base", "gfx-shared-l2-region-size",
            "gfx-handoff-base", "gfx-handoff-size",
            "agx-address-space-mgmt-mode", "issue-gmmu-tlbis-at-retype",
        };
        for (size_t i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
            CFStringRef key = CFStringCreateWithCString(kCFAllocatorDefault, keys[i],
                                                    kCFStringEncodingUTF8);
            CFTypeRef v = IORegistryEntryCreateCFProperty(sgx, key,
                                                          kCFAllocatorDefault, 0);
            CFRelease(key);
            if (v) {
                [lines addObject:[NSString stringWithFormat:@"dt: %-32s = %s (%llu)",
                                  keys[i], [hx(cf_u64(v)) UTF8String],
                                  (unsigned long long)cf_u64(v)]];
                CFRelease(v);
            }
            else {
                [lines addObject:[NSString stringWithFormat:@"dt: %-32s = <absent>", keys[i]]];
            }
        }
        IOObjectRelease(sgx);
    }

    NSString *joined = [lines componentsJoinedByString:@"\n"];
    NSLog(@"[SPTM272] dt:\n%@", joined);
    return joined;
}

#pragma mark - IOKit service reachability

NSString *run_iokit_probe(void)
{
    NSMutableArray<NSString *> *lines = [NSMutableArray array];

    // Enumerate services whose class name mentions AGX or GPU.
    NSMutableSet<NSString *> *gpuClasses = [NSMutableSet set];
    io_iterator_t all = IO_OBJECT_NULL;
    if (IOServiceGetMatchingServices(kIOMasterPortDefault, IOServiceMatching("IOService"), &all) == KERN_SUCCESS) {
        io_service_t svc = IO_OBJECT_NULL;
        int scanned = 0;
        while ((svc = IOIteratorNext(all)) != IO_OBJECT_NULL && scanned < 4000) {
            io_name_t cls = {0};
            if (IOObjectGetClass(svc, cls) == KERN_SUCCESS) {
                NSString *c = [NSString stringWithUTF8String:cls];
                if ([c rangeOfString:@"AGX"].location != NSNotFound ||
                    [c rangeOfString:@"GPU"].location != NSNotFound) {
                    [gpuClasses addObject:c];
                }
            }
            IOObjectRelease(svc);
            scanned++;
        }
        IOObjectRelease(all);
    }
    for (NSString *c in [[gpuClasses allObjects] sortedArrayUsingSelector:@selector(compare:)]) {
        [lines addObject:[NSString stringWithFormat:@"class: %@", c]];
    }

    const char *names[] = { "IOSurfaceRoot", "AGXAcceleratorG14P", "IOGPU", "IOGPUDevice",
                            "AppleM2ScalerCSCDriver", "AppleT8110DART" };
    for (size_t i = 0; i < sizeof(names) / sizeof(names[0]); i++) {
        io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault,
                                                       IOServiceMatching(names[i]));
        if (svc == IO_OBJECT_NULL) {
            [lines addObject:[NSString stringWithFormat:@"iokit: %s absent", names[i]]];
            continue;
        }
        NSMutableString *row = [NSMutableString stringWithFormat:@"iokit: %s", names[i]];
        io_name_t cls = {0};
        IOObjectGetClass(svc, cls);
        [row appendFormat:@" class=%s", cls];
        for (uint32_t type = 0; type < 4; type++) {
            io_connect_t conn = IO_OBJECT_NULL;
            kern_return_t kr = IOServiceOpen(svc, mach_task_self(), type, &conn);
            if (kr == KERN_SUCCESS) {
                [row appendFormat:@" t%u=OK", type];
                IOServiceClose(conn);
            }
            else {
                [row appendFormat:@" t%u=0x%x", type, kr];
            }
        }
        [lines addObject:row];
        IOObjectRelease(svc);
    }

    NSString *joined = [lines componentsJoinedByString:@"\n"];
    NSLog(@"[SPTM272] iokit:\n%@", joined);
    return joined;
}


#pragma mark - identity + GPU client sweep

#import <sys/utsname.h>
#import <sys/sysctl.h>

static NSString *sysctl_str(const char *name)
{
    size_t len = 0;
    if (sysctlbyname(name, NULL, &len, NULL, 0) != 0 || len == 0 || len > 512) return @"?";
    char *buf = calloc(1, len);
    NSString *out = @"?";
    if (sysctlbyname(name, buf, &len, NULL, 0) == 0) {
        out = [NSString stringWithUTF8String:buf] ?: @"?";
    }
    free(buf);
    return out;
}

NSString *run_identity_probe(void)
{
    NSMutableArray<NSString *> *lines = [NSMutableArray array];
    struct utsname u = {0};
    uname(&u);
    [lines addObject:[NSString stringWithFormat:@"id: sysname=%s release=%s version=%s",
                      u.sysname, u.release, u.version]];
    [lines addObject:[NSString stringWithFormat:@"id: hw.machine=%@ hw.model=%@",
                      sysctl_str("hw.machine"), sysctl_str("hw.model")]];
    [lines addObject:[NSString stringWithFormat:@"id: kern.osversion=%@",
                      sysctl_str("kern.osversion")]];
    [lines addObject:[NSString stringWithFormat:@"id: kern.version=%@",
                      sysctl_str("kern.version")]];
    NSString *joined = [lines componentsJoinedByString:@"\n"];
    NSLog(@"[SPTM272] id:\n%@", joined);
    return joined;
}

NSString *run_gpu_probe(void)
{
    NSMutableArray<NSString *> *lines = [NSMutableArray array];
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("IOGPU"));
    if (svc == IO_OBJECT_NULL) {
        [lines addObject:@"gpu: IOGPU service absent"];
        return [lines componentsJoinedByString:@"\n"];
    }
    io_connect_t conn = IO_OBJECT_NULL;
    kern_return_t kr = IOServiceOpen(svc, mach_task_self(), 1, &conn);
    [lines addObject:[NSString stringWithFormat:@"gpu: open type1 kr=0x%x conn=%u", kr, conn]];
    if (kr == KERN_SUCCESS) {
        uint8_t out[0x1000] = {0};
        size_t outSize = 0;
        for (uint32_t sel = 0; sel < 0x40; sel++) {
            uint64_t scalarIn[4] = {0, 0, 0, 0};
            uint32_t outCnt = (uint32_t)sizeof(out);
            outSize = 0;
            kr = IOConnectCallMethod(conn, sel, scalarIn, 0, NULL, 0,
                                     NULL, &outCnt, out, &outSize);
            if (kr != (kern_return_t)0xe00002c7 && kr != (kern_return_t)0xe00002bc) { // unsupported / bad arg
                [lines addObject:[NSString stringWithFormat:
                    @"gpu: sel 0x%02x kr=0x%x out=%zu", sel, kr, outSize]];
            }
        }
        IOServiceClose(conn);
    }
    IOObjectRelease(svc);
    NSString *joined = [lines componentsJoinedByString:@"\n"];
    NSLog(@"[SPTM272] gpu:\n%@", joined);
    return joined;
}


#pragma mark - Metal connection piggyback

#import <Metal/Metal.h>
#import <objc/runtime.h>

static void snapshot_ports(mach_port_name_array_t *outNames,
                          mach_port_type_array_t *outTypes,
                          mach_msg_type_number_t *outCount)
{
    *outNames = NULL; *outTypes = NULL; *outCount = 0;
    mach_msg_type_number_t tc = 0;
    if (mach_port_names(mach_task_self(), outNames, outCount, outTypes, &tc) != KERN_SUCCESS) {
        *outCount = 0;
    }
}

static BOOL port_in(const mach_port_name_array_t names, mach_msg_type_number_t count, mach_port_name_t p)
{
    for (mach_msg_type_number_t i = 0; i < count; i++) {
        if (names[i] == p) return YES;
    }
    return NO;
}

NSString *run_metal_probe(void)
{
    NSMutableArray<NSString *> *lines = [NSMutableArray array];

    mach_port_name_array_t before = NULL; mach_port_type_array_t beforeTypes = NULL;
    mach_msg_type_number_t beforeCount = 0;
    snapshot_ports(&before, &beforeTypes, &beforeCount);
    log_write(@"metal: ports before device = %u", beforeCount);

    log_write(@"metal: creating MTLDevice");
    id<MTLDevice> dev = MTLCreateSystemDefaultDevice();
    if (dev == nil) {
        [lines addObject:@"metal: MTLCreateSystemDefaultDevice returned nil"];
        return [lines componentsJoinedByString:@"\n"];
    }
    [lines addObject:[NSString stringWithFormat:@"metal: device=%@ class=%s",
                      [dev name], class_getName([dev class])]];
    {
        Class cls = [dev class];
        int depth = 0;
        while (cls != Nil && depth < 6) {
            [lines addObject:[NSString stringWithFormat:@"metal: class[%d]=%s",
                              depth, class_getName(cls)]];
            unsigned mc = 0;
            Method *methods = class_copyMethodList(cls, &mc);
            if (methods) {
                for (unsigned i = 0; i < mc && i < 40; i++) {
                    NSString *sel = NSStringFromSelector(method_getName(methods[i]));
                    [lines addObject:[NSString stringWithFormat:@"metal:   method %@", sel]];
                }
                free(methods);
            }
            unsigned ic = 0;
            Ivar *ivars = class_copyIvarList(cls, &ic);
            if (ivars) {
                for (unsigned i = 0; i < ic && i < 40; i++) {
                    [lines addObject:[NSString stringWithFormat:@"metal:   ivar %s type=%s off=%td",
                                      ivar_getName(ivars[i]), ivar_getTypeEncoding(ivars[i]),
                                      ivar_getOffset(ivars[i])]];
                }
                free(ivars);
            }
            cls = class_getSuperclass(cls);
            depth++;
        }
    }
    log_write(@"metal: device=%@ class=%s", [dev name], class_getName([dev class]));

    // IOGPUMetalDevice._acceleratorPort -> Metal's io_connect_t
    Class devClass = [dev class];
    Ivar apIvar = class_getInstanceVariable(devClass, "_acceleratorPort");
    Ivar drIvar = class_getInstanceVariable(devClass, "_deviceRef");
    if (apIvar == NULL) {
        Class c = class_getSuperclass(devClass);
        while (c && apIvar == NULL) {
            apIvar = class_getInstanceVariable(c, "_acceleratorPort");
            if (drIvar == NULL) drIvar = class_getInstanceVariable(c, "_deviceRef");
            c = class_getSuperclass(c);
        }
    }
    if (apIvar) {
        uint8_t *base = (uint8_t *)(__bridge void *)dev;
        uint32_t accelPort = *(uint32_t *)(base + ivar_getOffset(apIvar));
        void *deviceRef = drIvar ? *(void **)(base + ivar_getOffset(drIvar)) : NULL;
        [lines addObject:[NSString stringWithFormat:
            @"metal: _acceleratorPort=%u _deviceRef=%p", accelPort, deviceRef]];
        log_write(@"metal: _acceleratorPort=%u _deviceRef=%p", accelPort, deviceRef);

        if (accelPort != 0 && accelPort != MACH_PORT_NULL) {
            io_service_t svc = IO_OBJECT_NULL;
            kern_return_t gkr = IOConnectGetService(accelPort, &svc);
            if (gkr == KERN_SUCCESS && svc != IO_OBJECT_NULL) {
                io_name_t cls = {0};
                IOObjectGetClass(svc, cls);
                [lines addObject:[NSString stringWithFormat:
                    @"metal: accelPort -> %s", cls]];
                log_write(@"metal: accelPort -> %s", cls);
                IOObjectRelease(svc);
            }
            else {
                [lines addObject:[NSString stringWithFormat:
                    @"metal: IOConnectGetService(accelPort) kr=0x%x", gkr]];
                log_write(@"metal: IOConnectGetService(accelPort) kr=0x%x", gkr);
            }

            uint8_t out[0x1000] = {0};
            for (uint32_t sel = 0; sel < 0x40; sel++) {
                uint64_t scalarIn[4] = {0, 0, 0, 0};
                uint32_t outCnt = (uint32_t)sizeof(out);
                size_t outSize = 0;
                kern_return_t mkr = IOConnectCallMethod(accelPort, sel, scalarIn, 0, NULL, 0,
                                                        NULL, &outCnt, out, &outSize);
                if (mkr != (kern_return_t)0xe00002c7 && mkr != (kern_return_t)0xe00002bc) {
                    [lines addObject:[NSString stringWithFormat:
                        @"metal: accel sel 0x%02x kr=0x%x out=%zu", sel, mkr, outSize]];
                    log_write(@"metal: accel sel 0x%02x kr=0x%x out=%zu", sel, mkr, outSize);
                }
            }
        }
    }
    else {
        [lines addObject:@"metal: _acceleratorPort ivar not found"];
        log_write(@"metal: _acceleratorPort ivar not found");
    }

    mach_port_name_array_t after = NULL; mach_port_type_array_t afterTypes = NULL;
    mach_msg_type_number_t afterCount = 0;
    snapshot_ports(&after, &afterTypes, &afterCount);
    log_write(@"metal: ports after device = %u", afterCount);

    for (mach_msg_type_number_t i = 0; i < afterCount; i++) {
        mach_port_name_t p = after[i];
        if (port_in(before, beforeCount, p)) continue;
        mach_port_type_t t = afterTypes ? afterTypes[i] : 0;
        [lines addObject:[NSString stringWithFormat:@"metal: new port %u type=0x%x", p, t]];
        log_write(@"metal: new port %u type=0x%x", p, t);
        if ((t & MACH_PORT_TYPE_SEND) == 0 ||
            (t & (MACH_PORT_TYPE_RECEIVE | MACH_PORT_TYPE_PORT_SET | MACH_PORT_TYPE_DEAD_NAME)) != 0) {
            continue;
        }
        log_write(@"metal: probing new port %u", p);
        io_service_t svc = IO_OBJECT_NULL;
        if (IOConnectGetService(p, &svc) != KERN_SUCCESS || svc == IO_OBJECT_NULL) {
            log_write(@"metal: port %u not a connection", p);
            continue;
        }
        io_name_t cls = {0};
        IOObjectGetClass(svc, cls);
        NSString *c = [NSString stringWithUTF8String:cls];
        [lines addObject:[NSString stringWithFormat:@"metal: port %u -> %@", p, c]];
        log_write(@"metal: port %u -> %@", p, c);
        IOObjectRelease(svc);
    }

    if (before) vm_deallocate(mach_task_self(), (vm_address_t)before, beforeCount * sizeof(mach_port_name_t));
    if (after) vm_deallocate(mach_task_self(), (vm_address_t)after, afterCount * sizeof(mach_port_name_t));
    if (beforeTypes) vm_deallocate(mach_task_self(), (vm_address_t)beforeTypes, beforeCount * sizeof(mach_port_type_t));
    if (afterTypes) vm_deallocate(mach_task_self(), (vm_address_t)afterTypes, afterCount * sizeof(mach_port_type_t));

    NSString *joined = [lines componentsJoinedByString:@"\n"];
    log_write(@"metal result:\n%@", joined);
    return joined;
}


#pragma mark - IOSurface device memory regions

NSString *run_region_probe(void)
{
    NSMutableArray<NSString *> *lines = [NSMutableArray array];
    NSMutableArray<NSString *> *regions = [NSMutableArray array];

    io_iterator_t it = IO_OBJECT_NULL;
    if (IOServiceGetMatchingServices(kIOMasterPortDefault, IOServiceMatching("IOService"), &it) == KERN_SUCCESS) {
        io_service_t svc = IO_OBJECT_NULL;
        int n = 0;
        while ((svc = IOIteratorNext(it)) != IO_OBJECT_NULL && n < 4000) {
            io_name_t cls = {0};
            IOObjectGetClass(svc, cls);
            NSString *c = [NSString stringWithUTF8String:cls];
            if ([c rangeOfString:@"MemoryRegion"].location != NSNotFound ||
                [c rangeOfString:@"Carveout"].location != NSNotFound) {
                io_name_t nm = {0};
                IORegistryEntryGetName(svc, nm);
                [lines addObject:[NSString stringWithFormat:@"region: class=%@ name=%s", c, nm]];
                CFTypeRef v = IORegistryEntryCreateCFProperty(svc, CFSTR("name"),
                                                              kCFAllocatorDefault, 0);
                if (v) {
                    NSString *s = [NSString stringWithFormat:@"%@", v];
                    [lines addObject:[NSString stringWithFormat:@"region: name property=%@", s]];
                    [regions addObject:s];
                    CFRelease(v);
                }
                [regions addObject:[NSString stringWithUTF8String:nm]];
            }
            IOObjectRelease(svc);
            n++;
        }
        IOObjectRelease(it);
    }

    NSArray *names = @[@"PurpleGfxMem", @"PurpleGfxMem0", @"PurpleGfxMem1",
                       @"PurpleGfxMem2", @"PurpleGfxMem3", @"gpu-region",
                       @"gfx-shared-region", @"GFX", @"GPU"];
    NSMutableOrderedSet *tryNames = [NSMutableOrderedSet orderedSetWithArray:names];
    [tryNames addObjectsFromArray:regions];

    for (NSString *r in tryNames) {
        NSDictionary *props = @{
            @"IOSurfaceWidth": @64,
            @"IOSurfaceHeight": @64,
            @"IOSurfaceBytesPerRow": @256,
            @"IOSurfacePixelFormat": @(0x42475241),
            @"IOSurfaceAllocSize": @0x4000,
            @"IOSurfaceMemoryRegion": r,
        };
        IOSurfaceRef s = IOSurfaceCreate((__bridge CFDictionaryRef)props);
        if (s) {
            void *ba = IOSurfaceGetBaseAddress(s);
            id prop = nil;
            @try {
                prop = (__bridge id)IOSurfaceCopyValue(s, CFSTR("IOSurfaceMemoryRegion"));
            } @catch (__unused NSException *e) { prop = nil; }
            [lines addObject:[NSString stringWithFormat:
                @"region: %@ CREATE_OK alloc=0x%zx base=%p readback=%@", r,
                IOSurfaceGetAllocSize(s), ba, prop ?: @"<none>"]];
            log_write(@"region: %@ CREATE_OK alloc=0x%zx base=%p readback=%@", r,
                      IOSurfaceGetAllocSize(s), ba, prop ?: @"<none>");
            if (prop) CFRelease((__bridge CFTypeRef)prop);
            CFRelease(s);
        }
        else {
            [lines addObject:[NSString stringWithFormat:@"region: %@ CREATE_FAILED", r]];
            log_write(@"region: %@ CREATE_FAILED", r);
        }
    }

    NSMutableArray *alive = [NSMutableArray array];
    for (int i = 0; i < 3; i++) {
        NSDictionary *props = @{
            @"IOSurfaceWidth": @64,
            @"IOSurfaceHeight": @64,
            @"IOSurfaceBytesPerRow": @256,
            @"IOSurfacePixelFormat": @(0x42475241),
            @"IOSurfaceAllocSize": @0x4000,
            @"IOSurfaceMemoryRegion": @"PurpleGfxMem",
        };
        IOSurfaceRef s = IOSurfaceCreate((__bridge CFDictionaryRef)props);
        if (s) {
            [alive addObject:(__bridge id)s];
            [lines addObject:[NSString stringWithFormat:
                @"region: simultaneous[%d] base=%p", i, IOSurfaceGetBaseAddress(s)]];
        }
    }
    for (id s in alive) CFRelease((__bridge CFTypeRef)s);

    NSString *joined = [lines componentsJoinedByString:@"\n"];
    log_write(@"region result:\n%@", joined);
    return joined;
}

NSString *run_all_probes(void)
{
    NSMutableArray<NSString *> *out = [NSMutableArray array];
    [out addObject:@"== identity =="];
    [out addObject:run_identity_probe()];
    [out addObject:@"== gpu client =="];
    [out addObject:run_gpu_probe()];
    [out addObject:@"== metal piggyback =="];
    [out addObject:run_metal_probe()];
    [out addObject:@"== memory regions =="];
    [out addObject:run_region_probe()];
    [out addObject:@"== device tree =="];
    [out addObject:run_devicetree_probe()];
    [out addObject:@"== iokit =="];
    [out addObject:run_iokit_probe()];
    [out addObject:@"== iosurface address =="];
    [out addObject:run_address_probe()];
    [out addObject:@"== compressed geometry =="];
    [out addObject:run_surface_probes()];
    return [out componentsJoinedByString:@"\n"];
}
