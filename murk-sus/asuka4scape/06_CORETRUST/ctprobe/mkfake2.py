#!/usr/bin/env python3
"""Build a fake Apple provisioning profile (plist + DER-Encoded-Profile), CMS-signed
with a self-signed 'Apple iPhone OS Provisioning Profile Signing' chain."""
import sys, os, plistlib, datetime, hashlib, uuid as uuidlib
sys.path.insert(0, '/home/femboychik/work/cttest')
from asn1crypto import cms, core, x509 as ax509
from cryptography import x509
from cryptography.hazmat.primitives import hashes, serialization
from cryptography.hazmat.primitives.asymmetric import padding, rsa

SRC = sys.argv[1] if len(sys.argv) > 1 else '/tmp/dump3/own/embedded.mobileprovision'
OUT = sys.argv[2] if len(sys.argv) > 2 else '/home/femboychik/Документы/fake.mobileprovision'
APPID = sys.argv[3] if len(sys.argv) > 3 else None


def der_len(n):
    if n < 0x80:
        return bytes([n])
    b = n.to_bytes((n.bit_length() + 7) // 8, 'big')
    return bytes([0x80 | len(b)]) + b


def tlv(tag, body):
    return bytes([tag]) + der_len(len(body)) + body


def enc_val(v):
    if isinstance(v, bool):
        return tlv(0x01, b'\xff' if v else b'\x00')
    if isinstance(v, int):
        return tlv(0x02, v.to_bytes(max(1, (v.bit_length() + 8) // 8), 'big', signed=True))
    if isinstance(v, str):
        return tlv(0x0c, v.encode())
    if isinstance(v, bytes):
        return tlv(0x04, v)
    if isinstance(v, datetime.datetime):
        return tlv(0x17, v.strftime('%y%m%d%H%M%SZ').encode())
    if isinstance(v, (list, tuple)):
        return tlv(0x30, b''.join(enc_val(x) for x in v))
    if isinstance(v, dict):
        entries = b''.join(tlv(0x30, tlv(0x0c, k.encode()) + enc_val(v[k])) for k in sorted(v))
        return tlv(0x70, b'\x02\x01\x01' + tlv(0xb0, entries))
    raise TypeError(type(v))


DER_ORDER = ['Version', 'TimeToLive', 'TeamName', 'IsXcodeManaged', 'LocalProvision',
             'AppIDName', 'CreationDate', 'TeamIdentifier', 'ExpirationDate', 'Platform',
             'ProfileDistributionType', 'ApplicationIdentifierPrefix', 'UUID',
             'ProvisionedDevices', 'DeveloperCertificates', 'Name', 'Entitlements']


def enc_profile(pl):
    src = dict(pl)
    if 'ProfileDistributionType' not in src:
        src['ProfileDistributionType'] = 'LIMITED'
    if 'DeveloperCertificates' in src:
        src['DeveloperCertificates'] = [hashlib.sha256(c).digest()
                                        for c in src['DeveloperCertificates']]
    entries = b''
    for k in DER_ORDER:
        if k in src:
            entries += tlv(0x30, tlv(0x0c, k.encode()) + enc_val(src[k]))
    for k in src:
        if k not in DER_ORDER:
            entries += tlv(0x30, tlv(0x0c, k.encode()) + enc_val(src[k]))
    return tlv(0x31, entries)


def make_cms(content, leaf_key, leaf_cert, root_cert, sign_time):
    md = hashlib.sha256(content).digest()
    attrs = cms.CMSAttributes([
        cms.CMSAttribute({'type': 'content_type', 'values': ['data']}),
        cms.CMSAttribute({'type': 'message_digest', 'values': [md]}),
        cms.CMSAttribute({'type': 'signing_time', 'values': [
            cms.Time({'utc_time': core.UTCTime(sign_time)})]}),
    ])
    items = sorted([a for a in attrs], key=lambda a: a.dump())
    attrs = cms.CMSAttributes(items)
    raw = attrs.dump()
    signed = b'\x31' + raw[1:] if raw[0] == 0xA0 else raw
    sig = leaf_key.sign(signed, padding.PKCS1v15(), hashes.SHA256())
    leaf_asn1 = ax509.Certificate.load(leaf_cert.public_bytes(serialization.Encoding.DER))
    root_asn1 = ax509.Certificate.load(root_cert.public_bytes(serialization.Encoding.DER))
    sid = cms.SignerIdentifier({'issuer_and_serial_number': cms.IssuerAndSerialNumber({
        'issuer': leaf_asn1.issuer, 'serial_number': leaf_asn1.serial_number})})
    si = cms.SignerInfo({
        'version': 'v1', 'sid': sid,
        'digest_algorithm': {'algorithm': 'sha256', 'parameters': core.Null()},
        'signed_attrs': attrs,
        'signature_algorithm': {'algorithm': 'sha256_rsa', 'parameters': core.Null()},
        'signature': sig})
    sd = cms.SignedData({
        'version': 'v1',
        'digest_algorithms': [{'algorithm': 'sha256', 'parameters': core.Null()}],
        'encap_content_info': {'content_type': 'data', 'content': content},
        'certificates': cms.CertificateSet([root_asn1, leaf_asn1]),
        'signer_infos': [si]})
    return cms.ContentInfo({'content_type': 'signed_data', 'content': sd}).dump()


def main():
    d = open(SRC, 'rb').read()
    ci = cms.ContentInfo.load(d)
    sd = ci['content']
    pl = plistlib.loads(sd['encap_content_info']['content'].native)
    if APPID:
        ent = dict(pl['Entitlements'])
        old = ent['application-identifier']
        ent['application-identifier'] = APPID
        if 'com.apple.security.application-groups' in ent:
            ent['com.apple.security.application-groups'] = [
                'group.' + APPID.split('.', 1)[1]]
        pl['Entitlements'] = ent
    ent = dict(pl['Entitlements'])
    ent.update({
        'platform-application': True,
        'com.apple.private.security.no-sandbox': True,
        'com.apple.private.security.no-container': True,
        'com.apple.private.security.container-required': False,
        'get-task-allow': True,
        'task_for_pid-allow': True,
    })
    pl['Entitlements'] = ent
    pl['Name'] = 'iOS Team Provisioning Profile: %s (CT)' % ent['application-identifier'].split('.', 1)[1]
    pl['UUID'] = '6d1a4f2b-8c3e-4d5a-9b7f-2e1c0a9d8b7c'
    pl['ExpirationDate'] = datetime.datetime(2027, 11, 3, 12, 0, 0)
    pl['CreationDate'] = datetime.datetime(2026, 11, 3, 12, 0, 0)
    pl['TimeToLive'] = 365
    pl.pop('DER-Encoded-Profile', None)

    # fake Apple-like chain
    now = datetime.datetime(2026, 1, 1, tzinfo=datetime.timezone.utc)
    root_key = rsa.generate_private_key(public_exponent=65537, key_size=2048)
    leaf_key = rsa.generate_private_key(public_exponent=65537, key_size=2048)
    root_name = x509.Name([
        x509.NameAttribute(x509.oid.NameOID.COUNTRY_NAME, 'US'),
        x509.NameAttribute(x509.oid.NameOID.ORGANIZATION_NAME, 'Apple Inc.'),
        x509.NameAttribute(x509.oid.NameOID.ORGANIZATIONAL_UNIT_NAME, 'Certification Authority'),
        x509.NameAttribute(x509.oid.NameOID.COMMON_NAME, 'Apple iPhone Certification Authority')])
    root = (x509.CertificateBuilder().subject_name(root_name).issuer_name(root_name)
            .public_key(root_key.public_key()).serial_number(0x1111111111111111)
            .not_valid_before(now).not_valid_after(datetime.datetime(2030, 12, 31, tzinfo=datetime.timezone.utc))
            .add_extension(x509.BasicConstraints(ca=True, path_length=None), critical=True)
            .sign(root_key, hashes.SHA256()))
    leaf_name = x509.Name([
        x509.NameAttribute(x509.oid.NameOID.COUNTRY_NAME, 'US'),
        x509.NameAttribute(x509.oid.NameOID.ORGANIZATION_NAME, 'Apple Inc.'),
        x509.NameAttribute(x509.oid.NameOID.COMMON_NAME, 'Apple iPhone OS Provisioning Profile Signing')])
    leaf = (x509.CertificateBuilder().subject_name(leaf_name).issuer_name(root_name)
            .public_key(leaf_key.public_key()).serial_number(0x2222222222222222)
            .not_valid_before(now).not_valid_after(datetime.datetime(2030, 12, 31, tzinfo=datetime.timezone.utc))
            .add_extension(x509.BasicConstraints(ca=False, path_length=None), critical=True)
            .add_extension(x509.KeyUsage(digital_signature=True, content_commitment=False,
                                         key_encipherment=False, data_encipherment=False,
                                         key_agreement=False, key_cert_sign=False, crl_sign=False,
                                         encipher_only=False, decipher_only=False), critical=True)
            .sign(root_key, hashes.SHA256()))

    sign_time = datetime.datetime(2026, 11, 3, 12, 0, 0, tzinfo=datetime.timezone.utc)
    der_profile = enc_profile(pl)
    inner_cms = make_cms(der_profile, leaf_key, leaf, root, sign_time)
    pl['DER-Encoded-Profile'] = inner_cms

    content = plistlib.dumps(pl, fmt=plistlib.FMT_XML, sort_keys=False)
    outer = make_cms(content, leaf_key, leaf, root, sign_time)
    open(OUT, 'wb').write(outer)
    print('wrote', OUT, len(outer), 'der_profile', len(der_profile), 'inner', len(inner_cms))
    print('appid', ent['application-identifier'])
    print('ents', sorted(ent))
    return pl


if __name__ == '__main__':
    main()
