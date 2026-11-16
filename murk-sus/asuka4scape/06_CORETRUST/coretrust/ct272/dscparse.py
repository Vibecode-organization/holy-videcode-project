#!/usr/bin/env python3
"""Split dyld_shared_cache parser + standalone Mach-O re-builder.

Handles iOS 16+ "split" caches: a main file plus .01..NN subcaches, each with
its own dyld_cache_header and mapping table. Images are located via the main
file's imagesText table (uuid + loadAddress + textSize + pathOffset).
"""
import os, sys, struct, glob, json

MAGIC = b"dyld_v1"
SEG_CMD = 0x19
SEG64_CMD = 0x19
UUID_CMD = 0x1b
LC_SEGMENT_64 = 0x19


class Mapping:
    __slots__ = ("address", "size", "file_offset", "max_prot", "init_prot", "file")

    def __init__(self, address, size, file_offset, max_prot, init_prot, file):
        self.address = address
        self.size = size
        self.file_offset = file_offset
        self.max_prot = max_prot
        self.init_prot = init_prot
        self.file = file

    def __repr__(self):
        return f"<map {self.address:#x}+{self.size:#x} @{self.file}+{self.file_offset:#x}>"


class CacheFile:
    def __init__(self, path):
        self.path = path
        self.f = open(path, "rb")
        self.size = os.path.getsize(path)
        hdr = self.f.read(0x200)
        if hdr[:7] != MAGIC:
            raise ValueError(f"{path}: not a dyld cache (magic {hdr[:16]!r})")
        self.magic = hdr[:16].split(b"\0")[0].decode("ascii", "replace").strip()
        (self.mapping_offset, self.mapping_count, self.images_offset_old,
         self.images_count_old) = struct.unpack_from("<IIII", hdr, 0x10)
        (self.dyld_base, self.cs_offset, self.cs_size, self.slide_off, self.slide_size,
         self.local_sym_off, self.local_sym_size) = struct.unpack_from("<QQQQQQQ", hdr, 0x20)
        self.uuid = hdr[0x58:0x68]
        (self.cache_type,) = struct.unpack_from("<Q", hdr, 0x68)
        (self.images_text_offset, self.images_text_count) = struct.unpack_from("<QQ", hdr, 0x88)
        (self.shared_region_start, self.shared_region_size, self.max_slide) = struct.unpack_from(
            "<QQQ", hdr, 0xE0)
        self.mappings = []
        for i in range(self.mapping_count):
            off = self.mapping_offset + i * 32
            self.f.seek(off)
            b = self.f.read(32)
            if len(b) < 32:
                break
            addr, size, foff, mx, init = struct.unpack("<QQQII", b)
            self.mappings.append(Mapping(addr, size, foff, mx, init, self))

    def read_at(self, offset, n):
        self.f.seek(offset)
        return self.f.read(n)

    def __repr__(self):
        return (f"<{os.path.basename(self.path)} {self.magic!r} maps={self.mapping_count} "
                f"type={self.cache_type} uuid={self.uuid.hex()} size={self.size}>")


