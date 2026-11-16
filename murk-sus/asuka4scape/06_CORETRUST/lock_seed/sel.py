#!/usr/bin/env python3
"""IOSurfaceRootUserClient selector tables (27.2 24B115).
   record = {pac(fn), u32 scalarIn, u32 structInSize, u32 scalarOut, u32 structOutSize}
   A = base table 0x8068b90, B = restricted table 0x80694f0 (uc+0x127)"""
import importlib.util
spec = importlib.util.spec_from_file_location("kc2", "/home/femboychik/work/lock_seed/kc2.py")
k = importlib.util.module_from_spec(spec); spec.loader.exec_module(k)

TABLES = [("A", 0xfffffff008068b90), ("B", 0xfffffff0080694f0)]
N = 60
DENY = 0xfffffff009c3a1dc

def impl_of(wrapper):
    """first far b/bl inside wrapper (tail-call thunk)"""
    out = []
    for a, x in k.dis(wrapper, 20, stop_ret=True):
        if x.mnemonic in ("b", "bl") and k.target(x):
            t = k.target(x)
            if abs(t - wrapper) > 0x800:
                out.append(t)
    return out[0] if out else None

if __name__ == "__main__":
    data = {}
    for tag, table in TABLES:
        rows = []
        for i in range(N):
            e = table + i * 0x28
            fn = k.pac(k.u64(e))
            a, b, c, d = (k.u32(e + 8 + j * 4) for j in range(4))
            imp = impl_of(fn)
            rows.append((fn, a, b, c, d, imp))
        data[tag] = rows

    print("sel  A.wrapper     A.impl        B.wrapper     B.impl        sIn strIn   sOut strOut")
    for i in range(N):
        fa, a, b, c, d, ia = data["A"][i]
        fb, _, _, _, _, ib = data["B"][i]
        sa = "deny" if ia == DENY else (hex(ia) if ia else "-")
        sb = "deny" if ib == DENY else (hex(ib) if ib else "-")
        print(f"{i:3d} {fa:#012x} {sa:12s} {fb:#012x} {sb:12s} "
              f"{a:3d} {b if b != 0xffffffff else -1:6d} {c:4d} {d if d != 0xffffffff else -1:6d}")
