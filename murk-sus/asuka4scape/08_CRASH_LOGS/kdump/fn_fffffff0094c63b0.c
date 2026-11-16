// FUN_fffffff0094c63b0 @ fffffff0094c63b0 size=1812
// CALLERS:
//   fffffff00afb80ab ?
//   fffffff0094c5b44 FUN_fffffff0094c5408@fffffff0094c5408
// CALLS:
//   fffffff0094c786c FUN_fffffff0094c786c
//   fffffff0094c9bb4 thunk_EXT_FUN_80110000033502b4
//   fffffff0094c53a0 FUN_fffffff0094c53a0
//   fffffff0094c79bc FUN_fffffff0094c79bc

undefined8
FUN_fffffff0094c63b0
          (ulong *param_1,undefined8 param_2,long param_3,ulong *param_4,ulong *param_5,int param_6)

{
  ulong *puVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  ulong uVar5;
  ulong uVar6;
  ulong unaff_x30;
  
  puVar1 = (ulong *)0x0;
  if (param_6 == 0) {
    puVar1 = param_5;
  }
  if (param_3 == 9) {
    iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff00777088c);
    if (iVar3 == 0) {
      uVar4 = FUN_fffffff0094c53a0(param_1);
      if ((int)uVar4 == 0) {
        return uVar4;
      }
      uVar5 = *param_4;
      uVar6 = 0x100008;
      goto LAB_fffffff0094c67e0;
    }
    iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff00777098c,9);
    if (iVar3 == 0) {
      uVar4 = FUN_fffffff0094c53a0(param_1);
      if ((int)uVar4 == 0) {
        return uVar4;
      }
      uVar5 = *param_4 | 0x8000000000;
      goto LAB_fffffff0094c67e4;
    }
    iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff00777085d,9);
    if (iVar3 == 0) {
      uVar4 = FUN_fffffff0094c53a0(param_1);
      if ((int)uVar4 == 0) {
        return uVar4;
      }
      uVar5 = *param_4 | 0x2000000;
      goto LAB_fffffff0094c67e4;
    }
    iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff007770870,9);
    if (iVar3 == 0) {
      uVar4 = FUN_fffffff0094c53a0(param_1);
      if ((int)uVar4 == 0) {
        return uVar4;
      }
      uVar5 = *param_4 | 0x4000000;
      goto LAB_fffffff0094c67e4;
    }
    iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff007770879,9);
    if (iVar3 == 0) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0094c6904);
        (*pcVar2)();
      }
      uVar4 = FUN_fffffff0094c786c(param_1,param_4,puVar1);
      return uVar4;
    }
