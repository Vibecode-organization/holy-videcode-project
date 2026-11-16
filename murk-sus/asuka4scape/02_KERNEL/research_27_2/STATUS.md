# iOS 27.2 kernel R/W research — status

> **2026-10-27 update (SMITH):** the exact device build is `24B115`. The real RC
> kernel and SPTM were extracted from the 24B115 OTA:
> `work/rc115/24B115__iPhone14,7/`. The 24B115 kernel differs from 24B119 by
> 933 bytes — 15 in the Mach-O header, 918 in `__PRELINK_INFO`, **zero in any
> code segment**. The 24B115 SPTM is byte-identical to 24B119 and contains
> `VIOLATION_UAT_ILLEGAL_TTBAT_MAPPING` / `_LOCK`, so the 27.0.1 TTBAT path is
> closed. CoreGraphics RC115 contains both `CG-SEC-187882049` (Type 5 gate at
> `0x183c5cacc`) and `CG-SEC-187882136`; the repo's OOB writes do not exist on
> this build. Full verdict: `work/ОТЧЁТ_27.2_ФИНАЛ.md`.

## Target (verified over USB)

- Device: `iPhone14,7`, hardware `D27AP`, arm64e, A15/T8110.
- OS: iOS `27.2`, build `24B115`.
- Pairing: valid.
- Ghidra kernelcache version string: `Darwin Kernel Version 27.2.0 ... xnu-13432.42.3~28/RELEASE_ARM64_T8110`.
- Entry context: ordinary sandboxed app; Theos on Linux; new app project, no special entitlements.

## Confirmed binary findings

### IOSurface compressed geometry validation

`FUN_fffffff009c1af14` (`parse_properties`) has three real 32-bit truncation sites, independently reviewed by DeepSeek and checked against ARM64/p-code:

1. `0xfffffff009c1c1f4`: `mul w11,w10,w9` — `WidthInCompressedTiles * BytesPerTileData` is compared with `BytesPerRowOfTileData` after truncation. With width 3 and bytes/tile `0xAAAAAAAB`, the mathematical result is `0x200000001`, accepted as row size 1.
2. `0xfffffff009c1c45c` and `0xfffffff009c1c464`: two 32-bit multiplications for `HeightInCompressedTiles * WidthInCompressedTiles * BytesPerTileData`, used to validate `DataRegionBytesPerSlice`.
3. `0xfffffff009c1c4fc` / `0xfffffff009c1c504`: `add w11,w9,w8` and `mul w12,w11,w10` — `(DataRegionBytesPerSlice + HeaderRegionBytesPerSlice) * sliceCount` wraps to 32 bits before comparison with plane size.

These are proven validator defects, not yet arbitrary kernel R/W. They let an app create a surface whose declared compressed geometry exceeds its allocation. A consumer that computes addresses from that geometry is still required.

### Second IOSurface initializer

`FUN_fffffff009c29ee4` imports the same geometry through a different object-based path with little validation, including `fAllocSize` and `sliceCount`. Its three call contexts are being checked for userspace control and whether the path can mutate an already allocated surface. The inline capacity value 3 is not considered a bug without additional proof.

### Work-token candidate (lower priority)

The queue belongs to `IOPerfControlClient`, created internally by `IOGPU::start`, not directly exposed as a standalone user client. `0xfffffff00a9e2db4` performs a one-byte write at `entry+0x10` after an indirect callback. Exploitability requires proving destruction/reuse of the queue array during that callback. Current evidence does not establish this; IOGPU owns the client lifetime.

## Dynamic harness

`research_27_2/app` builds successfully as `KRW27.ipa` (arm64, ad-hoc signature). It contains three parser probes:

- baseline compressed type-3 surface;
- K2 row multiplication wrap (`3 * 0xAAAAAAAB -> 1`);
- K1 multi-slice wrap (`0x40000000 * 4 -> 0`).

The probes only create surfaces and read basic metadata; they do not intentionally access the invalid region.

## Current boundary

No complete exploit or arbitrary kernel R/W has been established yet. The next required evidence is a CPU/GPU consumer that uses the invalid compressed geometry for memory access, or a userspace-controllable second-initializer path that changes geometry after allocation.

## Reviewed after the first pass

- HTPC K2 produces a +4 GiB mismatch or a DART fault, not a controlled small OOB. K1 still lacks a consumer for DataRegionBytesPerSlice/HeaderRegionBytesPerSlice.
- The second initializer is fed by kernel-built descriptors (IOMFB/ANE), not directly by userspace. It does not offer an arbitrary post-allocation mutation.
- Memory-pool H1 was eliminated: the release in `c44d30` is paired with the collection's retain, not an over-release.
- `FUN_fffffff009c28a80` is the legacy compressed-data-region setter. It checks `planeIndex < 5 && planeIndex < planeCount`, so it is not an OOB by itself. It remains useful as a post-corruption write gadget if a separate bug supplies a fake IOSurface object.
- Dynamic IPA installation was attempted. The app builds correctly, but stock installd rejects ad-hoc signatures; final IPA must go through Kai's normal signing/install route. This does not affect static analysis.
