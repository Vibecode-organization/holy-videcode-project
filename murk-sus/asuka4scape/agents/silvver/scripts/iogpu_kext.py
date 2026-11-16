#!/usr/bin/env python3
"""
iogpu_kext.py - static extractor for the embedded IOGPUFamily kext in the
iOS 27.2 (24B115) kernelcache.

Answers four questions without Ghidra:
  1. where the kext lives in the kernelcache (fileset entry, own segments);
  2. which functions exist (LC_FUNCTION_STARTS -> 2004 entries);
  3. which object types it allocates and how big they are (__DATA_CONST,
     __kalloc_type / __kalloc_var - name + size per type);
  4. what every __auth_stubs trampoline actually calls (__auth_got entries
     encode the target as 0x8011_0000_<file offset of the function>).

Also dumps the IOGPUDeviceUserClient external-method table (56 selectors).

Usage:
    python3 iogpu_kext.py --kc /path/to/kernelcache          # local file
    python3 iogpu_kext.py --mcp                              # via asuka4scape hub
        (env: ASUKA_URL, ASUKA_TOKEN)

Options:
    --dump  types|funcs|dispatch|stubs|all       (default: all)
"""
import argparse, base64, json, os, struct, sys

BASE = 0xfffffff007004000
M64 = 0xFFFFFFFFFFFFFFFF

SEGS = [
    ("__TEXT",          0xfffffff007004000, 0x8000,     0x0),
    ("__PRELINK_TEXT",  0xfffffff00700c000, 0xbac000,   0x8000),
    ("__DATA_CONST",    0xfffffff007bb8000, 0x548000,   0xbb4000),
    ("__DATA_SPTM",     0xfffffff008100000, 0x4c000,    0x10fc000),
    ("__TEXT_EXEC",     0xfffffff00814c000, 0x2924000,  0x1148000),
    ("__TEXT_BOOT_EXEC",0xfffffff00aa70000, 0x8000,     0x3a6c000),
    ("__PRELINK_INFO",  0xfffffff00aa78000, 0x23c000,   0x3a74000),
    ("__DATA",          0xfffffff00acb4000, 0x2b8000,   0x3cb0000),
    ("__LINKEDIT",      0xfffffff00af6c000, 0xb8000,    0x3f68000),
]
KC_REL = "02_KERNEL/kc/27.2_24B115_kernelcache"


def off2va(off):
    for n, s, sz, fo in SEGS:
        if fo <= off < fo + sz:
            return s + (off - fo)
    return None


def va2off(va):
    for n, s, sz, fo in SEGS:
        if s <= va < s + sz:
            return fo + (va - s)
    return None