class SharedCache:
    def __init__(self, main_path):
        self.dir = os.path.dirname(main_path) or "."
        base = os.path.basename(main_path)
        self.files = []
        self.main = CacheFile(main_path)
        self.files.append(self.main)
        # Split caches name slots .NN, .NN.dylddata, .NN.dyldreadonly, .NN.dyldlinkedit;
        # numbering can have holes, so glob rather than counting.
        import re
        pat = re.compile(re.escape(base) + r"\.\d{2}(\.dyld(data|readonly|linkedit))?$")
        for p in sorted(os.listdir(self.dir)):
            if not pat.match(p):
                continue
            full = os.path.join(self.dir, p)
            if not os.path.isfile(full):
                continue
            try:
                self.files.append(CacheFile(full))
            except ValueError:
                # data-only file (no dyld header) - remember raw blob
                self.files.append(RawFile(full))
        self.maps = []
        for cf in self.files:
            if isinstance(cf, CacheFile):
                self.maps.extend(cf.mappings)
        self.maps.sort(key=lambda m: m.address)

    def find_map(self, va):
        lo, hi = 0, len(self.maps)
        while lo < hi:
            mid = (lo + hi) // 2
            if self.maps[mid].address <= va:
                lo = mid + 1
            else:
                hi = mid
        if lo == 0:
            return None
        m = self.maps[lo - 1]
        if m.address <= va < m.address + m.size:
            return m
        return None

    def read_va_fill(self, va, n):
        """Read n bytes at va; unmapped ranges come back as zeros. Returns (data, missing)."""
        out = bytearray(n)
        missing = 0
        pos = 0
        while pos < n:
            cur = va + pos
            m = self.find_map(cur)
            if m is None:
                # zero until the next mapping (or end)
                nxt = next((mm.address for mm in self.maps if mm.address > cur), cur + (n - pos))
                step = min(n - pos, nxt - cur)
                missing += step
                pos += step
                continue
            inner = cur - m.address
            step = min(n - pos, m.size - inner)
            data = m.file.read_at(m.file_offset + inner, step)
            out[pos:pos + len(data)] = data
            if len(data) < step:
                missing += step - len(data)
            pos += step
        return bytes(out), missing

    def read_va(self, va, n):
        """Read n bytes at virtual address va, crossing mappings if needed."""
        out = bytearray()
        while n > 0:
            m = self.find_map(va)
            if m is None:
                raise ValueError(f"VA {va:#x} not mapped")
            inner = va - m.address
            chunk = min(n, m.size - inner)
            data = m.file.read_at(m.file_offset + inner, chunk)
            if len(data) < chunk:
                data += b"\0" * (chunk - len(data))
            out += data
            va += chunk
            n -= chunk
        return bytes(out)

    def images_text(self):
        """Parse main file imagesText table -> list of dicts."""
        out = []
        m = self.main
        base = m.images_text_offset
        for i in range(m.images_text_count):
            b = m.read_at(base + i * 32, 32)
            if len(b) < 32:
                break
            uuid, addr, tsize, path_off = struct.unpack("<16sQII", b)
            path = self._cstr(m.read_at(path_off, 512))
            out.append({"uuid": uuid, "address": addr, "text_size": tsize, "path": path})
        return out

    def images_old(self):
        """Fallback: legacy images table in main header (dyld_cache_image_info)."""
        out = []
        m = self.main
        for i in range(m.images_count_old):
            b = m.read_at(m.images_offset_old + i * 32, 32)
            addr, modtime, inode, path_off, pad = struct.unpack("<QQQII", b)
            out.append({"address": addr, "path": self._cstr(m.read_at(path_off, 512))})
        return out

    @staticmethod
    def _cstr(b):
        z = b.find(b"\0")
        return b[:z if z >= 0 else len(b)].decode("utf-8", "replace")

    def find_image(self, needle):
        imgs = self.images_text()
        hits = [i for i in imgs if needle in i["path"]]
        return hits

    def extract_image(self, img, out_path, verbose=False):
        """Rebuild a standalone Mach-O with all segments re-based at image_base."""
        base = img["address"]
        hdr = self.read_va(base, 32)
        (magic, cputype, cpusubtype, filetype, ncmds, sizeofcmds, flags,
         reserved) = struct.unpack("<IiiIIIII", hdr)
        if magic != 0xFEEDFACF:
            raise ValueError(f"bad mach magic {magic:#x} at {base:#x} for {img['path']}")
        cmds = bytearray(self.read_va(base + 32, sizeofcmds))
        full = bytearray(hdr + bytes(cmds))

        segs = []
        p = 32
        end = 32 + sizeofcmds
        for _ in range(ncmds):
            if p + 8 > end:
                break
            cmd, csize = struct.unpack_from("<II", full, p)
            if cmd == LC_SEGMENT_64 and p + 72 <= end:
                segname = full[p + 8:p + 24].split(b"\0")[0].decode("ascii", "replace")
                vmaddr, vmsize, fileoff, filesize = struct.unpack_from("<QQQQ", full, p + 24)
                maxprot, initprot, nsects, sflags = struct.unpack_from("<IIII", full, p + 56)
                segs.append(dict(cmd_off=p, name=segname, vmaddr=vmaddr, vmsize=vmsize,
                                 fileoff=fileoff, filesize=filesize, maxprot=maxprot,
                                 initprot=initprot, nsects=nsects, flags=sflags))
            elif cmd in (0x2, 0xb, 0x1d, 0x1e, 0x22, 0x26, 0x29, 0x2b, 0x2e,
                         0x80000022, 0x80000033, 0x80000034):
                # linkedit-backed payload: zero the fields, the data is not in this file
                for i in range(p + 8, p + csize):
                    full[i] = 0
            p += csize

        if not segs:
            raise ValueError("no segments")

        image_base = min(s["vmaddr"] for s in segs)
        # Compact layout: segments back-to-back, 16 KB aligned. __TEXT stays at 0.
        # __LINKEDIT lives in the shared .dyldlinkedit subcache and is dropped.
        cursor = (len(full) + 0x3fff) & ~0x3fff
        blob = bytearray(cursor)
        blob[0:len(full)] = full
        missing_total = 0
        for s in segs:
            if s["name"] == "__LINKEDIT":
                struct.pack_into("<Q", blob, s["cmd_off"] + 32, 0)      # vmsize
                struct.pack_into("<Q", blob, s["cmd_off"] + 48, 0)      # filesize
                struct.pack_into("<Q", blob, s["cmd_off"] + 40, 0)      # fileoff
                continue
            if s["filesize"] == 0:
                struct.pack_into("<Q", blob, s["cmd_off"] + 40, 0)
                continue
            off = 0 if s["vmaddr"] == image_base else cursor
            if off == 0:
                newlen = max(len(blob), s["filesize"])
                if newlen > len(blob):
                    blob.extend(b"\0" * (newlen - len(blob)))
                cursor = max(cursor, s["filesize"])
            else:
                newlen = off + s["filesize"]
                if newlen > len(blob):
                    blob.extend(b"\0" * (newlen - len(blob)))
                cursor = newlen
            data, missing = self.read_va_fill(s["vmaddr"], s["filesize"])
            missing_total += missing
            blob[off:off + len(data)] = data
            # segment_command_64: cmd+cmdsize+segname=24, vmaddr=24, vmsize=32, fileoff=40
            struct.pack_into("<Q", blob, s["cmd_off"] + 40, off)
            s["new_off"] = off
            cursor = (cursor + 0x3fff) & ~0x3fff
            if cursor > len(blob):
                blob.extend(b"\0" * (cursor - len(blob)))
        # NOTE: load commands were patched in `blob` after each segment copy above;
        # do not rewrite them from `full`.

        with open(out_path, "wb") as out:
            out.write(blob)

        return dict(path=img["path"], address=base, image_base=image_base,
                    size=len(blob), ncmds=ncmds, segments=segs, missing_bytes=missing_total,
                    header=dict(magic=magic, cputype=cputype, cpusubtype=cpusubtype,
                                filetype=filetype, flags=flags))


