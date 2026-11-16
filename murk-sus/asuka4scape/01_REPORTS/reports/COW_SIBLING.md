# COW sibling audit — `vmkf_remap_prot_copy` exemption (CVE-2026-112576)

Scope: iOS 27.2 `kcore/272/com.apple.kernel` (__TEXT_EXEC `0xfffffff00a1cc000`) vs
iOS 27.0 `kcore/270/com.apple.kernel` (__TEXT_EXEC `0xfffffff00a190000`).
Reference source: `xnu-12377.61.12` -> `xnu-12377.81.4` (26.7.2), from
apple-oss-distributions/xnu tags. 27.x source is not public; the 27.x binary is
authoritative for addresses/flags.

Status legend: **live** / **possible** / **needs entitlement** / **not reachable**.

---

## TL;DR verdict

**Final classification: NEEDS ENTITLEMENT — not live. The trigger syscall is
reachable by any app, but the exemption's security-relevant effect is a no-op
without `MAP_JIT`; even with a JIT entitlement the 27.2 page-level fix is not
bypassed. The exemption is not introduced or left open by the 27.2 COW fix.**

The audited address `0xfffffff00a2e902c` is **`vm_map_remap`**, not
`vm_map_remap_extract`. The `vmkf_remap_prot_copy` test there (bit 42) only
decides whether an **in-map COW remap** preserves the `used_for_jit` entry flag
and execute protection. It does not touch `vm_fault_copy`'s destination-page
checks, which run unconditionally and cover `XNU_USER_JIT`.

Reachability of the exemption:
- any app can pass `VM_PROT_COPY` (0x10) via the Mach trap `mach_vm_protect`
  (trap 14), because `vm_map_protect`/`vm_map_protect_sanitize` explicitly allow
  that bit;
- but the only skipped work requires `entry->used_for_jit` (entry bit 18), which
  is only set for `MAP_JIT` mappings, and `MAP_JIT` is gated by the code-signing
  monitor / TXM (`com.apple.security.cs.allow-jit` or dynamic-codesigning).

Confidence: branch conditions, bit values and call paths are decompiled from the
27.2/27.0 binaries and cross-checked against the 26.7.2 source; exploitability
claims are limited to what those artifacts show. No device test was performed.

---

## 1. Correction to `KCORE_FIX_AUDIT.md` F2: function identity

`KCORE_FIX_AUDIT.md` F2 says the sibling is "`vm_map_remap_extract`
(`0xfffffff00a2e902c`)". That label is wrong. `0xfffffff00a2e902c` is
**`vm_map_remap`**.

Evidence:

1. Signature. The 27.2 decompile
   (`reports/ghidra272/fn_fffffff00a2e902c.c`, 11 parameters) matches
   `vm_map_remap(target_map, *address, size, mask, vmk_flags, src_map,
   memory_address, copy, *cur_prot, *max_prot, inheritance)`;
   `vm_map_remap_extract` has 12 parameters and no `inheritance` argument.
   The decompile's last check `param_11 < 3` is the inheritance range check.
2. Outputs. The function writes `*param_2` (target address), `*param_9`
   (cur_prot) and `*param_10` (max_prot) (decompile
   `reports/ghidra272/fn_fffffff00a2e902c.c:275-277`) — exactly the
   `vm_map_remap` out-parameters.
3. Caller. `vm_map_protect` (`0xfffffff00a2e898c`) calls it directly at
   `0xfffffff00a2e8e7c`; in xnu `vm_map_protect` calls `vm_map_remap`, not
   `vm_map_remap_extract`.
4. The function first calls the copy-extraction helper (`FUN_fffffff00a2e1788`,
   decompile line 128), then `vm_map_locate_space_*`, then the copy-map entry
   loop — the `vm_map_remap` shape.

`vm_map_remap_extract` is a different function reached through
`vm_map_copy_extract` (26.7.2 source: `vm_map_copy_extract` at
`osfmk/vm/vm_map.c:14182` calls `vm_map_remap_extract` at
`osfmk/vm/vm_map.c:18742`). The `copy && vmkf_remap_prot_copy` handling that
preserves `vme_permanent`/`csm_associated` is in that extract function, not in
`0xfffffff00a2e902c`.

Consequence: the audit's "the exemption is inside vm_map_remap_extract" is a
mis-attribution; the actual JIT-downgrade exemption is in the `vm_map_remap`
wrapper, at the copy-map entry loop, and is described below.

---

## 2. Where `vmkf_remap_prot_copy` is set

`VM_PROT_COPY` is `0x10` (`osfmk/mach/vm_prot.h:121`, 26.7.2).
In 27.2 `vmkf_remap_prot_copy` is **vmk_flags bit 42**
(`0x0000040000000000`).

