#!/usr/bin/env python3
# language: Python, file: scan_ref.py, target: iOS 27.2 arm64e kernelcache
# ADRP+ADD/LDR reference scanner across __PRELINK_TEXT.__text and __TEXT_EXEC.__text.
# Capstone ADRP imm is SIGNED -> mask with 0xFFFFFFFFFFFFFFFF.
import sys, struct
from capstone import *
from macho import load, BASE
from kdis import md, _int

data, segs = load()

RANGES = []
for name, vmaddr, vmsize, fileoff, filesize, secs in segs:
    if name in ("__PRELINK_TEXT", "__TEXT_EXEC", "__TEXT_BOOT_EXEC"):
        RANGES.append((vmaddr, vmsize))


def scan(target, window=0x40):
    hits = []
    page = target & ~0xfff
    for start, size in RANGES:
        n = size // 4
        words = struct.unpack_from(f"<{n}I", data, start - BASE)
        for i, w in enumerate(words):
            if (w & 0x9F000000) != 0x90000000:
                continue
            va = start + i * 4
            try:
                insn = next(md.disasm(struct.pack("<I", w), va))
                reg, imm = [x.strip() for x in insn.op_str.split(",")]
                p = _int(imm) & 0xFFFFFFFFFFFFFFFF
            except Exception:
                continue
            if p != page:
                continue
            for d in range(4, window, 4):
                try:
                    ni = next(md.disasm(data[va - BASE + d: va - BASE + d + 4], va + d))
                except StopIteration:
                    break
                m, op = ni.mnemonic, ni.op_str
                parts = [x.strip() for x in op.split(",")]
                if m in ("add", "ldr", "ldrb", "ldrh", "ldrsw") and len(parts) >= 2 and parts[0] == reg:
                    if m == "add" and len(parts) == 3 and parts[1] == reg and parts[2].startswith("#"):
                        off = _int(parts[2]) & 0xFFFFFFFFFFFFFFFF
                        if page + off == target:
                            hits.append((va, m, va + d))
                        break
                    if m != "add" and parts[1].startswith("[") and parts[1].startswith("[" + reg):
                        # ldr reg, [reg, #imm]
                        try:
                            off = _int(parts[1].split("#")[1].rstrip("]")) & 0xFFFFFFFFFFFFFFFF
                        except Exception:
                            continue
                        if page + off == target:
                            hits.append((va, m, va + d))
                        break
                    continue
                if m[0] == "b" or m in ("ret", "blr", "br"):
                    break
    return hits


if __name__ == "__main__":
    for a in sys.argv[1:]:
        t = _int(a) & 0xFFFFFFFFFFFFFFFF
        h = scan(t)
        print(hex(t), len(h))
        for x in h[:30]:
            print("   ", hex(x[0]), x[1], "at", hex(x[2]))
