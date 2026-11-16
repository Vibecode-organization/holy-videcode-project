# ANE direct path — H11ANEInDirectPathClient / H1xANELoadBalancerDirectPathClient
**Target:** `27.2_24B115_kernelcache` (iOS 27.2, 24B115) · AppleH11ANEInterface (integrated into `__PRELINK_TEXT` / `__TEXT_EXEC`)
**Subagent:** S · date 2026-10-28

---

## 0. Where the classes live

| item | VA | note |
|---|---|---|
| `H11ANEInDirectPathClient` name string | `0xfffffff007449545` (`__PRELINK_TEXT`) | 3 code refs: `0x89c02dc`, `0x89c04e0`, `0x89c04d0`-block |
| `H1xANELoadBalancerDirectPathClient` name string | `0xfffffff0074495b3` | 3 code refs: `0x89c0a1c`, `0x89c0c20` |
| `site.` mirror names | `0xfffffff007449563`, `0xfffffff0074495db` | typeinfo / pretty-function table |
| `site.`-table refs | `0xfffffff00796512f`, `0xfffffff007965153`, `0xfffffff007af0b9b` | same kasan type-site string family as the `site.` names — **not** a sandbox gate (per x_jpeg finding: 5062 such rows exist image-wide). Container reachability of both classes is the task's premise and was not re-derived here — **не подтверждено** |

`OSMetaClass` registrar pattern (both classes, identical shape):

```
adrp x1, "<ClassName>"            ; name
adrp x2, 0xfffffff00ae42xxx       ; superclass metaclass slot
mov  w3, #0x1a0                   ; sizeof(class) = 0x1a0 = 416 bytes
bl   OSMetaClass::OSMetaClass(name, super, size)      ; 0xa894d88
adrp x16, 0xfffffff007dc_xxx
add  x16, x16, #imm ; add x16,x16,#0x10
pacda x16, x17 ; str x16, [x0]    ; metaclass vtable
```

**sizeof = 0x1a0 for both direct-path clients** (and for the two non-direct siblings — the family is uniform).

### Class / constructor / vtable binding

| class (by code adjacency) | instance ctor | kalloc_type desc | OSMetaClass* passed in ctor | instance vtable |
|---|---|---|---|---|
| `H11ANEInDirectPathClient` | `0xfffffff0089c0520` | `0xfffffff007dd07d8` | `0xfffffff00ae42cc8` | `0xfffffff007dc2d58` |
| `H1xANELoadBalancerDirectPathClient` | `0xfffffff0089c0c60` | `0xfffffff007dd0858` | `0xfffffff00ae42d18` | `0xfffffff007dc3a68` |
| sibling A | `0xfffffff0089c0180` | `0xfffffff007dd0798` | `0xfffffff00ae42ca0` | `0xfffffff007dc26d0` |
| sibling B | `0xfffffff0089c08c0` | `0xfffffff007dd0818` | `0xfffffff00ae42cf0` | `0xfffffff007dc33e0` |

Ctor body (both): `kalloc_type(desc, 0x1a0)` → `IOService(OSMetaClass*)` → zero `[obj+0x188]`, `[obj+0x190]` → install vtable.
`[obj+0x188]` = ANEClientDevice*, `[obj+0x190]` = secondary handle (zeroed, set later), `[obj+0x198]` = reference passed to externalMethod, `[obj+0xd8]` = state byte.
Inheritance order itself (`super` slots `0xae42c78/0xcc8/0xcf0/0xd18` are all zero in-file, runtime-initialised) — **не подтверждено**.

---

## 1. Dispatch tables

Both classes route through the same IOService-style `externalMethod`. Only **two** 5-arg dispatcher call sites exist in the whole kernel image — both in this kext:

* `0xfffffff0089c16e4` → table `0xfffffff007dc4130`, count `0x10` → logs `H11ANEInUserClient(%p)`
* `0xfffffff0089c197c` → table `0xfffffff007dc43b0`, count `0x0b` → logs `H11ANEInDirectPathClient(%p)`

