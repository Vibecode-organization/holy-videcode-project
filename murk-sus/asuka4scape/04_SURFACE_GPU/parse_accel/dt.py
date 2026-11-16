import kc, struct, pickle
def code_va(q):
    if 0xfffffff000000000 <= q < 0xfffffff100000000: return q
    return kc.unpac(q)
def is_code(q):
    v = code_va(q)
    return 0xfffffff00814c000 <= v < 0xfffffff00aa78000 or 0xfffffff00700c000 <= v < 0xfffffff007bb8000

def entry_ok(off, stride):
    q = struct.unpack_from("<Q", kc.D, off)[0]
    if not is_code(q): return False
    # dwords 1..4 (or 1..5 for 0x28)
    n = 4 if stride==0x18 else 5
    for k in range(1,n+1):
        v = struct.unpack_from("<I", kc.D, off+k*4)[0]
        if not (v == 0xffffffff or v <= 0x100000): return False
    return True

def scan():
    out=[]
    for name, base, size, off in kc.SEGS:
        if name not in ("__DATA_CONST","__DATA"): continue
        n = size
        for stride in (0x18, 0x28):
            i = 0
            while i + stride*4 <= n:
                if entry_ok(off+i, stride):
                    cnt = 0
                    j = i
                    while j + stride <= n and entry_ok(off+j, stride):
                        cnt += 1; j += stride
                    if cnt >= 4:
                        out.append((base+i, stride, cnt))
                        i = j
                        continue
                i += 8
    return out

if __name__ == "__main__":
    out = scan()
    print(len(out))
    for a,s,c in out: print(hex(a), hex(s), c)
    pickle.dump(out, open("dt.pkl","wb"))
