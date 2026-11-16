"""fast raw-instruction xref engine for arm64 kernelcache"""
import struct
from kc import KC, SEGS

def sx(v, bits):
    m = 1 << (bits - 1)
    return (v & (m - 1)) - (v & m)

def dec_adrp(w, pc):
    if (w & 0x9F000000) != 0x90000000:
        return None
    rd = w & 0x1F
    immlo = (w >> 29) & 3
    immhi = (w >> 5) & 0x7FFFF
    imm = sx(immlo | (immhi << 2), 21) << 12
    return rd, (pc & ~0xFFF) + imm

def dec_add_imm(w, sf64=True):
    # ADD (immediate): sf 0 0 1 0 0 0 1 0 sh imm12 Rn Rd
    if (w & 0x7F000000) != 0x11000000:
        return None
    if not (w & 0x80000000) and sf64:
        return None
    rd = w & 0x1F
    rn = (w >> 5) & 0x1F
    imm12 = (w >> 10) & 0xFFF
    sh = (w >> 22) & 1
    imm = imm12 << (12 if sh else 0)
    return rd, rn, imm

def dec_ldr_imm(w):
    # LDR (immediate, unsigned offset) 64/32/8/16 signed
    for mask, opc, scale, sgn in ((0xFFC00000, 0xF9400000, 8, False),
                                  (0xFFC00000, 0xB9400000, 4, False),
                                  (0xFFC00000, 0xF9800000, 8, True),   # ldrsw
                                  (0xFFC00000, 0x39400000, 1, False),
                                  (0xFFC00000, 0x79400000, 2, False)):
        if (w & mask) == opc:
            rt = w & 0x1F
            rn = (w >> 5) & 0x1F
            imm = ((w >> 10) & 0xFFF) * scale
            return rt, rn, imm
    return None

def dec_bl(w, pc):
    if (w & 0xFC000000) == 0x94000000:
        return pc + (sx(w & 0x3FFFFFF, 26) << 2)
    return None

def dec_b(w, pc):
    if (w & 0xFC000000) == 0x14000000:
        return pc + (sx(w & 0x3FFFFFF, 26) << 2)
    return None

def text_segs():
    return [s for s in SEGS if s[4]]

def words(kc, seg):
    n, sva, so, sz, ex = seg
    return struct.unpack('<%dI' % (sz // 4), kc.d[so:so + sz])

def xrefs(kc, target, segs=None, kinds=('add', 'ldr')):
    """return list of (insn_va, 'add'|'ldr') whose adrp[-1..3] resolves to target"""
    out = []
    for seg in (segs or text_segs()):
        n, sva, so, sz, ex = seg
        W = words(kc, seg)
        for i, w in enumerate(W):
            r = dec_adrp(w, sva + i * 4)
            if not r:
                continue
            rd, page = r
            if (target - page) & 0xFFFFFFFFFFFFFFFF > 0xFFFFFFF and abs(target - page) > 0xFFFFFFFF:
                continue
            for j in range(i + 1, min(i + 4, len(W))):
                pcj = sva + j * 4
                wj = W[j]
                a = dec_add_imm(wj)
                if a and a[1] == rd and page + a[2] == target and 'add' in kinds:
                    out.append((sva + i * 4, 'add'))
                    break
                l = dec_ldr_imm(wj)
                if l and l[1] == rd and page + l[2] == target and 'ldr' in kinds:
                    out.append((sva + i * 4, 'ldr'))
                    break
                if (wj & 0xFC000000) in (0x14000000, 0x94000000) or (wj & 0xFFFFFC1F) == 0xD61F0000:
                    break
    return out

def callers(kc, target, segs=None):
    out = []
    for seg in (segs or text_segs()):
        n, sva, so, sz, ex = seg
        W = words(kc, seg)
        for i, w in enumerate(W):
            t = dec_bl(w, sva + i * 4)
            if t == target:
                out.append(sva + i * 4)
    return out

def direct_branches(kc, target):
    out = []
    for seg in text_segs():
        n, sva, so, sz, ex = seg
        W = words(kc, seg)
        for i, w in enumerate(W):
            t = dec_b(w, sva + i * 4)
            if t == target:
                out.append(sva + i * 4)
    return out

def functions_starting_at(kc, va, maxlook=0):
    """find preceding stp/prologue? simply return ordered candidates of func starts by scanning backwards for 'sub sp'/'stp x29'"""
    pass
