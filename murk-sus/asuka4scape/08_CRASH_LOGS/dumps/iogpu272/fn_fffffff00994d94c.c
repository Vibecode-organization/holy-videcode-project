// FUN_fffffff00994d94c @ fffffff00994d94c size=36

void FUN_fffffff00994d94c(long param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(param_1 + 0xc);
  iVar2 = *piVar1;
  *piVar1 = iVar2 + -1;
  LORelease();
  if (iVar2 != 1) {
    return;
  }
  FUN_fffffff0099836b0(piVar1,param_1);
  return;
}

