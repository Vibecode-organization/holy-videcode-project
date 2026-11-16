// FUN_fffffff009c1f614 @ fffffff009c1f614 size=144

void FUN_fffffff009c1f614(long param_1)

{
  undefined8 local_30;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff00806ca40;
  FUN_fffffff009c46fb8((undefined4 *)(param_1 + 0xc));
  local_30 = 0;
  thunk_EXT_FUN_80110000032db760(*(undefined8 *)(param_1 + 0x30),&local_30);
  thunk_EXT_FUN_80110000036da494
            (0x85210034,local_30,*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0xc),0,0)
  ;
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_28) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

