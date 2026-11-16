import struct
from kdis import *

def find_trampolines(slots):
    """slots: set of VA of GOT slots. return {trampoline_va: slot_va}"""
    want=set(slots); out={}
    for r in RANGES:
        if r[4]!='__TEXT_EXEC': continue
        base,vm,fz=r[2],r[0],r[1]-r[0]
        buf=D[base:base+fz]
        n=len(buf)//4
        for i in range(n):
            w=struct.unpack_from('<I',buf,i*4)[0]
            if (w & 0x9F00001F)!=0x90000011: continue
            pc=vm+i*4
            code=buf[i*4:i*4+16]
            ins=list(md.disasm(code,pc))
            if len(ins)<3: continue
            if ins[0].mnemonic!='adrp' or ins[1].mnemonic!='add': continue
            try:
                pg=ins[0].operands[1].imm & MASK
                off=ins[1].operands[2].imm
            except Exception: continue
            if (pg+off) in want:
                out[pc]=pg+off
    return out
