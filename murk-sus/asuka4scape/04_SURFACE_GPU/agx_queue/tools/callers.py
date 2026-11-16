#!/usr/bin/env python3
# find callers (bl/b) of a VA across chosen kexts
import sys
from kc import Fileset
from vm import VM, disasm

def callers(v, targets, eids=None):
    res=[]
    eids = eids or [e for e,_,_ in v.fs.entries]
    for eid in eids:
        m=v.fs.get(eid)
        if not m: continue
        for s in m.segs:
            if s.name not in ('__TEXT_EXEC',): continue
            adrp={}
            for ins in disasm(v,s.vmaddr,nbytes=s.filesize):
                if ins.mnemonic in ('bl','b'):
                    t=None
                    for op in ins.operands:
                        if op.type==2: t=op.imm & 0xFFFFFFFFFFFFFFFF
                    if t in targets:
                        res.append((ins.address,t,eid))
    return res

if __name__=='__main__':
    fs=Fileset(); v=VM(fs)
    tg={int(x,16) for x in sys.argv[1:]}
    for a,t,e in callers(v,tg):
        print(f"{a:#x} -> {t:#x}  {e}")
