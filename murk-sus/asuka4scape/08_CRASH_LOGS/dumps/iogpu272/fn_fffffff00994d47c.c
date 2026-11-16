// FUN_fffffff00994d47c @ fffffff00994d47c size=212

bool FUN_fffffff00994d47c(long param_1,long param_2)

{
  long *plVar1;
  int *piVar2;
  undefined8 *puVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  bool bVar7;
  
  thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(param_1 + 0x840));
  lVar4 = (long)*(int *)(param_2 + 0x18);
  if (*(int *)(param_2 + 0x18) < *(int *)(param_1 + 0x28)) {
    lVar5 = lVar4 * 0x18;
    plVar1 = (long *)(param_1 + 0x848 + (long)(int)lVar5);
    if (lVar5 - (int)lVar5 != 0) {
      plVar1 = (long *)(param_1 + 0x848 + lVar5 & 0xffffffffffffU | 0x2bad000000000000);
    }
    if (*plVar1 == param_2) {
      uVar6 = lVar4 << 4 | 8;
      piVar2 = (int *)(param_1 + 0x40 + (long)(int)uVar6);
      if (uVar6 != (long)(int)uVar6) {
        piVar2 = (int *)(param_1 + 0x40 + uVar6 & 0xffffffffffff | 0x2bad000000000000);
      }
      lVar4 = lVar4 * 8;
      puVar3 = (undefined8 *)(*(long *)(param_1 + 0x20) + (long)(int)lVar4);
      if (lVar4 - (int)lVar4 != 0) {
        puVar3 = (undefined8 *)
                 (*(long *)(param_1 + 0x20) + lVar4 & 0xffffffffffffU | 0x2bad000000000000);
      }
      bVar7 = *piVar2 - *(int *)*puVar3 < 1;
      goto LAB_fffffff00994d4e0;
    }
  }
  bVar7 = true;
LAB_fffffff00994d4e0:
  thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(param_1 + 0x840));
  return bVar7;
}

