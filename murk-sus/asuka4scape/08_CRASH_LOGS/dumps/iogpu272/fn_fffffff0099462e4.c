// FUN_fffffff0099462e4 @ fffffff0099462e4 size=36

void FUN_fffffff0099462e4(long param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x70);
  *(uint *)(param_1 + 0x70) = uVar1 + 1;
  if (uVar1 < 0xfffffff) {
    return;
  }
  FUN_fffffff009983454();
  return;
}

