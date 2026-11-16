#!/usr/bin/env python3
# dump IOGPUDeviceUserClient external method dispatch table
import struct, sys
from kc import Fileset
from vm import VM

fs = Fileset(); vm = VM(fs)
TBL = 0xFFFFFFF007FEA200

def pac(q):
    return 0xFFFFFFF007004000 + (q & 0x0FFFFFFF)

for i in range(int(sys.argv[1]) if len(sys.argv) > 1 else 56):
    va = TBL + i*0x18
    b = vm.read(va, 0x18)
    fn, scin, stin, scout, stout = struct.unpack('<QIIII', b)
    print(f"sel {i:2d}  fn={pac(fn)&0xFFFFFFFF:08x}  raw={fn:016x}  scIn={scin:#x} stIn={stin:#x} scOut={scout:#x} stOut={stout:#x}")
