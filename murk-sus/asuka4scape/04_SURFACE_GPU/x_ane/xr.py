#!/usr/bin/env python3
"""vectorized adrp xref scanner for kernelcache"""
import numpy as np, kc

EXEC = [s for s in kc.SEGS if s[0] in ("__TEXT_EXEC", "__PRELINK_TEXT", "__TEXT")]
_words = {}
for name, vm, vs, fo, fs in EXEC:
    n = fs // 4
    _words[name] = np.frombuffer(kc.BLOB, dtype="<u4", count=n, offset=fo)

def _decode(w, pc):
    """vectorized ADRP target page: capstone immlo/immhi are SIGNED 21-bit page delta"""
    w = np.asarray(w, dtype=np.uint64)
    immlo = (w >> np.uint64(29)) & np.uint64(3)
    immhi = (w >> np.uint64(5)) & np.uint64(0x7FFFF)
    imm = (immhi << np.uint64(2)) | immlo
    neg = (imm & np.uint64(1 << 20)) != 0
    imm = np.where(neg, imm - np.uint64(1 << 21), imm)          # sign-extend, wrap-safe
    pages = ((np.asarray(pc, dtype=np.uint64) & np.uint64(0xFFFFFFFFFFFFF000))
             + (imm.astype(np.uint64) << np.uint64(12)))
    return pages

def find_adrp(target, extra_check=True, gap=6):
    """return list of (pc, addoff_pc, resolved) for adrp/add|ldr sequences"""
    tpage = target & ~0xFFF
    out = []
    for name, vm, vs, fo, fs in EXEC:
        w = _words[name]
        cand = np.nonzero((w & 0x9F000000) == 0x90000000)[0]
        if len(cand) == 0: continue
        pcs = vm + cand.astype(np.uint64) * 4
        pages = _decode(w[cand].astype(np.uint64), pcs)
        sel = cand[pages == np.uint64(tpage)]
        for idx in sel:
            pc = vm + int(idx) * 4
            ins = next(kc.MD.disasm(kc.BLOB[kc.va2off(pc):kc.va2off(pc)+4], pc), None)
            if ins is None or ins.mnemonic != "adrp": continue
            dst = ins.operands[0].reg
            for k in range(1, gap + 1):
                a2 = pc + 4 * k
                if not kc.inrange(a2): break
                i2 = next(kc.MD.disasm(kc.BLOB[kc.va2off(a2):kc.va2off(a2)+4], a2), None)
                if i2 is None or not i2.operands: break
                o0 = i2.operands[0]
                if o0.type != 1 or o0.reg != dst: continue
                if i2.mnemonic in ("add",) and len(i2.operands) >= 3 and i2.operands[2].type == 2:
                    addr = (tpage + (i2.operands[2].imm & 0xFFFFFFFFFFFFFFFF)) & 0xFFFFFFFFFFFFFFFF
                elif len(i2.operands) > 1 and i2.operands[1].type == 3 and \
                        i2.operands[1].mem.base == dst and i2.operands[1].mem.index == 0:  # MEM
                    addr = (tpage + i2.operands[1].mem.disp) & 0xFFFFFFFFFFFFFFFF
                else:
                    break
                if addr == target:
                    out.append((pc, a2, i2.mnemonic))
                    break
    return out

def find_ptr(target, segnames=("__DATA_CONST", "__DATA", "__PRELINK_DATA", "__DATA_CONST_AUTH")):
    """scan data segments for raw 64-bit pointer to target (chained-fixup rebase decoded too)"""
    pat = np.uint64(target)
    out = []
    for name, vm, vs, fo, fs in kc.SEGS:
        if name not in segnames: continue
        arr = np.frombuffer(kc.BLOB, dtype="<u8", count=fs // 8, offset=fo)
        idx = np.nonzero(arr == pat)[0]
        for i in idx:
            out.append((name, vm + int(i) * 8, "raw"))
        # chained fixup rebase: high bits set, low 24 = offset into image? decode via
        # dyld chained ptr: 0x0000000X_XXXXXXXX form with strand
        idx2 = np.nonzero((arr & np.uint64(0xFFFFFFFF)) == pat)[0] if target < 0x100000000 else []
        for i in idx2:
            out.append((name, vm + int(i) * 8, "fixup"))
    return out

if __name__ == "__main__":
    import sys
    for t in sys.argv[1:]:
        tv = int(t, 16)
        print(f"== {tv:#x} {kc.cstr(tv)[:60] if kc.inrange(tv) else ''}")
        for pc, a2, m in find_adrp(tv):
            print(f"   adrp@{pc:#x} {m}@{a2:#x}")
        for seg, va, kind in find_ptr(tv):
            print(f"   ptr[{kind}] {seg} {va:#x}")
