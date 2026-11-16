"""classify each OSUnserialize call site: root OSDynamicCast? getObject key kind? iteration?"""
import struct, pickle, sys
from capstone import *
from capstone.arm64 import *

sys.path.insert(0, '/home/femboychik/work/keytype')
from funcs2 import rd, dis, fmt
from stub import resolve

hits = pickle.load(open('/home/femboychik/work/keytype/blhits.pkl', 'rb'))
rcache = {}


def res(t):
    if t not in rcache:
        r, _ = resolve(t)
        rcache[t] = r if r else t
    return rcache[t]


def string_at(va):
    s = rd(va, 64)
    if not s:
        return None
    e = s.find(b'\0')
    if e < 3 or not all(32 <= c < 127 for c in s[:e]):
        return None
    return s[:e].decode()


def analyze(site):
    insns = dis(site, 0x400 // 4)
    ops = [i.mnemonic for i in insns]
    out = {'casts': [], 'calls': [], 'strs': [], 'loop': False, 'getobj_n': 0}
    pend = {}
    for k, ins in enumerate(insns):
        m = ins.mnemonic
        if m == 'adrp':
            pend[ins.operands[0].reg] = ins.operands[1].imm & 0xFFFFFFFFFFFFFFFF
        elif m == 'add' and len(ins.operands) == 3 and ins.operands[2].type == ARM64_OP_IMM:
            b = ins.operands[1].reg
            if b in pend:
                s = string_at((pend[b] + ins.operands[2].imm) & 0xFFFFFFFFFFFFFFFF)
                if s and s not in out['strs']:
                    out['strs'].append(s)
        elif m in ('bl', 'b'):
            t = ins.operands[0].imm & 0xFFFFFFFFFFFFFFFF
            r = res(t)
            out['calls'].append(r)
            if r == 0xfffffff00a894f30:
                out['getobj_n'] += 1
        # metaclass walk fingerprint: vtable+0x38 call, then cmp with imm/global, then ldr [x0,#0x10]
        if m == 'cmp' and k + 1 < len(insns):
            nxt = insns[k + 1]
            if nxt.mnemonic == 'b.eq':
                # look back for ldr #0x38
                back = insns[max(0, k - 6):k]
                if any(b.mnemonic == 'ldr' and '#0x38' in b.op_str for b in back):
                    tgt = None
                    for o in ins.operands:
                        if o.type == ARM64_OP_REG and o.reg in pend:
                            tgt = pend[o.reg]
                    out['casts'].append(tgt)
    return out


rows = []
for site, tgt, kind, seg in sorted(hits):
    if tgt == 0xfffffff00a8d96f4:
        continue
    a = analyze(site)
    rows.append((site, a))

for site, a in rows:
    print('%016x  casts=%s  getObject=%d  calls=%s' % (
        site,
        ','.join('%x' % c if c else '?' for c in a['casts']) or '-',
        a['getobj_n'],
        ' '.join('%x' % c for c in a['calls'][:8])))
