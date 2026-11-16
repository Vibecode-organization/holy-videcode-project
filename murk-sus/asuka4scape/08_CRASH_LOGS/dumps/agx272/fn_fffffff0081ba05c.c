// FUN_fffffff0081ba05c @ fffffff0081ba05c size=148

undefined8 FUN_fffffff0081ba05c(long *param_1,ulong param_2)

{
  if (0x10000 < (uint)param_2) {
    return 0xe00002c2;
  }
  thunk_EXT_FUN_80110000032222a8(param_1[0x178]);
  *(uint *)(param_1 + 0x177) = (uint)param_2;
  if ((*(byte *)(param_1 + 0x176) & 1) == 0) {
    param_2 = (ulong)*(uint *)((long)param_1 + 0xbb4);
  }
  (**(code **)(*param_1 + 0x9e8))(param_1,param_2);
  thunk_EXT_FUN_8011000003222de0(param_1[0x178]);
  return 0;
}

