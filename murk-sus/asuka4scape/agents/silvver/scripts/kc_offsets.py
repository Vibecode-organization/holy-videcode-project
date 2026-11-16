#!/usr/bin/env python3
"""kc_offsets.py — VA -> file offset для распакованного kernelcache (MH_MAGIC_64 / MH_FILESET)
и дизассемблирование окна вокруг адреса. Без Ghidra, только stdlib + capstone.

Зачем: 123.rep (Ghidra DB, ~1 ГБ) текстом читать нельзя, а сам кернелкэш лежит в архиве
как обычный Mach-O: 02_KERNEL/diff_267_272/kernelcache.27.2RC.24B115.iphone14b (64.1 MB).
Этого достаточно для статики по конкретным адресам.

Проверено на 24B115 / iPhone14,7:
  __TEXT         va=0xfffffff007004000 off=0x0
  __PRELINK_TEXT va=0xfffffff00700c000 off=0x8000
  __DATA_CONST   va=0xfffffff007bb8000 off=0xbb4000
  __TEXT_EXEC    va=0xfffffff00814c000 off=0x1148000
  VA->off: off = 0x1148000 + (VA - 0xfffffff00814c000)

Использование:
  python3 kc_offsets.py kc.bin 0xfffffff00a21347c 0xfffffff00a2af7c8
  python3 kc_offsets.py kc.bin --off 0x320f47c --n 40        # дизасм по оффсету

Зависимости: pip install capstone (проверено на 5.0.7). Есть fallback на aarch64-linux-gnu-objdump.
"""
import struct
import subprocess
import sys

LC_SEGMENT_64 = 0x19
LC_FILESET_ENTRY = 0x80000035


def parse_segments(path, depth=0, base=0, prefix="", maxdepth=3):
    with open(path, "rb") as f:
        f.seek(base)
        d = f.read(32)
        if len(d) < 32:
            return []
        magic, cpu, sub, ft, ncmds, sz, flags, res = struct.unpack_from("<IiiIIIII", d, 0)
        if magic != 0xfeedfacf:
            return []
        segs = []
        cur = base + 32
        for _ in range(ncmds):
            f.seek(cur)
            c = f.read(8)
            if len(c) < 8:
                break
            cmd, cmdsize = struct.unpack_from("<II", c, 0)
            f.seek(cur)
            body = f.read(cmdsize)
            if cmd == LC_SEGMENT_64:
                nm = body[8:24].split(b"\0")[0].decode("latin1")
                vmaddr, vmsize, fileoff, filesize = struct.unpack_from("<QQQQ", body, 24)
                if filesize > 0:
                    segs.append((prefix + nm, vmaddr, fileoff, filesize))
            elif cmd == LC_FILESET_ENTRY and depth < maxdepth:
                eoff = struct.unpack_from("<Q", body, 16)[0]
                en = body[24:56].split(b"\0")[0].decode("latin1")
                if eoff:
                    segs += parse_segments(path, depth + 1, base + eoff, en + "/", maxdepth)
            cur += cmdsize
        return segs


SEGS = []


def va2off(va):
    for n, v, fo, fs in SEGS:
        if v <= va < v + fs:
            return fo + (va - v), n
    return None, None


def off2va(off):
    for n, v, fo, fs in SEGS:
        if fo <= off < fo + fs:
            return v + (off - fo), n
    return None, None


def disasm(data, base_va, n):
    try:
        from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
        md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
        out = []
        for ins in md.disasm(data, base_va):
            out.append("%#014x  %-8s %s" % (ins.address, ins.mnemonic, ins.op_str))
            if len(out) >= n:
                break
        return "\n".join(out)
    except ImportError:
        pass
    # fallback: objdump по сырому срезу
    open("/tmp/_kc_slice.bin", "wb").write(data)
    r = subprocess.run(["aarch64-linux-gnu-objdump", "-D", "-b", "binary", "-m", "aarch64",
                        "--adjust-vma=%#x" % base_va, "/tmp/_kc_slice.bin"],
                       capture_output=True, text=True)
    return "\n".join(r.stdout.splitlines()[:20 + n])


def main():
    if len(sys.argv) < 3:
        print(__doc__)
        return 1
    global SEGS
    path = sys.argv[1]
    SEGS = parse_segments(path)
    data = open(path, "rb").read()

    args = sys.argv[2:]
    if args[0] == "--off":
        off = int(args[1], 16)
        n = int(args[3]) if len(args) > 3 and args[2] == "--n" else 40
        va, seg = off2va(off)
        print("### off=%#x va=%s seg=%s" % (off, hex(va) if va else "?", seg))
        print(disasm(data[off:off + n * 4], va or 0, n))
        return 0

    n = 60
    for a in args:
        va = int(a, 16)
        off, seg = va2off(va)
        print("### %#x off=%s seg=%s" % (va, hex(off) if off else "unmapped", seg))
        if off is None:
            continue
        print(disasm(data[off:off + n * 4], va, n))
        print()
    return 0


if __name__ == "__main__":
    sys.exit(main())
