// FUN_fffffff0081be9c0 @ fffffff0081be9c0 size=84

undefined8 FUN_fffffff0081be9c0(long param_1,uint param_2)

{
  undefined8 uVar1;
  
  if ((param_2 == 0) ||
     ((uVar1 = 0xe00002c2, 99 < param_2 && (param_2 <= (uint)(*(int *)(param_1 + 0xb70) * 100))))) {
    uVar1 = 0;
    *(uint *)(*(long *)(param_1 + 0x280) + 0x10f68) = param_2;
    *(uint *)(param_1 + 0x1b28) = param_2;
    *(uint *)(*(long *)(param_1 + 0x348) + 0xac) = param_2;
  }
  return uVar1;
}

