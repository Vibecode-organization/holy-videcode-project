#!/usr/bin/env python3
"""uif_selref_scan.py — найти потребителей селекторов columnSpan/rowSpan в UIFoundation.

Задача #1 (NSHTMLReader / NSTextTable), следующий шаг из 01_REPORTS/СТАТУС_после_AGENTS.md:
  декодировать chained-fixup selref-слоты UIFoundation, взять слоты columnSpan/rowSpan,
  от них adrp+ldr -> ObjC-транки селекторов -> bl-потребители.

Запуск на хосте (только stdlib, ничего ставить не надо):

    python3 uif_selref_scan.py \
        /home/femboychik/asuka4scape/04_SURFACE_GPU/html_table/uif/UIFoundation \
        > /home/femboychik/asuka4scape/04_SURFACE_GPU/html_table/selref_report.txt

Потом мне достаточно прочитать selref_report.txt через хаб.

Что делает:
 1. парсит Mach-O и LC_DYLD_CHAINED_FIXUPS (PTR_64 / PTR_64_OFFSET / ARM64E варианты);
 2. раскручивает цепочки в __objc_selrefs, сопоставляет слот -> имя селектора;
 3. сканирует исполняемые секции на adrp+ldr по этим слотам => транки селекторов;
 4. сканирует bl на транки => call sites (потребители);
 5. печатает отчёт: слот, транк, call site, hex-окно и ближайшие bl-таргеты.

Флаги:
    --selectors columnSpan,rowSpan,...   (по умолчанию набор из задачи)
    --window 0x90                        (размер hex-окна вокруг call site)
"""

import sys
import struct

DEFAULT_SELECTORS = [
    "columnSpan",
    "rowSpan",
    "startingRow",
    "startingColumn",
    "numberOfColumns",
    "numberOfRows",
    "table",
    "initWithTable:startingRow:rowSpan:startingColumn:columnSpan:",
]

MH_MAGIC_64 = 0xFEEDFACF
LC_SEGMENT_64 = 0x19
LC_DYLD_CHAINED_FIXUPS = 0x80000034
S_ATTR_PURE_INSTRUCTIONS = 0x80000000

# dyld_chained_ptr formats
PTR_ARM64E = 1
PTR_64 = 2
PTR_ARM64E_OFFSET = 5
PTR_64_OFFSET = 6
PTR_ARM64E_KERNEL = 7
PTR_ARM64E_USERLAND = 9
PTR_ARM64E_USERLAND24 = 12
ARM64E_FORMATS = {PTR_ARM64E, PTR_ARM64E_OFFSET, PTR_ARM64E_KERNEL,
                  PTR_ARM64E_USERLAND, PTR_ARM64E_USERLAND24}
OFFSET_FORMATS = {PTR_ARM64E_OFFSET, PTR_64_OFFSET}

DYLD_CHAINED_PTR_START_NONE = 0xFFFF
DYLD_CHAINED_PTR_START_MULTI = 0x8000


def sx(v, bits):
    return v - (1 << bits) if v & (1 << (bits - 1)) else v


def cstr(data, off, limit=192):
    if off is None or off < 0 or off >= len(data):
        return None
    end = data.find(b"\x00", off, min(len(data), off + limit))
    if end < 0:
        return None
    try:
        return data[off:end].decode("utf-8", "replace")
    except Exception:
        return None


