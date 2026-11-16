# UAF / double-release hunt: IOMemoryDescriptor + IOMemoryMap in IOSurfaceRootUserClient

Target: iOS 27.2 (24B115), kernelcache `27.2_24B115_kernelcache`.
Conventions: short VAs like `0x9c38b2c` are low 32 bits → full VA `0xfffffff009c38b2c`.
`__TEXT_EXEC` fileoff = va - 0xfffffff007004000.

## Step 1 — bench setup
- [x] `/home/femboychik/work/uaf_desc/kd.py` — capstone wrapper on top of `parse_gpu/kc.py`
      (`load()`, `rd`, `off`, `sym_at`). `V()` normalizes short VAs to `0xfffffff0_xxxxxxxx`.
      pc-relative `adr/adrp/b/bl/cbz` resolved with sign masking (`& 0xffffffffffffffff`).
- [x] verified all 17 given points decode as real function entries (`bti c; pacibsp`) at
      VA = 0xfffffff000000000 | short.

## Step 2 — dispatch table decoded (stride 0x28, 60 selectors)
- [x] `IOSurfaceRootUserClient::getTargetAndMethodForIndex` @ `0x9c3ee10` → table `0xfffffff008068b90`
      (restricted twin `0xfffffff0080694f0`, chosen by `[self+0x127] & 1`), count 0x3c.
- [x] entry = `{u64 action; u32 sIn; u32 strIn; u32 sOut; u32 strOut; 0x10 pad}`; PAC-stripped action
      `VA = 0xfffffff007004000 + (q & 0x0FFFFFFF)`.
- [x] 60/60 selectors resolved; every "точка" from the brief matches the table (sel9/10/11/24/26/46/47/48/54).
- [x] `0xffffffff` in strIn/strOut == "size not checked" → these are exactly the descriptor-capable selectors.
- [x] `out/table_base.txt` — full table.

## Step 3 — vcall slot semantics (resolved from call sites + discriminators)
- slot `0xe8` disc `0x3ed6` → `IOMemoryDescriptor::map(options)`; input uses opts `0x1000`, output uses opts `0`.
- slot `0x78` disc `0x34f6` → `IOMemoryMap::getAddress()` (kernel VA of the mapping).
- slot `0xb0` disc `0xb392` → `IOMemoryDescriptor::getLength()` — called on the **descriptor**, never on the map.
- slot `0x28` disc `0x3a87` → `release()` (object teardown). slot `0x30` disc `0x89a9` → a different method,
      never used as teardown → no 0x28/0x30 confusion anywhere in the kext.
- [x] `out/vcall_scan.txt` — every `blraa`+slot in `0x9c30000..0x9c46000`.

## Step 4 — per-selector acquire/map/release audit (9 stubs + impls)
- [x] map/release balanced in every path; releases are LIFO (out-map before in-map) and strictly after the
      last use of the bytes pointer. Error paths (`createMapping` == NULL, short length) release the surviving map.
- [x] the *descriptor* is never released by the client (correct: owned by the MIG args) → no double-release there.
- [x] `out/vcall_scan.txt` shows exactly 11 `0xe8/0x3ed6` sites in the whole kext: sel0,9,10,11,24,26,46,47,48,54
      and the internal `0x9c3692c`. No hidden mapping site.

## Step 5 — 27.0 vs 27.2 diff of the descriptor stubs
- [x] 27.0 table `0xfffffff00805b530`, dispatcher `0x9c02e68`; constant shift of the stub cluster `0x3bfa8`.
- [x] all 9 stubs are instruction-for-instruction identical (only `cbz/cbnz` targets and one GOT slot move).
      → not a fresh 27.2 regression; identical constraints (`strIn/strOut`) in both tables.
- [x] `out/diff_stubs.txt`.

## Step 6 — report
- [x] `REPORT.md`: таблица слотов vtable, таблица «взял → замапил → отпустил» (13 селекторов),
      пошаговый канон sel9/sel10, вердикты по 4 пунктам задания, топ-3 остаточных кандидата (все «не подтверждено»),
      список проверенного-и-отброшенного.
- Итог: double-release / UAF не найден; код сбалансирован и совпадает с 27.0.

## Step 7 — chat entry
- [x] `CHAT_дипсики.md`: `## UAF дескрипторов (subagent M)` (8 строк).
- [x] `sbx_build` и IPA не трогал.
