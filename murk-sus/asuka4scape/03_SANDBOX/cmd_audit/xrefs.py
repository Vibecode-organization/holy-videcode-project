#!/usr/bin/env python3
# scan BL instructions in __text, map callee stub names, group by caller function
import sys, struct, bisect, json, re
sys.path.insert(0, '/home/femboychik/work/cmd_audit')
import dasm

im = dasm.Image()
text_name, tva, tvsz, tfoff, tfsz = im.segs[0]
code = open(dasm.PATH, 'rb').read()[tfoff:tfoff+tfsz]

# function symbols (nearest preceding)
funcs = [a for a, n in im.syms.items() if re.match(r'^[-+]\[' , n) or n.startswith('_')]
funcs.sort()

def caller(addr):
    i = bisect.bisect_right(funcs, addr) - 1
    if i < 0:
        return None
    a = funcs[i]
    if addr - a > 0x4000:
        return None
    return im.syms[a]

edges = {}
for off in range(0, len(code) - 4, 4):
    w = struct.unpack('<I', code[off:off+4])[0]
    if (w & 0xFC000000) != 0x94000000:
        continue
    imm = w & 0x3FFFFFF
    if imm & 0x2000000:
        imm -= 0x4000000
    tgt = tva + off + imm * 4
    nm = im.name_at(tgt)
    if not nm:
        continue
    c = caller(tva + off)
    if not c:
        continue
    edges.setdefault(c, {}).setdefault(nm, 0)
    edges[c][nm] += 1

filt = sys.argv[1] if len(sys.argv) > 1 else None
for c in sorted(edges):
    if filt and filt not in c:
        continue
    hits = [k for k in edges[c] if any(x in k for x in ('isAllowed', 'entitlement', 'Entitlement', 'allPersonas', 'userIdentity', 'persona', 'Persona', 'allowed', 'Allowed', 'canAccess'))]
    if hits:
        print('\n##', c)
        for k in sorted(hits):
            print('   ', edges[c][k], k)
