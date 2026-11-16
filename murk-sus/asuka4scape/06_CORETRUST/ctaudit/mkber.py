#!/usr/bin/env python3
"""Generate BER-indefinite variants of a DER CMS without touching signedAttrs.

Only outer SEQUENCE / [0] / SignedData / certificates wrappers are re-encoded,
so the bytes covered by the CMS signature stay identical.
"""
import os, sys

def read_len(b, i):
    if i >= len(b): raise ValueError('len')
    x = b[i]
    if x < 0x80:
        return x, i + 1
    n = x & 0x7f
    if n == 0 or i + 1 + n > len(b): raise ValueError('bad len')
    return int.from_bytes(b[i+1:i+1+n], 'big'), i + 1 + n

def tlv(b, i):
    start = i
    if i >= len(b): raise ValueError('eof')
    tag = b[i]; i += 1
    ln, i = read_len(b, i)
    body_start = i
    if body_start + ln > len(b): raise ValueError('overflow')
    return {'tag': tag, 'start': start, 'body': body_start, 'end': body_start + ln,
            'body_bytes': b[body_start:body_start+ln]}

def indef(tag, body):
    # tag must be constructed (0x20 bit set)
    return bytes([tag | 0x20, 0x80]) + body + b'\x00\x00'

def whole(b):
    t = tlv(b, 0)
    if t['end'] != len(b): raise ValueError('trailing')
    return t

def variant(path, mode):
    b = open(path, 'rb').read()
    outer = whole(b)
    # outer ContentInfo: SEQ { OID, [0] { SignedData } }
    oid = tlv(outer['body_bytes'], 0)
    ctx = tlv(outer['body_bytes'], oid['end'])
    if ctx['tag'] != 0xa0: raise ValueError('no [0]')
    sd = tlv(ctx['body_bytes'], 0)
    if sd['tag'] != 0x30: raise ValueError('no SignedData')
    sd_body = sd['body_bytes']

    def rewrap_sd(inner):
        if mode in ('sd', 'all'):
            return indef(0x30, inner)
        return bytes([0x30]) + enc_len(len(inner)) + inner

    def rewrap_ctx(inner):
        if mode in ('a0', 'all'):
            return indef(0xa0, inner)
        return bytes([0xa0]) + enc_len(len(inner)) + inner

    def rewrap_outer(inner):
        if mode in ('outer', 'all'):
            return indef(0x30, inner)
        return bytes([0x30]) + enc_len(len(inner)) + inner

    # optionally make certificates [0] indefinite: it is the field after encapContentInfo
    fields = []
    p = 0
    while p < len(sd_body):
        t = tlv(sd_body, p)
        fields.append(t)
        p = t['end']
    new_fields = []
    for t in fields:
        body = t['body_bytes']
        if t['tag'] == 0xa0 and mode in ('certs', 'all'):
            new_fields.append(indef(0xa0, body))
        else:
            new_fields.append(bytes([t['tag']]) + enc_len(len(body)) + body)
    new_sd_body = b''.join(new_fields)
    new_sd = rewrap_sd(new_sd_body)
    new_ctx = rewrap_ctx(new_sd)
    new_oid = bytes([oid['tag']]) + enc_len(len(oid['body_bytes'])) + oid['body_bytes']
    new_outer = rewrap_outer(new_oid + new_ctx)
    out = path.replace('.cms', '_' + mode + '.cms')
    open(out, 'wb').write(new_outer)
    print(out, len(out))

def enc_len(n):
    if n < 0x80: return bytes([n])
    x = n.to_bytes((n.bit_length()+7)//8, 'big')
    return bytes([0x80 | len(x)]) + x

if __name__ == '__main__':
    src = sys.argv[1]
    for mode in ('outer', 'a0', 'sd', 'certs', 'all'):
        try:
            variant(src, mode)
        except Exception as e:
            print('ERR', mode, e)
