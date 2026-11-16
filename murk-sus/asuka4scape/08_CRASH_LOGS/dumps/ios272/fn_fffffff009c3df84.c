// FUN_fffffff009c3df84 @ fffffff009c3df84 size=432

ulong FUN_fffffff009c3df84(long param_1,undefined8 param_2)

{
  uint uVar1;
  long *plVar2;
  ulong uVar3;
  undefined8 uVar4;
  long *local_90;
  undefined *local_88;
  undefined8 local_80;
  code *local_78;
  undefined *local_70;
  undefined8 *local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 *local_50;
  undefined8 local_48;
  undefined4 local_40;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  local_58 = 0;
  local_48 = DAT_fffffff0078a1288;
  local_40 = 0;
  local_50 = &local_58;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xd8));
  local_88 = PTR_DAT_fffffff00806c9b8;
  local_80 = DAT_fffffff0078a1290;
  local_78 = FUN_fffffff009c403a8;
  local_70 = &DAT_fffffff00806a120;
  local_68 = &local_58;
  uStack_60 = param_2;
  thunk_EXT_FUN_801100000389794c(&local_70,*(undefined8 *)(param_1 + 0x100),&local_88);
  if (*(int *)(local_50 + 3) == 0) {
    plVar2 = (long *)FUN_fffffff009c1607c(param_2);
    if (plVar2 == (long *)0x0) {
      *(undefined4 *)(local_50 + 3) = 0xe00002bd;
    }
    else {
      uVar4 = *(undefined8 *)(param_1 + 0x100);
      local_90 = plVar2;
      (**(code **)(*plVar2 + 0x20))();
      thunk_EXT_FUN_80110000038963f0(uVar4,&local_90);
      if (local_90 != (long *)0x0) {
        (**(code **)(*local_90 + 0x28))();
      }
      (**(code **)(*plVar2 + 0x28))(plVar2);
    }
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xd8));
  uVar1 = *(uint *)(local_50 + 3);
  thunk_EXT_FUN_80110000038e9dac(&local_58,8);
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_38) {
    return (ulong)uVar1;
  }
  uVar3 = thunk_EXT_FUN_8011000003a48590();
  return uVar3;
}

