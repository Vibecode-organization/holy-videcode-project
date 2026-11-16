#!/usr/bin/env python3
# Fast scan: function index by 4-byte pattern search; cached disasm; call graph w/ depth.
import re, sys, json, struct, bisect
from mo import MachO, md
from capstone import CS_OP_IMM

m = MachO()
COPYOUT = 0xfffffff00a38a690
COPYIN  = 0xfffffff00a389b14
TEXEC_START = TEXEC_END = None
for s in m.segments:
    if s['name'] == '__TEXT_EXEC':
        TEXEC_START = s['vmaddr']; TEXEC_END = s['vmaddr']+s['vmsize']

off = m.va2off(TEXEC_START)
n = TEXEC_END - TEXEC_START
buf = m.data[off:off+n]
pats = [b'\x7f\x23\x03\xd5', b'\x5f\x23\x03\xd5', b'\x5f\x24\x03\xd5']
starts = set()
for p in pats:
    i = buf.find(p)
    while i != -1:
        if i % 4 == 0:
            starts.add(TEXEC_START + i)
        i = buf.find(p, i+1)
starts = sorted(starts)
print('funcs:', len(starts), file=sys.stderr)

def func_end(va):
    i = bisect.bisect_right(starts, va)
    return min(starts[i], va + 0x8000) if i < len(starts) else va + 0x8000

_ins = {}
def insns(va):
    if va in _ins: return _ins[va]
    b = m.read(va, func_end(va)-va)
    out = []
    if b:
        try:
            for ins in md.disasm(b, va):
                out.append(ins)
        except Exception:
            pass
    _ins[va] = out
    return out

call_cache = {}
def calls(va):
    if va in call_cache: return call_cache[va]
    out = []
    for ins in insns(va):
        if ins.mnemonic in ('bl','b') and len(ins.operands)==1 and ins.operands[0].type == CS_OP_IMM:
            out.append((ins.address, ins.operands[0].imm & 0xffffffffffffffff, ins.mnemonic))
    call_cache[va] = out
    return out

def reach(va, depth=3):
    seen = {}
    frontier = [(va, [])]
    for d in range(depth+1):
        nxt = []
        for f, path in frontier:
            for site, t, kind in calls(f):
                if t < TEXEC_START or t >= TEXEC_END: continue
                if t in seen: continue
                seen[t] = path + [(site, t, kind)]
                nxt.append((t, seen[t]))
        frontier = nxt
    return seen

syscalls = []
for line in open('syscalls_raw.txt'):
    mm = re.match(r'^(\d+)\s+(0x[0-9a-f]+):\s+(\S+)', line)
    if mm:
        syscalls.append((int(mm.group(1)), int(mm.group(2),16), mm.group(3)))

res = []
for num, va, name in syscalls:
    if name == 'nosys': continue
    r = reach(va, 3)
    res.append(dict(num=num, va=va, name=name,
                    copyout=COPYOUT in r, copyin=COPYIN in r,
                    path=[(hex(a),hex(b),k) for a,b,k in r.get(COPYOUT, [])],
                    callees=sorted(hex(x) for x in r)))
json.dump(res, open('scan.json','w'), indent=1)
print('handlers:', len(res), 'copyout:', sum(1 for x in res if x['copyout']))
for x in res:
    if x['copyout']:
        print('%4d %-26s %016x copyin=%s' % (x['num'], x['name'], x['va'], x['copyin']))
