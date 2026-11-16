# CONSUMERS — who outside IOSurface.kext reads the compressed-plane metadata

Target: iOS 27.2 (24B115), kernelcache `kc/27.2_24B115_kernelcache`.
Companion reports: `reports/F1_ANALYSIS.md`, `reports/VALIDATOR_AUDIT.md` (finding F1).

Question: is there a consumer **outside `com.apple.iokit.IOSurface`** that reads
`IOSurfaceInfo` fields `+0x74` (sliceCount), per-plane `+0x80`
(DataRegionBytesPerSlice) / `+0x84` (HeaderRegionBytesPerSlice), or the raw
0x3c-byte compressed-plane record at `surface+0x308`, and uses any of them as a
length or offset for DMA programming, mapping or a copy?

Short answer: **no kernel consumer found.**  The three F1 accessors are imported
by **zero kexts** in the kernelcache.  The only code outside IOSurface.kext that
obtains the raw 0x3c record is the display stack; its plane-descriptor copy
stops at `+0x33`, and none of its reads touch `+0x34`/`+0x38`.  The values leave
the kernel only through `IOSurfaceInfo` (IOSurfaceRootUserClient selectors
0/2/4/6/7/34), i.e. the only potential consumers are user-space components
(Metal / AGX user driver / IOSurfaceAccelerator.framework), which are not in
this workspace.

---

## 0. Method and a correction to the field table

### 0.1 How cross-kext calls were resolved

Kexts in the kernelcache do not call IOSurface functions with a direct `BL`.
They call an `__auth_stubs` entry, which loads a pointer out of `__auth_got`.
In 27.2 the GOT entry encodes the target as

```
value = 0x8011_0000_0000_0000 | (target_va - 0xfffffff007004000)
```

This was validated against known good imports: e.g. `com.apple.iokit.IOGPUFamily`
slot 146 encodes `0x9c1f1a8` (`IOSurface::getAllocSize`, returns
`*(u64 *)(surface+0x90)`), and the display kexts import `0x9c28af0`
(`getCompressedPlaneEntry`) this way.  Scanning the whole 67 MB kernelcache for
these 8-byte values therefore enumerates **every kext that imports a given
IOSurface function**, including kexts that are not in `kexts/`.

Positive control: the 14 other field getters have 2–7 importers each (the
raw-entry-pointer accessor has 3); the method finds them.  The three F1 accessors have **0**.

### 0.2 Corrected offsets inside the 0x3c record

`F1_ANALYSIS.md` §1 lists `+0x20` as "HTPC prediction selector" and `+0x28` as
"compression type".  The parser shows the opposite grouping:

* `dumps/ios272/fn_fffffff009c1af14.c:856`
  `*(char *)(uVar52 + uVar46 + 0x20) = (char)puVar47;` where `puVar47` is
  `IOSurfacePlaneCompressionType` (read at l.781) → **+0x20 = compression type**.
* l.897/901 `*(char *)((long)puVar4 + 0x21) = ...` reads
  `IOSurfacePlaneHTPCPredictionSelector` (l.894) → **+0x21 = HTPC selector**.
* l.948 `*(char *)(puVar4 + 10) = ...` = `+0x28` ← `IOSurfacePlaneCompressionFootprint`.
* l.1036/1047 `+0x22` ← `IOSurfacePlaneHTPCVerticalHeaderGroupingMode`.

So:

| offset | field |
|---|---|
| +0x00 | compressed tile width |
| +0x04 | compressed tile height |
| +0x08 | **tile header region offset** |
| +0x0c | **tile data region offset** |
| +0x10 | bytes per compressed tile header |
| +0x14 | bytes per tile data |
| +0x18 | width in compressed tiles |
| +0x1c | height in compressed tiles |
| +0x20 | **compression type** |
| +0x21 | HTPC prediction selector |
| +0x22 | HTPC vertical header grouping mode |
| +0x24 | u16 (internal) |
| +0x26 | u16 (internal) |
| +0x28 | compression footprint |
| +0x2c | bytes per row of tile data |
| +0x30 | bytes per row of compressed tile header groups |
| +0x34 | **DataRegionBytesPerSlice** |
| +0x38 | **HeaderRegionBytesPerSlice** |

This matters for reading the display code below: `entry+0x20 == 3` is
"compression type 3", not "HTPC selector".

