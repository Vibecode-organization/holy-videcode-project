// FUN_fffffff0094c4d80 @ fffffff0094c4d80 size=200
// CALLERS:
// CALLS:
//   fffffff0094c4848 FUN_fffffff0094c4848
//   fffffff0094c99c4 thunk_EXT_FUN_8011000003a48590

void FUN_fffffff0094c4d80
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               uint param_5,undefined4 *param_6,undefined8 *param_7,undefined8 *param_8)

{
  int iVar1;
  undefined8 local_100;
  undefined8 uStack_f8;
  ulong local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 local_40;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff007f5bb60;
  local_40 = 0;
  uStack_58 = 0;
  local_60 = 0;
  uStack_48 = 0;
  uStack_50 = 0;
  uStack_78 = 0;
  local_80 = 0;
  uStack_68 = 0;
  local_70 = 0;
  uStack_98 = 0;
  local_a0 = 0;
  uStack_88 = 0;
  uStack_90 = 0;
  uStack_b8 = 0;
  local_c0 = 0;
  uStack_a8 = 0;
  uStack_b0 = 0;
  uStack_d8 = 0;
  local_e0 = 0;
  uStack_c8 = 0;
  uStack_d0 = 0;
  local_f0 = (ulong)param_5;
  uStack_e8 = 7;
  local_100 = param_1;
  uStack_f8 = param_2;
  iVar1 = FUN_fffffff0094c4848(&local_100,param_3,param_4);
  if ((((iVar1 == 0) && (param_6 != (undefined4 *)0x0)) && (param_7 != (undefined8 *)0x0)) &&
     (param_8 != (undefined8 *)0x0)) {
    *param_6 = (undefined4)uStack_78;
    *param_7 = local_70;
    *param_8 = uStack_68;
  }
  if (*(long *)PTR_DAT_fffffff007f5bb60 == local_38) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

