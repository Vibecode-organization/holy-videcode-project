#!/usr/bin/env python3
"""vtable annotator: dump table, resolve entries, show first string ref."""
import kc, dat, ddis
from capstone.arm64 import ARM64_OP_IMM, ARM64_OP_REG

def first_strings(fn, n=90):
    out = []
    for a, i in kc.dis(fn, n):
        if i.mnemonic != "adrp":
            continue
        t = kc.adr_or_adrp_target(i, a)
        r = i.operands[0].reg
        for k in (1, 2, 3):
            a2 = a + 4 * k
            i2 = next(kc.MD.disasm(kc.BLOB[kc.va2off(a2):kc.va2off(a2)+4], a2), None)
            if not i2 or not i2.operands: break
            if i2.mnemonic == "add" and len(i2.operands) >= 3 and i2.operands[2].type == ARM64_OP_IMM \
                    and i2.operands[1].type == ARM64_OP_REG and i2.operands[1].reg == r \
                    and i2.operands[0].reg == r:
                s = (t + i2.operands[2].imm) & 0xFFFFFFFFFFFFFFFF
                if kc.inrange(s):
                    try:
                        txt = kc.cstr(s, 80)
                        if txt and all(32 <= ord(c) < 127 for c in txt):
                            out.append(txt)
                    except Exception:
                        pass
                break
            if i2.mnemonic in ("ldr", "str"):
                break
    return out

def table(va, n=48, extra_off=(8, 12, 16, 20)):
    print(f"=== table {va:#x}")
    for i in range(n):
        s = va + i * 8
        try:
            w = kc.u64(s)
        except ValueError:
            return
        t = dat.decode_word(w)
        if not dat.iscode(t):
            print(f"[{i:2d}] +{i*8:#04x} {s:#x} -> {t:#x} (not code)")
            if t == 0:
                continue
            continue
        ss = first_strings(t, 60)
        print(f"[{i:2d}] +{i*8:#04x} {t:#x}  " + (" | ".join(ss)[:110]))
