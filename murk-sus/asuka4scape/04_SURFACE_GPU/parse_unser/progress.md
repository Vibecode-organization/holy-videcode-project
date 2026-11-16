# progress — OSUnserialize 27.2 (subagent E)

## setup
- workspace: /home/femboychik/work/parse_unser
- kc 27.2: /home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache (67239936)
- kc 27.0: /home/femboychik/Рабочий стол/дипсик 1/kc/27.0_24A437_kernelcache (66977792)
- next: check tooling (capstone, python)

## step 1 — string/table mapping done
- __LINKEDIT = bplist kext-symbol export (names only, NO addresses). 6181 syms, kpi.libkern set confirms overloads:
  __Z16OSUnserializeXMLPKcPP8OSString  / ...PKcmPP8OSString  / ...PKcmPFPK8OSObject... / OSSharedPtr variants
  __Z13OSUnserializePKcPP8OSString ; no OSUnserializeBinary symbol exported.
- string blob VAs (__PRELINK_TEXT):
  0xfffffff0070ae996 "OSUnserialize: %s near line %d"
  0xfffffff0070ae9bc "unexpected end of buffer"  0xfffffff0070ae9d5 "syntax error"
  0xfffffff0070ae9e2 buildDictionary / e9f2 "maximum object count" / ea07 buildArray / ea12 buildSet
  / ea1b buildString / ea27 buildData / ea31 buildNumber / ea3d buildBoolean / ea4a "maximum object reference count"
  / ea69 "forward reference detected" / ea84 "duplicate dictionary key" / ea9d "memory exhausted"
  / eaae "site.parser_state_t" + eac2 "12111112211" / eace "OSUnserializeXML: %s near line %d"
  / eaf1..eb23 tag table (array dict data format integer size plist string) / eb2e "site.object_t" "11111211222"

## step 2 — functions found (func list = pacibsp scan, 110809 funcs, funcs.pkl)
- 0xfffffff00a8d5c98  OSUnserializeXML(buf, OSString**)  [2-arg, no size] -> legacy parser
- 0xfffffff00a8d4630  legacy XML parser core (0x1668 b). uses globals in __DATA:
    buf=0xfffffff00add71d8, off=0xfffffff00add71e0 (u32), errbuf=0xfffffff00add7158 (128B), root=0xfffffff00add7140,
    line=0xfffffff00ad95f18, quote=0xfffffff00ad95f08 ; errors via 0xfffffff0070ae996 "OSUnserialize:"
- 0xfffffff00a8d846c  OSUnserializeXML(buf,size,func,ref,err) core (0x20c b) -> allocs 0x40B parser_state_t -> calls new parser
- 0xfffffff00a8d5ea4  NEW XML parser core (0x1bb4 b) uses "OSUnserializeXML:" + buildXxx + max-object-count etc; kalloc_type site.parser_state_t
- 0xfffffff00a8d812c  small helper (0x10c) called from 0xa8d5ea4 = error-string setter
- 0xfffffff00a8da3fc / 0xfffffff00a8da470 = OSSharedPtr<OSString>& overloads wrapping 0xa8d846c

## step 3 — overloads & dispatcher (VERIFIED by disasm)
- 0xfffffff00a8d8678  OSUnserializeXML(buf, size, func, ref, flags, err) 6-arg:
    if(!buf) return 0; if(size<4) return 0;
    if (strcmp("\xd3", buf)==0 || buf[0]==0xd4)  -> tail-call BINARY parser 0xfffffff00a8d96f4 (requires buf 4-byte aligned)
    else { if (buf[size-1] != 0) return 0;  -> tail-call B (XML core) with NO size }
