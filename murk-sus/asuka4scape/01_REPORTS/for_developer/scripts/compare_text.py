#!/usr/bin/env python3
# Compare the __text section of two Mach-O files (kext or dylib).
# Keeps immediates, normalizes branch targets/adrp/PAC.  Usage: compare_text.py A B
import sys, struct, difflib
from capstone import *
from capstone.arm64 import *

def find_text(path):
    d = open(path, 'rb').read()
    magic, ct, cs, ft, ncmds, sz, fl, _ = struct.unpack_from('<IiiIIIII', d, 0)
    assert magic == 0xFEEDFACF, hex(magic)
    q = 32
    best = None
    for _ in range(ncmds):
        cmd, csz = struct.unpack_from('<II', d, q)
        if cmd == 0x19:
            nsects = struct.unpack_from('<I', d, q+64)[0]
            so = q+72
            for _ in range(nsects):
                sn = d[so:so+16].split(b'\0')[0].decode()
                addr, size = struct.unpack_from('<QQ', d, so+32)
                off = struct.unpack_from('<I', d, so+48)[0]
                flags = struct.unpack_from('<I', d, so+64)[0]
                if sn == '__text' and size > 0:
                    if best is None or size > best[2]:
                        best = (d, addr, size, off)
                so += 80
        q += csz
    return best

md = Cs(CS_ARCH_ARM64, CS_MODE_LITTLE_ENDIAN)
md.detail = True
md.skipdata = True
BR = ('b','bl','adr','adrp','cbz','cbnz','tbz','tbnz')

def sig(d, addr, size, off):
    out = []
    for i in md.disasm(d[off:off+size], addr):
        if i.id == 0:
            out.append((i.address, 'data')); continue
        parts = [i.mnemonic]
        for op in i.operands:
            if op.type == ARM64_OP_REG:
                parts.append('R')
            elif op.type == ARM64_OP_IMM:
                mn = i.mnemonic
                if mn in BR or mn.startswith('b.') or mn in ('cbz','cbnz','tbz','tbnz'):
                    parts.append('T')
                elif abs(op.imm) > 0x100000:
                    parts.append('B')
                else:
                    parts.append('#%d' % op.imm)
            elif op.type == ARM64_OP_MEM:
                m = op.mem; s = '[R'
                if m.index: s += '+R'
                if m.disp: s += ('+B' if abs(m.disp) > 0x10000 else '+#%d' % m.disp)
                parts.append(s+']')
            else:
                parts.append('F' if op.type == ARM64_OP_FP else '?')
        out.append((i.address, ' '.join(parts)))
    return out

A, B = sys.argv[1], sys.argv[2]
ta, tb = find_text(A), find_text(B)
if not ta or not tb:
    print('no __text'); sys.exit(2)
IA = sig(*ta); IB = sig(*tb)
print(f'__text insns A={len(IA)} B={len(IB)}')
sm = difflib.SequenceMatcher(None, [x[1] for x in IA], [x[1] for x in IB], autojunk=False)
print('ratio', round(sm.ratio(), 6))
n = 0
for tag, i1, i2, j1, j2 in sm.get_opcodes():
    if tag == 'equal':
        continue
    n += 1
    print(f'== {tag} A@{IA[i1][0]:#x} ({i2-i1}) B@{IB[j1][0]:#x} ({j2-j1})')
    for k in range(max(i1-3,0), min(i2+3, len(IA))):
        print('   A', hex(IA[k][0]), IA[k][1])
    for k in range(max(j1-3,0), min(j2+3, len(IB))):
        print('   B', hex(IB[k][0]), IB[k][1])
    if n >= 60:
        print('...'); break
print('regions', n)
