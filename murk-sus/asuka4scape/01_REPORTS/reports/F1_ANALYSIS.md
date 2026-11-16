# F1_ANALYSIS — what the kernel does with the wrapped multi-slice region values

Target: iOS 27.2 (24B115), `com.apple.iokit.IOSurface`, kernelcache
`kc/27.2_24B115_kernelcache`.
Sources: `dumps/ios272/` (1702 decompiled functions, IOSurface.kext
`__text` 0xfffffff009c14f20-0xfffffff009c49554), plus the on-disk kernelcache
for cross-reference scans. Probe: KRWProbe 1.7, `probe/out/KRWProbe.ipa`.

Companion report: `reports/VALIDATOR_AUDIT.md` finding F1.

## 1. The three fields and where they live

The compressed-plane record is a 0x3c-byte array, one entry per plane:

| offset | type | meaning | set from XML key |
|---|---|---|---|
| +0x00 | u32 | compressed tile width | `IOSurfacePlaneCompressedTileWidth` |
| +0x04 | u32 | compressed tile height | `IOSurfacePlaneCompressedTileHeight` |
| +0x08 | u32 | tile header region offset | `IOSurfacePlaneCompressedTileHeaderRegionOffset` |
| +0x0c | u32 | tile data region offset | `IOSurfacePlaneCompressedTileDataRegionOffset` |
| +0x10 | u32 | bytes per compressed tile header | `IOSurfacePlaneBytesPerCompressedTileHeader` |
| +0x14 | u32 | bytes per tile data | `IOSurfacePlaneBytesPerTileData` |
| +0x18 | u32 | width in compressed tiles | `IOSurfacePlaneWidthInCompressedTiles` |
| +0x1c | u32 | height in compressed tiles | `IOSurfacePlaneHeightInCompressedTiles` |
| +0x20 | u8 | HTPC prediction selector | `IOSurfacePlaneHTPCPredictionSelector` |
| +0x21 | u8 | HTPC vertical header grouping | `IOSurfacePlaneHTPCVerticalHeaderGroupingMode` |
| +0x22 | u8 | (used as shift, `& 0x1f`) | internal |
| +0x24 | u16 | … | internal |
| +0x26 | u16 | … | internal |
| +0x28 | u8 | compression type | `IOSurfacePlaneCompressionType` |
| +0x2c | u32 | bytes per row of tile data | `IOSurfacePlaneBytesPerRowOfTileData` |
| +0x30 | u32 | bytes per row of tile header groups | `IOSurfacePlaneBytesPerRowOfCompressedTileHeaderGroups` |
| +0x34 | u32 | **`[0xd]` DataRegionBytesPerSlice** | `IOSurfacePlaneDataRegionBytesPerSlice` |
| +0x38 | u32 | **`[0xe]` HeaderRegionBytesPerSlice** | `IOSurfacePlaneHeaderRegionBytesPerSlice` |

Storage in the surface object (decompiler names in
`dumps/ios272/fn_fffffff009c1af14.c`, same function = `IOSurface::parse_properties`):

* `surface+0x308` = pointer to the 0x3c-byte compressed-plane array.
* `surface+0x310` = its element count.
* `surface+0x98`  = plane count (used for bounds).
* `surface+0x3b8` = **SliceCount (u32)**.
* `entry[0xd]` = `puVar4[0xd]` at line 1299:
  `puVar4[0xd] = (uint)local_78;` (DataRegionBytesPerSlice)
* `entry[0xe]` = `puVar4[0xe]` at line 1352:
  `puVar4[0xe] = (uint)local_78;` (HeaderRegionBytesPerSlice)
* SliceCount = line 874: `*(int *)(param_1 + 0x3b8) = (int)uVar52;`

All three are stored as **u32**; there is no 64-bit shadow copy anywhere in
the object.

## 2. Exact validation order around the F1 check

The relevant block is `fn_fffffff009c1af14.c` lines 1184-1364.  For CT=4
(`bVar34=1`, `bVar32=0`) the order is:

1. **l.1214-1216** — header region must fit in the plane:
   `planeSize + planeBase < headerRegionOffset + hdrGroupsRow*headerHeight`
   → `"Header region doesn't fit into plane size"`.
   With the probe XML `hdrGroupsRow=0`, this is
   `0x10000 < headerRegionOffset`.
2. **l.1232-1256** — data region total (64-bit):
   `dataRegionTotal = entry[0xc] * entry[6]` (row of tile data × height in
   tiles), then
   `planeSize + planeBase < dataRegionOffset + dataRegionTotal*sliceCount`
   → `"Data region doesn't fit into plane size"`.
   Note this uses **entry[0xc]**, not entry[0xd].
