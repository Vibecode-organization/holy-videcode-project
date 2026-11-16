import sys, json
sys.path.insert(0,'.')
import xr, k
from k import *

STR0=0xfffffff00789a748; STR1=STR0+0x33b7
# collect strings with va
d=DATA[va2off(STR0):va2off(STR0)+0x33b7]
strs={}
i=0
while i<len(d):
    if 32<=d[i]<127:
        j=d.index(b'\0',i); strs[STR0+i]=d[i:j].decode(); i=j+1
    else: i+=1

pairs = xr.resolve_adrp_pairs()
bytgt={}
for a,t,kind in pairs:
    bytgt.setdefault(t,[]).append((a,kind))

hits={}
for va,s in strs.items():
    if va in bytgt:
        hits[s]=(va,bytgt[va])
print("strings with direct addref:",len(hits))
for s,(va,refs) in sorted(hits.items()):
    print(f"{va:#x} {s!r:45s} " + " ".join(f"{a:#x}{k}" for a,k in refs))
