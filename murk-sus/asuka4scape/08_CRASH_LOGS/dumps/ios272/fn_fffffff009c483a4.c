// FUN_fffffff009c483a4 @ fffffff009c483a4 size=184

undefined8 FUN_fffffff009c483a4(long param_1,long param_2)

{
  undefined8 uVar1;
  undefined1 *local_40;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  local_40 = &DAT_aaaaaaaaaaaaaaaa;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x18));
  uVar1 = (**(code **)(**(long **)(param_1 + 0x30) + 0xb0))
                    (*(long **)(param_1 + 0x30),*(undefined8 *)(param_2 + 0x90),&local_40,0);
  if ((int)uVar1 != 0) {
    *(ulong *)(param_2 + 0x88) = (ulong)local_40 & 0xffffffff;
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x18));
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_38) {
    return uVar1;
  }
  uVar1 = thunk_EXT_FUN_8011000003a48590();
  return uVar1;
}