The only setter of the flag passed to `vm_map_remap` is `vm_map_protect`
(`0xfffffff00a2e898c`), in the `new_prot & VM_PROT_COPY` branch. Disassembly:

```
a2e89dc  tst   w4, w8            ; w8 = 0xffffffe8
a2e89e0  b.ne  a2e8f80           ; reject if any bit outside 0x17
...
a2e8a60  cmp   w4, #0x10
a2e8a64  b.hs  a2e8e14           ; prot >= 0x10 => VM_PROT_COPY branch
...
a2e8e24  and   w8, w4, #7        ; max_prot = new_prot & (R|W|X)
a2e8e28  stp   w8, wzr, [sp,#0x70]
a2e8e34  mov   x8, #0x4001
a2e8e38  movk  x8, #0x400, lsl #32        ; x8 = 0x40000004001
a2e8e3c  mov   x9, #0x4001
a2e8e40  movk  x9, #0x400, lsl #32
a2e8e44  movk  x9, #8, lsl #48            ; x9 = 0x80040000004001
a2e8e48  csel  x4, x9, x8, eq             ; TPRO override -> bit 51
...
a2e8e7c  bl    #0xfffffff00a2e902c       ; vm_map_remap
```

Flag bits: `0x1` = `vmf_fixed`, `0x4000` = `vmf_overwrite` (bit 14),
`0x40000000000` = `vmkf_remap_prot_copy` (bit 42), `0x8000000000000` =
`vmkf_tpro_enforcement_override` (bit 51). The call is
`vm_map_remap(map, &new_start, size, 0, kflags, map, start, TRUE, &cur, &max,
VM_INHERIT_DEFAULT)` — source map == destination map, `copy = TRUE`,
`vmf_overwrite = TRUE`.

The 27.0 counterpart (`0xfffffff00a2ac7fc`, decompile lines 109-111; setter
`vm_map_protect` `0xfffffff00a2ac15c`, decompile lines 109-111) passes the same
`0x8040000004001` / `0x40000004001` constants and has the same
`(param_5 & 0xffffffe8) != 0` / `0x10` routing. So the flag, the setter and the
routing are identical in 27.0 and 27.2.

### 2.1. Other callers do not set bit 42

`vm_map_remap` has five other callers in 27.2:

| caller | flags passed | bit 42? |
|---|---|---|
| `0xfffffff00a2e898c` (`vm_map_protect`) | `0x8040000004001` / `0x40000004001` | **yes** |
| `0xfffffff00a3b057c` | `0x80001100001` | no |
| `0xfffffff00a3b3048` | `0x1c100008`, `0x1c104001` | no |
| `0xfffffff00a3b6eb4` | `0x1c100008` | no |
| `0xfffffff00a3b89e8` | `0x1c100008` | no |
| `0xfffffff00a3445a4` | `(param_11 & 0x4169) ^ 0x100001` | no (mask 0x4169 cannot produce bit 42) |

`mach_vm_remap`/`mach_vm_remap_external` (26.7.2 `osfmk/vm/vm_user.c:928`,
`:1015`) build `vmk_flags` only from `VM_FLAGS_USER_REMAP`; `mmap`/`MAP_FIXED`
and `mmap(MAP_JIT)` go through `vm_map_enter` and set `vmkf_map_jit`, not
`vmkf_remap_prot_copy`. `mremap` is not a Darwin syscall. So the exemption is
reachable **only** through `vm_map_protect` with `VM_PROT_COPY`.

---

## 3. Exact branch conditions in 27.2 `vm_map_remap` (`0xfffffff00a2e902c`)

The copy-map entry loop runs at `0xfffffff00a2e939c..0xfffffff00a2e9514`.
Relevant 27.2 instructions:

