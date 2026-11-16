// FUN_fffffff0081d7818 @ fffffff0081d7818 size=128

void FUN_fffffff0081d7818(long *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = (**(code **)(*param_1 + 0x738))();
  *param_2 = uVar1;
  param_2[6] = 0xd40004000;
  *(int *)(param_2 + 7) = (int)DAT_fffffff00ae21810;
  *(undefined8 *)((long)param_2 + 0x3c) = DAT_fffffff007113fb0;
  *(undefined4 *)(param_1 + 0xc0) = 0x10;
  return;
}

