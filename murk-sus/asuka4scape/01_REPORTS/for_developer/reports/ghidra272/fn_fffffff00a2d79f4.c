// FUN_fffffff00a2d79f4 @ fffffff00a2d79f4 size=84

void FUN_fffffff00a2d79f4(long *param_1,int param_2)

{
  long lVar1;
  
  lVar1 = *param_1;
  if (lVar1 != 0) {
    if (param_2 == 0) {
      FUN_fffffff00a2ba128(param_1[1],param_1[2],param_1[2] + 0x4000);
    }
    FUN_fffffff00a3061bc(lVar1);
    FUN_fffffff00a2d7f14(lVar1);
    FUN_fffffff00a22aeac(lVar1 + 8);
    *param_1 = 0;
  }
  return;
}