There is **no third dispatcher for `H1xANELoadBalancerDirectPathClient`**. Either it shares the direct-path table through the same vtable slot (`0xfffffff007dc3a68[87] = 0xfffffff0089c1974` → `b 0xfffffff0089c1478`, identical to the direct-path client) or it exposes nothing. The table is chosen at runtime inside `0x89c1478`/`0x89c197c`, and the selector→method map below is the one that logs the direct-path class name. Whether a LoadBalancer client actually reaches it — **не подтверждено** (needs a live `newUserClient` type).

### 1.1 Dispatcher semantics (verified, `0xfffffff00a9b0888`)

```
w0 = 0xe00002c2 ; if (table == NULL) return 0xe00002bc
if (count <= selector) return 0xe00002c2
entry = table + selector * 0x28            ; add x8,x8,x8,lsl#2 ; lsl#3  => stride 0x28
if (entry->scalarIn  != -1 && entry->scalarIn  != args->scalarInputCount)  return 0xe00002c2
if (entry->structIn  != -1)
    if (args->structInDescriptor) { if (descriptor->getLength() != entry->structIn) return 0xe00002c2 }
    else                          { if (args->structInSize         != entry->structIn) return 0xe00002c2 }
if (entry->scalarOut != -1 && entry->scalarOut != args->scalarOutputCount) return 0xe00002c2
if (entry->structOut != -1)  ... same, against args->structOutSize / structOutDescriptor
if (args->asyncReference[0] && entry->allowAsync == 0) return 0xe00002c2
if (entry->entitlement) { if (!taskHasEntitlement(current_task, entry->entitlement)) return 0xe00002d8 }
if (entry->function == NULL) return 0xe00002ea
return entry->function(target, reference)
```

**`0xffffffff` = “unrestricted”** (`cmn w8,#1`), confirmed at four check sites. **Neither ANE table uses it** — every selector is exact-match on both sizes and both scalar counts.

`IOExternalMethodDispatch2022` (0x28) as observed:

| off | field |
|---|---|
| 0x00 | `IOExternalMethodAction function` |
| 0x08 | `checkScalarInputCount` (0xffffffff = skip) |
| 0x0c | `checkStructureInputSize` (0xffffffff = skip) |
| 0x10 | `checkScalarOutputCount` |
| 0x14 | `checkStructureOutputSize` |
| 0x18 | `allowAsync` (u8) — only direct-path sel 2 sets it |
| 0x20 | `const char *entitlement` — **0 for all 22 ANE selectors** |

`IOExternalMethodArguments` offsets proven by cross-referencing dispatcher + 3 handlers:

| off | field |
|---|---|
| 0x08 | `asyncReference[0]` |
| 0x20 | `scalarInput` (u64*) |
| 0x28 | `scalarInputCount` (u32) |
| 0x30 | `structureInput` (kernel copy) |
| 0x38 | `structureInputSize` (u32) |
| 0x40 | `structureInputDescriptor` (IOMemoryDescriptor*) |
| 0x48 | `scalarOutput` |
| 0x50 | `scalarOutputCount` |
| 0x58 | `structureOutput` |
| 0x60 | `structureOutputSize` |
| 0x68 | `structureOutputDescriptor` |

---

## 2. Selector table — `H11ANEInDirectPathClient` (table `0x7dc43b0`, 11 entries)

