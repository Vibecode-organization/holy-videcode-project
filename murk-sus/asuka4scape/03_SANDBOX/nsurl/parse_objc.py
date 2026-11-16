#!/usr/bin/env python3
# dump relative-method-list ObjC metadata (arm64e, chained fixups) with IMP addresses
import struct, sys, lief

BIN = sys.argv[1] if len(sys.argv) > 1 else "bin/nsurlsessiond"
b = lief.MachO.parse(BIN).at(0)
BASE = 0x100000000

def content(va, n):
    try:
        return bytes(b.get_content_from_virtual_address(va, n))
    except Exception:
        return b""

def u64(va):
    d = content(va, 8)
    return struct.unpack("<Q", d)[0] if len(d) == 8 else 0

def ptr(va):
    v = u64(va)
    if v == 0: return 0
    t = BASE + (v & 0xFFFFFFFF)
    return t if BASE <= t < BASE + 0x2000000 else 0

def cstr(va, maxlen=512):
    if not va: return None
    out = bytearray()
    for i in range(maxlen):
        d = content(va + i, 1)
        if not d or d[0] == 0: break
        out.append(d[0])
    return out.decode("utf-8", "replace")

def parse_method_list(va, prefix="-"):
    hdr = content(va, 8)
    if len(hdr) < 8: return []
    entsize_flags, count = struct.unpack("<II", hdr)
    rel = bool(entsize_flags & 0x80000000)
    entsize = entsize_flags & 0x0000FFFC
    if entsize == 0: entsize = 12 if rel else 24
    out = []
    for i in range(count):
        e = va + 8 + i * entsize
        d = content(e, entsize)
        if len(d) < entsize: break
        if rel:
            no, to, io = struct.unpack("<iii", d[:12])
            slot = e + (no & ~1)
            if no & 1:
                sel = cstr(slot)
            else:
                sel = cstr(ptr(slot))
            imp = e + 8 + io
        else:
            no, to, io = struct.unpack("<QQQ", d[:24])
            sel = cstr(no)
            imp = io
        out.append((prefix, sel, imp))
    return out

cl_sec = next(sec for sec in b.sections if sec.name == "__objc_classlist")
cl_va = cl_sec.virtual_address
nclasses = cl_sec.size // 8
target = sys.argv[2].lower() if len(sys.argv) > 2 else None
for i in range(nclasses):
    p = ptr(cl_va + i * 8)
    if not p: continue
    ro = ptr(p + 0x20) & ~0x7
    if not ro: continue
    cname = cstr(ptr(ro + 0x18))
    if target and target not in (cname or "").lower(): continue
    meta = ptr(p)
    mro = ptr(meta + 0x20) & ~0x7 if meta else 0
    inst = parse_method_list(ptr(ro + 0x20), "-") if ptr(ro + 0x20) else []
    cls = parse_method_list(ptr(mro + 0x20), "+") if mro and ptr(mro + 0x20) else []
    print("@interface %s" % cname)
    for prefix, sel, imp in cls + inst:
        print("  %#x  %s%s" % (imp, prefix, sel))
    print()
