import sys,struct,json
sys.path.insert(0,'/home/femboychik/work/parse_varout')
from kmap import *
import capstone
md=capstone.Cs(capstone.CS_ARCH_ARM64,capstone.CS_MODE_ARM)
md.detail=False
PACIBSP=0xD503237F; BTIC=0xD503245F; PACIA1716=0xD503211F
def func_start(va,limit=0x600):
    best=None
    for o in range(0,limit,4):
        p=va-o
        if p<0xfffffff007004000: break
        w=u32(p)
        if w in (PACIBSP,BTIC): best=p
        # stop at previous unconditional ret/branch boundary? keep last prologue marker
        if o>0x300 and best is not None: break
    return best
def dis(va,n=24):
    o=va2off(va)
    if o is None: return []
    out=[]
    for ins in md.disasm(D[o:o+n*4],va):
        out.append((ins.address,ins.mnemonic,ins.op_str,ins.bytes.hex()))
        if len(out)>=n: break
    return out
def dump(va,n=24,mark=None):
    for a,m,o,h in dis(va,n):
        f="  "+(("<<< " if mark and a==mark else ""))
        print(f"{a:#018x} {h:8s} {m:8s} {o} {f}")
def reg(w,shift=0): return (w>>shift)&31
def x(i): return 'sp' if i==31 else ('xzr' if i==30 and False else f'x{i}')
def fmt_ldr(w):
    rt=w&31; rn=(w>>5)&31; imm=((w>>10)&0xFFF)*8
    return f"ldr x{rt}, [{'sp' if rn==31 else f'x{rn}'}, #{imm:#x}]"
def fmt_str(w):
    rt=w&31; rn=(w>>5)&31; imm=((w>>10)&0xFFF)*8
    return f"str x{rt}, [{'sp' if rn==31 else f'x{rn}'}, #{imm:#x}]"
