// FUN_fffffff009c46f98 @ fffffff009c46f98 size=32

void FUN_fffffff009c46f98(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_2 != 0) {
    *param_1 = param_2;
    return;
  }
  piVar2 = (int *)FUN_fffffff009c49488();
  iVar1 = *piVar2;
  *piVar2 = iVar1 + 1;
  FUN_fffffff009c46fc8(piVar2,iVar1);
  return;
}

