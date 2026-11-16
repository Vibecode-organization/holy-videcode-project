#!/usr/bin/env python3
# language: Python, file: dis.py, target: iOS 27.2 arm64e kernelcache
# Recursive-descent disassembler for one function, with ADRP/ADD annotation.
import sys, struct
from capstone import *
from capstone.arm64 import *
from macho import load, BASE

data, segs = load()
md = Cs(CS_ARCH_ARM64, CS_MODE_LITTLE_ENDIAN)
md.detail = True

def rd(va, n):
    return data[va - BASE: va - BASE + n]

def read_cstr(va, maxlen=160):
    try:
        off = va - BASE
        if off < 0 or off >= len(data):
            return None
        end = data.find(b"\0", off, off + maxlen)
        if end < 0:
            return None
        s = data[off:end]
        if all(32 <= c < 127 or c in (9, 10, 13) for c in s) and len(s) >= 2:
            return s.decode()
    except Exception:
        pass
    return None

def _int(s):
    s = s.strip()
    if s.startswith("#"):
        s = s[1:]
    return int(s, 0)

def pac_strip(q):
    return BASE + (q & 0x0FFFFFFF)

class Func:
    def __init__(self, va):
        self.va = va
        self.insns = {}     # va -> (mnemonic, op_str, bytes, insn)
        self.order = []
        self.work = [va]
        self.seen = set()
        self.calls = set()
        self.labels = set()

    def run(self, limit=4000):
        while self.work and len(self.order) < limit:
            va = self.work.pop(0)
            if va in self.seen:
                continue
            while True:
                if va in self.seen or va < BASE:
                    break
                self.seen.add(va)
                code = rd(va, 4)
                if len(code) < 4:
                    break
                insns = list(md.disasm(code, va))
                if not insns:
                    break
                insn = insns[0]
                self.insns[va] = insn
                self.order.append(va)
                m = insn.mnemonic
                op = insn.op_str
                if m == "b":
                    try:
                        tgt = _int(op)
                        if tgt < va:  # backward jump = loop; keep linear for fallthrough
                            self.work.append(tgt)
                        else:
                            self.work.append(tgt)
                        break
                    except Exception:
                        break
                elif m in ("bl", "blr"):
                    try:
                        self.calls.add(_int(op))
                    except Exception:
                        pass
                    if m == "blr":
                        break
                    va += 4
                    continue
                elif m == "ret" or m == "br" or m.startswith("br") :
                    break
                elif m.startswith("b.") or m in ("cbz", "cbnz", "tbz", "tbnz"):
                    parts = op.split(",")
                    try:
                        tgt = _int(parts[-1])
                        self.work.append(tgt)
                    except Exception:
                        pass
                    va += 4
                    continue
                elif m in ("udf", "brk"):
                    break
                va += 4

    def annotate(self):
        # find adrp/add pairs
        notes = {}
        vals = {}
        for va in self.order:
            insn = self.insns[va]
            m, op = insn.mnemonic, insn.op_str
            if m == "adrp":
                try:
                    reg, imm = [x.strip() for x in op.split(",")]
                    vals[reg] = _int(imm)
                except Exception:
                    pass
            elif m in ("add", "ldr", "ldrb", "ldrh", "ldrsw", "str", "strb", "strh", "ldp", "stp"):
                parts = [x.strip() for x in op.split(",")]
                if len(parts) >= 2 and parts[1].startswith("#") and parts[0] in vals:
                    try:
                        imm = _int(parts[1])
                        target = vals[parts[0]] + imm
                        s = read_cstr(target)
                        if s is not None:
                            notes[va] = f'; "{s}"'
                        elif BASE <= target < BASE + len(data):
                            notes[va] = f"; ={target:#x}"
                    except Exception:
                        pass
        return notes

    def dump(self, start=None, end=None, notes=None):
        for va in self.order:
            if start is not None and va < start: continue
            if end is not None and va >= end: continue
            insn = self.insns[va]
            b = insn.bytes.hex()
            ann = (notes or {}).get(va, "")
            print(f"{va:#014x}:  {b:<10} {insn.mnemonic:<8} {insn.op_str:<40} {ann}")


def main():
    va = int(sys.argv[1], 0)
    f = Func(va)
    f.run()
    notes = f.annotate()
    f.dump(notes=notes)
    print()
    print("calls:", ", ".join(hex(c) for c in sorted(f.calls)))

if __name__ == "__main__":
    main()
