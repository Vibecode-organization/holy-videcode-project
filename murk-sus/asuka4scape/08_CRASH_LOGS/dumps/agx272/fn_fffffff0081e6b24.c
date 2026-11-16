// FUN_fffffff0081e6b24 @ fffffff0081e6b24 size=356

long FUN_fffffff0081e6b24(long param_1,ulong param_2,ulong param_3,uint param_4)

{
  undefined8 *puVar1;
  long *plVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  long lVar6;
  long local_48;
  
  thunk_EXT_FUN_801100000296c9fc();
  local_48 = 0;
  if ((param_4 != 6) && (param_4 != 0xd)) {
    if (param_4 != 0) {
      param_3 = param_3 >> ((ulong)DAT_fffffff00ae2181c & 0x3f);
      uVar4 = param_2 >> ((ulong)DAT_fffffff00ae2181c & 0x3f);
      uVar5 = uVar4 + param_3 & -param_3;
      if (param_3 == 0) {
        uVar5 = uVar4 + 1;
      }
      lVar6 = (ulong)param_4 * 8;
      puVar1 = (undefined8 *)(param_1 + 0x1f0 + (long)(int)lVar6);
      if (lVar6 != (int)lVar6) {
        puVar1 = (undefined8 *)(param_1 + 0x1f0 + lVar6 & 0xffffffffffffU | 0x2bad000000000000);
      }
      iVar3 = (**(code **)(*(long *)*puVar1 + 0xb0))((long *)*puVar1,uVar5,&local_48);
      lVar6 = 0;
      if (iVar3 != 0) {
        lVar6 = (ulong)param_4 * 8;
        plVar2 = (long *)(param_1 + 0xb8 + (long)(int)lVar6);
        if (lVar6 - (int)lVar6 != 0) {
          plVar2 = (long *)(param_1 + 0xb8 + lVar6 & 0xffffffffffffU | 0x2bad000000000000);
        }
        *plVar2 = *plVar2 + param_2;
        lVar6 = local_48 << ((ulong)DAT_fffffff00ae2181c & 0x3f);
      }
      thunk_EXT_FUN_801100000296ca08(param_1);
      return lVar6;
    }
    lVar6 = thunk_EXT_FUN_8011000003a49114
                      ("AGXk: %s:%d:%s: !!! Cannot allocate from default range!\n");
    return lVar6;
  }
  lVar6 = thunk_EXT_FUN_8011000003a49114
                    ("AGXk: %s:%d:%s: !!! Cannot allocate from unmapped range!\n");
  return lVar6;
}

