# identify class vtables: metaclass ctor sites (OSMetaClass ctor) -> gMetaClass/name/size,
# then find vtable in __DATA_CONST whose +0x48 (getMetaClass) returns that gMetaClass
import json, struct
import xm

kmap = json.load(open('kmap.json'))
T = {e['id']: e for e in kmap}


def kext(kext):
    e = T[kext]
    return {s['name']: s for s in e['segs']}


def metaclasses(name):
    sg = kext(name)
    s = sg['__TEXT_EXEC']
    fo, fsz, va0 = s['fo'], s['fs'], s['va']
    words = struct.unpack_from('<%dI' % (fsz // 4), xm.D, fo)
    out = []
    for i, w in enumerate(words):
        # bl with imm26
        if (w & 0xFC000000) != 0x94000000:
            continue
        pc = va0 + i * 4
        imm = w & 0x3FFFFFF
        if imm & (1 << 25):
            imm -= 1 << 26
        tgt = (pc + (imm << 2)) & xm.M64
        if xm.segname(tgt) != '__TEXT_EXEC':
            continue
        # look back up to 8 insn for mov w3,#size and adrp/add x0/x1
        win = [va0 + (i - k) * 4 for k in range(1, 9) if i - k >= 0]
        size = None
        for va in win:
            ww = xm.u32(va)
            if (ww & 0xFFE00000) == 0x52800000:  # movz w
                rd = ww & 0x1F
                imm16 = ((ww >> 5) & 0xFFFF) << (((ww >> 21) & 3) * 16)
                if rd == 3:
                    size = imm16
        nameva = None
        for k in range(1, 10):
            if i - k < 0:
                break
            va = va0 + (i - k) * 4
            ww = xm.u32(va)
            if (ww & 0xFF800000) == 0x91000000 and ((ww >> 5) & 0x1F) == 1:
                imm12 = (ww >> 10) & 0xFFF
                if (ww >> 22) & 1:
                    imm12 <<= 12
                # find adrp for x1
                for k2 in range(k + 1, k + 4):
                    if i - k2 < 0:
                        break
                    wp = xm.u32(va0 + (i - k2) * 4)
                    if (wp & 0x9F000000) == 0x90000000 and (wp & 0x1F) == 1:
                        page = xm._adrp_pc_page(va0 + (i - k2) * 4, wp)
                        cand = (page + imm12) & xm.M64
                        cs = xm.cstr(cand, 96)
                        if cs and cs.replace('.', '').replace('_', '').isalnum():
                            nameva = cand
                        break
                break
        # find x0 = gMetaClass (adrp/add x0) just before
        gm = None
        for k in range(1, 10):
            if i - k < 0:
                break
            va = va0 + (i - k) * 4
            ww = xm.u32(va)
            if (ww & 0xFF800000) == 0x91000000 and ((ww >> 5) & 0x1F) == 0:
                imm12 = (ww >> 10) & 0xFFF
                if (ww >> 22) & 1:
                    imm12 <<= 12
                for k2 in range(k + 1, k + 4):
                    if i - k2 < 0:
                        break
                    wp = xm.u32(va0 + (i - k2) * 4)
                    if (wp & 0x9F000000) == 0x90000000 and (wp & 0x1F) == 0:
                        gm = (xm._adrp_pc_page(va0 + (i - k2) * 4, wp) + imm12) & xm.M64
                        break
                break
        if nameva and gm:
            out.append(dict(site=pc, ctor=tgt, gmc=gm, name=xm.cstr(nameva, 96), nameva=nameva, size=size))
    return out


def getmeta_fn(gmc):
    """find functions shaped 'adrp x0,page; add x0,x0,#imm; ret' returning gmc"""
    hits = []
    for sn in ('__TEXT_EXEC',):
        s = kext(SN)['__TEXT_EXEC'] if False else None
    return hits


def find_vtables(name, gmc_map):
    sg = kext(name)
    s = sg['__DATA_CONST']
    n = s['fs'] // 8
    qs = struct.unpack_from('<%dQ' % n, xm.D, s['fo'])
    res = []
    for i in range(n - 1):
        if qs[i] == 0 and qs[i + 1] == 0:
            vt = s['va'] + i * 8
            if vt + 0x60 >= s['va'] + s['fs']:
                continue
            q = xm.u64(vt + 0x48)
            if not q:
                continue
            f = xm.pac(q)
            ins = xm.dis(f, 0x20, count=6)
            gm = None
            for k, insn in enumerate(ins):
                if insn.mnemonic == 'adrp' and insn.op_str.startswith('x0'):
                    page = insn.operands[1].imm & xm.M64
                    if k + 1 < len(ins) and ins[k + 1].mnemonic in ('add', 'sub'):
                        m = ins[k + 1]
                        imm = m.operands[2].imm
                        if m.mnemonic == 'sub':
                            imm = -imm
                        gm = page + imm
            if gm and gm in gmc_map:
                res.append((vt, gm, gmc_map[gm]))
    return res
