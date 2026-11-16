import sys
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from kc import load
k=load()
md=Cs(CS_ARCH_ARM64, CS_MODE_ARM); md.detail=True
def dis(va, n=40, stop_ret=True):
    out=[]
    o=k.off(va)
    code=k.data[o:o+n*4]
    for i in md.disasm(code, va):
        out.append(f"{i.address:#018x}  {i.mnemonic:8} {i.op_str}")
        if stop_ret and i.mnemonic in ('ret','retab'): break
    return out
if __name__=='__main__':
    va=int(sys.argv[1],16); n=int(sys.argv[2]) if len(sys.argv)>2 else 40
    for l in dis(va,n): print(l)