| sel | method | fn | sIn | structIn | sOut | structOut | async | ent |
|---|---|---|---|---|---|---|---|---|
| 0 | `ANE_DeviceOpen` | `0xfffffff0089c2948` | 0 | 0x88 | 0 | 0x88 | – | – |
| 1 | `ANE_DeviceClose` | `0xfffffff0089c2aa0` | 0 | 0 | 0 | 0 | – | – |
| 2 | `ANE_ProgramSendRequest` | `0xfffffff0089c37dc` | 1 | 0xc50 | 0 | 0x40 | **1** | – |
| 3 | `ANE_ProgramOutputSetEnqueue` | `0xfffffff0089c3ac0` | 0 | 0x28 | 0 | 0 | – | – |
| 4 | `ANE_ProgramInputsReady` | `0xfffffff0089c3bb0` | 0 | 0xc20 | 0 | 0 | – | – |
| 5 | `ANE_MemoryMapRequest` | `0xfffffff0089c3ca0` | 1 | 0x828 | 1 | 0 | – | – |
| 6 | `ANE_MemoryUnMapRequest` | `0xfffffff0089c3e34` | 0 | 0x828 | 0 | 0 | – | – |
| 7 | `ANE_SessionHintRequest` | `0xfffffff0089c3fb4` | 0 | 0x10 | 0 | 0x18 | – | – |
| 8 | `ANE_ProgramChainingSetActiveProcedure` | `0xfffffff0089c413c` | 0 | 0x20 | 0 | 0 | – | – |
| 9 | `ANE_MapMutableWeightsBuffer` | `0xfffffff0089c422c` | 0 | 0x208 | 1 | 0 | – | – |
| 10 | `ANE_UnmapMutableWeightsBuffer` | `0xfffffff0089c44e8` | 1 | 0 | 0 | 0 | – | – |

### 2.1 For comparison — `H11ANEInUserClient` (table `0x7dc4130`, 16 slots, 11 populated)

| sel | fn | sIn | structIn | sOut | structOut |
|---|---|---|---|---|---|
| 0 | `0x89c2948` `ANE_DeviceOpen` | 0 | 0x88 | 0 | 0x88 |
| 1 | `0x89c2aa0` `ANE_DeviceClose` | 0 | 0 | 0 | 0 |
| 2 | `0x89c2b88` `ANE_DoProgramCreate` | 0 | 0x20 | 0 | 0 |
| 3 | `0x89c2d30` | 0 | 0x20 | 0 | 0 |
| 4 | `0x89c2ed8` | 0 | 0x38 | 0 | 0x38 |
| 5 | `0x89c301c` | 0 | 0x38 | 0 | 0 |
| 6 | `0x89c310c` | 0 | 0x10 | 0 | 0 |
| 7 | `0x89c31fc` | 0 | 0 | 0 | 0x80 |
| 8 | `0x89c32ec` | 0 | 0x20 | 0 | 0 |
| 9 | `0x89c3498` | 0 | 0x20 | 0 | 0 |
| 10 | `0x89c3644` | 0 | 0x10 | 0 | 0x18 |
| 11-15 | 0 | — | — | — | — |

---

## 3. Top-5 — disassembly

### #1 — `ANE_MemoryMapRequest`, sel 5 (`0x89c3ca0`), struct 0x828 + 1 scalar in, 1 scalar out

```
89c3d64  ldr  x21, [x19,#0x30]        ; args->structureInput  (0x828-byte kernel copy)
89c3d68  cbz  x21, 89c3da8            ; NULL -> error
89c3d6c  ldr  x8,  [x19,#0x20]        ; args->scalarInput
89c3d70  ldr  x22, [x8]               ; scalarInput[0]   <-- user value
89c3d74  cmp  x22, #0
89c3d78  cset w2,  ne                 ; bool = (scalar[0] != 0)
89c3d7c  mov  x0, x20                 ; this->[0x10] = ANEClientDevice*
89c3d80  mov  x1, x21                 ; &struct
89c3d84  bl   0x89bf1d4               ; client->memoryMapRequest(struct*, bool)
89c3d88  cmp  x22, #0
89c3d8c  ccmp w0, #0, #0, ne          ; if (scalar[0] && ret==0) -> error
89c3d90  b.ne 89c3e20
89c3d94  mov  w0, #0
89c3d98  ldr  x8,  [x21,#0x818]       ; read struct[0x818]  (in-bounds: 0x818+8 <= 0x828)
89c3d9c  ldr  x9,  [x19,#0x48]        ; args->scalarOutput
89c3da0  str  x8,  [x9]               ; scalarOutput[0] = struct[0x818]
89c3da4  b    89c3e20
```

