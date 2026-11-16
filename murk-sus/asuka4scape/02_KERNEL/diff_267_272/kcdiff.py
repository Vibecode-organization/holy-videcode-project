#!/usr/bin/env python3
# language: Python 3, file: kcdiff.py
# target: iOS kernelcache filesets (MH_FILESET, arm64e), no external deps
"""
Structural diff of two iOS kernelcaches.

Per kext: span size, per-segment sizes, function-start count, version,
and the cstrings owned by its address span. Tables (mach traps, BSD
syscalls, MIG subsystems) come from `ipsw kernel *` when available.

Usage:
    python3 kcdiff.py OLD NEW --label-old "iOS 26.7.2 (23H128)" \
                              --label-new "iOS 27.2 RC (24B115)" --out out
"""
import argparse
import json
import os
import re
import struct
import subprocess
import sys
from collections import OrderedDict

MH_MAGIC_64 = 0xFEEDFACF
FAT_MAGIC = 0xCAFEBABE
FAT_MAGIC_64 = 0xCAFEBABF
LC_SEGMENT_64 = 0x19
LC_UUID = 0x1B
LC_FUNCTION_STARTS = 0x26
LC_FILESET_ENTRY = 0x80000035

CPU_ARM64E = 0x0100000C


def u32(b, o):
    return struct.unpack_from("<I", b, o)[0]


def u64(b, o):
    return struct.unpack_from("<Q", b, o)[0]


def cstr16(raw):
    return raw.split(b"\0", 1)[0].decode("utf-8", "replace")


def lc_str(cmdbytes, base, off):
    if off == 0 or base + off >= len(cmdbytes):
        return ""
    return cmdbytes[base + off:].split(b"\0", 1)[0].decode("utf-8", "replace")


def inner_macho(data, off, limit):
    """Parse the Mach-O header that lives at `off`, bounded by `limit`."""
    if off + 32 > limit:
        return None
    if u32(data, off) != MH_MAGIC_64:
        return None
    ncmds = u32(data, off + 16)
    p = off + 32
    segs = []
    func_starts = None
    build = None
    for _ in range(ncmds):
        if p + 8 > limit:
            break
        cmd = u32(data, p)
        cmdsz = u32(data, p + 4)
        if cmdsz < 8:
            break
        c = p + 8
        if cmd == LC_SEGMENT_64:
            name = cstr16(data[c:c + 16])
            segs.append({
                "name": name,
                "vmaddr": u64(data, c + 16),
                "vmsize": u64(data, c + 24),
                "fileoff": u64(data, c + 32),
                "filesize": u64(data, c + 40),
            })
        elif cmd == LC_FUNCTION_STARTS:
            func_starts = (u32(data, c), u32(data, c + 4))
        elif cmd == 0x32:  # LC_BUILD_VERSION
            platform, minos, sdk, ntools = struct.unpack_from("<IIII", data, c)
            build = {"platform": platform, "minos": f"{minos >> 16}.{(minos >> 8) & 0xff}.{minos & 0xff}"}
        p += cmdsz
    return {"segments": segs, "func_starts": func_starts, "build": build}


def count_func_starts(data, off):
    """count ULEB128 deltas in LC_FUNCTION_STARTS payload (excludes terminator)."""
    if not off:
        return 0
    start, size = off
    end = min(start + size, len(data))
    p = start
    n = 0
    while p < end:
        delta = 0
        shift = 0
        while p < end:
            byte = data[p]
            p += 1
            delta |= (byte & 0x7F) << shift
            shift += 7
            if not byte & 0x80:
                break
        if delta == 0:
            break
        n += 1
    return n


