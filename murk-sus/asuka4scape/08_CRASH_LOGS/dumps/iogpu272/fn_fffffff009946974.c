// FUN_fffffff009946974 @ fffffff009946974 size=8

void FUN_fffffff009946974(long param_1,undefined8 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  long lVar3;
  
  if (param_3 == 1) {
    piVar1 = (int *)(param_1 + 0x70);
    iVar2 = *piVar1;
    *piVar1 = iVar2 + -1;
    LORelease();
    if (iVar2 == 1) {
      FUN_fffffff0099835cc(piVar1,param_1);
    }
    return;
  }
  lVar3 = FUN_fffffff009983638();
  piVar1 = (int *)(lVar3 + 0x70);
  iVar2 = *piVar1;
  *piVar1 = iVar2 + -1;
  LORelease();
  if (iVar2 != 1) {
    return;
  }
  FUN_fffffff0099835cc(piVar1,lVar3);
  return;
}

