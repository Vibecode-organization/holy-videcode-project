# robust va->file mapping for the 27.2 kernelcache (kc.py bisect is unreliable on this image)
import struct, bisect
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
import kc as _kc

KC = "/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache"
BASE = 0xfffffff007004000

with open(KC, 'rb') as f:
    D = f.read()

k = _kc.load()

_s = []
for s in k.segs:
    if s['filesize'] and s['vmsize']:
        _s.append((s['vmaddr'], s['vmaddr'] + s['filesize'], s['fileoff'], s['name']))
_s.sort()
_lo = [x[0] for x in _s]

md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
md.detail = True


def foff(va):
    i = bisect.bisect_right(_lo, va) - 1
    while i >= 0:
        lo, hi, fo, nm = _s[i]
        if lo <= va < hi:
            return fo + (va - lo)
        i -= 1
    return None


def rd(va, n):
    o = foff(va)
    if o is None or o + n > len(D):
        return None
    return D[o:o + n]


def u32(va):
    b = rd(va, 4)
    return struct.unpack('<I', b)[0] if b else None


def u64(va):
    b = rd(va, 8)
    return struct.unpack('<Q', b)[0] if b else None


def cstr(va, n=200):
    b = rd(va, n)
    if not b:
        return None
    z = b.find(b'\0')
    return b[:z].decode('utf-8', 'replace') if z >= 0 else None


def pac(q):
    return BASE + (q & 0x0FFFFFFF)


def dis(va, n=0x200, stopret=True):
    o = foff(va)
    if o is None:
        return []
    out = []
    for i in md.disasm(D[o:o + n], va):
        out.append(i)
        if stopret and i.mnemonic in ('ret', 'retab'):
            break
    return out


def fmt(i):
    return "%#012x  %-7s %s" % (i.address, i.mnemonic, i.op_str)


def show(va, n=0x200, stopret=True):
    for i in dis(va, n, stopret):
        print(fmt(i))
