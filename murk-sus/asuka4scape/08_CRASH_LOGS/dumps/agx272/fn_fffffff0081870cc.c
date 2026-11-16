// FUN_fffffff0081870cc @ fffffff0081870cc size=176

void FUN_fffffff0081870cc(long param_1,uint param_2)

{
  long *plVar1;
  undefined8 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  
  uVar5 = *(uint *)(param_1 + 0xf0);
  if (uVar5 != param_2) {
    lVar7 = *(long *)(param_1 + 0xe8);
    do {
      uVar3 = *(uint *)(param_1 + 0x58);
      uVar4 = 0;
      if (uVar3 != 0) {
        uVar4 = uVar5 / uVar3;
      }
      uVar8 = (ulong)(uVar5 - uVar4 * uVar3);
      lVar6 = uVar8 * 8;
      plVar1 = (long *)(lVar7 + (int)lVar6);
      if (lVar6 != (int)lVar6) {
        plVar1 = (long *)(lVar7 + lVar6 & 0xffffffffffffU | 0x2bad000000000000);
      }
      if (*plVar1 != 0) {
        thunk_EXT_FUN_801100000294b224();
        lVar7 = *(long *)(param_1 + 0xe8);
        lVar6 = uVar8 * 8;
        puVar2 = (undefined8 *)(lVar7 + (int)lVar6);
        if (lVar6 - (int)lVar6 != 0) {
          puVar2 = (undefined8 *)(lVar7 + lVar6 & 0xffffffffffffU | 0x2bad000000000000);
        }
        *puVar2 = 0;
        uVar5 = *(uint *)(param_1 + 0xf0);
      }
      uVar5 = uVar5 + 1;
      *(uint *)(param_1 + 0xf0) = uVar5;
    } while (uVar5 != param_2);
  }
  return;
}

