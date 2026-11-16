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
def off2va(o):
    for n,sva,vs,fo,fs in SEGS:
        if fo<=o<fo+fs: return sva+(o-fo)
def rd(va,n):
    o=va2off(va); return D[o:o+n] if o is not None else b''
def q(va):
    o=va2off(va); return struct.unpack_from('<Q',D,o)[0] if o is not None else 0
def u32(va):
    o=va2off(va); return struct.unpack_from('<I',D,o)[0] if o is not None else 0
def unptr(v): return BASE+(v & 0x0FFFFFFF) if v else None
def cstr(va,maxlen=400):
    o=va2off(va)
    if o is None: return None
    e=D.find(b'\0',o,o+maxlen)
    if e<0: return None
    try: return D[o:e].decode('utf-8')
    except: return None
raw=D[0x3a74000:0x3a74000+0x23c000]
pl=plistlib.loads(raw[:raw.find(b'</plist>')+8])
def macho_ranges(va):
    """parse mach header at va, return dict seg->(vmaddr,vmsize)"""
    if u32(va)!=0xfeedfacf: return None
    ncmds=u32(va+16); off=va+32; out={}
    for _ in range(ncmds):
        cmd=u32(off); sz=u32(off+4)
        if cmd==0x19:
            nm=rd(off+8,16).split(b'\0')[0].decode()
            sva,vs=struct.unpack('<QQ',rd(off+24,16))
            out[nm]=(sva,vs)
        off+=sz
    return out
KEXTS=[]
for e in pl['_PrelinkInfoDictionary']:
    la=e.get('_PrelinkExecutableLoadAddr')
    if la is None: continue
    la=int(la)&0xffffffffffffffff
    if la==0x7fffffffffffffff: continue
    segs=macho_ranges(la)
    if not segs: 
        print("no macho",hex(la),e.get('CFBundleIdentifier')); continue
    te=segs.get('__TEXT_EXEC')
    KEXTS.append({'id':e.get('CFBundleIdentifier','?'),'exe':e.get('CFBundleExecutable',''),
                  'load':la,'text_exec':te,'segs':{k:list(v) for k,v in segs.items()}})
KEXTS=[k for k in KEXTS if k['text_exec']]
KEXTS.sort(key=lambda k:k['text_exec'][0])
json.dump(KEXTS,open('kmap.json','w'),indent=1)
print("kexts with __TEXT_EXEC:",len(KEXTS))
tot=sum(k['text_exec'][1] for k in KEXTS)
print("sum text_exec",hex(tot),"vs 0x2924000")
prev=None
for k in KEXTS:
    a,s=k['text_exec']; 
    if prev and a<prev: print("OVERLAP",k['id'],hex(a),hex(prev))
    prev=a+s
print("first",KEXTS[0]['id'],hex(KEXTS[0]['text_exec'][0]))
print("last",KEXTS[-1]['id'],hex(KEXTS[-1]['text_exec'][0]),hex(sum(KEXTS[-1]['text_exec'])))

def kext_of(va):
    import bisect
    lo,hi=0,len(KEXTS)-1
    if not KEXTS: return None
    # build on first use
    global _IDX
    try: _IDX
    except NameError:
        _IDX=[(k['text_exec'][0],k['text_exec'][0]+k['text_exec'][1],k['id']) for k in KEXTS]
    for a,b,i in _IDX:
        if a<=va<b: return i
    return None
