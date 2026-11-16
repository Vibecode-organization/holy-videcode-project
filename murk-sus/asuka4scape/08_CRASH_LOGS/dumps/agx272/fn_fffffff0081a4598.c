// FUN_fffffff0081a4598 @ fffffff0081a4598 size=732

undefined8 FUN_fffffff0081a4598(long param_1,undefined8 *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  long *plVar6;
  long *plVar7;
  uint uVar8;
  ulong uVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  undefined8 *puVar14;
  ulong uVar15;
  ulong uVar16;
  
  uVar9 = param_2[2];
  *(undefined4 *)(uVar9 + 0x14) = 0;
  uVar2 = *(uint *)(param_2 + 3);
  if (1 < uVar2) {
    lVar12 = (ulong)uVar2 - 1;
    lVar13 = 1;
    do {
      uVar15 = uVar9 + lVar13 * 0x18 + -0x18;
      if (((uVar9 ^ uVar15) & 0xffc0000000000000) != 0) {
        uVar15 = uVar15 & 0xffffffffffff | 0xc8a2000000000000;
      }
      uVar16 = uVar9 + lVar13 * 0x18;
      if (((uVar9 ^ uVar16) & 0xffc0000000000000) != 0) {
        uVar16 = uVar16 & 0xffffffffffff | 0xc8a2000000000000;
      }
      *(uint *)(uVar16 + 0x14) =
           *(int *)(uVar15 + 0x14) + *(int *)(uVar15 + 0x10) + 0x3fU & 0xffffffc0;
      lVar13 = lVar13 + 1;
      lVar12 = lVar12 + -1;
    } while (lVar12 != 0);
  }
  lVar13 = (ulong)(uVar2 - 1) * 0x18;
  uVar15 = uVar9 + (long)(int)lVar13;
  if (lVar13 - (int)lVar13 != 0) {
    uVar15 = uVar9 + lVar13 & 0xffffffffffff | 0x2bad000000000000;
  }
  iVar5 = *(int *)(uVar15 + 0x10);
  iVar1 = *(int *)(uVar15 + 0x14);
  uVar2 = *(uint *)PTR_DAT_fffffff007ca5f88;
  plVar6 = (long *)(**(code **)(DAT_fffffff00ae22f20 + 0x68))();
  if (plVar6 == (long *)0x0) {
    return 0;
  }
  iVar4 = 1 << (ulong)(uVar2 & 0x1f);
  uVar2 = (iVar1 + iVar5 + iVar4) - 1U & -iVar4;
  lVar13 = *(long *)(param_1 + 0x280);
  uVar8 = 0x22;
  if (param_3 == 0) {
    uVar8 = 0x23;
  }
  uVar3 = *(uint *)(lVar13 + 0x18b70);
  plVar6[2] = *(long *)PTR_DAT_fffffff007ca61d0;
  iVar5 = FUN_fffffff0081e07cc(plVar6,lVar13,uVar2,uVar3 | uVar8);
  if ((iVar5 != 0) &&
     (lVar13 = FUN_fffffff0081e0954(plVar6,param_3 ^ 1,*(undefined4 *)(param_2 + 1),param_2[4]),
     lVar13 != 0)) {
    plVar7 = (long *)plVar6[0xc];
    if (plVar7 == (long *)0x0) {
      lVar13 = thunk_EXT_FUN_801100000297ea14(plVar6[9],0);
      plVar6[0xc] = lVar13;
      if (lVar13 == 0) goto LAB_fffffff0081a484c;
      LOAcquire();
      DAT_fffffff00ae22f48 = DAT_fffffff00ae22f48 + plVar6[6];
      LORelease();
      plVar7 = (long *)plVar6[0xc];
    }
    lVar13 = (**(code **)(*plVar7 + 0x78))();
    if (lVar13 != 0) {
      *(long **)*param_2 = plVar6;
      lVar13 = (**(code **)(*(long *)plVar6[0xc] + 0x78))();
      lVar12 = (**(code **)(**(long **)(*(long *)*param_2 + 0x50) + 0x98))();
      thunk_EXT_FUN_8011000003a61cc0(lVar13,uVar2);
      uVar2 = *(uint *)(param_2 + 3);
      if (uVar2 != 0) {
        lVar10 = 0;
        lVar11 = 0;
        uVar9 = param_2[2];
        do {
          puVar14 = (undefined8 *)(uVar9 + lVar11 * 0x18);
          if (((uVar9 ^ (ulong)puVar14) & 0xffc0000000000000) != 0) {
            puVar14 = (undefined8 *)((ulong)puVar14 & 0xffffffffffff | 0xc8a2000000000000);
          }
          *(ulong *)*puVar14 = lVar13 + (ulong)*(uint *)((long)puVar14 + 0x14);
          uVar9 = param_2[2];
          uVar15 = uVar9 + lVar11 * 0x18;
          if (((uVar9 ^ uVar15) & 0xffc0000000000000) != 0) {
            uVar15 = uVar15 & 0xffffffffffff | 0xc8a2000000000000;
          }
          **(long **)(uVar15 + 8) = lVar12 + (ulong)*(uint *)(uVar15 + 0x14);
          lVar11 = lVar11 + 1;
          lVar10 = lVar10 + 0x18;
        } while ((ulong)uVar2 * 0x18 - lVar10 != 0);
      }
      return 1;
    }
  }
LAB_fffffff0081a484c:
  (**(code **)(*plVar6 + 0x28))(plVar6);
  return 0;
}

