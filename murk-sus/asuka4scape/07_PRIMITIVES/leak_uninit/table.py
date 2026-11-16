#!/usr/bin/env python3
# language: Python, file: table.py, target: iOS 27.2 arm64e kernelcache
# Dump the IOSurfaceRootUserClient external method table at 0xfffffff008068b90.
import struct, sys
from macho import load, BASE

VA = 0xfffffff008068b90
N = 60
STRIDE = 0x28

def pac(q):
    # PAC-stripped VA per the brief: base + (q & 0x0FFFFFFF)
    return BASE + (q & 0x0FFFFFFF)

data, segs = load()

def rd(va, n):
    return data[va - BASE: va - BASE + n]

print(f"table va={VA:#x} off={VA-BASE:#x}")
print("idx  count  fn0(pac)      fn1(pac)      nameptr")
for i in range(N):
    off = VA - BASE + i*STRIDE
    a, b, c, d, e = struct.unpack_from("<QQQQQ", data, off)
    # external method: u32 count, u64 func[2], u64 nameptr (IOSurface names 64-bit packed)
    print(f"{i:3d}  {a:#010x} {pac(b):#014x} {pac(c):#014x} {d:#x} {e:#x}")

print()
print("raw first records:")
for i in range(6):
    off = VA - BASE + i*STRIDE
    print(hex(VA + i*STRIDE), data[off:off+STRIDE].hex())
