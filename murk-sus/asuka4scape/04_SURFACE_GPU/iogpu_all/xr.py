from kc import *
import struct
M64=0xFFFFFFFFFFFFFFFF

def build_adrp_add_index(segs=("__TEXT_EXEC","__TEXT","__PRELINK_TEXT"), limit=None):
    """return dict target_va -> list of (insn_va)"""
    idx={}
    for n,sv,sz,off in SEGS:
        if n not in segs: continue
        p=off; end=off+sz-8
        prev=None
        while p<end:
            w=struct.unpack_from("<I",DATA,p)[0]
            pc=sv+(p-off)
            if (w & 0x9F000000)==0x90000000:
                imm=((w>>29)&3)|(((w>>5)&0x7FFFF)<<2)
                imm=(imm<<12)&M64
                if imm&(1<<32): imm|=0xFFFFFFFE00000000
                prev=((pc & ~0xFFF)+imm)&M64
                p+=4; continue
            if prev is not None and (w & 0xFF800000)==0x91000000:
                imm12=(w>>10)&0xFFF; sh=(w>>22)&1
                if sh: imm12<<=12
                tgt=(prev+imm12)&M64
                idx.setdefault(tgt,[]).append(pc)
            prev=None
            p+=4
    return idx

def xrefs(target, idx=None):
    global _IDX
    try: _IDX
    except NameError: _IDX=None
    if idx is None:
        if _IDX is None: _IDX=build_adrp_add_index()
        idx=_IDX
    return idx.get(target&M64,[])
