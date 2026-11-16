#!/usr/bin/env python3
"""BER<->DER wrapper variants for the App Store CMS seed.

Only the outer ContentInfo / [0] / SignedData wrappers are re-encoded.
The signedAttrs bytes are left untouched, so the CMS signature stays valid.
"""
import sys

def parse(b, i=0):
    start = i
    tag = b[i]; i += 1
    if i >= len(b): raise ValueError('eof')
    l = b[i]; i += 1
    if l == 0x80:
        # indefinite: find matching EOC, respecting nested TLVs
        cs = i
        j = i
        while True:
            if b[j:j+2] == b'\x00\x00':
                ce = j; end = j + 2; break
            t = parse(b, j)
            j = t['end']
        return {'tag': tag, 'indef': True, 'start': start, 'content_start': cs,
                'content_end': ce, 'end': end}
    elif l < 0x80:
        ln = l; hs = i
    else:
        n = l & 0x7f
        ln = int.from_bytes(b[i:i+n], 'big'); hs = i + n
    return {'tag': tag, 'indef': False, 'start': start, 'content_start': hs,
            'content_end': hs + ln, 'end': hs + ln}

def enc_len(n):
    if n < 0x80: return bytes([n])
    x = n.to_bytes((n.bit_length()+7)//8, 'big')
    return bytes([0x80 | len(x)]) + x

def children(b, t):
    out = []
    i = t['content_start']
    while i < t['content_end']:
        c = parse(b, i)
        out.append(c)
        i = c['end']
    return out

def rebuild(b, t, def_outer=False, def_ctx=False, def_sd=False, def_certs=False):
    # parse ContentInfo { OID, [0] { SignedData } }
    ch = children(b, t)
    if len(ch) < 2 or ch[1]['tag'] != 0xa0: raise ValueError('bad ContentInfo')
    oid, ctx = ch[0], ch[1]
    oid_bytes = b[oid['start']:oid['end']]
    ctx_ch = children(b, ctx)
    if not ctx_ch or ctx_ch[0]['tag'] != 0x30: raise ValueError('bad SignedData')
    sd = ctx_ch[0]
    sd_bytes_orig = b[sd['start']:sd['end']]

    # recursively rebuild SignedData children; only certificates [0] is optional
    sd_children = children(b, sd)
    new_sd_children = []
    for c in sd_children:
        raw = b[c['start']:c['end']]
        if def_certs and c['tag'] == 0xa0:
            raw = bytes([0xa0]) + enc_len(c['content_end'] - c['content_start']) + b[c['content_start']:c['content_end']]
        new_sd_children.append(raw)
    sd_content = b''.join(new_sd_children)
    sd_out = (bytes([0x30]) + (enc_len(len(sd_content)) if def_sd else b'\x80') +
              sd_content + (b'' if def_sd else b'\x00\x00'))
    ctx_content = sd_out
    ctx_out = (bytes([0xa0]) + (enc_len(len(ctx_content)) if def_ctx else b'\x80') +
               ctx_content + (b'' if def_ctx else b'\x00\x00'))
    outer_content = oid_bytes + ctx_out
    outer_out = (bytes([0x30]) + (enc_len(len(outer_content)) if def_outer else b'\x80') +
                 outer_content + (b'' if def_outer else b'\x00\x00'))
    return outer_out

if __name__ == '__main__':
    src = sys.argv[1]
    b = open(src, 'rb').read()
    t = parse(b, 0)
    if t['end'] != len(b): raise SystemExit('trailing bytes')
    modes = {
        'def_outer': dict(def_outer=True),
        'def_ctx': dict(def_ctx=True),
        'def_sd': dict(def_sd=True),
        'def_certs': dict(def_certs=True),
        'def_all': dict(def_outer=True, def_ctx=True, def_sd=True, def_certs=True),
        'def_sd_ctx': dict(def_ctx=True, def_sd=True),
        'def_sd_certs': dict(def_sd=True, def_certs=True),
    }
    for name, kw in modes.items():
        out = rebuild(b, t, **kw)
        p = src.replace('.cms', '_' + name + '.cms')
        open(p, 'wb').write(out)
        print(p, len(out))
