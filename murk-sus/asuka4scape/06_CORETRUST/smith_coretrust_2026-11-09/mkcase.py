#!/usr/bin/env python3
"""Generate a CoreTrust test case (CMS + CodeDirectory) with a fake chain."""
import sys, os, hashlib
sys.path.insert(0, '/home/femboychik/asuka4scape/06_CORETRUST/cttest')
sys.path.insert(0, '/tmp/opencode')
import mkct
from ctsign import build_cms
from cryptography.hazmat.primitives.asymmetric import rsa
from cryptography.hazmat.primitives import serialization

cd_path = sys.argv[1]
out = sys.argv[2]
root_cn, leaf_cn = sys.argv[3], sys.argv[4]
apple_ext = (len(sys.argv) > 5 and sys.argv[5] == '1')
root_key = rsa.generate_private_key(public_exponent=65537, key_size=2048)
leaf_key = rsa.generate_private_key(public_exponent=65537, key_size=2048)
root = mkct.make_root(root_cn, root_key)
leaf = mkct.make_leaf(leaf_cn, leaf_key, root, root_key, apple_ext)
cd = open(cd_path, 'rb').read()
cms = build_cms(cd, leaf_key, [leaf, root])
open(out + '.cms', 'wb').write(cms)
open(out + '.cd', 'wb').write(cd)
print(out, 'cms', len(cms), 'root', root_cn, 'leaf', leaf_cn, 'ext', apple_ext)
