#!/usr/bin/env python3
# map a kext's __DATA_CONST as a grid of pointer classes, to eyeball vtable boundaries
import json, struct, sys
from kc import load
k = load()
kmap = json.load(open('kmap.json'))
BASE = 0xfffffff007004000

def dec(q):
    if not q: return None
    va = BASE + (q & 0x0FFFFFFF)
    for s in k.segs:
        if s['name'] in ('__TEXT_EXEC','__TEXT') and s['filesize'] and s['vmaddr'] <= va < s['vmaddr']+s['filesize']:
            return va
    return None

if __name__ == '__main__':
    kid = sys.argv[1]
    e = next(x for x in kmap if x['id'] == kid)
    dc = next(s for s in e['segs'] if s['name'] == '__DATA_CONST')
    tex = next(s for s in e['segs'] if s['name'] == '__TEXT_EXEC')
    lo, hi = tex['va'], tex['va']+tex['vs']
    n = dc['fs']//8
    qs = struct.unpack_from('<%dQ' % n, k.data, dc['fo'])
    line = []
    for i, q in enumerate(qs):
        t = dec(q)
        if q == 0: line.append('0')
        elif t is None: line.append('?')
        elif lo <= t < hi: line.append('K')
        else: line.append('.')
    W = 64
    for r in range(0, len(qs), W):
        print(f"{dc['va']+r*8:#012x} " + ''.join(line[r:r+W]))
