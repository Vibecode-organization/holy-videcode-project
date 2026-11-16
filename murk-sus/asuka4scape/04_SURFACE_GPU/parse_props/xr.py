import json, struct, sys
import capstone
from kc import DATA
from k import va2off, off2va, rd, u64, u32, cstr, pdis, dis, SEGS

MD = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
MD.detail = True

KS = 0xfffffff009c14f20
KE = 0xfffffff009c49554
FUNCS = json.load(open('funcs.json'))
FUNCS_S = sorted(FUNCS)

def func_of(a):
    import bisect
    i = bisect.bisect_right(FUNCS_S, a) - 1
    return FUNCS_S[i] if i >= 0 else None

INSN = []   # list of (addr, mnem, op_str, bytes)
for i in MD.disasm(DATA[va2off(KS):va2off(KE)], KS):
    INSN.append((i.address, i.mnemonic, i.op_str, i.bytes))
print("insns", len(INSN), file=sys.stderr)

# map addr -> index
IDX = {a: n for n, (a, m, o, b) in enumerate(INSN)}

def regs(addr):
    """return (reg_written, [regs_read], imm_from_adrp or None)"""
    n = IDX[addr]
    return n

def next_idx(addr):
    return IDX[addr] + 1

# build adrp targets: reg -> page
def rd_op(addr):
    """decode operands with detail for a single insn"""
    o = va2off(addr)
    for i in MD.disasm(DATA[o:o+4], addr):
        return i

def adrp_info(addr):
    i = rd_op(addr)
    if i.mnemonic != 'adrp': return None
    # operands: Xd, imm
    d = i.operands[0].reg
    imm = i.operands[1].imm & 0xFFFFFFFFFFFFFFFF
    return d, imm

def add_imm(addr):
    i = rd_op(addr)
    if i.mnemonic not in ('add','ldr','str','ldrb','strb','ldrh','ldrsw','ldur','stur','strh','strw','ldrsw'): return None
    return i

def resolve_adrp_pairs():
    """scan: track adrp Xn -> page, then next insns using that reg with imm, emit (insn_addr, target_va, kind)"""
    out = []
    page = {}
    for n,(a,m,o,b) in enumerate(INSN):
        if m == 'adrp':
            i = rd_op(a)
            page[i.operands[0].reg] = i.operands[1].imm & 0xFFFFFFFFFFFFFFFF
            continue
        if m in ('add','ldr','str','ldrb','strb','ldrh','strh','ldrsb','ldrsw','ldur','str','ldp','stp'):
            i = rd_op(a)
            if m in ('ldp','stp','ldur','stur'):
                continue
            # operands: for add: Xd, Xn, #imm  ; for ldr: Xt, [Xn, #imm]
            if m == 'add':
                if len(i.operands) == 3 and i.operands[1].type == capstone.arm64.ARM64_OP_REG \
                   and i.operands[1].reg in page and i.operands[2].type == capstone.arm64.ARM64_OP_IMM:
                    tgt = (page[i.operands[1].reg] + i.operands[2].imm) & 0xFFFFFFFFFFFFFFFF
                    out.append((a, tgt, 'add'))
                continue
            if len(i.operands) >= 2 and i.operands[1].type == capstone.arm64.ARM64_OP_MEM \
               and i.operands[1].mem.base in page:
                tgt = (page[i.operands[1].mem.base] + i.operands[1].mem.disp) & 0xFFFFFFFFFFFFFFFF
                out.append((a, tgt, m))
    return out
