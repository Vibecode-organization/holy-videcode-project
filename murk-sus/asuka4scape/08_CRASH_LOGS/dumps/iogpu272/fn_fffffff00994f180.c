// FUN_fffffff00994f180 @ fffffff00994f180 size=164

void FUN_fffffff00994f180
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               uint param_5,undefined8 param_6)

{
  undefined8 uVar1;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  ulong local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  
  local_50 = 0;
  uStack_48 = 0;
  thunk_EXT_FUN_8011000003398228(param_3,&uStack_48);
  thunk_EXT_FUN_8011000003398228(param_4,&local_50);
  uStack_70 = uStack_48;
  local_68 = local_50;
  local_60 = (ulong)param_5;
  local_78 = param_2;
  local_58 = param_6;
  uVar1 = FUN_fffffff0099830ac(param_1);
  (**(code **)(PTR_DAT_fffffff007ff27d8 + 0xa0))(uVar1,&local_78,0x28);
  return;
}

