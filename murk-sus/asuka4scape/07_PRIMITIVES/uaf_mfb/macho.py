import struct, capstone
P='/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache'
BASE=0xfffffff007004000
D=open(P,'rb').read()
md=capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
md.detail=True
md.skipdata=True

def va_from(v):
    # accept low-32 lo (0x9aa33b8) or full va (0xfffffff009aa33b8)
    if v < 0x100000000:
        return 0xfffffff000000000+v
    return v

def off(va):
    va=va_from(va)
    return va-BASE

def rd(va,n):
    o=off(va); return D[o:o+n]
def u32(va): return struct.unpack('<I',rd(va,4))[0]
def u64(va): return struct.unpack('<Q',rd(va,8))[0]
def s32(va): return struct.unpack('<i',rd(va,4))[0]

def dis(va,n=0x100,count=None):
    va=va_from(va)
    code=D[off(va):off(va)+n]
    out=[]
    for i in md.disasm(code,va):
        out.append((i.address,i.mnemonic,i.op_str,i.bytes))
        if count and len(out)>=count: break
    return out

def show(va,n=0x100,count=None):
    for a,m,ops,b in dis(va,n,count):
        print(f'{a:016x}: {b.hex():<12} {m:<8} {ops}')

def pac_target(q):
    return BASE+(q&0x0FFFFFFF)

def parse_mem(op):
    # "[x0, #0x18]" -> (reg,disp)
    s=op.strip()
    if not s.startswith('['): return None
    s=s[1:].split(']')[0]
    parts=[p.strip() for p in s.split(',')]
    reg=parts[0]
    disp=0
    if len(parts)>1 and parts[1].startswith('#'):
        disp=int(parts[1][1:],0)
    return reg,disp

def bl_target(m,ops,addr):
    if m not in ('b','bl'): return None
    s=ops.replace('#','')
    try:
        t=int(s,0)
    except:
        return None
    # capstone returns absolute for b/bl with immediate
    return t & 0xFFFFFFFFFFFFFFFF

def adrp_page(m,ops,addr):
    if m!='adrp': return None
    reg,imm=ops.split(', #')
    tgt=(int(imm,0)) & 0xFFFFFFFFFFFFFFFF
    return tgt & ~0xFFF

def got_lookup(va):
    """decode adrp+add+ldr+braa trampoline starting at va -> (slot_va, target_va)"""
    ins=list(dis(va,24))
    reg=None; slot=None
    for a,m,ops,b in ins[:6]:
        if m=='adrp':
            r=ops.split(',')[0]
            page=int(ops.split('#')[1],0)&0xFFFFFFFFFFFFFFFF
            regs={r:page}
        elif m=='add':
            p=[x.strip() for x in ops.split(',')]
            if len(p)==3 and p[1].startswith('#'):
                regs[p[0]]=regs.get(p[0],0)+int(p[1][1:],0)
            elif len(p)==3:
                regs[p[0]]=regs.get(p[1],0)+int(p[2].lstrip('#'),0)
        elif m=='ldr':
            mem=parse_mem(ops.split(',',1)[1].strip()) if ',' in ops else None
            if mem:
                base,disp=mem
                if base in regs:
                    slot=regs[base]+disp
                    slot&=0xFFFFFFFFFFFFFFFF
        elif m in ('braa','bra'):
            if slot is not None:
                tgt=u64(slot)
                return slot,tgt,pac_target(tgt)
    return slot,None,None
