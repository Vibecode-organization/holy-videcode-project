#!/usr/bin/env python3
"""Dump ObjC classes/categories/method IMPs, resolving chained fixups via `ipsw macho info -u`."""
import struct, sys, re, subprocess

LC_SEGMENT_64 = 0x19
LC_SYMTAB = 0x2

FIX_RE = re.compile(r'^0x([0-9a-f]+):\s+raw:\s+0x([0-9a-f]+)\s+(\S+?):\s*(.*)$')
TGT_RE = re.compile(r'target:\s*0x([0-9a-f]+)')

def build_fixups(path):
    out = subprocess.run(['ipsw', 'macho', 'info', '-u', path],
                         capture_output=True, text=True).stdout
    m = {}
    for line in out.splitlines():
        mt = FIX_RE.match(line)
        if not mt: continue
        addr = int(mt.group(1), 16)
        kind, rest = mt.group(3), mt.group(4)
        tg = TGT_RE.search(rest)
        if 'rebase' in kind and tg:
            m[addr] = ('rebase', int(tg.group(1), 16))
        elif 'bind' in kind:
            sym = rest.split(')\t')[-1].strip() if ')' in rest else ''
            m[addr] = ('bind', sym)
    return m

class MachO:
    def __init__(self, path):
        self.d = open(path, 'rb').read()
        self.path = path
        magic, cpu, sub, ftype, ncmds, sizeofcmds, flags, rsv = struct.unpack_from('<IiiIIIII', self.d, 0)
        assert magic == 0xfeedfacf, hex(magic)
        self.segs = []
        self.sects = {}
        self.symoff = self.nsyms = self.stroff = self.strsize = 0
        off = 32
        for _ in range(ncmds):
            cmd, cmdsize = struct.unpack_from('<II', self.d, off)
            if cmd == LC_SEGMENT_64:
                name = self.d[off+8:off+24].split(b'\0')[0].decode()
                vmaddr, vmsize, fileoff, filesize = struct.unpack_from('<QQQQ', self.d, off+24)
                self.segs.append((name, vmaddr, vmsize, fileoff, filesize))
                nsects = struct.unpack_from('<I', self.d, off+64)[0]
                so = off + 72
                for _ in range(nsects):
                    sn = self.d[so:so+16].split(b'\0')[0].decode()
                    addr, size = struct.unpack_from('<QQ', self.d, so+32)
                    foff = struct.unpack_from('<I', self.d, so+48)[0]
                    self.sects.setdefault(sn, []).append((addr, size, foff))
                    so += 80
            elif cmd == LC_SYMTAB:
                self.symoff, self.nsyms, self.stroff, self.strsize = struct.unpack_from('<IIII', self.d, off+8)
            off += cmdsize
        self.base = min(s[1] for s in self.segs if s[1] != 0)
        self.fix = build_fixups(path)

    def off(self, addr):
        for name, vmaddr, vmsize, fileoff, filesize in self.segs:
            if vmaddr <= addr < vmaddr + filesize:
                return fileoff + (addr - vmaddr)
        return None

    def ptr(self, addr):
        """Resolve a pointer slot to an in-image address, or return -1 for external."""
        if addr in self.fix:
            kind, v = self.fix[addr]
            return v if kind == 'rebase' else -1
        o = self.off(addr)
        if o is None: return None
        raw = struct.unpack_from('<Q', self.d, o)[0]
        return raw

    def cstr(self, addr):
        if addr is None or addr < 0: return None
        o = self.off(addr)
        if o is None: return None
        e = self.d.find(b'\0', o)
        return self.d[o:e].decode('utf-8', 'replace')

    def methods(self, mlist_addr, prefix=''):
        out = []
        if mlist_addr is None or mlist_addr < 0: return out
        o = self.off(mlist_addr)
        if o is None: return out
        entsize_flags, count = struct.unpack_from('<II', self.d, o)
        if count > 5000: return out
        relative = bool(entsize_flags & 0x80000000)
        entsize = entsize_flags & 0xfffc
        if entsize == 0: return out
        base = mlist_addr + 8
        for i in range(count):
            ea = base + i*entsize
            eo = self.off(ea)
            if eo is None: continue
            if relative:
                name_off, types_off, imp_off = struct.unpack_from('<iii', self.d, eo)
                sel = self.cstr(self.ptr(ea + name_off))
                imp = ea + imp_off
            else:
                name_p, types_p, imp_p = struct.unpack_from('<QQQ', self.d, eo)
                sel = self.cstr(self.ptr(ea))
                imp = self.ptr(ea + 16)
            out.append((prefix + (sel or '?'), imp))
        return out

    def ivars(self, ivlist_addr):
        out = []
        if ivlist_addr is None or ivlist_addr < 0: return out
        o = self.off(ivlist_addr)
        if o is None: return out
        entsize, count = struct.unpack_from('<II', self.d, o)
        if count > 500 or entsize == 0: return out
        base = ivlist_addr + 8
        for i in range(count):
            ea = base + i*entsize
            eo = self.off(ea)
            if eo is None: continue
            off_p, name_p, type_p = struct.unpack_from('<QQQ', self.d, eo)
            # ivar_t is a relative list too in modern runtimes: offsets from entry
            if entsize >= 32:
                off_p, name_p, type_p = struct.unpack_from('<QQQ', self.d, eo)
                out.append((off_p, self.cstr(self.ptr(ea+8)), self.cstr(self.ptr(ea+16))))
        return out

    def classes(self):
        out = []
        for addr, size, foff in self.sects.get('__objc_classlist', []):
            for i in range(size // 8):
                out.append(self.parse_class(self.ptr(addr + i*8)))
        for addr, size, foff in self.sects.get('__objc_catlist', []):
            for i in range(size // 8):
                out.append(self.parse_category(self.ptr(addr + i*8)))
        return [c for c in out if c]

    def parse_class(self, cls):
        if cls is None or cls < 0: return None
        data = self.ptr(cls + 32)
        if data is None or data < 0: return None
        name = self.cstr(self.ptr(data + 24))
        d = {'kind': 'class', 'name': name, 'addr': cls, 'methods': [], 'ivars': []}
        bm = self.ptr(data + 32)
        d['methods'] += self.methods(bm, '-')
        meta = self.ptr(cls)
        if meta and meta > 0:
            mdata = self.ptr(meta + 32)
            if mdata and mdata > 0:
                cm = self.ptr(mdata + 32)
                d['methods'] += self.methods(cm, '+')
        ivl = self.ptr(data + 72)
        d['ivars'] = self.ivars(ivl)
        return d

    def parse_category(self, cat):
        if cat is None or cat < 0: return None
        name = self.cstr(self.ptr(cat))
        d = {'kind': 'category', 'name': name, 'addr': cat, 'methods': []}
        inst = self.ptr(cat + 16)
        clsm = self.ptr(cat + 24)
        d['methods'] += self.methods(inst, '-')
        d['methods'] += self.methods(clsm, '+')
        return d

def main():
    path = sys.argv[1]
    m = MachO(path)
    only = None
    for a in sys.argv[2:]:
        if not a.startswith('-'):
            only = a
    for c in m.classes():
        if only and only.lower() not in (c['name'] or '').lower(): continue
        print(f"\n{'@interface' if c['kind']=='class' else '@category'} {c['name']}  (0x{c['addr']:x})")
        for o, n, t in c.get("ivars", []):
            print(f"    ivar {n}: {t} @ {o}")
        for sel, imp in c['methods']:
            if isinstance(imp, int) and imp > 0:
                print(f"    0x{imp:x}  {sel}")
            else:
                print(f"    {'?' if imp is None else imp}  {sel}")

if __name__ == '__main__':
    main()