### 0.3 Accessor addresses used below

Every field has a two-address pair: the lower address is the arm64e entry that
the GOT imports, the upper (`+8`) is the body Ghidra decompiled.  They are the
same function.  The body returns `*(u32/u16/u8 *)(entry + field)` after bounds
checking `plane < surface+0x98` and `entry = surface+0x308 + plane*0x3c`.

| field | entry | dump |
|---|---|---|
| raw entry pointer | `0xfffffff009c28af0` | `fn_fffffff009c28af8.c` |
| +0x00 tile width | `0xfffffff009c28ba8` | `fn_fffffff009c28bb0.c` |
| +0x04 tile height | `0xfffffff009c28c68` | `fn_fffffff009c28c70.c` |
| +0x08 header region offset | `0xfffffff009c29268` | `fn_fffffff009c29270.c` |
| +0x0c data region offset | `0xfffffff009c291a8` | `fn_fffffff009c291b0.c` |
| +0x10 bytes/tile header | `0xfffffff009c28de8` | `fn_fffffff009c28df0.c` |
| +0x14 bytes/tile data | `0xfffffff009c28ea8` | `fn_fffffff009c28eb0.c` |
| +0x18 width in tiles | `0xfffffff009c28f68` | `fn_fffffff009c28f70.c` |
| +0x1c height in tiles | `0xfffffff009c290e8` | `fn_fffffff009c290f0.c` |
| +0x20 compression type | `0xfffffff009c294a8` | `fn_fffffff009c294b0.c` |
| +0x24 | `0xfffffff009c29328` | `fn_fffffff009c29330.c` |
| +0x26 | `0xfffffff009c293e8` | `fn_fffffff009c293f0.c` |
| +0x28 footprint | `0xfffffff009c29568` | `fn_fffffff009c29570.c` |
| +0x2c row of tile data | `0xfffffff009c28d28` | `fn_fffffff009c28d30.c` |
| +0x30 row of header groups | `0xfffffff009c29028` | `fn_fffffff009c29030.c` |
| **sliceCount** | **`0xfffffff009c297a8`** | `fn_fffffff009c297a8.c` |
| **+0x34 dataPerSlice** | **`0xfffffff009c297bc`** | `fn_fffffff009c297c4.c` |
| **+0x38 headerPerSlice** | **`0xfffffff009c2987c`** | `fn_fffffff009c29884.c` |

`getCompressedPlaneEntry` (`fn_fffffff009c28af8.c` l.30) returns
`surface+0x308 + plane*0x3c` (bounds-checked, NULL if `surface+0x308 == 0`), so
any importer of `0x9c28af0` can read *all* fields, including `+0x34`/`+0x38`,
without calling the individual getters.

---

## 1. Whole-kernelcache import scan (the decisive result)

`__auth_got` scans over all 250 fileset entries:

| accessor | importers |
|---|---|
| `+0x00 +0x04 +0x10 +0x14 +0x18 +0x1c +0x20 +0x24 +0x26 +0x28 +0x2c +0x30` | 2–7 each |
| `+0x0c` data region offset (`0x9c291a8`) | 7 |
| `+0x08` header region offset (`0x9c29268`) | 7 |
| `getCompressedPlaneEntry` (`0x9c28af0`) | **3** (display kexts, §7) |
| **`sliceCount` (`0x9c297a8`)** | **0** |
| **`+0x34` dataPerSlice (`0x9c297bc`)** | **0** |
| **`+0x38` headerPerSlice (`0x9c2987c`)** | **0** |
| `IOSurfaceInfo` export (`0x9c2c18c`) | **0** (only 6 direct BLs inside IOSurface.kext) |

The zero is not an artefact of one encoding: an independent 4-byte search for
the low-32-bit offsets `0x02c257a8` / `0x02c257bc` / `0x02c2587c` (which occur
in any `0x8011…` GOT entry) also returns 0 hits.  There is no reference to
these three functions anywhere in the kernelcache outside IOSurface.kext
itself, and no caller at all inside IOSurface.kext (confirmed by the `BL`/`B`
scan in `F1_ANALYSIS.md` §3.1).

---

## 2. `com.apple.AGXG14P` — ignores

