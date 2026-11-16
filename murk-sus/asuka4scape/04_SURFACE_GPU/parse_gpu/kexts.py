import plistlib, json
from kc import load
k = load()
s = k.seg_by_name['__PRELINK_INFO']
d = k.data[s['fileoff']:s['fileoff']+s['filesize']]
end = d.rfind(b'</plist>') + 8
pl = plistlib.loads(d[:end])
U = lambda v: None if v is None else (v & 0xFFFFFFFFFFFFFFFF)
out = []
for e in pl['_PrelinkInfoDictionary']:
    out.append(dict(id=e.get('CFBundleIdentifier'), exe=e.get('CFBundleExecutable'),
                    ver=e.get('CFBundleVersion'), addr=U(e.get('_PrelinkExecutableLoadAddr')),
                    size=e.get('_PrelinkExecutableSize'), kmod=U(e.get('_PrelinkKmodInfo'))))
ks=[x for x in out if x['addr']]
ks.sort(key=lambda x:x['addr'])
json.dump(ks, open('kexts.json','w'), indent=1)
print("total", len(out), "with addr", len(ks))
for x in ks[:14]:
    print(f"{x['addr']:#018x} +{x['size'] or 0:#09x} -> {(x['addr']+(x['size'] or 0)):#018x}  {x['id']}")
print('...')
for x in ks:
    if any(t in (x['id'] or '').lower() for t in ['framebuffer','keystore','ane','gpu','surface','jpeg','agx']):
        print(f"{x['addr']:#018x} +{x['size'] or 0:#09x} -> {(x['addr']+(x['size'] or 0)):#018x}  {x['id']}")