class KC:
    def __init__(self, path=None, mcp=False):
        self.path = path
        self.mcp = mcp
        self._hub = None
        self._cache = {}

    # ---- io ----
    def _read_mcp(self, off, n):
        if self._hub is None:
            import hub  # provided by the agent workspace
            self._hub = hub.Hub()
        return self._hub.read(KC_REL, off, n)

    def read(self, va, n):
        off = va2off(va)
        if off is None:
            raise ValueError("VA %#x outside kernelcache segments" % va)
        if self.mcp:
            return self._read_mcp(off, n)
        with open(self.path, "rb") as f:
            f.seek(off)
            return f.read(n)

    def u32(self, va):
        return struct.unpack("<I", self.read(va, 4))[0]

    def u64(self, va):
        return struct.unpack("<Q", self.read(va, 8))[0]

    def cstr(self, va, n=200):
        b = self.read(va, n)
        z = b.find(b"\0")
        return b[:z].decode("utf-8", "replace") if z >= 0 else None

    def pac(self, q):
        return BASE + (q & 0x0FFFFFFF)

    def fn_va(self, q):
        """decode a __auth_got bind: low32 == file offset of the target."""
        t = off2va(q & 0xFFFFFFFF)
        return t

    # ---- kext discovery ----
    def fileset(self):
        d = self.read(BASE, 0x8000)
        ncmds = struct.unpack_from("<I", d, 16)[0]
        o, out = 32, {}
        for _ in range(ncmds):
            cmd, cs = struct.unpack_from("<II", d, o)
            if cmd == 0x80000035:  # LC_FILESET_ENTRY
                vmaddr, fileoff = struct.unpack_from("<QQ", d, o + 8)
                soff = struct.unpack_from("<I", d, o + 24)[0]
                name = d[o + soff:].split(b"\0")[0].decode("utf-8", "replace")
                out[name] = (vmaddr, fileoff)
            o += cs
        return out

    def kext_header(self, fileoff):
        va = off2va(fileoff)
        d = self.read(va, 0x2000)
        ncmds = struct.unpack_from("<I", d, 16)[0]
        o, segs, syms, fstarts = 32, [], None, None
        for _ in range(ncmds):
            cmd, cs = struct.unpack_from("<II", d, o)
            if cmd == 0x19:
                sn = d[o + 8:o + 24].split(b"\0")[0].decode()
                sva, vsz, fo, fsz = struct.unpack_from("<QQQQ", d, o + 24)
                segs.append((sn, sva, vsz, fo, fsz))
            elif cmd == 0x2:
                syms = struct.unpack_from("<IIII", d, o + 8)
            elif cmd == 0x26:
                fstarts = struct.unpack_from("<II", d, o + 8)
            o += cs
        return dict(vmaddr=va, segs=segs, symtab=syms, funcstarts=fstarts)

    def functions(self, hdr):
        off, size = hdr["funcstarts"]
        va = off2va(off)
        d = self.read(va, size)
        base = hdr["segs"][0][1]
        i, addr, out = 0, base, []
        while i < len(d):
            r, sh = 0, 0
            while True:
                if i >= len(d):
                    return out
                x = d[i]; i += 1
                r |= (x & 0x7F) << sh
                sh += 7
                if not x & 0x80:
                    break
            if r == 0:
                break
            addr += r
            out.append(addr)
        return out

    def kalloc_types(self, hdr):
        """walk __DATA_CONST,__kalloc_type / __kalloc_var records."""
        names = {}
        for sn, sva, vsz, fo, fsz in hdr["segs"]:
            if sn != "__DATA_CONST":
                continue
            d = self.read(sva, vsz)
            # section table
            # (re-read the segment command to get section offsets)
        return names

    def sections(self, hdr):
        out = []
        for sn, sva, vsz, fo, fsz in hdr["segs"]:
            pass
        return out


# --- section-aware helpers (need the kext's LC_SEGMENT_64 section list) ------

def kext_sections(kc, fileoff):
    va = off2va(fileoff)
    d = kc.read(va, 0x2000)
    ncmds = struct.unpack_from("<I", d, 16)[0]
    o, out = 32, []
    for _ in range(ncmds):
        cmd, cs = struct.unpack_from("<II", d, o)
        if cmd == 0x19:
            ns = struct.unpack_from("<I", d, o + 64)[0]
            so = o + 72
            for _ in range(ns):
                sect = d[so:so + 16].split(b"\0")[0].decode()
                seg = d[so + 16:so + 32].split(b"\0")[0].decode()
                addr, size, off, al, rel, nr, fl = struct.unpack_from("<QQIIIII", d, so + 32)
                out.append(dict(seg=seg, sect=sect, addr=addr, size=size, off=off, flags=fl))
                so += 80
        o += cs
    return out


def dump_types(kc, secs):
    row = []
    for s in secs:
        if s["sect"] not in ("__kalloc_type", "__kalloc_var"):
            continue
        blob = kc.read(s["addr"], s["size"])
        step = 8
        for off in range(0, len(blob) - 0x28, step):
            nq = struct.unpack_from("<Q", blob, off + 0x08)[0]
            if not nq:
                continue
            t = kc.pac(nq)
            try:
                name = kc.cstr(t, 96)
            except ValueError:
                continue
            if not name or not name.startswith("site."):
                continue
            sigq = struct.unpack_from("<Q", blob, off + 0x18)[0]
            sig = None
            if sigq:
                try:
                    sig = kc.cstr(kc.pac(sigq), 512)
                except ValueError:
                    pass
            szq = struct.unpack_from("<Q", blob, off + 0x20)[0]
            size, kind = szq >> 32, szq & 0xFFFFFFFF
            row.append(dict(section=s["sect"], name=name[5:], size=size,
                            sig=sig, kind=kind, rec=s["addr"] + off))
    return row


