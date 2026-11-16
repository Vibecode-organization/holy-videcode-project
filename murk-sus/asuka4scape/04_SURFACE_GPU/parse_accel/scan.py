# fast adrp/add + GOT indexer
import struct, kc

D = kc.D
def sxt(v, bits):
    if v & (1 << (bits-1)): return v - (1 << bits)
    return v

def scan_seg(off, size, base):
    """yield (insn_va, kind, data)"""
    adrp = {}   # reg -> (page_va, va_of_insn)
    res = []    # (site_va, target_va, kind, reg)
    n = size // 4
    for i in range(n):
        insn = struct.unpack_from("<I", D, off + i*4)[0]
        site = base + i*4
        if (insn & 0x9F000000) == 0x90000000:
            rd = insn & 0x1F
            immhi = (insn >> 5) & 0x7FFFF
            immlo = (insn >> 29) & 3
            imm = sxt((immhi << 2) | immlo, 21) << 12
            adrp[rd] = (site + imm, site)
        elif (insn & 0x7F800000) == 0x91000000:
            rd = insn & 0x1F; rn = (insn >> 5) & 0x1F
            imm = (insn >> 10) & 0xFFF
            if (insn >> 22) & 1: imm <<= 12
            if rn in adrp and (rd == rn or rd == rn):
                page, _ = adrp[rn]
                res.append((site, page + imm, "add", rd))
                adrp[rd] = (page + imm, site)
        elif (insn & 0xFFC00000) == 0xF9400000:
            rt = insn & 0x1F; rn = (insn >> 5) & 0x1F
            imm = ((insn >> 10) & 0xFFF) * 8
            if rn in adrp:
                res.append((site, adrp[rn][0] + imm, "ldr", rt))
    return res

if __name__ == "__main__":
    import pickle
    allres = []
    for name, base, size, off in kc.SEGS:
        if name in ("__TEXT_EXEC", "__PRELINK_TEXT", "__TEXT"):
            r = scan_seg(off, size, base)
            print(name, len(r))
            allres += r
    pickle.dump(allres, open("/home/femboychik/work/parse_accel/adrp.pkl", "wb"))
    print("total", len(allres))
