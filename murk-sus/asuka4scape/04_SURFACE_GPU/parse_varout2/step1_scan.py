import sys, struct, array, json
sys.path.insert(0, "/home/femboychik/work/parse_varout2")
from kc import *

buf = DATA[TEXT_EXEC_OFF:TEXT_EXEC_OFF+TEXT_EXEC_SIZE]
a = array.array('I')
a.frombytes(buf)
n = len(a)
print("words:", n)

hits = []   # (va, kind, imm, rn, rt, rt2)
for i, w in enumerate(a):
    m = w & 0xFFC00000
    if m == 0xF9400000:      # LDR Xt,[Xn,#imm12]
        imm = (w >> 10) & 0xFFF
        if imm in (0x0E, 0x0F):
            rn = (w >> 5) & 0x1F
            rt = w & 0x1F
            hits.append((TEXT_EXEC_VA + i*4, 'ldr', imm*8, rn, rt, -1))
    elif m == 0xA9400000:    # LDP
        imm = (w >> 15) & 0x7F
        if imm in (0x0D, 0x0E, 0x0F):
            rt2 = (w >> 10) & 0x1F
            rn = (w >> 5) & 0x1F
            rt = w & 0x1F
            hits.append((TEXT_EXEC_VA + i*4, 'ldp', imm*8, rn, rt, rt2))
    elif m == 0xF9000000:    # STR
        imm = (w >> 10) & 0xFFF
        if imm in (0x0E, 0x0F):
            rn = (w >> 5) & 0x1F
            rt = w & 0x1F
            hits.append((TEXT_EXEC_VA + i*4, 'str', imm*8, rn, rt, -1))
    elif m == 0xA9000000:    # STP
        imm = (w >> 15) & 0x7F
        if imm in (0x0E, 0x0F):
            rt2 = (w >> 10) & 0x1F
            rn = (w >> 5) & 0x1F
            rt = w & 0x1F
            hits.append((TEXT_EXEC_VA + i*4, 'stp', imm*8, rn, rt, rt2))
    # unscaled LDUR/STUR imm9
    elif (w & 0xFFE00C00) == 0xF8400000:
        imm = (w >> 12) & 0x1FF
        if imm == 0x78:
            rn = (w >> 5) & 0x1F; rt = w & 0x1F
            hits.append((TEXT_EXEC_VA + i*4, 'ldur', imm, rn, rt, -1))
    elif (w & 0xFFE00C00) == 0xF8000000:
        imm = (w >> 12) & 0x1FF
        if imm == 0x78:
            rn = (w >> 5) & 0x1F; rt = w & 0x1F
            hits.append((TEXT_EXEC_VA + i*4, 'stur', imm, rn, rt, -1))

print("hits:", len(hits))
from collections import Counter
print(Counter(h[1] for h in hits))
print(Counter((h[1],h[2]) for h in hits))

with open("/home/femboychik/work/parse_varout2/hits_raw.txt","w") as f:
    for va,k,imm,rn,rt,rt2 in hits:
        f.write(f"{va:016x} {k} {imm:#x} rn=x{rn} rt=x{rt} rt2=x{rt2}\n")

json.dump(hits, open("/home/femboychik/work/parse_varout2/hits_raw.json","w"))

# how many are ldr 0x78 into a reg (the structureVariableOutputData read)
l78 = [h for h in hits if h[1]=='ldr' and h[2]==0x78]
print("ldr 0x78:", len(l78))
