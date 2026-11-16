import struct
from kcd import data, SECTIONS
tva,tsz,tfo=SECTIONS['__TEXT_EXEC']
words=struct.unpack_from('<%dI'%(tsz//4),data,tfo)
def overlap(base_off, size):
    return base_off < 0x123 and base_off+size > 0x122
res=[]
for i,w in enumerate(words):
    a=tva+i*4
    # unsigned imm forms
    if (w & 0xFFC00000) in (0x39000000,0x39400000): off=(w>>10)&0xFFF; sz=1
    elif (w & 0xFFC00000) in (0x79000000,): off=(w>>10)&0xFFF; sz=2
    elif (w & 0xFFC00000) in (0xB9000000,0xBD000000): off=((w>>10)&0xFFF)*4; sz=4
    elif (w & 0xFFC00000) in (0xF9000000,0xFD000000): off=((w>>10)&0xFFF)*8; sz=8
    elif (w & 0xFFC00000)==0x3D800000: off=((w>>10)&0xFFF)*16; sz=16
    elif (w & 0xFFE00C00) in (0x38000C00,0x39000C00):  # skip; handled elsewhere
        continue
    else:
        continue
    if overlap(off,sz): res.append((a,off,sz))
for a,off,sz in res:
    in_ios = 0xfffffff009c30000 <= a < 0xfffffff009c40000
    print(f"0x{a:x} off=0x{off:x} size={sz} {'<<< IOSURFACE CLIENT CLUSTER' if in_ios else ''}")
