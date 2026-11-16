# VALIDATOR_AUDIT — `FUN_0x9c1af14` (iOS 27.2, 24B115, IOSurface.kext)

Target: `kexts/iosurface/27.2/com.apple.iokit.IOSurface`, `__TEXT_EXEC,__text`
Function: `FUN_fffffff009c1af14` @ `0xfffffff009c1af14`, size `0x3710` (14 096 bytes)
Source of truth: `dumps/ios272/fn_fffffff009c1af14.c` (2 205 decompiled lines),
helper dumps cited inline. Addresses below are kernelcache VM addresses
(kernel base `0xfffffff007004000`, kext base as in `reports/DISPATCHER_RE.md`).

Call site: `IOSurface::initWithProperties` → `FUN_fffffff009c1a914` line 140:
`uVar12 = FUN_fffffff009c1af14(param_1, param_4);` — if it returns 0 the
surface is destroyed and sel 0 returns `0xe00002c2`.

## 0. Input model

* sel 0 (`IOSurfaceRootUserClient` selector 0 → `0x9c3888c` → `0x9c3ab8c` →
  `0x9c33c34` → `0x9c1a914`) passes the `structureInput` bytes to
  `OSUnserialize` (`thunk_...38d4754`) and then the resulting `OSDictionary`
  as `param_2`.
* `structureInputSize` is `0xffffffff` = unchecked in the dispatch table, but
  `IOConnectCallMethod` in-band data is capped at `0x1000`; larger inputs need
  an out-of-line descriptor (`args->structureInputDescriptor`, +0x40).
* sel 9 (`0x9c38b2c` → `0x9c3c3b8`) accepts a 0xc-byte header + plist and
  calls the property setter; it does **not** re-run this parser. The parser
  therefore sees a plist that is normally <= 4 KiB, but the same keys can be
  supplied through the in-kernel `IOSurfaceSetValue` path by other clients.
* All numeric reads go through `FUN_9c20038` (OSNumber → u64).  Note: for an
  `OSNumber` whose declared bit width is < 64 and whose top bit is set, the
  helper sign-extends (`*param_3 = value | -1L << width`, lines 1-30 of
  `dumps/ios272/fn_fffffff009c20038.c`).  Thus XML `<integer>2147483648</integer>`
  arrives as `0xffffffff80000000`, not `0x0000000080000000`.
* `FUN_9c1ff50` = u32 with `>>32` rejection; `FUN_9c20288` = required u32;
  `FUN_9c20114` = u8 with `>0xff` rejection; `FUN_9c1fec4` = low byte, no range
  check (used only for 0/1 booleans).

## 1. Complete index/length map (user field → use)

