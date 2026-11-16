"""Step 1: string index + code->string xrefs (raw word decode, adrp imm masked)."""
import sys, re, array, struct, json, bisect
sys.path.insert(0, "/home/femboychik/work/parse_varout3")
from tools import *

# ---- collect candidate strings (VA of the first byte)
strva = {}          # va -> text
pat = re.compile(rb"[\x20-\x7e]{6,200}")
for name in ("__PRELINK_TEXT", "__TEXT", "__DATA_CONST", "__DATA", "__PRELINK_INFO"):
    sva, soff, ssize = SEGS[name]
    buf = DATA[soff:soff + ssize]
    for m in pat.finditer(buf):
        s = m.group()
        if b"com.apple." not in s and b"entitlement" not in s.lower():
            continue
        va = sva + m.start()
        strva[va] = s.decode("ascii", "replace")
        # a cstring may be the tail of a longer constant run; also register its
        # interior offsets so adrp+add landing mid-string still resolves
SV = sorted(strva)
print("strings indexed:", len(SV))

# ---- raw adrp scan of __TEXT_EXEC
buf = DATA[TEXT_EXEC_OFF:TEXT_EXEC_OFF + TEXT_EXEC_SIZE]
a = array.array('I'); a.frombytes(buf)
n = len(a)
def sx21(v):
    return v - (1 << 21) if v & (1 << 20) else v

def add_imm(w):
    # ADD (immediate) 64-bit: sf=1 op=0 S=0 -> 0x91000000
    if (w & 0xFF800000) != 0x91000000:
        return None
    sh = (w >> 22) & 1
    imm = (w >> 10) & 0xFFF
    return imm << (12 if sh else 0)

def ldr_imm(w):
    if (w & 0xFFC00000) != 0xF9400000:
        return None
    return ((w >> 10) & 0xFFF) * 8

hits = []       # (func_start, str_va, adrp_va, kind)
SVSET = set(SV)
for i in range(n - 4):
    w = a[i]
    if (w & 0x9F000000) != 0x90000000:
        continue
    va = TEXT_EXEC_VA + i * 4
    page = (va & ~0xFFF)
    imm = sx21(((w >> 5) & 0x7FFFF) << 2 | ((w >> 29) & 3))
    tpage = page + (imm << 12)
    rd = w & 0x1F
    for j in range(1, 5):
        wj = a[i + j]
        if (wj & 0x1F) != rd:      # source reg must be the adrp dst
            continue
        imm2 = add_imm(wj)
        kind = "add"
        if imm2 is None:
            imm2 = ldr_imm(wj)
            kind = "ldr"
        if imm2 is None:
            continue
        tgt = tpage + imm2
        if tgt in SVSET:
            fs, _ = func_of(va)
            if fs:
                hits.append((fs, tgt, va, kind))
        break

print("string xrefs:", len(hits), "funcs:", len(set(h[0] for h in hits)))
json.dump([(h[0], h[1], h[2], h[3]) for h in hits],
          open("/home/femboychik/work/parse_varout3/strxref.json", "w"))
json.dump({str(k): v for k, v in strva.items()},
          open("/home/femboychik/work/parse_varout3/strings.json", "w"))

# ---- per-func entitlement strings
f2s = {}
for fs, sv, _, _ in hits:
    t = strva[sv]
    if "com.apple." in t:
        f2s.setdefault(fs, set()).add(t)
json.dump({str(k): sorted(v) for k, v in f2s.items()},
          open("/home/femboychik/work/parse_varout3/func_entstrings.json", "w"))
print("funcs referencing entitlement-looking strings:", len(f2s))
from collections import Counter
c = Counter()
for v in f2s.values():
    for t in v:
        c[t] += 1
for k, v in c.most_common(25):
    print(f"  {v:4d} {k}")
