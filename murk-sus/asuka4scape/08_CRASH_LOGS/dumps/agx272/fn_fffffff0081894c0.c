// FUN_fffffff0081894c0 @ fffffff0081894c0 size=140

undefined8 FUN_fffffff0081894c0(long param_1)

{
  int iVar1;
  long lVar2;
  
  iVar1 = FUN_fffffff0081e0b20(*(undefined8 *)(param_1 + 0x30));
  if (iVar1 == 0) {
    iVar1 = FUN_fffffff0081e0b20(*(undefined8 *)(param_1 + 0x278));
    if (iVar1 == 0) {
      return 1;
    }
    lVar2 = *(long *)(param_1 + 0x30);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar2 + 0x40));
    if (0 < *(long *)(lVar2 + 0x38)) {
      if (*(long *)(lVar2 + 0x50) != 0) {
        thunk_EXT_FUN_801100000297b408();
      }
      if (*(long *)(lVar2 + 0x58) != 0) {
        thunk_EXT_FUN_801100000297b408();
      }
      *(long *)(lVar2 + 0x38) = *(long *)(lVar2 + 0x38) + -1;
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar2 + 0x40));
  }
  return 0;
}

