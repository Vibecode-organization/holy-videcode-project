"""Step 3: walk every dispatch-table entry, follow A-tagged calls, collect
var-output evidence + gates."""
import sys, json, re, struct
sys.path.insert(0, "/home/femboychik/work/parse_varout3")
from tools import *
import flow

ENT_RE = re.compile(r"^(com\.apple\.(private|developer|security|internal|system|delegate)\.[A-Za-z0-9_.\-]+|com\.apple\.entitlement)")
f2s_raw = json.load(open("/home/femboychik/work/parse_varout3/func_entstrings.json"))
ENT = {}
for k, v in f2s_raw.items():
    keep = [s for s in v if ENT_RE.match(s)]
    if keep:
        ENT[int(k)] = keep
print("funcs with entitlement strings:", len(ENT))

TABLES = json.load(open("/home/femboychik/work/parse_varout3/tables.json"))

def ioret(insns_dump):
    return None

def resolve_entry(t):
    T = t['target']
    R = follow_stub(T)
    return T, R

def walk(start, tags, depth, seen, origin, acc):
    key = (start, tuple(sorted((k, str(v)) for k, v in tags.items())))
    if key in seen or depth > 2:
        return
    seen.add(key)
    r = flow.analyze(start, tags, max_bytes=0x3000)
    if r is None:
        return
    acc.append(dict(start=start, depth=depth, origin=origin, tags={k: str(v) for k, v in tags.items()},
                    writes=r['writes'], field_stores=r['field_stores'], loads=r['loads'],
                    gates=r['gates'], n_calls=len(r['calls'])))
    for c in r['calls']:
        args = c['args']
        newtags = {}
        for i, tag in enumerate(args):
            if tag != 'O':
                newtags['x%d' % i] = tag
        if newtags and c['target'] and TEXT_EXEC_VA <= c['target'] < TEXT_EXEC_END:
            walk(c['target'], newtags, depth + 1, seen, start, acc)
    for c in r['tail'] + r['indirect']:
        if c.get('target') and TEXT_EXEC_VA <= c['target'] < TEXT_EXEC_END:
            args = c['args']
            newtags = {('x%d' % i): tag for i, tag in enumerate(args) if tag != 'O'}
            if newtags:
                walk(c['target'], newtags, depth + 1, seen, start, acc)

rows = []
for t in TABLES:
    for i, e in enumerate(t['ents']):
        T, R = resolve_entry(e)
        acc = []
        walk(R, {'x2': ('A', 0)}, 0, set(), None, acc)
        writes = [(fr['depth'], fr['start'], w) for fr in acc for w in fr['writes']]
        fields = [(fr['depth'], fr['start'], w) for fr in acc for w in fr['field_stores']]
        loads = [(fr['depth'], fr['start'], w) for fr in acc for w in fr['loads']]
        if not writes and not fields:
            continue
        # gates: objflag in the entry frame, or calls to entitlement-checking funcs
        gate = []
        for fr in acc:
            for g in fr['gates']:
                if g['next'] in ('tbz', 'tbnz', 'cbz', 'cbnz'):
                    gate.append(dict(kind='objflag', va=g['va'], off=g['off'], depth=fr['depth']))
        ent_gate = []
        for fr in acc:
            r2 = flow.analyze(fr['start'], {'x2': ('A', 0)}, max_bytes=0x3000)
            if not r2:
                continue
            for c in r2['calls']:
                if c['target'] in ENT:
                    ent_gate.append(dict(va=c['va'], target=c['target'], strings=ENT[c['target']][:4]))
        rows.append(dict(tbl=t['base'], stride=t['stride'], idx=i, n=t['count'], tkext=t['kext'],
                         target=T, fn=R, f=e['f'], extra=e['extra'],
                         writes=writes, fields=fields, loads=loads, gate=gate, ent_gate=ent_gate,
                         frames=[(f['start'], f['depth']) for f in acc]))

print("entries with varout evidence:", len(rows))
strict = [r for r in rows if r['writes']]
print("  ...with a write through the pointer:", len(strict))
print("  ...with a store into args+0x78:", len([r for r in rows if r['fields']]))
json.dump([{k: v for k, v in r.items()} for r in rows],
          open("/home/femboychik/work/parse_varout3/s3_hits.json", "w"), default=str)
from collections import Counter
print(Counter(r['tkext'] for r in strict).most_common(30))
