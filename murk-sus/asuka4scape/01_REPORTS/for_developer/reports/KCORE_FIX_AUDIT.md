# iOS 27.2 kernel fix audit — live/sibling hunt

Scope: `kcore/272/com.apple.kernel` (27.2, __TEXT_EXEC `0xfffffff00a1cc000`) vs
`kcore/270/com.apple.kernel` (27.0, __TEXT_EXEC `0xfffffff00a190000`). 470 changed functions.
Ghidra 27.2 program: fresh import of `kcore/272/com.apple.kernel` (image base
`0xfffffff00700c000`), because the shared project copy was unreadable (buffer EOF).
Method: full-list shape diff (`reports/kcore_shape_diff_full2.txt`), strings
(`reports/ident_all.txt`), then per-function decompile 27.2 + disassembly 27.0.

## Status legend

- **closed** — fix covers the operation and all app-reachable siblings checked.
- **possible** — sibling path exists but reachability or missing check not proven.
- **live** — app-reachable sibling with the same unchecked operation.

---

## F1. `rt_setgate` AF_LINK gateway validation — candidate CVE-2026-112507 (OOB write)

- 27.2: `0xfffffff00a49c4e0`, size 2964.
- 27.0: `0xfffffff00a45f3f0`, size 2556 (+408 bytes).
- Source string: `route.c`; new message
  `"%s: rejecting AF_LINK gateway on index %u with unusable link address (nlen %u, alen %u, sdl_len %u)"`.
- Fix nature (27.2 decompile `reports/ghidra272/fn_fffffff00a49c4e0.c`):
  after the gateway sockaddr is copied into `rt_gateway`, if `sa_family == AF_LINK (0x12)`:
  - `nlen = sdl->sdl_nlen` (`gw[5]`), require `nlen <= 0x40`;
  - require `sdl->sdl_len >= 8 + nlen + alen` with 64-bit overflow checks;
  - require `alen <= 0xf7`;
  - otherwise log the message, free the new gateway and fail the set.
- 27.0 had only the debug assertion string `"sdl->sdl_alen == size"` (gone in 27.2),
  i.e. no release-mode bound tying `sdl_alen` to the copied `sdl_len`/allocation.
- Consequence in 27.0: an AF_LINK sockaddr whose `sdl_alen` exceeds the bytes actually
  present in `sdl_len` passed `rt_setgate`; consumers that copy `sdl_alen` bytes from
  `rt_gateway+8+sdl_nlen` read/write past the gateway allocation.
- Verdict: **fixed in rt_setgate**. Sibling hunt: `nd6_lookup_ipv6`
  (`0xfffffff00a6981ac`) also added a link-address fit check; `rtsock` path
  (`0xfffffff00a497e90`) added `size <= sdl->sdl_alen`. Remaining gateway consumers
  under audit (arp/nd6/if_llreach/rtsock).

---

## Changed-function inventory

- Shape diff: 20876 -> 20901 functions; 20393 identical; 392 changed regions;
  470 changed functions when insert/delete regions expanded (`kcore_shape_diff_full2.txt`).
- `reports/ident_all.txt`: all 470 with referenced source-file/format strings.
- High-value clusters: task/port/exception (`0xa1d5xxx-0xa21exxx`), VM/compressor
  (`0xa2b7xxx-0xa342xxx`), VFS (`0xa3c9xxx-0xa416xxx`), BPF (`0xa439xxx-0xa441xxx`),
  route/ARP (`0xa497xxx-0xa49cxxx`), NECP (`0xa4ddxxx-0xa50bxxx`), IGMP/MLD
  (`0xa590xxx-0xa6aaxxx`), proc/task (`0xa70fxxx-0xa71exxx`), tty/kqueue
  (`0xa780xxx-0xa784xxx`), skywalk (`0xa7f8xxx-0xa878xxx`).

---

## F2. `vm_fault_copy` busy/executable destination page — CVE-2026-112576 (COW integrity)

