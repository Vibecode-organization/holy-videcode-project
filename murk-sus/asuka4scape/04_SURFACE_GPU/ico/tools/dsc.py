"""Global VA index across a split dyld shared cache set: VA -> (file, file_offset).
Also resolves the branch-island stubs used for cross-image calls."""
import struct, glob, os, re

DSC_DIR = '/home/femboychik/work/rc115/dsc272/System/Library/Caches/com.apple.dyld'


class Dsc:
    def __init__(self, d=DSC_DIR, main='dyld_shared_cache_arm64e'):
        self.dir = d
        self.regions = []  # (addr, size, path, fileoff)
        files = [os.path.join(d, main)] + sorted(glob.glob(os.path.join(d, main + '.*')))
        for f in files:
            base = os.path.basename(f)
            if re.search(r'\.(symbols|atlas|a2s)$', base):
                continue
            if not os.path.isfile(f):
                continue
            with open(f, 'rb') as fh:
                h = fh.read(0x400)
            if h[:4] != b'dyld':
                continue
            moff, mcount = struct.unpack_from('<II', h, 0x10)
            if mcount > 64:
                continue
            for i in range(mcount):
                p = moff + i * 32
                if p + 32 > len(h):
                    continue
                addr, size, fileoff, maxprot, initprot = struct.unpack_from('<QQQII', h, p)
                self.regions.append((addr, size, f, fileoff, initprot))
        self.regions.sort()
        self._cache = {}

    def find(self, va):
        for (addr, size, path, fileoff, prot) in self.regions:
            if addr <= va < addr + size:
                return (path, fileoff + (va - addr), prot)
        return None

    def read(self, va, n):
        r = self.find(va)
        if not r:
            return None
        path, off, prot = r
        if path not in self._cache:
            self._cache[path] = open(path, 'rb')
        fh = self._cache[path]
        fh.seek(off)
        return fh.read(n)

    def name_at(self, va):
        """Follow up to 4 stub hops; return target VA."""
        seen = []
        cur = va
        for _ in range(5):
            if cur in seen:
                break
            seen.append(cur)
            b = self.read(cur, 12)
            if not b or len(b) < 12:
                break
            w = struct.unpack('<III', b)
            # adrp x16, #imm ; add x16, x16, #imm ; br x16
            if (w[0] & 0x9F00001F) == 0x90000010 and (w[1] & 0xFFC003FF) == 0x91000210 and w[2] == 0xD61F0200:
                imm = self._adrp_imm(w[0], cur)
                add = (w[1] >> 10) & 0xFFF
                cur = (imm + add) & 0xFFFFFFFFFFFFFFFF
                continue
            # adrp x17 ; add x17 ; ldr x16,[x17] ; braa x16,x17  (rebind)
            if (w[0] & 0x9F00001F) == 0x90000011 and (w[1] & 0xFFC003FF) == 0x91000231:
                imm = self._adrp_imm(w[0], cur)
                add = (w[1] >> 10) & 0xFFF
                slot = (imm + add) & 0xFFFFFFFFFFFFFFFF
                return ('got', slot)
            break
        return cur

    @staticmethod
    def _adrp_imm(w, pc):
        immlo = (w >> 29) & 3
        immhi = (w >> 5) & 0x7FFFF
        imm = (immhi << 2) | immlo
        if imm & (1 << 20):
            imm -= (1 << 21)
        return ((pc & ~0xFFF) + (imm << 12)) & 0xFFFFFFFFFFFFFFFF


if __name__ == '__main__':
    import sys
    d = Dsc()
    for a in sys.argv[1:]:
        va = int(a, 16)
        r = d.find(va)
        print(f'{va:#x} -> {r}')
        if r:
            print('  ', d.read(va, 32).hex())
        print('  resolved:', d.name_at(va))
