#!/usr/bin/env python3
# find all instructions referencing an immediate offset in a range, within a VA range
import sys, struct
from kc import Fileset
from vm import VM, disasm

fs = Fileset(); vm = VM(fs)

def scan(va, n, needle):
    for i in disasm(vm, va, n):
        if needle in i.op_str:
            print(f"{i.address & 0xFFFFFFFF:08x}  {i.mnemonic:8s} {i.op_str}")

if __name__ == '__main__':
    va = int(sys.argv[1], 0); n = int(sys.argv[2], 0); needle = sys.argv[3]
    if va < 0x100000000: va |= 0xFFFFFFF000000000
    scan(va, n, needle)
