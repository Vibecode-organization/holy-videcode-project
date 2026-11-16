#!/usr/bin/env python3
# raw range disassembly, no stop conditions
import sys
from mo import MachO, md

m = MachO()
va = int(sys.argv[1], 16)
n = int(sys.argv[2], 16)
code = m.read(va, n)
for ins in md.disasm(code, va):
    print('%016x: %-8s %s' % (ins.address, ins.mnemonic, ins.op_str))
