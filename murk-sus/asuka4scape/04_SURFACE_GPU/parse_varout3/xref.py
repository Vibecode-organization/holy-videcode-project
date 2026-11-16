"""xref: who calls/branches to a set of targets; print caller func + context."""
import sys, array, bisect, json
sys.path.insert(0, "/home/femboychik/work/parse_varout3")
from tools import *

buf = DATA[TEXT_EXEC_OFF:TEXT_EXEC_OFF + TEXT_EXEC_SIZE]
A = array.array('I'); A.frombytes(buf)

def callers(target, ctx=8):
    out = []
    for i, w in enumerate(A):
        op = w & 0xFC000000
        if op not in (0x94000000, 0x14000000):
            continue
        imm = w & 0x03FFFFFF
        if imm & 0x02000000:
            imm -= 0x04000000
        va = TEXT_EXEC_VA + i * 4
        if va + imm * 4 == target:
            out.append((va, 'bl' if op == 0x94000000 else 'b'))
    return out

def text(target, n=10):
    out = []
    for va, kind in callers(target):
        s, e = func_of(va)
        ins = list(md.disasm(DATA[va2off(max(s, va - 4 * n)):va2off(va) + 16], max(s, va - 4 * n)))
        out.append((va, kind, s, [(hex(i.address), i.mnemonic, i.op_str) for i in ins]))
    return out

if __name__ == "__main__":
    for a in sys.argv[1:]:
        t = int(a, 16)
        print("==== target", hex(t), kext_of(t))
        for va, kind, s, ins in text(t):
            print(f"  {kind} at {va:#x}  in func {s:#x} ({kext_of(s)})")
            for x in ins[-7:]:
                print("      ", *x)
