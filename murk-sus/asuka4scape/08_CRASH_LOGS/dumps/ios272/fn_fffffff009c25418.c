// FUN_fffffff009c25418 @ fffffff009c25418 size=308

undefined8 FUN_fffffff009c25418(long param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  undefined8 uVar2;
  undefined *local_90;
  undefined8 local_88;
  code *local_80;
  undefined *local_78;
  undefined8 uStack_70;
  undefined8 *local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 *local_50;
  undefined8 local_48;
  undefined1 local_40;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  local_68 = &local_58;
  local_58 = 0;
  local_48 = DAT_fffffff0078a1288;
  local_40 = 0;
  local_90 = PTR_DAT_fffffff00806c9b8;
  local_88 = DAT_fffffff0078a1290;
  local_80 = FUN_fffffff009c2554c;
  uStack_70 = *(undefined8 *)(param_1 + 0x20);
  local_78 = &DAT_fffffff008067298;
  uStack_60 = param_2;
  local_50 = local_68;
  thunk_EXT_FUN_801100000389794c(*(undefined8 *)(param_1 + 0x30),&local_90);
  if ((*(byte *)(local_50 + 3) & 1) == 0) {
    plVar1 = *(long **)(*(long *)(*(long *)(param_1 + 0x28) + 8) + 0x28);
    (**(code **)(*plVar1 + 0xf0))(plVar1,param_2,param_3);
  }
  thunk_EXT_FUN_80110000038e9dac(&local_58,8);
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_38) {
    return 0;
  }
  uVar2 = thunk_EXT_FUN_8011000003a48590();
  return uVar2;
}

