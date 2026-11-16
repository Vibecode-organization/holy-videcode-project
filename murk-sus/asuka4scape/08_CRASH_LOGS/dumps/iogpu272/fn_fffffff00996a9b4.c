// FUN_fffffff00996a9b4 @ fffffff00996a9b4 size=1116

void FUN_fffffff00996a9b4(long *param_1,long *param_2,int param_3)

{
  int *piVar1;
  undefined8 *puVar2;
  uint *puVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  long *plVar10;
  long lVar11;
  ulong uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  long lVar16;
  ulong uVar17;
  long lVar18;
  undefined1 auVar19 [16];
  undefined8 local_68;
  
  if (DAT_fffffff00af227e8 != 0) {
    uVar7 = (**(code **)(*param_2 + 0xe0))(param_2);
    local_68 = 0;
    thunk_EXT_FUN_80110000032db760(uVar7,&local_68);
    uVar7 = local_68;
    uVar8 = thunk_EXT_FUN_801100000390ebc0(param_1[2]);
    uVar9 = (**(code **)(*param_1 + 0xe0))(param_1);
    local_68 = 0;
    thunk_EXT_FUN_80110000032db760(uVar9,&local_68);
    thunk_EXT_FUN_80110000036da494(0x85180190,uVar7,uVar8,local_68,0,0);
  }
  uVar12 = (ulong)((long)param_2 * -0x61c8864680b583eb) >>
           ((ulong)(uint)-*(int *)((long)param_1 + 0xb4) & 0x3f);
  lVar16 = (uVar12 & 0xffffffff) * 4;
  iVar15 = (int)lVar16;
  puVar3 = (uint *)(param_1[0x12] + (long)iVar15);
  if (lVar16 - iVar15 != 0) {
    puVar3 = (uint *)(param_1[0x12] + lVar16 & 0xffffffffffffU | 0x2bad000000000000);
  }
  uVar13 = *puVar3;
LAB_fffffff00996aad0:
  if (uVar13 != 0) goto code_r0xfffffff00996aad4;
  uVar12 = (ulong)((long)param_2 * -0x61c8864680b583eb) >>
           ((ulong)(uint)-*(int *)((long)param_1 + 0x10c) & 0x3f);
  lVar16 = (uVar12 & 0xffffffff) * 4;
  iVar15 = (int)lVar16;
  puVar3 = (uint *)(param_1[0x1d] + (long)iVar15);
  if (lVar16 - iVar15 != 0) {
    puVar3 = (uint *)(param_1[0x1d] + lVar16 & 0xffffffffffffU | 0x2bad000000000000);
  }
  uVar13 = *puVar3;
  do {
    if (uVar13 == 0) {
      auVar19 = FUN_fffffff009983d34();
      FUN_fffffff00996a9b4(auVar19._0_8_,*(undefined8 *)(auVar19._8_8_ + 0x28));
      return;
    }
    uVar14 = (uVar13 & 0xaaaaaaaa) >> 1 | (uVar13 & 0x55555555) << 1;
    uVar14 = (uVar14 & 0xcccccccc) >> 2 | (uVar14 & 0x33333333) << 2;
    uVar14 = (uVar14 & 0xf0f0f0f0) >> 4 | (uVar14 & 0xf0f0f0f) << 4;
    uVar14 = (uVar14 & 0xff00ff00) >> 8 | (uVar14 & 0xff00ff) << 8;
    uVar14 = (uint)LZCOUNT(uVar14 >> 0x10 | uVar14 << 0x10);
    uVar6 = 1 << (ulong)(uVar14 & 0x1f);
    uVar13 = uVar13 & (uVar6 ^ 0xffffffff);
    uVar14 = uVar14 + (int)uVar12;
    uVar17 = (ulong)(uVar14 & (int)param_1[0x20] - 1U);
    lVar18 = param_1[0x1b];
    lVar11 = uVar17 * 8;
    plVar10 = (long *)(lVar18 + (int)lVar11);
    if (lVar11 != (int)lVar11) {
      plVar10 = (long *)(lVar18 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
    }
    plVar10 = (long *)*plVar10;
  } while (plVar10 != param_2);
  lVar11 = uVar17 * 4;
  piVar1 = (int *)(param_1[0x1c] + (long)(int)lVar11);
  if (lVar11 - (int)lVar11 != 0) {
    piVar1 = (int *)(param_1[0x1c] + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
  }
  iVar4 = *piVar1;
  *piVar1 = iVar4 + -1;
  if (iVar4 + -1 != 0) {
    return;
  }
  bVar5 = *(byte *)((long)param_1 + 0x129);
  lVar11 = (**(code **)(*plVar10 + 0x108))();
  param_1[0x24] = param_1[0x24] - lVar11;
  lVar11 = uVar17 * 8;
  puVar2 = (undefined8 *)(lVar18 + (int)lVar11);
  if (lVar11 - (int)lVar11 != 0) {
    puVar2 = (undefined8 *)(lVar18 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
  }
  plVar10 = (long *)*puVar2;
  if ((bVar5 & 1) == 0) {
    (**(code **)(*plVar10 + 0x28))(plVar10);
    *puVar2 = 0;
  }
  else {
    *puVar2 = 0;
    if (param_3 != 0) {
      FUN_fffffff009942c08(plVar10);
    }
    (**(code **)(*plVar10 + 0x28))(plVar10);
  }
  puVar3 = (uint *)(param_1[0x1d] + (long)iVar15);
  if (lVar16 - iVar15 != 0) {
    puVar3 = (uint *)(param_1[0x1d] + lVar16 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *puVar3 = *puVar3 & ~uVar6;
  lVar16 = 0x110;
  lVar11 = 0x108;
  lVar18 = 0xf0;
  goto LAB_fffffff00996adc0;
code_r0xfffffff00996aad4:
  uVar14 = (uVar13 & 0xaaaaaaaa) >> 1 | (uVar13 & 0x55555555) << 1;
  uVar14 = (uVar14 & 0xcccccccc) >> 2 | (uVar14 & 0x33333333) << 2;
  uVar14 = (uVar14 & 0xf0f0f0f0) >> 4 | (uVar14 & 0xf0f0f0f) << 4;
  uVar14 = (uVar14 & 0xff00ff00) >> 8 | (uVar14 & 0xff00ff) << 8;
  uVar14 = (uint)LZCOUNT(uVar14 >> 0x10 | uVar14 << 0x10);
  uVar6 = 1 << (ulong)(uVar14 & 0x1f);
  uVar13 = uVar13 & (uVar6 ^ 0xffffffff);
  uVar14 = uVar14 + (int)uVar12;
  uVar17 = (ulong)(uVar14 & (int)param_1[0x15] - 1U);
  lVar18 = param_1[0x10];
  lVar11 = uVar17 * 8;
  plVar10 = (long *)(lVar18 + (int)lVar11);
  if (lVar11 != (int)lVar11) {
    plVar10 = (long *)(lVar18 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
  }
  plVar10 = (long *)*plVar10;
  if (plVar10 == param_2) {
    lVar11 = uVar17 * 4;
    piVar1 = (int *)(param_1[0x11] + (long)(int)lVar11);
    if (lVar11 - (int)lVar11 != 0) {
      piVar1 = (int *)(param_1[0x11] + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
    }
    iVar4 = *piVar1;
    *piVar1 = iVar4 + -1;
    if (iVar4 + -1 == 0) {
      bVar5 = *(byte *)((long)param_1 + 0xd1);
      lVar11 = (**(code **)(*plVar10 + 0x108))();
      param_1[0x19] = param_1[0x19] - lVar11;
      lVar11 = uVar17 * 8;
      puVar2 = (undefined8 *)(lVar18 + (int)lVar11);
      if (lVar11 - (int)lVar11 != 0) {
        puVar2 = (undefined8 *)(lVar18 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
      }
      plVar10 = (long *)*puVar2;
      if ((bVar5 & 1) == 0) {
        (**(code **)(*plVar10 + 0x28))(plVar10);
        *puVar2 = 0;
      }
      else {
        *puVar2 = 0;
        if (((*(byte *)((long)param_1 + 0x24) >> 1 & 1) != 0) &&
           (FUN_fffffff0099437a0(plVar10), param_3 != 0)) {
          FUN_fffffff009942c08(plVar10);
        }
        (**(code **)(*plVar10 + 0x28))(plVar10);
      }
      puVar3 = (uint *)(param_1[0x12] + (long)iVar15);
      if (lVar16 - iVar15 != 0) {
        puVar3 = (uint *)(param_1[0x12] + lVar16 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar3 = *puVar3 & ~uVar6;
      lVar16 = 0xb8;
      lVar11 = 0xb0;
      lVar18 = 0x98;
LAB_fffffff00996adc0:
      uVar13 = *(uint *)((long)param_1 + lVar11) & uVar14 >> 6;
      *(ulong *)(*(long *)((long)param_1 + lVar18) + (ulong)uVar13 * 8) =
           *(ulong *)(*(long *)((long)param_1 + lVar18) + (ulong)uVar13 * 8) &
           (1L << ((ulong)uVar14 & 0x3f) ^ 0xffffffffffffffffU);
      *(int *)((long)param_1 + lVar16) = *(int *)((long)param_1 + lVar16) + -1;
    }
    return;
  }
  goto LAB_fffffff00996aad0;
}

