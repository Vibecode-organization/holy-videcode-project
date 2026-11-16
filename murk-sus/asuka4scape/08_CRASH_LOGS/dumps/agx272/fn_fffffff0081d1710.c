// FUN_fffffff0081d1710 @ fffffff0081d1710 size=92

void FUN_fffffff0081d1710(long param_1,uint param_2)

{
  uint uVar1;
  
  *(uint *)(*(long *)(param_1 + 0x348) + 0xe28) =
       *(uint *)(*(long *)(param_1 + 0x348) + 0xe28) & 0xfffffffe | param_2;
  uVar1 = 2;
  if (param_2 == 0) {
    uVar1 = 0;
  }
  *(uint *)(*(long *)(param_1 + 0x348) + 0xe28) =
       *(uint *)(*(long *)(param_1 + 0x348) + 0xe28) & 0xfffffffd | uVar1;
  *(uint *)(*(long *)(param_1 + 0x348) + 0xe28) =
       *(uint *)(*(long *)(param_1 + 0x348) + 0xe28) & 0xfffffffb;
  *(uint *)(*(long *)(param_1 + 0x348) + 0xe28) = *(uint *)(*(long *)(param_1 + 0x348) + 0xe28) & 7;
  return;
}

