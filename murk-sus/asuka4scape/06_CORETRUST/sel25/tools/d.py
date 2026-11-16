#!/usr/bin/env python3
# quick disasm helper: d.py <va-or-low32> <nbytes>
# accepts either full VA (0xfffffff00...) or low-32 form used in reports
import sys
from kc import Fileset
from vm import VM, disasm

fs = Fileset(); vm = VM(fs)

def fix(a):
    if a < 0x100000000:
        return 0xFFFFFFF000000000 | a
    return a

va = fix(int(sys.argv[1], 0))
n = int(sys.argv[2], 0) if len(sys.argv) > 2 else 0x200
for i in disasm(vm, va, n):
    print(f"{i.address & 0xFFFFFFFF:08x}  {i.mnemonic:8s} {i.op_str}")