- 27.2: `0xfffffff00a2cf230`, size 15484 (`vm_fault.c`; strings
  `Write fault on compressor map ...`, `vm_fault_page(): unexpected error ...`).
- 27.0: `0xfffffff00a292c2c`, size 15372 (+112 bytes).
- Reference fix shape (xnu-12377.61.12 -> xnu-12377.81.4, 26.7.2 source,
  `osfmk/vm/vm_fault.c`): after `dst_object` lock is dropped, the old loop copied
  into `dst_page` without rechecking it:
  - new code checks `dst_page->vmp_busy`; if busy, unlocks dst map/object, cleans up
    `result_page`/`dst_page`, and `continue`s the fault loop (re-fault) instead of
    copying into a page another thread now owns;
  - new code checks `PMAP_PAGE_IS_USER_EXECUTABLE(dst_page)` under `CONFIG_SPTM` and
    performs the unmap/retype path before writing the COW page.
- 27.2 binary contains the same structural expansion: 106 KB decompile
  (`reports/ghidra272/fn_fffffff00a2cf230.c`) with the new `vm_object_paging_*`
  refcount checks and the executable-page handling.
- Sibling check: `vm_fault_page` (`0xfffffff00a2d5330`) also grew; `vm_map_remap_extract`
  (`0xfffffff00a2e902c`) adds a JIT-to-non-JIT downgrade for COW remaps
  (`%s: downgrading VM entry [%p, %p) from JIT to non-JIT`).
- Verdict: **fixed for the vm_fault_copy path**. Sibling `vm_map_remap_extract` has the
  JIT downgrade, but the `vmkf_remap_prot_copy` branch is exempted by the flag test
  (`uVar18 >> 0x2a & 1`); whether that path can still COW a JIT entry is **possible**,
  not proven. Reachability: `mach_vm_remap`/`mprotect`/VM faults from an app.

---

## F3. NECP DATA-TRACE kernel-pointer sanitizer — CVE-2026-112665 (KASLR leak)

- New 27.2 helpers:
  - `0xfffffff00a4ecdf8` (108): range test for a pointer against
    `0xfffffff007c6a358..360`, `...a378..380`, `...a3a0..a3a8`.
  - `0xfffffff00a396010` (192): strips PAC/tag and converts a kernel pointer to an
    offset by subtracting `0xfffffff007c6a388`, `...a570` or `...a3b0`.
  - `0xfffffff00a1d12d4` (32): `pacga(5,ptr) | 1 | pacga(0x15,ptr)>>32` hash.
- Call sites: `necp_socket_find_policy_match` (`0xfffffff00a4f017c`),
  `necp_socket_check_policy` (`0xfffffff00a4ed1c0`),
  `necp_socket_find_policy_match_with_info_locked` (`0xfffffff00a4e8d7c`),
  `necp_socket_find_policy_match` body (`0xfffffff00a4f65d8`). The leaked value is
  `so = *(socket + 0x40)`, printed as `DATA-TRACE <%s %llx>`; 27.2 replaces it with a
  slide-relative offset or PAC hash before `FUN_0xfffffff00a8df19c`.
- Sibling check:
  - `cfil_service_inject_queue` (`0xfffffff00a575090`) **is sanitized too**: 27.2 calls
    `0xa396010`/`0xa1d12d4` before every `<so %llx>` log; 27.0 `0xa536d9c` did not.
  - `igmp_flush_relq` (`0xfffffff00a590a4c`) / `mld_flush_relq` (`0xfffffff00a68abd8`)
    still print raw `%llx` multicast-record addresses, but these are heap addresses in
    an os_log path, not an app-visible pointer interface.
- Verdict: **fixed for the NECP/CFIL log paths**. No second app-visible interface that
  returns the same `so` pointer was found.
- Reachability: `necp` socket-policy matching is reachable by ordinary sockets;
  DATA-TRACE output itself is normally kernel-log/sysdiagnose, not an app API.

