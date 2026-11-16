// FUN_fffffff0094bf1ec @ fffffff0094bf1ec size=156
// CALLERS:
// CALLS:
//   fffffff0094bef58 FUN_fffffff0094bef58
//   fffffff0094c99c4 thunk_EXT_FUN_8011000003a48590
//   fffffff0094c264c FUN_fffffff0094c264c

void FUN_fffffff0094bf1ec
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined8 param_7)

{
  int iVar1;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff007f5bb60;
  local_38 = 0;
  local_30 = 0;
  local_40 = 0;
  iVar1 = FUN_fffffff0094c264c
                    (param_1,param_2,1,1,param_5,param_6,param_3,param_4,&local_40,&local_38,
                     &DAT_fffffff007f577e0);
  if (iVar1 == 0) {
    FUN_fffffff0094bef58(local_40,local_38,local_30,param_7);
  }
  if (*(long *)PTR_DAT_fffffff007f5bb60 == local_28) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

