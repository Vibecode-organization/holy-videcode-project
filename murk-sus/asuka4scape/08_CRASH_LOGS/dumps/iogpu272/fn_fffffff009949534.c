// FUN_fffffff009949534 @ fffffff009949534 size=272

undefined8
FUN_fffffff009949534(long param_1,undefined8 param_2,long param_3,long param_4,long param_5)

{
  int iVar1;
  long *plVar2;
  undefined8 uVar3;
  undefined4 local_94;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  long local_48;
  
  local_48 = *(long *)PTR_DAT_fffffff007ff2800;
  uVar3 = 0xe00002c2;
  if ((param_4 != 0) && (0xffffffffffffffee < param_3 - 0x41U)) {
    uStack_68 = 0;
    local_70 = 0;
    uStack_58 = 0;
    uStack_60 = 0;
    uStack_88 = 0;
    local_90 = 0;
    uStack_78 = 0;
    uStack_80 = 0;
    iVar1 = thunk_EXT_FUN_8011000003385b14(param_4,&local_90,param_3);
    if ((iVar1 == 0) &&
       (plVar2 = (long *)FUN_fffffff009965da8(*(undefined8 *)(param_1 + 0x120),param_2),
       plVar2 != (long *)0x0)) {
      local_94 = 0;
      uVar3 = FUN_fffffff009976cf8(plVar2,&local_90,1,param_3,&local_94);
      if (param_5 != 0) {
        thunk_EXT_FUN_8011000003386690(&local_94,param_5,4);
      }
      (**(code **)(*plVar2 + 0x28))(plVar2);
    }
  }
  if (*(long *)PTR_DAT_fffffff007ff2800 == local_48) {
    return uVar3;
  }
  uVar3 = thunk_EXT_FUN_8011000003a48590();
  return uVar3;
}

