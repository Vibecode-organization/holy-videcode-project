#!/usr/bin/env python3
"""Sign a Mach-O for CoreTrust testing.

modes:
  cms        SHA1 + SHA256 CodeDirectories + crafted CMS (self-signed Apple-like chain)
  adhoc      SHA256 CodeDirectory only, CS_ADHOC flag set, no CMS
  adhoc_ent  same as adhoc plus an XML entitlements blob + slot 5 hash
"""
import sys, os, struct, hashlib
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..', 'cttest'))
import mkct

PAGE = 0x1000
NSLOTS_SPECIAL = 7
ENT_XML = b'''<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0"><dict>
<key>get-task-allow</key><true/>
<key>com.apple.security.cs.disable-library-validation</key><true/>
</dict></plist>'''


def first_section_off(d):
    ncmds = struct.unpack_from('<I', d, 16)[0]
    off = 32
    first = None
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
        if cmd == 0x19 and d[off + 8:off + 24].split(b'\0')[0] == b'__LINKEDIT':
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


def build_cd(code, code_limit, ident, hash_type, flags, slot5=None):
    hash_size = 20 if hash_type == 1 else 32
    h = hashlib.sha1 if hash_type == 1 else hashlib.sha256
    nslots = (code_limit + PAGE - 1) // PAGE
    hashes = b''
    for i in range(nslots):
        a = i * PAGE
        b = min((i + 1) * PAGE, code_limit)
        chunk = code[a:b]
        if len(chunk) < PAGE:
            chunk += b'\0' * (PAGE - len(chunk))
        hashes += h(chunk).digest()
    ident_b = ident.encode() + b'\0'
    ident_off = 0x58
    special_start = (ident_off + len(ident_b) + 3) & ~3
    hash_off = special_start + NSLOTS_SPECIAL * hash_size
    length = hash_off + len(hashes)
    hdr = struct.pack('>IIIIIIIII', 0xfade0c02, length, 0x20400, flags,
                      hash_off, ident_off, NSLOTS_SPECIAL, nslots, code_limit)
    hdr += struct.pack('>BBBB', hash_size, hash_type, 0, 12)
    hdr += struct.pack('>III', 0, 0, 0)          # scatter, team offset, spare
    hdr += struct.pack('>I', 0)                  # code limit 64
    hdr += struct.pack('>QQQQ', 0, 0, 0, 0)      # exec seg base/limit, runtime, preEncrypt
    assert len(hdr) == 0x58
    special = bytearray(NSLOTS_SPECIAL * hash_size)
    if slot5:
        special[5 * hash_size:6 * hash_size] = slot5[:hash_size]
    cd = hdr + ident_b + b'\0' * (special_start - ident_off - len(ident_b))
    cd += bytes(special) + hashes
    return bytes(cd)


def entitlements_blob(xml):
    return struct.pack('>II', 0xfade7171, 8 + len(xml)) + xml


def superblob(entries):
    """entries: list of (type, blob_bytes)"""
    hdr_len = 12 + len(entries) * 8
    off = hdr_len
    index = b''
    body = b''
    for t, blob in entries:
        index += struct.pack('>II', t, off)
        body += blob
        off += len(blob)
    total = hdr_len + len(body)
    return struct.pack('>III', 0xfade0cc0, total, len(entries)) + index + body


