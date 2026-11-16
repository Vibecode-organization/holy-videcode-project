#!/usr/bin/env python3
# KeyStore: map external-method jump table to handlers, report args fields touched
import kd, struct, collections, json
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
k = kd.k
md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)

TBL = 0xfffffff00914b3c8
BASE = 0xfffffff009142efc
ARGS = {0x00:'ver',0x04:'sel',0x08:'asyncPort',0x10:'ref',0x20:'scalarIn',0x28:'sInCnt',
        0x30:'structIn',0x38:'strInSz',0x40:'structInDesc',0x48:'scalarOut',0x50:'sOutCnt',
        0x58:'structOut',0x60:'strOutSz',0x68:'structOutDesc',0x70:'outDescCnt',0x78:'varOut'}

def selmap():
    m = {}
    for i in range(0xa9):
        off = struct.unpack('<i', k.rd(TBL + i*4, 4))[0]
        m[i+1] = BASE + off
    return m

def body(f, n=200):
    o = k.off(f)
    return list(md.disasm(k.data[o:o+n*4], f)) if o else []

def fields(ins):
    out = set()
    for i in ins:
        if i.mnemonic in ('ldr','ldrb','ldrh','ldrsw','str','strb','stur','ldur') and '[' in i.op_str:
            t = i.op_str.split('[')[1]
            reg, _, rest = t.partition(', ')
            if reg in ('x2','x19','x21') and rest.startswith('#'):
                try: off = int(rest[1:], 16)
                except Exception: continue
                if off in ARGS: out.add(ARGS[off])
    return out

if __name__ == '__main__':
    m = selmap()
    inv = collections.defaultdict(list)
    for s, t in m.items(): inv[t].append(s)
    rows = []
    for t, sels in sorted(inv.items(), key=lambda kv: kv[1][0]):
        ins = body(t)
        f = fields(ins)
        calls = [i.op_str for i in ins if i.mnemonic == 'bl'][:6]
        rows.append(dict(target=t, sels=sorted(sels), fields=sorted(f),
                         n=len(ins), calls=calls,
                         prog=[f'{i.mnemonic} {i.op_str}' for i in ins[:6]]))
    json.dump(rows, open('ks_sels.json', 'w'), indent=1)
    for r in rows:
        print(f"{r['target']:#x} sel={r['sels'][:6]}{'...' if len(r['sels'])>6 else ''} "
              f"n={r['n']} fields={','.join(r['fields'])}")
