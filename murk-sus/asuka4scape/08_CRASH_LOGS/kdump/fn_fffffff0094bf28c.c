// FUN_fffffff0094bf28c @ fffffff0094bf28c size=156
// CALLERS:
// CALLS:
//   fffffff0094c99c4 thunk_EXT_FUN_8011000003a48590
//   fffffff0094c264c FUN_fffffff0094c264c

void FUN_fffffff0094bf28c
               (undefined4 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined8 *param_7,undefined8 *param_8)

{
  int iVar1;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff007f5bb60;
  local_38 = 0;
  uStack_30 = 0;
  iVar1 = FUN_fffffff0094c264c
                    (param_1,param_2,0,1,param_5,param_6,param_3,param_4,0,&local_38,
                     &DAT_fffffff007f57818);
  if (((iVar1 == 0) && (param_7 != (undefined8 *)0x0)) && (param_8 != (undefined8 *)0x0)) {
    *param_7 = local_38;
    *param_8 = uStack_30;
  }
  if (*(long *)PTR_DAT_fffffff007f5bb60 == local_28) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

