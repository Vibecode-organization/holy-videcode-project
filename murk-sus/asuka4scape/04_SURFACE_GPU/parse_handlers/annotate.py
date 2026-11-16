#!/usr/bin/env python3
"""Full annotated dump of IOSurfaceRoot external methods (27.2 / 24B115).

Follows the one-level `b <real>` trampoline used by the dispatch shims, stops at
the first retab/ret, and resolves GOT-thunk call targets (adrp+add; ldr; braa)
to the real kernel function they jump to.

Outputs (into OUT):
  handlers_annotated.txt  - per selector: metadata, args fields touched, call map,
                            full disassembly with `; call -> <target>` annotations
  args_matrix.txt         - one line per selector: sel fn sIn strIn sOut strOut fl | fields | calls
"""
import sys, os, struct
import capstone

KC = sys.argv[1] if len(sys.argv) > 1 else "/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache"
OUT = sys.argv[2] if len(sys.argv) > 2 else os.path.join(os.path.dirname(os.path.abspath(__file__)), "out2")
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
TABLE_A = 0xfffffff008068b90
TABLE_B = 0xfffffff0080694f0

ARGS = {
    0x20: "scalarIn", 0x28: "scalarInCnt", 0x30: "structIn", 0x38: "structInSize",
    0x40: "structInDesc", 0x48: "scalarOut", 0x50: "scalarOutCnt", 0x58: "structOut",
    0x60: "structOutSize", 0x68: "structOutDesc", 0x70: "structOutDescSize", 0x78: "varOut",
}
data = open(KC, "rb").read()


def rd(va, n):
    if va is None:
        return b""
    for _n, vm, vs, fo in SEGS:
        if vm <= va < vm + vs:
            return data[fo + (va - vm): fo + (va - vm) + n]
    return b""


def dec_ptr(q):
    if not q:
        return None
    t = KB + (q & 0x0FFFFFFF)
    return t if KB <= t < 0xfffffff00b000000 else None


def fix_branch(imm):
    # capstone already resolves branches to absolute VAs (often negative as signed 64-bit)
    return imm & 0xFFFFFFFFFFFFFFFF


md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
md.detail = True


def disasm_body(va, limit=0x400):
    """Disassemble from va, stopping at the first retab/ret (or a b/branch that is
    an unconditional tail call at the very start)."""
    ins = []
    for i in md.disasm(rd(va, limit), va):
        ins.append(i)
        if i.mnemonic in ("retab", "ret"):
            break
    return ins


def follow_shim(entry):
    """If entry starts with `bti c` + optional `b <real>` within the first 8 insns,
    return the branch target."""
    ins = list(md.disasm(rd(entry, 8 * 4), entry))
    for i in ins[:8]:
        if i.mnemonic == "b" and i.operands and i.operands[0].type == capstone.arm64.ARM64_OP_IMM:
            return fix_branch(i.operands[0].imm)
        if i.mnemonic in ("retab", "ret"):
            break
    return entry


def resolve_thunk(va):
    """adrp x17,page ; add x17,x17,#imm ; ldr x16,[x17] ; braa x16,x17 -> returns
    (slot_addr, target_va) or None."""
    ins = list(md.disasm(rd(va, 4 * 6), va))
    page = None
    for i in ins:
        if i.mnemonic == "adrp":
            page = i.operands[1].imm & 0xFFFFFFFFFFFFFFFF
        elif i.mnemonic == "add" and page is not None and len(i.operands) == 3 \
                and i.operands[2].type == capstone.arm64.ARM64_OP_IMM:
            slot = page + i.operands[2].imm
            raw = rd(slot, 8)
            if len(raw) < 8:
                return None
            q = struct.unpack_from("<Q", raw)[0]
            tgt = dec_ptr(q)
            return slot, tgt
    return None


def cstr(va, lim=160):
    b = rd(va, lim)
    z = b.find(b"\0")
    return b[: z if z >= 0 else lim].decode("latin1", "replace")