3. **l.1265-1300** — if `sliceCount > 1`: parse `DataRegionBytesPerSlice`,
   reject `>0xffffffff`, reject `< entry[6]*entry[5]*entry[0xb]`
   (32-bit product, F2), store `entry[0xd]`.
4. **l.1304-1326** — overlap test.  For CT≠1:
   `headerRegionOffset < dataRegionOffset + dataRegionTotal*sliceCount`
   → `"Data region overlaps header region"`.
5. **l.1328-1352** — if `sliceCount > 1`: parse
   `HeaderRegionBytesPerSlice`, reject `>0xffffffff`, reject
   `< hdrGroupsRow*headerHeight`, store `entry[0xe]`.
6. **l.1353-1363** — the F1 check:
   `planeSize < (uint)((entry[0xd] + (uint)header) * (int)sliceCount)`
   → `"multi-slice interchange compressed plane ... size is greater than
   total planeSize"`.

**Correction to the audit recipe (important).** Step 4 sits between the
64-bit data-region check and the wrapped check.  With the audit's baseline
`IOSurfacePlaneCompressedTileHeaderRegionOffset = 0x4000`,
`dataRegionTotal*sliceCount = 0x4000*2*4 = 0x10000`, so
`0x4000 < 0x10000` is true and the shape is rejected by the **overlap**
check before line 1353.  To reach F1 the header region offset must satisfy

```
headerRegionOffset >= dataRegionOffset + dataRegionTotal*sliceCount
headerRegionOffset + hdrGroupsRow*headerHeight <= planeSize + planeBase
```

The probe therefore sets `headerRegionOffset = 0x10000`,
`hdrGroupsRow = 0`, `dataRegionOffset = 0` for the 0x10000-plane variants
(and `0x8000` / `0x10000` for the smaller-plane variants).  This is a
constructive requirement, not a fuzzed value; the audit's one-line shape is
incomplete without it.

Also note: XML `<integer>` values are created with **width 64** by default
(`OSUnserializeXML.y`: `object->size = 64;` unless a `size="N"` attribute is
present).  `FUN_fffffff009c20038` only sign-extends when the OSNumber width
is < 64, so `0x80000000` and `0x80000004` in this probe arrive as positive
64-bit values, not as `0xffffffff80000000`.  Any future test that adds
`size="32"` changes this.

## 3. Complete reader inventory for `entry[0xd]`, `entry[0xe]`, `surface+0x3b8`

Every dump that touches the compressed-plane array must first load
`surface+0x308`; `grep -l 0x308 dumps/ios272/*.c` returns 43 files.  Of those,
only the following read the F1 fields:

| # | function | address | dump | what it does with the value |
|---|---|---|---|---|
| 1 | `IOSurface::parse_properties` | `0xfffffff009c1af14` | `fn_fffffff009c1af14.c` l.874, 1299, 1352, 1353-1363 | writer; the only arithmetic on the sum is the 32-bit check |
| 2 | deserializer (second writer) | `0xfffffff009c29ee4` | `fn_fffffff009c29ee4.c` l.57-58, 171-173 | writes `surface+0x3b8`, `entry[0xd]` (l.171), `entry[0xe]` (l.173) from a serialized surface dictionary; **no F1-style validation at all**; stores only |
| 3 | DataRegion getter | `0xfffffff009c297bc` (arm64e alias +8 `0x9c297c4`) | `fn_fffffff009c297bc.c` l.30 | returns `*(u32 *)(entry + 0x34)`; pure load, no arithmetic |
| 4 | HeaderRegion getter | `0xfffffff009c2987c` (alias +8 `0x9c29884`) | `fn_fffffff009c2987c.c` l.30 | returns `*(u32 *)(entry + 0x38)`; pure load, no arithmetic |
| 5 | SliceCount getter | `0xfffffff009c297a8` | `fn_fffffff009c297a8.c` l.8-12 | `return max(*(u32 *)(surface+0x3b8), 1)`; pure |
| 6 | IOSurfaceInfo export | `0xfffffff009c2c18c` | `fn_fffffff009c2c18c.c` l.209, 217, 219 | `puVar1[0x10] = *(u64 *)(entry + 0x34)` (one 8-byte load = entry[0xd]+entry[0xe] into per-plane info +0x80); `uVar7 = *(u32 *)(surface+0x3b8)`; `*(u32 *)(info + 0x74) = uVar7` |
| 7 | destructor | `0xfffffff009c1f830` / `0xfffffff009c1f834` | l.66-71 | frees the 0x3c array and zeroes `surface+0x3b8`; no read |
| 8 | destructor | `0xfffffff009c2a48c` | l.16-21 | same; no read |

