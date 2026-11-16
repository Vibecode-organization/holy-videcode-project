// FUN_fffffff00819b1bc @ fffffff00819b1bc size=1820

void FUN_fffffff00819b1bc(long param_1)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  long *plVar6;
  undefined1 *puVar7;
  long lVar8;
  int *piVar9;
  long lVar10;
  ulong uVar11;
  long lVar12;
  ulong uVar13;
  long lVar14;
  ulong uVar15;
  long lVar16;
  ulong unaff_x30;
  
  thunk_EXT_FUN_8011000003224180(*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x11a70));
  if (*(long *)(param_1 + 0xe0) != 0) {
    plVar6 = *(long **)(*(long *)(param_1 + 0x10) + 0x4b0);
    puVar7 = *(undefined1 **)(param_1 + 200);
    (**(code **)(*plVar6 + 0x1c0))
              (plVar6,*(long *)(param_1 + 0xe0),*puVar7,puVar7[1],puVar7[4],puVar7[0x26]);
  }
  thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x11a70));
  if (*(long **)(param_1 + 0x28) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x28) + 0x28))();
    *(undefined8 *)(param_1 + 0x28) = 0;
    *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + -1;
  }
  if (*(long **)(param_1 + 0x30) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x30) + 0x28))();
    *(undefined8 *)(param_1 + 0x30) = 0;
    *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + -1;
  }
  if (*(long **)(param_1 + 0x38) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x38) + 0x28))();
    *(undefined8 *)(param_1 + 0x38) = 0;
    *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + -1;
  }
  if (*(long **)(param_1 + 0x40) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x40) + 0x28))();
    *(undefined8 *)(param_1 + 0x40) = 0;
    *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + -1;
  }
  if (*(long **)(param_1 + 0x48) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x48) + 0x28))();
    *(undefined8 *)(param_1 + 0x48) = 0;
    *(int *)(param_1 + 0x9c) = *(int *)(param_1 + 0x9c) + -1;
  }
  if (*(long **)(param_1 + 0x50) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x50) + 0x28))();
    *(undefined8 *)(param_1 + 0x50) = 0;
    *(int *)(param_1 + 0x9c) = *(int *)(param_1 + 0x9c) + -1;
  }
  if (*(long **)(param_1 + 0x58) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x58) + 0x28))();
    *(undefined8 *)(param_1 + 0x58) = 0;
    *(int *)(param_1 + 0x9c) = *(int *)(param_1 + 0x9c) + -1;
  }
  if (*(long **)(param_1 + 0x60) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x60) + 0x28))();
    *(undefined8 *)(param_1 + 0x60) = 0;
    *(int *)(param_1 + 0x9c) = *(int *)(param_1 + 0x9c) + -1;
  }
  if (*(long **)(param_1 + 0x68) == (long *)0x0) {
    plVar6 = *(long **)(param_1 + 0x80);
    if (plVar6 == (long *)0x0) goto LAB_fffffff00819b3f8;
LAB_fffffff00819b774:
    (**(code **)(*plVar6 + 0x28))();
    *(undefined8 *)(param_1 + 0x80) = 0;
    plVar6 = *(long **)(param_1 + 0x70);
    if (plVar6 != (long *)0x0) goto LAB_fffffff00819b79c;
LAB_fffffff00819b400:
    plVar6 = *(long **)(param_1 + 0x88);
    if (plVar6 == (long *)0x0) goto LAB_fffffff00819b408;
LAB_fffffff00819b7c4:
    (**(code **)(*plVar6 + 0x28))();
    *(undefined8 *)(param_1 + 0x88) = 0;
    plVar6 = *(long **)(param_1 + 0x78);
    if (plVar6 != (long *)0x0) goto LAB_fffffff00819b7ec;
LAB_fffffff00819b410:
    plVar6 = *(long **)(param_1 + 0x90);
    if (plVar6 == (long *)0x0) goto LAB_fffffff00819b418;
LAB_fffffff00819b814:
    (**(code **)(*plVar6 + 0x28))();
    *(undefined8 *)(param_1 + 0x90) = 0;
    plVar6 = *(long **)(param_1 + 0xa0);
  }
  else {
    (**(code **)(**(long **)(param_1 + 0x68) + 0x28))();
    *(undefined8 *)(param_1 + 0x68) = 0;
    plVar6 = *(long **)(param_1 + 0x80);
    if (plVar6 != (long *)0x0) goto LAB_fffffff00819b774;
LAB_fffffff00819b3f8:
    plVar6 = *(long **)(param_1 + 0x70);
    if (plVar6 == (long *)0x0) goto LAB_fffffff00819b400;
LAB_fffffff00819b79c:
    (**(code **)(*plVar6 + 0x28))();
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar6 = *(long **)(param_1 + 0x88);
    if (plVar6 != (long *)0x0) goto LAB_fffffff00819b7c4;
LAB_fffffff00819b408:
    plVar6 = *(long **)(param_1 + 0x78);
    if (plVar6 == (long *)0x0) goto LAB_fffffff00819b410;
LAB_fffffff00819b7ec:
    (**(code **)(*plVar6 + 0x28))();
    *(undefined8 *)(param_1 + 0x78) = 0;
    plVar6 = *(long **)(param_1 + 0x90);
    if (plVar6 != (long *)0x0) goto LAB_fffffff00819b814;
LAB_fffffff00819b418:
    plVar6 = *(long **)(param_1 + 0xa0);
  }
  if (plVar6 != (long *)0x0) {
    (**(code **)(*plVar6 + 0x28))();
  }
  *(undefined8 *)(param_1 + 0xa0) = 0;
  if (*(long **)(param_1 + 0xb0) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0xb0) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0xb0) = 0;
  if (*(long **)(param_1 + 0xa8) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0xa8) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0xa8) = 0;
  plVar6 = *(long **)(param_1 + 0xb8);
  if (plVar6 == (long *)0x0) goto LAB_fffffff00819b510;
  if (*(int *)(param_1 + 0xc0) == 0) {
LAB_fffffff00819b4ec:
    (**(code **)(*plVar6 + 0x28))(plVar6);
  }
  else {
    thunk_EXT_FUN_80110000032222a8(plVar6[8]);
    if (0 < plVar6[7]) {
      if (plVar6[10] != 0) {
        thunk_EXT_FUN_801100000297b408();
      }
      if (plVar6[0xb] != 0) {
        thunk_EXT_FUN_801100000297b408();
      }
      plVar6[7] = plVar6[7] + -1;
    }
    thunk_EXT_FUN_8011000003222de0(plVar6[8]);
    *(undefined4 *)(param_1 + 0xc0) = 0;
    plVar6 = *(long **)(param_1 + 0xb8);
    if (plVar6 != (long *)0x0) goto LAB_fffffff00819b4ec;
  }
  *(undefined8 *)(param_1 + 0xb8) = 0;
