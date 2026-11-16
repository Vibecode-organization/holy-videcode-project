// FUN_fffffff00996552c @ fffffff00996552c size=176

long * FUN_fffffff00996552c(long param_1,long param_2)

{
  int iVar1;
  long *plVar2;
  int iVar3;
  
  FUN_fffffff00994463c(*(undefined8 *)(param_1 + 0x10));
  iVar1 = *(int *)(*(long *)(param_1 + 0x10) + 0x28);
  if (iVar1 != 0) {
    iVar3 = 0;
    do {
      plVar2 = (long *)FUN_fffffff009945214(*(undefined8 *)(param_1 + 0x10),iVar3);
      if ((plVar2 != (long *)0x0) && (plVar2[5] == param_2)) {
        (**(code **)(*plVar2 + 0x20))(plVar2);
        goto LAB_fffffff0099655bc;
      }
      iVar3 = iVar3 + 1;
    } while (iVar1 != iVar3);
  }
  plVar2 = (long *)0x0;
LAB_fffffff0099655bc:
  FUN_fffffff009944648(*(undefined8 *)(param_1 + 0x10));
  return plVar2;
}

