"""resolve kext PLT stubs: adrp;add;ldr;braa -> pac'd target."""
import struct, sys

sys.path.insert(0, '/home/femboychik/work/keytype')
from funcs2 import rd, va2off

BASE = 0xfffffff007004000


def u32(va):
    b = rd(va, 4)
    return struct.unpack('<I', b)[0] if len(b) == 4 else None


def u64(va):
    b = rd(va, 8)
    return struct.unpack('<Q', b)[0] if len(b) == 8 else None


def pac(q):
    return (BASE + (q & 0x0FFFFFFF)) & 0xFFFFFFFFFFFFFFFF


def adrp(pc, w):
    if (w & 0x9F000000) != 0x90000000:
        return None
    imm = (((w >> 5) & 0x7FFFF) << 2) | ((w >> 29) & 3)
    if imm & (1 << 20):
        imm -= 1 << 21
    return ((pc & ~0xfff) + (imm << 12)) & 0xFFFFFFFFFFFFFFFF


def resolve(va):
    """if va is a PLT stub, return (target_va, slot_va); else (None,None)."""
    w0, w1, w2, w3 = u32(va), u32(va + 4), u32(va + 8), u32(va + 12)
    if None in (w0, w1, w2, w3):
        return None, None
    p = adrp(va, w0)
    if p is None:
        return None, None
    # add x17, x17, #imm  (or any reg)
    if (w1 & 0xFF800000) != 0x91000000:
        return None, None
    rn = (w1 >> 5) & 0x1F
    if rn != (w0 & 0x1F):
        return None, None
    imm = (w1 >> 10) & 0xFFF
    slot = (p + imm) & 0xFFFFFFFFFFFFFFFF
    if (w2 & 0xFFC00000) != 0xF9400000:
        return None, None
    if (w3 & 0xFFFFFC1F) not in (0xD71F0800, 0xD71F0C00, 0xD71F0000):
        # braa x16, x17 = 0xd71f0a10? accept broad: mask opcode bits
        if (w3 & 0xFFFFF800) != 0xD71F0800:
            return None, None
    q = u64(slot)
    if q is None:
        return None, None
    return pac(q), slot


if __name__ == '__main__':
    for a in (0xfffffff00880c148, 0xfffffff00880c1f8, 0xfffffff009c49764, 0xfffffff008908934):
        t, s = resolve(a)
        print('%016x -> target %s slot %s' % (a, hex(t) if t else None, hex(s) if s else None))