```
a2e93c8  tbz   x22, #0x2a, a2e9438        ; bit42 clear -> skip prot_copy block
a2e93cc  ldr   w8, [x24, #0x38]           ; entry->vme_flags
a2e93d0  tbnz  w8, #0x10, a2e93e0         ; vme_permanent?
a2e93d4  orr   w8, w8, #0x200             ; else max_protection |= VM_PROT_WRITE
a2e93d8  str   w8, [x24, #0x38]
a2e93dc  b     a2e9438
a2e93e0  tbz   w8, #0xa, a2e93f8          ; permanent: max_prot & VM_PROT_EXECUTE?
a2e93e4  adrp  x9, ...                    ; developer_mode_state() pointer
a2e93e8  ldr   x9, [x9, #0xeb8]
a2e93ec  cbz   x9, a2e93f8
a2e93f0  ldrb  w9, [x9]
a2e93f4  tbnz  w9, #0, a2e93d4            ; developer mode -> allow write
a2e93f8  ...                              ; deny/log path (proc name/pid)
a2e9438  tbz   w22, #5, a2e9460           ; vmf_resilient_codesign
a2e943c  stp   w25, w25, [x29, #-0x78]
a2e9440  ldr   w8, [x24, #0x38]
a2e9444  mov   w9, #0xf08f
a2e9448  movk  w9, #0xffdf, lsl #16
a2e944c  and   w8, w8, w9                 ; & 0xffdff08f
a2e9450  mov   w9, #0x110
a2e9454  movk  w9, #0x20, lsl #16
a2e9458  orr   w8, w8, w9                 ; | 0x200110
a2e945c  str   w8, [x24, #0x38]
a2e9460  tbz   w22, #6, a2e9494           ; vmf_resilient_media
...
a2e9494  ldr   w8, [x24, #0x38]           ; entry->vme_flags
a2e9498  tbnz  x22, #0x2a, a2e9504        ; <-- EXEMPTION: bit42 set -> skip downgrade
a2e949c  tbz   w8, #0x12, a2e9504         ; used_for_jit clear -> skip
a2e94a0  ldp   x8, x9, [x24, #0x10]
a2e94a4  stp   x8, x9, [sp, #8]
a2e94a8  str   x28, [sp]
a2e94ac  mov   x0, x27
a2e94b0  adrp  x1, ... ; "downgrading VM entry [%p, %p) from JIT to non-JIT"
a2e94c4  bl    #0xfffffff00a8df19c        ; os_log
a2e94c8  ldr   w9, [x24, #0x38]
a2e94cc  mov   w8, #0xfbbf
a2e94d0  movk  w8, #0xfffb, lsl #16
a2e94d4  and   w8, w9, w8                 ; & 0xfffbfbbf
a2e94d8  str   w8, [x24, #0x38]
a2e94dc  tbz   x22, #0x2b, a2e9500        ; vmkf_remap_legacy_mode
a2e94e0  ...                              ; recompute cur/max prot from entry
a2e9504  tbz   w22, #8, a2e93bc
a2e9508  tbz   w8, #7, a2e93bc
a2e950c  and   w8, w8, w19                ; & 0xfffeff7f (bits 7 and 16)
a2e9510  str   w8, [x24, #0x38]
```

### 3.1. Decoded masks

`0xfffbfbbf` clears bits **6, 10, 18**:

| bit | 27.x entry-word meaning | evidence |
|---|---|---|
| 6 (`0x40`) | `protection` EXECUTE | the resilient-codesign block sets protection=READ via bit 4 (`0x10`) and max_prot=READ via bit 8 (`0x100`); the downgrade clears `0x40`/`0x400` |
| 10 (`0x400`) | `max_protection` EXECUTE | same; the prot_copy permanent check `tbz w8,#0xa` tests `max_protection & VM_PROT_EXECUTE` |
| 18 (`0x40000`) | `used_for_jit` | tested by the block that logs "JIT to non-JIT"; `vm_map.c:18713` sets `used_for_jit` only for `vmkf_map_jit` |

So the entry word in 27.x is:
- bits 4-6 = `protection` (R/W/X),
- bits 8-11 = `max_protection` (R/W/X/UEXEC),
- bit 16 (`0x10000`) = `vme_permanent` (prot_copy allow-write check),
- bit 18 (`0x40000`) = `used_for_jit`,
- bit 21 (`0x200000`) = `vme_resilient_codesign` (set by the resilient block),
- bit 22 (`0x400000`) = `vme_resilient_media` (set by the `vmf_resilient_media`
  block at `0xa2e9460..0xa2e9490`).

The 27.2 decompile (`reports/ghidra272/fn_fffffff00a2e902c.c:200-242`) shows
the same logic at a higher level:

```c
if ((uVar18 >> 0x2a & 1) != 0) {            /* vmkf_remap_prot_copy */
    uVar7 = *(uint *)(lVar4 + 0x38);
    if (((uVar7 >> 0x10 & 1) == 0) ||        /* !vme_permanent */
        ((((uVar7 >> 10 & 1) != 0 && (DAT_fffffff007c14eb8 != 0)) &&
          ((*DAT_fffffff007c14eb8 & 1) != 0)))) {
        *(uint *)(lVar4 + 0x38) = uVar7 | 0x200;   /* max_prot |= WRITE */
    } else { ... deny ... }
}
if ((uVar14 >> 5 & 1) != 0) { ... }          /* vmf_resilient_codesign */
...
if (((uVar18 >> 0x2a & 1) == 0) && ((uVar7 >> 0x12 & 1) != 0)) {
    os_log(..., "downgrading VM entry [%p, %p) from JIT to non-JIT");
    uVar2 = *(uint *)(lVar4 + 0x38);
    uVar7 = uVar2 & 0xfffbfbbf;              /* clear EXEC, maxEXEC, used_for_jit */
    *(uint *)(lVar4 + 0x38) = uVar7;
    ...
}
```

