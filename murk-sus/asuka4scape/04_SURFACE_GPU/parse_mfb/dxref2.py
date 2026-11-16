#!/usr/bin/env python3
# capstone-based adrp data xref: tracks adrp page + add/ldr offsets per register
import json, sys, bisect, collections
from kc import load
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from capstone.arm64 import ARM64_OP_IMM, ARM64_OP_REG, ARM64_OP_MEM
k = load()
kmap = json.load(open('kmap.json'))
md = Cs(CS_ARCH_ARM64, CS_MODE_ARM); md.detail = True
BTI = 0xD503245F

def kext(kid):
    return next(x for x in kmap if x['id'] == kid)

_cache = {}
def refs(kid):
    if kid in _cache: return _cache[kid]
    e = kext(kid)
    s = next(x for x in e['segs'] if x['name'] == '__TEXT_EXEC')
    ins = list(md.disasm(k.data[s['fo']:s['fo']+s['fs']], s['va']))
    starts = [i.address for i in ins if i.bytes and int.from_bytes(i.bytes, 'little') == BTI]
    out = collections.defaultdict(list)
    page = {}
    for i in ins:
        pc = i.address
        w = i.reg_name(i.operands[0].reg) if i.operands and i.operands[0].type == ARM64_OP_REG else None
        if i.mnemonic == 'adrp':
            page[w] = i.operands[1].imm
            page[w] &= 0xFFFFFFFFFFFFFFFF
            continue
        hit = None
        if i.mnemonic == 'add' and len(i.operands) == 3 and i.operands[1].type == ARM64_OP_REG:
            rn = i.reg_name(i.operands[1].reg)
            if rn in page and i.operands[2].type == ARM64_OP_IMM:
                page[w] = (page[rn] + i.operands[2].imm) & 0xFFFFFFFFFFFFFFFF
                hit = (page[w], 'add')
        elif i.mnemonic in ('ldr','ldrb','ldrh','ldrsw','ldur') and i.operands[1].type == ARM64_OP_MEM:
            m = i.operands[1].mem
            rn = i.reg_name(m.base)
            if rn in page:
                hit = ((page[rn] + m.disp) & 0xFFFFFFFFFFFFFFFF, i.mnemonic)
        if hit:
            j = bisect.bisect_right(starts, pc)-1
            out[hit[0]].append((pc, starts[j] if j >= 0 else 0, hit[1]))
        # invalidate written regs (except when we just produced the value)
        for op in i.operands:
            if op.type == ARM64_OP_REG and i.reg_name(op.reg) in page:
                # was it read as source? keep for add/ldr base
                pass
        # simple: drop any reg written by this insn unless it is the current hit target
        try:
            _, wr = i.regs_access()
        except Exception:
            wr = []
        for r in wr:
            nm = i.reg_name(r)
            if nm in page and (hit is None or nm != w):
                del page[nm]
    _cache[kid] = out
    return out

if __name__ == '__main__':
    kid = sys.argv[1]
    r = refs(kid)
    print(f"{len(r)} distinct data addrs referenced from {kid}")
    for a in sys.argv[2:]:
        t = int(a, 16)
        print(f"{t:#x}: {[(hex(p),hex(f),kk) for p,f,kk in r.get(t,[])]}")
