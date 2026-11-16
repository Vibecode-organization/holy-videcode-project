#!/usr/bin/env python3
"""find adrp+add / adrp+ldr materializations of a target VA across executable segs"""
import sys, kc
from capstone.arm64 import ARM64_OP_IMM, ARM64_OP_REG, ARM64_OP_MEM

EXECSEGS = [s for s in kc.SEGS if s[0] in ("__TEXT_EXEC", "__PRELINK_TEXT", "__TEXT")]

def scan_target(target, maxgap=4):
    """yield (insn_va, kind) where adrp/add or adrp/ldr resolves to target"""
    tpage = target & ~0xFFF
    hits = []
    for name, vm, vs, fo, fs in EXECSEGS:
        base = fo
        end = fo + fs
        for o in range(base & ~3, end - 16, 4):
            w = int.from_bytes(kc.BLOB[o:o+4], "little")
            # ADRP: bits 31=1, 28-24=10000
            if (w & 0x9F000000) != 0x90000000:
                continue
            pc = kc.off2va(o)
            ins = next(kc.MD.disasm(kc.BLOB[o:o+4], pc), None)
            if ins is None or ins.mnemonic != "adrp":
                continue
            rd = ins.operands[0].reg
            page = (pc & ~0xFFF) + (ins.operands[1].imm & 0xFFFFFFFFFFFFFFFF)
            if page != tpage:
                continue
            dst = ins.operands[0].reg
            # look ahead a few insns for add/ldr using same reg as base
            for k in range(1, maxgap + 1):
                o2 = o + 4 * k
                if o2 + 4 > end: break
                i2 = next(kc.MD.disasm(kc.BLOB[o2:o2+4], kc.off2va(o2)), None)
                if i2 is None: break
                if not i2.operands: break
                if i2.operands[0].type != ARM64_OP_REG: break
                if i2.operands[0].reg != dst: break
                if i2.mnemonic in ("add", "ldr") and len(i2.operands) > 1:
                    op = i2.operands[1]
                    if op.type == ARM64_OP_MEM and op.mem.base == dst and op.mem.index == 0:
                        a = page + op.mem.disp
                    elif op.type == ARM64_OP_IMM:
                        a = (page + (op.imm & 0xFFFFFFFFFFFFFFFF)) & 0xFFFFFFFFFFFFFFFF
                    else:
                        break
                    if a == target:
                        hits.append((pc, i2.mnemonic, kc.off2va(o2)))
                        break
    return hits

if __name__ == "__main__":
    for t in sys.argv[1:]:
        tv = int(t, 16)
        print(f"== {tv:#x} {kc.cstr(tv) if kc.inrange(tv) else ''}")
        for h in scan_target(tv):
            print("   ", hex(h[0]), h[1], hex(h[2]))
