import struct, hashlib
from capstone import *
from capstone.arm64 import *
from kc import KC, KC27_0, KC27_2
import xr

def insns(kc, f, e):
    md = Cs(CS_ARCH_ARM64, CS_MODE_ARM); md.detail = True
    o = kc.va2off(f)
    return list(md.disasm(kc.d[o:o + (e - f)], f))

def normalize(kc, f, e):
    out = []
    page = {}
    for ins in insns(kc, f, e):
        m = ins.mnemonic; ops = ins.op_str
        if m == 'adrp':
            page[ins.operands[0].reg] = True
            ops = ops.split(',')[0]
        elif m in ('b','bl'):
            ops = 'rel%+d' % ((ins.operands[0].imm & 0xFFFFFFFFFFFFFFFF) - ins.address)
        elif m == 'adr':
            ops = ops.split(',')[0]
        elif m in ('cbz','cbnz','tbz','tbnz'):
            parts = ops.split(',')
            rel = (ins.operands[-1].imm & 0xFFFFFFFFFFFFFFFF) - ins.address
            ops = ','.join(parts[:-1]) + ',rel%+d' % rel
        elif m in ('add','sub') and len(ins.operands) == 3 and ins.operands[1].type == ARM64_OP_REG and page.get(ins.operands[1].reg):
            parts = ops.split(','); ops = '%s,%s' % (parts[0], parts[1])
        elif m in ('ldr','ldrb','ldrh','ldrsw','str','strb','strh','ldur','stur') and len(ins.operands) >= 2 and ins.operands[1].type == ARM64_OP_MEM and page.get(ins.operands[1].mem.base):
            ops = ops.split(',')[0]
        out.append(m + ' ' + ops)
    return out

def cmp(kc1, f1, kc2, f2, n):
    a = normalize(kc1, f1, f1 + n); b = normalize(kc2, f2, f2 + n)
    h1 = hashlib.sha256('\n'.join(a).encode()).hexdigest()
    h2 = hashlib.sha256('\n'.join(b).encode()).hexdigest()
    d = [(i, a[i], b[i]) for i in range(min(len(a), len(b))) if a[i] != b[i]]
    return h1, h2, len(a), len(b), d
