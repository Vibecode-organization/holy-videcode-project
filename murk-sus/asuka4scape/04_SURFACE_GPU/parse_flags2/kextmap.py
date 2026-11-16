import re, struct
from kcd import data, SECTIONS
pva,psz,pfo = SECTIONS['__PRELINK_INFO']
blob = data[pfo:pfo+psz]
print("prelink info head:", blob[:120])
# try to find _PrelinkExecutableLoadAddr occurrences
print("count load addr key:", blob.count(b'_PrelinkExecutableLoadAddr'))
print("count identifier key:", blob.count(b'CFBundleIdentifier'))
print(blob[:2000].decode('utf-8','replace')[:2000])
