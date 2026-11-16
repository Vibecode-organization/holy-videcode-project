// FUN_fffffff009c46fc8 @ fffffff009c46fc8 size=48

ulong FUN_fffffff009c46fc8(ulong param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  ulong uVar3;
  ulong extraout_x8;
  undefined1 auVar4 [12];
  
  if (param_2 == 0) {
    FUN_fffffff009c494bc();
  }
  else if (param_2 < 0xfffffff) {
    return param_1;
  }
  auVar4 = FUN_fffffff009c494f0();
  iVar1 = auVar4._8_4_;
  piVar2 = auVar4._0_8_;
  if (iVar1 < 4) {
    if (iVar1 - 1U < 2) {
      LOAcquire();
      iVar1 = *piVar2;
      *piVar2 = iVar1 + -1;
      goto LAB_fffffff009c47054;
    }
    if (iVar1 == 3) {
      iVar1 = *piVar2;
      *piVar2 = iVar1 + -1;
      LORelease();
      goto LAB_fffffff009c47054;
    }
  }
  else if ((iVar1 == 4) || (iVar1 == 5)) {
    LOAcquire();
    iVar1 = *piVar2;
    *piVar2 = iVar1 + -1;
    LORelease();
    goto LAB_fffffff009c47054;
  }
  iVar1 = *piVar2;
  *piVar2 = iVar1 + -1;
LAB_fffffff009c47054:
  if (iVar1 == 0) {
    FUN_fffffff009c49488();
    uVar3 = extraout_x8;
  }
  else {
    uVar3 = (ulong)(iVar1 - 1);
  }
  return uVar3;
}

