#!/usr/bin/env python3
"""capstone disassembly + function-start lookup for the 27.2 kernelcache."""
import struct, sys, bisect
from kc import KCFile
import capstone

K = KCFile()
_md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
_md.detail = True

BASE = 0xfffffff007004000
TEXT   = (0xfffffff007004000, 0xfffffff007004000+0x8000)
PTEXT  = (0xfffffff00700c000, 0xfffffff00700c000+0xbac000)
DCONST = (0xfffffff007bb8000, 0xfffffff007bb8000+0x548000)
DSPTM  = (0xfffffff008100000, 0xfffffff008100000+0x4c000)
TEXEC  = (0xfffffff00814c000, 0xfffffff00814c000+0x2924000)
BOOT   = (0xfffffff00aa70000, 0xfffffff00aa70000+0x8000)
PINFO  = (0xfffffff00aa78000, 0xfffffff00aa78000+0x23c000)
DATA   = (0xfffffff00acb4000, 0xfffffff00acb4000+0x2b8000)
LINK   = (0xfffffff00af6c000, 0xfffffff00af6c000+0xb8000)

def is_code(va):
    return TEXT[0] <= va < TEXT[1] or PTEXT[0] <= va < PTEXT[1] or TEXEC[0] <= va < TEXEC[1] or BOOT[0] <= va < BOOT[1]

def is_kdata(va):
    return DCONST[0] <= va < DCONST[1] or DATA[0] <= va < DATA[1]

def is_kaddr(v):
    return 0xfffffe0000000000 <= v <= 0xffffffffffffffff

def dis(va, n=40, count=None):
    b = K.read(va, n*4 if n else 4096)
    out = []
    for ins in _md.disasm(b, va):
        out.append(ins)
        if count and len(out) >= count:
            break
    return out

def show(va, n=40):
    for i in dis(va, n):
        print('  %#014x  %-8s %s' % (i.address, i.mnemonic, i.op_str))

# ---- function starts from LC_FUNCTION_STARTS ----
def _load_funcstarts():
    d = K.d
    ncmds = struct.unpack_from('<I', d, 16)[0]
    off = 32
    fs = None
    for _ in range(ncmds):
        cmd, cs = struct.unpack_from('<II', d, off)
        if cmd == 0x26:  # LC_FUNCTION_STARTS
            fs = struct.unpack_from('<II', d, off+8)
        off += cs
    starts = []
    if fs:
        do, ds = fs
        p = do
        cur = BASE
        while p < do+ds:
            v = 0; sh = 0
            while True:
                c = d[p]; p += 1
                v |= (c & 0x7f) << sh
                sh += 7
                if not (c & 0x80):
                    break
            if v == 0:
                break
            cur += v
            starts.append(cur)
    return starts

FS = _load_funcstarts()

def func_of(va):
    i = bisect.bisect_right(FS, va) - 1
    return FS[i] if i >= 0 else None

def funcs_in(lo, hi):
    a = bisect.bisect_left(FS, lo)
    b = bisect.bisect_right(FS, hi)
    return FS[a:b]

# ---- xref helpers ----
def adrp_target(ins):
    """compute adrp target"""
    if ins.mnemonic != 'adrp':
        return None
    return ins.operands[1].imm

def scan_page_refs(page, limit=None):
    """return list of (insn_addr, insn) referencing a 4k page via adrp"""
    res = []
    for seg in (TEXT, TEXEC, BOOT):
        lo, hi = seg
        for f in funcs_in(lo, hi):
            pass
    return res

if __name__ == '__main__':
    cmd = sys.argv[1]
    if cmd == 'dis':
        show(int(sys.argv[2], 16), int(sys.argv[3]) if len(sys.argv) > 3 else 40)
    elif cmd == 'func':
        va = int(sys.argv[2], 16)
        print('func_of(%#x) = %#x' % (va, func_of(va) or 0))
    elif cmd == 'fs':
        print(len(FS), 'function starts')
