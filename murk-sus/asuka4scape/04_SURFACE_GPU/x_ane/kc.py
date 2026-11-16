#!/usr/bin/env python3
"""kernelcache helper for x_ane: segments, VA<->file, capstone arm64."""
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
BYNAME = {s[0]: s for s in SEGS}

def va2off(va):
    va &= 0xFFFFFFFFFFFFFFFF
    for name, vmaddr, vmsize, fileoff, filesize in SEGS:
        if vmaddr <= va < vmaddr + filesize:
            return fileoff + (va - vmaddr)
    raise ValueError("va2off " + hex(va))

def off2va(off):
    for name, vmaddr, vmsize, fileoff, filesize in SEGS:
        if fileoff <= off < fileoff + filesize:
            return vmaddr + (off - fileoff)
    raise ValueError("off2va " + hex(off))

def inrange(va):
    try:
        va2off(va); return True
    except ValueError:
        return False

def rd(va, n):
    return BLOB[va2off(va):va2off(va)+n]

def u64(va): return struct.unpack("<Q", rd(va, 8))[0]
def u32(va): return struct.unpack("<I", rd(va, 4))[0]

def cstr(va, maxn=256):
    o = va2off(va)
    e = BLOB.find(b"\0", o)
    return BLOB[o:e][:maxn].decode("utf-8", "replace")

def pac(va):
    """PAC-signed non-chained pointer -> VA"""
    if va == 0: return 0
    return 0xfffffff007004000 + (va & 0x0FFFFFFF)

def is_pac(p):
    return (p >> 32) in (0xffffffe0, 0xfffffff0, 0xffffffd0, 0xfffffff1) or (p & 0xFFFFFFFF00000000) != 0

MD = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
MD.detail = True

def dis(va, n=1, maxbytes=None, stop_ret=False):
    out = []
    off = 0
    limit = maxbytes if maxbytes else n * 4
    while off < limit:
        try:
            chunk = BLOB[va2off(va+off): va2off(va+off)+4]
        except ValueError:
            break
        if len(chunk) < 4: break
        ins = next(MD.disasm(chunk, va+off), None)
        if ins is None: break
        out.append((va+off, ins))
        off += 4
        if stop_ret and ins.mnemonic == "ret" and off >= 8:
            break
    return out

def fmt(va, ins):
    return f"{va:016x}: {ins.mnemonic:8s} {ins.op_str}"

def dump(va, n=20, maxbytes=None, stop_ret=False, indent=""):
    for a, i in dis(va, n, maxbytes, stop_ret):
        print(indent + fmt(a, i))

# ---- generic instruction semantics -------------------------------------
def adrp_page(ins, pc):
    """capstone adrp imm is SIGNED page delta*4096 from pc page -> mask"""
    imm = ins.operands[1].imm
    return (pc & ~0xFFF) + (imm & 0xFFFFFFFFFFFFFFFF)

def sext32(v):
    """deprecated shim"""
    return v

def _sx(v, bits):
    m = 1 << (bits - 1)
    v &= (1 << bits) - 1
    return v - (1 << bits) if v & m else v

def branch_target(pc, word=None):
    """decode b/bl/b.cond/cbz/tbz/ldr-literal/adr/adrp target from the RAW word.
    capstone 5 mis-sign-extends 26/19-bit offsets, so never trust its imm here."""
    if word is None:
        word = struct.unpack_from("<I", BLOB, va2off(pc))[0]
    w = word
    if (w & 0x7C000000) == 0x14000000:            # b
        return (pc + _sx(w & 0x3FFFFFF, 26) * 4) & 0xFFFFFFFFFFFFFFFF
    if (w & 0xFC000000) == 0x94000000:            # bl
        return (pc + _sx(w & 0x3FFFFFF, 26) * 4) & 0xFFFFFFFFFFFFFFFF
    if (w & 0xFF000010) == 0x54000000:            # b.cond
        return (pc + _sx((w >> 5) & 0x7FFFF, 19) * 4) & 0xFFFFFFFFFFFFFFFF
    if (w & 0x7E000000) == 0x34000000:            # cbz/cbnz
        return (pc + _sx((w >> 5) & 0x7FFFF, 19) * 4) & 0xFFFFFFFFFFFFFFFF
    if (w & 0x7E000000) == 0x36000000:            # tbz/tbnz
        return (pc + _sx((w >> 5) & 0x3FFF, 14) * 4) & 0xFFFFFFFFFFFFFFFF
    if (w & 0x3B000000) == 0x18000000:            # ldr literal
        return (pc + _sx((w >> 5) & 0x7FFFF, 19) * 4) & 0xFFFFFFFFFFFFFFFF
    if (w & 0x9F000000) == 0x90000000:            # adrp
        immlo = (w >> 29) & 3
        immhi = (w >> 5) & 0x7FFFF
        delta = _sx((immhi << 2) | immlo, 21) << 12
        return ((pc & ~0xFFF) + delta) & 0xFFFFFFFFFFFFFFFF
    if (w & 0x9F000000) == 0x10000000:            # adr
        immlo = (w >> 29) & 3
        immhi = (w >> 5) & 0x7FFFF
        return (pc + _sx((immhi << 2) | immlo, 21)) & 0xFFFFFFFFFFFFFFFF
    return None

def adr_or_adrp_target(ins, pc):
    return branch_target(pc)

def b_target(ins, pc):
    return branch_target(pc)

def ldr_literal_target(ins, pc):
    return branch_target(pc)

REG = {1:"x1",2:"x2",3:"x3",4:"x4",5:"x5",6:"x6",7:"x7",8:"x8",0:"x0",
       9:"x9",10:"x10",11:"x11",12:"x12",13:"x13",14:"x14",15:"x15",
       16:"x16",17:"x17",18:"x18",19:"x19",20:"x20",21:"x21",22:"x22",
       23:"x23",24:"x24",25:"x25",26:"x26",27:"x27",28:"x28",29:"x29",30:"x30"}

if __name__ == "__main__":
    print("segments:")
    for s in SEGS:
        print(f"  {s[0]:16s} vm={s[1]:#018x} sz={s[3]:#x}/{s[4]:#x}")
