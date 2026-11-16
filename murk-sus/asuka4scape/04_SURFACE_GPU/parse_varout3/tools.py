"""Shared toolkit for the 27.2 kernelcache var-output scan (attempt 3).

Load-bearing: capstone returns adrp operand.imm as SIGNED 64-bit (pre-relocation
page form). Always mask & 0xFFFFFFFFFFFFFFFF.
"""
import struct, bisect, array, json, re
import kc
from kc import DATA, SEGS, BASE, va2off, off2va, seg_of, q, d, cstr, TEXT_EXEC_VA, TEXT_EXEC_OFF, TEXT_EXEC_SIZE, TEXT_EXEC_END
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from capstone.arm64 import ARM64_OP_REG, ARM64_OP_MEM, ARM64_OP_IMM

M64 = 0xFFFFFFFFFFFFFFFF

md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
md.detail = True

# ---------------------------------------------------------------- pointers
def unpac(qq):
    """PAC/plain kernel pointer -> VA inside a mapped segment, else None."""
    if qq is None:
        return None
    if qq == 0:
        return None
    cand = None
    if (qq & 0xFFFF000000000000) == 0xFFFF000000000000:
        cand = qq                      # plain kernel VA (TBI untouched)
    elif (qq >> 60) != 0:
        cand = BASE + (qq & 0x0FFFFFFF)  # PAC: low 28 bits are the VA delta
    if cand is None:
        return None
    if seg_of(cand) is None:
        # tolerate 8-byte aligned pointers one past the end
        if seg_of(cand - 8) is None:
            return None
        cand -= 8
    if cand & 3:
        return None
    return cand

def codeptr(qq):
    v = unpac(qq)
    if v is None:
        return None
    if TEXT_EXEC_VA <= v < TEXT_EXEC_END:
        return v
    return None

# ---------------------------------------------------------------- functions
_offs = array.array('I')
_offs.frombytes(open("/home/femboychik/work/parse_varout3/funcstarts.bin", "rb").read())
STARTS = [TEXT_EXEC_VA + o for o in _offs]

def func_of(va):
    i = bisect.bisect_right(STARTS, va) - 1
    if i < 0:
        return None, None
    return STARTS[i], (STARTS[i + 1] if i + 1 < len(STARTS) else TEXT_EXEC_END)

def disasm_func(start, end=None, limit=None):
    s, e = func_of(start) if end is None else (start, end)
    if s is None:
        return []
    n = min(e - s, limit or 0x4000)
    return list(md.disasm(DATA[va2off(s):va2off(s) + n], s))

# ---------------------------------------------------------------- kext map
_segs = json.load(open("/home/femboychik/work/parse_varout3/kext_segmap.json"))
def _ranges(segname):
    out = []
    for x in _segs:
        sg = x['segs'].get(segname)
        if sg:
            out.append((sg[0], sg[0] + sg[1], x['name']))
    return sorted(out)

TXR = _ranges("__TEXT_EXEC"); DCR = _ranges("__DATA_CONST"); DR = _ranges("__DATA")
TXR_LO = [t[0] for t in TXR]; DCR_LO = [t[0] for t in DCR]; DR_LO = [t[0] for t in DR]
LAST_TX = max([t[1] for t in TXR]) if TXR else TEXT_EXEC_VA
LAST_DC = max([t[1] for t in DCR]) if DCR else 0
LAST_D  = max([t[1] for t in DR]) if DR else 0

def kext_of(va):
    i = bisect.bisect_right(TXR_LO, va) - 1
    if i >= 0 and TXR[i][0] <= va < TXR[i][1]:
        return TXR[i][2]
    if LAST_TX <= va < TEXT_EXEC_END:
        return "com.apple.kernel"
    return "?"

def kext_of_data(va):
    for LO, R in ((DCR_LO, DCR), (DR_LO, DR)):
        i = bisect.bisect_right(LO, va) - 1
        if i >= 0 and R[i][0] <= va < R[i][1]:
            return R[i][2]
    return "?"

# ---------------------------------------------------------------- adrp
def adrp_target(insn):
    """insn must be adrp. Returns absolute page (unsigned 64-bit)."""
    if insn.mnemonic != "adrp" or not insn.operands:
        return None
    op = insn.operands[1]
    if op.type != ARM64_OP_IMM:
        return None
    return op.imm & M64          # <-- THE BUG FIX

def adrp_add(insns, i, maxlook=6):
    """From adrp at insns[i], find the (dst_reg, target_va) of a following add/ldr.
    Returns (dst_reg_name, target_va, j) or None."""
    if i >= len(insns):
        return None
    ins0 = insns[i]
    page = adrp_target(ins0)
    if page is None:
        return None
    rd = md.reg_name(ins0.operands[0].reg)
    for j in range(i + 1, min(i + 1 + maxlook, len(insns))):
        ins = insns[j]
        if ins.mnemonic == "add" and len(ins.operands) == 3:
            if md.reg_name(ins.operands[1].reg) != rd:
                continue
            if ins.operands[2].type != ARM64_OP_IMM:
                continue
            return (md.reg_name(ins.operands[0].reg),
                    (page + (ins.operands[2].imm & M64)) & M64, j)
        if ins.mnemonic in ("ldr", "ldur", "ldrsw") and len(ins.operands) == 2 \
                and ins.operands[1].type == ARM64_OP_MEM \
                and md.reg_name(ins.operands[1].mem.base) == rd:
            return (md.reg_name(ins.operands[0].reg),
                    (page + (ins.operands[1].mem.disp & M64)) & M64, j)
    return None

