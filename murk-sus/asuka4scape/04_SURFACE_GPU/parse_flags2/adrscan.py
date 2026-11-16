import struct
from kcd import data, SECTIONS
TB = SECTIONS['__TEXT_EXEC']
tva,tsz,tfo = TB
def sx(v,b):
    return v-(1<<b) if v&(1<<(b-1)) else v
words = struct.unpack_from('<%dI'%(tsz//4), data, tfo)
N = len(words)
def adrp(i):
    w = words[i]
    if (w & 0x9F000000) != 0x90000000: return None
    immlo = (w>>29)&3; immhi = (w>>5)&0x7FFFF
    imm = sx((immhi<<2)|immlo, 21) << 12
    rd = w & 0x1F
    pc = tva + i*4
    return rd, (pc & ~0xFFF) + imm
def addimm(i):
    w = words[i]
    if (w & 0x7F000000) != 0x11000000: return None
    sh = (w>>22)&1
    imm = ((w>>10)&0xFFF) << (12 if sh else 0)
    rn = (w>>5)&0x1F; rd = w&0x1F
    return rd, rn, imm, (w>>29)&0xFF
def ldr_imm(i):
    w = words[i]
    # LDR (immediate) unsigned offset, 64-bit: 1111 1001 01 imm12 Rn Rt
    if (w & 0xFFC00000) == 0xF9400000:
        imm = ((w>>10)&0xFFF)*8
        rn=(w>>5)&0x1F; rt=w&0x1F
        return rt, rn, imm
    return None
res = []
for i in range(N):
    a = adrp(i)
    if not a: continue
    rd, page = a
    for j in range(1,5):
        if i+j>=N: break
        ai = addimm(i+j)
        if ai and ai[0]==rd and ai[1]==rd:
            tgt = page + ai[2]
            res.append((tva+i*4, tgt, 'add'))
            break
        li = ldr_imm(i+j)
        if li and li[0]==rd and li[1]==rd:
            res.append((tva+i*4, page+li[2], 'ldr'))
            break
import pickle
pickle.dump(res, open('adr_points.pkl','wb'))
print("total adrp-derived points:", len(res))
hits = [r for r in res if 0xfffffff008fd0000 <= r[1] <= 0xfffffff008fe0000]
print("points in 0x8fd0000-0x8fe0000:", len(hits))
for h in hits[:200]:
    print(f"  insn 0x{h[0]:x} -> 0x{h[1]:x} [{h[2]}]")