with open(os.path.join(OUT, "handlers_annotated.txt"), "w") as out, \
        open(os.path.join(OUT, "args_matrix.txt"), "w") as mat:
    mat.write("sel entry real sIn strIn sOut strOut fl | fields | call targets\n")
    for label, T in (("A", TABLE_A), ("B", TABLE_B)):
        out.write(f"\n{'='*90}\nTABLE {label} @ {T:#x}\n{'='*90}\n")
        for sel in range(60):
            raw = rd(T + sel * 40, 40)
            if len(raw) < 40:
                break
            q = struct.unpack_from("<Q", raw)[0]
            entry = dec_ptr(q)
            a, b, c, e, f = struct.unpack_from("<IIIII", raw, 8)
            if not entry:
                out.write(f"\n### {label} sel {sel}: NULL entry\n")
                continue
            real = follow_shim(entry)
            if real != entry:
                ins = []
                for i in md.disasm(rd(entry, 0x40), entry):
                    ins.append(i)
                    if i.mnemonic in ("b", "retab", "ret"):
                        break
                ins += disasm_body(real)
            else:
                ins = disasm_body(entry)
            fields, calls, strings = set(), [], []
            for idx, i in enumerate(ins):
                for op in i.operands:
                    if op.type == capstone.arm64.ARM64_OP_MEM and op.mem.base:
                        rn = i.reg_name(op.mem.base)
                        if rn in ("x2", "x20") and op.mem.disp in ARGS:
                            fields.add(ARGS[op.mem.disp])
                        if rn == "x0" and 0x100 <= op.mem.disp <= 0x140:
                            fields.add(f"self{op.mem.disp:#x}")
                if i.mnemonic == "bl" and i.operands and i.operands[0].type == capstone.arm64.ARM64_OP_IMM:
                    t = resolve_thunk(fix_branch(i.operands[0].imm))
                    calls.append((i.address, t))
                if i.mnemonic == "adrp" and idx + 1 < len(ins):
                    nxt = ins[idx + 1]
                    if nxt.mnemonic == "add" and nxt.operands[1].type == capstone.arm64.ARM64_OP_REG \
                            and nxt.operands[1].reg == i.operands[0].reg \
                            and nxt.operands[2].type == capstone.arm64.ARM64_OP_IMM:
                        s = cstr(nxt.operands[2].imm, 80)
                        if len(s) > 3 and all(32 <= ord(ch) < 127 or ch in "\n\t" for ch in s):
                            strings.append((i.address, s))
            hdr = (f"\n### {label} sel {sel}  entry={entry:#x}  real={real:#x}  "
                   f"sIn={a} strIn={b if b != 0xffffffff else -1} "
                   f"sOut={c} strOut={e if e != 0xffffffff else -1} flags={f}")
            out.write(hdr + "\n")
            out.write(f"# args: {', '.join(sorted(fields)) or '-'}\n")
            for addr, t in calls:
                if t:
                    out.write(f"# call @{addr:x} -> slot {t[0]:#x} -> {t[1]:#x}\n")
                else:
                    out.write(f"# call @{addr:x} -> (direct/unknown)\n")
            for addr, s in strings:
                out.write(f'# str  @{addr:x} "{s}"\n')
            callmap = {addr: t for addr, t in calls}
            for i in ins:
                note = ""
                if i.address in callmap and callmap[i.address]:
                    note = f"   ; -> {callmap[i.address][1]:#x}"
                out.write(f"{i.address:016x}  {i.mnemonic:8s} {i.op_str}{note}\n")
            if label == "A":
                tgts = ",".join(f"{t[1]:#x}" if t else "?" for _, t in calls)
                mat.write(f"{sel:3d} {entry:#x} {real:#x} {a:3d} "
                          f"{b if b != 0xffffffff else -1:5d} {c:4d} "
                          f"{e if e != 0xffffffff else -1:6d} {f} | "
                          f"{','.join(sorted(fields)) or '-'} | {tgts}\n")
print(f"wrote {OUT}/handlers_annotated.txt and {OUT}/args_matrix.txt")
