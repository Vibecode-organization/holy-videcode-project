#!/usr/bin/env python3
"""Map exact local symbol names from a dyld split-cache .symbols blob to their images."""
import sys, struct, mmap
import numpy as np

sys.path.insert(0, "/home/femboychik/work/coretrust/ct272")
from dscparse import SharedCache, CacheFile

MAIN, SYMFILE, NAMES_FILE = sys.argv[1], sys.argv[2], sys.argv[3]
names = [l.strip() for l in open(NAMES_FILE) if l.strip()]

cache = SharedCache(MAIN)
images = cache.images_text()
region = cache.main.shared_region_start
by_addr = {i["address"]: i["path"] for i in images}

sym = CacheFile(SYMFILE)
blob_off = sym.local_sym_off
f = open(SYMFILE, "rb")
mm = mmap.mmap(f.fileno(), 0, access=mmap.ACCESS_READ)
nlist_off, nlist_count, strings_off, strings_size, entries_off, entries_count = \
    struct.unpack_from("<6I", mm, blob_off)
base = blob_off + strings_off
strings = mm[base: base + strings_size]

entries = []
eo = blob_off + entries_off
for i in range(entries_count):
    dylib_off, start, count = struct.unpack_from("<QII", mm, eo + i * 16)
    entries.append((dylib_off, start, count))
entries.sort()

nl = np.frombuffer(mm, dtype=np.dtype([('strx', '<u4'), ('type', 'u1'), ('sect', 'u1'),
                                       ('desc', '<u2'), ('value', '<u8')]),
                   count=nlist_count, offset=blob_off + nlist_off)


def image_for_symbol(idx):
    lo, hi = 0, len(entries)
    while lo < hi:
        mid = (lo + hi) // 2
        if entries[mid][1] <= idx:
            lo = mid + 1
        else:
            hi = mid
    if lo == 0:
        return None
    dylib_off, start, count = entries[lo - 1]
    if idx < start + count:
        return by_addr.get(region + dylib_off)
    return None


for name in names:
    needle = name.encode()
    pos = strings.find(needle)
    if pos < 0:
        print(f"{name:<48} {'NOT FOUND':>18}")
        continue
    idxs = np.nonzero(nl['strx'] == pos)[0]
    if len(idxs) == 0:
        print(f"{name:<48} {'no nlist':>18} (strx {pos:#x})")
        continue
    for j in idxs:
        print(f"{name:<48} {int(nl[j]['value']):#18x}  {image_for_symbol(int(j))}")
