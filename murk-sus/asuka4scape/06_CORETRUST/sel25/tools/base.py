#!/usr/bin/env python3
# list stores/loads with a given base register over an address range
import sys, struct
from kc import Fileset
from vm import VM, disasm

fs = Fileset(); vm = VM(fs)
def fix(a): return a | 0xFFFFFFF000000000 if a < 0x100000000 else a
lo = fix(int(sys.argv[1], 0)); hi = fix(int(sys.argv[2], 0))
reg = sys.argv[3] if len(sys.argv) > 3 else 'x19'
want = sys.argv[4] if len(sys.argv) > 4 else 'all'

for i in disasm(vm, lo, hi-lo):
    if f'[{reg}' not in i.op_str: continue
    k = i.mnemonic
    if want == 'str' and not k.startswith('str') and k not in ('stp','stur','stp'): continue
    print(f"{i.address & 0xFFFFFFFF:08x}  {i.mnemonic:8s} {i.op_str}")
