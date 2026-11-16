# IOAccel / IOGPU / AGX user-client surface — iOS 27.2 (24B115)

Image: `/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache`
67 239 936 bytes, arm64e, 263 load commands, no LC_SYMTAB (no symbols — everything below is derived from
OSMetaClass constructors, `__PRELINK_INFO` kext ranges, and `IOExternalMethodDispatch` tables located in data).

---

## 0. TL;DR

1. **Seven of the nine requested classes do not exist in this kernelcache.** `IOAccelDevice`, `IOAccelDevice2`,
   `IOAccelContext`, `IOAccelSharedUserClient`, `IOAccelSharedUserClient2`, `IOAccelSubmitter2` — zero occurrences of
   the name anywhere in the image (not as a C string, not in either metaclass registry). `IOAccelContext2` exists
   **only as a literal inside the sandbox compiled-profile string pool**, with no kernel class behind it: the sandbox
   rule is inert.
2. The live replacement stack is **IOGPUFamily** (51 classes, all registered at `0xfffffff00994xxxx`–`0xfffffff00998xxxx`)
   plus **AGXG14P** (97 classes, `0xfffffff008165000`–`0xfffffff008215000`). Only two of the nine named classes are real:
   `AGXCommandQueue` (0x948) and, as a prefix, `AGXDevice` → the real class is `AGXDeviceUserClient` (0x138).
3. `IOGPUDeviceUserClient` is the actual GPU device user client. It carries a **112-entry IOExternalMethodDispatch
   array** at `0xfffffff007fea200` (stride 0x18), split into two 56-selector halves that are chosen per-instance.
4. **Six selectors declare `checkStructureInputSize = 0xffffffff` (no kernel size validation) and their handlers never
   read `structureInputSize`.** Selector 52/53 read two u32s at `structureInput+0` and `structureInput+8` before any
   length is known — a 4-byte structure is enough to make them read past the `copyin` buffer word.
5. **The table split runs the other way from the usual assumption.** `userclient+0x103` = `private.gpu-restricted` OR
   `developer.gpu-restricted`, and when it is set the dispatcher uses `0x7fea740`, in which **28 selectors are replaced
   by an `0xe00002e2` stub** (incl. 45, 52, 53). So entitlement *narrows* the surface; the full 56-selector set —
   including all the unchecked ones — is what an un-entitled client gets.
6. `IOGPUMemoryInfoUserClient` is properly gated on `com.apple.private.ioaccelmemoryinfo`.

---

## 1. Presence check for the nine requested classes

Method: exact C-string scan of the whole image (`s[len]==0`), plus full enumeration of every `OSMetaClass` constructor
call in `__TEXT_EXEC` (two registry builders were found: `0xfffffff0099844dc` for IOGPUFamily, `0xfffffff008215ad0`
for AGX). A class that is registered *must* have its name string and an `OSMetaClass` ctor call.

| requested class | string present | in registry | verdict |
|---|---|---|---|
| `IOAccelDevice` | no | no | **absent** |
| `IOAccelDevice2` | no | no | **absent** |
| `IOAccelContext` | no | no | **absent** |
| `IOAccelContext2` | only inside the sandbox profile string pool (`0xfffffff0079de116`, no terminator) | no | **absent as a kernel class**; sandbox rule is dead |
| `IOAccelSharedUserClient` | no | no | **absent** |
| `IOAccelSharedUserClient2` | no | no | **absent** |
| `IOAccelSubmitter2` | no | no | **absent** |
| `AGXDevice` | only as prefix of `AGXDeviceUserClient` | no | **absent as a standalone class**; live class is `AGXDeviceUserClient` |
| `AGXCommandQueue` | yes (`0xfffffff00711964d`) | yes | **present**, size 0x948 |

The reason the sandbox profile still names them: the compiled SBPL string pool at `0xfffffff0079dd800`–`0xfffffff0079de400`
contains a suffix-merged run

