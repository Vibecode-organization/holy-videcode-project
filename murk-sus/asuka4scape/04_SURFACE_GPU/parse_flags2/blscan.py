import struct, collections, pickle
from kcd import data, SECTIONS
tva,tsz,tfo = SECTIONS['__TEXT_EXEC']
words = struct.unpack_from('<%dI'%(tsz//4), data, tfo)
N=len(words)
cnt = collections.Counter()
for i in range(N):
    w = words[i]
    if (w & 0xFC000000) == 0x94000000:   # bl
        imm = w & 0x3FFFFFF
        if imm & 0x2000000: imm -= 0x4000000
        cnt[tva + i*4 + imm*4] += 1
pickle.dump(dict(cnt), open('bl_targets.pkl','wb'))
print("distinct bl targets:", len(cnt))
for t in (0xfffffff008fd0ee4,):
    print(f"0x{t:x}: {cnt.get(t,0)} callers")
# who calls anything in the dispatcher A function region? find function start instead:
# print targets near 0x8fd0e00-0x8fd0f10 and 0x8fc0000-0x8fcff00 top counts
near = sorted([(k,v) for k,v in cnt.items() if 0xfffffff008fcf000<=k<=0xfffffff008fd0f20])
for k,v in near: print(f"  target 0x{k:x} x{v}")
