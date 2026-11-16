#!/usr/bin/env python3
# enclosing function start for a VA (uses function starts from LC_FUNCTION_STARTS)
import sys, bisect
from kc import Fileset
from vm import VM

fs = Fileset(); vm = VM(fs)
va = int(sys.argv[1], 0)
if va < 0x100000000: va |= 0xFFFFFFF000000000
i = bisect.bisect_right(vm.starts, va)
print(f"prev func start: {vm.starts[i-1] & 0xFFFFFFFF:08x}  (delta {va - vm.starts[i-1]:#x})")
print(f"next func start: {vm.starts[i] & 0xFFFFFFFF:08x}")
print("owner:", vm.owner(va))
