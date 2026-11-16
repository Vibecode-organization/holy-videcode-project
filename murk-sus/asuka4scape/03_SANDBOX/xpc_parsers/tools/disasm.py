#!/usr/bin/env python3
"""Annotated arm64 disassembly for Mach-O. Resolves adrp/add -> cstring, bl -> symbol."""
import struct, sys, re, subprocess, bisect
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from capstone.arm64 import ARM64_OP_REG, ARM64_OP_IMM, ARM64_OP_MEM

LC_SEGMENT_64 = 0x19
LC_SYMTAB = 0x2

FIX_RE = re.compile(r'^0x([0-9a-f]+):\s+raw:\s+0x([0-9a-f]+)\s+(\S+?):\s*(.*)$')
TGT_RE = re.compile(r'target:\s*0x([0-9a-f]+)')


class Bin:
    def __init__(self, path, fixups=True):
        self.d = open(path, 'rb').read()
        self.path = path
        magic, cpu, sub, ftype, ncmds, sizeofcmds, flags, rsv = struct.unpack_from('<IiiIIIII', self.d, 0)
        self.segs, self.sects = [], {}
        self.symoff = self.nsyms = self.stroff = self.strsize = 0
        self.func_starts = []
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
        self.syms = {}
        self._load_syms()
        self.fix = {}
        if fixups:
            self.fix = self._build_fixups()
        self._load_func_starts()
        try:
            from stubs import load as _load_stubs
            self.stubs = _load_stubs(self)
        except Exception:
            self.stubs = {}

    def _load_syms(self):
        if not self.symoff: return
        o = self.symoff
        for i in range(self.nsyms):
            strx, ntype, nsect, ndesc, nval = struct.unpack_from('<IBBHQ', self.d, o + i*16)
            if strx == 0: continue
            so = self.stroff + strx
            e = self.d.find(b'\0', so)
            nm = self.d[so:e].decode('utf-8', 'replace')
            if ntype & 1:  # N_EXT
                self.syms.setdefault(nval, nm)

    def _load_func_starts(self):
        # parse LC_FUNCTION_STARTS via the ULEB delta encoding
        # quick approach: scan load commands again
        ncmds = struct.unpack_from('<I', self.d, 16)[0]
        off = 32
        for _ in range(ncmds):
            cmd, cmdsize = struct.unpack_from('<II', self.d, off)
            if cmd == 0x26:  # LC_FUNCTION_STARTS
                dataoff, datasize = struct.unpack_from('<II', self.d, off+8)
                if datasize:
                    p = dataoff; end = dataoff+datasize
                    addr = self.base
                    while p < end:
                        val = 0; shift = 0
                        while True:
                            b = self.d[p]; p += 1
                            val |= (b & 0x7f) << shift
                            shift += 7
                            if not (b & 0x80): break
                        if val == 0: break
                        addr += val
                        self.func_starts.append(addr)
            off += cmdsize

    def _build_fixups(self):
        out = subprocess.run(['ipsw', 'macho', 'info', '-u', self.path],
                             capture_output=True, text=True).stdout
        m = {}
        for line in out.splitlines():
            mt = FIX_RE.match(line)
            if not mt: continue
            addr = int(mt.group(1), 16)
            kind, rest = mt.group(3), mt.group(4)
            tg = TGT_RE.search(rest)
            if 'rebase' in kind and tg:
                m[addr] = int(tg.group(1), 16)
            elif 'bind' in kind:
                m[addr] = rest.split(')\t')[-1].strip() if ')' in rest else ''
        return m

    def off(self, addr):
        for name, vmaddr, vmsize, fileoff, filesize in self.segs:
            if vmaddr <= addr < vmaddr + filesize:
                return fileoff + (addr - vmaddr)
        return None

    def read(self, addr, n):
        o = self.off(addr)
        return self.d[o:o+n] if o is not None else b''

    def cstr(self, addr):
        o = self.off(addr)
        if o is None: return None
        e = self.d.find(b'\0', o)
        if e < 0 or e - o > 400: return None
        s = self.d[o:e]
        try: return s.decode('utf-8')
        except UnicodeDecodeError: return None

    def name_at(self, addr):
        if addr in self.syms: return self.syms[addr]
        i = bisect.bisect_right(self.func_starts, addr) - 1
        if i >= 0 and addr - self.func_starts[i] < 0x4000 and addr in self.func_starts:
            return f"sub_{addr:x}"
        return None

    def fmt_near(self, addr):
        n = self.name_at(addr)
        return f"{n}+0x{addr-addr:x}" if n else f"0x{addr:x}"