Callee `0x89bf1d4` (`H11ANEInDirectPathClient::memoryMapRequest`):

```
89bf28c  str  x21, [x20,#0x800]       ; <-- writes the *kernel* ANEClientDevice* into user-struct field 0x800
89bf290  ldr  x0,  [x21,#0x20]        ; device->[0x20]
89bf294  mov  x1,  x20                ; &struct
89bf298  mov  x2,  x19                ; bool
89bf29c  b    0xfffffff0089d1e2c
```

`0x89d1e2c` validates (`0x89d201c`), builds a stack descriptor from the struct (`0x89d215c`), reads a **u32 field at struct+0x820** as part of that descriptor, and calls `0x89cf69c`.

**Assessment.** Sizes are exact-matched at the dispatcher, so nothing here is a size confusion. The two things worth a second look:
* `str x21,[struct+0x800]` writes a raw kernel object pointer into the 0x828 buffer at a fixed offset. No `structureOutput` is declared for this selector, so it is **not** copied back to userspace — no leak on this path. If any later code ever copies the whole 0x828 back, that field is a KASLR-defeating pointer. **Не подтверждено** whether any sibling path returns it.
* `struct+0x820` is consumed as a 32-bit field inside the map descriptor; `0x820+4 <= 0x828`, in bounds. Its meaning (index? size?) — **не подтверждено**, need the body of `0x89d215c`.

### #2 — `ANE_UnmapMutableWeightsBuffer`, sel 10 (`0x89c44e8`) — user scalar as a map key

```
89c45ac  ldr  w8, [x20,#0x28]         ; scalarInputCount
89c45b0  cbz  w8, 89c45dc             ; 0 -> error (dispatch already forced ==1)
89c45b4  ldr  x8, [x20,#0x20]         ; scalarInput
89c45b8  ldr  w1, [x8]                ; scalarInput[0] truncated to u32   <-- user value
89c45bc  mov  x0, x19                 ; ANEClientDevice*
89c45c0  bl   0x89be780
89c45c4  mov  w0, #0
```

Callee `0x89be780` — the value is used as a **hash-map key**, not an array index:

```
89be7a4  ldr  x19,[x0,#0x100]         ; container
89be7a8  cbz  x19, 89be814            ; NULL -> log+error
89be7b0  bl   lock
89be7b8  add  x0, x20,#0x108          ; map
89be7bc  sub  x1, x29,#0x24           ; &key (the u32)
89be7c0  bl   0x89be6a8               ; map.lookup(&key)
89be7c4  cbz  x0, 89be850              ; miss -> error
```

**Assessment.** No OOB: unknown handle → lookup miss → error. A u64→u32 truncation exists (only low 32 bits of the user scalar are used) but the key space is the map's. Safe as written.

### #3 — `ANE_DeviceOpen`, sel 0 (`0x89c2948`) — 0x88 in / 0x88 out, full struct copy

```
89c2a0c  ldr  w8, [x20,#0x38]         ; structureInputSize
89c2a10  cmp  w8, #0x88
89c2a14  b.lo 89c2a84                 ; < 0x88 -> kIOReturnBadArgument
89c2a18  ldr  w8, [x20,#0x60]         ; structureOutputSize
89c2a1c  cmp  w8, #0x88
89c2a20  b.lo 89c2a84
89c2a24  ldr  x8, [x20,#0x58]         ; structureOutput
89c2a28  ldr  x9, [x20,#0x30]         ; structureInput
89c2a2c  ldp  q0,q1, [x9]             ; copy 0x88 bytes in -> out
...
89c2a3c  ldr  x9, [x9,#0x80]
89c2a40  str  x9, [x8,#0x80]
89c2a44-50 stp q6,q7 / q4,q5 / q2,q3 / q0,q1
89c2a54  ldr  x1, [x20,#0x58]         ; out ptr
89c2a58  cbz  x1, 89c2a84
89c2a5c  mov  x0, x19                 ; ANEClientDevice*
89c2a80  b    0xfffffff0089ba9e8     ; tail call
```

