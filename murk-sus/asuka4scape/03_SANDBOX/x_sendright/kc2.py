#!/usr/bin/env python3
# kernelcache 27.2 fileset helper: kext slices, xrefs, disasm. sign masked.
import struct, json, sys
from capstone import *
from capstone.arm64 import *

KC = "/home/femboychik/work/x_sendright/kc272.bin"
BASE = 0xfffffff007004000
M64 = 0xFFFFFFFFFFFFFFFF
DATA = open(KC, "rb").read()

SEGS = [
    ("__TEXT",          0xfffffff007004000, 0x8000,     0x0),
    ("__PRELINK_TEXT",  0xfffffff00700c000, 0xbac000,   0x8000),
    ("__DATA_CONST",    0xfffffff007bb8000, 0x548000,   0xbb4000),
    ("__DATA_SPTM",     0xfffffff008100000, 0x4c000,    0x10fc000),
    ("__TEXT_EXEC",     0xfffffff00814c000, 0x2924000,  0x1148000),
    ("__TEXT_BOOT_EXEC",0xfffffff00aa70000, 0x8000,     0x3a6c000),
    ("__PRELINK_INFO",  0xfffffff00aa78000, 0x23c000,   0x3a74000),
    ("__DATA",          0xfffffff00acb4000, 0x2b8000,   0x3cb0000),
    ("__LINKEDIT",      0xfffffff00af6c000, 0xb8000,    0x3f68000),
]

def N(va):
    va &= M64
    if va < 0x100000000:
        va |= 0xFFFFFFF000000000
    return va

def va2off(va):
    va = N(va)
    for n, s, sz, off in SEGS:
        if s <= va < s + sz:
            return off + (va - s)
    return None

def seg_of(va):
    va = N(va)
    for n, s, sz, off in SEGS:
        if s <= va < s + sz:
            return n
    return None

def rd(va, n):
    o = va2off(N(va))
    if o is None: return None
    return DATA[o:o+n]

def u32(va):
    b = rd(va, 4)
    return struct.unpack("<I", b)[0] if b and len(b) == 4 else None

def u64(va):
    b = rd(va, 8)
    return struct.unpack("<Q", b)[0] if b and len(b) == 8 else None

def s64(va):
    b = rd(va, 8)
    return struct.unpack("<q", b)[0] if b and len(b) == 8 else None

def pac(q):
    return (BASE + (q & 0x0FFFFFFF)) & M64

def unpac(q):
    """return best-effort pointer: raw if mapped, else pac base+imm"""
    if q is None: return None
    q &= M64
    if (q >> 40) == 0xffffff and va2off(q) is not None: return q
    p = pac(q)
    if va2off(p) is not None: return p
    return None

def cstr(va, maxlen=200):
    b = rd(va, maxlen)
    if not b: return None
    return b.split(b"\0")[0].decode("latin1", "replace")

MD = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
MD.detail = True

def dis(va, n=0x400, count=0, stopret=True):
    off = va2off(N(va))
    if off is None: return []
    code = DATA[off:off+n]
    out = []
    for i in MD.disasm(code, va):
        out.append(i)
        if count and len(out) >= count: break
        if stopret and i.mnemonic == "ret": break
    return out

def show(va, n=0x200, count=0, addr_comment=True):
    for i in dis(va, n, count):
        extra = ""
        if i.mnemonic in ("bl","b","adrp") and i.operands:
            extra = ""
        print("%016x  %-8s %s" % (i.address, i.mnemonic, i.op_str))

