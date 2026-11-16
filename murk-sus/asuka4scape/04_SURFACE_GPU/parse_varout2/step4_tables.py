"""Step 4 v3: dispatch table discovery, relaxed.
iOS27 entry (stride 0x28): +0 fn | +8 scalarIn | +12 structIn | +16 scalarOut | +20 structOut | +24 q (flags/pad) | +32 q==0
classic (stride 0x18): same first 0x18 bytes only.
"""
import sys, json, struct, bisect
sys.path.insert(0,"/home/femboychik/work/parse_varout2")
from kc import *

segs = json.load(open("/home/femboychik/work/parse_varout2/kext_segmap.json"))
DCR = sorted((x['segs']['__DATA_CONST'][0], x['segs']['__DATA_CONST'][0]+x['segs']['__DATA_CONST'][1], x['name'])
             for x in segs if '__DATA_CONST' in x['segs'])
DR  = sorted((x['segs']['__DATA'][0], x['segs']['__DATA'][0]+x['segs']['__DATA'][1], x['name'])
             for x in segs if '__DATA' in x['segs'])
ALLD = sorted(DCR + DR); ALLD_LO=[t[0] for t in ALLD]
def kext_data(va):
    i=bisect.bisect_right(ALLD_LO,va)-1
    if i>=0 and ALLD[i][0]<=va<ALLD[i][1]: return ALLD[i][2]
    return "?"

def codeptr(a):
    qq = q(a)
    if qq is None or (qq>>60)!=8: return None
    t = BASE + (qq & 0x0FFFFFFF)
    if TEXT_EXEC_VA <= t < TEXT_EXEC_END: return t
    return None

def ent(a, stride):
    t = codeptr(a)
    if t is None: return None
    f = [d(a+8+4*i) for i in range(4)]
    for x in f:
        if x is None: return None
        if x > 0x100000 and x != 0xffffffff: return None
    extra = q(a+0x18) if stride == 0x28 else 0
    if stride == 0x28:
        if q(a+0x20) != 0: return None
        if extra is None or extra > 0x10000: return None
    return (t, f, extra)

tables = []
for name in ("__DATA_CONST","__DATA"):
    sva, soff, ssize = SEGS[name]
    for stride in (0x28, 0x18):
        a = sva
        while a < sva + ssize:
            e = ent(a, stride)
            if e is None:
                a += 8; continue
            if ent(a-stride, stride) is not None and a-stride >= sva:
                a += 8; continue
            run=[]; cur=a
            while cur < sva+ssize:
                e = ent(cur, stride)
                if e is None: break
                run.append((cur, e[0], e[1], e[2])); cur += stride
            if len(run) >= 2:
                tables.append(dict(seg=name, base=a, stride=stride, count=len(run), kext=kext_data(a),
                                   ents=[dict(addr=r[0], target=r[1], f=r[2], extra=r[3]) for r in run]))
            a = cur if cur > a else a+8

# drop tables fully contained in another (0x18 overlapping a 0x28 table)
def covers(t, e):
    return t['base'] <= e['addr'] < t['base'] + t['stride']*t['count'] and t['stride'] != e['stride']
tables.sort(key=lambda t: (-t['stride'], t['base']))
keep=[]
for t in tables:
    dup = False
    for k in keep:
        if k['seg']==t['seg'] and k['base']<=t['base'] and t['base']+t['stride']*t['count'] <= k['base']+k['stride']*k['count']:
            dup=True; break
    if not dup: keep.append(t)

print("tables:", len(keep), "entries:", sum(t['count'] for t in keep))
from collections import Counter
print("stride:", Counter(t['stride'] for t in keep))
print("kexts:", len(set(t['kext'] for t in keep)))
json.dump(keep, open("/home/femboychik/work/parse_varout2/tables.json","w"))
for t in keep:
    if t['kext']=='com.apple.iokit.IOSurface': print(hex(t['base']), hex(t['stride']), t['count'])
