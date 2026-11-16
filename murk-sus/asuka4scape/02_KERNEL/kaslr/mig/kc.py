#!/usr/bin/env python3
"""Minimal Mach-O kernelcache reader: VA<->file offset, segments, sections, symbol-ish helpers."""
import struct, sys

KC = '/home/femboychik/work/kc272/24B119__iPhone14,7/kernelcache.release.iPhone14,7'

class KCFile:
    def __init__(self, path=KC):
        self.path = path
        self.d = open(path, 'rb').read()
        magic, cpu, sub, ft, ncmds, sz, flags, res = struct.unpack_from('<IiiIIIII', self.d, 0)
        assert magic == 0xfeedfacf, hex(magic)
        self.segments = []
        self.sections = []
        off = 32
        for _ in range(ncmds):
            cmd, cs = struct.unpack_from('<II', self.d, off)
            if cmd == 0x19:
                segname = self.d[off+8:off+24].split(b'\0')[0].decode()
                va, vs, fo, fs, maxp, initp, nsect, fl = struct.unpack_from('<QQQQiiII', self.d, off+24)
                self.segments.append(dict(name=segname, va=va, vsize=vs, foff=fo, fsize=fs, nsect=nsect))
                so = off + 72
                for j in range(nsect):
                    sn = self.d[so:so+16].split(b'\0')[0].decode()
                    sv = self.d[so+16:so+32].split(b'\0')[0].decode()
                    addr, size, offset = struct.unpack_from('<QQI', self.d, so+32)
                    self.sections.append(dict(seg=segname, name=sn, va=addr, vsize=size, foff=offset))
                    so += 80
            off += cs
        self.segments.sort(key=lambda s: s['va'])

    def va2off(self, va):
        for s in self.segments:
            if s['va'] <= va < s['va'] + s['fsize']:
                return s['foff'] + (va - s['va'])
        return None

    def read(self, va, n):
        o = self.va2off(va)
        if o is None:
            return None
        return self.d[o:o+n]

    def u32(self, va):
        b = self.read(va, 4)
        return struct.unpack('<I', b)[0] if b else None

    def u64(self, va):
        b = self.read(va, 8)
        return struct.unpack('<Q', b)[0] if b else None

    def cstr(self, va, maxn=512):
        o = self.va2off(va)
        if o is None:
            return None
        e = self.d.find(b'\0', o, o+maxn)
        return self.d[o:e].decode('utf-8', 'replace')

    def ptr_at(self, va):
        """Read a possibly-chained ptr: returns va if it's a plain kernel VA."""
        v = self.u64(va)
        return v

    def seg_of(self, va):
        for s in self.segments:
            if s['va'] <= va < s['va'] + s['vsize']:
                return s['name']
        return None

if __name__ == '__main__':
    k = KCFile()
    for s in k.segments:
        print('SEG %-20s va=%#014x vsize=%#010x foff=%#010x fsize=%#010x' % (s['name'], s['va'], s['vsize'], s['foff'], s['fsize']))
