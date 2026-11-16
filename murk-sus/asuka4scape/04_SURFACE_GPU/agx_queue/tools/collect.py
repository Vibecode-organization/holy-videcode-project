#!/usr/bin/env python3
# collect all adrp+add/ldr materialized addresses inside a code range
import sys
from kc import Fileset
from vm import VM, disasm

def collect(v, start, end, pred):
    """returns dict va -> list of insn addrs that materialize it"""
    res={}
    adrp={}
    for ins in disasm(v, start, nbytes=end-start):
        if ins.mnemonic=='adrp':
            reg=ins.op_str.split(',')[0].strip()
            t=None
            for op in ins.operands:
                if op.type==2: t=op.imm & 0xFFFFFFFFFFFFFFFF
            adrp[reg]=t
            continue
        if ins.mnemonic in ('add','sub','ldr','ldrb','ldrh','ldrsw','ldur','str','stp','ldp','cmp','movk'):
            parts=[p.strip() for p in ins.op_str.split(',')]
            if len(parts)<2: continue
            base=parts[1].strip('[] ')
            if base!='sp' and base not in adrp: continue
            imm=None
            for op in ins.operands:
                if op.type==2 and not (op.imm is None): imm=op.imm
            if imm is None: continue
            b = 0 if base=='sp' else adrp[base]
            t=(b+imm)&0xFFFFFFFFFFFFFFFF
            if pred(t):
                res.setdefault(t,[]).append((ins.address, ins.mnemonic, ins.op_str))
    return res
