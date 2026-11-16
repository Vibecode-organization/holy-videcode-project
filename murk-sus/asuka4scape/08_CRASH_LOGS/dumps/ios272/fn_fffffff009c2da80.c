// FUN_fffffff009c2da80 @ fffffff009c2da80 size=148

ulong FUN_fffffff009c2da80(long param_1,undefined4 param_2)

{
  ulong uVar1;
  uint uVar2;
  byte local_19;
  long local_18;
  
  local_18 = *(long *)PTR_DAT_fffffff00806ca40;
  local_19 = 0;
  if (((*(long *)(param_1 + 0x18) == 0) || (*(code **)(param_1 + 0x28) == (code *)0x0)) ||
     (*(long *)(param_1 + 0x20) == 0)) {
    uVar2 = 0;
  }
  else {
    (**(code **)(param_1 + 0x28))(*(long *)(param_1 + 0x18),param_1,6,param_2,&local_19);
    uVar2 = (uint)local_19;
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_18) {
    return (ulong)(uVar2 & 1);
  }
  uVar1 = thunk_EXT_FUN_8011000003a48590();
  return uVar1;
}

