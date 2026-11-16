#!/usr/bin/env python3
# Diff one function between two Mach-O files.
# usage: diff_func.py A.bin A_addr B.bin B_addr [size]
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

def at(segs_, d, a, n):
    for nm, vm, vs, fo, fs in segs_:
        if vm <= a and a+n <= vm+vs and fs:
            return d[fo+(a-vm):fo+(a-vm)+n]
    return None

md = Cs(CS_ARCH_ARM64, CS_MODE_LITTLE_ENDIAN)
md.detail = True
md.skipdata = True
BR = ('b','bl','adr','adrp','cbz','cbnz','tbz','tbnz')

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
                p.append('T' if (mn in BR or mn.startswith('b.')) else '#%d' % op.imm)
            elif op.type == ARM64_OP_MEM:
                m = op.mem; x = '[R'
                if m.index: x += '+R'
                if m.disp: x += ('+B' if abs(m.disp) > 0x100000 else '+#%d' % m.disp)
                p.append(x+']')
            else: p.append('?')
        out.append((i.address, ' '.join(p)))
    return out

A, AA, B, BA = sys.argv[1], int(sys.argv[2], 16), sys.argv[3], int(sys.argv[4], 16)
N = int(sys.argv[5]) if len(sys.argv) > 5 else 0x2000
da, sa = segs(A)
db, sb = segs(B)
IA = dis(da, sa, AA, N)
IB = dis(db, sb, BA, N)
print(f'A insns={len(IA)} B insns={len(IB)}')
sm = difflib.SequenceMatcher(None, [x[1] for x in IA], [x[1] for x in IB], autojunk=False)
for tag, i1, i2, j1, j2 in sm.get_opcodes():
    if tag == 'equal':
        continue
    print(f'== {tag} A@{IA[i1][0]:#x} ({i2-i1}) B@{IB[j1][0]:#x} ({j2-j1})')
    for k in range(max(i1-4, 0), min(i2+4, len(IA))):
        print('   A', hex(IA[k][0]), IA[k][1])
    for k in range(max(j1-4, 0), min(j2+4, len(IB))):
        print('   B', hex(IB[k][0]), IB[k][1])
