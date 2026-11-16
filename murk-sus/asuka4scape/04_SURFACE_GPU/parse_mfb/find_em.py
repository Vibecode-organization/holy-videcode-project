#!/usr/bin/env python3
# find externalMethod-like functions: reads of IOExternalMethodArguments (x2) fields
import json, struct, sys, bisect, collections
from kc import load
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
k = load()
md = Cs(CS_ARCH_ARM64, CS_MODE_ARM); md.detail = True
kmap = json.load(open('kmap.json'))
BTI = 0xD503245F

def kext_seg(kid, name):
    e = next(x for x in kmap if x['id'] == kid)
    return next((s for s in e['segs'] if s['name'] == name), None)

ARGOFFS = {0x00:'version',0x04:'selector',0x08:'asyncWakePort',0x10:'ref',0x20:'scalarInput',
           0x28:'scalarInputCount',0x30:'structIn',0x38:'structInSize',0x40:'structInDesc',
           0x48:'scalarOut',0x50:'scalarOutCount',0x58:'structOut',0x60:'structOutSize'}

def scan(kid):
    s = kext_seg(kid, '__TEXT_EXEC')
    n = s['fs']//4
    w = struct.unpack_from('<%dI' % n, k.data, s['fo'])
    base = s['va']
    starts = [base+i*4 for i, x in enumerate(w) if x == BTI]
    starts.sort()
    hits = collections.defaultdict(set)
    for i, x in enumerate(w):
        # ldr/ldrb/ldrh/ldrsw unsigned-offset, Rn == 2
        op = x & 0xFFC00000
        rn = (x >> 5) & 0x1F
        if rn != 2: continue
        off = None
        if op == 0xF9400000:   # ldr x
            off = ((x >> 10) & 0xFFF) * 8
        elif op == 0xB9400000: # ldr w
            off = ((x >> 10) & 0xFFF) * 4
        elif op == 0x39400000: # ldrb
            off = (x >> 10) & 0xFFF
        elif op == 0x79400000: # ldrh
            off = ((x >> 10) & 0xFFF) * 2
        elif op == 0x39800000: # ldrsw
            off = ((x >> 10) & 0xFFF) * 4
        else:
            continue
        if off not in ARGOFFS: continue
        pc = base + i*4
        j = bisect.bisect_right(starts, pc) - 1
        if j < 0: continue
        hits[starts[j]].add(pc)
    return hits, (s['va'], s['va']+s['fs'])

def fn(kid, va, n=120):
    s = kext_seg(kid, '__TEXT_EXEC')
    o = k.off(va)
    out = []
    for i in md.disasm(k.data[o:o+n*4], va):
        out.append(i)
        if i.mnemonic in ('ret','retab'): break
    return out

if __name__ == '__main__':
    kid = sys.argv[1]
    minhits = int(sys.argv[2]) if len(sys.argv) > 2 else 2
    hits, rng = scan(kid)
    res = []
    for st, ps in hits.items():
        if len(ps) < minhits: continue
        ins = fn(kid, st)
        cmpsel = [i for i in ins if i.mnemonic in ('cmp','subs') and i.op_str.startswith(('w1,','w1 ,'))]
        res.append((len(ins), st, len(ps), sorted(ps), cmpsel[:3], ins))
    res.sort()
    for ln, st, nh, ps, cmps, ins in res:
        print(f"\n### {st:#x}  ninsn={ln} argreads={nh} selcmp={[c.op_str for c in cmps]}")
        print("   offs:", [ARGOFFS[(( (int(k.d32(p)))>>10)&0xFFF)*(8 if (k.d32(p)&0xFFC00000)==0xF9400000 else 4) if (k.d32(p)&0xFFC00000) in (0xF9400000,0xB9400000) else 0] for p in ps][:8])
        print("   ", " | ".join(f"{i.mnemonic} {i.op_str}" for i in ins[:10]))
