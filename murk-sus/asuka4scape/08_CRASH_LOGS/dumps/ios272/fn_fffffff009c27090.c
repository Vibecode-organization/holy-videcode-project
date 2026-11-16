// FUN_fffffff009c27090 @ fffffff009c27090 size=136

void FUN_fffffff009c27090
               (undefined8 param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined4 param_8)

{
  undefined8 local_30;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff00806ca40;
  local_30 = 0;
  FUN_fffffff009c27118(param_1,0,&local_30,param_3,param_4,param_5,param_6,param_7,param_8);
  *param_2 = local_30;
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_28) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

