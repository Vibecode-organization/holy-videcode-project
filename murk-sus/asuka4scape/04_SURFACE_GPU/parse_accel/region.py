import capstone, kc
C = capstone.arm64
md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
md.detail = True
M = 0xFFFFFFFFFFFFFFFF
def scan(base, size):
    out = []
    state = {}
    start = 0
    while start < size:
        state.clear(); last = start
        for ins in md.disasm(kc.D[kc.va2off(base)+start: kc.va2off(base)+size], base+start):
            a = ins.address; last = a-base
            m = ins.mnemonic; ops = ins.operands
            if m == "adrp" and len(ops)==2:
                state[ops[0].reg] = ops[1].imm & M
            elif m == "add" and len(ops)==3 and ops[0].type==C.ARM64_OP_REG:
                rd=ops[0].reg
                if ops[1].type==C.ARM64_OP_REG and ops[1].reg in state and ops[2].type==C.ARM64_OP_IMM:
                    t=(state[ops[1].reg]+ops[2].imm)&M; out.append((a,t,"add",rd)); state[rd]=t
                else: state.pop(rd,None)
            elif m == "ldr" and len(ops)==2:
                rd=ops[0].reg; mem=ops[1]
                if mem.type==C.ARM64_OP_MEM and mem.mem.base in state and mem.mem.index==0:
                    out.append((a,(state[mem.mem.base]+mem.mem.disp)&M,"ldr",rd))
                state.pop(rd,None)
            elif m in ("bl","b"):
                if ops and ops[0].type==C.ARM64_OP_IMM: out.append((a, ops[0].imm & M, m, 0))
            else:
                for o in ops:
                    if o.type==C.ARM64_OP_REG and (o.access & capstone.CS_AC_WRITE): state.pop(o.reg,None)
        start = last+4
    return out