* `__auth_got` @ `0xfffffff007ca5278`, 418 entries, 23 IOSurface imports:
  `0x9c36664 0x9c36c6c 0x9c3680c 0x9c36e94 0x9c190fc 0x9c17ca8 0x9c16744
  0x9c17548 0x9c15344 0x9c2708c 0x9c27c70 0x9c2771c 0x9c2a750 0x9c17530
  0x9c1753c 0x9c17584 0x9c17500 0x9c17590 0x9c16750 0x9c2235c 0x9c2a9f8
  0x9c2a620 0x9c229b0`.
  None is in the `0x9c28af0`–`0x9c29884` compressed-plane getter range, and
  none is `0x9c2c18c`.
* The imports are generic surface/fence accessors: `0x9c2235c` returns
  `*(u32 *)(surface+0x10)`, `0x9c229b0` returns plane-record `+0x20`,
  `0x9c2a9f8`/`0x9c2a750` return flag bits of `surface+0x3d3`/`+0x3d1`.
* Grep of `dumps/agx272/*.c` for `0x308` finds only AGX-private structures
  (`param_1+0x308` etc.), not the IOSurface plane array; the four hits in
  `fn_fffffff008180f2c.c`, `fn_fffffff0081d57dc.c`, `fn_fffffff0081d7bc0.c`,
  `fn_fffffff0081d7bf4.c` are vtable/state fields of AGX objects.
* **Verdict: ignores sliceCount/dataPerSlice/headerPerSlice and the plane
  record.**

## 3. `com.apple.iokit.IOGPUFamily` — ignores

* `__auth_got` @ `0xfffffff007ff2060`, 220 entries, 45 IOSurface imports.
  They are `IOSurfaceSharedEvent`/`IOSurfaceDeviceCache` accessors
  (`0x9c2e2d4`…`0x9c2e7f4`), generic surface accessors (`0x9c22350`,
  `0x9c2235c`, `0x9c223bc`, `0x9c22680`, `0x9c2274c`, `0x9c229b0`,
  `0x9c1f1a8`), plus `0x9c29ee4` (`IOSurface::initFromSerializedData`).
  No compressed-plane getter, no `0x9c2c18c`.
* Plane index is used, but only against the plane count:
  `dumps/iogpu272/fn_fffffff0099669e0.c:66-71`
  `uVar3 = thunk_...(surface); if ((uVar3 != 0) && (uVar3 <= param_2[0xf]))`
  → `"%s invalid plane %d in IOSurface with %d planes\n"`; the getter
  `0x9c223bc` is `return *(u32 *)(surface+0x98)`.
* The IOSurface-backed resource type (`0x82`) passes the plane index to
  `FUN_fffffff009953c54`, which works on the 0x38-byte plane record, not the
  0x3c compressed record.
* **Verdict: ignores.**

## 4. `com.apple.driver.AppleM2ScalerCSCDriver` — reads compressed geometry, not F1 fields

Imports 16 compressed-plane getters: `0x9c28ba8 0x9c28c68 0x9c28d28
0x9c28de8 0x9c28ea8 0x9c28f68 0x9c29028 0x9c290e8 0x9c291a8 0x9c29268
0x9c29328 0x9c293e8 0x9c294a8 0x9c29568 0x9c29628 0x9c296e8`, plus the
setter `0x9c28a80` (writes `surface+0x178` cache `+0xb8 + plane*4`) and
`0x9c1f1a8` (alloc size).  It does **not** import `0x9c297a8`, `0x9c297bc`,
`0x9c2987c` or `0x9c28af0`.

The consumer is `validateCompressedTileBuffers`
(`dumps/scaler272/fn_fffffff008cfdfac.c`):

