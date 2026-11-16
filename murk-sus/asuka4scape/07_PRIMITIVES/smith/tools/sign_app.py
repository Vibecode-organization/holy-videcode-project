#!/usr/bin/env python3
"""Sign an iOS app executable with a crafted CoreTrust CMS.

usage: sign_app.py in_bin out_bin com.smith.rootkey ents.plist ROOT_CN LEAF_CN ext|no
"""
import sys, os, struct, hashlib, tempfile
sys.path.insert(0, "/home/femboychik/work/cttest")
import mkct

PAGE = 0x1000
NSLOTS = 7

def first_section_off(d):
    ncmds = struct.unpack_from('<I', d, 16)[0]; off = 32; first = None
    for _ in range(ncmds):
        cmd, sz = struct.unpack_from('<II', d, off)
        if cmd == 0x19 and d[off+8:off+24].split(b'\0')[0] == b'__TEXT':
            nsects = struct.unpack_from('<I', d, off + 64)[0]; so = off + 72
            for _ in range(nsects):
                o = struct.unpack_from('<I', d, so + 48)[0]
                if o and (first is None or o < first): first = o
                so += 80
        off += sz
    return first

def find_linkedit(d):
    ncmds = struct.unpack_from('<I', d, 16)[0]; off = 32
    for _ in range(ncmds):
        cmd, sz = struct.unpack_from('<II', d, off)
        if cmd == 0x19 and d[off+8:off+24].split(b'\0')[0] == b'__LINKEDIT': return off
        off += sz
    return None

def find_code_sig(d):
    ncmds = struct.unpack_from('<I', d, 16)[0]; off = 32
    for _ in range(ncmds):
        cmd, sz = struct.unpack_from('<II', d, off)
        if cmd == 0x1d:
            return off, struct.unpack_from('<II', d, off + 8)[0], struct.unpack_from('<II', d, off + 12)[0]
        off += sz
    return None, 0, 0

def add_lc(d):
    ncmds = struct.unpack_from('<I', d, 16)[0]; sizeofcmds = struct.unpack_from('<I', d, 20)[0]
    lc_off = 32 + sizeofcmds; first = first_section_off(d)
    if first is None or lc_off + 16 > first:
        raise SystemExit('no space for LC_CODE_SIGNATURE (lc_off=%#x first=%#x)' % (lc_off, first or 0))
    b = bytearray(d)
    struct.pack_into('<IIII', b, lc_off, 0x1d, 16, 0, 0)
    struct.pack_into('<II', b, 16, ncmds + 1, sizeofcmds + 16)
    return b, lc_off

def build_cd(code, code_limit, ident, hash_type, flags, ent_hash, res_hash=None):
    hs = 20 if hash_type == 1 else 32
    h = hashlib.sha1 if hash_type == 1 else hashlib.sha256
    nslots = (code_limit + PAGE - 1) // PAGE
    hashes = b''.join(h(code[i*PAGE:min((i+1)*PAGE, code_limit)].ljust(PAGE, b'\0')).digest() for i in range(nslots))
    ident_b = ident.encode() + b'\0'
    ident_off = 0x58
    special_start = (ident_off + len(ident_b) + 3) & ~3
    hash_off = special_start + NSLOTS * hs
    length = hash_off + len(hashes)
    hdr = struct.pack('>IIIIIIIII', 0xfade0c02, length, 0x20400, flags, hash_off, ident_off, NSLOTS, nslots, code_limit)
    hdr += struct.pack('>BBBB', hs, hash_type, 0, 12)
    hdr += struct.pack('>III', 0, 0, 0)
    hdr += struct.pack('>I', 0)
    hdr += struct.pack('>QQQQ', 0, 0, 0, 0)
    assert len(hdr) == 0x58
    special = bytearray(NSLOTS * hs)
    if ent_hash: special[5*hs:6*hs] = ent_hash[:hs]
    if res_hash: special[3*hs:4*hs] = res_hash[:hs]
    cd = hdr + ident_b + b'\0' * (special_start - ident_off - len(ident_b))
    cd += bytes(special) + hashes
    return bytes(cd)

def ent_blob(xml):
    return struct.pack('>II', 0xfade7171, 8 + len(xml)) + xml

def superblob(entries):
    hdr_len = 12 + len(entries)*8; off = hdr_len; index = b''; body = b''
    for t, blob in entries:
        index += struct.pack('>II', t, off); body += blob; off += len(blob)
    return struct.pack('>III', 0xfade0cc0, hdr_len + len(body), len(entries)) + index + body

def sign(inp, outp, ident, ent_path, root_cn, leaf_cn, apple_ext, res_path=None):
    xml = open(ent_path, 'rb').read()
    eb = ent_blob(xml)
    rb = open(res_path,'rb').read() if res_path else None
    d = open(inp, 'rb').read()
    lc, dataoff, datasize = find_code_sig(d)
    if lc is None:
        b, lc = add_lc(d)
        b = bytes(b)
        sig_off = (len(b) + 15) & ~15
    else:
        sig_off = dataoff
        b = bytes(d[:sig_off])
    le = find_linkedit(b)
    if le is None: raise SystemExit('no __LINKEDIT')
    le_fileoff = struct.unpack_from('<Q', b, le + 40)[0]

    def build(sb_len, sig_off, le_size):
        tmp = bytearray(b)
        struct.pack_into('<II', tmp, lc + 8, sig_off, sb_len)
        struct.pack_into('<Q', tmp, le + 32, (le_size + 0x3fff) & ~0x3fff)
        struct.pack_into('<Q', tmp, le + 48, le_size)
        cd1 = build_cd(bytes(tmp), sig_off, ident, 1, 0, hashlib.sha1(eb).digest(), hashlib.sha1(rb).digest() if rb else None)
        cd2 = build_cd(bytes(tmp), sig_off, ident, 2, 0, hashlib.sha256(eb).digest(), hashlib.sha256(rb).digest() if rb else None)
        with tempfile.TemporaryDirectory() as td:
            pfx = os.path.join(td, 'ct')
            mkct.build_hashes(pfx, root_cn, leaf_cn, apple_ext,
                              hashlib.sha1(cd1).digest(), hashlib.sha256(cd2).digest(),
                              hashlib.sha256(cd2).digest())
            cms = open(pfx + '.cms', 'rb').read()
        cmsb = struct.pack('>II', 0xfade0b01, 8 + len(cms)) + cms
        sb = superblob([(0, cd1), (0x1000, cd2), (5, eb), (0x10000, cmsb)])
        return tmp, sb

    sb_len = 0
    le_size = sig_off - le_fileoff
    for _ in range(6):
        tmp, sb = build(sb_len, sig_off, le_size)
        if len(sb) == sb_len:
            break
        sb_len = len(sb)
        le_size = sig_off + sb_len - le_fileoff
    else:
        raise SystemExit('size did not converge')
    out = bytearray(tmp)
    out += b'\0' * (sig_off - len(out))
    out[sig_off:sig_off+len(sb)] = sb
    open(outp, 'wb').write(out); os.chmod(outp, 0o755)
    print('signed', outp, 'cd_ident', ident, 'size', len(out), 'sig', hex(sig_off), len(sb))

if __name__ == '__main__':
    if len(sys.argv) not in (8, 9):
        print(__doc__); sys.exit(1)
    sign(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5], sys.argv[6], sys.argv[7] == 'ext', sys.argv[8] if len(sys.argv) > 8 else None)
