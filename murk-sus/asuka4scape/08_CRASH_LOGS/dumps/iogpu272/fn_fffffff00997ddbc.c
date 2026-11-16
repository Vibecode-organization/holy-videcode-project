// FUN_fffffff00997ddbc @ fffffff00997ddbc size=80

long * FUN_fffffff00997ddbc(long *param_1,long param_2)

{
  undefined4 uVar1;
  
  *param_1 = param_2;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_2 + 0x28));
  param_1[1] = 0;
  uVar1 = *(undefined4 *)(param_2 + 0x1c);
  *(undefined4 *)(param_1 + 2) = 0;
  *(undefined4 *)((long)param_1 + 0x14) = uVar1;
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(*param_1 + 0x28));
  return param_1;
}

