import sys, json, struct
sys.path.insert(0,"/home/femboychik/work/parse_varout2")
from kc import *

rows=json.load(open("/home/femboychik/work/parse_varout2/kext_ranges.json"))
out=[]
for la,s,name,exe in rows:
    o=va2off(la)
    if o is None: continue
    if struct.unpack_from("<I",DATA,o)[0]!=0xfeedfacf: continue
    ncmds=struct.unpack_from("<I",DATA,o+16)[0]
    p=o+32; segs={}
    for i in range(ncmds):
        cmd,cs=struct.unpack_from("<II",DATA,p)
        if cmd==0x19:
            sn=DATA[p+8:p+24].rstrip(b"\0").decode()
            vm,vs,fo,fs=struct.unpack_from("<QQQQ",DATA,p+24)
            segs[sn]=(vm,vs)
        p+=cs
    out.append(dict(name=name, exe=exe, segs=segs, hdr=la))

print("parsed", len(out))
tx=[k for k in out if "__TEXT_EXEC" in k["segs"]]
print("with TEXT_EXEC", len(tx))
tx.sort(key=lambda k:k["segs"]["__TEXT_EXEC"][0])
tot=0; gaps=[]
for k in tx:
    vm,vs=k["segs"]["__TEXT_EXEC"]
    tot+=vs
print("total TEXT_EXEC covered", hex(tot), "of", hex(TEXT_EXEC_SIZE))
prev=None
for k in tx:
    vm,vs=k["segs"]["__TEXT_EXEC"]
    if prev is not None and vm!=prev:
        gaps.append((prev, vm, vm-prev, k["name"]))
    prev=vm+vs
print("gaps/overlaps", len(gaps), [(hex(a),hex(b),hex(c)) for a,b,c,_ in gaps[:10]])
json.dump(out, open("/home/femboychik/work/parse_varout2/kext_segmap.json","w"))