```c
lVar26 = *(long *)(param_1 + 0x18);
lVar25 = FUN_fffffff008dba984(param_3);            // request/plane context
...
iVar9 = thunk_EXT_FUN_...2c254a8(*(u64 *)(lVar25+0x90), uVar17);  // +0x20 CT
if (iVar9 == 3) {                                   // only CT==3 is validated
  uVar10 = thunk_...2c1e680(*(u64 *)(lVar25+0x90), uVar17); // plane record +0x00 (base)
  uVar11 = thunk_...2c1e74c(*(u64 *)(lVar25+0x90), uVar17); // plane record +0x08 (size)
  ...
  uVar12 = thunk_...2c24ea8(...,uVar17);  // entry +0x14 bytes/tile data
  uVar13 = thunk_...2c24f68(...,uVar17);  // entry +0x18 width in tiles
  uVar19 = FUN_fffffff008ccb600(...);     // expected metadata size
  uVar14 = thunk_...2c251a8(...,uVar17);  // entry +0x0c  <-- used as offset
  uVar15 = thunk_...2c25268(...,uVar17);  // entry +0x08  <-- used as offset
  uVar20 = thunk_...2c1b1a8(...);         // surface+0x90 alloc size
  uVar28 = uVar14; uVar27 = uVar15;       // "ActualPlaneBaseOffset"/"ActualMetadataOffset"
  uVar29 = uVar27 - uVar28;               // data area = headerOffset - dataOffset
  uVar30 = uVar20 - uVar27;               // metadata area = allocSize - headerOffset
  if (uVar29 < uVar18) -> "Plane %u Size %llu is less than expected size %llu"
  if (uVar30 < uVar19) -> "Plane %u Metadata Size %llu is less than expected size %llu"
  ...
  if (uVar6 * uVar31 * local_70 < uVar20) -> "Size %llu cannot support a stride ..."
}
```

* It uses `+0x08`/`+0x0c` as the actual data/metadata offsets and `surface+0x90`
  as the total size; the expected sizes are computed from `+0x14`, `+0x18`,
  `+0x1c`, `+0x2c`, `+0x30`, `+0x00`, `+0x04`.  The arithmetic is 32-bit
  (`*(uint *)(lVar25+0x18)` etc.) but that is finding F2/F3 territory.
* **No read of `+0x34`, `+0x38` or `sliceCount`.**  A multi-slice surface is
  simply validated as if it were single-slice.
* Debug dump `FUN_fffffff008d5e02c` / `FUN_fffffff008d5b7c8` (strings
  `tileDataRegionOffsetOfPlane[%u]=%u`, `bytesPerTileHeaderOfPlane[%u]=%u`, …,
  `dumps/scaler272/fn_fffffff008d5e02c.c`) prints the copy of the same fields
  from the scaler's own request struct; it is `os_log`-gated and not a consumer.
* **Verdict: uses compressed geometry (+0x08/+0x0c as offsets, tile sizes) but
  ignores the F1 fields.**

## 5. `com.apple.driver.AppleAVE2` — reads region offsets as DMA addresses

`FUN_fffffff0085287f4` (`dumps/ave272/fn_fffffff0085287f4.c`) builds the
encoder plane descriptor `param_4[0..0xf]` from an IOSurface
`*(u64 *)(param_1+0x68)`:

```c
uVar12 = thunk_...2c251a8(surface,0);            // entry +0x0c (data region offset)
*param_4 = lVar18 + (uVar12 & 0xffffffff);       // DMA address = plane base + offset
uVar12 = thunk_...2c25268(surface,0);            // entry +0x08 (header region offset)
param_4[2] = lVar18 + (uVar12 & 0xffffffff);     // metadata address = base + header offset
uVar11 = thunk_...2c24ea8(surface,0);            // +0x14 bytes/tile data
uVar13 = thunk_...2c24f68(surface,0);            // +0x18 width in tiles
uVar14 = thunk_...2c24d28(surface,0);            // +0x2c row of tile data
uVar3  = FUN_fffffff0084d7b70(uVar11,uVar13,uVar14);
*(u32 *)(param_4+1) = uVar3;
...
iVar8 = thunk_...2c24ea8(surface,0);             // +0x14
iVar9 = thunk_...2c24ba8(surface,0);             // +0x00
iVar4 = thunk_...2c24f68(surface,0);             // +0x18
iVar5 = thunk_...2c24c68(surface,0);             // +0x04
*(int *)(param_4+4) = iVar9 * iVar8 * iVar4 * iVar5;   // 32-bit product
...
uVar12 = thunk_...2c1e4e8(surface,1);            // plane 1 record +0x00
param_4[8] = lVar18 + (uVar12 & 0xffffffff);
```

* `lVar18` is the mapped plane base (`*(u64 *)(lVar16+0x28)`), so
  `+0x08`/`+0x0c` become **DMA addresses**, and the tile-size products become
  lengths.  The 32-bit products (`iVar9*iVar8*iVar4*iVar5` at l.165, and
  `iVar5*iVar4*iVar6*iVar7*(iVar8>>3)` at l.204, and `*2` at l.259) are
  overflow-prone — again F2/F3, not F1.
