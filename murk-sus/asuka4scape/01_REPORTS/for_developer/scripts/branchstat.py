#!/usr/bin/env python3
import sys,re,struct
from capstone import *
from capstone.arm64 import *
REPORT,PA,PB=sys.argv[1],sys.argv[2],sys.argv[3]
def segs(path):
    d=open(path,'rb').read(); magic,ct,cs,ft,ncmds,sz,fl,_=struct.unpack_from('<IiiIIIII',d,0)
    p=32;out=[]
    for _ in range(ncmds):
        cmd,csz=struct.unpack_from('<II',d,p)
        if cmd==0x19:
            nm=d[p+8:p+24].split(b'\0')[0].decode(); vm,vs,fo,fs=struct.unpack_from('<QQQQ',d,p+24); out.append((nm,vm,vs,fo,fs))
        p+=csz
    return d,out
def at(s,d,a,n):
    for nm,vm,vs,fo,fs in s:
        if vm<=a and a+n<=vm+vs and fs: return d[fo+(a-vm):fo+(a-vm)+n]
    return None
md=Cs(CS_ARCH_ARM64,CS_MODE_LITTLE_ENDIAN); md.detail=True; md.skipdata=True
COND=set()
for c in ['eq','ne','cs','hs','cc','lo','mi','pl','vs','vc','hi','ls','ge','lt','gt','le','al']:
    COND.add('b.'+c)
COND.update(['cbz','cbnz','tbz','tbnz'])
def stats(d,s,a,n):
    code=at(s,d,a,n); nb=ni=0
    if not code: return (0,0)
    for i in md.disasm(code,a):
        if i.id==0: continue
        ni+=1
        if i.mnemonic in COND: nb+=1
    return ni,nb
lines=open(REPORT).read().splitlines()
pairs=[]
for l in lines:
    m=re.match(r'=== (0x[0-9a-f]+) \((\d+)\) -> (0x[0-9a-f]+) \((\d+)\) d=([+-]\d+) insn (\d+)->(\d+) hunks=(\d+)',l)
    if m: pairs.append(tuple(int(x,16) if x.startswith('0x') else int(x) for x in m.groups()))
da,sa=segs(PA); db,sb=segs(PB)
res=[]
for a,asz,b,bsz,d,h,ni0,ni1 in pairs:
    nia,nba=stats(da,sa,a,asz); nib,nbb=stats(db,sb,b,bsz)
    res.append((nbb-nba,b,a,d,nba,nbb,nia,nib))
res.sort(reverse=True)
for dbr,b,a,d,nba,nbb,nia,nib in res:
    if dbr>=1 and d>=0:
        print(f'B {b:#x} A {a:#x} d={d:+5d} br {nba}->{nbb} (+{dbr}) insn {nia}->{nib}')
