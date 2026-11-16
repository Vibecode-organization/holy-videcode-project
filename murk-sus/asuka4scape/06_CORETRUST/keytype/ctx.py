"""dump per-call-site context: strings in window, insns before/after the call."""
import struct, pickle, sys
from capstone import *
from capstone.arm64 import *

sys.path.insert(0, '/home/femboychik/work/keytype')
from funcs2 import rd, va2off, dis, fmt

hits = pickle.load(open('/home/femboychik/work/keytype/blhits.pkl', 'rb'))
STUBS = {
    0xfffffff00880c148, 0xfffffff008908934, 0xfffffff008b74944, 0xfffffff008c1ffcc,
    0xfffffff008c78924, 0xfffffff008eb8980, 0xfffffff0092ba10c, 0xfffffff009363c20,
    0xfffffff0094be7ac, 0xfffffff0097ba7c4, 0xfffffff0099a046c, 0xfffffff0099b8ba8,
    0xfffffff009a4815c, 0xfffffff009a99d40, 0xfffffff009c49764, 0xfffffff009e9896c,
    0xfffffff009f0942c, 0xfffffff009f6f1c8, 0xfffffff009fa975c,
}

# function start heuristic: nearest preceding address where a 'ret'-ish terminator +
# padding is followed by a plausible prologue; fallback: nearest pacibsp with narrow gap.
def find_start(site):
    lo = site - 0x2000
    insns = dis(lo, (site - lo) // 4)
    best = None
    prev_term = True
    for i, ins in enumerate(insns):
        m = ins.mnemonic
        if m in ('ret', 'retab', 'retaa', 'br', 'brk'):
            prev_term = True
            continue
        if prev_term:
            if m in ('nop',):
                continue
            if m in ('pacibsp', 'stp', 'sub', 'mov', 'bti', 'paciasp', 'hint'):
                best = ins.address
            prev_term = False
    return best if best else site - 0x400


def strings_in(start, end, minlen=3):
    out = []
    insns = dis(start, max(1, (end - start) // 4))
    pend = {}
    for ins in insns:
        if ins.mnemonic == 'adrp':
            pend[ins.operands[0].reg] = ins.operands[1].imm & 0xFFFFFFFFFFFFFFFF
            continue
        if ins.mnemonic == 'add' and len(ins.operands) == 3 and ins.operands[2].type == ARM64_OP_IMM:
            b = ins.operands[1].reg
            if b in pend:
                va = (pend[b] + ins.operands[2].imm) & 0xFFFFFFFFFFFFFFFF
                s = rd(va, 128)
                if len(s) > minlen:
                    e = s.find(b'\0')
                    if e >= minlen and all(32 <= c < 127 for c in s[:e]):
                        out.append(s[:e].decode('ascii'))
        elif ins.mnemonic in ('ldr', 'ldrb', 'ldrh', 'ldrsw', 'ldur') and ins.operands[1].type == ARM64_OP_MEM:
            b = ins.operands[1].mem.base
            if b in pend:
                pass
    return out


groups = []
for site, tgt, kind, seg in sorted(hits):
    if tgt in STUBS:
        kindn = 'OSUnserialize(stub)'
    elif tgt == 0xfffffff00a8d8754:
        kindn = 'OSUnserialize(direct)'
    elif tgt == 0xfffffff00a8d96f4:
        continue
    else:
        kindn = 'sub_%x' % tgt
    groups.append((site, kindn))

with open('/home/femboychik/work/keytype/ctx.txt', 'w') as f:
    for site, kindn in groups:
        st = find_start(site)
        ss = strings_in(st, site + 0x200)
        f.write('\n===== %016x  %s   func~%016x (+0x%x)\n' % (site, kindn, st, site - st))
        f.write('  strings: %s\n' % ' | '.join(sorted(set(ss))[:24]))
        for ins in dis(site - 0x60, 6):
            f.write('   .. ' + fmt(ins) + '\n')
        f.write('  >>\n')
        for ins in dis(site, 30):
            f.write('     ' + fmt(ins) + '\n')
print('written')
