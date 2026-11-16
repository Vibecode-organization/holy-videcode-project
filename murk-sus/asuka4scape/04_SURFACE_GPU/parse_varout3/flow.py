"""Abstract interpreter for kext method handlers: tracks IOExternalMethodArguments*
and the structureVariableOutputData (args+0x78) pointer through one function.

Tag = ('A', off)  register holds args pointer + off
      'V'         register holds the value loaded from args+0x78 (varout target)
      'O'         anything else / unknown
"""
import sys, json, struct
sys.path.insert(0, "/home/femboychik/work/parse_varout3")
from tools import *
from capstone.arm64 import ARM64_OP_REG, ARM64_OP_MEM, ARM64_OP_IMM

CALLER_SAVED = list(range(0, 19)) + [30]
ARG_OFF = {0x20: "scalarInput", 0x28: "scalarInputCount", 0x30: "structureInput",
           0x38: "structureInputSize", 0x40: "structureInputDescriptor",
           0x48: "scalarOutput", 0x50: "scalarOutputCount",
           0x58: "structureOutput", 0x60: "structureOutputSize",
           0x68: "structureOutputDescriptor", 0x70: "structureOutputDescriptorSize",
           0x78: "structureVariableOutputData"}

def _r(ins, i):
    op = ins.operands[i]
    return canon(op.reg) if op.type == ARM64_OP_REG else None

def _mem(ins, i):
    op = ins.operands[i]
    return op.mem if op.type == ARM64_OP_MEM else None

def _imm(ins, i):
    op = ins.operands[i]
    return (op.imm & M64) if op.type == ARM64_OP_IMM else None

