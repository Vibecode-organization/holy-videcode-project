// FUN_fffffff009971060 @ fffffff009971060 size=116

undefined8 FUN_fffffff009971060(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = thunk_EXT_FUN_80110000032970b4(*(undefined8 *)(param_1 + 0x28));
  if (lVar1 == 0) {
    thunk_EXT_FUN_8011000003350cfc(param_2,"kernel_task",(long)(int)param_3,0xffffffffffffffff);
    uVar2 = 0;
  }
  else {
    uVar2 = thunk_EXT_FUN_8011000003720f30();
    thunk_EXT_FUN_8011000003722d80(uVar2,param_2,param_3);
  }
  return uVar2;
}

