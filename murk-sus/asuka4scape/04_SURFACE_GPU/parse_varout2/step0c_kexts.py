import sys, json, plistlib
sys.path.insert(0,"/home/femboychik/work/parse_varout2")
from kc import *

o=SEGS['__PRELINK_INFO'][1]; sz=SEGS['__PRELINK_INFO'][2]
d=DATA[o:o+sz]; e=d.rfind(b'</plist>'); pl=plistlib.loads(d[:e+8])
info=pl['_PrelinkInfoDictionary']

rows=[]
for k in info:
    la = k.get('_PrelinkExecutableLoadAddr'); s = k.get('_PrelinkExecutableSize')
    if la is None or s is None: continue
    la &= 0xffffffffffffffff; s &= 0xffffffffffffffff
    rows.append((la, s, k.get('CFBundleIdentifier','?'), k.get('CFBundleExecutable','?')))
rows.sort()
print("kexts with exec:", len(rows))
for la,s,name,exe in rows[:3]: print(hex(la), hex(s), name, exe)
lo,hi = rows[0][0], max(la+s for la,s,_,_ in rows)
print("range", hex(lo), hex(hi))
print("TEXT_EXEC", hex(TEXT_EXEC_VA), hex(TEXT_EXEC_END))
print("sum size", hex(sum(s for _,s,_,_ in rows)), "TEXT_EXEC size", hex(TEXT_EXEC_SIZE))
prev_end=None; gaps=[]
for la,s,name,exe in rows:
    if prev_end is not None and la != prev_end:
        gaps.append((prev_end, la, la-prev_end, name))
    prev_end = la+s
print("non-contiguous:", len(gaps))
for g in gaps[:20]: print("  ", hex(g[0]), "->", hex(g[1]), hex(g[2]), g[3])
json.dump(rows, open("/home/femboychik/work/parse_varout2/kext_ranges.json","w"))
