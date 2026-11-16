// FUN_fffffff0081a7064 @ fffffff0081a7064 size=572

void FUN_fffffff0081a7064
               (long *param_1,long param_2,undefined4 *param_3,undefined8 param_4,ulong param_5,
               int param_6)

{
  long *plVar1;
  long *plVar2;
  undefined8 *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char cVar7;
  undefined8 uVar8;
  uint uVar9;
  long lVar10;
  int iVar11;
  undefined4 uVar12;
  long lVar13;
  undefined8 uVar14;
  ulong uVar15;
  
  if (param_6 == 0) {
    FUN_fffffff0081870cc(param_2,param_3[1]);
    uVar12 = *param_3;
  }
  else {
    lVar13 = (param_5 & 0xffffffff) * 0x28;
    iVar11 = (int)lVar13;
    plVar1 = (long *)((long)param_1 + (long)iVar11 + 0x4b8);
    if (lVar13 - iVar11 != 0) {
      plVar1 = (long *)((ulong)(param_1 + (param_5 & 0xffffffff) * 5 + 0x97) & 0xffffffffffff |
                       0x2bad000000000000);
    }
    uVar8 = FUN_fffffff0081a72a0(plVar1,*(undefined8 *)(param_1[0x50] + 0x310));
    uVar4 = param_3[1];
    uVar9 = *(uint *)(param_2 + 0xf0);
    if (uVar9 != uVar4) {
      lVar13 = *(long *)(param_2 + 0xe8);
      do {
        uVar5 = *(uint *)(param_2 + 0x58);
        uVar6 = 0;
        if (uVar5 != 0) {
          uVar6 = uVar9 / uVar5;
        }
        uVar15 = (ulong)(uVar9 - uVar6 * uVar5);
        lVar10 = uVar15 * 8;
        plVar2 = (long *)(lVar13 + (int)lVar10);
        if (lVar10 != (int)lVar10) {
          plVar2 = (long *)(lVar13 + lVar10 & 0xffffffffffffU | 0x2bad000000000000);
        }
        if (*plVar2 != 0) {
          thunk_EXT_FUN_801100000294b224();
          lVar13 = *(long *)(param_2 + 0xe8);
          lVar10 = uVar15 * 8;
          puVar3 = (undefined8 *)(lVar13 + (int)lVar10);
          if (lVar10 - (int)lVar10 != 0) {
            puVar3 = (undefined8 *)(lVar13 + lVar10 & 0xffffffffffffU | 0x2bad000000000000);
          }
          *puVar3 = 0;
          uVar9 = *(uint *)(param_2 + 0xf0);
        }
        uVar9 = uVar9 + 1;
        *(uint *)(param_2 + 0xf0) = uVar9;
      } while (uVar9 != uVar4);
    }
    (**(code **)(*param_1 + 0x1a8))(param_1,uVar8,2,param_2,*param_3);
    DataMemoryBarrier(2,3);
    cVar7 = (**(code **)(*plVar1 + 0x38))(plVar1);
    (**(code **)(*plVar1 + 0x10))(plVar1,cVar7 + '\x01');
    uVar12 = *param_3;
    *(undefined4 *)(param_2 + 0x78) = uVar12;
  }
  uVar4 = param_3[2];
  uVar9 = *(uint *)(param_2 + 0x104);
  while (uVar9 != uVar4) {
    lVar13 = *(long *)(param_2 + 0x10);
    if ((*(byte *)(lVar13 + 0x1ac44) >> 3 & 1) != 0) {
      uVar5 = *(uint *)(param_2 + 0x100);
      uVar6 = 0;
      if (uVar5 != 0) {
        uVar6 = uVar9 / uVar5;
      }
      lVar10 = (ulong)(uVar9 - uVar6 * uVar5) * 8;
      puVar3 = (undefined8 *)(*(long *)(param_2 + 0xf8) + (long)(int)lVar10);
      if (lVar10 != (int)lVar10) {
        puVar3 = (undefined8 *)
                 (*(long *)(param_2 + 0xf8) + lVar10 & 0xffffffffffffU | 0x2bad000000000000);
      }
      uVar8 = *puVar3;
      uVar14 = *(undefined8 *)(param_2 + 0x98);
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar13 + 0x1ac48));
      thunk_EXT_FUN_80110000036da494(0x85930c08,uVar8,uVar14,0,uVar12,0);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar13 + 0x1ac48));
      uVar9 = *(uint *)(param_2 + 0x104);
    }
    uVar9 = uVar9 + 1;
    *(uint *)(param_2 + 0x104) = uVar9;
  }
  return;
}

