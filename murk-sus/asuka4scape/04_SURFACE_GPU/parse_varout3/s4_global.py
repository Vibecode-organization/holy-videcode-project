"""Step 4: global sweep — every function in __TEXT_EXEC that reads args+0x78
and stores through the loaded pointer. Independent of dispatch tables."""
import sys, json, array, bisect
sys.path.insert(0, "/home/femboychik/work/parse_varout3")
from tools import *
import flow

buf = DATA[TEXT_EXEC_OFF:TEXT_EXEC_OFF + TEXT_EXEC_SIZE]
a = array.array('I'); a.frombytes(buf)
hits = []
for i, w in enumerate(a):
    if (w & 0xFFC00000) == 0xF9400000:            # LDR Xt,[Xn,#imm12]
        if ((w >> 10) & 0xFFF) == 0x0F:
            hits.append((TEXT_EXEC_VA + i * 4, 'ldr', w))
    elif (w & 0xFFE00C00) == 0xF8400000:          # LDUR Xt,[Xn,#imm9]
        if ((w >> 12) & 0x1FF) == 0x78:
            hits.append((TEXT_EXEC_VA + i * 4, 'ldur', w))
    elif (w & 0xFFC00000) == 0xA9400000:          # LDP
        if ((w >> 15) & 0x7F) in (0x0F,):
            hits.append((TEXT_EXEC_VA + i * 4, 'ldp', w))

print("raw 0x78 loads:", len(hits))
funcs = {}
for va, kind, w in hits:
    s, e = func_of(va)
    if s:
        funcs.setdefault(s, []).append((va, kind))
print("containing funcs:", len(funcs))

rows = []
for s, hl in funcs.items():
    r = flow.analyze(s, {'x2': ('A', 0)}, max_bytes=0x4000)
    if not r or not r['writes']:
        continue
    rows.append(dict(func=s, kext=kext_of(s), loads=r['loads'], writes=r['writes'],
                     field_stores=r['field_stores'], gates=r['gates'], n_calls=len(r['calls'])))
print("funcs with write-through:", len(rows))
json.dump(rows, open("/home/femboychik/work/parse_varout3/s4_global.json", "w"))
from collections import Counter
print(Counter(r['kext'] for r in rows).most_common(40))
