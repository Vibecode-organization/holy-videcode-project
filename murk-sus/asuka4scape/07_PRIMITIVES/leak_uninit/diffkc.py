#!/usr/bin/env python3
# language: Python, file: diffkc.py, target: iOS 27.0 vs 27.2 kernelcache
# Compare IOSurfaceRootUserClient dispatch tables and handler bytes between builds.
import struct, sys
import macho

K2 = "/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache"
K1 = "/home/femboychik/Рабочий стол/дипсик 1/kc/27.0_24A437_kernelcache"

def loadkc(path):
    data, segs = macho.load(path)
    return data, segs

d2, s2 = loadkc(K2)
d1, s1 = loadkc(K1)
print("27.0 segs:")
for name, vmaddr, vmsize, fileoff, filesize, secs in s1:
    print(f"  {name:16s} va={vmaddr:#x} off={fileoff:#x} size={vmsize:#x}")
