import sys, struct, json
sys.path.insert(0,'.')
from kmap import *
PAC=0x8050bcad
DMIN=0xfffffff007004000; DMAX=DMIN+0x4020000
def is_pac_fn(v):
    if (v>>32)!=PAC: return False
    lo=v & 0x0FFFFFFF
    return lo < 0x4020000
def fn_va(v): return DMIN+(v & 0x0FFFFFFF)
def plausible(x):
    return x==0 or x==0xffffffff or x<0x200000
def scan_seg(name,sva,vs,fo,fs):
    ents=[]
    n=fs//8
    buf=D[fo:fo+fs]
    for i in range(n):
        v=struct.unpack_from('<Q',buf,i*8)[0]
        if is_pac_fn(v): ents.append((sva+i*8,v))
    return ents
CAND=[]
for name,sva,vs,fo,fs in [("__DATA_CONST",0xfffffff007bb8000,0x548000,0xbb4000,0x548000),
                          ("__DATA",0xfffffff00acb4000,0x2b8000,0x3cb0000,0x2b8000)]:
    for a,v in scan_seg(name,sva,vs,fo,fs): CAND.append((name,a,v))
print("pac ptr candidates",len(CAND))
# table building
tables=[]
used=set()
CAND.sort(key=lambda c:c[1])
addrmap={a:(n,v) for n,a,v in CAND}
for n,a,v in CAND:
    if a in used: continue
    row=[(a,v)]
    cur=a
    while True:
        nxt=cur+0x28
        if nxt in addrmap:
            row.append((nxt,addrmap[nxt][1])); used.add(nxt); cur=nxt
            continue
        break
    used.add(a)
    if len(row)>=2:
        # validate middle fields
        okall=True
        for i in range(len(row)-1):
            b=row[i][0]
            f=[u32(b+8+k*4) for k in range(4)]
            fl=u32(b+0x24)
            if not all(plausible(x) for x in f) or fl>0x10000: okall=False
        if okall: tables.append(row)
print("tables",len(tables),"entries",sum(len(t) for t in tables))
info=[]
for t in tables:
    fns=[fn_va(v) for a,v in t]
    ks={}
    for f in fns:
        k=kext_of(f) or "xnu/unknown"
        ks[k]=ks.get(k,0)+1
    info.append({'addr':t[0][0],'n':len(t),'fmin':min(fns),'fmax':max(fns),
                 'kexts':sorted(ks.items(),key=lambda x:-x[1]),'entries':[[a,fn_va(v)] for a,v in t]})
info.sort(key=lambda x:-x['n'])
json.dump(info,open('tables.json','w'),indent=1)
for i in info[:25]:
    print(hex(i['addr']),i['n'],hex(i['fmin']),hex(i['fmax']),i['kexts'][0][0])
