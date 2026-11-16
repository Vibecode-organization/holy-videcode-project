#!/usr/bin/env python3
"""pointer decode: chained-fixup aware + heuristics for KD cache."""
import kc, chain

BASE = 0xfffffff007004000

def decode_word(w):
    if w == 0:
        return 0
    if (w >> 63) & 1:                       # auth rebase
        return BASE + (w & 0x3FFFFFFF)
    if w < 0x40000000:                      # plain rebase offset
        return BASE + w
    return w                                # already a VA

def ptr(slot):
    if slot in chain.SLOT:
        return chain.SLOT[slot]
    try:
        return decode_word(kc.u64(slot))
    except ValueError:
        return None

def where(va):
    for n, vm, vs, fo, fs in kc.SEGS:
        if vm <= va < vm + fs:
            return n
    return "?"

def iscode(va):
    return where(va) in ("__TEXT_EXEC", "__PRELINK_TEXT", "__TEXT_BOOT_EXEC", "__TEXT")

def dump_vtable(va, n=64):
    print(f"--- table @ {va:#x}")
    for i in range(n):
        s = va + i * 8
        try:
            w = kc.u64(s)
        except ValueError:
            break
        t = decode_word(w)
        mark = "CODE" if iscode(t) else ""
        print(f"  +{i*8:#04x} {s:#x} raw={w:#018x} -> {t:#018x} {mark}")
        if i > 8 and t == 0 and not iscode(t):
            pass

def rev(target):
    return [s for s, t in chain.SLOT.items() if t == target]
