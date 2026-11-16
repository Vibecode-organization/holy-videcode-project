import struct,sys
def uleb(d,o):
    r=0;s=0
    while True:
        b=d[o];o+=1;r|=(b&0x7f)<<s;s+=7
        if not b&0x80: return r,o
for p in sys.argv[1:]:
    d=open(p,'rb').read()
    ncmds=struct.unpack("<I",d[16:20])[0]; off=32
    base=None; fs=None; text=None
    for i in range(ncmds):
        cmd,sz=struct.unpack("<II",d[off:off+8])
        if cmd==0x19: base=struct.unpack("<Q",d[off+8:off+16])[0]
        if cmd==0x26: fs=struct.unpack("<II",d[off+8:off+16])
        if cmd==0x19:
            seg=struct.unpack("<16sQQQQiiII",d[off+8:off+8+64])
            name=seg[0].rstrip(b'\0')
            if name==b'__TEXT': text=(seg[1],seg[3],seg[4])  # vmaddr, fileoff, filesize
        off+=sz
    # patch base for kext: fileoff 0 corresponds to vmaddr of __TEXT
    if not text: print(p,"no __TEXT"); continue
    vmaddr,fileoff,filesize=text
    o=fs[0]; n=0; addrs=[]
    prev=vmaddr
    while o < fs[0]+fs[1]:
        v,o=uleb(d,o)
        if v==0: break
        prev+=v; addrs.append(prev); n+=1
    print(p, "funcs:",n, "text vmaddr %#x size %#x"%(vmaddr,filesize))
