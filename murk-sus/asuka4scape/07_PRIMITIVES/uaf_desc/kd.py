# disasm helper over parse_gpu/kc.py -- linear sweep with sign-masked adr/adrp/b/bl
import sys, struct
sys.path.insert(0, '/home/femboychik/work/parse_gpu')
from kc import load, KC, BASE
import capstone
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from capstone.arm64_const import ARM64_OP_IMM

k = load()
md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
md.detail = True
M = 0xFFFFFFFFFFFFFFFF

def s64(v):
    return v - (1 << 64) if v & (1 << 63) else v

def V(x):
    """normalize: short form 0x9c38b2c -> 0xfffffff009c38b2c"""
    if isinstance(x, str):
        x = int(x, 16)
    if x < 0x100000000:
        x |= 0xfffffff000000000
    return x

def disarm(va, n):
    """disasm n bytes, return list of (va, mnem, op_str, insn)"""
    b = k.rd(va, n)
    if b is None:
        return []
    out = []
    for ins in md.disasm(b, va):
        # patch operand strings for pc-relative ops to absolute
        out.append((ins.address, ins.mnemonic, ins.op_str, ins))
    return out

def resolve_imm(ins, va):
    """return absolute target for adr/adrp/b/bl/cbz/tbz etc."""
    mn = ins.mnemonic
    ops = ins.operands
    if mn in ('adr', 'adrp'):
        return (va + s64(ins.operands[1].imm)) & M
    if mn.startswith('b') or mn in ('bl', 'cbz', 'cbnz'):
        for o in ops:
            if o.type == ARM64_OP_IMM:
                return o.imm & M
    return None

def fmt(va, n, mark=()):
    lines = []
    for addr, mn, ops, ins in disarm(va, n):
        tgt = resolve_imm(ins, addr)
        note = ''
        if tgt is not None and mn in ('adr', 'adrp'):
            pass
        if tgt is not None and (mn == 'b' or mn == 'bl' or mn.startswith('b.') or mn in ('cbz','cbnz')):
            sym = k.sym_at(tgt)
            note = f"   -> {tgt:#x}" + (f" <{sym}>" if sym else '')
        s = f"{addr:#x}:  {mn:8} {ops}{note}"
        if mark and addr in mark:
            s = ">>> " + s
        lines.append(s)
    return lines

def dump(va, n, label=''):
    print(f"\n===== {label} {va:#x} len {n:#x} =====")
    for l in fmt(va, n):
        print(l)

if __name__ == '__main__':
    va = int(sys.argv[1], 16)
    n = int(sys.argv[2], 16) if len(sys.argv) > 2 else 0x120
    dump(va, n)
