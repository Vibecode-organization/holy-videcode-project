import json, struct, re
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from kc import load
k=load(); kmap=json.load(open('kmap.json'))
md=Cs(CS_ARCH_ARM64,CS_MODE_ARM); md.detail=True
TARGETS={'com.apple.iokit.IOSurface','com.apple.iokit.IOGPUFamily','com.apple.AGXG14P',
 'com.apple.iokit.IOMobileGraphicsFamily','com.apple.iokit.IOMobileGraphicsFamily-DCP',
 'com.apple.driver.AppleJPEGDriver','com.apple.driver.AppleSEPKeyStore',
 'com.apple.driver.AppleH11ANEInterface','com.apple.driver.AppleSEPManager'}
out={}
for e in kmap:
    if e['id'] not in TARGETS: continue
    rows=[]
    for s in e.get('segs',[]):
        if s['name']!='__TEXT_EXEC': continue
        lo=s['va']; n=s['fs']
        code=k.data[k.off(lo):k.off(lo)+n]
        ins_=list(md.disasm(code, lo))
        ins=ins_
        for i,ins in enumerate(ins):
            if ins.mnemonic!='bl': continue
            # look back
            name=None; size=None; obj=None
            regs={}
            for j in range(max(0,i-10), i):
                p=ins_[j]
                if p.mnemonic=='adrp':
                    r,imm=p.op_str.split(', '); regs[r]=int(imm.strip('#'),16)
                elif p.mnemonic=='add':
                    parts=[x.strip() for x in p.op_str.split(',')]
                    if len(parts)==3 and parts[1] in regs and parts[2].startswith('#'):
                        try: o=int(parts[2][1:],16)
                        except: continue
                        tgt=regs[parts[1]]+o
                        if parts[0]=='x1':
                            b=k.rd(tgt,64)
                            if b:
                                z=b.find(b'\0')
                                if 4<z<64:
                                    t=b[:z]
                                    if re.fullmatch(rb'[A-Za-z_][A-Za-z0-9_]{3,}', t): name=t.decode()
                elif p.mnemonic=='mov' and p.op_str.startswith('w3, #'):
                    try: size=int(p.op_str.split('#')[1],16)
                    except: pass
                elif p.mnemonic=='adrp' and p.op_str.startswith('x0'):
                    pass
            if name and size is not None and 0x10<size<0x4000:
                rows.append(dict(site=ins.address, name=name, size=size))
    out[e['id']]=rows
    print(f"\n### {e['id']}  ({len(rows)} class ctors)")
    seen=set()
    for r in rows:
        if r['name'] in seen: continue
        seen.add(r['name'])
        print(f"   {r['name']:44} size={r['size']:#07x}  ctor_site={r['site']:#x}")
json.dump(out,open('metaclass.json','w'),indent=1)
