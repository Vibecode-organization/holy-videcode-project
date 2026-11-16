// FUN_fffffff00995109c @ fffffff00995109c size=196

void FUN_fffffff00995109c
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               ulong param_5,ulong param_6,ulong param_7)

{
  ulong local_90;
  ulong uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  ulong local_70;
  ulong uStack_68;
  ulong local_60;
  ulong uStack_58;
  ulong local_50;
  long local_48;
  
  local_48 = *(long *)PTR_DAT_fffffff007ff2800;
  local_90 = param_7;
  uStack_88 = param_6;
  thunk_EXT_FUN_8011000003398228(param_6,&uStack_88);
  thunk_EXT_FUN_8011000003398228(param_7,&local_90);
  uStack_68 = uStack_88 >> 0x20;
  local_70 = uStack_88;
  uStack_58 = local_90 >> 0x20;
  local_60 = local_90;
  local_50 = param_5 & 0xffffffff;
  local_80 = param_3;
  uStack_78 = param_4;
  thunk_EXT_FUN_80110000039a40ec(param_2,0,&local_80,7);
  if (*(long *)PTR_DAT_fffffff007ff2800 == local_48) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

