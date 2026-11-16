// FUN_fffffff009c43270 @ fffffff009c43270 size=208

bool FUN_fffffff009c43270(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  
  (**(code **)(PTR_DAT_fffffff00806ca30 + 0x78))();
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  lVar1 = thunk_EXT_FUN_8011000003962900(0,param_2,param_3,1);
  if (*(long **)(param_1 + 0x18) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x18) + 0x28))();
  }
  *(long *)(param_1 + 0x18) = lVar1;
  if (lVar1 != 0) {
    FUN_fffffff009c43340(param_1,param_2);
    (**(code **)(**(long **)(param_1 + 0x18) + 0xd8))(*(long **)(param_1 + 0x18),0);
  }
  return lVar1 != 0;
}

