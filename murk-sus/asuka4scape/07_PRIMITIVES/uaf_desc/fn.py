# annotated linear disasm: resolves adrp pages, GOT slots, bl targets, vtable call slots
import sys, struct
sys.path.insert(0, '/home/femboychik/work/parse_gpu')
sys.path.insert(0, '/home/femboychik/work/uaf_desc')
import kd
from kd import k, md, V, s64, resolve_imm
from capstone.arm64_const import ARM64_OP_IMM, ARM64_OP_REG, ARM64_OP_MEM

SYM = {}
try:
    import json, os
    for f in ('/home/femboychik/work/parse_gpu/tables_all.json',):
        if os.path.exists(f):
            pass
except Exception:
    pass

def symname(va):
    return SYM.get(va)

def annotate(va, n):
    out = []
    page = {}     # reg -> page base from adrp
    last_slot = None
    pend_slot = [None]
    lines = kd.disarm(va, n)
    for i, (addr, mn, ops, ins) in enumerate(lines):
        note = ''
        try:
            regs_written = [o.reg for o in ins.operands if o.access and (o.access & 2)]
        except Exception:
            regs_written = []
        if mn == 'adrp':
            r = ins.reg_name(ins.operands[0].reg)
            tgt = ins.operands[1].imm & 0xffffffffffffffff
            page[r] = tgt
            note = f"; {tgt:#x}"
        elif mn in ('ldr', 'ldrb', 'ldrh', 'ldrsb', 'ldrsw', 'str', 'strb', 'strh'):
            if ins.operands and ins.operands[-1].type == ARM64_OP_MEM:
                m = ins.operands[-1].mem
                base = ins.reg_name(m.base) if m.base else ''
                disp = s64(m.disp & 0xffffffffffffffff) if m.disp else 0
                if base in page:
                    tgt = (page[base] + m.disp) & 0xffffffffffffffff
                    if mn.startswith('ldr') or mn.startswith('str'):
                        q = k.q(tgt)
                        s = symname(q) if q else None
                        note = f"; [{tgt:#x}]" + (f" = {q:#x} <{s}>" if q and (s or True) else '')
                        note = f"; *{tgt:#x}" + (f" <{s}>" if s else '')
                    else:
                        note = f"; {tgt:#x}"
        elif mn in ('add','mov','sub'):
            if mn == 'add' and 'x16, x16, #' in ops:
                last_slot = ops.split('#')[-1]
            elif mn == 'mov' and 'x17, #' in ops:
                pend_slot[0] = ops.split('#')[-1]
            elif mn == 'add' and 'x16, x16, x17' in ops and pend_slot[0]:
                last_slot = pend_slot[0]
        elif mn in ('b', 'bl', 'blraa', 'braa', 'blr', 'br', 'blrab', 'brab'):
            if mn in ('blraa', 'braa', 'blrab', 'brab'):
                note = f"; vcall slot {last_slot}" if last_slot is not None else "; vcall"
                last_slot = None
            else:
                tgt = resolve_imm(ins, addr)
                if tgt is not None:
                    s = symname(tgt)
                    note = f"; {tgt:#x}" + (f" <{s}>" if s else '')
        elif mn == 'retab':
            note = '; RETURN'
        if mn == 'ldr' and ins.operands[-1].type == ARM64_OP_MEM:
            m = ins.operands[-1].mem
            if ']!' in ops and ins.operands[-1].mem.base:
                if ins.reg_name(m.base) == 'x16':
                    last_slot = hex(m.disp & 0xffffffffffffffff)
            pass
        out.append(f"{addr:#x}:  {mn:9} {ops}{('   ' + note) if note else ''}")
    return out

def dump(va, n, label=''):
    print(f"\n===== {label}  {va:#x}  ({n:#x} bytes) =====")
    for l in annotate(va, n):
        print(l)

if __name__ == '__main__':
    va = V(sys.argv[1])
    n = int(sys.argv[2], 16) if len(sys.argv) > 2 else 0x200
    dump(va, n, sys.argv[3] if len(sys.argv) > 3 else '')
