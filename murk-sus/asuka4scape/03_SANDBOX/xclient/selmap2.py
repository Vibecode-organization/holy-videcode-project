#!/usr/bin/env python3
# map IOGPUDeviceUserClient selectors -> device-level id operations
import sys, struct
sys.path.insert(0, "/home/femboychik/work/iogpu_all")
from kc import *
import an

FB = 0xfffffff007fea200        # table selected when uc->[0x103] bit0 == 0 (externalMethod)
N = 56

NAMES = {
    0xfffffff009965954: "res_detach_delete(id)",       # ns0x10 remove + vt[0xb0]
    0xfffffff0099664e4: "res_rec[id] (w2<=1)",         # ns0x10 get, index res+0x18+w2*0x40
    0xfffffff009966668: "res_type_dispatch(id)*",      # ns0x10 get, per-type ops
    0xfffffff0099659b4: "res_xlat(id)->ns0x78",        # dev->vt[0xa8] + ns0x78 add
    0xfffffff009965b04: "ns0x78.remove(id)->bool",
    0xfffffff009965c20: "ns0x18.remove(id)->bool",
    0xfffffff009965d78: "ns0x80.remove(id)->bool",
    0xfffffff009965edc: "ns0x90.remove(id)->bool",
    0xfffffff009965b68: "ns0x18.get_or_create(id)",
    0xfffffff009965cd4: "ns0x80.get_or_create(id)",
    0xfffffff009965dc4: "ns0x90.get_or_create(ch,id)",
    0xfffffff009966638: "res_iter(id)*",
    0xfffffff009965628: "ns0x10.get(id)",
    0xfffffff00996561c: "ns0x10.peek(id)",
    0xfffffff009965da8: "ns0x88.get(id)",
    0xfffffff009965db4: "ns0x90.get(id)",
    0xfffffff009967e24: "GROUP_ADD(group,id[])",
    0xfffffff009967f2c: "GROUP_REMOVE(group,id[])",
    0xfffffff009967d10: "GROUP_REMOVE2(group,id[])",
    0xfffffff009968058: "res_detach_backing(id)",
    0xfffffff0099680c8: "res_replace_bytes(id)",
    0xfffffff009968110: "res_replace_ranges(id)",
    0xfffffff00996689c: "res_set_purgeable(id)",
    0xfffffff009967330: "dev_info",
    0xfffffff00997fc84: "chan_obj_by_id",
}


def interesting(va, end):
    out = []
    off = va2off(va)
    if off is None or end is None:
        return out
    for ins in MD.disasm(DATA[off:off + (end - va)], va):
        if ins.mnemonic in ("bl", "b"):
            try:
                t = ins.operands[0].imm & M64
            except Exception:
                continue
            if t in NAMES:
                out.append((ins.address, NAMES[t]))
    return out


for i in range(N):
    q = u64(FB + i * 24)
    fn = pac(q)
    scin = u32(FB + i * 24 + 8)
    stin = u32(FB + i * 24 + 12) & 0xffffffff
    scout = u32(FB + i * 24 + 16)
    stout = u32(FB + i * 24 + 20) & 0xffffffff
    end = an.fn_end(fn)
    hits = interesting(fn, end)
    line = "sel %2d fn=%#x in=%d/%s out=%d/%s" % (i, fn, scin,
                                                  "var" if stin == 0xffffffff else hex(stin),
                                                  scout,
                                                  "var" if stout == 0xffffffff else hex(stout))
    print(line)
    for a, n in hits:
        print("      %#x  %s" % (a, n))
