#!/usr/bin/env python3
"""Rebuild a thin Mach-O extracted from a dyld cache, dropping __LINKEDIT and
rewriting segment/section file offsets so LLVM/Ghidra accept the file."""
import sys, struct
LC_SEGMENT_64 = 0x19
ZERO = {0x2,0xb,0x1d,0x1e,0x22,0x26,0x29,0x2b,0x2e,0x80000022,0x80000033,0x80000034}

def main(src,dst):
    d=bytearray(open(src,'rb').read())
    magic,ct,cs,ft,ncmds,sizeofcmds,flags,_=struct.unpack_from('<IiiIIIII',d,0)
    assert magic==0xFEEDFACF
    p=32; end=32+sizeofcmds
    segs=[]
    for _ in range(ncmds):
        cmd,sz=struct.unpack_from('<II',d,p)
        if cmd==LC_SEGMENT_64:
            name=d[p+8:p+24].split(b'\0')[0].decode()
            vm,vs,fo,fs=struct.unpack_from('<QQQQ',d,p+24)
            nsects=struct.unpack_from('<I',d,p+64)[0]
            secs=[]
            q=p+72
            for i in range(nsects):
                # section_64: sectname(16) segname(16) addr(8) size(8) offset(4) align(4) reloff(4) nreloc(4) flags(4) res1(4) res2(4) res3(4)
                addr,size,off=struct.unpack_from('<QQI',d,q+32)
                secs.append((q,addr,size,off))
                q+=80
            segs.append([name,p,vm,vs,fo,fs,secs])
        elif cmd in ZERO:
            for o in range(p+8,p+sz): d[o]=0
        p+=sz

    out=bytearray(d[:end])
    out.extend(b'\0'*((0x4000-len(out)) if len(out)<0x4000 else 0))
    for s in segs:
        name,off,vm,vs,fo,fs,secs=s
        if name=='__LINKEDIT':
            struct.pack_into('<QQ',d,off+40,0,0)
            for q,addr,size,so in secs:
                struct.pack_into('<Q',d,q+40,0) # size 0
                struct.pack_into('<I',d,q+48,0) # offset 0
            continue
        new=len(out)
        chunk=d[fo:fo+fs]
        if len(chunk)<fs: chunk+=b'\0'*(fs-len(chunk))
        out.extend(chunk)
        struct.pack_into('<Q',d,off+40,new)
        for q,addr,size,so in secs:
            if size and addr >= vm:
                struct.pack_into('<I',d,q+48, new + (addr - vm))
            else:
                struct.pack_into('<I',d,q+48, 0)
        s[4]=new
    out[0:end]=d[0:end]
    open(dst,'wb').write(out)
    print('wrote',dst,len(out))
    for s in segs: print(' ',s[0],hex(s[2]),'file',hex(s[4]),'size',hex(s[5]))

main(sys.argv[1],sys.argv[2])
