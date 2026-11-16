import numpy as np, pickle, collections
from kc import load
k=load()
s=k.seg_by_name['__TEXT_EXEC']; TEXT_BASE=s['vmaddr']
words=np.frombuffer(k.data, dtype='<u4', count=s['filesize']//4, offset=s['fileoff'])
idx=np.load('adrp_idx.npy'); rd=np.load('adrp_rd.npy'); page=np.load('adrp_page.npy')
adrp_at={int(i):(int(r),int(p)) for i,r,p in zip(idx,rd,page)}
am=(words & np.uint32(0xFF800000)) == np.uint32(0x91000000)
aidx=np.nonzero(am)[0]
pairs=[]
for j in aidx:
    w=int(words[j]); rn=(w>>5)&0x1F; rdd=w&0x1F; imm12=(w>>10)&0xFFF; sh=(w>>22)&1
    if rn!=rdd: continue
    off = imm12<<12 if sh else imm12
    for back in range(1,7):
        a=int(j)-back
        if a in adrp_at:
            ar,ap=adrp_at[a]
            if ar==rdd:
                pairs.append((ap+off, TEXT_BASE+a*4)); break
d=collections.defaultdict(list)
for t,pc in pairs: d[t].append(pc)
pickle.dump(dict(d), open('xreffull.pkl','wb'))
print("pairs",len(pairs),"targets",len(d))
tabs=[0xfffffff008068b90,0xfffffff008068bb8,0xfffffff008069518,0xfffffff008068d70,0xfffffff0080696d0,
      0xfffffff007fea200,0xfffffff007fea2d8,0xfffffff007fea818,0xfffffff007feac88]
for t in tabs:
    print(f"{t:#018x} -> {[hex(p) for p in sorted(set(d.get(t,[])))]}")
