#!/usr/bin/env python3
"""Dump 60x0x28 external-method tables from a kext collection."""
import struct, sys
from kc import KC

def dump(k, base, count=60, stride=0x28):
    rows = []
    for i in range(count):
        a = base + i*stride
        b = k.read(a, stride)
        if b is None or len(b) < stride:
            rows.append((i, None, None, None, None, None, None, None))
            continue
        fn_raw = struct.unpack_from('<Q', b, 0)[0]
        fn = k.unpac(fn_raw)
        sIn, strIn, sOut, strOut, flags = struct.unpack_from('<IIIiI', b, 8)
        rows.append((i, fn, fn_raw, sIn, strIn, sOut, strOut, flags))
    return rows

def fmt31(x):
    return "-1" if x == 0xffffffff else str(x)

def show(k, base, label):
    rows = dump(k, base)
    print("# table %s @ %#018x  (stride 0x28, entries used: 60)" % (label, base))
    print("# sel  fn            fn_raw              sIn strIn sOut strOut flags")
    for (i, fn, raw, sIn, strIn, sOut, strOut, flags) in rows:
        if fn is None:
            print("%4d  ?? " % i); continue
        print("%4d  %#018x  %#018x  %3d %4s %4d %6s %d" % (
            i, fn, raw, sIn, fmt31(strIn), sOut, fmt31(strOut), flags))
    return rows

if __name__ == '__main__':
    k = KC(sys.argv[1])
    for arg in sys.argv[2:]:
        label, addr = arg.split('=')
        show(k, int(addr, 16), label)
