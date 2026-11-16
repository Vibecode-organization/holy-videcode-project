// FUN_fffffff009c2708c @ fffffff009c2708c size=4

void FUN_fffffff009c2708c
               (undefined8 param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined4 param_8)

{
  undefined8 uStack_30;
  long lStack_28;
  
  lStack_28 = *(long *)PTR_DAT_fffffff00806ca40;
  uStack_30 = 0;
  FUN_fffffff009c27118(param_1,0,&uStack_30,param_3,param_4,param_5,param_6,param_7,param_8);
  *param_2 = uStack_30;
  if (*(long *)PTR_DAT_fffffff00806ca40 == lStack_28) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

