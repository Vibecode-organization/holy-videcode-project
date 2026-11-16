#!/usr/bin/env python3
# Kernel-wide function diff across all segments (MH_FILESET kernel image).
# Usage: fdiff_kernel.py A B [--max N]
import sys, struct, hashlib, difflib
from capstone import *
from capstone.arm64 import *

MAXF = 5000

def load(path):
    d = open(path, 'rb').read()
    magic, ct, cs, ft, ncmds, sz, fl, _ = struct.unpack_from('<IiiIIIII', d, 0)
    assert magic == 0xFEEDFACF
    p = 32
    segs = []
    fst = None
    for _ in range(ncmds):
        cmd, csz = struct.unpack_from('<II', d, p)
        if cmd == 0x19:
            nm = d[p+8:p+24].split(b'\0')[0].decode()
            vm, vs, fo, fs = struct.unpack_from('<QQQQ', d, p+24)
            segs.append((nm, vm, vs, fo, fs))
        elif cmd == 0x26:
            off, size = struct.unpack_from('<II', d, p+8)
            fst = (off, size)
        p += csz
    segs.sort(key=lambda s: s[1])
    return d, segs, fst

def func_starts(d, segs, fst):
    off, size = fst
    base = segs[0][1]
    p, end, addr = off, off+size, base
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

def seg_of(segs, a, n=1):
    for s in segs:
        if s[1] <= a and a + n <= s[1] + s[2] and s[4] > 0:
            return s
    return None

md = Cs(CS_ARCH_ARM64, CS_MODE_LITTLE_ENDIAN)
md.detail = True
md.skipdata = True
BR = ('b', 'bl', 'adr', 'adrp', 'cbz', 'cbnz', 'tbz', 'tbnz')

def fhash(d, seg, start, end):
    nm, vm, vs, fo, fs = seg
    code = d[fo+(start-vm):fo+(start-vm)+(end-start)]
    h = hashlib.sha1()
    for i in md.disasm(code, start):
        if i.id == 0:
            h.update(b'D;')
            continue
        parts = [i.mnemonic]
        for op in i.operands:
            if op.type == ARM64_OP_REG:
                parts.append('R')
            elif op.type == ARM64_OP_IMM:
                parts.append('I')
            elif op.type == ARM64_OP_MEM:
                m = op.mem
                s = '[R'
                if m.index:
                    s += '+R'
                if m.disp:
                    s += '+d'
                parts.append(s+']')
            else:
                parts.append('F' if op.type == ARM64_OP_FP else '?')
        h.update((' '.join(parts)+'\n').encode())
    return h.hexdigest()

def table(path):
    d, segs, fst = load(path)
    starts = func_starts(d, segs, fst)
    out = []
    for k in range(len(starts)-1):
        s, e = starts[k], starts[k+1]
        if e - s <= 0 or e - s > 0x20000:
            continue
        sg = seg_of(segs, s, e-s)
        if sg is None:
            continue
        out.append((s, e-s, fhash(d, sg, s, end=e)))
    return out

A, B = sys.argv[1], sys.argv[2]
TA = table(A)
TB = table(B)
print('funcs', len(TA), len(TB))
sm = difflib.SequenceMatcher(None, [x[2] for x in TA], [x[2] for x in TB], autojunk=False)
same = sum(b.size for b in sm.get_matching_blocks() if b.size)
print('identical', same, 'ratio', round(sm.ratio(), 5))
regions = [op for op in sm.get_opcodes() if op[0] != 'equal']
print('changed regions', len(regions))
n = 0
for tag, i1, i2, j1, j2 in regions:
    print(f'== {tag} A[{i1}:{i2}] B[{j1}:{j2}]')
    for k in range(i1, i2):
        print(f'   A {TA[k][0]:#x} sz={TA[k][1]}')
    for k in range(j1, j2):
        print(f'   B {TB[k][0]:#x} sz={TB[k][1]}')
    n += 1
    if n >= MAXF:
        print('... truncated')
        break
