
## 2026-10-28 · subagent S · ANE direct path
- parsed dyld chained fixups (fmt 8) for 27.2_24B115 → 438k rebase slots; `__DATA_CONST` GOT/vtable de-PAC works
- found both classes: names in `__PRELINK_TEXT` (0x7449545 / 0x74495b3), OSMetaClass ctor blobs with sizeof 0x1a0 each
- 4 sibling ctors of size 0x1a0; kalloc_type descs 0x7dd0798/0x7dd07d8/0x7dd0818/0x7dd0858; vtables 0x7dc26d0/0x7dc2d58/0x7dc33e0/0x7dc3a68
- only 2 externalMethod dispatcher call sites in whole image: table 0x7dc4130 (0x10, UserClient) and 0x7dc43b0 (0x0b, DirectPath)
- stride = 0x28 (IOExternalMethodDispatch2022); dispatcher 0xa9b0888 decoded: selector bound, exact `==` on sizes, `0xffffffff`=skip (unused in ANE), allowAsync flag @+0x18, entitlement ptr @+0x20 (all 0)
- 11 direct-path selectors named from `ANE_*` log strings
- sel5 memoryMapRequest writes raw `ANEClientDevice*` into struct+0x800 (not echoed back — no leak today)
- sel10 unmap handle is hash-map key, not array index (safe)
- gates: `com.apple.ane.iokit-user-access`, `com.apple.ane.allow-dataChaining-access`, state byte obj+0xd8 ∈ {2,4}
- open: struct+0x820 semantics, tail of ProgramSendRequest, LB-DirectPath has no own dispatcher (unconfirmed)
- artifacts: REPORT.md, selectors.tsv, kc/xr/idx/res/ddis/chain/dat/vt .py
