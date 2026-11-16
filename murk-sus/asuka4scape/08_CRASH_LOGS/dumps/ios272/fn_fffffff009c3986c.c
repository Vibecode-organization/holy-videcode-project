// FUN_fffffff009c3986c @ fffffff009c3986c size=132

void FUN_fffffff009c3986c(undefined8 param_1,undefined8 param_2,long param_3)

{
  ulong *puVar1;
  ulong local_38;
  uint local_2c;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff00806ca40;
  local_2c = 0;
  local_38 = 0;
  FUN_fffffff009c3dad4(param_1,**(undefined8 **)(param_3 + 0x20),&local_2c,&local_38);
  puVar1 = *(ulong **)(param_3 + 0x48);
  *puVar1 = (ulong)local_2c;
  puVar1[1] = local_38;
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_28) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