---

## F4. IGMP/MLD interface-detach UAF — CVE-2026-84495 / CVE-2026-112474

- 27.2: `igi_remref` `0xfffffff00a590dbc` (1124), `mli_remref`
  `0xfffffff00a68a1d0` (1124).
- 27.0: `igi_remref` `0xfffffff00a55297c` (940), `mli_remref`
  `0xfffffff00a64b4f0` (940).
- Fix nature: 27.2 adds a drain of the per-interface `inm_dthead` deferred-detach list
  before freeing `igmp_ifinfo`/`mld_ifinfo`:
  - reads `inm->inm_in_dtle` at `+0x51` and `inm->inm_dtlecnt` at `+0x74`;
  - asserts `_inm->inm_in_dtle == true` and `_dtlecnt != 0`;
  - calls `inm_remref`/`in6m_remref` (`0xa5a263c` / `0xa67cfd0` family) for each queued
    record, then frees the per-interface info.
  The strings `_inm->inm_in_dtle == true`, `_dtlecnt != 0`, `_in6m->in6m_in_dtle == true`
  are present only in 27.2.
- Sibling check: both address families changed symmetrically; `in_multi_detach`
  (`0xa5a43f4`) / `in6_multi_detach` (`0xa67e580`) queue records into
  `inm+0x12e0` / `in6m+0x12f0`; `igmp_domifdetach` (`0xa59068c`) and
  `mld_domifdetach` (`0xa68bf74`) also walk the same `inm_dthead` list and call
  `inm_remref` `dtlecnt` times before `igi_remref`/`mli_remref`. No third
  family/object found; no free path bypasses the drain in 27.2.
- Verdict: **fixed**. Reachability: `setsockopt(IP_ADD_MEMBERSHIP / IPV6_JOIN_GROUP)`
  from an app is the trigger class; no entitlement required.

---

## F5. `tty_ptmx` knote detach lifetime — CVE-2026-65350 / CVE-2026-112679 candidate

- 27.2 `ptmx_kqops_detach` `0xfffffff00a783590` (528) vs 27.0
  `0xfffffff00a743c00` (256).
- Fix nature: old detach trusted `kn->kn_hook` (`ptmx_ioctl`) and `pti->pt_tty`
  directly, then unlinked the knote from `tty+0x108/0x140`. 27.2:
  - derives the tty index from `pti->pt_tty->t_dev` (`*(uint *)(*plVar4 + 0xbc) & 0xffffff`);
  - looks the tty up in the global tty table under the tty lock, instead of writing through
    the stale `pt_tty` pointer;
  - checks the knote is actually linked in that tty's list before unlinking;
  - keeps the `invalid knote %p detach, filter: %d` validation.
- Sibling: `ptsd_kqops_detach` `0xfffffff00a782e94` (264) is **unchanged** and still uses
  `kn_hook` directly. It is not automatically a live bug: the ptsd knote holds a tty
  reference (`ttyfree` at the end, and `KNOTE_IS_AUTODETACHED` is handled by ttyclose),
  so the tty cannot be freed while the knote exists. The fixed ptmx path was needed
  because `ptmx_ioctl` outlives `pt_tty` independently.
- Verdict: **fixed for ptmx; ptsd closed under the tty-reference invariant**. No
  app-reachable double-unlink found.

---

## F6. Mach exception action port retain — CVE-2026-112517 / 65350 / 112679 candidate

- 27.2 `mach_exception_raise` dispatcher `0xfffffff00a211aa8` (2616) vs 27.0
  `0xfffffff00a1d58d8` (2384).
- Fix nature: after selecting the exception action port from the task/thread exception
  action array (`plVar24`), 27.2 calls `FUN_0xfffffff00a1f45e4` (ipc_port_copy_send) or
  `FUN_0xfffffff00a1f472c` (kernel port) and releases it on every exit. The old code used
  the raw `ipc_port_t` from the action array while the array could be replaced by
  `task_set_exception_ports`.
