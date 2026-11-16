import plistlib, json
from kcd import data, SECTIONS
pva,psz,pfo = SECTIONS['__PRELINK_INFO']
blob = data[pfo:pfo+psz].decode('utf-8','replace')
blob = blob[:blob.rfind('</plist>')+8]
pl = plistlib.loads(blob.encode())
M=(1<<64)-1
info = pl['_PrelinkInfoDictionary']
ranges=[]
for d in info:
    bid=d.get('CFBundleIdentifier','?')
    la=d.get('_PrelinkExecutableLoadAddr'); sa=d.get('_PrelinkExecutableSourceAddr')
    sz=d.get('_PrelinkExecutableSize')
    if not isinstance(sa,int) or not isinstance(sz,int): continue
    sa &= M
    ranges.append((sa, sa+sz, bid))
ranges.sort()
json.dump(ranges, open('kext_ranges3.json','w'))
print("ranges", len(ranges), "min",hex(ranges[0][0]),"max",hex(max(x[1] for x in ranges)))
def which(va):
    for a,b,bid in ranges:
        if a<=va<b: return bid,a,b
    return None
for va in (0xfffffff008fcf904,0xfffffff008fd0ee4,0xfffffff008fd1088,0xfffffff008fd1700,
           0xfffffff009c3ee14,0xfffffff009c3a60c,0xfffffff009c3a2c0,
           0xfffffff0080694f0,0xfffffff008068b90):
    print(hex(va), which(va))
