// FUN_fffffff0081b65c8 @ fffffff0081b65c8 size=172

void FUN_fffffff0081b65c8(long param_1)

{
  int iVar1;
  code *local_60;
  long lStack_58;
  undefined8 local_50;
  code *local_40;
  long lStack_38;
  undefined8 local_30;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff007ca61a0;
  local_30 = 0;
  local_40 = FUN_fffffff0081b6674;
  lStack_38 = param_1;
  thunk_EXT_FUN_8011000003350958(&local_30,"GFXFW",8);
  lStack_58 = lStack_38;
  local_60 = local_40;
  local_50 = local_30;
  iVar1 = thunk_EXT_FUN_80110000036db7a8(&local_60);
  *(int *)(param_1 + 0x8f0) = iVar1;
  if (*(long *)PTR_DAT_fffffff007ca61a0 == local_28) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590(iVar1 != 0);
  return;
}

