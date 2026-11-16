"""Step 6: join tables x handlers x varout evidence x args signature."""
import sys, json, struct, bisect, array
sys.path.insert(0,"/home/femboychik/work/parse_varout2")
from kc import *
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from capstone.arm64 import ARM64_OP_REG, ARM64_OP_MEM

md = Cs(CS_ARCH_ARM64, CS_MODE_ARM); md.detail = True
offs = array.array('I'); offs.frombytes(open("/home/femboychik/work/parse_varout2/funcstarts.bin","rb").read())
STARTS = [TEXT_EXEC_VA + o for o in offs]
def func_of(va):
    i = bisect.bisect_right(STARTS, va) - 1
    if i < 0: return None, None
    return STARTS[i], (STARTS[i+1] if i+1 < len(STARTS) else TEXT_EXEC_END)

segs = json.load(open("/home/femboychik/work/parse_varout2/kext_segmap.json"))
TXR = sorted((x['segs']['__TEXT_EXEC'][0], x['segs']['__TEXT_EXEC'][0]+x['segs']['__TEXT_EXEC'][1], x['name']) for x in segs if '__TEXT_EXEC' in x['segs'])
TXR_LO=[t[0] for t in TXR]; LAST=max(t[1] for t in TXR)
def kext_of(va):
    i=bisect.bisect_right(TXR_LO,va)-1
    if i>=0 and TXR[i][0]<=va<TXR[i][1]: return TXR[i][2]
    if LAST<=va<TEXT_EXEC_END: return "com.apple.kernel"
    return "?"

tables = json.load(open("/home/femboychik/work/parse_varout2/tables.json"))
res = {r['func']: r for r in json.load(open("/home/femboychik/work/parse_varout2/step3_results.json"))}

ARGOFF = {0x20:"scalarInput",0x28:"scalarInputCount",0x30:"structureInput",0x38:"structureInputSize",
          0x40:"structureInputDescriptor",0x48:"scalarOutput",0x50:"scalarOutputCount",
          0x58:"structureOutput",0x60:"structureOutputSize",0x68:"structureOutputDescriptor",
          0x70:"structureOutputDescriptorSize",0x78:"structureVariableOutputData"}

def sig(f):
    s, e = func_of(f)
    if s is None: return {}
    insns = md.disasm(DATA[va2off(s):va2off(s)+min(e-s, 0x2000)], s)
    seen = {}
    for insn in insns:
        if insn.mnemonic not in ("ldr","str","ldur","stur","ldrb","strb","ldrh","strh","ldp","stp"): continue
        for op in insn.operands:
            if op.type == ARM64_OP_MEM and op.mem.disp in ARGOFF and op.mem.base:
                bn = md.reg_name(op.mem.base)
                if bn and bn[0]=='x' and bn[1:].isdigit() and int(bn[1:]) <= 9:
                    seen[ARGOFF[op.mem.disp]] = seen.get(ARGOFF[op.mem.disp], 0) + 1
    return seen

def thunk(va):
    o = va2off(va)
    if o is None: return None
    w0 = struct.unpack_from("<I", DATA, o)[0]
    if w0 == 0xD503245F:
        va += 4; o += 4; w0 = struct.unpack_from("<I", DATA, o)[0]
    if (w0 & 0xFC000000) == 0x14000000:
        imm = w0 & 0x03FFFFFF
        if imm & 0x02000000: imm -= 0x04000000
        return va + imm*4
    return None

# map: strict func -> callers
callers = {}
for f, r in res.items():
    for src, kind in [(x[0], x[1]) for x in []]:
        pass

out = []
for t in tables:
    for i, e in enumerate(t['ents']):
        T = e['target']
        th = thunk(T)
        rec = dict(tbl=t['base'], stride=t['stride'], idx=i, n=t['count'], tkext=t['kext'],
                   target=T, fn=T, f=e['f'], extra=e['extra'])
        real = None
        if th: rec['thunk_to'] = th; real = th
        # evidence
        ev = res.get(T) or (res.get(th) if th else None)
        if ev:
            rec['varout'] = 'strict' if ev['strict'] else ('weak' if ev['weak'] else 'ldr-only')
            rec['varout_store'] = ev['strict'] or ev['weak']
            rec['fn'] = ev['func']; rec['kext'] = ev['kext']
        rec['sig'] = sig(rec['fn'])
        out.append(rec)

print("entries:", len(out))
strict_ent = [r for r in out if r.get('varout')=='strict']
print("table entries with strict varout:", len(strict_ent))
varany = [r for r in out if r.get('varout')]
print("table entries with ldr 0x78:", len(varany))
big = [r for r in out if r['f'][3]==0xffffffff]
print("entries with structOut=0xffffffff:", len(big))
bigv = [r for r in big if r.get('varout')]
print("...of which touch 0x78:", len(bigv))
json.dump(out, open("/home/femboychik/work/parse_varout2/step6_entries.json","w"))
for r in strict_ent:
    print(f"  {r['tkext'][:34]:34s} tbl {r['tbl']:#x} idx {r['idx']:3d} fn {r['fn']:#x} f={r['f']} sig={len(r['sig'])}")
