"""vectorized bl/b xref scan for a target set; groups by caller."""
import struct, sys, pickle
import numpy as np

KC = '/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache'
SEGS = [
    ('__PRELINK_TEXT',   0xfffffff00700c000, 0x008000, 0xbac000),
    ('__TEXT_EXEC',      0xfffffff00814c000, 0x1148000, 0x2924000),
    ('__TEXT_BOOT_EXEC', 0xfffffff00aa70000, 0x3a6c000, 0x008000),
]
d = open(KC, 'rb').read()

STUBS = {
    0xfffffff00880c148: 'stub_880c148',
    0xfffffff008908934: 'stub_8908934',
    0xfffffff008b74944: 'stub_8b74944',
    0xfffffff008c1ffcc: 'stub_8c1ffcc',
    0xfffffff008c78924: 'stub_8c78924',
    0xfffffff008eb8980: 'stub_8eb8980',
    0xfffffff0092ba10c: 'stub_92ba10c',
    0xfffffff009363c20: 'stub_9363c20',
    0xfffffff0094be7ac: 'stub_94be7ac',
    0xfffffff0097ba7c4: 'stub_97ba7c4',
    0xfffffff0099a046c: 'stub_99a046c',
    0xfffffff0099b8ba8: 'stub_99b8ba8',
    0xfffffff009a4815c: 'stub_9a4815c',
    0xfffffff009a99d40: 'stub_9a99d40',
    0xfffffff009c49764: 'stub_9c49764',
    0xfffffff009e9896c: 'stub_9e9896c',
    0xfffffff009f0942c: 'stub_9f0942c',
    0xfffffff009f6f1c8: 'stub_9f6f1c8',
    0xfffffff009fa975c: 'stub_9fa975c',
}
TARGETS = dict(STUBS)
TARGETS.update({
    0xfffffff00a8d8754: 'OSUnserialize_dispatch',
    0xfffffff00a8d96f4: 'OSUnserializeBinary',
    0xfffffff00a8d5ea4: 'OSUnserializeXML_bison',
    0xfffffff00a8d846c: 'sub_a8d846c',
    0xfffffff00a8d5c98: 'sub_a8d5c98',
})

hits = []  # (site_va, target_va)
for name, sva, so, sz in SEGS:
    n = sz // 4
    w = np.frombuffer(d[so:so + n * 4], dtype='<u4').astype(np.uint32)
    op = (w >> np.uint32(26)) & np.uint32(0x3F)
    idx = np.nonzero((op == np.uint32(0x25)) | (op == np.uint32(0x05)))[0]
    for i in idx:
        wi = int(w[i])
        imm = wi & 0x03FFFFFF
        if imm & 0x02000000:
            imm -= 0x04000000
        off = imm * 4
        pc = sva + int(i) * 4
        tgt = (pc + off) & 0xFFFFFFFFFFFFFFFF
        if tgt in TARGETS:
            hits.append((pc, tgt, 'bl' if ((wi >> 26) & 0x3F) == 0x25 else 'b', name))

print('total hits', len(hits))
by = {}
for pc, tgt, kind, seg in hits:
    by.setdefault(tgt, []).append((pc, kind, seg))
for tgt, nm in TARGETS.items():
    v = by.get(tgt, [])
    if not v:
        continue
    print('== %-26s %016x  %d' % (nm, tgt, len(v)))
    for pc, kind, seg in sorted(v):
        print('    %016x %s %s' % (pc, kind, seg))
pickle.dump(hits, open('/home/femboychik/work/keytype/blhits.pkl', 'wb'))
