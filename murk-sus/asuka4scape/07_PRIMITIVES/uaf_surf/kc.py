#!/usr/bin/env python3
"""kernelcache helper: mach-o segments, VA<->file, capstone arm64 disasm."""
import struct, sys
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from capstone.arm64 import ARM64_OP_IMM, ARM64_OP_MEM, ARM64_OP_REG, ARM64_OP_REG

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

def pac(va):
    """resolve a PAC-signed pointer value (non-chained) to a VA"""
    if va == 0:
        return 0
    return 0xfffffff007004000 + (va & 0x0FFFFFFF)

MD = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
MD.detail = True

def dis(va, n=1, stop_ret=False, maxbytes=None):
    """disassemble n instructions from va; returns list of (va, insn)."""
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

def fmt_ins(va, ins):
    s = f"{va:016x}: {ins.mnemonic:8s} {ins.op_str}"
    return s

def show(va, n=40, stop_ret=True):
    for a, i in dis(va, n, stop_ret=False):
        print(f"{a:016x}: {i.mnemonic:8s} {i.op_str}")
        if stop_ret and i.mnemonic == "ret":
            break

def target(ins):
    """imm target for b/bl/cbz/tbz/adr/adrp etc, sign-masked."""
    for op in ins.operands:
        if op.type == ARM64_OP_IMM:
            return op.imm & 0xFFFFFFFFFFFFFFFF
    return None

if __name__ == "__main__":
    for s in SEGS:
        print(s[0], hex(s[1]), hex(s[2]), hex(s[3]), hex(s[4]))
    print("text_exec", [hex(x) for x in TEXTEXEC[1:3]])
