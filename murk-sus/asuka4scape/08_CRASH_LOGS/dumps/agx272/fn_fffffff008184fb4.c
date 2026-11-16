// FUN_fffffff008184fb4 @ fffffff008184fb4 size=972

void FUN_fffffff008184fb4(long *param_1)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  int iVar6;
  long *plVar7;
  int *piVar8;
  ulong uVar9;
  long lVar10;
  ulong uVar11;
  ulong uVar12;
  long lVar13;
  ulong unaff_x30;
  
  (**(code **)(*param_1 + 0x100))();
  if ((long *)param_1[0x2c] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x2c] + 0x28))();
  }
  param_1[0x2c] = 0;
  iVar6 = (int)param_1[8];
  if (iVar6 != -1) {
    if ((long *)param_1[0x19] != (long *)0x0) {
      (**(code **)(*(long *)param_1[0x19] + 0x28))();
      iVar6 = (int)param_1[8];
    }
    param_1[0x19] = 0;
    FUN_fffffff0081b6df8(*(undefined8 *)(param_1[2] + 0x4b0),iVar6);
    param_1[0xc] = 0;
    param_1[0x12] = 0;
    param_1[0x13] = 0;
    param_1[0x11] = 0;
    *(undefined4 *)(param_1 + 8) = 0xffffffff;
  }
  iVar6 = *(int *)((long)param_1 + 0x44);
  if (iVar6 != -1) {
    if ((long *)param_1[0x1a] != (long *)0x0) {
      (**(code **)(*(long *)param_1[0x1a] + 0x28))();
      iVar6 = *(int *)((long)param_1 + 0x44);
    }
    param_1[0x1a] = 0;
    FUN_fffffff0081b7190(*(undefined8 *)(param_1[2] + 0x4b0),iVar6);
    param_1[0xd] = 0;
    param_1[0x14] = 0;
    *(undefined4 *)((long)param_1 + 0x44) = 0xffffffff;
  }
  uVar2 = *(uint *)(param_1 + 9);
  if (uVar2 != 0xffffffff) {
    if ((long *)param_1[0x1b] != (long *)0x0) {
      (**(code **)(*(long *)param_1[0x1b] + 0x28))();
      uVar2 = *(uint *)(param_1 + 9);
    }
    param_1[0x1b] = 0;
    lVar13 = *(long *)(param_1[2] + 0x4b0);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar13 + 0xee8));
    if ((uVar2 == 0xffffffff) ||
       (uVar3 = *(uint *)(lVar13 + 0xef8), uVar9 = *(long *)(lVar13 + 0xf30) * (ulong)uVar3,
       uVar9 < uVar2 || uVar9 - uVar2 == 0)) {
      thunk_EXT_FUN_8011000003a49114
                (
                "AGXk: %s:%d:%s: !!! Assertion failed: %s: Attempt to release an out-of-range element (%d)\n"
                );
      return;
    }
    uVar4 = 0;
    if (uVar3 != 0) {
      uVar4 = uVar2 / uVar3;
    }
    lVar10 = (ulong)uVar4 * 8;
    puVar1 = (undefined8 *)(*(long *)(lVar13 + 0xf28) + (long)(int)lVar10);
    if (lVar10 != (int)lVar10) {
      puVar1 = (undefined8 *)
               (*(long *)(lVar13 + 0xf28) + lVar10 & 0xffffffffffffU | 0x2bad000000000000);
    }
    piVar8 = (int *)*puVar1;
    if (piVar8 == (int *)0x0) {
      thunk_EXT_FUN_8011000003a49114
                ("AGXk: %s:%d:%s: !!! Assertion failed: %s: Invalid allocation\n");
      return;
    }
    if (*piVar8 == 0) {
      thunk_EXT_FUN_8011000003a49114
                ("AGXk: %s:%d:%s: !!! Assertion failed: %s: Invalid ref count (%d %d)\n");
      return;
    }
    *piVar8 = *piVar8 + -1;
    lVar10 = *(long *)(lVar13 + 0xf48) + (ulong)(uVar2 >> 8) * 0x20;
    uVar9 = (ulong)((uVar2 & 0xff) >> 6);
    uVar12 = 1L << ((ulong)(uVar2 & 0xff) & 0x3f);
    if ((*(ulong *)(lVar10 + uVar9 * 8) & uVar12) != 0) {
      thunk_EXT_FUN_8011000003a49114
                ("AGXk: %s:%d:%s: !!! Assertion failed: %s: Invalid element (%d)\n");
      return;
    }
    uVar11 = (ulong)(uVar2 >> 0xb) & 0x1ffff8;
    *(ulong *)(lVar13 + 0xf40 + uVar11) =
         *(ulong *)(lVar13 + 0xf40 + uVar11) | 1L << ((ulong)(uVar2 >> 8) & 0x3f);
    *(ulong *)(lVar10 + uVar9 * 8) = *(ulong *)(lVar10 + uVar9 * 8) | uVar12;
    FUN_fffffff0081b0d4c(lVar13 + 0xeb0,(ulong)uVar4,1);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar13 + 0xee8));
    param_1[0xe] = 0;
    param_1[0x15] = 0;
    *(undefined4 *)(param_1 + 9) = 0xffffffff;
  }
  lVar13 = param_1[0x1d];
  if (lVar13 != 0) {
    lVar10 = (long)(int)*(uint *)(param_1 + 0xb) << 3;
    if (0x7fffffff < *(uint *)(param_1 + 0xb)) {
      lVar10 = -0x8000000000000000;
    }
    param_1[0x1d] = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca2f28,lVar13,lVar10);
  }
  plVar7 = (long *)param_1[0x10];
  if (plVar7 != (long *)0x0) {
    if ((*(byte *)(param_1[2] + 0x5cc) >> 6 & 1) != 0) {
      FUN_fffffff00817ec08();
      plVar7 = (long *)param_1[0x10];
      if (plVar7 == (long *)0x0) goto LAB_fffffff00818524c;
    }
    (**(code **)(*plVar7 + 0x28))(plVar7);
  }
LAB_fffffff00818524c:
  param_1[0x10] = 0;
  lVar13 = param_1[0x1f];
  if (lVar13 != 0) {
    param_1[0x1f] = 0;
    thunk_EXT_FUN_80110000038fe6b0(lVar13,(ulong)*(uint *)(param_1 + 0x20) << 3);
  }
  if (param_1[0x2e] != 0) {
    thunk_EXT_FUN_80110000038ff020();
    param_1[0x2e] = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081852a8);
    (*pcVar5)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081852b0. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca60e8 + 0x80))(param_1);
  return;
}

