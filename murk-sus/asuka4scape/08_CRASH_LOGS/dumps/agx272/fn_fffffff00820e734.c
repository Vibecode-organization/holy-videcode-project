// FUN_fffffff00820e734 @ fffffff00820e734 size=44

void FUN_fffffff00820e734(long param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x38) != 0) {
    return;
  }
  uVar1 = 1;
  if (param_2 != 0) {
    *(undefined4 *)(*(long *)(param_1 + 0x20) + 0x10) = 1;
    uVar1 = 2;
  }
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  return;
}

