import sys, struct, json
sys.path.insert(0,"/home/femboychik/work/parse_varout2")
from kc import *

# LC_FILESET_ENTRY = 0x80000035
magic, cputype, cpusub, ftype, ncmds, sizeofcmds, flags, res = struct.unpack_from("<IiiIIIII", DATA, 0)
p = 32
ents = []
for i in range(ncmds):
    cmd, csize = struct.unpack_from("<II", DATA, p)
    if cmd == 0x80000035:
        vmaddr, fileoff = struct.unpack_from("<QQ", DATA, p+8)
        entry_id_off = struct.unpack_from("<I", DATA, p+24)[0]
        name = DATA[p+entry_id_off:DATA.find(b"\0", p+entry_id_off)].decode()
        ents.append((vmaddr, fileoff, name))
    p += csize

ents.sort()
print("fileset entries:", len(ents))
for e in ents[:5]: print(hex(e[0]), hex(e[1]), e[2])
json.dump(ents, open("/home/femboychik/work/parse_varout2/fileset.json","w"))
print("range:", hex(ents[0][0]), hex(ents[-1][0]))
