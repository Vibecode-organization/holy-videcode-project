# 27.2 24B115 kernelcache helpers: fast adrp/add xref, disasm, PAC decode, vtable scan
import struct, bisect
from kc import load
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM

M64 = 0xFFFFFFFFFFFFFFFF
BASE = 0xfffffff007004000

k = load()
D = k.data

TEXTSEGS = ("__TEXT", "__PRELINK_TEXT", "__TEXT_EXEC")
SEG = {s['name']: s for s in k.segs}

md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
md.detail = True


def rd(va, n):
    o = k.off(va)
    return D[o:o+n] if o is not None else None


def u32(va):
    b = rd(va, 4)
    return struct.unpack("<I", b)[0] if b else None


def u64(va):
    b = rd(va, 8)
    return struct.unpack("<Q", b)[0] if b else None


def pac(q):
    """strip PAC: VA = BASE + (q & 0x0FFFFFFF)"""
    return BASE + (q & 0x0FFFFFFF)


def okva(va):
    if va is None:
        return None
    if k.off(va) is None:
        return None
    return va


def cstr(va, n=256):
    b = rd(va, n)
    if not b:
        return None
    z = b.find(b'\0')
    return b[:z].decode('utf-8', 'replace') if z >= 0 else None


def dis(va, n=0x200, count=0, stopret=True):
    o = k.off(va)
    if o is None:
        return []
    out = []
    for i in md.disasm(D[o:o + n], va):
        out.append(i)
        if count and len(out) >= count:
            break
        if stopret and i.mnemonic in ("ret", "retab"):
            break
    return out


def fmt(i):
    return "%#012x  %-7s %s" % (i.address, i.mnemonic, i.op_str)


def show(va, n=0x200, count=0, stopret=True):
    for i in dis(va, n, count, stopret):
        print(fmt(i))


def segname(va):
    for n in ("__TEXT", "__PRELINK_TEXT", "__DATA_CONST", "__TEXT_EXEC",
              "__DATA", "__LINKEDIT", "__PRELINK_INFO", "__TEXT_BOOT_EXEC"):
        s = SEG[n]
        if s['vmaddr'] <= va < s['vmaddr'] + s['filesize']:
            return n
    return None


# ---------- fast raw adrp/add xref ----------
def _adrp_pc_page(pc, w):
    immlo = (w >> 29) & 3
    immhi = (w >> 5) & 0x7FFFF
    imm = (immhi << 2) | immlo
    if imm & (1 << 20):
        imm -= 1 << 21
    return ((pc & ~0xFFF) + ((imm << 12) & M64)) & M64


def xrefs(target, segs=TEXTSEGS, span=6):
    """all (site_va, kind) where adrp[+add] resolves to target. kind='add'|'adrp'"""
    target &= M64
    out = []
    for sn in segs:
        s = SEG[sn]
        fo, fsz, va0 = s['fileoff'], s['filesize'], s['vmaddr']
        words = struct.unpack_from("<%dI" % (fsz // 4), D, fo)
        for i, w in enumerate(words):
            if (w & 0x9F000000) != 0x90000000:
                continue
            pc = va0 + i * 4
            page = _adrp_pc_page(pc, w)
            rd_reg = w & 0x1F
            if page == target:
                out.append((pc, 'adrp'))
            for j in range(1, span + 1):
                if i + j >= len(words):
                    break
                w2 = words[i + j]
                # ADD (immediate) 64-bit: sf=1 op=0 S=0 -> 0x91000000
                if (w2 & 0xFF800000) == 0x91000000 and ((w2 >> 5) & 0x1F) == rd_reg:
                    imm12 = (w2 >> 10) & 0xFFF
                    if (w2 >> 22) & 1:
                        imm12 <<= 12
                    if ((page + imm12) & M64) == target:
                        out.append((pc + j * 4, 'add'))
                    break
                # break the window on control flow / new adrp
                if (w2 & 0x9F000000) == 0x90000000 or (w2 & 0x7C000000) == 0x14000000:
                    break
    return out


def bl_callers(target, segs=TEXTSEGS):
    """direct bl/b to target"""
    target &= M64
    out = []
    for sn in segs:
        s = SEG[sn]
        fo, fsz, va0 = s['fileoff'], s['filesize'], s['vmaddr']
        words = struct.unpack_from("<%dI" % (fsz // 4), D, fo)
        for i, w in enumerate(words):
            if (w & 0xFC000000) != 0x94000000:
                continue
            pc = va0 + i * 4
            imm = w & 0x3FFFFFF
            if imm & (1 << 25):
                imm -= 1 << 26
            if ((pc + (imm << 2)) & M64) == target:
                out.append(pc)
    return out
