import json
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from kc import load
k=load()
md=Cs(CS_ARCH_ARM64, CS_MODE_ARM)
tabs=json.load(open('tables_target.json'))
def insns(va, limit=400):
    o=k.off(va)
    if o is None: return []
    out=[]
    for i in md.disasm(k.data[o:o+limit*4], va):
        out.append(i)
        if i.mnemonic in ('ret','retab'): break
    return out
res=[]
for t in tabs:
    for r in t['rows']:
        S=insns(r['fn'])
        txt=[f"{i.mnemonic} {i.op_str}" for i in S]
        argsreads=sorted({(i.mnemonic, m) for i in S[:14] for m in [i.op_str] if '[x2' in i.op_str})
        calls=[i.op_str for i in S if i.mnemonic in ('bl','blr','blraa','braa','bra')][:6]
        res.append(dict(sel=r['sel'], fn=r['fn'], sIn=r['sIn'], strIn=r['strIn'], sOut=r['sOut'], strOut=r['strOut'],
                        ninsn=len(S), prog=txt[:16], calls=calls, kext=t['kext'], cls=t['cls'], table=t['va']))
json.dump(res, open('handlers_probe.json','w'), indent=1)
for x in res:
    if x['strIn'] or x['sIn']>0:
        print(f"\n[{x['cls']}] sel {x['sel']} fn={x['fn']:#x} sIn={x['sIn']} strIn={x['strIn']:#x} sOut={x['sOut']} strOut={x['strOut']:#x} n={x['ninsn']}")
        for l in x['prog']: print("   ",l)
