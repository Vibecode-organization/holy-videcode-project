"""Step 7: reverse index data-pointer -> code, then resolve dispatch entry/table per candidate func.
Handles PAC'd (q>>60==8, low28 = va-BASE) and plain forms, and single-entry tables."""
import sys, json, struct, bisect
sys.path.insert(0,"/home/femboychik/work/parse_varout2")
from kc import *

res = json.load(open("/home/femboychik/work/parse_varout2/step3_results.json"))

idx = {}   # low28 -> [(slot_va, qword)]
for name in ("__DATA_CONST", "__DATA", "__PRELINK_TEXT", "__TEXT"):
    sva, soff, ssize = SEGS[name]
    buf = DATA[soff:soff+ssize]
    for o in range(0, ssize-8, 8):
        qq = struct.unpack_from("<Q", buf, o)[0]
        if qq == 0: continue
        if (qq >> 60) == 8:
            idx.setdefault(qq & 0x0FFFFFFF, []).append((sva+o, qq))
        elif (qq >> 32) == 0xfffffff0:
            idx.setdefault(qq & 0x0FFFFFFF, []).append((sva+o, qq))
print("ptr slots indexed:", sum(len(v) for v in idx.values()))

def ent(a, stride):
    qq = q(a)
    if qq is None or (qq>>60)!=8: return None
    t = BASE + (qq & 0x0FFFFFFF)
    if not (TEXT_EXEC_VA <= t < TEXT_EXEC_END): return None
    f = [d(a+8+4*i) for i in range(4)]
    for x in f:
        if x is None: return None
        if x > 0x100000 and x != 0xffffffff: return None
    if stride == 0x28 and q(a+0x20) != 0: return None
    return (t, f)

def table_of(slot):
    best = None
    for stride in (0x28, 0x18):
        if ent(slot, stride) is None: continue
        base = slot; k = 0
        while k < 600 and ent(base-stride, stride) is not None:
            base -= stride; k += 1
        n = 0; cur = base
        while n < 600 and ent(cur, stride) is not None:
            n += 1; cur += stride
        index = (slot - base)//stride
        if best is None or n > best[2]:
            best = (base, stride, n, index, ent(slot, stride))
    return best

rows = []
for r in res:
    f = r['func']
    low = (f - BASE) & 0x0FFFFFFF
    slots = idx.get(low, [])
    tabs = []
    for sva, qq in slots:
        t = table_of(sva)
        if t:
            tabs.append(dict(slot=sva, base=t[0], stride=t[1], count=t[2], index=t[3], f=t[4][1], target=t[4][0]))
    r2 = dict(r); r2['tabs'] = tabs; r2['n_slots'] = len(slots)
    rows.append(r2)

json.dump(rows, open("/home/femboychik/work/parse_varout2/step7_ptridx.json","w"))
strict = [r for r in rows if r['strict']]
print("strict:", len(strict), "with table:", sum(1 for r in strict if r['tabs']))
for r in strict:
    t = r['tabs'][0] if r['tabs'] else None
    print(f"  {r['kext'][:36]:36s} {r['func']:#x} " + (f"tbl {t['base']:#x} stride {t['stride']:#x} idx {t['index']} n {t['count']} f={t['f']}" if t else "NO TABLE"))
