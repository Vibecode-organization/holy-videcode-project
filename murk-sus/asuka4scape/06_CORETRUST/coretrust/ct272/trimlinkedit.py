#!/usr/bin/env python3
"""Strip the shared __LINKEDIT payload from an extracted cache Mach-O for fast Ghidra loads.

Keeps segments/sections and all non-linkedit data. Zeroes linkedit-referencing load
command payloads so nothing points past EOF.
"""
import sys, struct

LC_SEGMENT_64 = 0x19
ZERO_CMDS = {
    0x2,          # LC_SYMTAB
    0xb,          # LC_DYSYMTAB
    0x1d,         # LC_CODE_SIGNATURE
    0x1e,         # LC_SEGMENT_SPLIT_INFO
    0x22,         # LC_DYLD_INFO
    0x26,         # LC_FUNCTION_STARTS
    0x29,         # LC_DATA_IN_CODE
    0x2b,         # LC_DYLIB_CODE_SIGN_DRS
    0x2e,         # LC_LINKER_OPTIMIZATION_HINT
    0x80000022,   # LC_DYLD_INFO_ONLY
    0x80000033,   # LC_DYLD_EXPORTS_TRIE
    0x80000034,   # LC_DYLD_CHAINED_FIXUPS
}


def main(src, dst):
    d = bytearray(open(src, "rb").read())
    magic, cputype, cpusub, ftype, ncmds, sizeofcmds, flags, _ = struct.unpack_from("<IiiIIIII", d, 0)
    assert magic == 0xFEEDFACF, hex(magic)
    p = 32
    end = 32 + sizeofcmds
    segs = []
    for _ in range(ncmds):
        cmd, csize = struct.unpack_from("<II", d, p)
        if cmd == LC_SEGMENT_64:
            name = d[p + 8:p + 24].split(b"\0")[0].decode()
            vmaddr, vmsize, fileoff, filesize = struct.unpack_from("<QQQQ", d, p + 24)
            segs.append((name, p, vmaddr, vmsize, fileoff, filesize))
        elif cmd in ZERO_CMDS:
            # zero the payload fields after cmd/cmdsize
            for off in range(p + 8, p + csize):
                d[off] = 0
        p += csize

    keep = 0
    for name, off, vmaddr, vmsize, fileoff, filesize in segs:
        if name == "__LINKEDIT":
            struct.pack_into("<QQ", d, off + 32, 0, 0)   # fileoff, filesize
            struct.pack_into("<Q", d, off + 24, 0)       # vmsize
            continue
        keep = max(keep, fileoff + filesize)
    keep = (keep + 0x3fff) & ~0x3fff
    open(dst, "wb").write(d[:keep])
    print(f"wrote {dst} {keep} bytes (was {len(d)})")


if __name__ == "__main__":
    main(sys.argv[1], sys.argv[2])
