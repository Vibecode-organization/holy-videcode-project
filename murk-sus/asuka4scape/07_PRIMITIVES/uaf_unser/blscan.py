import struct, sys, kc
k = kc.KC()
# map file offsets of executable segments
segs = [s for s in kc.SEGS if s[4]]
targets = {int(a,16):n for a,n in [x.split(':') for x in sys.argv[1:]]}
found = {t:[] for t in targets}
import numpy as np
for name, sva, so, sz, ex in segs:
    blob = k.d[so:so+sz]
    n = len(blob)//4
    w = np.frombuffer(blob[:n*4], dtype='<u4')
    mask = (w & 0xFC000000) == 0x94000000
    idx = np.nonzero(mask)[0]
    imm = w[idx].astype(np.int64)
    imm = (imm & 0x03FFFFFF)
    imm = np.where(imm >= 0x02000000, imm - 0x04000000, imm)
    # bl at va = sva + i*4 ; target = va + imm*4
    va = np.uint64(sva) + idx.astype(np.uint64)*np.uint64(4)
    tgt = va + (imm.astype(np.int64)*4).astype(np.uint64)
    for t,nm in targets.items():
        t = np.uint64(t)
        hit = np.nonzero(tgt == t)[0]
        for h in hit:
            found[t].append((int(va[h]), name))
for t,nm in targets.items():
    print('==', nm, hex(t), 'callers:', len(found[t]))
    for va,seg in found[t][:12]:
        print('   ', hex(va), seg)