- Sibling check: `0xfffffff00a212e94` (824, unchanged) already calls the same retain/release
  helpers in 27.0; `task_set_exception_ports` `0xfffffff00a21e488` adds only the
  `com.apple.security.only-one-exception-port` restriction; `task_get_special_port`
  `0xfffffff00a2153dc` adds only the `which == 33` memory-error logging path.
- Verdict: **fixed**. Reachability: Mach exception ports are reachable from a sandboxed
  app via `task_set_exception_ports`/`mach_exception_raise`.

---

## F7. Skywalk packet/mbuf type confusion — CVE-2026-112606 candidate

- 27.2 `nx_netif_filter_pkt_to_mbuf` `0xfffffff00a8760d8` (444) vs 27.0
  `0xfffffff00a83640c` (224); `nx_netif_filter_pkt_to_pkt`
  `0xfffffff00a8766b8` (452) vs `0xfffffff00a836910` (224).
- Fix nature: both now reject packets whose `pkt_pflags` do not carry the required
  wrapping type:
  `filter packet is not mbuf-wrapped: pkt_pflags 0x%llx` /
  `filter packet is not packet-wrapped: pkt_pflags 0x%llx`.
- Sibling: `nx_netif_compat_na_rxsync` (`0xa86563c`) checks
  `METADATA_TYPE(pkt) == NEXUS_META_TYPE_PACKET`; `netif_filter_na_txsync`
  (`0xa870d9c`) checks ring wrap/direction. Other packet-to-mbuf converters
  (`packet_copy.c`, `pbufpool.c`) are in the same 27.2 change set but are not reached
  without a nexus/user-pipe entitlement.
- Verdict: **possible** — the direct type check is fixed on both filter directions;
  remaining converters are entitlement-gated, so no ordinary-app live path proven.

---

## F8. Route gateway OOB read/write pair — CVE-2026-112476 / CVE-2026-112507

- OOB write candidate: `rt_setgate` `0xfffffff00a49c4e0` (F1 above).
- OOB read: `rtsock_msg_buffer` `0xfffffff00a497e90` (752) vs 27.0
  `0xfffffff00a45aeac` (684). 27.2 replaces the debug-only
  `sdl->sdl_alen == size` assert with `size <= sdl->sdl_alen`, bounds
  `nlen+alen <= 0xf7`, and a `param_5+0xff` buffer limit.
- New helper `0xfffffff00a498250` (200) builds an AF_LINK sockaddr for
  `arp_lookup_ip` (`0xa59d098`) and `nd6_lookup_ipv6` (`0xa6981ac`); it checks
  `size >= 0x14`, `alen <= 0xc`, and `nlen+8+alen <= 0xff`, then returns
  `EINVAL`/`EMSGSIZE` instead of writing past the caller buffer.
- Sibling check: gateway assignment exists only in `rt_setgate` (source `rt_gateway =`
  grep). Consumers that write link addresses are `in_arpinput` (bounded by
  `ifp->if_addrlen` sender_hw) and `nd6_cache_lladdr` (bounded by `ifp->if_addrlen`);
  both stay within the AF_LINK minimum allocation (32 bytes) on iPhone interfaces.
- Verdict: **fixed**; reachability: PF_ROUTE is usable by an unprivileged app process
  (public CVE-2026-20698 PoC class), so this is a real app attack surface, not a
  root-only path.

---

## F9. BPF detach / BIOCSBLEN changes

- `bpfioctl` 27.2 `0xfffffff00a43c194` vs 27.0 `0xfffffff00a3ff100`;
  `bpf_read`/`bpfwrite`/`bpf_setdlt`/`bpfdetach` also changed.
- New strings: `bpf%d BIOCSBLEN capped to %u from %u`,
  `bpf%u cannot set BIOCSBATCHWRITE when BIOCSETTC is set`,
  `bpf%u bd_write_size_max %u too big`, `%s: %p BPF_DETACHED not set`.
