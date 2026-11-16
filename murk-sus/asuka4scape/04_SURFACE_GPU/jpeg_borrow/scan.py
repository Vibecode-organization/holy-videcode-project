import struct, json, sys
KC="/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache"
D=open(KC,'rb').read()
BASE=0xfffffff007004000
SEGS={}  # name -> (va, foff, fsz)
# top-level segs (already known); keep uniform mapping
def seg_of(va):
    for n,(v,o,s) in SEGS.items():
        if v<=va<v+s: return n
    return None
# build from parse
import struct as st
off=32
for i in range(st.unpack_from('<I',D,16)[0]):
    cmd,cs=st.unpack_from('<II',D,off)
    if cmd==0x19:
        nm=D[off+8:off+24].rstrip(b'\0').decode()
        va,vs,fo,fs=st.unpack_from('<QQQQ',D,off+24)
        SEGS[nm]=(va,fo,fs)
    off+=cs

def scan(segname, targets):
    va0,fo,fsz=SEGS[segname]
    words=st.unpack_from('<%dI'%(fsz//4),D,fo)
    hits=[]
    for i,w in enumerate(words):
        # load/store immediate, unsigned offset forms
        op=w&0xFFC00000
        # LDR/STR 64 (F94/F90), 32 (B94/B90), byte(394/390), halfword(794/790), LDRSW(B98), PRFM(F98)
        for pat,scale,kind in ((0xF9400000,8,'ldr64'),(0xF9000000,8,'str64'),
                               (0xB9400000,4,'ldr32'),(0xB9000000,4,'str32'),
                               (0x39400000,1,'ldrb'),(0x39000000,1,'strb'),
                               (0x79400000,2,'ldrh'),(0x79000000,2,'strh'),
                               (0xF9800000,8,'ldrsw'),):
            if op==pat:
                imm=((w>>10)&0xFFF)*scale
                if imm in targets:
                    hits.append((va0+i*4,kind,imm,(w>>5)&0x1F,w&0x1F,w))
                break
    return hits

# kext ranges
pre=json.load(open('prelink.json'))
def u(x): return int(x) if isinstance(x,str) else x
ks=[]
for d in pre:
    la=d.get('_PrelinkExecutableLoadAddr'); sz=d.get('_PrelinkExecutableSize')
    if la is None: continue
    la=u(la)
    if la<0: la&=0xFFFFFFFFFFFFFFFF
    ks.append((la,u(sz),d.get('CFBundleIdentifier')))
ks.sort()
import bisect
def kext(va):
    i=bisect.bisect_right([x[0] for x in ks],va)-1
    if i<0: return None
    la,sz,bid=ks[i]
    return bid if va<la+sz+0x4000000 else None

T=set([0x4c8])
for sn in ('__TEXT_EXEC','__PRELINK_TEXT','__TEXT'):
    h=scan(sn,T)
    for a,kind,imm,rn,rt,w in h:
        print("%#012x %-6s imm=%#x rn=x%d rt=x%d kext=%s"%(a,kind,imm,rn,rt,kext(a)))
