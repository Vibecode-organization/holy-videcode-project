#!/usr/bin/env python3
# Identify changed kernel functions by the strings they reference.
import sys, struct, re
from capstone import *
from capstone.arm64 import *

KC = '/home/femboychik/Рабочий стол/дипсик 1/kcore/272/com.apple.kernel'
REPORT = sys.argv[1] if len(sys.argv)>1 else '/home/femboychik/Рабочий стол/дипсик 1/reports/kcore_shape_diff.txt'

d = open(KC, 'rb').read()
magic, ct, cs, ft, ncmds, sz, fl, _ = struct.unpack_from('<IiiIIIII', d, 0)
p = 32
segs = []
for _ in range(ncmds):
    cmd, csz = struct.unpack_from('<II', d, p)
    if cmd == 0x19:
        nm = d[p+8:p+24].split(b'\0')[0].decode()
        vm, vs, fo, fs = struct.unpack_from('<QQQQ', d, p+24)
        segs.append((nm, vm, vs, fo, fs))
    p += csz

def read(a, n):
    for nm, vm, vs, fo, fs in segs:
        if vm <= a and a + n <= vm + vs and fs:
            return d[fo + (a - vm):fo + (a - vm) + n]
    return None

# string map: scan all non-exec segments for printable runs >= 6
strs = {}
for nm, vm, vs, fo, fs in segs:
    if fs == 0 or nm in ('__text','__TEXT_EXEC'):
        continue
    blob = d[fo:fo+fs]
    i = 0
    while i < len(blob):
        j = i
        while j < len(blob) and 32 <= blob[j] < 127:
            j += 1
        if j - i >= 6:
            s = blob[i:j].decode('ascii', 'replace')
            if re.search(r'[A-Za-z]{3}', s):
                strs[vm + i] = s
        i = max(j, i + 1)

md = Cs(CS_ARCH_ARM64, CS_MODE_LITTLE_ENDIAN)
md.detail = True
md.skipdata = True

def refs(a, size):
    out = []
    adrp = {}
    code = read(a, size)
    if not code:
        return out
    for i in md.disasm(code, a):
        if i.id == 0:
            continue
        ops = i.operands
        if i.mnemonic == 'adrp' and len(ops) == 2 and ops[1].type == ARM64_OP_IMM:
            adrp[ops[0].reg] = ops[1].imm
        elif i.mnemonic in ('add', 'ldr') and len(ops) == 3 and ops[1].type == ARM64_OP_REG and ops[2].type == ARM64_OP_IMM:
            base = ops[1].reg
            if base in adrp:
                t = (adrp[base] + ops[2].imm) & 0xffffffffffffffff
                if t in strs:
                    out.append(strs[t])
    return out

text = [l for l in open(REPORT).read().splitlines()]
regions = []
cur = None
for l in text:
    m = re.match(r'== (\w+) A\[(\d+):(\d+)\] B\[(\d+):(\d+)\]', l)
    if m:
        if cur: regions.append(cur)
        cur = {'tag': m.group(1), 'b': []}
        continue
    m = re.match(r'\s+B (0x[0-9a-f]+) sz=(\d+)', l)
    if m and cur:
        cur['b'].append((int(m.group(1), 16), int(m.group(2))))
if cur: regions.append(cur)

for r in regions:
    for a, size in r['b'][:1]:
        ss = refs(a, size)
        # pick informative strings
        pick = [s for s in ss if ('%' in s or '/' in s or 'assert' in s.lower() or 'invalid' in s.lower() or 'overflow' in s.lower())]
        if not pick: pick = ss[:2]
        seen = []
        for s in pick:
            if s not in seen: seen.append(s)
        print(f"{a:#x} sz={size} :: " + ' | '.join(x[:90] for x in seen[:3]))
