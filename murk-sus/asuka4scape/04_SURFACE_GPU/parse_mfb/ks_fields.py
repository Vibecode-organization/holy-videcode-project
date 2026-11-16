#!/usr/bin/env python3
# attribute arg-field accesses inside the big KeyStore externalMethod to the enclosing case label
import kd, struct, collections, bisect
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from ks_map import selmap, ARGS
k = kd.k
md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)

FN_START = 0xfffffff009142e0c
FN_END = 0xfffffff00914a7cc

def main():
    m = selmap()
    labels = sorted(set(m.values()))
    rows = collections.defaultdict(lambda: dict(fields=set(), calls=[], n=0))
    o = k.off(FN_START)
    ins = list(md.disasm(k.data[o:o+(FN_END-FN_START)], FN_START))
    for i in ins:
        j = bisect.bisect_right(labels, i.address) - 1
        lab = labels[j] if j >= 0 else 0
        r = rows[lab]
        r['n'] += 1
        if i.mnemonic in ('ldr','ldrb','ldrh','ldrsw','str','strb','stur','ldur') and '[' in i.op_str:
            reg, _, rest = i.op_str.split('[')[1].partition(', ')
            rest = rest.rstrip(']')
            if reg in ('x19', 'x2', 'x21') and rest.startswith('#'):
                try: off = int(rest[1:], 16)
                except Exception: off = -1
                if off in ARGS: r['fields'].add(ARGS[off])
        if i.mnemonic == 'bl':
            try: r['calls'].append(int(i.op_str.strip('#'), 16))
            except Exception: pass
    out = []
    for lab, r in rows.items():
        sels = sorted(s for s, t in m.items() if t == lab)
        out.append(dict(label=lab, sels=sels, fields=sorted(r['fields']), n=r['n'],
                        calls=sorted(set(r['calls']))[:8]))
    out.sort(key=lambda x: (x['sels'][0] if x['sels'] else 0))
    return out

if __name__ == '__main__':
    for r in main():
        if r['fields']:
            print(f"{r['label']:#x} sel={r['sels']} n={r['n']} fields={','.join(r['fields'])} calls={[hex(c) for c in r['calls'][:5]]}")
