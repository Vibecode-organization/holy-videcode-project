"""for every vtable call in a consumer window: classify x1 (key) origin and vtable offset."""
import struct, pickle, sys
from capstone import *
from capstone.arm64 import *

sys.path.insert(0, '/home/femboychik/work/keytype')
from funcs2 import rd, va2off, dis
from stub import resolve, pac

SAFE = 0xfffffff00a894f30
hits = pickle.load(open('/home/femboychik/work/keytype/blhits.pkl', 'rb'))
rcache = {}


def res(t):
    if t not in rcache:
        r, _ = resolve(t)
        rcache[t] = r if r else t
    return rcache[t]


def cstr(va):
    s = rd(va, 48)
    if not s:
        return None
    e = s.find(b'\0')
    if e < 3 or not all(32 <= c < 127 for c in s[:e]):
        return None
    return s[:e].decode()


for site, tgt, kind, seg in sorted(hits):
    if tgt == 0xfffffff00a8d96f4:
        continue
    ins = dis(site, 0x500 // 4)
    events = []
    for k, i in enumerate(ins):
        if i.mnemonic != 'blraa':
            continue
        off = None
        for b in ins[max(0, k - 4):k]:
            if b.mnemonic == 'ldr' and b.operands[1].type == ARM64_OP_MEM and b.operands[1].mem.disp:
                off = b.operands[1].mem.disp
        # x1 origin
        src = None
        for b in ins[max(0, k - 8):k]:
            if b.mnemonic == 'mov' and b.operands[0].type == ARM64_OP_REG and b.operands[0].reg == 1 and b.operands[1].type == ARM64_OP_REG:
                r = b.operands[1].reg
                # trace adrp/add for r
                for c in ins[max(0, k - 10):k]:
                    if c.mnemonic == 'adrp' and c.operands[0].reg == r:
                        src = 'cstr:"%s"' % cstr(c.operands[1].imm & 0xFFFFFFFFFFFFFFFF)
                        # try add offset
                        for d in ins[max(0, k - 8):k]:
                            if d.mnemonic == 'add' and len(d.operands) == 3 and d.operands[1].type == ARM64_OP_REG and d.operands[1].reg == r and d.operands[2].type == ARM64_OP_IMM:
                                s = cstr((c.operands[1].imm & 0xFFFFFFFFFFFFFFFF) + d.operands[2].imm)
                                if s:
                                    src = 'cstr:"%s"' % s
                if src is None:
                    src = 'reg'
            elif b.mnemonic == 'ldr' and b.operands[0].type == ARM64_OP_REG and b.operands[0].reg == 1:
                src = 'global/sym'
        events.append((off, src))
    if events:
        print('%016x  %s' % (site, '  '.join('vt%x:%s' % (o or -1, s or '?') for o, s in events[:8])))