Nothing else.  In particular:

* the deserializer at `0xfffffff009c29ee4` is a second, validation-free writer:
  it fills `surface+0x3b8` (l.57-58), `entry[0xd]` (l.171), `entry[0xe]`
  (l.173) straight from a serialized surface dictionary.  It never computes
  the sum either; it only stores the caller's values.  (This path broadens
  who can plant the inconsistent metadata, but does not add a consumer.)
* no second 64-bit recomputation of
  `(entry[0xd] + entry[0xe]) * sliceCount` exists anywhere in the 1702 dumps;
* the only 64-bit products involving slice count use **`entry[0xc]`**
  (bytes per row of tile data) and `entry[6]` (height in tiles), not `[0xd]`
  or `[0xe]` (l.1232-1256 and l.1318);
* there is no `memcpy`, `IOMalloc`/`kalloc`, `createMappingInTask`, or
  `mapInTask` call whose length/offset is derived from `[0xd]`/`[0xe]`.

### 3.1 Are the getters called from kernel code?

A scan of all `BL` and `B` instructions in the kernelcache `__TEXT_EXEC`
segment (`0xfffffff00814c000`-`0xfffffff00aa70000`, 43 MB, every 4-byte word
decoded as a PC-relative branch) finds **zero** direct branches to

```
0xfffffff009c297a8   sliceCount getter
0xfffffff009c297bc   dataPerSlice getter
0xfffffff009c2987c   headerPerSlice getter
0xfffffff009c28d28   entry[0x2c] getter
0xfffffff009c29028   entry[0x30] getter
```

while the same scan finds the six expected call sites of the IOSurfaceInfo
export `0xfffffff009c2c18c` (0x9c3ae9c, 0x9c3b500, 0x9c3b714, 0x9c3b968,
0x9c3bd84, 0x9c3c1bc — all in the IOSurfaceRootUserClient selector range
0x9c3ab8c-0x9c3c3b8).  The getters have no direct kernel caller; they are
reachable only through the OSMetaClass/vtable dispatch (the per-plane getter
API).  Even when dispatched, they return a u32 to the caller and perform no
arithmetic.

### 3.2 The one cached derivative is also dead

At l.1366-1375 the parser caches `dataRegionTotalSize` (derived from
`entry[0xc] * entry[6]`) into `*(*plVar44 + 0xb8 + plane*4)`
(`plVar44 = param_1 + 0x178`).  No function in the 1702 dumps reads that
array (the `0xb8` reads elsewhere are unrelated vtable calls / fields of other
object types).  It is a write-only cache and is not derived from the wrapped
sum in any case.

## 4. What the mapping path uses instead

For completeness, the compressed fields do not participate in the surface
map path either:

* `FUN_fffffff009c2b8cc` (`IOSurface::mapInTask`, 880 bytes) maps the shared
  memory descriptor via `FUN_fffffff009c41c14`, then
  `FUN_fffffff009c2bc3c`; it uses the memory object's range/count
  (`param_3[2]`, `param_3[0x13]`) and `surface+0x9c`, not the 0x3c plane
  array.
* `FUN_fffffff009c2bc3c` (`createMappingInTask`, 440 bytes) creates the
  task mapping over the surface memory descriptor
  (`FUN_9c41bd8(surface+0x10)` / `thunk_...396cb64`) and computes the
  mapping position from the surface's client-aligned offset
  (`surface+0x168`) plus the mapping's size.  No plane record, no slice
  count.
* `FUN_fffffff009c237e8` (`prepare`, 556 bytes) only tracks the memory
  object's length (`(*(*surface+0x30)+0xa0)()`) and logs it; it does not
  look at compressed planes.

Consequently the wrapped values never become a length or offset for a
kernel copy, map, or allocation **inside IOSurface.kext**.

## 5. Verdict and resulting primitive

**No.**  After validation, the kernel does not recompute the region in
64-bit and does not use the wrapped values as a length/offset for a copy,
map, or allocation.  The verified data flow is:

