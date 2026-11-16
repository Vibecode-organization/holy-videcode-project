#!/usr/bin/env python3
# find all calls to a target function and print preceding insns + resolved string args
import sys
from kc import Fileset
from vm import VM, disasm

fs = Fileset(); vm = VM(fs)
def fix(a): return a | 0xFFFFFFF000000000 if a < 0x100000000 else a
tgt = fix(int(sys.argv[1], 0))
back = int(sys.argv[2], 0) if len(sys.argv) > 2 else 0x18

for (a, b, fo, nm, eid) in vm.segs:
    if nm != '__TEXT_EXEC': continue
    data = vm.read(a, b-a)
    for i in range(0, len(data)-4, 4):
        w = int.from_bytes(data[i:i+4], 'little')
        # BL imm26
        if (w & 0xFC000000) != 0x94000000: continue
        imm = w & 0x3FFFFFF
        if imm & (1 << 25): imm -= 1 << 26
        pc = a + i
        if pc + imm*4 != tgt: continue
        print(f"--- call at {pc & 0xFFFFFFFF:08x}")
        insns = list(disasm(vm, pc-back, back+4))
        for ins in insns[-6:]:
            extra = ''
            if ins.mnemonic == 'adrp':
                # resolve page
                extra = ''
            print(f"  {ins.address & 0xFFFFFFFF:08x}  {ins.mnemonic:8s} {ins.op_str}")
