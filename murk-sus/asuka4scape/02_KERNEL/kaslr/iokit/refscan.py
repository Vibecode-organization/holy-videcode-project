import numpy as np, sys
sys.path.insert(0,'.')
from macho import *

BASE = 0xfffffff007004000
buf = np.frombuffer(DATA, dtype='<u4')
idx = np.nonzero((buf & 0x9F000000) == 0x90000000)[0]
w = buf[idx]
immhi = ((w >> 5) & 0x7FFFF).astype(np.int64)
immlo = ((w >> 29) & 0x3).astype(np.int64)
imm = (immhi << 2) | immlo
imm = np.where(imm >= (1<<20), imm - (1<<21), imm)
pc = idx.astype(np.int64)*4
tgt = (pc & ~0xFFF) + (imm << 12)          # file offset of adrp page
va  = tgt + BASE
rd  = (w & 0x1F).astype(np.int64)

def refs_to(va_page, name=""):
    sel = np.nonzero(va.astype(np.uint64) == np.uint64(va_page))[0]
    print(f"{name} {va_page:#x}: {len(sel)} adrp")
    out=[]
    for h in sel:
        s = int(idx[h])*4
        out.append((s, int(rd[h])))
        print(f"   src {s+BASE:#x} (off {s:#x}) x{int(rd[h])}")
    return out

if __name__ == "__main__":
    for a in sys.argv[1:]:
        refs_to(int(a,16))
