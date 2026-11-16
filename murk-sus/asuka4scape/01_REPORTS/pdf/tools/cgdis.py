#!/usr/bin/env python3
"""VA->file offset disassembler for the extracted CoreGraphics dylib."""
import sys, lief
from capstone import *

BIN = "/home/femboychik/work/pdf/CoreGraphics.27.2"

class Bin:
    def __init__(self, path=BIN):
        self.b = lief.MachO.parse(path).at(0)
        self.segs = []
        for s in self.b.segments:
            if s.file_size:
                self.segs.append((s.virtual_address, s.virtual_address + s.file_size, s.file_offset))
    def off(self, va):
        for lo, hi, fo in self.segs:
            if lo <= va < hi:
                return fo + (va - lo)
        return None
    def read(self, va, n):
        o = self.off(va)
        if o is None: return None
        with open(self.b.name if hasattr(self.b,'name') else BIN, 'rb') as f:
            f.seek(o); return f.read(n)

def main():
    va = int(sys.argv[1], 0)
    n = int(sys.argv[2], 0) if len(sys.argv) > 2 else 0x200
    b = Bin()
    data = b.read(va, n)
    if data is None:
        print("no mapping for", hex(va)); return
    md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    md.detail = False
    print(f"; VA {va:#x} ({n:#x} bytes) fileoff {b.off(va):#x}")
    for i in md.disasm(data, va):
        print(f"{i.address:#014x}: {i.bytes.hex():<10} {i.mnemonic:<8} {i.op_str}")

if __name__ == "__main__":
    main()