| # | Property (user controlled) | Reaches | Bound in 27.2 | Verdict |
|---|---|---|---|---|
| 1 | `IOSurfacePlaneInfo` array count | `surface+0x98`, `surface+0x328`, allocations `count*0x18`, `count*0x38`, `count*0x3c`, `count*0x20`; loop index into plane arrays | `count != 0`; `count > 0x14` rejected (l. 278-284); count<4 uses the 3-entry inline array at `surface+0xa8` (l. 273-276) | bounded |
| 2 | plane index in the two plane arrays | `puVar1 = base + idx*0x38`, `puVar2 = base + idx*0x20`, compressed `entry = base + idx*0x3c` | per-access arm64e bounds tags (`...|0xc8a2...`, `...|0x2bad...`) + explicit `(uint)(end-base) < off+size` checks, l. 297-346, 749-772, 875-892 | bounded (trap) |
| 3 | `IOSurfacePlaneInfo[i]` sub-dictionary | per-plane fields | values are range-checked field by field (see below) | mixed |
| 4 | `IOSurfaceSliceCount` | `surface+0x3b8`; multiplied into region-size checks and exported in `IOSurfaceInfo+0x74` | only read for CT=3/4; accepted range 2..0xffffffff (l. 858-874); a present value of 0 or 1 is rejected | bounded value, **but see F1** |
| 5 | `IOSurfacePlaneDataRegionBytesPerSlice` | `entry[0xd]`; feeds the multi-slice total check and `IOSurfaceInfo` | `<= 0xffffffff`; `>= entry[6]*entry[5]*entry[0xb]` computed in **32-bit** (l. 1288-1290) | **F2 feeder** |
| 6 | `IOSurfacePlaneHeaderRegionBytesPerSlice` | `entry[0xe]`; feeds the multi-slice total check | `<= 0xffffffff`; `>= headerWidth*headerHeight` (64-bit) (l. 1343-1352) | **F1 feeder** |
| 7 | `IOSurfacePlaneBytesPerRowOfTileData` | `entry[0xc]` | must equal `entry[5]*entry[0xb]` computed in **32-bit** (l. 1119-1121) | **F3** |
| 8 | `IOSurfacePlaneWidthInCompressedTiles` | `entry[5]` | must equal `(planeWidth+extra)/tileWidth` exactly (l. 1087) | bounded |
| 9 | `IOSurfacePlaneHeightInCompressedTiles` | `entry[6]` | must cover the height exactly (l. 1163-1183) | bounded |
| 10 | `IOSurfacePlaneCompressedTileWidth/Height` | `entry[0]`, `entry[1]` | non-zero, power of two, `< 0x400`; height+header+planeHeight must fit 32 bits (l. 950-988) | bounded |
| 11 | `IOSurfacePlaneBytesPerCompressedTileHeader` | `entry[4]` | `<= 0xffffffff`; for AGX/CT=3/4 must be 2, 8 or 32 (l. 912-936) | bounded |
| 12 | `IOSurfacePlaneBytesPerTileData` | `entry[0xb]` | `<= 0xffffffff` (l. 1023-1028) | bounded value |
| 13 | `IOSurfacePlaneHTPCPredictionSelector` | `entry+0x21` | `<= 0xff`, then `<= 1` for HTPC (l. 893-910) | bounded |
| 14 | `IOSurfacePlaneHTPCVerticalHeaderGroupingMode` | `entry+0x22`; shift amount `& 0x1f` | `<= 0xff`, low 2 bits must be 0; used as `1 << (v & 0x1f)` (l. 1029-1044) | bounded (shift masked) |
| 15 | `IOSurfacePlaneExtendedPixels*` | inline array `entry[2]` area | 64-bit carry checks (l. 443-478) | bounded |
| 16 | `IOSurfacePlaneOffset/Base/Size` | `entry[3]`, `entry[2]`, `entry[5]` | 64-bit carry/overlap/`< planeSize` checks (l. 606-748) | bounded |
| 17 | `IOSurfacePlaneComponent*` (5 arrays) | additional-plane-info entry `surface+0x318 + i*0x18` | array count `<= 4`, count must match across all five arrays; store is `dest[0..count-1]` into 4-byte fields at +4/+8/+0xc/+0x10/+0x14 (`FUN_9c201c4`, `FUN_9c2b164`) | bounded (see F5) |
| 18 | `IOSurfaceAddressRanges` (OSData) | `surface+0x370`, `surface+0x3b4 = size>>4` | `size >= 0x10`, `size & 0xf == 0`; allocation then `memcpy` **without NULL check** (l. 1945-1960) | **F4** |
| 19 | `IOSurfaceDefaultBulkAttachments` (OSData) | `surface+0x260` (0x88-byte struct) | copy length clamped to `0x84` (l. 2037-2064) | bounded |
| 20 | `IOSurfaceMemoryRegion` (array) | 2-entry pointer array at `surface+0x198` | count clamped to 2; arm64e bounds tags (l. 2077-2170) | bounded |
| 21 | `IOSurfaceAllocSize` | `surface+0x90`; allocation length | 64-bit overflow checks; `<= *(root+0x198)` limit; `>= required image size` (l. 1717-1812) | bounded by root limit (>= 1 GiB on this device) |
| 22 | `IOSurfaceName` / `IOSurfaceYCbCrMatrix` / cache mode / direction | scalar fields | string copy; byte/u32 stores; explicit enumerations | bounded |

## 2. Findings

### F1 (TOP) — 32-bit wrap in the multi-slice compressed-plane total-size check

`dumps/ios272/fn_fffffff009c1af14.c`, lines 1353-1363:

