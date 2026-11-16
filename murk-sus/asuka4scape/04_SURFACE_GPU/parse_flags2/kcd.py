#!/usr/bin/env python3
import struct, sys
from capstone import *
KC = "/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache"
BASE = 0xfffffff007004000
data = open(KC,'rb').read()
SECTIONS = {
 '__TEXT':          (0xfffffff007004000, 0x8000,    0x0),
 '__PRELINK_TEXT':  (0xfffffff00700c000, 0xbac000,  0x8000),
 '__DATA_CONST':    (0xfffffff007bb8000, 0x548000,  0xbb4000),
 '__DATA_SPTM':     (0xfffffff008100000, 0x4c000,   0x10fc000),
 '__TEXT_EXEC':     (0xfffffff00814c000, 0x2924000, 0x1148000),
 '__TEXT_BOOT_EXEC':(0xfffffff00aa70000, 0x8000,    0x3a6c000),
 '__PRELINK_INFO':  (0xfffffff00aa78000, 0x23c000,  0x3a74000),
 '__DATA':          (0xfffffff00acb4000, 0x2b8000,  0x3cb0000),
 '__LINKEDIT':      (0xfffffff00af6c000, 0xb8000,   0x3f68000),
}
def va2off(va):
    for n,(v,sz,fo) in SECTIONS.items():
        if v <= va < v+sz: return fo + (va-v)
    return None
md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
md.detail = True
def dis(va, n=40, tag=""):
    o = va2off(va)
    print(f"--- 0x{va:x} {tag}")
    for i in md.disasm(data[o:o+n*4], va):
        print(f"  0x{i.address:x}: {i.mnemonic}\t{i.op_str}")
if __name__ == '__main__':
    a = int(sys.argv[1],16); n = int(sys.argv[2]) if len(sys.argv)>2 else 40
    dis(a,n)
