#!/usr/bin/env python3
"""Sign an .app bundle with a real Apple developer cert (key + cert chain),
a fake provisioning profile, and a freshly computed resource envelope."""
import os, sys, struct, hashlib, plistlib, datetime, glob

sys.path.insert(0, '/home/femboychik/work/cttest')
import mkct
from asn1crypto import cms, core, x509 as ax509
from cryptography import x509
from cryptography.hazmat.primitives import hashes, serialization
from cryptography.hazmat.primitives.asymmetric import padding

PAGE = 0x1000
NSLOTS_SPECIAL = 7


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


def find_lc_sig(d):
    ncmds = struct.unpack_from('<I', d, 16)[0]
    off = 32
    for _ in range(ncmds):
        cmd, cs = struct.unpack_from('<II', d, off)
        if cmd == 0x1d:
            return off, struct.unpack_from('<II', d, off + 8)[0]
        off += cs
    return None


def find_segment(d, name):
    ncmds = struct.unpack_from('<I', d, 16)[0]
    off = 32
    for _ in range(ncmds):
        cmd, cs = struct.unpack_from('<II', d, off)
        if cmd == 0x19:
            n = d[off + 8:off + 24].split(b'\0')[0].decode()
            if n == name:
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


def build_cd(code, sig_off, ident, team, hash_type, slots, version=0x20400,
             exec_limit=0xc000, exec_flags=0x11):
    hs = 20 if hash_type == 1 else 32
    h = hashlib.sha1 if hash_type == 1 else hashlib.sha256
    nslots = (sig_off + PAGE - 1) // PAGE
    hashes = b''
    for i in range(nslots):
        chunk = code[i * PAGE:min((i + 1) * PAGE, sig_off)]
        if len(chunk) < PAGE:
            chunk += b'\0' * (PAGE - len(chunk))
        hashes += h(chunk).digest()
    ident_b = ident.encode() + b'\0'
    team_b = team.encode() + b'\0'
    ident_off = 0x58
    team_off = ident_off + len(ident_b)
    special_start = team_off + len(team_b)
    hash_off = special_start + NSLOTS_SPECIAL * hs
    special = bytearray(NSLOTS_SPECIAL * hs)
    for idx, val in slots.items():
        i = int(idx)
        if 1 <= i <= NSLOTS_SPECIAL:
            special[(NSLOTS_SPECIAL - i) * hs:(NSLOTS_SPECIAL - i + 1) * hs] = val[:hs]
    hdr = struct.pack('>IIIIIIIII', 0xfade0c02, hash_off + len(hashes), version, 0,
                      hash_off, ident_off, NSLOTS_SPECIAL, nslots, sig_off)
    hdr += struct.pack('>BBBB', hs, hash_type, 0, 12)
    hdr += struct.pack('>IIII', 0, 0, team_off, 0)
    hdr += struct.pack('>Q', 0)
    hdr += struct.pack('>QQQ', 0, exec_limit, exec_flags)
    assert len(hdr) == 0x58, len(hdr)
    cd = hdr + ident_b + team_b + bytes(special) + hashes
    return cd


