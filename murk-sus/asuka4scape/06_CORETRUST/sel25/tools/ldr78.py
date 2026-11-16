#!/usr/bin/env python3
# list all ldr xT,[xN,#imm] sites in a kext with the next N insns
import sys
from kc import Fileset
from vm import VM, disasm

fs = Fileset(); vm = VM(fs)
imm = int(sys.argv[1], 0)
eid_filter = sys.argv[2] if len(sys.argv) > 2 else 'IOGPUFamily'
nxt = int(sys.argv[3], 0) if len(sys.argv) > 3 else 3

import struct
for (a, b, fo, nm, eid) in vm.segs:
    if nm != '__TEXT_EXEC' or eid_filter not in eid: continue
    n = b - a
    data = vm.read(a, n)
    for i in range(0, n-4, 4):
        w = int.from_bytes(data[i:i+4], 'little')
        # LDR Xt, [Xn, #imm] : 1111 1001 01 imm12 Rn Rt
        if (w & 0xFFC00000) != 0xF9400000: continue
        i12 = (w >> 10) & 0xFFF
        if i12*8 != imm: continue
        pc = a + i
        insns = list(disasm(vm, pc, 4*(nxt+1)))
        blob = " ; ".join(f"{x.mnemonic} {x.op_str}" for x in insns)
        rt = w & 0x1F; rn = (w >> 5) & 0x1F
        print(f"{pc & 0xFFFFFFFF:08x}  x{rt} <- [x{rn}+{imm:#x}]  | {blob}")
