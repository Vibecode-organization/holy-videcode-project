#!/usr/bin/env python3
# Full instruction diff for one changed function pair, with all hunks.
# usage: funcdiff.py PA AA PB BA [maxhunks] [--raw]
import sys, struct, difflib, re
from capstone import *
from capstone.arm64 import *

def segs(path):
    d=open(path,'rb').read(); magic,ct,cs,ft,ncmds,sz,fl,_=struct.unpack_from('<IiiIIIII',d,0)
    p=32; out=[]
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
BR=('b','bl','adr','adrp','cbz','cbnz','tbz','tbnz')
def dis(d,s,a,n,norm=True):
    code=at(s,d,a,n); out=[]
    if not code: return out
    adrp={}
    for i in md.disasm(code,a):
        if i.id==0: out.append((i.address,'data')); continue
        ops=i.operands; p=[i.mnemonic]
        immvals=[]
        for op in ops:
            if op.type==ARM64_OP_REG: p.append('R')
            elif op.type==ARM64_OP_IMM:
                mn=i.mnemonic
                if norm: p.append('T' if (mn in BR or mn.startswith('b.')) else '#')
                else: p.append(hex(op.imm & 0xffffffffffffffff))
                immvals.append(op.imm)
            elif op.type==ARM64_OP_MEM:
                m=op.mem; x='[R'
                if m.index: x+='+R'
                if m.disp: x+=('+B' if abs(m.disp)>0x1000 else '+#%d'%m.disp)
                p.append(x+']')
            elif op.type==ARM64_OP_FP: p.append('F')
            else: p.append('?')
        s_=' '.join(p)
        if not norm:
            # resolve adrp
            if i.mnemonic=='adrp' and len(ops)==2 and ops[1].type==ARM64_OP_IMM:
                adrp[ops[0].reg]=ops[1].imm&0xffffffffffffffff
            elif i.mnemonic in ('add','ldr','str','ldrb','ldrh') and len(ops)==3 and ops[1].type==ARM64_OP_REG and ops[2].type==ARM64_OP_IMM and ops[1].reg in adrp:
                t=(adrp[ops[1].reg]+ops[2].imm)&0xffffffffffffffff
                s_+=f'  ;= {t:#x}'
            elif i.mnemonic in ('bl','b') and ops and ops[0].type==ARM64_OP_IMM:
                s_+=f'  ;-> {ops[0].imm:#x}'
        out.append((i.address,s_))
    return out

PA,AA,PB,BA=sys.argv[1],int(sys.argv[2],16),sys.argv[3],int(sys.argv[4],16)
ASZ=int(sys.argv[5],0) if len(sys.argv)>5 else 0x2000
BSZ=int(sys.argv[6],0) if len(sys.argv)>6 else 0x2000
MH=int(sys.argv[7]) if len(sys.argv)>7 else 1000
RAW=('--raw' in sys.argv)
da,sa=segs(PA); db,sb=segs(PB)
IA=dis(da,sa,AA,ASZ,norm=not RAW)
IB=dis(db,sb,BA,BSZ,norm=not RAW)
print(f'A {len(IA)} insns @ {AA:#x}; B {len(IB)} insns @ {BA:#x}')
sm=difflib.SequenceMatcher(None,[x[1] for x in IA],[x[1] for x in IB],autojunk=False)
n=0
for tag,i1,i2,j1,j2 in sm.get_opcodes():
    if tag=='equal': continue
    n+=1
    if n>MH: break
    print(f'== {tag} A@{IA[i1][0]:#x} ({i2-i1}) B@{IB[j1][0]:#x} ({j2-j1})')
    for k in range(max(i1-3,0),min(i2+3,len(IA))):
        mark='A' if i1<=k<i2 else ' '
        print(f'   {mark} {IA[k][0]:#x} {IA[k][1]}')
    for k in range(max(j1-3,0),min(j2+3,len(IB))):
        mark='B' if j1<=k<j2 else ' '
        print(f'   {mark} {IB[k][0]:#x} {IB[k][1]}')
