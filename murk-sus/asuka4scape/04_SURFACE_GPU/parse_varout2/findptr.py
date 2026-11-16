import sys, json, struct
sys.path.insert(0,"/home/femboychik/work/parse_varout2")
from kc import *

def find_ptr(target):
    low = (target - BASE) & 0x0FFFFFFF
    out=[]
    for name in ("__DATA_CONST","__DATA","__PRELINK_INFO","__TEXT"):
        va,off,size = SEGS[name]
        buf = DATA[off:off+size]
        for i in range(0, size-8, 8):
            qq = struct.unpack_from("<Q", buf, i)[0]
            if (qq & 0x0FFFFFFF) == low and (qq>>60)==8:
                out.append((va+i, qq))
    return out

if __name__ == "__main__":
    for a in sys.argv[1:]:
        t=int(a,16)
        r=find_ptr(t)
        print(hex(t), [(hex(x),hex(qq)) for x,qq in r][:6], len(r))
