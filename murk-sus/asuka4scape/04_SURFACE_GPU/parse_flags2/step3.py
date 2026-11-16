import struct
from kcd import data, SECTIONS, va2off
def rdq(va): return struct.unpack_from('<Q', data, va2off(va))[0]
def rdd(va): return struct.unpack_from('<I', data, va2off(va))[0]
def cstr(va, n=64):
    o = va2off(va); b=b''
    for i in range(n):
        c=data[o+i]
        if c==0: break
        b+=bytes([c])
    return b.decode('utf-8','replace')
def unpac(q):
    if (q>>32)&0xffffffff == 0x8050bcad:
        return 0xfffffff007004000 + (q & 0x0FFFFFFF)
    return None

# jump table B: base 0x8fd1964, 0xf9 entries, relative to 0x8fd0f08
tb = 0xfffffff008fd1964
base = 0xfffffff008fd0f08
print("=== dispatcher B (setter) table @0x%x, base 0x%x"%(tb,base))
sel_map = {}
for i in range(0xf9):
    off = struct.unpack('<i', struct.pack('<I', rdd(tb+i*4)))[0]
    tgt = base+off
    sel = i+6
    sel_map[tgt]=sel
for want in (0xfffffff008fd1088, 0xfffffff008fd1700):
    for t,s in sel_map.items():
        if t==want: print(f"  handler 0x{t:x} -> selector {s} (0x{s:x})")
print("  handler count distinct:", len(sel_map))

print()
print("=== name table @0x7e9cd98 (210 entries) ===")
nt = 0xfffffff007e9cd98
for i in range(0xd2):
    idx = rdd(nt+i*0x10)
    q = rdq(nt+i*0x10+8)
    p = unpac(q) or (q if 0xfffffff000000000 <= q < 0xfffffff100000000 else None)
    s = cstr(p) if p else f"<raw 0x{q:x}>"
    print(f"  [{i:3d}] idx=0x{idx:03x} name={s!r}  (slot 0x{nt+i*0x10:x})")
