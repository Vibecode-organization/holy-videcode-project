#!/usr/bin/env python3
# build pseudo-symbol map from __assert_rtn call sites: (file,line,funcsig) -> code addr
import re, bisect, sys
from kc import Fileset
from vm import VM, disasm

ASSERT = 0xfffffff008217030
KBASE=0xfffffff007004000

def build(v, eid):
    m=v.fs.get(eid)
    seg=[s for s in m.segs if s.name=='__TEXT_EXEC'][0]
    start,end=seg.vmaddr,seg.vmaddr+seg.filesize
    ins=list(disasm(v,start,nbytes=end-start))
    idx={i.address:k for k,i in enumerate(ins)}
    out=[]
    for k,i in enumerate(ins):
        if i.mnemonic=='bl':
            t=None
            for op in i.operands:
                if op.type==2: t=op.imm & 0xFFFFFFFFFFFFFFFF
            if t!=ASSERT: continue
            # walk back up to 20 insns, track adrp regs
            adrp={}; strings=[]
            line=None
            for j in range(k-1, max(k-25,0), -1):
                p=ins[j]
                if p.mnemonic=='adrp':
                    reg=p.op_str.split(',')[0].strip(); tt=None
                    for op in p.operands:
                        if op.type==2: tt=op.imm & 0xFFFFFFFFFFFFFFFF
                    adrp[reg]=tt
                elif p.mnemonic=='add':
                    parts=[x.strip() for x in p.op_str.split(',')]
                    if len(parts)>=3 and parts[1] in adrp:
                        for op in p.operands:
                            if op.type==2:
                                t2=(adrp[parts[1]]+op.imm)&0xFFFFFFFFFFFFFFFF
                                s=v.cstr(t2, 300)
                                if s and len(s)>2: strings.append(s)
                elif p.mnemonic=='mov' and line is None:
                    mm=re.match(r'w\d+, #0x([0-9a-f]+)', p.op_str)
                    if mm: line=int(mm.group(1),16)
            fn=None; file=None
            for s in strings:
                if ('.h' in s or '.cpp' in s) and ' ' not in s: file=s
                elif '(' in s or '::' in s: fn=s
            out.append((i.address,file,line,fn,strings))
    return out

if __name__=='__main__':
    fs=Fileset(); v=VM(fs)
    rows=build(v, sys.argv[1] if len(sys.argv)>1 else 'com.apple.AGXG14P')
    for a,f,l,fn,ss in rows:
        if fn and 'AGXCommandQueue' in fn:
            print(f"{a:#x} {f}:{l} {fn[:120]}")
    print(len(rows),"assert sites")
