// FUN_fffffff009c42d48 @ fffffff009c42d48 size=356

undefined8 FUN_fffffff009c42d48(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  long *local_30;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff00806ca40;
  local_30 = (long *)0x0;
  thunk_EXT_FUN_80110000032db760(*(undefined8 *)(param_1 + 0x18),&local_30);
  local_30 = (long *)thunk_EXT_FUN_80110000038c6e24(local_30,0x40);
  thunk_EXT_FUN_801100000389d40c(param_2,"Descriptor address",&local_30);
  if (local_30 != (long *)0x0) {
    (**(code **)(*local_30 + 0x28))();
  }
  uVar1 = (**(code **)(**(long **)(param_1 + 0x18) + 0xb0))();
  local_30 = (long *)thunk_EXT_FUN_80110000038c6e24(uVar1,0x40);
  thunk_EXT_FUN_801100000389d40c(param_2,"Length",&local_30);
  if (local_30 != (long *)0x0) {
    (**(code **)(*local_30 + 0x28))();
  }
  local_30 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(param_1 + 0xc),0x20);
  thunk_EXT_FUN_801100000389d40c(param_2,"Options",&local_30);
  if (local_30 != (long *)0x0) {
    (**(code **)(*local_30 + 0x28))();
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_28) {
    return 1;
  }
  uVar1 = thunk_EXT_FUN_8011000003a48590();
  return uVar1;
}

