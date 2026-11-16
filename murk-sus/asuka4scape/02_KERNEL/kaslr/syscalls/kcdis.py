#!/usr/bin/env python3
# Disassemble a function with capstone, annotate BL targets, string refs, and stack frame.
import sys
from mo import MachO, disas, call_target, md
from capstone import CS_OP_IMM, CS_OP_MEM, CS_OP_REG

m = MachO()

def str_at(va):
    d = m.read(va, 200)
    if not d: return None
    e = d.find(b'\0')
    if e < 2: return None
    try:
        s = d[:e].decode('utf-8')
    except: return None
    if all(32 <= ord(c) < 127 for c in s):
        return s
    return None

def dump(va, label='', maxb=0x600):
    print('=== %s %016x ===' % (label, va))
    ins = disas(m, va, maxb)
    if not ins:
        print('  <no code>')
        return
    # find adrp/add pairs for string refs
    for i, x in enumerate(ins):
        extra = ''
        t = call_target(x)
        if t: extra += '  ; -> %016x' % t
        if x.mnemonic in ('bl','blr','br') or x.mnemonic.startswith('b.'):
            pass
        # adrp + add
        if x.mnemonic == 'adrp' and i+1 < len(ins):
            nx = ins[i+1]
            if nx.mnemonic == 'add' and nx.operands[0].type == CS_OP_REG and nx.operands[0].reg == x.operands[0].reg and nx.operands[1].type == CS_OP_REG and nx.operands[1].reg == x.operands[0].reg and nx.operands[2].type == CS_OP_IMM:
                a = x.operands[1].imm + nx.operands[2].imm
                s = str_at(a)
                if s: extra += '  ; "%s"' % s
        if x.mnemonic == 'adr' and x.operands[1].type == CS_OP_IMM:
            s = str_at(x.operands[1].imm)
            if s: extra += '  ; "%s"' % s
        print('  %016x: %-8s %-40s%s' % (x.address, x.mnemonic, x.op_str, extra))
    print()

if __name__ == '__main__':
    for a in sys.argv[1:]:
        dump(int(a, 16))
