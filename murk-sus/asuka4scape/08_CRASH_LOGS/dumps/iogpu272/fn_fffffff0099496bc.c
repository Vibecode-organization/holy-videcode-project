// FUN_fffffff0099496bc @ fffffff0099496bc size=188

void FUN_fffffff0099496bc(long param_1,undefined8 param_2,ulong param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined4 local_438 [256];
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff007ff2800;
  if (param_3 < 0x101) {
    if (param_3 < 2) {
      local_438[0] = (undefined4)param_4;
      if (param_3 == 0) {
        uVar1 = 0;
        goto LAB_fffffff009949748;
      }
    }
    else {
      uVar1 = thunk_EXT_FUN_8011000003385b14(param_4,local_438,param_3 << 2);
      if ((int)uVar1 != 0) goto LAB_fffffff009949748;
    }
    uVar1 = FUN_fffffff009967d10(*(undefined8 *)(param_1 + 0x120),param_2,local_438,param_3);
  }
  else {
    uVar1 = 0xe00002c2;
  }
LAB_fffffff009949748:
  if (*(long *)PTR_DAT_fffffff007ff2800 == local_38) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590(uVar1);
  return;
}

