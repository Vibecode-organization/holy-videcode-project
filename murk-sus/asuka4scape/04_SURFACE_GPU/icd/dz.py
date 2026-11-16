import sys, subprocess, bisect

sys.path.insert(0, '/home/femboychik/work/icd')
from macho import MachO, _text
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM


def load_syms(path):
    out = subprocess.run(['ipsw', 'macho', 'info', '-n', path],
                         capture_output=True, text=True).stdout
    syms = {}
    for line in out.splitlines():
        line = line.strip()
        if not line.startswith('0x') or '\t' not in line:
            continue
        try:
            addr = int(line.split(':')[0], 16)
        except ValueError:
            continue
        name = line.split('\t')[-1].strip()
        syms.setdefault(addr, name)
    return syms


def dump(path, start, end=None, syms=None, ninsn=200, out=None):
    m = MachO(path)
    code, base = _text(m)
    md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    md.detail = True
    if end is None:
        end = start + ninsn * 4
    lines = []
    adrp = {}
    for insn in md.disasm(code[start - base:end - base], start):
        s = f"{insn.address:x}: {insn.mnemonic} {insn.op_str}"
        if insn.mnemonic == 'adrp' and insn.operands:
            adrp[insn.operands[0].reg] = insn.operands[1].imm
        if insn.mnemonic == 'add' and len(insn.operands) == 3 and insn.operands[1].type == 1 and insn.operands[2].type == 2:
            v = adrp.get(insn.operands[1].reg)
            if v is not None:
                t = v + insn.operands[2].imm
                c = m.cstr(t) if m.va2off(t) else None
                if c and c.isascii() and c.isprintable():
                    s += f"   ; {hex(t)} {c!r}"
        if insn.mnemonic in ('bl', 'b') and insn.operands and insn.operands[0].type == 2:
            t = insn.operands[0].imm
            if syms and t in syms:
                s += f"   ; {syms[t]}"
        lines.append(s)
    txt = '\n'.join(lines)
    if out:
        open(out, 'w').write(txt)
    return txt


if __name__ == '__main__':
    path = sys.argv[1]
    start = int(sys.argv[2], 16)
    end = int(sys.argv[3], 16) if len(sys.argv) > 3 and sys.argv[3] != '-' else None
    print(dump(path, start, end, load_syms(path)))
