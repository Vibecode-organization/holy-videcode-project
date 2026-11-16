#!/usr/bin/env python3
"""CodeResources with every non-executable top-level file. usage: App.app"""
import sys,os,plistlib,hashlib
app=sys.argv[1]
try:
    info=plistlib.load(open(os.path.join(app,'Info.plist'),'rb'))
except Exception:
    info={}
exe=info.get('CFBundleExecutable','')
files={}; files2={}
for f in sorted(os.listdir(app)):
    p=os.path.join(app,f)
    if f=='_CodeSignature' or f==exe or not os.path.isfile(p): continue
    d=open(p,'rb').read()
    files[f]={'hash':hashlib.sha1(d).digest()}
    files2[f]={'hash2':hashlib.sha256(d).digest()}
rules={"^.*":True,"^_CodeSignature/":{"omit":True,"weight":1}}
cr={'files':files,'files2':files2,'rules':rules,'rules2':rules}
os.makedirs(os.path.join(app,'_CodeSignature'),exist_ok=True)
out=os.path.join(app,'_CodeSignature','CodeResources')
open(out,'wb').write(plistlib.dumps(cr,fmt=plistlib.FMT_BINARY))
print(out,len(open(out,'rb').read()),list(files))
