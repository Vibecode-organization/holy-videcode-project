#!/usr/bin/env python3
# global: functions that both compare w1 with an immediate and read IOExternalMethodArguments (x2)
import struct, bisect, collections
from kc import load
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
k = load()
md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
BTI = 0xD503245F
ARGS = set(range(0x20, 0x80, 8)) | {0x28, 0x38, 0x50, 0x60, 0x04}

def scan(segname='__TEXT_EXEC', mincmp=3):
    s = k.seg_by_name[segname]
    n = s['filesize']//4
    w = struct.unpack_from('<%dI' % n, k.data, s['fileoff'])
    starts = [s['vmaddr']+i*4 for i, x in enumerate(w) if x == BTI]
    cmps = []
    for i, x in enumerate(w):
        # cmp w1, #imm
        if (x & 0xFFC0001F) == 0x7100001F and ((x >> 5) & 0x1F) == 1:
            cmps.append((s['vmaddr']+i*4, (x >> 10) & 0xFFF))
        # cmp wN, #imm where wN was... (skip)
    g = collections.defaultdict(list)
    for pc, imm in cmps:
        j = bisect.bisect_right(starts, pc)-1
        if j >= 0:
            g[starts[j]].append((pc, imm))
    out = []
    for st, hs in g.items():
        if len(hs) < mincmp: continue
        o = k.off(st)
        if o is None: continue
        ins = list(md.disasm(k.data[o:o+400*4], st))
        reads = sum(1 for i in ins if i.mnemonic in ('ldr','ldrb','ldrh','ldrsw','ldur')
                    and (i.op_str.split('[')[1].startswith('x2, #') if '[' in i.op_str else False))
        out.append((len(hs), reads, st, hs))
    out.sort(reverse=True)
    return out

if __name__ == '__main__':
    out = scan()
    for ncmp, reads, st, hs in out[:25]:
        print(f"{st:#x} cmp={ncmp} argsreads={reads} imms={[hex(i) for _, i in hs][:12]}")
