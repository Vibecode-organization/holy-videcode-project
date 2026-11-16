#!/usr/bin/env python3
# function splitter + bl-graph for a kext __TEXT_EXEC
import json, struct, sys, bisect, collections
from kc import load
k = load()
kmap = json.load(open('kmap.json'))
BTI = 0xD503245F

def kext(kid):
    return next(x for x in kmap if x['id'] == kid)

def funcs(kid):
    """split __TEXT_EXEC into functions starting at each `bti c`"""
    e = kext(kid)
    s = next(x for x in e['segs'] if x['name'] == '__TEXT_EXEC')
    n = s['fs']//4
    w = struct.unpack_from('<%dI' % n, k.data, s['fo'])
    starts = [s['va']+i*4 for i, x in enumerate(w) if x == BTI]
    starts.sort()
    out = {}
    for idx, st in enumerate(starts):
        end = starts[idx+1] if idx+1 < len(starts) else s['va']+s['fs']
        i0 = (st - s['va'])//4
        i1 = (end - s['va'])//4
        seg = w[i0:i1]
        calls = []
        for j, x in enumerate(seg):
            if (x & 0xFC000000) == 0x94000000:  # bl
                imm = x & 0x3FFFFFF
                if imm & 0x2000000: imm -= 0x4000000
                calls.append((st+j*4, (st+j*4+imm*4) & 0xFFFFFFFFFFFFFFFF))
        out[st] = dict(end=end, n=len(seg), calls=calls)
    return out, (s['va'], s['va']+s['fs'])

if __name__ == '__main__':
    kid = sys.argv[1]
    F, rng = funcs(kid)
    print(f"{kid}: {len(F)} functions in {rng[0]:#x}..{rng[1]:#x}")
    # most-called targets
    cnt = collections.Counter()
    for st, f in F.items():
        for pc, t in f['calls']:
            cnt[t] += 1
    print("top called targets:")
    for t, c in cnt.most_common(15):
        print(f"   {t:#x} x{c}  {'IN-KEXT' if rng[0]<=t<rng[1] else 'ext'}")
    # biggest functions by call count
    print("functions with most bl:")
    for st, f in sorted(F.items(), key=lambda kv: -len(kv[1]['calls']))[:12]:
        print(f"   {st:#x} ninsn={f['n']} nbl={len(f['calls'])}")
