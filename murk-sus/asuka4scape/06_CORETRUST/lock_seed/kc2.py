#!/usr/bin/env python3
"""IOSurface lock/seed/mapping audit helpers — kernelcache 27.2 24B115."""
import struct, bisect
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from capstone.arm64 import ARM64_OP_REG, ARM64_OP_MEM, ARM64_OP_IMM

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
TEXT = next(s for s in SEGS if s[0] == "__TEXT_EXEC")

def va2off(va):
    va &= 0xFFFFFFFFFFFFFFFF
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
    return BLOB[va2off(va):va2off(va)+n]

def u64(va): return struct.unpack("<Q", rd(va, 8))[0]
def u32(va): return struct.unpack("<I", rd(va, 4))[0]

def pac(v):
    if v == 0: return 0
    return 0xfffffff007004000 + (v & 0x0FFFFFFF)

MD = Cs(CS_ARCH_ARM64, CS_MODE_ARM); MD.detail = True

def dis(va, n=1, stop_ret=False):
    out = []
    for i in range(n):
        a = va + i*4
        try: chunk = BLOB[va2off(a):va2off(a)+4]
        except ValueError: break
        ins = next(MD.disasm(chunk, a), None)
        if ins is None: break
        out.append((a, ins))
        if stop_ret and ins.mnemonic == "ret": break
    return out

def show(va, n=40, stop_ret=True):
    for a, i in dis(va, n, stop_ret=False):
        print(f"{a:016x}: {i.mnemonic:8s} {i.op_str}")
        if stop_ret and i.mnemonic == "ret": break

def target(ins):
    for op in ins.operands:
        if op.type == ARM64_OP_IMM:
            return op.imm & 0xFFFFFFFFFFFFFFFF
    return None

def memoff(ins):
    """return first memory operand disp (may be negative) or None"""
    for op in ins.operands:
        if op.type == ARM64_OP_MEM:
            d = op.mem.disp
            if d & (1 << 63): d -= (1 << 64)
            return d
    return None

def regs(ins):
    return [op.reg for op in ins.operands if op.type == ARM64_OP_REG]

def find_functions():
    """split __TEXT_EXEC into bti-c..pacibsp functions."""
    lo, hi = TEXT[1], TEXT[1] + TEXT[4]
    starts = []
    o = va2off(lo)
    a = lo
    # scan 4-byte aligned instructions
    for a in range(lo, hi, 4):
        if BLOB[va2off(a):va2off(a)+4] == b"\x5f\x24\x03\xd5":  # bti c
            nxt = BLOB[va2off(a+4):va2off(a+8)]
            if nxt in (b"\x7f\x23\x03\xd5",):  # pacibsp follows
                starts.append(a)
    return starts

# IOSurface kext hot region observed from prior work
IOS_LO, IOS_HI = 0xfffffff009c00000, 0xfffffff009c60000
