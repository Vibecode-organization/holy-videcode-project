// FUN_fffffff009951098 @ fffffff009951098 size=4

void FUN_fffffff009951098
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               ulong param_5,ulong param_6,ulong param_7)

{
  ulong uStack_90;
  ulong uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  ulong uStack_70;
  ulong uStack_68;
  ulong uStack_60;
  ulong uStack_58;
  ulong uStack_50;
  long lStack_48;
  
  lStack_48 = *(long *)PTR_DAT_fffffff007ff2800;
  uStack_90 = param_7;
  uStack_88 = param_6;
  thunk_EXT_FUN_8011000003398228(param_6,&uStack_88);
  thunk_EXT_FUN_8011000003398228(param_7,&uStack_90);
  uStack_68 = uStack_88 >> 0x20;
  uStack_70 = uStack_88;
  uStack_58 = uStack_90 >> 0x20;
  uStack_60 = uStack_90;
  uStack_50 = param_5 & 0xffffffff;
  uStack_80 = param_3;
  uStack_78 = param_4;
  thunk_EXT_FUN_80110000039a40ec(param_2,0,&uStack_80,7);
  if (*(long *)PTR_DAT_fffffff007ff2800 == lStack_48) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

