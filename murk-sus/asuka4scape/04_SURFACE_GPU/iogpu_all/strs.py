#!/usr/bin/env python3
import sys
from kc import *

M64=0xFFFFFFFFFFFFFFFF

def dis_range(start, end):
    off=va2off(start)
    if off is None: return []
    return list(MD.disasm(DATA[off:off+(end-start)], start))

def strings_in(start, end):
    ins=list(dis_range(start,end))
    out=[]
    prev=None
    for i in ins:
        if i.mnemonic=="adrp":
            try:
                prev=i.operands[1].imm & M64
            except Exception: prev=None
            continue
        if i.mnemonic=="add" and prev is not None and len(i.operands)==3:
            try:
                imm=i.operands[2].imm & M64
                va=(prev+imm)&M64
                s=cstr(va,300)
                if s: out.append((i.address,va,s))
            except Exception: pass
        prev=None
    return out

def find_end(va, limit=None, maxlen=0x800):
    if limit is None: limit=va+maxlen
    off=va2off(va)
    for ins in MD.disasm(DATA[off:off+maxlen], va):
        if ins.mnemonic in ("ret","retab"):
            return ins.address+4
        if ins.mnemonic=="b":
            try: t=ins.operands[0].imm&M64
            except Exception: t=None
            if t is None or not (va<=t<limit): return ins.address+4
    return limit

if __name__=="__main__":
    for a in sys.argv[1:]:
        va=int(a,0); e=find_end(va)
        print(f"== {va:#x}..{e:#x}")
        for ins_va,sva,s in strings_in(va,e):
            print(f"   {ins_va:#x} -> {sva:#x}  {s!r}")
