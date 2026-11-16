import struct
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM


class MachO:
    def __init__(self, path):
        self.d = open(path, 'rb').read()
        d = self.d
        self.sections = {}
        self.segments = []
        magic, = struct.unpack_from('<I', d, 0)
        assert magic == 0xfeedfacf, hex(magic)
        ncmds, = struct.unpack_from('<I', d, 16)
        off = 32
        for _ in range(ncmds):
            cmd, sz = struct.unpack_from('<II', d, off)
            if cmd == 0x19:
                name = d[off + 8:off + 24].split(b'\0')[0].decode()
                vmaddr, vmsize, fileoff, filesize = struct.unpack_from('<QQQQ', d, off + 24)
                nsects, = struct.unpack_from('<I', d, off + 64)
                self.segments.append((name, vmaddr, vmsize, fileoff, filesize))
                so = off + 72
                for _ in range(nsects):
                    sname = d[so:so + 16].split(b'\0')[0].decode()
                    seg = d[so + 16:so + 32].split(b'\0')[0].decode()
                    addr, size, offset = struct.unpack_from('<QQI', d, so + 32)
                    self.sections[seg + ',' + sname] = (addr, size, offset)
                    so += 80
            off += sz

    def sec(self, key):
        return self.sections[key]

    def va2off(self, va):
        for name, vmaddr, vmsize, fileoff, filesize in self.segments:
            if vmaddr <= va < vmaddr + filesize:
                return fileoff + (va - vmaddr)
        return None

    def cstr(self, va):
        o = self.va2off(va)
        if o is None:
            return None
        e = self.d.index(b'\0', o)
        return self.d[o:e].decode('utf-8', 'replace')

    def find_string(self, s):
        return self.d.find(s.encode() + b'\0')


def _text(m):
    addr, size, off = m.sec('__TEXT,__text')
    return m.d[off:off + size], addr


def iter_insns(m):
    code, base = _text(m)
    md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    md.detail = True
    for insn in md.disasm(code, base):
        yield insn


def find_refs(m, target_va):
    """adrp+add pairs resolving to target_va, and adrp-only if page==target page and add later."""
    refs = []
    page = {}
    md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    md.detail = True
    code, base = _text(m)
    for insn in md.disasm(code, base):
        if insn.mnemonic == 'adrp':
            page[insn.operands[0].reg] = insn.operands[1].imm
        elif insn.mnemonic == 'add' and len(insn.operands) == 3:
            dst, src, imm = insn.operands
            if src.type == 1 and imm.type == 2:
                v = page.get(src.reg)
                if v is not None and v + imm.imm == target_va:
                    refs.append(insn.address)
        elif insn.mnemonic == 'ldr' and len(insn.operands) == 3:
            dst, mem, imm = insn.operands
            if mem.type == 3 and imm.type == 2:
                v = page.get(mem.mem.base)
                if v is not None and v + imm.imm == target_va:
                    refs.append(insn.address)
    return refs


def disasm_range(m, va, count=40, back=60):
    code, base = _text(m)
    md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    md.detail = True
    start = max(base, va - back * 4)
    out = []
    for insn in md.disasm(code[start - base:start - base + (back + count) * 4], start):
        out.append((insn.address, insn.mnemonic, insn.op_str))
    return out
