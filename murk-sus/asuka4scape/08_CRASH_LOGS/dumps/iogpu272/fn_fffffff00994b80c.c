// FUN_fffffff00994b80c @ fffffff00994b80c size=100

bool FUN_fffffff00994b80c(long param_1)

{
  int iVar1;
  bool bVar2;
  long lVar3;
  ulong uVar4;
  
  uVar4 = (ulong)*(uint *)(param_1 + 0x28);
  if ((int)*(uint *)(param_1 + 0x28) < 1) {
    return true;
  }
  lVar3 = 0;
  do {
    uVar4 = uVar4 - 1;
    iVar1 = *(int *)(param_1 + 0x40 + (lVar3 << 4 | 0xcU)) -
            **(int **)(*(long *)(param_1 + 0x20) + lVar3 * 8);
    bVar2 = iVar1 < 1;
    if (0 < iVar1) {
      return bVar2;
    }
    lVar3 = lVar3 + 1;
  } while (uVar4 != 0);
  return bVar2;
}

