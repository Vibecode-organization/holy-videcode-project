// FUN_fffffff009952288 @ fffffff009952288 size=172

ulong FUN_fffffff009952288(int *param_1,int param_2)

{
  int iVar1;
  ulong uVar2;
  ulong extraout_x8;
  
  if (param_2 < 4) {
    if (param_2 - 1U < 2) {
      LOAcquire();
      iVar1 = *param_1;
      *param_1 = iVar1 + -1;
      goto LAB_fffffff0099522e4;
    }
    if (param_2 == 3) {
      iVar1 = *param_1;
      *param_1 = iVar1 + -1;
      LORelease();
      goto LAB_fffffff0099522e4;
    }
  }
  else if ((param_2 == 4) || (param_2 == 5)) {
    LOAcquire();
    iVar1 = *param_1;
    *param_1 = iVar1 + -1;
    LORelease();
    goto LAB_fffffff0099522e4;
  }
  iVar1 = *param_1;
  *param_1 = iVar1 + -1;
LAB_fffffff0099522e4:
  if (iVar1 == 0) {
    FUN_fffffff0099837a8();
    uVar2 = extraout_x8;
  }
  else {
    uVar2 = (ulong)(iVar1 - 1);
  }
  return uVar2;
}

