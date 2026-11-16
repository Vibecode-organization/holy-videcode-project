import numpy as np, json, pickle
from kc import load
k=load()
s=k.seg_by_name['__TEXT_EXEC']
TEXT_BASE=s['vmaddr']
words=np.frombuffer(k.data, dtype='<u4', count=s['filesize']//4, offset=s['fileoff'])
idx=np.load('adrp_idx.npy'); rd=np.load('adrp_rd.npy'); page=np.load('adrp_page.npy')
adrp_at={int(i):(int(r),int(p)) for i,r,p in zip(idx,rd,page)}
# add (immediate) 64-bit: sf=1 op=0 S=0 100010 sh imm12 Rn Rd  => mask 0x7F800000 == 0x11000000 with bit31 set
am = (words & np.uint32(0xFF800000)) == np.uint32(0x91000000)
aidx = np.nonzero(am)[0]
print("add-imm count", len(aidx))
pairs=[]
for j in aidx:
    w=int(words[j])
    rn=(w>>5)&0x1F; rdd=w&0x1F; imm12=(w>>10)&0xFFF
    if rn!=rdd: continue
    for back in (1,2,3):
        a=int(j)-back
        if a in adrp_at:
            ar,ap=adrp_at[a]
            if ar==rdd:
                pairs.append((ap+imm12, TEXT_BASE+a*4))
                break
print("adrp/add pairs", len(pairs))
import collections
d=collections.defaultdict(list)
for t,pc in pairs: d[t].append(pc)
pickle.dump(dict(d), open('xreffull.pkl','wb'))
print("distinct targets", len(d))