```c
puVar4[0xe] = (uint)local_78;                    // HeaderRegionBytesPerSlice
if (puVar1[5] <
    (ulong)((puVar4[0xd] + (uint)local_78) *     // uint + uint  -> 32-bit
           *(int *)(param_1 + 0x3b8))) {         // int * int   -> 32-bit
    "multi-slice interchange compressed plane[%d] (DataRegionBytesPerSlice %d + "
    "HeaderRegionBytesPerSlice %d) * sliceCount %d size is greater than total planeSize %lld"
    -> reject
}
```

Both operands of the addition are `uint` (`puVar4` is `uint *`, `local_78`
narrowed with `(uint)`), and the product is `uint * int`.  The decompiler's
`(ulong)` cast is applied to the already-truncated 32-bit result.  Therefore
the check that is supposed to prove

```
(dataRegionBytesPerSlice + headerRegionBytesPerSlice) * sliceCount <= planeSize
```

is evaluated modulo 2^32 twice.  It can be satisfied with values whose true
64-bit product is far larger than the plane.  A concrete shape that also
passes the earlier 64-bit data-region check:

* `IOSurfacePlaneSize = 0x10000` (64 KiB),
* `DataRegionBytesPerSlice = 0x4000` (16 KiB, the valid tile region),
* `HeaderRegionBytesPerSlice = 0x40000000`,
* `SliceCount = 4`,
* 32-bit sum = `0x40004000`; 32-bit product = `0x00010000` = 65536,
* `planeSize (0x10000) < 0x10000` is false, so it passes, while the true
  region is `4 * 0x40004000 = 0x1_0001_0000` (4 GiB + 64 KiB).

The data-region check earlier in the parser is 64-bit (`16384 * 4 = 65536`,
which equals the plane size), so this shape reaches the wrapped check.  If
the plane is left at the 64x64 default (16 KiB), the data-region check
rejects every multi-slice shape before line 1354 — that is why this needs a
larger `IOSurfacePlaneSize`.

The two per-slice values and the slice count are then stored in the
compressed-plane entry (`entry[0xd]`, `entry[0xe]`, `surface+0x3b8`) and are
exported verbatim in `IOSurfaceInfo` (`FUN_9c2c18c`, the loop at lines 190-230
copies the 0x3c-byte entry; `IOSurfaceInfo+0x74` is the slice count).  The
per-slice region sizes are consumed by the compressed-surface mapping/GPU
path, which is exactly where a wrapped size becomes an offset/size primitive.
The parser has no second 64-bit recomputation of this sum anywhere after
line 1363.

Reachability: needs CT=3 or CT=4, `IOSurfaceSliceCount >= 2`, both region
sizes present, and a plane large enough that the **correct** 64-bit data
region check also passes.  With the 64x64 baseline (plane 16 KiB) a
multi-slice plane fails the earlier `Data region doesn't fit into plane size`
check (`dataRegionTotalSize * sliceCount` is 64-bit), so the parser never
reaches the wrapped check.  The smallest working shape found statically is:

```
IOSurfacePlaneSize                    = 0x10000   (64 KiB; new field)
IOSurfaceAllocSize                    = 0x10000
IOSurfaceSliceCount                   = 4
IOSurfacePlaneHeaderRegionBytesPerSlice = 0x40000000
CT=4, DataRegionBytesPerSlice = 0x4000 (baseline emits it), other compressed fields baseline

data region check:  16384 * 4 = 65536 <= 65536        passes
multi-slice check:  (0x4000 + 0x40000000) * 4
                    = 0x1_0001_0000 -> 32-bit 0x10000
                    planeSize 0x10000 < 0x10000       false -> passes
true region:        0x1_0001_0000 (4 GiB + 64 KiB)
```

None of HARD's phases sets `IOSurfacePlaneSize`, and the pair phase only sets
two fields, so this shape is **not** reached by the current matrix.  It needs
a targeted call (or a new 4-field stage).  HARD additionally died at
ct-pair 2467, before the pair phase, so the combination is unexplored.

Status: **unvalidated on device**; static candidate #1.

### F2 — 32-bit product in the minimum `DataRegionBytesPerSlice` check

`dumps/ios272/fn_fffffff009c1af14.c`, lines 1288-1299:

```c
if (local_78 <
    (undefined1 *)(ulong)(puVar4[6] * puVar4[5] * puVar4[0xb])) {
    "kIOSurfacePlaneDataRegionBytesPerSlice %d is smaller than expected value %d"
    -> reject
}
puVar4[0xd] = (uint)local_78;
```

