import sys; sys.path.insert(0,'/home/femboychik/work/xpc_parsers/tools')
from disasm import Bin, annotate_bin
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from capstone.arm64 import ARM64_OP_IMM

STUBS={0x188138470:'malloc',0x188138460:'calloc',0x188138490:'realloc',
       0x188138650:'reallocf',0x188138480:'posix_memalign'}
path=sys.argv[1]; tsv=sys.argv[2]; filt=sys.argv[3] if len(sys.argv)>3 else None
b=Bin(path, fixups=False)
addr,size,foff=b.sects['__text'][0]
md=Cs(CS_ARCH_ARM64,CS_MODE_ARM); md.detail=True
hits=[]
for ins in md.disasm(b.d[foff:foff+size],addr):
    if ins.mnemonic=='bl' and ins.operands and ins.operands[0].type==ARM64_OP_IMM:
        if ins.operands[0].imm in STUBS:
            hits.append((ins.address, STUBS[ins.operands[0].imm]))
print(f"# {len(hits)} alloc sites", file=sys.stderr)
for a,name in hits:
    fn=b.name_at(a) or '?'
    if filt and filt.lower() not in fn.lower(): continue
    insns=annotate_bin(b,None,26,a-22*4)
    print(f"\n== {name} @0x{a:x} in {fn}")
    for m in insns:
        c=getattr(m,'_cmt','')
        print(f"   0x{m.address:x}: {m.mnemonic}\t{m.op_str}"+(f"\t; {c}" if c else ''))
