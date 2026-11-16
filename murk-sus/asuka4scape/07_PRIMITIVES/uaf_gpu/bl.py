from kc import *
import struct,sys
M64=0xFFFFFFFFFFFFFFFF
def build_bl_index():
    idx={}
    for n,sv,sz,off in SEGS:
        if n not in ("__TEXT_EXEC","__TEXT","__PRELINK_TEXT","__TEXT_BOOT_EXEC"): continue
        p=off; end=off+sz-4
        while p<end:
            w=struct.unpack_from("<I",DATA,p)[0]
            pc=sv+(p-off)
            if (w & 0xFC000000)==0x94000000:      # BL
                imm=(w & 0x3FFFFFF)
                if imm & (1<<25): imm|=~0x3FFFFFF & M64
                imm=(imm<<2)&M64
                if imm&(1<<27): imm|=0xFFFFFFF000000000
                idx.setdefault((pc+imm)&M64,[]).append(pc)
            elif (w & 0xFC000000)==0x14000000:    # B
                imm=(w & 0x3FFFFFF)
                if imm & (1<<25): imm|=~0x3FFFFFF & M64
                imm=(imm<<2)&M64
                if imm&(1<<27): imm|=0xFFFFFFF000000000
                idx.setdefault((pc+imm)&M64,[]).append(pc)
            p+=4
    return idx
if __name__=="__main__":
    print("building...",file=sys.stderr)
    idx=build_bl_index()
    for a in sys.argv[1:]:
        va=int(a,0)
        print(f"== callers of {va:#x}: {len(idx.get(va,[]))}")
        for c in idx.get(va,[]): print(f"   {c:#x}")
