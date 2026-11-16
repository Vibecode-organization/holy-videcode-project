// FUN_fffffff008167a0c @ fffffff008167a0c size=72

int FUN_fffffff008167a0c(long param_1,int param_2,undefined1 *param_3)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0x1a4d0);
  *param_3 = 0;
  if (param_2 == 2) {
    iVar1 = *(int *)(param_1 + 0x1a618);
  }
  else {
    if (param_2 != 1) {
      if (param_2 != 0) {
        return 0;
      }
      piVar2 = (int *)(param_1 + 0x19440);
    }
    iVar1 = *piVar2;
  }
  return iVar1 + -1;
}

