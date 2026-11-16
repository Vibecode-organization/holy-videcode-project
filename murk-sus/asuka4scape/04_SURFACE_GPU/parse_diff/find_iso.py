#!/usr/bin/env python3
"""Locate IOSurface external-method tables in a kext collection."""
import struct, sys
from kc import KC

k = KC(sys.argv[1])
tag = sys.argv[2] if len(sys.argv) > 2 else "?"

# --- 1. strings
for sname in ('__PRELINK_TEXT', '__TEXT'):
    for needle in (b'IOSurfaceRootUserClient', b'IOSurfaceRoot', b'IOSurface'):
        i = 0
        hits = []
        while True:
            i = k.find(needle, i)
            if i < 0:
                break
            va = k.off2va(i)
            hits.append((i, va))
            i += 1
            if len(hits) > 12:
                break
        if hits:
            print("[str] %-14s %-24s" % (sname, needle.decode()))
            for i, va in hits:
                print("        off=%#x va=%s ctx=%r" % (i, hex(va) if va else None,
                      k.data[max(0, i-24):i+len(needle)+40][:96]))

# --- 2. ldrb w9,[x0,#0x127]  (0x39449c09)
pat = struct.pack('<I', 0x39449C09)
i = 0
print("\n[pat] ldrb w9,[x0,#0x127] occurrences:")
n = 0
while True:
    i = k.data.find(pat, i)
    if i < 0:
        break
    va = k.off2va(i)
    if va:
        print("   %#x  (off %#x)" % (va, i))
        n += 1
    i += 1
print("   total=%d" % n)

# --- 3. wildcard ldrb Wt,[x0,#0x127] for any Rt
print("\n[pat] ldrb w?, [x0,#0x127] any Rt:")
for rt in range(8, 16):
    w = 0x39449C00 | rt
    i = k.data.find(struct.pack('<I', w))
    while i >= 0:
        va = k.off2va(i)
        if va:
            print("   w%d %#x" % (rt, va))
        i = k.data.find(struct.pack('<I', w), i+1)

# --- 4. stub returning 0xe00002e2 : mov w0,#0xe00002e2 = 0x52A00000|...  (MOVZ W0)
# movz w0,#0x2e2, lsl 16 -> 0x52A00000 | (0x2e2<<5) | 0
for imm in (0x2e2,):
    w = 0x52A00000 | (imm << 5)
    i = k.data.find(struct.pack('<I', w))
    while i >= 0:
        va = k.off2va(i)
        if va and va > 0xfffffff008000000:
            print("\n[stub?] movz w0,#%#x at %#x" % (imm, va))
        i = k.data.find(struct.pack('<I', w), i+1)
