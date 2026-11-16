import sys, struct
sys.path.insert(0,'.')
from macho import *

BASE = 0xfffffff007004000
TBL  = 0xfffffff008068b90
N    = 120
STRIDE = 0x28

def fixup(v):
    # arm64e chained fixup (auth rebase): low 32 = runtime offset from image base
    off = v & 0xffffffff
    return (BASE + off) & 0xffffffffffffffff

rows=[]
for i in range(N):
    a = TBL + i*STRIDE
    p = u64(a)
    f = [u32(a+8+4*j) for j in range(8)]
    rows.append((i,p,fixup(p),f))

out=[]
for i,p,h,f in rows:
    out.append(f"{i:3d} {h:#018x} raw={p:#018x} sin={f[0]:#x} szin={f[1]:#x} sout={f[2]:#x} szout={f[3]:#x} | sin2={f[4]:#x} szin2={f[5]:#x} sout2={f[6]:#x} szout2={f[7]:#x}")
print("\n".join(out))
open("tables/iosurface_dispatch_0x8068b90.txt","w").write("\n".join(out)+"\n")