`entry[6]` = height in compressed tiles, `entry[5]` = width in compressed
tiles, `entry[0xb]` = bytes per tile data, all `uint`.  The product is
computed in 32-bit and can wrap to a small value, so a
`DataRegionBytesPerSlice` much smaller than the true tile area is accepted.
The subsequent `dataRegionTotalSize` calculation is 64-bit and is checked
against the plane, but that calculation uses `entry[0xc]` (row of tile data),
not `entry[0xd]`; the small `entry[0xd]` then enters F1's already-wrapped
sum.  Feeder for F1 / inconsistent geometry.

### F3 — 32-bit product in the `BytesPerRowOfTileData` equality check

`dumps/ios272/fn_fffffff009c1af14.c`, lines 1114-1131:

```c
iVar35 = FUN_fffffff009c20038(lVar42,"IOSurfacePlaneBytesPerRowOfTileData",&local_78);
if (iVar35 != 0) {
    if ((ulong)local_78 >> 0x20 != 0) goto error;
    if ((puVar4[0xb] != 0) &&
        (local_78 != (undefined1 *)(ulong)(puVar4[5] * puVar4[0xb]))) {
        "kIOSurfacePlaneBytesPerRowOfTileData is %d less than WidthInCompressedTiles %d "
        "x BytesPerTileData %d Bytes"
        -> reject
    }
    puVar4[0xc] = (uint)local_78;
}
```

`entry[5] * entry[0xb]` is a 32-bit multiply.  With widthInTiles and
bytesPerTileData chosen so the product wraps (e.g. 0x10000 * 0x10000 =
0 in 32 bits), a `BytesPerRowOfTileData` of the wrapped value (0) passes the
"equality" check.  `entry[0xc]` is then used for the 64-bit
`dataRegionTotalSize` computation (l. 1232-1254); a zero row size makes the
"data region fits" check trivially true, and the per-slice data region is
undersized relative to the tile grid.  Combined with F1 this gives a
surface whose declared region size, actual tile grid and allocation size
disagree.  Feeder; impact depends on the mapping consumer.

### F4 — unchecked allocation before `memcpy` for `IOSurfaceAddressRanges`

`dumps/ios272/fn_fffffff009c1af14.c`, lines 1945-1961:

```c
plVar39 = (long *)FUN_fffffff009c203b0(param_2,"IOSurfaceAddressRanges");
if (plVar39 != 0) {
    uVar36 = (**(code **)(*plVar39 + 0xa0))();          // length (uint)
    if ((uVar36 < 0x10) || ((uVar36 & 0xf) != 0)) { ... reject ... }
    if (*(long *)(param_1 + 0x3a0) != 0) { ... reject ... }
    uVar61 = thunk_EXT_FUN_80110000038fe580(uVar36);    // allocate
    *(undefined8 *)(param_1 + 0x370) = uVar61;
    *(uint *)(param_1 + 0x3b4) = uVar36 >> 4;           // range count
    uVar41 = (**(code **)(*plVar39 + 0xd8))(plVar39);   // bytes
    thunk_EXT_FUN_8011000003a61b10(uVar61, uVar41, uVar36);  // memcpy, no NULL check
}
```

The length is a `uint` (the `OSData::getLength` return is truncated to 32
bits), the allocation size is `uVar36`, and the copy length is `uVar36`, so
there is no overflow.  The missing check is `uVar61 == NULL`: if the
allocation fails (large OOL `IOSurfaceAddressRanges`), the kernel copies into
address 0 and panics.  With in-band input (<= 0x1000) this cannot trigger;
it needs an out-of-line `structureInputDescriptor` and a multi-megabyte data
property.  DoS-class, not a memory-corruption primitive.

### F5 — paths that are correctly bounded (negative results)

* Plane count: `0 < count <= 0x14`; `count < 4` uses the inline 3-entry array
  at `surface+0xa8` (l. 241-291).  All four per-plane allocations are 64-bit
  expressions (`count*0x18`, `count*0x38`, `count*0x3c`, `count*0x20`) and
  NULL-checked.