def dump_dispatch(kc, secs):
    tab = 0xfffffff007fea200
    out = []
    for i in range(56):
        va = tab + i * 24
        q = kc.u64(va)
        fn = kc.pac(q)
        a, b, c, d = struct.unpack("<IIII", kc.read(va + 8, 16))
        out.append(dict(sel=i, fn=fn, in_scalar=a, in_struct=b,
                        out_scalar=c, out_struct=d))
    return out


def dump_stubs(kc, hdr, secs):
    st = [s for s in secs if s["sect"] == "__auth_stubs"]
    got = [s for s in secs if s["sect"] in ("__auth_got", "__got")]
    if not st or not got:
        return []
    out = []
    d = kc.read(st[0]["addr"], st[0]["size"])
    for off in range(0, len(d) - 0x10, 0x10):
        w0, w1 = struct.unpack_from("<II", d, off)
        if (w0 & 0x9F000000) != 0x90000000:
            continue
        imm = (((w0 >> 5) & 0x7FFFF) << 2) | ((w0 >> 29) & 3)
        if imm & (1 << 20):
            imm -= 1 << 21
        page = ((st[0]["addr"] + off) & ~0xFFF) + (imm << 12)
        if (w1 & 0xFFC00000) != 0x91000000:
            continue
        a = (w1 >> 10) & 0xFFF
        sh = (w1 >> 22) & 3
        gotva = page + (a << (12 if sh else 0))
        q = kc.u64(gotva)
        out.append(dict(stub=st[0]["addr"] + off, got=gotva,
                        raw=q, target=kc.fn_va(q)))
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--kc")
    ap.add_argument("--mcp", action="store_true")
    ap.add_argument("--dump", default="all")
    ap.add_argument("--json", action="store_true")
    a = ap.parse_args()

    kc = KC(path=a.kc, mcp=a.mcp)
    fs = kc.fileset()
    name = "com.apple.iokit.IOGPUFamily"
    if name not in fs:
        sys.exit("IOGPUFamily not in fileset")
    vm, fo = fs[name]
    hdr = kc.kext_header(fo)
    secs = kext_sections(kc, fo)
    funcs = kc.functions(hdr)
    types = dump_types(kc, secs)
    disp = dump_dispatch(kc, secs)
    stubs = dump_stubs(kc, hdr, secs)

    if a.json:
        print(json.dumps(dict(kext=name, fileoff=fo, segments=hdr["segs"],
                              functions=funcs, types=types,
                              dispatch=disp, stubs=stubs), indent=1))
        return

    print(f"kext {name}: fileoff={fo:#x}")
    for s in hdr["segs"]:
        print(f"  seg {s[0]:16s} va={s[1]:#012x} size={s[2]:#08x}")
    print(f"function starts: {len(funcs)} ({funcs[0]:#x} .. {funcs[-1]:#x})")
    print(f"kalloc types:    {len(types)}")
    print(f"dispatch table:  {len(disp)} selectors @0x7fea200")
    print(f"auth stubs:      {len(stubs)} resolvable")
    if a.dump in ("types", "all"):
        print("\n-- kalloc types --")
        for t in types:
            print(f"  {t['name']:40s} size={t['size']:#06x} {t['section']}")
    if a.dump in ("dispatch", "all"):
        print("\n-- IOGPUDeviceUserClient selectors --")
        for x in disp:
            print(f"  sel {x['sel']:2d} fn={x['fn']:#012x} inS={x['in_scalar']} "
                  f"inSt={x['in_struct']:#x} outS={x['out_scalar']} outSt={x['out_struct']:#x}")
    if a.dump in ("stubs", "all"):
        print("\n-- auth stubs (imports) --")
        for s in stubs:
            if s["target"]:
                print(f"  {s['stub']:#012x} -> {s['target']:#012x}")


if __name__ == "__main__":
    main()
