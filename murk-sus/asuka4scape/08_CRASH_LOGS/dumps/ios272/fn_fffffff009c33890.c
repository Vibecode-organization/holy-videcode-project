// FUN_fffffff009c33890 @ fffffff009c33890 size=184

long FUN_fffffff009c33890(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long *plVar2;
  long lVar3;
  
  plVar2 = (long *)FUN_fffffff009c33948(param_1,param_3);
  if (plVar2 != (long *)0x0) {
    thunk_EXT_FUN_80110000032222a8(plVar2[0x1b]);
  }
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x140));
  lVar3 = FUN_fffffff009c33548(param_1,param_2,param_3,plVar2);
  if ((lVar3 != 0) && (iVar1 = FUN_fffffff009c1f34c(lVar3), iVar1 == 0)) {
    lVar3 = 0;
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x140));
  if (plVar2 != (long *)0x0) {
    thunk_EXT_FUN_8011000003222de0(plVar2[0x1b]);
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  return lVar3;
}

