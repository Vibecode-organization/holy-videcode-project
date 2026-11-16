import struct, subprocess, functools
KC = "/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache"
DATA = open(KC,'rb').read()
print("size", len(DATA))

MAGIC = 0xfeedfacf
ncmds = struct.unpack_from('<I', DATA, 16)[0]
sizeofcmds = struct.unpack_from('<I', DATA, 20)[0]
print("ncmds", ncmds, "sizeofcmds", sizeofcmds)
off = 32
segs = {}
for i in range(ncmds):
    cmd, cmdsize = struct.unpack_from('<II', DATA, off)
    if cmd == 0x19:  # LC_SEGMENT_64
        name = DATA[off+8:off+24].rstrip(b'\0').decode()
        vmaddr, vmsize, fileoff, filesize = struct.unpack_from('<QQQQ', DATA, off+24)
        maxprot, initprot = struct.unpack_from('<ii', DATA, off+56)
        nsects = struct.unpack_from('<I', DATA, off+64)[0]
        segs[name] = dict(vmaddr=vmaddr, vmsize=vmsize, fileoff=fileoff, filesize=filesize,
                          maxprot=maxprot, initprot=initprot, hdr=(off,cmdsize), nsects=nsects)
        print(f"{name:18s} vm={vmaddr:#x} vsz={vmsize:#x} fo={fileoff:#x} fsz={filesize:#x} prot={initprot:#x} nsects={nsects}")
    off += cmdsize