# ---- kext slices ----
def parse_kexts():
    ncmds, szcmds = struct.unpack_from("<II", DATA, 16)
    off = 32; ents = []
    for i in range(ncmds):
        cmd, sz = struct.unpack_from("<II", DATA, off)
        if cmd == 0x80000035:
            vmaddr, fileoff, eid, res = struct.unpack_from("<QQII", DATA, off+8)
            name = DATA[off+32:off+sz].split(b"\0")[0].decode("latin1")
            ents.append({"name": name, "vmaddr": vmaddr, "fileoff": fileoff})
        off += sz
    for e in ents:
        h = e["fileoff"]; e["segs"] = []
        if h+32 > len(DATA): continue
        m, ct, cs, ft, nc, sc, fl = struct.unpack_from("<IIIIIII", DATA, h)
        o = h + 32
        for i in range(nc):
            if o+8 > len(DATA): break
            cmd, sz = struct.unpack_from("<II", DATA, o)
            if cmd == 0x19:
                seg = DATA[o+8:o+24].split(b"\0")[0].decode()
                va, vs = struct.unpack_from("<QQ", DATA, o+24)
                fo, fs = struct.unpack_from("<QQ", DATA, o+40)
                nsect = struct.unpack_from("<I", DATA, o+64)[0]
                secs = []
                so = o + 72
                for j in range(nsect):
                    sn = DATA[so:so+16].split(b"\0")[0].decode()
                    sva, ssz = struct.unpack_from("<QQ", DATA, so+32)
                    secs.append((sn, sva, ssz))
                    so += 80
                e["segs"].append({"seg": seg, "va": va, "vsize": vs, "fileoff": fo,
                                  "filesize": fs, "sects": secs})
            o += sz
    return ents

KEXTS = parse_kexts()
KEXT = {e["name"]: e for e in KEXTS}

def kext_code(name):
    """list of (start,end) code ranges (__TEXT_EXEC or __TEXT)"""
    e = KEXT[name]
    out = []
    for s in e["segs"]:
        if s["seg"] in ("__TEXT_EXEC", "__TEXT"):
            out.append((s["va"], s["va"]+s["vsize"]))
    return out

def adrp_target(insn):
    if insn.mnemonic != "adrp": return None
    imm = insn.operands[1].imm & 0xFFFFFFFF
    return N(imm)

def scan_adrp_to(va, ranges=None):
    """find adrp/add pairs (and adrp+ldr) that produce va. returns list of (addr, insn list)"""
    target_page = va & ~0xfff
    lo = va & 0xfff
    res = []
    ranges = ranges or [(s, s+sz) for n,s,sz,o in SEGS]
    for rs, re_ in ranges:
        off = va2off(rs)
        if off is None: continue
        blob = DATA[off:off+(re_-rs)]
        for i in range(0, len(blob)-4, 4):
            w = struct.unpack_from("<I", blob, i)[0]
            if (w & 0x9F000000) != 0x90000000: continue
            insva = rs + i
            rd_ = w & 0x1f
            immlo = (w >> 29) & 3
            immhi = (w >> 5) & 0x7ffff
            imm = (immhi << 2) | immlo
            if imm & (1 << 20): imm -= (1 << 21)
            page = ((insva & ~0xfff) + (imm << 12)) & M64
            if page != target_page: continue
            # look at next 1-3 insns
            nxt = dis(insva, 16, 3, stopret=False)
            if len(nxt) < 2: continue
            pg = adrp_target(nxt[0])
            hit = False
            for j in nxt[1:3]:
                for k, op in enumerate(j.operands):
                    if op.type == ARM64_OP_IMM and ((pg + op.imm) & M64) == va:
                        hit = True
                    if op.type == ARM64_OP_MEM and j.operands[1].type == ARM64_OP_MEM:
                        base = j.operands[1].mem
                        if base.base == (w & 0x1f) and ((pg + base.disp) & M64) == va:
                            hit = True
            if hit:
                res.append((insva, nxt))
    return res

def stub_target(va):
    """resolve adrp+add+ldr+braa GOT trampoline to final VA"""
    ins = dis(va, 16, 4, stopret=False)
    if len(ins) < 4: return None
    if ins[0].mnemonic != "adrp" or ins[1].mnemonic != "add": return None
    slot = (adrp_target(ins[0]) + ins[1].operands[2].imm) & M64
    q = u64(slot)
    if q is None: return None
    return (slot, q, unpac(q))

def stubs_of(kext):
    e = KEXT[kext]
    out = {}
    for s in e["segs"]:
        for sn, sva, ssz in s["sects"]:
            if sn == "__auth_stubs":
                for a in range(sva, sva+ssz, 16):
                    t = stub_target(a)
                    if t: out[a] = t
    return out

BTI = b"\x5f\x24\x03\xd5"
PACI = b"\x7f\x23\x03\xd5"
def func_start(va, back=0x2000):
    va=N(va); off=va2off(va)
    lo=max(0, off-back)
    blob=DATA[lo:off]
    i=blob.rfind(BTI)
    while i>=0:
        if blob[i+4:i+8]==PACI:
            return N(va-(off-(lo+i)))
        i=blob.rfind(BTI,0,i)
    return None
