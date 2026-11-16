# IOSurface property setters audit — progress

- target: `27.2_24B115_kernelcache` (67 239 936 B), iOS 27.2
- segments parsed OK: __TEXT 0xfffffff007004000 / __PRELINK_TEXT / __DATA_CONST 0xfffffff007bb8000 / __TEXT_EXEC 0xfffffff00814c000 / __DATA 0xfffffff00acb4000 / __PRELINK_INFO
- 250 LC_FILESET_ENTRY, no LC_SYMTAB (no symbols)
- IOSurface kext header VM = 0xfffffff00789a030, fileoff 0x896030
- CONFIRMED: terse VAs in task are `0xfffffff0XXXXXXXX` form. sel0 handler = 0xfffffff009c3888c (bti/pacibsp prologue OK), create_surface = 0xfffffff009c3ab8c (prologue OK)
## step 1 — call graph (partial)
- IOSurface kext: 1330 funcs from LC_FUNCTION_STARTS, __text 0xfffffff009c14f20..0xfffffff009c49554
- key strings live in kext __cstring 0xfffffff00789a748..0xfffffff00789dbff (438 strings)
- `create_surface` 0x9c3ab8c: vtable+0x138(dict, gSymbol@0x8066fc0) = getObject; then calls 0x9c33c34(x0=[this+0xe8], x1=authed[this+0xf8], x2=dict, x3=extra) -> IOSurface*
- `create_surface_fast_path` 0x9c3bb20: builds own OSDictionary: setObject(vt+0x100) with keys Address, Width, Height, PixelFormat, BytesPerElement, BytesPerRow, AllocSize (values = u32 from descriptor at args+8). NOT user-controlled keys; numbers only.
- NEXT: dump 0x9c33c34 chain -> IOSurface::initWithProperties
## step 2/3 — IOSurface::initWithProperties = 0xfffffff009c1af14 (size 0x3710, args: x0=IOSurface*, x1=OSDictionary*)
- getter family: 0x9c1fec4 getBool, 0x9c20038 getU64(via dict->getObject vt+0x138 -> OSNumber bits vt+0x88 / value vt+0xb0, sign-extends by bits), 0x9c1ff50 getU32(>32b -> "exceeds maximum"), 0x9c20114 getU8
- struct fields written: 0x58 width(u64), 0x60 height(u64), 0x68 bytesPerRow(u64), 0x70 bytesPerElement(u16), 0x72/0x73 elementW/H(u8), 0x78 offset(u64), 0x80 pixelFormat(u32), 0x90 allocSize(u64), 0x3d0 flags
- checks seen so far: widthInElements=(width+elemW-1)/elemW with overflow detect; bytesPerRow >= widthInElements*bpe (0x9c1cf74); bpr calc overflow; allocSize round-to-page overflow; allocSize <= [root+0x198]; child <= parent size 0x90
- HEIGHT read at 0x9c1dcdc — next
## step 4 — итог
- sel 7 (0x9c38adc) = create_surface_client_mem(addr,size) -> dict {IOSurfaceAddress,IOSurfaceAllocSize} -> 0x9c3bf44 -> init; entitlement-гейта в кесте нет
- IOSurfaceAddress -> [IOSurface+0x150], проверки: compressed==0, [+0x3a0]==0, page-align (0x9c1e93c). Владение не проверяется = топ-1
- PlaneBase (0x9c1ba40) без локальной проверки, но 0x9c1da48 cmp base+size vs fAllocSize закрывает
- геометрия/сжатые тайлы — все с umulh/adds/проверкой >>32; allocSize: page-round, parent, [root+0x198]
- IOSurfaceMemoryPoolSize (0x789b484): 0 code refs, 0 указателей в сегментах -> мёртвый ключ
- REPORT.md записан
