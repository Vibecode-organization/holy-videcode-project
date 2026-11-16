#!/usr/bin/env python3
"""Take the original CMS, re-sign its exact signedAttrs with our key, splice."""
import struct, sys
from cryptography import x509
from cryptography.hazmat.primitives import hashes, serialization
from cryptography.hazmat.primitives.asymmetric import padding
from asn1crypto import cms

def get_sig(d):
    n = struct.unpack_from('<I', d, 16)[0]; off = 32
    for _ in range(n):
        c, cs = struct.unpack_from('<II', d, off)
        if c == 0x1d: return off
        off += cs

def main(src, dst, key_path, leaf_path):
    d = bytearray(open(src, 'rb').read())
    lc = get_sig(d)
    do, ds = struct.unpack_from('<II', d, lc + 8)
    b = bytes(d[do:do + ds])
    m, l, cnt = struct.unpack_from('>III', b, 0)
    blobs = []
    for i in range(cnt):
        t, o = struct.unpack_from('>II', b, 12 + 8 * i)
        mm, ll = struct.unpack_from('>II', b, o)
        blobs.append((t, b[o:o + ll]))
    ci = cms.ContentInfo.load([x for x in blobs if x[0] == 0x10000][0][1][8:])
    sd = ci['content']; si = sd['signer_infos'][0]
    raw = si['signed_attrs'].dump()
    msg = b'\x31' + raw[1:] if raw[0] == 0xa0 else raw
    key = serialization.load_der_private_key(open(key_path, 'rb').read(), password=None)
    si['signature'] = key.sign(msg, padding.PKCS1v15(), hashes.SHA256())
    cms_data = ci.dump()
    newcms = struct.pack('>II', 0xfade0b01, 8 + len(cms_data)) + cms_data
    src_sb = struct.pack('>III', 0xfade0cc0, sum(0 for _ in []), 0)
    # rebuild superblob
    hdr = 12 + 8 * len(blobs); off = hdr; idx = b''; body = b''
    for t, blob in blobs:
        blob = newcms if t == 0x10000 else blob
        idx += struct.pack('>II', t, off); body += blob; off += len(blob)
    sb = struct.pack('>III', 0xfade0cc0, hdr + len(body), len(blobs)) + idx + body
    d[do:do + ds] = sb + b'\0' * (ds - len(sb)) if len(sb) <= ds else b''
    struct.pack_into('<II', d, lc + 8, do, len(sb))
    open(dst, 'wb').write(d)
    print('resigned cms', len(sb))

if __name__ == '__main__':
    main(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4])