def canon(reg):
    n = md.reg_name(reg)
    if not n:
        return None
    if n[0] == 'w' and n[1:].isdigit():
        return 'x' + n[1:]
    if n[0] in 'bh':
        return 'x' + n[1:]
    if n == 'sp' or n == 'wsp':
        return 'sp'
    if n == 'xzr' or n == 'wzr':
        return 'zr'
    return n

def rn(reg):
    return int(md.reg_name(reg)[1:])

# ---------------------------------------------------------------- dispatch tables
def parse_entry(a, stride):
    qq = q(a)
    t = codeptr(qq)
    if t is None:
        return None
    f = []
    for k in range(4):
        v = d(a + 8 + 4 * k)
        if v is None:
            return None
        if v != 0xffffffff and v > 0x400000:      # counts are small or the 0xffffffff sentinel
            return None
        f.append(v)
    extra = 0
    ent = None
    if stride == 0x28:
        # IOExternalMethodDispatch2022: +0x18 allowAsync(1B)+pad, +0x20 const char *checkEntitlement
        extra = d(a + 0x18)
        entq = q(a + 0x20)
        if entq:
            ent = unpac(entq)
            if ent is None:
                return None
            s = cstr(ent, 200)
            if not s or not s.startswith("com.apple."):
                return None
            ent = s
    return dict(target=t, f=f, extra=extra, ent=ent)

def find_tables():
    tables = []
    for segname in ("__DATA_CONST", "__DATA", "__DATA_SPTM"):
        sva, soff, ssize = SEGS[segname]
        for stride in (0x28, 0x18):
            a = sva + 8
            while a < sva + ssize - stride:
                if parse_entry(a, stride) is None:
                    a += 8
                    continue
                # cheap left extension
                base = a
                while base - stride >= sva and parse_entry(base - stride, stride) is not None:
                    base -= stride
                run = []
                cur = base
                while cur + stride <= sva + ssize:
                    e = parse_entry(cur, stride)
                    if e is None:
                        break
                    run.append((cur, e))
                    cur += stride
                if len(run) >= 3:
                    tables.append(dict(seg=segname, base=base, stride=stride,
                                       count=len(run), kext=kext_of_data(base),
                                       ents=[dict(addr=x, target=y['target'], f=y['f'],
                                                  extra=y['extra'], ent=y['ent'])
                                             for x, y in run]))
                a = max(cur, a + 8)
    # dedupe: same base covered by a bigger-stride table wins
    tables.sort(key=lambda t: (-t['stride'], -t['count'], t['base']))
    keep = []
    for t in tables:
        lo, hi = t['base'], t['base'] + t['stride'] * t['count']
        dup = False
        for k in keep:
            if k['base'] <= t['base'] and hi <= k['base'] + k['stride'] * k['count'] and k['stride'] >= t['stride']:
                dup = True
                break
        if not dup:
            keep.append(t)
    return sorted(keep, key=lambda t: t['base'])

# ---------------------------------------------------------------- stubs / thunks
def follow_stub(va, depth=0):
    """Resolve a dispatch-table target to the real function.
    Handles: b <imm>  (tail thunk), and the GOT trampoline
    adrp x17,page; add x17,x17,#imm; ldr x16,[x17]; braa x16,x17."""
    if depth > 4:
        return va
    o = va2off(va)
    if o is None:
        return va
    insns = list(md.disasm(DATA[o:o + 32], va))
    if not insns:
        return va
    k = 0
    while k < len(insns) and insns[k].mnemonic == "bti":
        k += 1
    if k >= len(insns):
        return va
    ins = insns[k]
    if ins.mnemonic == "b" and ins.operands and ins.operands[0].type == ARM64_OP_IMM:
        tgt = ins.operands[0].imm & M64
        if TEXT_EXEC_VA <= tgt < TEXT_EXEC_END and tgt != va:
            return follow_stub(tgt, depth + 1)
        return va
    # GOT trampoline: find adrp within first 4 insns, then add, then ldr, then braa
    page = None
    for j in range(k, min(k + 3, len(insns))):
        if insns[j].mnemonic == "adrp":
            page = adrp_target(insns[j])
            pa = md.reg_name(insns[j].operands[0].reg)
            break
    if page is None:
        return va
    slot = None
    for j in range(k, min(k + 5, len(insns))):
        m = insns[j]
        if m.mnemonic == "add" and len(m.operands) == 3 and md.reg_name(m.operands[1].reg) == pa:
            slot = (page + (m.operands[2].imm & M64)) & M64
            break
        if m.mnemonic in ("ldr", "ldur") and len(m.operands) == 2 and m.operands[1].type == ARM64_OP_MEM:
            slot = (page + (m.operands[1].mem.disp & M64)) & M64
            break
    if slot is None:
        return va
    v = q(slot)
    t = codeptr(v)
    if t is None or t == va:
        return va
    return follow_stub(t, depth + 1)

def is_got_stub(va):
    o = va2off(va)
    if o is None:
        return False
    w = list(struct.unpack_from("<4I", DATA, o))
    return any((x & 0x9F000000) == 0x90000000 for x in w[:3]) and \
           any((x & 0xFFC00000) == 0xF9400000 for x in w[:5]) and \
           any((x & 0xFFFFFC1F) == 0xD71F0800 for x in w[:6])
