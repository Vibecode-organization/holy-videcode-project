#!/usr/bin/env python3
"""xref scanner for kernelcache: find bl/b callers, adrp+add string refs, field loads."""
import sys, struct
import kc

def decode_bl(w, va):
    if (w & 0xFC000000) not in (0x14000000, 0x94000000):
        return None
    imm = w & 0x03FFFFFF
    if imm & 0x02000000:
        imm -= 0x04000000
    return (va + (imm << 2)) & 0xFFFFFFFFFFFFFFFF

def callers(target_va, lo=None, hi=None):
    lo = lo if lo else kc.TEXTEXEC[1]
    hi = hi if hi else kc.TEXTEXEC[1] + kc.TEXTEXEC[4]
    fo = kc.TEXTEXEC[3]
    out = []
    n = hi - lo
    B = kc.BLOB
    for a in range(0, n, 4):
        w = struct.unpack_from("<I", B, fo + a)[0]
        t = decode_bl(w, lo + a)
        if t == target_va:
            out.append(lo + a)
    return out

def func_start(va, maxback=0x800):
    """walk back to a 'bti c' preceded by terminator / alignment"""
    B = kc.BLOB
    for back in range(0, maxback, 4):
        a = va - back
        o = kc.va2off(a)
        w = struct.unpack_from("<I", B, o)[0]
        if w == 0xD503245F:  # bti c
            return a
    return None

def show_callers(target, name=""):
    print(f"== callers of {name} {target:#x}")
    for a in callers(target):
        fs = func_start(a)
        print("   ", f"{a-0xFFFFFFF000000000:#x}", "in", f"{fs-0xFFFFFFF000000000:#x}" if fs else "?")

if __name__ == "__main__":
    for arg in sys.argv[1:]:
        show_callers(int(arg, 16))
