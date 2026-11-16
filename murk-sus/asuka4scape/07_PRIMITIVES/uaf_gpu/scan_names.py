from kc import *
import struct, json
FB = 0xfffffff007fea200
handlers=[]
for i in range(56):
    va=pac(u64(FB+i*24)); handlers.append(va)

def strings_in(va, n=0x600):
    off=va2off(va)
    if off is None: return []
    code=DATA[off:off+n]
    res=[]; prev_adrp=None
    for ins in MD.disasm(code, va):
        if ins.mnemonic=="adrp":
            prev_adrp=adrp_imm(ins); continue
        if ins.mnemonic=="add" and prev_adrp is not None:
            try:
                imm=ins.operands[2].imm & M64
            except Exception:
                imm=None
            if imm is not None:
                tgt=(prev_adrp+imm)&M64
                s=cstr(tgt,120)
                if s and len(s)>=4 and all(32<=ord(c)<127 or c in '\n\t' for c in s):
                    res.append((ins.address,tgt,s))
        prev_adrp=None
    return res

names={}
for i,va in enumerate(handlers):
    ss=strings_in(va)
    names[i]=[(hex(a),hex(t),s) for a,t,s in ss]
    print(f"--- sel {i:2d} {va:#x}")
    for a,t,s in ss[:8]:
        print(f"     {a:#x} {t:#x} {s!r}")
json.dump(names,open('names.json','w'),indent=1)
