// FUN_fffffff009952228 @ fffffff009952228 size=32

void FUN_fffffff009952228(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_2 != 0) {
    *param_1 = param_2;
    return;
  }
  piVar2 = (int *)FUN_fffffff0099837a8();
  iVar1 = *piVar2;
  *piVar2 = iVar1 + 1;
  FUN_fffffff009952258(piVar2,iVar1);
  return;
}

