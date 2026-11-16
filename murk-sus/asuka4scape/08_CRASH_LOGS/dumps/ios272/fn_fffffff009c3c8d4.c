// FUN_fffffff009c3c8d4 @ fffffff009c3c8d4 size=236

undefined8 FUN_fffffff009c3c8d4(long param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  undefined8 uVar2;
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
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined4 local_40;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  uVar2 = 0xe00002c2;
  if ((*(long *)(param_1 + 0x130) != 0) &&
     (plVar1 = (long *)FUN_fffffff009c3f1d0(), plVar1 != (long *)0x0)) {
    local_40 = 0;
    uStack_58 = 0;
    local_60 = 0;
    uStack_48 = 0;
    uStack_50 = 0;
    uStack_78 = 0;
    local_80 = 0;
    uStack_68 = 0;
    uStack_70 = 0;
    uStack_98 = 0;
    local_a0 = 0;
    uStack_88 = 0;
    uStack_90 = 0;
    uStack_b8 = 0;
    local_c0 = 0;
    uStack_a8 = 0;
    uStack_b0 = 0;
    FUN_fffffff009c25e38(plVar1,&local_c0,0x3fffff);
    thunk_EXT_FUN_8011000003224180(*(undefined8 *)(param_1 + 0xe0));
    FUN_fffffff009c256e8(plVar1,*(undefined8 *)(param_1 + 0x130),param_3);
    thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(param_1 + 0xe0));
    (**(code **)(*plVar1 + 0x28))(plVar1);
    uVar2 = 0;
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_38) {
    return uVar2;
  }
  uVar2 = thunk_EXT_FUN_8011000003a48590();
  return uVar2;
}

