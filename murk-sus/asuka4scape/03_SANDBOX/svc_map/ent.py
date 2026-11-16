#!/usr/bin/env python3
# pull entitlements + code-signature layout out of a Mach-O by hand (ldid prints empty on 27.x blobs)
import struct, sys, json

LC_CODE_SIGNATURE = 0x1d


def macho(path):
    b = open(path, 'rb').read()
    magic = b[:4]
    e = '<' if magic in (b'\xcf\xfa\xed\xfe', b'\xce\xfa\xed\xfe') else '>'
    is64 = magic in (b'\xcf\xfa\xed\xfe', b'\xfe\xed\xfa\xcf')
    u32 = lambda o: struct.unpack_from(e + 'I', b, o)[0]
    if u32(0) not in (0xfeedfacf, 0xfeedface):
        return None
    ncmds = u32(16)
    off = 32 if is64 else 28
    cs = None
    segs = []
    for _ in range(ncmds):
        cmd, sz = u32(off), u32(off + 4)
        if cmd == LC_CODE_SIGNATURE:
            cs = (u32(off + 8), u32(off + 12))
        if cmd in (0x19, 0x1):
            segname = b[off + 8:off + 24].rstrip(b'\x00').decode()
            fileoff, filesize = u32(off + 32), u32(off + 36)
            segs.append((segname, fileoff, filesize))
        if sz == 0:
            break
        off += sz
    return b, cs, segs, e


def blobs(sig, e):
    u32 = lambda o: struct.unpack_from('>I', sig, o)[0]  # CS blobs are always big-endian
    magic, length, count = u32(0), u32(4), u32(8)
    out = {}
    for i in range(count):
        o = 12 + i * 8
        typ, boff = u32(o), u32(o + 4)
        if boff + 8 > len(sig):
            continue
        blen = u32(boff + 4)
        out.setdefault(typ, []).append(sig[boff:boff + blen])
    return out


def main(path):
    b, cs, segs, e = macho(path)
    if not cs:
        print('no LC_CODE_SIGNATURE')
        return
    sig = b[cs[0]:cs[0] + cs[1]]
    bl = blobs(sig, e)
    xml = ''.join(x.decode('utf-8', 'replace') for x in bl.get(5, [])).replace('\x00', '')
    if xml.strip():
        print(xml)
    else:
        print('XML: none; sig blob types=%s' % ({k: len(v) for k, v in sorted(bl.items())}))
    # text segment for __entitlements section scan
    txt = [s for s in segs if s[0] == '__TEXT']
    if txt:
        seg = b[txt[0][1]:txt[0][1] + txt[0][2]]
        import re
        toks = sorted(set(re.findall(rb'[a-z0-9.\-]{6,120}', seg)))
        print('text-seg tokens: %d' % len(toks))


if __name__ == '__main__':
    main(sys.argv[1])
