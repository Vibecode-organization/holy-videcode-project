#!/usr/bin/env python3
"""27.2 (24B115) kernelcache helper. flat image: fileoff == va - BASE.
capstone arm64, sign-extended immediates masked to 64 bit."""
import struct
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from capstone.arm64 import ARM64_OP_IMM, ARM64_OP_MEM, ARM64_OP_REG

P = "/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache"
BASE = 0xfffffff007004000
M64 = 0xFFFFFFFFFFFFFFFF
D = open(P, "rb").read()

def va2off(v):
    v &= M64
    o = v - BASE
    if 0 <= o < len(D):
        return o
    return None

def off2va(o):
    return BASE + o

def rd(v, n):
    o = va2off(v)
    return None if o is None else D[o:o+n]

def u32(v):
    b = rd(v, 4)
    return None if not b or len(b) < 4 else struct.unpack("<I", b)[0]

def u64(v):
    b = rd(v, 8)
    return None if not b or len(b) < 8 else struct.unpack("<Q", b)[0]

def s32(v):
    b = rd(v, 4)
    return None if not b or len(b) < 4 else struct.unpack("<i", b)[0]

def pac(q):
    return (BASE + (q & 0x0FFFFFFF)) & M64

def cstr(v, n=300):
    b = rd(v, n)
    if not b:
        return None
    z = b.find(b"\0")
    return b[:z].decode("utf-8", "replace") if z >= 0 else None

MD = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
MD.detail = True

def dis(v, n=0x200, count=0, stopret=False):
    o = va2off(v)
    if o is None:
        return []
    out = []
    for i in MD.disasm(D[o:o+n], v & M64):
        out.append(i)
        if count and len(out) >= count:
            break
        if stopret and i.mnemonic == "ret":
            break
    return out

def fmti(i):
    return f"{i.address:016x}: {i.mnemonic:8s} {i.op_str}"

def show(v, n=0x200, count=0, stopret=False):
    for i in dis(v, n, count, stopret):
        print(fmti(i))

def tgt(i):
    if i.mnemonic in ("b", "bl", "cbz", "cbnz", "tbz", "tbnz", "adr"):
        try:
            return i.operands[0].imm & M64
        except Exception:
            return None
    return None

def adrp_page(i):
    try:
        return i.operands[1].imm & M64
    except Exception:
        return None

def reg(i, idx):
    try:
        return i.reg_name(i.operands[idx].reg)
    except Exception:
        return None

def mem(i, idx):
    """-> (base_reg, disp, index_reg, shift) for [xN, #imm] / [xN, xM, lsl #k]"""
    try:
        o = i.operands[idx]
        if o.type != ARM64_OP_MEM:
            return None
        base = i.reg_name(o.mem.base)
        idxr = i.reg_name(o.mem.index) if o.mem.index else None
        return (base, o.mem.disp, idxr, o.mem.lshift)
    except Exception:
        return None

def bls(v, n=0x400, stopret=True):
    """all bl targets in a function body -> [(site, target)]"""
    out = []
    for i in dis(v, n, stopret=stopret):
        if i.mnemonic in ("bl", "b"):
            t = tgt(i)
            if t is not None:
                out.append((i.address, t))
    return out

def strrefs(v, n=0x400):
    """adrp+add string refs in body -> [(site, str_va, string)]"""
    out = []
    page = None
    for i in dis(v, n):
        if i.mnemonic == "adrp":
            page = adrp_page(i)
            continue
        if i.mnemonic == "add" and page is not None:
            try:
                imm = i.operands[2].imm & M64
            except Exception:
                imm = None
            if imm is not None:
                t = (page + imm) & M64
                s = cstr(t)
                if s is not None:
                    out.append((i.address, t, s))
        page = None
    return out

def xrefs_add(target, start=None, end=None, step_scan=4):
    """find adrp+add pairs that resolve to target anywhere in image"""
    out = []
    lo = 0 if start is None else start - BASE
    hi = len(D) if end is None else end - BASE
    p = (lo // 4) * 4
    prev = None
    prev_va = None
    while p < hi:
        w = struct.unpack_from("<I", D, p)[0]
        if (w & 0x9F000000) == 0x90000000:  # adrp
            imm = ((w >> 29) & 3) | (((w >> 5) & 0x7FFFF) << 2)
            imm = (imm << 12) & M64
            if imm & (1 << 32):
                imm |= 0xFFFFFFFE00000000
            pc = BASE + p
            prev = ((pc & ~0xFFF) + imm) & M64
            prev_va = pc
            p += 4
            continue
        if (w & 0xFF800000) == 0x91000000 and prev is not None:
            imm12 = (w >> 10) & 0xFFF
            if (w >> 22) & 1:
                imm12 <<= 12
            if ((prev + imm12) & M64) == (target & M64):
                out.append((BASE + p, prev_va))
        prev = None
        p += 4
    return out

def find(s):
    b = s.encode() if isinstance(s, str) else s
    out = []
    i = 0
    while True:
        j = D.find(b, i)
        if j < 0:
            break
        out.append(BASE + j)
        i = j + 1
    return out

def func_start(v, back=0x800):
    """walk back for stp/pacibsp prologue boundary"""
    o = va2off(v)
    if o is None:
        return None
    for k in range(0, back, 4):
        w = struct.unpack_from("<I", D, o - k)[0]
        # pacibsp / paciasp / bti c
        if w in (0xD503233F, 0xD503237F):
            return BASE + o - k
        # stp x29, x30, [sp, #-N]!
        if (w & 0xFFC07FFF) == 0xA9807BFD:
            return BASE + o - k
    return None
