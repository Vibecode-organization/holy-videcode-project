#!/usr/bin/env python3
"""Build a fake Apple App Store chain (root -> iPhone CA -> iPhone OS Application Signing)
with Apple's exact subject names, key usages and marker OIDs, and sign an app with it."""
import sys, os, datetime
sys.path.insert(0, '/tmp/opencode')
sys.path.insert(0, '/home/femboychik/asuka4scape/06_CORETRUST/cttest')
import mkcase2, ctsign
from cryptography import x509
from cryptography.x509.oid import NameOID, ExtendedKeyUsageOID, ObjectIdentifier
from cryptography.hazmat.primitives.asymmetric import rsa
from cryptography.hazmat.primitives import hashes, serialization

OID_APPSTORE = ObjectIdentifier('1.2.840.113635.100.6.1.3')
OID_CA = ObjectIdentifier('1.2.840.113635.100.6.2.18')
UTC = datetime.timezone.utc
NB = datetime.datetime(2020, 1, 1, tzinfo=UTC)
NA = datetime.datetime(2033, 1, 1, tzinfo=UTC)


def name(cn, ou, o, c='US'):
    return x509.Name([
        x509.NameAttribute(NameOID.COUNTRY_NAME, c),
        x509.NameAttribute(NameOID.ORGANIZATION_NAME, o),
        x509.NameAttribute(NameOID.ORGANIZATIONAL_UNIT_NAME, ou),
        x509.NameAttribute(NameOID.COMMON_NAME, cn),
    ])


def build(subject, issuer, pubkey, signer_key, ca, exts, serial):
    b = (x509.CertificateBuilder().subject_name(subject).issuer_name(issuer)
         .public_key(pubkey).serial_number(serial)
         .not_valid_before(NB).not_valid_after(NA)
         .add_extension(x509.BasicConstraints(ca=ca, path_length=None), critical=True)
         .add_extension(x509.KeyUsage(digital_signature=not ca, content_commitment=False,
                                      key_encipherment=False, data_encipherment=False,
                                      key_agreement=False, key_cert_sign=ca, crl_sign=ca,
                                      encipher_only=False, decipher_only=False), critical=True))
    if not ca:
        b = b.add_extension(x509.ExtendedKeyUsage([ExtendedKeyUsageOID.CODE_SIGNING]), critical=False)
    for oid in exts:
        b = b.add_extension(x509.UnrecognizedExtension(oid, b'\x05\x00'), critical=False)
    return b.sign(signer_key, hashes.SHA256())


def main(outdir):
    os.makedirs(outdir, exist_ok=True)
    root_key = rsa.generate_private_key(public_exponent=65537, key_size=2048)
    ca_key = rsa.generate_private_key(public_exponent=65537, key_size=2048)
    leaf_key = rsa.generate_private_key(public_exponent=65537, key_size=2048)

    root_n = name('Apple Root CA', 'Apple Certification Authority', 'Apple Inc.')
    ca_n = name('Apple iPhone Certification Authority', 'Certification Authority', 'Apple Inc.')
    leaf_n = name('Apple iPhone OS Application Signing', 'iPhone', 'Apple Inc.')

    root = build(root_n, root_n, root_key.public_key(), root_key, True, [], 1)
    ca = build(ca_n, root_n, ca_key.public_key(), root_key, True, [OID_CA], 2)
    leaf = build(leaf_n, ca_n, leaf_key.public_key(), ca_key, False, [OID_APPSTORE], 3)

    root_der = mkcase2.resign_no_params(root, root_key, 'sha1')
    ca_der = mkcase2.resign_no_params(ca, root_key, 'sha256')
    leaf_der = mkcase2.resign_no_params(leaf, ca_key, 'sha256')
    open(os.path.join(outdir, 'leaf.der'), 'wb').write(leaf_der)
    open(os.path.join(outdir, 'ca.der'), 'wb').write(ca_der)
    open(os.path.join(outdir, 'root.der'), 'wb').write(root_der)
    open(os.path.join(outdir, 'leaf.key'), 'wb').write(
        leaf_key.private_bytes(serialization.Encoding.DER,
                               serialization.PrivateFormat.PKCS8,
                               serialization.NoEncryption()))
    print('chain built:', leaf_n.rfc4514_string(), '<-', ca_n.rfc4514_string(), '<-', root_n.rfc4514_string())
    return outdir


if __name__ == '__main__':
    main(sys.argv[1])
