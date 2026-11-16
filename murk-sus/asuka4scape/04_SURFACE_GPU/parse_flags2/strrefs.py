import struct, sys
from kcd import data, SECTIONS, va2off
def cstr(va,n=100):
    o=va2off(va); b=b''
    for i in range(n):
        c=data[o+i]
        if c==0: break
        b+=bytes([c])
    return b.decode('utf-8','replace')
def sx(v,b): return v-(1<<b) if v&(1<<(b-1)) else v
def refs(start,end,lo=0xfffffff00789b000,hi=0xfffffff0078b0000):
    words=struct.unpack_from('<%dI'%((end-start)//4), data, va2off(start))
    out=[]
    for i,w in enumerate(words):
        if (w & 0x9F000000)==0x90000000:
            immlo=(w>>29)&3; immhi=(w>>5)&0x7FFFF
            imm=sx((immhi<<2)|immlo,21)<<12
            rd=w&0x1F; pc=start+i*4; page=(pc&~0xFFF)+imm
            for j in range(1,4):
                if i+j>=len(words): break
                w2=words[i+j]
                if (w2 & 0x7F000000)==0x11000000 and (w2&0x1F)==rd and ((w2>>5)&0x1F)==rd:
                    sh=(w2>>22)&1; a=((w2>>10)&0xFFF)<<(12 if sh else 0)
                    t=page+a
                    if lo<=t<hi:
                        s=cstr(t)
                        if len(s)>4: out.append((start+i*4,t,s))
                    break
    return out
if __name__=='__main__':
    s=int(sys.argv[1],16); e=int(sys.argv[2],16)
    for a,t,x in refs(s,e): print(f"0x{a:x} -> 0x{t:x} {x!r}")
