#!/usr/bin/env python3
# fast pattern scan over __TEXT_EXEC for LDR/STR with a given unsigned imm12 offset
# usage: pat.py <imm-bytes> [--str|--ldr|--both]
import sys, struct
from kc import Fileset
from vm import VM

fs = Fileset(); vm = VM(fs)
imm = int(sys.argv[1], 0)
mode = sys.argv[2] if len(sys.argv) > 2 else 'both'
imm12 = imm // 4

# ranges of executable segments
ranges = [(a, b, fo) for (a, b, fo, nm, eid) in vm.segs if nm == '__TEXT_EXEC']

def decode_word(w):
    # LDR/STR (immediate, unsigned offset), 32-bit Wt
    # 0xB9000000 STR Wt ; 0xB9400000 LDR Wt  (size=10 opc=00/01)
    op = w & 0xFFC00000
    if op not in (0xB9000000, 0xB9400000):
        return None
    i12 = (w >> 10) & 0xFFF
    if i12 != imm12:
        return None
    rn = (w >> 5) & 0x1F
    rt = w & 0x1F
    return ('str' if op == 0xB9000000 else 'ldr', rn, rt)

for (a, b, fo) in ranges:
    n = b - a
    data = bytes(vm.d[fo:fo+n])
    for i in range(0, n - 3, 4):
        w = struct.unpack_from('<I', data, i)[0]
        d = decode_word(w)
        if not d: continue
        k, rn, rt = d
        if mode == '--str' and k != 'str': continue
        if mode == '--ldr' and k != 'ldr': continue
        print(f"{(a+i)&0xFFFFFFFF:08x}  {k} w{rt}, [x{rn}, #{imm:#x}]")
