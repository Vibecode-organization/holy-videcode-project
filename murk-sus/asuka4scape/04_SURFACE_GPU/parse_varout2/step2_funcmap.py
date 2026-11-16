"""Build function-start map of __TEXT_EXEC: pacibsp-based prologues only.
Snap start down over a preceding 'bti c'. Also add bl targets that land exactly on a
pacibsp (already there) -> nothing extra needed.
"""
import sys, struct, array
sys.path.insert(0,"/home/femboychik/work/parse_varout2")
from kc import *

buf = DATA[TEXT_EXEC_OFF:TEXT_EXEC_OFF+TEXT_EXEC_SIZE]
a = array.array('I'); a.frombytes(buf)
PACIBSP, BTI_C = 0xD503237F, 0xD503245F

starts = []
for i, w in enumerate(a):
    if w == PACIBSP:
        va = TEXT_EXEC_VA + i*4
        o = va2off(va-4)
        if o is not None and struct.unpack_from("<I", DATA, o)[0] == BTI_C:
            va -= 4
        starts.append(va)
starts.sort()
offs = array.array('I', [s - TEXT_EXEC_VA for s in starts])
open("/home/femboychik/work/parse_varout2/funcstarts.bin","wb").write(offs.tobytes())
print("starts:", len(starts))
print("first:", [hex(x) for x in starts[:6]])
print("last:", [hex(x) for x in starts[-4:]])
# sanity: histogram of func sizes
import statistics
sizes = [starts[i+1]-starts[i] for i in range(len(starts)-1)]
print("median size", statistics.median(sizes), "mean", sum(sizes)/len(sizes), "max", max(sizes))
