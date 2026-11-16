#!/usr/bin/env python3
# language: Python, file: ldis.py, target: iOS 27.2 arm64e kernelcache
# Linear disassembly of a VA range + ADRP/ADD string annotation.
import sys
from capstone import *
from macho import load, BASE
from kdis import md, read_cstr, _int

data, segs = load()

def rd(va, n):
    return data[va - BASE: va - BASE + n]

def dump(start, end, extra_regs=None):
    vals = dict(extra_regs or {})
    va = start
    while va < end:
        code = rd(va, 4)
        insns = list(md.disasm(code, va))
        if not insns:
            print(f"{va:#014x}:  ????"); va += 4; continue
        insn = insns[0]
        m, op = insn.mnemonic, insn.op_str
        ann = ""
        parts = [x.strip() for x in op.split(",")]
        if m == "adrp":
            try:
                vals[parts[0]] = _int(parts[1])
            except Exception:
                pass
        elif m in ("add", "ldr", "ldrb", "ldrh", "ldrsw", "str", "strb", "strh", "ldp", "stp", "ldur"):
            if len(parts) >= 2 and parts[1].startswith("#") and parts[0] in vals:
                try:
                    t = vals[parts[0]] + _int(parts[1])
                    s = read_cstr(t)
                    if s is not None:
                        ann = f'; "{s}"'
                    elif BASE <= t < BASE + len(data):
                        ann = f"; ={t:#x}"
                except Exception:
                    pass
        print(f"{va:#014x}:  {insn.bytes.hex():<10} {m:<8} {op:<42} {ann}")
        va += 4

if __name__ == "__main__":
    a = _int(sys.argv[1]); b = _int(sys.argv[2])
    dump(a, b)
