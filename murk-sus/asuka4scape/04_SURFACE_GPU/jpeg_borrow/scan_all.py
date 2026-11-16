#!/usr/bin/env python3
# scan_all.py <kernelcache> <out.json>  -- raw A64 word scan for field +0x4c8
import struct, json, sys, bisect, os
from array import array

KC = sys.argv[1]; OUT = sys.argv[2]
BASE = 0xfffffff007004000
D = open(KC, 'rb').read()

ncmds = struct.unpack_from('<I', D, 16)[0]
off = 32; TOP = []
for _ in range(ncmds):
    cmd, cs = struct.unpack_from('<II', D, off)
    if cmd == 0x19:
        nm = D[off+8:off+24].rstrip(b'\0').decode()
        va, vs, fo, fs = struct.unpack_from('<QQQQ', D, off+24)
        TOP.append((nm, va, vs, fo, fs))
    off += cs

pre = json.load(open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'prelink.json')))
def U(x):
    v = int(x) if isinstance(x, str) else x
    return v & 0xFFFFFFFFFFFFFFFF
segs = []
for d in pre:
    la = d.get('_PrelinkExecutableLoadAddr')
    if la is None: continue
    la = U(la); o = la - BASE
    if o < 0 or o + 4 > len(D) or D[o:o+4] != b'\xcf\xfa\xed\xfe': continue
    n = struct.unpack_from('<I', D, o+16)[0]; p = o + 32
    for _ in range(n):
        c, cs = struct.unpack_from('<II', D, p)
        if c == 0x19:
            nm = D[p+8:p+24].rstrip(b'\0').decode()
            v, vs, f, fs = struct.unpack_from('<QQQQ', D, p+24)
            if fs: segs.append((v, v+fs, d.get("CFBundleIdentifier"), nm, f))
        p += cs
segs.sort(); starts = [s[0] for s in segs]
def kext_at(va):
    i = bisect.bisect_right(starts, va) - 1
    if i >= 0 and segs[i][0] <= va < segs[i][1]: return segs[i][2]
    return None

hits = []
def emit(va, kind, detail):
    hits.append((va, kind, detail, kext_at(va)))

LDST = {0xF9400000:('ldr64',8),0xF9000000:('str64',8),0xB9400000:('ldr32',4),0xB9000000:('str32',4),
        0x39400000:('ldrb',1),0x39000000:('strb',1),0x79400000:('ldrh',2),0x79000000:('strh',2),0xF9800000:('ldrsw',4)}
PAIR = {0xA9000000:('stp64',8),0xA9400000:('ldp64',8),0x29000000:('stp32',4),0x29400000:('ldp32',4),
        0xA9800000:('stp64pre',8),0xA9C00000:('ldp64pre',8),0xA8800000:('stp64post',8),0xA8C00000:('ldp64post',8),
        0x29800000:('stp32pre',4),0x29C00000:('ldp32pre',4),0x28800000:('stp32post',4),0x28C00000:('ldp32post',4)}

for nm, vbase, vsize, fbase, fsize in TOP:
    if nm not in ('__TEXT_EXEC', '__TEXT', '__PRELINK_TEXT'): continue
    a = array('I'); a.frombytes(D[fbase:fbase+(fsize//4)*4])
    for i, w in enumerate(a):
        va = vbase + i*4
        op = w & 0xFFC00000
        if op in LDST and ((w >> 10) & 0xFFF)*LDST[op][1] == 0x4c8:
            emit(va, LDST[op][0], 'rt=x%d rn=x%d' % ((w>>5)&31, w&31))
        elif (w & 0x7F000000) == 0x11000000 and ((w >> 10) & 0xFFF) == 0x4c8 and ((w>>22)&1) == 0:
            emit(va, 'addX' if (w>>31)&1 else 'addW', 'rd=x%d rn=x%d' % (w&31, (w>>5)&31))
        elif (w & 0x7F800000) in (0x52800000, 0xD2800000) and ((w >> 5) & 0xFFFF) == 0x4c8:
            emit(va, 'movzX' if (w>>31)&1 else 'movzW', 'rd=x%d' % (w & 31))
        elif op in PAIR and ((w >> 15) & 0x7F)*PAIR[op][1] == 0x4c8:
            emit(va, PAIR[op][0], 'rt=x%d rt2=x%d rn=x%d' % (w&31,(w>>10)&31,(w>>5)&31))

json.dump(hits, open(OUT, 'w'))
from collections import Counter
c = Counter(h[3] for h in hits)
print(len(hits), 'hits')
for k, n in c.most_common(50):
    print('%5d  %s' % (n, k))
