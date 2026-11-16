// FUN_fffffff0099428a8 @ fffffff0099428a8 size=36

void FUN_fffffff0099428a8(long *param_1,long param_2)

{
  int iVar1;
  
  *param_1 = param_2;
  iVar1 = *(int *)(param_2 + 0xa0);
  *(undefined4 *)(param_1 + 1) = 0;
  *(uint *)((long)param_1 + 0xc) = iVar1 + 0x3fU >> 6;
  param_1[2] = -0x100000000;
  return;
}

