from kdis import *

def find_start(va, limit=0x8000):
    """walk back to nearest prologue whose body reaches va without ret"""
    a=va & ~3
    cands=[]
    x=a
    while x>va-limit:
        x-=4
        try: seg=segof(x)
        except KeyError: break
        if seg[4] not in ('__TEXT_EXEC','__TEXT','__TEXT_BOOT_EXEC'): break
        try: ins=list(md.disasm(blob(x,4), x))
        except Exception: continue
        if not ins: continue
        mn=ins[0].mnemonic
        if mn in ('pacibsp','paciasp','bti'): cands.append(x)
        elif mn.startswith('ret'): break
    # nearest candidate that decodes to va exactly
    for c in cands:
        ok=False
        n=0
        for i in md.disasm(blob(c, va-c+4), c):
            n+=1
            if i.address==va: ok=True; break
            if i.mnemonic.startswith('ret') or i.mnemonic in ('br','braa','brk'): break
        if ok: return c
    return cands[0] if cands else None

def body(start, end=None, maxn=3000):
    out=[]
    for i in md.disasm(blob(start, (end-start)+4 if end else 4*maxn), start):
        out.append(i)
        if i.mnemonic.startswith('ret') or i.mnemonic=='brk': break
        if end and i.address>=end: break
    return out

def dump(va, back=None):
    s=find_start(va)
    ins=body(s) if s else []
    print("=== %#x  start=%s  n=%d"%(va, hex(s) if s else '?', len(ins)))
    for i in ins:
        m=' <<<' if i.address==va else ''
        print(fmt(i)+m)
    return s,ins
