#!/usr/bin/env python3
"""Extract a Mach-O image from a split dyld shared cache without ipsw/dyldex.

Usage: dsc_extract.py <cache_dir_or_main_file> <substring> <out.macho>
Parses dyld_cache_header (main + subcaches), mapping tables, imagesText table,
finds the image whose path contains <substring>, then rebuilds a thin Mach-O
by copying the mach header + load commands and each segment's file data from
the cache mappings.
"""
import sys, os, struct, glob, hashlib

def rd(fn, off, n):
    with open(fn, 'rb') as f:
        f.seek(off)
        return f.read(n)

def parse_header(fn):
    b = rd(fn, 0, 0x200)
    if b[:7] != b'dyld_v1':
        return None
    h = {}
    h['file'] = fn
    h['mapping_off'], h['mapping_cnt'], h['images_off'], h['images_cnt'] = struct.unpack_from('<IIII', b, 0x10)
    h['dyld_base'] = struct.unpack_from('<Q', b, 0x20)[0]
    h['images_text_off'] = struct.unpack_from('<Q', b, 0x88)[0]
    h['images_text_cnt'] = struct.unpack_from('<Q', b, 0x90)[0]
    # try several known offsets for subCacheArray (varies by version)
    h['sub_off'] = h['sub_cnt'] = None
    for off in (0x1c0, 0x1d0, 0x1e0, 0x200, 0x210, 0x220):
        if off + 12 <= len(b):
            o, c = struct.unpack_from('<QI', b, off)
            if 0 < c < 200 and 0x100 <= o <= os.path.getsize(fn):
                h['sub_off'], h['sub_cnt'] = o, c
                h['sub_at'] = off
                break
    return h

def mappings(h):
    fn = h['file']
    off, cnt = h['mapping_off'], h['mapping_cnt']
    if not off or cnt > 64:
        return []
    sz = os.path.getsize(fn)
    out = []
    for i in range(cnt):
        b = rd(fn, off + i * 32, 32)
        if len(b) < 32:
            break
        addr, size, foff, maxp, initp = struct.unpack('<QQQII', b)
        if foff > sz or size > (1 << 40):
            continue
        out.append((addr, size, foff, maxp, initp))
    return out

def image_texts(h):
    fn = h['file']
    off, cnt = h['images_text_off'], h['images_text_cnt']
    if not off or not cnt or cnt > 200000:
        return []
    data = rd(fn, off, cnt * 32)
    out = []
    for i in range(cnt):
        b = data[i*32:(i+1)*32]
        if len(b) < 32:
            break
        uuid = b[:16]
        load, textsz, pathoff = struct.unpack_from('<QII', b, 16)
        out.append((load, textsz, pathoff, uuid))
    return out

def cstr(fn, off, maxlen=4096):
    with open(fn, 'rb') as f:
        f.seek(off)
        d = f.read(maxlen)
    z = d.find(b'\0')
    return d[:z].decode('utf-8', 'replace') if z >= 0 else d.decode('utf-8', 'replace')

def main():
    if len(sys.argv) < 4:
        print(__doc__); return 1
    target = sys.argv[1]
    needle = sys.argv[2]
    outpath = sys.argv[3]
    if os.path.isdir(target):
        mainf = os.path.join(target, 'dyld_shared_cache_arm64e')
    else:
        mainf = target
    cache_dir = os.path.dirname(mainf)
    files = [mainf] + sorted(f for f in glob.glob(os.path.join(cache_dir, 'dyld_shared_cache_arm64e.*'))
                             if not f.endswith(('.symbols', '.atlas')))
    heads = []
    vamap = []  # (start, end, file, fileoff)
    for fn in files:
        h = parse_header(fn)
        if not h:
            continue
        heads.append(h)
        for (addr, size, foff, maxp, initp) in mappings(h):
            vamap.append((addr, addr + size, fn, foff))
    print(f'[i] cache files parsed: {len(heads)} mappings: {len(vamap)}')
    # locate image
    found = None
    for h in heads:
        for (load, textsz, pathoff, uuid) in image_texts(h):
            try:
                p = cstr(h['file'], pathoff)
            except Exception:
                continue
            if needle.lower() in p.lower():
                print(f'[+] {os.path.basename(h["file"])} load={load:#x} textsz={textsz:#x} {p}')
                found = (load, p, h['file'])
                break
        if found:
            break
    if not found:
        # fallback: search every file for the path string then scan imagesText of all
        print('[-] not in imagesText; scanning all headers for path strings')
        for fn in files:
            with open(fn, 'rb') as f:
                data = f.read()
            i = data.find(needle.encode())
            if i < 0:
                continue
            p = data[max(0,i-200):i+200]
            print('[?] string in', fn, 'at', hex(i), p[:120])
        return 2
    load, path, srcfile = found
    # read mach header at load
    def read_va(va, n):
        for (a, b, fn, fo) in vamap:
            if a <= va < b:
                take = min(n, b - va)
                return rd(fn, fo + (va - a), take)
        return None
    mh = read_va(load, 32)
    if mh is None or struct.unpack_from('<I', mh, 0)[0] not in (0xfeedfacf,):
        print('[-] no mach_header_64 at', hex(load), mh[:8] if mh else None)
        return 3
    magic, cputype, cpusub, ftype, ncmds, sizeofcmds, flags, res = struct.unpack_from('<IiiIIIII', mh, 0)
    hdr = read_va(load, 32 + sizeofcmds)
    if hdr is None:
        print('[-] cannot read load commands'); return 3
    print(f'[i] macho load={load:#x} ncmds={ncmds} sizeofcmds={sizeofcmds:#x} ftype={ftype}')
    # parse segments
    segs = []
    off = 32
    for i in range(ncmds):
        if off + 8 > len(hdr): break
        cmd, cmdsize = struct.unpack_from('<II', hdr, off)
        if cmdsize < 8 or off + cmdsize > len(hdr): break
        if cmd == 0x19:  # LC_SEGMENT_64
            name = hdr[off+8:off+24].split(b'\0')[0].decode('latin1')
            vmaddr, vmsize, fileoff, filesize, maxprot, initprot, nsects, flags_ = struct.unpack_from('<QQQQIIII', hdr, off+24)
            segs.append((name, vmaddr, vmsize, fileoff, filesize))
        off += cmdsize
    print('[i] segments:', [(s[0], hex(s[1]), hex(s[3]), hex(s[4])) for s in segs])
    maxend = 32 + sizeofcmds
    blobs = []
    for (name, vmaddr, vmsize, fileoff, filesize) in segs:
        if filesize == 0:
            continue
        va = vmaddr if vmaddr >= load else load + vmaddr
        data = read_va(va, filesize)
        if data is None:
            print(f'[-] missing segment data {name} at {va:#x} size {filesize:#x}')
            continue
        if len(data) != filesize:
            print(f'[!] short segment {name}: {len(data):#x} of {filesize:#x}')
        blobs.append((fileoff, data))
        maxend = max(maxend, fileoff + filesize)
    out = bytearray(hdr + b'\0' * (maxend - len(hdr)))
    for (fileoff, data) in blobs:
        out[fileoff:fileoff+len(data)] = data
    os.makedirs(os.path.dirname(outpath) or '.', exist_ok=True)
    with open(outpath, 'wb') as f:
        f.write(out)
    print(f'[+] wrote {outpath} size={len(out):#x} sha256={hashlib.sha256(out).hexdigest()}')
    return 0

if __name__ == '__main__':
    sys.exit(main())
