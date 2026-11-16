// FUN_fffffff0099468a0 @ fffffff0099468a0 size=36

void FUN_fffffff0099468a0(long param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x70);
  *(uint *)(param_1 + 0x70) = uVar1 + 1;
  if (uVar1 < 0xfffffff) {
    return;
  }
  FUN_fffffff009983474();
  return;
}