class MachO:
    def __init__(self, data):
        self.data = data
        (magic, cputype, cpusub, filetype, ncmds, sizeofcmds,
         flags, reserved) = struct.unpack_from("<IiiIIIII", data, 0)
        if magic != MH_MAGIC_64:
            raise SystemExit("не Mach-O 64 LE (magic=0x%08x)" % magic)
        self.cputype = cputype
        self.filetype = filetype
        self.segments = []   # dict(name, vmaddr, vmsize, fileoff, filesize, nsects)
        self.sections = []   # dict(name, seg, addr, size, offset, flags)
        self.fixups = None   # (fileoff, size)
        off = 32
        for _ in range(ncmds):
            cmd, cmdsize = struct.unpack_from("<II", data, off)
            if cmd == LC_SEGMENT_64:
                segname, vmaddr, vmsize, fileoff, filesize, maxprot, initprot, nsects, sflags = \
                    struct.unpack_from("<16sQQQQiiII", data, off + 8)
                name = segname.split(b"\x00")[0].decode("ascii", "replace")
                self.segments.append(dict(name=name, vmaddr=vmaddr, vmsize=vmsize,
                                          fileoff=fileoff, filesize=filesize,
                                          protect=initprot, nsects=nsects))
                soff = off + 72
                for _ in range(nsects):
                    sectname, segn, addr, size, offset, align, reloff, nreloc, sflags2, \
                        r1, r2, r3 = struct.unpack_from("<16s16sQQIIIIIIII", data, soff)
                    self.sections.append(dict(
                        name=sectname.split(b"\x00")[0].decode("ascii", "replace"),
                        seg=segn.split(b"\x00")[0].decode("ascii", "replace"),
                        addr=addr, size=size, offset=offset, flags=sflags2))
                    soff += 80
            elif cmd == LC_DYLD_CHAINED_FIXUPS:
                dataoff, datasize = struct.unpack_from("<II", data, off + 8)
                self.fixups = (dataoff, datasize)
            off += cmdsize

        self.base = 0
        for s in self.segments:
            if s["fileoff"] == 0 and s["vmsize"]:
                self.base = s["vmaddr"]
                break

    # ---- VA -> file offset -------------------------------------------------
    def va2off(self, va):
        for s in self.sections:
            if s["size"] and s["addr"] <= va < s["addr"] + s["size"]:
                return s["offset"] + (va - s["addr"])
        for g in self.segments:
            if g["vmsize"] and g["vmaddr"] <= va < g["vmaddr"] + g["filesize"]:
                return g["fileoff"] + (va - g["vmaddr"])
        return None

    def section_of(self, va):
        for s in self.sections:
            if s["size"] and s["addr"] <= va < s["addr"] + s["size"]:
                return s
        return None


def walk_chains(m, want):
    """want: set имён селекторов. Возвращает {name: [slot_va,...]}."""
    if not m.fixups:
        raise SystemExit("нет LC_DYLD_CHAINED_FIXUPS")
    data = m.data
    blob_off, blob_size = m.fixups
    blob = data[blob_off:blob_off + blob_size]
    (ver, starts_off, imports_off, symbols_off, imports_count,
     imports_format, symbols_format) = struct.unpack_from("<7I", blob, 0)

    starts = blob[starts_off:]
    seg_count = struct.unpack_from("<I", starts, 0)[0]
    seg_info_off = list(struct.unpack_from("<%dI" % seg_count, starts, 4))

    selrefs = next((s for s in m.sections if s["name"] == "__objc_selrefs"), None)
    methname = next((s for s in m.sections if s["name"] == "__objc_methname"), None)
    if not selrefs or not methname:
        raise SystemExit("нет __objc_selrefs / __objc_methname")

    out = {k: [] for k in want}
    stats = dict(chains=0, selref_entries=0, resolved=0, unmatched=0,
                 formats={}, segs_with_fixups=0)

    for i, si in enumerate(seg_info_off):
        if si == 0:
            continue
        stats["segs_with_fixups"] += 1
        info = starts[si:]
        (size_, page_size, pointer_format, segment_offset,
         max_valid, page_count) = struct.unpack_from("<IHHQIH", info, 0)
        stats["formats"][pointer_format] = stats["formats"].get(pointer_format, 0) + 1
        page_start = struct.unpack_from("<%dH" % page_count, info, 22)
        stride = 8 if pointer_format in ARM64E_FORMATS else 4

        for page in range(page_count):
            ps = page_start[page]
            if ps == DYLD_CHAINED_PTR_START_NONE:
                continue
            if ps == DYLD_CHAINED_PTR_START_MULTI:
                continue  # редкий случай, в UIFoundation не встречается
            page_va = m.base + segment_offset + page * page_size
            cur = page_va + ps
            guard = 0
            while cur and guard < 20000:
                guard += 1
                stats["chains"] += 1
                foff = m.va2off(cur)
                if foff is None or foff + 8 > len(data):
                    break
                val = struct.unpack_from("<Q", data, foff)[0]

                if pointer_format in ARM64E_FORMATS:
                    auth = (val >> 63) & 1
                    bind = (val >> 62) & 1
                    nxt = (val >> 51) & 0x7FF
                    tgt = val & 0x7FFFFFFFFFFF
                    high8 = (val >> 43) & 0xFF
                else:
                    auth = 0
                    bind = (val >> 63) & 1
                    nxt = (val >> 51) & 0xFFF
                    tgt = val & 0xFFFFFFFFF
                    high8 = (val >> 36) & 0xFF

                if selrefs["addr"] <= cur < selrefs["addr"] + selrefs["size"]:
                    stats["selref_entries"] += 1
                    if not bind and tgt:
                        cand = tgt
                        if pointer_format in OFFSET_FORMATS:
                            cand = m.base + tgt
                        for attempt in (cand, (high8 << 56) | tgt):
                            off = m.va2off(attempt)
                            if off is None:
                                continue
                            if methname["addr"] <= attempt < methname["addr"] + methname["size"]:
                                name = cstr(data, off)
                                stats["resolved"] += 1
                                if name in out:
                                    out[name].append(cur)
                                break
                        else:
                            stats["unmatched"] += 1

                nxt_off = nxt * stride
                if not nxt_off:
                    break
                cur = cur + nxt_off

    stats["unmatched_selrefs"] = stats["unmatched"]
    return out, stats


