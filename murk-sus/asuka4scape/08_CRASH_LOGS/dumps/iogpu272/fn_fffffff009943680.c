// FUN_fffffff009943680 @ fffffff009943680 size=48

undefined8 FUN_fffffff009943680(long param_1,undefined8 param_2,undefined8 param_3,ulong param_4)

{
  uint uVar1;
  undefined8 uVar2;
  
  LOAcquire();
  uVar1 = *(uint *)(param_1 + 0x24);
  *(uint *)(param_1 + 0x24) = uVar1 + 4;
  if (((uVar1 & 1) != 0) && ((*(ulong *)(param_1 + 0x28) & param_4) != 0)) {
    return 0;
  }
  uVar2 = FUN_fffffff0099433cc();
  return uVar2;
}

