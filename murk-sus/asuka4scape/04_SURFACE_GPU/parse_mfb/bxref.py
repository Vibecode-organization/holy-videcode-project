#!/usr/bin/env python3
# fast BL/B/BCOND xref scan over __TEXT_EXEC (+ __TEXT), raw u32 decode
import struct, sys, bisect
from kc import load
k = load()

def targets():
    """yield (pc, target, kind) for direct branches in all executable segments"""
    for s in k.segs:
        if s['name'] not in ('__TEXT_EXEC', '__TEXT', '__PRELINK_TEXT'):
            continue
        n = s['filesize'] // 4
        w = struct.unpack_from('<%dI' % n, k.data, s['fileoff'])
        base = s['vmaddr']
        for i, x in enumerate(w):
            op = x & 0x7C000000
            if op == 0x14000000:  # b/bl (bit31 = link)
                imm = x & 0x3FFFFFF
                if imm & 0x2000000:
                    imm -= 0x4000000
                pc = base + i*4
                kind = 'bl' if (x >> 31) else 'b'
                yield pc, (pc + imm*4) & 0xFFFFFFFFFFFFFFFF, kind

if __name__ == '__main__':
    want = set(int(a, 16) for a in sys.argv[1:])
    out = {w: [] for w in want}
    for pc, t, kind in targets():
        if t in out:
            out[t].append((pc, kind))
    for w in want:
        print(f"{w:#x}: {[(hex(p), kk) for p, kk in out[w]]}")
