#!/usr/bin/env python3
# Function-level diff of two Mach-O images (same arch), using LC_FUNCTION_STARTS
# and instruction signatures that keep immediates but normalize branch targets/PAC.
import sys, struct, difflib
from capstone import *
from capstone.arm64 import *

def load(path):
    d = open(path, 'rb').read()
    magic, ct, cs, ft, ncmds, sz, fl, _ = struct.unpack_from('<IiiIIIII', d, 0)
    p = 32
    text = None
    fstarts = None
    for _ in range(ncmds):
        cmd, csz = struct.unpack_from('<II', d, p)
        if cmd == 0x19:
            nm = d[p+8:p+24].split(b'\0')[0].decode()
            vm, vs, fo, fs = struct.unpack_from('<QQQQ', d, p+24)
            if text is None:
                text = (vm, vs, fo, fs)
        elif cmd == 0x26:
            off, size = struct.unpack_from('<II', d, p+8)
            fstarts = (off, size)
        p += csz
    return d, text, fstarts

def funcs(d, text, fstarts):
    vm, vs, fo, fs = text
    off, size = fstarts
    p, end, addr = off, off+size, vm
    out = []
    while p < end:
        v = 0
        shift = 0
        while True:
            b = d[p]; p += 1
            v |= (b & 0x7f) << shift
            shift += 7
            if not b & 0x80:
                break
        if v == 0:
            break
        addr += v
        out.append(addr)
    return out

md = Cs(CS_ARCH_ARM64, CS_MODE_LITTLE_ENDIAN)
md.detail = True
md.skipdata = True
BR = {'b','bl','cbz','cbnz','tbz','tbnz','b.eq','b.ne','b.hs','b.lo','b.hi','b.ls',
      'b.mi','b.pl','b.vs','b.vc','b.gt','b.le','b.ge','b.lt'}

def sig(d, text, start, end):
    vm, vs, fo, fs = text
    if start < vm or end > vm + vs:
        return ''
    il = list(md.disasm(d[fo+(start-vm):fo+(start-vm)+(end-start)], start))
    out = []
    for i in il:
        parts = [i.mnemonic]
        for op in i.operands:
            if op.type == ARM64_OP_REG:
                parts.append('R')
            elif op.type == ARM64_OP_IMM:
                if i.mnemonic in BR or i.mnemonic == 'adrp':
                    parts.append('T')
                elif abs(op.imm) > 0x100000:
                    parts.append('BIG')
                else:
                    parts.append('#%d' % op.imm)
            elif op.type == ARM64_OP_MEM:
                m = op.mem
                s = '[R'
                if m.index:
                    s += '+R'
                if m.disp:
                    s += ('+BIG' if abs(m.disp) > 0x100000 else '+#%d' % m.disp)
                parts.append(s+']')
            elif op.type == ARM64_OP_FP:
                parts.append('F')
            else:
                parts.append('?')
        out.append(' '.join(parts))
    return '\n'.join(out)

A, B = sys.argv[1], sys.argv[2]
da, ta, fa = load(A)
db, tb, fb = load(B)
la = funcs(da, ta, fa) + [ta[0]+ta[1]]
lb = funcs(db, tb, fb) + [tb[0]+tb[1]]
SA = [sig(da, ta, la[i], la[i+1]) for i in range(len(la)-1)]
SB = [sig(db, tb, lb[i], lb[i+1]) for i in range(len(lb)-1)]
print('funcs', len(SA), len(SB), 'identical', sum(1 for a, b in zip(SA, SB) if a == b))
diff = [(la[i], la[i+1]-la[i], lb[i], lb[i+1]-lb[i])
        for i in range(min(len(SA), len(SB))) if SA[i] != SB[i]]
print('differing funcs', len(diff))
for a, asz, b, bsz in diff[:40]:
    print(f'  A {a:#x} sz={asz}   B {b:#x} sz={bsz}')
