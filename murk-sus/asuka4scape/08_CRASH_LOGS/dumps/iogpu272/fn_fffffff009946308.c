// FUN_fffffff009946308 @ fffffff009946308 size=36

void FUN_fffffff009946308(long param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(param_1 + 0x70);
  iVar2 = *piVar1;
  *piVar1 = iVar2 + -1;
  LORelease();
  if (iVar2 != 1) {
    return;
  }
  FUN_fffffff009983530(piVar1,param_1);
  return;
}

