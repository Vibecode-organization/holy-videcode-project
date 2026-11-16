#!/usr/bin/env python3
# full dump of table A selectors with annotations
import struct, json, sys
from kc import *

FB = 0xfffffff007fea200
N = 56

def func_end(va, limit=None, maxlen=0x4000):
    off = va2off(va)
    if off is None: return None
    if limit is None: limit = va + maxlen
    for ins in MD.disasm(DATA[off:off+maxlen], va):
        if ins.mnemonic in ("ret", "retab", "br", "braa", "retaa"):
            return ins.address + 4
        if ins.mnemonic == "b":
            try:
                t = ins.operands[0].imm & M64
            except Exception:
                t = None
            if t is None or not (va <= t < limit):
                return ins.address + 4
    return None

def target(ins):
    try:
        v = ins.operands[0].imm
        return v & M64
    except Exception:
        return None

def annot(ins, straddr):
    if ins.mnemonic in ("bl", "b", "blraa", "braa", "blr", "br"):
        t = target(ins)
        if t is not None:
            s = straddr.get(t)
            if s: return s
    return None

def cstr_at(va, maxn=200):
    b = rd(va, maxn)
    if not b: return None
    z = b.find(b'\0')
    if z < 2: return None
    try:
        s = b[:z].decode()
    except Exception:
        return None
    if all(32 <= ord(c) < 127 for c in s):
        return s
    return None

# PAC-resolve table A
entries = []
for i in range(N):
    q = u64(FB + i*24)
    fn = pac(q)
    entries.append((i, fn, u32(FB+i*24+8), u32(FB+i*24+12), u32(FB+i*24+16), u32(FB+i*24+20)))

# function names from __func__ xrefs
pref = b"static IOReturn IOGPUDeviceUserClient::"
funcs = {}
i = 0
while True:
    j = DATA.find(pref, i)
    if j < 0: break
    for n, sv, sz, off in SEGS:
        if off <= j < off+sz:
            va = sv + (j - off)
            s = cstr_at(va, 400)
            if s: funcs[va] = s
            break
    i = j + 1

import xr
idx = xr.build_adrp_add_index()
str_x = {}
for sva in funcs:
    xs = xr.xrefs(sva, idx)
    if xs: str_x[sva] = xs

def names_for(start, end):
    out = []
    for sva, xs in str_x.items():
        if any(start <= x < end for x in xs):
            out.append(funcs[sva])
    return out

# build string address map for annotations (only __PRELINK_TEXT / __TEXT)
straddr = {}
for n, sv, sz, off in SEGS:
    if n not in ("__PRELINK_TEXT", "__TEXT", "__TEXT_EXEC", "__DATA_CONST", "__DATA"):
        continue
    # too heavy to map every byte; only use known funcs
for sva in funcs:
    straddr[sva] = funcs[sva]

fns_sorted = sorted(f for _, f, *_ in entries)
out = []
for sel, fn, scin, stin, scout, stout in entries:
    nxt = [x for x in fns_sorted if x > fn]
    limit = nxt[0] if nxt else fn + 0x400
    end = func_end(fn, limit)
    out.append({"sel": sel, "fn": fn, "end": end, "len": (end-fn) if end else None,
                "scin": scin & 0xffffffff, "stin": stin & 0xffffffff,
                "scout": scout & 0xffffffff, "stout": stout & 0xffffffff,
                "names": names_for(fn, end) if end else []})
json.dump([{k: (hex(v) if isinstance(v, int) and k in ("fn","end") else v) for k, v in o.items()} for o in out],
          open("selmap.json", "w"), indent=1, ensure_ascii=False)

with open("disasm_all.txt", "w") as f:
    for o in out:
        sel, fn, end = o["sel"], o["fn"], o["end"]
        f.write("\n" + "="*100 + "\n")
        f.write(f"SEL {sel:2d}  fn={fn:#x} len={o['len']:#x}  scIn={o['scin']} stIn={o['stin']:#x} scOut={o['scout']} stOut={o['stout']:#x}\n")
        for nm in o["names"]:
            f.write("   name: " + nm + "\n")
        if not end:
            f.write("   !! no ret found\n"); continue
        off = va2off(fn)
        for ins in MD.disasm(DATA[off:off+(end-fn)], fn):
            a = annot(ins, straddr)
            line = "%#012x  %-8s %s" % (ins.address, ins.mnemonic, ins.op_str)
            if a: line += "   ; " + a
            f.write(line + "\n")

print("wrote disasm_all.txt, selmap.json")
for o in out:
    print("sel %2d %#x len %#6x names=%s" % (o["sel"], o["fn"], o["len"] or 0, len(o["names"])))
