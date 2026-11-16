import numpy as np, sys
sys.path.insert(0,'.')
from macho import *

buf = np.frombuffer(DATA, dtype='<u4')
idx = np.nonzero((buf & 0x9F000000) == 0x90000000)[0]
w = buf[idx]
immhi = ((w >> 5) & 0x7FFFF).astype(np.int64)
immlo = ((w >> 29) & 0x3).astype(np.int64)
imm = (immhi << 2) | immlo
imm = np.where(imm >= (1<<20), imm - (1<<21), imm)
rd = (w & 0x1F).astype(np.int64)
pc = idx.astype(np.int64)*4
page = (pc & ~0xFFF) + (imm << 12)
page_u = page.astype(np.uint64)

def find(target):
    hits = np.nonzero(page_u == np.uint64(target))[0]
    return [(int(idx[h])*4, int(rd[h])) for h in hits]

for t in (0xfffffff008068000, 0xfffffff008069000, 0xfffffff008068b90 & ~0xFFF):
    hits = find(t)
    print(hex(t), len(hits))
    for off, r in hits[:20]:
        va = off2va(off)
        print("   ", hex(va) if va else hex(off), "x%d"%r)
