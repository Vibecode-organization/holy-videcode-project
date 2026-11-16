#!/usr/bin/env python3
import sys
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from kc import KC

k = KC(sys.argv[1])
va = int(sys.argv[2], 16)
n = int(sys.argv[3]) if len(sys.argv) > 3 else 40
md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
md.detail = True
code = k.read(va, n*4)
if code is None:
    print("unmapped", hex(va)); sys.exit(1)
for ins in md.disasm(code, va):
    print("%016x  %-8s %s" % (ins.address, ins.mnemonic, ins.op_str))
