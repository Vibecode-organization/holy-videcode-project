#!/usr/bin/env python3
# find adrp+add sequences producing a target VA, print surrounding 8 insns
import sys
from kc import Fileset
from vm import VM, disasm

fs = Fileset(); vm = VM(fs)
target = int(sys.argv[1], 0)

def fix(a): return a | 0xFFFFFFF000000000 if a < 0x100000000 else a
target = fix(target)
page = target & ~0xFFF
off = target & 0xFFF

for (a, b, fo, nm, eid) in vm.segs:
    if nm != '__TEXT_EXEC': continue
    n = b - a
    data = vm.read(a, n)
    for i in range(0, n - 8, 4):
        # ADRP Xd, page : 1xx10000 immhi immlo Rd  -> mask 0x9F000000 == 0x90000000
        w = int.from_bytes(data[i:i+4], 'little')
        if (w & 0x9F000000) != 0x90000000: continue
        immlo = (w >> 29) & 3
        immhi = (w >> 5) & 0x7FFFF
        imm = ((immhi << 2) | immlo) << 12
        if imm & (1 << 32): imm -= 1 << 33
        pc = a + i
        dst = (pc & ~0xFFF) + imm
        if dst != page: continue
        rd = w & 0x1F
        nxt = int.from_bytes(data[i+4:i+8], 'little')
        # ADD Xd, Xn, #imm12 : 1001000100 imm12 Rn Rd
        if (nxt & 0xFFC00000) != 0x91000000: continue
        rn = (nxt >> 5) & 0x1F
        rd2 = nxt & 0x1F
        imm12 = (nxt >> 10) & 0xFFF
        if rn != rd or rd2 != rd or imm12 != off: continue
        print(f"--- hit at {pc & 0xFFFFFFFF:08x} -> {target:#x}")
        for ins in disasm(vm, pc - 0x10, 0x40):
            print(f"  {ins.address & 0xFFFFFFFF:08x}  {ins.mnemonic:8s} {ins.op_str}")