def sign(in_path, out_path, mode, root_cn, leaf_cn, apple_ext, ident='com.smith.helper'):
    d = open(in_path, 'rb').read()
    b, lc_off = add_lc(d)
    le_off = find_linkedit(bytes(b))
    if le_off is None:
        raise SystemExit('no __LINKEDIT')
    le_fileoff = struct.unpack_from('<Q', b, le_off + 40)[0]
    sig_off = (len(b) + 15) & ~15

    flags = 0x2 if mode in ('adhoc', 'adhoc_ent') else 0
    ent_blob = entitlements_blob(ENT_XML) if mode == 'adhoc_ent' else None

    if mode == 'cms':
        tmp = bytearray(b)
        struct.pack_into('<II', tmp, lc_off + 8, sig_off, 0)
        cd1 = build_cd(bytes(tmp), sig_off, ident, 1, flags)
        cd2 = build_cd(bytes(tmp), sig_off, ident, 2, flags)
        mkct.build_hashes(out_path + '.tmp', root_cn, leaf_cn, apple_ext,
                          hashlib.sha1(cd1).digest(), hashlib.sha256(cd2).digest(),
                          hashlib.sha256(cd2).digest())
        cms1 = open(out_path + '.tmp.cms', 'rb').read()
        sb_len = len(superblob([(0, cd1), (0x1000, cd2), (0x10000, struct.pack('>II', 0xfade0b01, 8 + len(cms1)) + cms1)]))
        tmp = bytearray(b)
        struct.pack_into('<II', tmp, lc_off + 8, sig_off, sb_len)
    else:
        sb_len = 0
        for _ in range(2):
            tmp = bytearray(b)
            struct.pack_into('<II', tmp, lc_off + 8, sig_off, sb_len)
            if mode == 'adhoc_ent':
                cd = build_cd(bytes(tmp), sig_off, ident, 2, flags,
                              hashlib.sha256(ent_blob).digest())
                entries = [(0, cd), (5, ent_blob)]
            else:
                cd = build_cd(bytes(tmp), sig_off, ident, 2, flags)
                entries = [(0, cd)]
            sb = superblob(entries)
            if len(sb) == sb_len:
                break
            sb_len = len(sb)

    le_size = sig_off + sb_len - le_fileoff
    tmp = bytearray(b)
    struct.pack_into('<II', tmp, lc_off + 8, sig_off, sb_len)
    struct.pack_into('<Q', tmp, le_off + 32, (le_size + 0x3fff) & ~0x3fff)
    struct.pack_into('<Q', tmp, le_off + 48, le_size)

    if mode == 'cms':
        cd1 = build_cd(bytes(tmp), sig_off, ident, 1, flags)
        cd2 = build_cd(bytes(tmp), sig_off, ident, 2, flags)
        mkct.build_hashes(out_path + '.tmp2', root_cn, leaf_cn, apple_ext,
                          hashlib.sha1(cd1).digest(), hashlib.sha256(cd2).digest(),
                          hashlib.sha256(cd2).digest())
        cms = open(out_path + '.tmp2.cms', 'rb').read()
        cmsb = struct.pack('>II', 0xfade0b01, 8 + len(cms)) + cms
        sb = superblob([(0, cd1), (0x1000, cd2), (0x10000, cmsb)])
        if len(sb) != sb_len:
            raise SystemExit('superblob size changed %d -> %d' % (sb_len, len(sb)))
    else:
        if mode == 'adhoc_ent':
            cd = build_cd(bytes(tmp), sig_off, ident, 2, flags, hashlib.sha256(ent_blob).digest())
            sb = superblob([(0, cd), (5, ent_blob)])
        else:
            cd = build_cd(bytes(tmp), sig_off, ident, 2, flags)
            sb = superblob([(0, cd)])
        if len(sb) != sb_len:
            raise SystemExit('superblob size changed %d -> %d' % (sb_len, len(sb)))

    out = bytearray(bytes(tmp))
    out += b'\0' * (sig_off - len(out))
    out[sig_off:sig_off + len(sb)] = sb
    open(out_path, 'wb').write(out)
    os.chmod(out_path, 0o755)
    print('signed', out_path, 'mode', mode, 'size', len(out), 'sigoff', hex(sig_off), 'sbsize', len(sb))
    for f in [out_path + '.tmp.cms', out_path + '.tmp2.cms']:
        try: os.unlink(f)
        except OSError: pass


if __name__ == '__main__':
    if len(sys.argv) < 7:
        print('usage: sign_helper.py in out mode root_cn leaf_cn ext|no'); sys.exit(1)
    mode = sys.argv[3]
    sign(sys.argv[1], sys.argv[2], mode, sys.argv[4], sys.argv[5], sys.argv[6] == 'ext')
