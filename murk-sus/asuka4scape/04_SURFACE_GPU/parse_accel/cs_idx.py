# capstone streaming indexer, resumable on bad bytes
import capstone, kc, pickle, sys
C = capstone.arm64

md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
md.detail = True

def scan_seg(base, size, off):
    out = []
    state = {}
    start = 0
    d = kc.D
    while start < size:
        state.clear()
        last = start
        for ins in md.disasm(d[off+start: off+size], base+start):
            a = ins.address
            last = a - base
            m = ins.mnemonic
            ops = ins.operands
            if m == "adrp" and len(ops) == 2 and ops[1].type == C.ARM64_OP_IMM:
                state[ops[0].reg] = ops[1].imm & 0xFFFFFFFFFFFFFFFF
            elif m == "add" and len(ops) == 3 and ops[0].type == C.ARM64_OP_REG:
                rd = ops[0].reg
                if ops[1].type == C.ARM64_OP_REG and ops[1].reg in state and ops[2].type == C.ARM64_OP_IMM:
                    t = (state[ops[1].reg] + ops[2].imm) & 0xFFFFFFFFFFFFFFFF
                    out.append((a, t, "add", rd))
                    state[rd] = t
                else:
                    state.pop(rd, None)
            elif m == "ldr" and len(ops) == 2:
                rd = ops[0].reg
                mem = ops[1]
                if mem.type == C.ARM64_OP_MEM and mem.base in state and mem.index == 0:
                    out.append((a, (state[mem.base] + mem.disp) & 0xFFFFFFFFFFFFFFFF, "ldr", rd))
                state.pop(rd, None)
            elif m in ("bl", "b"):
                if ops and ops[0].type == C.ARM64_OP_IMM:
                    out.append((a, ops[0].imm & 0xFFFFFFFFFFFFFFFF, m, 0))
            else:
                for o in ops:
                    if o.type == C.ARM64_OP_REG and (o.access & capstone.CS_AC_WRITE):
                        state.pop(o.reg, None)
        start = last + 4
    return out

if __name__ == "__main__":
    out = []
    for name, base, size, off in kc.SEGS:
        if name in ("__TEXT_EXEC", "__PRELINK_TEXT"):
            o2 = scan_seg(base, size, off)
            print(name, len(o2), file=sys.stderr)
            out += o2
    pickle.dump(out, open("/home/femboychik/work/parse_accel/cs.pkl", "wb"))
    print("total", len(out))
