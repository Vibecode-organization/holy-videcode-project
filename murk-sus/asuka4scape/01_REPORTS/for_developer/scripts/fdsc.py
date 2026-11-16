#!/usr/bin/env python3
# Linear instruction diff of two Mach-O __TEXT ranges (works on dsc_extract output
# without LC_FUNCTION_STARTS). Branch targets and adrp pages are normalized.
import sys, struct, difflib
from capstone import *
from capstone.arm64 import *

def segs(path):
    d = open(path, 'rb').read()
    magic, ct, cs, ft, ncmds, sz, fl, _ = struct.unpack_from('<IiiIIIII', d, 0)
    assert magic == 0xFEEDFACF, hex(magic)
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

md = Cs(CS_ARCH_ARM64, CS_MODE_LITTLE_ENDIAN)
md.detail = True
md.skipdata = True
BR = {'b','bl','cbz','cbnz','tbz','tbnz','b.eq','b.ne','b.hs','b.lo','b.hi','b.ls',
      'b.mi','b.pl','b.vs','b.vc','b.gt','b.le','b.ge','b.lt'}

def sigs(d, seg, lo=None, hi=None):
    nm, vm, vs, fo, fs = seg
    start = vm if lo is None else lo
    end = vm+vs if hi is None else hi
    code = d[fo+(start-vm):fo+(start-vm)+(end-start)]
    out = []
    for i in md.disasm(code, start):
        if i.id == 0:
            out.append((i.address, 'data'))
            continue
        parts = [i.mnemonic]
        for op in i.operands:
            if op.type == ARM64_OP_REG:
                parts.append('R')
            elif op.type == ARM64_OP_IMM:
                mn = i.mnemonic
                is_t = mn in BR or mn in ('adrp','adr','cbz','cbnz','tbz','tbnz') or mn.startswith('b.')
                parts.append('T' if is_t else '#%d' % op.imm)
            elif op.type == ARM64_OP_MEM:
                m = op.mem
                s = '[R'
                if m.index:
                    s += '+R'
                if m.disp:
                    s += ('+BIG' if abs(m.disp) > 0x100000 else '+#%d' % m.disp)
                parts.append(s+']')
            else:
                parts.append('F' if op.type == ARM64_OP_FP else '?')
        out.append((i.address, ' '.join(parts)))
    return out

def textseg(ss):
    for s in ss:
        if s[0] == '__TEXT':
            return s
    return ss[0]

A, B = sys.argv[1], sys.argv[2]
da, sa = segs(A)
db, sb = segs(B)
ta, tb = textseg(sa), textseg(sb)
IA = sigs(da, ta)
IB = sigs(db, tb)
print(f'__TEXT A {len(IA)} insns  B {len(IB)} insns')
sa_ = [x[1] for x in IA]
sb_ = [x[1] for x in IB]
sm = difflib.SequenceMatcher(None, sa_, sb_, autojunk=False)
print('ratio', round(sm.ratio(), 5))
n = 0
for tag, i1, i2, j1, j2 in sm.get_opcodes():
    if tag == 'equal':
        continue
    n += 1
    print(f'== {tag} A@{IA[i1][0]:#x} ({i2-i1}) B@{IB[j1][0]:#x} ({j2-j1})')
    for k in range(i1, min(i2, i1+6)):
        print('   A', IA[k][1])
    for k in range(j1, min(j2, j1+6)):
        print('   B', IB[k][1])
    if n > 60:
        print('... more')
        break
