import plistlib, re, json
from kcd import data, SECTIONS
pva,psz,pfo = SECTIONS['__PRELINK_INFO']
blob = data[pfo:pfo+psz]
xml = blob.decode('utf-8','replace')
end = xml.rfind('</plist>')+len('</plist>')
xml = xml[:end]
# strip any trailing garbage after </plist>
pl = plistlib.loads(xml.encode())
info = pl['_PrelinkInfoDictionary']
print("entries:", len(info))
ranges=[]
for d in info:
    bid = d.get('CFBundleIdentifier','?')
    la = d.get('_PrelinkExecutableLoadAddr')
    sz = d.get('_PrelinkExecutableSize')
    if isinstance(la,int) and isinstance(sz,int):
        ranges.append((la, la+sz, bid))
ranges.sort()
print("ranges:", len(ranges))
json.dump(ranges, open('kext_ranges.json','w'))
def which(va):
    for a,b,bid in ranges:
        if a<=va<b: return bid, a, b
    return None
for va in (0xfffffff008fcf904, 0xfffffff008fd0ee4, 0xfffffff008fd1088, 0xfffffff009c3ee14, 0xfffffff009c3a60c, 0xfffffff0080694f0, 0xfffffff008068b90):
    print(hex(va), which(va))
