#!/usr/bin/env python3
"""Build a single-signer CMS blob (with Apple hash-agility attributes) for
CoreTrust evaluation, plus a self-signed Apple-like CA/leaf chain.

Usage: mkct.py <cd_blob> <out_prefix> <root_cn> <leaf_cn> [ext]
"""
import sys, os, hashlib, plistlib, datetime
from cryptography import x509
from cryptography.x509.oid import NameOID, ObjectIdentifier, ExtendedKeyUsageOID
from cryptography.hazmat.primitives import hashes, serialization
from cryptography.hazmat.primitives.asymmetric import rsa, padding
from asn1crypto import cms, core, x509 as a_x509

DERTemplate = bytes([
    0x30,0x1D, 0x06,0x05,0x2B,0x0E,0x03,0x02,0x1A, 0x04,0x14,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0x30,0x2D, 0x06,0x09,0x60,0x86,0x48,0x01,0x65,0x03,0x04,0x02,0x01, 0x04,0x20,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,
])
SHA1_OFF = 11
SHA256_OFF = 46

def make_root(cn, key):
    name = x509.Name([
        x509.NameAttribute(NameOID.COUNTRY_NAME, "US"),
        x509.NameAttribute(NameOID.ORGANIZATION_NAME, "Apple Inc."),
        x509.NameAttribute(NameOID.ORGANIZATIONAL_UNIT_NAME, "Certification Authority"),
        x509.NameAttribute(NameOID.COMMON_NAME, cn),
    ])
    now = datetime.datetime(2020, 1, 1, tzinfo=datetime.timezone.utc)
    cert = (x509.CertificateBuilder()
            .subject_name(name).issuer_name(name)
            .public_key(key.public_key())
            .serial_number(0x0102030405060708090a0b0c0d0e0f10)
            .not_valid_before(now)
            .not_valid_after(datetime.datetime(2033, 1, 1, tzinfo=datetime.timezone.utc))
            .add_extension(x509.BasicConstraints(ca=True, path_length=None), critical=True)
            .sign(key, hashes.SHA256()))
    return cert

def make_leaf(cn, key, root_cert, root_key, apple_ext):
    name = x509.Name([
        x509.NameAttribute(NameOID.COUNTRY_NAME, "US"),
        x509.NameAttribute(NameOID.ORGANIZATION_NAME, "Test"),
        x509.NameAttribute(NameOID.COMMON_NAME, cn),
    ])
    now = datetime.datetime(2020, 1, 1, tzinfo=datetime.timezone.utc)
    b = (x509.CertificateBuilder()
         .subject_name(name).issuer_name(root_cert.subject)
         .public_key(key.public_key())
         .serial_number(0x0102030405060708090a0b0c0d0e0f10)
         .not_valid_before(now)
         .not_valid_after(datetime.datetime(2033, 1, 1, tzinfo=datetime.timezone.utc))
         .add_extension(x509.BasicConstraints(ca=False, path_length=None), critical=True)
         .add_extension(x509.KeyUsage(digital_signature=True, content_commitment=False,
                                      key_encipherment=False, data_encipherment=False,
                                      key_agreement=False, key_cert_sign=False,
                                      crl_sign=False, encipher_only=False,
                                      decipher_only=False), critical=True)
         .add_extension(x509.ExtendedKeyUsage([ExtendedKeyUsageOID.CODE_SIGNING]), critical=False))
    if apple_ext:
        b = b.add_extension(x509.UnrecognizedExtension(
            ObjectIdentifier("1.2.840.113635.100.6.1.2"), b"\x05\x00"), critical=False)
    return b.sign(root_key, hashes.SHA256())

def build_hashes(prefix, root_cn, leaf_cn, apple_ext, sha1_hash, sha256_hash, message_digest):
    sha1 = sha1_hash
    sha256 = sha256_hash
    der = bytearray(DERTemplate)
    der[SHA1_OFF:SHA1_OFF+20] = sha1
    der[SHA256_OFF:SHA256_OFF+32] = sha256
    xml = plistlib.dumps({'cdhashes': [sha1, sha256[:20]]}, fmt=plistlib.FMT_XML)

    root_key = rsa.generate_private_key(public_exponent=65537, key_size=2048)
    leaf_key = rsa.generate_private_key(public_exponent=65537, key_size=2048)
    root = make_root(root_cn, root_key)
    leaf = make_leaf(leaf_cn, leaf_key, root, root_key, apple_ext)
    root_asn1 = a_x509.Certificate.load(root.public_bytes(serialization.Encoding.DER))
    leaf_asn1 = a_x509.Certificate.load(leaf.public_bytes(serialization.Encoding.DER))

    attrs = cms.CMSAttributes([
        cms.CMSAttribute({'type': 'content_type', 'values': ['data']}),
        cms.CMSAttribute({'type': 'message_digest', 'values': [message_digest]}),
        cms.CMSAttribute({'type': '1.2.840.113635.100.9.1', 'values': [core.OctetString(xml)]}),
        cms.CMSAttribute({'type': '1.2.840.113635.100.9.2', 'values': [
            core.SequenceOf.load(b'\x30\x4e' + bytes(der)),
        ]}),
    ])
    # DER SET OF sorting: order by encoded attribute bytes
    items = [a for a in attrs]
    items.sort(key=lambda a: a.dump())
    attrs = cms.CMSAttributes(items)

    signed_der = attrs.dump()
    if signed_der[0] == 0xA0:
        signed_der = b'\x31' + signed_der[1:]
    sig = leaf_key.sign(signed_der, padding.PKCS1v15(), hashes.SHA256())

    sid = cms.SignerIdentifier({'issuer_and_serial_number': cms.IssuerAndSerialNumber({
        'issuer': leaf_asn1.issuer,
        'serial_number': leaf_asn1.serial_number,
    })})
    si = cms.SignerInfo({
        'version': 'v1',
        'sid': sid,
        'digest_algorithm': {'algorithm': 'sha256', 'parameters': core.Null()},
        'signed_attrs': attrs,
        'signature_algorithm': {'algorithm': '1.2.840.113549.1.1.11', 'parameters': core.Null()},
        'signature': sig,
    })
    sd = cms.SignedData({
        'version': 'v1',
        'digest_algorithms': [{'algorithm': 'sha256', 'parameters': core.Null()}],
        'encap_content_info': {'content_type': 'data'},
        'certificates': cms.CertificateSet([leaf_asn1, root_asn1]),
        'signer_infos': [si],
    })
    ci = cms.ContentInfo({'content_type': 'signed_data', 'content': sd})
    cms_der = ci.dump()

    open(prefix + '.cms', 'wb').write(cms_der)
    open(prefix + '.root.pem', 'wb').write(root.public_bytes(serialization.Encoding.PEM))
    open(prefix + '.leaf.pem', 'wb').write(leaf.public_bytes(serialization.Encoding.PEM))
    print(prefix, 'cms', len(cms_der), 'sha1', sha1.hex(), 'sha256', sha256.hex())

def build(cd_path, prefix, root_cn, leaf_cn, apple_ext):
    cd = open(cd_path, 'rb').read()
    build_hashes(prefix, root_cn, leaf_cn, apple_ext,
                 hashlib.sha1(cd).digest(), hashlib.sha256(cd).digest(), hashlib.sha256(cd).digest())

if __name__ == '__main__':
    if len(sys.argv) < 5:
        print(__doc__); sys.exit(1)
    build(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4], len(sys.argv) > 5)
