// FUN_fffffff0081bd13c @ fffffff0081bd13c size=1928

/* WARNING: Removing unreachable block (ram,0xfffffff0081bd1bc) */

undefined8 FUN_fffffff0081bd13c(long *param_1,long *param_2,uint param_3)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  uint *puVar7;
  ulong uVar8;
  undefined4 *puVar9;
  undefined *puVar10;
  undefined *puVar11;
  bool bVar12;
  int iVar13;
  uint uVar14;
  long lVar15;
  long *plVar16;
  float *pfVar17;
  undefined4 *puVar18;
  float extraout_s0;
  float fVar19;
  float extraout_s0_00;
  undefined4 uVar20;
  
  (**(code **)(*param_1 + 0x6c0))(param_1,0,0);
  lVar15 = (**(code **)(*param_2 + 0x138))(*param_2 + 0x138,param_2,"target");
  puVar11 = PTR_DAT_fffffff007ca60a8;
  if (lVar15 != 0) {
    plVar16 = (long *)thunk_EXT_FUN_8011000003890f30(lVar15,*(undefined8 *)PTR_DAT_fffffff007ca60a8)
    ;
    if (plVar16 == (long *)0x0) {
      return 0xe00002c2;
    }
    iVar13 = (**(code **)(*plVar16 + 0xa8))();
    lVar15 = (ulong)param_3 * 0x278;
    uVar8 = param_1[0x50] + 0x10ab8 + (long)(int)lVar15;
    if (lVar15 - (int)lVar15 != 0) {
      uVar8 = param_1[0x50] + 0x10ab8 + lVar15 & 0xffffffffffffU | 0x2bad000000000000;
    }
    lVar1 = param_1[0x123] + 0xc4;
    lVar15 = (ulong)param_3 + (ulong)param_3 * 4;
    uVar3 = lVar15 * 8 | 4;
    piVar6 = (int *)(lVar1 + (int)uVar3);
    if (uVar3 != (long)(int)uVar3) {
      piVar6 = (int *)(lVar1 + uVar3 & 0xffffffffffff | 0x2bad000000000000);
    }
    lVar15 = lVar15 * 8;
    lVar2 = lVar15 + 0x24;
    puVar7 = (uint *)(lVar1 + (int)lVar2);
    if (lVar2 != (int)lVar2) {
      puVar7 = (uint *)(lVar1 + lVar2 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *(int *)(uVar8 + 0x50) = iVar13;
    bVar12 = iVar13 != 0;
    iVar4 = *(int *)(uVar8 + 0xc);
    if (bVar12) {
      iVar4 = iVar13;
    }
    *piVar6 = iVar4;
    *puVar7 = (uint)bVar12;
    iVar4 = *(int *)(uVar8 + 0xc);
    if (bVar12) {
      iVar4 = iVar13;
    }
    uVar14 = iVar4 - 500U;
    if (*(uint *)(uVar8 + 0x1c) <= iVar4 - 500U) {
      uVar14 = *(uint *)(uVar8 + 0x1c);
    }
    *(uint *)(uVar8 + 0x10) = uVar14;
    if (*(uint *)(uVar8 + 0x54) != 0) {
      uVar14 = *(uint *)(uVar8 + 0x54);
    }
    lVar15 = lVar15 + 8;
    puVar7 = (uint *)(lVar1 + (int)lVar15);
    if (lVar15 != (int)lVar15) {
      puVar7 = (uint *)(lVar1 + lVar15 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *puVar7 = uVar14;
  }
  lVar15 = (**(code **)(*param_2 + 0x138))(param_2,"release");
  if (lVar15 != 0) {
    plVar16 = (long *)thunk_EXT_FUN_8011000003890f30(lVar15,*(undefined8 *)puVar11);
    if (plVar16 == (long *)0x0) {
      return 0xe00002c2;
    }
    uVar14 = (**(code **)(*plVar16 + 0xa8))();
    lVar15 = (ulong)param_3 * 0x278;
    uVar8 = param_1[0x50] + 0x10ab8 + (long)(int)lVar15;
    if (lVar15 - (int)lVar15 != 0) {
      uVar8 = param_1[0x50] + 0x10ab8 + lVar15 & 0xffffffffffffU | 0x2bad000000000000;
    }
    uVar5 = *(uint *)(uVar8 + 0xc);
    if (*(uint *)(uVar8 + 0x50) != 0) {
      uVar5 = *(uint *)(uVar8 + 0x50);
    }
    if (uVar5 < uVar14) {
      return 0xe00002c2;
    }
    *(uint *)(uVar8 + 0x54) = uVar14;
    uVar5 = *(uint *)(uVar8 + 0x10);
    if (uVar14 != 0) {
      uVar5 = uVar14;
    }
    lVar15 = (ulong)param_3 * 0x28 + 8;
    puVar7 = (uint *)(param_1[0x123] + 0xc4 + (long)(int)lVar15);
    if (lVar15 != (int)lVar15) {
      puVar7 = (uint *)(param_1[0x123] + 0xc4 + lVar15 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *puVar7 = uVar5;
  }
  lVar15 = (**(code **)(*param_2 + 0x138))(param_2,"analog_offset");
  if (lVar15 != 0) {
    plVar16 = (long *)thunk_EXT_FUN_8011000003890f30(lVar15,*(undefined8 *)puVar11);
    if (plVar16 == (long *)0x0) {
      return 0xe00002c2;
    }
    iVar13 = (**(code **)(*plVar16 + 0xa8))();
    lVar15 = (ulong)param_3 * 0x278;
    uVar8 = param_1[0x50] + 0x10ab8 + (long)(int)lVar15;
    if (lVar15 - (int)lVar15 != 0) {
      uVar8 = param_1[0x50] + 0x10ab8 + lVar15 & 0xffffffffffffU | 0x2bad000000000000;
    }
    bVar12 = iVar13 != *(int *)(uVar8 + 0x20);
    *(int *)(uVar8 + 0x58) = iVar13;
    *(uint *)(uVar8 + 0x5c) = (uint)bVar12;
    lVar15 = 0x58;
    if (!bVar12) {
      lVar15 = 0x20;
    }
    puVar9 = (undefined4 *)(uVar8 + (long)(int)lVar15);
    if (lVar15 != (int)lVar15) {
      puVar9 = (undefined4 *)(uVar8 + lVar15 & 0xffffffffffff | 0x2bad000000000000);
    }
    lVar15 = (ulong)param_3 * 0x28 + 0xc;
    puVar18 = (undefined4 *)(param_1[0x123] + 0xc4 + (long)(int)lVar15);
    if (lVar15 != (int)lVar15) {
      puVar18 = (undefined4 *)
                (param_1[0x123] + 0xc4 + lVar15 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *puVar18 = *puVar9;
  }
  lVar15 = (**(code **)(*param_2 + 0x138))(param_2,"targetDelta");
  if (lVar15 != 0) {
    plVar16 = (long *)thunk_EXT_FUN_8011000003890f30(lVar15,*(undefined8 *)puVar11);
    if (plVar16 == (long *)0x0) {
      return 0xe00002c2;
    }
    uVar14 = (**(code **)(*plVar16 + 0xa8))();
    lVar15 = (ulong)param_3 * 0x278;
    uVar8 = param_1[0x50] + 0x10ab8 + (long)(int)lVar15;
    if (lVar15 - (int)lVar15 != 0) {
      uVar8 = param_1[0x50] + 0x10ab8 + lVar15 & 0xffffffffffffU | 0x2bad000000000000;
    }
    uVar5 = *(uint *)(uVar8 + 0xc);
    if (*(uint *)(uVar8 + 0x50) != 0) {
      uVar5 = *(uint *)(uVar8 + 0x50);
    }
    if (uVar5 < uVar14) {
      return 0xe00002c2;
    }
    *(uint *)(uVar8 + 0x60) = uVar14;
    uVar5 = *(uint *)(uVar8 + 0x18);
    if (uVar14 != 0) {
      uVar5 = uVar14;
    }
    lVar15 = (ulong)param_3 * 0x28 + 0x10;
    puVar7 = (uint *)(param_1[0x123] + 0xc4 + (long)(int)lVar15);
    if (lVar15 != (int)lVar15) {
      puVar7 = (uint *)(param_1[0x123] + 0xc4 + lVar15 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *puVar7 = uVar5;
  }
  lVar15 = (**(code **)(*param_2 + 0x138))(param_2,"Kp");
  puVar10 = PTR_DAT_fffffff007ca6090;
  fVar19 = extraout_s0;
  if (lVar15 != 0) {
    plVar16 = (long *)thunk_EXT_FUN_8011000003890f30(lVar15,*(undefined8 *)PTR_DAT_fffffff007ca6090)
    ;
    if (plVar16 == (long *)0x0) {
      return 0xe00002c2;
    }
    pfVar17 = (float *)(**(code **)(*plVar16 + 0xd8))();
    lVar15 = (ulong)param_3 * 0x278;
    uVar8 = param_1[0x50] + 0x10ab8 + (long)(int)lVar15;
    if (lVar15 - (int)lVar15 != 0) {
      uVar8 = param_1[0x50] + 0x10ab8 + lVar15 & 0xffffffffffffU | 0x2bad000000000000;
    }
    fVar19 = *pfVar17;
    *(float *)(uVar8 + 100) = fVar19;
    if (fVar19 == 0.0) {
      fVar19 = *(float *)(uVar8 + 0x30);
    }
    lVar15 = (ulong)param_3 * 0x28 + 0x14;
    pfVar17 = (float *)(param_1[0x123] + 0xc4 + (long)(int)lVar15);
    if (lVar15 != (int)lVar15) {
      pfVar17 = (float *)(param_1[0x123] + 0xc4 + lVar15 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *pfVar17 = fVar19;
    fVar19 = *pfVar17;
  }
  lVar15 = (**(code **)(*param_2 + 0x138))(fVar19,param_2,"Ki");
  fVar19 = extraout_s0_00;
  if (lVar15 != 0) {
    plVar16 = (long *)thunk_EXT_FUN_8011000003890f30(lVar15,*(undefined8 *)puVar10);
    if (plVar16 == (long *)0x0) {
      return 0xe00002c2;
    }
    pfVar17 = (float *)(**(code **)(*plVar16 + 0xd8))();
    lVar15 = (ulong)param_3 * 0x278;
    uVar8 = param_1[0x50] + 0x10ab8 + (long)(int)lVar15;
    if (lVar15 - (int)lVar15 != 0) {
      uVar8 = param_1[0x50] + 0x10ab8 + lVar15 & 0xffffffffffffU | 0x2bad000000000000;
    }
    fVar19 = (float)NEON_ucvtf(*(undefined4 *)(uVar8 + 8));
    fVar19 = *pfVar17 * ((fVar19 / 24000.0) / 1000.0);
    *(float *)(uVar8 + 0x68) = fVar19;
    if (fVar19 == 0.0) {
      fVar19 = *(float *)(uVar8 + 0x34);
    }
    lVar15 = (ulong)param_3 * 0x28 + 0x18;
    pfVar17 = (float *)(param_1[0x123] + 0xc4 + (long)(int)lVar15);
    if (lVar15 != (int)lVar15) {
      pfVar17 = (float *)(param_1[0x123] + 0xc4 + lVar15 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *pfVar17 = fVar19;
    fVar19 = *pfVar17;
  }
  lVar15 = (**(code **)(*param_2 + 0x138))(fVar19,param_2,"control");
  if (lVar15 != 0) {
    plVar16 = (long *)thunk_EXT_FUN_8011000003890f30(lVar15,*(undefined8 *)puVar10);
    if (plVar16 == (long *)0x0) {
      return 0xe00002c2;
    }
    puVar18 = (undefined4 *)(**(code **)(*plVar16 + 0xd8))();
    lVar15 = (ulong)param_3 * 0x278 + 0x6c;
    puVar9 = (undefined4 *)(param_1[0x50] + 0x10ab8 + (long)(int)lVar15);
    if (lVar15 != (int)lVar15) {
      puVar9 = (undefined4 *)
               (param_1[0x50] + 0x10ab8 + lVar15 & 0xffffffffffffU | 0x2bad000000000000);
    }
    uVar20 = *puVar18;
    *puVar9 = uVar20;
    lVar15 = (ulong)param_3 * 0x28 + 0x1c;
    puVar9 = (undefined4 *)(param_1[0x123] + 0xc4 + (long)(int)lVar15);
    if (lVar15 != (int)lVar15) {
      puVar9 = (undefined4 *)(param_1[0x123] + 0xc4 + lVar15 & 0xffffffffffffU | 0x2bad000000000000)
      ;
    }
    *puVar9 = uVar20;
  }
  lVar15 = (**(code **)(*param_2 + 0x138))(param_2,"transfer");
  if (lVar15 == 0) {
    lVar15 = param_1[0x123];
  }
  else {
    plVar16 = (long *)thunk_EXT_FUN_8011000003890f30(lVar15,*(undefined8 *)puVar11);
    if (plVar16 == (long *)0x0) {
      return 0xe00002c2;
    }
    uVar20 = (**(code **)(*plVar16 + 0xa8))();
    lVar15 = (ulong)param_3 * 0x278 + 0x70;
    puVar9 = (undefined4 *)(param_1[0x50] + 0x10ab8 + (long)(int)lVar15);
    if (lVar15 != (int)lVar15) {
      puVar9 = (undefined4 *)
               (param_1[0x50] + 0x10ab8 + lVar15 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *puVar9 = uVar20;
    lVar15 = param_1[0x123];
    lVar1 = (ulong)param_3 * 0x28 + 0x20;
    puVar9 = (undefined4 *)(lVar15 + 0xc4 + (long)(int)lVar1);
    if (lVar1 != (int)lVar1) {
      puVar9 = (undefined4 *)(lVar15 + 0xc4 + lVar1 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *puVar9 = uVar20;
  }
  *(undefined4 *)(lVar15 + 0xc4) = 1;
  return 0;
}

