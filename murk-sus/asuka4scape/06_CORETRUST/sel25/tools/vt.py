#!/usr/bin/env python3
# dump a vtable: vt.py <va> <nslots>
import sys, struct
from kc import Fileset
from vm import VM

fs = Fileset(); vm = VM(fs)
BASE = 0xFFFFFFF007004000

def fix(a):
    return a | 0xFFFFFFF000000000 if a < 0x100000000 else a

def pac(q):
    return BASE + (q & 0x0FFFFFFF)

vt = fix(int(sys.argv[1], 0))
n = int(sys.argv[2], 0) if len(sys.argv) > 2 else 44
for i in range(n):
    q = vm.u64(vt + i*8)
    if q is None: break
    print(f"slot {i:2d}  +{i*8:#04x}  raw={q:016x}  fn={pac(q)&0xFFFFFFFF:08x}")
