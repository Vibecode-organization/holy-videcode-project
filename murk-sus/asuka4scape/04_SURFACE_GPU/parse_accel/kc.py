# kernelcache helpers for 27.2_24B115
import struct, subprocess
PATH = "/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache"
D = open(PATH, "rb").read()
BASE = 0xfffffff007004000

SEGS = [
    ("__TEXT",        0xfffffff007004000, 0x8000,    0x0),
    ("__PRELINK_TEXT",0xfffffff00700c000, 0xbac000,  0x8000),
    ("__DATA_CONST",  0xfffffff007bb8000, 0x548000,  0xbb4000),
    ("__DATA",        0xfffffff00acb4000, 0x2b8000,  0x3cb0000),
    ("__TEXT_EXEC",   0xfffffff00814c000, 0x2924000, 0x1148000),
    ("__PRELINK_INFO",0xfffffff00aa78000, 0x23c000,  0x3a74000),
]

def va2off(va):
    for name, base, size, off in SEGS:
        if base <= va < base + size:
            return off + (va - base)
    return None

def off2va(off):
    for name, base, size, o in SEGS:
        if o <= off < o + size:
            return base + (off - o)
    return None

def rq(va):
    o = va2off(va)
    if o is None: return None
    return struct.unpack_from("<Q", D, o)[0]

def rd(va):
    o = va2off(va)
    if o is None: return None
    return struct.unpack_from("<I", D, o)[0]

def rb(va):
    o = va2off(va)
    if o is None: return None
    return D[o]

def cstr(va, maxlen=256):
    o = va2off(va)
    if o is None: return None
    e = D.find(b"\0", o, o + maxlen)
    if e < 0: return None
    try:
        return D[o:e].decode("utf-8", "replace")
    except Exception:
        return None

def unpac(q):
    return 0xfffffff007004000 + (q & 0x0FFFFFFF)

def find_all(needle, start=0):
    out = []
    i = start
    while True:
        i = D.find(needle, i)
        if i < 0: break
        out.append(i)
        i += 1
    return out

def find_str(s):
    return find_all(s.encode() if isinstance(s, str) else s)

def xrefs_va(target):
    """find all qword occurrences of target (assumes no PAC on data ptrs)"""
    return [o for o in find_all(struct.pack("<Q", target))]

def xrefs_adrp_add(va):
    """find adrp/add pairs landing on va - brute force via capstone over TEXT_EXEC is slow; use regex-ish scan"""
    return None
