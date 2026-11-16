# HARD crash 28.10.2026 — analysis and KRWProbe 1.5

## 1. Log inventory

All five runs are the same crash.  The folder timestamp is the app launch
time; the mtimes are the last write before the process disappeared.

| run dir | version | last write | last phase | last action |
|---|---|---|---|---|
| `KRWProbe-20261028-165059` | 1.3 | 16:51:38 | `HARD/geom ct-pair 2400/2496` | idx 2467 |
| `KRWProbe-20261028-165201` | 1.3 | 16:52:32 | `HARD/geom ct-pair 2400/2496` | idx 2467 |
| `KRWProbe-20261028-165247` | 1.3 | 16:54:08 | `HARD/geom ct-pair 2400/2496` | idx 2467 |
| `KRWProbe-20261028-165547` | 1.3 | 16:55:58 | `HARD/geom ct-pair 2400/2496` | idx 2467 |
| `KRWProbe-20261028-170010` | 1.4 | 17:00:30 | `HARD/geom ct-pair 2400/2496` | idx 2467 |

Every `last_action.json` is byte-identical:

```json
{"mode":"geom","phase":"ct-pair","index":2467,"total":2496,"selector":0,
 "scalarIn":[0],"structInBytes":1701,"structOutBytes":3176,
 "fields":"CT=4,IOSurfaceAllocSize=1073741824","config":"last_config.xml"}
```

`last_config.xml` is tagged `HARD geometry ct-pair 2467/2496` and contains the
valid compressed baseline plus `IOSurfacePlaneCompressionType=4` and
`IOSurfaceAllocSize=1073741824`.

Because `hard_geom_one()` writes `last_config.xml`, then `last_action.json`,
then calls sel 0, and the next iteration would overwrite both before its call,
the process died **inside or immediately after the sel 0 call for index
2467**, before index 2468 was prepared.  The 2400 checkpoint line is the last
log line because geometry only logs every 100 calls.

## 2. Index decoding (exact input)

`kBoundaryCount = 26`, `MUT_FIELD_COUNT = 17`.

```
ct-pair index = field_ordinal * (6*26) + ct_index*26 + value_index
2467          = 15 * 156 + 4*26 + 23
```

Non-CT field ordinal 15 = `MUT_ALLOC` (`IOSurfaceAllocSize`),
`kHardCTValues[4] = 4`, `kBoundaryValues[23] = 0x40000000`.

So the call was exactly:

```
sel 0, scalarIn[0] = 0 (no parent)
plist: width=64 height=64 bpe=4 fmt='BGRA'
       plane 64x64 bpe=4 bpr=256,
       IOSurfacePlaneCompressionType = 4,
       compressed baseline (tile 32x32, 2x2 tiles, hdr 8, tile data 4096,
       tile row 8192, data region 0x4000, header region offset 0),
       IOSurfaceAllocSize = 0x40000000 (1 GiB)
structOut = 0xc68
```

The same pair had already run in the singles sweep at index 419.  In the
window indices 400..421 the only values that pass the "allocation must cover
the 16 KiB image" check are `65535`, `65536` and `0x40000000` (the next two,
`0x80000000` and `0xffffffff`, were rejected — by the `root+0x198` limit
and/or OSNumber sign-extension).  `created` went from 144 at idx 400 to 147
at idx 421 — exactly +3.  Therefore **the 1 GiB surface was successfully
created at single #419**; it is not an untested boundary value.

## 3. App or kernel?

**The app was killed; the kernel did not panic.**

1. No panic log, panic string, fault address or backtrace exists in any of the
   five run folders.  A kernel panic writes a panic log and reboots; the app
   container survives, but nothing here contains one.
2. Timing strongly argues against a reboot: run `165201`'s last write is
   `16:52:32`, and the next run folder `165247` was created at `16:52:47` —
   15 seconds later; the previous gap (`165059` → `165201`) is 23 seconds.
   A panic-reboot-unlock-relaunch cycle in 15-23 s is at the very edge of
   what the hardware can do, twice in a row, while the operator is holding
   the phone.  A jetsam/SIGKILL relaunch fits these gaps naturally.
   (This is strong but not absolute; the decisive test is 1.5's capped rerun,
   see §6.)
3. The same input kills at the same index in three different binary versions
   (1.3 x4, 1.4 x1) and at wildly different wall-clock times (11 s to 81 s
   from launch to death), which is a deterministic *input* condition, not a
   watchdog and not a random panic.
4. The kernel path taken is a normal, fully bounds-checked allocation path.
   Nothing in the logs shows a kernel fault.

Most likely killer: **memorystatus (jetsam)** while the process is inside the
second 1 GiB `IOSurfaceAllocSize` request.  The surface's memory descriptor is
created with the client task as owner (`FUN_9c33c34(task, ..., props, parent)`
called from `FUN_9c3ab8c` with `*(client+0xe8)`), so the allocation is charged
to the app.  The first 1 GiB is accepted; the second identical request is
what pushes the process over its limit, and the SIGKILL arrives before
`IOConnectCallMethod` can return (hence no log line for 2467).  This is
consistent with the pool path in `FUN_9c1e624` → `FUN_9c372dc` (global
`IOSurfaceMemoryPool`) → `FUN_9c4405c`/`FUN_9c443e0` (size-class chunking).

## 4. The pasted disassembly is selector 8, not selector 9

```
fffffff009c38b0c  ldr  x8, [x2, #0x20]   ; args->scalarInput
fffffff009c38b10  ldr  w1, [x8]          ; id = *(u32*)scalarInput
fffffff009c38b14  bl   0xfffffff009c3c354
fffffff009c38b18  ldr  x8, [x19, #0x48]  ; args->scalarOutput
fffffff009c38b1c  str  xzr, [x8]         ; *scalarOutput = 0
```