# ---------------------------------------------------------------- ARM64 mini

def is_adrp(w):
    return (w & 0x9F000000) == 0x90000000


def is_ldr_x(w):
    # LDR (immediate, unsigned offset), 64-bit: size=11 -> F9400000
    return (w & 0xFFC00000) == 0xF9400000


def is_bl(w):
    return (w & 0xFC000000) == 0x94000000


def is_b(w):
    return (w & 0xFC000000) == 0x14000000


def is_ret(w):
    return w == 0xD65F03C0


def dec_adrp(w, pc):
    immlo = (w >> 29) & 3
    immhi = (w >> 5) & 0x7FFFF
    imm = sx((immhi << 2) | immlo, 21) << 12
    return (pc & ~0xFFF) + imm, w & 0x1F


def dec_bl(w, pc):
    return pc + (sx(w & 0x3FFFFFF, 26) << 2)


def exec_sections(m):
    out = []
    for s in m.sections:
        if s["size"] < 4:
            continue
        if (s["flags"] & S_ATTR_PURE_INSTRUCTIONS) or s["name"] in ("__text", "__stubs"):
            out.append(s)
    return out


def iter_words(m, sec):
    data = m.data
    off = sec["offset"]
    n = sec["size"] // 4
    for i in range(n):
        yield sec["addr"] + i * 4, struct.unpack_from("<I", data, off + i * 4)[0]


def find_refs(m, slot_vas):
    """adrp+ldr на слот -> список (adrp_pc, ldr_pc, slot_va)."""
    slot_page = {}
    for va in slot_vas:
        slot_page.setdefault(va & ~0xFFF, set()).add(va)

    hits = []
    for sec in exec_sections(m):
        words = list(iter_words(m, sec))
        for i, (pc, w) in enumerate(words):
            if not is_adrp(w):
                continue
            page, rd = dec_adrp(w, pc)
            if page not in slot_page:
                continue
            for j in range(1, 5):
                if i + j >= len(words):
                    break
                pc2, w2 = words[i + j]
                if not is_ldr_x(w2):
                    continue
                rn = (w2 >> 5) & 0x1F
                if rn != rd:
                    continue
                imm12 = (w2 >> 10) & 0xFFF
                addr = page + imm12 * 8
                if addr in slot_page[page]:
                    hits.append((pc, pc2, addr))
                    break
    return hits


def find_calls(m, targets):
    calls = []
    tset = set(targets)
    for sec in exec_sections(m):
        for pc, w in iter_words(m, sec):
            if is_bl(w):
                t = dec_bl(w, pc)
                if t in tset:
                    calls.append((pc, t))
    return calls


