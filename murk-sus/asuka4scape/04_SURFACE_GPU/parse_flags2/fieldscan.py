import struct
from kcd import data, SECTIONS
def scan(secname, imm):
    va,sz,fo = SECTIONS[secname]
    words = struct.unpack_from('<%dI'%(sz//4), data, fo)
    res=[]
    for i,w in enumerate(words):
        # byte load/store unsigned imm: 0011 1001/1000 size=00 opc ...  -> ldrb 0x39400000, strb 0x39000000
        if (w & 0xFFC00000) in (0x39400000, 0x39000000):
            off = (w>>10)&0xFFF
            if off == imm:
                rt = w & 0x1F; rn = (w>>5)&0x1F
                kind = 'ldrb' if (w & 0xFFC00000)==0x39400000 else 'strb'
                res.append((va+i*4, kind, rn, rt))
    return res
for imm in (0x122, 0x127):
    print(f"=== byte accesses at +0x{imm:x} ===")
    for a,k,rn,rt in scan('__TEXT_EXEC', imm):
        print(f"  0x{a:x}: {k} w{rt}, [x{rn}, #0x{imm:x}]")
