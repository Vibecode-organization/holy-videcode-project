#!/usr/bin/env python3
# Mach-O helper: parse segments, symbols, VA<->offset, capstone disassembly of functions.
import struct, sys, subprocess
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM, CS_OP_IMM, CS_OP_REG, CS_OP_MEM

KC = '/home/femboychik/work/kc272/24B119__iPhone14,7/kernelcache.release.iPhone14,7'

class MachO:
    def __init__(self, path=KC):
        self.path = path
        self.data = open(path, 'rb').read()
        magic, cputype, cpusub, ftype, ncmds, sizeofcmds, flags, res = struct.unpack_from('<IiiIIIII', self.data, 0)
        assert magic == 0xfeedfacf
        self.segments = []
        self.sections = []
        self.symtab = None
        off = 32
        for _ in range(ncmds):
            cmd, cmdsize = struct.unpack_from('<II', self.data, off)
            if cmd == 0x19:  # LC_SEGMENT_64
                segname = self.data[off+8:off+24].rstrip(b'\0').decode()
                vmaddr, vmsize, fileoff, filesize, maxprot, initprot, nsects, sflags = struct.unpack_from('<QQQQIIII', self.data, off+24)
                self.segments.append(dict(name=segname, vmaddr=vmaddr, vmsize=vmsize, fileoff=fileoff, filesize=filesize, maxprot=maxprot, initprot=initprot))
                soff = off + 72
                for i in range(nsects):
                    sectname = self.data[soff:soff+16].rstrip(b'\0').decode()
                    segname2 = self.data[soff+16:soff+32].rstrip(b'\0').decode()
                    addr, size, offset, align, reloff, nreloc, sflags2, r1, r2, r3 = struct.unpack_from('<QQIIIIIIII', self.data, soff)
                    self.sections.append(dict(name=sectname, seg=segname2, addr=addr, size=size, offset=offset))
                    soff += 80
            elif cmd == 0x2:  # LC_SYMTAB
                symoff, nsyms, stroff, strsize = struct.unpack_from('<IIII', self.data, off+8)
                self.symtab = dict(symoff=symoff, nsyms=nsyms, stroff=stroff, strsize=strsize)
            off += cmdsize
        self._build_syms()

    def _build_syms(self):
        self.syms = {}
        self.symlist = []
        if not self.symtab:
            return
        st = self.symtab
        for i in range(st['nsyms']):
            o = st['symoff'] + i*16
            strx, ntype, nsect, ndesc, nvalue = struct.unpack_from('<IBBHQ', self.data, o)
            name_off = st['stroff'] + strx
            end = self.data.find(b'\0', name_off)
            name = self.data[name_off:end].decode('utf-8', 'replace')
            self.symlist.append((name, nvalue, ntype, nsect))
            if nvalue and ntype & 0x0e == 0x0e:  # N_SECT
                self.syms.setdefault(name, nvalue)

    def va2off(self, va):
        for s in self.segments:
            if s['vmaddr'] <= va < s['vmaddr']+s['vmsize']:
                delta = va - s['vmaddr']
                if delta < s['filesize']:
                    return s['fileoff'] + delta
        return None

    def off2va(self, off):
        for s in self.segments:
            if s['fileoff'] <= off < s['fileoff']+s['filesize']:
                return s['vmaddr'] + (off - s['fileoff'])
        return None

    def read(self, va, n):
        o = self.va2off(va)
        if o is None: return None
        return self.data[o:o+n]

    def find_sym(self, substr, exact=False):
        if exact:
            return self.syms.get(substr)
        for n,v in self.syms.items():
            if substr in n:
                return v
        return None

    def all_syms(self, substr):
        return [(n,v) for n,v in self.syms.items() if substr in n]

md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
md.detail = True

def disas(m, va, maxbytes=0x400, stop_ret=True):
    code = m.read(va, maxbytes)
    out = []
    for ins in md.disasm(code, va):
        out.append(ins)
        if stop_ret and ins.mnemonic in ('ret','brk','b') and ins.mnemonic!='b':
            break
    return out

def call_target(ins):
    if ins.mnemonic in ('bl','b') and len(ins.operands)==1 and ins.operands[0].type==CS_OP_IMM:
        return ins.operands[0].imm & 0xffffffffffffffff
    return None

if __name__ == '__main__':
    m = MachO()
    print('segments:')
    for s in m.segments:
        print('  %-18s %016x size %08x fileoff %08x filesize %08x' % (s['name'], s['vmaddr'], s['vmsize'], s['fileoff'], s['filesize']))
    print('symtab:', m.symtab, 'syms:', len(m.syms))
    for nm in ['copyout','copyin','_copyout','memcpy','bcopy','kdebug_trace','printf']:
        print(nm, [hex(v) for n,v in m.all_syms(nm)][:8])
