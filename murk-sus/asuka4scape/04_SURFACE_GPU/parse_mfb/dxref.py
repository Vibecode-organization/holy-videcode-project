#!/usr/bin/env python3
# adrp-page aware data xref: catches `ldr Rt,[xN,#imm]` (no add), which plain adrp/add misses
import json, struct, sys, collections
from kc import load
k = load()
kmap = json.load(open('kmap.json'))
BTI = 0xD503245F

def refs(kid):
    e = next(x for x in kmap if x['id'] == kid)
    s = next(x for x in e['segs'] if x['name'] == '__TEXT_EXEC')
    n = s['fs']//4
    w = struct.unpack_from('<%dI' % n, k.data, s['fo'])
    base = s['va']
    starts = [base+i*4 for i, x in enumerate(w) if x == BTI]
    import bisect
    out = collections.defaultdict(list)   # data addr -> [(pc,fn,kind)]
    page = {}
    for i, x in enumerate(w):
        pc = base + i*4
        if (x & 0x9F00001F) == 0x90000000:  # adrp
            rd = x & 0x1F
            immlo = (x >> 29) & 3
            immhi = (x >> 5) & 0x7FFFF
            imm = (immhi << 2) | immlo
            if imm & 0x100000: imm -= 0x200000
            page[rd] = (pc & ~0xFFF) + (imm << 12)
            page[rd] &= 0xFFFFFFFFFFFFFFFF
            continue
        if not page:
            continue
        rd = x & 0x1F
        rn = (x >> 5) & 0x1F
        # add Rd, Rn, #imm (Rn holds page)
        if (x & 0xFF800000) == 0x91000000 and rn in page:
            imm12 = (x >> 10) & 0xFFF
            sh = (x >> 22) & 1
            t = (page[rn] + ((imm12 << 12) if sh else imm12))
            page[rd] = t
            j = bisect.bisect_right(starts, pc)-1
            out[t & 0xFFFFFFFFFFFFFFFF].append((pc, starts[j] if j>=0 else 0, 'add'))
            continue
        if (x & 0xFFC00000) == 0xF9400000 and rn in page:
            imm12 = (x >> 10) & 0xFFF
            t = page[rn] + imm12*8
            j = bisect.bisect_right(starts, pc)-1
            out[t & 0xFFFFFFFFFFFFFFFF].append((pc, starts[j] if j>=0 else 0, 'ldr'))
            if rd in page: del page[rd]
            continue
        if (x & 0xFFC00000) == 0xB9400000 and rn in page:
            imm12 = (x >> 10) & 0xFFF
            t = page[rn] + imm12*4
            j = bisect.bisect_right(starts, pc)-1
            out[t & 0xFFFFFFFFFFFFFFFF].append((pc, starts[j] if j>=0 else 0, 'ldrw'))
            continue
        # any other write to reg invalidates page
        if rd in page and (x & 0x1F000000) not in (0x09000000, 0x0B000000):
            # conservative: drop on non-add ALU ops writing rd
            if (x >> 26) & 0x1F not in (0b10001,):  # keep add/sub
                del page[rd]
    return out

if __name__ == '__main__':
    kid = sys.argv[1]
    r = refs(kid)
    print(f"{len(r)} distinct data addrs referenced")
    if len(sys.argv) > 2:
        for a in sys.argv[2:]:
            t = int(a, 16)
            print(f"{t:#x}: {[(hex(p),hex(f),kk) for p,f,kk in r.get(t,[])]}")
