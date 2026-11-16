import sys, struct, json
sys.path.insert(0,'.')
from kmap import *
import re
EXEC=[("__TEXT_EXEC",0xfffffff00814c000,0x2924000,0x1148000,0x2924000),
      ("__PRELINK_TEXT",0xfffffff00700c000,0xbac000,0x8000,0xbac000),
      ("__TEXT_BOOT_EXEC",0xfffffff00aa70000,0x8000,0x3a6c000,0x8000),
      ("__TEXT",0xfffffff007004000,0x8000,0x0,0x8000)]
def hits():
    out=[]
    for name,sva,vs,fo,fs in EXEC:
        buf=D[fo:fo+fs]
        n=len(buf)//4
        w=struct.unpack_from('<%dI'%n,buf,0)
        for i,x in enumerate(w):
            if (x & 0xFFC00000)==0xF9400000 and ((x>>10)&0xFFF)==0x0F:
                out.append(('ldr',sva+i*4,x))
            elif (x & 0xFFC00000)==0xF9000000 and ((x>>10)&0xFFF)==0x0F:
                out.append(('str',sva+i*4,x))
            elif (x & 0xFFC00000)==0x91000000 and ((x>>10)&0xFFF)==0x78:
                out.append(('add',sva+i*4,x))
    return out
if __name__=="__main__":
    h=hits()
    from collections import Counter
    print(Counter(t for t,_,_ in h))
    json.dump([[t,a,w] for t,a,w in h],open('raw_hits.json','w'))
    for t,a,w in h:
        if t=='ldr':
            rt=w&31; rn=(w>>5)&31
            print(hex(a),hex(w),"ldr x%d,[x%d,#0x78]"%(rt,rn),kext_of(a) if False else "")
