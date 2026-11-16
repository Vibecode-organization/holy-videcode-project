import struct, sys
from kc import DATA
import capstone
md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
md.detail = False

TEXT    = (0xfffffff007004000, 0x8000,      0x0)
PRELINK = (0xfffffff00700c000, 0xbac000,    0x8000)
DCONST  = (0xfffffff007bb8000, 0x548000,    0xbb4000)
TEXEC   = (0xfffffff00814c000, 0x2924000,   0x1148000)
BOOTEX  = (0xfffffff00aa70000, 0x8000,      0x3a6c000)
PINFO   = (0xfffffff00aa78000, 0x23c000,    0x3a74000)
DATA_   = (0xfffffff00acb4000, 0x2b8000,    0x3cb0000)
LINKED  = (0xfffffff00af6c000, 0xb8000,     0x3f68000)
SEGS=[TEXT,PRELINK,DCONST,TEXEC,BOOTEX,PINFO,DATA_,LINKED]

def va2off(va):
    for vm,sz,fo in SEGS:
        if vm <= va < vm+sz: return fo + (va-vm)
    return None
def off2va(o):
    for vm,sz,fo in SEGS:
        if fo <= o < fo+sz: return vm + (o-fo)
    return None
def rd(va,n):
    o=va2off(va)
    if o is None: raise Exception("bad va %#x"%va)
    return DATA[o:o+n]
def u64(va): return struct.unpack('<Q',rd(va,8))[0]
def u32(va): return struct.unpack('<I',rd(va,4))[0]
def u16(va): return struct.unpack('<H',rd(va,2))[0]
def u8(va): return DATA[va2off(va)]
def cstr(va):
    o=va2off(va); e=DATA.index(b'\0',o); return DATA[o:e].decode('latin1')
def dis(va,n=0x100,end=None):
    o=va2off(va); out=[]
    if end is not None: n = end-va
    for i in md.disasm(DATA[o:o+n], va):
        out.append(i)
    return out
def pdis(va,n=0x100,end=None):
    for i in dis(va,n,end):
        print(f"{i.address:#014x}  {i.bytes.hex():<10} {i.mnemonic:<8} {i.op_str}")
def pac(v): return 0xfffffff007004000 + (v & 0x0FFFFFFF)
