#!/usr/bin/env python3
import pickle, sys
import kc2
from capstone.arm64 import ARM64_OP_IMM, ARM64_OP_MEM

def scan_kext(name):
    e = kc2.KEXT[name]
    calls = []   # (pc, target)
    xrefs = []   # (pc, target, kind)
    for s in e["segs"]:
        for sn, sva, ssz in s["sects"]:
            if sn != "__text": continue
            blob = kc2.DATA[kc2.va2off(sva):kc2.va2off(sva)+ssz]
            insns = list(kc2.MD.disasm(blob, sva))
            for i, ins in enumerate(insns):
                if ins.mnemonic in ("bl", "b") and ins.operands and ins.operands[0].type == ARM64_OP_IMM:
                    t = ins.operands[0].imm & kc2.M64
                    if t >= 0xfffffff000000000:
                        calls.append((ins.address, t, ins.mnemonic))
                if ins.mnemonic == "adrp":
                    pg = kc2.adrp_target(ins)
                    for j in insns[i+1:i+5]:
                        done = False
                        for k, op in enumerate(j.operands):
                            if op.type == ARM64_OP_IMM:
                                xrefs.append((ins.address, (pg + op.imm) & kc2.M64, j.mnemonic))
                                done = True
                            elif op.type == ARM64_OP_MEM:
                                xrefs.append((ins.address, (pg + op.mem.disp) & kc2.M64, j.mnemonic))
                                done = True
                        if done: break
    return calls, xrefs

if __name__ == "__main__":
    name = sys.argv[1]
    calls, xrefs = scan_kext(name)
    short = name.split(".")[-1]
    pickle.dump((calls, xrefs), open(short + "_cg.pkl", "wb"))
    print(name, "calls", len(calls), "xrefs", len(xrefs))
