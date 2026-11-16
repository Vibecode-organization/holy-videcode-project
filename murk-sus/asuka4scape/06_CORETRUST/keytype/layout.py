"""parse mach-o load commands of 27.2 kernelcache: segments, sections, and which ones are GOT."""
import struct, sys

KC = '/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache'
d = open(KC, 'rb').read()
magic, cputype, cpusub, ftype, ncmds, sizeofcmds, flags, res = struct.unpack_from('<IiiIIIII', d, 0)
print('magic', hex(magic), 'ncmds', ncmds, 'sizeofcmds', hex(sizeofcmds))
off = 32
segs = []
for i in range(ncmds):
    cmd, cmdsize = struct.unpack_from('<II', d, off)
    if cmd == 0x19:  # LC_SEGMENT_64
        name = d[off+8:off+24].rstrip(b'\0').decode()
        vmaddr, vmsize, fileoff, filesize, maxprot, initprot, nsects, sflags = struct.unpack_from('<QQQQIIII', d, off+24)
        secs = []
        so = off + 72
        for j in range(nsects):
            sname = d[so:so+16].rstrip(b'\0').decode()
            segname = d[so+16:so+32].rstrip(b'\0').decode()
            addr, size, offset, align, reloff, nreloc, sfl, r1, r2, r3 = struct.unpack_from('<QQIIIIIIII', d, so+32)
            secs.append((sname, addr, size, offset, sfl))
            so += 80
        segs.append((name, vmaddr, vmsize, fileoff, filesize, initprot, secs))
        off += cmdsize
    elif cmd == 0x80000022:  # LC_DYLD_CHAINED_FIXUPS? actually 0x80000034
        off += cmdsize
    else:
        off += cmdsize

for name, vmaddr, vmsize, fileoff, filesize, ip, secs in segs:
    print('SEG %-18s va=%016x size=%08x off=%08x fsz=%08x prot=%d' % (name, vmaddr, vmsize, fileoff, filesize, ip))
    for sname, addr, size, offset, sfl in secs:
        if any(t in sname for t in ('got', 'const', 'la_symbol', 'nl_symbol', 'stubs')):
            print('    SEC %-20s va=%016x size=%06x off=%08x fl=%08x' % (sname, addr, size, offset, sfl))
