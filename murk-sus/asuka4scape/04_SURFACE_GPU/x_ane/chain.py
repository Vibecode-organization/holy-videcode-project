#!/usr/bin/env python3
"""decode dyld chained fixups (DYLD_CHAINED_PTR_64_KERNEL_CACHE, fmt 8) ->
map pointer-slot VA -> target VA.  base = 0xfffffff007004000."""
import struct, numpy as np, kc

BASE = 0xfffffff007004000
FXOFF = 0x401c000
b = kc.BLOB[FXOFF:FXOFF + 0x4b6]
fv, so, io, symo, ic, fmt, symfmt = struct.unpack_from("<IIIIIII", b, 0)
SEGCOUNT = struct.unpack_from("<I", b, so)[0]

# slot VA -> encoded word
SLOT = {}          # slot_va -> target_va_or_None
AUTH = {}          # slot_va -> (target, key, div, addrdv)

def _walk(seg_index, start_off, page_start_va, page_size):
    off = start_off * 4
    slot = page_start_va + off
    while True:
        w = struct.unpack_from("<Q", kc.BLOB, kc.va2off(slot))[0]
        isauth = (w >> 63) & 1
        tgt = w & 0x3FFFFFFF
        nxt = (w >> 51) & 0xFFF
        if isauth:
            key = (w >> 49) & 3
            div = (w >> 32) & 0xFFFF
            addrdv = (w >> 48) & 1
            SLOT[slot] = BASE + tgt
            AUTH[slot] = (BASE + tgt, key, div, addrdv)
        else:
            SLOT[slot] = BASE + tgt
        if nxt == 0:
            break
        slot += nxt * 4

def build():
    for i in range(SEGCOUNT):
        sio = struct.unpack_from("<I", b, so + 4 + 4 * i)[0]
        if sio == 0:
            continue
        p = so + sio
        size, pgsz, pfmt, segoff, maxvalid, pagecount = struct.unpack_from("<IHHQIH", b, p)
        # segment file offset != segoff here; map via segment list order
        name, vm, vs, fo, fs = kc.SEGS[i + 1] if False else kc.SEGS[[s[0] for s in kc.SEGS].index(
            ["__TEXT", "__PRELINK_TEXT", "__DATA_CONST", "__DATA_SPTM", "__TEXT_EXEC",
             "__TEXT_BOOT_EXEC", "__PRELINK_INFO", "__DATA", "__LINKEDIT"][i])]
        for pi in range(pagecount):
            ps = struct.unpack_from("<H", b, p + 22 + 2 * pi)[0]
            page_va = vm + pi * pgsz
            if ps == 0xFFFF:
                continue
            if ps == 0xFFFE:
                # multi-start page
                for k in range(64):
                    ent = struct.unpack_from("<H", b, p + 22 + 2 * pagecount + 2 * k
                                             + 2 * 64 * 0)[0]
                    _walk(i, 0, page_va, pgsz)
                continue
            _walk(i, ps, page_va, pgsz)

build()

if __name__ == "__main__":
    print("slots decoded:", len(SLOT), "auth:", len(AUTH))
    for s, t in list(SLOT.items())[:10]:
        print(f"  {s:#x} -> {t:#x}")
