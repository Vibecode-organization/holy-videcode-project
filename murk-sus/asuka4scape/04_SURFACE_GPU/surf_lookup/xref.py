import struct, pickle, os, collections, kc
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM, arm64
def sxt(v,b): return v-(1<<b) if v&(1<<(b-1)) else v
MD = Cs(CS_ARCH_ARM64, CS_MODE_ARM); MD.detail=True
def build():
    idx=[]
    for name,vmaddr,vmsize,fileoff,filesize in kc.SEGS:
        if name not in ("__TEXT_EXEC","__PRELINK_TEXT","__TEXT_BOOT_EXEC"): continue
        for i in range(filesize//4):
            w=struct.unpack_from("<I",kc.BLOB,fileoff+i*4)[0]
            if (w & 0x9F000000)==0x90000000:
                pc=vmaddr+i*4
                imm=sxt((((w>>5)&0x7FFFF)<<2)|((w>>29)&3),21)<<12
                idx.append(((pc & ~0xFFF)+imm, fileoff+i*4, pc))
    return idx
P="adrp.idx"
IDX=pickle.load(open(P,"rb")) if os.path.exists(P) else build()
if not os.path.exists(P): pickle.dump(IDX,open(P,"wb"))
BY=collections.defaultdict(list)
for tgt,foff,pc in IDX: BY[tgt].append((foff,pc))

def refs(va, window=10, want=("add","ldr","str")):
    """sites whose resolved absolute address == va (adrp-anchored)."""
    out=[]
    for foff,pc in BY.get(va & ~0xFFF,[]):
        chunk=kc.BLOB[foff:foff+4*window]
        st={}
        for ins in MD.disasm(chunk,pc):
            o=ins.operands; m=ins.mnemonic
            if m=="adrp" and o[0].type==arm64.ARM64_OP_REG:
                st[ins.reg_name(o[0].reg)]=(o[1].imm & 0xFFFFFFFFFFFFFFFF, "imm")
                continue
            if m=="add" and len(o)==3 and o[2].type==arm64.ARM64_OP_IMM and o[1].type==arm64.ARM64_OP_REG:
                base=ins.reg_name(o[1].reg)
                if base in st:
                    val=(st[base][0]+o[2].imm)&0xFFFFFFFFFFFFFFFF
                    st[ins.reg_name(o[0].reg)]=(val,"imm")
                    if val==va: out.append((ins.address,"add",ins.reg_name(o[0].reg)))
                continue
            if m in ("ldr","ldrb","ldrh","ldrsw") and len(o)==2 and o[1].type==arm64.ARM64_OP_MEM:
                mem=o[1].mem; base=ins.reg_name(mem.base) if mem.base else None
                if base in st and mem.index==0:
                    val=(st[base][0]+mem.disp)&0xFFFFFFFFFFFFFFFF
                    if val==va: out.append((ins.address,m,ins.reg_name(o[0].reg)))
                    st[ins.reg_name(o[0].reg)]=(val,"mem")
                continue
            if m in ("str","stp","strb","strh","strw") and o and o[0].type==arm64.ARM64_OP_REG:
                mem=o[-1]
                if mem.type==arm64.ARM64_OP_MEM and mem.mem.base:
                    b=ins.reg_name(mem.mem.base)
                    if b in st and mem.mem.index==0:
                        val=(st[b][0]+mem.mem.disp)&0xFFFFFFFFFFFFFFFF
                        if val==va: out.append((ins.address,m,"?"))
            if m in ("ret","b","br"): pass
    return out
