# per-kext Mach-O header parse inside __PRELINK_TEXT -> exact segment ranges
import json, struct
from kc import load
k = load()
ks = json.load(open('kexts.json'))
out = []
for e in ks:
    a = e['addr']
    if a < 0xfffffff007000000: continue
    hdr = k.rd(a, 32)
    if not hdr or struct.unpack_from('<I',hdr,0)[0] != 0xfeedfacf:
        e['ok']=False; out.append(e); continue
    ncmds, sizeofcmds = struct.unpack_from('<II', hdr, 16)
    segs=[]
    off=a+32
    for i in range(ncmds):
        cmd,cmdsize = struct.unpack_from('<II', k.rd(off,8), 0)
        if cmd==0x19:
            p=k.rd(off,72)
            name=p[8:24].rstrip(b'\0').decode()
            vmaddr,vmsize,fileoff,filesize,maxp,initp,nsects,fl = struct.unpack_from('<QQQQiiII',p,24)
            segs.append(dict(name=name,va=vmaddr,vs=vmsize,fo=fileoff,fs=filesize,prot=initp))
        off+=cmdsize
    e['segs']=segs; e['ok']=True
    out.append(e)
json.dump(out, open('kmap.json','w'), indent=1)
print("parsed", sum(1 for x in out if x.get('ok')), "/", len(out))
for x in out:
    if not x.get('ok'): print("  FAIL", x['id'])
for x in out:
    if x['id'] in ('com.apple.iokit.IOGPUFamily','com.apple.iokit.IOSurface','com.apple.AGXG14P','com.apple.driver.AppleSEPKeyStore','com.apple.driver.AppleH11ANEInterface','com.apple.driver.AppleJPEGDriver'):
        print(x['id'])
        for s in x['segs']: print(f"   {s['name']:18} {s['va']:#018x} vs={s['vs']:#x} fs={s['fs']:#x} prot={s['prot']}")
