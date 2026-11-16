from kdis import *

def find_addr_refs(targets, segfilter=('__TEXT_EXEC',)):
    """linear scan; track adrp/add and adrp/ldr patterns; report insn index where reg holds target"""
    hits=[]
    for r in RANGES:
        nm,vm,fo = r[3], r[0], r[2]
        fz = r[1]-r[0]
        if segfilter and r[4] not in segfilter: continue
        regs={}
        prev=None
        for i in md.disasm(D[fo:fo+fz], vm):
            mn=i.mnemonic
            if mn in ('bl','blr','ret','retab','br','braa','blraa','b','cbz','cbnz','tbz','tbnz'):
                regs={}
                if mn=='b': continue
                continue
            if mn=='adrp':
                try:
                    d=i.reg_name(i.operands[0].reg); v=i.operands[1].imm & MASK
                    regs[d]=v
                except Exception: pass
            elif mn=='add' and len(i.operands)==3:
                try:
                    if i.operands[2].type==capstone.arm64.ARM64_OP_IMM:
                        d=i.reg_name(i.operands[0].reg); s=i.reg_name(i.operands[1].reg)
                        if s in regs:
                            regs[d]=(regs[s]+i.operands[2].imm) & MASK
                            if regs[d] in targets:
                                hits.append((i.address, regs[d], r[3]))
                except Exception: pass
            elif mn.startswith('ldr') and mn!='ldrsw':
                try:
                    if i.operands[1].type==capstone.arm64.ARM64_OP_MEM:
                        b=i.reg_name(i.operands[1].mem.base)
                        if b in regs and regs[b] in targets:
                            hits.append((i.address, regs[b], r[3]))
                except Exception: pass
            elif mn=='mov' and len(i.operands)==2:
                try:
                    s=i.reg_name(i.operands[1].reg)
                    d=i.reg_name(i.operands[0].reg)
                    if s in regs: regs[d]=regs[s]
                except Exception: pass
    return hits
