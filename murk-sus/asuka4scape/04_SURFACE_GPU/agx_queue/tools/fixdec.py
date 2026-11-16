KBASE=0xfffffff007004000
def dec(raw):
    if (raw>>62)&1: return ('bind', raw & 0xFFFFFF)
    if (raw>>63)&1: return ('auth', KBASE + (raw & 0xFFFFFFFF))
    return ('rebase', KBASE + (raw & 0x7FFFFFFFFFF))