class RawFile:
    """A split-cache companion file with no dyld header (e.g. .dylddata)."""

    def __init__(self, path):
        self.path = path
        self.size = os.path.getsize(path)
        self.mappings = []
        self.cache_type = None
        self.uuid = b""
        self.f = open(path, "rb")

    def read_at(self, offset, n):
        self.f.seek(offset)
        return self.f.read(n)


def main():
    if len(sys.argv) < 3:
        print(__doc__)
        print("usage: dscparse.py <main cache> list [filter]")
        print("       dscparse.py <main cache> extract <path-substr> <out>")
        return 1
    cache = SharedCache(sys.argv[1])
    what = sys.argv[2]
    if what == "info":
        for cf in cache.files:
            print(cf if isinstance(cf, CacheFile) else f"<raw {cf.path} {cf.size}>")
        print("total VA mappings", len(cache.maps))
        imgs = cache.images_text()
        print("imagesText", len(imgs))
        if imgs:
            print("first image", imgs[0]["path"], hex(imgs[0]["address"]))
    elif what == "list":
        needle = sys.argv[3] if len(sys.argv) > 3 else ""
        for i in cache.images_text():
            if needle.lower() in i["path"].lower():
                print(f"{i['address']:#018x} {i['text_size']:#x} {i['path']}")
    elif what == "extract":
        needle, out = sys.argv[3], sys.argv[4]
        hits = cache.find_image(needle)
        if not hits:
            print("not found")
            return 2
        for h in hits[:5]:
            print("hit", h["path"], hex(h["address"]))
        info = cache.extract_image(hits[0], out)
        print(json.dumps({k: v for k, v in info.items() if k != "segments"}, indent=1))
        for s in info["segments"]:
            print(f"  {s['name']:<18} vm={s['vmaddr']:#x} vsize={s['vmsize']:#x} "
                  f"file={s['fileoff']:#x} fsize={s['filesize']:#x}")
        return 0
    return 0


if __name__ == "__main__":
    sys.exit(main())