def parse(path):
    with open(path, "rb") as f:
        data = f.read()

    # tolerate fat/universal wrappers
    base = 0
    magic = u32(data, 0)
    if magic in (FAT_MAGIC, FAT_MAGIC_64):
        nfat = u32(data, 4)
        p = 8
        for _ in range(nfat):
            if magic == FAT_MAGIC_64:
                cputype, _sub = struct.unpack_from("<ii", data, p)
                off, size = u64(data, p + 16), u64(data, p + 24)
                p += 32
            else:
                cputype, _sub = struct.unpack_from("<ii", data, p)
                off, size = u32(data, p + 8), u32(data, p + 12)
                p += 20
            if cputype == CPU_ARM64E:
                base = off
                break

    if u32(data, base) != MH_MAGIC_64:
        raise SystemExit(f"{path}: not a 64-bit Mach-O at {base:#x}")

    ncmds = u32(data, base + 16)
    p = base + 32
    entries = []
    for _ in range(ncmds):
        cmd = u32(data, p)
        cmdsz = u32(data, p + 4)
        if cmd == LC_FILESET_ENTRY:
            c = p + 8
            entries.append({
                "vmaddr": u64(data, c),
                "fileoff": u64(data, c + 8),
                "entry_id": lc_str(data[p:p + cmdsz], 0, u32(data, c + 16)),
            })
        p += cmdsz

    entries.sort(key=lambda e: e["fileoff"])
    spans = {}
    for i, e in enumerate(entries):
        limit = entries[i + 1]["fileoff"] if i + 1 < len(entries) else len(data)
        e["span"] = limit - e["fileoff"]
        hdr = inner_macho(data, e["fileoff"], limit)
        if not hdr:
            e["segments"] = []
            e["funcs"] = 0
            continue
        e["segments"] = hdr["segments"]
        # kext segment fileoffs are absolute and interleaved across the shared
        # __PRELINK_TEXT / __DATA regions, so a kext's real weight in the file is
        # the sum of its own segment sizes, not a byte range.
        e["span"] = sum(s["filesize"] for s in hdr["segments"])
        e["seg_sizes"] = {s["name"]: s["filesize"] for s in hdr["segments"] if s["filesize"] and s["name"] in
                          ("__TEXT", "__TEXT_EXEC", "__DATA", "__DATA_CONST", "__DATA_SPTM",
                           "__PRELINK_TEXT", "__PRELINK_INFO", "__LINKEDIT", "__TEXT_BOOT_EXEC")}
        lo = min((s["fileoff"] for s in hdr["segments"]), default=0)
        e["funcs"] = count_func_starts(data, hdr["func_starts"]) if hdr["func_starts"] else 0
        e["text_exec"] = sum(s["vmsize"] for s in hdr["segments"] if s["name"] in ("__TEXT_EXEC", "__TEXT"))
        e["limit"] = limit
        e["bytes_start"] = e["fileoff"]
        spans[e["entry_id"]] = e
        del lo

    return {"path": path, "data": data, "entries": spans, "size": len(data), "base": base}


def kext_versions(path):
    """name -> version string, from ipsw kernel kexts (falls back to empty)."""
    try:
        outp = subprocess.run(["ipsw", "kernel", "kexts", path],
                              capture_output=True, text=True, timeout=600).stdout
    except Exception:
        return {}
    ver = {}
    for line in outp.splitlines():
        m = re.search(r":\s+(\S+)\s+\(([^)]*)\)", line)
        if m:
            ver[m.group(1)] = m.group(2)
    return ver


def dump_table(path, sub):
    try:
        outp = subprocess.run(["ipsw", "kernel", sub, path],
                              capture_output=True, text=True, timeout=900).stdout
    except Exception:
        return []
    return [l.rstrip() for l in outp.splitlines() if l.strip() and not l.lstrip().startswith(("•", "found", "Found"))]


def syscalls(path):
    rows = []
    for line in dump_table(path, "syscall"):
        m = re.match(r"\s*(\d+)\s+0x[0-9a-f]+:\s+(\S+)", line)
        if m:
            # addresses shift between builds; keep only the ABI-relevant text
            sig = re.sub(r"0x[0-9a-f]+", "0xADDR", line.split(":", 1)[-1]).strip()
            rows.append((int(m.group(1)), m.group(2), sig))
    return rows


def mach_traps(path):
    rows = []
    for line in dump_table(path, "mach"):
        m = re.match(r"\s*(\d+)\s+0x[0-9a-f]+:\s+(\S+)", line)
        if m:
            rows.append((int(m.group(1)), m.group(2)))
    return rows


