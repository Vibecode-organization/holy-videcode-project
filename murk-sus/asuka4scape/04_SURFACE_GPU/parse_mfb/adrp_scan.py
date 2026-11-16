#!/usr/bin/env python3
# global scan: adrp targeting a page of interest, show following insns
import struct, sys
from kc import load
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
k = load()
md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)

def scan(pages):
    res = []
    for s in k.segs:
        if s['name'] not in ('__TEXT_EXEC', '__TEXT', '__PRELINK_TEXT'):
            continue
        n = s['filesize']//4
        w = struct.unpack_from('<%dI' % n, k.data, s['fileoff'])
        for i, x in enumerate(w):
            if (x & 0x9F000000) != 0x90000000:
                continue
            immlo = (x >> 29) & 3
            immhi = (x >> 5) & 0x7FFFF
            imm = (immhi << 2) | immlo
            if imm & 0x100000: imm -= 0x200000
            pc = s['vmaddr'] + i*4
            tgt = ((pc & ~0xFFF) + (imm << 12)) & 0xFFFFFFFFFFFFFFFF
            if tgt in pages:
                res.append((pc, tgt, s['name'], i, s, w))
    return res

if __name__ == '__main__':
    pages = set(int(a, 16) for a in sys.argv[1:])
    for pc, tgt, seg, i, s, w in scan(pages):
        print(f"\n@{pc:#x} ({seg}) adrp -> {tgt:#x}")
        off = s['fileoff'] + i*4
        for ins in md.disasm(k.data[off:off+24], pc):
            print(f"    {ins.address:#x} {ins.mnemonic} {ins.op_str}")
