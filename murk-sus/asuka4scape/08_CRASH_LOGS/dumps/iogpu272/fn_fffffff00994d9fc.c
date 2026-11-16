// FUN_fffffff00994d9fc @ fffffff00994d9fc size=8

void FUN_fffffff00994d9fc(long param_1,undefined8 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  long lVar3;
  
  if (param_3 == 1) {
    piVar1 = (int *)(param_1 + 0xc);
    iVar2 = *piVar1;
    *piVar1 = iVar2 + -1;
    LORelease();
    if (iVar2 == 1) {
      FUN_fffffff0099836b0(piVar1,param_1);
    }
    return;
  }
  lVar3 = FUN_fffffff009983714();
  piVar1 = (int *)(lVar3 + 0xc);
  iVar2 = *piVar1;
  *piVar1 = iVar2 + -1;
  LORelease();
  if (iVar2 != 1) {
    return;
  }
  FUN_fffffff0099836b0(piVar1,lVar3);
  return;
}

