#!/usr/bin/env python3
# per-binary profile: entitlements plist + XPC-ish selectors + interesting strings
import sys, re, subprocess, json, plistlib, os

sys.path.insert(0, '/home/femboychik/work/svc_map')
from ent import macho, blobs


def ents(path):
    b, cs, segs, e = macho(path)
    if not cs:
        return {}
    sig = b[cs[0]:cs[0] + cs[1]]
    bl = blobs(sig, e)
    xml = b''.join(bl.get(5, []))
    i = xml.find(b'<?xml')
    if i < 0:
        return {}
    try:
        return plistlib.loads(xml[i:].rstrip(b'\x00'))
    except Exception:
        return {}


def strings(path, minlen=5):
    out = subprocess.run(['strings', '-a', '-n', str(minlen), path], capture_output=True)
    return out.stdout.decode('utf-8', 'replace').split('\n')


def main(path):
    name = os.path.basename(path)
    e = ents(path)
    s = strings(path)
    pat = re.compile(r'(^com\.apple\.[A-Za-z0-9_.\-]{4,}$)|(^[a-zA-Z][A-Za-z0-9]{2,}(With|For)[A-Za-z0-9]+:)|(^[a-z][A-Za-z0-9]+:with)|(^did[A-Z][A-Za-z]+:)|(^handle[A-Z][A-Za-z]+:)|(^[a-z]+[A-Z][A-Za-z]+:error:)')
    sels = sorted({x for x in s if pat.match(x) and len(x) < 90})
    print('## %s  %d bytes' % (name, os.path.getsize(path)))
    print('### entitlements (%d keys)' % len(e))
    for k in sorted(e):
        v = e[k]
        if isinstance(v, bool):
            print('  %s' % k if v else '  %s=false' % k)
        elif isinstance(v, list):
            print('  %s = %s' % (k, ', '.join(map(str, v))[:200]))
        elif isinstance(v, dict):
            print('  %s = {%s}' % (k, ', '.join(sorted(v))[:200]))
        else:
            print('  %s = %s' % (k, str(v)[:160]))
    print('### selector-like strings (%d)' % len(sels))
    for x in sels[:120]:
        print('  ' + x)
    print('### path/url-ish strings')
    pu = [x for x in s if ('/var/' in x or '/private/' in x or x.startswith('file://')) and len(x) < 160]
    seen = set()
    for x in pu:
        if x in seen:
            continue
        seen.add(x)
        if len(seen) > 40:
            break
        print('  ' + x)
    print()


main(sys.argv[1])
