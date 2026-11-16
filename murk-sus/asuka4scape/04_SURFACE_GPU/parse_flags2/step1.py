#!/usr/bin/env python3
import struct, sys

KC = "/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache"
BASE = 0xfffffff007004000
data = open(KC,'rb').read()

SECTIONS = {
 '__TEXT':          (0xfffffff007004000, 0x8000,    0x0),
 '__PRELINK_TEXT':  (0xfffffff00700c000, 0xbac000,  0x8000),
 '__DATA_CONST':    (0xfffffff007bb8000, 0x548000,  0xbb4000),
 '__DATA_SPTM':     (0xfffffff008100000, 0x4c000,   0x10fc000),
 '__TEXT_EXEC':     (0xfffffff00814c000, 0x2924000, 0x1148000),
 '__TEXT_BOOT_EXEC':(0xfffffff00aa70000, 0x8000,    0x3a6c000),
 '__PRELINK_INFO':  (0xfffffff00aa78000, 0x23c000,  0x3a74000),
 '__DATA':          (0xfffffff00acb4000, 0x2b8000,  0x3cb0000),
 '__LINKEDIT':      (0xfffffff00af6c000, 0xb8000,   0x3f68000),
}

def off2va(off):
    for n,(va,sz,fo) in SECTIONS.items():
        if fo <= off < fo+sz:
            return va + (off-fo), n
    return None, None

def decode(q):
    if (q>>32) & 0xFFFFFFFF == 0x8050bcad:
        return BASE + (q & 0x0FFFFFFF)
    return None

targets = {
 0xfffffff008fd1088: 'setter_122',
 0xfffffff008fd1700: 'setter_127',
}

hits = {k:[] for k in targets}
# scan DATA_CONST and DATA and PRELINK_INFO
for sec in ('__DATA_CONST','__DATA','__PRELINK_INFO','__DATA_SPTM'):
    va,sz,fo = SECTIONS[sec]
    blob = data[fo:fo+sz]
    for i in range(0, len(blob)-8, 8):
        q = struct.unpack_from('<Q', blob, i)[0]
        d = decode(q)
        if d in targets:
            hits[d].append((va+i, sec, q))

out = []
for t,name in targets.items():
    out.append(f"== {name} target VA 0x{t:x} ==")
    for a,sec,q in hits[t]:
        out.append(f"  slot 0x{a:x}  ({sec})  raw=0x{q:016x}")
    out.append(f"  total {len(hits[t])}")
    out.append("")
# also raw (non-PAC) pointers
rawhits = {k:[] for k in targets}
for sec in ('__DATA_CONST','__DATA'):
    va,sz,fo = SECTIONS[sec]
    blob = data[fo:fo+sz]
    for i in range(0, len(blob)-8, 8):
        q = struct.unpack_from('<Q', blob, i)[0]
        if q in targets:
            rawhits[q].append((va+i,sec))
for t,name in targets.items():
    out.append(f"== {name} raw(no-PAC) ==")
    for a,sec in rawhits[t]:
        out.append(f"  slot 0x{a:x} ({sec})")
    out.append(f"  total {len(rawhits[t])}")
print("\n".join(out))
