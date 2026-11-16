"""find GOT slots whose pac'd pointer resolves into the OSUnserialize family, then all xrefs."""
import struct, sys, numpy as np
sys.path.insert(0, '/home/femboychik/work/parse_unser')
import kc
k = kc.KC()

BASE = kc.KCBASE
ENTRY = {
    0xfffffff00a8d5c98: 'OSUnserializeXML_2arg_legacy',
    0xfffffff00a8d846c: 'OSUnserializeXML_core5',
    0xfffffff00a8d8660: 'OSUnserializeXML_2arg_B',
    0xfffffff00a8d8678: 'OSUnserializeXML_sized6',
    0xfffffff00a8d8754: 'OSUnserializeXML_sized3',
    0xfffffff00a8d96f4: 'OSUnserializeBinary',
    0xfffffff00a8da3fc: 'OSSharedPtr_str_ref',
    0xfffffff00a8da470: 'OSSharedPtr_str_ref2',
}

def pac(q):
    return (BASE + (q & 0x0FFFFFFF)) & 0xFFFFFFFFFFFFFFFF

hits = {}
for name, sva, so, sz, ex in kc.SEGS:
    if ex: continue
    blob = k.d[so:so+sz]
    n = len(blob)//8
    w = np.frombuffer(blob[:n*8], dtype='<u8')
    lo = (w & np.uint64(0x0FFFFFFF)).astype(np.uint64) + np.uint64(BASE)
    for t, nm in ENTRY.items():
        idx = np.nonzero(lo == np.uint64(t))[0]
        for i in idx:
            va = sva + int(i)*8
            hits.setdefault(t, []).append((va, name))

for t, nm in ENTRY.items():
    print('==', nm, hex(t), 'slots:', len(hits.get(t, [])))
    for va, seg in hits.get(t, []):
        print('    slot', hex(va), seg)
