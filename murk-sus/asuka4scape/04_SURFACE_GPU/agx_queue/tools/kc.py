#!/usr/bin/env python3
# kernelcache fileset reader (offset-based, no slicing copies)
import struct, mmap

KC = "/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache"

def u32(d, o): return struct.unpack_from('<I', d, o)[0]
def s32(d, o): return struct.unpack_from('<i', d, o)[0]
def u64(d, o): return struct.unpack_from('<Q', d, o)[0]

class Seg:
    __slots__ = ('name','vmaddr','vmsize','fileoff','filesize','maxprot','initprot')
    def __init__(self, d, o):
        self.name = bytes(d[o:o+16]).rstrip(b'\0').decode('latin1')
        self.vmaddr, self.vmsize, self.fileoff, self.filesize, self.maxprot, self.initprot, _, _ = struct.unpack_from('<QQQQiiII', d, o+16)
    def __repr__(self): return f"<Seg {self.name} vm={self.vmaddr:#x} size={self.vmsize:#x} off={self.fileoff:#x}>"

class MachO:
    """slice at file offset `base`; all read offsets are relative to the slice"""
    def __init__(self, data, base):
        self.d = data; self.base = base; self.segs=[]; self.sects=[]
        self.symtab=None
        assert u32(data, base)==0xfeedfacf, hex(u32(data,base))
        self.ncmds = u32(data, base+16)
        off = base+32
        for _ in range(self.ncmds):
            cmd, sz = u32(data, off), u32(data, off+4)
            if cmd == 0x19:
                self.segs.append(Seg(data, off+8))
            elif cmd == 0x1:
                sg = bytes(data[off+8:off+24]).rstrip(b'\0').decode('latin1')
                nsects = u32(data, off+64)
                for i in range(nsects):
                    so = off+72+i*80
                    sn = bytes(data[so:so+16]).rstrip(b'\0').decode('latin1')
                    addr, size, offset = u64(data,so+32), u64(data,so+40), u32(data,so+48)
                    self.sects.append((sg, sn, addr, size, offset))
            elif cmd == 0x2:
                symoff, nsyms, stroff, strsize = struct.unpack_from('<IIII', data, off+8)
                self.symtab = (symoff, nsyms, stroff, strsize)
            off += sz
    def cstr(self, off, maxlen=4096):
        e = self.d.find(b'\0', off, off+maxlen)
        return bytes(self.d[off:e if e>=0 else off]).decode('latin1','replace')
    def read(self, va, n):
        for s in self.segs:
            if s.vmaddr <= va < s.vmaddr+s.vmsize and s.filesize:
                fo = s.fileoff + (va - s.vmaddr)
                return bytes(self.d[fo:fo+n])
        return None

class Fileset:
    def __init__(self, path=KC):
        f = open(path,'rb'); self._f = f
        self.d = mmap.mmap(f.fileno(), 0, access=mmap.ACCESS_READ)
        d = self.d
        self.entries=[]
        ncmds = u32(d, 16); off = 32
        for _ in range(ncmds):
            cmd, sz = u32(d, off), u32(d, off+4)
            if cmd == 0x80000035:
                vmaddr, fileoff = u64(d, off+8), u64(d, off+16)
                idoff = off + u32(d, off+24)
                eid = self.cstr(idoff)
                self.entries.append((eid, vmaddr, fileoff))
            off += sz
        self._m = {}
    def cstr(self, off, maxlen=512):
        e = self.d.find(b'\0', off, off+maxlen)
        return bytes(self.d[off:e]).decode('latin1','replace')
    def get(self, eid):
        if eid in self._m: return self._m[eid]
        for e, vm, fo in self.entries:
            if e == eid or e.endswith(eid):
                m = MachO(self.d, fo); self._m[eid]=m; return m
        return None
    def find(self, sub):
        return [e for e,_,_ in self.entries if sub.lower() in e.lower()]

if __name__ == '__main__':
    import sys
    fs = Fileset()
    print(len(fs.entries), "entries")
    for e in fs.find(sys.argv[1] if len(sys.argv)>1 else 'AGX'):
        print(e)
