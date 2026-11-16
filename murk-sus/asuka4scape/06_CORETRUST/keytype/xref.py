"""single-pass xref scan for a set of __DATA_CONST slot addresses.
records (insn_va, kind, slot) for adrp+ldr / adrp+add resolving into the slot set."""
import sys, struct, numpy as np
sys.path.insert(0, '/home/femboychik/work/parse_unser')
import kc
from capstone import *
from capstone.arm64 import *

k = kc.KC()

SLOTS = {}
for slug, addrs in {
 'sized3': [0xfffffff007d7c130,0xfffffff007db41d8,0xfffffff007dfd1e0,0xfffffff007e0e6b0,0xfffffff007e26350,
            0xfffffff007e741d8,0xfffffff007f0a140,0xfffffff007f1f018,0xfffffff007f57550,0xfffffff007f99338,
            0xfffffff007ff8c28,0xfffffff007ffd8d0,0xfffffff008016ec0,0xfffffff008021bd8,0xfffffff00806c618,
            0xfffffff0080b65d8,0xfffffff0080c5eb8,0xfffffff0080d7e00,0xfffffff0080dcf70],
 '2argB': [0xfffffff007dbc198,0xfffffff007dfd1d8,0xfffffff008004c58],
}.items():
    for a in addrs: SLOTS[a] = slug

PAGES = set(a & ~0xfff for a in SLOTS)
res = []
for name, sva, so, sz, ex in kc.SEGS:
    if not ex: continue
    md = Cs(CS_ARCH_ARM64, CS_MODE_ARM); md.detail = True; md.skipdata = True
    blob = k.d[so:so+sz]
    pend = {}   # reg -> (page, insn addr)
    for ins in md.disasm(blob, sva):
        m = ins.mnemonic
        if m == 'adrp':
            p = ins.operands[1].imm & 0xFFFFFFFFFFFFFFFF
            if p in PAGES:
                pend[ins.operands[0].reg] = p
                cnt = 0
            else:
                pend.pop(ins.operands[0].reg, None)
            continue
        if m in ('ldr','ldrb','ldrh','ldrsw','ldur') and ins.operands[1].type == ARM64_OP_MEM:
            b = ins.operands[1].mem.base
            if b in pend:
                eff = (pend[b] + ins.operands[1].mem.disp) & 0xFFFFFFFFFFFFFFFF
                if eff in SLOTS:
                    res.append((ins.address, 'ldr', eff, name))
        elif m == 'add' and len(ins.operands) == 3 and ins.operands[1].type == ARM64_OP_REG and ins.operands[2].type == ARM64_OP_IMM:
            b = ins.operands[1].reg
            if b in pend:
                eff = (pend[b] + ins.operands[2].imm) & 0xFFFFFFFFFFFFFFFF
                if eff in SLOTS:
                    res.append((ins.address, 'add', eff, name))
        elif m in ('br','blr','ret','b','bl'):
            pass
        if pend:
            try:
                for o in ins.operands:
                    if o.type == ARM64_OP_REG and o.access and o.access & CS_AC_WRITE and o.reg in pend and o.reg != ins.operands[0].reg:
                        pend.pop(o.reg, None)
            except CsError:
                pass

print('total xref sites', len(res))
by = {}
for va, kind, slot, seg in res:
    by.setdefault(SLOTS[slot], []).append((va, kind, slot))
for slug, v in by.items():
    print('==', slug, len(v))
    for va, kind, slot in sorted(v):
        print('   ', hex(va), kind, 'slot', hex(slot))
import pickle
pickle.dump(res, open('xrefs.pkl','wb'))
