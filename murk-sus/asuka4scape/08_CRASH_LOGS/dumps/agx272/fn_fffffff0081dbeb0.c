// FUN_fffffff0081dbeb0 @ fffffff0081dbeb0 size=92

int FUN_fffffff0081dbeb0(long param_1,int param_2,undefined1 *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)(param_1 + 0x1a4d0);
  *param_3 = 0;
  if (param_2 == 2) {
    iVar2 = *(int *)(param_1 + 0x1a618);
  }
  else {
    if (param_2 != 1) {
      iVar2 = 0;
      if (param_2 != 0) goto LAB_fffffff0081dbef8;
      piVar3 = (int *)(param_1 + 0x19440);
    }
    iVar2 = *piVar3;
  }
  iVar2 = iVar2 + -1;
LAB_fffffff0081dbef8:
  iVar1 = 3;
  if (*(long *)(param_1 + 0x105f8) != 0) {
    iVar1 = iVar2;
  }
  return iVar1;
}

