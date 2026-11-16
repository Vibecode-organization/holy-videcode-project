#!/usr/bin/env python3
# dis.py -- kernelcache disassembly helper
# usage: ./dis.py VA [len]   |  ./dis.py --fn VA [maxlen]
import sys, struct
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM, CS_OP_IMM, CS_OP_REG, CS_OP_MEM

KC = "/home/femboychik/\u0420\u0430\u0431\u043e\u0447\u0438\u0439 \u0441\u0442\u043e\u043b/\u0434\u0438\u043f\u0441\u0438\u043a 1/kc/27.2_24B115_kernelcache"
BASE = 0xfffffff007004000
DATA_CONST_BASE = 0xfffffff007bb8000
DATA_CONST_OFF  = 0xbb4000
DATA_BASE = 0xfffffff00acb4000
DATA_OFF  = 0x3cb0000
TEXT_EXEC_BASE = 0xfffffff00814c000
TEXT_EXEC_OFF  = 0x1148000

_data = open(KC, "rb").read()

SEGS = [
    (0xfffffff007004000, 0x8000,     0x0),          # __TEXT
    (0xfffffff00700c000, 0xbac000,   0x8000),       # __PRELINK_TEXT
    (0xfffffff007bb8000, 0x548000,   0xbb4000),     # __DATA_CONST
    (0xfffffff00acb4000, 0x2b8000,   0x3cb0000),    # __DATA
    (0xfffffff00814c000, 0x2924000,  0x1148000),    # __TEXT_EXEC
    (0xfffffff00aa78000, 0x23c000,   0x3a74000),    # __PRELINK_INFO
]

def seg_of(va):
    for base, size, off in SEGS:
        if base <= va < base + size:
            return base, size, off
    return None

def read(va, n):
    s = seg_of(va)
    if not s:
        return b""
    base, size, off = s
    fo = off + (va - base)
    return _data[fo:fo+min(n, size - (va - base))]

def q(va):
    b = read(va, 8)
    return struct.unpack("<Q", b)[0] if len(b) == 8 else None

def d(va, n=4):
    return struct.unpack("<I", read(va,4))[0] if len(read(va,4))==4 else None

md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
md.detail = True

def pac(va_or_q):
    return BASE + (va_or_q & 0x0FFFFFFF)

def dis(va, length, label=""):
    code = read(va, length)
    out = []
    if label: out.append(f"; ---- {label} @ {va:#x} ----")
    for i in md.disasm(code, va):
        line = f"{i.address:#014x}: {i.mnemonic:<8} {i.op_str}"
        # annotate adrp/b targets
        for op in i.operands:
            if op.type == CS_OP_IMM:
                t = op.imm & 0xFFFFFFFFFFFFFFFF
                if t > 0xfffffff000000000:
                    line += f"   ; -> {t:#x}"
        out.append(line)
    return "\n".join(out)

def fn(va, maxlen=0x2000):
    """linear disasm from va until ret/brk end-of-function heuristic"""
    code = read(va, maxlen)
    out = []
    for i in md.disasm(code, va):
        out.append(f"{i.address:#014x}: {i.mnemonic:<8} {i.op_str}")
        if i.mnemonic in ("ret","brk","retaa","retab") and len(out) > 2:
            # peek next insn: if it's a new function prologue (stp x29,x30 or sub sp) continue is fine
            pass
    return "\n".join(out)

if __name__ == "__main__":
    if sys.argv[1] == "--fn":
        va = int(sys.argv[2],0); ln = int(sys.argv[3],0) if len(sys.argv)>3 else 0x2000
        print(fn(va,ln))
    else:
        va = int(sys.argv[1],0); ln = int(sys.argv[2],0) if len(sys.argv)>2 else 0x100
        print(dis(va,ln))
