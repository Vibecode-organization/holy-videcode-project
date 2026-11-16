#!/usr/bin/env python3
# disasm helper for 27.2 kernelcache -- sign-extension masked
import struct, sys
from capstone import *
from capstone.arm64 import *

KC = "/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache"
BASE = 0xfffffff007004000
M64 = 0xFFFFFFFFFFFFFFFF

SEGS = [
    ("__TEXT",         0xfffffff007004000, 0x8000,    0x0),
    ("__PRELINK_TEXT", 0xfffffff00700c000, 0xbac000,  0x8000),
    ("__DATA_CONST",   0xfffffff007bb8000, 0x548000,  0xbb4000),
    ("__DATA_SPTM",    0xfffffff008100000, 0x4c000,   0x10fc000),
    ("__TEXT_EXEC",    0xfffffff00814c000, 0x2924000, 0x1148000),
    ("__TEXT_BOOT_EXEC",0xfffffff00aa70000,0x8000,    0x3a6c000),
    ("__PRELINK_INFO", 0xfffffff00aa78000, 0x23c000,  0x3a74000),
    ("__DATA",         0xfffffff00acb4000, 0x2b8000,  0x3cb0000),
    ("__LINKEDIT",     0xfffffff00af6c000, 0xb8000,   0x3f68000),
]

with open(KC, "rb") as f:
    DATA = f.read()

def va2off(va):
    va &= M64
    for n, s, sz, off in SEGS:
        if s <= va < s + sz:
            return off + (va - s)
    return None

def seg_of(va):
    va &= M64
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

def okptr(q):
    """is q a plausible kernel pointer into our image (pac or raw)? """
    if q is None: return None
    if (q >> 40) in (0xffffff, 0xfffff0, 0xfffff007):
        pass
    if 0xfffffff007000000 <= q <= 0xfffffff00b000000:
        return q
    p = pac(q)
    if va2off(p) is not None:
        return p
    return None

MD = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
MD.detail = True

def dis(va, n=0x400, count=0, stopret=True):
    off = va2off(va)
    if off is None:
        return []
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
    try:
        return ins.operands[0].imm & M64
    except Exception:
        return None

def adrp_imm(ins):
    try:
        return ins.operands[1].imm & M64
    except Exception:
        return None

def cstr(va, maxn=256):
    b = rd(va, maxn)
    if not b: return None
    z = b.find(b'\0')
    return b[:z].decode('utf-8', 'replace') if z >= 0 else None

def find_cstr(s):
    """locate string in __TEXT/__PRELINK_TEXT/__TEXT_EXEC, return VA"""
    if isinstance(s, str): s = s.encode()
    idx = 0
    hits = []
    while True:
        i = DATA.find(s, idx)
        if i < 0: break
        for n, sv, sz, off in SEGS:
            if off <= i < off + sz:
                hits.append(sv + (i - off))
                break
        idx = i + 1
    return hits

def xrefs_to(va, segs=("__TEXT_EXEC", "__TEXT", "__PRELINK_TEXT")):
    """find adrp+add pairs resolving to va; returns list of (insn_va, next_insn_va)"""
    out = []
    for n, sv, sz, off in SEGS:
        if n not in segs: continue
        start = off
        end = off + sz - 8
        base = sv
        p = start
        prev_adrp = None
        prev_adrp_va = None
        while p < end:
            w = struct.unpack_from("<I", DATA, p)[0]
            # ADRP: 1xx10000...
            if (w & 0x9F000000) == 0x90000000:
                imm = ((w >> 29) & 3) | (((w >> 5) & 0x7FFFF) << 2)
                imm = (imm << 12) & M64
                # sign extend 33-bit
                if imm & (1 << 32):
                    imm |= 0xFFFFFFFE00000000
                page = ((p + start*0 - (p - start) + start) if False else 0)
                pc = base + (p - start)
                prev_adrp = ((pc & ~0xFFF) + imm) & M64
                prev_adrp_va = pc
                p += 4
                continue
            if (w & 0xFF800000) == 0x91000000 and prev_adrp is not None:
                # ADD (imm) 64-bit
                imm12 = (w >> 10) & 0xFFF
                sh = (w >> 22) & 1
                if sh: imm12 <<= 12
                tgt = (prev_adrp + imm12) & M64
                if tgt == (va & M64):
                    out.append((base + (p - start), prev_adrp_va))
            prev_adrp = None
            p += 4
    return out

if __name__ == "__main__":
    a = int(sys.argv[1], 0)
    n = int(sys.argv[2], 0) if len(sys.argv) > 2 else 0x400
    cnt = int(sys.argv[3], 0) if len(sys.argv) > 3 else 0
    show(a, n, cnt)
