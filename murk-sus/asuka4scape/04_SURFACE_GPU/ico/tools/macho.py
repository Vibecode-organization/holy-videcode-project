"""Mach-O reader for arm64e dsc-extracted images: segments, symbols, chained fixups, disasm helpers.

Resolution notes:
  - chained fixups (DYLD_CHAINED_PTR_64_OFFSET / ARM64E): pointers are rebased at runtime.
    For static analysis we expose resolve_chain() -> target VA or symbol name.
  - capstone gives SIGNED immediates for adrp/b/bl. Always mask with & 0xFFFFFFFFFFFFFFFF
    before using as an address. This module masks everything itself.
"""
import struct
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM

MASK64 = 0xFFFFFFFFFFFFFFFF

LC_SEGMENT_64 = 0x19
LC_SYMTAB = 0x2
LC_DYSYMTAB = 0xB
LC_DYLD_CHAINED_FIXUPS = 0x80000034
LC_DYLD_INFO_ONLY = 0x80000022


class Segment:
    def __init__(self, name, vmaddr, vmsize, fileoff, filesize, maxprot, initprot):
        self.name = name
        self.vmaddr = vmaddr
        self.vmsize = vmsize
        self.fileoff = fileoff
        self.filesize = filesize
        self.maxprot = maxprot
        self.initprot = initprot

    @property
    def end(self):
        return self.vmaddr + self.vmsize

    def __repr__(self):
        return f"<Seg {self.name} {self.vmaddr:#x}+{self.vmsize:#x} f{self.fileoff:#x}>"


