#!/usr/bin/env python3
# Show only semantically-interesting diffs (mnemonic or mem-displacement changes).
import sys, re
lines=open(sys.argv[1]).read().splitlines()
lo=int(sys.argv[2],16) if len(sys.argv)>2 else 0
hi=int(sys.argv[3],16) if len(sys.argv)>3 else 1<<64
cur=None; buf=[]; keep=False
def flush():
    global cur,buf
    if cur and keep and buf:
        print(cur); print('\n'.join(buf))
    cur=None; buf=[]
for l in lines:
    m=re.match(r'=== (0x[0-9a-f]+) \((\d+)\) -> (0x[0-9a-f]+) \((\d+)\) d=([+-]\d+) insn (\d+)->(\d+) hunks=(\d+)',l)
    if m:
        flush(); cur=l; buf=[]
        b=int(m.group(3),16); keep=lo<=b<hi
        continue
    if cur is None: continue
    if l.startswith('  --') or l.startswith('  ..'): buf.append(l.strip())
    elif l.strip().startswith('A ') or l.strip().startswith('B '): buf.append(l.strip())
flush()
