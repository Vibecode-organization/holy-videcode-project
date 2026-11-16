import struct
from kc import DATA
ncmds=struct.unpack_from('<I',DATA,16)[0]; off=32
entries=[]
for i in range(ncmds):
    cmd,sz=struct.unpack_from('<II',DATA,off)
    if cmd==0x80000035:
        vm,fo,eid,res=struct.unpack_from('<QQII',DATA,off+8)
        s=DATA[off+eid:DATA.index(b'\0',off+eid)].decode()
        entries.append((s,vm,fo))
    off+=sz
print(len(entries))
for s,vm,fo in entries:
    if 'IOSurface' in s or 'IOMobileFramebuffer' in s or 'AppleCLCD' in s or 'IOSurfaceRoot' in s: print(s,hex(vm),hex(fo))
print('---total---')
