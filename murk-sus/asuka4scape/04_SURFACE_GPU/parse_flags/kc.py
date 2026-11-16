import struct, capstone

KC = "/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache"
BASE = 0xfffffff007004000
PAC_TAG = 0x8050bcad

SEGS = {
    "__TEXT":            (0xfffffff007004000, 0x8000,     0x0,       0x8000),
    "__PRELINK_TEXT":    (0xfffffff00700c000, 0xbac000,   0x8000,    0xbac000),
    "__DATA_CONST":      (0xfffffff007bb8000, 0x548000,   0xbb4000,  0x548000),
    "__DATA_SPTM":       (0xfffffff008100000, 0x4c000,    0x10fc000, 0x4c000),
    "__TEXT_EXEC":       (0xfffffff00814c000, 0x2924000,  0x1148000, 0x2924000),
    "__TEXT_BOOT_EXEC":  (0xfffffff00aa70000, 0x8000,     0x3a6c000, 0x8000),
    "__PRELINK_INFO":    (0xfffffff00aa78000, 0x23c000,   0x3a74000, 0x23c000),
    "__DATA":            (0xfffffff00acb4000, 0x2b8000,   0x3cb0000, 0x2b8000),
    "__LINKEDIT":        (0xfffffff00af6c000, 0xb8000,    0x3f68000, 0xb8000),
}

class Cache:
    def __init__(self):
        with open(KC, "rb") as f:
            self.buf = f.read()
        self.md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
        self.md.detail = True

    def va2off(self, va):
        for n, (v, vs, fo, fs) in SEGS.items():
            if v <= va < v + fs:
                return fo + (va - v)
        return None

    def off2va(self, off):
        for n, (v, vs, fo, fs) in SEGS.items():
            if fo <= off < fo + fs:
                return v + (off - fo)
        return None

    def seg(self, name):
        v, vs, fo, fs = SEGS[name]
        return self.buf[fo:fo+fs]

    def seg_va(self, name):
        return SEGS[name][0]

    def read(self, va, n):
        o = self.va2off(va)
        if o is None: return None
        return self.buf[o:o+n]

    def u32(self, va):
        b = self.read(va, 4)
        return None if b is None or len(b) < 4 else struct.unpack("<I", b)[0]

    def u64(self, va):
        b = self.read(va, 8)
        return None if b is None or len(b) < 8 else struct.unpack("<Q", b)[0]

    def dis(self, va, n=1):
        b = self.read(va, n*4)
        if not b: return []
        return list(self.md.disasm(b, va))

def pac_decode(q):
    if (q >> 32) != PAC_TAG:
        return None
    return BASE + (q & 0x0FFFFFFF)

def find_pac_refs(c, target_va):
    """return list of (slot_va, seg) where qword pac-decodes to target_va"""
    off = target_va - BASE
    out = []
    for name in ("__DATA_CONST", "__DATA", "__DATA_SPTM", "__PRELINK_INFO"):
        v, vs, fo, fs = SEGS[name]
        data = c.buf[fo:fo+fs]
        for i in range(0, len(data) - 8, 8):
            q = struct.unpack_from("<Q", data, i)[0]
            if (q >> 32) == PAC_TAG and (q & 0x0FFFFFFF) == off:
                out.append((v + i, name, q))
    return out

def find_plain_refs(c, target_va):
    out = []
    for name in ("__DATA_CONST", "__DATA"):
        v, vs, fo, fs = SEGS[name]
        data = c.buf[fo:fo+fs]
        tgt = struct.pack("<Q", target_va)
        start = 0
        while True:
            j = data.find(tgt, start)
            if j < 0: break
            out.append((v + j, name))
            start = j + 1
    return out

def adrp_addrs(c):
    """map page_va -> list of adrp insn va in __TEXT_EXEC (and __TEXT)"""
    res = {}
    for segname in ("__TEXT_EXEC", "__TEXT", "__TEXT_BOOT_EXEC", "__PRELINK_TEXT"):
        v, vs, fo, fs = SEGS[segname]
        data = c.buf[fo:fo+fs]
        for i in range(0, len(data) - 4, 4):
            iw = struct.unpack_from("<I", data, i)[0]
            if (iw & 0x9F000000) == 0x90000000:  # ADRP
                immlo = (iw >> 29) & 3
                immhi = (iw >> 5) & 0x7FFFF
                imm = (immhi << 2) | immlo
                if imm & (1 << 20): imm -= (1 << 21)
                pc = v + i
                page = (pc & ~0xfff) + (imm << 12)
                res.setdefault(page, []).append(pc)
    return res
