#!/usr/bin/env python3
# Batch-diff all changed function pairs listed in a shape-diff report.
# usage: batch_diff.py REPORT A.bin B.bin [maxhunks]
import sys, re, struct, difflib
from capstone import *
from capstone.arm64 import *

REPORT, PA, PB = sys.argv[1], sys.argv[2], sys.argv[3]
OUT = sys.argv[4] if len(sys.argv) > 4 else None

def segs(path):
    d = open(path, 'rb').read()
    magic, ct, cs, ft, ncmds, sz, fl, _ = struct.unpack_from('<IiiIIIII', d, 0)
    p = 32
    out = []
    for _ in range(ncmds):
        cmd, csz = struct.unpack_from('<II', d, p)
        if cmd == 0x19:
            nm = d[p+8:p+24].split(b'\0')[0].decode()
            vm, vs, fo, fs = struct.unpack_from('<QQQQ', d, p+24)
            out.append((nm, vm, vs, fo, fs))
        p += csz
    return d, out

def at(s, d, a, n):
    for nm, vm, vs, fo, fs in s:
        if vm <= a and a+n <= vm+vs and fs:
            return d[fo+(a-vm):fo+(a-vm)+n]
    return None

md = Cs(CS_ARCH_ARM64, CS_MODE_LITTLE_ENDIAN)
md.detail = True
md.skipdata = True
BR = ('b', 'bl', 'adr', 'adrp', 'cbz', 'cbnz', 'tbz', 'tbnz')

def dis(d, s, a, n):
    code = at(s, d, a, n)
    out = []
    if not code:
        return out
    for i in md.disasm(code, a):
        if i.id == 0:
            out.append((i.address, 'data')); continue
        p = [i.mnemonic]
        for op in i.operands:
            if op.type == ARM64_OP_REG: p.append('R')
            elif op.type == ARM64_OP_IMM:
                mn = i.mnemonic
                if mn in BR or mn.startswith('b.'):
                    p.append('T')
                else:
                    p.append('#%d' % op.imm)
            elif op.type == ARM64_OP_MEM:
                m = op.mem; x = '[R'
                if m.index: x += '+R'
                if m.disp: x += ('+B' if abs(m.disp) > 0x1000 else '+#%d' % m.disp)
                p.append(x+']')
            elif op.type == ARM64_OP_FP:
                p.append('F')
            else:
                p.append('?')
        out.append((i.address, ' '.join(p)))
    return out

t = open(REPORT).read().splitlines()
regions = []; cur = None
for l in t:
    m = re.match(r'== (\w+) A\[(\d+):(\d+)\] B\[(\d+):(\d+)\]', l)
    if m:
        if cur: regions.append(cur)
        cur = {'tag': m.group(1), 'a': [], 'b': []}
        continue
    m = re.match(r'\s+A (0x[0-9a-f]+) sz=(\d+)', l)
    if m and cur: cur['a'].append((int(m.group(1), 16), int(m.group(2))))
    m = re.match(r'\s+B (0x[0-9a-f]+) sz=(\d+)', l)
    if m and cur: cur['b'].append((int(m.group(1), 16), int(m.group(2))))
if cur: regions.append(cur)

da, sa = segs(PA)
db, sb = segs(PB)
out = []
for r in regions:
    if r['tag'] != 'replace':
        a0 = r['a'][0][0] if r['a'] else 0
        b0 = r['b'][0][0] if r['b'] else 0
        out.append(f"### {r['tag']} A={len(r['a'])} B={len(r['b'])} A0={a0:#x} B0={b0:#x}")
    for k in range(min(len(r['a']), len(r['b']))):
        aa, asz = r['a'][k]; ba, bsz = r['b'][k]
        IA = dis(da, sa, aa, asz)
        IB = dis(db, sb, ba, bsz)
        sm = difflib.SequenceMatcher(None, [x[1] for x in IA], [x[1] for x in IB], autojunk=False)
        ops = [o for o in sm.get_opcodes() if o[0] != 'equal']
        if not ops: continue
        out.append(f"=== {aa:#x} ({asz}) -> {ba:#x} ({bsz}) d={bsz-asz:+d} insn {len(IA)}->{len(IB)} hunks={len(ops)}")
        for tag, i1, i2, j1, j2 in ops[:6]:
            pa = IA[min(i1, len(IA)-1)][0] if IA else 0
            pb = IB[min(j1, len(IB)-1)][0] if IB else 0
            out.append(f"  -- {tag} A@{pa:#x} ({i2-i1}) B@{pb:#x} ({j2-j1})")
            for q in range(max(i1-3, 0), min(i2+3, len(IA))):
                out.append(f"   A {IA[q][0]:#x} {IA[q][1]}")
            for q in range(max(j1-3, 0), min(j2+3, len(IB))):
                out.append(f"   B {IB[q][0]:#x} {IB[q][1]}")
        if len(ops) > 6:
            out.append(f"  .. {len(ops)-6} more hunks")

s = '\n'.join(out)
if OUT:
    open(OUT, 'w').write(s + '\n')
    print('wrote', OUT, len(out), 'lines')
else:
    print(s)
