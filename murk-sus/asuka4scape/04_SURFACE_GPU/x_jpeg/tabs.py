# scan kext __DATA_CONST/__DATA for IOExternalMethodDispatch arrays
import json, struct, sys
import xm

kmap = json.load(open('kmap.json'))
T = {e['id']: e for e in kmap}


def segs_of(kext):
    e = T[kext]
    return {s['name']: s for s in e['segs']}


def code_range(kext):
    s = segs_of(kext)['__TEXT_EXEC']
    return s['va'], s['va'] + s['fs']


def is_code(q, lo, hi):
    if not q:
        return 0
    t = xm.pac(q)
    return t if lo <= t < hi else 0


def scan(kext, stride, min_entries=3, extra_windows=()):
    sg = segs_of(kext)
    lo, hi = code_range(kext)
    res = []
    for name in ('__DATA_CONST', '__DATA') + tuple(extra_windows):
        s = sg.get(name)
        if not s or not s['fs']:
            continue
        n = s['fs']
        blob = xm.D[s['fo']:s['fo'] + n]
        for off in range(0, n - stride * min_entries, 8):
            hits = []
            i = 0
            while True:
                eo = off + i * stride
                if eo + stride > n:
                    break
                q = struct.unpack_from('<Q', blob, eo)[0]
                t = is_code(q, lo, hi)
                if not t:
                    break
                if stride == 0x18:
                    f = struct.unpack_from('<4i', blob, eo + 8)
                else:
                    f = struct.unpack_from('<4qI', blob, eo + 8)  # 4 x u64 + flags
                ok = all(-1 <= x <= 0x400000 for x in f[:4])
                if not ok:
                    break
                hits.append((s['va'] + eo, t, f))
                i += 1
            if len(hits) >= min_entries:
                res.append((len(hits), hits, stride))
    return res


if __name__ == '__main__':
    kext = sys.argv[1]
    for stride in (0x18, 0x28):
        r = scan(kext, stride)
        r.sort(key=lambda x: -x[0])
        print(f"== stride {stride:#x}: {len(r)} candidates")
        for n, hits, st in r[:8]:
            print(f"  n={n} base={hits[0][0]:#x} end={hits[-1][0]:#x}")
            for a, t, f in hits[:6]:
                print(f"     {a:#x} fn={t:#x} {f}")
