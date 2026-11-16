// FUN_fffffff0099436e4 @ fffffff0099436e4 size=60

undefined8 FUN_fffffff0099436e4(long param_1,ulong param_2)

{
  uint uVar1;
  undefined8 uVar2;
  
  LOAcquire();
  uVar1 = *(uint *)(param_1 + 0x24);
  *(uint *)(param_1 + 0x24) = uVar1 + 4;
  if (((uVar1 & 1) != 0) && ((*(ulong *)(param_1 + 0x28) & param_2) != 0)) {
    return 0;
  }
  uVar2 = FUN_fffffff0099433cc(param_1,0,1);
  return uVar2;
}

