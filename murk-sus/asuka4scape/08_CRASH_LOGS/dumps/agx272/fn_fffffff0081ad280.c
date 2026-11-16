// FUN_fffffff0081ad280 @ fffffff0081ad280 size=336

void FUN_fffffff0081ad280(long *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  
  uVar2 = param_2 >> 6;
  uVar3 = (ulong)uVar2;
  uVar1 = param_2 & 0x3f;
  if (uVar1 == 0) {
    param_1[3] = param_1[uVar3 ^ 3];
    if (uVar2 == 3) {
      lVar6 = 0;
    }
    else {
      lVar6 = param_1[2 - uVar3];
    }
    param_1[2] = lVar6;
    if (param_2 < 0x80) {
      param_1[1] = param_1[1 - uVar3];
      if (param_2 < 0x40) {
        *param_1 = *param_1;
        return;
      }
      *param_1 = 0;
      return;
    }
    *param_1 = 0;
    param_1[1] = 0;
    return;
  }
  uVar5 = (ulong)(0x40 - uVar1);
  lVar6 = (long)(int)~uVar2;
  if (uVar2 == 3) {
    lVar7 = 0;
    param_1[3] = param_1[uVar3 ^ 3] << uVar1;
    if (0x7f < param_2) goto LAB_fffffff0081ad2c8;
LAB_fffffff0081ad320:
    param_1[2] = (ulong)param_1[lVar6 + 2] >> (uVar5 & 0x3f) | lVar7 << uVar1;
    lVar4 = param_1[1 - uVar3];
    if (param_2 < 0x40) {
      param_1[1] = (ulong)param_1[lVar6 + 1] >> (uVar5 & 0x3f) | lVar4 << uVar1;
      lVar6 = *param_1;
      goto LAB_fffffff0081ad378;
    }
  }
  else {
    param_1[3] = (ulong)param_1[lVar6 + 3] >> (uVar5 & 0x3f) | param_1[uVar3 ^ 3] << uVar1;
    lVar7 = param_1[2 - uVar3];
    if (param_2 < 0x80) goto LAB_fffffff0081ad320;
LAB_fffffff0081ad2c8:
    lVar4 = 0;
    param_1[2] = lVar7 << uVar1;
  }
  lVar6 = 0;
  param_1[1] = lVar4 << uVar1;
LAB_fffffff0081ad378:
  *param_1 = lVar6 << uVar1;
  return;
}

