#!/usr/bin/env python3
# disasm helper over the kernelcache
import sys, struct
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from kc import load

k = load()
md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
md.detail = True

def seg_of(va):
    for s in k.segs:
        if s['filesize'] and s['vmaddr'] <= va < s['vmaddr']+s['filesize']:
            return s['name']
    return '?'

def insns(va, n=200, stop_ret=True):
    o = k.off(va)
    if o is None:
        return []
    out = []
    for i in md.disasm(k.data[o:o+n*4], va):
        out.append(i)
        if stop_ret and i.mnemonic in ('ret', 'retab'):
            break
    return out

def show(va, n=60, stop_ret=False, mark=None):
    for i in insns(va, n, stop_ret):
        m = ''
        if mark and i.address in mark:
            m = '   <<<< ' + mark[i.address]
        print(f"{i.address:#013x}  {i.bytes.hex():<8} {i.mnemonic:<8} {i.op_str}{m}")

def bltargets(va, n=400):
    return [i for i in insns(va, n, False) if i.mnemonic in ('bl', 'b')]

def q(va):
    b = k.rd(va, 8)
    return struct.unpack('<Q', b)[0] if b else None

def dmpq(va, cnt, base=None):
    for i in range(cnt):
        v = q(va+i*8)
        s = ''
        if base is not None and v is not None:
            s = f"  -> {base + (v & 0x0FFFFFFF):#x}" if (v >> 40) else ''
            if v and 0xfffffff007004000 <= v < 0xfffffff080000000:
                s = f"  -> {v:#x}"
        print(f"{va+i*8:#013x} [{i:3d}] {v:#018x}{s}")

if __name__ == '__main__':
    a = int(sys.argv[1], 16)
    n = int(sys.argv[2],0) if len(sys.argv) > 2 else 60
    show(a, n, stop_ret=False)
