// FUN_fffffff009c397f0 @ fffffff009c397f0 size=120

void FUN_fffffff009c397f0(undefined8 param_1,undefined8 param_2,long param_3)

{
  uint local_2c;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff00806ca40;
  local_2c = 0;
  FUN_fffffff009c3b9f8
            (param_1,**(undefined4 **)(param_3 + 0x20),(*(undefined4 **)(param_3 + 0x20))[2],
             &local_2c);
  **(ulong **)(param_3 + 0x48) = (ulong)local_2c;
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_28) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

