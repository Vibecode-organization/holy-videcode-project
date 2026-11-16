#!/usr/bin/env python3
# find adrp to a page, show next 6 insns; filter by following add immediate if given
import sys
from kc import Fileset
from vm import VM, disasm

fs = Fileset(); vm = VM(fs)
def fix(a): return a | 0xFFFFFFF000000000 if a < 0x100000000 else a
page = fix(int(sys.argv[1], 0)) & ~0xFFF
want = sys.argv[2] if len(sys.argv) > 2 else None

for (a, b, fo, nm, eid) in vm.segs:
    if nm != '__TEXT_EXEC': continue
    data = vm.read(a, b-a)
    for i in range(0, len(data)-4, 4):
        w = int.from_bytes(data[i:i+4], 'little')
        if (w & 0x9F000000) != 0x90000000: continue
        immlo = (w >> 29) & 3
        immhi = (w >> 5) & 0x7FFFF
        imm = ((immhi << 2) | immlo) << 12
        if imm & (1 << 32): imm -= 1 << 33
        pc = a + i
        if (pc & ~0xFFF) + imm != page: continue
        insns = list(disasm(vm, pc, 0x1C))
        blob = " ; ".join(f"{x.mnemonic} {x.op_str}" for x in insns)
        if want and want not in blob: continue
        rd = w & 0x1F
        print(f"{pc & 0xFFFFFFFF:08x} [x{rd}]  {blob}")
