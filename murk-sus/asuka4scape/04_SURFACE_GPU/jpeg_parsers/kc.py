# kernelcache Mach-O fileset parser (MH_FILESET) + layout helpers
import struct, os, sys, bisect

KC = "/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache"
BASE = 0xfffffff007004000

class KC:
    def __init__(self, path=KC):
        self.path = path
        with open(path,'rb') as f:
            self.data = f.read()
        d = self.data
        self.magic, self.cputype, self.cpusubtype, self.filetype, self.ncmds, self.sizeofcmds, self.flags = \
            struct.unpack_from('<IIIIIII', d, 0)
        assert self.magic == 0xfeedfacf, hex(self.magic)
        self.segs = []     # (name, vmaddr, vmsize, fileoff, filesize, maxprot, initprot)
        self.filesets = [] # (entry_id, vmaddr, fileoff, entryoff)
        self.syms = []
        off = 32
        for i in range(self.ncmds):
            cmd, cmdsize = struct.unpack_from('<II', d, off)
            if cmd == 0x19:  # LC_SEGMENT_64
                segname = d[off+8:off+24].rstrip(b'\0').decode()
                vmaddr, vmsize, fileoff, filesize, maxprot, initprot, nsects, flags = \
                    struct.unpack_from('<QQQQiiII', d, off+24)
                self.segs.append(dict(name=segname, vmaddr=vmaddr, vmsize=vmsize,
                                      fileoff=fileoff, filesize=filesize,
                                      maxprot=maxprot, initprot=initprot, flags=flags))
            elif cmd == 0x35:  # LC_FILESET_ENTRY
                vmaddr, fileoff, entry_id_off, _reserved = struct.unpack_from('<QQII', d, off+8)
                eid = d[entry_id_off:d.index(b'\0', entry_id_off)].decode('utf-8','replace')
                self.filesets.append((eid, vmaddr, fileoff, entry_id_off))
            elif cmd == 0x2:  # LC_SYMTAB
                symoff, nsyms, stroff, strsize = struct.unpack_from('<IIII', d, off+8)
                self.symoff, self.nsyms, self.stroff, self.strsize = symoff, nsyms, stroff, strsize
            off += cmdsize
        self._build_index()
        self._load_syms()

    def _build_index(self):
        self.seg_by_name = {s['name']: s for s in self.segs}
        self._ranges = []
        for s in self.segs:
            if s['filesize']:
                self._ranges.append((s['vmaddr'], s['vmaddr']+s['filesize'], s['fileoff'], s['filesize']))
        self._ranges.sort()
        self._starts = [r[0] for r in self._ranges]

    def off(self, va):
        i = bisect.bisect_right(self._starts, va) - 1
        if i < 0: return None
        lo, hi, foff, fsz = self._ranges[i]
        if va < hi:
            return foff + (va - lo)
        return None

    def rd(self, va, n):
        o = self.off(va)
        if o is None or o+n > len(self.data): return None
        return self.data[o:o+n]

    def q(self, va):
        b = self.rd(va, 8)
        return struct.unpack('<Q', b)[0] if b else None

    def d32(self, va):
        b = self.rd(va, 4)
        return struct.unpack('<I', b)[0] if b else None

    def _load_syms(self):
        self.symmap = {}
        if not getattr(self,'nsyms',0): return
        d = self.data
        for i in range(self.nsyms):
            e = self.symoff + i*16
            if e+16 > len(d): break
            n_strx, n_type, n_sect, n_desc, n_value = struct.unpack_from('<IBBHQ', d, e)
            if n_strx == 0: continue
            s = self.stroff + n_strx
            z = d.index(b'\0', s)
            name = d[s:z].decode('utf-8','replace')
            if n_value:
                self.symmap.setdefault(n_value, name)
        self.symaddrs = sorted(self.symmap)

    def sym_at(self, va):
        return self.symmap.get(va)

    def sym_before(self, va, limit=0x2000):
        i = bisect.bisect_right(self.symaddrs, va) - 1
        if i >= 0:
            a = self.symaddrs[i]
            if va - a <= limit:
                return a, self.symmap[a]
        return None

    def kext_at(self, va):
        # fileset entries are sorted by vmaddr; entry range = to next entry
        i = bisect.bisect_right([f[1] for f in self._fs_sorted], va) - 1
        if i < 0: return None
        return self._fs_sorted[i][0]

kc = None
def load():
    global kc
    if kc is None:
        kc = KC()
        kc._fs_sorted = sorted([(f[0], f[1]) for f in kc.filesets], key=lambda x: x[1])
    return kc

if __name__ == '__main__':
    k = load()
    print("filetype", k.filetype, "ncmds", k.ncmds, "nsyms", getattr(k,'nsyms',0))
    for s in k.segs:
        print(f"{s['name']:20} va={s['vmaddr']:#018x} vmsize={s['vmsize']:#x} fileoff={s['fileoff']:#x} filesize={s['filesize']:#x}")
    print("fileset entries:", len(k.filesets))
    print("syms:", len(k.symmap))
