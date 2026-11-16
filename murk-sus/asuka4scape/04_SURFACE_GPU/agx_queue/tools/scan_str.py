#!/usr/bin/env python3
# scan a code range for adrp/add | adrp/ldr references to a target VA
import sys
from kc import Fileset
from vm import VM, disasm

def scan(v, start, end, targets, ctx=6):
    hits=[]
    adrp={}
    insns = disasm(v, start, nbytes=end-start)
    for i,ins in enumerate(insns):
        m = ins.mnemonic
        if m == 'adrp':
            reg = ins.op_str.split(',')[0].strip()
            tgt = None
            for op in ins.operands:
                if op.type == 2: tgt = op.imm & 0xFFFFFFFFFFFFFFFF
            adrp[reg]=tgt
            continue
        # add xD, xS, #imm  /  ldr xD, [xS, #imm]
        if m in ('add','ldr','ldrb','ldrh','ldrsw') and '#' in ins.op_str:
            parts = [p.strip() for p in ins.op_str.split(',')]
            if len(parts)>=3:
                base_reg = parts[1].strip('[] ')
                if m!='add' and ']' not in parts[1]: continue
                imm = None
                for op in ins.operands:
                    if op.type == 2: imm = op.imm
                if base_reg in adrp and imm is not None:
                    t = (adrp[base_reg] + imm) & 0xFFFFFFFFFFFFFFFF
                    if t in targets:
                        hits.append((ins.address, t, ins.mnemonic, ins.op_str))
    return hits

if __name__=='__main__':
    fs=Fileset(); v=VM(fs)
    start=int(sys.argv[1],16); end=int(sys.argv[2],16)
    tgts={int(x,16) for x in sys.argv[3:]}
    hs = scan(v,start,end,tgts)
    for a,t,m,o in hs:
        print(f"hit {a:#x} -> {t:#x}  {m} {o}")
        for ins in disasm(v,a-0x20,count=8):
            print(f"   {ins.address:#x}: {ins.mnemonic:8s} {ins.op_str}")
    print(len(hs),"hits")
