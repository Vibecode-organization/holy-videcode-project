import struct, capstone, kc, collections
C = capstone.arm64
md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
md.detail = True

ADRP = []   # (off_in_file, va)
_d = kc.D
for name, base, size, off in kc.SEGS:
    if name not in ("__TEXT_EXEC","__PRELINK_TEXT"): continue
    for i in range(size//4):
        w = struct.unpack_from("<I", _d, off+i*4)[0]
        if (w & 0x9F000000) == 0x90000000:
            ADRP.append((off+i*4, base+i*4, w))

def sxt(v,b): return v-(1<<b) if v&(1<<(b-1)) else v
def adrp_target(pc, w):
    imm = sxt((((w>>5)&0x7FFFF)<<2)|((w>>29)&3), 21)<<12
    return (pc & ~0xFFF) + imm

BY_PAGE = collections.defaultdict(list)
for foff, pc, w in ADRP:
    BY_PAGE[adrp_target(pc,w)].append((foff,pc))

def find_refs(va, maxn=40):
    page = va & ~0xFFF
    out = []
    for foff, pc in BY_PAGE.get(page, []):
        chunk = kc.D[foff: foff+4*maxn]
        reg = None
        for ins in md.disasm(chunk, pc):
            m, ops = ins.mnemonic, ins.operands
            if m == "adrp" and ins.address == pc:
                reg = ops[0].reg
            elif m == "add" and len(ops)==3 and ops[0].type==C.ARM64_OP_REG and ops[1].type==C.ARM64_OP_REG \
                 and ops[1].reg==reg and ops[2].type==C.ARM64_OP_IMM:
                if ((page + ops[2].imm) & 0xFFFFFFFFFFFFFFFF) == va:
                    out.append((ins.address, "add", ops[0].reg))
                reg = ops[0].reg if ops[0].reg == reg else None
            elif len(ops)>=1 and ops[0].type==C.ARM64_OP_REG and (ops[0].access & capstone.CS_AC_WRITE) and ops[0].reg!=reg:
                if ops[0].reg == reg: reg=None
            if m in ("ret","br"): break
    return out
