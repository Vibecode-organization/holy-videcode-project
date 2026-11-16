// FUN_fffffff00994b6b0 @ fffffff00994b6b0 size=152

int FUN_fffffff00994b6b0(long param_1)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (*(long *)(param_1 + 0x20) == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x28) < 1) {
    iVar5 = 0;
  }
  else {
    iVar4 = 0;
    bVar2 = false;
    iVar5 = 0;
    do {
      iVar3 = FUN_fffffff00994b57c(param_1,iVar4);
      iVar1 = 0;
      if (iVar3 != -1) {
        iVar1 = iVar3;
      }
      iVar5 = iVar1 + iVar5;
      bVar2 = (bool)(iVar3 == -1 | bVar2);
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x28));
    if (bVar2) {
      iVar5 = -1;
    }
  }
  return iVar5;
}

