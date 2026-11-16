import struct, sys
from capstone import *
from capstone.arm64 import *
from kc import KC, SEGS
import xr

kc = KC()
md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
md.detail = True

def is_str_at(va):
    o = kc.va2off(va)
    if o is None or o >= len(kc.d):
        return None
    end = kc.d.find(b'\0', o, o + 200)
    if end < 0:
        return None
    b = kc.d[o:end]
    if len(b) < 2:
        return None
    if all(32 <= c < 127 or c in (9, 10) for c in b):
        return b.decode()
    return None

def annot(ins, addr):
    """return comment string"""
    s = ''
    # adrp+add/ldr resolution
    return s

def dump(va, n=80, resolve_dc=True, show_bytes=False):
    o = kc.va2off(va)
    code = kc.d[o:o + n * 4]
    insns = list(md.disasm(code, va))
    out = []
    prev_adrp = None  # (addr, rd, page)
    for ins in insns:
        line = '0x%016x  %-8s %s' % (ins.address, ins.mnemonic, ins.op_str)
        if show_bytes:
            line = '%08x  ' % struct.unpack('<I', code[(ins.address - va):(ins.address - va) + 4])[0] + line
        cmt = ''
        if ins.mnemonic == 'adrp':
            page = ins.operands[1].imm & 0xFFFFFFFFFFFFFFFF
            prev_adrp = (ins.address, ins.operands[0].reg, page)
        elif ins.mnemonic == 'add' and prev_adrp and len(ins.operands) == 3 and ins.operands[2].type == ARM64_OP_IMM:
            if ins.operands[1].reg == prev_adrp[1] and ins.address - prev_adrp[0] <= 12:
                tgt = (prev_adrp[2] + ins.operands[2].imm) & 0xFFFFFFFFFFFFFFFF
                s = is_str_at(tgt)
                cmt = '; = 0x%x' % tgt + (' "%s"' % s if s else '')
        elif ins.mnemonic in ('ldr', 'ldrb', 'ldrh', 'str', 'ldrsw') and len(ins.operands) >= 2 and ins.operands[1].type == ARM64_OP_MEM:
            if prev_adrp and ins.operands[1].mem.base == prev_adrp[1] and ins.address - prev_adrp[0] <= 12:
                tgt = (prev_adrp[2] + ins.operands[1].mem.disp) & 0xFFFFFFFFFFFFFFFF
                s = is_str_at(tgt)
                cmt = '; [0x%x]' % tgt + (' "%s"' % s if s else '')
                q = kc.rd(tgt, 8)
                if q and len(q) == 8 and resolve_dc:
                    qq = struct.unpack('<Q', q)[0]
                    cmt += ' val=0x%016x' % qq
        elif ins.mnemonic == 'bl':
            t = ins.operands[0].imm & 0xFFFFFFFFFFFFFFFF
            cmt = '; -> 0x%x' % t
            s = is_str_at(t)
            if s: cmt += ''
            if t in NAMES: cmt += ' ' + NAMES[t]
        elif ins.mnemonic == 'b':
            t = ins.operands[0].imm & 0xFFFFFFFFFFFFFFFF
            cmt = '; -> 0x%x' % t
        line = line.ljust(58) + cmt
        out.append(line)
    return '\n'.join(out)

NAMES = {}

def set_names(d):
    NAMES.update(d)