**Branch summary**

| condition | effect |
|---|---|
| `vmkf_remap_prot_copy == 0` | JIT entries are downgraded: bits 6/10/18 cleared. (For non-JIT entries this block is a no-op: bit 18 is already clear.) |
| `vmkf_remap_prot_copy == 1`, `vme_permanent == 0` | `max_protection |= VM_PROT_WRITE`; JIT downgrade skipped. |
| `vmkf_remap_prot_copy == 1`, `vme_permanent == 1`, `max_protection & EXEC` and developer mode | `max_protection |= VM_PROT_WRITE`; JIT downgrade skipped. |
| `vmkf_remap_prot_copy == 1`, `vme_permanent == 1`, no developer mode or no max EXEC | write not added (deny/log); JIT downgrade still skipped. |

The exemption is therefore exactly: **for a VM_PROT_COPY in-place remap, do not
downgrade a JIT entry to non-JIT and do not strip its execute bits.**

---

## 4. App reachability of the trigger

### 4.1. Mach trap `mach_vm_protect` (no entitlement in the handler)

`/home/femboychik/work/mach_27.2.txt:16`:

```
14  0xfffffff00a1ff970: mach_vm_protect
    munge=0xfffffff00a3bac10 nargs=5
    mach_vm_protect(mach_port_name_t task, mach_vm_address_t address,
                    mach_vm_size_t size, boolean_t set_maximum,
                    vm_prot_t new_protection);
```

The handler `0xfffffff00a1ff970` (27.2, decompiled) does:

```c
lVar1 = FUN_fffffff00a21dd40(*param_1, 0);        /* port name -> task */
...
pppppuVar3 = *(undefined ******)(lVar1 + 0x28);    /* task->map */
...
uVar2 = vm_map_protect(pppppuVar3,                    /* map */
                       *(ulong *)(param_1 + 2),       /* address */
                       *(long *)(param_1 + 4) + *(ulong *)(param_1 + 2), /* end */
                       param_1[6],                    /* set_maximum */
                       param_1[8]);                   /* new_protection */
```

No entitlement check, no prot filtering beyond `vm_map_protect`'s own sanitizer.
An app holds a send right to its own task port, so `mach_vm_protect(mach_task_self(),
addr, size, FALSE, VM_PROT_COPY | prot)` reaches the copy branch.

The only remaining gate is the sandbox profile for Mach trap 14. Self-VM
operations are part of the normal app surface, and the handler performs no
`cs_*`/entitlement check; a device test was not performed to enumerate sandbox
profiles, so this is stated as "no in-kernel gate found".

### 4.2. Why BSD `mprotect` cannot be used

`mprotect(2)` ends in `mach_vm_protect(user_map, addr, size, false, prot)`
(26.7.2 `bsd/kern/kern_mman.c:1291`). But the BSD wrapper first runs
`vm_sanitize_prot_bsd`, which masks the user prot with
`VM_PROT_ALL | VM_PROT_TRUSTED | VM_PROT_STRIP_READ`
(26.7.2 `osfmk/vm/vm_sanitize.c:805-816`). `VM_PROT_COPY` (0x10) is not in
that mask, so BSD `mprotect` cannot request a prot-copy remap.

`vm_map_protect_sanitize` (26.7.2 `osfmk/vm/vm_map.c:6059`) passes
`extra_mask = VM_PROT_COPY`, so `vm_map_protect` explicitly permits 0x10. The
27.2 binary shows the same allowance at `0xa2e89dc` (`tst w4, #0xffffffe8`:
allowed bits 0x1, 0x2, 0x4, 0x10). The `prot >= 0x10` test at `0xa2e8a60`
therefore means "VM_PROT_COPY set", because no other allowed bit is >= 0x10.

The other in-tree user of this API is DTrace
(`bsd/dev/dtrace/dtrace_glue.c:187`, `dtrace_ptss.c:202`), which is an
entitlement/root facility.

### 4.3. Why the JIT half needs an entitlement

The skipped block is only non-trivial if `entry->used_for_jit` (bit 18) is set.
In 26.7.2 source:

- `vm_map_enter` sets `new_entry->used_for_jit = TRUE` only under
  `if (vmk_flags.vmkf_map_jit)` (`osfmk/vm/vm_map.c:18713`).
