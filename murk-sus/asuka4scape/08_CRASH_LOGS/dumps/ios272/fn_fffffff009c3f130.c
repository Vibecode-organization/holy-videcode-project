// FUN_fffffff009c3f130 @ fffffff009c3f130 size=160

undefined8 FUN_fffffff009c3f130(long param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 *local_38;
  undefined8 local_30;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff00806ca40;
  local_38 = &DAT_aaaaaaaaaaaaaaaa;
  local_30 = 0;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xd8));
  iVar1 = FUN_fffffff009c3f044(param_1,param_2,&local_38);
  uVar2 = 0;
  if (iVar1 != 0) {
    FUN_fffffff009c16670(&local_30,local_38);
    uVar2 = local_30;
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xd8));
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_28) {
    return uVar2;
  }
  uVar2 = thunk_EXT_FUN_8011000003a48590();
  return uVar2;
}

