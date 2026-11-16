"""annotated per-site transcripts: resolve every bl through PLT stubs."""
import struct, pickle, sys
from capstone import *
from capstone.arm64 import *

sys.path.insert(0, '/home/femboychik/work/keytype')
from funcs2 import rd, va2off, dis, fmt
from stub import resolve

hits = pickle.load(open('/home/femboychik/work/keytype/blhits.pkl', 'rb'))
STUBS = {
    0xfffffff00880c148, 0xfffffff008908934, 0xfffffff008b74944, 0xfffffff008c1ffcc,
    0xfffffff008c78924, 0xfffffff008eb8980, 0xfffffff0092ba10c, 0xfffffff009363c20,
    0xfffffff0094be7ac, 0xfffffff0097ba7c4, 0xfffffff0099a046c, 0xfffffff0099b8ba8,
    0xfffffff009a4815c, 0xfffffff009a99d40, 0xfffffff009c49764, 0xfffffff009e9896c,
    0xfffffff009f0942c, 0xfffffff009f6f1c8, 0xfffffff009fa975c,
}

cache = {}


def call_name(t):
    if t in cache:
        return cache[t]
    r, slot = resolve(t)
    if r:
        cache[t] = 'stub->%x' % r
    else:
        cache[t] = '%x' % t
    return cache[t]


def string_at(va):
    s = rd(va, 64)
    if not s:
        return None
    e = s.find(b'\0')
    if e < 3:
        return None
    if not all(32 <= c < 127 for c in s[:e]):
        return None
    return s[:e].decode()


out = open('/home/femboychik/work/keytype/sites.txt', 'w')
for site, tgt, kind, seg in sorted(hits):
    if tgt == 0xfffffff00a8d96f4:
        continue
    out.write('\n=== site %016x  %s\n' % (site, 'OSUnserialize'))
    insns = dis(site - 0x80, (0x80 + 0x200) // 4)
    pend = {}
    for ins in insns:
        m = ins.mnemonic
        note = ''
        if m == 'adrp':
            pend[ins.operands[0].reg] = ins.operands[1].imm & 0xFFFFFFFFFFFFFFFF
        elif m == 'add' and len(ins.operands) == 3 and ins.operands[2].type == ARM64_OP_IMM:
            b = ins.operands[1].reg
            if b in pend:
                va = (pend[b] + ins.operands[2].imm) & 0xFFFFFFFFFFFFFFFF
                s = string_at(va)
                if s:
                    note = '  ; "%s"' % s
                else:
                    note = '  ; &%x' % va
        elif m in ('ldr', 'ldrsw') and ins.operands[1].type == ARM64_OP_MEM:
            b = ins.operands[1].mem.base
            if b in pend:
                va = (pend[b] + ins.operands[1].mem.disp) & 0xFFFFFFFFFFFFFFFF
                q = rd(va, 8)
                if len(q) == 8:
                    v = struct.unpack('<Q', q)[0]
                    note = '  ; [%x]=%x' % (va, v)
        elif m in ('bl', 'b'):
            t = ins.operands[0].imm & 0xFFFFFFFFFFFFFFFF
            note = '   -> ' + call_name(t)
        marker = ' <<<' if ins.address == site else ''
        out.write('%s%s%s\n' % (fmt(ins), note, marker))
out.close()
print('ok')