`0x9c38b10` lies in `FUN_fffffff009c38af4` (`0x9c38af4`..`0x9c38b2b`).
Reading the real dispatch table (`sMethods` @ `0xfffffff008068b90`, stride
0x28) from the kext gives:

```
sel 8: handler 0x9c38af4  si=1 szi=0 so=1 szo=0
sel 9: handler 0x9c38b2c  si=0 szi=0xffffffff so=0 szo=4
```

So the snippet is **sel 8**, the "read one surface byte" method:

```c
// FUN_fffffff009c38af4
FUN_fffffff009c3c354(this, *(uint32_t *)args->scalarInput);
*(uint64_t *)args->scalarOutput = 0;
```

```c
// FUN_fffffff009c3c354
surface = FUN_fffffff009c3f1d0(client, id);   // client handle-table lookup
if (!surface) return 0xe00002c2;
ret = FUN_fffffff009c24754(surface);          // *(u8*)(*(u64*)(surface+0x178)+0x6e)
release(surface);
return ret;
```

`FUN_9c3f1d0` → `FUN_9c3f044` checks `id == 0 || id >= *(u32*)(client+0x110)`
before indexing `*(u64*)(client+0x108) + id*8`, and validates the owner
(`entry+0x10 == client+0x118`, else recurses to the parent client).  The byte
read at `surface+0x178` is the client-shared buffer, always present on a live
surface.

**A malformed set-value request cannot fault there**, for three reasons:
this handler takes no plist/struct input at all (`szi=0`); the id is
range-checked and an unknown id returns `0xe00002c2`; and the surface pointer
is a retained kernel object.

The real sel 9 is at `0x9c38b2c` and its callee is `0x9c3c3b8`:

```c
surface = FUN_9c3f1d0(client, *(u32*)in);            // NULL -> 0xe00002c2
arr = OSUnserialize(in+0xc, inSize-0xc, 0);          // NULL -> 0xe00002c2
if (!is_OSArray(arr)) return 0xe00002c2;
value = arr[0];
key   = arr[1];
if (key && !is_OSString(key)) return 0xe00002c2;
if (value) FUN_9c28220(surface, key, value, &out4);
```

A one-element array (missing key) is handled: `FUN_9c28220` passes key=NULL
to `FUN_9c255c8` → `FUN_9c24b28`, which treats the value as a dictionary of
properties to apply.  An empty array (no value) returns `0xe00002c2`.
No path dereferences the key without a NULL check.  So the pasted snippet is
a read primitive unrelated to the HARD crash and is not faulting.

## 5. What changed in KRWProbe 1.5

File: `probe/KRWProbe/main.m` (built at `/tmp/opencode/krwprobe`, IPA copied
to `probe/out/KRWProbe.ipa`, version 1.5 / build 15).

1. **Allocation cap.**  Every geometry request with `IOSurfaceAllocSize`
   chosen is clamped to `alloc_cap` (default 64 MiB).  The 1 GiB / 2 GiB /
   4 GiB boundary values are still enumerated and logged, but the kernel sees
   `alloc_clamped=67108864` and the log says
   `HARD: alloc clamp ...: 1073741824 -> 67108864`.
2. **Live-bytes accounting + connection recycling.**  `HardConn` now tracks
   `liveBytes`.  After every successful sel 0 the requested allocation is
   added; when it exceeds 256 MiB the user client is closed and reopened,
   which is the only release path for sel-0 surfaces (sel 1 is a different
   table and returns `0xe00002c2` for sel-0 ids).  This bounds the memory
   held by one client regardless of how many surfaces succeed.
3. **Resumable HARD.**  At the start of `hard_loop()` the app reads
   `<Documents>/KRWProbe-hard.txt`:

   ```
   phase=0          # 0=geometry, 1=struct, 2=race
   stage=ct-pair    # singles | ct-pair | pair
   index=2467       # first index to execute in that stage (inclusive)
   alloc_cap=67108864
   ```

   Missing file = safe defaults (phase 0, singles, index 0, 64 MiB).
   `hard_geometry()` skips earlier stages and skips `idx < index` in the
   selected stage without incrementing the call counter.  `hard_loop()` skips
   whole phases below `phase`.  The app writes the current position to
   `<Documents>/KRWProbe-progress.txt` before every call group and logs
   `[HARD] group <stage> start idx=N/total (first=...)` plus
   `[HARD] resume: phase=... stage=... index=...`.
4. The HARD banner now uses `app_version()` instead of the hardcoded `1.4`.

## 6. How to reproduce / continue

1. Install `probe/out/KRWProbe.ipa`, open it once so Documents is created.
2. **Decisive rerun:** create `KRWProbe-hard.txt` in the app's Documents:

   ```
   phase=0
   stage=ct-pair
   index=2467
   ```

   and press HARD.  The cap turns the 1 GiB request into 64 MiB.  The log
   starts with
   `[HARD] resume: phase=0 stage=ct-pair(1) index=2467 (inclusive) alloc_cap=67108864`
   and at index 2467 contains
   `HARD: alloc clamp ct-pair 2467/2496 CT=4,IOSurfaceAllocSize=1073741824: 1073741824 -> 67108864`.
   If the process now passes 2467 and continues, the cause was the allocation
   size / memory pressure (as concluded above).  If it dies again at exactly
   2467, the trigger is something else in that input and the 1 GiB theory is
   wrong; `last_action.json` will again point at 2467.
3. If the process survives 2467, set `index=2496` to continue into the
   `pair` phase.  Note: the pair phase alone does not reach the multi-slice
   validator tuple in `reports/VALIDATOR_AUDIT.md` (it needs
   `IOSurfacePlaneSize`); that shape needs a dedicated 4-field call.