```
... AppleKeyStoreUserClient | AppleJPEGDriverUserClient | IOAccelContext2 | IOAccel…FContext | EDevice |
    Submitter2 | haredUserClient | …2 | IOG…APU | GraphicsAccelerator2 | AGXCommandQueue |
    IOSurfaceAcceleratorClient | IOSurfaceRootUserClient | IOGPUDeviceUserClient | AGXDevice |
    AGXSharedUserClient | IOMobileFramebufferUserClient | IOPMrootDomain | AppleKeyStore | AGXAcceleratorG…
```

The `\x0f` byte is the pool's string terminator and adjacent names are suffix-merged (`IOAccel` + `\x0f` + `FContext`),
which is why the raw bytes look truncated. **Which profile (container/application/…) references this run was not
reconstructed — the compiled profile's op stream was not decoded; that binding is "не подтверждено".)**

Consequence: `iokit-open` rules keyed on `IOAccelDevice*`, `IOAccelContext*`, `IOAccelSharedUserClient*`,
`IOAccelSubmitter2` match nothing — there is no IOService with those IOClass names. Anyone who audited those rules as
"GPU access granted from the sandbox" was auditing dead letters.

### Live IOGPUFamily registry (51 classes, instance sizes)

| class | size | class | size |
|---|---|---|---|
| IOGPU | 0x2f0 | IOGPUDevice | 0x120 |
| IOGPUDeviceUserClient | 0x130 | IOGPUCommandQueue | 0x5d0 |
| IOGPUMemoryInfoUserClient | 0xe8 | IOGPUNotificationQueue | 0x30 |
| IOGPUResource | 0xa0 | IOGPUGroupMemory | 0x130 |
| IOGPUVirtualMemory | 0xd8 | IOGPUSysMemory | 0xe8 |
| IOGPUTask | 0x1d0 | IOGPUScheduler | 0x250 |
| IOGPUCommandDescriptor | 0x140 | IOGPUMappingCommandDescriptor | 0x180 |
| IOGPUEventMachine | 0x1450 | IOGPUWorkQueue | 0x100 |
| IOGPUAllocationInfo | 0x430 | IOGPUBufferMemoryDescriptor | 0xe8 |
| IOAcceleratorES | 0x88 | IOAccelGPURestartReport | 0x88 |
| (39 more: fences, memory descriptors, IOCommandQueue/Buffer, namespaces, statistics) | | | |

Full list: `tsv/classes_iogpu.tsv`.

### Live AGX registry — GPU-relevant subset (97 classes total, `tsv/classes_agx.tsv`)

| class | size | class | size |
|---|---|---|---|
| AGXDeviceUserClient | 0x138 | AGXCommandQueue | 0x948 |
| AGXShared | 0x218 | AGXCommandBuffer | 0x17c0 |
| AGXAccelerator | 0xacf0 | AGXAcceleratorG14 | 0xad08 |
| AGXAcceleratorG14P | 0xad08 | AGXAcceleratorG14P_A0 | 0xad08 |
| AGXFamilyAccelerator | 0xacf8 | AGXScheduler | 0x250 |
| AGXCommandDescriptor | 0x240 | AGXUAT | 0x3e0 |

Superclass pointers are PAC-signed GOT slots that are zero in the file image (filled at boot), so
**class → superclass edges are "не подтверждено"** except by size/layout inference (e.g. `AGXDeviceUserClient` 0x138
vs `IOGPUDeviceUserClient` 0x130 = 8-byte tail extension, consistent with inheritance, but not proven statically).

---

## 2. Dispatch tables — how they were found, and the two traps

`IOExternalMethodDispatch` entry (stride 0x18, 0x28 also observed):

```
+0x00  IOExternalMethodAction function      (ptrauth-signed code pointer)
+0x08  uint32 checkScalarInputCount
+0x0c  uint32 checkStructureInputSize
+0x10  uint32 checkScalarOutputCount
+0x14  uint32 checkStructureOutputSize
```

