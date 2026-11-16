// FUN_fffffff009c2db14 @ fffffff009c2db14 size=144

ulong FUN_fffffff009c2db14(long param_1)

{
  ulong uVar1;
  uint uVar2;
  byte local_19;
  long local_18;
  
  local_18 = *(long *)PTR_DAT_fffffff00806ca40;
  local_19 = 0;
  if (*(long *)(param_1 + 0x18) != 0) {
    uVar2 = 0;
    if (*(code **)(param_1 + 0x28) == (code *)0x0) goto LAB_fffffff009c2db78;
    if (*(long *)(param_1 + 0x20) != 0) {
      (**(code **)(param_1 + 0x28))(*(long *)(param_1 + 0x18),param_1,8,0,&local_19);
      uVar2 = (uint)local_19;
      goto LAB_fffffff009c2db78;
    }
  }
  uVar2 = 0;
LAB_fffffff009c2db78:
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_18) {
    return (ulong)(uVar2 & 1);
  }
  uVar1 = thunk_EXT_FUN_8011000003a48590();
  return uVar1;
}

