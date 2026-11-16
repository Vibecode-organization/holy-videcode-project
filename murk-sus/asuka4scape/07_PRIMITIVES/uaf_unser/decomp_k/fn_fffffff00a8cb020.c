// FUN_fffffff00a8cb020 @ fffffff00a8cb020 size=80
// CALLERS:
//   fffffff00a8d99b8 FUN_fffffff00a8d96f4@fffffff00a8d96f4

void FUN_fffffff00a8cb020(undefined8 param_1)

{
  long lVar1;
  
  lVar1 = (**(code **)(DAT_fffffff00ad95dc8 + 0x68))();
  *(undefined4 *)(lVar1 + 0xc) = 0x3e;
  *(undefined8 *)(lVar1 + 0x10) = param_1;
  return;
}