**Assessment.** `b.lo` (>=) here is *looser* than the dispatcher's `==`, so the effective contract is still exact-0x88 — the dispatcher wins. Copy is 0x88/0x88. Clean.

### #4 — `ANE_SessionHintRequest`, sel 7 (`0x89c3fb4`) — 0x10 in / 0x18 out

```
89c407c  ldr  x1, [x20,#0x30]         ; structureInput
89c4080  ldr  x2, [x20,#0x58]         ; structureOutput
89c4084  cmp  x1, #0
89c4088  ccmp x2, #0, #4, ne          ; require both non-NULL
89c408c  b.ne 89c40c4
...
89c40c4  mov  x0, x19
89c40ec  b    0xfffffff0089bf39c
```
**Assessment.** Both pointers are the kernel copies; sizes fixed at 0x10/0x18 by the table. No arithmetic on caller data before the tail call. Nothing to exploit at this layer.

### #5 — `ANE_ProgramSendRequest`, sel 2 (`0x89c37dc`) — the only async selector

```
89c38b4  mov  w20,#0x2c2 ; movk w20,#0xe000,lsl#16     ; default kIOReturnBadArgument
89c38bc  mov  x0, x19
89c38c0  bl   0x89bb408                  ; device->state()
89c38c4  ldr  w8, [x0,#0xc]
89c38c8  cmp  w8, #2
89c38cc  b.ne 89c38dc
89c38d0  mov  w8, #5
89c38d4  orr  w20, w20, w8               ; error |= 5
89c38dc  ... same read, cmp #1 -> 0xe0000000|... path
89c3910  ldr  x22, [x21,#0x30]           ; structureInput (0xc50)
89c3914  cbz  x22, 89c3938               ; NULL -> log path
89c3918  ldr  x24, [x21,#8]              ; asyncReference[0]
89c391c  cbz  x24, 89c3974               ; 0 -> log path
89c3920  ldr  x8,  [x21,#0x20]           ; scalarInput
89c3924  ldr  x8,  [x8]                  ; scalarInput[0]
89c3928  cmp  x8,  #1
89c392c  b.ne 89c39b0
89c3930  ldr  x23, [x21,#0x58]           ; structureOutput (0x40)
89c39b4  ldr  x8,  [x21,#0x10]           ; args->asyncReference[1..]
89c39b8  ldp  q0,q1, [x8,#0x20]          ; copy 0x40 bytes of async refs to stack
89c39bc  ldp  q3,q2, [x8]
89c39c8  mov  x0, x19 ; bl 0x89bb414
89c39d4  mov  x0, x19 ; bl 0x89bb420
89c39dc  mov  x3, x0
89c39e0  add  x0, sp, #0x30
```

**Assessment.** `entry->allowAsync == 1` is the only entry in either table that accepts an async reference; without it the dispatcher rejects any selector carrying `asyncReference[0]`. The handler additionally gates on `scalarInput[0] == 1` before touching `structureOutput`. The 0x40-byte copy at `0x89c39b8` reads from `args->asyncReference` (kernel-owned array, 0x40 bytes = exactly the 8 slots) — in bounds. The tail of the function (`0x89c39e0` onward) was **not** fully traced → **не подтверждено**.

---

## 4. Gates

