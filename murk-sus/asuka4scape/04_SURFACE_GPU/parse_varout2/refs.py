"""Find code references (adrp+add / adrp+ldr) to a target VA inside __TEXT_EXEC."""
import sys, struct, json
sys.path.insert(0,"/home/femboychik/work/parse_varout2")
from kc import *
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from capstone.arm64 import ARM64_OP_REG, ARM64_OP_IMM, ARM64_OP_MEM

md = Cs(CS_ARCH_ARM64, CS_MODE_ARM); md.detail = True

def refs_to(target, limit=40):
    out = []
    # crude: scan all adrp (0x90000000 mask 0x9F000000) and pair with next few insns
    buf = DATA[TEXT_EXEC_OFF:TEXT_EXEC_OFF+TEXT_EXEC_SIZE]
    n = len(buf)//4
    import array
    a = array.array('I'); a.frombytes(buf)
    for i, w in enumerate(a):
        if (w & 0x9F000000) != 0x90000000:
            continue
        va = TEXT_EXEC_VA + i*4
        page = va & ~0xFFF
        immhi = (w >> 5) & 0x7FFFF
        immlo = (w >> 29) & 3
        off = (immhi << 2) | immlo
        if off & (1 << 20): off -= (1 << 21)
        tgt_page = page + (off << 12)
        if abs(tgt_page - (target & ~0xFFF)) > 0x2000:
            continue
        # look at next 3 insns for add/ldr with imm reaching target
        o = va2off(va)
        for j, ins in enumerate(md.disasm(DATA[o:o+16], va)):
            if j == 0: continue
            if ins.mnemonic == 'add' and len(ins.operands) == 3 and ins.operands[2].type == ARM64_OP_IMM:
                v = tgt_page + ins.operands[2].imm
                if v == target:
                    out.append((va, 'adrp+add'))
            if ins.mnemonic in ('ldr','ldur') and ins.operands and ins.operands[1].type == ARM64_OP_MEM:
                v = tgt_page + ins.operands[1].mem.disp
                if v == target:
                    out.append((va, 'adrp+ldr'))
        if len(out) > limit: break
    return out

if __name__ == "__main__":
    for a in sys.argv[1:]:
        t = int(a, 16)
        r = refs_to(t)
        print(hex(t), [(hex(x), k) for x, k in r][:10])
