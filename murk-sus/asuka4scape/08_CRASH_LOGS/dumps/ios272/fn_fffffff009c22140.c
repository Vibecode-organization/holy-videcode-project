// FUN_fffffff009c22140 @ fffffff009c22140 size=280

void FUN_fffffff009c22140(long param_1)

{
  int iVar1;
  undefined8 local_30;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff00806ca40;
  local_30 = 0;
  thunk_EXT_FUN_80110000032db760(*(undefined8 *)(param_1 + 0x30),&local_30);
  thunk_EXT_FUN_80110000036da494(0x85210045,local_30,*(undefined4 *)(param_1 + 0x10),0,0,0);
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
  iVar1 = (**(code **)(**(long **)(param_1 + 0x3d8) + 0x90))();
  if (iVar1 != 0) {
    thunk_EXT_FUN_801100000389794c(*(undefined8 *)(param_1 + 0x3d8),&DAT_fffffff008067318);
    if (*(long **)(param_1 + 0x3d8) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x3d8) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x3d8) = 0;
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
  thunk_EXT_FUN_80110000036da494(0x85210046,0,0,0,0,0);
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_28) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