def mig(path):
    subs = OrderedDict()
    cur = None
    for line in dump_table(path, "mig"):
        m = re.match(r"0x[0-9a-f]+:\s+(\S+)\s+start=(\d+)\s+end=(\d+)", line)
        if m:
            cur = m.group(1)
            subs[cur] = {"start": int(m.group(2)), "end": int(m.group(3)), "routines": []}
            continue
        m = re.match(r"\s*0x[0-9a-f]+:\s+(\S+)\s+num=(\d+)\s+impl=0x[0-9a-f]+\s+argc=(\w+)\s+descr=(\d)\s+reply_descr=(\d)\s+max_reply_msg=(\d+)", line)
        if m and cur:
            subs[cur]["routines"].append({
                "name": m.group(1), "num": int(m.group(2)), "argc": m.group(3),
                "descr": int(m.group(4)), "reply_descr": int(m.group(5)),
                "max_reply": int(m.group(6)),
            })
    return subs


STR_RE = re.compile(rb"[\x20-\x7e]{4,200}")


def strings_by_kext(kc):
    """>=4-char printable runs, attributed to the kext whose span contains them."""
    out = {}
    data = kc["data"]
    for name, e in kc["entries"].items():
        lo = e["fileoff"]
        hi = min(e.get("limit", lo + e["span"]), len(data))
        blob = data[lo:hi]
        found = {m.group(0).decode("ascii", "replace") for m in STR_RE.finditer(blob)}
        out[name] = found
    return out


KEYWORDS = re.compile(
    r"panic|assert|denied|deny|entitle|sandbox|invalid|overflow|underflow|bounds|"
    r"out of range|too (small|large|long|many)|bad |fail|corrupt|truncat|userclient|"
    r"user client|userclient|SPTM|TXM|page table|pte|trust|codesign|cs_|AMFI|"
    r"signature|leak|use.after|double.free|refcount|unserializ|serializ|deserial|"
    r"XPC|surface|mapped|unmap|wire|wired",
    re.IGNORECASE,
)


def symbolsets(path):
    sets = OrderedDict()
    cur = None
    for line in dump_table(path, "symbolsets"):
        m = re.match(r"(com\.apple\.kpi\S*):\s*\(([^)]*)\)", line)
        if m:
            cur = m.group(1)
            sets[cur] = {"version": m.group(2), "symbols": set()}
            continue
        if cur and re.match(r"^[_A-Za-z]", line):
            sets[cur]["symbols"].add(line.strip())
    return sets


