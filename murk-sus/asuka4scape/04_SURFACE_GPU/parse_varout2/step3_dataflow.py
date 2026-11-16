"""Step 3 v2: dataflow with canonical (x/w) register ids, strict store conditions."""
import sys, json, struct, bisect, array
sys.path.insert(0,"/home/femboychik/work/parse_varout2")
from kc import *
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from capstone.arm64 import ARM64_OP_REG, ARM64_OP_MEM, ARM64_OP_IMM, ARM64_OP_CIMM

md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
md.detail = True

offs = array.array('I'); offs.frombytes(open("/home/femboychik/work/parse_varout2/funcstarts.bin","rb").read())
STARTS = [TEXT_EXEC_VA + o for o in offs]

segs = json.load(open("/home/femboychik/work/parse_varout2/kext_segmap.json"))
TXR = sorted((x['segs']['__TEXT_EXEC'][0], x['segs']['__TEXT_EXEC'][0]+x['segs']['__TEXT_EXEC'][1], x['name']) for x in segs if '__TEXT_EXEC' in x['segs'])
TXR_LO = [t[0] for t in TXR]
LAST_TX = max(t[1] for t in TXR)

def kext_of(va):
    i = bisect.bisect_right(TXR_LO, va) - 1
    if i >= 0 and TXR[i][0] <= va < TXR[i][1]:
        return TXR[i][2]
    if LAST_TX <= va < TEXT_EXEC_END:
        return "com.apple.kernel"
    return "?"

def func_of(va):
    i = bisect.bisect_right(STARTS, va) - 1
    if i < 0: return None, None
    return STARTS[i], (STARTS[i+1] if i+1 < len(STARTS) else TEXT_EXEC_END)

def canon(reg):
    n = md.reg_name(reg)
    if not n: return None
    if n[0] == 'w' and n[1:].isdigit(): return 'x'+n[1:]
    if n[0] in 'bhsvd' and n[1:].isdigit(): return 'v'+n[1:]
    if n[0] == 'q' and n[1:].isdigit(): return 'v'+n[1:]
    return n

def ins_ops(insn):
    mem = None
    wr = []; rd = []
    for op in insn.operands:
        if op.type == ARM64_OP_MEM:
            mem = op.mem
        elif op.type == ARM64_OP_REG:
            c = canon(op.reg)
            if op.access & 2: wr.append(c)
            if op.access & 1: rd.append(c)
        elif op.type == ARM64_OP_IMM:
            pass
    # capstone sometimes doesn't flag base reg read
    return mem, wr, rd

hits = json.load(open("/home/femboychik/work/parse_varout2/hits_raw.json"))
cands = {}
for va, kind, imm, rn, rt, rt2 in hits:
    if not (kind in ('ldr','ldur','ldp') and imm == 0x78):
        continue
    s, e = func_of(va)
    if s is None: continue
    cands.setdefault(s, []).append((va, kind, rn, rt, rt2, e))

print("candidate funcs:", len(cands))
results = []
for s, lst in cands.items():
    e = lst[0][5]
    insns = list(md.disasm(DATA[va2off(s):va2off(s)+min(e-s, 0x1800)], s))
    varout = {}     # canon reg -> ldr va
    strict = []     # disp==0, no index
    weak = []
    passed = []
    stopper = None
    for insn in insns:
        mnem = insn.mnemonic
        mem, wr, rd = ins_ops(insn)
        if mnem in ("ldr","ldur","ldp") and mem is not None and mem.disp == 0x78:
            for c in wr:
                varout[c] = insn.address
            continue
        if mnem in ("mov",) and len(insn.operands) == 2 and insn.operands[0].type == ARM64_OP_REG and insn.operands[1].type == ARM64_OP_REG:
            if canon(insn.operands[1].reg) in varout:
                varout[canon(insn.operands[0].reg)] = varout[canon(insn.operands[1].reg)]
                continue
        if mnem in ("str","stur","stp","stnp","strb","strh","strl") and mem is not None and mem.base and canon(mem.base) in varout:
            noidx = (mem.index == 0)
            rec = (insn.address, f"{mnem} {insn.op_str}", mem.disp, noidx, varout[canon(mem.base)])
            src = canon(insn.operands[0].reg) if insn.operands and insn.operands[0].type == ARM64_OP_REG else ""
            if noidx and mem.disp == 0 and mnem == "str" and src.startswith("x"):
                strict.append(rec)
            else:
                weak.append(rec)
            continue
        if mnem in ("bl","blr") and any(c in varout for c in rd):
            passed.append((insn.address, insn.op_str, [c for c in rd if c in varout]))
        for c in wr:
            if c in varout:
                del varout[c]
        if mnem in ("ret","retab"):
            stopper = insn.address
            break
    results.append(dict(func=s, end=e, kext=kext_of(s), ldr=[x[0] for x in lst],
                        ldr_rn=[x[2] for x in lst], strict=strict, weak=weak, passed=passed))

conf = [r for r in results if r['strict']]
print("STRICT confirmed:", len(conf), "kexts:", len(set(r['kext'] for r in conf)))
print("weak-only:", len([r for r in results if not r['strict'] and r['weak']]))
print("passed-only:", len([r for r in results if not r['strict'] and not r['weak'] and r['passed']]))
json.dump(results, open("/home/femboychik/work/parse_varout2/step3_results.json","w"))
from collections import Counter
for k,v in Counter(r['kext'] for r in conf).most_common(): print(f"  {v:3d} {k}")
