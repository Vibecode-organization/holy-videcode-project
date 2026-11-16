import struct, plistlib, json
P="/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache"
D=open(P,'rb').read()
BASE=0xfffffff007004000
SEGS=[("__TEXT",0xfffffff007004000,0x8000,0x0,0x8000),
("__PRELINK_TEXT",0xfffffff00700c000,0xbac000,0x8000,0xbac000),
("__DATA_CONST",0xfffffff007bb8000,0x548000,0xbb4000,0x548000),
("__DATA_SPTM",0xfffffff008100000,0x4c000,0x10fc000,0x4c000),
("__TEXT_EXEC",0xfffffff00814c000,0x2924000,0x1148000,0x2924000),
("__TEXT_BOOT_EXEC",0xfffffff00aa70000,0x8000,0x3a6c000,0x8000),
("__PRELINK_INFO",0xfffffff00aa78000,0x23c000,0x3a74000,0x23c000),
("__DATA",0xfffffff00acb4000,0x2b8000,0x3cb0000,0x2b8000),
("__LINKEDIT",0xfffffff00af6c000,0xb8000,0x3f68000,0xb8000)]
def va2off(va):
    for n,sva,vs,fo,fs in SEGS:
        if sva<=va<sva+vs: return fo+(va-sva)
    return None
def off2va(o):
    for n,sva,vs,fo,fs in SEGS:
        if fo<=o<fo+fs: return sva+(o-fo)
    return None
def rd(va,n):
    o=va2off(va)
    return D[o:o+n] if o is not None else b''
def q(va):
    o=va2off(va)
    return struct.unpack_from('<Q',D,o)[0] if o is not None else 0
def u32(va):
    o=va2off(va)
    return struct.unpack_from('<I',D,o)[0] if o is not None else 0
def unptr(v):
    if v is None: return None
    return BASE + (v & 0x0FFFFFFF)
def cstr(va,maxlen=300):
    o=va2off(va)
    if o is None: return None
    e=D.find(b'\0',o,o+maxlen)
    if e<0: return None
    try: return D[o:e].decode('utf-8')
    except: return None
# kext map
raw=D[0x3a74000:0x3a74000+0x23c000]
end=raw.find(b'</plist>')+len(b'</plist>')
pl=plistlib.loads(raw[:end])
KEXTS=[]
for e in pl['_PrelinkInfoDictionary']:
    la=e.get('_PrelinkExecutableLoadAddr'); sz=e.get('_PrelinkExecutableSize')
    bid=e.get('CFBundleIdentifier','?')
    if la is None: continue
    la=int(la)&0xffffffffffffffff
    KEXTS.append((la,la+(sz or 0),bid,e.get('CFBundleExecutable','')))
KEXTS.sort()
def kext_of(va):
    for lo,hi,bid,exe in KEXTS:
        if lo<=va<hi: return bid
    return None
json.dump([[a,b,c,d] for a,b,c,d in KEXTS],open('kexts.json','w'),indent=0)
