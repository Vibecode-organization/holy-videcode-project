#!/usr/bin/env python3
"""Compact an extracted cache Mach-O: place segments back-to-back at 0x4000 alignment.

Keeps every vmaddr, drops the shared __LINKEDIT payload, and zeroes load commands
that would otherwise point past EOF.
"""
import sys, struct

LC_SEGMENT_64 = 0x19
ZERO_CMDS = {
    0x2, 0xb, 0x1d, 0x1e, 0x22, 0x26, 0x29, 0x2b, 0x2e,
    0x80000022, 0x80000033, 0x80000034,
}


def main(src, dst):
    d = bytearray(open(src, "rb").read())
    magic, cputype, cpusub, ftype, ncmds, sizeofcmds, flags, _ = struct.unpack_from("<IiiIIIII", d, 0)
    assert magic == 0xFEEDFACF, hex(magic)
    p, end = 32, 32 + sizeofcmds
    segs = []
    for _ in range(ncmds):
        cmd, csize = struct.unpack_from("<II", d, p)
        if cmd == LC_SEGMENT_64:
            name = d[p + 8:p + 24].split(b"\0")[0].decode()
            vmaddr, vmsize, fileoff, filesize = struct.unpack_from("<QQQQ", d, p + 24)
            segs.append([name, p, vmaddr, vmsize, fileoff, filesize])
        elif cmd in ZERO_CMDS:
            for off in range(p + 8, p + csize):
                d[off] = 0
        p += csize

    out = bytearray()
    out.extend(d[:end])          # header + commands, patched below
    cursor = (end + 0x3fff) & ~0x3fff
    for s in segs:
        name, off, vmaddr, vmsize, fileoff, filesize = s
        if name == "__LINKEDIT":
            struct.pack_into("<Q", d, off + 24, 0)
            struct.pack_into("<QQ", d, off + 32, 0, 0)
            continue
        if filesize == 0:
            continue
        new_off = cursor
        chunk = d[fileoff:fileoff + filesize]
        if len(chunk) < filesize:
            chunk += b"\0" * (filesize - len(chunk))
        if len(out) < new_off:
            out.extend(b"\0" * (new_off - len(out)))
        out.extend(chunk)
        cursor = len(out)
        struct.pack_into("<Q", d, off + 32, new_off)
        s[4] = new_off

    out[0:end] = d[0:end]
    open(dst, "wb").write(out)
    print(f"wrote {dst} {len(out)} bytes")
    for s in segs:
        print(f"  {s[0]:<16} vm={s[2]:#x} vsize={s[3]:#x} new_off={s[4]:#x} fsize={s[5]:#x}")


if __name__ == "__main__":
    main(sys.argv[1], sys.argv[2])
