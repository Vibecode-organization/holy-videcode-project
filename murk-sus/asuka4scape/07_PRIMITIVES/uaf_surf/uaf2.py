#!/usr/bin/env python3
"""UAF detector v2: flag reads/mem-access of a register after it was released."""
import kc, re, sys
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from capstone.arm64 import ARM64_OP_REG, ARM64_OP_MEM, ARM64_OP_IMM

TXT="/tmp/opencode/uaf_surf.txt"
INS=[]
for l in open(TXT):
    m=re.match(r"([0-9a-f]{16}): (\S+)\s*(.*?)\s*$",l)
    if m: INS.append((int(m.group(1),16),m.group(2),m.group(3)))
import bisect
def is_start(i):
    a,mn,ops=INS[i]
    if mn!="bti" or ops!="c": return False
    if i+1>=len(INS): return True
    return INS[i+1][1] in ("pacibsp","sub","stp","ldr","mov","cbz","add","mrs","adrp","str","ldrb")
STARTS=[INS[i][0] for i in range(len(INS)) if is_start(i)]
def fr(addr):
    j=bisect.bisect_right(STARTS,addr)-1
    if j<0: return None
    return STARTS[j],(STARTS[j+1] if j+1<len(STARTS) else STARTS[j]+0x2000)

MD=Cs(CS_ARCH_ARM64,CS_MODE_ARM); MD.detail=True

def analyze(s,e):
    seq=[]
    a=s
    while a<e:
        ins=next(MD.disasm(kc.BLOB[kc.va2off(a):kc.va2off(a)+4],a),None)
        if ins is None: break
        seq.append(ins); a+=4
    idx={ins.address:i for i,ins in enumerate(seq)}
    succ={}
    for i,ins in enumerate(seq):
        mn=ins.mnemonic; nx=i+1; tg=None
        for op in ins.operands:
            if op.type==ARM64_OP_IMM: tg=op.imm & 0xffffffffffffffff
        if mn=="b" and tg is not None: succ[i]=[idx[tg]] if tg in idx else []
        elif mn in ("cbz","cbnz","tbz","tbnz") or mn.startswith("b."):
            s1=[nx] if nx<len(seq) else []
            succ[i]=s1+([idx[tg]] if tg in idx else [])
        elif mn in ("ret","retab","braa","braaz","br"): succ[i]=[]
        else: succ[i]=[nx] if nx<len(seq) else []

    relsite={}   # blraa idx -> obj reg
    relspan={}
    for i,ins in enumerate(seq):
        if ins.mnemonic!="blraa": continue
        obj=None
        for j in range(i-1,max(-1,i-5),-1):
            p=seq[j]
            if p.mnemonic=="mov" and p.op_str.startswith("x0, x"):
                obj=p.op_str.split(",")[1].strip(); break
        if obj:
            relsite[i]=obj
            relspan[i]=(i-5,i)

    reports=[]; visited=set()
    def dfs(i,freed,span):
        if i>=len(seq): return
        ins=seq[i]; a=ins.address
        if not (span[0]<=i<=span[1]):
            for op in ins.operands:
                if op.type==ARM64_OP_MEM and op.mem.base:
                    rn=ins.reg_name(op.mem.base)
                    if rn in freed:
                        reports.append(("UAF_MEM",a,rn,ins.mnemonic+" "+ins.op_str))
                elif op.type==ARM64_OP_REG and (op.access & 2) and not (op.access & 1):
                    rn=ins.reg_name(op.reg)
                    if rn in freed:
                        reports.append(("UAF_REG",a,rn,ins.mnemonic+" "+ins.op_str))
        nf=set(freed)
        nspan=span
        if i in relsite:
            rn=relsite[i]
            if rn in nf: reports.append(("DOUBLE",a,rn,"release"))
            nf.add(rn)
            nspan=(i-5,i)
        # writes invalidate (dest reg)
        for op in ins.operands:
            if op.type==ARM64_OP_REG and (op.access & 1):
                nf.discard(ins.reg_name(op.reg))
        # ldp/stp destination regs: capstone may mark write
        key=(i,frozenset(nf))
        if key in visited: return
        visited.add(key)
        for s2 in succ.get(i,[]):
            dfs(s2,nf,nspan)
    dfs(0,set(),(-1,-1))
    return reports

if __name__=="__main__":
    lo=int(sys.argv[1],16); hi=int(sys.argv[2],16)
    for s in STARTS:
        if not (lo<=s<hi): continue
        r=fr(s)
        try: rep=analyze(*r)
        except Exception: continue
        rep=[x for x in rep if x[0] in ("UAF_MEM","UAF_REG","DOUBLE")]
        if rep:
            print(f"fn {s&0xffffffff:08x}-{r[1]&0xffffffff:08x}: {len(rep)}")
            seen=set()
            for k,a,rn,ctx in rep:
                if (k,a) in seen: continue
                seen.add((k,a))
                print(f"    {k} {a&0xffffffff:08x} {rn}  {ctx}")