```
user XML
  -> parse_properties:
       entry[0xd] = (u32)DataRegionBytesPerSlice
       entry[0xe] = (u32)HeaderRegionBytesPerSlice
       surface+0x3b8 = (u32)SliceCount
       32-bit check only: (entry[0xd] + entry[0xe]) * sliceCount
  -> stored in the 0x3c-byte compressed-plane entry / surface object
  -> read back only by:
       getter 0x9c297bc  (returns entry[0xd])
       getter 0x9c2987c  (returns entry[0xe])
       getter 0x9c297a8  (returns max(sliceCount,1))
       IOSurfaceInfo export 0x9c2c18c:
           per-plane info +0x80 = entry[0xd] | entry[0xe]<<32
           info +0x74          = sliceCount
  -> IOSurfaceRootUserClient selectors copy IOSurfaceInfo to user space
```

There is **no kernel read/write primitive** in the audited code.  The
immediate result is a metadata inconsistency:

* the surface is really backed by `IOSurfaceAllocSize` bytes (the probe uses
  64 KiB, matching `IOSurfacePlaneSize`), while the compressed-plane entry
  advertises `SliceCount * (DataRegionBytesPerSlice +
  HeaderRegionBytesPerSlice)` bytes of per-slice region;
* for the F1 probe tuple that true 64-bit value is
  `4 * (0x4000 + 0x40000000) = 0x1_0001_0000` (4 GiB + 64 KiB) against a
  64 KiB plane; the truncated 32-bit value is exactly `0x10000`, so the
  parser's comparison passes;
* because the 64-bit data-region check at l.1254 uses `entry[0xc]`, not
  `entry[0xd]`, there is no earlier rejection for the 4-slice shape (the
  header-region overlap check must be satisfied as described in §2).

Any memory-safety impact therefore requires a **downstream consumer outside
these 1702 dumps** that trusts the exported `IOSurfaceInfo` fields
(per-plane +0x80/+0x84 and +0x74) and computes a slice offset in 64-bit.
Such a consumer would get an address window of up to 4 GiB + 64 KiB starting
at the plane base while only 64 KiB is allocated — i.e. a GPU/DMA or
userland-driver OOB window, not an IOSurface.kext kernel memory primitive.
The AGX/IOGPU user client is the obvious next target; it is not part of this
dump set (only IOSurface, AVD, AVE and ANE kexts are extracted under
`kexts/`).

For the in-kernel IOSurface object itself the only observable effect is that
`IOSurfaceInfo` (returned by sel 0 and sel 2) contains attacker-chosen
slice/region values, while the allocation, the plane record and the mapping
remain 64 KiB.

## 6. Probe 1.7 — F1 button

Build: KRWProbe **1.7** (`CFBundleVersion 17`), IPA
`probe/out/KRWProbe.ipa` (62,021 bytes,
sha256 `d26013f93c9553c6a0119787cab5448bea082a1a23f29f6cb6b7ec9827aff1a9`;
`Payload/KRWProbe.app/KRWProbe` 200,736 bytes,
sha256 `d23f331d23379ba199124f1115ab81c2a23538b9a8b9f6342034786f35e2e871`).
Built with Theos from `/tmp/opencode/krwprobe` (`make ipa`) because the
project path contains spaces.

The UI row that used to hold the full-width LEAK button is now two
half-width buttons: `LEAK (sel10 ptr hunt)` and **`F1  sel0 wrap`**.
`F1` runs `f1_loop()` on the worker queue; there is no repetition and no
fuzz loop.

### 6.1 What one F1 press sends

For each variant, exactly **one** raw `IOSurfaceRootUserClient` selector 0
call:

```
scalarIn  = 1 entry { parent = 0 }          (high 32 bits zero)
structIn  = hand-built XML plist + NUL      (must end with NUL)
scalarOut = none
structOut = 0xc68 bytes (IOSurfaceInfo)
```

The XML is built with decimal `<integer>` values (64-bit OSNumber, no
`size` attribute) and contains:

