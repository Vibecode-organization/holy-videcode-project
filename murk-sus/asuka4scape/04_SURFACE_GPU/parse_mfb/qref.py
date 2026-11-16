#!/usr/bin/env python3
# find every qword in the image whose low 28 bits (+ kernel base) equal a target VA,
# or which equals the raw VA. Covers PAC'd const pointers and plain rebased ones.
import struct, sys
from kc import load
k = load()
BASE = 0xfffffff007004000

def search(target):
    res = []
    for s in k.segs:
        if not s['filesize']:
            continue
        n = s['filesize'] // 8
        if n <= 0:
            continue
        qs = struct.unpack_from('<%dQ' % n, k.data, s['fileoff'])
        for i, q in enumerate(qs):
            hit = None
            if q == target:
                hit = 'raw'
            elif q and (q & 0x0FFFFFFF) == (target - BASE) & 0x0FFFFFFF and (q >> 32) & 0xFFFF:
                hit = 'pac'
            elif q and (q & 0x0000FFFFFFFFFFFF) == (target & 0x0000FFFFFFFFFFFF):
                hit = 'lo48'
            if hit:
                res.append((s['name'], s['vmaddr'] + i*8, q, hit))
    return res

if __name__ == '__main__':
    for a in sys.argv[1:]:
        t = int(a, 16)
        print(f"=== {t:#x}")
        for seg, va, q, kind in search(t):
            print(f"   {seg:14} {va:#x} q={q:#018x} {kind}")
