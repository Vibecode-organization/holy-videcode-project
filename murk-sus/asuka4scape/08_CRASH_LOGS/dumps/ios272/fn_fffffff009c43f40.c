// FUN_fffffff009c43f40 @ fffffff009c43f40 size=116

undefined8 FUN_fffffff009c43f40(long param_1,long *param_2)

{
  long *plVar1;
  
  thunk_EXT_FUN_8011000003223a00(*(undefined8 *)(param_1 + 0x18));
  param_2[6] = 0;
  plVar1 = *(long **)(param_1 + 0x38);
  param_2[7] = (long)plVar1;
  *plVar1 = (long)param_2;
  *(long **)(param_1 + 0x38) = param_2 + 6;
  thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(param_1 + 0x18));
  (**(code **)(*param_2 + 0x28))(param_2);
  return 1;
}

