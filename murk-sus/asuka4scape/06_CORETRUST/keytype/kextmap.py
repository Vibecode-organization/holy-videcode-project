"""map VAs to kext bundle via __PRELINK_INFO plist."""
import plistlib, bisect, pickle

KC = '/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache'
d = open(KC, 'rb').read()
seg = d[0x3a74000:0x3a74000 + 0x23c000]
p = plistlib.loads(seg[:seg.find(b'</plist>') + 8])
ks = p['_PrelinkInfoDictionary']
rngs = []
for v in ks:
    la = v.get('_PrelinkExecutableLoadAddr')
    sz = v.get('_PrelinkExecutableSize') or v.get('_PrelinkExecutableSegmentSize')
    if la is None:
        continue
    la &= 0xFFFFFFFFFFFFFFFF
    if not (0xfffffff000000000 <= la <= 0xffffffffffffffff):
        continue
    rngs.append((la, sz or 0, v.get('CFBundleIdentifier') or '?'))
rngs.sort()
pickle.dump(rngs, open('/home/femboychik/work/keytype/kextranges.pkl', 'wb'))


def owner(va):
    lo = [r[0] for r in rngs]
    i = bisect.bisect_right(lo, va) - 1
    if i < 0:
        return '?'
    la, sz, bid = rngs[i]
    if sz and va >= la + sz:
        return '?<gap %016x..%016x>' % (la, la + sz)
    return bid


if __name__ == '__main__':
    print('ranges', len(rngs))
    for r in rngs:
        print('%016x %08x %s' % r)
    print()
    sites = pickle.load(open('/home/femboychik/work/keytype/blhits.pkl', 'rb'))
    from collections import Counter
    c = Counter(owner(s[0]) for s in sites)
    for k, v in c.most_common():
        print('%3d %s' % (v, k))
