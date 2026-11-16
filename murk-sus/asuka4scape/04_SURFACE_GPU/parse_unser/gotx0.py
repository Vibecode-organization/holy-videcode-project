import struct, pickle
from kc import KC, KC27_0, SEGS
import xr
# patch SEGS for 27.0? mapping offsets are identical (va-0x7004000), so reuse
kc=KC(KC27_0)
out={}
for n,sva,so,sz,ex in xr.text_segs():
    W=struct.unpack('<%dI'%(sz//4), kc.d[so:so+sz])
    for i,w in enumerate(W):
        r=xr.dec_adrp(w, sva+i*4)
        if not r: continue
        rd,page=r
        for j in range(i+1,min(i+4,len(W))):
            l=xr.dec_ldr_imm(W[j])
            if l and l[1]==rd:
                out[sva+i*4]=page+l[2]; break
            a=xr.dec_add_imm(W[j])
            if a and a[1]==rd:
                out[sva+i*4]=(page+a[2],'add'); break
pickle.dump(out,open('adrprefs0.pkl','wb'))
print('pairs',len(out))
