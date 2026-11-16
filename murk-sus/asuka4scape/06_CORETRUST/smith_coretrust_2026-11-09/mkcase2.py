#!/usr/bin/env python3
"""Generate a CoreTrust test case with a fake chain whose cert signatures use
absent AlgorithmIdentifier parameters (Apple's encoding) instead of NULL."""
import sys, os
sys.path.insert(0, '/home/femboychik/asuka4scape/06_CORETRUST/cttest')
sys.path.insert(0, '/tmp/opencode')
import mkct
from ctsign import build_cms
from cryptography.hazmat.primitives.asymmetric import rsa
from cryptography.hazmat.primitives import hashes, serialization
from cryptography.hazmat.primitives.asymmetric import padding
from asn1crypto import x509 as ax509, algos

ALG = {'sha256': ('sha256_rsa', hashes.SHA256()), 'sha1': ('sha1_rsa', hashes.SHA1())}


def resign_no_params(cert, signer_key, hash_name='sha256'):
    name, h = ALG[hash_name]
    der = cert.public_bytes(serialization.Encoding.DER)
    a = ax509.Certificate.load(der)
    tbs = a['tbs_certificate']
    tbs['signature'] = algos.SignedDigestAlgorithm({'algorithm': name})
    sig = signer_key.sign(tbs.dump(), padding.PKCS1v15(), h)
    a['signature_algorithm'] = algos.SignedDigestAlgorithm({'algorithm': name})
    a['signature_value'] = sig
    return a.dump()


def main():
    cd_path, out, root_cn, leaf_cn, ext = sys.argv[1:6]
    apple_ext = ext == '1'
    rk = rsa.generate_private_key(public_exponent=65537, key_size=2048)
    lk = rsa.generate_private_key(public_exponent=65537, key_size=2048)
    root = mkct.make_root(root_cn, rk)
    leaf = mkct.make_leaf(leaf_cn, lk, root, rk, apple_ext)
    root_der = resign_no_params(root, rk, 'sha1')
    leaf_der = resign_no_params(leaf, rk, 'sha256')
    from cryptography import x509
    root2 = x509.load_der_x509_certificate(root_der)
    leaf2 = x509.load_der_x509_certificate(leaf_der)
    assert root2.public_key().public_numbers() == root.public_key().public_numbers()
    cd = open(cd_path, 'rb').read()
    cms = build_cms(cd, lk, [leaf2, root2])
    open(out + '.cms', 'wb').write(cms)
    open(out + '.cd', 'wb').write(cd)
    print(out, 'cms', len(cms), 'root', root_cn, 'leaf', leaf_cn, 'ext', apple_ext)


if __name__ == '__main__':
    main()
