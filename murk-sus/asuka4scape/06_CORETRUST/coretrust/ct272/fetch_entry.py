#!/usr/bin/env python3
# Range-extract one stored/deflated ZIP entry from a remote IPSW, chunked with retries.
import sys, os, struct, zlib, urllib.request, time

URL, WANT, OUT = sys.argv[1], sys.argv[2], sys.argv[3]
CHUNK = 32 << 20


def req(url, start=None, end=None, method="GET", tries=6):
    last = None
    for a in range(tries):
        h = {}
        if start is not None:
            h["Range"] = f"bytes={start}-{end}"
        r = urllib.request.Request(url, headers=h, method=method)
        try:
            with urllib.request.urlopen(r, timeout=180) as f:
                return f.read()
        except Exception as e:  # noqa
            last = e
            print(f"  retry {a+1}: {e}", flush=True)
            time.sleep(2 + 3 * a)
    raise last


size = int(urllib.request.urlopen(urllib.request.Request(URL, method="HEAD"), timeout=60).headers["Content-Length"])
tail_len = min(4 << 20, size)
tail = req(URL, size - tail_len, size - 1)

cd_off = cd_size = None
j = tail.rfind(b"PK\x06\x07")
if j >= 0:
    z64_off, = struct.unpack_from("<Q", tail, j + 8)
    z = req(URL, z64_off, z64_off + 55)
    cd_size, cd_off = struct.unpack_from("<QQ", z, 40)
else:
    i = tail.rfind(b"PK\x05\x06")
    cd_size, cd_off = struct.unpack_from("<II", tail, i + 12)

cd = req(URL, cd_off, cd_off + cd_size - 1)
entries = []
p = 0
while p + 46 <= len(cd) and cd[p:p+4] == b"PK\x01\x02":
    (method,) = struct.unpack_from("<H", cd, p + 10)
    csize, usize = struct.unpack_from("<II", cd, p + 20)
    nlen, elen, clen = struct.unpack_from("<HHH", cd, p + 28)
    (lho,) = struct.unpack_from("<I", cd, p + 42)
    name = cd[p + 46:p + 46 + nlen].decode("utf-8", "replace")
    extra = cd[p + 46 + nlen:p + 46 + nlen + elen]
    if csize == 0xFFFFFFFF or usize == 0xFFFFFFFF or lho == 0xFFFFFFFF:
        q = 0
        while q + 4 <= len(extra):
            tag, ln = struct.unpack_from("<HH", extra, q)
            body = extra[q + 4:q + 4 + ln]
            if tag == 0x0001:
                off = 0
                if usize == 0xFFFFFFFF:
                    usize = struct.unpack_from("<Q", body, off)[0]; off += 8
                if csize == 0xFFFFFFFF:
                    csize = struct.unpack_from("<Q", body, off)[0]; off += 8
                if lho == 0xFFFFFFFF:
                    lho = struct.unpack_from("<Q", body, off)[0]; off += 8
                break
            q += 4 + ln
    entries.append((name, method, csize, usize, lho))
    p += 46 + nlen + elen + clen

hit = next((e for e in entries if e[0] == WANT), None) or next((e for e in entries if WANT in e[0]), None)
if not hit:
    raise SystemExit(f"not found: {WANT}")
name, method, csize, usize, lho = hit
print(f"entry {name} method={method} csize={csize} usize={usize} lho={lho}", flush=True)

hdr = req(URL, lho, lho + 29)
nlen, elen = struct.unpack_from("<HH", hdr, 26)
data_off = lho + 30 + nlen + elen

if method == 0:
    if os.path.exists(OUT) and os.path.getsize(OUT) == csize:
        print("already complete", flush=True)
        raise SystemExit(0)
    with open(OUT, "wb") as f:
        done = 0
        while done < csize:
            end = min(done + CHUNK - 1, csize - 1)
            b = req(URL, data_off + done, data_off + end)
            f.write(b)
            done += len(b)
            print(f"  {done}/{csize} ({100*done/csize:.1f}%)", flush=True)
    print("wrote", OUT, os.path.getsize(OUT), flush=True)
elif method == 8:
    blob = req(URL, data_off, data_off + csize - 1)
    open(OUT, "wb").write(zlib.decompress(blob, -15))
    print("wrote", OUT, os.path.getsize(OUT), flush=True)
else:
    raise SystemExit(f"method {method}")