def disasm_line(m, pc, w):
    if is_adrp(w):
        p, rd = dec_adrp(w, pc)
        return "adrp x%d, 0x%x" % (rd, p)
    if is_ldr_x(w):
        rn = (w >> 5) & 0x1F
        rt = w & 0x1F
        imm = ((w >> 10) & 0xFFF) * 8
        return "ldr x%d, [x%d, #0x%x]" % (rt, rn, imm)
    if is_bl(w):
        return "bl 0x%x" % dec_bl(w, pc)
    if is_b(w):
        return "b 0x%x" % (pc + (sx(w & 0x3FFFFFF, 26) << 2))
    if is_ret(w):
        return "ret"
    if (w & 0x7F800000) == 0x52800000 or (w & 0x7F800000) == 0x12800000:
        return "mov/movn w?, #%d" % ((w >> 5) & 0xFFFF)
    return None


def hexwin(m, center, span):
    lines = []
    start = center - span
    end = center + span
    for va in range(start, end, 4):
        off = m.va2off(va)
        if off is None:
            continue
        w = struct.unpack_from("<I", m.data, off)[0]
        d = disasm_line(m, va, w)
        mark = "  <<<" if va == center else ""
        lines.append("  0x%012x  %08x  %s%s" % (va, w, d if d else ".word", mark))
    return "\n".join(lines)


def main(argv):
    if len(argv) < 2:
        print(__doc__)
        return 2
    path = argv[1]
    sel = DEFAULT_SELECTORS
    span = 0x90
    i = 2
    while i < len(argv):
        if argv[i] == "--selectors":
            sel = argv[i + 1].split(",")
            i += 2
        elif argv[i] == "--window":
            span = int(argv[i + 1], 0)
            i += 2
        else:
            i += 1

    with open(path, "rb") as f:
        data = f.read()
    m = MachO(data)

    print("== image: %s" % path)
    print("   base=0x%x  segments=%d  sections=%d  fixups=%s"
          % (m.base, len(m.segments), len(m.sections), m.fixups))
    for s in m.segments:
        print("   seg %-14s vm=0x%012x size=0x%-8x off=0x%x"
              % (s["name"], s["vmaddr"], s["vmsize"], s["fileoff"]))

    found, stats = walk_chains(m, set(sel))
    print("\n== chained fixups: chains=%d selref_entries=%d resolved=%d "
          "unmatched=%d formats=%s"
          % (stats["chains"], stats["selref_entries"], stats["resolved"],
             stats["unmatched"], stats["formats"]))
    for name in sel:
        print("   selref %-58s slots=%d %s"
              % (name, len(found.get(name, [])),
                 " ".join("0x%x" % v for v in found.get(name, [])[:6])))

    all_slots = [v for vs in found.values() for v in vs]
    if not all_slots:
        print("\nНЕТ СЛОТОВ — либо формат fixups нестандартный, либо селекторы "
              "в другом образе (например в UIKitCore).")
        return 1

    refs = find_refs(m, all_slots)
    slot2name = {v: k for k, vs in found.items() for v in vs}
    print("\n== adrp+ldr на слоты (кандидаты в транки): %d" % len(refs))
    tramps = []
    for code_va, ldr_va, slot in refs:
        print("   tramp? 0x%x  (ldr @0x%x)  sel=%s" % (code_va, ldr_va, slot2name[slot]))
        tramps.append(code_va)
    if not tramps:
        print("   пусто — значит слоты читаются иначе (напр. через GOT), нужен другой проход")
        return 1

    calls = find_calls(m, tramps)
    print("\n== bl на транки (потребители): %d" % len(calls))
    for pc, t in calls:
        print("   call 0x%x -> 0x%x  sel=%s"
              % (pc, t, slot2name.get(next((s for c, l, s in refs if c == t), 0), "?")))

    print("\n== окна вокруг call sites ==")
    for pc, t in calls:
        print("\n--- call 0x%x -> tramp 0x%x" % (pc, t))
        print(hexwin(m, pc, span))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
