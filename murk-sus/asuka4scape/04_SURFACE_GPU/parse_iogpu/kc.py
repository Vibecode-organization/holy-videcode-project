#!/usr/bin/env python3
# disasm helper for 27.2 kernelcache
import struct, sys
from capstone import *
from capstone.arm64 import *

KC = "/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache"
BASE = 0xfffffff007004000

SEGS = [
    # name, va, size, fileoff
    ("__TEXT",         0xfffffff007004000, 0x8000,    0x0),
    ("__PRELINK_TEXT", 0xfffffff00700c000, 0xbac000,  0x8000),
    ("__DATA_CONST",   0xfffffff007bb8000, 0x548000,  0xbb4000),
    ("__DATA",         0xfffffff00acb4000, 0x2b8000,  0x3cb0000),
    ("__TEXT_EXEC",    0xfffffff00814c000, 0x2924000, 0x1148000),
    ("__PRELINK_INFO", 0xfffffff00aa78000, 0x23c000,  0x3a74000),
]

with open(KC, "rb") as f:
    DATA = f.read()

def va2off(va):
    for n, s, sz, off in SEGS:
        if s <= va < s + sz:
            return off + (va - s)
    return None

def seg_of(va):
    for n, s, sz, off in SEGS:
        if s <= va < s + sz:
            return n
    return None

def rd(va, n):
    o = va2off(va)
    if o is None: return None
    return DATA[o:o+n]

def u32(va):
    b = rd(va, 4)
    return struct.unpack("<I", b)[0] if b and len(b) == 4 else None

def u64(va):
    b = rd(va, 8)
    return struct.unpack("<Q", b)[0] if b and len(b) == 8 else None

def pac(q):
    return BASE + (q & 0x0FFFFFFF)

MD = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
MD.detail = True

def dis(va, n=0x400, count=0, stopret=True):
    off = va2off(va)
    if off is None:
        print("!! unmapped %#x" % va); return []
    code = DATA[off:off+n]
    out = []
    for i in MD.disasm(code, va):
        out.append(i)
        if count and len(out) >= count: break
        if stopret and i.mnemonic == "ret": break
    return out

def fmt(ins):
    return "%#012x  %-8s %s" % (ins.address, ins.mnemonic, ins.op_str)

def show(va, n=0x400, count=0, stopret=True):
    for i in dis(va, n, count, stopret):
        print(fmt(i))

def target(ins):
    """branch target, sign-extended"""
    try:
        return ins.operands[0].imm & 0xFFFFFFFFFFFFFFFF
    except Exception:
        return None

def adrp_imm(ins):
    try:
        return ins.operands[1].imm & 0xFFFFFFFFFFFFFFFF
    except Exception:
        return None

if __name__ == "__main__":
    va = int(sys.argv[1], 0)
    n = int(sys.argv[2], 0) if len(sys.argv) > 2 else 0x400
    show(va, n)
