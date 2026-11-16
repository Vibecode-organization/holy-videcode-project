"""locate GOT slots for the OSUnserialize entrypoints + all adrp/ldr xref sites.

slot encoding: qword low32 == (target - image_base) low32 (arm64e chained fixup, auth).
xref: hand-decoded adrp + following ldr/add, no capstone sign issues.
"""
import struct, sys, pickle
import numpy as np

KC = '/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache'
BASE = 0xfffffff007004000
SEGS = [
    ('__TEXT',           0xfffffff007004000, 0x000000, 0x008000),
    ('__PRELINK_TEXT',   0xfffffff00700c000, 0x008000, 0xbac000),
    ('__DATA_CONST',     0xfffffff007bb8000, 0xbb4000, 0x548000),
    ('__DATA_SPTM',      0xfffffff008100000, 0x10fc000, 0x04c000),
    ('__TEXT_EXEC',      0xfffffff00814c000, 0x1148000, 0x2924000),
    ('__TEXT_BOOT_EXEC', 0xfffffff00aa70000, 0x3a6c000, 0x008000),
    ('__PRELINK_INFO',   0xfffffff00aa78000, 0x3a74000, 0x23c000),
    ('__DATA',           0xfffffff00acb4000, 0x3cb0000, 0x2b8000),
    ('__LINKEDIT',       0xfffffff00af6c000, 0x3f68000, 0x0b8000),
]
EXEC = ('__PRELINK_TEXT', '__TEXT_EXEC', '__TEXT_BOOT_EXEC')

TARGETS = {
    'sub_a8d5c98': 0xfffffff00a8d5c98,
    'sub_a8d846c': 0xfffffff00a8d846c,
    'sub_a8d8754': 0xfffffff00a8d8754,
    'sub_a8d96f4': 0xfffffff00a8d96f4,
    'sub_a8d5ea4': 0xfffffff00a8d5ea4,
}

d = open(KC, 'rb').read()


def va2off(va):
    for n, sva, so, sz in SEGS:
        if sva <= va < sva + sz:
            return so + va - sva
    return None


# ---------- step 1: slots
slots = {}   # slot_va -> (name, target)
for name, sva, so, sz in SEGS:
    if name not in ('__DATA_CONST', '__DATA'):
        continue
    n = sz // 8
    w = np.frombuffer(d[so:so + n * 8], dtype='<u8')
    lo = (w & np.uint64(0xFFFFFFFF)).astype(np.uint64)
    for tname, tva in TARGETS.items():
        toff = np.uint64((tva - BASE) & 0xFFFFFFFF)
        idx = np.nonzero(lo == toff)[0]
        for i in idx:
            q = int(w[i])
            # sanity: pac bits present, top not garbage
            if q >> 60 not in (0x8, 0x9, 0xa, 0xb):
                continue
            va = sva + int(i) * 8
            slots[va] = (tname, tva)

for va, (tname, tva) in sorted(slots.items()):
    print('slot %016x -> %-12s %016x  (%s)' % (va, tname, tva,
          next(n for n, s, so, sz in SEGS if s <= va < s + sz)))

# ---------- step 2: xref sites
PAGES = sorted({va & ~0xfff for va in slots})
print('slot pages:', [hex(p) for p in PAGES])

sites = []  # (insn_va, slot_va, kind, seg)


def adrp_decode(pc, w):
    if (w & 0x9F000000) != 0x90000000:
        return None
    immlo = (w >> 29) & 3
    immhi = (w >> 5) & 0x7FFFF
    imm = (immhi << 2) | immlo
    if imm & (1 << 20):
        imm -= (1 << 21)
    return ((pc & ~0xfff) + (imm << 12)) & 0xFFFFFFFFFFFFFFFF, (w & 0x1F)


def ldr_uoff_decode(w):
    # ldr Xt, [Xn, #imm12*8]  -> (rt, rn, disp)
    if (w & 0xFFC00000) == 0xF9400000:
        rt = w & 0x1F
        rn = (w >> 5) & 0x1F
        imm = (w >> 10) & 0xFFF
        return rt, rn, imm * 8
    # ldr Wt, [Xn, #imm12*4]
    if (w & 0xFFC00000) == 0xB9400000:
        rt = w & 0x1F
        rn = (w >> 5) & 0x1F
        imm = (w >> 10) & 0xFFF
        return rt, rn, imm * 4
    return None


def add_imm_decode(w):
    # add Xd, Xn, #imm12 (shift 0)
    if (w & 0xFF800000) == 0x91000000:
        rd = w & 0x1F
        rn = (w >> 5) & 0x1F
        imm = (w >> 10) & 0xFFF
        return rd, rn, imm
    return None


for name, sva, so, sz in SEGS:
    if name not in EXEC:
        continue
    n = sz // 4
    w = np.frombuffer(d[so:so + n * 4], dtype='<u4')
    cand = np.nonzero((w & np.uint32(0x9F000000)) == np.uint32(0x90000000))[0]
    for i in cand:
        pc = sva + int(i) * 4
        dec = adrp_decode(pc, int(w[i]))
        if not dec:
            continue
        page, rd = dec
        if page not in PAGES:
            continue
        for k in (1, 2, 3):
            if int(i) + k >= n:
                break
            w2 = int(w[i + k])
            pa = pc + k * 4
            l = ldr_uoff_decode(w2)
            if l and l[1] == rd:
                eff = (page + l[2]) & 0xFFFFFFFFFFFFFFFF
                if eff in slots:
                    sites.append((pa, eff, 'ldr', name, pa))
                break
            a = add_imm_decode(w2)
            if a and a[1] == rd:
                eff = (page + a[2]) & 0xFFFFFFFFFFFFFFFF
                if eff in slots:
                    sites.append((pa, eff, 'add', name, pa))
                break
            # any write to rd kills the chain
            # (crude: stop when the next insn writes rd)
            break

print('sites:', len(sites))
by = {}
for pa, slot, kind, seg, _ in sites:
    by.setdefault(slots[slot][0], []).append((pa, slot, kind, seg))
for tname in TARGETS:
    v = sorted(by.get(tname, []))
    print('== %-12s %d sites' % (tname, len(v)))
    for pa, slot, kind, seg in v:
        print('    %016x  slot %016x  %s  %s' % (pa, slot, kind, seg))

pickle.dump((slots, sites), open('/home/femboychik/work/keytype/slots.pkl', 'wb'))
