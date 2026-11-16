#!/usr/bin/env python3
# language: Python, file: macho.py, target: iOS 27.2 arm64e kernelcache
# Thin Mach-O reader: segments/sections, VA<->file offset, fat slice.
import struct, sys

PATH = "/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache"
BASE = 0xfffffff007004000
DCONST_BASE = 0xfffffff007bb8000
DCONST_OFF = 0xbb4000

def load(path=PATH):
    data = open(path, "rb").read()
    # fat?
    magic = struct.unpack_from("<I", data, 0)[0]
    if magic in (0xcafebabe, 0xbebafeca):
        n = struct.unpack_from(">I", data, 4)[0]
        for i in range(n):
            off = 8 + i*20
            cpu, sub, foff, size, align = struct.unpack_from(">iiIII", data, off)
            if cpu == 0x0100000c:
                data = data[foff:foff+size]
                break
    assert struct.unpack_from("<I", data, 0)[0] == 0xfeedfacf, "not MH_MAGIC_64"
    ncmds = struct.unpack_from("<I", data, 16)[0]
    p = 32
    segs = []
    for _ in range(ncmds):
        cmd, cmdsize = struct.unpack_from("<II", data, p)
        if cmd == 0x19:  # LC_SEGMENT_64
            name = data[p+8:p+24].rstrip(b"\0").decode()
            vmaddr, vmsize, fileoff, filesize = struct.unpack_from("<QQQQ", data, p+24)
            nsects = struct.unpack_from("<I", data, p+64)[0]
            secs = []
            sp = p + 72
            for _ in range(nsects):
                sname = data[sp:sp+16].rstrip(b"\0").decode()
                sseg = data[sp+16:sp+32].rstrip(b"\0").decode()
                addr, size, off = struct.unpack_from("<QQI", data, sp+32)
                secs.append((sname, addr, size, off))
                sp += 80
            segs.append((name, vmaddr, vmsize, fileoff, filesize, secs))
        p += cmdsize
    return data, segs

def va_to_off(va):
    return va - BASE

def off_to_va(off):
    return off + BASE

if __name__ == "__main__":
    data, segs = load()
    print("len", hex(len(data)))
    for name, vmaddr, vmsize, fileoff, filesize, secs in segs:
        print(f"{name:16s} va={vmaddr:#x} size={vmsize:#x} off={fileoff:#x} fsize={filesize:#x}")
        for s in secs:
            if s[0] in ("__text", "__const", "__data", "__cstring", "__oslogstring"):
                print(f"    {s[0]:20s} va={s[1]:#x} size={s[2]:#x} off={s[3]:#x}")