* `+0x34`, `+0x38`, `sliceCount` are never read (they are not in the import
  list and not in the function).
* **Verdict: uses compressed geometry (region offsets as DMA addresses, sizes)
  but ignores the F1 fields.**

## 6. `com.apple.driver.AppleH11ANEInterface` — imports, never calls

* Imports `0x9c291a8` and `0x9c29268` (region offsets) at GOT slots 164/165,
  but the resolved stubs `0xfffffff008a81e64` / `0xfffffff008a81e74` have
  **zero** direct `BL` sites in the 347 KB of disassembly.  No
  `0x9c28af0`, no `0x9c297a8`, `0x9c297bc`, `0x9c2987c`.
* **Verdict: not reachable / ignores.**

## 7. `com.apple.driver.AppleMobileDispH14P-DCP`,
   `com.apple.iokit.IOMobileGraphicsFamily-DCP`,
   `com.apple.iokit.IOMobileGraphicsFamily` — the only raw-record consumers

These three are the only kexts in the whole kernelcache that import
`getCompressedPlaneEntry` (`0x9c28af0`): GOT hits at file offsets `0xe70710`,
`0x101e128`, `0x10262a0`, mapped through the fileset segment tables to
`__DATA_CONST` of the three bundles above.  They read the 0x3c record directly,
so they *could* read `+0x34`/`+0x38`.  They do not.

### 7.1 `AppleMobileDispH14P-DCP` — `FUN_fffffff008e9a684`

`dumps/dcp14/fn_fffffff008e9a684.c:79-91` (HTPC branch, compression type 1):

```c
iVar3 = thunk_...2c1ea7c(param_1,uVar22);
piVar12 = (int *)thunk_...2c24af0(param_1,uVar22);  // raw 0x3c entry
if (piVar12 == 0) return 0;
*(int *)(param_6 + uVar22*4) = piVar12[7];          // +0x1c height in tiles
*(int *)(param_2 + uVar22*4) = piVar12[3];          // +0x0c data region offset
*(int *)(param_4 + uVar22*4) = piVar12[2];          // +0x08 header region offset
*(int *)(param_3 + uVar22*4) =
     piVar12[3] + *piVar12*iVar3*piVar12[1]*piVar12[5]*piVar12[6] - 1;  // 32-bit
iVar3 = piVar12[2] +
        ((uint)piVar12[6] >> (*(byte *)((long)piVar12+0x22) & 0x1f))*piVar12[7] - 1;
```

and l.515-525 (non-HTPC branch):

```c
lVar15 = thunk_...2c24af0(param_1,uVar22);
iVar8 = *(int *)(lVar15 + 0xc);     // +0x0c data region offset
*(int *)(param_2 + uVar22*4) = iVar8;
*(int *)(param_3 + uVar22*4) = iVar8 + iVar3;
iVar3 = *(int *)(lVar15 + 8);       // +0x08 header region offset
*(int *)(param_4 + uVar22*4) = iVar3;
goto ...;                            // param_5 = headerOffset + iVar7
```

`FUN_fffffff008ea818c:424-426` only tests `*(char *)(entry+0x20)` (compression
type) to set a change flag.  No `+0x34`/`+0x38`.

### 7.2 `IOMobileGraphicsFamily-DCP` — `FUN_fffffff009a71064`

`dumps/iomgfdcp/fn_fffffff009a71064.c:42-54`:

```c
lVar10 = thunk_...2c24af0(param_1,uVar15);          // raw entry
if (lVar10 != 0 && *(char *)(lVar10+0x20) == '\x03') {   // CT == 3
  uVar7 = *(uint *)(lVar10 + 8);                    // +0x08 header region offset
  uVar2 = *(uint *)(lVar10 + 0xc);                  // +0x0c data region offset
  iVar4 = thunk_...2c1e5b4(param_1,uVar15);         // plane size
  thunk_...3a60ec0(lVar8 + (ulong)uVar2, iVar4, 0, iVar4);  // IOMemsetWithFill
}
```