- `vmkf_map_jit` is set by `mmap(MAP_JIT)` (`bsd/kern/kern_mman.c:725`).
- `mmap(MAP_JIT)` is gated by
  `vm_map_csm_allow_jit(user_map)` (`bsd/kern/kern_mman.c:463`), which calls
  `csm_allow_jit_region(pmap)` (`osfmk/vm/vm_map.c:23393`) and ultimately the
  TXM monitor (`bsd/kern/code_signing/txm.c:1341`, selector
  `kTXMKernelSelectorAllowJITRegion`). On iOS this is the
  `com.apple.security.cs.allow-jit` / dynamic-codesigning grant.
- There is no user-visible `mach_vm_map` flag that maps to `vmkf_map_jit`;
  `VM_FLAGS_USER_ALLOCATE`/`VM_FLAGS_USER_MAP` (`osfmk/mach/vm_statistics.h:335`)
  do not include a JIT bit.

Therefore:

| process | mach_vm_protect(VM_PROT_COPY) | exemption effect |
|---|---|---|
| ordinary app without JIT entitlement | reachable | none: `used_for_jit == 0`, the skipped block would be a no-op |
| app with `com.apple.security.cs.allow-jit` / dynamic-codesigning | reachable | keeps `used_for_jit` + execute bits on the in-place COW entry |

The exemption is **not** a way for a JIT-less app to acquire `used_for_jit`;
nothing in `vm_map_remap` sets that bit, it only preserves it.

### 4.4. Same-map only

`vm_map_protect` calls `vm_map_remap` with `src_map == dst_map`
(`0xa2e8e70: mov x5, x0`) and `vmf_fixed|vmf_overwrite` set. The COW remap
therefore replaces the caller's own mapping in place; it does not create a
second address-space alias of the JIT page. This is the structural reason the
exemption is safe to grant for `VM_PROT_COPY` while a cross-map `vm_remap` of a
JIT entry is downgraded.

---

## 5. Does the exemption bypass the CVE-2026-112576 fix?

### 5.1. What the fix actually changes

26.7.2 source diff `xnu-12377.61.12` -> `xnu-12377.81.4`,
`osfmk/vm/vm_fault.c` circa line 7859. The old `vm_fault_copy` loop dropped
`dst_object`'s lock and then copied into the previously-found `dst_page`
unconditionally:

```c
vm_object_unlock(dst_object);
/* copy into dst_page */
```

The fixed code (81.4) adds:

```c
if (__improbable(dst_page->vmp_busy)) {
        vm_object_unlock(dst_object);
        vm_map_unlock_read(dst_map);
        ...
        vm_fault_copy_dst_cleanup(dst_page);
        continue;                     /* re-fault the destination */
}

#if CONFIG_SPTM
if (__improbable(PMAP_PAGE_IS_USER_EXECUTABLE(dst_page))) {
        ... /* wait for cleaning/iopl_wired if needed */
        pmap_disconnect_options(VM_PAGE_GET_PHYS_PAGE(dst_page),
            PMAP_OPTIONS_RETYPE, NULL);
}
#endif
/* now copy */
```

`PMAP_PAGE_IS_USER_EXECUTABLE` is (`osfmk/vm/pmap.h:241-246`):

```c
#define PMAP_PAGE_IS_USER_EXECUTABLE(m) ({ \
    const sptm_paddr_t __paddr = ptoa(VM_PAGE_GET_PHYS_PAGE(m)); \
    const sptm_frame_type_t __frame_type = sptm_get_frame_type(__paddr); \
    sptm_type_is_user_executable(__frame_type); })
```

and `sptm_type_is_user_executable` returns true for
`XNU_USER_EXEC`, `XNU_USER_DEBUG` **and `XNU_USER_JIT`**
(`osfmk/arm64/sptm/sptm.h:152-154`).

So the fix is a property of the destination **page/frame**, not of the mapping
flags. A `used_for_jit` entry is explicitly covered.

27.2 binary check: `vm_fault_copy` is at `0xfffffff00a2cf230`, size 15484,
versus 27.0 `0xfffffff00a292c2c`, size 15372 (+112 bytes;
`reports/batch_diff_full.txt:4367`). The decompile
(`reports/ghidra272/fn_fffffff00a2cf230.c`) is present; an instruction-level
diff is noisy because the stack layout changed throughout, so the fix shape
above is taken from the 26.7.2 source diff and the binary size/shape, not from a
clean per-instruction match.

### 5.2. Where `vm_fault_copy` is called from

In 26.7.2 `vm_fault_copy` has exactly two callers, both in
`osfmk/vm/vm_map.c`:

- `vm_map_copy_overwrite_unaligned` (`vm_map.c:11450`)
- `vm_map_copy_overwrite_aligned` (`vm_map.c:11964`)

These are the `vm_map_copy_overwrite`/`vm_map_copyout` machinery used by:

- `mach_vm_write` (`osfmk/vm/vm_user.c:730`) — needs a send right to the target
  task; self is always available;
