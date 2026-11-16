#!/usr/bin/env python3
# find IOExternalMethodDispatch-like tables in __DATA_CONST (all alignments)
import struct, sys
from kc import Fileset
from vm import VM
KBASE=0xfffffff007004000

def dec(raw):
    if (raw>>62)&1: return ('bind', raw & 0xFFFFFF)
    t = raw & 0x7FFFFFFFFFF
    return ('rebase', KBASE + t)

def code_ok(v, va):
    o=v.owner(va)
    return bool(o and o[1] in ('__TEXT_EXEC','__TEXT'))

def entry(v, a):
    raw=v.u64(a)
    if not raw: return None
    kind,t = dec(raw)
    if kind!='rebase' or t%4 or not code_ok(v,t): return None
    b=v.read(a+8,16)
    if not b: return None
    vals=struct.unpack('<IIII', b)
    for x in vals:
        if x!=0xffffffff and x>0x10000: return None
    return (t,)+vals

def tables(v, lo, hi, stride):
    out=[]
    a=lo
    while a+stride<=hi:
        e=entry(v,a)
        if e:
            run=[(a,e)]
            b=a+stride
            while b+stride<=hi:
                e2=entry(v,b)
                if not e2: break
                run.append((b,e2)); b+=stride
            if len(run)>=2:
                out.append(run)
            a=b
        else:
            a+=8
    return out

if __name__=='__main__':
    fs=Fileset(); v=VM(fs)
    for eid in (sys.argv[1].split(',') if len(sys.argv)>1 else ['com.apple.AGXG14P']):
        m=fs.get(eid)
        for s in m.segs:
            if s.name=='__DATA_CONST':
                lo,hi=s.vmaddr,s.vmaddr+s.filesize
                for stride in (0x18,0x28):
                    for run in tables(v,lo,hi,stride):
                        print(f"== {eid} stride={stride:#x} table={run[0][0]:#x} n={len(run)}")
                        for a,e in run:
                            print(f"   {a:#x} fn={e[0]:#x} chk={e[1:]} owner={v.owner(e[0])[1]}")