`3a60ec0` resolves to `0xfffffff00aa64ec0`, which clamps its 4th argument and
calls the `(dst, fill, size)` memset at `0xfffffff00aa65d70`; so this is a
**memset of `planeSize` bytes at `mappingBase + dataRegionOffset`**.
`FUN_fffffff009a7ed6c:121-122` and `FUN_fffffff009a7fdfc:120-121` instead use
`entry+0x08` as an offset into the mapping to inspect 16 bytes of metadata:
`lVar12 = lVar11 + (ulong)*(uint *)(lVar12 + 8); if (*pcVar2 != 0) ...`.

### 7.3 `IOMobileGraphicsFamily` — `FUN_fffffff009aaf910`

`dumps/iomgf/fn_fffffff009aaf910.c:32-48`:

```c
lVar6 = thunk_...2c24af0(param_1,0);                 // plane 0 raw entry
if ((lVar6 == 0) || (*(char *)(lVar6+0x20) != '\x02')) {   // CT != 2
  uVar9 = thunk_...2c1b1a8(param_1);                 // alloc size
  uVar8 = uVar9; uVar7 = 0;
} else {
  uVar1 = *(uint *)(lVar6 + 8);                      // +0x08 header region offset
  iVar3 = thunk_...2c1b1a8(param_1);                 // alloc size
  uVar9 = iVar3 - uVar1;
  thunk_...3a60ec0(lVar4, uVar8, 0, uVar8);          // memset(base, 0, headerOffset)
  lVar4 += uVar8;
  uVar7 = 0xff;
}
thunk_...3a60ec0(lVar4, uVar9, uVar7, uVar8);        // memset(base+headerOffset, fill, allocSize-headerOffset)
```

### 7.4 `IOMobileGraphicsFamily` — `FUN_fffffff009abc21c` (the plane-descriptor copy)

`dumps/iomgf/fn_fffffff009abc21c.c:119,166-176`:

```c
puVar21 = (undefined8 *)thunk_...2c24af0(param_2,uVar20);   // raw entry
...
uVar12 = *puVar21;              puVar18[1] = puVar21[1];  *puVar18 = uVar12;   // +0x00..0x0f
uVar12 = puVar21[2];            puVar18[3] = puVar21[3];  puVar18[2] = uVar12; // +0x10..0x1f
*(u8  *)(puVar18+4)        = *(u8  *)(puVar21+4);          // +0x20
*(u16 *)((long)puVar18+0x21) = *(u16 *)((long)puVar21+0x21); // +0x21..0x22
*(u32 *)((long)puVar18+0x23) = *(u32 *)((long)puVar21+0x24); // +0x24..0x27
*(u64 *)((long)puVar18+0x2b) = *(u64 *)((long)puVar21+0x2c); // +0x2c..0x33
*(u8  *)((long)puVar18+0x27) = *(u8  *)(puVar21+5);          // +0x28 footprint
```

The destination descriptor is 0x50 bytes and the copy **stops at source
`+0x33`**.  `+0x34`/`+0x38` are not copied and the local buffer ends before
them.  This is the strongest single piece of evidence that the hardware plane
descriptor has no per-slice fields.

### 7.5 Display verdict

* The display stack is a genuine offset consumer of `+0x08`/`+0x0c`
  (memsets into the surface mapping, metadata inspection), and a consumer of
  compression type / tile geometry.
* It never reads `+0x34`, `+0x38` or `sliceCount`.
* The branch selector at DCP14 `FUN_fffffff008e9a684:67` is **not** the
  compression type: `thunk_2c1eb48` resolves to `0x9c22b48`, the getter for
  the 0x38 plane record byte **`+0x36` = `IOSurfaceAddressFormat`**.  The
  parser writes it from the XML key of the same name:
  `disassembly 0xfffffff009c1b728-0x9c1b73c`
  `strb wzr,[x2,#0x36]! ; ... adrp/add "IOSurfaceAddressFormat" ; bl 0x9c20114`
  (Ghidra drops the third argument in `fn_fffffff009c1af14.c:441`; the
  disassembly shows `x2 = plane+0x36`).
  So `IOSurfaceAddressFormat` is attacker-controlled and selects the display
  branches: 0 = plain plane base/size, 1 = HTPC (also requires compression
  type 1), 2/3 = compressed (`FUN_fffffff008e9a684:416-423` checks
  `(addressFormat & 0xfe) == 2`), 5 = another compressed layout, other values
  return 0.  A CT=4 surface with `IOSurfaceAddressFormat=2` or `3` therefore
  *does* reach the offset arithmetic in §7.1 — but that arithmetic still uses
  only `+0x08`/`+0x0c` and tile geometry, never `+0x34`/`+0x38`/`sliceCount`.
