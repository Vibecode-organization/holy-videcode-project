#!/usr/bin/env python3
"""resolve GOT trampolines / b-thunks to real target, dump code."""
import kc, dat
from capstone.arm64 import ARM64_OP_IMM, ARM64_OP_REG

def _i(va):
    return next(kc.MD.disasm(kc.BLOB[kc.va2off(va):kc.va2off(va)+4], va), None)

def got_slot_at(va):
    """if the 4-insn pattern adrp x17/ add x17 / ldr x16,[x17] / braa starts at va -> slot"""
    i0 = _i(va)
    if not i0 or i0.mnemonic != "adrp": return None
    reg = i0.operands[0].reg
    page = (va & ~0xFFF) + (i0.operands[1].imm & 0xFFFFFFFFFFFFFFFF)
    i1 = _i(va+4); i2 = _i(va+8); i3 = _i(va+12)
    if not (i1 and i1.mnemonic == "add" and i1.operands[2].type == ARM64_OP_IMM): return None
    slot = page + i1.operands[2].imm
    if not (i2 and i2.mnemonic == "ldr" and i2.operands[1].type == 3): return None
    return slot

def resolve(va, depth=6, trace=False):
    seen = []
    for _ in range(depth):
        if not kc.inrange(va): return va, seen
        i = _i(va)
        if i is None: return va, seen
        if i.mnemonic == "bti":
            va += 4; continue
        s = got_slot_at(va)
        if s is not None:
            t = dat.ptr(s)
            seen.append(("got", hex(s), hex(t)))
            if not t: return va, seen
            va = t; continue
        if i.mnemonic == "b" and i.operands and i.operands[0].type == ARM64_OP_IMM:
            t = (va + (i.operands[0].imm & 0xFFFFFFFFFFFFFFFF)) & 0xFFFFFFFFFFFFFFFF
            seen.append(("b", hex(t)))
            va = t; continue
        return va, seen
    return va, seen

def call_target(va):
    """resolve bl target at va through GOT"""
    i = _i(va)
    if not i: return None
    t = (va + (i.operands[0].imm & 0xFFFFFFFFFFFFFFFF)) & 0xFFFFFFFFFFFFFFFF
    real, _ = resolve(t)
    return real
