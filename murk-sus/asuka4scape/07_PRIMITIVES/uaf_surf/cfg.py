#!/usr/bin/env python3
"""CFG + simple freed-register analysis over the IOSurface code range."""
import kc, re, bisect, sys
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from capstone.arm64 import ARM64_OP_REG, ARM64_OP_IMM, ARM64_OP_MEM

TXT = "/tmp/opencode/uaf_surf.txt"
LINES = open(TXT).read().splitlines()
INS = []
for l in LINES:
    m = re.match(r"([0-9a-f]{16}): (\S+)\s*(.*?)\s*$", l)
    if m:
        INS.append((int(m.group(1),16), m.group(2), m.group(3)))

BY = {a:(mn,ops) for a,mn,ops in INS}
ADDR = [a for a,_,_ in INS]

def is_start(i):
    a,mn,ops = INS[i]
    if mn != "bti" or ops != "c": return False
    if i+1 >= len(INS): return True
    nmn = INS[i+1][1]
    return nmn in ("pacibsp","sub","stp","ldr","mov","cbz","add","mrs","adrp","str","ldrb")

STARTS = [INS[i][0] for i in range(len(INS)) if is_start(i)]

def func_range(addr):
    j = bisect.bisect_right(STARTS, addr)-1
    if j < 0: return None
    s = STARTS[j]; e = STARTS[j+1] if j+1 < len(STARTS) else s+0x2000
    return s,e

def decode_func(s,e):
    """yield (addr, mnemonic, regs_read, regs_write, target, cond)"""
    md = Cs(CS_ARCH_ARM64, CS_MODE_ARM); md.detail=True
    out=[]
    a=s
    while a<e:
        off=kc.va2off(a)
        chunk=kc.BLOB[off:off+4]
        ins=next(md.disasm(chunk,a),None)
        if ins is None: break
        reads=set(); writes=set()
        for op in ins.operands:
            if op.type==ARM64_OP_REG:
                if op.access & 2: reads.add(op.reg)
                if op.access & 1: writes.add(op.reg)
            elif op.type==ARM64_OP_MEM:
                if op.mem.base: reads.add(op.mem.base)
                if op.mem.index: reads.add(op.mem.index)
        out.append((a, ins.mnemonic, ins.op_str, reads, writes, ins))
        a+=4
    return out

def analyze(addr, verbose=False):
    r=func_range(addr)
    if not r: return None
    s,e=r
    seq=decode_func(s,e)
    idx={a:i for i,(a,*_ ) in enumerate(seq)}
    # successors
    succ={}
    for i,(a,mn,ops,rd,wr,ins) in enumerate(seq):
        nx=i+1
        tg=None
        if mn in ("b","bl"):
            for op in ins.operands:
                if op.type==ARM64_OP_IMM: tg=op.imm & 0xffffffffffffffff
        if mn=="b" and tg is not None:
            succ[i]=[idx[tg]] if tg in idx else []
        elif mn in ("cbz","cbnz","tbz","tbnz"):
            if tg in idx: succ[i]=[nx, idx[tg]] if nx<len(seq) else [idx[tg]]
            else: succ[i]=[nx]
        elif mn.startswith("b."):
            if tg in idx: succ[i]=[nx, idx[tg]] if nx<len(seq) else [idx[tg]]
            else: succ[i]=[nx]
        elif mn in ("ret","retab"):
            succ[i]=[]
        elif mn in ("br","braa","blraa","blr","braaz","blraaz"):
            succ[i]=[] if mn in ("braa","braaz") else [nx]
        else:
            succ[i]=[nx] if nx<len(seq) else []

    # identify release calls: blraa preceded by ldr xN,[xM,#0x28]!
    rel_at={}   # insn idx of blraa -> register released (from preceding mov x0,xR)
    for i,(a,mn,ops,rd,wr,ins) in enumerate(seq):
        if mn=="blraa":
            reg=None
            for j in range(max(0,i-4),i):
                m2=seq[j][1]; o2=seq[j][2]
                mm=re.match(r"x0, (x\d+)",o2) if m2=="mov" else None
                if mm: reg=mm.group(1)
            rel_at[i]=reg

    reports=[]
    def dfs(i, freed, path):
        if i is None or i>=len(seq): return
        a,mn,ops,rd,wr,ins=seq[i]
        if i in rel_at:
            reg=rel_at[i]
            if reg and reg in freed:
                reports.append(("DOUBLE_FREE", a, reg, list(path)))
            elif reg:
                freed=freed|{reg}
        # invalidate freed regs on redefinition
        newfreed=set(freed)
        for op in ins.operands:
            if op.type==ARM64_OP_REG and (op.access & 1):
                name=ins.reg_name(op.reg)
                if name in newfreed:
                    newfreed.discard(name)
        key=(i, frozenset(newfreed))
        if key in visited: return
        visited.add(key)
        path.append(a)
        for s2 in succ.get(i,[]):
            dfs(s2, newfreed, path)
        path.pop()

    visited=set()
    dfs(0,set(),[])
    return dict(start=s,end=e,releases=rel_at,reports=reports)

if __name__=="__main__":
    import an
    calls=[int(x,16) for x in sys.argv[1:]]
    for c in calls:
        r=analyze(0xfffffff000000000+c)
        if not r: continue
        bad=[x for x in r['reports']]
        if bad:
            print(f"fn {r['start']:016x}-{r['end']:016x} call {c:08x}: {len(bad)} double-free paths")
            for k,a,reg,p in bad[:3]:
                print("   ",k,hex(a),reg,"pathlen",len(p))
