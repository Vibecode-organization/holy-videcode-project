// FUN_fffffff009c3a230 @ fffffff009c3a230 size=120

void FUN_fffffff009c3a230(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  undefined4 local_2c;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff00806ca40;
  local_2c = 0;
  iVar1 = FUN_fffffff009c3c8d4(param_1,param_2,&local_2c);
  if (iVar1 == 0) {
    thunk_EXT_FUN_8011000003386690(&local_2c,param_3,4);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_28) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

