#!/usr/bin/env python3
# full class inventory: name, metaclass VA, size, superclass cell, kext
import json, sys
from kc import Fileset
from vm import VM, disasm
from fixdec import dec

def build(v):
    out=[]
    for eid, vmaddr, fo in v.fs.entries:
        m=v.fs.get(eid)
        if not m: continue
        seg=[s for s in m.segs if s.name=='__TEXT_EXEC']
        if not seg: continue
        s=seg[0]
        adrp={}; regs={}; prev=None
        try:
            ins=list(disasm(v,s.vmaddr,nbytes=s.filesize))
        except Exception:
            continue
        for x in ins:
            m_=x.mnemonic
            if m_=='adrp':
                reg=x.op_str.split(',')[0].strip(); t=None
                for op in x.operands:
                    if op.type==2: t=op.imm & 0xFFFFFFFFFFFFFFFF
                adrp[reg]=t
            elif m_=='add':
                parts=[y.strip() for y in x.op_str.split(',')]
                if len(parts)==3 and parts[1] in adrp:
                    for op in x.operands[2:]:
                        if op.type==2: regs[parts[0]]=(adrp[parts[1]]+op.imm)&0xFFFFFFFFFFFFFFFF
            elif m_=='ldr':
                parts=[y.strip() for y in x.op_str.split(',')]
                if len(parts)==3 and parts[1].startswith('['):
                    base=parts[1].strip('[]')
                    if base in adrp:
                        imm=0
                        for op in x.operands[2:]:
                            if op.type==2: imm=op.imm
                        t=(adrp[base]+imm)&0xFFFFFFFFFFFFFFFF
                        val=v.u64(t)
                        regs[parts[0]]=val if val is not None else 0
            elif m_=='mov' and x.op_str.startswith('w3, #'):
                try: regs['w3']=int(x.op_str.split('#')[1],16)
                except: pass
            elif m_=='bl' and prev and prev.mnemonic=='mov' and prev.op_str.startswith('w3, #'):
                name=regs.get('x1'); meta=regs.get('x0'); size=regs.get('w3'); sup=regs.get('x2')
                if name and meta:
                    sname=v.cstr(name,120)
                    if sname and sname[0].isalpha() and len(sname)<100 and ' ' not in sname:
                        out.append(dict(eid=eid, site=x.address, meta=meta, name=sname, size=size, sup=sup))
            prev=x
    return out

if __name__=='__main__':
    fs=Fileset(); v=VM(fs)
    rows=build(v)
    json.dump(rows, open('/home/femboychik/work/agx_queue/classes.json','w'), indent=0)
    for r in rows: print(f"{r['meta']:#x} {r['size']:#x} {r['name']:45s} {r['eid']}")
    print(len(rows))
