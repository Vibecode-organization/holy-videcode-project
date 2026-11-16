"""compare 27.0 vs 27.2 for the unserialize family by normalized disasm hash"""
import struct, hashlib, pickle, sys
from capstone import *
from kc import KC, SEGS, KC27_0, KC27_2
import xr

STRINGS = {
 'xml_fmt': b'OSUnserializeXML: %s near line %d',
 'os_fmt' : b'OSUnserialize: %s near line %d',
 'maxobj' : b'maximum object count',
 'fwdref' : b'forward reference detected',
 'dupkey' : b'duplicate dictionary key',
 'memexh' : b'mem exhausted',
 's_create_surface': b's_create_surface',
 'create_surface'  : b'create_surface',
}

def find_va_by_string(kc, s):
    va = kc.find_bytes(s, segs=('__PRELINK_TEXT','__TEXT_EXEC','__DATA_CONST'))
    return va[0] if va else None

def funcs_ref(kc, target):
    """functions whose body references target (adrp+add/ldr)"""
    st, refs = build_or_load(kc)
    out = []
    for f, lst in refs.items():
        for a, t in lst:
            if t == target:
                out.append(f); break
    return out, st

_pk = {}
def build_or_load(kc):
    key = kc.path
    if key in _pk: return _pk[key]
    st = []
    for n, sva, so, sz, ex in xr.text_segs():
        W = struct.unpack('<%dI' % (sz // 4), kc.d[so:so + sz])
        for i, w in enumerate(W):
            if w in (0xD503237F, 0xD503233F):
                st.append(sva + i * 4)
    st = sorted(st)
    refs = {}
    import bisect
    for idx, s in enumerate(st):
        e = st[idx + 1] if idx + 1 < len(st) else s + 0x2000
        o = kc.va2off(s); size = min(e - s, 0x4000)
        W = struct.unpack('<%dI' % (size // 4), kc.d[o:o + size])
        lst = []
        for i, w in enumerate(W):
            r = xr.dec_adrp(w, s + i * 4)
            if not r: continue
            rd, page = r
            for j in range(i + 1, min(i + 4, len(W))):
                a = xr.dec_add_imm(W[j]); tgt = None
                if a and a[1] == rd: tgt = page + a[2]
                else:
                    l = xr.dec_ldr_imm(W[j])
                    if l and l[1] == rd: tgt = page + l[2]
                if tgt is not None:
                    lst.append((s + i * 4, tgt & 0xFFFFFFFFFFFFFFFF)); break
        refs[s] = lst
    _pk[key] = (st, refs)
    return st, refs

def norm_hash(kc, f, n=None):
    st, refs = build_or_load(kc)
    import bisect
    i = bisect.bisect_right(st, f)
    e = st[i] if i < len(st) else f + 0x1000
    if n: e = f + n
    md = Cs(CS_ARCH_ARM64, CS_MODE_ARM); md.detail = False
    o = kc.va2off(f)
    out = []
    for ins in md.disasm(kc.d[o:o + (e - f)], f):
        s = ins.mnemonic + ' ' + ins.op_str
        out.append(s)
    h = hashlib.sha256('\n'.join(out).encode()).hexdigest()
    return h, len(out), e - f
