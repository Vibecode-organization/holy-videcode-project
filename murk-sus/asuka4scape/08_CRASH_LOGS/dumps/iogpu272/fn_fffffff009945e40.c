// FUN_fffffff009945e40 @ fffffff009945e40 size=36

void FUN_fffffff009945e40(long param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(param_1 + 0xe4);
  iVar2 = *piVar1;
  *piVar1 = iVar2 + -1;
  LORelease();
  if (iVar2 != 1) {
    return;
  }
  FUN_fffffff009983494(piVar1,param_1);
  return;
}

