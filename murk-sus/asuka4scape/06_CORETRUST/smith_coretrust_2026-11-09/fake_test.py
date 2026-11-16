#!/usr/bin/env python3
"""Build a test IPA whose CMS is signed by a fake, Apple-named chain.

Isolates CoreTrust's certificate/policy decision: the CodeDirectory is taken
from a known-good binary, so only the CMS/chain changes.
"""
import os, sys, struct, shutil, zipfile, hashlib
sys.path.insert(0, '/tmp/opencode')
sys.path.insert(0, '/home/femboychik/asuka4scape/06_CORETRUST/cttest')
import mkct
from ctsign import find_segment


def lc_off(d):
    n = struct.unpack_from('<I', d, 16)[0]
    off = 32
    for _ in range(n):
        c, cs = struct.unpack_from('<II', d, off)
        if c == 0x1d:
            return off
        off += cs


def blobs_of(d):
    lc = lc_off(d)
    do, ds = struct.unpack_from('<II', d, lc + 8)
    b = d[do:do + ds]
    m, l, cnt = struct.unpack_from('>III', b, 0)
    out = []
    for i in range(cnt):
        t, o = struct.unpack_from('>II', b, 12 + 8 * i)
        mm, ll = struct.unpack_from('>II', b, o)
        out.append((t, b[o:o + ll]))
    return lc, do, ds, out


def make(base_dir, out_ipa, root_cn, leaf_cn, apple_ext, with_profile):
    app = os.path.join(base_dir, 'Payload/BQ272.app')
    binp = os.path.join(app, 'BQ272')
    d = bytearray(open(binp, 'rb').read())
    lc, do, ds, blobs = blobs_of(d)
    cd = [x for x in blobs if x[0] == 0][0][1]
    prefix = '/tmp/opencode/fake_%s' % (hashlib.sha256(root_cn.encode() + leaf_cn.encode()).hexdigest()[:8])
    mkct.build_hashes(prefix, root_cn, leaf_cn, apple_ext,
                      hashlib.sha1(cd).digest(), hashlib.sha256(cd).digest(),
                      hashlib.sha256(cd).digest())
    cms = open(prefix + '.cms', 'rb').read()
    newcms = struct.pack('>II', 0xfade0b01, 8 + len(cms)) + cms
    out = [(t, newcms if t == 0x10000 else v) for t, v in blobs]
    # rebuild superblob, keep original pad
    hdr = 12 + 8 * len(out)
    off = hdr
    idx = b''
    body = b''
    for t, blob in out:
        idx += struct.pack('>II', t, off)
        body += blob
        off += len(blob)
    sb = struct.pack('>III', 0xfade0cc0, hdr + len(body), len(out)) + idx + body
    if len(sb) > ds:
        raise SystemExit('cms too big %d > %d' % (len(sb), ds))
    d[do:do + ds] = sb + b'\0' * (ds - len(sb))
    open(binp, 'wb').write(d)
    if not with_profile:
        p = os.path.join(app, 'embedded.mobileprovision')
        if os.path.exists(p):
            os.unlink(p)
    if os.path.exists(out_ipa):
        os.unlink(out_ipa)
    top = os.path.dirname(os.path.dirname(app))
    with zipfile.ZipFile(out_ipa, 'w', zipfile.ZIP_DEFLATED) as z:
        for dp, dn, fn in os.walk(top):
            for f in fn:
                fp = os.path.join(dp, f)
                z.write(fp, os.path.relpath(fp, top))
    print('built', out_ipa, 'cms', len(sb), 'chain', root_cn, '->', leaf_cn, 'ext', apple_ext, 'profile', with_profile)


if __name__ == '__main__':
    base, out, root_cn, leaf_cn, ext, prof = sys.argv[1:7]
    make(base, out, root_cn, leaf_cn, ext == '1', prof == '1')
