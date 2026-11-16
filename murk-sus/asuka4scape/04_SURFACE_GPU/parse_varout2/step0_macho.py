import sys, struct
sys.path.insert(0,"/home/femboychik/work/parse_varout2")
from kc import *
import json

magic, cputype, cpusub, ftype, ncmds, sizeofcmds, flags, res = struct.unpack_from("<IiiIIIII", DATA, 0)
print(hex(magic), hex(cputype), ftype, ncmds, sizeofcmds, hex(flags), res)

p = 32
cmds = []
for i in range(ncmds):
    cmd, csize = struct.unpack_from("<II", DATA, p)
    cmds.append((cmd, csize, p))
    p += csize

names = {0x19:"LC_SEGMENT_64", 0x1:"LC_SYMTAB", 0xb:"LC_DYSYMTAB", 0x26:"LC_FUNCTION_STARTS",
         0x1d:"LC_CODE_SIGNATURE", 0x2:"LC_SYMSEG", 0x80000022:"LC_DYLD_INFO_ONLY",
         0x22:"LC_DYLD_INFO", 0x80000033:"LC_DYLD_EXPORTS_TRIE", 0x80000034:"LC_DYLD_CHAINED_FIXUPS",
         0x2a:"LC_ENCRYPTION_INFO_64", 0x1e:"LC_SEGMENT_SPLIT_INFO", 0x32:"LC_BUILD_VERSION"}
for cmd, csize, p in cmds:
    print(hex(cmd), names.get(cmd,"?"), csize)
    if cmd == 0x19:
        segname = DATA[p+8:p+24].rstrip(b"\0").decode()
        vmaddr, vmsize, fileoff, filesize = struct.unpack_from("<QQQQ", DATA, p+24)
        maxprot, initprot, nsects, sgflags = struct.unpack_from("<iiII", DATA, p+56)
        print("   ", segname, hex(vmaddr), hex(vmsize), hex(fileoff), hex(filesize), nsects)
    elif cmd == 0x1:
        symoff, nsyms, stroff, strsize = struct.unpack_from("<IIII", DATA, p+8)
        print("    symoff", hex(symoff), "nsyms", nsyms, "stroff", hex(stroff), "strsize", hex(strsize))
    elif cmd == 0x26:
        dataoff, datasize = struct.unpack_from("<II", DATA, p+8)
        print("    funcstarts off", hex(dataoff), "size", hex(datasize))
    elif cmd == 0x2a:
        print(struct.unpack_from("<IIII", DATA, p+8))
