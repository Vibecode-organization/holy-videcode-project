#!/usr/bin/env python3
import base64,struct,sys,os
src,out=sys.argv[1],sys.argv[2]
d=base64.b64decode(open(src).read())
n=struct.unpack_from('<I',d,16)[0]; off=32; lc=None
for _ in range(n):
    cmd,sz=struct.unpack_from('<II',d,off)
    if cmd==0x1d: lc=off
    off+=sz
so=struct.unpack_from('<I',d,lc+8)[0]; ss=struct.unpack_from('<I',d,lc+12)[0]; sig=d[so:so+ss]
magic,length,count=struct.unpack_from('>III',sig,0)
os.makedirs(out,exist_ok=True)
for i in range(count):
    t,o=struct.unpack_from('>II',sig,12+i*8); blen=struct.unpack_from('>I',sig,o+4)[0]; blob=sig[o:o+blen]
    open(os.path.join(out,'type_%x.bin'%t),'wb').write(blob)
    if t==0x10000:
        open(os.path.join(out,'cms.der'),'wb').write(blob[8:])
    if t==0:
        open(os.path.join(out,'real_cd.bin'),'wb').write(blob)
    print('type',hex(t),'len',blen)
