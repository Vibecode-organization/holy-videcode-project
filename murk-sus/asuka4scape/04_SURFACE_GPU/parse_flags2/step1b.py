import struct, collections
from kcd import data, SECTIONS, decode, BASE
hi = collections.Counter()
for sec in ('__DATA_CONST','__DATA','__PRELINK_INFO'):
    va,sz,fo = SECTIONS[sec]
    blob = data[fo:fo+sz]
    for i in range(0,len(blob)-8,8):
        q = struct.unpack_from('<Q',blob,i)[0]
        if q>>56 == 0x80 or (q>>48)&0xffff in (0x8050,0x8000,0xffff):
            hi[(q>>32)&0xffffffff]+=1
print("top high-words:")
for k,v in hi.most_common(12):
    print(f"  0x{k:08x}  {v}")
# decode with the canonical key and histogram of target ranges
tg = collections.Counter()
n=0
for sec in ('__DATA_CONST','__DATA'):
    va,sz,fo = SECTIONS[sec]
    blob = data[fo:fo+sz]
    for i in range(0,len(blob)-8,8):
        q = struct.unpack_from('<Q',blob,i)[0]
        d = decode(q)
        if d is not None:
            n+=1
            tg[(d>>16)<<16]+=1
print("total decoded:", n)
print("targets in __TEXT_EXEC range 0x814c000-0xaa70000:", sum(v for k,v in tg.items() if 0xfffffff00814c000<=k<=0xfffffff00aa70000))
for k,v in sorted(tg.items()):
    if 0xfffffff008f00000 <= k <= 0xfffffff009000000:
        print(f"  near 0x8fd: 0x{k:x} x{v}")
