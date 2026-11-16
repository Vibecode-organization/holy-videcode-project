import struct, json
P="/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache"
D=open(P,'rb').read()
BASE=0xfffffff007004000
FIX=0x401c000
STARTS=struct.unpack_from('<I',D,FIX+4)[0]

def decode_seg(segi):
    o=FIX+STARTS+struct.unpack_from('<I',D,FIX+STARTS+4)[0] if False else None

segs={}
starts=struct.unpack_from('<I',D,FIX+4)[0]
sc,=struct.unpack_from('<I',D,FIX+starts)
offs=struct.unpack_from('<%dI'%sc,D,FIX+starts+4)
SEGINFO=[(0xfffffff007004000,0x8000,0x0),(0xfffffff00700c000,0xbac000,0x8000),
(0xfffffff007bb8000,0x548000,0xbb4000),(0xfffffff008100000,0x4c000,0x10fc000),
(0xfffffff00814c000,0x2924000,0x1148000),(0xfffffff00aa70000,0x8000,0x3a6c000),
(0xfffffff00aa78000,0x23c000,0x3a74000),(0xfffffff00acb4000,0x2b8000,0x3cb0000),
(0xfffffff00af6c000,0xb8000,0x3f68000)]

ptrs={}  # file_offset -> va (unslid, unsiged)
for segi in range(sc):
    if offs[segi]==0: continue
    o=FIX+STARTS+offs[segi]
    size,page_size,pf,segoff,maxvalid,pagecnt=struct.unpack_from('<IHHQIH',D,o)
    ps=struct.unpack_from('<%dH'%pagecnt,D,o+22)
    for pi,psv in enumerate(ps):
        if psv==0xffff: continue
        # chains may overflow to next page
        po=o+22+pagecnt*2+psv
        cur=pi
        while True:
            val,=struct.unpack_from('<Q',D,po)
            nxt=(val>>51)&0x7ff
            is_bind=(val>>63)&1
            is_auth=(val>>62)&1
            if is_bind:
                tgt=None
            else:
                tgt=(val & 0x3FFFFFFF)
                ptrs[segoff+cur*page_size+(po-(o+22+pagecnt*2)-psv if False else 0)]=0
            # chain offset tracking: entries live at page+chain_off
            po+=8
            if nxt==0:
                break
            if nxt>=0xC00:  # 0xC00..0xFFF -> next page at (nxt-0xC00)*8
                cur = pi+1
                po = o+22+pagecnt*2+(nxt-0xC00)*8
            else:
                po = po-8+nxt*8
