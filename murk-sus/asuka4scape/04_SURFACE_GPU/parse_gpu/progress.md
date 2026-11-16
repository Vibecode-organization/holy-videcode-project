# GPU/MFB surface — subagent D
target: /home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache (67,239,936 B)

## Step 0 — init
- [x] workspace created

## Step 1 — kext map
- [x] kc.py parser (segments, off(), rd(), q())
- [x] kexts.py -> kexts.json (267 kexts, addr+size from __PRELINK_INFO)
- NOTE: no LC_FILESET_ENTRY, no LC_SYMTAB (nsyms=0). kext size = __TEXT only; data segs are separate.

## Step 2 — per-kext segment map
- [x] kmap.py -> kmap.json: each kext's own Mach-O parsed (249/249 ok)
- IOGPUFamily __TEXT_EXEC=0x99407d0+0x4481c, __DATA_CONST=0x7fe8c10+0x9c38
- IOSurface   __TEXT_EXEC=0x9c14f20+0x34f74, __DATA_CONST=0x8066558+0x6528
- AGXG14P     __TEXT_EXEC=0x8165300+0xb1e70, __DATA_CONST=0x7c923f0+0x13e00
- H11ANE      __TEXT_EXEC=0x892d870+0x154c94, __DATA_CONST=0x7dbe430+0x206e0
- JPEGDriver  __TEXT_EXEC=0x8c7b8a0+0x2e008, __DATA_CONST=0x7e27198+0x6118
- SEPKeyStore __TEXT_EXEC=0x9132630+0x4138c, __DATA_CONST=0x7ec2598+0x5240
- Confirmed stride 0x28 layout: fn(8) sIn(4) strIn(4) sOut(4) strOut(4) then 8 zero bytes
- Confirmed prior table 0xfffffff008068b90 == IOSurface __DATA_CONST

## Step 3 — string scan
- [x] class-name strings found in each kext __TEXT but NOT referenced by any data pointer (only adrp/add in code)
- [x] entitlement strings near IOSurface handlers: com.apple.private.iosurfaceinfo, com.apple.private.gpu-restricted, com.apple.developer.gpu-restricted
- [x] "site.<ClassName>" strings present (kprintf tags), no data xref
- [x] sandbox profile string pool in __DATA_CONST @0xfffffff0079ddea4.. holds the container require-any list (confirms Kai's list)
- DECISION: attribution = table -> kext (exact segments) + adrp/add xref -> referencing fn -> vtable/kext + handler string evidence

## Step 4 — dispatch tables (ground truth = adrp/add xref)
- [x] xrefs4.py -> xreffull.pkl (1.1M adrp/add+add-chain pairs, 207k distinct targets)
- [x] tabs2.py -> tables_ref.json: only tables actually referenced by code (true bases)
- KEY: two tables per class selected by a class flag bit -> `csel` between table A and table B
- IOGPUDeviceUserClient dispatcher 0x994a1e0: cmp w1,#0x37 (56 sel), umull x9,w1,#0x18,
      tables 0x7fea200 / 0x7fea740, gate ldrb w9,[x0,#0x100] bit0, ldrb w8,[x0,#0x103] bit0 -> variant
      if args->structureInputDescriptor (args+0x10) != 0 -> returns kIOReturnUnsupported+0x16 (0xe00002d8)
- IOSurface dispatcher 0x9c3ee14: tables 0x8068b90 / 0x80694f0 (17 sel each), variant = ldrb [x0,#0x127] bit0
- 0xffffffff in strIn field == unchecked-size sentinel

## Step 5 — tables dumped
- [x] tables_target.json: IOSurface 17 sel (x2 variants), IOGPUDeviceUserClient 56 sel (x2 variants),
      H11ANE 3 tables (11/2/4), AppleJPEGDriver 6 sel
- IOGPU variant table B routes ~30 selectors to a single stub 0x9949520 (restricted/paravirt mode)

## Step 6 — IOExternalMethodArguments layout CONFIRMED from handler code
  +0x00 version  +0x04 selector
  +0x10 asyncReference[0]   (IOGPU dispatcher rejects !=0 -> kIOReturnMessageTooLarge)
  +0x20 scalarInput (u64*)  +0x28 scalarInputCount
  +0x30 structureInput (void*)   +0x38 structureInputSize (u32)
  +0x40 structureInputDescriptor (IOMemoryDescriptor*)
  +0x48 scalarOutput (u64*)  +0x50 scalarOutputCount
  +0x58 structureOutput (void*)  +0x60 structureOutputSize (u32, in/out)
- [x] handlers_probe.json: first 16 insns + call targets for every selector
- IOSurface sel0 validates scalarInput[0] hi32==0 then uses it as surface id
- IOSurface sel9 reads args+0x40 (structureInputDescriptor) with strIn=UNCHECKED

## Step 7 — OSMetaClass ctor scan => definitive class inventory + instance sizes
- [x] metaclass.py -> metaclass.json (site, name, size per class)
- IOSurfaceRootUserClient  size=0x148  ctor 0x9c38400   <-> table 0x8068b90 (dispatcher 0x9c3ee10 uses [x0+0x127],[x0+0x126],[x0+0xe8],[x0+0x120])  CONFIRMED
- IOGPUDeviceUserClient    size=0x130  ctor 0x9946b6c   <-> table 0x7fea200 (dispatcher 0x994a1e0 uses [x0+0x100],[x0+0x103])                    CONFIRMED
- AGXG14P: AGXDeviceUserClient size=0x138, AGXCommandQueue 0x948, AGXCommandBuffer 0x17c0 — but ZERO dispatch tables in kext
- IOMobileGraphicsFamily: IOMobileFramebufferUserClient size=0x958 — ZERO dispatch tables
- AppleSEPKeyStore: AppleKeyStoreUserClient size=0x118 — ZERO dispatch tables
- AppleJPEGDriver: 1 table (6 sel) but class names in kext are only AppleJPEGWrapperControlV14 etc.
- Both big user clients use hand-rolled selector switches instead of IOExternalMethodDispatch -> must be analyzed separately

## Step 8 — handler analysis (done)
- IOSurface sel0 s_create_surface: no min length, OSUnserializeXML(ptr,len) via GOT 0x806c618; limit 0x4000 surfaces/client
- IOSurface sel9: 12-byte hdr + OSUnserializeXML(ptr+0xc, len-0xc), min 0xd, uxtw -> correct bounds
- IOSurface sel10: min 0xd both dirs, both may be descriptors
- IOGPU sel8: len>=0x58, output unchecked
- IOGPU sel45: (len-8)%0x18==0 && input[0]==count  -> exemplar safe
- IOGPU restricted stub 0x9949520 = kIOReturnNotPermitted (0xe00002e2)
- IOSurface restricted stub 0x9c3a1dc = kIOReturnNotPermitted, sel 4,5,6,7,8,16
- entitlement gates: iosurfaceinfo / gpu-restricted / developer.gpu-restricted / IOSurface.protected-access
- MIG io_connect_method #2865 argc=17 -> descriptor path reachable from userspace

## Step 9 — deliverables
- [x] REPORT.md
- [x] selectors_*.tsv (7 files)
- [x] chat entry
- [x] corrected: IOSurface sel11 -> 0x9c3c9c0 (id + NUL-terminated string, bounds OK), IOGPU sel8 output unchecked noted
- FINAL: REPORT.md 34.9K, 7 TSV, chat entry appended (11 lines)