- `mach_vm_copy` (`osfmk/vm/vm_user.c:787`);
- out-of-line Mach message delivery (`osfmk/ipc/ipc_kmsg.c:3844`), reachable by
  any app that receives an OOL descriptor.

The page fault path (`vm_fault_page`) does not call `vm_fault_copy`; it resolves
COW through the object's copy object (`first_object->vo_copy`) directly.
Therefore the CVE path is the **copy-overwrite / OOL / mach_vm_write** path,
not a normal write fault.

### 5.3. The aligned copy-overwrite fast path excludes JIT/executable
destinations

Before calling `vm_fault_copy`, `vm_map_copy_overwrite_aligned` has a fast path
that replaces the destination object instead of copying pages. Its guard
(26.7.2 `vm_map.c:11696-11704`) is:

```c
if ((!entry->is_shared &&
    !entry->vme_permanent &&
    !entry->used_for_jit &&
#if __arm64e__
    !entry->used_for_tpro &&
#endif
    !(entry->protection & VM_PROT_EXECUTE) &&
    !pmap_has_prot_policy(dst_map->pmap, entry->translated_allow_execute,
        entry->protection) &&
    ((object == VM_OBJECT_NULL) ||
     (object->internal && !object->true_share &&
      object->copy_strategy != MEMORY_OBJECT_COPY_NONE))) ||
    entry->needs_copy) {
        /* virtual replacement of the destination object, no page copy */
        ...
} else {
slow_copy:
        ...
        vm_fault_copy(...);       /* physical copy, now with the busy/exec fix */
}
```

Consequences:

- A `used_for_jit` entry **without** `needs_copy` cannot take the fast path; it
  goes to `vm_fault_copy`, i.e., the fixed code. This is the actual CVE path and
  it does not require the `vmkf_remap_prot_copy` exemption at all (a plain
  `MAP_JIT` mapping is enough).
- A `used_for_jit` entry **with** `needs_copy` (the state created by the
  prot-copy exemption) takes the fast path: it replaces the object rather than
  writing into a page, so there is no executable-page copy to protect.
- An executable non-JIT entry likewise cannot take the fast path; it goes to
  `vm_fault_copy` and is covered by `PMAP_PAGE_IS_USER_EXECUTABLE`.

Thus the exemption does not route a page copy around the fix. It changes entry
flags in the map, and the page-level copy path is chosen later by the
copy-overwrite code, which already excludes JIT/executable pages from the
"replace object" fast path unless `needs_copy` is set.

### 5.4. What the exemption leaves behind

After `mach_vm_protect(self, addr, len, FALSE, VM_PROT_COPY|R|W|X)` on a JIT
entry:

- the entry is replaced by an in-place COW entry (`needs_copy=1`);
- `used_for_jit` (bit 18) is preserved;
- `vm_map_protect`'s W^X check has an explicit `!(current->used_for_jit)`
  exemption (26.7.2 `vm_map.c:6311`), so the entry can be RWX at the VM layer;
- the pmap update strips `VM_PROT_WRITE` before `pmap_protect_options`
  (`vm_map.c:6490-6560`), so the physical mapping remains R-X until a fault or
  copy.

A subsequent write (fault or `mach_vm_write`) on the needs-copy entry either
takes the object-replacement fast path (no page copy) or a fault path that
retypes/unmaps the page. A subsequent write on a non-needs-copy JIT entry goes
to `vm_fault_copy`, which has the fix. No route writes into an executable page
without the busy/retype checks.

Related hardening (context, not a bypass): the wiring path uses
`extra_prots = VM_PROT_COPY | VM_PROT_COPY_FAIL_IF_EXECUTABLE`
(26.7.2 `vm_map.c:6889`) and `vm_map_lookup_and_lock_object` fails instead of
copying an executable mapping when that marker is set
(`vm_map.c:15217`). `vm_map_protect`'s prot-copy path does **not** set
`VM_PROT_COPY_FAIL_IF_EXECUTABLE`; mprotect/debug/JIT COW of executable memory
is therefore allowed to proceed, which is exactly why the page-level
`vm_fault_copy` fix is the enforcement point.

### 5.5. Verdict for the fix-bypass question

**No bypass found.** The exemption is upstream of the copy; the fix is at the
destination page and is unconditional with respect to `vmkf_remap_prot_copy` /
`used_for_jit`.

---

## 6. 27.0 vs 27.2: the exemption is not part of the 27.2 fix

