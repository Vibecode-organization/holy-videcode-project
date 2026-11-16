import kc, struct, pickle
def fn_va(q): return kc.unpac(q)
def is_fn(q):
    if (q >> 32) & 0xFFFF == 0xBCAD:
        v = kc.unpac(q); return 0xfffffff00700c000 <= v < 0xfffffff00aa78000
    if 0xfffffff000000000 <= q < 0xfffffff100000000:
        return 0xfffffff00700c000 <= q < 0xfffffff00aa78000
    return False
def eok(o, stride, maxv=0x1000000):
    if not is_fn(struct.unpack_from("<Q", kc.D, o)[0]): return False
    nd = 4 if stride == 0x18 else 5
    for k in range(2, 2+nd):
        v = struct.unpack_from("<I", kc.D, o+k*4)[0]
        if not (v == 0xffffffff or v <= maxv): return False
    return True
def scan(minlen=3):
    out=[]
    for name, base, size, off in kc.SEGS:
        if name not in ("__DATA_CONST","__DATA"): continue
        for stride in (0x18, 0x28):
            i=0
            while i + stride*minlen <= size:
                if eok(off+i, stride):
                    c=0;j=i
                    while j+stride<=size and eok(off+j, stride): c+=1;j+=stride
                    if c>=minlen:
                        out.append((base+i,stride,c,name)); i=j; continue
                i+=8
    return out
if __name__=="__main__":
    r=scan()
    print(len(r))
    for x in r: print(hex(x[0]),hex(x[1]),x[2],x[3])
    pickle.dump(r, open("dt3.pkl","wb"))
