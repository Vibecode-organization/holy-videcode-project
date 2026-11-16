import struct, json, pickle, os
from kc import KC, SEGS
import xr

kc = KC()

def func_starts():
    starts = []
    for seg in xr.text_segs():
        n, sva, so, sz, ex = seg
        W = struct.unpack('<%dI' % (sz // 4), kc.d[so:so + sz])
        for i, w in enumerate(W):
            if w == 0xD503237F:  # pacibsp
                starts.append(sva + i * 4)
            elif w == 0xD503233F:  # paciasp
                starts.append(sva + i * 4)
    return sorted(starts)

def build():
    st = func_starts()
    print('func starts', len(st))
    # map each function -> list of (insn_va, target_string_va)
    refs = {}
    for idx, s in enumerate(st):
        e = st[idx + 1] if idx + 1 < len(st) else s + 0x2000
        o = kc.va2off(s)
        size = min(e - s, 0x4000)
        W = struct.unpack('<%dI' % (size // 4), kc.d[o:o + size])
        lst = []
        for i, w in enumerate(W):
            r = xr.dec_adrp(w, s + i * 4)
            if not r:
                continue
            rd, page = r
            for j in range(i + 1, min(i + 4, len(W))):
                a = xr.dec_add_imm(W[j])
                tgt = None
                if a and a[1] == rd:
                    tgt = page + a[2]
                else:
                    l = xr.dec_ldr_imm(W[j])
                    if l and l[1] == rd:
                        tgt = page + l[2]
                if tgt is not None:
                    lst.append((s + i * 4, tgt & 0xFFFFFFFFFFFFFFFF))
                    break
        refs[s] = lst
    return st, refs

if __name__ == '__main__':
    st, refs = build()
    pickle.dump((st, refs), open('funcs.pkl', 'wb'))
    print('saved')
