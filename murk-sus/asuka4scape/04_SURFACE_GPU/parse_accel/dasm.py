import capstone, kc
C = capstone.arm64
md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
md.detail = True
md.skipdata = True
def dis(va, n=40, back=0):
    start = va - back*4
    o = kc.va2off(start)
    out=[]
    for ins in md.disasm(kc.D[o:o+4*n], start):
        mark = ">>" if ins.address == va else "  "
        out.append(f"{mark} {ins.address:#014x}: {ins.mnemonic:8s} {ins.op_str}")
    return "\n".join(out)
def show(va, n=40, back=0):
    print(dis(va,n,back))
