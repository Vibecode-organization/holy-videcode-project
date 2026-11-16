import pickle, json, struct, bisect
from kc import load
k=load()
kmap=json.load(open('kmap.json'))
X=pickle.load(open('xreffull.pkl','rb'))
TEXT=[]
for e in kmap:
    for s in e.get('segs',[]):
        if s['fs'] and ('EXEC' in s['name'] or s['name']=='__TEXT'): TEXT.append((s['va'],s['va']+s['vs'],e['id']))
TEXT.sort(); TS=[t[0] for t in TEXT]
def in_text(va):
    i=bisect.bisect_right(TS,va)-1
    if i<0: return None
    lo,hi,eid=TEXT[i]; return eid if va<hi else None
def dec(q): return 0xfffffff007004000 + (q & 0x0FFFFFFF)
DC=k.seg_by_name['__DATA_CONST']; D0=DC['vmaddr']; D1=DC['vmaddr']+DC['filesize']
DATA=k.seg_by_name['__DATA']; E0=DATA['vmaddr']; E1=DATA['vmaddr']+DATA['filesize']
def in_data(va): return (D0<=va<D1) or (E0<=va<E1)
def entry(va):
    b=k.rd(va,0x20)
    if not b or len(b)<0x20: return None
    fn,sIn,strIn,sOut,strOut = struct.unpack_from('<QIIII', b, 0)
    return dec(fn),sIn,strIn,sOut,strOut
def ok(e, maxsmall=0x100000):
    if not e: return False
    fn,sIn,strIn,sOut,strOut=e
    if not in_text(fn) or (fn&3): return False
    UN=0xffffffff
    return sIn<=64 and sOut<=64 and (strIn==UN or strIn<=maxsmall) and (strOut==UN or strOut<=maxsmall)
def runlen(va, stride):
    n=0
    while True:
        e=entry(va+n*stride)
        if not ok(e): break
        if stride==0x28:
            t=k.rd(va+n*stride+0x18,8)
            if not t or struct.unpack('<Q',t)[0]!=0: break
        n+=1
        if n>400: break
    return n
cands={}
for tgt,pcs in X.items():
    if not in_data(tgt) or (tgt&7): continue
    e=entry(tgt)
    if not ok(e): continue
    n28=runlen(tgt,0x28); n18=runlen(tgt,0x18)
    if n28>=2 and n28>=n18: st,n=0x28,n28
    elif n18>=2: st,n=0x18,n18
    else: continue
    cands[tgt]=dict(va=tgt,stride=st,n=n,pc=sorted(set(pcs))[0],pcs=sorted(set(pcs)),
                    kext=in_text(e[0]), kext_pc=in_text(sorted(set(pcs))[0]))
print("candidates", len(cands))
json.dump(list(cands.values()), open('tables_ref.json','w'), indent=1)
import collections
c=collections.Counter(v['kext'] for v in cands.values())
for kk,v in c.most_common(25): print(f"{v:4d} {kk}")