A live entry is recognisable because the PAC discriminator lands in the top half: high 32 bits `0x80X0bcad`,
low 32 bits = `VA & 0xFFFFFFFF`, i.e. `VA = 0xfffffff007004000 + (q & 0x0FFFFFFF)`.

**Trap 1 — dead/duplicated copies.** The IOGPUFamily table region contains the same array twice, 0x540 bytes apart
(`0x7fea200` and `0x7fea740`), i.e. a 56-entry shift. Only the copy the code actually indexes is real; the dispatcher
at `0xfffffff00994a1dc` computes `table + sel*0x18` from **both** bases and picks one per instance.

**Trap 2 — capstone `adrp` immediates come back truncated positive** (`adrp x1, 0x782a000` instead of
`0xfffffff00782a000`). Any xref search must mask/`& 0xFFFFFFFFFFFFFFFF` and re-add the image base, otherwise every
class-name xref silently misses (this is exactly how the first pass produced "no tables anywhere").

Result: 151 real tables in `__DATA_CONST`; 8 of them are bound to the GPU stack by xref from within the owning kext's
code range (plus selector-bound `cmp w1,#N` cross-check where reachable).

| table | stride | entries | xref site | bound class | confidence |
|---|---|---|---|---|---|
| `0xfffffff007fea200` | 0x18 | 112 (2×56 halves) | `0xfffffff00994a22c` | **IOGPUDeviceUserClient** | high (init at `0x…946cb0` in same bundle, `cmp w1,#0x37`) |
| `0xfffffff007fef7c0` | 0x18 | 3 | `0xfffffff00997e898` | **IOGPUMemoryInfoUserClient** | high (nearest init `0x…97e548`, 0x350 bytes back) |
| `0xfffffff007ff2f98` | 0x28 | 6 | `0xfffffff009995a28` | IOGPUNotificationQueue | medium (nearest init 0x1283c back) |
| `0xfffffff007ff7a78` | 0x28 | 3 | `0xfffffff00999eff8` | IOGPUNotificationQueue | medium |
| `0xfffffff007ff46e8` | 0x28 | 2 | `0xfffffff00999b0f0` | IOGPUNotificationQueue | medium |
| `0xfffffff007ca6f40` | 0x28 | 8 | `0xfffffff008219660` | AGXScheduler area | medium |
| `0xfffffff007caff88` | 0x18 | 7 | `0xfffffff00821f844` | AGXScheduler area | medium |
| `0xfffffff007fe3aa8` | 0x18 | 5 | `0xfffffff00993b894` | IOGPUFamily, class **не подтверждено** | low |

TSVs: `tsv/*.tsv` (see §7).

**No `IOExternalMethodDispatch` table was found for `AGXDeviceUserClient` or `AGXCommandQueue`.** `AGXDeviceUserClient`
does override the dispatcher (`0xfffffff00819ec30`) but only to special-case selector `0x107`; every other selector is
tail-called into the parent `IOUserClient::externalMethod` with the dispatch pointer untouched, which is consistent
with `AGXDeviceUserClient` inheriting `IOGPUDeviceUserClient`'s table (unproven). No external-method table bound to
`AGXCommandQueue` was found in this build; its user-visible entry points appear to be IOGPU-family
(queue creation/submit), but a table reached through a code path outside the AGX/IOGPU text ranges
cannot be ruled out — **не подтверждено**.

---

## 3. `IOGPUDeviceUserClient` — gate chain and dispatcher

### 3.1 `initWithTask` (0xfffffff009946eb8)

