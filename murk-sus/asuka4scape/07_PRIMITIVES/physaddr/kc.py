import struct, bisect
PATH='/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache'
KERNEL_BASE=0xfffffff007004000
D=open(PATH,'rb').read()
MASK=0xFFFFFFFFFFFFFFFF

# ---------- outer mach-o ----------
_ncmds=struct.unpack_from('<I',D,16)[0]
_off=32; FS=[]
for _ in range(_ncmds):
    cmd,cs=struct.unpack_from('<II',D,_off)
    if cmd==0x80000035:
        vm,fo,ents,r,le=struct.unpack_from('<QQIII',D,_off+8)
        FS.append((D[_off+32:_off+cs].split(b'\0')[0].decode(),vm,fo))
    _off+=cs

def parse_kext(name):
    e=[x for x in FS if x[0]==name][0]
    hdr=e[2]
    magic,cpu,sub,ft,nc,sc,fl,rs=struct.unpack_from('<IiiIIIII',D,hdr)
    o=hdr+32; segs=[]
    for i in range(nc):
        c,cs=struct.unpack_from('<II',D,o)
        if c==0x19:
            nm=D[o+8:o+24].split(b'\0')[0].decode()
            vm,vs,fo,fz=struct.unpack_from('<QQQQ',D,o+24)
            segs.append((nm,vm,vs,fo,fz))
        o+=cs
    return segs

# ---------- global va->off table (all kexts) ----------
RANGES=[]   # (vmstart, vmend, fo, name)
for nm,vm,fo in FS:
    for s in parse_kext(nm):
        RANGES.append((s[1], s[1]+s[2], s[3], nm, s[0]))
RANGES.sort()
STARTS=[r[0] for r in RANGES]

def segof(va):
    i=bisect.bisect_right(STARTS,va)-1
    if i<0: raise KeyError(hex(va))
    r=RANGES[i]
    if va>=r[1]: raise KeyError(hex(va))
    return r

def va2off(va):
    r=segof(va); return r[2]+(va-r[0])

def off2va(o):
    for st,en,fo,nm,sn in RANGES:
        if fo<=o<fo+(en-st): return st+(o-fo)
    raise KeyError(hex(o))

def q(va): return struct.unpack_from('<Q',D,va2off(va))[0]
def d32(va): return struct.unpack_from('<I',D,va2off(va))[0]
def blob(va,n): o=va2off(va); return D[o:o+n]
def cstr(va,lim=512):
    o=va2off(va); e=D.index(b'\0',o,o+lim); return D[o:e].decode('utf-8','replace')

def pt(va):
    """decode arm64e chained pointer at va -> (target_va, next, auth, tag) or None"""
    v=q(va)
    if v==0: return None
    if v & (1<<63):
        tgt=(v & 0xFFFFFFFFF) | (0xFFFFFF<<56)
        return (tgt&MASK, (v>>51)&0x7FF, True, (v>>49)&3)
    tgt=(v & 0xFFFFFFFFF) | (((v>>36)&0xFF)<<56)
    return (tgt&MASK, (v>>51)&0x7FF, False, 0)
