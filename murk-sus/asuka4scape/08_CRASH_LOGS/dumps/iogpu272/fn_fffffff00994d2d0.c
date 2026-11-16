// FUN_fffffff00994d2d0 @ fffffff00994d2d0 size=140

void FUN_fffffff00994d2d0(long *param_1)

{
  long lVar1;
  
  if (0 < (int)param_1[5]) {
    lVar1 = 0;
    do {
      (**(code **)(*param_1 + 0xb8))
                (param_1,lVar1,*(undefined4 *)((long)param_1 + (lVar1 << 4 | 8U) + 0x40));
      lVar1 = lVar1 + 1;
    } while (lVar1 < (int)param_1[5]);
  }
  return;
}

