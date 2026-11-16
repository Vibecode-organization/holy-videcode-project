"""resolve metaclass argument of every safeMetaCast call at each OSUnserialize site."""
import struct, pickle, sys
from capstone import *
from capstone.arm64 import *

sys.path.insert(0, '/home/femboychik/work/keytype')
from funcs2 import rd, va2off, dis
from stub import resolve, pac

BASE = 0xfffffff007004000
SAFE = 0xfffffff00a894f30
hits = pickle.load(open('/home/femboychik/work/keytype/blhits.pkl', 'rb'))

rcache = {}


def res(t):
    if t not in rcache:
        r, _ = resolve(t)
        rcache[t] = r if r else t
    return rcache[t]


def q(va):
    b = rd(va, 8)
    if len(b) != 8:
        return None
    return struct.unpack('<Q', b)[0]


def meta_of(v):
    """given a qword that should be a pac'd pointer to a global, return metaclass VA."""
    if v is None:
        return None
    t = pac(v)
    inner = q(t)
    if inner is None:
        return None
    if (inner >> 40) in (0xfffff0, 0xffffff, 0xfffff, 0x100000, 0x9f, 0x9e):
        pass
    return pac(inner) if (inner >> 32) in (0xfffffff0,) or (inner & 0xFFFFFFFF00000000) else None


for site, tgt, kind, seg in sorted(hits):
    if tgt == 0xfffffff00a8d96f4:
        continue
    ins = dis(site, 0x700 // 4)
    metas = []
    vt = []
    for k, i in enumerate(ins):
        if i.mnemonic == 'bl' and (i.operands[0].imm & 0xFFFFFFFFFFFFFFFF) != 0 and res(i.operands[0].imm & 0xFFFFFFFFFFFFFFFF) == SAFE:
            # look back for the ldr feeding x1
            m = None
            for b in ins[max(0, k - 8):k]:
                if b.mnemonic == 'ldr' and b.operands[0].type == ARM64_OP_REG and b.operands[0].reg == 1 and b.operands[1].type == ARM64_OP_MEM:
                    base = b.operands[1].mem.base
                    # find adrp for base
                    for c in ins[max(0, k - 10):k]:
                        if c.mnemonic == 'adrp' and c.operands[0].reg == base:
                            slot = (c.operands[1].imm & 0xFFFFFFFFFFFFFFFF) + b.operands[1].mem.disp
                            v = q(slot)
                            if v is not None:
                                t = pac(v)
                                inner = q(t)
                                if inner is not None:
                                    m = pac(inner)
                            break
                    break
            metas.append(m)
        if i.mnemonic == 'blraa':
            # find the vtable offset from the preceding ldr
            for b in ins[max(0, k - 3):k]:
                if b.mnemonic == 'ldr' and b.operands[1].type == ARM64_OP_MEM and b.operands[1].mem.disp:
                    vt.append(b.operands[1].mem.disp)
    print('%016x  cast=%s  vtoff=%s' % (
        site,
        ','.join(('%x' % m) if m else '?' for m in metas) or '-',
        ','.join('%x' % v for v in vt) or '-'))