class MachO:
    def __init__(self, path):
        self.path = path
        self.data = open(path, 'rb').read()
        self.d = self.data
        magic, ct, cs, ft, ncmds, sz, flags, res = struct.unpack_from('<IiiIIIII', self.d, 0)
        assert magic == 0xfeedfacf, hex(magic)
        self.segments = []
        self.symbols = []          # (name, n_type, n_sect, n_desc, n_value)
        self.sym_by_addr = {}
        self.sym_by_name = {}
        self.chained = None
        self._parse_lc(ncmds)

    def _parse_lc(self, ncmds):
        off = 32
        for _ in range(ncmds):
            cmd, cmdsz = struct.unpack_from('<II', self.d, off)
            if cmd == LC_SEGMENT_64:
                name = self.d[off + 8:off + 24].rstrip(b'\x00').decode('latin1')
                vmaddr, vmsize, fileoff, filesize = struct.unpack_from('<QQQQ', self.d, off + 24)
                maxprot, initprot = struct.unpack_from('<ii', self.d, off + 56)
                self.segments.append(Segment(name, vmaddr, vmsize, fileoff, filesize, maxprot, initprot))
            elif cmd == LC_SYMTAB:
                symoff, nsyms, stroff, strsize = struct.unpack_from('<IIII', self.d, off + 8)
                self._parse_symtab(symoff, nsyms, stroff, strsize)
            elif cmd == LC_DYLD_CHAINED_FIXUPS:
                doff, dsz = struct.unpack_from('<II', self.d, off + 8)
                self.chained = (doff, dsz)
            off += cmdsz

    def _parse_symtab(self, symoff, nsyms, stroff, strsize):
        stro = self.d[stroff:stroff + strsize]
        for i in range(nsyms):
            p = symoff + i * 16
            if p + 16 > len(self.d):
                break
            n_strx, n_type, n_sect, n_desc, n_value = struct.unpack_from('<IBBHQ', self.d, p)
            if n_strx >= len(stro):
                continue
            end = stro.find(b'\x00', n_strx)
            name = stro[n_strx:end].decode('latin1', 'replace')
            sym = (name, n_type, n_sect, n_desc, n_value)
            self.symbols.append(sym)
            if n_value:
                self.sym_by_addr.setdefault(n_value, name)
            self.sym_by_name.setdefault(name, n_value)

    # ---- VA <-> file ----
    def seg_of(self, va):
        for s in self.segments:
            if s.vmaddr <= va < s.end:
                return s
        return None

    def va2off(self, va):
        s = self.seg_of(va)
        if s is None:
            return None
        if s.filesize == 0:
            return None
        delta = va - s.vmaddr
        if delta >= s.filesize:
            return None
        return s.fileoff + delta

    def off2va(self, off):
        for s in self.segments:
            if s.fileoff <= off < s.fileoff + s.filesize:
                return s.vmaddr + (off - s.fileoff)
        return None

    def read(self, va, n):
        o = self.va2off(va)
        if o is None:
            return None
        return self.d[o:o + n]

    def qword(self, va):
        b = self.read(va, 8)
        return None if b is None or len(b) < 8 else struct.unpack('<Q', b)[0]

    def dword(self, va):
        b = self.read(va, 4)
        return None if b is None or len(b) < 4 else struct.unpack('<I', b)[0]

    # ---- chained fixups ----
    def _fixup_header(self):
        if not self.chained:
            return None
        doff, dsz = self.chained
        blob = self.d[doff:doff + dsz]
        # dyld_chained_fixups_header
        version, starts_off, imports_off, symbols_off, imports_count, imports_format, symbols_format = \
            struct.unpack_from('<IIIIIII', blob, 0)
        return dict(blob=blob, version=version, starts_off=starts_off, imports_off=imports_off,
                    symbols_off=symbols_off, imports_count=imports_count,
                    imports_format=imports_format, symbols_format=symbols_format)

    def chained_starts(self):
        """-> list of (segment_index, page_size, [start offsets])"""
        h = self._fixup_header()
        if not h:
            return []
        blob = h['blob']
        base = h['starts_off']
        seg_count = struct.unpack_from('<I', blob, base)[0]
        out = []
        for i in range(seg_count):
            seg_info_off = struct.unpack_from('<I', blob, base + 4 + i * 4)[0]
            if seg_info_off == 0:
                out.append((i, 0, []))
                continue
            p = base + seg_info_off
            page_size = struct.unpack_from('<H', blob, p)[0]
            ptr_format = struct.unpack_from('<H', blob, p + 2)[0]
            max_valid = struct.unpack_from('<H', blob, p + 4)[0]
            page_count = struct.unpack_from('<H', blob, p + 6)[0]
            fmt = ptr_format & 0xFFFF
            if fmt in (2, 6):  # DYLD_CHAINED_PTR_64 / 64_OFFSET: 4-byte starts
                starts = struct.unpack_from('<%dH' % page_count, blob, p + 8)
            elif fmt in (1, 7, 9, 12):
                starts = struct.unpack_from('<%dH' % page_count, blob, p + 8)
            else:
                starts = struct.unpack_from('<%dH' % page_count, blob, p + 8)
            out.append((i, page_size, starts, ptr_format))
        return out

    def _imports(self):
        h = self._fixup_header()
        if not h or not h['imports_count']:
            return []
        blob = h['blob']
        fmt = h['imports_format']
        sym_base = h['symbols_off']
        names = []
        p = sym_base
        while p < len(blob):
            end = blob.find(b'\x00', p)
            if end < 0:
                break
            names.append(blob[p:end].decode('latin1'))
            p = end + 1
        imps = []
        for i in range(h['imports_count']):
            p = h['imports_off'] + i * 4
            if p + 4 > len(blob):
                break
            v = struct.unpack_from('<I', blob, p)[0]
            if fmt == 1:  # IMPORT
                lib = v & 0xFF
                name_off = (v >> 9) & 0x7FFFFF
            elif fmt == 3:  # IMPORT_ADDEND64
                name_off = (v >> 32) & 0xFFFF
                lib = -1
            else:
                lib = v & 0xFF
                name_off = (v >> 9) & 0x7FFFFF
            name = ''
            if name_off < len(blob) - sym_base:
                np = sym_base + name_off
                end = blob.find(b'\x00', np)
                name = blob[np:end].decode('latin1', 'replace')
            imps.append((lib, name))
        return imps

    def resolve_chain(self, va):
        """Decode a chained-fixup pointer stored at VA. Returns ('bind', name) | ('rebase', target_va) | None."""
        val = self.qword(va)
        if val is None:
            return None
        # Find which segment/page this VA is in to know the format
        for (segi, page_size, starts, ptr_format) in self.chained_starts():
            s = self.segments[segi] if segi < len(self.segments) else None
            if not s or not (s.vmaddr <= va < s.end):
                continue
            fmt = ptr_format & 0xFFFF
            page = (va - s.vmaddr) // page_size if page_size else 0
            # DYLD_CHAINED_PTR_64_OFFSET: 64-bit, target = vmaddr + (v>>0 & 0xFFFFFFFFF)
            if fmt == 6:  # DYLD_CHAINED_PTR_64_OFFSET
                if val & 1:  # bind
                    ordinal = (val >> 32) & 0xFFFF
                    imps = self._imports()
                    if ordinal < len(imps):
                        return ('bind', imps[ordinal][1])
                    return ('bind', f'ord_{ordinal}')
                # DYLD_CHAINED_PTR_64_OFFSET: rebase target = image base + (v & 0xFFFFFFFFF)
                target = (val & 0xFFFFFFFFF)  # already image-relative
                return ('rebase', target)
            if fmt == 2:  # DYLD_CHAINED_PTR_64: absolute vmaddr
                if val & 1:
                    ordinal = (val >> 32) & 0xFFFF
                    imps = self._imports()
                    if ordinal < len(imps):
                        return ('bind', imps[ordinal][1])
                    return ('bind', f'ord_{ordinal}')
                return ('rebase', val & 0xFFFFFFFFF)
            if fmt == 9:  # DYLD_CHAINED_PTR_ARM64E (userland24)
                if val & 1:
                    ordinal = (val >> 32) & 0xFFFF
                    imps = self._imports()
                    if ordinal < len(imps):
                        return ('bind', imps[ordinal][1])
                    return ('bind', f'ord_{ordinal}')
                target = val & 0xFFFFFFFFF
                return ('rebase', target)
            if fmt == 12:  # DYLD_CHAINED_PTR_ARM64E_USERLAND24
                if (val >> 62) & 1 or val & 1:
                    ordinal = (val >> 32) & 0xFFFFFF
                    imps = self._imports()
                    if ordinal < len(imps):
                        return ('bind', imps[ordinal][1])
                    return ('bind', f'ord_{ordinal}')
                target = val & 0xFFFFFFFFF
                return ('rebase', target)
        return None

    def ptr_target(self, va):
        """Follow a data pointer (chained or plain). Returns VA or None."""
        r = self.resolve_chain(va)
        if not r:
            return None
        if r[0] == 'rebase':
            return r[1]
        return None


