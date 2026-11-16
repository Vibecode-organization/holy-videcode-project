// FUN_fffffff009c3a22c @ fffffff009c3a22c size=4

void FUN_fffffff009c3a22c(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined4 uStack_2c;
  long lStack_28;
  
  lStack_28 = *(long *)PTR_DAT_fffffff00806ca40;
  uStack_2c = 0;
  iVar1 = FUN_fffffff009c3c8d4(param_1,param_2,&uStack_2c);
  if (iVar1 == 0) {
    thunk_EXT_FUN_8011000003386690(&uStack_2c,param_3,4);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == lStack_28) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

