// FUN_fffffff0081bfaf8 @ fffffff0081bfaf8 size=68

void FUN_fffffff0081bfaf8(long param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(long *)(param_1 + 0x838) + 0x10);
  while (iVar1 != 0) {
    thunk_EXT_FUN_80110000038fe968(10);
    iVar1 = *(int *)(*(long *)(param_1 + 0x838) + 0x10);
  }
  return;
}

