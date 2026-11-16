# progress — var-output scan, 27.2 (24B115) — attempt 3 (subagent C3)

KC: /home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache (67 239 936 bytes)
Workdir: /home/femboychik/work/parse_varout3   (reused artifacts from ../parse_varout2)

## log
- [0] reused kc.py + funcstarts.bin (110 778 starts) + kext_segmap.json from varout2.
      Fresh scan of __TEXT_EXEC: 3333 loads of [x?,#0x78] in 1523 functions.
- [1] calibration: found IOSurface dispatch table 0xfffffff008068b90 (stride 0x28, 120 entries),
      sel 30 -> 0xfffffff009c3968c, sel 49 -> 0xfffffff009c39e0c. Both load [args+0x78]
      and `str <obj>,[xN]`. sel 30 has `ldrb w8,[x0,#0x122]; tbz` before the write, sel 49 none.
      => pipeline calibrated against Kai's ground truth.
- [2] table discovery (tools.find_tables): 189 tables (151 x stride 0x18, 38 x stride 0x28),
      2090 entries, 67 named kexts + 39 tables in unattributed __DATA_CONST.
- [3] IMPORTANT correction: stride 0x28 == IOExternalMethodDispatch2022
      (+0x18 allowAsync/u8, +0x20 const char *checkEntitlement).
      First parser demanded q(a+0x20)==0 and therefore silently dropped gated tables.
      Fixed in tools.parse_entry. Result: 433 entries in 0x28 tables, 0 of them carry
      checkEntitlement => no per-selector entitlement gates anywhere in this cache.
- [4] abstract interpreter (flow.analyze): tracks IOExternalMethodArguments* (x2 + copies +
      stack spills), ldr [args,#0x78] -> varout ptr, str through it; follows bl/b with tagged
      args, depth<=2. All table entries walked.
- [5] independent global sweep over all 1523 functions that read [x?,#0x78]:
      exactly 14 functions store through the value.
- [6] IOSurface gate confirmed: 0xfffffff009c3a2d4 checks "com.apple.private.iosurfaceinfo"
      via 0xfffffff009c3a60c and does `strb w0,[x19,#0x122]`; sel 30 reads that flag and
      returns kIOReturnNotPrivileged (0xe00002c1) when clear.
- [7] semantics confirmed against XNU source (iokit/Kernel/IOUserClient.cpp:5049-5125):
      args.structureVariableOutputData = &local OSObject*; after the method,
      OSDynamicCast(OSSerialize) -> copyout text, OSDynamicCast(OSData) -> copyout bytes,
      else kIOReturnUnderrun; then release.
- [8] final set: 14 writer functions, 12 (table,selector) pairs. REPORT.md written.
      tables_full.txt = all 189 tables. dump/*.txt = disassembly of each writer.
