// FUN_fffffff0081c9618 @ fffffff0081c9618 size=140

undefined8 FUN_fffffff0081c9618(long param_1)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  
  if (((*(long **)(param_1 + 0x210) == (long *)0x0) ||
      (iVar1 = (**(code **)(**(long **)(param_1 + 0x210) + 0x10))(), iVar1 < 1)) ||
     (uVar2 = (**(code **)(**(long **)(param_1 + 0x210) + 0x10))(),
     *(uint *)(*(long *)(param_1 + 0x2a0) + 0x10e0) < uVar2)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}