def diff(old_path, new_path, label_old, label_new, out_dir):
    os.makedirs(out_dir, exist_ok=True)
    A = parse(old_path)
    B = parse(new_path)
    va = kext_versions(old_path)
    vb = kext_versions(new_path)
    sa = strings_by_kext(A)
    sb = strings_by_kext(B)

    names_a, names_b = set(A["entries"]), set(B["entries"])
    report = {
        "labels": {"old": label_old, "new": label_new},
        "meta": {
            "old_size": A["size"], "new_size": B["size"],
            "old_kexts": len(names_a), "new_kexts": len(names_b),
        },
        "kexts": {"added": sorted(names_b - names_a), "removed": sorted(names_a - names_b)},
        "rows": [],
    }

    for name in sorted(names_a | names_b):
        if name not in A["entries"] or name not in B["entries"]:
            report["rows"].append({
                "kext": name,
                "version_old": va.get(name, ""),
                "version_new": vb.get(name, ""),
                "version_bump": va.get(name, "") != vb.get(name, ""),
                "aux_only": True,
                "span_old": A["entries"].get(name, {}).get("span", 0),
                "span_new": B["entries"].get(name, {}).get("span", 0),
                "span_delta": 0, "text_old": 0, "text_new": 0, "text_delta": 0,
                "funcs_old": 0, "funcs_new": 0, "func_delta": 0,
                "strings_added": 0, "strings_removed": 0,
                "interesting_added": [], "interesting_removed": [],
            })
            continue
        a, b = A["entries"][name], B["entries"][name]
        fa, fb = sa.get(name, set()), sb.get(name, set())
        new_strings = sorted(fb - fa)
        gone_strings = sorted(fa - fb)
        hit_new = [s for s in new_strings if KEYWORDS.search(s)][:12]
        hit_gone = [s for s in gone_strings if KEYWORDS.search(s)][:8]
        seg_delta = {}
        for seg in set(a.get("seg_sizes", {})) | set(b.get("seg_sizes", {})):
            d = b.get("seg_sizes", {}).get(seg, 0) - a.get("seg_sizes", {}).get(seg, 0)
            if d:
                seg_delta[seg] = d
        report["rows"].append({
            "kext": name,
            "version_old": va.get(name, ""),
            "version_new": vb.get(name, ""),
            "version_bump": va.get(name, "") != vb.get(name, ""),
            "span_old": a["span"], "span_new": b["span"],
            "span_delta": b["span"] - a["span"],
            "text_old": a.get("text_exec", 0), "text_new": b.get("text_exec", 0),
            "text_delta": b.get("text_exec", 0) - a.get("text_exec", 0),
            "funcs_old": a["funcs"], "funcs_new": b["funcs"],
            "func_delta": b["funcs"] - a["funcs"],
            "strings_added": len(new_strings),
            "strings_removed": len(gone_strings),
            "segments": seg_delta,
            "interesting_added": hit_new,
            "interesting_removed": hit_gone,
        })

    sc_a, sc_b = syscalls(old_path), syscalls(new_path)
    report["syscalls"] = {
        "count_old": len(sc_a), "count_new": len(sc_b),
        "added": [(n, nm) for n, nm, _ in sc_b if n not in {x[0] for x in sc_a}],
        "removed": [(n, nm) for n, nm, _ in sc_a if n not in {x[0] for x in sc_b}],
        "renamed": [(na, na_name, nb_name) for (na, na_name, _), (nb, nb_name, _) in zip(sc_a, sc_b)
                    if na == nb and na_name != nb_name],
        "signature_changed": [na_name for (na, na_name, la), (nb, nb_name, lb) in zip(sc_a, sc_b)
                              if na == nb and la != lb][:200],
    }
    mt_a, mt_b = mach_traps(old_path), mach_traps(new_path)
    bad_a = sum(1 for _, nm in mt_a if nm in ("<unknown>",)) / max(len(mt_a), 1)
    bad_b = sum(1 for _, nm in mt_b if nm in ("<unknown>",)) / max(len(mt_b), 1)
    report["mach_traps"] = {
        "count_old": len(mt_a), "count_new": len(mt_b),
        "unparsed_ratio_old": round(bad_a, 3), "unparsed_ratio_new": round(bad_b, 3),
        "reliable": bad_a < 0.1 and bad_b < 0.1,
        "added": [(n, nm) for n, nm in mt_b if n not in {x[0] for x in mt_a}],
        "removed": [(n, nm) for n, nm in mt_a if n not in {x[0] for x in mt_b}],
        "renamed": [(na, na_name, nb_name) for (na, na_name), (nb, nb_name) in zip(mt_a, mt_b)
                    if na == nb and na_name != nb_name
                    and "<unknown>" not in (na_name, nb_name)],
    }
    ma, mb = mig(old_path), mig(new_path)
    report["mig"] = {
        "subsystems_old": len(ma), "subsystems_new": len(mb),
        "subsystems_added": sorted(set(mb) - set(ma)),
        "subsystems_removed": sorted(set(ma) - set(mb)),
        "routines_old": sum(len(s["routines"]) for s in ma.values()),
        "routines_new": sum(len(s["routines"]) for s in mb.values()),
        "per_subsystem": [
            {"subsystem": k, "old": len(ma[k]["routines"]), "new": len(mb[k]["routines"]),
             "added": sorted({r["name"] for r in mb[k]["routines"]} - {r["name"] for r in ma[k]["routines"]})[:20],
             "removed": sorted({r["name"] for r in ma[k]["routines"]} - {r["name"] for r in mb[k]["routines"]})[:20]}
            for k in ma if k in mb and {r["name"] for r in ma[k]["routines"]} != {r["name"] for r in mb[k]["routines"]}
        ],
    }

    sa_sets = symbolsets(old_path)
    sb_sets = symbolsets(new_path)
    report["symbolsets"] = {
        "old": {k: v["version"] for k, v in sa_sets.items()},
        "new": {k: v["version"] for k, v in sb_sets.items()},
        "added": sorted(set(sb_sets) - set(sa_sets)),
        "removed": sorted(set(sa_sets) - set(sb_sets)),
        "symbols_added": sorted({s for k in sb_sets for s in sb_sets[k]["symbols"]}
                                - {s for k in sa_sets for s in sa_sets[k]["symbols"]})[:400],
        "symbols_removed": sorted({s for k in sa_sets for s in sa_sets[k]["symbols"]}
                                  - {s for k in sb_sets for s in sb_sets[k]["symbols"]})[:400],
    }

    with open(os.path.join(out_dir, "diff.json"), "w") as f:
        json.dump(report, f, indent=1, ensure_ascii=False)
    write_markdown(report, os.path.join(out_dir, "REPORT.md"))
    print(f"wrote {out_dir}/diff.json, {out_dir}/REPORT.md")
    return report