LAB_fffffff00819b510:
  lVar8 = *(long *)(param_1 + 0x18);
  *(undefined4 *)(lVar8 + 0x8e8) = 0;
  if (0 < *(int *)(lVar8 + 0x848)) {
    lVar10 = 0;
    lVar12 = *(long *)(lVar8 + 0x8f0);
    lVar14 = *(long *)(lVar8 + 0x8f8);
    lVar16 = *(long *)(lVar8 + 0x900);
    do {
      *(undefined8 *)(lVar12 + lVar10 * 8) = 0;
      *(undefined8 *)(lVar14 + lVar10 * 8) = 0;
      *(undefined4 *)(lVar16 + lVar10 * 4) = 0;
      lVar10 = lVar10 + 1;
    } while (lVar10 < *(int *)(lVar8 + 0x848));
  }
  if (*(long **)(param_1 + 0xe8) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0xe8) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0xf0) = 0;
  *(undefined8 *)(param_1 + 0xe8) = 0;
  lVar8 = *(long *)(param_1 + 0xd0);
  if (lVar8 != 0) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar8 + 0x40));
    if (0 < *(long *)(lVar8 + 0x38)) {
      if (*(long *)(lVar8 + 0x50) != 0) {
        thunk_EXT_FUN_801100000297b408();
      }
      if (*(long *)(lVar8 + 0x58) != 0) {
        thunk_EXT_FUN_801100000297b408();
      }
      *(long *)(lVar8 + 0x38) = *(long *)(lVar8 + 0x38) + -1;
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar8 + 0x40));
    if (*(long **)(param_1 + 0xd0) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0xd0) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0xd0) = 0;
  }
  if (*(long *)(param_1 + 200) != 0) {
    lVar8 = *(long *)(*(long *)(param_1 + 0x10) + 0x4b0);
    uVar2 = *(uint *)(param_1 + 0xd8);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar8 + 4000));
    if ((uVar2 == 0xffffffff) ||
       (uVar3 = *(uint *)(lVar8 + 0xfb0), uVar11 = *(long *)(lVar8 + 0xfe8) * (ulong)uVar3,
       uVar11 < uVar2 || uVar11 - uVar2 == 0)) {
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
    puVar1 = (undefined8 *)(*(long *)(lVar8 + 0xfe0) + (long)(int)lVar10);
    if (lVar10 != (int)lVar10) {
      puVar1 = (undefined8 *)
               (*(long *)(lVar8 + 0xfe0) + lVar10 & 0xffffffffffffU | 0x2bad000000000000);
    }
    piVar9 = (int *)*puVar1;
    if (piVar9 == (int *)0x0) {
      thunk_EXT_FUN_8011000003a49114
                ("AGXk: %s:%d:%s: !!! Assertion failed: %s: Invalid allocation\n");
      return;
    }
    if (*piVar9 == 0) {
      thunk_EXT_FUN_8011000003a49114
                ("AGXk: %s:%d:%s: !!! Assertion failed: %s: Invalid ref count (%d %d)\n");
      return;
    }
    *piVar9 = *piVar9 + -1;
    lVar10 = *(long *)(lVar8 + 0x1000) + (ulong)(uVar2 >> 8) * 0x20;
    uVar11 = (ulong)((uVar2 & 0xff) >> 6);
    uVar15 = 1L << ((ulong)(uVar2 & 0xff) & 0x3f);
    if ((*(ulong *)(lVar10 + uVar11 * 8) & uVar15) != 0) {
      thunk_EXT_FUN_8011000003a49114
                ("AGXk: %s:%d:%s: !!! Assertion failed: %s: Invalid element (%d)\n");
      return;
    }
    uVar13 = (ulong)(uVar2 >> 0xb) & 0x1ffff8;
    *(ulong *)(lVar8 + 0xff8 + uVar13) =
         *(ulong *)(lVar8 + 0xff8 + uVar13) | 1L << ((ulong)(uVar2 >> 8) & 0x3f);
    *(ulong *)(lVar10 + uVar11 * 8) = *(ulong *)(lVar10 + uVar11 * 8) | uVar15;
    FUN_fffffff0081af724(lVar8 + 0xf68,(ulong)uVar4,1);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar8 + 4000));
  }
  *(undefined8 *)(param_1 + 200) = 0;
  *(undefined8 *)(param_1 + 0xe0) = 0;
  *(undefined4 *)(param_1 + 0xd8) = 0xffffffff;
  *(undefined8 *)(param_1 + 0x20) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00819b70c);
    (*pcVar5)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00819b714. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca6180 + 0x80))(param_1);
  return;
}