* **Verdict: uses other compressed-plane fields; ignores the F1 fields.**

---

## 8. Where the F1 fields actually go

`FUN_fffffff009c2c18c` (`dumps/ios272/fn_fffffff009c2c18c.c`) is the only
producer of `IOSurfaceInfo`:

* l.209 `puVar1[0x10] = *(undefined8 *)((long)puVar10 + 0x34);`
  → plane entry `+0x80` = `dataPerSlice | headerPerSlice<<32`;
* l.217-219 `uVar7 = *(undefined4 *)(lVar15 + 0x3b8);`
  `*(undefined4 *)((long)param_2 + 0x74) = uVar7;`
  → info `+0x74` = sliceCount.

Its six call sites are inside IOSurfaceRootUserClient methods only
(`reports/DISPATCHER_RE.md` §Table A):

| selector | handler | structOut |
|---|---|---|
| 0 (create) | `0x9c3ab8c` | 0xc68 |
| 2 (use+info) | `0x9c3b3ac` | 0xc68 |
| 4 (lookup by id) | `0x9c3b628` | 0xc68 |
| 6 (create from memory) | `0x9c3bb20` | 0xc68 |
| 7 (create from range) | `0x9c3bf44` | 0xc68 |
| 34 | `0x9c397d8` | 0xc68 |

The whole-kernelcache scan finds **no other importer** of `0x9c2c18c`
(GOT import count 0, raw pointer 0).  There is therefore no in-kernel path by
which a driver receives `IOSurfaceInfo`; the struct exists for user space.

---

## 9. Verdict and best candidate

**No kernel consumer of `+0x74`, `+0x80`, `+0x84` exists in iOS 27.2 24B115.**
The F1 corruption is invisible to every kernel driver:

* the three accessors (`0x9c297a8`, `0x9c297bc`, `0x9c2987c`) are imported by
  nobody and called by nobody;
* the raw-record accessor (`0x9c28af0`) is imported only by the three display
  kexts, and all of their record reads stop at `+0x33`;
* the `IOSurfaceInfo` export is called only by the user-client selectors.

The **closest** kernel candidates, in order of relevance:

1. **Display / DCP path** (`AppleMobileDispH14P-DCP:FUN_fffffff008e9a684`,
   `IOMobileGraphicsFamily-DCP:FUN_fffffff009a71064`,
   `IOMobileGraphicsFamily:FUN_fffffff009aaf910`, `FUN_fffffff009abc21c`).
   It is the only code that walks the raw 0x3c record; it turns `+0x08`/`+0x0c`
   into a mapping offset / memset address and `+0x00..0x1c` into sizes.  It
   would be the natural place for a per-slice consumer to exist, but the
   descriptor copy demonstrably ends at `+0x33`; the compressed branches are
   selected by the attacker-controlled `IOSurfaceAddressFormat` (`+0x36`), not
   by the F1 fields, and even then they read only `+0x08`/`+0x0c` and tile
   geometry.  Userspace operation:
   `IOMobileFramebuffer` surface swap / `swap_apply_fences`
   (WindowServer / backboardd, not an app-reachable ioctl).
2. **Scaler ioctl** (`validateCompressedTileBuffers`,
   `FUN_fffffff008cfdfac`).  Uses `+0x08`/`+0x0c` + `surface+0x90` and 32-bit
   expected-size products; ignores slices.  Userspace operation:
   `IOSurfaceAccelerator` request via `AppleM2ScalerCSCDriver` user client.
3. **AVE** (`FUN_fffffff0085287f4`).  Builds DMA addresses as
   `planeBase + entry[+0x0c]` and metadata as `planeBase + entry[+0x08]`;
   ignores slices.  Userspace operation: VideoToolbox encode session
   (`AppleAVE2` user client).

