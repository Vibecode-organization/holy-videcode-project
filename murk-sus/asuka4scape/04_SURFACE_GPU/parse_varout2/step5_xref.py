"""Step 5: xrefs (bl/b) to candidate funcs + IOExternalMethodArguments signature score."""
import sys, json, struct, bisect, array
sys.path.insert(0,"/home/femboychik/work/parse_varout2")
from kc import *

res = json.load(open("/home/femboychik/work/parse_varout2/step3_results.json"))
tables = json.load(open("/home/femboychik/work/parse_varout2/tables.json"))

# table target index
tidx = {}
for t in tables:
    for i, e in enumerate(t['ents']):
        tidx.setdefault(e['target'], []).append((t['base'], t['stride'], i, t['kext']))

cand = {r['func']: r for r in res}
offs2 = array.array('I'); offs2.frombytes(open("/home/femboychik/work/parse_varout2/funcstarts.bin","rb").read())
STARTS = [TEXT_EXEC_VA + o for o in offs2]
def func_of(va):
    i = bisect.bisect_right(STARTS, va) - 1
    if i < 0: return None, None
    return STARTS[i], (STARTS[i+1] if i+1 < len(STARTS) else TEXT_EXEC_END)
targets = set(cand)

buf = DATA[TEXT_EXEC_OFF:TEXT_EXEC_OFF+TEXT_EXEC_SIZE]
a = array.array('I'); a.frombytes(buf)
xrefs = {}
for i, w in enumerate(a):
    op = w & 0xFC000000
    if op == 0x94000000 or op == 0x14000000:
        imm = w & 0x03FFFFFF
        if imm & 0x02000000: imm -= 0x04000000
        t = TEXT_EXEC_VA + i*4 + imm*4
        if t in targets:
            xrefs.setdefault(t, []).append((TEXT_EXEC_VA + i*4, 'bl' if op == 0x94000000 else 'b'))

print("cands with direct xref:", len(xrefs))

# find table entries pointing at thunks of our candidates
THUNK = {}
for i, w in enumerate(a):
    pass

def thunk_target(va):
    o = va2off(va)
    if o is None: return None
    w0 = struct.unpack_from("<I", DATA, o)[0]
    if w0 == 0xD503245F:  # bti c
        o += 4
        w0 = struct.unpack_from("<I", DATA, o)[0]
    if (w0 & 0xFC000000) == 0x14000000:
        imm = w0 & 0x03FFFFFF
        if imm & 0x02000000: imm -= 0x04000000
        return va + (4 if struct.unpack_from("<I", DATA, va2off(va))[0] == 0xD503245F else 0) + imm*4
    return None

rows = []
for r in res:
    f = r['func']
    xr = xrefs.get(f, [])
    th = thunk_target(f)
    via = []
    for src, kind in xr:
        cs, ce = func_of(src)
        if cs in tidx:
            via.append(('caller-tabled', src, kind, cs, tidx[cs]))
        elif cs is not None and thunk_target(cs) is not None:
            tf = thunk_target(cs)
            if tf in tidx:
                via.append(('caller-thunk-tabled', src, kind, cs, tidx[tf]))
    # is the function itself a table target?
    self_tbl = tidx.get(f)
    th_tbl = tidx.get(th) if th else None
    rows.append(dict(func=f, kext=r['kext'], strict=r['strict'], weak=r['weak'], passed=r['passed'],
                     ldr=r['ldr'], ldr_rn=r['ldr_rn'], xrefs=xr[:8], n_xref=len(xr),
                     self_tbl=self_tbl, thunk=th, thunk_tbl=th_tbl, via=via))

json.dump(rows, open("/home/femboychik/work/parse_varout2/step5_xref.json","w"))
n_self = sum(1 for r in rows if r['self_tbl'])
n_th = sum(1 for r in rows if r['thunk_tbl'])
n_via = sum(1 for r in rows if r['via'])
print(f"self in table: {n_self}, via thunk in table: {n_th}, via caller-thunk: {n_via}")
strict = [r for r in rows if r['strict']]
print("strict:", len(strict), "of which tabled:", sum(1 for r in strict if r['self_tbl'] or r['thunk_tbl'] or r['via']))
