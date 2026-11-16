#!/usr/bin/env python3
# Raw disassembly with string and call annotation.
# usage: disr.py BIN START SIZE
import sys, struct
from capstone import *
from capstone.arm64 import *
path=sys.argv[1]; START=int(sys.argv[2],16); SIZE=int(sys.argv[3],16)
d=open(path,'rb').read(); magic,ct,cs,ft,ncmds,sz,fl,_=struct.unpack_from('<IiiIIIII',d,0)
p=32; segs=[]
for _ in range(ncmds):
    cmd,csz=struct.unpack_from('<II',d,p)
    if cmd==0x19:
        nm=d[p+8:p+24].split(b'\0')[0].decode(); vm,vs,fo,fs=struct.unpack_from('<QQQQ',d,p+24); segs.append((nm,vm,vs,fo,fs))
    p+=csz
def read(a,n):
    for nm,vm,vs,fo,fs in segs:
        if vm<=a and a+n<=vm+vs and fs: return d[fo+a-vm:fo+a-vm+n]
    return None
# strings
strs={}
for nm,vm,vs,fo,fs in segs:
    if fs==0 or nm in ('__TEXT_EXEC','__TEXT','__TEXT_BOOT_EXEC'): continue
    blob=d[fo:fo+fs]; i=0
    while i<len(blob):
        j=i
        while j<len(blob) and 32<=blob[j]<127: j+=1
        if j-i>=5: strs[vm+i]=blob[i:j].decode('ascii','replace')
        i=max(j,i+1)
md=Cs(CS_ARCH_ARM64,CS_MODE_LITTLE_ENDIAN); md.detail=True; md.skipdata=True
adrp={}; code=read(START,SIZE) or b''
for i in md.disasm(code,START):
    if i.id==0: print(f'{i.address:#x} data'); continue
    ops=i.operands; extra=''
    if i.mnemonic=='adrp' and len(ops)==2 and ops[1].type==ARM64_OP_IMM:
        adrp[ops[0].reg]=ops[1].imm & 0xffffffffffffffff
    elif i.mnemonic in ('add','ldr','str','ldrb','ldrh','ldrsw','stur') and len(ops)>=3 and ops[1].type==ARM64_OP_REG and ops[2].type==ARM64_OP_IMM and ops[1].reg in adrp:
        t=(adrp[ops[1].reg]+ops[2].imm)&0xffffffffffffffff
        if t in strs: extra=' ; "'+strs[t][:80]+'"'
        else: extra=f' ; {t:#x}'
    elif i.mnemonic in ('bl','b') and ops and ops[0].type==ARM64_OP_IMM:
        extra=f' ; -> {ops[0].imm & 0xffffffffffffffff:#x}'
    print(f'{i.address:#x}: {i.mnemonic}\t{i.op_str}{extra}')
