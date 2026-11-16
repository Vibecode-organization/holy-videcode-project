#!/usr/bin/env python3
"""full-image 8-byte pointer index: target VA -> [slot VAs]."""
import numpy as np, kc

BASE = np.uint64(0xfffffff007004000)
MASKA = np.uint64(0x3FFFFFFF)

REC = []   # (target, slot)
def build():
    for name, vm, vs, fo, fs in kc.SEGS:
        if name in ("__LINKEDIT",):
            continue
        n = fs // 8
        if n == 0:
            continue
        arr = np.frombuffer(kc.BLOB, dtype="<u8", count=n, offset=fo)
        auth = (arr >> np.uint64(63)) == 1
        low = arr < np.uint64(0x40000000)
        tgt = arr.copy()
        tgt[auth] = BASE + (arr[auth] & MASKA)
        tgt[low] = BASE + arr[low]
        keep = auth | low
        idx = np.nonzero(keep)[0]
        vms = vm + idx.astype(np.uint64) * np.uint64(8)
        REC.append((tgt[idx], vms, name))

build()
_T = np.concatenate([r[0] for r in REC])
_S = np.concatenate([r[1] for r in REC])
_N = np.concatenate([np.full(len(r[0]), i, dtype=np.int64) for i, r in enumerate(REC)])
ORDER = np.argsort(_T)
_Ts = _T[ORDER]

def refs(target, limit=64):
    i = np.searchsorted(_Ts, np.uint64(target))
    out = []
    while i < len(_Ts) and _Ts[i] == np.uint64(target) and len(out) < limit:
        out.append((kc.SEGS[_N[ORDER[i]]][0], int(_S[ORDER[i]])))
        i += 1
    return out

def where(va):
    for n, vm, vs, fo, fs in kc.SEGS:
        if vm <= va < vm + fs:
            return n
    return "?"

if __name__ == "__main__":
    print("indexed", len(_T))
