import struct,sys
P='/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache'
d=open(P,'rb').read()
magic=struct.unpack('<I',d[:4])[0]
print('magic %08x'%magic)
ncmds,szcmds=struct.unpack('<II',d[16:24])
print('ncmds',ncmds,'szcmds',szcmds)
off=32
segs={}
for i in range(ncmds):
    cmd,cmdsize=struct.unpack('<II',d[off:off+8])
    if cmd==0x19:
        name=d[off+8:off+24].rstrip(b'\0').decode()
        vmaddr,vmsize,fileoff,filesize=struct.unpack('<QQQQ',d[off+24:off+56])
        nsects=struct.unpack('<I',d[off+64:off+68])[0]
        segs[name]=(vmaddr,vmsize,fileoff,filesize)
        print('SEG %-16s va=%016x size=%08x off=%08x fsize=%08x nsects=%d'%(name,vmaddr,vmsize,fileoff,filesize,nsects))
        so=off+72
        for j in range(nsects):
            sname=d[so:so+16].rstrip(b'\0').decode()
            sseg=d[so+16:so+32].rstrip(b'\0').decode()
            saddr,ssize=struct.unpack('<QQ',d[so+32:so+48])
            soff=struct.unpack('<I',d[so+48:so+52])[0]
            print('   SEC %-20s va=%016x size=%08x off=%08x'%(sname,saddr,ssize,soff))
            so+=80
    off+=cmdsize
