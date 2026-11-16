#!/usr/bin/env python3
# find a class vtable by scanning __DATA_CONST for a slot at base+0x550 whose target
# looks like externalMethod (reads IOExternalMethodArguments in x2)
import struct, json, sys
from kc import load
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
k = load()
md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
kmap = json.load(open('kmap.json'))
BASE = 0xfffffff007004000

def dec(q):
    if not q: return None
    va = BASE + (q & 0x0FFFFFFF)
    return va if k.seg_by_name['__TEXT_EXEC']['vmaddr'] <= va < 0xfffffff00aa70000 else None

def body(f, n=80):
    o = k.off(f)
    return list(md.disasm(k.data[o:o+n*4], f)) if o else []

def score(ins):
    s = 0
    for i in ins:
        t = i.op_str
        if i.mnemonic in ('ldr','ldrb','ldrh','ldrsw') and ('[x2, #0x38]' in t or '[x2, #0x28]' in t or '[x2, #0x30]' in t or '[x2, #0x20]' in t or '[x2, #0x50]' in t):
            s += 3
        if i.mnemonic == 'cmp' and t.startswith('w1, #'):
            s += 2
    return s

def scan(kid, want=None):
    e = next(x for x in kmap if x['id'] == kid)
    s = next(x for x in e['segs'] if x['name'] == '__TEXT_EXEC')
    dc = next(x for x in e['segs'] if x['name'] == '__DATA_CONST')
    lo, hi = s['va'], s['va']+s['vs']
    n = dc['fs']//8
    qs = struct.unpack_from('<%dQ' % n, k.data, dc['fo'])
    out = []
    for i in range(n):
        va = dc['va'] + i*8
        if want is not None:
            if dec(qs[i]) != want: continue
        V = va - 0x550
        if V < dc['va']: continue
        t = dec(qs[i])
        if t is None or not (lo <= t < hi): continue
        ins = body(t, 60)
        sc = score(ins)
        if sc >= 4:
            out.append((sc, V, t, [f'{x.mnemonic} {x.op_str}' for x in ins[:8]], len(ins)))
    out.sort(reverse=True)
    return out

if __name__ == '__main__':
    kid = sys.argv[1]
    want = int(sys.argv[2], 16) if len(sys.argv) > 2 else None
    for sc, V, t, b, ln in scan(kid, want):
        print(f"score={sc} base={V:#x} extM={t:#x} n={ln} : " + ' | '.join(b))
