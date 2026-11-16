// FUN_fffffff00994aaf4 @ fffffff00994aaf4 size=188

void FUN_fffffff00994aaf4(long *param_1,long param_2)

{
  uint uVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;
  
  param_1[3] = param_2;
  uVar1 = *(uint *)(param_1 + 5);
  if (uVar1 == 1) {
    param_1[4] = (long)(param_1 + 3);
  }
  else {
    lVar3 = (long)(int)uVar1 << 3;
    if (0x7fffffff < uVar1) {
      lVar3 = -0x8000000000000000;
    }
    lVar3 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ff12c8,lVar3);
    param_1[4] = lVar3;
    if ((int)param_1[5] < 1) {
      return;
    }
  }
  lVar3 = 0;
  do {
    lVar4 = param_1[3];
    uVar2 = (**(code **)(*param_1 + 0x88))(param_1,lVar3);
    *(ulong *)(param_1[4] + lVar3 * 8) = lVar4 + (uVar2 & 0xffffffff);
    lVar3 = lVar3 + 1;
  } while (lVar3 < (int)param_1[5]);
  return;
}