- 0xfffffff00a8d8754  OSUnserializeXML(buf, size, err): same, XML path same NUL check
- 0xfffffff00a8d8660  OSUnserializeXML(buf, err) -> B directly (via 0xa8d8674 branch)
- 0xfffffff00a8d5c98  OSUnserializeXML(buf, err) 2-arg via LEGACY parser 0xa8d4630
- binary: 0xfffffff00a8d96f4 (0xd08 b), classic tag/word format (word&0x7F000000 type, &0xFFFFFF data)
- XML core: B=0xa8d846c -> state alloc kalloc_type(0xfffffff007c7c2d0, 0x40) -> parser 0xa8d5ea4
- XML parser limits found:
    * object count: state+0x38 u32, ++ then if (old >= 0x1FFFF) error "maximum object count"  (2 sites: 0xa8d6a74/0xa8d6b78/0xa8d6c3c)
    * live/temp objects: state+0x3c u32, if (++ >= 0x10000) error  (0xa8d6b30..0xa8d6b64)
    * tag name <= 31 chars (0xa8d7718 cmp x8,#0x1f), attr name <=30 (0xa8d77ec), attr value <=30 (0xa8d78cc)
    * attribute count <= 31 (0xa8d7928 cmp w11,#0x1e) -> 32 records * 32B at sp+0x800/0xC00
    * NO buffer length in parser_state_t: offset is u32 at state+0x08, read via `ldr w8,[x19,#8]`+sxtw; parser reads until NUL/'<' -> requires NUL-terminated input
    * depth: no explicit depth counter; nesting via linked list state+0x18 (object_t nodes), bounded only by object count 131071

## step 4 — IOSurface chain
- IOSurfaceRootUserClient code range in __TEXT_EXEC ~0xfffffff009c3xxxx-0x9c4xxxx (strings 0xfffffff00789cxxx/0xfffffff0078axxx).
- 0xfffffff009c38890  action wrapper for selector 0, logs with "s_create_surface"; reads args:
      [args+0x20] = scalarInput ptr -> parentID (u64, must fit 32 bits: "invalid parentID (0x%llx)")
      [args+0x40] = structureInputDescriptor (if != 0: map via vtable+0xe8(w1=0x1000); getAddress vtable+0x78; getLength vtable+0xb0)
      else        [args+0x30] = structureInput,  w4 = [args+0x38] = structureInputSize (u32)
      if (buf==0 || size==0) -> "%s error - no args"
      bl 0x9c3ab8c (create_surface) with (this, buf, parentID, [args+0x58], size)
- 0xfffffff009c3ab90  create_surface: client limit check ([this+0x128] < 0x1000)
      parse: 0x9c3ac18  mov x1, size(u32 zero-ext) ; x2 = 0 ; bl PLT 0x9c49764 (slot 0xfffffff00806c618)
      slot 0x806c618 = OSUnserializeXML(buf,size,err) 6-arg? -> actually 0xa8d8754 (sized3) => OSUnserializeXML(buf,size,OSString**)
      result must be non-NULL; then dynamic-cast check to OSDictionary (via 0x9c498d4 + metaClass 0x806c9c8)
      then IOSurfaceRoot::createSurface(dict) etc.
- NOTE: no data xref to 0x9c38890 / 0x9c3ab90 anywhere in cache (dispatch table not found) => selector->action binding NOT confirmed.

## step 5 — DIFF 27.0 vs 27.2 (normalized-insn sha256, adrp/add/bl/pc-rel masked)
- parser cluster in 27.0 = 27.2 - 0x3FDEC (libkern block), IOSurface = 27.2 - 0x3AFA8 (create_surface).
- IDENTICAL (ndiff=0):
    2-arg wrapper d3fd6183 / core 563f0d0e / stub 7 insn f1e48839 / sized6 079e5ea4 / sized3 1cca973d
    sharedptr wrappers 7c19e227 b429a8e1 / binary parser 320e87e6 (834 insn) / legacy 726195ca (1434)
    new parser 65f5da4e (1773) / err setter f229a211 / finalize ea07d557 / hex 38320f97 / b64 fda2bdd8
    number d077cfed / string 06767a38 / create_surface 64c8fa84 (333) / s_create_surface identical
- libkern unserialize error-string blob byte-identical between builds; same 23 strings referenced by parser
- PLT slot check: 27.0 slot 0x805efb8 -> 0xa898968 (= sized3), 27.2 slot 0x806c618 -> 0xa8d8754 -> same call
=> NO parser changes 27.0 -> 27.2. Answer to diff question: code identical.

## step 6 — REPORT.md written
- /home/femboychik/work/parse_unser/REPORT.md (адреса, таблица проверок, цепочка IOSurface, 5 подозрительных мест, дифф)
- created artifacts: kc.py xr.py dump.py d2.py funcs.py gotx.py gotx0.py adrprefs.pkl adrprefs0.pkl normdiff*.py diff27.py
- remaining: CHAT_дипсики.md entry

## done
- REPORT.md (384 строки) + запись в CHAT_дипсики.md
- итог: парсеры и путь IOSurface в 27.2 идентичны 27.0; границы чтения держатся на NUL
