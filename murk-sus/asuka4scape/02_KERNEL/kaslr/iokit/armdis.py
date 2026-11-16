import sys
sys.path.insert(0,'.')
from macho import *
from capstone import *
from capstone.arm64 import *
md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
md.detail = True
def disasm(va, n=40, extra=0):
    code = rd(va, n*4+extra)
    out=[]
    for i in md.disasm(code, va):
        out.append(f"{i.address:#018x}: {i.bytes.hex():<10} {i.mnemonic:<8} {i.op_str}")
        if len(out)>=n: break
    return "\n".join(out)
