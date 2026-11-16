// FUN_fffffff009943644 @ fffffff009943644 size=60

undefined8 FUN_fffffff009943644(long param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  LOAcquire();
  uVar1 = *(uint *)(param_1 + 0x24);
  *(uint *)(param_1 + 0x24) = uVar1 + 4;
  if (((uVar1 & 1) != 0) && ((*(ulong *)(param_1 + 0x28) & 0xf) != 0)) {
    return 0;
  }
  uVar2 = FUN_fffffff0099433cc(param_1,0,1,0xf);
  return uVar2;
}

