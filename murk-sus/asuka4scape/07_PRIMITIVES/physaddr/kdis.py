import capstone, struct
from kc import *
md=capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
md.detail=True

def dis(va,n,seg=None):
    if seg is None: seg=segof(va)
    o=va2off(va); code=D[o:o+n*4]
    out=[]
    for i in md.disasm(code, va):
        out.append(i)
    return out

def fmt(i):
    s="%#x: %-8s %s"%(i.address,i.mnemonic,i.op_str)
    # annotate bl/b targets
    if i.mnemonic in ('bl','b','adr'):
        try:
            t=i.operands[0].imm & MASK
            if 0xfffffff000000000 <= t <= 0xffffffffffffffff:
                s+="   -> %#x"%t
        except Exception: pass
    return s

def show(va,n,seg=None):
    for i in dis(va,n,seg): print(fmt(i))

def bl_targets(seglist):
    """yield (callsite_va, target_va) for bl/b with imm"""
    for nm,vm,vs,fo,fz in seglist:
        data=D[fo:fo+fz]
        for i in md.disasm(data, vm):
            if i.mnemonic in ('bl','b'):
                try: t=i.operands[0].imm & MASK
                except Exception: continue
                yield (i.address, t)
