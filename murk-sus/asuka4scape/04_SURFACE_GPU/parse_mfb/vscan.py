#!/usr/bin/env python3
# scan __DATA_CONST for PAC-encoded kernel-text pointers, build vtable candidates
import struct, json, sys
from kc import load
k = load()
BASE = 0xfffffff007004000
dc = k.seg_by_name['__DATA_CONST']
tex = k.seg_by_name['__TEXT_EXEC']

def dec(q):
    if q == 0: return None
    va = BASE + (q & 0x0FFFFFFF)
    if tex['vmaddr'] <= va < tex['vmaddr'] + tex['filesize']:
        return va
    return None

def scan():
    n = dc['filesize'] // 8
    qs = struct.unpack_from('<%dQ' % n, k.data, dc['fileoff'])
    hits = {}
    for i, q in enumerate(qs):
        t = dec(q)
        if t is not None:
            hits.setdefault(t, []).append(dc['vmaddr'] + i*8)
    return qs, hits

if __name__ == '__main__':
    qs, hits = scan()
    print("qwords", len(qs), "distinct text targets", len(hits))
    for a in sys.argv[1:]:
        v = int(a, 16)
        print(f"{v:#x} <- {[hex(x) for x in hits.get(v, [])]}")
