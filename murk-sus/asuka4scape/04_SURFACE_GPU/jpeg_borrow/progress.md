# jpeg_borrow — progress

## 2026-10-29 — subagent AA2: consumers of `session+0x4c8`

- Fixed the earlier map bug: prelinked segment `fileoff` is absolute; the old
  `o+f` double-added the header offset and disassembled another kext. Rebuilt
  `jpeg_segs.json` / `jpeg_ins.json` (per-word decode, 4 bad words).
- 27.2 JPEG `__TEXT_EXEC` = `0xfffffff008c7b8a0` foff `0x1c778a0` `0x2e008`.
  Field `+0x4c8` touched exactly 3×: `0x8c8518c` (init/wipe read),
  `0x8c8634c`, `0x8c87368` (borrow stores); plus `add` at `0x8ca8500`.
- Borrow stores: `startDecoderExt 0x8c86024` (guard `size<=0xf7f` +
  `[in+0x30]==0`, count `0x3df`) and `startDecoder2024 0x8c87038`
  (guard `size<=0xc03`, count `0x300`); pointer is `in+0x84`, `x19=[args+0x30]`.
- Consumers: init/wipe `0x8c8509c` (loop `0x8c851b4..c8`, called only after
  `kalloc_type 0x7e2c498`, field not cleared) and copy-to-e8 `0x8ca83b8`
  (`0x8ca8500`, `{ptr,count} -> session+0xe8`), reached from callback
  `0x8c858fc` via `0x8c85e50 -> 0x8ca83a4`.
- Session: alloc `0x8c860b4`/`0x8c870c8`, synchronous gate call
  `0x8c864b0..f8`/`0x8c874f0..530` (pacia 0x8c858fc, key 0xbd41, target x21),
  dealloc `0x8c8651c/60`, `0x8c87554/f4`; no publication of x21 (only self
  store `0x8c85d30`).
- Verdict: **not a working UAF** — every consumer runs inside the same
  externalMethod before the copyin dies; session is per-call and destroyed
  before return. Latent only if session caching / async runAction / re-init
  appears.
- 27.0 has the same three sites (`0x8c4ea2c`, `0x8c4fbec`, `0x8c50c08`,
  counts `0x3df`/`0x300`) — pattern is not new in 27.2.
- Global scan 1552 hits; JPEG=4; neighbours (M2Scaler 12, AVE2 20, H13Cam 10,
  ProResHW 7) are their own structs, no cross-kext consumer of the session type.
- Unconfirmed: identity of `0x8ca9278`/`0x8ca9228`, class of
  `[driver+0xb8]+0xe8` (sync inferred), allocator zeroing (inferred),
  `args+0x30` copyin-vs-descriptor.
- Report: `work/jpeg_borrow/REPORT.md`.
