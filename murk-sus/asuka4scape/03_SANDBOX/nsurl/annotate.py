#!/usr/bin/env python3
# annotate disassembly window: resolve __objc_stubs calls to selector names
import sys, re, struct, lief, bisect
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM

b = lief.MachO.parse("bin/nsurlsessiond").at(0)
def c(va,n):
    try: return bytes(b.get_content_from_virtual_address(va,n))
    except Exception: return b""
def u64(va):
    d=c(va,8); return struct.unpack("<Q",d)[0] if len(d)==8 else 0
def cp(v):
    if v==0: return 0
    t=0x100000000+(v&0xffffffff)
    return t if 0x100000000<=t<0x100200000 else 0
def cstr(va):
    out=bytearray()
    while va and len(out)<256:
        d=c(va,1)
        if not d or d[0]==0: break
        out.append(d[0]); va+=1
    return out.decode('utf-8','replace')
md=Cs(CS_ARCH_ARM64,CS_MODE_ARM); md.detail=True
cache={}
def sel_at(va):
    if va in cache: return cache[va]
    page=None; off=None
    for ins in md.disasm(c(va,16),va):
        if ins.mnemonic=='adrp' and ins.reg_name(ins.operands[0].reg)=='x1':
            page=ins.operands[1].imm
        elif ins.mnemonic=='ldr' and ins.reg_name(ins.operands[1].mem.base)=='x1':
            off=ins.operands[1].mem.disp
    s = cstr(cp(u64(page+off))) if page is not None and off is not None else None
    cache[va]=s
    return s
lines=open("disasm.txt",encoding="utf-8",errors="replace").read().splitlines()
ins={}
for ln in lines:
    m=re.match(r'^\s*([0-9a-f]{6,}):\t(.*)$',ln)
    if m: ins[int(m.group(1),16)]=m.group(2)
order=sorted(ins)
start=int(sys.argv[1],16); count=int(sys.argv[2]) if len(sys.argv)>2 else 60
i=bisect.bisect_left(order,start)
for a in order[i:i+count]:
    t=ins[a]; extra=""
    m=re.search(r'\bbl\s+(0x[0-9a-f]+)',t)
    if m:
        tgt=int(m.group(1),16)
        if 0x1000875c0 <= tgt < 0x100092120:
            s=sel_at(tgt)
            if s: extra=" ; SEL "+s
    print(f"{a:#x}:\t{t}{extra}")
