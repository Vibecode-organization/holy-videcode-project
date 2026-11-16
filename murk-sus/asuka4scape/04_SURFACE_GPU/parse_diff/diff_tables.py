#!/usr/bin/env python3
"""Diff IOSurface external-method tables 27.0 vs 27.2 and emit selector dumps."""
import struct, sys, json
from kc import KC
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM

K270 = "/home/femboychik/Рабочий стол/дипсик 1/kc/27.0_24A437_kernelcache"
K272 = "/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache"
A270, B270 = 0xfffffff00805b530, 0xfffffff00805be90
A272, B272 = 0xfffffff008068b90, 0xfffffff0080694f0
STUB270 = 0xfffffff009bfe234
STUB272 = 0xfffffff009c3a1dc
DELTA = 0x3bfa8   # 272_fn = 270_fn + DELTA (verified below)

def table(k, base, count=60, stride=0x28):
    rows = []
    for i in range(count):
        b = k.read(base + i*stride, stride)
        fn = k.unpac(struct.unpack_from('<Q', b, 0)[0])
        sIn, strIn, sOut, strOut, flags = struct.unpack_from('<IIIiI', b, 8)
        rows.append(dict(sel=i, fn=fn, raw=struct.unpack_from('<Q', b, 0)[0],
                         sIn=sIn, strIn=strIn, sOut=sOut, strOut=strOut, flags=flags))
    return rows

def fmt(x):
    return "-1" if x == 0xffffffff else str(x)

def write_dump(path, k, base, label, rows):
    with open(path, 'a') as f:
        f.write("# table %s @ %#018x  (stride 0x28, entries used: 60)\n" % (label, base))
        f.write("# sel  fn            sIn strIn sOut strOut flags\n")
        for r in rows:
            f.write("%4d  %#018x  %3d %4s %4d %6s %d\n" % (
                r['sel'], r['fn'], r['sIn'], fmt(r['strIn']), r['sOut'], fmt(r['strOut']), r['flags']))
        f.write("\n")

k0, k2 = KC(K270), KC(K272)
A0, B0 = table(k0, A270), table(k0, B270)
A2, B2 = table(k2, A272), table(k2, B272)

# --- sanity: PAC signature distribution
from collections import Counter
sig0 = Counter((r['raw'] >> 32) for r in A0 + B0)
sig2 = Counter((r['raw'] >> 32) for r in A2 + B2)
print("27.0 pac sigs:", {hex(k): v for k, v in sig0.items()})
print("27.2 pac sigs:", {hex(k): v for k, v in sig2.items()})

# --- delta census over table A+B
deltas = Counter()
for r0, r2 in zip(A0 + B0, A2 + B2):
    if r0['fn'] != STUB270 and r2['fn'] != STUB272:
        deltas[r2['fn'] - r0['fn']] += 1
print("delta census (non-stub):", {hex(k): v for k, v in deltas.most_common()})

print("\n=== table A: index-level compare (fn normalized to 27.2 by +%#x) ===" % DELTA)
fields = ('sIn', 'strIn', 'sOut', 'strOut', 'flags')
def compare(name, t0, t2, stub0, stub2):
    out = []
    for r0, r2 in zip(t0, t2):
        d = {}
        n0 = r0['fn'] + DELTA
        if n0 != r2['fn']:
            d['fn'] = (r0['fn'], r2['fn'])
        for f in fields:
            if r0[f] != r2[f]:
                d[f] = (r0[f], r2[f])
        s0 = (r0['fn'] == stub0)
        s2 = (r2['fn'] == stub2)
        if s0 != s2:
            d['stub'] = (s0, s2)
        if d:
            out.append((r0['sel'], d))
    print("--- %s: %d differing slots" % (name, len(out)))
    for sel, d in out:
        print("  sel %2d: %s" % (sel, d))
    return out

dA = compare("A", A0, A2, STUB270, STUB272)
dB = compare("B", B0, B2, STUB270, STUB272)

# --- write 27.0 dump
open('/home/femboychik/work/parse_diff/selectors_27.0.txt', 'w').close()
write_dump('/home/femboychik/work/parse_diff/selectors_27.0.txt', k0, A270, "A", A0)
write_dump('/home/femboychik/work/parse_diff/selectors_27.0.txt', k0, B270, "B", B0)
print("\nwrote selectors_27.0.txt")
