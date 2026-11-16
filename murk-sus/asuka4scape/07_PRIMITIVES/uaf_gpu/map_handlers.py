from kc import *
import struct, json
FB=0xfffffff007fea200
H=[]
for i in range(56):
    H.append((i,pac(u64(FB+i*24))))

def func_end(va, maxlen=0x2000):
    off=va2off(va)
    if off is None: return None
    code=DATA[off:off+maxlen]
    last=None
    for ins in MD.disasm(code, va):
        last=ins
        if ins.mnemonic in ("ret","retab"):
            return ins.address+4
    return None

# collect __func__ strings
funcs={}
pref=b"static IOReturn IOGPUDeviceUserClient::"
i=0
while True:
    j=DATA.find(pref,i)
    if j<0: break
    for n,sv,sz,off in SEGS:
        if off<=j<off+sz:
            va=sv+(j-off); funcs[va]=cstr(va,400); break
    i=j+1
# xref index for those
import xr
idx=xr.build_adrp_add_index()
str_x={}
for sva in funcs:
    xs=xr.xrefs(sva,idx)
    if xs: str_x[sva]=xs

rows=[]
for sel,va in H:
    end=func_end(va)
    if end is None:
        rows.append((sel,va,None,[])); continue
    enc=[]
    for sva,xs in str_x.items():
        if any(va<=x<end for x in xs):
            enc.append((sva,funcs[sva]))
    rows.append((sel,va,end,enc))

for sel,va,end,enc in rows:
    nm = enc[0][1].split("::")[1].split("(")[0] if enc else "?"
    print(f"sel {sel:2d} {va:#x}..{end if end else 0:#x} len={ (end-va) if end else 0:#5x}  {nm}")
json.dump([(s,hex(a),hex(e) if e else None,[n for _,n in en]) for s,a,e,en in rows],open('hmap.json','w'),indent=1)
