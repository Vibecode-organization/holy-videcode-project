"""function boundary finder + per-call-site context dump for kernelcache."""
import struct, bisect, pickle, sys
import numpy as np
from capstone import *
from capstone.arm64 import *

KC = '/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache'
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
d = open(KC, 'rb').read()


def va2off(va):
    for n, sva, so, sz in SEGS:
        if sva <= va < sva + sz:
            return so + va - sva
    return None


def rd(va, n):
    o = va2off(va)
    if o is None:
        return b''
    return d[o:o + n]


def u32(va):
    b = rd(va, 4)
    return struct.unpack('<I', b)[0] if len(b) == 4 else None


TERM = {0xd65f03c0, 0xd65f0bff, 0xd65f0fff,  # ret / retab / retaa-ish
        0xd503201f, 0x00000000, 0xd4200000}   # nop, zero, brk


def build_funcmap():
    starts = []
    PACIBSP = u32(0xfffffff00a8d8754)
    for name, sva, so, sz in SEGS:
        if name not in EXEC:
            continue
        n = sz // 4
        w = np.frombuffer(d[so:so + n * 4], dtype='<u4').astype(np.uint32)
        idx = np.nonzero(w == np.uint32(PACIBSP))[0]
        prev = np.concatenate(([0], w[:-1]))
        ok = []
        for i in idx:
            if i == 0 or int(prev[i]) in TERM or (int(prev[i]) >> 26) in (0x05, 0x25):
                ok.append(i)
        for i in idx:
            # also accept pacibsp preceded by another function's padding/term inside same page
            pass
        starts.extend(sva + int(i) * 4 for i in ok)
    starts.sort()
    return starts


def dis(va, count):
    md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    md.detail = True
    o = va2off(va)
    return list(md.disasm(d[o:o + count * 4], va))


def fmt(ins):
    return '0x%016x  %-8s %s' % (ins.address, ins.mnemonic, ins.op_str)


def adrp_page(ins):
    return ins.operands[1].imm & 0xFFFFFFFFFFFFFFFF


def strings_in(start, end, minlen=4):
    """adrp(+add) -> printable C string refs inside function [start,end)."""
    out = []
    insns = dis(start, (end - start) // 4)
    pend = {}
    for ins in insns:
        if ins.mnemonic == 'adrp':
            pend[ins.operands[0].reg] = adrp_page(ins)
            continue
        if ins.mnemonic == 'add' and len(ins.operands) == 3 and ins.operands[2].type == ARM64_OP_IMM:
            b = ins.operands[1].reg
            if b in pend:
                va = (pend[b] + ins.operands[2].imm) & 0xFFFFFFFFFFFFFFFF
                s = rd(va, 96)
                if len(s) > minlen and all(32 <= c < 127 or c == 0 for c in s[:minlen]):
                    e = s.find(b'\0')
                    if e >= minlen:
                        out.append((ins.address, s[:e].decode('ascii', 'replace')))
        if ins.mnemonic in ('ldr', 'ldrb', 'ldrh', 'ldrsw') and ins.operands[1].type == ARM64_OP_MEM:
            b = ins.operands[1].mem.base
            if b in pend:
                va = (pend[b] + ins.operands[1].mem.disp) & 0xFFFFFFFFFFFFFFFF
                q = rd(va, 8)
                if len(q) == 8:
                    v = struct.unpack('<Q', q)[0]
                    if v and va2off(v & 0xFFFFFFFFFFFFFFFF):
                        pass
    return out


def func_start_map():
    return build_funcmap()


if __name__ == '__main__':
    fm = build_funcmap()
    print('functions', len(fm))
    pickle.dump(fm, open('/home/femboychik/work/keytype/funcstarts.pkl', 'wb'))
    # quick sanity on known funcs
    for a in (0xfffffff00a8d8754, 0xfffffff00a8d96f4, 0xfffffff009c3ac1c):
        i = bisect.bisect_right(fm, a) - 1
        print('%016x -> func %016x (+0x%x)' % (a, fm[i], a - fm[i]))
