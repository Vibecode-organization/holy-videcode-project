#!/usr/bin/env python3
# scan for 64-bit LDR/STR with imm12 offset (F940/F900)
import sys
from kc import Fileset
from vm import VM, disasm

fs = Fileset(); vm = VM(fs)
imm = int(sys.argv[1], 0)
eid_filter = sys.argv[2] if len(sys.argv) > 2 else 'IOGPUFamily'
kind = sys.argv[3] if len(sys.argv) > 3 else 'str'
nxt = 3

for (a, b, fo, nm, eid) in sorted(vm.segs):
    if nm != '__TEXT_EXEC' or eid_filter not in eid: continue
    data = vm.read(a, b-a)
    for i in range(0, len(data)-4, 4):
        w = int.from_bytes(data[i:i+4], 'little')
        op = w & 0xFFC00000
        if op not in (0xF9400000, 0xF9000000): continue
        want = 0xF9000000 if kind == 'str' else 0xF9400000
        if op != want: continue
        i12 = (w >> 10) & 0xFFF
        if i12*8 != imm: continue
        pc = a + i
        insns = list(disasm(vm, pc, 4*(nxt+1)))
        blob = " ; ".join(f"{x.mnemonic} {x.op_str}" for x in insns)
        rt = w & 0x1F; rn = (w >> 5) & 0x1F
        print(f"{pc & 0xFFFFFFFF:08x}  x{rt} -> [x{rn}+{imm:#x}]  | {blob}")
