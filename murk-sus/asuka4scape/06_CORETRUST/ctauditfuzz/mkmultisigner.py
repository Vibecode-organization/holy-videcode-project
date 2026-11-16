#!/usr/bin/env python3
"""Build a CMS with several signers over one CodeDirectory.

Each signer supplies its own cert chain; the hash-agility attributes are the
same (they describe the CodeDirectory, not the signer). Used to test whether
CoreTrust aggregates policy flags across SignerInfos.
"""
import sys, hashlib, plistlib, datetime
sys.path.insert(0, '/tmp/opencode')
from asn1crypto import cms, core, x509 as ax509
from cryptography.hazmat.primitives import hashes, serialization
from cryptography.hazmat.primitives.asymmetric import padding


def digest_info_sha256(d):
    return b'\x30\x2d\x06\x09\x60\x86\x48\x01\x65\x03\x04\x02\x01\x04\x20' + d


def attrs_for(cd):
    d = hashlib.sha256(cd).digest()
    xml = plistlib.dumps({'cdhashes': [d[:20]]}, fmt=plistlib.FMT_XML)
    a = [
        cms.CMSAttribute({'type': 'content_type', 'values': ['data']}),
        cms.CMSAttribute({'type': 'signing_time', 'values': [
            cms.Time({'utc_time': core.UTCTime(datetime.datetime.now(datetime.timezone.utc))})]}),
        cms.CMSAttribute({'type': 'message_digest', 'values': [d]}),
        cms.CMSAttribute({'type': '1.2.840.113635.100.9.1', 'values': [core.OctetString(xml)]}),
        cms.CMSAttribute({'type': '1.2.840.113635.100.9.2',
                          'values': [core.Sequence.load(digest_info_sha256(d))]}),
    ]
    return cms.CMSAttributes(sorted(a, key=lambda x: x.dump()))


def build(cd, signers):
    """signers: list of (key, [leaf, ...chain])"""
    signer_infos = []
    all_certs = []
    for key, chain in signers:
        attrs = attrs_for(cd)
        raw = attrs.dump()
        msg = b'\x31' + raw[1:] if raw[0] == 0xa0 else raw
        sig = key.sign(msg, padding.PKCS1v15(), hashes.SHA256())
        leaf = ax509.Certificate.load(chain[0].public_bytes(serialization.Encoding.DER))
        sid = cms.SignerIdentifier({'issuer_and_serial_number': cms.IssuerAndSerialNumber({
            'issuer': leaf.issuer, 'serial_number': leaf.serial_number})})
        signer_infos.append(cms.SignerInfo({
            'version': 'v1', 'sid': sid,
            'digest_algorithm': {'algorithm': 'sha256', 'parameters': core.Null()},
            'signed_attrs': attrs,
            'signature_algorithm': {'algorithm': 'rsassa_pkcs1v15', 'parameters': core.Null()},
            'signature': sig}))
        all_certs += [ax509.Certificate.load(c.public_bytes(serialization.Encoding.DER)) for c in chain]
    sd = cms.SignedData({
        'version': 'v1',
        'digest_algorithms': [{'algorithm': 'sha256', 'parameters': core.Null()}],
        'encap_content_info': {'content_type': 'data'},
        'certificates': cms.CertificateSet(all_certs),
        'signer_infos': signer_infos})
    return cms.ContentInfo({'content_type': 'signed_data', 'content': sd}).dump()