```asm
0x9946ed0  adrp  x8, 0xfffffff007ff2000
0x9946ed4  ldr   x8, [x8, #0x7d0]        ; global policy object
0x9946ed8  add   x9, x8, #0x2c0
0x9946edc  ldr   x8, [x8, #0x2c0]
0x9946ee0  movk  x17, #0x3c68, lsl #48
0x9946ee8  braa  x8, x17                 ; <- policy check #1 (global)
0x9946eec  cbz   w0, 0x9946f38           ; fail -> abort init
0x9946ef0  adrp  x8, 0xfffffff007fee000
0x9946ef8  ldr   x1, [x8]                ; IOProviderClass matcher
0x9946f00  bl    0xfffffff0099846cc      ; getProvider/open
0x9946f04  str   x0, [x19, #0xf8]        ; -> IOGPUDevice*
0x9946f1c..0x9946f30  braa [this->vtable+0x5d0]
0x9946f34  strb  w0, [x19, #0x100]       ; <- per-client permission byte
```

`userclient+0x100` is therefore not a hard-coded entitlement test inside this function — it is whatever the
`vtable+0x5d0` override returns (likely the "willOpen / task is GPU-entitled" path), and it is the **only thing standing
between a client and the dispatcher** (§3.2).

### 3.2 `externalMethod` (0xfffffff00994a1dc)

```asm
0x994a1e0  mov   w8, #0x2c2 ; movk w8, #0xe000, lsl #16   ; kIOReturnBadArgument
0x994a1e8  ldrb  w9, [x0, #0x100]
0x994a1ec  tbz   w9, #0, 0x994a26c                       ; no permission -> 0xe00002e6
0x994a1f0  cmp   w1, #0x37                               ; selector <= 55
0x994a1f4  b.hi  0x994a278                              ; -> pass-through to super
0x994a1f8  ldr   x9, [x2, #0x10]
0x994a1fc  cbnz  x9, 0x994a270                           ; args[0x10] must be 0
0x994a200  ldrb  w8, [x0, #0x103]                        ; "restricted" byte
0x994a208  mov   w9, #0x18
0x994a20c  umull x9, w1, w9
0x994a210  add   x10, x10, #0x740                       ; table A  = 0x7fea740  (selectors 56..111)
0x994a22c  add   x10, x10, #0x200                       ; table B  = 0x7fea200  (selectors  0..55)
0x994a244  tst   w8, #1
0x994a248  csel  x3, x11, x12, ne                        ; dispatch = A if restricted else B
0x994a268  braa  x16, x17                                ; IOUserClient::externalMethod(...)
```

`userclient+0x103` is written in `IOGPUDeviceUserClient::start`-adjacent code at `0xfffffff009949eb0` from
`0xfffffff0099658e8`:

```asm
0x9965900  adrp  x1, 0x782d000 ; add x1, x1, #0xebf
0x9965908  bl    0xfffffff009964e38        ; has_entitlement("com.apple.private.gpu-restricted")
0x996590c  tbz   w0, #0, 0x9965920
0x9965910  mov   w0, #1 ; ret
0x9965920  adrp  x1, 0x782d000 ; add x1, x1, #0xee0
0x9965944  b     0xfffffff009964e38        ; has_entitlement("com.apple.developer.gpu-restricted")
```

Both strings are in `__PRELINK_TEXT`:
* `0xfffffff00782debf` `com.apple.private.gpu-restricted`
* `0xfffffff00782dee0` `com.apple.developer.gpu-restricted`

**Finding G-1 (polarity — read the instruction stream, not the intuition).** `tst w8,#1` + `csel x3, x11, x12, ne`
means **entitled → table A (0x7fea740), not entitled → table B (0x7fea200)**. And in this build the *entitled* table is
the **smaller** one:

| range | table A `0x7fea740` (entitled) | table B `0x7fea200` (plain) |
|---|---|---|
| sel 0..20 | live | live |
| sel 21 | `0xfffffff009949520` → `0xe00002e2` | live (`0xfffffff009947cf8`) |
| sel 22..26 | live | live |
| sel 27..54 | `0xfffffff009949520` → `0xe00002e2` (28 stubs) | live |
| sel 35 | live (`0xfffffff0099484b4`) | live |
| sel 55 | live (`0xfffffff009949514`) | live |

