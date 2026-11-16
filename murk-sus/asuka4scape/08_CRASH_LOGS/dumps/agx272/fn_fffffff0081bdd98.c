// FUN_fffffff0081bdd98 @ fffffff0081bdd98 size=156

undefined8 FUN_fffffff0081bdd98(long param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  long *plVar3;
  undefined8 uVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 0x280);
  plVar3 = (long *)thunk_EXT_FUN_8011000003890f30(param_2,*(undefined8 *)PTR_DAT_fffffff007ca60a8);
  if (plVar3 == (long *)0x0) {
    uVar4 = 0xe00002c2;
  }
  else {
    iVar2 = (**(code **)(*plVar3 + 0xa8))();
    uVar4 = 0;
    iVar1 = *(int *)(lVar5 + 0x10f88) + *(int *)(lVar5 + 0x11028) + iVar2;
    *(int *)(lVar5 + 0x10f88) = iVar2;
    *(int *)(lVar5 + 0x11028) = iVar1;
    *(int *)(*(long *)(param_1 + 0x918) + 0x1c) = iVar1;
  }
  return uVar4;
}

