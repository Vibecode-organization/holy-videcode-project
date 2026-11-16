import kc
def dumpq(va,n,label=""):
    print(f"== {label} {va:#x}")
    for i in range(n):
        v=kc.u64(va+i*8)
        tgt=""
        if v and (v>>32)==0x8060 or (v>>28)==0x8060:
            tgt=f"  pac-> {kc.pac(v):#x}"
        print(f"  +{i*8:03x}: {v:016x}{tgt}")
dumpq(0xfffffff00ae6e9b8, 24, "meta?")
print()
dumpq(0xfffffff007e3b0d8, 16, "vptr")
print()
dumpq(0xfffffff007e3b738, 12*6, "table 0x30")
