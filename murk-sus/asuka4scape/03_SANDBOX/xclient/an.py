#!/usr/bin/env python3
# analysis helpers for 27.2 kernelcache -- IOGPU cross-client id work
# reuses disasm helper from ../iogpu_all/kc.py (sign extension masked)
import sys, os, struct, pickle
sys.path.insert(0, "/home/femboychik/work/iogpu_all")
from kc import *          # DATA, SEGS, va2off, u32, u64, pac, MD, show, cstr, find_cstr
from kc import M64

CACHE = os.path.join(os.path.dirname(os.path.abspath(__file__)), "callidx.pkl")


def build_call_index():
    """target_va -> [(site_va, kind)] for B/BL inside __TEXT_EXEC"""
    idx = {}
    for n, sv, sz, off in SEGS:
        if n not in ("__TEXT_EXEC", "__TEXT", "__PRELINK_TEXT"):
            continue
        end = off + sz - 4
        p = off
        while p < end:
            w = struct.unpack_from("<I", DATA, p)[0]
            op = w & 0xFC000000
            if op == 0x94000000 or op == 0x14000000:
                imm = w & 0x03FFFFFF
                if imm & 0x02000000:
                    imm -= 0x04000000
                site = sv + (p - off)
                tgt = (site + (imm << 2)) & M64
                idx.setdefault(tgt, []).append((site, "bl" if op == 0x94000000 else "b"))
            p += 4
    return idx


def call_index():
    if os.path.exists(CACHE):
        try:
            return pickle.load(open(CACHE, "rb"))
        except Exception:
            pass
    idx = build_call_index()
    pickle.dump(idx, open(CACHE, "wb"))
    return idx


IDX = None


def callers(va):
    global IDX
    if IDX is None:
        IDX = call_index()
    return IDX.get(va & M64, [])


def fn_start(va, back=0x1000):
    """walk back to a plausible function start (bti c / pacibsp)"""
    off = va2off(va)
    p = va
    while p > va - back:
        w = u32(p)
        if w == 0xD503245F:      # bti c
            return p
        if w == 0xD503237F:      # pacibsp
            # start is usually bti c before, else here
            return p
        p -= 4
    return va


def fn_end(va, maxlen=0x2000):
    off = va2off(va)
    if off is None:
        return None
    for ins in MD.disasm(DATA[off:off + maxlen], va):
        if ins.mnemonic in ("ret", "retab", "retaa"):
            return ins.address + 4
        if ins.mnemonic == "b":
            try:
                t = ins.operands[0].imm & M64
            except Exception:
                t = None
            if t is None or not (va <= t < va + maxlen):
                return ins.address + 4
    return None


def callers_of_pac(va):
    """callers grouped: for each call site, the enclosing fn start"""
    out = []
    for site, kind in callers(va):
        out.append((site, kind, fn_start(site)))
    return out
