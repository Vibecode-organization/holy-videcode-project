#!/usr/bin/env python3
# scan __TEXT_EXEC for adrp/add pairs that compute a given VA (or any VA inside a range)
import sys
import kc

def scan(ranges, lo=None, hi=None):
    start = 0xfffffff00814c000
    size = 0x2924000
    off = kc.va2off(start)
    code = kc.DATA[off:off+size]
    md = kc.MD
    regs = {}
    hits = []
    for ins in md.disasm(code, start):
        m = ins.mnemonic
        if m == "adrp":
            reg = ins.reg_name(ins.operands[0].reg)
            regs[reg] = ins.operands[1].imm & 0xFFFFFFFFFFFFFFFF
        elif m == "add" and len(ins.operands) == 3 and ins.operands[2].type == 2:  # imm
            dst = ins.reg_name(ins.operands[0].reg)
            src = ins.reg_name(ins.operands[1].reg)
            if src in regs:
                v = (regs[src] + ins.operands[2].imm) & 0xFFFFFFFFFFFFFFFF
                regs[dst] = v
                for name, (a, b) in ranges.items():
                    if a <= v < b:
                        hits.append((name, v, ins.address))
        elif m in ("ldr", "str", "ldrb", "strb", "ldrh", "strh", "mov", "cmp", "cbz", "cbnz", "bl", "b"):
            # adrp+ldr immediate form also yields address; keep regs for base
            pass
    return hits

if __name__ == "__main__":
    r = {
        "full_table": (0xfffffff007fea200, 0xfffffff007fea200+56*24),
        "restricted_table": (0xfffffff007fea740, 0xfffffff007fea740+28*24),
    }
    for name, v, pc in scan(r):
        print("%-16s %#x  (ref @ %#x)" % (name, v, pc))
