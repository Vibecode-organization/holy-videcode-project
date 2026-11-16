// FUN_fffffff009c1f34c @ fffffff009c1f34c size=164

undefined8 FUN_fffffff009c1f34c(long param_1)

{
  undefined8 uVar1;
  undefined8 local_40;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  uVar1 = FUN_fffffff009c49430((undefined4 *)(param_1 + 0xc));
  local_40 = 0;
  thunk_EXT_FUN_80110000032db760(*(undefined8 *)(param_1 + 0x30),&local_40);
  thunk_EXT_FUN_80110000036da494
            (0x85210034,local_40,*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0xc),0,0)
  ;
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_38) {
    return uVar1;
  }
  uVar1 = thunk_EXT_FUN_8011000003a48590();
  return uVar1;
}

