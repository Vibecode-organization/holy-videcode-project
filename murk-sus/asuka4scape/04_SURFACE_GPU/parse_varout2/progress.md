# progress — var-output scan, 27.2 (24B115)

KC: /home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache (67239936 bytes)
Layout:
  __TEXT_EXEC      va 0xfffffff00814c000  file 0x1148000  size 0x2924000
  __DATA_CONST     va 0xfffffff007bb8000  file 0xbb4000   size 0x548000
  __DATA           va 0xfffffff00acb4000  file 0x3cb0000  size 0x2b8000
  __PRELINK_INFO   va 0xfffffff00aa78000  file 0x3a74000  size 0x23c000

env: python 3.14.7, capstone 5.0.7

## log
- [0] start, dirs created
- [1] step0: parsed top MH (no LC_SYMTAB, no FUNCTION_STARTS; LC_FILESET_ENTRY x250, LC_DYLD_CHAINED_FIXUPS stub).
- [1a] __PRELINK_INFO plist -> 267 kexts, 249 with _PrelinkExecutableLoadAddr (64-bit signed, mask &0xffffffffffffffff).
- [1b] per-kext Mach-O header in __PRELINK_TEXT gives real segment VAs (incl __TEXT_EXEC/__DATA_CONST/__DATA).
      coverage of __TEXT_EXEC: contiguous 0xfffffff00814c000..0xfffffff00a1c9938 (gaps only 4/8/12-byte align),
      tail 0xa1c9938..0xaa70000 = zeros then code at 0xfffffff00a1cdd00 (owner kext unknown yet).
- [2] step1 raw scan __TEXT_EXEC done -> hits_raw.txt / hits_raw.json
      ldr 0x78 = 3116, ldp 0x70 = 198, ldp 0x78 = 192, stp..., etc. total 33325 raw hits.
