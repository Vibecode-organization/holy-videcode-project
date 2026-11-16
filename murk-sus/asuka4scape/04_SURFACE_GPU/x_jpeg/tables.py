# decode the two dispatch tables + per-handler summary
import struct, json
import xm

kmap = json.load(open('kmap.json'))
T = {e['id']: e for e in kmap}

JPEG = dict(kext='com.apple.driver.AppleJPEGDriver', vt=0xfffffff007e28d40, vptr=0xfffffff007e28d50,
            name='AppleJPEGDriverUserClient', size=0x110, gmc=0xfffffff00ae4b740,
            table=0xfffffff007e293c0, n=10, stride=0x28, fnoff=0)
SURF = dict(kext='com.apple.driver.AppleM2ScalerCSCDriver', vt=0xfffffff007e3b0c8, vptr=0xfffffff007e3b0d8,
            name='IOSurfaceAcceleratorClient', size=0x180, gmc=0xfffffff00ae6eb98,
            table=0xfffffff007e3b738, n=12, stride=0x30, fnoff=0x08)


def entry(fn, off, C):
    base = C['table'] + off * C['stride']
    q = [xm.u64(base + i * 8) for i in range(C['stride'] // 8)]
    f = xm.pac(q[C['fnoff'] // 8]) if q[C['fnoff'] // 8] else 0
    return base, f, q


def args_reads(fnva, n=200):
    """what the handler reads from x2 (IOExternalMethodArguments) and x0 (this)"""
    ins = xm.dis(fnva, 0x320, count=n)
    out = dict(this=[], arg=[], cmp=[], calls=[], strs=[])
    for i in ins:
        s = i.op_str
        if i.mnemonic in ('ldr', 'ldrb', 'ldrh', 'ldrsw', 'ldur', 'ldurb', 'str', 'strb', 'strh', 'stur'):
            if s.startswith('[x0') or s.startswith('w8, [x0'):
                out['this'].append(s)
            if ', [x2' in s or s.startswith('[x2'):
                out['arg'].append(s)
        if i.mnemonic in ('cmp', 'cmn', 'tst') and (', #' in s):
            out['cmp'].append(s)
        if i.mnemonic in ('bl', 'b') and i.op_str.startswith('#'):
            try:
                t = int(i.op_str[1:], 16)
            except ValueError:
                continue
            out['calls'].append((i.mnemonic, t))
    return out


if __name__ == '__main__':
    for C in (JPEG, SURF):
        print("==" * 30)
        print(C['name'], "table", hex(C['table']), "n", C['n'], "stride", hex(C['stride']))
        for k in range(C['n']):
            base, f, q = entry(None, k, C)
            a = args_reads(f)
            print(" sel %2d  %#x  fn=%#x  q=%s" % (k, base, f, ' '.join('%x' % x for x in q)))
            print("        this:", a['this'][:6])
            print("        args:", a['arg'][:6])
            print("        cmp :", a['cmp'][:8])
