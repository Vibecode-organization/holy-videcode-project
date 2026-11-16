#!/usr/bin/env python3
"""Dump IOSurfaceRoot external-method tables + handlers from a 27.2 kernelcache.

Usage: python3 dump_handlers.py [kernelcache] [outdir]

Facts baked in (27.2 / 24B115):
  externalMethod @ 0xfffffff009c3ee14
  table A 0xfffffff008068b90 (client without [self+0x127]&1), table B 0xfffffff0080694f0
  stride 0x28, 60 entries, layout: fn(8) sIn(4) strIn(4) sOut(4) strOut(4) flags(4)
  data pointers PAC-encoded: (q>>32)==0x8050bcad, VA = kernel_base + (q & 0x0FFFFFFF)
"""
import sys, os, struct
import capstone

KC = sys.argv[1] if len(sys.argv) > 1 else "/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache"
OUT = sys.argv[2] if len(sys.argv) > 2 else os.path.join(os.path.dirname(os.path.abspath(__file__)), "out")
os.makedirs(OUT, exist_ok=True)

SEGS = [
    ("__TEXT", 0xfffffff007004000, 0x8000, 0x0),
    ("__PRELINK_TEXT", 0xfffffff00700c000, 0xbac000, 0x8000),
    ("__DATA_CONST", 0xfffffff007bb8000, 0x548000, 0xbb4000),
    ("__DATA_SPTM", 0xfffffff008100000, 0x4c000, 0x10fc000),
    ("__TEXT_EXEC", 0xfffffff00814c000, 0x2924000, 0x1148000),
    ("__TEXT_BOOT_EXEC", 0xfffffff00aa70000, 0x8000, 0x3a6c000),
    ("__PRELINK_INFO", 0xfffffff00aa78000, 0x23c000, 0x3a74000),
    ("__DATA", 0xfffffff00acb4000, 0x2b8000, 0x3cb0000),
    ("__LINKEDIT", 0xfffffff00af6c000, 0xb8000, 0x3f68000),
]
KB = SEGS[0][1]
PAC = 0x8050bcad
TABLES = {"A": 0xfffffff008068b90, "B": 0xfffffff0080694f0}
ARGS_FIELDS = {
    0x20: "scalarIn", 0x28: "scalarInCnt", 0x30: "structIn", 0x38: "structInSize",
    0x40: "structInDesc", 0x48: "scalarOut", 0x50: "scalarOutCnt", 0x58: "structOut",
    0x60: "structOutSize", 0x68: "structOutDesc", 0x70: "structOutDescSize", 0x78: "varOut",
}

data = open(KC, "rb").read()


def rd(va, n):
    for _name, vm, vs, fo in SEGS:
        if vm <= va < vm + vs:
            return data[fo + (va - vm): fo + (va - vm) + n]
    return b""


def dec_ptr(q):
    if q == 0:
        return 0
    if (q >> 32) != PAC:
        return None
    return KB + (q & 0x0FFFFFFF)


def fix_branch(imm):
    t = imm & 0xFFFFFFFF
    if t & 0x80000000:
        t |= 0xFFFFFFF000000000
    return t


def cstr(va, lim=200):
    b = rd(va, lim)
    z = b.find(b"\0")
    return b[: z if z >= 0 else lim].decode("latin1", "replace")


md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
md.detail = True

summary = open(os.path.join(OUT, "matrix.txt"), "w")
summary.write("sel fn start sIn strIn sOut strOut fl insns tail fields\n")
full = open(os.path.join(OUT, "handlers.txt"), "w")

for label, T in TABLES.items():
    full.write(f"\n\n########## table {label} @ {T:#x}\n")
    for sel in range(60):
        q = struct.unpack_from("<Q", rd(T + sel * 40, 8))[0]
        fn = dec_ptr(q)
        a, b, c, e, f = struct.unpack_from("<IIIII", rd(T + sel * 40 + 8, 20))
        if not fn:
            continue
        ins = []
        fields = set()
        for i in md.disasm(rd(fn, 0x200), fn):
            ins.append(i)
            for op in i.operands:
                if op.type == capstone.arm64.ARM64_OP_MEM and op.mem.base:
                    rn = i.reg_name(op.mem.base)
                    if rn in ("x2", "x20") and op.mem.disp in ARGS_FIELDS:
                        fields.add(ARGS_FIELDS[op.mem.disp])
                    if rn == "x0" and 0x100 <= op.mem.disp <= 0x140:
                        fields.add(f"self{op.mem.disp:#x}")
            if i.mnemonic in ("retab", "ret", "b", "br", "braa", "braaz", "brraa"):
                break
        tail = "?"
        if ins and ins[-1].mnemonic == "b" and ins[-1].operands and ins[-1].operands[0].type == capstone.arm64.ARM64_OP_IMM:
            tail = f"b->{fix_branch(ins[-1].operands[0].imm):#x}"
        elif ins and ins[-1].mnemonic in ("retab", "ret"):
            tail = "ret"
        elif ins:
            tail = ins[-1].mnemonic
        if label == "A":
            summary.write(
                f"{sel:3d} {fn:#x} {len(ins):4d} {a:3d} {b if b != 0xffffffff else -1:5d} "
                f"{c:4d} {e if e != 0xffffffff else -1:6d} {f} {tail} {','.join(sorted(fields))}\n")
        full.write(f"\n### {label} sel {sel} fn {fn:#x} sIn={a} strIn={b if b != 0xffffffff else -1} "
                   f"sOut={c} strOut={e if e != 0xffffffff else -1} fl={f}\n")
        full.write("\n".join(f"{i.address:x} {i.mnemonic} {i.op_str}" for i in ins) + "\n")

summary.close()
full.close()
print(f"wrote {OUT}/matrix.txt and {OUT}/handlers.txt")