```
IOSurfaceWidth=64, IOSurfaceHeight=64, IOSurfaceBytesPerElement=4,
IOSurfacePixelFormat=0x42475241 ('BGRA'),
IOSurfaceAllocSize=<variant>,
IOSurfaceSliceCount=<variant>,
IOSurfacePlaneInfo=[ {
  IOSurfacePlaneWidth=64, IOSurfacePlaneHeight=64,
  IOSurfacePlaneBytesPerElement=4, IOSurfacePlaneBytesPerRow=512,
  IOSurfacePlaneSize=<variant>,
  IOSurfacePlaneCompressionType=4,
  IOSurfacePlaneDataRegionBytesPerSlice=0x4000,
  IOSurfacePlaneHeaderRegionBytesPerSlice=<variant>,
  IOSurfacePlaneCompressedTileWidth=32,
  IOSurfacePlaneCompressedTileHeight=32,
  IOSurfacePlaneBytesPerCompressedTileHeader=8,
  IOSurfacePlaneBytesPerTileData=4096,
  IOSurfacePlaneWidthInCompressedTiles=2,
  IOSurfacePlaneHeightInCompressedTiles=2,
  IOSurfacePlaneBytesPerRowOfTileData=8192,
  IOSurfacePlaneCompressedTileHeaderRegionOffset=<variant>,
  IOSurfacePlaneCompressedTileDataRegionOffset=0,
  IOSurfacePlaneBytesPerRowOfCompressedTileHeaderGroups=0
} ]
```

`IOSurfacePlaneCompressedTileHeaderRegionOffset` is part of the shape even
though the audit recipe omits it: it is a required key
(`FUN_fffffff009c20288`) and the value must satisfy the overlap check in §2.
The log prints the exact XML before the call.

### 6.2 Variants

| # | sliceCount | headerPerSlice | planeSize | allocSize | headerRegionOffset | expected parser path |
|---|---|---|---|---|---|---|
| 1 | 4 | 0x40000000 | 0x10000 | 0x10000 | 0x10000 | data check `0x4000*4 = 0x10000` passes; wrapped check `(0x4000+0x40000000)*4 mod 2^32 = 0x10000`, `0x10000 < 0x10000` false → **accept**; true region `0x1_0001_0000` (4 GiB + 64 KiB) |
| 2 | 0x80000004 | 0x40000000 | 0x10000 | 0x10000 | 0x10000 | slice-count range accepts 2..0xffffffff; **data check rejects** at l.1254: `0x4000 * 0x80000004 = 0x2_0001_0000 > 0x10000`, so the wrapped check is never reached |
| 3 | 2 | 0x80000000 | 0x10000 | 0x10000 | 0x8000 | data check `0x4000*2 = 0x8000` passes; wrapped check `(0x4000+0x80000000)*2 mod 2^32 = 0x8000 <= 0x10000` → **accept**; true region `0x1_0000_8000` |
| 4 | 4 | 0x40000000 | 0x20000 | 0x20000 | 0x10000 | larger plane control; wrapped check passes (trivially: 0x10000 < 0x20000), true region still 4 GiB + 64 KiB |

Variant 4 raises `IOSurfaceAllocSize` with `IOSurfacePlaneSize` because the
planar allocation check (l.1874-1922) requires
`AllocSize >= planeBase + planeSize`; with the audit's `AllocSize=0x10000`
it would be rejected at that check, not at F1.  The base shape already has
`AllocSize == PlaneSize == 0x10000`, so variants 1-3 are exactly the audit
numbers.

### 6.3 What is logged (f1.txt)

`<run>/f1.txt` (and every line also goes to `run.log` through `L()`), opened
append + line-buffered, one block per variant:

1. variant number/name, all input fields, and the arithmetic:
   `32-bit product`, `true 64-bit product`, `planeSize < product ?`;
2. the exact XML sent;
3. `sel0 CREATE -> kr=0x... , structIn=..., structOut=.../0xc68`;
4. on success, the surface id and `f1_info_fields`:
   `id`, `planes`, `sliceCount (+0x74)`, `flag`, `pixfmt`, `usecnt`, and for
   every plane: `tileData(+0x78)`, `tileRow(+0x7c)`,
   `dataPerSlice(+0x80)`, `headerPerSlice(+0x84)`;
5. the full 0xc68 response: first 0x200 bytes in hex **and every non-zero
   u32 at a 4-byte offset** (with offset and decimal value);
6. `sel2 USE+INFO` (structIn 0xc `{id,0,0}`, structOut 0xc68), same field
   readout + full dump;
7. `sel10 GET 'IOSurfaceWidth'` and `sel10 GET 'IOSurfaceSliceCount'`
   (structIn 0xc + C-string key, structOut 0x800, first 0x100 bytes hex).

On a rejected variant the log records the `kr` and explicitly says the
surface was not created; the kernel returns only `0xe00002c2`, so the
individual failing check is identified statically (the arithmetic line and
§2/§6.2 already say which one).  The connection is closed at the end, which
destroys all surfaces created by the run.

**Device status:** the IPA is built and copied to `probe/out/KRWProbe.ipa`;
no device run was performed in this session.  The first F1 press will
create `f1.txt` in the per-run folder and the summary line will name it.