i.e. a client that carries `com.apple.private.gpu-restricted` / `com.apple.developer.gpu-restricted` gets **28 fewer**
selectors than a client that carries neither. The security-relevant consequence is the inverse of the usual
assumption: **the full 56-selector surface, including all six `strIn = -1` selectors, is what an un-entitled client
gets.** (A prior subagent note claims the opposite polarity; the instruction trace above — `0x994a200` load,
`0x994a244` `tst`, `0x994a248` `csel ... ne` with `x11` built from `0x7fea740` at `0x994a210` — is what the binary
says.)

### 3.3 Entitlement strings present in the GPU stack

| string | VA | gate site |
|---|---|---|
| `com.apple.private.gpu-restricted` | `0xfffffff00782debf` | `0xfffffff009965904` → `userclient+0x103` |
| `com.apple.developer.gpu-restricted` | `0xfffffff00782dee0` | `0xfffffff009965924` → `userclient+0x103` |
| `com.apple.private.ioaccelmemoryinfo` | `0xfffffff0078301b1` | `0xfffffff00997eb2c` → `IOGPUMemoryInfoUserClient::externalMethod` |
| `com.apple.private.iogpu.disable_wired_collector` | `0xfffffff00782e18d` | `0xfffffff009968214` |
| `com.apple.private.ggdsw.GPUProcessProtectedContent` | `0xfffffff00782d612` | `0xfffffff00995c694` |
| `com.apple.private.agx.rt-priority-spi` | `0xfffffff00782de55` | AGX rt-priority |
| `com.apple.private.agx.performance-spi` | `0xfffffff007122a2a` | AGX perf counters |
| `com.apple.private.allow-explicit-graphics-priority` | `0xfffffff0078557ad` | IOGPU priority |
| `com.apple.private.graphics-restart-no-kill` | `0xfffffff00782de94` | restart report |

`IOGPUMemoryInfoUserClient` is the one class in this stack with a hard private-entitlement gate in the dispatch path
(`0xfffffff00997e904  bl 0xfffffff00997eb08` → `tbz` → `0xe00002c1`). Its 3-selector table is at
`0xfffffff007fef7c0` and is entered through a stub that does **not** bounds-check the selector itself; the compiler's
`csel`/`0x2bad` PAC range check does that job (`0xfffffff00997e88c`–`0xfffffff00997e8ac`).

---

## 4. Selectors that trust user-supplied structure sizes

The kernel-side check in `IOUserClient::externalMethod` (`0xfffffff00a9a18bc`) is:

```asm
0x…a18f0  ldr  w8,  [x3, #8]      ; checkScalarInputCount
0x…a18f4  cmn  w8, #1            ; == -1 ?
0x…a18fc  ldr  w9,  [x2, #0x28]  ; args->scalarInputCount
0x…a1904  b.ne fail
0x…a1908  ldr  w19, [x3, #0xc]   ; checkStructureInputSize
0x…a190c  cmn  w19, #1
0x…a1914  ldr  x8,  [x2, #0x40]  ; args->structureInputDescriptor
0x…a1968  cmp  x8,  x19          ; descriptor length must equal check size
0x…a1990  ldr  w8,  [x2, #0x38]  ; args->structureInputSize  (when no descriptor)
...
0x…a199c  ldr  w8,  [x3, #0x10]  ; checkScalarOutputCount
0x…a19a8  ldr  w9,  [x2, #0x50]  ; args->scalarOutputCount
0x…a19b4  ldr  w19, [x3, #0x14]  ; checkStructureOutputSize
0x…a19c0  ldr  x8,  [x2, #0x68]  ; args->structureOutputDescriptor
```

So the argument layout in this kernel is:

