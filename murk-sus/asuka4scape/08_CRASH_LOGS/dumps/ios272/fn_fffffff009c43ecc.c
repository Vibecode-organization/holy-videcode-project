// FUN_fffffff009c43ecc @ fffffff009c43ecc size=116

undefined8 FUN_fffffff009c43ecc(long param_1,long *param_2)

{
  long *plVar1;
  
  thunk_EXT_FUN_8011000003223a00(*(undefined8 *)(param_1 + 0x10));
  param_2[2] = 0;
  plVar1 = *(long **)(param_1 + 0x28);
  param_2[3] = (long)plVar1;
  *plVar1 = (long)param_2;
  *(long **)(param_1 + 0x28) = param_2 + 2;
  thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(param_1 + 0x10));
  (**(code **)(*param_2 + 0x28))(param_2);
  return 1;
}

