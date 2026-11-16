/* ==== FUN_183b538e4 @ 183b538e4 size=188 ==== */

long FUN_183b538e4(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = 0;
  if (param_1 != 0) {
    lVar1 = func_0x000188140aa0();
    lVar3 = 0;
    if (lVar1 != 0) {
      lVar1 = func_0x000188140ab0(param_1);
      uVar2 = func_0x000188141250(param_1);
      if (lVar1 < 1) {
        FUN_183b75268("%s: Invalid size = %jd");
        lVar3 = 0;
      }
      else {
        lVar3 = _create_provider(uVar2,0);
        if (lVar3 != 0) {
          *(long *)(lVar3 + 0x20) = lVar1;
          *(undefined8 *)(lVar3 + 0x58) = 0;
          *(code **)(lVar3 + 0x50) = _getCFDataBytePointer;
          *(code **)(lVar3 + 0x60) = _cf_get_bytes_at_position;
          *(code **)(lVar3 + 0x48) = _releaseCFData;
        }
      }
    }
  }
  return lVar3;
}



/* ==== FUN_183bd603c @ 183bd603c size=652 ==== */

long FUN_183bd603c(ulong param_1,long param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  long lVar2;
  long lVar3;
  
  if (4 < param_1) {
    return 0;
  }
  if ((1L << (param_1 & 0x3f) & 0x1aU) == 0) {
    return 0;
  }
  if (param_4 != 0) {
    lVar1 = func_0x000188140d60(param_4);
    if (DAT_1edf367a0 != -1) {
      func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
    }
    if ((lVar1 == DAT_1edf36a20) && (*(int *)(*(long *)(param_4 + 0x18) + 0x18) == 9)) {
      return 0;
    }
    if (*(ulong *)(*(long *)(param_4 + 0x18) + 0x30) != param_1) {
      return 0;
    }
  }
  lVar1 = FUN_183b6f8bc(param_3);
  lVar2 = FUN_183b739b8();
  if (lVar1 != 0) {
    func_0x000188141240(lVar1);
  }
  if (lVar2 != 0) {
    lVar1 = *(long *)(lVar2 + 0x18);
    if (param_1 == *(ulong *)(lVar1 + 0x30)) {
      if (param_2 != 0) {
        if (*(int *)(lVar1 + 0x18) == 6) {
          lVar1 = *(long *)(*(long *)(lVar1 + 0x60) + 0x38);
        }
        else {
          if (*(int *)(lVar1 + 0x18) != 10) {
                    /* WARNING: Subroutine does not return */
            FUN_183c19214("CGColorSpaceICCGetRange",0x236,
                          "/Library/Caches/com.apple.xbs/418A84E5-A935-45BB-BEF3-31726BD24C5D/TemporaryDirectory.myKecQ/Sources/CoreGraphics/CoreGraphics/ColorSpaces/CGColorSpace_ICC.c"
                          ,
                          "s->state->type == kCGColorSpaceICCBased || s->state->type == kCGColorSpaceProfileSets"
                          ,"Colorspace not ICC. type = %d");
          }
          lVar1 = _CGColorSpaceProfileSetsGetRange();
        }
        lVar3 = 0;
        do {
          if (*(double *)(param_2 + lVar3 * 8) != *(double *)(lVar1 + lVar3 * 8))
          goto LAB_183bd61c0;
          lVar3 = lVar3 + 1;
          param_1 = param_1 - 1;
        } while (param_1 != 0);
        lVar1 = *(long *)(lVar2 + 0x18);
      }
      if (*(int *)(lVar1 + 0x18) != 6 && *(int *)(lVar1 + 0x18) != 10) {
                    /* WARNING: Subroutine does not return */
        FUN_183c19214("CGColorSpaceICCSetAlternate",0x24c,
                      "/Library/Caches/com.apple.xbs/418A84E5-A935-45BB-BEF3-31726BD24C5D/TemporaryDirectory.myKecQ/Sources/CoreGraphics/CoreGraphics/ColorSpaces/CGColorSpace_ICC.c"
                      ,
                      "s->state->type == kCGColorSpaceICCBased || s->state->type == kCGColorSpaceProfileSets"
                      ,"Colorspace not ICC. type = %d");
      }
      lVar1 = *(long *)(*(long *)(lVar1 + 0x60) + 0x30);
      if (lVar1 != 0) {
        lVar3 = func_0x000188140d60(lVar1);
        if (DAT_1edf367a0 != -1) {
          func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
        }
        if (lVar3 == DAT_1edf36a20) {
          func_0x000188141240(lVar1);
        }
      }
      if (param_4 != 0) {
        func_0x000188141250(param_4);
      }
      *(long *)(*(long *)(*(long *)(lVar2 + 0x18) + 0x60) + 0x30) = param_4;
      return lVar2;
    }
LAB_183bd61c0:
    lVar1 = func_0x000188140d60(lVar2);
    if (DAT_1edf367a0 != -1) {
      func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
    }
    if (lVar1 == DAT_1edf36a20) {
      func_0x000188141240(lVar2);
    }
  }
  if (param_4 == 0) {
    return 0;
  }
  func_0x000188141250(param_4);
  return param_4;
}



/* ==== FUN_183ca244c @ 183ca244c size=220 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long FUN_183ca244c(void)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  undefined1 auStack_1038 [4096];
  long local_38;
  
  (*_DAT_1e1f91910)();
  local_38 = *_DAT_1e0186220;
  lVar1 = _CGPDFStreamCreateFilterChainExcluding();
  if (lVar1 == 0) {
    lVar2 = 0;
  }
  else {
    lVar2 = func_0x00018814c4e0(*_DAT_1e00fe6a8,0);
    if (lVar2 != 0) {
      do {
        uVar3 = FUN_183bd4a90(lVar1,auStack_1038,0x1000);
        func_0x000188140a70(lVar2,auStack_1038,uVar3);
      } while (0xfff < uVar3);
    }
    func_0x000188141240(lVar1);
  }
  if (*_DAT_1e0186220 == local_38) {
    return lVar2;
  }
  lVar1 = func_0x000188138130();
  return lVar1;
}



