#!/usr/bin/env python3
# scan function: print xpc key strings and command ids
import sys, struct
sys.path.insert(0, '/home/femboychik/work/cmd_audit')
import dasm

im = dasm.Image()

XPC_FUNCS = ('_xpc_dictionary_get_string', '_xpc_dictionary_get_uint64', '_xpc_dictionary_get_int64',
             '_xpc_dictionary_get_BOOL', '_xpc_dictionary_get_value', '_xpc_dictionary_get_data',
             '_xpc_dictionary_get_double', '_xpc_dictionary_get_count')

def scan(va, n=2000):
    code = im.read(va, n*4)
    ins = list(im.md.disasm(code, va))
    for i, x in enumerate(ins):
        if x.mnemonic == 'bl':
            try:
                tgt = int(x.op_str[1:], 16)
            except ValueError:
                continue
            nm = im.name_at(tgt)
            if nm in XPC_FUNCS:
                # walk back for x1 key
                key = None
                for j in range(i-1, max(0, i-10), -1):
                    p = ins[j]
                    if p.mnemonic == 'add' and p.op_str.startswith('x1, x1,'):
                        try:
                            immv = int(p.op_str.split('#')[1], 0)
                        except (IndexError, ValueError):
                            continue
                        # find adrp x1
                        for k in range(j-1, max(0, j-4), -1):
                            q = ins[k]
                            if q.mnemonic == 'adrp' and q.op_str.startswith('x1,'):
                                page = int(q.op_str.split('#')[1], 16)
                                key = im.cstr(page + immv)
                                break
                        break
                print(f'{x.address:08x} {nm}  key={key}')
        if x.mnemonic in ('ret', 'retab'):
            break

if __name__ == '__main__':
    scan(int(sys.argv[1], 16), int(sys.argv[2]) if len(sys.argv) > 2 else 2000)