* Per-plane index: every access to the 0x38/0x20/0x3c arrays is emitted with
  arm64e bounds metadata (`... | 0xc8a2...` / `... | 0x2bad...`) and a
  preceding `(uint)(end-base) < offset+size` test that calls the non-returning
  `FUN_9c48f28`/`FUN_9c48f3c` on failure (l. 297-346, 749-772, 875-892).
  Out-of-range plane index traps instead of corrupting memory.
* Additional plane info (`IOSurfacePlaneComponent*`): `FUN_9c2b164` rejects
  array counts `> 4` and `== 0`, requires all five arrays to agree on the
  count, and writes at most 4 bytes into each of five 4-byte fields of a
  0x18-byte entry (`dumps/ios272/fn_fffffff009c2b164.c` l. 20-58;
  `fn_fffffff009c201c4.c` l. 5-25).  No overflow.
* `IOSurfaceDefaultBulkAttachments`: copy length is `min(size, 0x84)` into a
  0x88-byte struct (l. 2061-2064).  No overflow.
* `IOSurfaceMemoryRegion`: the array count is clamped to 2 (`if (1 < count)
  count = 2`), the destination is a 2-pointer array at `surface+0x198`
  (0x1a8-0x198 = 0x10), and the store is bounds-tagged (l. 2077-2170).
