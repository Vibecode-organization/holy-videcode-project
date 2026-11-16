// FUN_fffffff0081e8150 @ fffffff0081e8150 size=324

undefined8 FUN_fffffff0081e8150(long param_1,uint param_2,ulong param_3,ulong param_4)

{
  undefined8 *puVar1;
  long lVar2;
  undefined8 uVar3;
  ulong uVar4;
  
  uVar4 = (ulong)DAT_fffffff00ae2181c;
  thunk_EXT_FUN_801100000296c9fc();
  if ((1 << (ulong)(param_2 & 0x1f) & 0x5f80U) != 0) {
    thunk_EXT_FUN_80110000032222a8(DAT_fffffff00ae23bd0);
    *(undefined1 *)(param_1 + 0x2a0) = 1;
  }
  if ((param_2 != 6) && (param_2 != 0xd)) {
    if (param_2 != 0) {
      lVar2 = (ulong)param_2 * 8;
      puVar1 = (undefined8 *)(param_1 + 0x1f0 + (long)(int)lVar2);
      if (lVar2 != (int)lVar2) {
        puVar1 = (undefined8 *)(param_1 + 0x1f0 + lVar2 & 0xffffffffffffU | 0x2bad000000000000);
      }
      uVar3 = (**(code **)(*(long *)*puVar1 + 0xb8))
                        ((long *)*puVar1,param_3 >> (uVar4 & 0x3f),param_4 >> (uVar4 & 0x3f));
      if ((*(byte *)(param_1 + 0x2a0) & 1) != 0) {
        *(undefined1 *)(param_1 + 0x2a0) = 0;
        thunk_EXT_FUN_8011000003222de0(DAT_fffffff00ae23bd0);
      }
      thunk_EXT_FUN_801100000296ca08(param_1);
      return uVar3;
    }
    uVar3 = thunk_EXT_FUN_8011000003a49114
                      ("AGXk: %s:%d:%s: !!! Cannot reserve from default range!\n");
    return uVar3;
  }
  uVar3 = thunk_EXT_FUN_8011000003a49114
                    ("AGXk: %s:%d:%s: !!! Cannot reserve from unmapped range!\n");
  return uVar3;
}