| off | field |
|---|---|
| 0x00 | version (u32) |
| 0x04 | selector (u32) |
| 0x10 | async reference word (must be 0 for IOGPU) |
| 0x20 | `structureInput` (user data, copied in) |
| 0x28 | `scalarInputCount` |
| 0x30 | `scalarInput` |
| 0x38 | `structureInputSize` |
| 0x40 | `structureInputDescriptor` (IOMemoryDescriptor) |
| 0x50 | `scalarOutputCount` |
| 0x58 | `scalarOutput` |
| 0x60 | `structureOutputSize` |
| 0x68 | `structureOutputDescriptor` |

`checkStructureInputSize == 0xffffffff` disables **both** the plain-size check and the descriptor-length check. In the
live 56-selector half of `IOGPUDeviceUserClient` that is true for **six** selectors:

| sel | handler | sIn | strIn | sOut | strOut | reads `structureInputSize`? |
|---|---|---|---|---|---|---|
| 6 | `0xfffffff0099476bc` | 0 | **-1** | 0 | 0x10 | no |
| 8 | `0xfffffff009947a54` | 0 | **-1** | 0 | **-1** | no |
| 25 | `0xfffffff009947de4` | 4 | **-1** | 1 | 0 | no |
| 45 | `0xfffffff009948af4` | 1 | **-1** | 0 | 0 | no |
| 52 | `0xfffffff0099491a0` | 2 | **-1** | 0 | 0 | no |
| 53 | `0xfffffff009949330` | 2 | **-1** | 0 | 0 | no |

Twelve entries across the 112-slot array declare `-1`, but the six duplicates live at slots 62, 64, 81, 101, 108,
109 and **three of those (101, 108, 109 = selectors 45, 52, 53) have their function pointer replaced by the
`0xe00002e2` stub** while keeping the original size metadata. In other words the "restricted" table deliberately
disables exactly the two sharpest handlers (52/53) and 45, leaving 6, 8, 25 reachable on both paths.

### 4.1 Selector 52 (`0xfffffff0099491a0`) — the sharp one

```asm
0x99941d4  ldr  x8,  [x2, #0x20]      ; structureInput
0x99941d8  ldr  w23, [x8]             ; user u32 #1  (no size known)
0x99941dc  ldr  w21, [x8, #8]         ; user u32 #2  (reads past a 4-byte input)
0x99941e0  ldr  x0,  [x2, #0x40]      ; structureInputDescriptor
0x99941e4  cbz  x0,  0x9994258
0x99941fc  mov  w1,  #0x1000          ; map request
0x9994204  blraa x8, x16              ; desc->createMapping/virtual +0xe8
0x9994210..0x9994228  second virtual +0x78 -> mapped kernel address
0x9994230  ldr  x0,  [x25, #0x40]     ; descriptor again
0x9994244  ldr  x8,  [x16, #0xb0]     ; desc->getLength()
0x9994268  cmp  x0,  x21, lsl #2      ; length >= count*4 ?
0x999426c  b.lo 0x9994288             ; -> fail
0x9994270  ldr  x0,  [x22, #0x120]    ; this->fDevice
0x9994274  mov  x1,  x23              ; index  (user)
0x9994278  mov  x2,  x24              ; data   (mapped / scalarInput)
0x999427c  mov  x3,  x21              ; count  (user)
0x9994280  bl   0xfffffff009967e24    ; IOGPUDevice::<...>(idx, data, count)
```

What the user controls here:

* `structureInput[0]` → `x1` **index** handed to `IOGPUDevice` at `0x99967e24`.
* `structureInput[8]` → `x3` **element count**, validated only as `descriptor_length >= count*4`.
* the **data** itself is `scalarInput` (`[x2,#0x30]`) in the no-descriptor path and the mapped descriptor otherwise.
* `structureInputSize` is never read, and no descriptor is required, so `IOClientCallMethod(sel=52,
  scalarInput=[…], structureInput=4 bytes)` leaves `structureInput[1]` pointing at whatever follows the `copyin`
  buffer. That is a bounded 4-byte out-of-bounds **read** of adjacent kernel heap used as a length; the value is then
  range-checked against the descriptor (or `structureInputSize`) before being used, so it does not directly become a
  write primitive — but the index path (`x1`) has no such check, and whether `0x99967e24` bounds `idx` itself is
  **не подтверждено** (the function was not fully reversed).

