import struct, json, bisect
KC="/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache"
D=open(KC,'rb').read()
pre=json.load(open('prelink.json'))
def u(x): return int(x) if isinstance(x,str) else x
def parse(va):
    o=va-0xfffffff007004000
    if D[o:o+4]!=b'\xcf\xfa\xed\xfe': return None
    n=struct.unpack_from('<I',D,o+16)[0]; p=o+32; out=[]
    for i in range(n):
        cmd,cs=struct.unpack_from('<II',D,p)
        if cmd==0x19:
            nm=D[p+8:p+24].rstrip(b'\0').decode()
            v,s,fo,fs=struct.unpack_from('<QQQQ',D,p+24)
            out.append((nm,v,s,fo,fs))
        p+=cs
    return out
segs=[]  # (va,end,bid,segname,foff)
ks=[]
for d in pre:
    la=d.get('_PrelinkExecutableLoadAddr')
    if la is None: continue
    la=u(la)
    if la<0: la&=0xFFFFFFFFFFFFFFFF
    bid=d.get('CFBundleIdentifier'); ks.append((la,u(d.get('_PrelinkExecutableSize')),bid))
    try: ss=parse(la)
    except Exception as e: ss=None
    if not ss:
        print("skip", bid, hex(la)); continue
    for nm,v,s,fo,fs in ss:
        if fs: segs.append((v,v+fs,bid,nm,fo))
segs.sort()
starts=[s[0] for s in segs]
def kext(va):
    i=bisect.bisect_right(starts,va)-1
    while i>=0:
        if segs[i][0]<=va<segs[i][1]: return segs[i][2]
        if segs[i][0]<=va: 
            j=i-1
            if j>=0 and segs[j][1]<=va and segs[j][0]<=va and va>=segs[j][1]: return None
            break
        i-=1
    return None
json.dump({"segs":segs,"ks":ks},open('kmap.json','w'))
print(len(segs),"segs",len(ks),"kexts")