1. **Sandbox.** Both class names appear inside SBPL bytecode (`0xfffffff007964c44`/`0x...96512f`/`0x...965153`/`0xfffffff007af0b9b`) — a profile exists that allows opening `H11ANEInDirectPathClient` from a container. That is a *capacity*, not a grant; who consumes it is **не подтверждено**.
2. **Entitlements** (`0x89ba1e0`, `ANEClientDevice::create`):
   * `com.apple.ane.iokit-user-access` (`0xfffffff00744925d`) — required when the `newUserClient` type asks for it; result stored as bool at `ctx+0x10`.
   * `com.apple.ane.allow-dataChaining-access` (`0xfffffff00744927d`) — bool at `ctx+0x11`.
   Both are `IOTaskHasEntitlement`-style checks on the *task*, evaluated once at client creation.
3. **Per-selector entitlement slot** (`dispatch+0x20`) — **0 in all 22 ANE selectors**. No per-method entitlement.
4. **State gate** in `externalMethod` (`0x89c1478`): `ldrb [obj+0xd8]`; must be `2` or `4`, otherwise `kIOReturnNotPermitted (0xe00002e2)`. The direct-path dispatcher (`0x89c197c`) re-checks `== 2` only.
5. **Selector bound**: `count <= selector` → `kIOReturnBadArgument`; selectors 11-15 of the user-client table are 0-filled holes and unreachable because `count = 0x10` and their `function == NULL` → `kIOReturnUnsupported`.

## 5. `free` / `stop`

* No class-specific override of `free`/`stop`/`clientClose`/`clientDied`: vtable slots differ from the sibling clients in **only** 3 places — `[0]`/`[1]` (D1/D0 destructor thunks) and `[7]` (`getMetaClass`). `[87]` (`externalMethod`) resolves to the same thunk (`0x89c1974` → `b 0x89c1478`) for both direct-path classes and to `0x89c1478` directly for the two siblings.
* The ctor zeroes `[obj+0x188]` (ANEClientDevice*) and `[obj+0x190]`; the release path is therefore the inherited `IOService::free` plus `OSSafeReleaseNULL` on those two fields — **не подтверждено** (no direct `ANEClientDevice::release` call site was traced).

## 6. Verdict

**The direct path is *not* the hole it used to be.** On 27.2 (24B115) the 11-selector table is enforced by an exact-match dispatcher: selector bound, scalar-in/out counts, structure-in/out sizes compared with `==` against either `structureInputSize` or `IOMemoryDescriptor::getLength()`, plus an async-consistency flag. `0xffffffff` (“no check”) is never used on this kext. Every handler that reads past the first 0x40 of its structure stays inside the declared size (`struct+0x818` vs 0x828, `struct+0x820` vs 0x828).

What remains interesting, in order of value:

1. **`str x21,[struct+0x800]` in `memoryMapRequest`** — a raw `ANEClientDevice*` written into the caller-supplied structure. Not returned to userspace today (no `structureOutput` on sel 5). It becomes a KASLR leak the moment any path echoes the 0x828 buffer back. Watch this one across builds.
2. **`allowAsync` on sel 2** — the only async-capable entry; a 0x40-byte copy of `asyncReference` and a `scalarInput[0]==1` discriminator. This is the widest piece of user-controlled plumbing in the class.
3. **No per-selector entitlement** — the only gate is `com.apple.ane.iokit-user-access` at client creation. If a sandbox profile permits the class *and* the entitlement is inherited, all 11 selectors are reachable with zero further checks.
4. **`H1xANELoadBalancerDirectPathClient` has no dispatcher of its own** — it shares the direct-path vtable slot. That means the class name is *described* but its surface is the same 11 selectors; the LB-specific behaviour is behind the ANEClientDevice it wraps. **Не подтверждено** end-to-end.

Nothing in this pass is a demonstrated memory-safety bug. Two items (`struct+0x820` as a 32-bit field inside the map descriptor; the untraced tail of `ProgramSendRequest`) are open threads, listed as unconfirmed rather than as findings.

---
*Artifacts: `selectors.tsv` (both tables), `kc.py`/`xr.py`/`idx.py`/`res.py`/`ddis.py` (tooling).*
