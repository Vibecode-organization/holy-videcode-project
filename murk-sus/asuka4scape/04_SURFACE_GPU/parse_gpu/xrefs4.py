import numpy as np, pickle, collections
from kc import load
k=load()
s=k.seg_by_name['__TEXT_EXEC']; TEXT_BASE=s['vmaddr']
n=s['filesize']//4
words=np.frombuffer(k.data, dtype='<u4', count=n, offset=s['fileoff'])
idx=np.load('adrp_idx.npy').astype(np.int64); rd=np.load('adrp_rd.npy').astype(np.int64); page=np.load('adrp_page.npy').astype(np.uint64)
W=lambda j: int(words[j]) if 0<=j<n else None
pairs=[]
for ii in range(len(idx)):
    a=int(idx[ii]); reg=int(rd[ii]); cur=int(page[ii]); start=TEXT_BASE+a*4
    pairs.append((cur,start))
    for j in range(a+1, a+9):
        w=W(j)
        if w is None: break
        if (w & 0xFF800000)==0x91000000:  # add imm
            rn=(w>>5)&0x1F; rdd=w&0x1F; imm12=(w>>10)&0xFFF; sh=(w>>22)&1
            if rn==reg and rdd==reg and imm12:
                cur += (imm12<<12) if sh else imm12
                pairs.append((cur,start)); continue
        if (w & 0xFF800000)==0xD1000000:  # sub imm
            rn=(w>>5)&0x1F; rdd=w&0x1F; imm12=(w>>10)&0xFFF; sh=(w>>22)&1
            if rn==reg and rdd==reg and imm12:
                cur -= (imm12<<12) if sh else imm12
                pairs.append((cur,start)); continue
        if (w & 0x7F800000)==0x11000000:  # add imm 32-bit (w reg) -> ignore value
            pass
        # stop if register redefined by something else
        if ((w & 0xFF800000) in (0x91000000,0xD1000000)) and ((w&0x1F)==reg) and ((w>>5)&0x1F)!=reg:
            break
        if (w & 0x9F000000)==0x90000000 and (w&0x1F)==reg:
            break
    # end
d=collections.defaultdict(list)
for t,pc in pairs: d[t].append(pc)
pickle.dump(dict(d), open('xreffull.pkl','wb'))
print("pairs",len(pairs),"targets",len(d))
for t in (0xfffffff008068b90,0xfffffff008068bb8,0xfffffff008069518,0xfffffff008068d70,0xfffffff0080696d0,
          0xfffffff007fea200,0xfffffff007fea2d8,0xfffffff007fea818,0xfffffff007feac88,0xfffffff007e293c0):
    print(f"{t:#018x} -> {[hex(p) for p in sorted(set(d.get(t,[])))]}")
