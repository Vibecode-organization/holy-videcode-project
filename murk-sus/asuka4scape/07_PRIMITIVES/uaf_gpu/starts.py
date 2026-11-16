from kc import *
import struct,sys
def starts(a,b):
    o=va2off(a); n=b-a
    res=[]
    for i in range(0,n-4,4):
        w=struct.unpack_from("<I",DATA,o+i)[0]
        if w==0xd503245f:  # bti c
            res.append(a+i)
    return res
a=int(sys.argv[1],0); b=int(sys.argv[2],0)
for s in starts(a,b):
    e=None
    for ins in MD.disasm(DATA[va2off(s):va2off(s)+0x600], s):
        if ins.mnemonic in ("ret","retab"): e=ins.address+4; break
    print(f"{s:#x} len={ (e-s) if e else 0:#x}")