def annotate_bin(b, start, count, base_addr=None, show_syms=True):
    text = None
    for addr, size, foff in b.sects.get('__text', []) + b.sects.get('__objc_stubs', []) + b.sects.get('__auth_stubs', []):
        if base_addr is None or addr <= base_addr < addr+size:
            text = (addr, size, foff)
            break
    if text is None:
        return []
    seg_addr, seg_size, seg_off = text
    if base_addr is None: base_addr = seg_addr
    off = seg_off + (base_addr - seg_addr)
    code = b.d[off:off + count*4 + 64]
    md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    md.detail = True
    insns = list(md.disasm(code, base_addr))
    # pass 1: resolve adrp+add/ldr pairs within 2 instructions
    cmt = {}
    for i, ins in enumerate(insns):
        if ins.mnemonic != 'adrp' or not ins.operands: continue
        reg = ins.op_str.split(',')[0].strip()
        page = ins.operands[1].imm
        for j in range(i+1, min(i+3, len(insns))):
            n = insns[j]
            dst = n.op_str.split(',')[0].strip()
            if dst != reg:
                if reg in n.op_str: break
                continue
            tgt = None
            if n.mnemonic == 'add' and '#' in n.op_str:
                try: tgt = page + int(n.op_str.split('#')[-1], 0)
                except ValueError: pass
            elif n.mnemonic in ('ldr', 'ldrb', 'ldrh', 'ldrsw') and '[' in n.op_str and '#' in n.op_str:
                try: tgt = page + int(n.op_str.split('#')[-1].rstrip(']'), 0)
                except ValueError: pass
            if tgt is not None:
                fx = b.fix.get(tgt) if hasattr(b, 'fix') else None
                if isinstance(fx, str) and fx:
                    cmt[j] = f'-> {fx}'
                elif isinstance(fx, int):
                    ss = b.cstr(fx)
                    cmt[j] = f'-> 0x{fx:x}' + (f' "{ss}"' if ss else '')
                else:
                    ss = b.cstr(tgt)
                    if ss and all(32 <= ord(ch) < 127 for ch in ss):
                        cmt[j] = f'"{ss}"'
                    else:
                        cmt[j] = f'@0x{tgt:x}'
            break
    # pass 2: branch targets
    for i, ins in enumerate(insns):
        if ins.mnemonic in ('b', 'bl', 'cbz', 'cbnz', 'tbz', 'tbnz') or ins.mnemonic.startswith('b.'):
            ops = ins.operands
            if ops and ops[-1].type == ARM64_OP_IMM:
                t = ops[-1].imm
                n = b.name_at(t) if show_syms else None
                if n is None and t in getattr(b, 'stubs', {}):
                    n = b.stubs[t]
                if n: cmt[i] = n
        for c in cmt.values(): pass
    for i, ins in enumerate(insns):
        if i in cmt:
            ins._cmt = cmt[i]
    return insns


def main():
    path = sys.argv[1]
    start = None; count = 200
    for i, a in enumerate(sys.argv):
        if a == '-a': start = int(sys.argv[i+1], 0)
        if a == '-c': count = int(sys.argv[i+1], 0)
    b = Bin(path)
    insns = annotate_bin(b, start, count, start)
    for ins in insns:
        c = getattr(ins, '_cmt', '')
        print(f"0x{ins.address:x}:  {ins.mnemonic}\t{ins.op_str}" + (f"\t; {c}" if c else ''))

if __name__ == '__main__':
    main()
