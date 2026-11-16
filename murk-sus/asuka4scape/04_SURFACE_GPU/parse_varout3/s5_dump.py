"""Step 5: dump writer candidates for manual review + build call/ENT context."""
import sys, json, os
sys.path.insert(0, "/home/femboychik/work/parse_varout3")
from tools import *
import flow

s3 = json.load(open("/home/femboychik/work/parse_varout3/s3_hits.json"))
g = json.load(open("/home/femboychik/work/parse_varout3/s4_global.json"))

sites = {}      # func -> dict(writes=[], tables=[])
for r in s3:
    for d, f, w in r['writes']:
        if d != 0:
            continue
        e = sites.setdefault(f, dict(func=f, writes=[], tables=[]))
        e['writes'].append(w['va'])
        e['tables'].append((r['tbl'], r['stride'], r['idx'], r['n'], r['tkext'], r['f']))
for r in g:
    f = r['func']
    e = sites.setdefault(f, dict(func=f, writes=[], tables=[]))
    for w in r['writes']:
        if w['va'] not in e['writes']:
            e['writes'].append(w['va'])

print("unique writer functions:", len(sites))
os.makedirs("/home/femboychik/work/parse_varout3/dump", exist_ok=True)
for f, e in sites.items():
    s, end = func_of(f)
    insns = list(md.disasm(DATA[va2off(s):va2off(s) + min(end - s, 0x1200)], s))
    with open(f"/home/femboychik/work/parse_varout3/dump/{f:016x}.txt", "w") as fh:
        fh.write(f"func {f:#x} kext {kext_of(f)} writes {[hex(x) for x in e['writes']]}\n")
        for t in e['tables']:
            fh.write(f"  table {t[0]:#x} stride {t[1]:#x} idx {t[2]}/{t[3]} kext {t[4]} f={t[5]}\n")
        fh.write("\n")
        for i in insns:
            mark = " <<<" if i.address in e['writes'] else ""
            fh.write(f"{i.address:016x}  {i.mnemonic:8s} {i.op_str}{mark}\n")
json.dump({hex(k): dict(func=v['func'], writes=[hex(x) for x in v['writes']],
                       tables=[list(t) for t in v['tables']]) for k, v in sites.items()},
          open("/home/femboychik/work/parse_varout3/writers.json", "w"), indent=1)
for f, e in sorted(sites.items()):
    print(f"  {f:#x} {kext_of(f):38s} tbls {[(hex(t[0]), t[2]) for t in e['tables']]}")
