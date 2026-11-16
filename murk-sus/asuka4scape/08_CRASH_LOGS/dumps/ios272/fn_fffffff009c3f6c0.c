// FUN_fffffff009c3f6c0 @ fffffff009c3f6c0 size=188

void FUN_fffffff009c3f6c0(long param_1,long param_2,ulong param_3,ulong param_4)

{
  int iVar1;
  undefined1 auStack_60 [8];
  ulong local_58;
  ulong uStack_50;
  long local_48;
  
  local_48 = *(long *)PTR_DAT_fffffff00806ca40;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xd8));
  iVar1 = FUN_fffffff009c3f044(param_1,param_4,auStack_60);
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xd8));
  if (iVar1 != 0) {
    local_58 = param_3 & 0xffffffff;
    uStack_50 = param_4 & 0xffffffff;
    thunk_EXT_FUN_80110000039a40ec(param_2 + 0x10,0,&local_58,2);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_48) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