def build_cms(cd1, cd256, key, cert_chain):
    """cert_chain: list of cryptography certs, leaf first."""
    leaf = cert_chain[0]
    sha1_cd = hashlib.sha1(cd1).digest()
    sha256_alt = hashlib.sha256(cd256).digest()
    xml = plistlib.dumps({'cdhashes': [sha1_cd, sha256_alt[:20]]}, fmt=plistlib.FMT_XML)
    # 1.2.840.113635.100.9.2 = SET { DigestInfo(sha1, sha1(CD1)), DigestInfo(sha256, sha256(CD256)) }
    der1 = b'\x30\x1d\x06\x05\x2b\x0e\x03\x02\x1a\x04\x14' + sha1_cd
    der2 = b'\x30\x2d\x06\x09\x60\x86\x48\x01\x65\x03\x04\x02\x01\x04\x20' + sha256_alt
    attrs = cms.CMSAttributes([
        cms.CMSAttribute({'type': 'content_type', 'values': ['data']}),
        cms.CMSAttribute({'type': 'message_digest', 'values': [hashlib.sha256(cd1).digest()]}),
        cms.CMSAttribute({'type': 'signing_time', 'values': [
            cms.Time({'utc_time': core.UTCTime(datetime.datetime.now(datetime.timezone.utc))})]}),
        cms.CMSAttribute({'type': '1.2.840.113635.100.9.1', 'values': [core.OctetString(xml)]}),
        cms.CMSAttribute({'type': '1.2.840.113635.100.9.2',
                          'values': [core.SequenceOf.load(der1), core.SequenceOf.load(der2)]}),
    ])
    items = sorted([a for a in attrs], key=lambda a: a.dump())
    attrs = cms.CMSAttributes(items)
    raw = attrs.dump()
    signed = b'\x31' + raw[1:] if raw[0] == 0xA0 else raw
    sig = key.sign(signed, padding.PKCS1v15(), hashes.SHA256())
    leaf_asn1 = ax509.Certificate.load(leaf.public_bytes(serialization.Encoding.DER))
    sid = cms.SignerIdentifier({'issuer_and_serial_number': cms.IssuerAndSerialNumber({
        'issuer': leaf_asn1.issuer, 'serial_number': leaf_asn1.serial_number})})
    si = cms.SignerInfo({
        'version': 'v1', 'sid': sid,
        'digest_algorithm': {'algorithm': 'sha256', 'parameters': core.Null()},
        'signed_attrs': attrs,
        'signature_algorithm': {'algorithm': 'sha256_rsa', 'parameters': core.Null()},
        'signature': sig})
    chain = [ax509.Certificate.load(c.public_bytes(serialization.Encoding.DER))
             for c in cert_chain[1:]]
    # mirror iLoader order: intermediates/root first, leaf last
    sd = cms.SignedData({
        'version': 'v1',
        'digest_algorithms': [{'algorithm': 'sha256', 'parameters': core.Null()}],
        'encap_content_info': {'content_type': 'data'},
        'certificates': cms.CertificateSet(chain + [leaf_asn1]),
        'signer_infos': [si]})
    return cms.ContentInfo({'content_type': 'signed_data', 'content': sd}).dump()


def superblob(entries):
    body = b''
    off = 12 + 8 * len(entries)
    for t, b in entries:
        body += struct.pack('>II', t, off)
        off += len(b)
    total = 12 + len(body) + sum(len(b) for _, b in entries)
    return struct.pack('>III', 0xfade0cc0, total, len(entries)) + body + b''.join(b for _, b in entries)


