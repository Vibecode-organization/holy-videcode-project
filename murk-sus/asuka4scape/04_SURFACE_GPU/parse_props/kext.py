import struct
from kc import DATA
FO=0x896030
m=struct.unpack_from('<I',DATA,FO)
print("mach magic %#x"%m, "cputype",struct.unpack_from('<I',DATA,FO+4)[0])
ncmds=struct.unpack_from('<I',DATA,FO+16)[0]
sizeofcmds=struct.unpack_from('<I',DATA,FO+20)[0]
print("ncmds",ncmds,"size",sizeofcmds)
off=FO+32
from collections import Counter
c=Counter()
for i in range(ncmds):
    cmd,sz=struct.unpack_from('<II',DATA,off)
    c[hex(cmd)]+=1
    if cmd==0x19:
        name=DATA[off+8:off+24].rstrip(b'\0').decode()
        vm,vs,fo,fs=struct.unpack_from('<QQQQ',DATA,off+24)
        ns=struct.unpack_from('<I',DATA,off+64)[0]
        print(f"SEG {name:16s} vm={vm:#x} vsz={vs:#x} fo={fo:#x} fsz={fs:#x} nsects={ns}")
        so=off+72
        for s in range(ns):
            sn=DATA[so:so+16].rstrip(b'\0').decode()
            sseg=DATA[so+16:so+32].rstrip(b'\0').decode()
            addr,size,offset=struct.unpack_from('<QQI',DATA,so+32)
            print(f"   SEC {sseg},{sn:20s} addr={addr:#x} size={size:#x} off={offset:#x}")
            so+=80
    elif cmd==0x26 or cmd==0x1d or cmd==0x2 or cmd==0xb:
        print("CMD",hex(cmd),DATA[off:off+min(sz,40)].hex())
    off+=sz
print(c)
