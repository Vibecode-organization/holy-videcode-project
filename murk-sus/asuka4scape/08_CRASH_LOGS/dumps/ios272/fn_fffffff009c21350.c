// FUN_fffffff009c21350 @ fffffff009c21350 size=272

void FUN_fffffff009c21350(long param_1,undefined8 param_2)

{
  long *plVar1;
  undefined8 uVar2;
  long *local_40;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  plVar1 = (long *)FUN_fffffff009c2f4cc(param_2,*(undefined8 *)(param_1 + 0x30));
  if (plVar1 == (long *)0x0) {
    uVar2 = 0xe00002bc;
  }
  else {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
    uVar2 = *(undefined8 *)(param_1 + 0x3d8);
    local_40 = plVar1;
    (**(code **)(*plVar1 + 0x20))(plVar1);
    thunk_EXT_FUN_80110000038963f0(uVar2,&local_40);
    if (local_40 != (long *)0x0) {
      (**(code **)(*local_40 + 0x28))();
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
    (**(code **)(*plVar1 + 0x28))(plVar1);
    uVar2 = 0;
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_38) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590(uVar2);
  return;
}

