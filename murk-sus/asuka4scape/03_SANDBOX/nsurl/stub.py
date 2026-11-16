#!/usr/bin/env python3
# resolve an __objc_stubs selector stub -> SEL string
import sys, struct, lief
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM

b = lief.MachO.parse("bin/nsurlsessiond").at(0)
def c(va,n):
    try: return bytes(b.get_content_from_virtual_address(va,n))
    except Exception: return b''
def u64(va):
    d=c(va,8); return struct.unpack("<Q",d)[0] if len(d)==8 else 0
def cp(v): return 0x100000000+(v&0xffffffff)
def cstr(va):
    out=b''
    while True:
        d=c(va,1)
        if not d or d[0]==0: break
        out+=d; va+=1
    return out.decode('utf-8','replace')
md=Cs(CS_ARCH_ARM64,CS_MODE_ARM); md.detail=True
for arg in sys.argv[1:]:
    a=int(arg,16)
    code=c(a,12)
    page=None; off=None
    for ins in md.disasm(code,a):
        if ins.mnemonic=='adrp' and ins.reg_name(ins.operands[0].reg)=='x1':
            page=ins.operands[1].imm
        elif ins.mnemonic=='ldr' and ins.reg_name(ins.operands[1].mem.base)=='x1':
            off=ins.operands[1].mem.disp
    if page is not None and off is not None:
        slot=page+off
        p=cp(u64(slot))
        print(hex(a),'-> stub sel:',cstr(p) if p else None,'slot',hex(slot))
    else:
        print(hex(a),'no adrp/ldr', [f"{i.mnemonic} {i.op_str}" for i in md.disasm(code,a)])
