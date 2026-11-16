import struct
from kcd import data, SECTIONS, va2off
BASE=0xfffffff007004000
def unpac(q):
    return BASE + (q & 0x0FFFFFFF) if (q>>32)==0x8050bcad else None
def dump(base, n=60, label=''):
    rows=[]
    for i in range(n):
        o=va2off(base+i*0x28)
        q0,q1,q2,q3,q4 = struct.unpack_from('<5Q', data, o)
        act = unpac(q0)
        ins = q1 & 0xFFFFFFFF; inst = q1>>32
        outs = q2 & 0xFFFFFFFF; outsz = q2>>32
        rows.append((i,act,ins,inst,outs,outsz))
    return rows
for base,label in ((0xfffffff008068b90,'A'),(0xfffffff0080694f0,'B')):
    rows = dump(base)
    print(f"=== table {label} (0x{base:x}) : {len(rows)} entries")
    for i,act,ins,inst,outs,outsz in rows:
        print(f"  sel {i:2d}: action=0x{act:x}  in={ins}/{hex(inst)} out={outs}/{hex(outsz)}")
