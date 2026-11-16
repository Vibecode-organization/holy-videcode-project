#!/usr/bin/env python3
# global bl/b/tail scan over executable segments (pure arithmetic, no full disasm)
import struct, sys, pickle
import kc2

def scan_calls():
    out=[]
    for segname in ("__TEXT_EXEC","__PRELINK_TEXT","__TEXT"):
        for n,s,sz,o in kc2.SEGS:
            if n!=segname: continue
            blob=kc2.DATA[o:o+sz]
            for i in range(0,len(blob)-4,4):
                w=struct.unpack_from('<I',blob,i)[0]
                if (w & 0xFC000000)==0x94000000:
                    imm=w & 0x03FFFFFF
                    if imm & 0x02000000: imm-=0x04000000
                    t=(s+i+imm*4)&kc2.M64
                    out.append((s+i,t,'bl'))
                elif (w & 0xFC000000)==0x14000000:
                    imm=w & 0x03FFFFFF
                    if imm & 0x02000000: imm-=0x04000000
                    t=(s+i+imm*4)&kc2.M64
                    out.append((s+i,t,'b'))
    return out

if __name__=="__main__":
    c=scan_calls()
    pickle.dump(c,open('allcalls.pkl','wb'))
    print(len(c))