- Verdict: **hardening, not app-reachable** in the ordinary sandbox (`/dev/bpf` is
  entitlement-gated on iOS). No sibling check performed beyond the changed bpf paths.

---

## F10. `if_ports_used` — not a 27.2 fix

- `if_ports_used_add_inpcb` `0xa4b9d84` / `add_flow_entry` `0xa4ba930` grew by 96
  bytes, but the `ifindex > UINT16_MAX` check and `unexpected protocol` rejection are
  already present in 27.0 (`0xa47cad4` / `0xa47d620`) and in the 26.7.2 source.
- 27.2 adds IPv6 scope/embedded-scope handling (`sin6_scope_id`, `s6_addr16[1]`), not
  an index-bounds fix. Verdict: **not CVE-2026-112507**.

---

## CVE map (best-effort, addresses)

| CVE | Class | 27.2 fixed function | 27.0 | Verdict |
|---|---|---|---|---|
| 2026-112507 | OOB write | `rt_setgate` `0xfffffff00a49c4e0` | `0xfffffff00a45f3f0` | fixed; PF_ROUTE reachable |
| 2026-112476 | OOB read | `rtsock_msg_buffer` `0xa497e90` + `nd6_lookup_ipv6` `0xa6981ac` | `0xa45aeac` / `0xa659328` | fixed |
| 2026-112576 | COW integrity | `vm_fault_copy` `0xa2cf230` | `0xa292c2c` | fixed (source-confirmed) |
| 2026-112665 | KASLR | NECP trace sanitizer `0xa4ecdf8` + `0xa396010`/`0xa1d12d4` | absent (27.0 logs raw) | fixed for NECP/CFIL logs |
| 2026-84495/112474 | UAF + write | `igi_remref` `0xa590dbc`, `mli_remref` `0xa68a1d0` | `0xa55297c`, `0xa64b4f0` | fixed v4/v6 |
| 2026-65350/112679 | UAF | `mach_exception_raise` `0xa211aa8` (port retain) | `0xa1d58d8` | fixed |
| 2026-112517 | UAF | `ptmx_kqops_detach` `0xa783590` (tty lookup) | `0xa743c00` | fixed ptmx; ptsd unchanged but ref-held |
| 2026-112606 | type confusion | `nx_netif_filter_pkt_to_mbuf` `0xa8760d8`, `..._to_pkt` `0xa8766b8` | `0xa83640c`, `0xa836910` | possible, entitlement-gated |
| 2026-112514 | UAF (attacker) | not isolated | — | open |

Reference source used for fix shapes: `xnu-12377.61.12` -> `xnu-12377.81.4`
(26.7.2), `osfmk/vm/vm_fault.c`, `bsd/net/route.c`, `bsd/kern/kern_aio.c`,
`osfmk/ipc/ipc_kmsg.c`, `bsd/net/pf_ioctl.c`. These are the same advisory family,
not 27.2 source; 27.2 binary is authoritative for addresses.

## Live-bug verdict

No single app-reachable memory-corruption sibling was proven live in this pass.
F2's `vm_map_remap_extract` `vmkf_remap_prot_copy` exemption is the strongest
COW-integrity sibling still open; F7's remaining skywalk converters are
entitlement-gated. The NECP/CFIL KASLR log paths are both sanitized in 27.2.

Next concrete steps if continuing:
1. Re-derive `vm_map_remap_extract` flag bit 0x2a from the 27.2 call sites and test
   whether `vm_map_protect(VM_PROT_COPY)` reaches the JIT-exempt branch.
2. Fuzz the `rt_setgate` AF_LINK path from a PF_ROUTE socket on 27.0 to confirm the
   later `in_arpinput` write primitive, then verify 27.2 rejects it.
3. Check `igi_remref`/`mli_remref` deferred-list drain against a third path
   (`igi_delete`/`mli_delete`) that might free without walking `inm_dthead`.
