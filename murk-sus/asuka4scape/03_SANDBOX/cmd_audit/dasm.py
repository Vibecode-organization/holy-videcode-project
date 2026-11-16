#!/usr/bin/env python3
# arm64e disasm with ObjC selector-stub annotation for extracted dsc image
import sys, struct, bisect, json
from capstone import *

PATH = '/home/femboychik/work/cmd_audit/lib/ContainerManagerCommon'
SYMS = '/tmp/opencode/cm_syms.txt'
STUBMAP = '/tmp/opencode/selstubs.json'
HELPERS = '/tmp/opencode/stubs.txt'

class Image:
    def __init__(self, path=PATH):
        self.d = open(path, 'rb').read()
        ncmds = struct.unpack('<I', self.d[16:20])[0]
        off = 32
        self.segs = []
        for _ in range(ncmds):
            cmd, size = struct.unpack('<II', self.d[off:off+8])
            if cmd == 0x19:
                name = self.d[off+8:off+24].rstrip(b'\0').decode()
                va, vsz, foff, fsz = struct.unpack('<QQQQ', self.d[off+24:off+56])
                self.segs.append((name, va, vsz, foff, fsz))
            off += size
        self.syms = {}
        for line in open(SYMS):
            a, n = line.rstrip('\n').split(' ', 1)
            self.syms[int(a, 16)] = n
        self.skeys = sorted(self.syms)
        self.stubs = {}
        for k, v in json.load(open(STUBMAP)).items():
            self.stubs[int(k, 16)] = v[0]
        self.helpers = {}
        for line in open(HELPERS, errors='ignore'):
            m = line.split(': ', 1)
            if len(m) == 2 and m[0].startswith('0x'):
                try:
                    self.helpers[int(m[0], 16)] = m[1].strip()
                except ValueError:
                    pass
        self.md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
        self.md.detail = True
        self.text = self.segs[0]

    def read(self, va, n):
        for name, sva, vsz, foff, fsz in self.segs:
            if sva <= va < sva + max(vsz, fsz):
                o = foff + (va - sva)
                return self.d[o:o+n]
        return None

    def sym_at(self, va):
        i = bisect.bisect_right(self.skeys, va) - 1
        if i >= 0:
            a = self.skeys[i]
            if 0 <= va - a < 0x2000:
                return f'{self.syms[a]}+0x{va-a:x}' if va != a else self.syms[a]
        return None

    def name_at(self, va):
        s = self.sym_at(va)
        if s:
            return s
        if va in self.stubs:
            return f'objc_msgSend${self.stubs[va]}'
        if va in self.helpers:
            return self.helpers[va]
        return None

    def cstr(self, addr, maxlen=96):
        b = self.read(addr, maxlen)
        if not b:
            return None
        s = b.split(b'\0')[0]
        if len(s) < 3:
            return None
        try:
            t = s.decode('utf-8')
        except UnicodeDecodeError:
            return None
        if all(32 <= ord(c) < 127 for c in t):
            return t
        return None

    def cfstr(self, addr):
        b = self.read(addr, 32)
        if not b or len(b) < 32:
            return None
        flags, ptr, ln = struct.unpack('<QQQ', b[8:32])
        if not (0x100000000 <= ptr <= 0x300000000) or ln > 256:
            return None
        s = self.cstr(ptr, 256)
        return s

    def dis(self, va, count=60, stop_ret=True):
        code = self.read(va, count*4)
        out = []
        regs = {}
        for ins in self.md.disasm(code, va):
            line = f'{ins.address:08x}  {ins.mnemonic:<8} {ins.op_str}'
            note = None
            ops = ins.op_str
            if ins.mnemonic == 'adrp':
                a, b = [x.strip() for x in ops.split(',', 1)]
                try:
                    regs[a] = int(b.lstrip('#'), 16)
                except ValueError:
                    pass
            elif ins.mnemonic == 'add':
                parts = [x.strip() for x in ops.split(',')]
                if len(parts) == 3 and parts[1] in regs and parts[2].startswith('#'):
                    try:
                        regs[parts[0]] = regs[parts[1]] + int(parts[2][1:], 0)
                    except ValueError:
                        pass
            # annotate any register whose tracked value is a string
            for r, v in list(regs.items()):
                if 0x207f15ec0 <= v < 0x207f20000:
                    s = self.cstr(v, 64)
                    if s:
                        note = s
                        break
                if 0x26a1f0000 <= v < 0x26a220000 or 0x268360000 <= v < 0x268370000:
                    s = self.cfstr(v)
                    if s:
                        note = s
                        break
            if ins.mnemonic in ('bl', 'b', 'blraa', 'braa') and ins.op_str.startswith('#'):
                try:
                    tgt = int(ins.op_str[1:], 16)
                    nm = self.name_at(tgt)
                    if nm:
                        line += f'    ; {nm}'
                    if ins.mnemonic == 'b' and nm is None and not (self.text[1] <= tgt < self.text[1]+self.text[2]):
                        line += f'    ; -> {tgt:x}'
                except ValueError:
                    pass
            if note:
                line += f'    ; "{note}"'
            out.append(line)
            if len(out) >= count:
                break
            if stop_ret and ins.mnemonic in ('ret', 'retab'):
                break
        return '\n'.join(out)

if __name__ == '__main__':
    im = Image()
    va = int(sys.argv[1], 16)
    n = int(sys.argv[2]) if len(sys.argv) > 2 else 80
    print(im.dis(va, n))