def analyze(start, tags=None, max_bytes=0x3000, follow_b=True, stop_at_ret=True):
    """Returns dict with events. tags: {'x2': ('A',0)} etc."""
    insns = []
    s, e = func_of(start)
    if s is None:
        return None
    end = min(e, start + max_bytes)
    insns = list(md.disasm(DATA[va2off(start):va2off(start) + (end - start)], start))
    T = {}
    for i in range(31):
        T['x%d' % i] = 'O'
    for k, v in (tags or {}).items():
        T[k] = v
    slots = {}           # entry-sp-relative byte offset -> tag
    spd = 0
    out = dict(writes=[], field_stores=[], loads=[], calls=[], gates=[],
               indirect=[], tail=[], ret_vals=[], start=s, end=end)
    prev = None
    for idx, ins in enumerate(insns):
        m = ins.mnemonic
        n = len(ins.operands)
        # --- stack frame deltas
        pre = ins.op_str.rstrip().endswith("!")
        post = (n == 3 and ins.operands[-1].type == ARM64_OP_IMM and m in ('ldp', 'stp', 'ldr', 'str'))
        mem0 = _mem(ins, 1) if n > 1 else None
        membase_sp = mem0 is not None and canon(mem0.base) == 'sp'

        if m in ('sub', 'add') and n == 3 and _r(ins, 0) == 'sp' and _r(ins, 1) == 'sp':
            v = _imm(ins, 2) or 0
            spd = spd - v if m == 'sub' else spd + v
            continue
        if m in ('stp', 'str', 'stur', 'strb', 'strh') and membase_sp:
            srcs = []
            if m in ('stp',):
                srcs = [(_r(ins, 0), 0), (_r(ins, 1), 8)]
            else:
                srcs = [(_r(ins, 0), 0)]
            base = spd + (mem0.disp if not pre else mem0.disp)
            if pre:
                spd += mem0.disp
                base = spd
            for reg, extra in srcs:
                if reg is None:
                    continue
                slots[base + extra] = T.get(reg, 'O')
            if post:
                spd += _imm(ins, 2) or 0
            continue
        if m in ('ldp', 'ldr', 'ldur', 'ldrb', 'ldrh', 'ldrsw', 'ldrsb') and membase_sp:
            base = spd + mem0.disp
            if post:
                base = spd
            if m == 'ldp':
                d0, d1 = _r(ins, 0), _r(ins, 1)
                if d0: T[d0] = slots.get(base, 'O')
                if d1: T[d1] = slots.get(base + 8, 'O')
            else:
                d0 = _r(ins, 0)
                if d0:
                    T[d0] = slots.get(base, 'O') if m in ('ldr', 'ldur') else 'O'
            if post:
                spd += _imm(ins, 2) or 0
            continue
        # --- plain reg moves
        if m == 'mov' and n == 2 and _r(ins, 0) and _r(ins, 1):
            T[_r(ins, 0)] = T.get(_r(ins, 1), 'O')
            continue
        if m in ('add', 'sub') and n == 3 and _r(ins, 0) and _r(ins, 1) and _imm(ins, 2) is not None:
            d, b = _r(ins, 0), _r(ins, 1)
            v = _imm(ins, 2)
            if m == 'sub':
                v = (-v) & M64
                if v > 0x7fffffff:
                    v -= 1 << 64
            t = T.get(b, 'O')
            if isinstance(t, tuple) and t[0] == 'A':
                T[d] = ('A', (t[1] + v) & M64)
            elif t == 'V' and v == 0:
                T[d] = 'V'
            else:
                T[d] = 'O'
            continue
        # --- memory ops on tagged pointers
        if m in ('ldr', 'ldur', 'ldrb', 'ldrh', 'ldrsw', 'ldrsb', 'ldp') and n >= 2:
            mm = _mem(ins, 1)
            if mm is not None:
                base = canon(mm.base)
                off = mm.disp
                t = T.get(base, 'O')
                if m == 'ldrb' and 0x100 <= off < 0x200 and base == 'x0':
                    out['gates'].append(dict(kind='objflag', va=ins.address, off=off,
                                             next=insns[idx + 1].mnemonic if idx + 1 < len(insns) else ''))
                if isinstance(t, tuple) and t[0] == 'A':
                    eff = (t[1] + off) & M64
                    if m == 'ldr' and eff == 0x78:
                        d = _r(ins, 0)
                        T[d] = 'V'
                        out['loads'].append(dict(va=ins.address, dst=d, args_off=0x78))
                        prev = ins
                        continue
                if m == 'ldp':
                    d0, d1 = _r(ins, 0), _r(ins, 1)
                    if d0: T[d0] = 'O'
                    if d1: T[d1] = 'O'
                else:
                    d = _r(ins, 0)
                    if d: T[d] = 'O'
                prev = ins
                continue
        if m in ('str', 'stur', 'strb', 'strh', 'stp') and n >= 2:
            mm = _mem(ins, 1)
            if mm is not None:
                base = canon(mm.base)
                off = mm.disp
                t = T.get(base, 'O')
                if isinstance(t, tuple) and t[0] == 'A':
                    eff = (t[1] + off) & M64
                    if eff == 0x78:
                        out['field_stores'].append(dict(va=ins.address, ins=f"{m} {ins.op_str}",
                                                        src=_r(ins, 0)))
                elif t == 'V' and off == 0:
                    srcs = [(_r(ins, 0), 0)]
                    if m == 'stp':
                        srcs.append((_r(ins, 1), 8))
                    for reg, extra in srcs:
                        out['writes'].append(dict(va=ins.address,
                                                  ins=f"{m} {ins.op_str}",
                                                  src=reg, src_tag=T.get(reg, 'O') if reg else None,
                                                  size=8, off=extra))
                    prev = ins
                    continue
            # kill dst if written by a register load
            prev = ins
            continue
        # --- calls
        if m == 'bl':
            tgt = _imm(ins, 0)
            args = [T.get('x%d' % i, 'O') for i in range(8)]
            out['calls'].append(dict(va=ins.address, target=tgt & M64, args=args))
            for r in CALLER_SAVED:
                T['x%d' % r] = 'O'
            slots2 = {}
            for k, v in slots.items():
                slots2[k] = v if v in ('O', 'V') or isinstance(v, tuple) else 'O'
            slots = slots2
            continue
        if m in ('blr', 'blraa', 'blraaz', 'blrAA', 'braa', 'braaz'):
            out['indirect'].append(dict(va=ins.address, ins=f"{m} {ins.op_str}",
                                        args=[T.get('x%d' % i, 'O') for i in range(4)]))
            for r in CALLER_SAVED:
                T['x%d' % r] = 'O'
            continue
        if m in ('b', 'br', 'braa') and n == 1 and _imm(ins, 0) is not None:
            t = _imm(ins, 0)
            if follow_b and t is not None:
                out['tail'].append(dict(va=ins.address, target=t & M64,
                                        args=[T.get('x%d' % i, 'O') for i in range(8)]))
            if not (s <= (t & M64) < end):
                break
            continue
        if m in ('ret', 'retab'):
            if stop_at_ret:
                break
        prev = ins
    return out

if __name__ == "__main__":
    for a in sys.argv[1:]:
        v = int(a, 16)
        r = analyze(v, {'x2': ('A', 0)})
        print(hex(v), "writes", len(r['writes']), "field", len(r['field_stores']),
              "loads", len(r['loads']), "gates", r['gates'], "calls", len(r['calls']))
        for w in r['writes']:
            print("   W", hex(w['va']), w['ins'], w['src_tag'])
