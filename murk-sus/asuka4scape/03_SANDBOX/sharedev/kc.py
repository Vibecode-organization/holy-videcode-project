#!/usr/bin/env python3
"""kernelcache helper: mach-o segments, VA<->file, capstone arm64 disasm."""
import struct, sys
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from capstone.arm64 import ARM64_OP_IMM, ARM64_OP_MEM, ARM64_OP_REG

PATH = "/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache"
BLOB = open(PATH, "rb").read()

def parse_segments():
    ncmds = struct.unpack_from("<I", BLOB, 16)[0]
    off = 32
    segs = []
    for _ in range(ncmds):
        cmd, cmdsize = struct.unpack_from("<II", BLOB, off)
        if cmd == 0x19:
            name = BLOB[off+8:off+24].split(b"\0")[0].decode()
            vmaddr, vmsize, fileoff, filesize = struct.unpack_from("<QQQQ", BLOB, off+24)
            segs.append((name, vmaddr, vmsize, fileoff, filesize))
        off += cmdsize
    return segs

SEGS = parse_segments()
TEXTEXEC = next(s for s in SEGS if s[0] == "__TEXT_EXEC")
DATACONST = next(s for s in SEGS if s[0] == "__DATA_CONST")

def va2off(va):
    va &= 0xFFFFFFFFFFFFFFFF
    if va < 0x10000000:          # short form: 0x9c39868 -> 0xfffffff009c39868
        va += 0xFFFFFFF000000000
    for name, vmaddr, vmsize, fileoff, filesize in SEGS:
        if vmaddr <= va < vmaddr + filesize:
            return fileoff + (va - vmaddr)
    raise ValueError(hex(va))

def off2va(off):
    for name, vmaddr, vmsize, fileoff, filesize in SEGS:
        if fileoff <= off < fileoff + filesize:
            return vmaddr + (off - fileoff)
    raise ValueError(hex(off))

def rd(va, n):
    o = va2off(va)
    return BLOB[o:o+n]

def u64(va):
    return struct.unpack("<Q", rd(va, 8))[0]

def u32(va):
    return struct.unpack("<I", rd(va, 4))[0]

def u16(va):
    return struct.unpack("<H", rd(va, 2))[0]

def u8(va):
    return rd(va, 1)[0]

def pac(va):
    """resolve a PAC-signed pointer value (non-chained) to a VA"""
    if va == 0:
        return 0
    return 0xfffffff007004000 + (va & 0x0FFFFFFF)

MD = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
MD.detail = True

def dis(va, n=1, stop_ret=False, maxbytes=None):
    out = []
    off = 0
    limit = maxbytes if maxbytes else n * 4
    while off < limit:
        chunk = BLOB[va2off(va + off): va2off(va + off) + 4]
        if len(chunk) < 4:
            break
        ins = next(MD.disasm(chunk, va + off), None)
        if ins is None:
            break
        out.append((va + off, ins))
        off += 4
        if stop_ret and ins.mnemonic in ("ret",):
            break
    return out

def show(va, n=40, stop_ret=True):
    for a, i in dis(va, n, stop_ret=False):
        print(f"{a:016x}: {i.mnemonic:8s} {i.op_str}")
        if stop_ret and i.mnemonic == "ret":
            break

def target(ins):
    for op in ins.operands:
        if op.type == ARM64_OP_IMM:
            return op.imm & 0xFFFFFFFFFFFFFFFF
    return None

def cstr(va, maxlen=200):
    o = va2off(va)
    end = BLOB.index(b"\0", o)
    return BLOB[o:end][:maxlen].decode("utf-8", "replace")

def find_str(s):
    b = s.encode()
    out = []
    i = 0
    while True:
        i = BLOB.find(b, i)
        if i < 0:
            break
        out.append(off2va(i))
        i += 1
    return out

def xrefs_str(va):
    """find adrp+add pairs referencing va; returns list of (insn_va, reg)"""
    hits = []
    # adrp Xn, page ; add Xn, Xn, #off
    lo = TEXTEXEC[1]
    hi = TEXTEXEC[1] + TEXTEXEC[4]
    page = va & ~0xFFF
    off = va & 0xFFF
    blob = BLOB
    base_off = TEXTEXEC[3]
    for a in range(0, TEXTEXEC[4] - 8, 4):
        w = struct.unpack_from("<I", blob, base_off + a)[0]
        # adrp is 1xx10000 immhi immlo -> (w & 0x9F000000) == 0x90000000
        if (w & 0x9F000000) != 0x90000000:
            continue
        rd_ = w & 0x1F
        immlo = (w >> 29) & 3
        immhi = (w >> 5) & 0x7FFFF
        imm = (immhi << 2) | immlo
        if imm & (1 << 20):
            imm -= (1 << 21)
        insn_va = lo + a
        if ((insn_va & ~0xFFF) + (imm << 12)) & 0xFFFFFFFFFFFFFFFF != page:
            continue
        # next insn add
        w2 = struct.unpack_from("<I", blob, base_off + a + 4)[0]
        if (w2 & 0xFFC00000) != 0x91000000:
            continue
        rn = (w2 >> 5) & 0x1F
        rd2 = w2 & 0x1F
        imm12 = (w2 >> 10) & 0xFFF
        sh = (w2 >> 22) & 1
        if sh:
            imm12 <<= 12
        if rn != rd_ or imm12 != off:
            continue
        hits.append((insn_va, rd2))
    return hits

if __name__ == "__main__":
    for s in SEGS:
        print(s[0], hex(s[1]), hex(s[2]), hex(s[3]), hex(s[4]))
