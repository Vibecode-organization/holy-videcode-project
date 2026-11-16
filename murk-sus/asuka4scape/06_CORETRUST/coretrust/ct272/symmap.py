#!/usr/bin/env python3
"""Map local symbol names from a dyld split-cache .symbols blob to their images."""
import sys, struct, mmap, re
import numpy as np

sys.path.insert(0, "/home/femboychik/work/coretrust/ct272")
from dscparse import SharedCache, CacheFile

MAIN = sys.argv[1]
SYMFILE = sys.argv[2]
PATTERN = sys.argv[3] if len(sys.argv) > 3 else "CTEvaluate"

cache = SharedCache(MAIN)
images = cache.images_text()
region = cache.main.shared_region_start
by_addr = {i["address"]: i["path"] for i in images}

sym = CacheFile(SYMFILE)
blob_off = sym.local_sym_off
f = open(SYMFILE, "rb")
mm = mmap.mmap(f.fileno(), 0, access=mmap.ACCESS_READ)

info = struct.unpack_from("<6I", mm, blob_off)
nlist_off, nlist_count, strings_off, strings_size, entries_off, entries_count = info
print(f"nlist={nlist_count} strings={strings_size} entries={entries_count}")

# entries are local_symbols_entry_64 (16 bytes) for 64-bit caches
entries = []
eo = blob_off + entries_off
for i in range(entries_count):
    dylib_off, start, count = struct.unpack_from("<QII", mm, eo + i * 16)
    entries.append((dylib_off, start, count))
entries.sort()
print("first entry dylib_off", hex(entries[0][0]), "->", by_addr.get(region + entries[0][0], "?"))

# find matching symbols: gather nlist names via regex over strings is easier:
strings = mm[blob_off + strings_off: blob_off + strings_off + strings_size]
hits = {}
for m in re.finditer(rb"[A-Za-z0-9_$.]*(?:%s)[A-Za-z0-9_$.]*" % PATTERN.encode(), strings):
    hits[m.start()] = m.group().decode()
print("string hits", len(hits))

if not hits:
    sys.exit(0)

wanted = set(hits)
# nlist array
nl = np.frombuffer(mm, dtype=np.dtype([('strx', '<u4'), ('type', 'u1'), ('sect', 'u1'),
                                       ('desc', '<u2'), ('value', '<u8')]),
                   count=nlist_count, offset=blob_off + nlist_off)

# entries index symbols by range; find ranges containing matches
rows = []
for strx, name in sorted(hits.items()):
    idx = np.nonzero(nl['strx'] == strx)[0]
    for j in idx:
        rows.append((int(j), name, int(nl[j]['value'])))

# map symbol index -> image
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
        return by_addr.get(region + dylib_off), start, count
    return None

out = []
for j, name, val in rows:
    owner = image_for_symbol(j)
    path = owner[0] if owner else "?"
    out.append((name, hex(val), path))
for name, val, path in sorted(out):
    print(f"{name:<48} {val:>18}  {path}")
