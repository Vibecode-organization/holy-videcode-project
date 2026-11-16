"""backward slice: what metaclass does each safeMetaCast at a site check?"""
import struct, pickle, sys
from capstone import *
from capstone.arm64 import *

sys.path.insert(0, '/home/femboychik/work/keytype')
from funcs2 import rd, dis
from stub import resolve, pac

SAFE = 0xfffffff00a894f30
hits = pickle.load(open('/home/femboychik/work/keytype/blhits.pkl', 'rb'))
MREG = ARM64_OP_REG
MMEM = ARM64_OP_MEM


def q(va):
    b = rd(va, 8)
    return struct.unpack('<Q', b)[0] if len(b) == 8 else None


def find_write(ins, idx, reg, depth=0):
    """return ('adrp_page', page, off) or ('ldr', slot) or ('deref', sub) for last write to reg."""
    for k in range(idx - 1, max(-1, idx - 40), -1):
        i = ins[k]
        if i.mnemonic in ('adrp',):
            if i.operands[0].reg == reg:
                return ('page', i.operands[1].imm & 0xFFFFFFFFFFFFFFFF)
        if i.mnemonic in ('ldr', 'ldrb', 'ldrh', 'ldrsw') and i.operands[0].reg == reg:
            m = i.operands[1]
            if m.type == MMEM:
                base, off = m.mem.base, m.mem.disp
                sub = find_write(ins, k, base, depth + 1)
                if sub and sub[0] == 'page':
                    slot = (sub[1] + off) & 0xFFFFFFFFFFFFFFFF
                    if off == 0 and depth == 0:
                        # could be a second-level load: value at slot is a pointer to a global
                        return ('deref', slot)
                    return ('slot', slot)
                if sub and sub[0] == 'slot':
                    v = q(sub[1])
                    if v:
                        return ('deref', pac(v))
                return None
        if i.mnemonic == 'add' and len(i.operands) == 3 and i.operands[0].reg == reg and i.operands[1].type == MREG and i.operands[2].type == ARM64_OP_IMM:
            sub = find_write(ins, k, i.operands[1].reg, depth + 1)
            if sub and sub[0] == 'page':
                return ('slot', (sub[1] + i.operands[2].imm) & 0xFFFFFFFFFFFFFFFF)
            return None
        if i.mnemonic in ('mov', 'orr') and i.operands[0].reg == reg and i.operands[1].type == MREG and len(i.operands) == 2:
            continue
    return None


for site, tgt, kind, seg in sorted(hits):
    if tgt == 0xfffffff00a8d96f4:
        continue
    ins = dis(site, 0x300)
    metas = []
    for k, i in enumerate(ins):
        if i.mnemonic != 'bl':
            continue
        t = i.operands[0].imm & 0xFFFFFFFFFFFFFFFF
        if resolve(t)[0] != SAFE:
            continue
        src = find_write(ins, k, ARM64_REG_X1)
        m = None
        if src and src[0] == 'deref':
            inner = q(src[1])
            if inner:
                m = pac(inner)
        metas.append(m)
    print('%016x  cast->%s' % (site, ','.join('%x' % x if x else '?' for x in metas) or '-'))
