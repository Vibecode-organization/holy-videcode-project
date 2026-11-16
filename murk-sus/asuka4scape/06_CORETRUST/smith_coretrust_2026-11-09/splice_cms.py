#!/usr/bin/env python3
"""Splice a freshly built CMS into an existing signed Mach-O.

Keeps every other signature blob and the CodeDirectory, rewrites
LC_CODE_SIGNATURE.datasize, __LINKEDIT and truncates the file exactly at the
end of the new superblob (trailing bytes after the signature make the Mach-O
invalid on iOS).
"""
import os, sys, struct, hashlib, math
sys.path.insert(0, '/tmp/opencode')
from ctsign import build_cms, superblob, find_segment
from cryptography import x509
from cryptography.hazmat.primitives import serialization


def get_lc(d):
    n = struct.unpack_from('<I', d, 16)[0]
    off = 32
    for _ in range(n):
        c, cs = struct.unpack_from('<II', d, off)
        if c == 0x1d:
            return off
        off += cs


def main(src, dst, key_path, cert_paths):
    d = bytearray(open(src, 'rb').read())
    lc = get_lc(d)
    dataoff, datasize = struct.unpack_from('<II', d, lc + 8)
    b = bytes(d[dataoff:dataoff + datasize])
    magic, length, count = struct.unpack_from('>III', b, 0)
    blobs = []
    for i in range(count):
        t, o = struct.unpack_from('>II', b, 12 + 8 * i)
        m, l = struct.unpack_from('>II', b, o)
        blobs.append((t, b[o:o + l]))
    cd = [x for x in blobs if x[0] == 0][0][1]
    key = serialization.load_der_private_key(open(key_path, 'rb').read(), password=None)
    certs = [x509.load_der_x509_certificate(open(p, 'rb').read()) for p in cert_paths]
    cms_data = build_cms(cd, key, certs)
    new_cms = struct.pack('>II', 0xfade0b01, 8 + len(cms_data)) + cms_data
    out = [(t, (new_cms if t == 0x10000 else blob)) for t, blob in blobs]
    sb = superblob(out)
    del d[dataoff:]
    d += sb
    struct.pack_into('<II', d, lc + 8, dataoff, len(sb))
    le = find_segment(bytes(d), '__LINKEDIT')
    le_fileoff = struct.unpack_from('<Q', d, le + 40)[0]
    le_size = len(d) - le_fileoff
    struct.pack_into('<Q', d, le + 32, (le_size + 0xfff) & ~0xfff)
    struct.pack_into('<Q', d, le + 48, le_size)
    open(dst, 'wb').write(d)
    print('spliced cms superblob=%d file=%d cd=%s' % (len(sb), len(d), hashlib.sha256(cd).hexdigest()[:16]))


if __name__ == '__main__':
    main(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4:])
