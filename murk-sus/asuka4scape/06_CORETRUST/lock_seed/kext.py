#!/usr/bin/env python3
"""xref strings in com.apple.iokit.IOSurface kext (standalone binary, 27.2)."""
import struct, sys, re
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from capstone.arm64 import ARM64_OP_IMM, ARM64_OP_REG, ARM64_OP_MEM

P = "/home/femboychik/work/ios272/com.apple.iokit.IOSurface"
D = open(P, "rb").read()
ncmds = struct.unpack_from("<I", D, 16)[0]
off = 32
SEGS = []
for _ in range(ncmds):
    cmd, size = struct.unpack_from("<II", D, off)
    if cmd == 0x19:
        nm = D[off+8:off+24].split(b"\0")[0].decode()
        va, vs, fo, fs = struct.unpack_from("<QQQQ", D, off+24)
        SEGS.append((nm, va, vs, fo, fs))
    off += size
TEXT = next(s for s in SEGS if s[0] == "__TEXT_EXEC")

def va2off(va):
    for nm, va0, vs, fo, fs in SEGS:
        if va0 <= va < va0 + fs:
            return fo + (va - va0)
    raise ValueError(hex(va))

def off2va(o):
    for nm, va0, vs, fo, fs in SEGS:
        if fo <= o < fo + fs:
            return va0 + (o - fo)
    raise ValueError(hex(o))

MD = Cs(CS_ARCH_ARM64, CS_MODE_ARM); MD.detail = True

def ins_at(va):
    try: b = D[va2off(va):va2off(va)+4]
    except ValueError: return None
    return next(MD.disasm(b, va), None) if len(b) == 4 else None

def find_str(pat):
    out = []
    for m in re.finditer(re.escape(pat.encode() if isinstance(pat, str) else pat), D):
        start = D.rfind(b"\0", 0, m.start()) + 1
        out.append((start, off2va(start), D[start:start+120].split(b"\0")[0]))
    return out

def xrefs(strva, lo=None, hi=None):
    """scan for adrp+add (or adrp+ldr) pairs pointing at strva"""
    lo = lo or TEXT[1]; hi = hi or TEXT[1] + TEXT[4]
    hits = []
    adrp = {}
    for a in range(lo, hi, 4):
        i = ins_at(a)
        if i is None: continue
        if i.mnemonic == "adrp":
            rd = i.operands[0].reg
            imm = i.operands[1].imm & 0xFFFFFFFFFFFFFFFF
            adrp[rd] = imm
        elif i.mnemonic == "add" and len(i.operands) >= 3 and i.operands[1].type == ARM64_OP_REG and i.operands[2].type == ARM64_OP_IMM:
            base = adrp.get(i.operands[1].reg)
            if base is not None:
                val = (base + (i.operands[2].imm & 0xFFFFFFFFFFFFFFFF)) & 0xFFFFFFFFFFFFFFFF
                if val == strva:
                    hits.append(a)
    return hits

if __name__ == "__main__":
    pat = sys.argv[1] if len(sys.argv) > 1 else None
    if not pat:
        for nm, va, vs, fo, fs in SEGS: print(nm, hex(va), hex(fo), hex(fs))
        sys.exit(0)
    for o, va, s in find_str(pat):
        print(f"str {va:#x} off {o:#x}: {s!r}")
        for h in xrefs(va):
            print("   xref", hex(h))
