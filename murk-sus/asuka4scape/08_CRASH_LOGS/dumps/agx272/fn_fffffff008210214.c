// FUN_fffffff008210214 @ fffffff008210214 size=28

uint FUN_fffffff008210214(long param_1,long param_2)

{
  uint uVar1;
  
  uVar1 = (uint)(*(ulong *)(param_2 + 8) < *(ulong *)(param_1 + 8));
  if (*(ulong *)(param_1 + 8) < *(ulong *)(param_2 + 8)) {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

