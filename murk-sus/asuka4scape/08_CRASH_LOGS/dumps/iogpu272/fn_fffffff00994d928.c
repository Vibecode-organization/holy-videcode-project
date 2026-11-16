// FUN_fffffff00994d928 @ fffffff00994d928 size=36

void FUN_fffffff00994d928(long param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0xc);
  *(uint *)(param_1 + 0xc) = uVar1 + 1;
  if (uVar1 < 0xfffffff) {
    return;
  }
  FUN_fffffff009983678();
  return;
}

