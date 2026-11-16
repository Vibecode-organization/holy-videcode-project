// FUN_fffffff0081b7b5c @ fffffff0081b7b5c size=188

void FUN_fffffff0081b7b5c(long param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (*(long *)(param_1 + 0x10) == 0) {
    thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! Using uninitialized validator class\n");
    return;
  }
  uVar1 = **(uint **)(param_1 + 8);
  *(uint *)(param_1 + 0x18) = uVar1;
  uVar2 = (*(uint **)(param_1 + 8))[8];
  *(uint *)(param_1 + 0x1c) = uVar2;
  if (((ulong)uVar1 < *(ulong *)(param_1 + 0x28)) && ((ulong)uVar2 < *(ulong *)(param_1 + 0x28))) {
    return;
  }
  thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! read_index out of bounds\n");
  return;
}

