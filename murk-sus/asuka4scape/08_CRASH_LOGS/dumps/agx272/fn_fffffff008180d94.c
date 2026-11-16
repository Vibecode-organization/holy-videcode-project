// FUN_fffffff008180d94 @ fffffff008180d94 size=352

long * FUN_fffffff008180d94(long param_1)

{
  long *plVar1;
  undefined8 uVar2;
  long *plVar3;
  undefined4 *puVar4;
  long *plVar5;
  bool bVar6;
  
  plVar1 = (long *)(**(code **)(**(long **)(param_1 + 0x4b0) + 0x358))
                             (*(long **)(param_1 + 0x4b0),8,0);
  if (plVar1 == (long *)0x0) {
    return (long *)0x0;
  }
  uVar2 = (**(code **)(*plVar1 + 0x138))(plVar1,"ConfigData");
  plVar3 = (long *)thunk_EXT_FUN_8011000003890f30(uVar2,*(undefined8 *)PTR_DAT_fffffff007ca6090);
  if (plVar3 == (long *)0x0) {
    plVar3 = (long *)0x0;
  }
  else {
    puVar4 = (undefined4 *)(**(code **)(*plVar3 + 0xd8))();
    plVar3 = (long *)thunk_EXT_FUN_80110000038c6e24(*puVar4,0x20);
    if (plVar3 != (long *)0x0) {
      (**(code **)(*plVar3 + 0x20))(plVar3);
      bVar6 = false;
      plVar5 = plVar3;
      goto LAB_fffffff008180ea0;
    }
  }
  plVar5 = (long *)0x0;
  bVar6 = true;
LAB_fffffff008180ea0:
  (**(code **)(*plVar1 + 0x28))(plVar1);
  if (!bVar6) {
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
  return plVar3;
}

