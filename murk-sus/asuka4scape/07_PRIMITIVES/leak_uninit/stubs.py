#!/usr/bin/env python3
# language: Python, file: stubs.py, target: iOS 27.2 arm64e kernelcache
# Resolve __auth_stubs thunks: stub VA -> imported function VA (PAC-stripped).
import struct, sys
from macho import load, BASE
from kdis import md

data, segs = load()

def q(va):
    return struct.unpack_from("<Q", data, va - BASE)[0]

def resolve(stub_va):
    # bti c; adrp x17,page; add x17,x17,#off; ldr x16,[x17]; braa x16,x17
    for d in range(0, 32, 4):
        try:
            i = next(md.disasm(data[stub_va-BASE+d:stub_va-BASE+d+4], stub_va+d))
        except StopIteration:
            continue
        if i.mnemonic == "adrp" and i.op_str.startswith("x17"):
            page = int(i.op_str.split(",")[1].strip().lstrip("#"), 0)
        elif i.mnemonic == "add" and i.op_str.startswith("x17, x17"):
            off = int(i.op_str.split(",")[2].strip().lstrip("#"), 0)
            slot = page + off
            return slot, BASE + (q(slot) & 0x0FFFFFFF), q(slot)
    return None

if __name__ == "__main__":
    for a in sys.argv[1:]:
        v = int(a, 0)
        r = resolve(v)
        print(hex(v), "->", None if not r else (hex(r[0]), hex(r[1]), hex(r[2])))
