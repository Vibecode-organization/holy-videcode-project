import struct
from kc import DATA, segs
# scan all load commands for types of interest
ncmds = struct.unpack_from('<I', DATA, 16)[0]
off = 32
for i in range(ncmds):
    cmd, cmdsize = struct.unpack_from('<II', DATA, off)
    print(f"{i:3d} cmd={cmd:#x} ({cmd & 0x7fffffff:#x}) size={cmdsize:#x} off={off:#x}")
    if cmd==0x19: pass
    off += cmdsize
