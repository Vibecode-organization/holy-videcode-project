#!/usr/bin/env python3
"""
dsc_selref.py — decode __objc_selrefs of a DSC-extracted Mach-O (iOS 26/27 format).

Why: images pulled out of the dyld shared cache (27.x) have no LC_DYLD_CHAINED_FIXUPS
and an empty __objc_methname. Their 8-byte selrefs are {u32 off; u32 tag} where
  off = offset from the DSC sharedRegionStart (0x180000000 on arm64e),
  tag = 0x00100000 for objc string references (0 for null slots).
Resolving off -> string needs the main cache header (subCacheArray) plus each
subcache's own mapping table.

Usage:
  python3 dsc_selref.py DSC_DIR IMAGE [--find rowSpan] [--dump N]

  DSC_DIR  directory holding dyld_shared_cache_arm64e and its .NN subcaches
  IMAGE    Mach-O extracted from that cache (e.g. UIFoundation)

Outputs the image's __objc_selrefs table decoded to selector strings.
Stdlib only.
"""
import argparse, os, struct, sys

TAG_OBJC = 0x00100000


def u32(b, o): return struct.unpack_from("<I", b, o)[0]
def u64(b, o): return struct.unpack_from("<Q", b, o)[0]


class Dsc:
    def __init__(self, d):
        self.dir = d
        self.main = os.path.join(d, "dyld_shared_cache_arm64e")
        head = open(self.main, "rb").read(0x1000)
        assert head[:7] == b"dyld_v1", "not a dyld shared cache"
        self.base = u64(head, 224)              # sharedRegionStart
        self.region_size = u64(head, 232)
        self.maps = [struct.unpack_from("<QQQIII", head, u32(head, 16) + i * 32)
                     for i in range(u32(head, 20))]
        self._subcache(head)
        self._map_cache = {}

    def _subcache(self, head):
        off, n = u32(head, 392), u32(head, 396)
        blob = open(self.main, "rb").read()[off:off + n * 56]
        self.subs = []
        for i in range(n):
            o = i * 56
            vm = struct.unpack_from("<Q", blob, o + 16)[0]
            suf = blob[o + 24:o + 56].split(b"\0")[0].decode()
            self.subs.append((vm, suf))

    def _maps_for(self, suf):
        if suf in self._map_cache:
            return self._map_cache[suf]
        p = os.path.join(self.dir, "dyld_shared_cache_arm64e" + suf)
        h = open(p, "rb").read(0x1000)
        m = [struct.unpack_from("<QQQIII", h, u32(h, 16) + i * 32)
             for i in range(u32(h, 20))]
        self._map_cache[suf] = (p, m)
        return self._map_cache[suf]

    def locate(self, va):
        off = va - self.base
        for i, (vm, suf) in enumerate(self.subs):
            nxt = self.subs[i + 1][0] if i + 1 < len(self.subs) else self.region_size
            if vm <= off < nxt:
                p, maps = self._maps_for(suf)
                for mva, msz, mfo, prot, pad, _ in maps:
                    if mva <= va < mva + msz:
                        return p, mfo + (va - mva)
        return None, None

    def read(self, va, n=128):
        p, fo = self.locate(va)
        if not p:
            return None
        with open(p, "rb") as f:
            f.seek(fo)
            return f.read(n)

    def cstr(self, va):
        b = self.read(va, 128)
        return b.split(b"\0")[0].decode("utf-8", "replace") if b else None

    def selrefs(self, macho):
        data = open(macho, "rb").read()
        ncmds = u32(data, 16)
        o, out = 32, []
        for _ in range(ncmds):
            cmd, sz = struct.unpack_from("<II", data, o)
            if cmd == 0x19:  # LC_SEGMENT_64
                ns = u32(data, o + 64)
                so = o + 72
                for _ in range(ns):
                    sn = data[so:so + 16].split(b"\0")[0].decode()
                    addr, size, off, _a, _r, _n, _f = struct.unpack_from("<QQIIIII", data, so + 32)
                    if sn == "__objc_selrefs":
                        out.append((addr, size, off, data[off:off + size]))
                    so += 80
            o += sz
        return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("dsc_dir")
    ap.add_argument("image")
    ap.add_argument("--find", default=None, help="print only slots whose selector == this string")
    ap.add_argument("--dump", type=int, default=0, help="print first N decoded slots")
    a = ap.parse_args()

    dsc = Dsc(a.dsc_dir)
    secs = dsc.selrefs(a.image)
    if not secs:
        sys.exit("no __objc_selrefs in image")
    addr, size, off, blob = secs[0]
    n = size // 8
    hits = 0
    for i in range(n):
        lo, tg = struct.unpack_from("<II", blob, i * 8)
        if tg != TAG_OBJC:
            continue
        name = dsc.cstr(dsc.base + lo)
        if a.find:
            if name == a.find:
                print(f"{name}\tslot=0x{addr + i * 8:x}\tsel=0x{lo:x}")
                hits += 1
        elif i < a.dump:
            print(f"slot {addr + i * 8:#x} tag={tg:#x} -> {name}")
    if a.find and not hits:
        print(f"(no selref equal to {a.find!r})")


if __name__ == "__main__":
    main()
