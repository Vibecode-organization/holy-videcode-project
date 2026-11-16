import struct, pickle, os, kc
def sxt(v,b): return v-(1<<b) if v&(1<<(b-1)) else v
def scan():
    out=[]
    for name,vmaddr,vmsize,fileoff,filesize in kc.SEGS:
        if name not in ("__TEXT_EXEC",): continue
        n=filesize//4
        for i in range(n):
            w=struct.unpack_from("<I",kc.BLOB,fileoff+i*4)[0]
            if (w & 0xFC000000)==0x94000000:   # bl
                pc=vmaddr+i*4
                out.append((pc,(pc+(sxt(w&0x3FFFFFF,26)<<2))&0xFFFFFFFFFFFFFFFF,"bl"))
            elif (w & 0xFC000000)==0x14000000: # b
                pc=vmaddr+i*4
                out.append((pc,(pc+(sxt(w&0x3FFFFFF,26)<<2))&0xFFFFFFFFFFFFFFFF,"b"))
    return out
P="br.idx"
BR=pickle.load(open(P,"rb")) if os.path.exists(P) else scan()
if not os.path.exists(P): pickle.dump(BR,open(P,"wb"))
CALLERS={}
for pc,t,k in BR: CALLERS.setdefault(t,[]).append((pc,k))