| item | 27.0 | 27.2 |
|---|---|---|
| `vm_map_remap` | `0xfffffff00a2ac7fc`, 1580 bytes | `0xfffffff00a2e902c`, 1796 bytes |
| prot_copy test | `0xa2acb84 tbz x22,#0x2a,...` (entry block) | `0xa2e93c8 tbz x22,#0x2a,...` |
| JIT downgrade exemption | `0xa2acc68 tbnz x22,#0x2a,0xa2acb78` | `0xa2e9498 tbnz x22,#0x2a,0xa2e9504` |
| downgrade mask | `0xfffbfbbf` (bits 6/10/18) | `0xfffbfbbf` (bits 6/10/18) |
| protect-write mask | `0x200` (`max_protection |= WRITE`) | `0x200` |
| resilient-codesign mask | `0x200110` | `0x200110` |
| resilient-media mask | `0x400000` | `0x400000` |
| `vm_map_protect` kflags | `0x8040000004001`/`0x40000004001` | `0x8040000004001`/`0x40000004001` |

The decompiled 27.0 block (`reports/ghidra270/fn_fffffff00a2ac7fc.c:177-217`)
is the same code as the 27.2 block
(`reports/ghidra272/fn_fffffff00a2e902c.c:200-242`).

The log string is present in **both** binaries:

```
kcore/270/com.apple.kernel  file offset 741450 (0xb50ca)
kcore/272/com.apple.kernel  file offset 743300 (0xb5784)
```

Therefore `KCORE_FIX_AUDIT.md` F2's statement that 27.2 "adds a JIT-to-non-JIT
downgrade for COW remaps" is incorrect. The downgrade and its
`vmkf_remap_prot_copy` exemption exist in 27.0, which is still vulnerable to
CVE-2026-112576 (Apple lists the fix in 26.7.2 and 27.2, not 27.0). The 27.2
change that matters is the `vm_fault_copy` page-level fix.

The 27.2 `vm_map_remap` growth (+216 bytes, 33 hunks;
`reports/batch_diff_full.txt:5350`, `reports/semdiff.txt:5342`) is in the
initial flag-validation/`vmf_resilient_media` refactoring, not in the
prot_copy/JIT block.

---

## 7. Final verdict and residual risk

### Verdict

**NOT LIVE — needs JIT entitlement; no bypass of the CVE-2026-112576 fix.**

Breakdown:

1. **The audited address is `vm_map_remap`, not `vm_map_remap_extract`.**
   The exemption is a mapping-layer flag-preservation decision, not a
   page-copy check.
2. **Trigger is app-reachable but inert for JIT-less apps.** Any app can call
   `mach_vm_protect(self, addr, len, FALSE, VM_PROT_COPY|prot)` (Mach trap 14),
   because `vm_map_protect` explicitly allows `VM_PROT_COPY` (0x10). But the
   only work skipped by the exemption is the JIT downgrade, which requires
   `entry->used_for_jit`; that bit is only set by `MAP_JIT`, which is gated by
   the code-signing monitor / TXM
   (`com.apple.security.cs.allow-jit` or dynamic-codesigning).
3. **The exemption is in-map only.** `vm_map_protect` calls `vm_map_remap` with
   `src_map == dst_map` and `vmf_overwrite`, so it replaces the mapping in place
   with a COW copy. No cross-map alias of the JIT page is created.
4. **The CVE fix is page-level and unconditional.** `vm_fault_copy`'s
   `dst_page->vmp_busy` and `PMAP_PAGE_IS_USER_EXECUTABLE` checks apply to every
   call, and `PMAP_PAGE_IS_USER_EXECUTABLE` covers `XNU_USER_JIT`. The
   copy-overwrite aligned fast path already excludes `used_for_jit` /
   executable destinations unless `needs_copy` is set, and `needs_copy` takes
   the object-replacement path, not a page copy.
5. **27.0 already has the exemption.** It is not a regression introduced by the
   27.2 fix. The audit's "27.2 adds" claim is contradicted by the 27.0
   decompile and the string present in both binaries.

### Residual / not proven

- A JIT-entitled process can leave an entry RWX at the VM layer via
  `mach_vm_protect(VM_PROT_COPY|R|W|X)`, with the pmap still R-X until a fault
  or copy. On a platform/configuration where TXM allows RWX `USER_JIT` frames,
  this could weaken in-process W^X. On iOS 27.2 the SPTM frame-type policy and
  the `vm_fault_copy` retype path treat `XNU_USER_JIT` as executable and
  write-protected, so no page write bypass was found. Not tested on a device.
- The second JIT-downgrade site in `FUN_fffffff00a2e81a0` (called from
  `vm_map_remap`) was only partially mapped. It is gated by
  `flags >= 0x1000`; the prot-copy call constructs flags `0x830`, so that site
  is also skipped. It is a nuance of the same JIT-preservation policy, not a
  page-copy bypass.
- Sandbox profiles were not enumerated on device; the claim is "no in-kernel
  entitlement check in the `mach_vm_protect` handler", with sandbox policy left
  as the only possible gate.

### Exact app-reachable trigger (for the record)

