#!/usr/bin/env python3
"""Create _CodeSignature/CodeResources for a minimal .app.
usage: make_coderesources.py App.app
Writes App.app/_CodeSignature/CodeResources (binary plist).
"""
import sys, os, plistlib, hashlib
def h(p, alg):
    d=open(p,'rb').read(); return alg(d).digest()
app=sys.argv[1]
info=os.path.join(app,'Info.plist')
s1=h(info, hashlib.sha1); s256=h(info, hashlib.sha256)
rules={"^.*": True, "^_CodeSignature/": {"omit": True, "weight": 1}}
cr={"files": {"Info.plist": {"hash": s1}},
    "files2": {"Info.plist": {"hash2": s256}},
    "rules": rules, "rules2": rules}
os.makedirs(os.path.join(app,'_CodeSignature'), exist_ok=True)
out=os.path.join(app,'_CodeSignature','CodeResources')
open(out,'wb').write(plistlib.dumps(cr, fmt=plistlib.FMT_BINARY))
print(out, len(open(out,'rb').read()))
