import sys, json, bisect
sys.path.insert(0,'.')
import capstone
from kc import DATA
from k import va2off, off2va, u64, u32, cstr, dis, SEGS
import xr

MD = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM); MD.detail=True

STR0=0xfffffff00789a748; STR1=STR0+0x33b7
def maybe_str(va):
    if STR0 <= va < STR1:
        try: return repr(cstr(va))
        except: return None
    return None

def annot(va):
    a=[]
    o=va2off(va)
    if o is None: return ''
    if 0xfffffff007bb8000 <= va < 0xfffffff008100000 or 0xfffffff00acb4000 <= va < 0xfffffff00af6c000 or 0xfffffff00700c000<=va<0xfffffff007bb8000:
        s=maybe_str(va)
        if s: return s
        try:
            p=u64(va)
            if p >= 0xfffffff007004000:
                if p in set(xr.FUNCS): a.append("func^ %#x"%p)
                else:
                    s2=maybe_str(p)
                    a.append("ptr %#x %s"%(p, s2 or (repr(cstr(p)) if STR0<=p<STR1 else '')))
        except: pass
    return ' '.join(a)

def dump(va, end=None, maxn=0x2000):
    fs=xr.FUNCS_S
    if end is None:
        i=bisect.bisect_right(fs, va)-1
        end = fs[i+1] if i+1 < len(fs) else va+0x400
    page={}
    o=va2off(va)
    for ins in MD.disasm(DATA[o:o+min(end-va,maxn)], va):
        ann=''
        m=ins.mnemonic; ops=ins.op_str
        if m=='adrp' and ins.operands and len(ins.operands)>1:
            page[ins.operands[0].reg]=ins.operands[1].imm & 0xFFFFFFFFFFFFFFFF
        elif ins.operands:
            for op in ins.operands:
                if op.type==capstone.arm64.ARM64_OP_MEM and op.mem.base in page:
                    t=(page[op.mem.base]+op.mem.disp)&0xFFFFFFFFFFFFFFFF
                    ann='; [%#x] %s'%(t, annot(t))
                    break
                if op.type==capstone.arm64.ARM64_OP_REG and op.reg in page and m in ('add','sub'):
                    rest=ins.op_str
                    if len(ins.operands)>2 and ins.operands[2].type==capstone.arm64.ARM64_OP_IMM:
                        t=(page[op.reg]+ins.operands[2].imm)&0xFFFFFFFFFFFFFFFF
                        ann='; %#x %s'%(t, annot(t))
                        break
        print(f"{ins.address:#014x}  {ins.bytes.hex():<8} {m:<8} {ops:<46}{ann}")

def callers(tgt):
    out=[]
    for a,m,o,b in xr.INSN:
        if m in ('bl','b'):
            # parse #imm
            if o.startswith('#0x'):
                t=int(o[1:],16)&0xFFFFFFFFFFFFFFFF
                if t==tgt: out.append((a,m))
    return out
