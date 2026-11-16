// FUN_fffffff0081d6c4c @ fffffff0081d6c4c size=268

undefined4 FUN_fffffff0081d6c4c(void)

{
  long *plVar1;
  long *plVar2;
  long *plVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  plVar1 = (long *)thunk_EXT_FUN_8011000003906044("IODeviceTree:/chosen",0,0,0,0);
  if (plVar1 == (long *)0x0) {
    return 0;
  }
  plVar2 = (long *)(**(code **)(*plVar1 + 0x118))(plVar1,"chip-id");
  if (plVar2 != (long *)0x0) {
    plVar3 = (long *)thunk_EXT_FUN_8011000003890f30(plVar2,*(undefined8 *)PTR_DAT_fffffff007ca6090);
    if (plVar3 != (long *)0x0) {
      puVar4 = (undefined4 *)(**(code **)(*plVar3 + 0xd8))();
      uVar5 = *puVar4;
      goto LAB_fffffff0081d6d2c;
    }
    (**(code **)(*plVar2 + 0x38))(plVar2);
    thunk_EXT_FUN_8011000003891b28();
  }
  uVar5 = 0;
LAB_fffffff0081d6d2c:
  (**(code **)(*plVar1 + 0x28))(plVar1);
  return uVar5;
}

