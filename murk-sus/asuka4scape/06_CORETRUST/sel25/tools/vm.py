#!/usr/bin/env python3
# global VA map + function starts + capstone helpers
import struct
from kc import Fileset, u32, u64

MASK = 0xFFFFFFFFFFFFFFFF

class VM:
    def __init__(self, fs):
        self.fs = fs; self.d = fs.d
        self.segs = []   # (va_start, va_end, fileoff, segname, eid)
        for eid, vm, fo in fs.entries:
            m = fs.get(eid)
            if not m: continue
            for s in m.segs:
                if s.filesize:
                    self.segs.append((s.vmaddr, s.vmaddr+s.filesize, s.fileoff, s.name, eid))
        self.segs.sort()
        self.starts = []; self._load_starts()
    def off(self, va):
        lo, hi = 0, len(self.segs)-1
        while lo <= hi:
            mid=(lo+hi)//2
            a,b,fo,nm,eid = self.segs[mid]
            if va < a: hi = mid-1
            elif va >= b: lo = mid+1
            else: return fo + (va-a)
        return None
    def read(self, va, n):
        o = self.off(va)
        if o is None or o+n > len(self.d): return None
        return bytes(self.d[o:o+n])
    def u32(self, va):
        b=self.read(va,4); return struct.unpack('<I',b)[0] if b else None
    def u64(self, va):
        b=self.read(va,8); return struct.unpack('<Q',b)[0] if b else None
    def ptr(self, va):
        v=self.u64(va)
        if v is None: return None
        if (v >> 48) == 0xffff: return v & 0x0000FFFFFFFFFFFF
        return v
    def cstr(self, va, maxlen=1024):
        o=self.off(va)
        if o is None: return None
        e=self.d.find(b'\0', o, o+maxlen)
        if e<0: e=o+maxlen
        return bytes(self.d[o:e]).decode('latin1','replace')
    def owner(self, va):
        lo,hi=0,len(self.segs)-1
        while lo<=hi:
            mid=(lo+hi)//2
            a,b,fo,nm,eid=self.segs[mid]
            if va<a: hi=mid-1
            elif va>=b: lo=mid+1
            else: return eid, nm
        return None, None
    def _load_starts(self):
        for eid, vm, fo in self.fs.entries:
            m = self.fs.get(eid)
            if not m or not m.segs: continue
            base = m.segs[0].vmaddr; d=self.d; off=fo+32
            for _ in range(m.ncmds):
                cmd, sz = u32(d, off), u32(d, off+4)
                if cmd == 0x26:
                    dataoff, datasize = struct.unpack_from('<II', d, off+8)
                    p = dataoff; cur = base
                    end = dataoff+datasize
                    while p < end:
                        v=0; shift=0
                        while True:
                            b=d[p]; p+=1; v |= (b&0x7f)<<shift; shift+=7
                            if not (b&0x80): break
                        if v==0: break
                        cur += v; self.starts.append(cur)
                off += sz
        self.starts = sorted(set(self.starts))

def disasm(vm, va, nbytes=None, count=None):
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
    md.detail = True
    if count: nbytes = count*4
    b = vm.read(va, nbytes)
    if not b: return []
    return list(md.disasm(b, va))

def branch_target(insn):
    for op in insn.operands:
        if op.type == 2:  # ARM64_OP_IMM
            return op.imm & MASK
    return None

def func_end(vm, va, maxlen=0x2000):
    """walk until ret/pacibsp+ret or next function start"""
    import bisect
    i = bisect.bisect_right(vm.starts, va)
    nxt = vm.starts[i] if i < len(vm.starts) else va+maxlen
    return min(nxt, va+maxlen)

def off2va(vm, off):
    hits=[]
    for a,b,fo,nm,eid in vm.segs:
        if fo <= off < fo+(b-a):
            hits.append((a+(off-fo), nm, eid))
    return hits
