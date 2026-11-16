import kc
cands = [0x7e3b0d8, 0x7e3b738, 0xae6eb98, 0x8e00070, 0x8d56a18]
for c in cands:
    as_va = 0xfffffff000000000 | c
    print(f"-- {c:#x}")
    try:
        print("   as VA  " + " ".join(f"{kc.u32(as_va+i*4):08x}" for i in range(6)))
    except Exception as e:
        print("   as VA fail", e)
    try:
        off = 0xbb4000 + (as_va - 0xfffffff007bb8000)
        print(f"   as DC-fileoff {off:#x} -> va {kc.off2va(off):#x}")
        print("   " + " ".join(f"{kc.u32(kc.off2va(off)+i*4):08x}" for i in range(6)))
    except Exception as e:
        print("   DC fail", e)
    try:
        off = as_va - 0xfffffff007004000
        v = kc.off2va(off)
        print(f"   as TE-fileoff {off:#x} -> va {v:#x}  ", kc.dis(v,3)[0][1].mnemonic if kc.dis(v,3) else "")
    except Exception as e:
        print("   TE fail", e)
