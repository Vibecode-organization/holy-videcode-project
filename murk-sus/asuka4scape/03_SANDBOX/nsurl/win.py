#!/usr/bin/env python3
# print a window of the pre-dumped llvm-objdump text with resolved bl targets
import sys, re
lines = open("disasm.txt", encoding="utf-8", errors="replace").read().splitlines()
ins = {}
order = []
for ln in lines:
    m = re.match(r'^\s*([0-9a-f]{6,}):\t(.*)$', ln)
    if m:
        a = int(m.group(1), 16); ins[a] = m.group(2); order.append(a)
order.sort()
import bisect
start = int(sys.argv[1], 16)
count = int(sys.argv[2]) if len(sys.argv) > 2 else 60
i = bisect.bisect_left(order, start)
for a in order[i:i+count]:
    print(f"{a:#x}:\t{ins[a]}")