If the F1 lie is exploitable at all, the consumer must be **user space**: the
only copies of `+0x74`/`+0x80`/`+0x84` leave the kernel in the 0xc68-byte
`IOSurfaceInfo` returned by selectors 0/2/4/6/7/34, and a user-space GPU/Media
driver that re-derives `slice * (dataPerSlice + headerPerSlice)` from that
struct and feeds the result back to a kernel driver is the only remaining
candidate.  Metal's user-space driver is not part of this kernelcache; the
`dsc/272/IOSurface` image is the IOSurface.framework (truncated DSC image,
export trie beyond EOF), and it contains only the property-key string
`IOSurfaceSliceCount`, not an accessor.  Verifying the Metal path requires the
full dyld shared cache / `Metal` + `AGX*` userspace binaries, which are not in
this workspace.

### 9.1 Adjacent observation (not F1)

The display memset in `IOMobileGraphicsFamily-DCP:FUN_fffffff009a71064:52-54`
uses the **tile data region offset** `entry+0x0c` as an offset and the
**plane size** as the length, with no clamping against `IOSurfaceAllocSize`:

```c
uVar2 = *(uint *)(lVar10 + 0xc);                  // data region offset
iVar4 = thunk_...2c1e5b4(param_1,uVar15);         // plane size
thunk_...3a60ec0(lVar8 + uVar2, iVar4, 0, iVar4); // memset(base+offset, 0, planeSize)
```

The parser allows `dataRegionOffset` up to
`planeSize + planeBase - entry[0xc]*entry[6]*sliceCount` (64-bit data-region
check), so with `planeBase == 0` the memset ends at
`dataRegionOffset + planeSize`, i.e. up to `planeSize - dataRegionTotal*sliceCount`
bytes past `IOSurfaceAllocSize`.  This is a separate offset/length bug that
F1's 32-bit wrap can help satisfy, but it is driven by `+0x0c`, not by
`+0x34`/`+0x38`.  It is only reachable from the display pipeline
(`IOMobileFramebuffer`), not from an app ioctl; and it requires
compression type 3 (`entry+0x20 == 3`) on that display driver.

### 9.2 Suggested next steps

1. **User space (highest value).** Capture `IOSurfaceInfo` from selector 0/2/34
   in a normal app, then feed the same surface to Metal
   (`MTLTexture` from `IOSurface`) and to `IOSurfaceAccelerator` and diff the
   resulting kernel-visible request.  The three fields have no kernel reader,
   so any use must be in `Metal`/`AGX*`/`IOSurfaceAccelerator.framework`.
   Those binaries are not in this workspace (`dsc/272/IOSurface` is only the
   IOSurface.framework DSC image and is truncated past `__LINKEDIT`, so its
   export trie cannot be parsed).
2. **Display path on device.** The display stack is the only kernel code that
   walks the raw 0x3c record.  If a surface can be handed to
   `IOMobileFramebuffer` with `IOSurfaceAddressFormat = 2/3` and
   compression type 4, watch `param_3` (`+0x0c + tiles*bytes`) and the
   `IOMobileGraphicsFamily-DCP` memset at `0x9a71064:54`; this is where an
   offset/length bug would show, but it is a `+0x08`/`+0x0c` bug, not F1.
3. **Do not expect** any of AGX/IOGPU/scaler/AVE/ANE to touch `+0x74`/`+0x80`
   `/+0x84`; the import scan is exhaustive for this kernelcache.

---

## 10. Reproduce

```
# whole-kernelcache importer scan (no external tools)
python3 - <<'EOF'
import struct
d=open("kc/27.2_24B115_kernelcache","rb").read()
base=0xfffffff007004000
for a,name in [(0x9c28af0,'entry_ptr'),(0x9c291a8,'+0x0c'),
               (0x9c29268,'+0x08'),(0x9c297a8,'sliceCount'),
               (0x9c297bc,'+0x34'),(0x9c2987c,'+0x38'),
               (0x9c2c18c,'IOSurfaceInfo')]:
    off=(0xfffffff000000000|a)-base
    print(name, d.count(struct.pack('<Q',0x8011000000000000|off)))
EOF
```

Source dumps:
`dumps/ios272/` (IOSurface), `dumps/agx272/`, `dumps/iogpu272/`,
`dumps/scaler272/`, `dumps/ave272/`, `dumps/dcp14/`, `dumps/iomgfdcp/`,
`dumps/iomgf/`.
