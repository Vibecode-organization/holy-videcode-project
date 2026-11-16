from kc import *
import struct,sys
M64=0xFFFFFFFFFFFFFFFF
targets={}
for a in sys.argv[1:]:
    targets[int(a,0)&M64]=a
# scan __DATA_CONST + __DATA for 8-byte values that pac() to targets
for n,sv,sz,off in SEGS:
    if n not in ("__DATA_CONST","__DATA"): continue
    p=off
    while p<off+sz-8:
        q=struct.unpack_from("<Q",DATA,p)[0]
        if q:
            r=pac(q)
            if r in targets:
                va=sv+(p-off)
                print(f"slot {va:#x} -> {r:#x}   (raw {q:#x})")
        p+=8
