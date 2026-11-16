#!/usr/bin/env python3
# language: Python, file: refs.py, target: iOS 27.2 arm64e kernelcache
# Fast ADRP/ADD|LDR reference scanner (opcode prefilter, then capstone).
import sys, struct
from capstone import *
from macho import load, BASE
from kdis import md, _int

data, segs = load()
TEXT_START, TEXT_SIZE = 0xfffffff00814c000, 0x2924000

def scan(target, window=0x40):
    hits = []
    n = TEXT_SIZE // 4
    words = struct.unpack_from(f"<{n}I", data, TEXT_START - BASE)
    pages = {}
    for i, w in enumerate(words):
        if (w & 0x9F000000) != 0x90000000:
            continue
        va = TEXT_START + i*4
        try:
            insn = next(md.disasm(struct.pack("<I", w), va))
            reg, imm = [x.strip() for x in insn.op_str.split(",")]
            page = _int(imm)
        except Exception:
            continue
        pages.setdefault(page, []).append((va, reg))
    for (va, reg) in pages.get(target & ~0xfff, []):
        for d in range(4, window, 4):
            try:
                ni = next(md.disasm(data[va-BASE+d:va-BASE+d+4], va+d))
            except StopIteration:
                break
            if ni.mnemonic in ("add", "ldr", "ldrb", "ldrh", "ldrsw") and ni.op_str.startswith(reg + ","):
                parts = [x.strip() for x in ni.op_str.split(",")]
                try:
                    off = _int(parts[1])
                except Exception:
                    break
                if (target & ~0xfff) + off == target:
                    hits.append((va, ni.mnemonic, va+d))
                break
            if ni.mnemonic[0] == "b" or ni.mnemonic in ("ret", "blr"):
                break
    return hits

if __name__ == "__main__":
    for a in sys.argv[1:]:
        t = _int(a)
        h = scan(t)
        print(hex(t), len(h))
        for x in h[:20]:
            print("   ", hex(x[0]), x[1], "at", hex(x[2]))
