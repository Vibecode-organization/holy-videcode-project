"""Final consolidation: unique writer rows, gate status, report table."""
import sys, json, re
sys.path.insert(0, "/home/femboychik/work/parse_varout3")
from tools import *
import flow

T = json.load(open("tables.json"))
s3 = json.load(open("s3_hits.json"))
g = json.load(open("s4_global.json"))

# ---- unique (table, selector) rows with varout evidence
rows = {}
for r in s3:
    for d, f, w in r['writes']:
        if d != 0:
            continue
        k = (r['tbl'], r['stride'], r['idx'])
        rows.setdefault(k, dict(tbl=r['tbl'], stride=r['stride'], idx=r['idx'], n=r['n'],
                                tkext=r['tkext'], target=r['target'], fn=r['fn'], f=r['f'],
                                writes=[]))
        rows[k]['writes'].append(w['va'])
print("unique (table,selector) with write:", len(rows))
for k, v in sorted(rows.items()):
    print(f"  {v['tkext'][:36]:36s} tbl {v['tbl']:#x} s{v['stride']:#x} sel {v['idx']} fn {v['fn']:#x} f={v['f']} ent={None}")

# ---- unique writer functions
writers = {}
for r in rows.values():
    writers.setdefault(r['fn'], dict(fn=r['fn'], kext=kext_of(r['fn']), writes=[], tabs=[]))
    writers[r['fn']]['writes'] += r['writes']
    writers[r['fn']]['tabs'].append((r['tbl'], r['stride'], r['idx'], r['n'], r['f']))
for r in g:
    writers.setdefault(r['func'], dict(fn=r['func'], kext=kext_of(r['func']), writes=[], tabs=[]))
    for w in r['writes']:
        if w['va'] not in writers[r['func']]['writes']:
            writers[r['func']]['writes'].append(w['va'])
print("unique writer funcs:", len(writers))

# ---- gate analysis for each writer
entmap = json.load(open("func_entstrings.json"))
ENT_RE = re.compile(r"^com\.apple\.(private|developer|security|internal|system|delegate)\.")
def ent_of(f):
    return [s for s in entmap.get(str(f), []) if ENT_RE.match(s)]

def reachable_ent(f, depth=2, seen=None):
    """direct call graph (bl / b) up to depth; returns {func: [strings]}"""
    seen = seen or set()
    if depth < 0 or f in seen:
        return {}
    seen.add(f)
    r = flow.analyze(f, {'x2': ('A', 0)}, max_bytes=0x4000)
    out = {}
    if not r:
        return out
    if ent_of(f):
        out[f] = ent_of(f)
    for c in r['calls'] + r['tail']:
        t = c.get('target')
        if t and TEXT_EXEC_VA <= t < TEXT_EXEC_END and (t not in seen):
            out.update(reachable_ent(t, depth - 1, seen))
    return out

for f, w in sorted(writers.items()):
    r = flow.analyze(f, {'x2': ('A', 0)}, max_bytes=0x4000)
    flags = [g for g in (r['gates'] if r else []) if g['next'] in ('tbz', 'tbnz', 'cbz', 'cbnz')]
    ents = reachable_ent(f, 2)
    w['flags'] = flags
    w['ents'] = {hex(k): v[:2] for k, v in ents.items()}
    w['nflags'] = len(flags)
json.dump({hex(k): dict(kext=v['kext'], writes=[hex(x) for x in v['writes']],
                        tabs=[list(t) for t in v['tabs']],
                        flags=[dict(va=hex(x['va']), off=hex(x['off'])) for x in v['flags']],
                        ents=v['ents']) for k, v in writers.items()},
          open("final_writers.json", "w"), indent=1)
print("\n--- gate summary")
for f, w in sorted(writers.items()):
    print(f"  {f:#x} {w['kext'][:34]:34s} flags={[(hex(x['va']),hex(x['off'])) for x in w['flags']]} ent={list(w['ents'].values())[:2]}")

# ---- table stats for the report
tb28 = [t for t in T if t['stride'] == 0x28]
tb18 = [t for t in T if t['stride'] == 0x18]
print("\ntables:", len(T), "18:", len(tb18), "28:", len(tb28),
      "entries:", sum(t['count'] for t in T))
print("kexts with tables:", len(set(t['kext'] for t in T)), "unattributed:", sum(1 for t in T if t['kext'] == '?'))
print("entries with var struct out:", sum(1 for t in T for e in t['ents'] if e['f'][3] == 0xffffffff))
print("entries with checkEntitlement:", sum(1 for t in T for e in t['ents'] if e['ent']))
print("allowAsync=1:", sum(1 for t in T if t['stride'] == 0x28 for e in t['ents'] if (e['extra'] or 0) & 0xff == 1))
