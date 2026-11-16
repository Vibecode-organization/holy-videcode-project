#!/usr/bin/env python3
"""ctsign — sign an iOS .app bundle in the layout CoreTrust/AMFI expect.

Single SHA-256 CodeDirectory, CMS SignedData with Apple hash-agility
attributes 9.1 (XML cdhashes) and 9.2 (DigestInfo), optional chain/extra
signers injected by the caller.
"""
import os, sys, struct, hashlib, plistlib, datetime, zipfile, shutil
from cryptography import x509
from cryptography.hazmat.primitives import hashes, serialization
from cryptography.hazmat.primitives.asymmetric import padding, rsa
from asn1crypto import cms, core, x509 as ax509

PAGE = 0x1000
NSLOTS = 7


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


def build_cd(code, sig_off, ident, team, exec_limit, slots):
    hs = 32
    nslots = (sig_off + PAGE - 1) // PAGE
    hashes = b''
    for i in range(nslots):
        chunk = code[i * PAGE:min((i + 1) * PAGE, sig_off)]
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
    assert len(hdr) == 0x58
    return hdr + ident_b + team_b + bytes(special) + hashes


def digest_info_sha256(digest):
    return b'\x30\x2d\x06\x09\x60\x86\x48\x01\x65\x03\x04\x02\x01\x04\x20' + digest


def build_cms(cd, key, cert_chain, extra_attrs=None, extra_signers=None,
              message_digest=None, agility_digest=None):
    """cert_chain: [leaf, intermediate, root] (cryptography certs).
    extra_signers: list of dicts {key, cert(chain leaf), attrs} appended."""
    leaf = cert_chain[0]
    md = message_digest or hashlib.sha256(cd).digest()
    ad = agility_digest or hashlib.sha256(cd).digest()
    xml = plistlib.dumps({'cdhashes': [ad[:20]]}, fmt=plistlib.FMT_XML)
    attrs = [
        cms.CMSAttribute({'type': 'content_type', 'values': ['data']}),
        cms.CMSAttribute({'type': 'signing_time', 'values': [
            cms.Time({'utc_time': core.UTCTime(datetime.datetime.now(datetime.timezone.utc))})]}),
        cms.CMSAttribute({'type': 'message_digest', 'values': [md]}),
        cms.CMSAttribute({'type': '1.2.840.113635.100.9.1', 'values': [core.OctetString(xml)]}),
        cms.CMSAttribute({'type': '1.2.840.113635.100.9.2',
                          'values': [core.Sequence.load(digest_info_sha256(ad))]}),
    ]
    if extra_attrs:
        attrs += extra_attrs
    attrs = cms.CMSAttributes(sorted(attrs, key=lambda a: a.dump()))
    raw = attrs.dump()
    signed = (b'\x31' + raw[1:]) if raw[0] == 0xA0 else raw
    sig = key.sign(signed, padding.PKCS1v15(), hashes.SHA256())
    leaf_asn1 = ax509.Certificate.load(leaf.public_bytes(serialization.Encoding.DER))
    sid = cms.SignerIdentifier({'issuer_and_serial_number': cms.IssuerAndSerialNumber({
        'issuer': leaf_asn1.issuer, 'serial_number': leaf_asn1.serial_number})})
    signer = cms.SignerInfo({
        'version': 'v1', 'sid': sid,
        'digest_algorithm': {'algorithm': 'sha256', 'parameters': core.Null()},
        'signed_attrs': attrs,
        'signature_algorithm': {'algorithm': 'rsassa_pkcs1v15', 'parameters': core.Null()},
        'signature': sig})
    signers = [signer]
    certs = [ax509.Certificate.load(c.public_bytes(serialization.Encoding.DER))
             for c in cert_chain]
    for es in (extra_signers or []):
        signers.append(es['signer'])
        certs.extend(es.get('certs') or [])
    sd = cms.SignedData({
        'version': 'v1',
        'digest_algorithms': [{'algorithm': 'sha256', 'parameters': core.Null()}],
        'encap_content_info': {'content_type': 'data'},
        'certificates': cms.CertificateSet(certs[1:] + [certs[0]]),
        'signer_infos': signers})
    return cms.ContentInfo({'content_type': 'signed_data', 'content': sd}).dump()


def profile_ents(profile_path):
    raw = open(profile_path, 'rb').read()
    i = raw.find(b'<?xml')
    j = raw.find(b'</plist>', i)
    if i < 0 or j < 0:
        raise SystemExit('profile payload not found')
    return plistlib.loads(raw[i:j + 8])


