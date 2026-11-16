// FUN_fffffff0081c1e28 @ fffffff0081c1e28 size=52

undefined8 FUN_fffffff0081c1e28(long param_1,int param_2)

{
  ulong uVar1;
  
  uVar1 = 2;
  if (param_2 == 0) {
    uVar1 = 0;
  }
  *(ulong *)(*(long *)(param_1 + 0x280) + 0x5c8) =
       *(ulong *)(*(long *)(param_1 + 0x280) + 0x5c8) & 0xfffffffffffffffd | uVar1;
  *(int *)(*(long *)(param_1 + 0x348) + 0x34) = param_2;
  return 0;
}

