#!/usr/bin/env python3
# decode dyld chained fixups for a kext slice, resolve pointers by VA
import struct
from kc import Fileset, u32, u64

FORMATS = {1:'ARM64E', 2:'PTR_64', 3:'PTR_32', 6:'ARM64E_USERLAND', 7:'ARM64E_KERNEL', 8:'ARM64E_USERLAND24'}

class Fixups:
    def __init__(self, fs, eid):
        self.fs=fs; m=fs.get(eid); self.m=m; self.d=fs.d
        self.base = m.segs[0].vmaddr
        self.seg_infos = {}   # segname -> list of (page_va, first_off, fmt)
        self.imports = []
        self.symbols = b''
        self._parse()
    def _parse(self):
        d=self.d; m=self.m
        off = m.base+32
        cf = None
        for _ in range(m.ncmds):
            cmd, sz = u32(d, off), u32(d, off+4)
            if cmd == 0x80000034:
                dataoff, datasize = struct.unpack_from('<II', d, off+8)
                cf = (dataoff, datasize)
            off += sz
        if not cf: return
        o = cf[0]
        fixups_version, starts_off, imports_off, symbols_off, imports_count, imports_format, symbols_format = struct.unpack_from('<IIIIIII', d, o)
        self.imports_format = imports_format
        # imports
        for i in range(imports_count):
            if imports_format == 1:  # DYLD_CHAINED_IMPORT
                v, = struct.unpack_from('<I', d, o+imports_off+i*4)
                lib = v & 0xff; weak = (v>>8)&1
                nameoff = v>>9
                name = self._cstr(o+symbols_off+nameoff)
                self.imports.append((lib, weak, name))
            elif imports_format == 3:  # DYLD_CHAINED_IMPORT_ADDEND64
                v, addend = struct.unpack_from('<QI', d, o+imports_off+i*16)
                nameoff = v>>32
                name = self._cstr(o+symbols_off+nameoff)
                self.imports.append((0,0,name,addend))
        # starts
        seg_count = u32(d, o+starts_off)
        for i in range(seg_count):
            sioff = u32(d, o+starts_off+4+i*4)
            if sioff == 0: continue
            si = o+starts_off+sioff
            size, page_size, fmt, seg_off = struct.unpack_from('<IHHQ', d, si)
            maxvalid, page_count = struct.unpack_from('<IH', d, si+20)
            segname = None
            for s in m.segs:
                if s.fileoff - m.base == seg_off: segname = s.name
            starts=[]
            for p in range(page_count):
                ps = struct.unpack_from('<H', d, si+28+p*2)[0]
                if ps == 0xFFFF: continue
                if ps & 0x8000:  # multi-start
                    idx = ps & 0x7FFF
                    # overflow starts table after page_start array
                    base2 = si+28+page_count*2
                    cnt = struct.unpack_from('<H', d, base2+idx*4)[0]
                    for k in range(cnt):
                        so = struct.unpack_from('<H', d, base2+idx*4+2+k*2)[0]
                        starts.append(p*page_size+so)
                else:
                    starts.append(p*page_size+ps)
            self.seg_infos[segname]=(page_size, fmt, starts, seg_off)
    def _cstr(self, off):
        e=self.d.find(b'\0', off, off+512)
        return bytes(self.d[off:e]).decode('latin1','replace')
    def iter_binds(self, segname):
        """yield (va, symbol_or_ordinal) for bind entries in segment"""
        if segname not in self.seg_infos: return
        page_size, fmt, starts, seg_off = self.seg_infos[segname]
        for s in self.m.segs:
            if s.name==segname: vmstart=s.vmaddr; fstart=s.fileoff
        for st in starts:
            va = vmstart + st; off = fstart + st
            while True:
                raw = u64(self.d, off)
                nxt, isbind, auth = self._next(raw, fmt)
                if isbind:
                    ordinal = raw & 0xFFFFFF if fmt in (1,7) else raw & 0xFFFF
                    name = self.imports[ordinal][2] if ordinal < len(self.imports) else f'ord{ordinal}'
                    yield va, name, raw
                if nxt == 0: break
                off += nxt; va += nxt
    def _next(self, raw, fmt):
        if fmt in (1,6,7,8):
            # arm64e: next bits 51..61 (11 bits), bind bit 62, auth bit 63
            nxt = (raw >> 51) & 0x7FF
            bind = (raw >> 62) & 1
            auth = (raw >> 63) & 1
            return nxt, bind, auth
        elif fmt == 2:
            nxt = (raw >> 51) & 0xFFF
            bind = (raw >> 63) & 1
            return nxt, bind, 0
        return 0,0,0
    def resolve(self, va, segname='__DATA_CONST'):
        """decode a rebase pointer stored at va -> target VA"""
        if segname not in self.seg_infos: return None
        page_size, fmt, starts, seg_off = self.seg_infos[segname]
        for s in self.m.segs:
            if s.name==segname: vmstart=s.vmaddr; fstart=s.fileoff
        off = fstart + (va-vmstart)
        raw = u64(self.d, off)
        bind = (raw>>62)&1
        auth = (raw>>63)&1
        if bind:
            ordinal = raw & 0xFFFFFF
            return ('bind', self.imports[ordinal][2] if ordinal<len(self.imports) else ordinal)
        if auth:
            target = raw & 0xFFFFFFFF
            return ('auth', target)
        target = raw & 0x7FFFFFFFFFF
        high8 = (raw>>43)&0xFF
        return ('rebase', self.base + target if target < 0x100000000000 else target)
