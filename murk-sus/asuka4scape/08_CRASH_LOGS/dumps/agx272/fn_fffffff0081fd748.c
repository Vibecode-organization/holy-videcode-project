// FUN_fffffff0081fd748 @ fffffff0081fd748 size=160

undefined8
FUN_fffffff0081fd748(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  
  thunk_EXT_FUN_801100000296c9fc();
  if ((1 << (ulong)((uint)param_4 & 0x1f) & 0x5f80U) != 0) {
    thunk_EXT_FUN_80110000032222a8(DAT_fffffff00ae23bd0);
    *(undefined1 *)(param_1 + 0x2a0) = 1;
  }
  uVar1 = FUN_fffffff0081e6b24(param_1,param_2,param_3,param_4);
  if ((*(byte *)(param_1 + 0x2a0) & 1) != 0) {
    *(undefined1 *)(param_1 + 0x2a0) = 0;
    thunk_EXT_FUN_8011000003222de0(DAT_fffffff00ae23bd0);
  }
  thunk_EXT_FUN_801100000296ca08(param_1);
  return uVar1;
}

