#!/usr/bin/env python3
# Build function index in __TEXT_EXEC and compute call graphs for all syscall handlers.
import re, sys, json, struct
from mo import MachO, md
from capstone import CS_OP_IMM

m = MachO()

COPYOUT = 0xfffffff00a38a690
COPYIN  = 0xfffffff00a389b14
TEXEC_START = None
TEXEC_END = None
for s in m.segments:
    if s['name'] == '__TEXT_EXEC':
        TEXEC_START = s['vmaddr']; TEXEC_END = s['vmaddr']+s['vmsize']

print('TEXT_EXEC %x-%x' % (TEXEC_START, TEXEC_END), file=sys.stderr)

# scan for pacibsp and bti c at instruction boundaries
starts = []
data = m.data
off = m.va2off(TEXEC_START)
n = TEXEC_END - TEXEC_START
buf = data[off:off+n]
for i in range(0, n-4, 4):
    w = struct.unpack_from('<I', buf, i)[0]
    # pacibsp = 0xD503237F, paciasp = 0xD503235F, bti c = 0xD503245F
    if w in (0xD503237F, 0xD503235F, 0xD503245F):
        starts.append(TEXEC_START + i)
starts = sorted(set(starts))
print('function candidates:', len(starts), file=sys.stderr)

import bisect
def func_end(va):
    i = bisect.bisect_right(starts, va)
    if i < len(starts):
        return min(starts[i], va + 0x8000)
    return va + 0x8000

def body(va):
    return m.read(va, func_end(va)-va)

def calls(va):
    out = []
    b = body(va)
    if not b: return out
    for ins in md.disasm(b, va):
        if ins.mnemonic in ('bl','b') and len(ins.operands)==1 and ins.operands[0].type == CS_OP_IMM:
            t = ins.operands[0].imm & 0xffffffffffffffff
            out.append((ins.address, t, ins.mnemonic))
    return out

def istart(va):
    i = bisect.bisect_left(starts, va)
    return i if i < len(starts) and starts[i] == va else None
