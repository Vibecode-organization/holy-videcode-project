import struct, sys
from capstone import *
from capstone.arm64 import *

PATH="/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache"
BASE=0xfffffff007004000
DATA=open(PATH,'rb').read()

md=Cs(CS_ARCH_ARM64, CS_MODE_ARM)
md.detail=True

def off(va):
    return va-BASE

def rd(va,n):
    o=off(va); return DATA[o:o+n]

def u32(va): return struct.unpack('<I', rd(va,4))[0]
def u64(va): return struct.unpack('<Q', rd(va,8))[0]

def sx(v,bits):
    m=1<<(bits-1)
    v &= (1<<bits)-1
    return (v ^ m) - m

def dis(va,n,label=None):
    out=[]
    for i in md.disasm(rd(va,n), va):
        out.append("%08x  %-8s %s" % (i.address, i.mnemonic, i.op_str))
    if label: out.insert(0,";; "+label)
    return "\n".join(out)

def one(va):
    for i in md.disasm(rd(va,4), va):
        return i
    return None

if __name__=="__main__":
    va=int(sys.argv[1],16); n=int(sys.argv[2],16)
    print(dis(va,n))
