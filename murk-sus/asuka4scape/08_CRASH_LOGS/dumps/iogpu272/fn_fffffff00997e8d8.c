// FUN_fffffff00997e8d8 @ fffffff00997e8d8 size=312

undefined8 FUN_fffffff00997e8d8(undefined8 param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long *plVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 local_48;
  
  iVar1 = FUN_fffffff00997eb08();
  if (iVar1 != 0) {
    return 0xe00002c1;
  }
  iVar1 = *(int *)(param_3 + 0x70);
  if (iVar1 == 0) {
    plVar2 = (long *)0x0;
    iVar1 = *(int *)(param_3 + 0x60);
    uVar3 = *(undefined8 *)(param_3 + 0x58);
  }
  else {
    plVar2 = (long *)(**(code **)(**(long **)(param_3 + 0x68) + 0xe8))(*(long **)(param_3 + 0x68),0)
    ;
    if (plVar2 == (long *)0x0) {
      return 0xe00002be;
    }
    uVar3 = (**(code **)(*plVar2 + 0x78))();
  }
  local_48 = 0;
  lVar4 = thunk_EXT_FUN_8011000003890f30(param_1,&DAT_fffffff00af22898);
  if (lVar4 == 0) {
    uVar3 = 0xe00002c2;
  }
  else {
    uVar3 = FUN_fffffff00997eb7c(lVar4,iVar1,(long)&local_48 + 4,&local_48,uVar3);
  }
  if (plVar2 == (long *)0x0) {
    *(undefined4 *)(param_3 + 0x60) = (undefined4)local_48;
  }
  else {
    (**(code **)(*plVar2 + 0x28))(plVar2);
    *(undefined4 *)(param_3 + 0x70) = (undefined4)local_48;
  }
  **(ulong **)(param_3 + 0x48) = local_48 >> 0x20;
  return uVar3;
}

