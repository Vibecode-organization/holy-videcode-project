#!/usr/bin/env python3
"""Scan MIG handlers for 'kernel address stored into a local struct' patterns."""
import re, sys, json
from kc import KCFile
import capstone
from kdis import K, _md, is_kaddr, is_kdata, is_code, dis, TEXEC, DATA, DCONST, PINFO

def parse_mig(path='mig_all.txt'):
    subs = []
    cur = None
    for line in open(path):
        m = re.match(r'^(0x[0-9a-f]+): (\S+)\s+start=(\d+) end=(\d+)', line)
        if m:
            cur = dict(addr=int(m.group(1), 16), name=m.group(2), start=int(m.group(3)), end=int(m.group(4)), routines=[])
            subs.append(cur)
            continue
        m = re.match(r'^\s+(0x[0-9a-f]+): (\S+)\s+num=(\d+) impl=(0x[0-9a-f]+) argc=(\d+) descr=(\d+) reply_descr=(\d+) max_reply_msg=(\d+)', line)
        if m and cur is not None:
            cur['routines'].append(dict(addr=int(m.group(1), 16), name=m.group(2), num=int(m.group(3)),
                                        argc=int(m.group(5)), reply_descr=int(m.group(7)), max_reply=int(m.group(8))))
    return subs

def analyze(start, maxins=900):
    """disassemble a function; return list of (kind, ins_addr, value, store_target)"""
    out = []
    adrp = {}
    for ins in dis(start, maxins):
        m = ins.mnemonic
        ops = ins.operands
        if m == 'adrp' and ops:
            adrp[ins.reg_name(ops[0].reg)] = ops[1].imm
        elif m in ('add', 'orr') and len(ops) == 3 and ops[2].type == capstone.arm64.ARM64_OP_IMM:
            base = ins.reg_name(ops[1].reg) if ops[1].type == capstone.arm64.ARM64_OP_REG else None
            if base in adrp:
                val = adrp[base] + ops[2].imm
                adrp[ins.reg_name(ops[0].reg)] = val
                if is_kaddr(val):
                    out.append(('addr', ins.address, val))
        elif m in ('ldr', 'ldur', 'ldrsw', 'ldrh', 'ldrb') and len(ops) == 2 and ops[1].type == capstone.arm64.ARM64_OP_MEM:
            membase = ins.reg_name(ops[1].mem.base)
            if membase in adrp:
                val = adrp[membase] + ops[1].mem.disp
                out.append(('load', ins.address, val))
        elif m in ('str', 'stur', 'strh', 'strb', 'stp') and ops:
            # find a source reg that holds a kaddr
            srcs = []
            for o in ops[:-1]:
                if o.type == capstone.arm64.ARM64_OP_REG:
                    r = ins.reg_name(o.reg)
                    if r in adrp:
                        srcs.append((r, adrp[r]))
            if srcs and ops[-1].type == capstone.arm64.ARM64_OP_MEM:
                mb = ins.reg_name(ops[-1].mem.base)
                if mb in ('sp', 'wsp', 'x29', 'fp') or mb.startswith('x2') or mb.startswith('x19') or mb.startswith('w19'):
                    for r, v in srcs:
                        if is_kaddr(v):
                            out.append(('store_kaddr', ins.address, v, '%s+%#x' % (mb, ops[-1].mem.disp), r, m))
        elif m in ('ret', 'retab', 'br') :
            if m != 'br':
                break
    return out

if __name__ == '__main__':
    subs = parse_mig()
    tot = sum(len(s['routines']) for s in subs)
    print('%d subsystems, %d routines' % (len(subs), tot))
    res = {}
    for s in subs:
        for r in s['routines']:
            if r['name'] == '<unknown>':
                pass
            try:
                a = analyze(r['addr'])
            except Exception as e:
                a = [('err', 0, str(e))]
            hits = [x for x in a if x[0] == 'store_kaddr']
            if hits:
                res['%s/%d' % (r['name'], r['num'])] = dict(sub=s['name'], addr=r['addr'], reply=r['max_reply'],
                                                            reply_descr=r['reply_descr'], argc=r['argc'],
                                                            hits=[(h[1], h[2], h[3]) for h in hits])
    for k, v in res.items():
        print('%-52s %-24s %#x reply=%d rd=%d' % (k, v['sub'], v['addr'], v['reply'], v['reply_descr']))
        for h in v['hits'][:6]:
            print('      %#x  -> %#x  store %s' % (h[0], h[1], h[2]))
    json.dump(res, open('store_kaddr.json', 'w'), indent=1)
