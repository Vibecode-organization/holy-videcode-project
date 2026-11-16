#!/usr/bin/env python3
# KeyStore: per-selector slice heuristics (expected scalar counts, fields touched, calls)
import kd, struct, collections, bisect, json
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from ks_map import selmap, ARGS
from ks_fields import FN_START, FN_END
k = kd.k
md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)

def run():
    m = selmap()
    labels = sorted(set(m.values()))
    ins = list(md.disasm(k.data[k.off(FN_START):k.off(FN_END)], FN_START))
    idx = {i.address: n for n, i in enumerate(ins)}
    bylab = collections.defaultdict(list)
    for s, t in m.items(): bylab[t].append(s)
    out = []
    for lab, sels in sorted(bylab.items(), key=lambda kv: kv[1][0]):
        j = idx.get(lab)
        if j is None: continue
        sl = ins[j:j+60]
        fields, calls, exp_in, exp_out = [], [], None, None
        for n, i in enumerate(sl):
            if i.mnemonic in ('ldr','ldrb','ldrh','ldrsw') and '[' in i.op_str:
                reg, _, rest = i.op_str.split('[')[1].partition(', ')
                rest = rest.rstrip(']')
                if reg == 'x19' and rest.startswith('#'):
                    try: off = int(rest[1:], 16)
                    except Exception: off = -1
                    f = ARGS.get(off)
                    if f and f not in fields: fields.append(f)
                    # next cmp with imm
                    for q in sl[n+1:n+3]:
                        if q.mnemonic == 'cmp' and q.op_str.startswith('w') and ', #' in q.op_str:
                            v = int(q.op_str.split('#')[1], 16)
                            if off == 0x28 and exp_in is None: exp_in = v
                            if off == 0x50 and exp_out is None: exp_out = v
                            break
            if i.mnemonic == 'bl':
                try: calls.append(int(i.op_str.strip('#'), 16))
                except Exception: pass
        out.append(dict(label=lab, sels=sels, fields=fields, sIn=exp_in, sOut=exp_out,
                        calls=sorted(set(calls))[:6]))
    return out

if __name__ == '__main__':
    rows = run()
    with open('ks_selectors.tsv', 'w') as f:
        f.write('sel\thandler\tfields\texpScalarIn\texpScalarOut\tcalls\n')
        for r in rows:
            for s in r['sels']:
                f.write(f"{s}\t{r['label']:#x}\t{','.join(r['fields'])}\t"
                        f"{r['sIn'] if r['sIn'] is not None else '?'}\t"
                        f"{r['sOut'] if r['sOut'] is not None else '?'}\t"
                        f"{','.join(hex(c) for c in r['calls'])}\n")
    for r in rows:
        print(f"{r['label']:#x} sel={r['sels']} sIn={r['sIn']} sOut={r['sOut']} f={','.join(r['fields'])}")
