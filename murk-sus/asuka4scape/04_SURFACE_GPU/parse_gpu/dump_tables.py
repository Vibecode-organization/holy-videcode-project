import json, struct, sys
from kc import load
k=load()
kmap=json.load(open('kmap.json'))
T={}
for e in kmap:
    for s in e.get('segs',[]):
        if s['fs']: T.setdefault(e['id'],[]).append((s['va'],s['va']+s['vs'],s['name']))
def kext_of(va):
    for kid,segs in T.items():
        for lo,hi,n in segs:
            if lo<=va<hi: return kid,n
    return None,None
def dec(q): return 0xfffffff007004000 + (q & 0x0FFFFFFF)
def entry(va,stride):
    b=k.rd(va,0x28)
    if not b: return None
    fn,sIn,strIn,sOut,strOut=struct.unpack_from('<QIIII',b,0)
    return dict(va=va,fn=dec(fn),sIn=sIn,strIn=strIn,sOut=sOut,strOut=strOut)
TABLES=[
 # (va, stride, n, kext, class_guess)
 (0xfffffff008068b90,0x28,17,'com.apple.iokit.IOSurface','IOSurfaceRootUserClient'),
 (0xfffffff0080694f0,0x28,17,'com.apple.iokit.IOSurface','IOSurfaceRootUserClient(variant)'),
 (0xfffffff007fea200,0x18,56,'com.apple.iokit.IOGPUFamily','IOGPUDeviceUserClient'),
 (0xfffffff007fea740,0x18,56,'com.apple.iokit.IOGPUFamily','IOGPUDeviceUserClient(variant)'),
 (0xfffffff007fef7c0,0x18,3,'com.apple.iokit.IOGPUFamily','?'),
 (0xfffffff007dc4130,0x28,11,'com.apple.driver.AppleH11ANEInterface','?'),
 (0xfffffff007dc43b0,0x28,2,'com.apple.driver.AppleH11ANEInterface','?'),
 (0xfffffff007dc8a90,0x28,4,'com.apple.driver.AppleH11ANEInterface','?'),
 (0xfffffff007e293c0,0x28,6,'com.apple.driver.AppleJPEGDriver','AppleJPEGDriverUserClient'),
]
out=[]
for va,st,n,kext,cls in TABLES:
    rows=[]
    for i in range(n):
        e=entry(va+i*st,st)
        if not e: break
        kid,seg=kext_of(e['fn'])
        e['kext_fn']=kid; e['sel']=i
        rows.append(e)
    out.append(dict(va=va,stride=st,n=len(rows),kext=kext,cls=cls,rows=rows))
json.dump(out,open('tables_target.json','w'),indent=1)
for t in out:
    print(f"\n=== {t['cls']} @ {t['va']:#x} stride={t['stride']:#x} n={t['n']} kext={t['kext']}")
    for r in t['rows']:
        print(f"  sel {r['sel']:3d} fn={r['fn']:#018x} sIn={r['sIn']} strIn={r['strIn']:#x} sOut={r['sOut']} strOut={r['strOut']:#x}")
