#!/usr/bin/env python3
"""disasm with adrp+add string annotation"""
import kc, dat
from capstone.arm64 import ARM64_OP_IMM, ARM64_OP_REG, ARM64_OP_MEM

def ann(va, n=60, show_bytes=False):
    ins = kc.dis(va, n)
    pend = {}
    for a, i in ins:
        note = ""
        try:
            if i.mnemonic in ("adrp", "adr"):
                t = kc.adr_or_adrp_target(i, a)
                pend[i.operands[0].reg] = t
            elif i.mnemonic == "add" and len(i.operands) >= 3 and i.operands[2].type == ARM64_OP_IMM \
                    and i.operands[1].type == ARM64_OP_REG and i.operands[1].reg in pend:
                base = pend[i.operands[1].reg]
                t = (base + i.operands[2].imm) & 0xFFFFFFFFFFFFFFFF
                pend[i.operands[0].reg] = t
                note = lit(t)
            elif i.mnemonic == "ldr" and i.operands[1].type == ARM64_OP_MEM \
                    and i.operands[1].mem.base in pend and i.operands[1].mem.index == 0:
                slot = (pend[i.operands[1].mem.base] + i.operands[1].mem.disp) & 0xFFFFFFFFFFFFFFFF
                t = dat.ptr(slot)
                note = f"  ; [GOT {slot:#x}] = {t:#x} " + (kc.cstr(t, 40) if t and kc.inrange(t) else "")
        except Exception:
            pass
        print(f"{a:016x}: {i.mnemonic:8s} {i.op_str:44s}{note}")

def lit(t):
    if kc.inrange(t):
        try:
            s = kc.cstr(t, 90)
            if s and all(32 <= ord(c) < 127 for c in s):
                return f'  ; "{s}"'
        except Exception:
            pass
        if t >= 0xfffffff007004000:
            return f"  ; {dat.where(t)}"
    return f"  ; {t:#x}"

def func_start(pc, back=0x400):
    a = pc
    while a > pc - back:
        i = next(kc.MD.disasm(kc.BLOB[kc.va2off(a):kc.va2off(a)+4], a), None)
        if i and i.mnemonic == "bti":
            return a
        a -= 4
    return pc

def strings_in(fn, n=200):
    out = []
    for a, i in kc.dis(fn, n):
        if i.mnemonic == "adrp":
            t = kc.adr_or_adrp_target(i, a)
            for k in range(1, 4):
                if fn + 4*k > a + 12: break
                i2 = next(kc.MD.disasm(kc.BLOB[kc.va2off(a+4*k):kc.va2off(a+4*k)+4], a+4*k), None)
                if i2 and i2.mnemonic == "add" and len(i2.operands) >= 3 and i2.operands[2].type == ARM64_OP_IMM \
                        and i2.operands[1].type == ARM64_OP_REG and i2.operands[1].reg == i.operands[0].reg:
                    s = (t + i2.operands[2].imm) & 0xFFFFFFFFFFFFFFFF
                    if kc.inrange(s):
                        try:
                            txt = kc.cstr(s, 90)
                            if txt and all(32 <= ord(c) < 127 for c in txt):
                                out.append((a, s, txt))
                        except Exception:
                            pass
    return out
