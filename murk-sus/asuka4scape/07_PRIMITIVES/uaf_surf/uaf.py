#!/usr/bin/env python3
"""UAF checks: cfg + use-after-release and double-release detection, whole region."""
import kc, re, sys
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM

TXT = "/tmp/opencode/uaf_surf.txt"
INS=[]
for l in open(TXT):
    m=re.match(r"([0-9a-f]{16}): (\S+)\s*(.*?)\s*$", l)
    if m: INS.append((int(m.group(1),16), m.group(2), m.group(3)))
import bisect
ADDR=[a for a,_,_ in INS]
def is_start(i):
    a,mn,ops=INS[i]
    if mn!="bti" or ops!="c": return False
    if i+1>=len(INS): return True
    return INS[i+1][1] in ("pacibsp","sub","stp","ldr","mov","cbz","add","mrs","adrp","str","ldrb")
STARTS=[INS[i][0] for i in range(len(INS)) if is_start(i)]
def func_range(addr):
    j=bisect.bisect_right(STARTS,addr)-1
    if j<0: return None
    return STARTS[j], (STARTS[j+1] if j+1<len(STARTS) else STARTS[j]+0x2000)

MD=Cs(CS_ARCH_ARM64,CS_MODE_ARM); MD.detail=True

def decode(s,e):
    out=[]; a=s
    while a<e:
        ins=next(MD.disasm(kc.BLOB[kc.va2off(a):kc.va2off(a)+4],a),None)
        if ins is None: break
        out.append(ins); a+=4
    return out

def regname(ins, regid):
    return ins.reg_name(regid)

def analyze(s,e, verbose=False):
    ins_list=decode(s,e)
    idx={ins.address:i for i,ins in enumerate(ins_list)}
    succ={}
    for i,ins in enumerate(ins_list):
        mn=ins.mnemonic; nx=i+1; tg=None
        for op in ins.operands:
            if op.type==2: tg=op.imm & 0xffffffffffffffff
        if mn=="b" and tg is not None: succ[i]=[idx[tg]] if tg in idx else []
        elif mn in ("cbz","cbnz","tbz","tbnz") or mn.startswith("b."):
            if tg in idx: succ[i]=([nx] if nx<len(ins_list) else []) + [idx[tg]]
            else: succ[i]=[nx] if nx<len(ins_list) else []
        elif mn in ("ret","retab"): succ[i]=[]
        elif mn in ("braa","braaz","br"): succ[i]=[]
        else: succ[i]=[nx] if nx<len(ins_list) else []

    # find release sites: blraa whose preceding ldr is [xN,#0x28]!
    rel_sites={}
    rel_span={}
    for i,ins in enumerate(ins_list):
        if ins.mnemonic!="blraa": continue
        # look back for ldr x8,[x16,#0x28]!
        base=None; slot=None
        for j in range(i-1,max(-1,i-6),-1):
            p=ins_list[j]
            if p.mnemonic=="ldr" and "#0x28]!" in p.op_str:
                base=p.operands[1].mem.base
                base=regname(p,base)
                break
        # object reg passed as x0
        obj=None
        for j in range(i-1,max(-1,i-6),-1):
            p=ins_list[j]
            if p.mnemonic=="mov" and p.op_str.startswith("x0, x"):
                obj=p.op_str.split(",")[1].strip()
                break
        if obj: rel_sites[i]=(obj,base)
        rel_span[i]=(max(0,i-6),i)

    reports=[]
    visited=set()
    def dfs(i, freed, inrel):
        if i>=len(ins_list): return
        ins=ins_list[i]
        a=ins.address
        # check reads of freed regs
        if i not in inrel:
            for op in ins.operands:
                if op.type==1 and (op.access & 2):
                    rn=regname(ins,op.reg)
                    if rn in freed:
                        reports.append(("UAF", a, rn, ins.mnemonic+" "+ins.op_str))
        nf=set(freed)
        if i in rel_sites:
            rn=rel_sites[i][0]
            if rn in nf: reports.append(("DOUBLE",a,rn,"release"))
            nf.add(rn)
        # invalidate on write
        for op in ins.operands:
            if op.type==1 and (op.access & 1):
                rn=regname(ins,op.reg)
                nf.discard(rn)
        key=(i,frozenset(nf))
        if key in visited: return
        visited.add(key)
        nrel = rel_span.get(i,inrel)
        if i in rel_span: nrel=rel_span[i]
        elif i<inrel[0] or i>inrel[1]: nrel=(-1,-1)
        for s2 in succ.get(i,[]):
            dfs(s2,nf,nrel)
    dfs(0,set(),(-1,-1))
    return reports

if __name__=="__main__":
    lo=int(sys.argv[1],16); hi=int(sys.argv[2],16)
    for s in STARTS:
        if not (lo<=s<hi): continue
        r=func_range(s)
        try:
            rep=analyze(r[0],r[1])
        except Exception as ex:
            continue
        interesting=[x for x in rep if x[0] in ("UAF","DOUBLE")]
        if interesting:
            print(f"fn {s:016x}:")
            for k,a,rn,ctx in interesting[:6]:
                print(f"   {k} at {a:016x} reg {rn}  ({ctx})")
