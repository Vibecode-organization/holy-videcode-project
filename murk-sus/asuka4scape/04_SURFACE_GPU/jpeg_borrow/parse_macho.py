import struct, sys, json

PATH="/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache"
data=open(PATH,'rb').read()

def u32(o): return struct.unpack_from('<I',data,o)[0]
def u64(o): return struct.unpack_from('<Q',data,o)[0]

magic=u32(0); print("magic %#x"%magic)
cputype=u32(4); cpusub=u32(8); ftype=u32(12); ncmds=u32(16); sizeofcmds=u32(20); flags=u32(24)
print("cputype %#x sub %#x ftype %d ncmds %d sizeofcmds %#x flags %#x"%(cputype,cpusub,ftype,ncmds,sizeofcmds,flags))
off=32
LC_FILESET_ENTRY=0x35
SEG=0x19
entries=[]
segs=[]
for i in range(ncmds):
    cmd=u32(off); cmdsize=u32(off+4)
    if cmd==LC_FILESET_ENTRY:
        vmaddr=u64(off+8); fileoff=u64(off+16); entry_id=u64(off+24); reserved=u32(off+32); nameoff=u32(off+36)
        nm=data[off+nameoff:data.index(b'\0',off+nameoff)].decode()
        entries.append((nm,vmaddr,fileoff))
    elif cmd==SEG:
        segname=data[off+8:off+24].rstrip(b'\0').decode()
        vmaddr=u64(off+24); vmsize=u64(off+32); fileoff=u64(off+40); filesize=u64(off+48)
        segs.append((segname,vmaddr,vmsize,fileoff,filesize))
    off+=cmdsize
print("segments:", len(segs))
for s in segs: print("  %-20s va=%#018x size=%#x off=%#x fsize=%#x"%s)
print("fileset entries:", len(entries))
json.dump({"entries":entries,"segs":segs},open('top.json','w'))
for e in entries[:20]: print(e)
