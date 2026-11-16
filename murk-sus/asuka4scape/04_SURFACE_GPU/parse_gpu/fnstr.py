import sys, re, json
from kc import load
k=load()
kmap=json.load(open('kmap.json'))
SEG=[]
for e in kmap:
    for s in e.get('segs',[]):
        if s['fs']: SEG.append((s['va'],s['va']+s['vs'],e['id'],s['name']))
SEG.sort()
import bisect
ST=[s[0] for s in SEG]
def seginfo(va):
    i=bisect.bisect_right(ST,va)-1
    if i<0: return None
    lo,hi,kid,n=SEG[i]
    return (kid,n) if va<hi else None
def strs(va, window=64):
    # crude: scan forward up to window instructions for adrp/add targets that look like cstrings
    import struct
    from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
    md=Cs(CS_ARCH_ARM64,CS_MODE_ARM)
    o=k.off(va); out=set()
    ins=list(md.disasm(k.data[o:o+window*4], va))
    regs={}
    for i in ins:
        if i.mnemonic=='adrp':
            r,imm=i.op_str.split(', ')
            imm=int(imm.strip('#'),16)
            regs[r]=imm
        elif i.mnemonic=='add' and ',' in i.op_str:
            parts=[x.strip() for x in i.op_str.split(',')]
            if len(parts)==3 and parts[1] in regs and parts[2].startswith('#'):
                try: lo=int(parts[2][1:],16)
                except: continue
                tgt=regs[parts[1]]+lo
                b=k.rd(tgt,64)
                if b:
                    z=b.find(b'\0')
                    if 3<z<64:
                        s=b[:z]
                        if all(0x20<=c<0x7f for c in s): out.add((tgt,s.decode()))
    return sorted(out)
if __name__=='__main__':
    va=int(sys.argv[1],16); w=int(sys.argv[2]) if len(sys.argv)>2 else 64
    print("seginfo", seginfo(va))
    for t,s in strs(va,w): print(f"  {t:#x}  {s}")
