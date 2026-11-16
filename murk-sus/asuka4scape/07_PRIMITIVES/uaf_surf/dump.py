#!/usr/bin/env python3
"""disassemble a VA range into /tmp/opencode/uaf_surf.txt with annotations."""
import kc, sys
from capstone.arm64 import ARM64_OP_REG, ARM64_OP_MEM, ARM64_OP_IMM

def annotate(a, i, regs):
    note = ""
    m = i.mnemonic
    ops = i.operands
    if m == "adrp":
        regs[ops[0].reg] = ops[1].imm & 0xFFFFFFFFFFFFFFFF
    elif m == "add" and len(ops) == 3 and ops[1].type == ARM64_OP_REG:
        if ops[1].reg in regs:
            v = regs[ops[1].reg] + ops[2].imm
            regs[ops[0].reg] = v
            note = f"; = {v:016x}"
    elif m in ("ldr",) and len(ops) == 2 and ops[1].type == ARM64_OP_MEM:
        base = ops[1].mem.base
        off = ops[1].mem.disp
        if base == 0:
            v = 0 + off
            note = ""
        if base in regs:
            note = f"; [{regs[base]+off:016x}]"
    elif m in ("b", "bl") and len(ops) == 1 and ops[0].type == ARM64_OP_IMM:
        note = f"; -> {ops[0].imm & 0xFFFFFFFFFFFFFFFF:016x}"
    return note

def main(a0, a1, out):
    regs = {}
    n = (a1 - a0)//4
    with open(out, "w") as f:
        for a, i in kc.dis(a0, n, stop_ret=False):
            if i.mnemonic == "bti" and i.op_str == "c":
                regs = {}
            note = annotate(a, i, regs)
            f.write(f"{a:016x}: {i.mnemonic:9s} {i.op_str:40s} {note}\n")
    print("wrote", out)

if __name__ == "__main__":
    main(int(sys.argv[1], 16), int(sys.argv[2], 16), sys.argv[3])