* `IOSurfaceAllocSize`: `required = offset + bytesPerRow*height` is 64-bit
  with `SUB168`/`CARRY8` checks; aligned size add is checked; `align` uses
  `~mask`; the root limit `*(root+0x198)` is checked before use
  (l. 1717-1812).  On this device the limit is >= 1 GiB (a 1 GiB surface was
  created at HARD single #419, see `reports/`/run logs).
* Slice count: the parser accepts 2..0xffffffff and rejects 0/1
  (`local_88 - 0x100000000 < 0xffffffff00000002`, l. 858-874).  The bound is
  present; the bug is how the value is *multiplied* (F1).

### F6 — informational: OSNumber widths change the value

`FUN_9c20038` (l. 1-30) sign-extends an `OSNumber` when its declared bit
width is < 64 and its top bit is set.  Consequences for boundary testing:

* `IOSurfaceAllocSize = 0x80000000` / `0xffffffff` were rejected in the HARD
  singles sweep (#420/#421 logged `0xe00002c2`), while #419 (`0x40000000`,
  1 GiB) succeeded.  This is either the `root+0x198` limit (< 2 GiB) or
  sign-extension of a 32-bit-wide OSNumber (0x80000000 →
  `0xffffffff80000000`, 0xffffffff → `0xffffffffffffffff`); the log alone
  cannot distinguish the two because both paths return `0xe00002c2`.
* The same applies to every 32-bit property: any XML integer with bit 31 set
  and a 32-bit OSNumber width becomes a negative 64-bit value.  Tests that
  expect `0x80000000` to mean "+2 GiB" are actually testing a negative
  number.  The probe's descriptors already print the decimal value, not the
  sign-extended value, so the `last_action.json` field text alone is not
  enough to reconstruct the kernel-side value.

## 3. HARD crash correlation (why this audit matters)

The HARD geometry sweep never reached the F1 combination: it died at
`ct-pair 2467/2496` on `CT=4, IOSurfaceAllocSize=0x40000000`, before the
`pair` phase.  Even the pair phase alone would not hit F1: it never sets
`IOSurfacePlaneSize`, and without a larger plane the 64-bit data-region check
rejects every multi-slice shape before the wrapped check.  F1 is therefore
*unexplored*, not disproven.  The probe changes in 1.5 (alloc cap 64 MiB,
connection recycling every 256 MiB of live surfaces, resumable stage/index)
are what make it possible to reach the pair phase at all; the exact F1 shape
still needs a targeted call.

## 4. Next static steps

1. Follow `entry[0xd]`/`entry[0xe]`/`surface+0x3b8` into the compressed
   mapping path (AGX / `IOSurface::map`), and check whether the per-slice
   offset is computed as `sliceIndex * (dataPerSlice + headerPerSlice)` in
   64-bit (safe) or 32-bit (OOB).
2. Test the exact F1 tuple on device: sel 0 with
   `IOSurfacePlaneSize=0x10000`, `IOSurfaceAllocSize=0x10000`,
   `IOSurfaceSliceCount=4`,
   `IOSurfacePlaneHeaderRegionBytesPerSlice=0x40000000`, CT=4 and the valid
   compressed baseline.  Compare `kr` with and without the wrap; then read
   `IOSurfaceInfo` back and check the slice/region fields.
3. Check `FUN_9c2c18c`'s export of `entry[0xd]`/`[0xe]` to user space: if the
   values are readable back, they are also writable into GPU-side commands by
   an attacker-controlled surface.

## 5. LEAK mode (probe 1.6) — testing the 255047 sel-10 "pointer" hits

### Why

The 1.5 HARD race summary ended with

`kernel_like_ptr_hits=255047 first_ptr=0xffffffff84000040 (sel=10)`

`hard_scan_ptrs()` counted every 8-byte word `>= 0xffff000000000000`; that
test cannot distinguish a kernel pointer from a sign-extended 32-bit value,
and the 1.5 code did not record where the value was or what surrounded it.
LEAK reproduces the get path and records the bytes.

### What the button does

1. Opens `IOSurfaceRoot` (type 0), creates a surface with sel 0
   (`scalarIn={0}`, NUL-terminated 64x64 BGRA XML, `structOut=0xc68`), reads
   the id at `info+0x18`.  The raw 0xc68 CREATE response header (first 0x98
   bytes) is written to `leak.txt` for reference.
2. Sets `LEAKKEY` with sel 9 (`structIn = 0xc header + [1,"LEAKKEY"]`).
3. Calls sel 10 (`structIn = 0xc header + "LEAKKEY\0"`):
   * 200000 single-threaded gets (NULL `scalarOut`, identical to the 1.5 race);
   * 4 x 200000 gets with one concurrent sel 9/sel 11 churn thread
     (value 1 / 0xffffffff, remove) to recreate the raced shape;
   * 20000 gets with a 4-entry `scalarOut` buffer.
4. Every `structOut` is zeroed before the call and scanned at every 4-byte
   offset for a 64-bit word whose top 24 bits are `0xffffff` or top 32 bits
   are `0xffffffff` (the 1.5 `>= 0xffff000000000000` bound is also kept).
   Each matching response is dumped with iteration, tid, selector, `kr`,
   `structOut` size, `scalarOut` count, every matching 64-bit value (offset,
   alignment, `lo32`/`hi32`), and the first 128 bytes of `structOut`.

### Classification / interpretation

* `text_range=YES` — value lies in `[0xfffffff007004000,
  0xfffffff00aa78000]`, the **unslid** kernel text/data window: a real
  kernel text/data pointer (a slid runtime pointer would be outside this
  exact window and needs the KASLR slide added).
* `class=0xfffffff0... (kernel range, possibly KASLR-slid)` — top bits match
  the kernel range but the value is outside the unslid window; this is what
  a genuine runtime pointer looks like after the slide.
* `ffffffff8_range=YES` — value lies in `[0xffffffff80000000,
  0xffffffffffffffff]`.  A value such as `0xffffffff84000040` has
  `top32=0xffffffff` and `lo32=0x84000040`: it is the 32-bit value
  `0x84000040` sign-extended, not a kernel text pointer.  `lo32`/`hi32` are
  printed to make this visible.
* `align=4` — the 8-byte match starts at offset 4 mod 8, so it is two
  adjacent 32-bit fields rather than an aligned 64-bit pointer.

Decision rule: a real leak needs a reproducible `text_range=YES` (or a
consistent KASLR-slid `0xfffffff...` value) at `align=8` inside the
kernel-written part of `structOut`, including the single-threaded control.
A value that is only `ffffffff8...` with `lo32`/`hi32` matching a 32-bit
length or offset, or that only appears at `align=4`, is a sign-extension or
struct-packing artifact, not a kernel pointer.

### Output and cap

`<Documents>/KRWProbe-<stamp>/leak.txt` (same run folder as `run.log`) is
opened append-only; every dump block is `fflush()`ed and the same text goes
to the on-screen log.  Dumps are capped at 200 records; hits beyond the cap
are still counted in the summary.  The summary reports calls, hit responses,
matching values, dump records, and churn ops/errors.

Build: KRWProbe 1.6 (`CFBundleVersion 16`), IPA
`probe/out/KRWProbe.ipa`, 57,205 bytes.
