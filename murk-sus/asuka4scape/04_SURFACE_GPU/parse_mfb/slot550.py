#!/usr/bin/env python3
# find code that touches IOUserClient vtable slot 0x550 (externalMethod) after loading
# the IOUserClient vtable pointer from a GOT slot -> identifies externalMethod overrides
import json, struct, sys, bisect
from kc import load
k = load()
kmap = json.load(open('kmap.json'))
BASE = 0xfffffff007004000

def segs(kid=None):
    if kid:
        e = next(x for x in kmap if x['id'] == kid)
        return [s for s in e['segs'] if s['name'] == '__TEXT_EXEC']
    return [x for x in k.segs if x['name'] == '__TEXT_EXEC']

def scan(kid=None):
    hits = []
    for s in segs(kid):
        n = s['fs']//4
        w = struct.unpack_from('<%dI' % n, k.data, s['fo'])
        for i, x in enumerate(w):
            pc = s['va']+i*4
            if (x & 0xFFC00000) == 0x91000000 and ((x >> 10) & 0xFFF) == 0x550:
                hits.append((pc, 'add #0x550 r%d,r%d' % (x & 0x1F, (x >> 5) & 0x1F)))
            elif (x & 0xFFC00000) == 0xF9400000 and ((x >> 10) & 0xFFF) == 0xAA:
                hits.append((pc, 'ldr [r%d,#0x550] -> r%d' % ((x >> 5) & 0x1F, x & 0x1F)))
    return hits

if __name__ == '__main__':
    kid = sys.argv[1] if len(sys.argv) > 1 else None
    for pc, txt in scan(kid):
        print(f"{pc:#x}  {txt}")