LAB_fffffff0094c6760:
    uVar5 = *param_1;
    uVar6 = param_1[1];
  }
  else {
    if (param_3 != 10) {
      if (param_3 == 0xb) {
        iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff0077708c7);
        if (iVar3 == 0) {
          uVar4 = FUN_fffffff0094c53a0(param_1);
          if ((int)uVar4 == 0) {
            return uVar4;
          }
          uVar5 = *param_4 | 0x400000000000;
          goto LAB_fffffff0094c67e4;
        }
        iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff0077708f0,0xb);
        if (iVar3 == 0) {
          uVar4 = FUN_fffffff0094c53a0(param_1);
          if ((int)uVar4 == 0) {
            return uVar4;
          }
          uVar5 = *param_4 | 0x200;
          goto LAB_fffffff0094c67e4;
        }
        iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff007770905,0xb);
        if (iVar3 == 0) {
          uVar4 = FUN_fffffff0094c53a0(param_1);
          if ((int)uVar4 == 0) {
            return uVar4;
          }
          uVar5 = *param_4 | 0x800;
          goto LAB_fffffff0094c67e4;
        }
        iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff00777091a,0xb);
        if (iVar3 == 0) {
          uVar4 = FUN_fffffff0094c53a0(param_1);
          if ((int)uVar4 == 0) {
            return uVar4;
          }
          uVar5 = *param_4 | 0x2000;
          goto LAB_fffffff0094c67e4;
        }
        iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff00777092f,0xb);
        if (iVar3 == 0) {
          uVar4 = FUN_fffffff0094c53a0(param_1);
          if ((int)uVar4 == 0) {
            return uVar4;
          }
          uVar5 = *param_4 | 0x100000000000;
          goto LAB_fffffff0094c67e4;
        }
        iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff00777093a,0xb);
        if (iVar3 == 0) {
          uVar4 = FUN_fffffff0094c53a0(param_1);
          if ((int)uVar4 == 0) {
            return uVar4;
          }
          uVar5 = *param_4 | 0x4000;
          goto LAB_fffffff0094c67e4;
        }
        iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff007770945,0xb);
        if (iVar3 == 0) {
          uVar4 = FUN_fffffff0094c53a0(param_1);
          if ((int)uVar4 == 0) {
            return uVar4;
          }
          uVar5 = *param_4 | 0x8000;
          goto LAB_fffffff0094c67e4;
        }
      }
      goto LAB_fffffff0094c6760;
    }
    iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff007770950);
    if (iVar3 == 0) {
      uVar4 = FUN_fffffff0094c53a0(param_1);
      if ((int)uVar4 == 0) {
        return uVar4;
      }
      uVar5 = *param_4;
      uVar6 = 0x800000100000;
LAB_fffffff0094c67e0:
      uVar5 = uVar5 | uVar6;
LAB_fffffff0094c67e4:
      *param_4 = uVar5;
      return 1;
    }
    iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff00777095a,10);
    if (iVar3 == 0) {
      uVar4 = FUN_fffffff0094c53a0(param_1);
      if ((int)uVar4 == 0) {
        return uVar4;
      }
      uVar5 = *param_4;
      uVar6 = 0x58600003f0d0;
      goto LAB_fffffff0094c67e0;
    }
    iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff007770964,10);
    if (iVar3 == 0) {
LAB_fffffff0094c6830:
      uVar4 = FUN_fffffff0094c53a0(param_1);
      if ((int)uVar4 == 0) {
        return uVar4;
      }
      uVar5 = *param_4 | 0x20;
      goto LAB_fffffff0094c67e4;
    }
    iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff00777096e,10);
    if (iVar3 == 0) {
      uVar4 = FUN_fffffff0094c53a0(param_1);
      if ((int)uVar4 == 0) {
        return uVar4;
      }
      uVar5 = *param_4 | 0xf00;
      goto LAB_fffffff0094c67e4;
    }
    iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff007770895,10);
    if (iVar3 == 0) {
      uVar4 = FUN_fffffff0094c53a0(param_1);
      if ((int)uVar4 == 0) {
        return uVar4;
      }
      uVar5 = *param_4 | 0x800000000000;
      goto LAB_fffffff0094c67e4;
    }
    iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff00777089f,10);
    if (iVar3 == 0) {
      uVar4 = FUN_fffffff0094c53a0(param_1);
      if ((int)uVar4 == 0) {
        return uVar4;
      }
      uVar5 = *param_4 | 0x10;
      goto LAB_fffffff0094c67e4;
    }
    iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff0077708a9,10);
    if (iVar3 == 0) {
      uVar4 = FUN_fffffff0094c53a0(param_1);
      if ((int)uVar4 == 0) {
        return uVar4;
      }
      uVar5 = *param_4 | 0x20000;
      goto LAB_fffffff0094c67e4;
    }
    iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff0077708b3,10);
    if (iVar3 == 0) goto LAB_fffffff0094c6830;
    iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff0077708bd,10);
    if (iVar3 == 0) {
      uVar4 = FUN_fffffff0094c53a0(param_1);
      if ((int)uVar4 == 0) {
        return uVar4;
      }
      uVar5 = *param_4 | 0x40;
      goto LAB_fffffff0094c67e4;
    }
    iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff0077708d2,10);
    if (iVar3 == 0) {
      uVar4 = FUN_fffffff0094c53a0(param_1);
      if ((int)uVar4 == 0) {
        return uVar4;
      }
      uVar5 = *param_4 | 0x80;
      goto LAB_fffffff0094c67e4;
    }
    iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff0077708dc,10);
    if (iVar3 == 0) {
      uVar4 = FUN_fffffff0094c53a0(param_1);
      if ((int)uVar4 == 0) {
        return uVar4;
      }
      uVar5 = *param_4 | 0x10000;
      goto LAB_fffffff0094c67e4;
    }
    iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff0077708e6,10);
    if (iVar3 == 0) {
      uVar4 = FUN_fffffff0094c53a0(param_1);
      if ((int)uVar4 == 0) {
        return uVar4;
      }
      uVar5 = *param_4 | 0x100;
      goto LAB_fffffff0094c67e4;
    }
    iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff0077708fb,10);
    if (iVar3 == 0) {
      uVar4 = FUN_fffffff0094c53a0(param_1);
      if ((int)uVar4 == 0) {
        return uVar4;
      }
      uVar5 = *param_4 | 0x400;
      goto LAB_fffffff0094c67e4;
    }
    iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff007770910,10);
    if (iVar3 == 0) {
      uVar4 = FUN_fffffff0094c53a0(param_1);
      if ((int)uVar4 == 0) {
        return uVar4;
      }
      uVar5 = *param_4 | 0x1000;
      goto LAB_fffffff0094c67e4;
    }
    iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff007770925,10);
    if (iVar3 == 0) {
      uVar4 = FUN_fffffff0094c53a0(param_1);
      if ((int)uVar4 == 0) {
        return uVar4;
      }
      uVar5 = *param_4 | 0x80000000000;
      goto LAB_fffffff0094c67e4;
    }
    iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff007770978,10);
    if (iVar3 == 0) {
      uVar4 = FUN_fffffff0094c53a0(param_1);
      if ((int)uVar4 == 0) {
        return uVar4;
      }
      uVar5 = *param_4 | 0x2000000000;
      goto LAB_fffffff0094c67e4;
    }
    iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff007770982,10);
    if (iVar3 == 0) {
      uVar4 = FUN_fffffff0094c53a0(param_1);
      if ((int)uVar4 == 0) {
        return uVar4;
      }
      uVar5 = *param_4 | 0x4000000000;
      goto LAB_fffffff0094c67e4;
    }
    iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff007770853,10);
    if (iVar3 == 0) {
      uVar4 = FUN_fffffff0094c53a0(param_1);
      if ((int)uVar4 == 0) {
        return uVar4;
      }
      uVar5 = *param_4 | 0x400000;
      goto LAB_fffffff0094c67e4;
    }
    iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff007770849,10);
    if (iVar3 == 0) {
      uVar4 = FUN_fffffff0094c53a0(param_1);
      if ((int)uVar4 == 0) {
        return uVar4;
      }
      uVar5 = *param_4;
      uVar6 = 0x1000002400000;
      goto LAB_fffffff0094c67e0;
    }
    iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff007770866,10);
    if (iVar3 == 0) {
      uVar4 = FUN_fffffff0094c53a0(param_1);
      if ((int)uVar4 == 0) {
        return uVar4;
      }
      uVar5 = *param_4;
      uVar6 = 0x8004000000;
      goto LAB_fffffff0094c67e0;
    }
    iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff007770882,10);
    if (iVar3 == 0) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0094c6abc);
        (*pcVar2)();
      }
      uVar4 = FUN_fffffff0094c79bc(param_1,param_4,puVar1);
      return uVar4;
    }
    iVar3 = thunk_EXT_FUN_80110000033502b4(param_2,&DAT_fffffff0077706f0,10);
    if (iVar3 != 0) goto LAB_fffffff0094c6760;
    uVar5 = *param_1;
    uVar6 = param_1[1];
    if (puVar1 != (ulong *)0x0) {
      if (uVar6 < uVar5) goto LAB_fffffff0094c6ac0;
      *param_5 = uVar5;
      param_5[1] = uVar6 - uVar5;
    }
    *param_4 = *param_4 | 0x80000000;
  }
  if (uVar5 <= uVar6) {
    *param_1 = uVar6;
    return 1;
  }
LAB_fffffff0094c6ac0:
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0x5519,0xfffffff0094c6ac4);
  (*pcVar2)();
}

