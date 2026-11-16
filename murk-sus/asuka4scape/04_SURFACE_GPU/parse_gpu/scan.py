import json, struct, bisect
from kc import load
k = load()
kmap = json.load(open('kmap.json'))
TEXT=[]
for e in kmap:
    for s in e.get('segs',[]):
        if s['fs'] and ('EXEC' in s['name'] or s['name']=='__TEXT'):
            TEXT.append((s['va'], s['va']+s['vs'], e['id']))
TEXT.sort(); TSTARTS=[t[0] for t in TEXT]
def in_text(va):
    i=bisect.bisect_right(TSTARTS,va)-1
    if i<0: return None
    lo,hi,eid=TEXT[i]
    return eid if va<hi else None
def dec(q): return 0xfffffff007004000 + (q & 0x0FFFFFFF)

def scan(segname, stride, maxsmall=0x20000, maxsc=64, minrun=3):
    s=k.seg_by_name[segname]
    base=s['vmaddr']; n=s['filesize']
    data=k.data[s['fileoff']:s['fileoff']+n]
    nent = n//8
    qs=struct.unpack_from('<%dQ'%nent, data, 0)
    valid={}
    for i in range(nent):
        fn=dec(qs[i])
        eid=in_text(fn)
        if eid and (fn&3)==0:
            valid[i]=fn
    res=[]
    i=0
    while i<nent:
        if i in valid:
            # try run
            run=[]
            j=i
            while j<nent and j in valid:
                off=j*8
                if off+0x20<=n:
                    sIn,strIn,sOut,strOut = struct.unpack_from('<IIII', data, off+8)
                    tail = struct.unpack_from('<II', data, off+24) if stride>=0x20 else (0,0)
                    good = (sIn<=maxsc and strIn<=maxsmall and sOut<=maxsc and strOut<=maxsmall)
                    if stride==0x18:
                        good = good and off+0x18<=n
                    else:
                        good = good and tail==(0,0)
                    if good:
                        run.append((base+off, valid[j], sIn, strIn, sOut, strOut, tail))
                        j+=stride//8
                        continue
                break
            if len(run)>=minrun:
                res.append(dict(seg=segname, stride=stride, va=base+i*8, n=len(run), entries=run))
                i=j
                continue
        i+=1
    return res

all_t=[]
for seg in ('__DATA_CONST','__DATA','__DATA_SPTM'):
    for st in (0x28,0x18):
        r=scan(seg,st)
        for t in r: t['kext']=in_text(t['entries'][0][1])
        all_t+=r
        print(f"{seg} stride={st:#x}: {len(r)} tables")
json.dump(all_t, open('tables_all.json','w'), indent=1)
print("TOTAL", len(all_t))
