// FUN_fffffff008168a4c @ fffffff008168a4c size=520

undefined8 FUN_fffffff008168a4c(undefined8 param_1,undefined4 *param_2)

{
  uint uVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  undefined4 *puVar5;
  long *plVar6;
  uint *puVar7;
  undefined8 uVar8;
  
  plVar2 = (long *)thunk_EXT_FUN_8011000003906044("IODeviceTree:/chosen",0,0,0,0);
  if (plVar2 == (long *)0x0) {
    return 0;
  }
  plVar3 = (long *)(**(code **)(*plVar2 + 0x118))(plVar2,"chip-id");
  if (plVar3 != (long *)0x0) {
    uVar8 = *(undefined8 *)PTR_DAT_fffffff007ca6090;
    plVar4 = (long *)thunk_EXT_FUN_8011000003890f30(plVar3,uVar8);
    if (plVar4 == (long *)0x0) {
      (**(code **)(*plVar3 + 0x38))(plVar3);
      thunk_EXT_FUN_8011000003891b28();
    }
    else {
      puVar5 = (undefined4 *)(**(code **)(*plVar4 + 0xd8))();
      *param_2 = *puVar5;
      plVar3 = (long *)thunk_EXT_FUN_8011000003906044("IODeviceTree:/arm-io",0,0,0,0);
      if (plVar3 != (long *)0x0) {
        plVar4 = (long *)(**(code **)(*plVar3 + 0x118))(plVar3,"chip-revision");
        if (plVar4 == (long *)0x0) {
LAB_fffffff008168c04:
          uVar8 = 0;
        }
        else {
          plVar6 = (long *)thunk_EXT_FUN_8011000003890f30(plVar4,uVar8);
          if (plVar6 == (long *)0x0) {
            (**(code **)(*plVar4 + 0x38))(plVar4);
            thunk_EXT_FUN_8011000003891b28();
            goto LAB_fffffff008168c04;
          }
          puVar7 = (uint *)(**(code **)(*plVar6 + 0xd8))();
          uVar1 = *puVar7;
          param_2[1] = uVar1 >> 4;
          param_2[2] = uVar1 & 7;
          uVar8 = 1;
        }
        (**(code **)(*plVar3 + 0x28))(plVar3);
        goto LAB_fffffff008168c20;
      }
    }
  }
  uVar8 = 0;
LAB_fffffff008168c20:
  (**(code **)(*plVar2 + 0x28))(plVar2);
  return uVar8;
}

