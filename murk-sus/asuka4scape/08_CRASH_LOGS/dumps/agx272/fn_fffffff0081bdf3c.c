// FUN_fffffff0081bdf3c @ fffffff0081bdf3c size=136

undefined8 FUN_fffffff0081bdf3c(long param_1,undefined8 param_2)

{
  undefined4 uVar1;
  long *plVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x280);
  plVar2 = (long *)thunk_EXT_FUN_8011000003890f30(param_2,*(undefined8 *)PTR_DAT_fffffff007ca60a8);
  if (plVar2 == (long *)0x0) {
    uVar3 = 0xe00002c2;
  }
  else {
    uVar1 = (**(code **)(*plVar2 + 0xa8))();
    uVar3 = 0;
    *(undefined4 *)(lVar4 + 0x10ff0) = uVar1;
    *(undefined4 *)(*(long *)(param_1 + 0x918) + 0x10) = uVar1;
  }
  return uVar3;
}

