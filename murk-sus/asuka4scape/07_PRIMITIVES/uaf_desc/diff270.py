# compare function bodies between 27.0 and 27.2 with pc-relative targets masked
import sys, struct
sys.path.insert(0, '/home/femboychik/work/parse_gpu')
import kc as KCmod
import capstone
from capstone.arm64_const import ARM64_OP_REG, ARM64_OP_IMM, ARM64_OP_MEM, ARM64_OP_CIMM

k2 = KCmod.KC('/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache')
k0 = KCmod.KC('/home/femboychik/Рабочий стол/дипсик 1/kc/27.0_24A437_kernelcache')
md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
md.detail = True

def skel(k, va, n):
    out = []
    for ins in md.disasm(k.rd(va, n) or b'', va):
        ops = []
        for o in ins.operands:
            if o.type == ARM64_OP_REG:
                ops.append(ins.reg_name(o.reg))
            elif o.type == ARM64_OP_IMM:
                if ins.mnemonic in ('adr', 'adrp') or ins.mnemonic[0] == 'b':
                    ops.append('<rel>')
                else:
                    ops.append(f"#{o.imm:#x}")
            elif o.type == ARM64_OP_MEM:
                base = ins.reg_name(o.mem.base) if o.mem.base else '-'
                ops.append(f"[{base}+{o.mem.disp:#x}]")
            elif o.type == ARM64_OP_CIMM:
                ops.append(f"c#{o.imm:#x}")
            else:
                ops.append('?')
        out.append((ins.mnemonic, ','.join(ops), ins.bytes.hex()))
    return out

def fn_end(k, va, limit=0x2000):
    """find end: last ret/retab before next 'bti c' + pacibsp pair"""
    ins = list(md.disasm(k.rd(va, limit) or b'', va))
    end = va
    for i, x in enumerate(ins):
        if x.mnemonic in ('ret', 'retab'):
            end = x.address + x.size
            # continue if next insn isn't a fresh function prologue
            if i+2 < len(ins):
                nxt = ins[i+1]
                if nxt.mnemonic == 'bti':
                    break
    return end

def diff_fn(va2, va0, label):
    e2 = fn_end(k2, va2); e0 = fn_end(k0, va0)
    s2 = skel(k2, va2, e2-va2); s0 = skel(k0, va0, e0-va0)
    same_len = len(s2) == len(s0)
    diffs = []
    for i in range(max(len(s2), len(s0))):
        a = s2[i] if i < len(s2) else None
        b = s0[i] if i < len(s0) else None
        if a is None or b is None or a[0] != b[0] or a[1] != b[1]:
            diffs.append((i, a, b))
    print(f"\n=== {label}: 27.2 {va2:#x} ({e2-va2:#x}) vs 27.0 {va0:#x} ({e0-va0:#x})  insns {len(s2)}/{len(s0)}  diffs={len(diffs)}")
    for i, a, b in diffs[:40]:
        print(f"  [{i:3d}] 27.2: {a[0]:9} {a[1] if a else ''}")
        print(f"        27.0: {b[0]:9} {b[1] if b else ''}")
    return diffs

if __name__ == '__main__':
    pairs = [
        ('sel9',   0xfffffff009c38b2c, 0xfffffff009bfcb84),
        ('sel10',  0xfffffff009c38c44, 0xfffffff009bfcc9c),
        ('sel11',  0xfffffff009c38e54, 0xfffffff009bfceac),
        ('sel24',  0xfffffff009c392c0, 0xfffffff009bfd318),
        ('sel26',  0xfffffff009c39448, 0xfffffff009bfd4a0),
        ('sel46',  0xfffffff009c39a78, 0xfffffff009bfdad0),
        ('sel47',  0xfffffff009c39bdc, 0xfffffff009bfdc34),
        ('sel48',  0xfffffff009c39cf4, 0xfffffff009bfdd4c),
        ('sel54',  0xfffffff009c39f5c, 0xfffffff009bfdfb4),
    ]
    for name, a, b in pairs:
        diff_fn(a, b, name)
