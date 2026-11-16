// FUN_fffffff009c1fec4 @ fffffff009c1fec4 size=140

bool FUN_fffffff009c1fec4(long *param_1,undefined8 param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  undefined8 uVar2;
  long *plVar3;
  
  uVar2 = (**(code **)(*param_1 + 0x138))();
  plVar3 = (long *)thunk_EXT_FUN_8011000003890f30(uVar2,*(undefined8 *)PTR_DAT_fffffff00806ca20);
  if (plVar3 != (long *)0x0) {
    uVar1 = (**(code **)(*plVar3 + 0x88))(plVar3);
    *param_3 = uVar1;
  }
  return plVar3 != (long *)0x0;
}

