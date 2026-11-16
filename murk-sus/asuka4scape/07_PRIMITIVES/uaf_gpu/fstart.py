from kc import *
import struct,sys
def find_start(va, back=0x2000):
    o=va2off(va)
    for d in range(0, back, 4):
        w=struct.unpack_from("<I",DATA,o-d)[0]
        if w==0xd503245f:  # bti c
            return va-d
    return None
def find_end(va, maxlen=0x4000):
    o=va2off(va)
    for ins in MD.disasm(DATA[o:o+maxlen], va):
        if ins.mnemonic in ("ret","retab"):
            return ins.address+4
if __name__=="__main__":
    for a in sys.argv[1:]:
        va=int(a,0)
        s=find_start(va); e=find_end(s) if s else None
        print(f"{va:#x} -> start {s:#x} end {e:#x} len {e-s if e and s else 0:#x}")
