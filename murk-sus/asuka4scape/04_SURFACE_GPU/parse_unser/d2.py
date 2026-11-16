import struct
from capstone import *
from capstone.arm64 import *
from kc import KC, SEGS
def dis(kc, va, n):
    md=Cs(CS_ARCH_ARM64, CS_MODE_ARM); md.detail=True
    o=kc.va2off(va)
    return list(md.disasm(kc.d[o:o+n*4], va))
def is_str_at(kc, va):
    o=kc.va2off(va)
    if o is None: return None
    e=kc.d.find(b'\0',o,o+200)
    if e<0: return None
    b=kc.d[o:e]
    if len(b)<2 or not all(32<=c<127 or c in (9,10) for c in b): return None
    return b.decode()
def dump(kc, va, n):
    out=[]; prev=None
    for ins in dis(kc,va,n):
        line='0x%016x  %-8s %s'%(ins.address,ins.mnemonic,ins.op_str)
        cmt=''
        if ins.mnemonic=='adrp':
            prev=(ins.operands[0].reg, ins.operands[1].imm & 0xFFFFFFFFFFFFFFFF)
        elif prev and len(ins.operands)>=2:
            if ins.mnemonic in ('add','ldr','ldrb','ldrh','str','ldrsw'):
                base=None; disp=0
                if ins.mnemonic=='add' and len(ins.operands)==3 and ins.operands[2].type==ARM64_OP_IMM:
                    base=ins.operands[1].reg; disp=ins.operands[2].imm
                elif ins.operands[1].type==ARM64_OP_MEM:
                    base=ins.operands[1].mem.base; disp=ins.operands[1].mem.disp
                if base==prev[0]:
                    tgt=(prev[1]+disp)&0xFFFFFFFFFFFFFFFF
                    s=is_str_at(kc,tgt)
                    cmt='; 0x%x'%tgt+(' "%s"'%s if s else '')
        if ins.mnemonic in ('bl','b'):
            cmt='; -> 0x%x'%(ins.operands[0].imm&0xFFFFFFFFFFFFFFFF)
        out.append(line.ljust(56)+cmt)
    return '\n'.join(out)
