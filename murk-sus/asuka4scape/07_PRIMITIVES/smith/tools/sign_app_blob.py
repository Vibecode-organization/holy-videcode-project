#!/usr/bin/env python3
"""sign_app_blob.py in out ident ent.plist resdir_or_dash [cms.der] [real_cd.bin]
SuperBlob: (0 real_cd|our cd1) (0x1000 our cd2) (5 ent) (0x10000 real CMS)
"""
import sys,os,struct,hashlib
sys.path.insert(0,"/home/femboychik/claude_code/smith/tools")
from sign_app import first_section_off, find_linkedit, find_code_sig, add_lc, build_cd, ent_blob, superblob

def sign(inp,outp,ident,ent_path,res_path,cms_path,realcd_path):
    xml=open(ent_path,'rb').read(); eb=ent_blob(xml)
    rb=open(res_path,'rb').read() if res_path and res_path!='-' else None
    cms=open(cms_path,'rb').read(); cmsb=struct.pack('>II',0xfade0b01,8+len(cms))+cms
    realcd=open(realcd_path,'rb').read() if realcd_path and realcd_path!='-' else None
    d=open(inp,'rb').read(); lc,dataoff,datasize=find_code_sig(d)
    if lc is None:
        b,lc=add_lc(d); b=bytes(b); sig_off=(len(b)+15)&~15
    else:
        sig_off=dataoff; b=bytes(d[:sig_off])
    le=find_linkedit(b)
    if le is None: raise SystemExit('no __LINKEDIT')
    le_fileoff=struct.unpack_from('<Q',b,le+40)[0]
    def build(sb_len,sig_off,le_size):
        tmp=bytearray(b); struct.pack_into('<II',tmp,lc+8,sig_off,sb_len)
        struct.pack_into('<Q',tmp,le+32,(le_size+0x3fff)&~0x3fff)
        struct.pack_into('<Q',tmp,le+48,le_size)
        cd1=build_cd(bytes(tmp),sig_off,ident,1,0,hashlib.sha1(eb).digest(),hashlib.sha1(rb).digest() if rb else None)
        cd2=build_cd(bytes(tmp),sig_off,ident,2,0,hashlib.sha256(eb).digest(),hashlib.sha256(rb).digest() if rb else None)
        entries=[]
        if realcd: entries.append((0,realcd))
        else: entries.append((0,cd1))
        entries += [(0x1000,cd2),(5,eb),(0x10000,cmsb)]
        return tmp,superblob(entries)
    sb_len=0; le_size=sig_off-le_fileoff
    for _ in range(6):
        tmp,sb=build(sb_len,sig_off,le_size)
        if len(sb)==sb_len: break
        sb_len=len(sb); le_size=sig_off+sb_len-le_fileoff
    else: raise SystemExit('no converge')
    out=bytearray(tmp); out+=b'\0'*(sig_off-len(out)); out[sig_off:sig_off+len(sb)]=sb
    open(outp,'wb').write(out); os.chmod(outp,0o755)
    print('signed',outp,'ident',ident,'size',len(out),'sig',hex(sig_off),len(sb),'realcd',len(realcd) if realcd else 0)

if __name__=='__main__':
    if len(sys.argv) not in (8,9):
        print(__doc__); sys.exit(1)
    sign(sys.argv[1],sys.argv[2],sys.argv[3],sys.argv[4],sys.argv[5],sys.argv[6],sys.argv[7] if len(sys.argv)>7 else '-')
