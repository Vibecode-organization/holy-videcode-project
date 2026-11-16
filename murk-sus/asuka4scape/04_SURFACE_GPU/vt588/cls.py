import sys,struct; sys.path.insert(0,'/home/femboychik/work/vt588')
from kc import *
M64=(1<<64)-1
REG={'x0':0,'x1':1}
def cstr(va):
    o=voff(va); e=D.index(b'\0',o); return D[o:e].decode('utf-8','replace')
def parse_reg(reg):
    return int(reg[1:]) if reg.startswith('x') and reg[1:].isdigit() else None
def classes():
    out=[]
    for pc in [h for h in ALLBL if h]:
        pass
