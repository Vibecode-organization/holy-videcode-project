#!/usr/bin/env python3
# locate a kext's class vtables by the externalMethod slot at vtable+0x550
import json, struct, sys
from kc import load
k = load()
BASE = 0xfffffff007004000
kmap = json.load(open('kmap.json'))

def dec(q):
    if not q: return None
    va = BASE + (q & 0x0FFFFFFF)
    for s in k.segs:
        if s['name'] in ('__TEXT_EXEC', '__TEXT') and s['filesize'] and s['vmaddr'] <= va < s['vmaddr']+s['filesize']:
            return va
    return None

def find(kextid):
    e = next(x for x in kmap if x['id'] == kextid)
    tex = next(s for s in e['segs'] if s['name'] == '__TEXT_EXEC')
    dc = next(s for s in e['segs'] if s['name'] == '__DATA_CONST')
    lo, hi = tex['va'], tex['va']+tex['vs']
    n = dc['fs']//8
    qs = struct.unpack_from('<%dQ' % n, k.data, dc['fo'])
    out = []
    for i, q in enumerate(qs):
        t = dec(q)
        if t is None or not (lo <= t < hi):
            continue
        va = dc['va'] + i*8
        cand = va - 0x550
        # candidate vtable start: entry0 also in this kext, entry before invalid
        q0 = k.q(cand); prev = k.q(cand-8) if cand-8 >= dc['va'] else 0
        d0 = dec(q0) if q0 else None
        out.append(dict(slot=va, target=t, cand=cand, cand0=d0,
                        prev_text=bool(prev and dec(prev)), prev=prev))
    return out, (lo, hi), (dc['va'], dc['va']+dc['fs'])

if __name__ == '__main__':
    for kid in sys.argv[1:]:
        res, tex, dc = find(kid)
        print(f"== {kid}  tex={tex[0]:#x}..{tex[1]:#x}  dc={dc[0]:#x}..{dc[1]:#x}")
        for r in res:
            flag = 'VTB?' if r['prev_text'] is False else '    '
            print(f" {flag} slot={r['slot']:#x} -> {r['target']:#x}  base={r['cand']:#x} e0={r['cand0'] and hex(r['cand0'])} prev={r['prev']:#x}")