def fmt_kb(n):
    return f"{n/1024:+.0f}K" if n else "0"


def write_markdown(r, path):
    L = []
    a, b = r["labels"]["old"], r["labels"]["new"]
    L.append(f"# Kernelcache diff: {a} -> {b}\n")
    m = r["meta"]
    L.append(f"- размер файла: {m['old_size']:,} -> {m['new_size']:,} ({m['new_size']-m['old_size']:+,})")
    L.append(f"- kext'ов: {m['old_kexts']} -> {m['new_kexts']}")
    L.append(f"- новых: {len(r['kexts']['added'])}, удалённых: {len(r['kexts']['removed'])}\n")

    if r["kexts"]["added"]:
        L.append("## Новые kext\n")
        L += [f"- `{k}`" for k in r["kexts"]["added"]] + [""]
    if r["kexts"]["removed"]:
        L.append("## Удалённые kext\n")
        L += [f"- `{k}`" for k in r["kexts"]["removed"]] + [""]

    bumps = [x for x in r["rows"] if x["version_bump"]]
    L.append(f"## Изменения версий ({len(bumps)})\n")
    for x in sorted(bumps, key=lambda x: x["kext"]):
        L.append(f"- `{x['kext']}`: {x['version_old']} -> {x['version_new']}")
    L.append("")

    big = sorted(r["rows"], key=lambda x: -abs(x["span_delta"]))[:25]
    L.append("## Крупнейшие изменения размера kext (span)\n")
    L.append("| kext | span | Δ | text | Δ | funcs | Δ |")
    L.append("|---|---|---|---|---|---|---|")
    for x in big:
        L.append(f"| `{x['kext']}` | {x['span_old']:,} | {x['span_delta']:+,} | {x['text_old']:,} | "
                 f"{x['text_delta']:+,} | {x['funcs_old']} | {x['func_delta']:+d} |")
    L.append("")

    churn = sorted(r["rows"], key=lambda x: -(abs(x["text_delta"]) + abs(x["func_delta"]) * 64))[:20]
    L.append("## Наибольший код-чёрн (text delta + func delta)\n")
    for x in churn:
        L.append(f"- `{x['kext']}`: text {fmt_kb(x['text_delta'])}, funcs {x['func_delta']:+d}, "
                 f"строк +{x['strings_added']}/-{x['strings_removed']}")

    seg_rows = [x for x in r["rows"] if x.get("segments")]
    seg_rows.sort(key=lambda x: -sum(abs(v) for v in x["segments"].values()))
    L.append("\n## Изменения по сегментам (топ 15 kext)\n")
    for x in seg_rows[:15]:
        parts = ", ".join(f"{k} {v:+,}" for k, v in sorted(x["segments"].items()))
        L.append(f"- `{x['kext']}`: {parts}")

    hot = [x for x in r["rows"] if x["interesting_added"]]
    hot.sort(key=lambda x: -len(x["interesting_added"]))
    L.append(f"\n## Новые строки с security-релевантной лексикой ({len(hot)} kext)\n")
    for x in hot[:18]:
        L.append(f"### `{x['kext']}`")
        for s in x["interesting_added"]:
            L.append(f"- `{s}`")
        L.append("")

    sc = r["syscalls"]
    L.append(f"## Syscalls: {sc['count_old']} -> {sc['count_new']}")
    if sc["added"]:
        L.append("новые: " + ", ".join(f"{n}:{nm}" for n, nm in sc["added"]))
    if sc["removed"]:
        L.append("удалённые: " + ", ".join(f"{n}:{nm}" for n, nm in sc["removed"]))
    if sc["renamed"]:
        L.append("переименованные: " + ", ".join(f"{n}:{o}->{x}" for n, o, x in sc["renamed"]))
    L.append(f"изменённых прототипов: {len(sc['signature_changed'])}\n")

    mt = r["mach_traps"]
    L.append(f"## Mach traps: {mt['count_old']} -> {mt['count_new']}")
    if not mt.get("reliable", True):
        L.append(f"_парсер ipsw не нашёл таблицу корректно (unknown: {mt['unparsed_ratio_old']:.0%} / "
                 f"{mt['unparsed_ratio_new']:.0%}); имена не сравниваются_")
    if mt["added"]:
        L.append("новые: " + ", ".join(f"{n}:{nm}" for n, nm in mt["added"]))
    if mt["removed"]:
        L.append("удалённые: " + ", ".join(f"{n}:{nm}" for n, nm in mt["removed"]))
    if mt["renamed"]:
        L.append("переименованные: " + ", ".join(f"{n}:{o}->{x}" for n, o, x in mt["renamed"]))
    L.append("")

    mg = r["mig"]
    L.append(f"## MIG: {mg['subsystems_old']} подсистем ({mg['routines_old']} routines) -> "
             f"{mg['subsystems_new']} ({mg['routines_new']})")
    if mg["subsystems_added"]:
        L.append("- новые подсистемы: " + ", ".join(mg["subsystems_added"]))
    if mg["subsystems_removed"]:
        L.append("- удалённые подсистемы: " + ", ".join(mg["subsystems_removed"]))
    for s in mg["per_subsystem"][:20]:
        if s["added"] or s["removed"]:
            L.append(f"- `{s['subsystem']}`: {s['old']} -> {s['new']}"
                     + (f"; +{', '.join(s['added'][:6])}" if s["added"] else "")
                     + (f"; -{', '.join(s['removed'][:6])}" if s["removed"] else ""))
    L.append("")

    ss = r.get("symbolsets", {})
    L.append("## Symbol sets (kpi)")
    for k in sorted(set(ss.get("old", {})) | set(ss.get("new", {}))):
        o, n = ss["old"].get(k), ss["new"].get(k)
        flag = "" if o == n else f"  **{o} -> {n}**"
        L.append(f"- `{k}`: {o}{flag}")
    if ss.get("symbols_added"):
        L.append("\nНовые экспортируемые символы: " + ", ".join(f"`{s}`" for s in ss["symbols_added"][:80]))
    if ss.get("symbols_removed"):
        L.append("\nУдалённые символы: " + ", ".join(f"`{s}`" for s in ss["symbols_removed"][:80]))
    L.append("")

    with open(path, "w") as f:
        f.write("\n".join(L))


if __name__ == "__main__":
    ap = argparse.ArgumentParser()
    ap.add_argument("old")
    ap.add_argument("new")
    ap.add_argument("--label-old", default="old")
    ap.add_argument("--label-new", default="new")
    ap.add_argument("--out", default="out")
    ns = ap.parse_args()
    diff(ns.old, ns.new, ns.label_old, ns.label_new, ns.out)