For a JIT-entitled process (`com.apple.security.cs.allow-jit` /
dynamic-codesigning), with a `MAP_JIT` mapping at `addr`, length `len`:

```c
mach_vm_protect(mach_task_self(), addr, len, FALSE,
                VM_PROT_COPY | VM_PROT_READ | VM_PROT_WRITE | VM_PROT_EXECUTE);
```

- `VM_PROT_COPY` = 0x10; the handler passes 0x17 through
  `vm_map_protect`'s `tst w4,#0xffffffe8` check.
- This enters `vm_map_remap` with `kflags = 0x80040000004001`
  (bit 42 set), `src_map == dst_map`, `copy = TRUE`, `overwrite = TRUE`.
- The copy-map loop skips the JIT downgrade (`0xa2e9498`) and, if
  `vme_permanent == 0`, adds `VM_PROT_WRITE` to `max_protection`
  (`0xa2e93d4`).
- Result: in-place COW entry, `used_for_jit` preserved, VM-level protection can
  be RWX; pmap remains R-X; any page copy still goes through the fixed
  `vm_fault_copy` (or the `needs_copy` object-replacement fast path).

For a JIT-less app the same call is permitted but `used_for_jit == 0`, so the
skipped downgrade block would have been a no-op; the only observable effect is
the generic prot-copy `max_protection |= VM_PROT_WRITE` behavior for
non-permanent mappings, which is the documented `VM_PROT_COPY` contract.

### 7.1. What would change this verdict

- A user-reachable way to set `used_for_jit` without `MAP_JIT` (e.g., a new
  user-visible VM flag, or inheriting a JIT mapping from a JIT-entitled parent
  into a less-privileged process). None was found in 27.2: `vmkf_map_jit` is
  only set by `mmap(MAP_JIT)`, and the downgrade clears the bit on a plain
  cross-map remap.
- A page-copy path into an executable destination that does not go through
  `vm_fault_copy` and does not have its own busy/executable handling. The
  fault-path COW copy in `vm_fault_page` is a separate implementation (the 27.2
  fix is only in `vm_fault_copy`); it has its own `vmp_busy` wait for the copy
  object page and allocates a fresh page when the copy page is absent, so no
  executable-destination copy was found there either. Not exhaustively audited.
- A platform/configuration where TXM permits RWX `USER_JIT` frames. Then the
  VM-level RWX state the exemption can produce would be a stronger in-process
  W^X weakening. On iOS 27.2 the SPTM frame-type policy and the
  `PMAP_PAGE_IS_USER_EXECUTABLE` retype path treat JIT frames as executable and
  write-protected, so a page write still goes through the fixed code. Not
  tested on device.

---

## Evidence index

| item | path |
|---|---|
| 27.2 `vm_map_remap` decompile | `reports/ghidra272/fn_fffffff00a2e902c.c` |
| 27.0 `vm_map_remap` decompile | `reports/ghidra270/fn_fffffff00a2ac7fc.c` |
| 27.2 `vm_map_protect` decompile | `reports/ghidra272/fn_fffffff00a2e898c.c` |
| 27.0 `vm_map_protect` decompile | `reports/ghidra270/fn_fffffff00a2ac15c.c` |
| 27.2 `mach_vm_protect` handler | `reports/ghidra272/fn_fffffff00a1ff970.c` |
| 27.2 `vm_map_remap` decompile (vm_map_enter helper) | `reports/ghidra272/fn_fffffff00a2e81a0.c` |
| 27.2/27.0 `vm_fault_copy` decompiles | `reports/ghidra272/fn_fffffff00a2cf230.c`, `reports/ghidra270/fn_fffffff00a292c2c.c` |
| Mach trap table | `/home/femboychik/work/mach_27.2.txt:16` |
| 26.7.2 fix source | `xnu-12377.81.4/osfmk/vm/vm_fault.c` (diff vs `xnu-12377.61.12`), saved as `reports/xnu_61_81_vm_fault.diff` |
| `vmkf_remap_prot_copy` setter | `xnu-12377.81.4/osfmk/vm/vm_map.c:6188` |
| `MAP_JIT` gate | `xnu-12377.81.4/bsd/kern/kern_mman.c:463,725` |
| `used_for_jit` setter | `xnu-12377.81.4/osfmk/vm/vm_map.c:18713` |
| `PMAP_PAGE_IS_USER_EXECUTABLE` | `xnu-12377.81.4/osfmk/vm/pmap.h:241`, `osfmk/arm64/sptm/sptm.h:152` |
| `vm_fault_copy` callers | `xnu-12377.81.4/osfmk/vm/vm_map.c:11450,11964` |
| copy-overwrite fast path | `xnu-12377.81.4/osfmk/vm/vm_map.c:11696` |

