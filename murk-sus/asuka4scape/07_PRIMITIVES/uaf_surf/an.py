#!/usr/bin/env python3
"""extract functions around IOSurface code; report lookup/retain/release and call targets."""
import kc, re, sys
from capstone.arm64 import ARM64_OP_REG, ARM64_OP_IMM, ARM64_OP_MEM

TXT = "/tmp/opencode/uaf_surf.txt"
LINES = open(TXT).read().splitlines()

def parse(l):
    m = re.match(r"([0-9a-f]{16}): (\S+)\s*(.*?)\s*$", l)
    if not m: return None
    a = int(m.group(1),16); mn = m.group(2); ops = m.group(3)
    return a, mn, ops

INS = [parse(l) for l in LINES]
INS = [x for x in INS if x]

def is_start(i):
    a,mn,ops = INS[i]
    if mn != "bti" or ops != "c": return False
    if i+1 >= len(INS): return True
    nmn,nops = INS[i+1][1], INS[i+1][2]
    if nmn in ("pacibsp","sub","stp","ldr","mov","cbz","add","mrs","adrp","str"): return True
    return False

STARTS = [INS[i][0] for i in range(len(INS)) if is_start(i)]

def func_of(addr):
    lo=0; hi=len(STARTS)-1; best=0
    import bisect
    j=bisect.bisect_right(STARTS, addr)-1
    if j<0: return None
    s=STARTS[j]; e=STARTS[j+1] if j+1<len(STARTS) else STARTS[j]+0x2000
    return s,e

def show_func(addr, maxn=4000):
    r=func_of(addr)
    if not r: return
    s,e=r
    print(f"### func {s:016x} .. {e:016x}  (call at {addr:016x})")
    n=0
    for a,mn,ops in INS:
        if a<s: continue
        if a>=e: break
        print(f"{a:016x}: {mn:9s} {ops}")
        n+=1
        if n>maxn: break
        if mn in ("ret","retab") and a+4>=e-8: pass

def summarize(addr):
    s,e=func_of(addr)
    if not s: return None
    look=[];rel=[];ret=[];calls=[]
    slot=None
    for a,mn,ops in INS:
        if a<s: continue
        if a>=e: break
        if mn=="bl" and "9c3f1d0" in ops: look.append(a)
        if mn=="ldr" and "#0x28]!" in ops: rel.append(a)
        if mn=="ldr" and "#0x20]!" in ops: ret.append(a)
        if mn=="bl":
            m=re.search(r"-> ([0-9a-f]{16})", ops)
            if m: calls.append((a,m.group(1)))
    return dict(start=s,end=e,look=look,rel=rel,ret=ret,calls=calls)

if __name__=="__main__":
    if sys.argv[1]=="s":
        for a in [int(x,16) for x in sys.argv[2:]]:
            print(summarize(a))
    else:
        show_func(int(sys.argv[1],16))
