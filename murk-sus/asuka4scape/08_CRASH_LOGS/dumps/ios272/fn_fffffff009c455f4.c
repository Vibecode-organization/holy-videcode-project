// FUN_fffffff009c455f4 @ fffffff009c455f4 size=216

undefined8 FUN_fffffff009c455f4(long param_1,long *param_2,long *param_3)

{
  long lVar1;
  
  thunk_EXT_FUN_8011000003224180(*(undefined8 *)(param_1 + 0x18));
  lVar1 = param_1;
  do {
    lVar1 = *(long *)(lVar1 + 0x30);
    if (lVar1 == 0) goto LAB_fffffff009c45668;
  } while (param_3 != *(long **)(lVar1 + 0x20));
  if (param_2 != (long *)0x0) {
    (**(code **)(*param_2 + 0x20))(param_2);
  }
  FUN_fffffff009c429e4(lVar1,param_2);
LAB_fffffff009c45668:
  thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(param_1 + 0x18));
  if (param_3 != (long *)0x0) {
    (**(code **)(*param_3 + 0x28))(param_3);
  }
  if (param_2 != (long *)0x0) {
    (**(code **)(*param_2 + 0x28))(param_2);
  }
  return 1;
}

