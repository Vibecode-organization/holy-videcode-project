#!/usr/bin/env python3
import struct, sys
from kc import *
import bl

def show(va, n=0x600):
    off = va2off(va)
    if off is None:
        print("no map", hex(va)); return
    for ins in MD.disasm(DATA[off:off+n], va):
        print("%#012x  %-8s %s" % (ins.address, ins.mnemonic, ins.op_str))
        if ins.mnemonic in ("ret", "retab"):
            break

if __name__ == "__main__":
    for a in sys.argv[1:]:
        va = int(a, 0)
        print("\n" + "="*90)
        print("FUNC %#x" % va)
        show(va)
