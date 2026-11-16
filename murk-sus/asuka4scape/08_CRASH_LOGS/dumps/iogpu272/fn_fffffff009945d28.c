// FUN_fffffff009945d28 @ fffffff009945d28 size=36

void FUN_fffffff009945d28(long param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0xe4);
  *(uint *)(param_1 + 0xe4) = uVar1 + 1;
  if (uVar1 < 0xfffffff) {
    return;
  }
  FUN_fffffff009983434();
  return;
}

