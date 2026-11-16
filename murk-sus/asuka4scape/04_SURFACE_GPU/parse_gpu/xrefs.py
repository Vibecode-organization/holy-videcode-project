import numpy as np, struct, json, bisect
from kc import load
k=load()
s=k.seg_by_name['__TEXT_EXEC']
TEXT_BASE=s['vmaddr']
words=np.frombuffer(k.data, dtype='<u4', count=s['filesize']//4, offset=s['fileoff'])
print("words", len(words))
m = (words & np.uint32(0x9F000000)) == np.uint32(0x90000000)
idx = np.nonzero(m)[0]
print("adrp count", len(idx))
w = words[idx].astype(np.uint64)
rd = (w & 0x1F)
immlo = ((w >> 29) & 3).astype(np.int64)
immhi = ((w >> 5) & 0x7FFFF).astype(np.int64)
imm = (immhi << 2) | immlo
imm = np.where(imm >= (1<<20), imm - (1<<21), imm)
pc = TEXT_BASE + idx.astype(np.uint64)*4
page = (pc & ~np.uint64(0xFFF)) + (imm.astype(np.uint64) << 12)
np.save('adrp_idx.npy', idx); np.save('adrp_rd.npy', rd); np.save('adrp_page.npy', page)
print("example pages", [hex(x) for x in page[:5]])
