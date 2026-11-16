#!/usr/bin/env python3
"""Resolve stub addresses to imported symbols or objc_msgSend selectors."""
import sys, struct
sys.path.insert(0, __file__.rsplit('/', 1)[0])
from disasm import Bin
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM


def load(b):
    out = {}
    md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    md.detail = True
    # auth stubs: adrp x17, page ; add x17, x17, #off ; ldr x16,[x17] ; braa
    for addr, size, foff in b.sects.get('__auth_stubs', []):
        insns = list(md.disasm(b.d[foff:foff+size], addr))
        for i, ins in enumerate(insns):
            if ins.mnemonic == 'adrp' and ins.op_str.startswith('x17'):
                page = ins.operands[1].imm
                for j in range(i+1, min(i+3, len(insns))):
                    n = insns[j]
                    if n.mnemonic == 'add' and n.op_str.startswith('x17'):
                        tgt = page + int(n.op_str.split('#')[-1], 0)
                        fx = b.fix.get(tgt)
                        if isinstance(fx, str):
                            out[ins.address] = fx
                        break
    # objc stubs: adrp x?, page ; add x?, x?, #selref ; ldr x16 ; br
    for addr, size, foff in b.sects.get('__objc_stubs', []):
        insns = list(md.disasm(b.d[foff:foff+size], addr))
        i = 0
        while i < len(insns):
            ins = insns[i]
            if ins.mnemonic == 'adrp':
                page = ins.operands[1].imm
                reg = ins.op_str.split(',')[0].strip()
                sel = None
                for j in range(i+1, min(i+4, len(insns))):
                    n = insns[j]
                    if n.mnemonic in ('add', 'ldr') and n.op_str.startswith(reg):
                        try:
                            slot = page + int(n.op_str.split('#')[-1].rstrip(']'), 0)
                        except ValueError:
                            continue
                        p = b.fix.get(slot)
                        if isinstance(p, int):
                            sel = b.cstr(p)
                        break
                if sel:
                    out[ins.address] = f'objc_msgSend  ; {sel}'
            i += 1
    return out


if __name__ == '__main__':
    b = Bin(sys.argv[1])
    for a, s in sorted(load(b).items()):
        print(f"0x{a:x}  {s}")
