import struct, bisect
from kc import load
k=load()
# build reverse index of all 8-byte-aligned qwords in data segments
DATA_SEGS=['__DATA_CONST','__DATA','__DATA_SPTM']
_idx={}
for sn in DATA_SEGS:
    s=k.seg_by_name[sn]
    n=s['filesize']//8
    qs=struct.unpack_from('<%dQ'%n, k.data, s['fileoff'])
    base=s['vmaddr']
    for i,q in enumerate(qs):
        # accept raw and pac-masked forms
        cand={q}
        cand.add(0xfffffff007004000 + (q & 0x0FFFFFFF))
        for c in cand:
            _idx.setdefault(c,[]).append(base+i*8)
def refs_to(va):
    return sorted(set(_idx.get(va,[])))