def sign_app(bundle, profile, key, certs, template_cr, ident=None, preserve=False):
    info_path = os.path.join(bundle, 'Info.plist')
    info = open(info_path, 'rb').read()
    pl = plistlib.loads(info)
    ident = ident or pl['CFBundleIdentifier']
    team = '873962H52X'
    binary_name = pl['CFBundleExecutable']
    bin_path = os.path.join(bundle, binary_name)
    d = open(bin_path, 'rb').read()

    # profile -> entitlements
    pci = cms.ContentInfo.load(open(profile, 'rb').read())
    ppl = plistlib.loads(pci['content']['encap_content_info']['content'].native)
    ents = ppl['Entitlements']
    ent_xml = plistlib.dumps(ents, fmt=plistlib.FMT_XML, sort_keys=True)
    ent_blob = struct.pack('>II', 0xfade7171, 8 + len(ent_xml)) + ent_xml
    der_blob = struct.pack('>II', 0xfade7172, 8 + len(build_der_entitlements(ents))) + build_der_entitlements(ents)

    # strip old signature
    lc = find_lc_sig(d)
    if lc is None:
        raise SystemExit('no LC_CODE_SIGNATURE')
    lc_off, old_off = lc
    orig_datasize = struct.unpack_from('<I', d, lc_off + 12)[0]
    base = bytearray(d[:old_off])
    # align signature offset
    sig_off = (len(base) + 15) & ~15
    base += b'\0' * (sig_off - len(base))

    # CodeResources (written into bundle first)
    cr = build_code_resources(bundle, template_cr, binary_name)
    os.makedirs(os.path.join(bundle, '_CodeSignature'), exist_ok=True)
    open(os.path.join(bundle, '_CodeSignature', 'CodeResources'), 'wb').write(cr)

    req_blob = struct.pack('>III', 0xfade0c01, 12, 0)

    def make(sb_len):
        b = bytearray(base)
        if not preserve:
            struct.pack_into('<II', b, lc_off + 8, sig_off, sb_len)
            le = find_segment(bytes(b), '__LINKEDIT')
            le_fileoff = struct.unpack_from('<Q', b, le + 40)[0]
            le_size = sig_off + sb_len - le_fileoff
            struct.pack_into('<Q', b, le + 32, (le_size + 0x3fff) & ~0x3fff)
            struct.pack_into('<Q', b, le + 48, le_size)
        code = bytes(b)
        slots1 = {1: hashlib.sha1(info).digest(),
                  2: hashlib.sha1(req_blob).digest(),
                  3: hashlib.sha1(cr).digest(),
                  5: hashlib.sha1(ent_blob).digest(),
                  7: hashlib.sha1(der_blob).digest()}
        slots256 = {1: hashlib.sha256(info).digest(),
                    2: hashlib.sha256(req_blob).digest(),
                    3: hashlib.sha256(cr).digest(),
                    5: hashlib.sha256(ent_blob).digest(),
                    7: hashlib.sha256(der_blob).digest()}
        cd1 = build_cd(code, sig_off, ident, team, 1, slots1)
        cd256 = build_cd(code, sig_off, ident, team, 2, slots256)
        return cd1, cd256, code

    # size iteration
    sb_len = 0
    for _ in range(8):
        cd1, cd256, code = make(sb_len)
        cms_data = build_cms(cd1, cd256, key, certs)
        cms_blob = struct.pack('>II', 0xfade0b01, 8 + len(cms_data)) + cms_data
        sb = superblob([(0, cd1), (2, req_blob), (5, ent_blob), (7, der_blob),
                        (0x1000, cd256), (0x10000, cms_blob)])
        if len(sb) == sb_len:
            break
        sb_len = len(sb)
    else:
        raise SystemExit('signature size did not converge')
    cd1, cd256, code = make(len(sb))
    cms_data = build_cms(cd1, cd256, key, certs)
    cms_blob = struct.pack('>II', 0xfade0b01, 8 + len(cms_data)) + cms_data
    sb = superblob([(0, cd1), (2, req_blob), (5, ent_blob), (7, der_blob),
                    (0x1000, cd256), (0x10000, cms_blob)])
    assert len(sb) == sb_len

    out = bytearray(base)
    if preserve:
        assert len(sb) <= orig_datasize, (len(sb), orig_datasize)
        out += sb + b'\0' * (orig_datasize - len(sb))
    else:
        struct.pack_into('<II', out, lc_off + 8, sig_off, len(sb))
        le = find_segment(bytes(out), '__LINKEDIT')
        le_fileoff = struct.unpack_from('<Q', out, le + 40)[0]
        le_size = sig_off + len(sb) - le_fileoff
        struct.pack_into('<Q', out, le + 32, (le_size + 0x3fff) & ~0x3fff)
        struct.pack_into('<Q', out, le + 48, le_size)
        out += sb
    open(bin_path, 'wb').write(out)
    os.chmod(bin_path, 0o755)
    print('signed', bin_path, 'size', len(out), 'sig', hex(sig_off), len(sb),
          'cd1', hashlib.sha1(cd1).hexdigest()[:16], 'cd256', hashlib.sha256(cd256).hexdigest()[:16])
    return ents


if __name__ == '__main__':
    bundle, profile, key_path, template_cr = sys.argv[1:5]
    certs = [x509.load_der_x509_certificate(open(p, 'rb').read()) for p in sys.argv[5:]]
    key = serialization.load_der_private_key(open(key_path, 'rb').read(), password=None)
    sign_app(bundle, profile, key, certs, template_cr, preserve=os.environ.get('PRESERVE')=='1')
