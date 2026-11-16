#!/usr/bin/env python3
# Identify all changed 27.2 kernel functions by referenced strings + direct call targets.
import sys, struct, re
from capstone import *
from capstone.arm64 import *

KC = '/home/femboychik/Рабочий стол/дипсик 1/kcore/272/com.apple.kernel'
REPORT = sys.argv[1] if len(sys.argv)>1 else '/home/femboychik/Рабочий стол/дипсик 1/reports/kcore_shape_diff_full2.txt'

d = open(KC,'rb').read()
magic, ct, cs, ft, ncmds, sz, fl, _ = struct.unpack_from('<IiiIIIII', d, 0)
p = 32; segs = []
for _ in range(ncmds):
    cmd, csz = struct.unpack_from('<II', d, p)
    if cmd == 0x19:
        nm = d[p+8:p+24].split(b'\0')[0].decode()
        vm, vs, fo, fs = struct.unpack_from('<QQQQ', d, p+24)
        segs.append((nm, vm, vs, fo, fs))
    p += csz

def read(a, n):
    for nm, vm, vs, fo, fs in segs:
        if vm <= a and a + n <= vm + vs and fs:
            return d[fo + (a - vm):fo + (a - vm) + n]
    return None

# string map
strs = {}
for nm, vm, vs, fo, fs in segs:
    if fs == 0 or nm in ('__text','__TEXT_EXEC','__TEXT_BOOT_EXEC'):
        continue
    blob = d[fo:fo+fs]
    i = 0
    while i < len(blob):
        j = i
        while j < len(blob) and 32 <= blob[j] < 127:
            j += 1
        if j - i >= 5:
            s = blob[i:j].decode('ascii', 'replace')
            if re.search(r'[A-Za-z]{2}', s):
                strs[vm + i] = s
        i = max(j, i + 1)

md = Cs(CS_ARCH_ARM64, CS_MODE_LITTLE_ENDIAN)
md.detail = True
md.skipdata = True

B=[]
curtag=None
for l in open(REPORT):
    m=re.match(r'== (\w+) A\[(\d+):(\d+)\] B\[(\d+):(\d+)\]',l)
    if m: curtag=m.group(1); continue
    m=re.match(r'\s+B (0x[0-9a-f]+) sz=(\d+)',l)
    if m: B.append((int(m.group(1),16),int(m.group(2)),curtag))

def analyze(a,size):
    code=read(a,size); out=[]; calls=[]; data=[]
    if not code: return out,calls,data
    adrp={}
    for i in md.disasm(code,a):
        if i.id==0: continue
        ops=i.operands
        if i.mnemonic=='adrp' and len(ops)==2 and ops[1].type==ARM64_OP_IMM:
            adrp[ops[0].reg]=ops[1].imm & 0xffffffffffffffff
        elif i.mnemonic in ('add','ldr','str','ldrb','ldrh','ldrsw') and len(ops)==3 and ops[1].type==ARM64_OP_REG and ops[2].type==ARM64_OP_IMM:
            base=ops[1].reg
            if base in adrp:
                t=(adrp[base]+ops[2].imm)&0xffffffffffffffff
                if t in strs: out.append(strs[t].rstrip())
                elif i.mnemonic=='ldr': data.append(t)
        elif i.mnemonic in ('bl','b') and ops and ops[0].type==ARM64_OP_IMM:
            if i.mnemonic=='bl': calls.append(ops[0].imm & 0xffffffffffffffff)
    return out,calls,data

for a,s,tag in B:
    ss,calls,data=analyze(a,s)
    uniq=[]
    for x in ss:
        if x not in uniq: uniq.append(x)
    print(f"{a:#x} sz={s} {tag} :: " + ' | '.join(x[:110] for x in uniq[:4]))
