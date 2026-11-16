#!/usr/bin/env python3
"""Каталог vtable-кандидатов в kernel __DATA_CONST (iPhone14,7 / 24B115).

Зачем: если userland-селектор сливает PAC-подписанный указатель (q0), то низкие
32 бита сохраняют смещение. Сопоставив (q0 & 0xffffffff) + KB с каталогом,
можно мгновенно назвать класс объекта и получить slide.

Формат: python3 vtables.py <kernelcache> [min_run]
Вход: распакованный kernelcache (MH_FILESET, arm64e) — 02_KERNEL/diff_267_272/...
Выход: stdout, строки "va count" для серий >= min_run.

Проверено на 24B115: 8683 серии >= 8.
Дополнительно: pipe в grep по низким 32 битам лика:
    python3 vtables.py kc.bin | awk -v q=<low32> '$1 ~ ...'
проще: посчитать target = 0xfffffff007004000 + (q0 & 0xffffffff) и искать его в выводе.
"""
import struct
import sys

KB = 0xfffffff007004000
KT_LO, KT_HI = 0xfffffff00a1cc000, 0xfffffff00aa88000  # com.apple.kernel __TEXT_EXEC


def load(path):
    d = open(path, "rb").read()
    n = struct.unpack_from("<I", d, 16)[0]
    off, segs = 32, []
    for _ in range(n):
        cmd, sz = struct.unpack_from("<II", d, off)
        if cmd == 0x19:  # LC_SEGMENT_64
            name = d[off + 8:off + 24].rstrip(b"\0").decode(errors="replace")
            va, vs, fo, fs = struct.unpack_from("<QQQQ", d, off + 24)
            segs.append((name, va, vs, fo, fs))
        off += sz
    return d, segs


def main():
    path = sys.argv[1]
    min_run = int(sys.argv[2]) if len(sys.argv) > 2 else 8
    d, segs = load(path)
    dc = d  # kernelcache: __DATA_CONST лежит внутри файла
    name, va0, vsz, fo, fsz = next(s for s in segs if s[0] == "__DATA_CONST")

    def q(o):
        return struct.unpack_from("<Q", dc, o)[0]

    def tgt(v):
        if v >> 63:
            return KB + (v & 0xffffffff)
        if (v >> 62) & 1:
            return KB + (v & 0x3ffffffff)
        return v

    runs, cur = [], None
    for o in range(fo, fo + fsz - 8, 8):
        v = q(o)
        ok = ((v >> 63) or ((v >> 62) & 1)) and KT_LO <= tgt(v) < KT_HI
        if ok:
            cur = [o, o] if cur is None else [cur[0], o]
        else:
            if cur and (cur[1] - cur[0]) // 8 + 1 >= min_run:
                runs.append((va0 + (cur[0] - fo), (cur[1] - cur[0]) // 8 + 1))
            cur = None
    if cur and (cur[1] - cur[0]) // 8 + 1 >= min_run:
        runs.append((va0 + (cur[0] - fo), (cur[1] - cur[0]) // 8 + 1))

    for a, n in runs:
        print("%#x %d" % (a, n))


if __name__ == "__main__":
    main()
