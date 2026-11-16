#!/usr/bin/env python3
"""Find call sites of alloc/copy/mem primitives and show a context window."""
import sys, re
sys.path.insert(0, __file__.rsplit('/', 1)[0])
from disasm import Bin, annotate_bin
from stubs import load as load_stubs

WANT = re.compile(r'(malloc|calloc|realloc|memcpy|memmove|memset|strcpy|strcat|sprintf|snprintf|vsnprintf|strlen|alloca|CFDataCreate|CFDataGetBytes|_Znwm|_Znam|operator new|new\[\])', re.I)

def main():
    path = sys.argv[1]
    win = int(sys.argv[2]) if len(sys.argv) > 2 else 25
    filt = sys.argv[3] if len(sys.argv) > 3 else None
    b = Bin(path)
    st = b.stubs
    # disassemble whole __text in one go
    addr, size, foff = b.sects['__text'][0]
    insns = annotate_bin(b, None, size // 4 + 4, addr)
    idx = {ins.address: i for i, ins in enumerate(insns)}
    for i, ins in enumerate(insns):
        if ins.mnemonic != 'bl': continue
        tgt = None
        if ins.operands and ins.operands[0].type == 2:
            tgt = ins.operands[0].imm
        name = st.get(tgt, '')
        if not name or not WANT.search(name): continue
        fn = b.name_at(ins.address) or f'0x{ins.address:x}'
        if filt and filt.lower() not in fn.lower(): continue
        print(f"\n===== {name}  @0x{ins.address:x}  in {fn}")
        for j in range(max(0, i-win), min(len(insns), i+3)):
            m = insns[j]
            c = getattr(m, '_cmt', '')
            mark = '>>' if j == i else '  '
            print(f"{mark} 0x{m.address:x}:  {m.mnemonic}\t{m.op_str}" + (f"\t; {c}" if c else ''))

if __name__ == '__main__':
    main()
