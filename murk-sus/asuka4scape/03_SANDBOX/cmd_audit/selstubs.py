#!/usr/bin/env python3
# decode objc selector stubs from dumped raw bytes
import struct, re, json, sys
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM

BASE = 0x208000000
sels = {}
for line in open('/tmp/opencode/sels.txt', errors='ignore'):
    m = re.match(r'^(0x[0-9a-f]+): (.*)$', line.rstrip('\n'))
    if m:
        sels[int(m.group(1), 16)] = m.group(2)

md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
stubs = {}
for i in range(4):
    data = open(f'/tmp/opencode/stub_{i}.bin', 'rb').read()
    base = BASE + i*0x40000
    for off in range(0, len(data)-12, 16):
        code = data[off:off+12]
        ins = list(md.disasm(code, base+off))
        if len(ins) != 3:
            continue
        i0, i1, i2 = ins
        if i0.mnemonic == 'adrp' and i0.op_str.startswith('x1,') and i1.mnemonic == 'add' and i1.op_str.startswith('x1, x1,') and i2.mnemonic == 'b':
            page = int(i0.op_str.split(',')[1].strip(), 16) if False else None
            # capstone gives absolute page in op_str? compute manually
            immlo = (struct.unpack('<I', code[0:4])[0] >> 29) & 3
            immhi = (struct.unpack('<I', code[0:4])[0] >> 5) & 0x7ffff
            imm = (immhi << 2) | immlo
            if imm & (1 << 20):
                imm -= 1 << 21
            page = ((base+off) & ~0xfff) + (imm << 12)
            addimm = (struct.unpack('<I', code[4:8])[0] >> 10) & 0xfff
            sel = page + addimm
            stubs[base+off] = (sels.get(sel, f'sel_{sel:x}'), sel)
print(len(stubs))
json.dump({hex(k): v for k, v in stubs.items()}, open('/tmp/opencode/selstubs.json', 'w'))
for k in sorted(stubs)[:10]:
    print(hex(k), stubs[k])
print(hex(0x2080b69e0), stubs.get(0x2080b69e0))
print(hex(0x2080b5ef0), stubs.get(0x2080b5ef0))
