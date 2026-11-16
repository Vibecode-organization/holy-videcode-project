import struct, sys

KC = "/home/femboychik/work/kc272/24B119__iPhone14,7/kernelcache.release.iPhone14,7"
DATA = open(KC,'rb').read()

SEGS = [
 ("__TEXT",              0xfffffff007004000, 0x8000,      0x0),
 ("__PRELINK_TEXT",      0xfffffff00700c000, 0xba0000,    0x8000),
 ("__DATA_CONST",        0xfffffff007bac000, 0x548000,    0xba8000),
 ("__DATA_SPTM",         0xfffffff0080f4000, 0x4c000,     0x10f0000),
 ("__TEXT_EXEC",         0xfffffff008140000, 0x28f0000,   0x113c000),
 ("__TEXT_BOOT_EXEC",    0xfffffff00aa30000, 0x8000,      0x3a2c000),
 ("__PRELINK_INFO",      0xfffffff00aa38000, 0x23c000,    0x3a34000),
 ("__DATA",              0xfffffff00ac74000, 0x2b8000,    0x3c70000),
 ("__LINKEDIT",          0xfffffff00af2c000, 0xb8000,     0x3f28000),
]

def va2off(va):
    for n,b,s,o in SEGS:
        if b <= va < b+s:
            return o + (va-b)
    return None

def off2va(off):
    for n,b,s,o in SEGS:
        if o <= off < o+s:
            return b + (off-o)
    return None

def rd(va, n):
    o = va2off(va)
    if o is None: raise ValueError(hex(va))
    return DATA[o:o+n]

def u32(va): return struct.unpack('<I', rd(va,4))[0]
def u64(va): return struct.unpack('<Q', rd(va,8))[0]
def s32(va): return struct.unpack('<i', rd(va,4))[0]

def cstr(va, maxlen=256):
    o = va2off(va)
    if o is None: return None
    e = DATA.index(b'\0', o)
    return DATA[o:min(e,o+maxlen)].decode('utf-8','replace')

def is_text(va):
    return 0xfffffff008140000 <= va < 0xfffffff00aa30000 or 0xfffffff00700c000 <= va < 0xfffffff007bac000 or 0xfffffff007004000<=va<0xfffffff00700c000

BASE_K = 0xfffffff007004000
def ptr(va):
    v = u64(va)
    if (v >> 32) == 0xfffffff0 or (v >> 40) == 0xffffff:
        return v
    # chained fixup: low 32 = runtimeOffset
    return (BASE_K + (v & 0xffffffff)) & 0xffffffffffffffff