**Severity: medium.** Missing size check → OOB read of 4–8 bytes and an unchecked user index into an IOGPUDevice
lookup table. Not a proven write primitive.

### 4.2 Selector 53 (`0xfffffff009949330`)

Identical shape to 52 (`ldr w23,[x8]`, `ldr w21,[x8,#8]`, descriptor map, `cmp x0, x21, lsl #2`), different callee.
Same finding.

### 4.3 Selector 25 (`0xfffffff009947de4`) and 45 (`0xfffffff009948af4`)

Both start with

```asm
ldr  x0, [x2, #0x40]        ; structureInputDescriptor
cbz  x0, fail
ldr  x8, [x16, #0xe8]!      ; descriptor virtual
mov  w1, #0x1000
blraa x8, x16               ; create mapping
```

then a second virtual `+0x78` produces a kernel pointer, and the handler copies/uses it. Because `strIn == -1` the
descriptor length is never compared to anything; the only length the handler can use is the descriptor's own
`getLength()` (virtual `+0xb0`), which is consistent but means **any size descriptor is accepted**, including
zero-length, and the handler's internal reads are bounded only by whatever it does with `getLength()`.
Selectors 8 and 6 have the same `-1` descriptor pattern with additional `structureInput` dereferences.

---

## 5. Command-buffer / ring-buffer path

Nothing in `IOGPUDeviceUserClient` writes user data into a ring buffer. The device user client only *creates*
objects; the submit path lives in `IOGPUCommandQueue` (0x5d0) and `AGXCommandQueue` (0x948), which have **no
IOExternalMethodDispatch table** in this build — their submission entry points are reached through the IOGPU-family
object graph (e.g. selector 2 of the device UC returns a 0x218-byte structure output, which is the queue-creation
result), not through a second user-client selector table. What exactly that 0x218-byte blob carries was not decoded.
Deeper reverse of `IOGPUCommandQueue` was out of scope for this pass;
**"submit path has no size check" is не подтверждено, not confirmed.**

The only user→device data handoff found in the device UC is the `(index, data, count)` triple of selectors 52/53 above.

---

## 6. Top-5

1. **`IOGPUDeviceUserClient` sel 52 / 53 — no `structureInputSize` check, OOB read + unchecked index.**
   `strIn = -1`; handler reads `u32 [si+0]` and `u32 [si+8]` unconditionally; `[si+0]` becomes the index into
   `IOGPUDevice::<0x99967e24>`, `[si+8]` becomes a count validated against `descriptor_length` only. A 4-byte
   structure input is accepted. Disasm §4.1. Confidence in the missing check: high. Confidence in downstream impact:
   medium (index validation inside the callee not reversed).
2. **The unchecked selectors are on the *un-entitled* path.** Polarity in §3.2/§3.3: `gpu-restricted` (private or
   developer) switches to `0x7fea740`, which stubs out 28 selectors. A client with **no** GPU entitlement gets
   `0x7fea200` — all 56 live, including 6/8/25/45/52/53. So the "restricted" entitlement is a *reduction*, and the
   attack surface that matters is the default one.
3. **`IOGPUDeviceUserClient` sel 25 / 45 / 8 / 6 — descriptor accepted at any length.**
   `strIn = -1` means `externalMethod` compares neither `structureInputSize` nor the descriptor length against the
   table; a zero-length `IOMemoryDescriptor` is accepted where a fixed layout is expected. The handlers do use
   `getLength()` (`+0xb0`), so this is consistency, not proof of overflow — flagged because the table claims "no
   check" for a selector that clearly consumes structured input.
