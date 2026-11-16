// FUN_fffffff0081e8f54 @ fffffff0081e8f54 size=156

undefined8 FUN_fffffff0081e8f54(long param_1,long param_2,long param_3)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  if ((param_2 != 0) && (param_3 != 0)) {
    if ((*(byte *)(param_3 + 0xb1) & 1) == 0) {
      return 0;
    }
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x18));
    if ((*(uint *)(param_1 + 0x20) < 0x400) && (uVar1 = *(uint *)(param_2 + 0x1b8), uVar1 < 0x20)) {
      *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) + 1;
      *(uint *)(param_2 + 0x1b8) = uVar1 + 1;
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x18));
  }
  return uVar2;
}

