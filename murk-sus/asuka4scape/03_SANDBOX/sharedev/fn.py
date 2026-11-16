#!/usr/bin/env python3
"""compact per-function summary: start, size, bl targets, string refs."""
import struct, sys
import kc
from x import decode_bl

BTI = 0xD503245F

def funcs(lo, hi):
    B = kc.BLOB
    fo = kc.TEXTEXEC[3]
    starts = []
    for a in range(lo, hi, 4):
        w = struct.unpack_from("<I", B, kc.va2off(a))[0]
        if w == BTI:
            starts.append(a)
    starts.append(hi)
    return [(starts[i], starts[i+1] - starts[i]) for i in range(len(starts)-1)]

def summarize(lo, hi):
    for s, sz in funcs(lo, hi):
        calls = []
        strs = []
        up = []
        for a, i in kc.dis(s, maxbytes=min(sz, 0x1200)):
            if i.mnemonic in ("bl", "b"):
                t = decode_bl(struct.unpack_from("<I", kc.BLOB, kc.va2off(a))[0], a)
                if t:
                    calls.append((a, t))
            if i.mnemonic in ("adrp",):
                up.append((a, i))
        print(f"--- {s-0xFFFFFFF000000000:#08x} size {sz:#x}")
        # first 6 insns
        for a, i in kc.dis(s, 6):
            print(f"      {i.mnemonic:8s} {i.op_str}")
        tg = sorted(set(t for _, t in calls if t > s))
        print("      bl-> " + " ".join(f"{t-0xFFFFFFF000000000:#x}" for t in tg[:14]))

if __name__ == "__main__":
    lo = int(sys.argv[1], 16) + 0xFFFFFFF000000000
    hi = int(sys.argv[2], 16) + 0xFFFFFFF000000000
    summarize(lo, hi)
