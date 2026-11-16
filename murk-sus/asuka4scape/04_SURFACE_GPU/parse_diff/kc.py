#!/usr/bin/env python3
"""Minimal Mach-O kext-collection reader: header, LC_SEGMENT_64 map, va<->off."""
import struct, sys

class KC:
    def __init__(self, path):
        self.path = path
        with open(path, 'rb') as f:
            self.data = f.read()
        self.segs = []          # (name, vmaddr, vmsize, fileoff, filesize, maxprot, initprot)
        self._parse()

    def _parse(self):
        d = self.data
        magic = struct.unpack_from('<I', d, 0)[0]
        assert magic in (0xfeedfacf, 0xcffaedfe), hex(magic)
        self.magic = magic
        (self.cputype, self.cpusubtype, self.filetype, self.ncmds,
         self.sizeofcmds, self.flags) = struct.unpack_from('<iiIIII', d, 4)
        self.cputype &= 0xffffffff
        off = 32
        segs = []
        for _ in range(self.ncmds):
            cmd, cmdsize = struct.unpack_from('<II', d, off)
            if cmd == 0x19:  # LC_SEGMENT_64
                name = d[off+8:off+24].split(b'\0')[0].decode('ascii', 'replace')
                vmaddr, vmsize, fileoff, filesize = struct.unpack_from('<QQQQ', d, off+24)
                maxprot, initprot, nsects, sflags = struct.unpack_from('<iiII', d, off+56)
                segs.append(dict(name=name, vmaddr=vmaddr, vmsize=vmsize,
                                 fileoff=fileoff, filesize=filesize,
                                 maxprot=maxprot, initprot=initprot, nsects=nsects))
            off += cmdsize
        self.segs = segs
        self.text_base = next(s['vmaddr'] for s in segs if s['name'] == '__TEXT')
        # kernel slide base used by PAC low-28 encode
        self.pac_base = self.text_base

    def seg(self, name):
        return next((s for s in self.segs if s['name'] == name), None)

    def va2off(self, va, size=1):
        for s in self.segs:
            if s['fileoff'] == 0 and s['filesize'] == 0:
                continue
            if s['vmaddr'] <= va < s['vmaddr'] + s['filesize']:
                if va + size > s['vmaddr'] + s['filesize']:
                    return None
                return s['fileoff'] + (va - s['vmaddr'])
        return None

    def off2va(self, off):
        for s in self.segs:
            if s['fileoff'] and s['fileoff'] <= off < s['fileoff'] + s['filesize']:
                return s['vmaddr'] + (off - s['fileoff'])
        return None

    def read(self, va, n):
        o = self.va2off(va, n)
        if o is None:
            return None
        return self.data[o:o+n]

    def q(self, va):
        b = self.read(va, 8)
        return None if b is None else struct.unpack('<Q', b)[0]

    def u32(self, va):
        b = self.read(va, 4)
        return None if b is None else struct.unpack('<I', b)[0]

    def unpac(self, q):
        """PAC-encoded pointer in __DATA_CONST/__DATA: top32 sig, low28 = offset from text base."""
        if q is None:
            return None
        return self.pac_base + (q & 0x0FFFFFFF)

    def is_pac(self, q):
        return q is not None and (q >> 32) in (0x8050bcad, 0x8050bcae, 0x00000000) or \
               (q is not None and 0xffffffff00000000 <= (q & 0xffffffff00000000))

    def find(self, needle, start=0):
        i = self.data.find(needle, start)
        return i

    def dump_segs(self):
        out = []
        for s in self.segs:
            out.append("%-16s %#018x %#010x  off=%#010x size=%#010x" % (
                s['name'], s['vmaddr'], s['vmsize'], s['fileoff'], s['filesize']))
        return "\n".join(out)


if __name__ == '__main__':
    k = KC(sys.argv[1])
    print("file:", k.path)
    print("filetype=%d ncmds=%d sizeofcmds=%#x cputype=%#x" % (
        k.filetype, k.ncmds, k.sizeofcmds, k.cputype))
    print(k.dump_segs())
    print("text_base = %#018x" % k.text_base)