def disasm(m, va, count=120, stop_ret=True):
    o = m.va2off(va)
    if o is None:
        return []
    code = m.d[o:o + count * 4]
    md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    md.detail = True
    out = []
    for ins in md.disasm(code, va):
        out.append(ins)
        if stop_ret and ins.mnemonic in ('ret',) and len(out) > 1:
            break
        if len(out) >= count:
            break
    return out


def fmt(m, ins):
    """Disasm text with sign-masked branch/adrp targets and inline symbol annotation."""
    s = f"{ins.address:#012x}  {ins.bytes.hex():<8}  {ins.mnemonic:<8} {ins.op_str}"
    annot = ''
    mn = ins.mnemonic
    ops = ins.op_str
    if mn in ('bl', 'b', 'blraa', 'blrab', 'br', 'blr') or mn.startswith('b.'):
        try:
            tgt = int(ops, 16) & MASK64
            annot = f'  ; -> {tgt:#x}'
            nm = m.sym_by_addr.get(tgt)
            if nm:
                annot += f' {nm}'
        except ValueError:
            pass
    if mn == 'adrp':
        try:
            parts = ops.split(', ')
            imm = int(parts[1], 16) & MASK64
            annot = f'  ; page {imm:#x}'
        except (ValueError, IndexError):
            pass
    return s + annot


def dump(m, va, count=120, stop_ret=True, show_bytes=True):
    lines = []
    for ins in disasm(m, va, count, stop_ret):
        lines.append(fmt(m, ins))
    return '\n'.join(lines)


def find_meth(m, name):
    """Look up __ZN... demangled-ish by substring in symbol table."""
    hits = [(n, v) for (n, v) in m.sym_by_addr.items() if name in n]
    return hits
