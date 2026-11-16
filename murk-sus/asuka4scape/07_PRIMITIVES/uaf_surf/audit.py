#!/usr/bin/env python3
"""precise path audit for functions calling 0x9c3f1d0 (lookupSurface, returns +1)."""
import kc, re, bisect
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from capstone.arm64 import ARM64_OP_REG, ARM64_OP_MEM, ARM64_OP_IMM

TXT="/tmp/opencode/uaf_surf.txt"
INS=[]
for l in open(TXT):
    m=re.match(r"([0-9a-f]{16}): (\S+)\s*(.*?)\s*$",l)
    if m: INS.append((int(m.group(1),16),m.group(2),m.group(3)))
def is_start(i):
    a,mn,ops=INS[i]
    if mn!="bti" or ops!="c": return False
    if i+1>=len(INS): return True
    return INS[i+1][1] in ("pacibsp","sub","stp","ldr","mov","cbz","add","mrs","adrp","str","ldrb")
STARTS=[INS[i][0] for i in range(len(INS)) if is_start(i)]
def fr(addr):
    j=bisect.bisect_right(STARTS,addr)-1
    return STARTS[j],(STARTS[j+1] if j+1<len(STARTS) else STARTS[j]+0x2000)
MD=Cs(CS_ARCH_ARM64,CS_MODE_ARM); MD.detail=True

def decode(s,e):
    out=[];a=s
    while a<e:
        ins=next(MD.disasm(kc.BLOB[kc.va2off(a):kc.va2off(a)+4],a),None)
        if ins is None: break
        out.append(ins);a+=4
    return out

LOOK=0xfffffff009c3f1d0

def audit(start):
    s,e=fr(start); seq=decode(s,e); idx={i.address:k for k,i in enumerate(seq)}
    # find lookup call and result reg
    look=None
    for k,ins in enumerate(seq):
        if ins.mnemonic=="bl" and any(op.type==ARM64_OP_IMM and (op.imm & 0xffffffffffffffff)==LOOK for op in ins.operands):
            look=k; break
    if look is None: return None
    reg=None
    for k in range(look+1,min(look+4,len(seq))):
        ins=seq[k]
        if ins.mnemonic=="mov" and re.match(r"x\d+, x0$", ins.op_str):
            reg=ins.op_str.split(",")[0].strip(); break
        if ins.mnemonic=="cbz" and ins.op_str.startswith("x0"): break
    if reg is None: reg="x0"
    # releases: find blraa whose obj reg == our reg
    rel=set()
    for k,ins in enumerate(seq):
        if ins.mnemonic=="blraa":
            obj=None
            for j in range(k-1,max(-1,k-6),-1):
                p=seq[j]
                if p.mnemonic=="mov" and p.op_str.startswith("x0, "):
                    obj=p.op_str.split(",")[1].strip(); break
            if obj==reg: rel.add(k)
    # cfg
    succ={}
    for k,ins in enumerate(seq):
        mn=ins.mnemonic; nx=k+1; tg=None
        for op in ins.operands:
            if op.type==ARM64_OP_IMM: tg=op.imm & 0xffffffffffffffff
        if mn=="b" and tg is not None: succ[k]=[idx[tg]] if tg in idx else []
        elif mn in ("cbz","cbnz","tbz","tbnz") or mn.startswith("b."):
            succ[k]=([nx] if nx<len(seq) else [])+([idx[tg]] if tg in idx else [])
        elif mn in ("ret","retab","braa","braaz","br"): succ[k]=[]
        else: succ[k]=[nx] if nx<len(seq) else []
    # BFS after lookup success through fallthrough; note cbz x0 branches treated normally
    startk=look+1
    states=set(); work=[(startk,0)]
    bad=[]; dbl=[]
    while work:
        k,nrel=work.pop()
        if k>=len(seq): continue
        if k in rel: nrel+=1
        ins=seq[k]
        if ins.mnemonic in ("ret","retab"):
            if nrel==0: bad.append((ins.address,nrel))
            if nrel>1: dbl.append((ins.address,nrel))
            continue
        st=(k,nrel)
        if st in states: continue
        states.add(st)
        for s2 in succ.get(k,[]):
            work.append((s2,nrel))
    return dict(start=s,end=e,reg=reg,look=seq[look].address,nrel=len(rel),
                leaks=sorted(set(b for b,_ in bad)), doubles=sorted(set(d for d,_ in dbl)))

if __name__=="__main__":
    import sys
    lo=int(sys.argv[1],16); hi=int(sys.argv[2],16)
    for s in STARTS:
        if not (lo<=s<hi): continue
        try: r=audit(s)
        except Exception: r=None
        if r and (r['leaks'] or r['doubles']):
            print(f"fn {r['start']&0xffffffff:08x}-{r['end']&0xffffffff:08x} lookup@{r['look']&0xffffffff:08x} obj={r['reg']} releases={r['nrel']}")
            if r['doubles']: print("   DOUBLE->", [hex(x&0xffffffff) for x in r['doubles']])
            if r['leaks']: print("   NORELEASE->", [hex(x&0xffffffff) for x in r['leaks']])
