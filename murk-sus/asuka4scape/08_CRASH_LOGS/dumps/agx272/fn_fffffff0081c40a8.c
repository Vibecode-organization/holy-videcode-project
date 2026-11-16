// FUN_fffffff0081c40a8 @ fffffff0081c40a8 size=52

bool FUN_fffffff0081c40a8(long param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0x1bf0);
  piVar1 = (int *)(*(long *)(param_1 + 0x910) + 0x4c20);
  iVar3 = *piVar1;
  if (iVar2 != iVar3) {
    *(int *)(param_1 + 0x1bf0) = *piVar1;
  }
  return iVar2 != iVar3;
}

