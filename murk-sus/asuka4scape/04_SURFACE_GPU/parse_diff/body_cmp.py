#!/usr/bin/env python3
"""Byte-compare handler bodies 27.0 vs 27.2 at fn and fn+delta; also scan for
any other 60x0x28 IOSurface-shaped tables in both images."""
import struct, sys
from collections import Counter
from kc import KC

K270 = "/home/femboychik/Рабочий стол/дипсик 1/kc/27.0_24A437_kernelcache"
K272 = "/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache"
A270, B270 = 0xfffffff00805b530, 0xfffffff00805be90
A272, B272 = 0xfffffff008068b90, 0xfffffff0080694f0
DELTA = 0x3bfa8
ISORANGE = (0xfffffff009b00000, 0xfffffff009d00000)

def table(k, base, count=60, stride=0x28):
    rows = []
    for i in range(count):
        b = k.read(base + i*stride, stride)
        fn = k.unpac(struct.unpack_from('<Q', b, 0)[0])
        sIn, strIn, sOut, strOut, flags = struct.unpack_from('<IIIiI', b, 8)
        rows.append((i, fn, sIn, strIn, sOut, strOut, flags))
    return rows

k0, k2 = KC(K270), KC(K272)
A0, A2 = table(k0, A270), table(k2, A272)
B0, B2 = table(k0, B270), table(k2, B272)

def body(k, va, n=0x400):
    return k.read(va, n)

print("=== handler body compare (first 0x400 bytes) ===")
ndiff = 0
for tag, t0, t2 in (('A', A0, A2), ('B', B0, B2)):
    for r0, r2 in zip(t0, t2):
        b0 = body(k0, r0[1])
        b2 = body(k2, r0[1] + DELTA)
        if b0 is None or b2 is None:
            print("  %s sel %2d: unreadable" % (tag, r0[0])); ndiff += 1; continue
        if b0 != b2:
            # locate first differing byte
            i = next(x for x in range(len(b0)) if b0[x] != b2[x])
            print("  %s sel %2d fn %#x/%#x first diff +%#x" % (tag, r0[0], r0[1], r2[1], i))
            ndiff += 1
print("total bodies differing:", ndiff)

print("\n=== scan for other 60x0x28 PAC tables pointing into IOSurface range ===")
def scan(k, tag):
    for segname in ('__DATA_CONST', '__DATA'):
        s = k.seg(segname)
        data = k.data[s['fileoff']:s['fileoff']+s['filesize']]
        for off in range(0, len(data) - 60*0x28, 8):
            ok = 0
            for i in range(60):
                q = struct.unpack_from('<Q', data, off + i*0x28)[0]
                hi = q >> 32
                if hi & 0xff000000 != 0x80000000 and hi not in (0x8050bcad, 0x8060bcad, 0x8000bcad):
                    ok = -1; break
                va = k.pac_base + (q & 0x0FFFFFFF)
                if not (ISORANGE[0] <= va < ISORANGE[1]):
                    ok = -1; break
                sIn, strIn, sOut, strOut, flags = struct.unpack_from('<IIIiI', data, off + i*0x28 + 8)
                # plausibility
                if sIn > 8 or sOut > 8 or flags > 1:
                    ok = -1; break
                ok += 1
            if ok == 60:
                print("  %s %s off %#x va %#x" % (tag, segname, off, s['vmaddr'] + off))

scan(k0, '27.0')
scan(k2, '27.2')
