import struct,capstone,re,difflib,sys
BASE=0xfffffff007004000
D={}
for tag,p in (('270','/home/femboychik/Рабочий стол/дипсик 1/kc/27.0_24A437_kernelcache'),('272','/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache')):
    D[tag]=open(p,'rb').read()
md=capstone.Cs(capstone.CS_ARCH_ARM64,capstone.CS_MODE_ARM); md.detail=True; md.skipdata=True
def dis(tag,lo,n):
    buf=D[tag]; va=0xfffffff000000000+lo; o=va-BASE
    return list(md.disasm(buf[o:o+n],va))
def norm(ins):
    ops=ins.op_str
    # normalize absolute addresses and adrp pages
    ops=re.sub(r'0xfffffff[0-9a-f]+','ADDR',ops)
    # adrp targets
    if ins.mnemonic=='adrp':
        ops='PAGE'
    return f'{ins.mnemonic} {ops}'
def dump_norm(tag,lo,n):
    return [norm(i) for i in dis(tag,lo,n)]
def compare(name,lo270,lo272,n):
    a=dump_norm('270',lo270,n); b=dump_norm('272',lo272,n)
    print(f'===== {name}: 27.0 {lo270:#x} vs 27.2 {lo272:#x}  ({len(a)} vs {len(b)} insns)')
    sm=difflib.SequenceMatcher(None,a,b)
    for tag,i1,i2,j1,j2 in sm.get_opcodes():
        if tag=='equal': continue
        print(f'  {tag} 27.0[{i1}:{i2}] 27.2[{j1}:{j2}]')
        for x in a[i1:i2][:12]: print('    -',x)
        for x in b[j1:j2][:12]: print('    +',x)
if __name__=='__main__':
    compare('externalMethod',0x9a66460,0x9aa33b8,0x70)
    compare('sel44',0x9a67384,0x9aa42dc,0x110)
    compare('sel4e',0x9a66de4,0x9aa3d3c,0x120)
    compare('sel4f',0x9a66edc,0x9aa3e34,0x100)
