// FUN_fffffff0081e0b20 @ fffffff0081e0b20 size=132

undefined8 FUN_fffffff0081e0b20(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x50);
  if ((lVar2 == 0) || (iVar1 = thunk_EXT_FUN_801100000297b3fc(lVar2), iVar1 == 0)) {
    if ((*(long *)(param_1 + 0x58) == 0) || (iVar1 = thunk_EXT_FUN_801100000297b3fc(), iVar1 == 0))
    {
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x40));
      *(long *)(param_1 + 0x38) = *(long *)(param_1 + 0x38) + 1;
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x40));
      return 0;
    }
    if (lVar2 == 0) {
      return 0xe00002be;
    }
    thunk_EXT_FUN_801100000297b408(*(undefined8 *)(param_1 + 0x50));
  }
  return 0xe00002be;
}

