// FUN_fffffff009943760 @ fffffff009943760 size=64

undefined8 FUN_fffffff009943760(long param_1,ulong param_2)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = (uint *)(param_1 + 0x24);
  LOAcquire();
  uVar2 = *puVar1;
  *puVar1 = uVar2 + 4;
  if (((uVar2 & 1) != 0) && ((*(ulong *)(param_1 + 0x28) & param_2) != 0)) {
    return 0;
  }
  *puVar1 = *puVar1 - 4;
  LORelease();
  return 0xe00002be;
}

