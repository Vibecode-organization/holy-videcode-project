import kc
k = kc.KC()
def resolve(stub):
    reg = None; page = None; slot = None
    for ins in kc.dis(k, stub, 8):
        if ins.mnemonic == 'adrp':
            reg = ins.operands[0].reg; page = (ins.operands[1].imm) & 0xFFFFFFFFFFFFFFFF
        elif ins.mnemonic == 'add' and page is not None and ins.operands[0].reg == reg:
            page = (page + ins.operands[2].imm) & 0xFFFFFFFFFFFFFFFF
        elif ins.mnemonic == 'ldr' and page is not None and ins.operands[1].type == 3 and ins.operands[1].mem.base == reg:
            slot = (page + ins.operands[1].mem.disp) & 0xFFFFFFFFFFFFFFFF
            break
    if slot is None: return None, None
    q = k.u64(slot)
    return slot, (0xfffffff007004000 + (q & 0x0FFFFFFF)) & 0xFFFFFFFFFFFFFFFF
NAMES = {0xfffffff009c49764:'OSUnserializeXML?',0xfffffff009c498d4:'dynamic_cast?',
 0xfffffff009c49a74:'?',0xfffffff009c49a84:'?',0xfffffff009c49ae4:'?',0xfffffff009c49924:'?',
 0xfffffff009c49b74:'log',0xfffffff009c495b4:'lock',0xfffffff009c495d4:'unlock',
 0xfffffff009c49634:'alloc',0xfffffff009c49c34:'kdebug',0xfffffff009c49c14:'kdebug2',
 0xfffffff009c49d54:'?',0xfffffff009c49874:'?',0xfffffff009c49744:'free',0xfffffff009c49a54:'?',
 0xfffffff009c49e74:'?',0xfffffff009c49b64:'panic/fail',0xfffffff009c49684:'?',0xfffffff009c49674:'?',
 0xfffffff009c49904:'?',0xfffffff009c49914:'?',0xfffffff009c49c84:'?',0xfffffff009c48f28:'?',0xfffffff009c48f3c:'?'}
for a,n in NAMES.items():
    s,t = resolve(a)
    print('%-16s %s slot=%s -> %s' % (n, hex(a), hex(s) if s else None, hex(t) if t else None))
