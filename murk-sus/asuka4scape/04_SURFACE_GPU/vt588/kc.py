import struct, bisect, subprocess
P="/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache"
D=open(P,'rb').read()
BASE=0xfffffff007004000
FIX=0x401c000
SEGS=[(0xfffffff007004000,0x8000,0x0),(0xfffffff00700c000,0xbac000,0x8000),
(0xfffffff007bb8000,0x548000,0xbb4000),(0xfffffff008100000,0x4c000,0x10fc000),
(0xfffffff00814c000,0x2924000,0x1148000),(0xfffffff00aa70000,0x8000,0x3a6c000),
(0xfffffff00aa78000,0x23c000,0x3a74000),(0xfffffff00acb4000,0x2b8000,0x3cb0000),
(0xfffffff00af6c000,0xb8000,0x3f68000)]
_segva=[s[0] for s in SEGS]
def voff(va):
    # file offset from VA
    i=bisect.bisect_right(_segva,va)-1
    va0,sz,fo=SEGS[i]
    return fo+(va-va0)
def off2va(off):
    for va0,sz,fo in SEGS:
        if fo<=off<fo+sz: return va0+(off-fo)
    return None
def q(va): return struct.unpack_from('<Q',D,voff(va))[0]
def u32(va): return struct.unpack_from('<I',D,voff(va))[0]

# ---- chained fixups ----
starts=struct.unpack_from('<I',D,FIX+4)[0]
sc,=struct.unpack_from('<I',D,FIX+starts)
offs=struct.unpack_from('<%dI'%sc,D,FIX+starts+4)
PTR={}   # va -> target va (unslid) decoded from chain
for segi in range(sc):
    if offs[segi]==0: continue
    o=FIX+starts+offs[segi]
    size,page_size,pf,segoff,maxvalid,pagecnt=struct.unpack_from('<IHHQIH',D,o)
    ps=struct.unpack_from('<%dH'%pagecnt,D,o+22)
    tbl=o+22+pagecnt*2
    for pi in range(pagecnt):
        if ps[pi]==0xFFFF: continue
        cur=segoff+pi*page_size+ps[pi]*8
        while True:
            off=cur
            raw,=struct.unpack_from('<Q',D,off)
            auth=(raw>>63)&1; bind=(raw>>62)&1
            nxt=(raw>>51)&0x7FF
            if not bind:
                tgt=raw & 0x3FFFFFFF
                PTR[off2va(off)]=BASE+tgt
            cur+=nxt*4
            if nxt==0: break
            if cur>=segoff+(pi+1)*page_size: break
def fixptr(va):
    return PTR.get(va)
def ptr(va):
    # returns decoded pointer if chained, else raw q
    v=PTR.get(va)
    return v if v is not None else q(va)

import capstone
md=capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
md.detail=True
M64=(1<<64)-1
def dis(va,n=40,verbose=False):
    out=[]
    off=voff(va)
    code=D[off:off+n*4]
    for ins in md.disasm(code,va):
        out.append(ins)
    return out
def show(va,n=40):
    for ins in dis(va,n):
        print("%016x: %-8s %s"%(ins.address,ins.mnemonic,ins.op_str))
def refs_to(target,limit=40):
    """find adrp+add or literal ptr refs to target"""
    res=[]
    lo,hi=SEGS[4][0],SEGS[4][0]+SEGS[4][1]
    # scan __TEXT_EXEC for adrp;add pairs up to 3 instr apart
    off=voff(lo); end=voff(hi)
    import re
    for m in re.finditer(b'\x00\x00\x00',D[off:end]):
        pass
