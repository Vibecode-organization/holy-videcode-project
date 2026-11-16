// FUN_fffffff0081bccb4 @ fffffff0081bccb4 size=1160

/* WARNING: Removing unreachable block (ram,0xfffffff0081bcd2c) */

undefined8 FUN_fffffff0081bccb4(long *param_1,long *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  long lVar8;
  long *plVar9;
  float *pfVar10;
  undefined4 *puVar11;
  undefined4 extraout_s0;
  float fVar12;
  undefined4 uVar13;
  undefined4 extraout_s0_00;
  
  (**(code **)(*param_1 + 0x6c0))(param_1,0,0);
  lVar8 = (**(code **)(*param_2 + 0x138))(*param_2 + 0x138,param_2,"target");
  if (lVar8 != 0) {
    plVar9 = (long *)thunk_EXT_FUN_8011000003890f30(lVar8,*(undefined8 *)PTR_DAT_fffffff007ca60a8);
    if (plVar9 == (long *)0x0) {
      return 0xe00002c2;
    }
    iVar5 = (**(code **)(*plVar9 + 0xa8))();
    lVar8 = param_1[0x50];
    *(int *)(lVar8 + 0x10d7c) = iVar5;
    iVar1 = *(int *)(lVar8 + 0x10d54);
    if (iVar5 != 0) {
      iVar1 = iVar5;
    }
    uVar7 = 0;
    if (*(uint *)(lVar8 + 0x10d30) != 0) {
      uVar7 = (uint)(iVar1 * 100) / *(uint *)(lVar8 + 0x10d30);
    }
    if (99 < uVar7) {
      uVar7 = 100;
    }
    thunk_EXT_FUN_80110000039b78d4
              (*(undefined8 *)(*(long *)(lVar8 + 0x1ac50) + 0x130),0,
               (ulong)uVar7 * 0x1999999a >> 0x20);
    *(int *)(param_1[0x123] + 300) = iVar1;
  }
  lVar8 = (**(code **)(*param_2 + 0x138))(param_2,"Kp");
  puVar4 = PTR_DAT_fffffff007ca6090;
  uVar13 = extraout_s0;
  if (lVar8 != 0) {
    plVar9 = (long *)thunk_EXT_FUN_8011000003890f30(lVar8,*(undefined8 *)PTR_DAT_fffffff007ca6090);
    if (plVar9 == (long *)0x0) {
      return 0xe00002c2;
    }
    pfVar10 = (float *)(**(code **)(*plVar9 + 0xd8))();
    fVar12 = *pfVar10;
    lVar8 = param_1[0x50];
    *(float *)(lVar8 + 0x10d80) = fVar12;
    if (fVar12 == 0.0) {
      fVar12 = *(float *)(lVar8 + 0x10d68);
    }
    lVar8 = param_1[0x123];
    *(float *)(lVar8 + 0x130) = fVar12;
    uVar13 = *(undefined4 *)(lVar8 + 0x130);
  }
  lVar8 = (**(code **)(*param_2 + 0x138))(uVar13,param_2,"Ki");
  uVar13 = extraout_s0_00;
  if (lVar8 != 0) {
    plVar9 = (long *)thunk_EXT_FUN_8011000003890f30(lVar8,*(undefined8 *)puVar4);
    if (plVar9 == (long *)0x0) {
      return 0xe00002c2;
    }
    pfVar10 = (float *)(**(code **)(*plVar9 + 0xd8))();
    lVar8 = param_1[0x50];
    fVar12 = (float)NEON_ucvtf(*(undefined4 *)(lVar8 + 0x10d34));
    fVar12 = *pfVar10 * (fVar12 / 1000.0);
    *(float *)(lVar8 + 0x10d84) = fVar12;
    if (fVar12 == 0.0) {
      fVar12 = *(float *)(lVar8 + 0x10d5c);
    }
    lVar8 = param_1[0x123];
    *(float *)(lVar8 + 0x134) = fVar12;
    uVar13 = *(undefined4 *)(lVar8 + 0x134);
  }
  lVar8 = (**(code **)(*param_2 + 0x138))(uVar13,param_2,"tfc");
  if (lVar8 != 0) {
    plVar9 = (long *)thunk_EXT_FUN_8011000003890f30(lVar8,*(undefined8 *)PTR_DAT_fffffff007ca60a8);
    if (plVar9 == (long *)0x0) {
      return 0xe00002c2;
    }
    iVar5 = (**(code **)(*plVar9 + 0xa8))();
    lVar8 = param_1[0x50];
    *(int *)(lVar8 + 0x10d90) = iVar5;
    iVar1 = *(int *)(lVar8 + 0x10d38);
    if (iVar5 != 0) {
      iVar1 = iVar5;
    }
    *(int *)(param_1[0x123] + 0x138) = iVar1;
  }
  lVar8 = (**(code **)(*param_2 + 0x138))(param_2,"tfc-ms");
  if (lVar8 != 0) {
    plVar9 = (long *)thunk_EXT_FUN_8011000003890f30(lVar8,*(undefined8 *)PTR_DAT_fffffff007ca60a8);
    if (plVar9 == (long *)0x0) {
      return 0xe00002c2;
    }
    uVar6 = (**(code **)(*plVar9 + 0xa8))();
    lVar8 = param_1[0x50];
    uVar7 = *(uint *)(lVar8 + 0x10d34);
    uVar3 = 0;
    if (uVar7 != 0) {
      uVar3 = uVar6 / uVar7;
    }
    *(uint *)(lVar8 + 0x10d90) = uVar3;
    uVar2 = *(uint *)(lVar8 + 0x10d38);
    if (uVar7 <= uVar6) {
      uVar2 = uVar3;
    }
    *(uint *)(param_1[0x123] + 0x138) = uVar2;
  }
  lVar8 = (**(code **)(*param_2 + 0x138))(param_2,"control");
  if (lVar8 != 0) {
    plVar9 = (long *)thunk_EXT_FUN_8011000003890f30(lVar8,*(undefined8 *)puVar4);
    if (plVar9 == (long *)0x0) {
      return 0xe00002c2;
    }
    puVar11 = (undefined4 *)(**(code **)(*plVar9 + 0xd8))();
    uVar13 = *puVar11;
    *(undefined4 *)(param_1[0x50] + 69000) = uVar13;
    *(undefined4 *)(param_1[0x123] + 0x13c) = uVar13;
  }
  lVar8 = (**(code **)(*param_2 + 0x138))(param_2,"transfer");
  if (lVar8 == 0) {
    lVar8 = param_1[0x123];
  }
  else {
    plVar9 = (long *)thunk_EXT_FUN_8011000003890f30(lVar8,*(undefined8 *)PTR_DAT_fffffff007ca60a8);
    if (plVar9 == (long *)0x0) {
      return 0xe00002c2;
    }
    uVar7 = (**(code **)(*plVar9 + 0xa8))();
    lVar8 = param_1[0x50];
    if (uVar7 != 0) {
      if (uVar7 < *(uint *)(lVar8 + 0x10d70)) {
        return 0xe00002c2;
      }
      if (*(uint *)(lVar8 + 0x10d74) < uVar7) {
        return 0xe00002c2;
      }
    }
    *(uint *)(lVar8 + 0x10d8c) = uVar7;
    lVar8 = param_1[0x123];
    *(uint *)(lVar8 + 0x140) = uVar7;
  }
  *(undefined4 *)(lVar8 + 0x128) = 1;
  return 0;
}