4. **`IOGPUDeviceUserClient` dispatcher gate is a single byte written from a virtual call.**
   `userclient+0x100` comes from `vtable+0x5d0` inside `initWithTask`; everything else (selector bound, table select)
   is downstream of it. If that override is permissive for a task class (e.g. any task that can open the provider),
   the whole 56-selector surface opens with no entitlement at all. The override itself was not reversed —
   **не подтверждено**.
5. **`IOGPUMemoryInfoUserClient` — correct gate, but a 3-selector table with a stub that does not check the selector.**
   `0xfffffff00997e88c` computes `table + sel*0x18` and relies on the compiler's `csel`/`0x2bad` PAC range check
   instead of an explicit `cmp w1,#N`. The range check makes OOB indexing trap rather than read, so this is a
   robustness note, not a bug.

---

## 7. Artifacts

```
tsv/classes_iogpu.tsv                    51 classes + instance sizes
tsv/classes_agx.tsv                      97 classes + instance sizes
tsv/iogpu_device_userclient.tsv          56 selectors (base half, 0x7fea200 + 0*0x18)
tsv/iogpu_device_userclient_private.tsv  56 selectors (private half, 0x7fea200 + 56*0x18)
tsv/iogpu_memoryinfo_userclient.tsv      3 selectors
tsv/iogpu_notificationqueue_a.tsv        6 selectors (0x28)
tsv/iogpu_notificationqueue_b.tsv        3 selectors (0x28)
tsv/iogpu_notificationqueue_c.tsv        2 selectors (0x28), both strIn/strOut = -1
tsv/agx_extmethod_8x28.tsv               8 selectors (0x28)
tsv/agx_extmethod_7x18.tsv               7 selectors (0x18)
```

TSV columns: `sel  fn  sIn  strIn  sOut  strOut` (all values hex, `0xffffffff` = "не проверять").

Helper scripts left in the directory: `kc.py` (image map), `refs.py` (correct adrp+add xref search),
`dt3.py` (dispatch-table scanner), `dasm.py` (disassembly), `agx_all.pkl` / `inits.pkl` (class registries).

---

## 8. Conclusion

**Which classes open without rights.** Of the nine named classes, seven have no kernel object at all: the sandbox
rules that name them are dead. Of the two that exist as names, `AGXDevice` is not a class (only `AGXDeviceUserClient`
is), and `AGXCommandQueue` exposes no external-method table. The real surface is:

* `IOGPUDeviceUserClient` — 56 live selectors on the default (un-entitled) path, gated only by a per-instance byte
  derived from a virtual call. Carrying `gpu-restricted` *removes* 28 of them. **This is the class that opens to a
  sandboxed client without any `com.apple.private.*` entitlement in the dispatch path itself.**
* `IOGPUMemoryInfoUserClient` — 3 selectors, hard-gated on `com.apple.private.ioaccelmemoryinfo`.
* `IOGPUNotificationQueue` — 6 + 3 + 2 selectors, no entitlement check found at the table site.
* `AGXDeviceUserClient` — inherits the IOGPU dispatcher, adds one selector (`0x107`).

**Where user sizes are trusted.** Exactly six selectors of `IOGPUDeviceUserClient` disable kernel size validation
(`checkStructureInputSize = 0xffffffff`) and their handlers never read `structureInputSize`; two of them (52, 53) read
two u32s out of the structure with no length knowledge at all, one of which becomes an unchecked index into an
`IOGPUDevice` lookup. Everything else in the table uses fixed sizes (`0`, `4`, `0xc`, `0x18`) that `externalMethod`
enforces byte-exactly.

**Not confirmed in this pass:** class→superclass edges (PAC GOT slots are zero on disk), the `vtable+0x5d0` permission
override body, the callee at `0xfffffff009967e24` (index bounds), the `IOGPUCommandQueue`/`AGXCommandQueue` submit
path, and the exact compiled sandbox profile that references the `IOAccel*` names (only the string-pool presence was
proven).
