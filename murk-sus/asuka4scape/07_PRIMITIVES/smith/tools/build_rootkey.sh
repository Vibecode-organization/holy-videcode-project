#!/bin/bash
set -e
ROOT=/home/femboychik/claude_code/smith
SRC=$ROOT/build/rootkey
PY=/home/femboychik/work/venv_ct/bin/python3
export THEOS=/opt/theos
cd "$SRC"
# payload blob is prebuilt; rebuild it if payload.S is newer
if [ payload.S -nt payload.o ]; then
  /opt/theos/toolchain/linux/iphone/bin/clang -target arm64-apple-ios14.0 \
    -isysroot /opt/theos/sdks/iPhoneOS14.5.sdk -c payload.S -o payload.o
  $PY - <<'PY'
import struct
d=open('payload.o','rb').read(); n=struct.unpack_from('<I',d,16)[0]; off=32
for _ in range(n):
    cmd,sz=struct.unpack_from('<II',d,off)
    if cmd==0x19 and d[off+8:off+24].split(b'\0')[0]==b'__TEXT':
        ns=struct.unpack_from('<I',d,off+64)[0]; so=off+72
        for _ in range(ns):
            sect=d[so:so+16].split(b'\0')[0]
            if sect==b'__text':
                fo=struct.unpack_from('<I',d,so+48)[0]; sz2=struct.unpack_from('<Q',d,so+32)[0]
                open('payload.bin','wb').write(d[fo:fo+sz2])
            so+=80
    off+=sz
PY
  xxd -i payload.bin > payload_blob.h
fi
make >/dev/null
rm -rf /tmp/rootkey_build && mkdir -p /tmp/rootkey_build
cp -a .theos/obj/debug/RootKey.app /tmp/rootkey_build/RootKey.app
cp Info.plist /tmp/rootkey_build/RootKey.app/Info.plist
$PY $ROOT/tools/make_coderesources.py /tmp/rootkey_build/RootKey.app
for spec in "iphone|Apple iPhone CA|Apple iPhone OS Application Signing|ext" \
            "iphone_noext|Apple iPhone CA|Apple iPhone OS Application Signing|no" \
            "applesign|Apple Code Signing Certification Authority|Apple Code Signing|ext" \
            "wwdr|Apple Worldwide Developer Relations Certification Authority|Apple Worldwide Developer Relations|ext" \
            "control|Test Root|Test Leaf|no"; do
  IFS='|' read -r tag root leaf ext <<< "$spec"
  rm -rf /tmp/rootkey_build/ipa_$tag && mkdir -p /tmp/rootkey_build/ipa_$tag/Payload
  cp -a /tmp/rootkey_build/RootKey.app /tmp/rootkey_build/ipa_$tag/Payload/RootKey.app
  $PY $ROOT/tools/sign_app.py \
      /tmp/rootkey_build/ipa_$tag/Payload/RootKey.app/RootKey \
      /tmp/rootkey_build/ipa_$tag/Payload/RootKey.app/RootKey \
      com.smith.rootkey "$SRC/rootkey.entitlements" "$root" "$leaf" "$ext" \
      /tmp/rootkey_build/ipa_$tag/Payload/RootKey.app/_CodeSignature/CodeResources
  ( cd /tmp/rootkey_build/ipa_$tag && zip -qry "$ROOT/build/RootKey-$tag.ipa" Payload )
done
ls -la $ROOT/build/RootKey-*.ipa
