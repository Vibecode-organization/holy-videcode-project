## step 1 — setup / segment check
- file 0x4020000, __TEXT_EXEC offset 0x1148000 confirmed, extra segs __DATA_SPTM/__LINKEDIT
- built kc.py (va<->off, cstr, strings) + scan.py (fast adrp/add/GOT index, 724k sites, 8s)
- NOTE: literal strings `IOAccelDevice|IOAccelDevice2|IOAccelContext*|IOAccelSharedUserClient*|IOAccelSubmitter2` DO NOT EXIST in cache (0 hits). `IOGPU*` + `AGX*` do. Checking class registry before concluding.
## step 2 — class registry (KEY FINDING)
- capstone streaming indexer too slow; built `refs.py` (adrp page index + targeted disasm) instead. **capstone `adrp` imm comes back truncated positive (0x782a000) — mask required**, as warned.
- found OSMetaClass ctor call target `0xfffffff0099844dc`; 153 call sites = full IOGPUFamily class registry with instance sizes.
- **IOAccelDevice / IOAccelDevice2 / IOAccelContext / IOAccelContext2 / IOAccelSharedUserClient / IOAccelSharedUserClient2 / IOAccelSubmitter2 DO NOT EXIST in 27.2 (24B115).** No name strings anywhere in the image, not in the 153-metaclass registry. Only `IOAccelGPURestartReport` + `IOAcceleratorES` (IOMatchCategory) survive. Their role is taken by IOGPUDevice (0x120), IOGPUDeviceUserClient (0x130), IOGPUCommandQueue (0x5d0), IOGPUShared* etc. → report these.
## step 3 — tables found
- REAL table signature: entry = ptrauth-signed fn (top32 has 0xbcad) + 4 dwords at +8/+0xc/+0x10/+0x14. My first attempts missed it because the dword base was off by 4 and the fn needs unpac (`VA = BASE + (q & 0x0FFFFFFF)`).
- 151 real IOExternalMethodDispatch tables in __DATA_CONST.
- kext ranges from `__PRELINK_INFO` plist (`_PrelinkExecutableLoadAddr/Size`): IOGPUFamily 0x7829f60 sz 0x5af41, AGXG14P 0x7112f20 sz 0xdcf8c. NOTE these are the __TEXT halves; code lives in __TEXT_EXEC.
- class registries (via OSMetaClass ctor calls): IOGPUFamily 51 classes @0x9940-0x9983 (ctor 0x99844dc); AGX 97 classes @0x8165000-0x8216000 (ctor 0x8215ad0).
- bound: IOGPUDeviceUserClient table 0x7fea200 (112 sel, 0x18); IOGPUMemoryInfoUserClient 0x7fef7c0 (3); IOGPUNotificationQueue 0x7ff2f98 (6)/0x7ff7a78 (3); AGXScheduler 0x7ca6f40 (8, 0x28)/0x7caff88 (7).
## step 4 — gates + handlers + final artifacts
- dispatcher IOGPUDeviceUserClient::externalMethod @0x994a1dc: gate `ldrb [this+0x100]&1` (set in initWithTask @0x9946eb8 from vtable+0x5d0), `args[0x10]==0`, sel<=0x37, then table = (byte[0x103]&1) ? 0x7fea740 : 0x7fea200.
- byte[0x103] written @0x9949eb0 from 0x99658e8 == has_entitlement("com.apple.private.gpu-restricted") || has_entitlement("com.apple.developer.gpu-restricted"). Developer entitlement → private half.
- arg layout mapped from IOUserClient::externalMethod @0xa9a18bc: 0x20 structureInput, 0x28 scalarInputCount, 0x30 scalarInput, 0x38 structureInputSize, 0x40 structureInputDescriptor, 0x50/0x58 out, 0x60/0x68 structout.
- 6 live selectors with strIn=-1: 6,8,25,45,52,53. sel52/53 read u32 at structureInput+0 and +8 with no size; +0 → index into IOGPUDevice::0x99967e24, +8 → count checked as desc_len >= n*4.
- IOGPUMemoryInfoUserClient hard-gated on com.apple.private.ioaccelmemoryinfo @0x997eb08.
- dead/dup table pair 0x7fea200 vs 0x7fea740 (56 entries apart) — both indexed by the same dispatcher.
- sandbox compiled-SBPL string pool @0x79dd800-0x79de400 contains IOAccelContext2 / IOAccel…Device / …Submitter2 / …haredUserClient / AGXDevice / AGXCommandQueue / AGXSharedUserClient / IOGPUDeviceUserClient. profile binding not decoded.
- wrote REPORT.md + tsv/*.tsv (8 files) + classes_*.tsv
## step 5 — polarity correction + ship
- verified 0x9964e38 = task_has_entitlement(userclient->task, string) via vtable+0x138.
- CORRECTION to subagent G: entitled (private|developer gpu-restricted) -> table 0x7fea740 which is the REDUCED one (28 stubs); un-entitled -> 0x7fea200 with all 56 live. Recorded in REPORT.md and CHAT.
- shipped REPORT.md (441+ lines), tsv/ (10 files), CHAT entry "## IOAccel/AGX (subagent J)".
