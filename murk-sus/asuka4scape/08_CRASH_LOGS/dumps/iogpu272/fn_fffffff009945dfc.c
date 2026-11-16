// FUN_fffffff009945dfc @ fffffff009945dfc size=8

void FUN_fffffff009945dfc(long param_1,undefined8 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  long lVar3;
  
  if (param_3 == 1) {
    piVar1 = (int *)(param_1 + 0xe4);
    iVar2 = *piVar1;
    *piVar1 = iVar2 + -1;
    LORelease();
    if (iVar2 == 1) {
      FUN_fffffff009983494(piVar1,param_1);
    }
    return;
  }
  lVar3 = FUN_fffffff009983500();
  piVar1 = (int *)(lVar3 + 0xe4);
  iVar2 = *piVar1;
  *piVar1 = iVar2 + -1;
  LORelease();
  if (iVar2 != 1) {
    return;
  }
  FUN_fffffff009983494(piVar1,lVar3);
  return;
}

