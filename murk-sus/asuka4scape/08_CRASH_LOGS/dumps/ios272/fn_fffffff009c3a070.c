// FUN_fffffff009c3a070 @ fffffff009c3a070 size=132

void FUN_fffffff009c3a070(undefined8 param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  uint local_2c;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff00806ca40;
  local_2c = 0;
  if (**(long **)(param_3 + 0x20) == 0) {
    uVar1 = 0xe00002c2;
  }
  else {
    uVar1 = FUN_fffffff009c3c8d4(param_1,**(long **)(param_3 + 0x20),&local_2c);
    **(ulong **)(param_3 + 0x48) = (ulong)local_2c;
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_28) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590(uVar1);
  return;
}

