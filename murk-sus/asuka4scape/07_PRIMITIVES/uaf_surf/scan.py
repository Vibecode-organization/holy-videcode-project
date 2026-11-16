#!/usr/bin/env python3
"""scan kernelcache __TEXT_EXEC: function prologues, direct calls, vtable slot calls."""
import kc, struct
from capstone.arm64 import ARM64_OP_REG, ARM64_OP_MEM, ARM64_OP_IMM

SEG = kc.TEXTEXEC
start = SEG[1]; size = SEG[4]

def scan():
    funcs = []
    insns = {}
    va = start
    end = start + size
    while va < end:
        off = kc.va2off(va)
        if off < 0 or off + 4 > len(kc.BLOB):
            break
        w = struct.unpack_from("<I", kc.BLOB, off)[0]
        # function start marker: bti c (0xd503245f) optionally followed by pacibsp
        if w == 0xD503245F:
            insns[va] = "bti"
            funcs.append(va)
        va += 4
    print("candidate funcs:", len(funcs))
    return funcs

if __name__ == "__main__":
    fs = scan()
    print(hex(fs[0]) if fs else None, hex(fs[-1]) if fs else None)
