#!/usr/bin/env python3
# Shape-only linear diff of two Mach-O __TEXT ranges (works on dsc_extract output).
# Keeps mnemonic + operand kinds + small immediates only where stable.
import sys, struct, difflib
from capstone import *
from capstone.arm64 import *

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

md = Cs(CS_ARCH_ARM64, CS_MODE_LITTLE_ENDIAN)
md.detail = True
md.skipdata = True

def shapes(d, seg):
    nm, vm, vs, fo, fs = seg
    code = d[fo:fo+fs] if fo + fs <= len(d) else d[fo:]
    out = []
    for i in md.disasm(code, vm):
        if i.id == 0:
            out.append((i.address, 'data'))
            continue
        s = i.mnemonic
        for op in i.operands:
            if op.type == ARM64_OP_REG:
                s += ' R'
            elif op.type == ARM64_OP_IMM:
                s += ' I'
            elif op.type == ARM64_OP_MEM:
                s += ' [R'
                if op.mem.index:
                    s += '+R'
                if op.mem.disp:
                    s += '+d'
                s += ']'
            elif op.type == ARM64_OP_FP:
                s += ' F'
            else:
                s += ' ?'
        out.append((i.address, s))
    return out

A, B = sys.argv[1], sys.argv[2]
da, sa = segs(A)
db, sb = segs(B)
def textseg(ss):
    for s in ss:
        if s[0] == '__TEXT' and s[4] > 0x1000:
            return s
    return ss[0]
ta, tb = textseg(sa), textseg(sb)
IA, IB = shapes(da, ta), shapes(db, tb)
print(f'insns A={len(IA)} B={len(IB)}')
sa_, sb_ = [x[1] for x in IA], [x[1] for x in IB]
sm = difflib.SequenceMatcher(None, sa_, sb_, autojunk=False)
print('ratio', round(sm.ratio(), 5))
n = 0
for tag, i1, i2, j1, j2 in sm.get_opcodes():
    if tag == 'equal':
        continue
    n += 1
    print(f'== {tag} A@{IA[i1][0]:#x} ({i2-i1}) B@{IB[j1][0]:#x} ({j2-j1})')
    for k in range(i1, min(i2, i1+5)):
        print('   A', IA[k][1])
    for k in range(j1, min(j2, j1+5)):
        print('   B', IB[k][1])
    if n >= 120:
        print('...')
        break
