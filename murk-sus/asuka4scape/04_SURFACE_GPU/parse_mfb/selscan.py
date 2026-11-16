#!/usr/bin/env python3
# list functions containing selector compares / switch prologues
import json, struct, sys, bisect
from kc import load
k = load()
kmap = json.load(open('kmap.json'))
BTI = 0xD503245F

def kext(kid):
    return next(x for x in kmap if x['id'] == kid)

def textseg(kid, name='__TEXT_EXEC'):
    e = kext(kid)
    return next(x for x in e['segs'] if x['name'] == name)

def scan(kid, verbose=True):
    s = textseg(kid)
    n = s['fs']//4
    w = struct.unpack_from('<%dI' % n, k.data, s['fo'])
    starts = [s['va']+i*4 for i, x in enumerate(w) if x == BTI]
    starts.sort()
    hits = []
    for i, x in enumerate(w):
        # cmp w1, #imm  -> subs wzr, w1, #imm
        if x & 0xFFC0001F == 0x7100001F and ((x >> 5) & 0x1F) == 1:
            imm = (x >> 10) & 0xFFF
            hits.append((s['va']+i*4, imm, 'cmp w1,#%#x' % imm))
        # cmp w1, w8  -> subs wzr, w1, w8
        elif x & 0xFFE0FC1F == 0x6B00001F and ((x >> 5) & 0x1F) == 1 and ((x >> 16) & 0x1F) == 8:
            hits.append((s['va']+i*4, None, 'cmp w1,w8'))
        # sub w8, w1, #imm ; mov w8, w1 ; mov w9, w1
        elif (x & 0xFFC0001F) == 0x51000000 and ((x >> 5) & 0x1F) == 1:
            imm = (x >> 10) & 0xFFF
            hits.append((s['va']+i*4, imm, 'sub w%d,w1,#%#x' % (x & 0x1F, imm)))
    # group by enclosing function
    import collections
    g = collections.defaultdict(list)
    for pc, imm, txt in hits:
        j = bisect.bisect_right(starts, pc) - 1
        if j >= 0:
            g[starts[j]].append((pc, txt))
    out = []
    for st, hs in g.items():
        if len(hs) >= 3:
            out.append((len(hs), st, hs))
    out.sort(reverse=True)
    if verbose:
        for c, st, hs in out[:25]:
            print(f"\n### fn {st:#x}  {c} selector-tests:  {hs[0][1]} ... {hs[-1][1]}")
    return out, (s['va'], s['va']+s['fs'])

if __name__ == '__main__':
    scan(sys.argv[1])
