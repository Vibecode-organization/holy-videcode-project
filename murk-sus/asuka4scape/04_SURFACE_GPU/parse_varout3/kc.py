"""Common loader/helpers for the 27.2 kernelcache var-output scan."""
import struct, os

KC = "/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache"
DATA = open(KC, "rb").read()

BASE = 0xfffffff007004000

SEGS = {
    "__TEXT":          (0xfffffff007004000, 0x0,       0x8000),
    "__PRELINK_TEXT":  (0xfffffff00700c000, 0x8000,    0xbac000),
    "__DATA_CONST":    (0xfffffff007bb8000, 0xbb4000,  0x548000),
    "__DATA_SPTM":     (0xfffffff008100000, 0x10fc000, 0x4c000),
    "__TEXT_EXEC":     (0xfffffff00814c000, 0x1148000, 0x2924000),
    "__TEXT_BOOT_EXEC":(0xfffffff00aa70000, 0x3a6c000, 0x8000),
    "__PRELINK_INFO":  (0xfffffff00aa78000, 0x3a74000, 0x23c000),
    "__DATA":          (0xfffffff00acb4000, 0x3cb0000, 0x2b8000),
    "__LINKEDIT":      (0xfffffff00af6c000, 0x3f68000, 0xb8000),
}

def va2off(va):
    for name, (sva, soff, ssize) in SEGS.items():
        if sva <= va < sva + ssize:
            return soff + (va - sva)
    return None

def off2va(off):
    for name, (sva, soff, ssize) in SEGS.items():
        if soff <= off < soff + ssize:
            return sva + (off - soff)
    return None

def seg_of(va):
    for name, (sva, soff, ssize) in SEGS.items():
        if sva <= va < sva + ssize:
            return name
    return None

def q(va):
    o = va2off(va)
    if o is None or o + 8 > len(DATA):
        return None
    return struct.unpack_from("<Q", DATA, o)[0]

def d(va):
    o = va2off(va)
    if o is None or o + 4 > len(DATA):
        return None
    return struct.unpack_from("<I", DATA, o)[0]

def unpac(v):
    """PAC-strip a kernel data pointer. Returns VA or None if not a plausible ptr."""
    if v is None:
        return None
    if (v >> 32) == 0x8050bcad:
        return BASE + (v & 0x0FFFFFFF)
    if 0xfffffff000000000 <= v <= 0xffffffffffffffff:
        # maybe already plain
        if seg_of(v):
            return v
    return None

def cstr(va, maxlen=256):
    o = va2off(va)
    if o is None:
        return None
    e = DATA.find(b"\x00", o, o + maxlen)
    if e < 0:
        return None
    try:
        return DATA[o:e].decode("utf-8", "replace")
    except Exception:
        return None

TEXT_EXEC_VA = 0xfffffff00814c000
TEXT_EXEC_OFF = 0x1148000
TEXT_EXEC_SIZE = 0x2924000
TEXT_EXEC_END = TEXT_EXEC_VA + TEXT_EXEC_SIZE