def sign_app(bundle, profile, key_path, cert_paths, ident=None, team=None,
             ents_override=None, cms_hook=None, out_ipa=None, verbose=True,
             req_blob_path=None, ent_xml_path=None, ent_der_path=None, embed_profile=True):
    info_path = os.path.join(bundle, 'Info.plist')
    info = open(info_path, 'rb').read()
    pl = plistlib.loads(info)
    ident = ident or pl['CFBundleIdentifier']
    binary_name = pl['CFBundleExecutable']
    bin_path = os.path.join(bundle, binary_name)
    d = open(bin_path, 'rb').read()

    if not embed_profile and os.path.exists(os.path.join(bundle, 'embedded.mobileprovision')):
        os.unlink(os.path.join(bundle, 'embedded.mobileprovision'))
    ppl = profile_ents(profile)
    ents = ents_override if ents_override is not None else ppl['Entitlements']
    if team is None:
        team = ppl['TeamIdentifier'][0]
    if ent_xml_path:
        ent_blob = open(ent_xml_path, 'rb').read()
    else:
        ent_xml = plistlib.dumps(ents, fmt=plistlib.FMT_XML, sort_keys=True)
        ent_blob = struct.pack('>II', 0xfade7171, 8 + len(ent_xml)) + ent_xml
    if ent_der_path:
        der_blob = open(ent_der_path, 'rb').read()
    else:
        der_blob = struct.pack('>II', 0xfade7172, 8 + len(build_der_entitlements(ents))) + build_der_entitlements(ents)

    lc_off = find_lc(d, 0x1d)
    if lc_off is None:
        d = bytearray(d)
        ncmds, sizeofcmds = struct.unpack_from('<II', d, 16)
        lc_off = 32 + sizeofcmds
        first = None
        off = 32
        for _ in range(ncmds):
            c, cs = struct.unpack_from('<II', d, off)
            if c == 0x19:
                nsects = struct.unpack_from('<I', d, off + 64)[0]
                soff = off + 72
                for _ in range(nsects):
                    o = struct.unpack_from('<I', d, soff + 48)[0]
                    first = o if first is None else min(first, o)
                    soff += 80
            off += cs
        if first is not None and lc_off + 16 > first:
            raise SystemExit('no headerpad for LC_CODE_SIGNATURE (%x > %x)' % (lc_off + 16, first))
        struct.pack_into('<IIII', d, lc_off, 0x1d, 16, 0, 0)
        struct.pack_into('<II', d, 16, ncmds + 1, sizeofcmds + 16)
        d = bytes(d)
        old_off = len(d)
    else:
        old_off = struct.unpack_from('<I', d, lc_off + 8)[0]
    req_off = old_off
    # pull the original requirements blob if present, else empty
    req = struct.pack('>III', 0xfade0c01, 12, 0)
    if req_blob_path:
        req = open(req_blob_path, 'rb').read()
    if os.path.exists(os.path.join(bundle, '_CodeSignature', 'CodeResources')):
        pass

    base = bytearray(d[:old_off])
    sig_off = (len(base) + 15) & ~15
    base += b'\0' * (sig_off - len(base))

    key = serialization.load_der_private_key(open(key_path, 'rb').read(), password=None)
    certs = [x509.load_der_x509_certificate(open(p, 'rb').read()) for p in cert_paths]
    if os.path.exists(os.path.join(bundle, '_CodeSignature', 'CodeResources')):
        cr = open(os.path.join(bundle, '_CodeSignature', 'CodeResources'), 'rb').read()
    else:
        cr = b''

    text = find_segment(d, '__TEXT')
    exec_limit = struct.unpack_from('<Q', d, text + 48)[0] if text else 0x4000

    def make(sb_len):
        pad = int(os.environ.get('CT_PAD','0'),0) or ((sb_len + 0xfff) & ~0xfff)
        b = bytearray(base)
        struct.pack_into('<II', b, lc_off + 8, sig_off, pad)
        le = find_segment(bytes(b), '__LINKEDIT')
        le_fileoff = struct.unpack_from('<Q', b, le + 40)[0]
        le_size = sig_off + pad - le_fileoff
        struct.pack_into('<Q', b, le + 32, (le_size + 0xfff) & ~0xfff)
        struct.pack_into('<Q', b, le + 48, le_size)
        code = bytes(b)
        slots = {1: hashlib.sha256(info).digest(),
                 2: hashlib.sha256(req).digest(),
                 3: hashlib.sha256(cr).digest(),
                 5: hashlib.sha256(ent_blob).digest(),
                 7: hashlib.sha256(der_blob).digest()}
        return build_cd(code, sig_off, ident, team, exec_limit, slots), code, pad

    sb_len = 0
    for _ in range(12):
        cd, code, pad = make(sb_len)
        cms_data = build_cms(cd, key, certs)
        if cms_hook:
            cms_data = cms_hook(cd, key, certs, cms_data)
        cms_blob = struct.pack('>II', 0xfade0b01, 8 + len(cms_data)) + cms_data
        sb = superblob([(0, cd), (2, req), (5, ent_blob), (7, der_blob), (0x10000, cms_blob)])
        if len(sb) == sb_len:
            break
        sb_len = len(sb)
    else:
        raise SystemExit('signature size did not converge')
    cd, code, pad = make(len(sb))
    cms_data = build_cms(cd, key, certs)
    if cms_hook:
        cms_data = cms_hook(cd, key, certs, cms_data)
    cms_blob = struct.pack('>II', 0xfade0b01, 8 + len(cms_data)) + cms_data
    sb = superblob([(0, cd), (2, req), (5, ent_blob), (7, der_blob), (0x10000, cms_blob)])
    assert len(sb) == sb_len, (len(sb), sb_len)
    assert pad >= len(sb) and pad % 0x1000 == 0, (pad, len(sb))

    out = bytearray(code)
    out += sb + b'\0' * (pad - len(sb))
    open(bin_path, 'wb').write(out)
    os.chmod(bin_path, 0o755)
    if verbose:
        print('signed %s cd=%s sig=%d' % (bin_path, hashlib.sha256(cd).hexdigest()[:16], len(sb)))
    if out_ipa:
        make_ipa(bundle, out_ipa)
    return cd


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
    ap.add_argument('profile')
    ap.add_argument('key')
    ap.add_argument('certs', nargs='+')
    ap.add_argument('--out')
    ap.add_argument('--ident')
    ap.add_argument('--team')
    ap.add_argument('--req')
    ap.add_argument('--ent-xml')
    ap.add_argument('--ent-der')
    a = ap.parse_args()
    sign_app(a.bundle, a.profile, a.key, a.certs, ident=a.ident, team=a.team, out_ipa=a.out,
             req_blob_path=a.req, ent_xml_path=a.ent_xml, ent_der_path=a.ent_der)
