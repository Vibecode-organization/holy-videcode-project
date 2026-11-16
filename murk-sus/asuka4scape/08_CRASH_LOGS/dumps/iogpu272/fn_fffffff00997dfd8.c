// FUN_fffffff00997dfd8 @ fffffff00997dfd8 size=28

void FUN_fffffff00997dfd8(long *param_1,long param_2)

{
  undefined4 uVar1;
  
  *param_1 = param_2;
  param_1[1] = 0;
  uVar1 = *(undefined4 *)(param_2 + 0x1c);
  *(int *)(param_1 + 2) = *(int *)(param_2 + 0x14) + -1;
  *(undefined4 *)((long)param_1 + 0x14) = uVar1;
  return;
}

