// FUN_fffffff009c303bc @ fffffff009c303bc size=136

bool FUN_fffffff009c303bc(long param_1,undefined8 param_2,ulong param_3,ulong param_4)

{
  bool bVar1;
  
  if (!CARRY8(param_3,param_4)) {
    bVar1 = param_3 + param_4 <= *(ulong *)(param_1 + 0x48);
    if (bVar1) {
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x18));
      thunk_EXT_FUN_8011000003a61b10(param_2,*(long *)(param_1 + 0x50) + param_3,param_4);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x18));
    }
    return bVar1;
  }
  return false;
}

