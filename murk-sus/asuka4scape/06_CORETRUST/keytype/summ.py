"""compact summary: per site, ordered resolved calls + string literals; global target freq."""
import struct, pickle, sys
from collections import Counter, OrderedDict
from capstone import *
from capstone.arm64 import *

sys.path.insert(0, '/home/femboychik/work/keytype')
from funcs2 import rd, va2off, dis
from stub import resolve

hits = pickle.load(open('/home/femboychik/work/keytype/blhits.pkl', 'rb'))
cache = {}


def resolve_cached(t):
    if t not in cache:
        r, slot = resolve(t)
        cache[t] = r if r else t
    return cache[t]


def string_at(va):
    s = rd(va, 64)
    if not s:
        return None
    e = s.find(b'\0')
    if e < 3 or not all(32 <= c < 127 for c in s[:e]):
        return None
    return s[:e].decode()


freq = Counter()
rows = []
for site, tgt, kind, seg in sorted(hits):
    if tgt == 0xfffffff00a8d96f4:
        continue
    insns = dis(site, 0x180 // 4)
    calls = []
    strs = []
    pend = {}
    for ins in insns:
        m = ins.mnemonic
        if m == 'adrp':
            pend[ins.operands[0].reg] = ins.operands[1].imm & 0xFFFFFFFFFFFFFFFF
        elif m == 'add' and len(ins.operands) == 3 and ins.operands[2].type == ARM64_OP_IMM:
            b = ins.operands[1].reg
            if b in pend:
                s = string_at((pend[b] + ins.operands[2].imm) & 0xFFFFFFFFFFFFFFFF)
                if s and s not in strs:
                    strs.append(s)
        elif m in ('bl', 'b'):
            t = ins.operands[0].imm & 0xFFFFFFFFFFFFFFFF
            r = resolve_cached(t)
            if r in (0xfffffff00a8d8754,):
                continue
            calls.append(r)
            freq[r] += 1
    rows.append((site, calls[:10], strs[:6]))

print('=== target frequency (resolved, after unserialize)')
for t, n in freq.most_common(25):
    print('%3d  %016x' % (n, t))
print()
print('=== per site')
for site, calls, strs in rows:
    print('%016x  calls: %s' % (site, ' '.join('%x' % c for c in calls)))
    if strs:
        print('             strs : %s' % ' | '.join(strs))
