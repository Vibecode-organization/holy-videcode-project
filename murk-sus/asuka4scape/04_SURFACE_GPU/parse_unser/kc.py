"""kernelcache helper: VA<->file offset, string find, xref find via capstone."""
import struct, re, sys
from capstone import *
from capstone.arm64 import *

KC27_2 = '/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache'
KC27_0 = '/home/femboychik/Рабочий стол/дипсик 1/kc/27.0_24A437_kernelcache'
KCBASE = 0xfffffff007004000

SEGS = [  # name, va, fileoff, filesize, exec
    ('__TEXT',           0xfffffff007004000, 0x000000, 0x008000, False),
    ('__PRELINK_TEXT',   0xfffffff00700c000, 0x008000, 0xbac000, True),
    ('__DATA_CONST',     0xfffffff007bb8000, 0xbb4000, 0x548000, False),
    ('__DATA_SPTM',      0xfffffff008100000, 0x10fc000, 0x04c000, False),
    ('__TEXT_EXEC',      0xfffffff00814c000, 0x1148000, 0x2924000, True),
    ('__TEXT_BOOT_EXEC', 0xfffffff00aa70000, 0x3a6c000, 0x008000, True),
    ('__PRELINK_INFO',   0xfffffff00aa78000, 0x3a74000, 0x23c000, False),
    ('__DATA',           0xfffffff00acb4000, 0x3cb0000, 0x2b8000, False),
    ('__LINKEDIT',       0xfffffff00af6c000, 0x3f68000, 0x0b8000, False),
]


class KC:
    def __init__(self, path=KC27_2):
        self.path = path
        self.d = open(path, 'rb').read()

    # ---- address translation
    def va2off(self, va):
        for n, sva, so, sz, _ in SEGS:
            if sva <= va < sva + sz:
                return so + (va - sva)
        return None

    def off2va(self, off):
        for n, sva, so, sz, _ in SEGS:
            if so <= off < so + sz:
                return sva + (off - so)
        return None

    def seg_of(self, va):
        for n, sva, so, sz, ex in SEGS:
            if sva <= va < sva + sz:
                return n
        return None

    def rd(self, va, n):
        o = self.va2off(va)
        return self.d[o:o + n]

    def u32(self, va):
        return struct.unpack('<I', self.rd(va, 4))[0]

    def u64(self, va):
        return struct.unpack('<Q', self.rd(va, 8))[0]

    def pac(self, q):
        """decode PAC'd pointer constant as used in this cache"""
        return 0xfffffff007004000 + (q & 0x0FFFFFFF)

    def cstr(self, va):
        o = self.va2off(va)
        e = self.d.index(b'\0', o)
        return self.d[o:e].decode('utf-8', 'replace')

    def find_bytes(self, b, segs=None):
        out = []
        for n, sva, so, sz, ex in SEGS:
            if segs and n not in segs:
                continue
            i = so
            while True:
                i = self.d.find(b, i, so + sz)
                if i < 0:
                    break
                out.append(sva + (i - so))
                i += 1
        return out


# ---------- disassembly helpers ----------
def dis(kc, va, count=40, thumb=False):
    md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    md.detail = True
    o = kc.va2off(va)
    return list(md.disasm(kc.d[o:o + count * 4], va))


def fmt(ins):
    return '0x%016x  %-8s %s' % (ins.address, ins.mnemonic, ins.op_str)


def adrp_target(ins):
    """capstone sign quirk handled"""
    return (ins.operands[1].imm) & 0xFFFFFFFFFFFFFFFF


def bl_target(ins):
    return (ins.operands[0].imm) & 0xFFFFFFFFFFFFFFFF


def find_xrefs(kc, target_va, window=400, segs=('__PRELINK_TEXT', '__TEXT_EXEC', '__TEXT_BOOT_EXEC')):
    """find adrp/add or adrp/ldr pairs resolving to target_va. returns list of (insn_va, kind)"""
    res = []
    for n, sva, so, sz, ex in SEGS:
        if n not in segs:
            continue
        md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
        md.detail = True
        blob = kc.d[so:so + sz]
        insns = list(md.disasm(blob, sva))
        for i, ins in enumerate(insns):
            if ins.mnemonic != 'adrp':
                continue
            page = adrp_target(ins)
            for j in range(i + 1, min(i + 4, len(insns))):
                nxt = insns[j]
                if nxt.mnemonic == 'add' and len(nxt.operands) == 3 and nxt.operands[2].type == ARM64_OP_IMM:
                    if (page + nxt.operands[2].imm) & 0xFFFFFFFFFFFFFFFF == target_va:
                        res.append((ins.address, 'add'))
                elif nxt.mnemonic in ('ldr', 'ldrb', 'ldrh', 'ldrsw') and len(nxt.operands) >= 2:
                    if nxt.operands[1].type == ARM64_OP_MEM and nxt.operands[1].mem.base == ins.operands[0].reg:
                        eff = (page + nxt.operands[1].mem.disp) & 0xFFFFFFFFFFFFFFFF
                        if eff == target_va:
                            res.append((ins.address, 'ldr'))
                if nxt.mnemonic in ('add', 'ldr', 'ldrb', 'ldrh', 'ldrsw', 'br', 'blr', 'ret', 'b') and j > i + 1:
                    break
    return res
